package vxlisp

type vxcmd struct {
	name string
	code string
	doc  string
	lang string
	path string
}

type vxpath struct {
	doc  string
	name string
	path string
}

type vxproject struct {
	name        string
	author      string
	doc         string
	version     string
	listcmd     []*vxcmd
	listlib     []*vxlibrary
	listpath    []*vxpath
	listpackage []*vxpackage
	textblock   *vxtextblock
}

func NewCmd() *vxcmd {
	return new(vxcmd)
}

func NewCmdCopy(cmd *vxcmd) *vxcmd {
	output := NewCmd()
	output.code = cmd.code
	output.doc = cmd.doc
	output.lang = cmd.lang
	output.name = cmd.name
	output.path = cmd.path
	return output
}

func NewPath() *vxpath {
	return new(vxpath)
}

func NewProject() *vxproject {
	return new(vxproject)
}

func CmdFromTextblock(textblock *vxtextblock) (*vxcmd, *vxmsgblock) {
	msgblock := NewMsgBlock("CmdTextblock")
	cmd := NewCmd()
	switch textblock.blocktype {
	case "(":
		var lastprop = ""
		for idx, proptextblock := range textblock.listtextblock {
			prop := proptextblock.text
			switch idx {
			case 0:
				switch prop {
				case "cmd":
				default:
					msg := NewMsgFromTextblock(textblock, "Cmds may only contain (cmd):", prop)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			case 1:
				cmd.name = prop
			default:
				switch lastprop {
				case "":
					switch proptextblock.blocktype {
					case "//":
					default:
						if BooleanFromStringStarts(prop, ":") {
							switch prop {
							case ":code", ":doc", ":lang", ":name", ":path":
								lastprop = prop
							default:
								msg := NewMsgFromTextblock(textblock, "Invalid Keyword:", prop)
								msgblock = MsgblockAddError(msgblock, msg)
							}
						} else {
							msg := NewMsgFromTextblock(textblock, "Invalid Cmd Property:", prop)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					}
				default:
					switch lastprop {
					case ":code":
						cmd.code = prop
					case ":doc":
						cmd.doc = prop
					case ":lang":
						cmd.lang = prop
					case ":path":
						cmd.path = prop
					}
					lastprop = ""
				}
			}
		}
	default:
		msg := NewMsgFromTextblock(textblock, "Cmd properties must be enclosed in (cmd)")
		msgblock = MsgblockAddError(msgblock, msg)
	}
	return cmd, msgblock
}

func CmdsFromProject(prj *vxproject, cmdtexts []string) []*vxcmd {
	var output []*vxcmd
	for _, cmd := range prj.listcmd {
		if BooleanFromListStringContains(cmdtexts, cmd.name) {
			output = append(output, cmd)
		}
	}
	return output
}

/*
func CmdsFromTextblock(textblock *vxtextblock) ([]*vxcmd, *vxmsgblock) {
	msgblock := NewMsgBlock("CmdsFromTextblock")
	var output []*vxcmd
	switch textblock.blocktype {
	case "[":
		for _, textblock := range textblock.listtextblock {
			cmd, msgs := CmdFromTextblock(textblock)
			msgblock = MsgBlockAddBlock(msgblock, msgs)
			output = append(output, cmd)
		}
	default:
		msg := NewMsgFromTextblock(textblock, "Invalid Cmds definition:", textblock.blocktype)
		msgblock = MsgBlockAddError(msgblock, msg)
	}
	return output, msgblock
}
*/

func ExecuteProjectCmd(prj *vxproject, origcmd *vxcmd) *vxmsgblock {
	msgblock := NewMsgBlock("ExecutProjectCmd")
	path := StringPathFromProjectCmd(prj, origcmd)
	cmd := NewCmdCopy(origcmd)
	cmd.path = path
	switch cmd.code {
	case ":doc":
		msgs := WriteDocFromProjectCmd(prj, cmd)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	case ":source":
		switch cmd.lang {
		case ":java":
			msgs := WriteJavaFromProjectCmd(prj, cmd)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":js":
			msgs := WriteJsFromProjectCmd(prj, cmd)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
	case ":test":
		switch cmd.lang {
		case ":java":
			msgs := WriteJavaFromProjectCmd(prj, cmd)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":js":
			msgs := WriteJsFromProjectCmd(prj, cmd)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
	case ":webserver":
		WebServerStart()
	}
	return msgblock
}

func ExecuteProjectCmds(prj *vxproject, cmds []*vxcmd) *vxmsgblock {
	msgblock := NewMsgBlock("ExecutProjectCmds")
	for _, cmd := range cmds {
		msgs := ExecuteProjectCmd(prj, cmd)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func ExecuteProjectFromArgs(args []string) *vxmsgblock {
	msgblock := NewMsgBlock("ExecuteProjectFromArgs")
	MsgStartLog()
	var cmdtexts []string
	prjpath := ""
	lastarg := ""
	for argidx, arg := range args {
		switch argidx {
		case 0:
		default:
			switch lastarg {
			case "--path":
				prjpath = arg
			default:
				switch arg {
				case "--path":
					lastarg = arg
				default:
					cmdtexts = append(cmdtexts, arg)
				}
			}
		}
	}
	exepath := StringFromExec()
	prj, msgs := ProjectFromPath(prjpath, exepath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !IsErrorFromMsgblock(msgblock) {
		cmds := CmdsFromProject(prj, cmdtexts)
		msgs := ExecuteProjectCmds(prj, cmds)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	if IsErrorFromMsgblock(msgblock) {
		MsgblockLog(msgblock)
	} else if IsWarningFromMsgblock(msgblock) {
		MsgblockLog(msgblock)
	}
	MsgStopLog()
	return msgblock
}

/*
func ListPathFromTextblock(textblock *vxtextblock) ([]*vxpath, *vxmsgblock) {
	msgblock := NewMsgBlock("PathsFromTextblock")
	var output []*vxpath
	switch textblock.blocktype {
	case "[":
		for _, textblock := range textblock.listtextblock {
			path, msgs := PathFromTextblock(textblock)
			msgblock = MsgBlockAddBlock(msgblock, msgs)
			output = append(output, path)
		}
	default:
		msg := NewMsgFromTextblock(textblock, "Invalid Paths definition:", textblock.blocktype)
		msgblock = MsgBlockAddError(msgblock, msg)
	}
	return output, msgblock
}
*/

func PathFromTextblock(textblock *vxtextblock) (*vxpath, *vxmsgblock) {
	msgblock := NewMsgBlock("PathFromTextblock")
	path := NewPath()
	switch textblock.blocktype {
	case "(":
		lastprop := ""
		for idx, proptextblock := range textblock.listtextblock {
			prop := proptextblock.text
			switch idx {
			case 0:
				switch prop {
				case "path":
				default:
					msg := NewMsgFromTextblock(textblock, "paths may only contain (path):", prop)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			case 1:
				path.name = prop
			default:
				if lastprop != "" {
					switch lastprop {
					case ":doc":
						path.doc = prop
					case ":path":
						path.path = prop
					}
					lastprop = ""
				} else {
					switch prop {
					case ":doc", ":path":
						lastprop = prop
					default:
						msg := NewMsgFromTextblock(textblock, "Invalid Path Keyword:", prop)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				}
			}
		}
	default:
		msg := NewMsgFromTextblock(textblock, "Invalid Paths definition:", textblock.blocktype)
		msgblock = MsgblockAddError(msgblock, msg)
	}
	return path, msgblock
}

func ProjectFromFile(projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromFile")
	var prj = NewProject()
	textblock, msgs := TextblockFromReadFile(projectpath + "/project.vxlsp")
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		parseprj, msgs := ProjectFromTextblock(textblock)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		prj = parseprj
	}
	return prj, msgblock
}

func ProjectFromPath(projectpath string, exepath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromPath")
	prj, msgs := ProjectFromFile(projectpath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		corepkgs, msgs := ListPackageFromReadPath(exepath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		prjpkgs, msgs := ListPackageFromReadPath(projectpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		pkgs := append(corepkgs, prjpkgs...)
		if !msgblock.iserror {
			pkgs, msgs = ListPackageValidateLibraries(pkgs, prj)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
		if !msgblock.iserror {
			pkgs, msgs = ListPackageLink(pkgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			prj.listpackage = pkgs
		}
		if !msgblock.iserror {
			pkgs, msgs = ListPackageValidate(pkgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			prj.listpackage = pkgs
		}
	}
	return prj, msgblock
}

func ProjectFromTextblock(textblock *vxtextblock) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromTextblock")
	prj := NewProject()
	prj.textblock = textblock
	var foundproject = false
	var lastword = ""
	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	for _, alltextblock := range textblock.listtextblock {
		wordtextblocks := alltextblock.listtextblock
		if alltextblock.blocktype != "(" {
			msg := NewMsgFromTextblock(textblock, "Invalid Project Blocktype")
			msgblock = MsgblockAddError(msgblock, msg)
		} else if len(wordtextblocks) > 0 {
			firstwordtextblock := wordtextblocks[0]
			switch firstwordtextblock.text {
			case "project":
				if foundproject {
					msg := NewMsgFromTextblock(textblock, "Found more than 1 Project definition")
					msgblock = MsgblockAddError(msgblock, msg)
				} else {
					foundproject = true
					for i, wordtextblock := range wordtextblocks {
						word := wordtextblock.text
						switch i {
						case 0:
						case 1:
							prj.name = word
						default:
							switch wordtextblock.blocktype {
							case "//":
							default:
								if BooleanFromStringStarts(word, ":") {
									switch word {
									case ":author", ":cmds", ":doc", ":libs", ":paths", ":version":
										lastword = word
									default:
										msg := NewMsgFromTextblock(textblock, "Invalid Keyword:", word)
										msgblock = MsgblockAddError(msgblock, msg)
									}
								} else {
									switch lastword {
									case ":author":
										prj.author = word
										lastword = ""
									case ":doc":
										prj.doc = word
										lastword = ""
									case ":version":
										prj.version = word
										lastword = ""
									case ":cmds":
										cmd, msgs := CmdFromTextblock(wordtextblock)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										prj.listcmd = append(prj.listcmd, cmd)
									case ":libs":
										lib, msgs := LibraryFromTextblock(wordtextblock)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										prj.listlib = append(prj.listlib, lib)
									case ":paths":
										path, msgs := PathFromTextblock(wordtextblock)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										prj.listpath = append(prj.listpath, path)
									default:
										msg := NewMsgFromTextblock(textblock, "Invalid Project Property:", word)
										msgblock = MsgblockAddError(msgblock, msg)
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return prj, msgblock
}

func StringFromCmd(cmd *vxcmd) string {
	return StringFromCmdIndent(cmd, "")
}

func StringFromCmdIndent(cmd *vxcmd, indent string) string {
	lineindent := "\n" + indent
	var output = "" +
		lineindent + "(cmd" +
		lineindent + " :name " + cmd.name +
		lineindent + " :code " + cmd.code +
		lineindent + " :lang " + cmd.lang +
		lineindent + " :path " + cmd.path +
		lineindent + " :doc  " + cmd.doc +
		")"
	return output
}

func StringFromListCmd(cmds []*vxcmd) string {
	return StringFromListCmdIndent(cmds, "")
}

func StringFromListCmdIndent(cmds []*vxcmd, indent string) string {
	output := "(cmdlist"
	for _, cmd := range cmds {
		output += StringFromCmdIndent(cmd, indent+" ")
	}
	output += ")"
	return output
}

func StringFromListPath(listpath []*vxpath) string {
	return StringFromListPathIndent(listpath, "")
}

func StringFromListPathIndent(listpath []*vxpath, indent string) string {
	output := "(pathlist"
	for _, path := range listpath {
		output += StringFromPathIndent(path, indent+" ")
	}
	output += ")"
	return output
}

func StringFromPath(path *vxpath) string {
	return StringFromPathIndent(path, "")
}

func StringFromPathIndent(path *vxpath, indent string) string {
	lineindent := "\n" + indent
	var output = "" +
		lineindent + "(path" +
		lineindent + " :name " + path.name +
		lineindent + " :path " + path.path +
		lineindent + " :doc  " + path.doc + ")"
	return output
}

func StringFromProject(prj *vxproject) string {
	var pkgnames []string
	for _, pkg := range prj.listpackage {
		pkgnames = append(pkgnames, pkg.name)
	}
	var output = "" +
		"(project" +
		"\n :name     " + prj.name +
		"\n :author   " + prj.author +
		"\n :version  " + prj.version +
		"\n :doc      " + prj.doc +
		"\n :cmds " + StringFromListCmdIndent(prj.listcmd, " ") +
		"\n :libs " + StringFromListLibraryIndent(prj.listlib, " ") +
		"\n :paths " + StringFromListPathIndent(prj.listpath, " ") +
		"\n :packages [" + StringJoinFromListString(pkgnames, " ") + "])"
	return output
}

func StringPathFromProjectCmd(prj *vxproject, cmd *vxcmd) string {
	pathtext := cmd.path
	switch cmd.path {
	case "":
		code := cmd.code
		lang := cmd.lang
		switch code {
		case ":doc":
			pathtext = "build/doc"
		case ":source":
			switch lang {
			case ":java":
				pathtext = "build/java/src"
			case ":js":
				pathtext = "build/js/test"
			}
		case ":test":
			switch lang {
			case ":java":
				pathtext = "build/java/src"
			case ":js":
				pathtext = "build/js/test"
			}
		}
	default:
		for _, path := range prj.listpath {
			pathname := path.name
			pathpath := path.path
			switch pathname {
			case "":
			case pathtext:
				pathtext = pathpath
			default:
				pathtext = StringReplace(pathtext, "*"+pathname+"*", path.path)
			}
		}
	}
	return pathtext
}
