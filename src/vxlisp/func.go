package vxlisp

type vxfunc struct {
	name         string
	pkgname      string
	alias        string
	listarg      []vxarg
	argname      string
	async        bool
	bigospace    string
	bigotime     string
	clientserver string
	context      bool
	debug        bool
	deprecated   string
	doc          string
	generictype  *vxtype
	mapgeneric   map[string]*vxtype
	idx          int
	iscopied     bool
	isgeneric    bool
	isimplement  bool
	isimplement2 bool
	isoverride   bool
	messages     bool
	parallel     bool
	permission   bool
	protected    bool
	private      bool
	//recurive      bool
	sideeffects   string
	listtestvalue []vxvalue
	textblock     *vxtextblock
	value         vxvalue
	vxtype        *vxtype
	wrapper       bool
}

var emptyfunc = NewFunc()

var emptysignature = NewSignature()

var func_any_from_any = NewFuncFromPkgnameName(
	"vx/core", "any_from_any")
var func_any_from_any_async = NewFuncFromPkgnameName(
	"vx/core", "any_from_any_async")
var func_any_from_func = NewFuncFromPkgnameName(
	"vx/core", "any_from_func")
var func_any_from_func_async = NewFuncFromPkgnameName(
	"vx/core", "any_from_func_async")
var func_any_from_struct = NewFuncFromPkgnameName("vx/core", "any_from_struct")
var func_anylist_from_arraystring = NewFuncFromPkgnameName(
	"vx/core", "anylist_from_arraystring")
var func_arraylist_from_array = NewFuncFromPkgnameName(
	"vx/core", "arraylist_from_array")
var func_async = NewFuncFromPkgnameName(
	"vx/core", "async")
var func_async_from_async = NewFuncFromPkgnameName(
	"vx/core", "async_from_async")
var func_async_from_async_fn = NewFuncFromPkgnameName(
	"vx/core", "async_from_async_fn")
var func_boolean_from_func = NewFuncFromPkgnameName(
	"vx/core", "boolean_from_func")
var func_boolean_permission_from_func = NewFuncFromPkgnameName(
	"vx/core",
	"boolean_permission_from_func")
var func_boolean_write_from_file_string = NewFuncFromPkgnameName(
	"vx/data/file", "boolean_write_from_file_string")
var func_copy = NewFuncFromPkgnameName(
	"vx/core", "copy")
var func_empty = NewFuncFromPkgnameName("vx/core", "empty")
var func_let_async = NewFuncFromPkgnameName("vx/core", "let_async")
var func_log = NewFuncFromPkgnameName("vx/core", "log")
var func_log_1 = NewFuncFromPkgnameName("vx/core", "log_1")
var func_list_from_list_async = NewFuncFromPkgnameName(
	"vx/core", "list_from_list_async")
var func_listimmutable = NewFuncFromPkgnameName(
	"vx/core", "listimmutable")
var func_mapimmutable = NewFuncFromPkgnameName("vx/core", "mapimmutable")
var func_mapmutable = NewFuncFromPkgnameName("vx/core", "mapmutable")
var func_msg_from_error = NewFuncFromPkgnameName("vx/core", "msg_from_error")
var func_msg_from_exception = NewFuncFromPkgnameName("vx/core", "msg_from_exception")
var func_new = NewFuncFromPkgnameName("vx/core", "new")
var func_new_anylist = NewFuncFromPkgnameName(
	"vx/core", "new_anylist")
var func_new_boolean = NewFuncFromPkgnameName("vx/core", "new_boolean")
var func_new_decimal = NewFuncFromPkgnameName("vx/core", "new_decimal")
var func_new_from_type = NewFuncFromPkgnameName("vx/core", "new_from_type")
var func_new_int = NewFuncFromPkgnameName("vx/core", "new_int")
var func_new_string = NewFuncFromPkgnameName("vx/core", "new_string")
var func_pathfull_from_file = NewFuncFromPkgnameName(
	"vx/data/file", "pathfull_from_file")
var func_read_test_file = NewFuncFromPkgnameNameTypeArgs(
	"TestLib", "read_test_file",
	rawstringtype,
	argcontext,
	NewArgFromNameTypeFinal("path", rawstringtype, true),
	NewArgFromNameTypeFinal("filename", rawstringtype, true))
var func_resolve_testcase = NewFuncFromPkgnameName(
	"vx/test", "resolve_testcase")
var func_run_testcase = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testcase",
	testcasetype,
	NewArgFromNameTypeFinal("testcase", testcasetype, true))
var func_run_testcase_async = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testcase_async",
	testcasetype,
	NewArgFromNameTypeFinal("testcase", testcasetype, true))
var func_run_testcaselist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testcaselist",
	testcaselisttype,
	NewArgFromNameTypeFinal("testcaselist", testcaselisttype, true))
var func_run_testdescribe = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testdescribe",
	testdescribetype,
	NewArgFromNameTypeFinal("testpkg", rawstringtype, true),
	NewArgFromNameTypeFinal("casename", rawstringtype, true),
	NewArgFromNameTypeFinal("describe", testdescribetype, true))
var func_run_testdescribelist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testdescribelist",
	testdescribelisttype,
	NewArgFromNameTypeFinal("testpkg", rawstringtype, true),
	NewArgFromNameTypeFinal("casename", rawstringtype, true),
	NewArgFromNameTypeFinal("testdescribelist", testdescribelisttype, true))
var func_run_testpackage = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testpackage",
	testpackagetype,
	NewArgFromNameTypeFinal("testpackage", testpackagetype, true))
var func_run_testpackage_async = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testpackage_async",
	testpackagetype,
	NewArgFromNameTypeFinal("testpackage", testpackagetype, true))
var func_run_testpackagelist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testpackagelist",
	testpackagelisttype,
	NewArgFromNameTypeFinal("testpackagelist", testpackagelisttype, true))
var func_run_testresult = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"run_testresult",
	testresulttype,
	NewArgFromNameTypeFinal("testpkg", rawstringtype, true),
	NewArgFromNameTypeFinal("testname", rawstringtype, true),
	NewArgFromNameTypeFinal("message", rawstringtype, true),
	NewArgFromNameTypeFinal("testresult", testresulttype, true))
var func_sample_testcase1 = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testcase1",
	testcasetype,
	argcontext)
var func_sample_testcase2 = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testcase2",
	testcasetype,
	argcontext)
var func_sample_testcaselist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testcaselist",
	testcaselisttype,
	argcontext)
var func_sample_testdescribe1 = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testdescribe1",
	testdescribetype,
	argcontext)
var func_sample_testdescribe2 = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testdescribe2",
	testdescribetype,
	argcontext)
var func_sample_testdescribelist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testdescribelist",
	testdescribelisttype,
	argcontext)
var func_sample_testpackage = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testpackage",
	testpackagetype,
	argcontext)
var func_sample_testpackagelist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testpackagelist",
	testpackagelisttype,
	argcontext)
var func_sample_testresult1 = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testresult1",
	testresulttype,
	argcontext)
var func_sample_testresult2 = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"sample_testresult2",
	testresulttype,
	argcontext)
var func_string_from_any = NewFuncFromPkgnameName("vx/core", "string_from_any")
var func_string_read_from_file = NewFuncFromPkgnameName(
	"vx/data/file", "string_read_from_file")
var func_sync_from_async = NewFuncFromPkgnameName(
	"vx/core", "sync_from_async")
var func_test = NewFuncFromPkgnameName("vx/test", "test")
var func_test_false = NewFuncFromPkgnameName("vx/test", "test_false")
var func_test_true = NewFuncFromPkgnameName("vx/test", "test_true")
var func_test_async_from_async_fn = NewFuncFromPkgnameNameType("TestLib", "test_async_from_async_fn", rawbooltype)
var func_test_async_new_from_value = NewFuncFromPkgnameNameType("TestLib", "test_async_new_from_value", rawbooltype)
var func_test_helloworld = NewFuncFromPkgnameNameType(
	"TestLib",
	"test_helloworld",
	rawbooltype)
var func_test_list_from_list_async = NewFuncFromPkgnameNameType("TestLib", "test_list_from_list_async", rawbooltype)
var func_test_pathfull_from_file = NewFuncFromPkgnameNameType("TestLib", "test_pathfull_from_file", rawbooltype)
var func_test_read_file = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_read_file",
	rawbooltype,
	argcontext)
var func_test_run_testcase = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testcase",
	rawbooleantype,
	argcontext)
var func_test_run_testcase_async = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testcase_async",
	rawbooleantype,
	argcontext)
var func_test_run_testcaselist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testcaselist",
	rawbooleantype,
	argcontext)
var func_test_run_testdescribe = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testdescribe",
	rawbooleantype,
	argcontext)
var func_test_run_testdescribe_async = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testdescribe_async",
	rawbooleantype,
	argcontext)
var func_test_run_testdescribelist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testdescribelist",
	rawbooleantype,
	argcontext)
var func_test_run_testdescribelist_async = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testdescribelist_async",
	rawbooleantype,
	argcontext)
var func_test_run_testpackage = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testpackage",
	rawbooleantype,
	argcontext)
var func_test_run_testpackagelist = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testpackagelist",
	rawbooleantype,
	argcontext)
var func_test_run_testresult = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testresult",
	rawbooleantype,
	argcontext)
var func_test_run_testresult_async = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_run_testresult_async",
	rawbooleantype,
	argcontext)
var func_test_write_file = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test_write_file",
	rawbooltype,
	argcontext)
var func_testlib_test = NewFuncFromPkgnameNameTypeArgs(
	"TestLib",
	"test",
	rawbooltype,
	NewArgFromNameTypeFinal("testname", rawstringtype, true),
	NewArgFromNameTypeFinal("expected", rawstringtype, true),
	NewArgFromNameTypeFinal("actual", rawstringtype, true))
var func_typedef_new = NewFuncFromPkgnameNameType("vx/core", "typedef_new", typedeftype)
var func_write_testpackagelist_async = NewFuncFromPkgnameNameType("TestLib", "write_testpackagelist_async", rawbooltype)

func NewFunc() *vxfunc {
	output := new(vxfunc)
	output.vxtype = emptytype
	output.textblock = emptytextblock
	return output
}

func NewFuncFromPkgnameName(
	pkgname string,
	funcname string) *vxfunc {
	output := NewFunc()
	output.pkgname = pkgname
	output.name = funcname
	output.alias = funcname
	return output
}

func NewFuncFromPkgnameNameType(
	pkgname string,
	funcname string,
	typ *vxtype) *vxfunc {
	output := NewFunc()
	output.pkgname = pkgname
	output.name = funcname
	output.alias = funcname
	output.vxtype = typ
	return output
}

func NewFuncFromPkgnameNameTypeArgs(
	pkgname string,
	funcname string,
	typ *vxtype,
	args ...vxarg) *vxfunc {
	output := NewFunc()
	output.pkgname = pkgname
	output.name = funcname
	output.alias = funcname
	output.vxtype = typ
	output.listarg = args
	return output
}

func NewFuncFromPkgnameNameTypeAsyncArgs(
	pkgname string,
	funcname string,
	typ *vxtype,
	args ...vxarg) *vxfunc {
	output := NewFunc()
	output.pkgname = pkgname
	output.name = funcname
	output.alias = funcname
	output.vxtype = typ
	output.async = true
	output.listarg = args
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
	output.generictype = fnc.generictype
	output.iscopied = true
	output.isgeneric = fnc.isgeneric
	output.listarg = NewListArgCopy(fnc.listarg)
	output.listtestvalue = emptyvalues
	output.mapgeneric = fnc.mapgeneric
	output.parallel = fnc.parallel
	output.permission = fnc.permission
	output.generictype = fnc.generictype
	output.sideeffects = fnc.sideeffects
	output.textblock = fnc.textblock
	output.value = emptyvalue
	output.debug = fnc.debug
	return output
}

func NewMapFuncMap() map[string][]*vxfunc {
	return make(map[string][]*vxfunc)
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

func FuncFromTextblock(
	textblock *vxtextblock,
	pkg *vxpackage) (*vxfunc, *vxmsgblock) {
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
				msg := NewMsgFromTextblock(
					textblock, 0, 0, "Invalid Function", word, "package:", pkg.name)
				msgblock = MsgblockAddError(
					msgblock, msg)
			}
		case 1:
			fnc.name = word
			fnc.alias = word
		default:
			switch wordtextblock.blocktype {
			case "/*", "//":
			case "[":
				listfuncarg, msgs := ListArgFromTextblock(
					wordtextblock, fnc, pkg)
				msgblock = MsgblockAddBlock(
					msgblock, msgs)
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
								msg := NewMsgFromTextblock(
									textblock, 0, 0, "Package Not Found", word)
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
							msg := NewMsgFromTextblock(
								textblock, 0, 0, "func:", fnc.name, "Invalid bigospace", word)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					case ":bigotime":
						switch word {
						case ":1", ":logn", ":n", ":nlogn", ":2n", ":n^2", ":2^n", ":n^n":
							fnc.bigotime = word
						default:
							msg := NewMsgFromTextblock(
								textblock, 0, 0, "Invalid bigotime", word, "func", fnc.name)
							msgblock = MsgblockAddError(msgblock, msg)
						}
					case ":clientserver":
						switch word {
						case ":client", ":server":
							fnc.clientserver = word
						default:
							msg := NewMsgFromTextblock(
								textblock, 0, 0, "Invalid clientserver", word, "func", fnc.name)
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
				} else if BooleanFromStringStarts(word, ":") && (textblock.blocktype != "\"") {
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
						fnc.permission = true
					case ":test":
						testcls = true
					default:
						msg := NewMsgFromTextblock(
							textblock, 0, 0, "Invalid Keyword", word)
						msgblock = MsgblockAddError(msgblock, msg)
					}
				} else if !typefound {
					msg := NewMsgFromTextblock(
						textblock, 0, 0, "Function Type Missing", word)
					msgblock = MsgblockAddError(msgblock, msg)
				} else if valuefound {
					msg := NewMsgFromTextblock(
						textblock, 0, 0, "Functions Cannot Have More than 1 Result. Perhaps you have missed a :test keyword or parentheses are arranged incorrectly:", word)
					msgblock = MsgblockAddError(msgblock, msg)
				} else {
					valuefound = true
					value, msgs := ValueFromTextblock(
						wordtextblock, fnc, pkg)
					msgblock = MsgblockAddBlock(
						msgblock, msgs)
					fnc.value = value
				}
			}
		}
	}
	fnc.listtestvalue = listtestvalue
	return fnc, msgblock
}

func FuncValidate(
	fnc *vxfunc,
	textblock *vxtextblock,
	path string) (*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("FuncValidate")
	path = path + "/" + fnc.name + StringIndexFromFunc(fnc)
	if fnc.isgeneric && fnc.generictype != nil {
		// explict type added to function
		genericname := fnc.generictype.name
		if fnc.vxtype.name != "" {
			fnc.mapgeneric = MapGenericSetType(
				fnc.mapgeneric, genericname, fnc.vxtype)
		}
	}
	if len(fnc.listarg) > 0 {
		listarg, mapgeneric, msgs := ListArgValidate(
			fnc.listarg, fnc.mapgeneric, textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listarg = listarg
		fnc.mapgeneric = mapgeneric
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
	chgvalue, _, msgs := ValueValidate(
		fnc.value, fnc.vxtype, false, fnc.mapgeneric, textblock, path)
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
		testvalues, msgs := ListValueValidateTestFuncs(
			fnc.listtestvalue, fnc.textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listtestvalue = testvalues
	}
	return fnc, msgblock
}

func FuncSetType(
	fnc *vxfunc,
	typ *vxtype) *vxfunc {
	fnc.vxtype = typ
	if fnc.generictype != nil {
		fnc.mapgeneric = MapTypeSetType(
			fnc.mapgeneric, fnc.generictype.name, typ)
	}
	return fnc
}

func ListFuncLink(
	listfunc []*vxfunc,
	listscope []vxscope,
	path string) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncLink")
	for _, fnc := range listfunc {
		subpath := path + "/" + fnc.name + StringIndexFromFunc(fnc)
		typ := fnc.vxtype
		lookuptype, ok := TypeOrFuncFromListScope(
			listscope, typ.pkgname, typ.name, subpath)
		if ok {
			fnc.vxtype = lookuptype
			if lookuptype.isgeneric {
				fnc.generictype = lookuptype
			}
		} else if fnc.name == "native" {
		} else {
			msg := NewMsgFromTextblock(
				fnc.textblock, 0, 0, "Type Not Found", typ.pkgname, "subpath", subpath, "type", typ.name)
			msgblock = MsgblockAddError(msgblock, msg)
		}
		if len(fnc.listarg) > 0 || fnc.context {
			args, msgs := ListArgLink(
				fnc.listarg, listscope, fnc.textblock, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			fnc.listarg = args
		}
	}
	return listfunc, msgblock
}

func ListFuncLinkValues(
	listfunc []*vxfunc,
	listscope []vxscope,
	path string) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncLinkValues")
	for _, fnc := range listfunc {
		subpath := path + "/" + fnc.name + StringIndexFromFunc(fnc)
		listfuncscope := ListScopeAddFuncArg(
			listscope, fnc)
		value, msgs := ValueLink(
			fnc.value, fnc.vxtype, listfuncscope, fnc.textblock, subpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.value = value
		listtestvalue, msgs := ListValueLink(
			fnc.listtestvalue, listscope, fnc.textblock, subpath+"/test")
		msgblock = MsgblockAddBlock(msgblock, msgs)
		fnc.listtestvalue = listtestvalue
	}
	return listfunc, msgblock
}

func ListFuncParse(
	textblock *vxtextblock,
	pkg *vxpackage) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncParse")
	var output []*vxfunc
	for _, wordtextblock := range textblock.listtextblock {
		words := wordtextblock.listtextblock
		switch wordtextblock.blocktype {
		case "/*", "//":
		case "(":
			if len(words) == 0 {
				msg := NewMsgFromTextblock(
					textblock, 0, 0, "", "Empty Func")
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
			msg := NewMsgFromTextblock(
				textblock, 0, 0, "", "Invalid Func Blocktype")
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return output, msgblock
}

func ListFuncReverse(
	listfunc []*vxfunc) []*vxfunc {
	var output []*vxfunc
	for i := len(listfunc) - 1; i >= 0; i-- {
		output = append(output, listfunc[i])
	}
	return output
}

func ListFuncValidate(
	listfunc []*vxfunc,
	path string) ([]*vxfunc, *vxmsgblock) {
	msgblock := NewMsgBlock("ListFuncValidate")
	var output []*vxfunc
	for _, fnc := range listfunc {
		chgfunc, msgs := FuncValidate(fnc, fnc.textblock, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		output = append(output, chgfunc)
	}
	return output, msgblock
}

func ListKeyFromMapFunc(
	mapfunc map[string][]*vxfunc) []string {
	keys := make([]string, 0, len(mapfunc))
	for id := range mapfunc {
		keys = append(keys, id)
	}
	return ListStringSort(keys)
}

func ListArgLocalFromFunc(
	fnc *vxfunc) []vxarg {
	var output []vxarg
	for _, arg := range fnc.listarg {
		if arg.value.code == ":arglist" {
			output = ListArgFromValue(arg.value)
		}
	}
	return output
}

func ListNameFromListFunc(
	listfunc []*vxfunc) []string {
	var output []string
	for _, fnc := range listfunc {
		output = append(output, NameFromFunc(fnc))
	}
	return output
}

func MapFuncFromListFunc(
	listfunc []*vxfunc) map[string][]*vxfunc {
	output := NewMapFuncMap()
	for _, fnc := range listfunc {
		existing := output[fnc.name]
		fnc.idx = len(existing)
		existing = append(existing, fnc)
		output[fnc.name] = existing
	}
	return output
}

func NameFromFunc(
	fnc *vxfunc) string {
	output := fnc.name
	if fnc.pkgname != "" {
		output = fnc.pkgname + "/" + fnc.name
	}
	if fnc.idx > 0 {
		output = output + "_" + StringFromInt(fnc.idx)
	}
	return output
}

func ScopeFromFunc(
	fnc *vxfunc) vxscope {
	scope := ScopeNew()
	maparg := ArgMapFromArgList(fnc.listarg)
	if fnc.context {
		maparg["context"] = argcontext
	}
	scope.maparg = maparg
	return scope
}

func ScopeFromListFuncArg(
	listarg []vxarg) vxscope {
	var scope = ScopeNew()
	var listchgarg []vxarg
	for _, arg := range listarg {
		arg.value = emptyvalue
		listchgarg = append(listchgarg, arg)
	}
	scope.maparg = ArgMapFromArgList(listchgarg)
	return scope
}

func StringFromFunc(
	fnc *vxfunc) string {
	return StringFromFuncIndent(fnc, 0)
}

func StringFromFuncIndent(
	fnc *vxfunc,
	indent int) string {
	output := ""
	if indent > 30 {
		output += "..."
	} else {
		initindent := ""
		lineindent := "\n"
		if indent > 0 {
			sindent := StringRepeat(" ", indent)
			lineindent += sindent
			initindent = lineindent
		}
		output += "" +
			initindent + "(func" +
			lineindent + " :name  " + fnc.name +
			lineindent + " :alias " + fnc.alias +
			lineindent + " :pkg   " + fnc.pkgname
		if fnc.idx > 0 {
			output += lineindent + " :idx   " + StringFromInt(fnc.idx)
		}
		if fnc.vxtype.name != "" {
			output += lineindent + " :type  " + NameFromType(fnc.vxtype)
		}
		if fnc.async {
			output += lineindent + " :async " + StringFromBoolean(fnc.async)
		}
		if fnc.isgeneric {
			output += lineindent + " :isgeneric " + StringFromBoolean(fnc.isgeneric)
		}
		if fnc.generictype != nil {
			output += lineindent + " :generictype " + NameFromType(fnc.generictype)
		}
		if len(fnc.mapgeneric) > 0 {
			output += lineindent + " :genericmap " + ListNameFromMapType(fnc.mapgeneric)
		}
		if len(fnc.listarg) > 0 {
			output += lineindent + " :args " + StringFromListArgIndent(fnc.listarg, indent+2)
		}
		if fnc.value.code != "" {
			output += lineindent + " :value " + StringFromValueIndent(fnc.value, indent+2)
		}
		if len(fnc.listtestvalue) > 0 {
			output += lineindent + " :test " + StringFromListValueIndent(fnc.listtestvalue, indent+2)
		}
		output += ")"
	}
	return output
}

func StringFromListFunc(
	listfunc []*vxfunc) string {
	return StringFromListFuncIndent(listfunc, 0)
}

func StringFromListFuncIndent(
	listfunc []*vxfunc,
	indent int) string {
	output := ""
	if len(listfunc) > 0 {
		lineindent := ""
		if indent > 0 {
			lineindent = "\n" + StringRepeat(" ", indent)
		}
		output += lineindent + "(funclist"
		for _, fnc := range listfunc {
			output += lineindent + StringFromFuncIndent(fnc, indent+2)
		}
		output += ")"
	}
	return output
}

func StringFromNativeFunc(
	fnc *vxfunc,
	lang string) string {
	output := ""
	if fnc.name == "native" {
		isNative := false
		for _, arg := range fnc.listarg {
			var argvalue = arg.value
			valuetext := ""
			if argvalue.code == "string" {
				valuetext = StringValueFromValue(argvalue)
			}
			if valuetext == lang {
				isNative = true
			} else if BooleanFromStringStarts(valuetext, ":") {
				isNative = false
			} else if isNative {
				if argvalue.name == "newline" {
					output += "\n"
				} else {
					value := arg.value
					output += value.textblock.text
				}
			}
		}
	}
	return output
}

func StringIndexFromFunc(
	fnc *vxfunc) string {
	output := ""
	if fnc.idx > 0 {
		output = "_" + StringFromInt(fnc.idx)
	}
	return output
}
