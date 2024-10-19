package vxlisp

import (
	"maps"
)

type vxpath struct {
	doc  string
	name string
	path string
}

type vxproject struct {
	name        string
	author      string
	doc         string
	path        string
	version     string
	javadomain  string
	listcmd     []*vxcommand
	listlib     []*vxlibrary
	listpath    []*vxpath
	listpackage []*vxpackage
	listprjpath []string
	listproject []*vxproject
	mapnative   map[string]string
	textblock   *vxtextblock
}

var emptyproject = NewProject("")

func NewPath() *vxpath {
	return new(vxpath)
}

func NewProject(prjname string) *vxproject {
	output := new(vxproject)
	output.name = prjname
	return output
}

func ExecuteProjectCommand(
	project *vxproject,
	origcommand *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("ExecutProjectCommand")
	path := StringPathFromProjectCmd(project, origcommand)
	command := NewCommandCopy(origcommand)
	command.path = path
	issource := false
	switch command.code {
	case ":doc":
		msgs := WriteDocFromProjectCmd(project, command)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	case ":source", ":test":
		if !issource {
			msgs := LangSpecificWriteFromProjectCmd(
				command.lang, project, command)
			msgblock = MsgblockAddBlock(
				msgblock, msgs)
		}
		issource = true
	case ":webserver":
		WebServerStart(project, command)
	}
	return msgblock
}

func ExecuteProjectCmds(
	project *vxproject,
	listcommand []*vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("ExecutProjectCmds")
	for _, command := range listcommand {
		msgs := ExecuteProjectCommand(project, command)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func ExecuteProjectFromArgs(
	listarg []string) *vxmsgblock {
	msgblock := NewMsgBlock("ExecuteProjectFromArgs")
	MsgStartLog()
	var cmdtexts []string
	projectpath := ""
	lastarg := ""
	for argidx, arg := range listarg {
		switch argidx {
		case 0:
		default:
			switch lastarg {
			case "--path", ":path":
				projectpath = arg
			default:
				switch arg {
				case "--path", ":path":
					lastarg = arg
				default:
					cmdtexts = append(cmdtexts, arg)
				}
			}
		}
	}
	projectpath, _ = PathAbsoluteFromPath(projectpath)
	projectpath = StringFromStringFindReplace(
		projectpath, "\\", "/")
	project, msgs := ProjectReadFromPath(projectpath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !IsErrorFromMsgblock(msgblock) {
		cmds := ListCommandFromProject(project, cmdtexts)
		msgs := ExecuteProjectCmds(project, cmds)
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

func FuncFromProjectFuncname(
	project *vxproject,
	funcname string) *vxfunc {
	output := emptyfunc
	if funcname != "" {
		pos := IntFromStringFindLast(funcname, "/")
		if pos > 0 {
			packagename := funcname[0:pos]
			fncname := funcname[pos+1:]
			pkg, ok := PackageFromProjectName(project, packagename)
			if ok {
				fncs, ok := pkg.mapfunc[fncname]
				if ok {
					output = fncs[0]
				}
			}
		}
	}
	return output
}

func ListPackageFromProject(
	project *vxproject) []*vxpackage {
	var output []*vxpackage
	for _, subproject := range project.listproject {
		output = append(output, subproject.listpackage...)
	}
	output = append(output, project.listpackage...)
	return output
}

func PackageFromProjectFunc(
	prj *vxproject,
	fnc *vxfunc) *vxpackage {
	output := packageempty
	pkg, ok := PackageFromProjectName(prj, fnc.pkgname)
	if ok {
		output = pkg
	} else {
		MsgLog(
			"Error: Package Not Found from Func: " + fnc.name)
	}
	return output
}

func PackageFromProjectName(
	project *vxproject,
	name string) (*vxpackage, bool) {
	var output *vxpackage
	isfound := false
	listpackage := ListPackageFromProject(project)
	for _, pkg := range listpackage {
		if pkg.name == name {
			output = pkg
			isfound = true
		}
	}
	return output, isfound
}

func PackageCoreFromProject(
	project *vxproject) *vxpackage {
	output, ok := PackageFromProjectName(project, "vx/core")
	if !ok {
		MsgLog(
			"Error: vx/core package not found")
	}
	return output
}

func PathFromProjectCmd(
	project *vxproject,
	command *vxcommand) string {
	output := PathFromPathRelativePath(project.path, command.path)
	return output
}

func PathFromProjectPath(
	project *vxproject,
	relativepath string) string {
	output := PathFromPathRelativePath(project.path, relativepath)
	return output
}

func PathFromTextblock(
	textblock *vxtextblock) (*vxpath, *vxmsgblock) {
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

func ProjectReadFromFilename(
	filename string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromFile")
	var project = NewProject("")
	textblock, msgs := TextblockFromReadFile(filename)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		parseprj, msgs := ProjectFromTextblock(textblock)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		project = parseprj
	}
	filename = StringFromStringBefore(filename, "/project.vxlisp")
	project.path = filename
	return project, msgblock
}

func ProjectReadFromPath(
	projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromPath")
	project, msgs := ProjectReadAllFromPath(projectpath)
	maptext := project.mapnative
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		if len(project.listprjpath) > 0 {
			var subprojects []*vxproject
			for _, subprojectpath := range project.listprjpath {
				subproject, msgs := ProjectReadAllFromPath(subprojectpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				listpackage := ListPackageFromProject(subproject)
				if !msgblock.iserror {
					listpackage, msgs = ListPackageValidateLibraries(
						listpackage, subproject)
					msgblock = MsgblockAddBlock(msgblock, msgs)
				}
				subproject.listpackage = listpackage
				subprojects = append(subprojects, subproject)
				maps.Copy(maptext, subproject.mapnative)
			}
			project.listproject = subprojects
		}
		listpackage := ListPackageFromProject(project)
		if !msgblock.iserror {
			listpackage, msgs = ListPackageValidateLibraries(listpackage, project)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
		if !msgblock.iserror {
			listpackage, msgs = ListPackageSortDependencies(listpackage)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			project.listpackage = listpackage
		}
		if !msgblock.iserror {
			listpackage, msgs = ListPackageLink(listpackage)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			project.listpackage = listpackage
		}
		if !msgblock.iserror {
			listpackage, msgs = ListPackageValidate(listpackage)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			project.listpackage = listpackage
		}
	}
	return project, msgblock
}

func ProjectReadAllFromPath(
	projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectReadAllFromPath")
	var packages []*vxpackage
	maptext := NewMapString()
	project := emptyproject
	filenames, msgs := ListStringReadFromPathExtension(
		projectpath, ".vxlisp")
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		for _, filename := range filenames {
			if project == emptyproject && BooleanFromStringEnds(filename, "/project.vxlisp") {
				project, msgs = ProjectReadFromFilename(filename)
				msgblock = MsgblockAddBlock(msgblock, msgs)
			} else {
				textblock, msgs := TextblockFromReadFile(filename)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				if !msgblock.iserror {
					textblock, msgs = TextblockParse(textblock)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					if !msgblock.iserror {
						pkg, msgs := PackageFromTextblock(textblock)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						packages = append(packages, pkg)
					}
				}
			}
		}
		for _, pkg := range packages {
			pkg.project = project
		}
	}
	if !msgblock.iserror {
		var extrafilenames []string
		langs := []string{"cpp", "csharp", "java", "js", "kotlin", "swift"}
		for _, lang := range langs {
			extralangfilenames, msgs := ListStringReadFromPathExtension(
				projectpath, "_"+lang+".txt")
			msgblock = MsgblockAddBlock(msgblock, msgs)
			extrafilenames = append(
				extrafilenames, extralangfilenames...)
		}
		if !msgblock.iserror {
			for _, filename := range extrafilenames {
				extraname := StringFromStringFindReplace(
					filename, projectpath+"/", "")
				extratext, msgs := StringFromReadTextFile(filename)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				if !msgblock.iserror {
					maptext[extraname] = extratext
				}
			}
		}
	}
	if project == emptyproject {
		msg := NewMsg("project.vxlisp file not found in " + projectpath)
		msgblock = MsgblockAddError(msgblock, msg)
	} else {
		for _, pkg := range packages {
			pkg.project = project
		}
		project.listpackage = packages
		project.mapnative = maptext
	}
	return project, msgblock
}

func ProjectFromTextblock(
	textblock *vxtextblock) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromTextblock")
	prj := NewProject("")
	prj.textblock = textblock
	var foundproject = false
	var lastword = ""
	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	for _, alltextblock := range textblock.listtextblock {
		wordtextblocks := alltextblock.listtextblock
		if alltextblock.blocktype != "(" {
			msg := NewMsgFromTextblock(
				textblock, "Invalid Project Blocktype")
			msgblock = MsgblockAddError(msgblock, msg)
		} else if len(wordtextblocks) > 0 {
			firstwordtextblock := wordtextblocks[0]
			switch firstwordtextblock.text {
			case "project":
				if foundproject {
					msg := NewMsgFromTextblock(
						textblock, "Found more than 1 Project definition")
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
									case ":author", ":cmds", ":doc", ":javadomain", ":libs", ":paths", ":projects", ":version":
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
									case ":javadomain":
										prj.javadomain = word
									case ":version":
										prj.version = word
										lastword = ""
									case ":cmds":
										cmd, msgs := CommandFromTextblock(wordtextblock)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										prj.listcmd = append(prj.listcmd, cmd)
									case ":libs":
										lib, msgs := LibraryFromTextblock(wordtextblock)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										prj.listlib = append(prj.listlib, lib)
									case ":projects":
										prj.listprjpath = append(prj.listprjpath, word)
									case ":paths":
										path, msgs := PathFromTextblock(wordtextblock)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										prj.listpath = append(prj.listpath, path)
									default:
										msg := NewMsgFromTextblock(
											textblock, "Invalid Project Property:", word)
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

func StringFromCmd(
	cmd *vxcommand) string {
	return StringFromCmdIndent(cmd, 0)
}

func StringFromCmdIndent(
	cmd *vxcommand,
	indent int) string {
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output := "" +
		lineindent + "(cmd" +
		lineindent + " :name " + cmd.name +
		lineindent + " :code " + cmd.code +
		lineindent + " :lang " + cmd.langcode +
		lineindent + " :path " + cmd.path +
		lineindent + " :doc  " + cmd.doc + ")"
	return output
}

func StringFromListCmd(
	cmds []*vxcommand) string {
	return StringFromListCmdIndent(cmds, 0)
}

func StringFromListCmdIndent(
	cmds []*vxcommand, indent int) string {
	output := ""
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output = lineindent + "(cmdlist"
	for _, cmd := range cmds {
		output += StringFromCmdIndent(cmd, indent+1)
	}
	output += ")"
	return output
}

func StringFromListPath(
	listpath []*vxpath) string {
	return StringFromListPathIndent(listpath, 0)
}

func StringFromListPathIndent(
	listpath []*vxpath,
	indent int) string {
	output := ""
	if len(listpath) == 0 {
		output = "[]"
	} else {
		lineindent := ""
		if indent > 0 {
			lineindent = "\n" + StringRepeat(" ", indent)
		}
		output = lineindent + "(pathlist"
		for _, path := range listpath {
			output += StringFromPathIndent(path, indent+1)
		}
		output += ")"
	}
	return output
}

func StringFromPath(
	path *vxpath) string {
	return StringFromPathIndent(path, 0)
}

func StringFromPathIndent(
	path *vxpath,
	indent int) string {
	lineindent := ""
	startindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
		startindent = lineindent
	}
	output := "" +
		startindent + "(path" +
		lineindent + " :name " + path.name +
		lineindent + " :path " + path.path +
		lineindent + " :doc  " + path.doc + ")"
	return output
}

func StringFromProject(
	project *vxproject) string {
	return StringFromProjectIndent(project, 0)
}

func StringFromProjectIndent(
	project *vxproject,
	indent int) string {
	var pkgnames []string
	lineindent := ""
	startindent := ""
	lineindent = "\n" + StringRepeat(" ", indent)
	if indent > 0 {
		startindent = lineindent
	}
	for _, pkg := range project.listpackage {
		pkgnames = append(pkgnames, pkg.name)
	}
	var output = "" +
		startindent + "(project" +
		lineindent + " :name     " + project.name +
		lineindent + " :author   " + project.author +
		lineindent + " :version  " + project.version +
		lineindent + " :doc      " + project.doc +
		lineindent + " :cmds " + StringFromListCmdIndent(
		project.listcmd, indent+2) +
		lineindent + " :libs " + StringFromListLibraryIndent(
		project.listlib, indent+2) +
		lineindent + " :paths " + StringFromListPathIndent(
		project.listpath, indent+2) +
		lineindent + " :packages [" + StringFromListStringJoin(
		pkgnames, " ") + "]" +
		lineindent + " :projects " + StringFromListProjectIndent(
		project.listproject, 2) + ")"
	return output
}

func StringFromListProjectIndent(
	listproject []*vxproject,
	indent int) string {
	output := ""
	if len(listproject) == 0 {
		output = "[]"
	} else {
		lineindent := ""
		if indent > 0 {
			lineindent = "\n" + StringRepeat(" ", indent)
		}
		var listtextproject []string
		for _, project := range listproject {
			textproject := StringFromProjectIndent(project, indent+1)
			listtextproject = append(listtextproject, textproject)
		}
		output = lineindent + "(projectlist" + StringFromListStringJoin(listtextproject, lineindent+" ") + ")"
	}
	return output
}

func StringPathFromProjectCmd(
	prj *vxproject,
	cmd *vxcommand) string {
	pathtext := cmd.path
	switch cmd.path {
	case "":
		code := cmd.code
		lang := cmd.lang
		pathtext = LangSpecificPathtext(lang, code)
	default:
		for _, path := range prj.listpath {
			pathname := path.name
			pathpath := path.path
			switch pathname {
			case "":
			case pathtext:
				pathtext = pathpath
			default:
				pathtext = StringFromStringFindReplace(pathtext, "*"+pathname+"*", path.path)
			}
		}
	}
	return pathtext
}
