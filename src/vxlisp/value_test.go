package vxlisp

import (
	"testing"
)

func TestValueValidate(t *testing.T) {
	//msgblock := MsgBlockNew("TestValueValidate")
	textblock := NewTextblock()
	textblock.name = "testfile.vxlisp"
	path := ""
	expected := ""
	actual := ""

	// new: (func new : any-1 [type : any-1 values : anylist :...])
	newfunc := NewFunc()
	newfunc.name = "new<-type"
	newfunc.pkgname = "vx/core"
	newfunc.vxtype = anytype1
	arg := NewArg("type")
	arg.vxtype = anytype1
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	newfunc.listarg = append(newfunc.listarg, arg)
	arg = NewArg("values")
	arg.vxtype = anylisttype
	arg.multi = true
	newfunc.listarg = append(newfunc.listarg, arg)

	// any<-any: (func any<-any : any-1 [value : any-2])
	anyfromanyfunc := NewFunc()
	anyfromanyfunc.name = "any<-any"
	anyfromanyfunc.pkgname = "vx/core"
	anyfromanyfunc.vxtype = anytype1
	anyfromanyfunc.isgeneric = true
	anyfromanyfunc.generictype = anytype1
	arg = NewArg("value")
	arg.vxtype = anytype2
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	anyfromanyfunc.listarg = append(anyfromanyfunc.listarg, arg)
	anyfromanytype := NewTypeFromFunc(anyfromanyfunc)

	// any<-func: (func any<-func : any-1)
	anyfromfunc := NewFunc()
	anyfromfunc.name = "any<-func"
	anyfromfunc.pkgname = "vx/core"
	anyfromfunc.vxtype = anytype1
	anyfromfunc.isgeneric = true
	anyfromfunc.generictype = anytype1
	anyfromfunctype := NewTypeFromFunc(anyfromfunc)

	// any<-key-value (func any<-key-value : any-1 [key : string val : any-2])
	anyfromkeyvaluefunc := NewFunc()
	anyfromkeyvaluefunc.name = "any<-key-value"
	anyfromkeyvaluefunc.pkgname = "vx/core"
	anyfromkeyvaluefunc.vxtype = anytype1
	anyfromkeyvaluefunc.isgeneric = true
	anyfromkeyvaluefunc.generictype = anytype1
	arg = NewArg("key")
	arg.vxtype = stringtype
	anyfromkeyvaluefunc.listarg = append(anyfromkeyvaluefunc.listarg, arg)
	arg = NewArg("value")
	arg.vxtype = anytype2
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	anyfromkeyvaluefunc.listarg = append(anyfromkeyvaluefunc.listarg, arg)
	anyfromkeyvaluetype := NewTypeFromFunc(anyfromkeyvaluefunc)

	// any<-list: (func any<-list : any-1 [values : list-1 index : int])
	anyfromlistfunc := NewFunc()
	anyfromlistfunc.name = "any<-list"
	anyfromlistfunc.pkgname = "vx/core"
	anyfromlistfunc.vxtype = anytype1
	anyfromlistfunc.isgeneric = true
	anyfromlistfunc.generictype = anytype1
	arg = NewArg("values")
	arg.vxtype = listtype1
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	anyfromlistfunc.listarg = append(anyfromlistfunc.listarg, arg)
	arg = NewArg("index")
	arg.vxtype = inttype
	anyfromlistfunc.listarg = append(anyfromlistfunc.listarg, arg)

	// list<-list: (func list<-list : list-1 [values : list-2 fn-any<-any : any<-any])
	listfromlistfunc := NewFunc()
	listfromlistfunc.name = "list<-list"
	listfromlistfunc.pkgname = "vx/core"
	listfromlistfunc.vxtype = listtype1
	listfromlistfunc.isgeneric = true
	listfromlistfunc.generictype = listtype1
	arg = NewArg("values")
	arg.vxtype = listtype2
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	listfromlistfunc.listarg = append(listfromlistfunc.listarg, arg)
	arg = NewArg("fn-any<-any")
	arg.vxtype = anyfromanytype
	listfromlistfunc.listarg = append(listfromlistfunc.listarg, arg)

	// any<-map: (func any<-map : any-1 [valuemap : map-2 key : string])
	mapgetfunc := NewFunc()
	mapgetfunc.name = "any<-map"
	mapgetfunc.pkgname = "vx/core"
	mapgetfunc.vxtype = anytype1
	mapgetfunc.isgeneric = true
	mapgetfunc.generictype = anytype1
	arg = NewArg("valuemap")
	arg.vxtype = maptype2
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	mapgetfunc.listarg = append(mapgetfunc.listarg, arg)
	arg = NewArg("key")
	arg.vxtype = stringtype
	mapgetfunc.listarg = append(mapgetfunc.listarg, arg)

	// list<-map: (func list<-map : list-1 [valuemap : map-2 fn-any<-key-value : any<-key-value])
	listfrommapfunc := NewFunc()
	listfrommapfunc.name = "list<-map"
	listfrommapfunc.pkgname = "vx/core"
	listfrommapfunc.vxtype = listtype1
	listfrommapfunc.isgeneric = true
	listfrommapfunc.generictype = listtype1
	arg = NewArg("valuemap")
	arg.vxtype = maptype2
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	listfrommapfunc.listarg = append(listfrommapfunc.listarg, arg)
	arg = NewArg("fn-any<-key-value")
	arg.vxtype = anyfromkeyvaluetype
	listfrommapfunc.listarg = append(listfrommapfunc.listarg, arg)

	// fn (func fn : any-1 [params : arglist fn-any<-any : any<-any])
	fnfunc := NewFunc()
	fnfunc.name = "fn"
	fnfunc.pkgname = "vx/core"
	fnfunc.vxtype = anytype1
	fnfunc.isgeneric = true
	fnfunc.generictype = arg.vxtype
	arg = NewArg("params")
	arg.vxtype = arglisttype
	fnfunc.listarg = append(fnfunc.listarg, arg)
	arg = NewArg("fn-any<-key-value")
	arg.vxtype = anyfromfunctype
	fnfunc.listarg = append(fnfunc.listarg, arg)

	// any<-struct: (func any<-struct : any-1 [valuestruct : struct-2 key : string])
	anyfromstructfunc := NewFunc()
	anyfromstructfunc.name = "any<-struct"
	anyfromstructfunc.pkgname = "vx/core"
	anyfromstructfunc.vxtype = anytype1
	anyfromstructfunc.isgeneric = true
	anyfromstructfunc.generictype = arg.vxtype
	arg = NewArg("valuestruct")
	arg.vxtype = structtype2
	arg.isgeneric = true
	arg.generictype = arg.vxtype
	anyfromstructfunc.listarg = append(anyfromstructfunc.listarg, arg)
	arg = NewArg("key")
	arg.vxtype = stringtype
	anyfromstructfunc.listarg = append(anyfromstructfunc.listarg, arg)

	// expected string, actual string
	expectedtype := stringtype
	value := NewValueFromString("text1")
	value, _, msgs := ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(expectedtype)
	actual = NameFromType(value.vxtype)
	errortext := CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	/*
		// expected composite type that allows string
		// actual string
		expectedtype = NewType("compositetype")
		expectedtype.pkgname = "mypackage"
		expectedtype.allowtypes = []*vxtype{stringtype}
		value = NewValueFromString("text2")
		value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
		expected = NameFromType(stringtype)
		actual = NameFromType(value.vxtype)
		errortext = CompareText(expected, actual, 20, msgs)
		if errortext != "" {
			t.Error(errortext)
		}
	*/

	// expected unknown type
	// actual string
	expectedtype = unknowntype
	value = NewValueFromString("text3")
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected generic any
	// actual string
	expectedtype = anytype
	value = NewValueFromString("text4")
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected string
	// actual string arg
	expectedtype = stringtype
	arg = NewArg("a1")
	arg.vxtype = stringtype
	value = NewValueFromArg(arg)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected generic any
	// actual string arg
	expectedtype = anytype
	arg = NewArg("a2")
	arg.vxtype = stringtype
	value = NewValueFromArg(arg)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	/*
		// any<-list: stringlist
		// actual string
		expectedtype = anytype

		genericmap := NewMapType()
		genericmap["any-1"] = stringlisttype

		fnc := NewFuncCopy(newfunc)
		fnc.mapgeneric = genericmap
		arglist := fnc.listarg
		arg = arglist[0]
		arg.value = NewValueFromType(stringlisttype)
		arglist[0] = arg
		argvalue := NewValueFromFunc(fnc)

		fnc = NewFuncCopy(anyfromlistfunc)
		arglist = fnc.listarg
		arg = arglist[0]
		arg.value = argvalue
		arglist[0] = arg
		arg = arglist[1]
		arg.value = NewValueFromInteger("0")
		arglist[1] = arg
		fnc.listarg = arglist

		value = NewValueFromFunc(fnc)
		value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
		expected = NameFromType(stringtype)
		actual = NameFromType(value.vxtype)
		errortext = CompareText(expected, actual, 20, msgs)
		if errortext != "" {
			t.Error(errortext)
		}

		// any<-map: stringmap
		// actual string
		expectedtype = anytype

		fnc = NewFuncCopy(newfunc)
		arglist = fnc.listarg
		arg = arglist[0]
		arg.value = NewValueFromType(stringmaptype)
		arglist[0] = arg

		argvalue = NewValueFromFunc(fnc)
		fnc = NewFuncCopy(mapgetfunc)
		arglist = fnc.listarg
		arg = arglist[0]
		arg.value = argvalue
		arglist[0] = arg
		arg = arglist[1]
		arg.value = NewValueFromString("a")
		arglist[1] = arg
		fnc.listarg = arglist

		value = NewValueFromFunc(fnc)
		value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
		expected = NameFromType(stringtype)
		actual = NameFromType(value.vxtype)
		errortext = CompareText(expected, actual, 20, msgs)
		if errortext != "" {
			t.Error(errortext)
		}
	*/

	// expected string
	// actual string function
	expectedtype = stringtype
	fnc := NewFunc()
	fnc.name = "f1"
	fnc.vxtype = stringtype
	value = NewValueFromFunc(fnc)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	/*
		// expected type that allows string, actual string function
		expectedtype = NewType("compositetype")
		expectedtype.pkgname = "mypackage"
		expectedtype.allowtypes = []*vxtype{stringtype}
		fnc = NewFunc()
		fnc.name = "f2"
		fnc.vxtype = stringtype
		value = NewValueFromFunc(fnc)
		value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
		expected = NameFromType(stringtype)
		actual = NameFromType(value.vxtype)
		errortext = CompareText(expected, actual, 20, msgs)
		if errortext != "" {
			t.Error(errortext)
		}
	*/

	// expected generic any, actual string function
	expectedtype = anytype
	fnc = NewFunc()
	fnc.name = "f3"
	fnc.vxtype = stringtype
	value = NewValueFromFunc(fnc)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected generic map
	// actual stringmap function
	expectedtype = maptype1
	fnc = NewFunc()
	fnc.name = "f5"
	fnc.vxtype = stringmaptype
	value = NewValueFromFunc(fnc)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringmaptype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected (f6) funcref
	// actual myfunc funcref
	fnc = NewFunc()
	fnc.name = "f6"
	expectedtype = NewTypeFromFunc(fnc)
	value = NewValueFromFuncRef(fnc)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(expectedtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected funcref (f7 : string [a1 : string])
	// actual (fn : string [a2 : string], a2)
	fnc = NewFunc()
	fnc.name = "f7"
	fnc.vxtype = stringtype
	arg = NewArg("a1")
	arg.vxtype = stringtype
	fnc.listarg = append(fnc.listarg, arg)
	expectedtype = NewTypeFromFunc(fnc)
	fnc = NewFuncCopy(fnfunc)
	fnc.vxtype = stringtype
	arg = NewArg("a2")
	arg.vxtype = stringtype
	arglist := FuncFnGetArgList(fnc)
	arglist = append(arglist, arg)
	fnc = FuncFnSetListArg(fnc, arglist)
	value = NewValueFromFunc(fnc)
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(expectedtype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected int
	// actual (f10 : unknown (new int 4))
	newintfunc := NewFuncCopy(newfunc)
	arglist = newintfunc.listarg
	arg = arglist[0]
	arg.value = NewValueFromType(inttype)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromInteger("4")
	arglist[1] = arg
	newintfunc.listarg = arglist

	fnc = NewFunc()
	fnc.name = "f10"
	fnc.vxtype = unknowntype
	fnc.value = NewValueFromFunc(newintfunc)

	value = NewValueFromFunc(fnc)
	expectedtype = inttype
	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(inttype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected stringlist
	// actual (f11 : stringlist (list<-list (new intlist 4) (fn [val : int] "a")))
	newintlistfunc := NewFuncCopy(newfunc)
	arglist = newintlistfunc.listarg
	arg = arglist[0]
	arg.value = NewValueFromType(intlisttype)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromInteger("4")
	arglist[1] = arg
	newintlistfunc.listarg = arglist

	valuefnfunc := NewFuncCopy(fnfunc)
	arglist = valuefnfunc.listarg
	subarg := NewArg("value")
	subarg.vxtype = inttype
	subarglist := []vxarg{subarg}
	arg = arglist[0]
	argvalue := arg.value
	arg.value = ValueSetListArg(argvalue, subarglist)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromString("a")
	arglist[1] = arg
	valuefnfunc.listarg = arglist

	listlistfunc := NewFuncCopy(listfromlistfunc)
	arglist = listlistfunc.listarg
	arg = arglist[0]
	arg.value = NewValueFromFunc(newintlistfunc)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromFunc(valuefnfunc)
	arglist[1] = arg
	listlistfunc.listarg = arglist

	fnc = NewFunc()
	fnc.name = "f11"
	fnc.vxtype = stringlisttype
	fnc.value = NewValueFromFunc(listlistfunc)

	value = NewValueFromFunc(fnc)
	expectedtype = stringlisttype

	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(stringlisttype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

	// expected intlist
	// actual (f11 : intlist (list<-map (new intmap "a" 1 "b" 2) (fn [key : string val : int] val)))
	newintmapfunc := NewFuncCopy(newfunc)
	arglist = newintmapfunc.listarg
	arg = arglist[0]
	arg.value = NewValueFromType(intmaptype)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromString("a")
	arglist[1] = arg
	arg = NewArgCopy(arg)
	arg.value = NewValueFromInteger("1")
	arglist = append(arglist, arg)
	arg = NewArgCopy(arg)
	arg.value = NewValueFromString("b")
	arglist = append(arglist, arg)
	arg = NewArgCopy(arg)
	arg.value = NewValueFromInteger("2")
	arglist = append(arglist, arg)
	newintmapfunc.listarg = arglist

	valuefnfunc = NewFuncCopy(fnfunc)
	arglist = valuefnfunc.listarg
	subarglist = []vxarg{}
	keyarg := NewArg("key")
	keyarg.vxtype = stringtype
	subarglist = append(subarglist, keyarg)
	valarg := NewArg("value")
	valarg.vxtype = inttype
	subarglist = append(subarglist, valarg)
	arg = arglist[0]
	argvalue = arg.value
	arg.value = ValueSetListArg(argvalue, subarglist)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromArg(valarg)
	arglist[1] = arg
	valuefnfunc.listarg = arglist

	maplistfunc := NewFuncCopy(listfrommapfunc)
	arglist = maplistfunc.listarg
	arg = arglist[0]
	arg.value = NewValueFromFunc(newintmapfunc)
	arglist[0] = arg
	arg = arglist[1]
	arg.value = NewValueFromFunc(valuefnfunc)
	arglist[1] = arg
	maplistfunc.listarg = arglist

	fnc = NewFunc()
	fnc.name = "f12"
	fnc.vxtype = intlisttype
	fnc.value = NewValueFromFunc(maplistfunc)

	value = NewValueFromFunc(fnc)
	expectedtype = intlisttype

	value, _, msgs = ValueValidate(value, expectedtype, false, emptygenerictypes, textblock, path)
	expected = NameFromType(intlisttype)
	actual = NameFromType(value.vxtype)
	errortext = CompareText(expected, actual, 20, msgs)
	if errortext != "" {
		t.Error(errortext)
	}

}

func TestPackageValidate(t *testing.T) {
	msgblock := NewMsgBlock("TestPackageValidate")
	textblock := NewTextblock()
	textblock.name = "testfile.vxlisp"
	textblock.text = `
(package vx/core)

(type any)

(type anylist
 :extends    :list
 :allowtypes [any])
  
(type anytype
 :extends :type)

(type arg
 :extends  :struct
 :properties
  [name    : string
   argtype : type
   fn-any  : any<-func])

(type arglist
 :extends    :list
 :allowtypes [arg])

(type int)

(type intlist
 :extends    :list
 :allowtypes [int])

(type intmap
 :extends    :map
 :allowtypes [int])

(type list
 :extends    :list
 :allowtypes [any])

(type map
 :extends    :map
 :allowtypes [any])

(type string
 :extends string)

(type stringlist
 :extends    :list
 :allowtypes [string])

(type stringmap
 :extends    :map
 :allowtypes [string])

(type type
 :extends :type)

(func any<-any : any-1
 [value : any-2])

(func any<-func : any-1
 [])

(func any<-key-value : any-1
 [key : string
  val : any-2])
   
(func fn : any-1
 [params : arglist
  fn-any : any<-func])

(func list<-list : list-1
 [values      : list-2
  fn-any<-any : any<-any])

(func list<-map : list-1
 [valuemap         : map-2
 fn-any<-key-value : any<-key-value])

(func new : any-1
 [type   : any-1
  values : anylist :...])

(func string<-int : string
 [value : int])

(func test1 : string
 (string<-int 4))

(func test2 : stringlist
 (list<-list
  (intlist 1 2)
  (fn [value : int] (string<-int value))))

(func test3 : stringlist
 (list<-map
  (intmap :a 1 :b 2)
  (fn
   [key   : string
    value : int]
   (string<-int value))))
`

	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkg, msgs := PackageFromTextblock(textblock)
	pkg.listlib = emptylistlibrary
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkgs := []*vxpackage{pkg}
	pkgs, msgs = ListPackageLink(pkgs)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	_, msgs = ListPackageValidate(pkgs)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expected := ""
	actual := ""
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}

}
