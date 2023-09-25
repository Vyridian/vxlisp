package vxlisp

import (
	"sort"
	"strings"
)

type vxarg struct {
	name        string
	alias       string
	doc         string
	isdefault   bool
	isgeneric   bool
	generictype *vxtype
	mapgeneric  map[string]*vxtype
	multi       bool
	async       bool
	vxtype      *vxtype
	value       vxvalue
}

var emptyarg = NewArg("")

var argcontext = NewArgContext()

func NewArg(name string) vxarg {
	output := *new(vxarg)
	output.name = name
	output.alias = name
	output.vxtype = emptytype
	output.value = emptyvalue
	return output
}

func NewArgCopy(arg vxarg) vxarg {
	output := *new(vxarg)
	output.name = arg.name
	output.alias = arg.name
	output.async = arg.async
	output.multi = arg.multi
	output.isdefault = arg.isdefault
	output.isgeneric = arg.isgeneric
	output.generictype = arg.generictype
	output.mapgeneric = arg.mapgeneric
	output.vxtype = arg.vxtype
	output.value = emptyvalue
	return output
}

func NewArgContext() vxarg {
	contexttype := NewType("context")
	contexttype.pkgname = "vx/core"
	contexttype.extends = ":struct"
	output := *new(vxarg)
	output.name = "context"
	output.alias = "context"
	output.vxtype = contexttype
	output.value = emptyvalue
	return output
}

func NewArgFromType(typ *vxtype) vxarg {
	output := NewArg(typ.name)
	output.value = NewValueFromType(typ)
	return output
}

func NewListArgCopy(arglist []vxarg) []vxarg {
	var output []vxarg
	for _, arg := range arglist {
		chgarg := NewArgCopy(arg)
		output = append(output, chgarg)
	}
	return output
}

func NewMapArg() map[string]vxarg {
	return make(map[string]vxarg)
}

func ArgLink(arg vxarg, listscope []vxscope, textblock *vxtextblock, path string) (vxarg, *vxmsgblock) {
	msgblock := NewMsgBlock("ArgLink")
	subpath := path + "/:arg/" + arg.name
	typ := arg.vxtype
	if typ.pkgname != "" {
	} else if typ.name != "" {
		lookuptype, ok := TypeOrFuncFromListScope(listscope, typ.pkgname, typ.name, subpath)
		if ok {
			arg.vxtype = lookuptype
		} else {
			msg := NewMsgFromTextblock(textblock, "Type Not Found", typ.pkgname, typ.name, "\n"+subpath)
			msgblock = MsgblockAddError(msgblock, msg)
		}
		if !ok {
		} else if !arg.multi {
		} else if arg.vxtype.extends != ":list" {
			msg := NewMsgFromTextblock(textblock, "Argument is marked as multi but its type is not a list", NameFromType(arg.vxtype), "\n"+path)
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	if arg.generictype != nil {
		generictype := arg.generictype
		lookuptype, ok := TypeOrFuncFromListScope(listscope, generictype.pkgname, generictype.name, subpath)
		if ok {
			arg.generictype = lookuptype
		} else {
			msg := NewMsgFromTextblock(textblock, "Generic Type Not Found", generictype.pkgname, generictype.name, "\n"+subpath)
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	value, msgs := ValueLink(arg.value, arg.vxtype, listscope, textblock, subpath)
	switch value.code {
	case ":func", ":funcref":
		valuefnc := FuncFromValue(value)
		if valuefnc.async {
			arg.async = true
		}
	}
	msgblock = MsgblockAddBlock(msgblock, msgs)
	arg.value = value
	return arg, msgblock
}

func ArgMapFromArgList(listarg []vxarg) map[string]vxarg {
	maparg := make(map[string]vxarg)
	for _, arg := range listarg {
		maparg[arg.name] = arg
	}
	return maparg
}

func ArgValidate(arg vxarg, mapgeneric map[string]*vxtype, textblock *vxtextblock, path string) (vxarg, map[string]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("ArgValidate")
	subpath := path + "/:arg/" + arg.name
	var msgs *vxmsgblock
	var value vxvalue
	value, mapgeneric, msgs = ValueValidate(arg.value, arg.vxtype, arg.multi, mapgeneric, textblock, subpath)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	valuetype := value.vxtype
	if arg.generictype == nil {
	} else if valuetype.name == "" {
	} else if valuetype.isgeneric {
	} else if !valuetype.isfunc {
		lookuptype, ok := mapgeneric[arg.generictype.name]
		if ok && !lookuptype.isgeneric {
			valuetype = lookuptype
		} else {
			mapgeneric = MapGenericSetType(mapgeneric, arg.generictype.name, valuetype)
		}
		if !arg.vxtype.isfunc {
			arg.vxtype = valuetype
		}
	}
	switch value.code {
	case ":arg":
		// The value of the argument is another higher level argument
		subarg := ArgFromValue(value)
		subargtyp := subarg.vxtype
		if !arg.multi {
			if subarg.multi {
				subarg.multi = false
				value = ValueSetArg(value, subarg)
			}
		} else {
			if !subarg.multi {
			} else if subargtyp.extends == ":list" {
				// Both arguments are lists so should not be 'exploded'
				subarg.multi = true
				value = ValueSetArg(value, subarg)
			}
		}
	}
	arg.value = value
	if arg.isgeneric {
		arg.mapgeneric = mapgeneric
	}
	return arg, mapgeneric, msgblock
}

func ListArgFromMapArg(maparg map[string]vxarg) []vxarg {
	var output []vxarg
	for _, arg := range maparg {
		output = append(output, arg)
	}
	return output
}

func ListArgFromTextblock(textblock *vxtextblock, fnc *vxfunc, pkg *vxpackage) ([]vxarg, *vxmsgblock) {
	msgblock := NewMsgBlock("ListArgFromTextblock")
	//	typmap := prj.vxtype_map
	var listarg []vxarg
	var lastargstr = ""
	var arg vxarg
	for _, argtextblock := range textblock.listtextblock {
		switch argtextblock.blocktype {
		case "/*", "//":
		default:
			argstr := argtextblock.text
			switch lastargstr {
			case ":":
				argtyp := NewType(argstr)
				if argtyp.pkgname != "" {
					pkgname := LibraryPathFromPackage(pkg, argtyp.pkgname)
					if pkgname != "" {
						argtyp.pkgname = pkgname
					} else {
						msg := NewMsgFromTextblock(textblock, "Package Not Found:", argstr)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				}
				arg.vxtype = argtyp
				if argtyp.isgeneric {
					arg.isgeneric = true
					arg.generictype = arg.vxtype
				}
			case "::":
				argtyp := NewType(argstr)
				if argtyp.pkgname != "" {
					pkgname := LibraryPathFromPackage(pkg, argtyp.pkgname)
					if pkgname != "" {
						argtyp.pkgname = pkgname
					} else {
						msg := NewMsgFromTextblock(textblock, "Package Not Found:", argstr)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				}
				arg.generictype = argtyp
			case ":alias":
				arg.alias = argstr
			case ":doc":
				arg.doc = argstr
			case ":=":
				value, msgs := ValueFromTextblock(argtextblock, fnc, pkg)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				arg.value = value
			default:
				if strings.HasPrefix(argstr, ":") {
					switch argstr {
					case ":", "::", ":alias", ":doc", ":=":
					case ":default":
						arg.isdefault = true
					case ":...":
						arg.multi = true
					default:
						msg := NewMsgFromTextblock(textblock, "Invalid Keyword:", argstr)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				} else {
					if arg.name != "" {
						listarg = append(listarg, arg)
					}
					arg = NewArg(argstr)
				}
			}
			lastargstr = argstr
		}
	}
	if arg.name != "" {
		listarg = append(listarg, arg)
	}
	return listarg, msgblock
}

func ListArgLink(listarg []vxarg, scopes []vxscope, textblock *vxtextblock, path string) ([]vxarg, *vxmsgblock) {
	msgblock := NewMsgBlock("ListArgLink")
	var output []vxarg
	for _, arg := range listarg {
		arg, msgs := ArgLink(arg, scopes, textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = append(output, arg)
	}
	return output, msgblock
}

func ListArgMergeValues(listfromarg []vxarg, listtoarg []vxarg, textblock *vxtextblock, path string) ([]vxarg, *vxmsgblock) {
	msgblock := NewMsgBlock("ListArgMergeValues")
	output := listtoarg
	toargcnt := len(listtoarg)
	fromargcnt := len(listfromarg)
	if fromargcnt < toargcnt {
		msg := NewMsgFromTextblock(textblock, path, "Too Few Arguments", StringFromListArg(listfromarg), StringFromListArg(listtoarg))
		msgblock = MsgblockAddError(msgblock, msg)
	} else if fromargcnt == 0 && toargcnt == 0 {
	} else if toargcnt == 0 && fromargcnt > 0 {
		msg := NewMsgFromTextblock(textblock, path, "Too Many Arguments", fromargcnt, toargcnt)
		msgblock = MsgblockAddError(msgblock, msg)
	} else {
		lastarg := listtoarg[toargcnt-1]
		if fromargcnt > toargcnt && !lastarg.multi {
			msg := NewMsgFromTextblock(textblock, path, "Too Many Arguments", fromargcnt, toargcnt)
			msgblock = MsgblockAddError(msgblock, msg)
		} else {
			var chgargs []vxarg
			for argidx, arg := range listfromarg {
				chgarg := lastarg
				if argidx < toargcnt {
					chgarg = listtoarg[argidx]
				}
				chgarg.value = arg.value
				if chgarg.vxtype.isgeneric {
					chgarg.vxtype = arg.vxtype
				}
				chgargs = append(chgargs, chgarg)
			}
			output = chgargs
		}
	}
	return output, msgblock
}

func ListArgValidate(listarg []vxarg, mapgeneric map[string]*vxtype, textblock *vxtextblock, path string) ([]vxarg, map[string]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("ListArgValidate")
	var output []vxarg
	for _, arg := range listarg {
		var chgarg vxarg
		var msgs *vxmsgblock
		chgarg, mapgeneric, msgs = ArgValidate(arg, mapgeneric, textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = append(output, chgarg)
	}
	return output, mapgeneric, msgblock
}

func ListKeyFromMapArg(maparg map[string]vxarg) []string {
	listkey := make([]string, 0, len(maparg))
	for id := range maparg {
		listkey = append(listkey, id)
	}
	sort.Strings(listkey)
	return listkey
}

func StringFromArg(arg vxarg) string {
	return StringFromArgIndent(arg, " ")
}

func StringFromArgIndent(arg vxarg, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		"(arg" +
		lineindent + ":name  " + arg.name +
		lineindent + ":alias " + arg.alias
	if arg.vxtype.name != "" {
		output += lineindent + ":type  " + NameFromType(arg.vxtype)
	}
	if arg.isgeneric {
		output += lineindent + ":isgeneric " + StringFromBoolean(arg.isgeneric)
	}
	if arg.generictype != nil {
		output += lineindent + ":generictype " + NameFromType(arg.generictype)
	}
	if len(arg.mapgeneric) > 0 {
		output += lineindent + ":genericmap " + ListNameFromMapType(arg.mapgeneric)
	}
	if arg.async {
		output += lineindent + ":async " + StringFromBoolean(arg.async)
	}
	if arg.doc != "" {
		output += lineindent + ":doc " + arg.doc
	}
	if arg.multi {
		output += lineindent + ":multi " + StringFromBoolean(arg.multi)
	}
	if arg.value.code != "" {
		output += lineindent + ":value " + StringFromValueIndent(arg.value, indent+" ")
	}
	if arg.isdefault {
		output += lineindent + ":default " + StringFromBoolean(arg.isdefault)
	}
	output += ")"
	return output
}

func StringFromListArg(listarg []vxarg) string {
	return StringFromListArgIndent(listarg, " ")
}

func StringFromListArgIndent(listarg []vxarg, indent string) string {
	lineindent := "\n" + indent
	output := "(arglist"
	for _, arg := range listarg {
		output += lineindent + StringFromArgIndent(arg, indent+" ")
	}
	output += ")"
	return output
}

func StringFromMapArg(maparg map[string]vxarg) string {
	return StringFromMapArgIndent(maparg, "")
}

func StringFromMapArgIndent(maparg map[string]vxarg, indent string) string {
	listkey := make([]string, 0, len(maparg))
	for id := range maparg {
		listkey = append(listkey, id)
	}
	sort.Strings(listkey)
	var listtext []string
	for _, id := range listkey {
		arg := maparg[id]
		listtext = append(listtext, StringFromArg(arg))
	}
	return StringFromListStringJoin(listtext, "\n"+indent)
}

func TypeFromArg(arg vxarg) *vxtype {
	output := arg.vxtype
	if arg.value.vxtype != nil {
		output = arg.value.vxtype
	}
	return output
}
