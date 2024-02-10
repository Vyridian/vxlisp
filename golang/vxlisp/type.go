package vxlisp

type vxtype struct {
	name           string
	alias          string
	defaultvalue   string
	deprecated     string
	doc            string
	extends        string
	generic        string
	isgeneric      bool
	properties     []vxarg
	pkgname        string
	traits         []*vxtype
	allowfuncs     []*vxfunc
	disallowfuncs  []*vxfunc
	allowtypes     []*vxtype
	disallowtypes  []*vxtype
	allowvalues    []*vxconst
	disallowvalues []*vxconst
	//contraints       []*vxfunc
	convert      []string
	isfunc       bool
	vxfunc       *vxfunc
	createvalue  vxvalue
	destroyvalue vxvalue
	emptyvalue   vxvalue
	testvalues   []vxvalue
	textblock    *vxtextblock
}

//var emptygenerics = make([]string, 0)

var emptygenerictypes = make(map[string]*vxtype)

var emptytype = NewType("")

var emptylisttype = []*vxtype{}

var anylisttype = NewTypeList("vx/core/anylist", anytype)

var anytype = NewType("vx/core/any")

var anytype1 = NewType("vx/core/any-1")

var anytype2 = NewType("vx/core/any-2")

var argtype = NewType("vx/core/arg")

var arglisttype = NewTypeList("vx/core/arglist", argtype)

var booleantype = NewType("vx/core/boolean")

var contexttype = NewContextType()

var decimaltype = NewType("vx/core/decimal")

var functype = NewType("vx/core/func")

var floattype = NewType("vx/core/float")

var inttype = NewType("vx/core/int")

var intlisttype = NewTypeList("vx/core/intlist", inttype)

var intmaptype = NewTypeMap("vx/core/intmap", inttype)

var listtype = NewTypeList("vx/core/list", anytype)

var listtype1 = NewTypeList("vx/core/list-1", anytype)

var listtype2 = NewTypeList("vx/core/list-2", anytype)

var maptype = NewTypeMap("vx/core/map", anytype)

var maptype1 = NewTypeMap("vx/core/map1", anytype)

var maptype2 = NewTypeMap("vx/core/map2", anytype)

var msgtype = NewType("vx/core/msg")

var numbertype = NewType("vx/core/number")

var sessiontype = NewTypeStruct("vx/core/session")

var settingtype = NewTypeStruct("vx/core/setting")

var stringtype = NewType("vx/core/string")

var stringprimitivetype = NewType("string")

var stringlisttype = NewTypeList("vx/core/stringlist", stringtype)

var stringmaptype = NewTypeMap("vx/core/stringmap", stringtype)

var structtype = NewTypeStruct("vx/core/struct")

//var structtype1 = NewType("vx/core/struct-1")

var structtype2 = NewType("vx/core/struct-2")

var testresulttype = NewTypeStruct("vx/test/testresult")

var unknowntype = NewType("vx/core/unknown")

func NewContextType() *vxtype {
	var listprop []vxarg
	prop := NewArg("setting")
	prop.vxtype = settingtype
	listprop = append(listprop, prop)
	prop = NewArg("session")
	prop.vxtype = sessiontype
	listprop = append(listprop, prop)
	output := NewType("context")
	output.pkgname = "vx/core"
	output.extends = ":struct"
	output.properties = listprop
	return output
}

func NewMapType() map[string]*vxtype {
	return make(map[string]*vxtype)
}

func NewType(typename string) *vxtype {
	typ := new(vxtype)
	pos := IntFromStringFindLast(typename, "/")
	if pos < 0 {
		typ.name = typename
	} else {
		typ.pkgname = typename[0:pos]
		typ.name = typename[pos+1:]
	}
	switch typename {
	case "vx/core/arglist", "vx/core/intlist", "vx/core/list", "vx/core/stringlist":
		typ.extends = ":list"
	case "vx/core/intmap", "vx/core/map", "vx/core/stringmap":
		typ.extends = ":map"
	default:
		isfound := false
		if BooleanFromStringEnds(typename, "-1") {
			isfound = true
		} else if BooleanFromStringEnds(typename, "-2") {
			isfound = true
		} else if BooleanFromStringEnds(typename, "-3") {
			isfound = true
		} else if BooleanFromStringEnds(typename, "-4") {
			isfound = true
		} else if BooleanFromStringEnds(typename, "-5") {
			isfound = true
		}
		if isfound {
			typ.alias = StringSubstring(typename, 0, len(typename)-2)
			typ.isgeneric = true
		}
	}
	return typ
}

func NewTypeCopy(typecopy *vxtype) *vxtype {
	typ := new(vxtype)
	typ.name = typecopy.name
	typ.alias = typecopy.alias
	typ.pkgname = typecopy.pkgname
	typ.defaultvalue = typecopy.defaultvalue
	typ.deprecated = typecopy.deprecated
	typ.doc = typecopy.doc
	typ.extends = typecopy.extends
	typ.generic = typecopy.generic
	typ.isgeneric = typecopy.isgeneric
	typ.properties = typecopy.properties
	typ.traits = typecopy.traits
	typ.allowfuncs = typecopy.allowfuncs
	typ.disallowfuncs = typecopy.disallowfuncs
	typ.allowtypes = typecopy.allowtypes
	typ.disallowtypes = typecopy.disallowtypes
	typ.allowvalues = typecopy.allowvalues
	typ.disallowvalues = typecopy.disallowvalues
	typ.convert = typecopy.convert
	typ.isfunc = typecopy.isfunc
	typ.vxfunc = typecopy.vxfunc
	typ.createvalue = typecopy.createvalue
	typ.destroyvalue = typecopy.destroyvalue
	typ.emptyvalue = typecopy.emptyvalue
	typ.testvalues = typecopy.testvalues
	typ.textblock = typecopy.textblock
	return typ
}

func NewTypeFromFunc(fnc *vxfunc) *vxtype {
	typ := new(vxtype)
	typ.name = fnc.name
	typ.alias = fnc.alias
	typ.pkgname = fnc.pkgname
	typ.isfunc = true
	typ.vxfunc = fnc
	return typ
}

func NewTypeList(typename string, basetype *vxtype) *vxtype {
	typ := NewType(typename)
	typ.extends = ":list"
	typ.allowtypes = []*vxtype{basetype}
	isfound := false
	if BooleanFromStringEnds(typename, "-1") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-2") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-3") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-4") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-5") {
		isfound = true
	}
	if isfound {
		typ.alias = StringSubstring(typename, 0, len(typename)-2)
		typ.isgeneric = true
	}
	return typ
}

func NewTypeMap(typename string, basetype *vxtype) *vxtype {
	typ := NewType(typename)
	typ.extends = ":map"
	typ.allowtypes = []*vxtype{basetype}
	isfound := false
	if BooleanFromStringEnds(typename, "-1") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-2") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-3") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-4") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-5") {
		isfound = true
	}
	if isfound {
		typ.alias = StringSubstring(typename, 0, len(typename)-2)
		typ.isgeneric = true
	}
	return typ
}

func NewTypeStruct(typename string) *vxtype {
	typ := NewType(typename)
	typ.extends = ":struct"
	isfound := false
	if BooleanFromStringEnds(typename, "-1") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-2") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-3") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-4") {
		isfound = true
	} else if BooleanFromStringEnds(typename, "-5") {
		isfound = true
	}
	if isfound {
		typ.alias = StringSubstring(typename, 0, len(typename)-2)
		typ.isgeneric = true
	}
	return typ
}

func BooleanAllowFromTypeConst(typ *vxtype, cnst *vxconst) (bool, *vxmsgblock) {
	msgblock := NewMsgBlock("BooleanAllowFromTypeConst")
	pass := false
	constname := NameFromConst(cnst)
	if constname != "" {
		typename := NameFromType(typ)
		for _, allowvalue := range typ.allowvalues {
			if constname == NameFromConst(allowvalue) {
				pass = true
			}
		}
		for _, disallowvalue := range typ.disallowvalues {
			if constname == NameFromConst(disallowvalue) {
				pass = false
				msg := NewMsg("Disallow Constant", typename, constname)
				msgblock = MsgblockAddError(msgblock, msg)
			}
		}
	}
	return pass, msgblock
}

func BooleanAllowFromTypeFunc(expectedtype *vxtype, fnc *vxfunc, path string) (bool, *vxmsgblock) {
	msgblock := NewMsgBlock("BooleanAllowFromTypeFunc")
	pass := false
	funcname := NameFromFunc(fnc)
	if funcname != "" {
		expectedtypename := NameFromType(expectedtype)
		for _, allowfunc := range expectedtype.allowfuncs {
			if funcname == NameFromFunc(allowfunc) {
				pass = true
			}
		}
		for _, disallowfunc := range expectedtype.disallowfuncs {
			if funcname == NameFromFunc(disallowfunc) {
				pass = false
				msg := NewMsg("Disallow Function", expectedtypename, funcname)
				msgblock = MsgblockAddError(msgblock, msg)
			}
		}
	}
	return pass, msgblock
}

func BooleanAllowFromTypeType(typ *vxtype, checktype *vxtype) (bool, *vxmsgblock) {
	msgblock := NewMsgBlock("BooleanAllowFromTypeType")
	pass := false
	checkname := NameFromType(checktype)
	if checkname != "" {
		typename := NameFromType(typ)
		for _, allowtype := range typ.allowtypes {
			if checkname == NameFromType(allowtype) {
				pass = true
			}
		}
		for _, disallowtype := range typ.disallowtypes {
			if checkname == NameFromType(disallowtype) {
				pass = false
				msg := NewMsg("Disallow Type", typename, checkname)
				msgblock = MsgblockAddError(msgblock, msg)
			}
		}
	}
	return pass, msgblock
}

func BooleanGenericFromType(typ *vxtype) bool {
	name := NameFromType(typ)
	output := false
	if BooleanFromStringEnds(name, "-1") {
		output = true
	} else if BooleanFromStringEnds(name, "-2") {
		output = true
	} else if BooleanFromStringEnds(name, "-3") {
		output = true
	}
	return output
}

func BooleanMatchFromTypeType(expectedtype *vxtype, actualtype *vxtype, multi bool, index int, path string) (*vxtype, bool, *vxmsgblock) {
	msgblock := NewMsgBlock("BooleanMatchTypeType")
	resulttype := actualtype
	pass := false
	expectedtypename := NameFromType(expectedtype)
	actualtypename := NameFromType(actualtype)
	if expectedtype.isgeneric {
		genericname := NameWithoutGenericFromType(expectedtype)
		if genericname == actualtypename {
			pass = true
		} else if genericname == "vx/core/any" {
			pass = true
		} else if genericname == "vx/core/list" {
			if actualtype.extends == ":list" {
				pass = true
			}
		} else if genericname == "vx/core/map" {
			if actualtype.extends == ":map" {
				pass = true
			}
		} else {
			ok, msgs := BooleanAllowFromTypeType(expectedtype, actualtype)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if ok {
				pass = true
			}
		}
	} else if actualtype.isgeneric {
		genericname := NameWithoutGenericFromType(actualtype)
		if expectedtypename == "/" {
			pass = true
			///} else if expectedtypename == "vx/core/any" {
			//	pass = true
			//resulttype = expectedtype
		} else if genericname == expectedtypename {
			pass = true
			resulttype = expectedtype
		} else if genericname == "vx/core/any" {
			pass = true
			resulttype = expectedtype
		} else if genericname == "vx/core/list" {
			if expectedtype.extends == ":list" {
				pass = true
				resulttype = expectedtype
			}
		} else if genericname == "vx/core/map" {
			if expectedtype.extends == ":map" {
				pass = true
				resulttype = expectedtype
			}
		} else {
			ok, msgs := BooleanAllowFromTypeType(actualtype, expectedtype)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if ok {
				pass = true
				resulttype = expectedtype
			}
		}
	} else {
		switch expectedtypename {
		case actualtypename:
			// same type
			pass = true
		case "/", "vx/core/unknown":
			// no type defined
			pass = true
		case "vx/core/any":
			// no type defined
			//if !actualtype.isfunc {
			pass = true
			//}
		case "vx/core/anytype":
			// no type defined
			// FIXME This can produce a warning or an error with strict typing turned on
			pass = true
		case "vx/core/typelist":
			// All types are allow.
			pass = true
		case "vx/core/none":
			// It doesn't matter what type. It will be discarded.
			pass = true
		}
	}
	switch actualtypename {
	case "", "/":
		// no type defined
		pass = true
	default:
		if pass {
		} else if !multi && (expectedtype.extends == ":list") {
		} else if index == 0 && (expectedtype.extends == "") {
			// first value cannot be within allow types
		} else {
			// within allow types
			for _, allowtype := range expectedtype.allowtypes {
				switch NameFromType(allowtype) {
				case "vx/core/any":
					pass = true
				case actualtypename:
					pass = true
				default:
					for _, suballowtype := range allowtype.allowtypes {
						switch NameFromType(suballowtype) {
						case "vx/core/any":
							pass = true
						case actualtypename:
							pass = true
						}
					}
				}
			}
		}
		if pass {
			// within disallow types
			for _, disallowtype := range expectedtype.disallowtypes {
				if actualtypename == NameFromType(disallowtype) {
					pass = false
					msg := NewMsg("Disallow Type", expectedtypename, actualtypename, path)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
		}
	}
	return resulttype, pass, msgblock
}

func ListAllowTypeFromType(typ *vxtype) []*vxtype {
	var output []*vxtype
	if len(typ.allowtypes) > 0 {
		output = append(output, typ.allowtypes...)
	}
	if len(typ.allowfuncs) > 0 {
		listtype := ListTypeFromListFunc(typ.allowfuncs)
		output = append(output, listtype...)
	}
	return output
}

func ListKeyFromMapType(maptype map[string]*vxtype) []string {
	listkey := make([]string, 0, len(maptype))
	for id := range maptype {
		listkey = append(listkey, id)
	}
	return ListStringSort(listkey)
}

func ListNameFromListType(listtype []*vxtype) string {
	var names []string
	for _, typ := range listtype {
		names = append(names, typ.pkgname+"/"+typ.name)
	}
	return "[" + StringFromListStringJoin(names, " ") + "]"
}

func ListNameFromMapType(maptype map[string]*vxtype) string {
	output := ""
	if len(maptype) > 0 {
		listkey := make([]string, 0, len(maptype))
		for id := range maptype {
			listkey = append(listkey, id)
		}
		var listname []string
		listkey = ListStringSort(listkey)
		for _, key := range listkey {
			typ := maptype[key]
			listname = append(listname, key+" "+typ.pkgname+"/"+typ.name)
		}
		output = "(typemap " + StringFromListStringJoin(listname, " ") + ")"
	}
	return output
}

func ListPropertyTraitFromType(typ *vxtype) []vxarg {
	var output []vxarg
	if len(typ.traits) == 0 {
		output = typ.properties
	} else {
		for _, trait := range typ.traits {
			output = append(output, trait.properties...)
		}
		output = append(output, typ.properties...)
	}
	return output
}

func ListTypeFromGenericMapType(typmap map[string]*vxtype) []*vxtype {
	var output []*vxtype
	keys := make([]string, 0, len(typmap))
	for id := range typmap {
		keys = append(keys, id)
	}
	keys = ListStringSort(keys)
	for _, key := range keys {
		typ := typmap[key]
		output = append(output, typ)
	}
	return output
}

func ListTypeFromListFunc(listfunc []*vxfunc) []*vxtype {
	var output []*vxtype
	if len(listfunc) > 0 {
		for _, fnc := range listfunc {
			typ := NewTypeFromFunc(fnc)
			if typ.isfunc {
				output = append(output, typ)
			}
		}
	}
	return output
}

func ListTypeFromMapType(typmap map[string]*vxtype) []*vxtype {
	var output []*vxtype
	keys := make([]string, 0, len(typmap))
	for id := range typmap {
		keys = append(keys, id)
	}
	keys = ListStringSort(keys)
	for _, key := range keys {
		typ := typmap[key]
		output = append(output, typ)
	}
	return output
}

func ListTypeFromTextblock(textblock *vxtextblock, pkg *vxpackage) ([]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("ListTypeFromTextblock")
	var output []*vxtype
	for _, wordtextblock := range textblock.listtextblock {
		words := wordtextblock.listtextblock
		switch wordtextblock.blocktype {
		case "/*", "//":
		case "(":
			if len(words) == 0 {
				msg := NewMsgFromTextblock(textblock, "Empty Type")
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				firstword := words[0]
				switch firstword.text {
				case "type":
					typ, msgs := TypeFromTextblock(wordtextblock, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					output = append(output, typ)
				}
			}
		default:
			msg := NewMsgFromTextblock(textblock, "Invalid Type Blocktype")
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return output, msgblock
}

func ListTypeLink(listtype []*vxtype, scopes []vxscope, path string) ([]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("ListTypeLink")
	for _, typ := range listtype {
		subpath := path + "/" + typ.name
		if len(typ.traits) > 0 {
			var values []*vxtype
			for _, val := range typ.traits {
				chgval, ok := TypeOrFuncFromListScope(scopes, "", val.name, subpath)
				if ok {
					values = append(values, chgval)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Trait Type Missing", val.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.traits = values
		}
	}
	for _, typ := range listtype {
		subpath := path + "/" + typ.name
		if len(typ.allowtypes) > 0 {
			var values []*vxtype
			for _, val := range typ.allowtypes {
				chgval, ok := TypeOrFuncFromListScope(scopes, "", val.name, subpath)
				if ok {
					values = append(values, chgval)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Allowed Type Missing", val.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.allowtypes = values
		}
		if len(typ.disallowtypes) > 0 {
			var values []*vxtype
			for _, val := range typ.disallowtypes {
				chgval, ok := TypeOrFuncFromListScope(scopes, "", val.name, subpath)
				if ok {
					values = append(values, chgval)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Disallow Type Missing", val.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.disallowtypes = values
		}
		if len(typ.allowvalues) > 0 {
			var values []*vxconst
			for _, val := range typ.allowvalues {
				chgval, ok := ConstFromListScope(scopes, "", val.name)
				if ok {
					values = append(values, chgval)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Allowed Value Missing", val.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.allowvalues = values
		}
		if len(typ.disallowvalues) > 0 {
			var values []*vxconst
			for _, val := range typ.disallowvalues {
				chgval, ok := ConstFromListScope(scopes, "", val.name)
				if ok {
					values = append(values, chgval)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Disallow Value Missing", val.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.disallowvalues = values
		}
		if len(typ.allowfuncs) > 0 {
			var fncs []*vxfunc
			for _, fnc := range typ.allowfuncs {
				updatedfnc, ok := FuncFromListScope(scopes, "", fnc.name, emptysignature, subpath)
				if ok {
					fncs = append(fncs, updatedfnc)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Allowed Function Missing", fnc.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.allowfuncs = fncs
		}
		if len(typ.disallowfuncs) > 0 {
			var fncs []*vxfunc
			for _, fnc := range typ.disallowfuncs {
				updatedfnc, ok := FuncFromListScope(scopes, "", fnc.name, emptysignature, subpath)
				if ok {
					fncs = append(fncs, updatedfnc)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Disallow Function Missing", fnc.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.disallowfuncs = fncs
		}
		if len(typ.properties) > 0 {
			var properties []vxarg
			for _, property := range typ.properties {
				lookuptype, ok := TypeOrFuncFromListScope(scopes, "", property.vxtype.name, subpath)
				if ok {
					property.vxtype = lookuptype
					properties = append(properties, property)
				} else {
					msg := NewMsgFromTextblock(typ.textblock, subpath, "Property Type Missing", property.name, property.vxtype.name)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
			typ.properties = properties
		}
	}
	return listtype, msgblock
}

func ListTypeLinkValues(listtype []*vxtype, scopes []vxscope, path string) ([]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("ListTypeLinkValues")
	for _, typ := range listtype {
		subpath := path + "/" + typ.name
		if !typ.isfunc {
			emptyvalue, msgs := ValueLink(typ.emptyvalue, typ, scopes, typ.textblock, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			typ.emptyvalue = emptyvalue
			testvalues, msgs := ListValueLink(typ.testvalues, scopes, typ.textblock, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			typ.testvalues = testvalues
		}
	}
	return listtype, msgblock
}

func ListTypeValidate(listtype []*vxtype, path string) ([]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("TypesValidateTypes")
	for _, typ := range listtype {
		subpath := path + "/" + typ.name
		if len(typ.properties) > 0 {
			properties, _, msgs := ListArgValidate(typ.properties, emptygenerictypes, typ.textblock, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			typ.properties = properties
		}
		testvalues, msgs := ListValueValidateTestFuncs(typ.testvalues, typ.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typ.testvalues = testvalues
	}
	return listtype, msgblock
}

func MapGenericSetType(mapgeneric map[string]*vxtype, generic string, typ *vxtype) map[string]*vxtype {
	if mapgeneric == nil {
		mapgeneric = NewMapType()
	}
	mapgeneric[generic] = typ
	if BooleanFromStringStarts(generic, "list-") {
		allowtype, ok := TypeAllowFromType(typ)
		if ok {
			generic = StringFromStringFindReplace(generic, "list-", "any-")
			mapgeneric[generic] = allowtype
		}
	} else if BooleanFromStringStarts(generic, "map-") {
		allowtype, ok := TypeAllowFromType(typ)
		if ok {
			generic = StringFromStringFindReplace(generic, "map-", "any-")
			mapgeneric[generic] = allowtype
		}
	}
	return mapgeneric
}

func MapTypeFromListType(listtype []*vxtype) map[string]*vxtype {
	var output = NewMapType()
	for _, val := range listtype {
		output[val.name] = val
	}
	return output
}

func MapTypeSetType(maptype map[string]*vxtype, key string, typ *vxtype) map[string]*vxtype {
	if maptype == nil {
		maptype = NewMapType()
	}
	maptype[key] = typ
	return maptype
}

func MapTypeMerge(maptype map[string]*vxtype, maptype2 map[string]*vxtype, path string) (map[string]*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("MapTypeMerge")
	typekeys := ListKeyFromMapType(maptype2)
	for _, typeid := range typekeys {
		type2, ok := TypeFromMapType(maptype2, typeid)
		if ok {
			type1, ok := TypeFromMapType(maptype, typeid)
			if ok {
				type3, ok, msgs := BooleanMatchFromTypeType(type1, type2, false, 0, path)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				if ok {
					maptype = MapTypeSetType(maptype, typeid, type3)
				}
			} else {
				maptype = MapTypeSetType(maptype, typeid, type2)
			}
		}
	}
	return maptype, msgblock
}

func NameFromType(typ *vxtype) string {
	return typ.pkgname + "/" + typ.name
}

func NameWithoutGenericFromType(typ *vxtype) string {
	name := NameFromType(typ)
	isfound := BooleanGenericFromType(typ)
	if isfound {
		name = name[0 : len(name)-2]
	}
	return name
}

func StringFromType(typ *vxtype) string {
	return StringFromTypeIndent(typ, 0)
}

func StringFromTypeIndent(typ *vxtype, indent int) string {
	sindent := ""
	lineindent := "\n"
	if indent > 0 {
		sindent = StringRepeat(" ", indent)
		lineindent += sindent
	}
	output := "" +
		sindent + "(type" +
		lineindent + " :name     " + typ.name +
		lineindent + " :pkgname  " + typ.pkgname +
		lineindent + " :extends  " + typ.extends
	if typ.isfunc {
		output += lineindent + " :isfunc " + StringFromBoolean(typ.isfunc)
	}
	//if typ.signature == nil {
	//} else if len(typ.signature.vxtypes) > 0 {
	//	output += lineindent + ":signature " + SignatureToText(typ.signature)
	//}
	if len(typ.properties) > 0 {
		output += lineindent + " :properties " + StringFromListArgIndent(typ.properties, indent+1)
	}
	if len(typ.traits) > 0 {
		output += lineindent + " :traits " + ListNameFromListType(typ.traits)
	}
	if len(typ.allowtypes) > 0 {
		output += lineindent + ":allowtypes " + ListNameFromListType(typ.allowtypes)
	}
	if len(typ.disallowtypes) > 0 {
		output += lineindent + ":disallowtypes " + ListNameFromListType(typ.disallowtypes)
	}
	if len(typ.testvalues) > 0 {
		output += lineindent + ":testvalues " + StringFromListValueIndent(typ.testvalues, indent+1)
	}
	output += ")"
	return output
}

func StringFromListTypeIndent(listtype []*vxtype, indent int) string {
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output := lineindent + "(typelist"
	if len(listtype) > 0 {
		for _, typ := range listtype {
			output += lineindent + StringFromTypeIndent(typ, indent+1)
		}
	}
	output += ")"
	return output
}

func StringFromMapType(maptype map[string]*vxtype) string {
	return StringFromMapTypeIndent(maptype, 0)
}

func StringFromMapTypeIndent(maptype map[string]*vxtype, indent int) string {
	lineindent := ""
	if indent > 0 {
		lineindent = "\n" + StringRepeat(" ", indent)
	}
	output := lineindent + "(typemap"
	if len(maptype) > 0 {
		for key, typ := range maptype {
			output += lineindent + " " + key + " " + StringFromTypeIndent(typ, indent+2)
		}
	}
	output += ")"
	return output
}

func TypeAllowFromType(typ *vxtype) (*vxtype, bool) {
	output := emptytype
	ok := false
	if len(typ.allowtypes) == 1 {
		output = typ.allowtypes[0]
		ok = true
	}
	return output, ok
}

func TypeFromMapType(maptype map[string]*vxtype, key string) (*vxtype, bool) {
	typ := emptytype
	ok := false
	if maptype != nil {
		var lookuptype *vxtype
		lookuptype, ok = maptype[key]
		if ok {
			typ = lookuptype
		}
	}
	return typ, ok
}

func TypeFromTextblock(textblock *vxtextblock, pkg *vxpackage) (*vxtype, *vxmsgblock) {
	msgblock := NewMsgBlock("TypeFromTextblock")
	typ := NewType("")
	typ.pkgname = pkg.name
	typ.textblock = textblock
	var valuefound = false
	var lastword = ""
	var testcls = false
	var testvalues []vxvalue
	for i, wordtextblock := range textblock.listtextblock {
		word := wordtextblock.text
		switch i {
		case 0:
			switch word {
			case "type":
			default:
				msg := NewMsgFromTextblock(textblock, "Type Not Found: ", word)
				msgblock = MsgblockAddError(msgblock, msg)
			}
		case 1:
			typ.name = word
		default:
			if testcls {
				if BooleanFromStringStarts(word, ":") {
					testcls = false
					lastword = word
				} else {
					testvalue, msgs := ValueFromTextblock(wordtextblock, emptyfunc, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					testvalues = append(testvalues, testvalue)
				}
			} else if lastword != "" {
				switch lastword {
				case ":":
					typ.extends = ":" + word
				case ":alias":
					typ.alias = StringRemoveQuotes(word)
				case ":allowfuncs", ":disallowfuncs":
					if wordtextblock.blocktype == "[" {
						var funcs []*vxfunc
						for _, subtextblock := range wordtextblock.listtextblock {
							funcname := subtextblock.text
							fnc := NewFunc()
							fnc.name = funcname
							funcs = append(funcs, fnc)
						}
						switch lastword {
						case ":allowfuncs":
							typ.allowfuncs = funcs
						case ":disallowfuncs":
							typ.disallowfuncs = funcs
						}
					} else {
						msg := NewMsgFromTextblock(textblock, "Invalid Allowed/Disallow Functions:", word)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				case ":allowtypes", ":disallowtypes", ":traits":
					if wordtextblock.blocktype == "[" {
						var types []*vxtype
						for _, subtextblock := range wordtextblock.listtextblock {
							typname := subtextblock.text
							typ := NewType(typname)
							types = append(types, typ)
						}
						switch lastword {
						case ":allowtypes":
							typ.allowtypes = types
						case ":disallowtypes":
							typ.disallowtypes = types
						case ":traits":
							typ.traits = types
						}
					} else {
						msg := NewMsgFromTextblock(textblock, "Invalid Allowed/Disallow Types:", word)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				case ":allowvalues", ":disallowvalues":
					// typ.allowvalues = strings.ReplaceAll(word, "\"", "")
				case ":create":
					value, msgs := ValueFromTextblock(wordtextblock, emptyfunc, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					typ.createvalue = value
				case ":destroy":
					value, msgs := ValueFromTextblock(wordtextblock, emptyfunc, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					typ.destroyvalue = value
				case ":default":
					typ.defaultvalue = word
				case ":deprecated":
					typ.deprecated = StringRemoveQuotes(word)
				case ":doc":
					typ.doc = StringRemoveQuotes(word)
				case ":extends":
					typ.extends = word
				case ":properties":
					if wordtextblock.blocktype == "[" {
						lastword := ""
						var arg vxarg
						for _, subtextblock := range wordtextblock.listtextblock {
							property := subtextblock.text
							if lastword == "" {
								switch property {
								case ":", ":doc", ":alias":
									lastword = property
								case ":default":
									arg.isdefault = true
								case ":...":
									arg.multi = true
								default:
									if BooleanFromStringStarts(property, ":") {
										msg := NewMsgFromTextblock(textblock, "Invalid Property:", property, typ.properties)
										msgblock = MsgblockAddError(msgblock, msg)
									} else {
										if arg.name != "" {
											typ.properties = append(typ.properties, arg)
										}
										arg = NewArg(property)
									}
								}
							} else {
								switch lastword {
								case ":":
									argtype := NewType(property)
									arg.vxtype = argtype
								case ":alias":
									arg.alias = property
								case ":doc":
									arg.doc = property
								}
								lastword = ""
							}
						}
						if arg.name != "" {
							typ.properties = append(typ.properties, arg)
						}
					} else {
						msg := NewMsgFromTextblock(textblock, "Invalid Properties:", word)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				case ":convert":
					var converts []string
					converts = append(converts, word)
					typ.convert = converts
				}
				lastword = ""
			} else if BooleanFromStringStarts(word, ":") {
				switch word {
				case ":", ":alias", ":allowfuncs", ":allowtypes", ":allowvalues", ":convert", ":create", ":default", ":deprecated", ":destroy", ":disallowfuncs", ":disallowtypes", ":disallowvalues", ":doc", ":extends", ":properties", ":traits":
					lastword = word
				case ":test":
					testcls = true
				default:
					msg := NewMsgFromTextblock(textblock, "Invalid Keyword:", word)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			} else if valuefound {
				msg := NewMsgFromTextblock(textblock, "More Than 1 Value:", word)
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				valuefound = true
				value, msgs := ValueFromTextblock(wordtextblock, emptyfunc, pkg)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				typ.emptyvalue = value
			}
		}
	}
	//if (typ.extends == "") && (len(typ.allowfuncs) > 0) {
	//	typ.isfunc = true
	//}
	if typ.alias == "" {
		typ.alias = typ.name
	}
	typ.testvalues = testvalues
	return typ, msgblock
}
