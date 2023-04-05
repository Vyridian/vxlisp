package vxlisp

import (
	"testing"
)

func TestConstFromTextblock(t *testing.T) {
	msgblock := NewMsgBlock("TestConstFromTextblock")
	typetext := `(const c1 : int
 (f1 1 2)
 :test (test-true (is-int c1))
 :doc "Docs")`
	pkg := NewPackage()
	pkg.name = "testpkg"
	textblock := NewTextblockFromText(typetext)
	textblock.name = "testfile.vxlisp"
	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	consts, msgs := ListConstFromTextblock(textblock, pkg)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expectedconst := NewConst()
	expectedconst.name = "c1"
	expectedconst.alias = "c1"
	expectedconst.pkgname = pkg.name
	expectedconst.doc = "Docs"
	typ := NewType("int")
	expectedconst.vxtype = typ
	valuefunc := NewFunc()
	valuefunc.name = "f1"
	valuefunc.alias = "f1"
	var args []vxarg
	arg := NewArg(":unknown")
	arg.value = NewValueFromInteger("1")
	args = append(args, arg)
	arg = NewArg(":unknown")
	arg.value = NewValueFromInteger("2")
	args = append(args, arg)
	valuefunc.listarg = args
	value := NewValueFromFunc(valuefunc)
	expectedconst.value = value
	valuefunc = NewFunc()
	valuefunc.name = "test-true"
	valuefunc.alias = "test-true"
	arg = NewArg(":unknown")
	argfunc := NewFunc()
	argfunc.name = "is-int"
	argfunc.alias = "is-int"
	valuearg := NewArg(":unknown")
	valuearg.value = NewValueFromString("c1")
	argfunc.listarg = append(argfunc.listarg, valuearg)
	textvalue := NewValueFromFunc(argfunc)
	arg.value = textvalue
	args = append(args, arg)
	valuefunc.listarg = args
	testvalue := NewValueFromFunc(valuefunc)
	expectedconst.listtestvalue = append(expectedconst.listtestvalue, testvalue)
	expected := StringFromConst(expectedconst)
	actual := ""
	if len(consts) > 0 {
		actual = StringFromConst(consts[0])
	}
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}
