package vxlisp

type vxfunc struct {
	name          string
	pkgname       string
	alias         string
	listarg       []vxarg
	async         bool
	bigospace     string
	bigotime      string
	clientserver  string
	context       bool
	debug         bool
	deprecated    string
	doc           string
	generictype   *vxtype
	mapgeneric    map[string]*vxtype
	idx           int
	iscopied      bool
	isgeneric     bool
	messages      bool
	parallel      bool
	permission    bool
	protected     bool
	private       bool
	sideeffects   string
	listtestvalue []vxvalue
	textblock     *vxtextblock
	value         vxvalue
	vxtype        *vxtype
	wrapper       bool
}

var emptyfunc = NewFunc()

var emptysignature = NewSignature()

func NewFunc() *vxfunc {
	output := new(vxfunc)
	output.vxtype = emptytype
	output.textblock = emptytextblock
	return output
}

func NewFuncCopy(fnc *vxfunc) *vxfunc {
	output := NewFunc()
	output.pkgname = fnc.pkgname
	output.name = fnc.name
	output.idx = fnc.idx
	output.alias = fnc.alias
	output.clientserver = fnc.clientserver
	output.context = fnc.context
	output.vxtype = fnc.vxtype
	output.async = fnc.async
	output.deprecated = fnc.deprecated
	output.iscopied = true
	output.isgeneric = fnc.isgeneric
	output.listarg = NewListArgCopy(fnc.listarg)
	output.listtestvalue = emptyvalues
	output.parallel = fnc.parallel
	output.permission = fnc.permission
	output.generictype = fnc.generictype
	output.sideeffects = fnc.sideeffects
	output.textblock = fnc.textblock
	output.value = emptyvalue
	return output
}

func NewMapFuncMap() map[string][]*vxfunc {
	return make(map[string][]*vxfunc)
}

func FuncSetType(fnc *vxfunc, typ *vxtype) *vxfunc {
	fnc.vxtype = typ
	if fnc.generictype != nil {
		fnc.mapgeneric = MapTypeSetType(fnc.mapgeneric, fnc.generictype.name, typ)
	}
	return fnc
}

func FuncFnGetArgList(fnc *vxfunc) []vxarg {
	var output []vxarg
	switch NameFromFunc(fnc) {
	case "vx/core/fn", "vx/core/let":
		arg0 := fnc.listarg[0]
		output = ListArgFromValue(arg0.value)
	}
	return output
}

func FuncFnSetListArg(fnc *vxfunc, listarg []vxarg) *vxfunc {
	switch NameFromFunc(fnc) {
	case "vx/core/fn", "vx/core/let":
		arg0 := fnc.listarg[0]
		arg0.value = ValueSetListArg(arg0.value, listarg)
		fnc.listarg[0] = arg0
	}
	return fnc
}

func FuncFromTextblock(textblock *vxtextblock, pkg *vxpackage) (*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("FuncFromTextblock")
	fnc := NewFunc()
	fnc.pkgname = pkg.name
	fnc.textblock = textblock
	var lastword = ""
	var testcls = false
	var typefound = false
	var valuefound = false
	var listtestvalue []vxvalue
	listwordtextblock := textblock.listtextblock
	for i, wordtextblock := range listwordtextblock {
		word := wordtextblock.text
		switch i {
		case 0:
			if word != "func" {
				msg := NewMsgFromTextblock(textblock, "Invalid Function:", word, "package:", pkg.name)
				msgblock = MsgblockAddError(msgblock, msg)
			}
		case 1:
			fnc.name = word
			fnc.alias = word
		default:
			switch wordtextblock.blocktype {
			case "/*", "//":
			case "[":
				listfuncarg, msgs := ListArgFromTextblock(wordtextblock, fnc, pkg)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				fnc.listarg = listfuncarg
				for _, arg := range listfuncarg {
					if arg.vxtype.isgeneric {
						fnc.isgeneric = true
					}
				}
			default:
				if testcls {
					if BooleanFromStringStarts(word, ":") {
						testcls = false
					} else {
						testvalue, msgs := ValueFromTextblock(wordtextblock, fnc, pkg)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						listtestvalue = append(listtestvalue, testvalue)
					}
				}
				if testcls {
				} else if lastword != "" {
					switch lastword {
					case ":":
						fnctyp := NewType(word)
						if fnctyp.isgeneric {
							fnc.isgeneric = true
						}
						pkgname := fnctyp.pkgname
						if pkgname != "" {
							pkgname = LibraryPathFromPackage(pkg, pkgname)
							if pkgname != "" {
								fnctyp.pkgname = pkgname
							} else {
								msg := NewMsgFromTextblock(textblock, "Package Not Found:", word)
								msgblock = MsgblockAddError(msgblock, msg)
							}
						}
						fnc.vxtype = fnctyp
						typefound = true
					case ":alias":
						fnc.alias = StringRemoveQuotes(word)
					case ":bigospace":
						switch word {
						case ":1", ":logn", ":n", ":nlogn", ":2n", ":n^2", ":2^n", ":n^n":
							fnc.bigospace = word
						default:
							msg := NewMsgFromTextblock(textblock, "func:", fnc.name, "Invalid bigospace", word)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					case ":bigotime":
						switch word {
						case ":1", ":logn", ":n", ":nlogn", ":2n", ":n^2", ":2^n", ":n^n":
							fnc.bigotime = word
						default:
							msg := NewMsgFromTextblock(textblock, "func", fnc.name, "Invalid bigotime", word)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					case ":clientserver":
						switch word {
						case ":client", ":server":
							fnc.clientserver = word
						default:
							msg := NewMsgFromTextblock(textblock, "func", fnc.name, "Invalid clientserver", word)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					case ":doc":
						fnc.doc = StringRemoveQuotes(word)
					case ":deprecated":
						fnc.deprecated = StringRemoveQuotes(word)
					case ":sideeffects":
						fnc.sideeffects = StringRemoveQuotes(word)
					}
					lastword = ""
				} else if BooleanFromStringStarts(word, ":") {
					switch word {
					case ":", ":alias", ":bigospace", ":bigotime", ":clientserver", ":doc", ":deprecated", ":sideeffects":
						lastword = word
					case ":private":
						fnc.private = true
					case ":protected":
						fnc.protected = true
					case ":wrapper":
						fnc.wrapper = true
					case ":async":
						fnc.async = true
					case ":context":
						fnc.context = true
					case ":debug":
						fnc.debug = true
					case ":messages":
						fnc.messages = true
					case ":parallel":
						fnc.parallel = true
					case ":permission":
						fnc.parallel = true
					case ":test":
						testcls = true
					default:
						msg := NewMsgFromTextblock(textblock, "Invalid Keyword:", word)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				} else if !typefound {
					msg := NewMsgFromTextblock(textblock, "Function Type Missing:", word)
					msgblock = MsgblockAddError(msgblock, msg)
				} else if valuefound {
					msg := NewMsgFromTextblock(textblock, "Functions Cannot Have More than 1 Result. Perhaps your parentheses are arranged incorrectly:", word)
					msgblock = MsgblockAddError(msgblock, msg)
				} else {
					valuefound = true
					value, msgs := ValueFromTextblock(wordtextblock, fnc, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					fnc.value = value
				}
			}
		}
	}
	fnc.listtestvalue = listtestvalue
	return fnc, msgblock
}

func FuncValidate(fnc *vxfunc, textblock *vxtextblock, path string) (*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("FuncValidate")
	path = path + "/" + fnc.name
	if fnc.idx > 0 {
		path += "/" + StringFromInt(fnc.idx)
	}
	if fnc.isgeneric && fnc.generictype != nil {
		// explict type added to function
		genericname := fnc.generictype.name
		if fnc.vxtype.name != "" {
			fnc.mapgeneric = MapGenericSetType(fnc.mapgeneric, genericname, fnc.vxtype)
		}
	}
	if len(fnc.listarg) > 0 {
		listarg, mapgeneric, msgs := ListArgValidate(fnc.listarg, fnc.mapgeneric, textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listarg = listarg
		fnc.mapgeneric = mapgeneric
		switch fnc.name {
		case "any<-list":
			arg := listarg[0]
			argvalue := arg.value
			argtype := argvalue.vxtype
			switch argtype.extends {
			case ":list":
				if BooleanGenericFromType(argtype) {
				} else {
					allowtype, ok := TypeAllowFromType(argtype)
					if ok {
						fnc.vxtype = allowtype
					}
				}
			}
		case "any<-map":
			arg := listarg[0]
			fnctype := TypeFromArg(arg)
			switch fnctype.extends {
			case ":map":
				allowtype, ok := TypeAllowFromType(fnctype)
				if ok {
					fnc.vxtype = allowtype
				}
			case ":struct":
				fnc.name = "any<-struct"
				fnc.alias = "any<-struct"
				arg.name = "struct"
				arg.alias = "struct"
				arg.generictype = NewType("struct-1")
				listarg[0] = arg
				fnc.listarg = listarg
				structtype, ok := fnc.mapgeneric["map-1"]
				if ok {
					fnc.mapgeneric["struct-1"] = structtype
					delete(fnc.mapgeneric, "map-1")
				}
				argvalue := arg.value
				switch argvalue.code {
				case "string":
					key := StringValueFromValue(argvalue)
					if BooleanFromStringStarts(key, ":") {
						key = StringSubstring(key, 1, len(key))
					}
					props := ListPropertyTraitFromType(fnctype)
					proptype := emptytype
					for _, proparg := range props {
						if proparg.name == key {
							proptype = proparg.vxtype
						}
					}
					switch proptype.name {
					case "":
						msg := NewMsgFromTextblock(textblock, "Attempt to get a property that does not exist from a given structure.", path, key, StringFromType(fnctype))
						msgblock = MsgblockAddError(msgblock, msg)
					default:
						fnc.vxtype = proptype
					}
				}
			}
		}
		if fnc.vxtype.isgeneric {
			genericname := fnc.vxtype.name
			generictype, ok := fnc.mapgeneric[genericname]
			if ok {
				fnc.vxtype = generictype
			}
		} else if fnc.vxtype.name == "" && fnc.generictype != nil {
			genericname := fnc.generictype.name
			generictype, ok := fnc.mapgeneric[genericname]
			if ok {
				fnc.vxtype = generictype
			}
		}
	}
	chgvalue, _, msgs := ValueValidate(fnc.value, fnc.vxtype, false, fnc.mapgeneric, textblock, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	fnc.value = chgvalue
	if NameFromType(fnc.vxtype) == "vx/core/unknown" {
		fnc.vxtype = fnc.value.vxtype
	} else if fnc.vxtype.isgeneric && fnc.generictype != nil {
		genericname := fnc.generictype.name
		generictype, ok := fnc.mapgeneric[genericname]
		if ok {
			fnc.vxtype = generictype
		}
	}
	if len(fnc.listtestvalue) > 0 {
		testvalues, msgs := ListValueValidateTestFuncs(fnc.listtestvalue, fnc.textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listtestvalue = testvalues
	}
	return fnc, msgblock
}

func ListFuncLink(listfunc []*vxfunc, listscope []vxscope, path string) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncLink")
	for _, fnc := range listfunc {
		subpath := path + "/" + fnc.name
		if fnc.idx > 0 {
			subpath += "/" + StringFromInt(fnc.idx)
		}
		typ := fnc.vxtype
		lookuptype, ok := TypeOrFuncFromListScope(listscope, typ.pkgname, typ.name, subpath)
		if ok {
			fnc.vxtype = lookuptype
			if lookuptype.isgeneric {
				fnc.generictype = lookuptype
			}
		} else if fnc.name == "native" {
		} else {
			msg := NewMsgFromTextblock(fnc.textblock, subpath, "Type Not Found:", typ.pkgname, typ.name)
			msgblock = MsgblockAddError(msgblock, msg)
		}
		if len(fnc.listarg) > 0 {
			argscope := ScopeFromFunc(fnc)
			argscope.pkgname = ""
			argscopes := append([]vxscope{argscope}, listscope...)
			args, msgs := ListArgLink(fnc.listarg, argscopes, fnc.textblock, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			fnc.listarg = args
		}
	}
	return listfunc, msgblock
}

func ListFuncLinkValues(listfunc []*vxfunc, listscope []vxscope, path string) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncLinkValues")
	for _, fnc := range listfunc {
		subpath := path + "/" + fnc.name
		if fnc.idx > 0 {
			subpath += "/" + StringFromInt(fnc.idx)
		}
		listfuncscope := ListScopeAddFuncArg(listscope, fnc)
		value, msgs := ValueLink(fnc.value, fnc.vxtype, listfuncscope, fnc.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.value = value
		listtestvalue, msgs := ListValueLink(fnc.listtestvalue, listscope, fnc.textblock, subpath+"/test")
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listtestvalue = listtestvalue
	}
	return listfunc, msgblock
}

func ListFuncParse(textblock *vxtextblock, pkg *vxpackage) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncParse")
	var output []*vxfunc
	for _, wordtextblock := range textblock.listtextblock {
		words := wordtextblock.listtextblock
		switch wordtextblock.blocktype {
		case "/*", "//":
		case "(":
			if len(words) == 0 {
				msg := NewMsgFromTextblock(textblock, "Empty Func")
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				firstword := words[0]
				switch firstword.text {
				case "func":
					fnc, msgs := FuncFromTextblock(wordtextblock, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					output = append(output, fnc)
				}
			}
		default:
			msg := NewMsgFromTextblock(textblock, "Invalid Func Blocktype")
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return output, msgblock
}

func ListFuncValidate(listfunc []*vxfunc, path string) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncValidate")
	var output []*vxfunc
	for _, fnc := range listfunc {
		chgfunc, msgs := FuncValidate(fnc, fnc.textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = append(output, chgfunc)
	}
	return output, msgblock
}

func ListKeyFromMapFunc(mapfunc map[string][]*vxfunc) []string {
	keys := make([]string, 0, len(mapfunc))
	for id := range mapfunc {
		keys = append(keys, id)
	}
	return ListStringSort(keys)
}

func ListLocalArgFromFunc(fnc *vxfunc) []vxarg {
	var output []vxarg
	for _, arg := range fnc.listarg {
		if arg.value.code == ":arglist" {
			output = ListArgFromValue(arg.value)
		}
	}
	return output
}

func ListNameFromListFunc(listfunc []*vxfunc) []string {
	var output []string
	for _, fnc := range listfunc {
		output = append(output, NameFromFunc(fnc))
	}
	return output
}

func MapFuncFromListFunc(listfunc []*vxfunc) map[string][]*vxfunc {
	output := NewMapFuncMap()
	for _, fnc := range listfunc {
		existing := output[fnc.name]
		fnc.idx = len(existing)
		existing = append(existing, fnc)
		output[fnc.name] = existing
	}
	return output
}

func NameFromFunc(fnc *vxfunc) string {
	return fnc.pkgname + "/" + fnc.name
}

func ScopeFromFunc(fnc *vxfunc) vxscope {
	scope := ScopeNew()
	scope.maparg = ArgMapFromArgList(fnc.listarg)
	return scope
}

func ScopeFromListFuncArg(listarg []vxarg) vxscope {
	var scope = ScopeNew()
	var listchgarg []vxarg
	for _, arg := range listarg {
		arg.value = emptyvalue
		listchgarg = append(listchgarg, arg)
	}
	scope.maparg = ArgMapFromArgList(listchgarg)
	return scope
}

func StringFromFunc(fnc *vxfunc) string {
	return StringFromFuncIndent(fnc, " ")
}

func StringFromFuncIndent(fnc *vxfunc, indent string) string {
	output := ""
	if len(indent) > 20 {
		output += "..."
	} else {
		lineindent := "\n" + indent
		output += "" +
			"(func" +
			lineindent + ":name  " + fnc.name +
			lineindent + ":alias " + fnc.alias +
			lineindent + ":pkg   " + fnc.pkgname
		if fnc.idx > 0 {
			output += lineindent + ":idx   " + StringFromInt(fnc.idx)
		}
		if fnc.vxtype.name != "" {
			output += lineindent + ":type  " + NameFromType(fnc.vxtype)
		}
		if fnc.async {
			output += lineindent + ":async " + StringFromBoolean(fnc.async)
		}
		if fnc.isgeneric {
			output += lineindent + ":isgeneric " + StringFromBoolean(fnc.isgeneric)
		}
		if fnc.generictype != nil {
			output += lineindent + ":generictype " + NameFromType(fnc.generictype)
		}
		if len(fnc.mapgeneric) > 0 {
			output += lineindent + ":genericmap " + ListNameFromMapType(fnc.mapgeneric)
		}
		if len(fnc.listarg) > 0 {
			output += lineindent + ":args " + StringFromListArgIndent(fnc.listarg, indent+" ")
		}
		if fnc.value.code != "" {
			output += lineindent + ":value " + StringFromValueIndent(fnc.value, indent+" ")
		}
		if len(fnc.listtestvalue) > 0 {
			output += lineindent + ":test " + StringFromListValueIndent(fnc.listtestvalue, indent+" ")
		}
		output += ")"
	}
	return output
}

func StringFromListFunc(listfunc []*vxfunc) string {
	return StringFromListFuncIndent(listfunc, "")
}

func StringFromListFuncIndent(listfunc []*vxfunc, indent string) string {
	output := ""
	if len(listfunc) > 0 {
		lineindent := "\n" + indent
		output += "(funclist"
		for _, fnc := range listfunc {
			output += lineindent + StringFromFuncIndent(fnc, indent+" ")
		}
		output += ")"
	}
	return output
}

func StringIndexFromFunc(fnc *vxfunc) string {
	output := ""
	if fnc.idx > 0 {
		output = "_" + StringFromInt(fnc.idx)
	}
	return output
}
