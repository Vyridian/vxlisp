package vxlisp

type vxlibrary struct {
	name string
	path string
	lang string
	doc  string
	pkg  *vxpackage
}

var emptylistlibrary = NewListLibrary()

func NewLibrary() *vxlibrary {
	return new(vxlibrary)
}

func NewListLibrary() []*vxlibrary {
	return []*vxlibrary{}
}

func NewMapLibrary() map[string]*vxlibrary {
	return make(map[string]*vxlibrary)
}

func LibraryFromTextblock(textblock *vxtextblock) (*vxlibrary, *vxmsgblock) {
	msgblock := NewMsgBlock("LibraryFromTextblock")
	library := NewLibrary()
	switch textblock.blocktype {
	case "(":
		lastprop := ""
		for libnum, libblock := range textblock.listtextblock {
			prop := libblock.text
			switch libnum {
			case 0:
				switch prop {
				case "lib":
				default:
					msg := NewMsgFromTextblock(textblock, "Invalid Library definition:", textblock.blocktype)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			case 1:
				library.name = prop
			default:
				switch lastprop {
				case "":
					switch prop {
					case ":lang", ":path", ":doc":
						lastprop = prop
					default:
						msg := NewMsgFromTextblock(textblock, "Invalid Library definition:", textblock.blocktype)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				case ":doc":
					library.doc = prop
					lastprop = ""
				case ":lang":
					library.lang = prop
					lastprop = ""
				case ":path":
					library.path = prop
					lastprop = ""
				}
			}
		}
	default:
		msg := NewMsgFromTextblock(textblock, "Invalid Library definition:", textblock.blocktype)
		msgblock = MsgblockAddError(msgblock, msg)
	}
	return library, msgblock
}

func ListLibraryFromMapLibrary(maplibrary map[string]*vxlibrary) []*vxlibrary {
	output := NewListLibrary()
	for _, library := range maplibrary {
		output = append(output, library)
	}
	return output
}

func MapLibraryFromListLibrary(listlibrary []*vxlibrary) map[string]*vxlibrary {
	output := NewMapLibrary()
	for _, library := range listlibrary {
		name := library.name
		output[name] = library
	}
	return output
}

func StringFromLibrary(library *vxlibrary) string {
	return StringFromLibraryIndent(library, 0)
}

func StringFromLibraryIndent(library *vxlibrary, indent int) string {
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output := "" +
		lineindent + "(library" +
		lineindent + " :name " + library.name +
		lineindent + " :path " + library.path +
		lineindent + " :lang " + library.lang +
		lineindent + " :doc  " + library.doc + ")"
	return output
}

func StringFromListLibrary(listlib []*vxlibrary) string {
	return StringFromListLibraryIndent(listlib, 0)
}

func StringFromListLibraryIndent(listlib []*vxlibrary, indent int) string {
	output := ""
	if len(listlib) > 0 {
		lineindent := ""
		if indent > 0 {
			lineindent = "\n" + StringRepeat(" ", indent)
		}
		output = lineindent + "(librarylist"
		for _, lib := range listlib {
			output += StringFromLibraryIndent(lib, indent+1)
		}
		output += ")"
	}
	return output
}
