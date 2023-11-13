package vxlisp

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
	maptext     map[string]string
	textblock   *vxtextblock
}

var emptyproject = NewProject()

func NewPath() *vxpath {
	return new(vxpath)
}

func NewProject() *vxproject {
	return new(vxproject)
}

func ExecuteProjectCommand(project *vxproject, origcommand *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("ExecutProjectCommand")
	path := StringPathFromProjectCmd(project, origcommand)
	command := NewCommandCopy(origcommand)
	command.path = path
	switch command.code {
	case ":doc":
		msgs := WriteDocFromProjectCmd(project, command)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	case ":source":
		switch command.lang {
		case ":cpp":
			msgs := CppWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":csharp":
			msgs := CSharpWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":java":
			msgs := JavaWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":js":
			msgs := WriteJsFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":kotlin":
			msgs := KotlinWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":swift":
			msgs := SwiftWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
	case ":test":
		switch command.lang {
		case ":cpp":
			msgs := CppWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":csharp":
			msgs := CSharpWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":java":
			msgs := JavaWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":js":
			msgs := WriteJsFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":kotlin":
			msgs := KotlinWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		case ":swift":
			msgs := SwiftWriteFromProjectCmd(project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
	case ":webserver":
		WebServerStart(project, command)
	}
	return msgblock
}

func ExecuteProjectCmds(project *vxproject, listcommand []*vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("ExecutProjectCmds")
	for _, command := range listcommand {
		msgs := ExecuteProjectCommand(project, command)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func ExecuteProjectFromArgs(listarg []string) *vxmsgblock {
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
			case "--path":
				projectpath = arg
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
	projectpath = StringFromStringFindReplace(projectpath, "\\", "/")
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

func FuncFromProjectFuncname(project *vxproject, funcname string) *vxfunc {
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

func ListPackageFromProject(project *vxproject) []*vxpackage {
	var output []*vxpackage
	for _, subproject := range project.listproject {
		output = append(output, subproject.listpackage...)
	}
	output = append(output, project.listpackage...)
	return output
}

func PackageFromProjectName(project *vxproject, name string) (*vxpackage, bool) {
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

func PathFromProjectCmd(project *vxproject, command *vxcommand) string {
	output := PathFromPathRelativePath(project.path, command.path)
	return output
}

func PathFromProjectPath(project *vxproject, relativepath string) string {
	output := PathFromPathRelativePath(project.path, relativepath)
	return output
}

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

func ProjectReadFromFilename(filename string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromFile")
	var prj = NewProject()
	textblock, msgs := TextblockFromReadFile(filename)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		parseprj, msgs := ProjectFromTextblock(textblock)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		prj = parseprj
	}
	filename = StringFromStringBefore(filename, "/project.vxlisp")
	prj.path = filename
	return prj, msgblock
}

func ProjectReadFromPath(projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromPath")
	project, msgs := ProjectReadAllFromPath(projectpath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		if len(project.listprjpath) > 0 {
			var subprojects []*vxproject
			for _, subprojectpath := range project.listprjpath {
				subproject, msgs := ProjectReadFromPath(subprojectpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				subprojects = append(subprojects, subproject)
			}
			project.listproject = subprojects
		}
		pkgs := ListPackageFromProject(project)
		if !msgblock.iserror {
			pkgs, msgs = ListPackageValidateLibraries(pkgs, project)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
		if !msgblock.iserror {
			pkgs, msgs = ListPackageLink(pkgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			project.listpackage = pkgs
		}
		if !msgblock.iserror {
			pkgs, msgs = ListPackageValidate(pkgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			project.listpackage = pkgs
		}
	}
	return project, msgblock
}

func ProjectReadAllFromPath(projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectReadAllFromPath")
	var packages []*vxpackage
	maptext := NewMapString()
	project := emptyproject
	filenames, msgs := ListStringReadFromPathExtension(projectpath, ".vxlisp")
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
	}
	if !msgblock.iserror {
		var extrafilenames []string
		langs := []string{"cpp", "java", "js"}
		for _, lang := range langs {
			extralangfilenames, msgs := ListStringReadFromPathExtension(projectpath, "_"+lang+".txt")
			msgblock = MsgblockAddBlock(msgblock, msgs)
			extrafilenames = append(extrafilenames, extralangfilenames...)
		}
		if !msgblock.iserror {
			for _, filename := range extrafilenames {
				extraname := StringFromStringFindReplace(filename, projectpath+"/", "")
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
		project.maptext = maptext
	}
	return project, msgblock
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

func StringFromCmd(cmd *vxcommand) string {
	return StringFromCmdIndent(cmd, "")
}

func StringFromCmdIndent(cmd *vxcommand, indent string) string {
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

func StringFromListCmd(cmds []*vxcommand) string {
	return StringFromListCmdIndent(cmds, "")
}

func StringFromListCmdIndent(cmds []*vxcommand, indent string) string {
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
		"\n :packages [" + StringFromListStringJoin(pkgnames, " ") + "])"
	return output
}

func StringPathFromProjectCmd(prj *vxproject, cmd *vxcommand) string {
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
				pathtext = StringFromStringFindReplace(pathtext, "*"+pathname+"*", path.path)
			}
		}
	}
	return pathtext
}
