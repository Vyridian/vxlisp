package vxlisp

import (
	"os"
	"path/filepath"

	"github.com/fsnotify/fsnotify"
)

type vxfile struct {
	name string
	path string
	text string
}

func NewFile() *vxfile {
	return new(vxfile)
}

func BooleanExistsFromPath(path string) bool {
	output := false
	_, err := os.Stat(path)
	if err == nil {
		output = true
	} else if os.IsExist(err) {
		output = true
	}
	return output
}

func ListenToPath(path string) {
	// creates a new file watcher
	watcher, err := fsnotify.NewWatcher()
	if err != nil {
		MsgLog("ListenToPath", "ERROR", err)
	}
	defer watcher.Close()

	//
	done := make(chan bool)

	//
	go func() {
		for {
			select {
			// watch for events
			case event := <-watcher.Events:
				MsgLog("EVENT!", event)

				// watch for errors
			case err := <-watcher.Errors:
				MsgLog("ERROR", err)
			}
		}
	}()

	// out of the box fsnotify can watch a single file, or a single directory
	if err := watcher.Add(path); err != nil {
		MsgLog("ERROR", err)
	}

	<-done
}

func ListStringReadFromPathExtension(path string, extension string) ([]string, *vxmsgblock) {
	var files []string
	msgblock := NewMsgBlock("ReadFileNames")
	if BooleanExistsFromPath(path) {
		err := filepath.Walk(
			path,
			func(path string, info os.FileInfo, err error) error {
				if info.IsDir() {
				} else if extension != "" && !BooleanFromStringEnds(path, extension) {
				} else {
					path = StringFromStringFindReplace(path, "\\", "/")
					files = append(files, path)
				}
				return nil
			})
		msgblock = MsgblockAddException(msgblock, err)
	} else {
		msg := NewMsg("Path not found: " + path)
		msgblock = MsgblockAddError(msgblock, msg)
	}
	return files, msgblock
}

func PathAbsoluteFromPath(path string) (string, error) {
	output, err := filepath.Abs(path)
	return output, err
}

func PathFromPathRelativePath(basepath string, relativepath string) string {
	abspath, _ := PathAbsoluteFromPath(basepath)
	abspath = StringFromStringFindReplace(abspath, "\\", "/")
	listbasepath := ListStringFromStringSplit(abspath, "/")
	listrelpath := ListStringFromStringSplit(relativepath, "/")
	for _, relpath := range listrelpath {
		switch relpath {
		case ".":
		case "..":
			if len(listbasepath) > 0 {
				listbasepath = listbasepath[:len(listbasepath)-1]
			}
		default:
			listbasepath = append(listbasepath, relpath)
		}
	}
	output := StringFromListStringJoin(listbasepath, "/")
	return output
}

func StringFromExec() string {
	output := ""
	path, err := os.Getwd()
	if err != nil {
		MsgLog(err)
	}
	output = StringFromStringFindReplace(path, "\\", "/")
	return output
}

func StringFromFile(file *vxfile) string {
	var output string
	output += "file: " + file.path + "/" + file.name + "\n" + file.text
	return output
}

func StringFromListFile(listfile []*vxfile) string {
	var output string
	for _, file := range listfile {
		output += StringFromFile(file)
	}
	return output
}

func StringFromReadTextFile(filename string) (string, *vxmsgblock) {
	text := ""
	msgblock := NewMsgBlock("ReadTextFile")
	content, err := os.ReadFile(filename)
	if err == nil {
		text = string(content)
	} else {
		msgblock = MsgblockAddException(msgblock, err)
	}
	return text, msgblock
}

func TextblockFromReadFile(filename string) (*vxtextblock, *vxmsgblock) {
	msgblock := NewMsgBlock("ReadTextblock")
	text, msgs := StringFromReadTextFile(filename)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	textblock := NewTextblockFromText(text)
	textblock.name = filename
	return textblock, msgblock
}

func WriteFile(file *vxfile) *vxmsgblock {
	return WriteListFile([]*vxfile{file})
}

func WriteFileFromFilenameText(filename string, text string) (int, error) {
	file, err := os.Create(filename)
	if err != nil {
		return 0, err
	}
	num, err := file.WriteString(text)
	if err != nil {
		file.Close()
		return 0, err
	}
	err = file.Close()
	return num, err
}

func WriteListFile(listfile []*vxfile) *vxmsgblock {
	msgblock := NewMsgBlock("FileWriteFiles")
	for _, file := range listfile {
		name := file.name
		path := file.path
		writetext := file.text
		if !BooleanExistsFromPath(path) {
			err := WritePath(path, true)
			if err != nil {
				msgblock = MsgblockAddException(msgblock, err)
			}
		}
		filepath := path + "/" + name
		if BooleanExistsFromPath(filepath) {
			readtext, _ := StringFromReadTextFile(filepath)
			if readtext != writetext {
				_, err := WriteFileFromFilenameText(filepath, writetext)
				if err != nil {
					msgblock = MsgblockAddException(msgblock, err)
				}
			}
		} else {
			_, err := WriteFileFromFilenameText(filepath, writetext)
			if err != nil {
				msgblock = MsgblockAddException(msgblock, err)
			}
		}
	}
	return msgblock
}

func WritePath(path string, all bool) error {
	var output error
	if all {
		output = os.MkdirAll(path, os.ModePerm)
	} else {
		output = os.Mkdir(path, os.ModePerm)
	}
	return output
}
