package vxlisp

type vxlibrary struct {
	name string
	path string
	lang string
	doc  string
	pkg  *vxpackage
}

var emptylistlibrary = []*vxlibrary{}

func NewLibrary() *vxlibrary {
	return new(vxlibrary)
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

func MapLibraryFromListLibrary(listlibrary []*vxlibrary) map[string]*vxlibrary {
	output := NewMapLibrary()
	for _, library := range listlibrary {
		name := library.name
		output[name] = library
	}
	return output
}

func StringFromLibrary(library *vxlibrary) string {
	return StringFromLibraryIndent(library, "")
}

func StringFromLibraryIndent(library *vxlibrary, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		lineindent + "(library" +
		lineindent + " :name " + library.name +
		lineindent + " :path " + library.path +
		lineindent + " :lang " + library.lang +
		lineindent + " :doc  " + library.doc + ")"
	return output
}

func StringFromListLibrary(listlib []*vxlibrary) string {
	return StringFromListLibraryIndent(listlib, "")
}

func StringFromListLibraryIndent(listlib []*vxlibrary, indent string) string {
	output := "["
	for _, lib := range listlib {
		output += StringFromLibraryIndent(lib, indent+" ")
	}
	output += "]"
	return output
}
