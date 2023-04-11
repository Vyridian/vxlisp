package vxlisp

import (
	"testing"
)

func TestFuncParse(t *testing.T) {
	msgblock := NewMsgBlock("TestFuncParse")
	functext := `(func . : any-1
 [object : any-1
  method : string
  params : any-2 :...]
 (native :js "object[method].apply(params)")
 :alias "dotmethod"
 :doc "Docs")`
	pkg := NewPackage()
	pkg.name = "testpkg"
	textblock := NewTextblockFromText(functext)
	textblock.name = "testfile.vxlisp"
	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	funcs, msgs := ListFuncParse(textblock, pkg)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expectedfunc := NewFunc()
	expectedfunc.name = "."
	expectedfunc.pkgname = pkg.name
	expectedfunc.alias = "dotmethod"
	expectedfunc.doc = "Docs"
	typ := NewType("any-1")
	expectedfunc.vxtype = typ
	expectedfunc.isgeneric = true
	var args []vxarg
	arg := NewArg("object")
	typ = NewType("any-1")
	arg.vxtype = typ
	arg.isgeneric = true
	arg.generictype = typ
	args = append(args, arg)
	arg = NewArg("method")
	typ = NewType("string")
	arg.vxtype = typ
	args = append(args, arg)
	arg = NewArg("params")
	typ = NewType("any-2")
	arg.isgeneric = true
	arg.generictype = typ
	arg.multi = true
	arg.vxtype = typ
	args = append(args, arg)
	expectedfunc.listarg = args
	valuefunc := NewFunc()
	valuefunc.name = "native"
	valuefunc.alias = "native"
	var nativeargs []vxarg
	arg = NewArg(":unknown")
	textvalue := NewValueFromString(":js")
	arg.value = textvalue
	nativeargs = append(nativeargs, arg)
	arg = NewArg(":unknown")
	textvalue = NewValueFromString("\"object[method].apply(params)\"")
	arg.value = textvalue
	nativeargs = append(nativeargs, arg)
	valuefunc.listarg = nativeargs
	expectedfunc.value = NewValueFromFunc(valuefunc)
	expected := StringFromFunc(expectedfunc)
	actual := ""
	if len(funcs) > 0 {
		actual = StringFromFunc(funcs[0])
	}
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}
