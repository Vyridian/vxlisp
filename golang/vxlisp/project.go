package vxlisp

type vxcommand struct {
	name string
	code string
	doc  string
	lang string
	path string
	port int
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
	path        string
	version     string
	listcmd     []*vxcommand
	listlib     []*vxlibrary
	listpath    []*vxpath
	listpackage []*vxpackage
	listpkgpath []string
	textblock   *vxtextblock
}

func NewCmd() *vxcommand {
	return new(vxcommand)
}

func NewCmdCopy(cmd *vxcommand) *vxcommand {
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

func CmdFromTextblock(textblock *vxtextblock) (*vxcommand, *vxmsgblock) {
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
							case ":code", ":doc", ":lang", ":name", ":path", ":port":
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
					case ":port":
						cmd.port = IntFromString(prop)
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

func CmdsFromProject(prj *vxproject, cmdtexts []string) []*vxcommand {
	var output []*vxcommand
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

func ExecuteProjectCmd(prj *vxproject, origcmd *vxcommand) *vxmsgblock {
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

func ExecuteProjectCmds(prj *vxproject, cmds []*vxcommand) *vxmsgblock {
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
	projectpath := ""
	lastarg := ""
	for argidx, arg := range args {
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
	project, msgs := ProjectFromPath(projectpath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !IsErrorFromMsgblock(msgblock) {
		cmds := CmdsFromProject(project, cmdtexts)
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

func ProjectFromFile(projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromFile")
	var prj = NewProject()
	textblock, msgs := TextblockFromReadFile(projectpath + "/project.vxlisp")
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		parseprj, msgs := ProjectFromTextblock(textblock)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		prj = parseprj
	}
	prj.path = projectpath
	return prj, msgblock
}

func ProjectFromPath(projectpath string) (*vxproject, *vxmsgblock) {
	msgblock := NewMsgBlock("ProjectFromPath")
	project, msgs := ProjectFromFile(projectpath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if !msgblock.iserror {
		var pkgs []*vxpackage
		for _, pkgpath := range project.listpkgpath {
			// projectpath
			workpath := PathFromProjectPath(project, pkgpath)
			loadpkgs, msgs := ListPackageFromReadPath(workpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			pkgs = append(pkgs, loadpkgs...)
		}
		loadpkgs, msgs := ListPackageFromReadPath(projectpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		pkgs = append(pkgs, loadpkgs...)
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
									case ":author", ":cmds", ":doc", ":libs", ":packages", ":paths", ":version":
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
									case ":packages":
										prj.listpkgpath = append(prj.listpkgpath, word)
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
