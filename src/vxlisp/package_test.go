package vxlisp

import (
	"testing"
)

func TestPackageParse(t *testing.T) {
	msgblock := NewMsgBlock("TestPackageParse")
	typetext := `(package testpkg
 :alias "alias"
 :libs  (lib testlibalias1 :path testlib1)
        (lib testlib2      :path testlib2)
 :doc   "Package doc")
 
 (type t1)
 
 (const c1)
 
 (func f1)`
	pkgname := "testpkg"
	textblock := NewTextblockFromText(typetext)
	textblock.name = "testfile.vxlisp"
	parsedtextblock, msgs := TextblockParse(textblock)
	textblock = parsedtextblock
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkg, msgs := PackageFromTextblock(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expectedpkg := NewPackage(pkgname)
	expectedpkg.alias = "alias"
	expectedpkg.doc = "Package doc"
	lib := NewLibrary()
	lib.name = "vx/core"
	lib.path = "vx/core"
	expectedpkg.listlib = append(expectedpkg.listlib, lib)
	lib = NewLibrary()
	lib.name = "vx/test"
	lib.path = "vx/test"
	expectedpkg.listlib = append(expectedpkg.listlib, lib)
	lib = NewLibrary()
	lib.name = "testlibalias1"
	lib.path = "testlib1"
	expectedpkg.listlib = append(expectedpkg.listlib, lib)
	lib = NewLibrary()
	lib.name = "testlib2"
	lib.path = "testlib2"
	expectedpkg.listlib = append(expectedpkg.listlib, lib)
	expectedconst := NewConst()
	expectedconst.name = "infinity"
	typ := NewType("t1")
	typ.pkgname = pkgname
	expectedpkg.listtype = append(expectedpkg.listtype, typ)
	cnst := NewConst()
	cnst.name = "c1"
	cnst.alias = "c1"
	cnst.pkgname = pkgname
	expectedpkg.listconst = append(expectedpkg.listconst, cnst)
	fnc := NewFunc()
	fnc.name = "f1"
	fnc.alias = "f1"
	fnc.pkgname = pkgname
	expectedpkg.listfunc = append(expectedpkg.listfunc, fnc)
	expected := StringFromPackage(expectedpkg)
	actual := StringFromPackage(pkg)
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}

func TestValuePackageValidate(t *testing.T) {
	msgblock := NewMsgBlock("TestValuePackageValidate")
	typetext := `(package testpkg)
 
 (type t1
  :extends :list)
 
 (const c1 : t1)

 (func f1 : t1
  [a1 : t1 :...])
  
 (func f2 : t1
  [a2 : t1]
  (f1 a2))`
	pkgname := "testpkg"
	textblock := NewTextblockFromText(typetext)
	textblock.name = "testfile.vxlisp"
	parsedtextblock, msgs := TextblockParse(textblock)
	textblock = parsedtextblock
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkg, msgs := PackageFromTextblock(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkg.listlib = emptylistlibrary
	pkgs := []*vxpackage{pkg}
	pkgs, msgs = ListPackageLink(pkgs)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkgs, msgs = ListPackageValidate(pkgs)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	pkg = pkgs[0]
	expectedpkg := NewPackage(pkgname)
	expectedpkg.alias = pkgname
	expectedconst := NewConst()
	expectedconst.name = "infinity"
	typ1 := NewType("t1")
	typ1.pkgname = pkgname
	typ1.extends = ":list"
	expectedpkg.listtype = append(expectedpkg.listtype, typ1)
	cnst1 := NewConst()
	cnst1.name = "c1"
	cnst1.alias = "c1"
	cnst1.pkgname = pkgname
	cnst1.vxtype = typ1
	expectedpkg.listconst = append(expectedpkg.listconst, cnst1)
	fnc1 := NewFunc()
	fnc1.name = "f1"
	fnc1.alias = "f1"
	fnc1.pkgname = pkgname
	fnc1.vxtype = typ1
	fnc1arg1 := NewArg("a1")
	fnc1arg1.vxtype = typ1
	fnc1arg1.multi = true
	fnc1.listarg = append(fnc1.listarg, fnc1arg1)
	expectedpkg.listfunc = append(expectedpkg.listfunc, fnc1)
	fnc2 := NewFunc()
	fnc2.name = "f2"
	fnc2.alias = "f2"
	fnc2.pkgname = pkgname
	fnc2.vxtype = typ1
	fnc2arg2 := NewArg("a2")
	fnc2arg2.vxtype = typ1
	fnc2arg2.multi = false
	fnc2.listarg = append(fnc2.listarg, fnc2arg2)
	fnc2fnc1 := NewFunc()
	fnc2fnc1.name = "f1"
	fnc2fnc1.alias = "f1"
	fnc2fnc1.pkgname = pkgname
	fnc2fnc1.vxtype = typ1
	fnc2fnc1arg1 := NewArg("a1")
	fnc2fnc1arg1.vxtype = typ1
	fnc2fnc1arg1.multi = true
	fnc2fnc1arg1arg2 := NewArg("a2")
	fnc2fnc1arg1arg2.vxtype = typ1
	fnc2fnc1arg1.value = ValueSetArg(fnc2fnc1arg1.value, fnc2fnc1arg1arg2)
	fnc2fnc1.listarg = append(fnc2fnc1.listarg, fnc2fnc1arg1)
	fnc2.value = NewValueFromFunc(fnc2fnc1)
	expectedpkg.listfunc = append(expectedpkg.listfunc, fnc2)
	expected := StringFromPackage(expectedpkg)
	actual := StringFromPackage(pkg)
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}
