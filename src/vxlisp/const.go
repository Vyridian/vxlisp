package vxlisp

import (
	"sort"
	"strings"
)

type vxconst struct {
	name          string
	alias         string
	deprecated    string
	doc           string
	multi         bool
	mutable       bool
	pkgname       string
	vxtype        *vxtype
	value         vxvalue
	listtestvalue []vxvalue
	textblock     *vxtextblock
}

func NewConst() *vxconst {
	output := new(vxconst)
	output.vxtype = emptytype
	output.value = emptyvalue
	output.textblock = emptytextblock
	return output
}

func NewMapConst() map[string]*vxconst {
	return make(map[string]*vxconst)
}

func ConstFromTextblock(textblock *vxtextblock, pkg *vxpackage) (*vxconst, *vxmsgblock) {
	msgblock := NewMsgBlock("ConstFromTextblock")
	cnst := NewConst()
	cnst.pkgname = pkg.name
	cnst.textblock = textblock
	var valuefound = false
	var lastword = ""
	var testcls = false
	var listtestvalue []vxvalue
	for i, wordtextblock := range textblock.listtextblock {
		word := wordtextblock.text
		switch i {
		case 0:
			if word != "const" {
				msg := NewMsgFromTextblock(
					textblock, 0, 0, "Invalid Const", word)
				msgblock = MsgblockAddError(msgblock, msg)
			}
		case 1:
			cnst.name = word
		default:
			if testcls {
				if strings.HasPrefix(word, ":") {
					testcls = false
				} else {
					testvalue, msgs := ValueFromTextblock(wordtextblock, emptyfunc, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					listtestvalue = append(listtestvalue, testvalue)
				}
			}
			if testcls {
			} else if lastword != "" {
				switch lastword {
				case ":":
					cnsttyp := NewType(word)
					pkgname := cnsttyp.pkgname
					if pkgname != "" {
						pkgname = LibraryPathFromPackage(pkg, pkgname)
						if pkgname != "" {
							cnsttyp.pkgname = pkgname
						} else {
							msg := NewMsgFromTextblock(
								textblock, 0, 0, "Package Not Found", word)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					}
					cnst.vxtype = cnsttyp
				case ":alias":
					cnst.alias = StringRemoveQuotes(word)
				case ":deprecated":
					cnst.deprecated = StringRemoveQuotes(word)
				case ":doc":
					cnst.doc = StringRemoveQuotes(word)
				}
				lastword = ""
			} else if strings.HasPrefix(word, ":") && (textblock.blocktype != "\"") {
				switch word {
				case ":", ":alias", ":deprecated", ":doc":
					lastword = word
				case ":mutable":
					cnst.mutable = true
				case ":test":
					testcls = true
				default:
					msg := NewMsgFromTextblock(
						textblock, 0, 0, "Invalid Keyword", word)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			} else if valuefound {
				msg := NewMsgFromTextblock(
					textblock, 0, 0, "More Than 1 Value", word)
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				valuefound = true
				value, msgs := ValueFromTextblock(
					wordtextblock, emptyfunc, pkg)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				cnst.value = value
			}
		}
	}
	if cnst.alias == "" {
		cnst.alias = cnst.name
	}
	if len(listtestvalue) > 0 {
		cnst.listtestvalue = listtestvalue
	}
	return cnst, msgblock
}

func ListConstLink(listconst []*vxconst, listscope []vxscope, path string) ([]*vxconst, *vxmsgblock) {
	msgblock := NewMsgBlock("ListConstLink")
	for _, cnst := range listconst {
		typ := cnst.vxtype
		subpath := path + "/" + cnst.name
		lookuptype, ok := TypeOrFuncFromListScope(
			listscope, typ.pkgname, typ.name, subpath)
		if ok {
			cnst.vxtype = lookuptype
		} else {
			msg := NewMsgFromTextblock(
				cnst.textblock, 0, 0, "Type Not Found", "subpath", subpath, "package", typ.pkgname, "type", typ.name)
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return listconst, msgblock
}

func ListConstLinkValues(
	listconst []*vxconst,
	listscope []vxscope,
	path string) ([]*vxconst, *vxmsgblock) {
	msgblock := NewMsgBlock("ListConstLinkValues")
	for _, cnst := range listconst {
		subpath := path + "/" + cnst.name
		value, msgs := ValueLink(cnst.value, cnst.vxtype, listscope, cnst.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		cnst.value = value
		listtestvalue, msgs := ListValueLink(cnst.listtestvalue, listscope, cnst.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		cnst.listtestvalue = listtestvalue
	}
	return listconst, msgblock
}

func ListConstFromTextblock(
	textblock *vxtextblock,
	pkg *vxpackage) ([]*vxconst, *vxmsgblock) {
	msgblock := NewMsgBlock("ListConstFromTextblock")
	var output []*vxconst
	for _, wordtextblock := range textblock.listtextblock {
		words := wordtextblock.listtextblock
		switch wordtextblock.blocktype {
		case "/*", "//":
		case "(":
			if len(words) == 0 {
				msg := NewMsgFromTextblock(
					textblock, 0, 0, "", "Empty Const")
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				firstword := words[0]
				switch firstword.text {
				case "const":
					cnst, msgs := ConstFromTextblock(wordtextblock, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					output = append(output, cnst)
				}
			}
		default:
			msg := NewMsgFromTextblock(
				textblock, 0, 0, "", "Invalid Const Blocktype")
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return output, msgblock
}

func ListConstValidate(
	listconst []*vxconst,
	path string) ([]*vxconst, *vxmsgblock) {
	msgblock := NewMsgBlock("ConstValidate")
	for _, cnst := range listconst {
		subpath := path + "/" + cnst.name
		value, _, msgs := ValueValidate(cnst.value, cnst.vxtype, false, emptygenerictypes, cnst.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		cnst.value = value
		listtestvalue, msgs := ListValueValidateTestFuncs(cnst.listtestvalue, cnst.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		cnst.listtestvalue = listtestvalue
	}
	return listconst, msgblock
}

func ListKeyFromMapConst(mapcnst map[string]*vxconst) []string {
	listkey := make([]string, 0, len(mapcnst))
	for id := range mapcnst {
		listkey = append(listkey, id)
	}
	sort.Strings(listkey)
	return listkey
}

func MapConstFromListConst(listconst []*vxconst) map[string]*vxconst {
	var output = NewMapConst()
	for _, val := range listconst {
		output[val.name] = val
	}
	return output
}

func NameFromConst(cnst *vxconst) string {
	return cnst.pkgname + "/" + cnst.name
}

func StringFromConst(cnst *vxconst) string {
	return StringFromConstIndent(cnst, 0)
}

func StringFromConstIndent(cnst *vxconst, indent int) string {
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output := "" +
		lineindent + "(const" +
		lineindent + " :name    " + cnst.name +
		lineindent + " :pkgname " + cnst.pkgname +
		lineindent + " :type    " + NameFromType(cnst.vxtype)
	if cnst.value.code != "" {
		output += lineindent + " :value " + StringFromValueIndent(cnst.value, indent+2)
	}
	output += ")"
	return output
}

func StringFromListConstIndent(listconst []*vxconst, indent int) string {
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output := lineindent + "["
	if len(listconst) > 0 {
		for _, cnst := range listconst {
			output += lineindent + StringFromConstIndent(cnst, indent+2)
		}
	}
	output += "]"
	return output
}
