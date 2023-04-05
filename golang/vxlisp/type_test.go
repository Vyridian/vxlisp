package vxlisp

import (
	"testing"
)

func TestTypesParse(t *testing.T) {
	msgblock := NewMsgBlock("TestTypesParse")
	typetext := `(type int
 :default 0
 :allowvalues [infinity neginfinity]
 :test (test-true (is-int 4))
 :doc "Docs")`
	pkg := NewPackage()
	pkg.name = "testpkg"
	textblock := NewTextblockFromText(typetext)
	textblock.name = "testfile.vxlisp"
	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	types, msgs := ListTypeFromTextblock(textblock, pkg)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expectedtype := NewType("int")
	expectedtype.pkgname = pkg.name
	expectedtype.doc = "Docs"
	expectedtype.defaultvalue = "0"
	var allowvalues []*vxconst
	allowconst := NewConst()
	allowconst.name = "infinity"
	allowvalues = append(allowvalues, allowconst)
	allowconst = NewConst()
	allowconst.name = "neginfinity"
	allowvalues = append(allowvalues, allowconst)
	expectedtype.allowvalues = allowvalues
	valuefunc := NewFunc()
	valuefunc.name = "test-true"
	valuefunc.alias = "test-true"
	var args []vxarg
	arg := NewArg(":unknown")
	argfunc := NewFunc()
	argfunc.name = "is-int"
	argfunc.alias = "is-int"
	valuearg := NewArg(":unknown")
	valuearg.value = NewValueFromInteger("4")
	argfunc.listarg = append(argfunc.listarg, valuearg)
	textvalue := NewValueFromFunc(argfunc)
	arg.value = textvalue
	args = append(args, arg)
	valuefunc.listarg = args
	testvalue := NewValueFromFunc(valuefunc)
	expectedtype.testvalues = append(expectedtype.testvalues, testvalue)
	expected := StringFromType(expectedtype)
	actual := ""
	if len(types) > 0 {
		actual = StringFromType(types[0])
	}
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}
