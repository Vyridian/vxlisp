package vxlisp

type vxvalue struct {
	code        string
	name        string
	pkg         string
	multi       bool
	textblock   *vxtextblock
	vxtype      *vxtype
	generictype *vxtype
	native      interface{}
}

var emptyvalue = NewValue()

var emptyvalues []vxvalue

func NewValue() vxvalue {
	value := *new(vxvalue)
	value.textblock = emptytextblock
	value.vxtype = emptytype
	value.generictype = emptytype
	return value
}

func NewValueFromArg(arg vxarg) vxvalue {
	value := NewValue()
	return ValueSetArg(value, arg)
}

func NewValueFromArgList(args []vxarg) vxvalue {
	value := NewValue()
	return ValueSetListArg(value, args)
}

func NewValueFromConst(cnst *vxconst) vxvalue {
	value := NewValue()
	return ValueSetConst(value, cnst)
}

func NewValueFromDecimal(text string) vxvalue {
	value := NewValue()
	return ValueSetDecimal(value, text)
}

func NewValueFromFunc(fnc *vxfunc) vxvalue {
	value := NewValue()
	return ValueSetFunc(value, fnc)
}

func NewValueFromFuncRef(fnc *vxfunc) vxvalue {
	value := NewValue()
	return ValueSetFuncRef(value, fnc)
}

func NewValueFromInteger(text string) vxvalue {
	value := NewValue()
	return ValueSetInteger(value, text)
}

func NewValueFromString(text string) vxvalue {
	value := NewValue()
	return ValueSetString(value, text)
}

func NewValueFromType(typ *vxtype) vxvalue {
	value := NewValue()
	return ValueSetType(value, typ)
}

func NewValueFromUnknown(text string) vxvalue {
	value := NewValue()
	value.code = ":unknown"
	value.name = text
	value.pkg = ""
	return value
}

func ArgFromValue(value vxvalue) vxarg {
	var output vxarg
	switch value.code {
	case ":arg":
		output = value.native.(vxarg)
	}
	return output
}

func BooleanFromValue(value vxvalue) bool {
	var output = false
	switch value.code {
	case "boolean":
		output = value.native.(bool)
	default:
		var strval = StringValueFromValue(value)
		if strval == "" {
			output = false
		} else {
			output = true
		}
	}
	return output
}

func ConstFromValue(value vxvalue) *vxconst {
	var output *vxconst
	switch value.code {
	case ":const":
		output = value.native.(*vxconst)
	}
	return output
}

func FloatFromValue(value vxvalue) float64 {
	var output float64 = 0
	switch value.code {
	case "float", "number":
		output = value.native.(float64)
	case "int":
		output = FloatFromInt(value.native.(int))
	case "string":
		output = FloatFromString(value.native.(string))
	}
	return output
}

func FuncFromValue(value vxvalue) *vxfunc {
	var output *vxfunc
	switch value.code {
	case ":func", ":funcref":
		output = value.native.(*vxfunc)
	}
	return output
}

func IntFromValue(value vxvalue) int {
	var output int = 0
	switch value.code {
	case "int":
		output = value.native.(int)
	case "float", "number":
		output = IntFromFloat(value.native.(float64))
	case "string":
		output = IntFromString(value.native.(string))
	}
	return output
}

func ListArgFromValue(value vxvalue) []vxarg {
	var output []vxarg
	switch value.code {
	case ":arglist":
		output = value.native.([]vxarg)
	}
	return output
}

func ListValueLink(listvalue []vxvalue, scopes []vxscope, textblock *vxtextblock, path string) ([]vxvalue, *vxmsgblock) {
	msgblock := NewMsgBlock("ValuesLink")
	var output []vxvalue
	for _, value := range listvalue {
		chgvalue, msgs := ValueLink(value, emptytype, scopes, textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = append(output, chgvalue)
	}
	return output, msgblock
}

func ListValueValidateTestFuncs(listvalue []vxvalue, textblock *vxtextblock, path string) ([]vxvalue, *vxmsgblock) {
	msgblock := NewMsgBlock("ListValueValidateTestFuncs")
	var listtestvalue []vxvalue
	for idx, value := range listvalue {
		subpath := path + "/test" + StringFromInt(idx+1)
		switch value.code {
		case ":func":
			fnc := FuncFromValue(value)
			testname := fnc.name
			switch testname {
			case "test", "test-false", "test-ne", "test-string", "test-true":
				testvalue, _, msgs := ValueValidate(value, testresulttype, false, emptygenerictypes, textblock, subpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				listtestvalue = append(listtestvalue, testvalue)
			default:
				msg := NewMsgFromTextblock(textblock, path, "Test:", testname, "Func Must Be a Test")
				msgblock = MsgblockAddError(msgblock, msg)
			}
		}
	}
	return listtestvalue, msgblock
}

func StringFromListValue(listvalue []vxvalue) string {
	return StringFromListValueIndent(listvalue, "")
}

func StringFromListValueIndent(listvalue []vxvalue, indent string) string {
	lineindent := "\n" + indent
	output := "(valuelist"
	for _, value := range listvalue {
		output += lineindent + StringFromValueIndent(value, indent+" ")
	}
	output += ")"
	return output
}

func StringFromValue(value vxvalue) string {
	return StringFromValueIndent(value, " ")
}

func StringFromValueIndent(value vxvalue, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		"(value" +
		lineindent + ":code  " + value.code
	if value.name != "" {
		output += lineindent + ":name  " + value.name
	}
	if value.pkg != "" {
		output += lineindent + ":pkg   " + value.pkg
	}
	if value.vxtype == nil {
	} else if value.vxtype.name != "" {
		output += lineindent + ":type  " + NameFromType(value.vxtype)
	}
	if value.generictype.name != "" {
		output += lineindent + ":generictype " + NameFromType(value.generictype)
	}
	if value.multi {
		output += lineindent + ":multi " + StringFromBoolean(value.multi)
	}
	output += lineindent + ":value "
	switch value.code {
	case ":arg":
		arg := ArgFromValue(value)
		output += StringFromArgIndent(arg, indent+" ")
	case ":arglist":
		args := ListArgFromValue(value)
		output += StringFromListArgIndent(args, indent+" ")
	case ":const":
		output += NameFromConst(ConstFromValue(value))
	case ":func":
		output += StringFromFuncIndent(FuncFromValue(value), indent+" ")
	case ":funcref":
		output += NameFromFunc(FuncFromValue(value))
	case ":type":
		output += NameFromType(TypeFromValue(value))
	case "decimal", "int", "number", "string", ":unknown":
		output += StringValueFromValue(value)
	}
	output += ")"
	return output
}

func StringValueFromValue(value vxvalue) string {
	var output = ""
	switch value.code {
	case "decimal", "int", "number", "string":
		output = value.native.(string)
	}
	return output
}

func TypeFromValue(value vxvalue) *vxtype {
	var output *vxtype
	switch value.code {
	case ":type":
		output = value.native.(*vxtype)
	}
	return output
}

func ValueSetArg(value vxvalue, arg vxarg) vxvalue {
	value.code = ":arg"
	value.native = arg
	value.vxtype = arg.vxtype
	return value
}

func ValueSetListArg(value vxvalue, args []vxarg) vxvalue {
	value.code = ":arglist"
	value.native = args
	value.vxtype = arglisttype
	return value
}

func ValueSetBoolean(value vxvalue, boolvalue bool) vxvalue {
	value.code = "boolean"
	value.name = ""
	value.pkg = ""
	value.native = boolvalue
	value.vxtype = booleantype
	return value
}

func ValueSetConst(value vxvalue, cnst *vxconst) vxvalue {
	value.code = ":const"
	value.name = cnst.name
	value.pkg = cnst.pkgname
	value.multi = cnst.multi
	value.native = cnst
	value.vxtype = cnst.vxtype
	return value
}

func ValueSetDecimal(value vxvalue, text string) vxvalue {
	value.code = "decimal"
	value.name = ""
	value.pkg = ""
	value.native = text
	value.vxtype = decimaltype
	return value
}

func ValueSetFunc(value vxvalue, fnc *vxfunc) vxvalue {
	value.code = ":func"
	value.name = fnc.name
	value.pkg = fnc.pkgname
	value.native = fnc
	value.vxtype = fnc.vxtype
	/*
		if fnc.mapgeneric != nil {
			switch NameFromType(fnc.vxtype) {
			case "vx/core/any", "vx/core/list", "vx/core/map":
				generictype, ok := MapTypeGetType(fnc.mapgeneric, ":1")
				if ok {
					value.vxtype = generictype
				}
			}
		}
	*/
	return value
}

func ValueSetFuncRef(value vxvalue, fnc *vxfunc) vxvalue {
	value.code = ":funcref"
	value.name = fnc.name
	value.pkg = fnc.pkgname
	value.native = fnc
	value.vxtype = fnc.vxtype
	return value
}

func ValueSetInteger(value vxvalue, text string) vxvalue {
	value.code = "int"
	value.name = ""
	value.pkg = ""
	value.native = text
	value.vxtype = inttype
	return value
}

func ValueSetString(value vxvalue, text string) vxvalue {
	value.code = "string"
	value.name = ""
	value.pkg = ""
	value.native = text
	value.vxtype = stringtype
	return value
}

func ValueSetType(value vxvalue, typ *vxtype) vxvalue {
	value.code = ":type"
	value.name = typ.name
	value.pkg = typ.pkgname
	value.native = typ
	value.vxtype = typ
	return value
}

func ValueFromTextblock(textblock *vxtextblock, parentfunc *vxfunc, pkg *vxpackage) (vxvalue, *vxmsgblock) {
	msgblock := NewMsgBlock("ValueFromTextblock")
	output := NewValue()
	text := textblock.text
	switch textblock.blocktype {
	case "/*", "//":
	case "(":
		clausetextblocks := textblock.listtextblock
		partslen := len(clausetextblocks)
		var addtoend []vxarg
		var fnc = NewFunc()
		lastword := ""
		for idx, clausetextblock := range clausetextblocks {
			switch clausetextblock.blocktype {
			case "/*", "//":
			default:
				clausepart := clausetextblock.text
				switch idx {
				case 0:
					fncname := clausepart
					if BooleanFromStringStarts(fncname, ":") {
						keyname := StringSubstring(fncname, 1, len(fncname))
						if BooleanIsIntFromString(keyname) {
							fncname = "any<-list"
							arg := NewArg(":unknown")
							arg.value = NewValueFromInteger(keyname)
							addtoend = append(addtoend, arg)
						} else {
							fncname = "any<-map"
							arg := NewArg(":unknown")
							arg.value = NewValueFromString(clausepart)
							addtoend = append(addtoend, arg)
						}
					} else if fncname == "/" {
					} else {
						pos := IntFromStringIndexLast(fncname, "/")
						if pos >= 0 {
							pkgcode := fncname[0:pos]
							pkgpath := LibraryPathFromPackage(pkg, pkgcode)
							fnc.pkgname = pkgpath
							fncname = fncname[pos+1:]
						}
					}
					fnc.name = fncname
					fnc.alias = fncname
				default:
					switch lastword {
					case ":":
						fnc.vxtype = NewType(clausepart)
						lastword = ""
					default:
						lastword = ""
						switch clausepart {
						case ":":
							lastword = clausepart
						case ":native":
						default:
							if idx < (partslen-1) && (clausetextblocks[idx+1].text == ":native") {
								nativeconst := NewConst()
								nativeconst.name = clausepart
								nativeconst.pkgname = ":native"
								arg := NewArg(":unknown")
								arg.value = NewValueFromConst(nativeconst)
								fnc.listarg = append(fnc.listarg, arg)
							} else {
								arg := NewArg(":unknown")
								val, msgs := ValueFromTextblock(clausetextblock, fnc, pkg)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								arg.value = val
								fnc.listarg = append(fnc.listarg, arg)
							}
						}
					}
				}
			}
		}
		if len(addtoend) > 0 {
			fnc.listarg = append(fnc.listarg, addtoend...)
		}
		switch fnc.name {
		case "<-", "<<-":
			var prevarg vxarg
			for argidx, arg := range fnc.listarg {
				switch argidx {
				case 0:
					prevarg = arg
				default:
					currvalue := arg.value
					switch currvalue.code {
					case ":func":
						currfunc := FuncFromValue(currvalue)
						switch fnc.name {
						case "<<-":
							currfunc.listarg = append(currfunc.listarg, prevarg)
						default:
							currfunc.listarg = append([]vxarg{prevarg}, currfunc.listarg...)
						}
						currvalue = ValueSetFunc(currvalue, currfunc)
						arg.value = currvalue
					}
					prevarg = arg
				}
			}
			currvalue := prevarg.value
			switch currvalue.code {
			case ":func":
				fnc = FuncFromValue(currvalue)
			default:
				msg := NewMsgFromTextblock(textblock, "Last Argument in <- or <<- must be a Function", StringFromValue(currvalue))
				msgblock = MsgblockAddError(msgblock, msg)
			}
		}
		output = NewValueFromFunc(fnc)
	case "[":
		switch parentfunc.name {
		case "fn", "let":
			args, msgs := ListArgFromTextblock(textblock, parentfunc, pkg)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			output = NewValueFromArgList(args)
		default:
			// list of any
			fnc := NewFunc()
			fnc.name = "new"
			textblocks := textblock.listtextblock
			if len(textblocks) == 0 {
				fnc.name = "empty"
			} else {
				newtextblock := NewTextblockFromText("list")
				var prefixargs = []*vxtextblock{newtextblock}
				textblocks = append(prefixargs, textblocks...)
				for _, clausepart := range textblocks {
					subarg := NewArg(":unknown")
					val, msgs := ValueFromTextblock(clausepart, fnc, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					subarg.value = val
					fnc.listarg = append(fnc.listarg, subarg)
				}
			}
			output = NewValueFromFunc(fnc)
		}
	case "\"", "`":
		text = StringFromStringFindReplace(text, "“", "\"")
		text = StringFromStringFindReplace(text, "”", "\"")
		output = NewValueFromString("\"" + text + "\"")
	case "text":
		if BooleanFromStringStarts(text, ":") {
			output = NewValueFromString(text)
		} else if text == "infinity" {
			output = NewValueFromUnknown(text)
		} else if BooleanIsIntFromString(text) {
			output = NewValueFromInteger(text)
		} else if BooleanIsNumberFromString(text) {
			output = NewValueFromDecimal(text)
		} else {
			output = NewValueFromUnknown(text)
		}
	}
	output.textblock = textblock
	return output, msgblock
}

func ValueLink(value vxvalue, expectedtype *vxtype, listscope []vxscope, textblock *vxtextblock, path string) (vxvalue, *vxmsgblock) {
	msgblock := NewMsgBlock("ValueLink")
	output := value
	subpath := path + "/:value"
	switch value.code {
	case ":arg":
		arg := ArgFromValue(value)
		arg, msgs := ArgLink(arg, listscope, textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = ValueSetArg(value, arg)
	case ":arglist":
		args := ListArgFromValue(value)
		args, msgs := ListArgLink(args, listscope, textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = ValueSetListArg(value, args)
	case ":unknown":
		subpath += "/" + value.name
		lookuparg, ok := ArgFromListScope(listscope, value.name)
		if ok {
			argtype := lookuparg.vxtype
			if argtype.name != "" && argtype.pkgname == "" {
				lookuptype, ok := TypeOrFuncFromListScope(listscope, "", argtype.name, subpath)
				if ok {
					lookuparg.vxtype = lookuptype
				} else {
					msg := NewMsgFromTextblock(textblock, subpath, "Arg Type Not Found", value.code, value.name, argtype.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			output = NewValueFromArg(lookuparg)
		} else {
			lookupconst, ok := ConstFromListScope(listscope, value.pkg, value.name)
			if ok {
				output = NewValueFromConst(lookupconst)
			} else {
				lookuptype, ok := TypeFromListScope(listscope, value.pkg, value.name, subpath)
				if ok {
					output = NewValueFromType(lookuptype)
				} else {
					lookupfunc, ok := FuncFromListScope(listscope, value.pkg, value.name, emptysignature, subpath)
					if ok {
						output = NewValueFromFuncRef(lookupfunc)
					} else {
						msg := NewMsgFromTextblock(textblock, subpath, "Value Not Found", value.code, value.name)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				}
			}
		}
	case ":func":
		fnc := FuncFromValue(value)
		subpath += "/" + fnc.name
		if fnc.idx > 0 {
			subpath += "/" + StringFromInt(fnc.idx)
		}
		functype := fnc.vxtype
		if functype.name == "" {
			functype = expectedtype
		}
		if functype.name != "" {
			lookuptype, ok := TypeOrFuncFromListScope(listscope, functype.pkgname, functype.name, subpath)
			if ok {
				fnc.vxtype = lookuptype
				if lookuptype.isgeneric {
					fnc.generictype = lookuptype
				}
			}
		}
		switch NameFromFunc(fnc) {
		case "vx/core/fn":
			args := fnc.listarg
			if len(args) > 0 {
				lastpos := len(args) - 1
				arg := args[lastpos]
				arg.vxtype = fnc.vxtype
				args[lastpos] = arg
				fnc.listarg = args
			}
		}
		listscope = ListScopeAddFuncLocalArg(listscope, fnc)
		chgargs, msgs := ListArgLink(fnc.listarg, listscope, textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listarg = chgargs
		origfunc := fnc
		if !fnc.iscopied {
			signature := SignatureFromFunc(fnc, subpath)
			lookupfunc, ok := FuncFromListScope(listscope, origfunc.pkgname, origfunc.name, signature, subpath)
			if ok {
				fnc = NewFuncCopy(lookupfunc)
				fnc.textblock = origfunc.textblock
				if origfunc.vxtype.name != "" {
					fnc.vxtype = origfunc.vxtype
				}
			} else {
				lookuptype, ok := TypeFromListScope(listscope, origfunc.pkgname, origfunc.name, subpath)
				if ok && !lookuptype.isfunc {
					if len(origfunc.listarg) == 0 {
						// (type) -> (empty type)
						lookupfunc, ok := FuncFromListScope(listscope, "", "empty", emptysignature, subpath)
						if ok {
							fnc = NewFuncCopy(lookupfunc)
							fnc.textblock = origfunc.textblock
							fnc = FuncSetType(fnc, lookuptype)
							typearg := NewArgFromType(lookuptype)
							origfunc.listarg = []vxarg{typearg}
						} else {
							msg := NewMsgFromTextblock(textblock, subpath, "Empty Function Not Found")
							msgblock = MsgblockAddError(msgblock, msg)
						}
					} else {
						// (type arg1 argn) -> (new type arg1 argn)
						lookupfunc, ok := FuncFromListScope(listscope, "", "new", emptysignature, subpath)
						if ok {
							fnc = NewFuncCopy(lookupfunc)
							fnc.textblock = origfunc.textblock
							fnc = FuncSetType(fnc, lookuptype)
							typearg := NewArgFromType(lookuptype)
							origfunc.listarg = append([]vxarg{typearg}, origfunc.listarg...)
						} else {
							msg := NewMsgFromTextblock(textblock, subpath, "New Function Not Found")
							msgblock = MsgblockAddError(msgblock, msg)
						}
					}
				} else {
					msg := NewMsgFromTextblock(textblock, subpath, "Function Not Found", origfunc.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
		}
		chgargs, msgs = ListArgMergeValues(origfunc.listarg, fnc.listarg, textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listarg = chgargs
		output = ValueSetFunc(output, fnc)
	}
	return output, msgblock
}

func ValueValidate(value vxvalue, expectedtype *vxtype, multi bool, mapgeneric map[string]*vxtype, textblock *vxtextblock, path string) (vxvalue, map[string]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("ValueValidate")
	pass := false
	expectedtypename := NameFromType(expectedtype)
	actualtype := value.vxtype
	subpath := path + "/:value"
	var msgs *vxmsgblock
	switch value.pkg {
	case ":native":
		// values marked native are not typechecked
		pass = true
	default:
		switch expectedtype.isfunc {
		case true:
			expectedfuncref := expectedtype.vxfunc
			expectedfuncname := NameFromFunc(expectedfuncref)
			switch value.code {
			case ":func":
				actualfunc := FuncFromValue(value)
				actualfuncname := NameFromFunc(actualfunc)
				switch actualfuncname {
				case "vx/core/fn":
					actualargs := FuncFnGetArgList(actualfunc)
					if len(expectedfuncref.listarg) != len(actualargs) {
						msg := NewMsgFromTextblock(textblock, "Value with Lambda (fn) must have the same number of arguments", len(expectedfuncref.listarg), len(actualfunc.listarg), "\n"+subpath+"\n", StringFromValue(value))
						msgblock = MsgblockAddError(msgblock, msg)
					} else {
						var chgargs []vxarg
						for i := range expectedfuncref.listarg {
							actualarg := actualargs[i]
							chgargs = append(chgargs, actualarg)
						}
						actualfunc = FuncFnSetListArg(actualfunc, chgargs)
						var msgs *vxmsgblock
						actualfunc, msgs = FuncValidate(actualfunc, textblock, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						mapgeneric, msgs = MapTypeMerge(mapgeneric, actualfunc.mapgeneric, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						expectedsignature := SignatureFromFunc(expectedfuncref, subpath)
						actualsignature := SignatureFromFunc(actualfunc, subpath)
						pass = IsSignatureMatch(expectedsignature, actualsignature, 0, subpath)
						if pass {
							actualtype = expectedtype
						}
					}
				default:
					switch expectedtypename {
					case "vx/core/any<-func", "vx/core/any<-func-async", "vx/core/boolean<-func", "vx/core/int<-func", "vx/core/number<-func", "vx/core/string<-func":
						actualtype := actualfunc.vxtype
						if actualtype.isgeneric {
							genericname := actualtype.name
							lookuptype, ok := mapgeneric[genericname]
							if ok {
								actualfunc.vxtype = lookuptype
								if actualfunc.generictype == nil {
									actualfunc.generictype = actualtype
								}
							}
						}
						actualfunc, msgs = FuncValidate(actualfunc, textblock, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						mapgeneric, msgs = MapTypeMerge(mapgeneric, actualfunc.mapgeneric, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						//actualtype = actualfunc.vxtype
						pass = true
					case "vx/core/any<-any", "vx/core/any<-any-async", "v/core/any<-key-value", "vx/core/any<-key-value-async":
						actualargs := actualfunc.listarg
						if len(expectedfuncref.listarg) != len(actualargs) {
							msg := NewMsgFromTextblock(textblock, "Value with Function Type must have the same number of arguments", len(expectedfuncref.listarg), len(actualfunc.listarg), expectedfuncname, actualfuncname, "\n"+subpath+"\n", StringFromValue(value))
							msgblock = MsgblockAddError(msgblock, msg)
						} else {
							var chgargs []vxarg
							for i := range expectedfuncref.listarg {
								actualarg := actualargs[i]
								chgargs = append(chgargs, actualarg)
							}
							actualfunc.listarg = chgargs
							actualfunc, msgs = FuncValidate(actualfunc, textblock, subpath)
							msgblock = MsgblockAddBlock(msgblock, msgs)
							mapgeneric, msgs = MapTypeMerge(mapgeneric, actualfunc.mapgeneric, subpath)
							msgblock = MsgblockAddBlock(msgblock, msgs)
							expectedsignature := SignatureFromFunc(expectedfuncref, subpath)
							actualsignature := SignatureFromFunc(actualfunc, subpath)
							pass = IsSignatureMatch(expectedsignature, actualsignature, 0, subpath)
							if pass {
								actualtype = expectedtype
							}
						}
					default:
						msg := NewMsgFromTextblock(textblock, "Value with Function Type can only be a lambda (fn) or refer to another function", NameFromFunc(expectedfuncref), NameFromFunc(actualfunc), "\n"+subpath+"\n", StringFromValue(value))
						msgblock = MsgblockAddError(msgblock, msg)
					}
				}
			case ":funcref":
				actualfuncref := FuncFromValue(value)
				expectedsignature := SignatureFromFunc(expectedfuncref, subpath)
				actualsignature := SignatureFromFunc(actualfuncref, subpath)
				pass = IsSignatureMatch(expectedsignature, actualsignature, 0, subpath)
			case "":
				pass = true
			default:
				if actualtype.isfunc {
					actualfunc := actualtype.vxfunc
					actualtype = actualfunc.vxtype
				}
				subtype := expectedfuncref.vxtype
				actualtype, pass, msgs = IsTypeSimpleMatch(subtype, actualtype, multi, 0, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
			}
			if IsErrorFromMsgblock(msgblock) {
			} else if pass {
				switch NameFromType(actualtype) {
				case "/":
					value.vxtype = expectedtype
				default:
					value.vxtype = actualtype
				}
			} else {
				msg := NewMsgFromTextblock(textblock, "Value Function Type does not match expected type", NameFromType(expectedtype), NameFromType(actualtype), "\n"+subpath+"\n", StringFromValue(value))
				msgblock = MsgblockAddError(msgblock, msg)
			}
		default:
			switch value.code {
			case ":arg":
				arg := ArgFromValue(value)
				arg, mapgeneric, msgs = ArgValidate(arg, mapgeneric, textblock, subpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				value = ValueSetArg(value, arg)
			case ":arglist":
				arglist := ListArgFromValue(value)
				subpath = path + "/:arglist"
				arglist, mapgeneric, msgs = ListArgValidate(arglist, mapgeneric, textblock, subpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				value = ValueSetListArg(value, arglist)
				if expectedtypename == "vx/core/arglist" {
					pass = true
				}
			case ":const":
				cnst := ConstFromValue(value)
				subpath = path + "/" + cnst.name
				actualtype = cnst.vxtype
				pass, msgs = BooleanAllowFromTypeConst(expectedtype, cnst)
				msgblock = MsgblockAddBlock(msgblock, msgs)
			case ":func":
				fnc := FuncFromValue(value)
				if fnc.isgeneric {
					if expectedtype.isgeneric {
					} else if fnc.generictype == nil {
					} else {
						if fnc.vxtype.isgeneric {
							fnc.vxtype = expectedtype
						}
						fnc.mapgeneric = MapGenericSetType(fnc.mapgeneric, fnc.generictype.name, fnc.vxtype)
					}
				}
				fnc, msgs = FuncValidate(fnc, textblock, subpath)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				actualtype = fnc.vxtype
				switch NameFromFunc(fnc) {
				case "vx/core/let":
					lambdaargs := FuncFnGetArgList(fnc)
					for _, lambdaarg := range lambdaargs {
						if lambdaarg.async {
							fnc.async = true
						}
					}
				}
			case ":funcref":
				fnc := FuncFromValue(value)
				actualtype = fnc.vxtype
				pass, msgs = BooleanAllowFromTypeFunc(expectedtype, fnc, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
			case ":type":
				actualtype = TypeFromValue(value)
			case "":
				switch expectedtypename {
				case "/", "vx/core/unknown", "vx/core/any":
					pass = true
				default:
					actualtype = expectedtype
					/*
						} else {
							var ok bool
							actualtype, ok = MapTypeGetType(mapgeneric, expectedgeneric)
							if !ok {
								actualtype = expectedtype
							}
						}*/
				}
			}
			if !pass {
				actualtype, pass, msgs = IsTypeSimpleMatch(expectedtype, actualtype, multi, -1, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				if pass {
					value.vxtype = actualtype
				}
			}
		}
		if IsErrorFromMsgblock(msgblock) {
		} else if value.code == "" {
		} else if !pass {
			msg := NewMsgFromTextblock(textblock, path, value.code, "Value Type does not match expected type", NameFromType(expectedtype), NameFromType(actualtype), "\n"+subpath+"\n", StringFromValue(value))
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return value, mapgeneric, msgblock
}
