package vxlisp

type vxcommand struct {
	name    string
	code    string
	doc     string
	filter  string
	lang    string
	path    string
	port    int
	config  string
	context string
	main    string
}

func NewCommand() *vxcommand {
	return new(vxcommand)
}

func NewCommandCopy(command *vxcommand) *vxcommand {
	output := NewCommand()
	output.code = command.code
	output.context = command.context
	output.doc = command.doc
	output.filter = command.filter
	output.lang = command.lang
	output.main = command.main
	output.name = command.name
	output.path = command.path
	output.port = command.port
	return output
}

func CommandFromTextblock(textblock *vxtextblock) (*vxcommand, *vxmsgblock) {
	msgblock := NewMsgBlock("CmdTextblock")
	command := NewCommand()
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
				command.name = prop
			default:
				switch lastprop {
				case "":
					switch proptextblock.blocktype {
					case "//":
					default:
						if BooleanFromStringStarts(prop, ":") {
							switch prop {
							case ":code", ":config", ":context", ":doc", ":filter",
								":lang", ":main", ":name", ":path", ":port":
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
						command.code = prop
					case ":config":
						command.config = prop
					case ":context":
						command.context = prop
					case ":doc":
						command.doc = prop
					case ":filter":
						command.filter = prop
					case ":lang":
						command.lang = prop
					case ":main":
						command.main = prop
					case ":path":
						command.path = prop
					case ":port":
						command.port = IntFromString(prop)
					}
					lastprop = ""
				}
			}
		}
	default:
		msg := NewMsgFromTextblock(textblock, "Cmd properties must be enclosed in (cmd)")
		msgblock = MsgblockAddError(msgblock, msg)
	}
	return command, msgblock
}

func ListCommandFromProject(prj *vxproject, cmdtexts []string) []*vxcommand {
	var output []*vxcommand
	for _, cmd := range prj.listcmd {
		if BooleanFromListStringContains(cmdtexts, cmd.name) {
			output = append(output, cmd)
		}
	}
	return output
}
