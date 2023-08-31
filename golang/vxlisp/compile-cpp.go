package vxlisp

import (
	"strings"
)

var issharedpointer = false

func ListCaptureFromArg(arg vxarg, listinnerarg []string, path string) []string {
	output := ListCaptureFromValue(arg.value, listinnerarg, path)
	return output
}

func ListCaptureFromFunc(fnc *vxfunc, listinnerarg []string, path string) []string {
	var output []string
	switch NameFromFunc(fnc) {
	case "vx/core/fn":
		listarg := fnc.listarg
		var listlocalarg []string
		if fnc.context {
			listlocalarg = append(listlocalarg, "context")
		}
		for _, arg := range listarg {
			subpath := path + "/:arg" + arg.name
			switch arg.name {
			case "params":
				subargvalue := arg.value
				listsubsubarg := ListArgFromValue(subargvalue)
				for _, subsubarg := range listsubsubarg {
					inner := CppFromName(subsubarg.alias)
					if !BooleanFromListStringContains(listlocalarg, inner) {
						listlocalarg = append(listlocalarg, inner)
					}
				}
			case "fn-any":
				var listmore []string
				listmore = ListCaptureFromValue(arg.value, listlocalarg, subpath)
				for _, outer := range listmore {
					if !BooleanFromListStringContains(output, outer) {
						output = append(output, outer)
					}
				}
			}
		}
	case "vx/core/let", "vx/core/let-async":
		listarg := fnc.listarg
		var listlocalarg []string
		if fnc.context {
			listlocalarg = append(listlocalarg, "context")
		}
		for _, arg := range listarg {
			subpath := path + "/:arg/" + arg.name
			switch arg.name {
			case "args":
				argvalue := arg.value
				listsubarg := ListArgFromValue(argvalue)
				for _, subarg := range listsubarg {
					inner := CppFromName(subarg.alias)
					if !BooleanFromListStringContains(listlocalarg, inner) {
						listlocalarg = append(listlocalarg, inner)
					}
				}
				for _, subarg := range listsubarg {
					subargvalue := subarg.value
					listmore := ListCaptureFromValue(subargvalue, listlocalarg, subpath)
					for _, outer := range listmore {
						if !BooleanFromListStringContains(output, outer) {
							output = append(output, outer)
						}
					}
				}
			case "fn-any":
				argvalue := arg.value
				switch argvalue.code {
				case ":arg":
					subarg := ArgFromValue(argvalue)
					outer := CppFromName(subarg.alias)
					if !BooleanFromListStringContains(listlocalarg, outer) {
						listlocalarg = append(listlocalarg, outer)
					}
				case ":func":
					listmore := ListCaptureFromValue(argvalue, listlocalarg, subpath)
					for _, outer := range listmore {
						if !BooleanFromListStringContains(output, outer) {
							output = append(output, outer)
						}
					}
				}
			}
		}
	case "vx/core/native":
		nativetext := StringFromNativeFunc(fnc, ":cpp")
		istartpos := IntFromStringFind(nativetext, "// :capture ")
		if istartpos >= 0 {
			iendpos := IntFromStringFindStart(nativetext, "\n", istartpos)
			if iendpos >= 0 {
				capturetext := nativetext[istartpos+12 : iendpos]
				capturetext = StringTrim(capturetext)
				capturetexts := ListStringFromStringSplit(capturetext, ", ")
				output = append(output, capturetexts...)
			}
		}
	default:
		if fnc.vxtype.isgeneric {
			genericname := CppGenericNameFromType(fnc.vxtype)
			output = append(output, genericname)
		}
		listarg := fnc.listarg
		for _, arg := range listarg {
			subpath := path + "/:arg/" + arg.name
			value := arg.value
			listmore := ListCaptureFromValue(value, listinnerarg, subpath)
			for _, outer := range listmore {
				if !BooleanFromListStringContains(output, outer) {
					output = append(output, outer)
				}
			}
		}
	}
	return output
}

func ListCaptureFromValue(value vxvalue, listinnerarg []string, path string) []string {
	var output []string
	switch value.code {
	case ":arg":
		arg := ArgFromValue(value)
		outer := arg.alias
		if outer == "" {
			outer = arg.name
		}
		outer = CppFromName(outer)
		if BooleanFromListStringContains(listinnerarg, outer) {
		} else if !BooleanFromListStringContains(output, outer) {
			output = append(output, outer)
		}
	case ":func":
		fnc := FuncFromValue(value)
		subpath := path + "/" + fnc.name + StringIndexFromFunc(fnc)
		listmore := ListCaptureFromFunc(fnc, listinnerarg, subpath)
		for _, more := range listmore {
			if BooleanFromListStringContains(listinnerarg, more) {
			} else if BooleanFromListStringContains(output, more) {
			} else {
				output = append(output, more)
			}
		}
		if fnc.context {
			output = append(output, "context")
		}
	}
	return output
}

func CppAbstractInterfaceFromInterface(typename string, interfaces string) (string, string) {
	abstractinterfaces := "" +
		"\n    Abstract_" + typename + "() {};" +
		"\n    virtual ~Abstract_" + typename + "() = 0;"
	classinterfaces := ""
	listinterfaces := ListStringFromStringSplit(interfaces, "\n")
	partial := ""
	for _, item := range listinterfaces {
		isfunc := false
		if partial == "" {
			if BooleanFromStringEnds(item, "(") {
				partial = item
			}
		} else {
			partial += "\n" + item
			if BooleanFromStringEnds(item, ";") {
				item = partial
				partial = ""
			}
		}
		if partial == "" {
			if BooleanFromStringEnds(item, ");") {
				isfunc = true
			} else if BooleanFromStringEnds(item, " override;") {
				isfunc = true
			} else if BooleanFromStringEnds(item, " const;") {
				isfunc = true
			}
			if isfunc {
				isstatic := BooleanFromStringContains(item, " static ")
				if isstatic {
					classinterfaces += "\n" + item
				} else {
					abstractinterface := StringFromStringFindReplace(item, ";", " = 0;")
					abstractinterface = StringTrim(abstractinterface)
					abstractinterfaces += "\n    virtual " + abstractinterface
					classinterface := StringTrim(item)
					classinterface = StringFromStringFindReplace(classinterface, ";", " override;")
					classinterfaces += "\n    virtual " + classinterface
				}
			} else if item != "" {
				abstractinterfaces += "\n" + item
			}
		}
	}
	return abstractinterfaces, classinterfaces
}

func CppArgMapFromListArg(listarg []vxarg, indent int) string {
	output := "vx_core::e_argmap()"
	if len(listarg) > 0 {
		var listtext []string
		for _, arg := range listarg {
			argtext := CppFromArg(arg, indent+1)
			listtext = append(listtext, argtext)
		}
		lineindent := "\n" + StringRepeat("  ", indent)
		output = "vx_core::vx_argmap_from_listarg({" + lineindent + "  " + StringFromListStringJoin(listtext, ","+lineindent+"  ") + lineindent + "})"
	}
	return output
}

func CppCaptureFromFunc(fnc *vxfunc, path string) string {
	var listinnerarg []string
	var listcapturetext []string = ListCaptureFromFunc(fnc, listinnerarg, path)
	output := StringFromListStringJoin(listcapturetext, ", ")
	return output
}

func CppCaptureFromValue(value vxvalue, path string) string {
	var listinnerarg []string
	var listcapturetext []string = ListCaptureFromValue(value, listinnerarg, path)
	output := StringFromListStringJoin(listcapturetext, ", ")
	return output
}

func CppCaptureFromValueListInner(value vxvalue, listinnerarg []string, path string) string {
	var listcapturetext []string = ListCaptureFromValue(value, listinnerarg, path)
	output := StringFromListStringJoin(listcapturetext, ", ")
	return output
}

func CppFolderCopyTestdataFromProjectPath(project *vxproject, targetpath string) *vxmsgblock {
	msgblock := NewMsgBlock("CppFileCopyTestdataFromProjectPath")
	sourcepath := PathFromProjectPath(project, "./testdata")
	if BooleanExistsFromPath(sourcepath) {
		msgs := FolderCopyFromSourceTarget(sourcepath, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	for _, subproject := range project.listproject {
		msgs := CppFolderCopyTestdataFromProjectPath(subproject, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func CppConstDefsFromListConst(values []*vxconst, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	var outputvalues []string
	if len(values) > 0 {
		for _, val := range values {
			name := "" +
				lineindent + "vx_core::Class_constdef::vx_constdef_new(" +
				lineindent + "  \"" + val.pkgname + "\"," +
				lineindent + "  \"" + val.name + "\"," +
				lineindent + "  null" +
				lineindent + ")"
			outputvalues = append(outputvalues, name)
		}
		output = "vx_core::arraylist_from_array(" + strings.Join(outputvalues, ",") + lineindent + ")"
	}
	return output
}

func CppDebugFromFunc(fnc *vxfunc, lineindent string) (string, string) {
	debugstart := ""
	debugend := ""
	if fnc.debug {
		debugstart = lineindent + "vx_core::debug(\"" + fnc.name + "\", \"start\""
		for _, arg := range fnc.listarg {
			debugstart += ", " + CppTypeStringValNew(arg.name+"=") + ", " + CppFromName(arg.alias)
		}
		debugstart += ");"
		debugend = lineindent + "vx_core::debug(\"" + fnc.name + "\", \"end\", output);"
	}
	return debugstart, debugend
}

func CppDocFromFunc(fnc *vxfunc) string {
	var doc = ""
	var argsdoc = ""
	switch NameFromFunc(fnc) {
	case "vx/core/copy", "vx/core/empty", "vx/core/new":
	default:
		//if fnc.isgeneric {
		//	argsdoc += "\n@param  {generic} generic_any_1"
		//}
	}
	for _, arg := range fnc.listarg {
		argsdoc += "\n@param "
		if arg.vxtype.name != "" {
			argsdoc += " {" + arg.vxtype.name + "}"
		}
		argsdoc += " " + arg.alias
		if arg.doc != "" {
			argsdoc += " " + arg.doc
		}
	}
	if fnc.async {
		doc += "" +
			"\n@async" +
			"\n"
	}
	doc += "@function " + CppFromName(fnc.alias)
	if fnc.idx > 0 {
		doc += " " + StringFromInt(fnc.idx)
	}
	if fnc.doc != "" {
		doc += "\n" + fnc.doc
	}
	if fnc.deprecated != "" {
		doc += "\n" + fnc.deprecated
	}
	doc += "" +
		argsdoc +
		"\n@return {" + fnc.vxtype.name + "}"
	output := "" // +
	//"  /**" +
	//"\n   * " + StringFromStringIndent(doc, "   * ") +
	//"\n   * (func " + fnc.name + ")" +
	//"\n   */"
	return output
}

func CppEmptyValueFromType(typ *vxtype) string {
	return CppEmptyValueFromTypeIndent(typ, "")
}

func CppEmptyValueFromTypeIndent(typ *vxtype, indent string) string {
	output := "\"\""
	if len(indent) < 10 {
		output = typ.defaultvalue
		switch typ.extends {
		case "string":
			output = "\"" + output + "\""
		case ":list":
			output = "vx_core::f_type_to_list(" + CppNameFromPkgName(typ.pkgname) + "::t_" + typ.name + ")"
		default:
			if len(typ.properties) > 0 {
				output = "{\n"
				for _, property := range typ.properties {
					propdefault := CppEmptyValueFromTypeIndent(property.vxtype, indent+"  ")
					output += indent + "    " + CppFromName(property.name) + ": " + propdefault + ","
					if property.doc != "" {
						output += " // " + property.doc
					}
					output += "\n"
				}
				output += "" +
					indent + "    vxtype: " + CppNameFromPkgName(typ.pkgname) + "::t_" + CppFromName(typ.name) +
					"\n" + indent + "  }"
			} else if output == "" || strings.HasPrefix(output, ":") {
				output = "\"" + output + "\""
			}
		}
	}
	return output
}

func CppFilesFromProjectCmd(project *vxproject, command *vxcommand) ([]*vxfile, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFilesFromProjectCmd")
	var files []*vxfile
	cmdpath := PathFromProjectCmd(project, command)
	switch command.code {
	case ":source":
		file := NewFile()
		file.name = "app.cpp"
		file.path = cmdpath
		file.text = CppApp(project)
		files = append(files, file)
	case ":test":
		file := NewFile()
		file.name = "app_test.cpp"
		file.path = cmdpath
		file.text = CppAppTest(project)
		files = append(files, file)
		testlibbody, testlibheader := CppTestLib()
		file = NewFile()
		file.name = "test_lib.cpp"
		file.path = cmdpath
		file.text = testlibbody
		files = append(files, file)
		file = NewFile()
		file.name = "test_lib.hpp"
		file.path = cmdpath
		file.text = testlibheader
		files = append(files, file)
	}
	pkgs := ListPackageFromProject(project)
	for _, pkg := range pkgs {
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringFromStringFindReplace(pkgname, "/", "_")
		switch command.code {
		case ":source":
			text, header, msgs := CppFromPackage(pkg, project)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + ".cpp"
			file.path = cmdpath + "/" + pkgpath
			file.text = text
			files = append(files, file)
			file = NewFile()
			file.name = pkgname + ".hpp"
			file.path = cmdpath + "/" + pkgpath
			file.text = header
			files = append(files, file)
		case ":test":
			text, header, msgs := CppTestFromPackage(pkg, project)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + "_test.cpp"
			file.path = cmdpath + "/" + pkgpath
			file.text = text
			files = append(files, file)
			file = NewFile()
			file.name = pkgname + "_test.hpp"
			file.path = cmdpath + "/" + pkgpath
			file.text = header
			files = append(files, file)
		}
	}
	return files, msgblock
}

func CppFromArg(arg vxarg, indent int) string {
	lineindent := "\n" + StringRepeat("  ", indent)
	output := "" +
		"vx_core::vx_new_arg(" +
		lineindent + "  \"" + arg.name + "\", // name" +
		lineindent + "  " + CppNameTFromType(arg.vxtype) + " // type" +
		lineindent + ")"
	return output
}

func CppFromBoolean(istrue bool) string {
	output := "false"
	if istrue {
		output = "true"
	}
	return output
}

func CppFromConst(cnst *vxconst, pkg *vxpackage) (string, string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFromConst")
	var doc = ""
	path := cnst.pkgname + "/" + cnst.name
	doc += "Constant: " + cnst.name + "\n"
	if cnst.doc != "" {
		doc += cnst.doc + "\n"
	}
	if cnst.deprecated != "" {
		doc += cnst.deprecated + "\n"
	}
	cnsttype := cnst.vxtype
	doc += "{" + cnsttype.name + "}"
	cnstname := CppFromName(cnst.alias)
	cnstclassname := "Class_" + cnstname
	cnsttypename := CppNameFromType(cnst.vxtype)
	cnsttypeclassname := CppNameTypeFullFromType(cnsttype)
	pkgname := CppNameFromPkgName(cnst.pkgname)
	fullclassname := pkgname + "::Class_" + cnstname
	fullconstname := pkgname + "::Const_" + cnstname
	initval := ""
	cnstval := StringValueFromValue(cnst.value)
	headerextras := ""
	switch NameFromType(cnsttype) {
	case "vx/core/boolean":
		if cnstval == "" {
			switch NameFromConst(cnst) {
			case "vx/core/true":
				cnstval = "true"
			default:
				cnstval = "false"
			}
		}
		cnstval = "\n      output->vx_p_boolean = " + cnstval + ";"
		headerextras += "\n    bool vx_boolean() const override;"
		initval = "" +
			"\n    bool " + fullclassname + "::vx_boolean() const {" +
			"\n      return this->vx_p_boolean;" +
			"\n    }"
	case "vx/core/decimal":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      output->vx_p_decimal = " + cnstval + ";"
		headerextras += "\n    std::string vx_decimal() const override;"
		initval = "" +
			"\n    std::string " + fullclassname + "::vx_decimal() const {" +
			"\n      return this->vx_p_decimal;" +
			"\n    }"
	case "vx/core/float":
		if cnstval == "" {
			cnstval = "f0"
		}
		cnstval = "\n      output->vx_p_float = " + cnstval + ";"
		headerextras += "\n    float vx_float() const override;"
		initval = "" +
			"\n    float " + fullclassname + "::vx_float() const {" +
			"\n      return this->vx_p_float;" +
			"\n    }"
	case "vx/core/int":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      output->vx_p_int = " + cnstval + ";"
		headerextras += "\n    long vx_int() const override;"
		initval = "" +
			"\n    long " + fullclassname + "::vx_int() const {" +
			"\n      return this->vx_p_int;" +
			"\n    }"
	case "vx/core/string":
		cnstval = "\n      output->vx_p_string = " + cnstval + ";"
		headerextras += "\n    std::string vx_string() const override;"
		initval = "" +
			"\n    std::string " + fullclassname + "::vx_string() const {" +
			"\n      return this->vx_p_string;" +
			"\n    }"
	default:
		switch cnsttype.extends {
		case ":list":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				listtypename := cnsttypename
				if listtypename == "any" {
					listtypename = ""
				}
				cnstval = "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output->vx_p_list" + listtypename + " = val->vx_list" + listtypename + "();"
			}
		case ":map":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				maptypename := cnsttypename
				if maptypename == "any" {
					maptypename = ""
				}
				cnstval = "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output->vx_p_map" + maptypename + " = val->vx_map" + maptypename + "();"
			}
		case ":struct":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				cnstval = "" +
					"\n      long irefcount = vx_core::refcount;" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";"
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					cnstval += "" +
						"\n      output->vx_p_" + CppFromName(prop.name) + " = val->" + CppFromName(prop.name) + "();" +
						"\n      vx_core::vx_reserve(output->vx_p_" + CppFromName(prop.name) + ");"
				}
				cnstval += "" +
					"\n      vx_core::vx_release(val);" +
					"\n      vx_core::refcount = irefcount;"
			}
			/*
				clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "        ", true, false, path)
				msgblock = MsgBlockAddBlock(msgblock, msgs)
				if clstext != "" {
					cnstval = "" +
						"\n      if ((!this->vx_p_map) || (this->vx_p_map.size() == 0)) {" +
						"\n        " + cnsttypeclassname + " orig = " + clstext + ";" +
						"\n        this->vx_p_map = orig->vx_map();" +
						"\n      }"
					initval = "" +
						"\n    std::map<std::string, vx_core::Type_any> vx_map() {" +
						cnstval +
						"\n      return this->vx_p_map;" +
						"\n    }"
				}
			*/
		}
	}
	extends := CppNameClassFullFromType(cnsttype)
	headers := "" +
		"\n  // (const " + cnst.name + ")" +
		"\n  class Class_" + cnstname + " : public " + extends + " {" +
		"\n  public:" +
		"\n    static " + fullconstname + " vx_const_new();" +
		"\n    vx_core::Type_constdef vx_constdef() const;" +
		headerextras +
		"\n  };" +
		"\n"
	output := "" +
		//"\n  /**" +
		//"\n   * " + StringFromStringIndent(doc, "   * ") +
		//"\n   */" +
		"\n  // (const " + cnst.name + ")" +
		"\n  // class " + cnstclassname + " {" +
		"\n" +
		"\n    // vx_const_new()" +
		"\n    " + fullconstname + " " + fullclassname + "::vx_const_new() {" +
		"\n      " + fullconstname + " output = new " + fullclassname + "();" +
		cnstval +
		"\n      vx_core::vx_reserve_type(output);" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    // vx_constdef()" +
		"\n    vx_core::Type_constdef " + fullclassname + "::vx_constdef() const {" +
		"\n      return vx_core::Class_constdef::vx_constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + CppTypeDefFromType(cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n" +
		initval +
		"\n" +
		"\n  //}" +
		"\n"
	bodyfooter := "" +
		"\n  // (const " + cnst.name + ")" +
		"\n  " + fullconstname + " c_" + cnstname + "() {" +
		"\n    " + fullconstname + " output = " + pkgname + "::vx_package->c_" + cnstname + ";" +
		"\n    if (output == NULL) {" +
		"\n      output = " + fullclassname + "::vx_const_new();" +
		"\n      " + pkgname + "::vx_package->c_" + cnstname + " = output;" +
		"\n    }" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	return output, headers, bodyfooter, msgblock
}

func CppBodyFromFunc(fnc *vxfunc) (string, string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppBodyFromFunc")
	var listargtype []string
	var listargname []string
	var listsimplearg []string
	var listreleasename []string
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async", "vx/core/any<-key-value-async",
		"vx/core/any<-none-async", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next-async":
		listsimplearg = append(listsimplearg, "vx_core::Type_any generic_any_1")
	}
	funcname := CppFromName(fnc.alias) + CppIndexFromFunc(fnc)
	returntype := ""
	returnttype := ""
	returnetype := ""
	if fnc.generictype == nil {
		returntype = CppGenericFromType(fnc.vxtype)
		returnttype = CppNameTFromType(fnc.vxtype)
		returnetype = CppNameEFromType(fnc.vxtype)
	} else {
		returntype = CppPointerDefFromClassName(CppGenericFromType(fnc.generictype))
		returnttype = CppNameTFromType(fnc.generictype)
		returnetype = CppNameEFromType(fnc.generictype)
	}
	pkgname := CppNameFromPkgName(fnc.pkgname)
	instancevars := ""
	//	constructor := ""
	//	destructor := ""
	staticvars := ""
	instancefuncs := ""
	//staticfuncs := ""
	path := fnc.pkgname + "/" + fnc.name + CppIndexFromFunc(fnc)
	genericdefinition := CppGenericDefinitionFromFunc(fnc)
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		case "vx/core/any<-any", "vx/core/any<-any-async",
			"vx/core/any<-any-context", "vx/core/any<-any-context-async",
			"vx/core/any<-func", "vx/core/any<-func-async",
			"vx/core/any<-key-value", "vx/core/any<-key-value-async",
			"vx/core/any<-none", "vx/core/any<-none-async",
			"vx/core/any<-reduce", "vx/core/any<-reduce-async",
			"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
			argtext := CppPointerDefFromClassName("T") + " generic_any_1"
			listargtype = append(listargtype, argtext)
		default:
			if fnc.generictype != nil {
				genericargname := CppNameTFromTypeGeneric(fnc.generictype)
				argtext := CppPointerDefFromClassName(CppGenericFromType(fnc.generictype)) + " " + genericargname
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, genericargname)
			}
		}
	}
	switch NameFromFunc(fnc) {
	case "vx/core/let":
		argtext := "vx_core::Func_any_from_func fn_any"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any")
		listreleasename = append(listreleasename, "fn_any")
	case "vx/core/let-async":
		argtext := "vx_core::Func_any_from_func_async fn_any_async"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any_async")
		listreleasename = append(listreleasename, "fn_any_async")
	default:
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if fnc.generictype != nil && argtype.isgeneric {
				argtypename = CppPointerDefFromClassName(CppGenericFromType(argtype))
			} else {
				argtypename = CppNameTypeFromType(argtype)
			}
			argtext := argtypename + " " + CppFromName(arg.alias)
			listsimplearg = append(listsimplearg, CppNameTypeFromType(argtype)+" "+CppFromName(arg.alias))
			listargname = append(listargname, CppFromName(arg.alias))
			listreleasename = append(listreleasename, CppFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	contextarg := ""
	if fnc.context {
		contextarg = ", vx_core::Type_context context"
		listargtype = append(listargtype, "vx_core::Type_context context")
		listargname = append(listargname, "context")
		listsimplearg = append(listsimplearg, "vx_core::Type_context context")
	}
	//var funcgenerics []string
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = CppPointerDefFromClassName(CppGenericFromType(fnc.generictype))
	} else {
		functypetext = returntype
	}
	if fnc.async {
		functypetext = "vx_core::vx_Type_async"
	}
	simpleargtext := StringFromListStringJoin(listsimplearg, ", ")
	classname := "Class_" + funcname
	fullabstractname := pkgname + "::Abstract_" + funcname
	fullclassname := pkgname + "::Class_" + funcname
	fullfuncname := pkgname + "::Func_" + funcname
	fulltname := CppNameTFromFunc(fnc)
	fullename := CppNameEFromFunc(fnc)
	constructor := "" +
		"\n      vx_core::refcount += 1;"
	destructor := "" +
		"\n      vx_core::refcount -= 1;" +
		"\n      if (this->vx_p_msgblock) {" +
		"\n        vx_core::vx_release_one(this->vx_p_msgblock);" +
		"\n      }"
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-context", "vx/core/any<-func",
		"vx/core/any<-none", "vx/core/any<-key-value",
		"vx/core/any<-reduce", "vx/core/any<-reduce-next":
		destructor += "" +
			"\n      vx_core::vx_release_one(this->lambdavars);"
		instancevars += "" +
			"\n    " + fullfuncname + " " + classname + "::vx_fn_new(vx_core::vx_Type_listany lambdavars, " + fullabstractname + "::IFn fn) const {" +
			"\n      " + fullfuncname + " output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->fn = fn;" +
			"\n      output->lambdavars = lambdavars;" +
			"\n      vx_core::vx_reserve(lambdavars);" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    vx_core::Type_any " + classname + "::vx_" + funcname + "(" + simpleargtext + ") const {" +
			"\n      vx_core::Type_any output = vx_core::e_any();" +
			"\n      if (fn) {" +
			"\n        output = fn(" + StringFromListStringJoin(listargname, ", ") + ");" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async",
		"vx/core/any<-none-async", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce-async", "vx/core/any<-reduce-next-async":
		destructor += "" +
			"\n      vx_core::vx_release_one(this->lambdavars);"
		instancevars += "" +
			"\n    " + fullfuncname + " " + classname + "::vx_fn_new(vx_core::vx_Type_listany lambdavars, " + fullabstractname + "::IFn fn) const {" +
			"\n      " + fullfuncname + " output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->fn = fn;" +
			"\n      output->lambdavars = lambdavars;" +
			"\n      vx_core::vx_reserve(lambdavars);" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    vx_core::vx_Type_async " + classname + "::vx_" + funcname + "(" + simpleargtext + ") const {" +
			"\n      vx_core::vx_Type_async output = NULL;" +
			"\n      if (fn) {" +
			"\n        output = fn(" + StringFromListStringJoin(listargname, ", ") + ");" +
			"\n        output->type = generic_any_1;" +
			"\n      } else {" +
			"\n        output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		destructor += "" +
			"\n      vx_core::vx_release_one(this->lambdavars);"
		instancefuncs += "" +
			"\n    " + fullfuncname + " " + fullclassname + "::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_" + CppFromName(fnc.vxtype.alias) + "_from_func::IFn fn) const {" +
			"\n      " + fullfuncname + " output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->fn = fn;" +
			"\n      output->lambdavars = lambdavars;" +
			"\n      vx_core::vx_reserve(lambdavars);" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    " + returntype + " " + classname + "::vx_" + funcname + "(" + simpleargtext + ") const {" +
			"\n      " + returntype + " output = " + returnetype + ";" +
			"\n      if (fn) {" +
			"\n        output = fn(" + StringFromListStringJoin(listargname, ", ") + ");" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	default:
		switch returntype {
		case "void":
		default:
			switch len(fnc.listarg) {
			case 1:
				argtypename := ""
				arg := fnc.listarg[0]
				argtypename = CppNameTypeFromType(arg.vxtype)
				argtname := CppNameTFromType(arg.vxtype)
				subargnames := "inputval"
				switch NameFromFunc(fnc) {
				case "vx/core/empty":
				default:
					if fnc.generictype != nil {
						subargnames = CppNameTFromType(fnc.vxtype) + ", inputval"
					}
				}
				contextname := ""
				if fnc.context {
					contextname = "_context"
					subargnames += ", context"
				}
				if fnc.async {
					asyncbody := ""
					issamegeneric := false
					fncgenerictype := fnc.generictype
					argtype := arg.vxtype
					if fncgenerictype == nil {
					} else if fncgenerictype.name == argtype.name {
						issamegeneric = true
					} else if argtype.isfunc && fncgenerictype.name == argtype.vxfunc.vxtype.name {
						// type = (func : generic)
						issamegeneric = true
					}
					if issamegeneric {
						// both generics are the same
						asyncbody += "" +
							"\n      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(val);"
					} else {
						asyncbody += "" +
							"\n      " + CppNameTypeFromType(arg.vxtype) + " inputval = vx_core::vx_any_from_any(" + CppNameTFromType(arg.vxtype) + ", val);" +
							"\n      vx_core::vx_Type_async output = " + pkgname + "::f_" + funcname + "(" + subargnames + ");"
					}
					instancefuncs += "" +
						"\n    vx_core::Func_any_from_any" + contextname + "_async " + classname + "::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any" + contextname + "_async::IFn fn) const {" +
						"\n      return vx_core::e_any_from_any" + contextname + "_async();" +
						"\n    }" +
						"\n" +
						"\n    vx_core::vx_Type_async " + classname + "::vx_any_from_any" + contextname + "_async(vx_core::Type_any generic_any_1, vx_core::Type_any val" + contextarg + ") const {" +
						asyncbody +
						"\n      vx_core::vx_release(val);" +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					instancefuncs += "" +
						"\n    vx_core::Func_any_from_any" + contextname + " " + classname + "::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any" + contextname + "::IFn fn) const {" +
						"\n      return vx_core::e_any_from_any" + contextname + "();" +
						"\n    }" +
						"\n" +
						"\n    vx_core::Type_any " + classname + "::vx_any_from_any" + contextname + "(vx_core::Type_any val" + contextarg + ") const {" +
						"\n      vx_core::Type_any output = vx_core::e_any();" +
						"\n      " + argtypename + " inputval = vx_core::vx_any_from_any(" + argtname + ", val);" +
						"\n      output = " + pkgname + "::f_" + funcname + "(" + subargnames + ");" +
						"\n      vx_core::vx_release_except(val, output);" +
						"\n      return output;" +
						"\n    }" +
						"\n"
				}
			}
		}
	}
	repltext := CppReplFromFunc(fnc)
	instancefuncs += repltext
	valuetext, msgs := CppFromValue(fnc.value, fnc.pkgname, fnc, 0, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	valuetexts := ListStringFromStringSplit(valuetext, "\n")
	var chgvaluetexts []string
	chgvaluetexts = append(chgvaluetexts, valuetexts...)
	indent := "    "
	lineindent := "\n" + indent
	msgtop := ""
	msgbottom := ""
	permissiontop := ""
	permissionbottom := ""
	if fnc.permission {
		permissiontop = lineindent + "if (vx_core::f_boolean_permission_from_any(" + fulltname + ", context)) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			lineindent + "  vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"Permission Denied: " + fnc.name + "\");" +
			lineindent + "  output = vx_core::vx_copy(" + fulltname + ", {msg});" +
			lineindent + "}"
		indent += "  "
	}
	if fnc.messages {
		msgtop = lineindent + "try {"
		msgbottom = "" +
			lineindent + "} catch (std::exception err) {" +
			lineindent + "  vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception(\"" + fnc.name + "\", err);" +
			lineindent + "  output = vx_core::vx_copy(" + returnttype + ", {msg});" +
			lineindent + "}"
	}
	lineindent = "\n" + indent
	valuetext = StringFromListStringJoin(chgvaluetexts, "\n")
	if IntFromStringFind(valuetext, "output ") >= 0 {
	} else if IntFromStringFind(valuetext, "output->") >= 0 {
	} else if fnc.vxtype.name == "none" {
	} else if valuetext == "" {
	} else {
		valuetext = "output = " + valuetext
	}
	if valuetext == "" {
	} else if !BooleanFromStringEnds(valuetext, ";") {
		valuetext += ";"
	}
	if valuetext != "" {
		if fnc.messages {
			valuetext = "\n  " + indent + StringFromStringIndent(valuetext, "  "+indent)
		} else {
			valuetext = "\n" + indent + StringFromStringIndent(valuetext, indent)
		}
	}
	debugtop, debugbottom := CppDebugFromFunc(fnc, lineindent)
	returnvalue := ""
	interfacefn := CppHeaderFnFromFunc(fnc)
	if interfacefn == "" {
		if returntype != "void" {
			returnvalue += "\n      return "
		}
		returnvalue += pkgname + "::f_" + funcname + "(" + StringFromListStringJoin(listargname, ", ") + ");"
	} else if fnc.async {
		returnvalue += "" +
			"\n      vx_core::vx_Type_async output;" +
			"\n      if (!fn) {" +
			"\n        output = vx_core::vx_async_new_from_value(vx_core::vx_empty(generic_any_1));" +
			"\n      } else {" +
			"\n        output = fn(" + StringFromListStringJoin(listargname, ", ") + ");" +
			"\n      }" +
			"\n      return output;"
	} else {
		if BooleanFromStringStarts(fnc.name, "boolean<-") {
			returnvalue += "" +
				"\n      vx_core::Type_boolean output = vx_core::c_false();" +
				"\n      if (fn) {" +
				"\n        output = vx_core::vx_any_from_any(vx_core::t_boolean(), fn(" + StringFromListStringJoin(listargname, ", ") + "));" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "int<-") {
			returnvalue += "" +
				"\n      vx_core::Type_int output = vx_core::e_int();" +
				"\n      if (fn) {" +
				"\n        output = vx_core::vx_any_from_any(vx_core::t_int(), fn(" + StringFromListStringJoin(listargname, ", ") + "));" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "string<-") {
			returnvalue += "" +
				"\n      vx_core::Type_string output = vx_core::e_string();" +
				"\n      if (fn) {" +
				"\n        output = vx_core::vx_any_from_any(vx_core::t_string(), fn(" + StringFromListStringJoin(listargname, ", ") + "));" +
				"\n      }"
		} else {
			returnvalue += "" +
				"\n      " + CppPointerDefFromClassName("T") + " output = vx_core::vx_empty(generic_any_1);" +
				"\n      if (fn) {" +
				"\n        output = vx_core::vx_any_from_any(generic_any_1, fn(" + StringFromListStringJoin(listargname, ", ") + "));" +
				"\n      }"
		}
		if returntype != "void" {
			returnvalue += "\n      return output;"
		}
	}
	reserve := ""
	release := ""
	after := ""
	switch len(listreleasename) {
	case 0:
	case 1:
		reserve = "" +
			lineindent + "vx_core::vx_reserve(" + StringFromListStringJoin(listreleasename, ", ") + ");"
		if fnc.async || fnc.vxtype.name == "none" {
			release = "" +
				lineindent + "vx_core::vx_release_one(" + StringFromListStringJoin(listreleasename, ", ") + ");"
		} else {
			release = "" +
				lineindent + "vx_core::vx_release_one_except(" + StringFromListStringJoin(listreleasename, ", ") + ", output);"
		}
	default:
		reserve = "" +
			lineindent + "vx_core::vx_reserve({" + StringFromListStringJoin(listreleasename, ", ") + "});"
		if fnc.async || fnc.vxtype.name == "none" {
			release = "" +
				lineindent + "vx_core::vx_release_one({" + StringFromListStringJoin(listreleasename, ", ") + "});"
		} else {
			release = "" +
				lineindent + "vx_core::vx_release_one_except({" + StringFromListStringJoin(listreleasename, ", ") + "}, output);"
		}
	}
	defaultvalue := ""
	switch NameFromFunc(fnc) {
	case "vx/core/new", "vx/core/copy", "vx/core/empty":
	default:
		if fnc.vxtype.name == "none" {
		} else if fnc.async {
			defaultvalue = lineindent + "vx_core::vx_Type_async output = NULL;"
			after += "" +
				lineindent + "if (!output) {" +
				lineindent + "  output = vx_core::vx_async_new_from_value(" + CppNameEFromType(fnc.vxtype) + ");" +
				lineindent + "}"
		} else if fnc.generictype != nil {
			defaultvalue = lineindent + returntype + " output = vx_core::vx_empty(" + CppNameTFromTypeGeneric(fnc.generictype) + ");"
		} else {
			defaultvalue = lineindent + returntype + " output = " + CppNameEFromType(fnc.vxtype) + ";"
		}
	}
	if fnc.vxtype.name == "none" {
	} else {
		after += lineindent + "return output;"
	}
	fdefinition := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  " + genericdefinition + functypetext + " f_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		debugtop +
		defaultvalue +
		reserve +
		permissiontop +
		msgtop +
		valuetext +
		msgbottom +
		permissionbottom +
		debugbottom +
		release +
		after +
		"\n  }" +
		"\n"
	staticfunction := ""
	output := ""
	if genericdefinition == "" {
		output += fdefinition
	} else {
		staticfunction = fdefinition
	}
	doc := CppDocFromFunc(fnc)
	output += "" +
		doc +
		"\n  // (func " + fnc.name + ")" +
		"\n  // class " + classname + " {" +
		"\n    Abstract_" + funcname + "::~Abstract_" + funcname + "() {}" +
		"\n" +
		"\n    " + classname + "::" + classname + "() : Abstract_" + funcname + "::Abstract_" + funcname + "() {" +
		constructor +
		"\n    }" +
		"\n" +
		"\n    " + classname + "::~" + classname + "() {" +
		destructor +
		"\n    }" +
		"\n" +
		instancevars +
		"\n    vx_core::Type_any " + classname + "::vx_new(vx_core::vx_Type_listany vals) const {" +
		"\n      " + pkgname + "::Func_" + funcname + " output = " + fullename + ";" +
		"\n      vx_core::vx_release(vals);" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_any " + classname + "::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {" +
		"\n      " + pkgname + "::Func_" + funcname + " output = " + fullename + ";" +
		"\n      vx_core::vx_release_except(copyval, output);" +
		"\n      vx_core::vx_release_except(vals, output);" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_typedef " + classname + "::vx_typedef() const {" +
		"\n      vx_core::Type_typedef output = " + CppTypeDefFromFunc(fnc, "      ") + ";" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_funcdef " + classname + "::vx_funcdef() const {" +
		"\n      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(" +
		"\n        \"" + fnc.pkgname + "\", // pkgname" +
		"\n        \"" + fnc.name + "\", // name" +
		"\n        " + StringFromInt(fnc.idx) + ", // idx" +
		"\n        " + StringFromBoolean(fnc.async) + ", // async" +
		"\n        this->vx_typedef() // typedef" +
		"\n      );" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_any " + classname + "::vx_empty() const {return " + fullename + ";}" +
		"\n    vx_core::Type_any " + classname + "::vx_type() const {return " + fulltname + ";}" +
		"\n    vx_core::Type_msgblock " + classname + "::vx_msgblock() const {return this->vx_p_msgblock;}" +
		"\n    vx_core::vx_Type_listany " + classname + "::vx_dispose() {return vx_core::emptylistany;}" +
		"\n" +
		staticvars +
		instancefuncs +
		"\n  //}" +
		"\n"
	footer := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  " + fullfuncname + " e_" + funcname + "() {" +
		"\n    " + fullfuncname + " output = " + pkgname + "::vx_package->e_" + funcname + ";" +
		"\n    if (!output) {" +
		"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
		"\n      vx_core::vx_reserve_empty(output);" +
		"\n      " + pkgname + "::vx_package->e_" + funcname + " = output;" +
		"\n    }" +
		"\n    return output;" +
		"\n  }" +
		"\n  " + fullfuncname + " t_" + funcname + "() {" +
		"\n    " + fullfuncname + " output = " + pkgname + "::vx_package->t_" + funcname + ";" +
		"\n    if (!output) {" +
		"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
		"\n      vx_core::vx_reserve_type(output);" +
		"\n      " + pkgname + "::vx_package->t_" + funcname + " = output;" +
		"\n    }" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	return output, staticfunction, footer, msgblock
}

func CppConstListFromListConst(listconst []*vxconst) string {
	output := "vx_core::e_anylist()"
	if len(listconst) > 0 {
		var listtext []string
		for _, cnst := range listconst {
			typetext := CppNameFromConst(cnst)
			listtext = append(listtext, typetext)
		}
		output = "vx_core::vx_anylist_from_listany({" + StringFromListStringJoin(listtext, ", ") + "})"
	}
	return output
}

func CppFuncDefsFromFuncs(funcs []*vxfunc, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(funcs) > 0 {
		var outputtypes []string
		for _, fnc := range funcs {
			name := "" +
				lineindent + "  vx_core::Type_funcdef::vx_funcdef_new(" +
				lineindent + "    \"" + fnc.pkgname + "\"," +
				lineindent + "    \"" + fnc.name + "\"," +
				lineindent + "    " + StringFromInt(fnc.idx) + "," +
				lineindent + "    " + StringFromBoolean(fnc.async) + "," +
				lineindent + "    null" +
				lineindent + "  )"
			outputtypes = append(outputtypes, name)
		}
		output = "vx_core::arraylist_from_array(" + StringFromListStringJoin(outputtypes, ",") + lineindent + ")"
	}
	return output
}

func CppFromName(name string) string {
	output := name
	switch output {
	case "extends":
		output = "extend"
	}
	output = StringFromStringFindReplace(output, "->", "_to_")
	output = StringFromStringFindReplace(output, "<-", "_from_")
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func CppFromPackage(pkg *vxpackage, prj *vxproject) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFromPackage")
	pkgname := CppFromName(pkg.name)
	var specialtypeorder []string
	var specialfuncorder []string
	specialfirst := ""
	specialheader := ""
	specialbody := ""
	extratext, ok := prj.maptext[pkg.name+"_cpp.txt"]
	if ok {
		delimheaderfirst := "// :headerfirst\n"
		delimheadertype := "// :headertype\n"
		delimheaderfunc := "// :headerfunc\n"
		delimheader := "// :header\n"
		delimbody := "// :body\n"
		specialfirst = StringFromStringFromTo(extratext, delimheaderfirst, delimheadertype)
		specialtype := StringFromStringFromTo(extratext, delimheadertype, delimheaderfunc)
		specialfunc := StringFromStringFromTo(extratext, delimheaderfunc, delimheader)
		specialheader = StringFromStringFromTo(extratext, delimheader, delimbody)
		specialbody = StringFromStringFromTo(extratext, delimbody, "")
		if specialtype != "" {
			specialtype = StringFromStringFindReplace(specialtype, delimheadertype, "")
			specialtypeorder = ListStringFromStringSplit(specialtype, "\n")
		}
		if specialfunc != "" {
			specialfunc = StringFromStringFindReplace(specialfunc, delimheaderfunc, "")
			specialfuncorder = ListStringFromStringSplit(specialfunc, "\n")
		}
	}
	forwardheader := "\n  // forward declarations"
	typkeys := ListKeyFromMapType(pkg.maptype)
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typename := CppFromName(typ.alias)
		forwardheader += "" +
			"\n  class Abstract_" + typename + ";" +
			"\n  typedef " + CppPointerDefFromClassName("Abstract_"+typename) + " Type_" + typename + ";" +
			"\n  extern Type_" + typename + " e_" + typename + "();" +
			"\n  extern Type_" + typename + " t_" + typename + "();"
	}
	for _, constid := range cnstkeys {
		cnst := pkg.mapconst[constid]
		constname := CppFromName(cnst.alias)
		forwardheader += "" +
			"\n  class Class_" + constname + ";" +
			"\n  typedef " + CppPointerDefFromClassName("Class_"+constname) + " Const_" + constname + ";" +
			"\n  extern Const_" + constname + " c_" + constname + "();"
	}
	for _, funcid := range fnckeys {
		fncs := pkg.mapfunc[funcid]
		for _, fnc := range fncs {
			funcname := CppFromName(fnc.alias) + CppIndexFromFunc(fnc)
			forwardheader += "" +
				"\n  class Abstract_" + funcname + ";" +
				"\n  typedef " + CppPointerDefFromClassName("Abstract_"+funcname) + " Func_" + funcname + ";" +
				"\n  extern Func_" + funcname + " e_" + funcname + "();" +
				"\n  extern Func_" + funcname + " t_" + funcname + "();"
		}
	}
	packageheader := ""
	typeheaders := ""
	typebodyfooters := ""
	typebodys := ""
	for _, typid := range specialtypeorder {
		if typid != "" {
			typ, ok := pkg.maptype[typid]
			if !ok {
				msg := NewMsg(":headertype type not found: " + pkg.name + "/" + typid)
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				typeheader := CppHeaderFromType(typ)
				typebody, typebodyfooter, msgs := CppBodyFromType(typ)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				typebodys += typebody
				typebodyfooters += typebodyfooter
				specialheader += typeheader
			}
			packageheader += "" +
				"\n    " + CppNameTypeFullFromType(typ) + " e_" + CppNameFromType(typ) + ";" +
				"\n    " + CppNameTypeFullFromType(typ) + " t_" + CppNameFromType(typ) + ";"
		}
	}
	remainingkeys := ListStringFromListStringNotMatch(typkeys, specialtypeorder)
	for _, typid := range remainingkeys {
		typ := pkg.maptype[typid]
		typeheader := CppHeaderFromType(typ)
		typebody, typebodyfooter, msgs := CppBodyFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typebodys += typebody
		typeheaders += typeheader
		typebodyfooters += typebodyfooter
		packageheader += "" +
			"\n    " + CppNameTypeFullFromType(typ) + " e_" + CppNameFromType(typ) + ";" +
			"\n    " + CppNameTypeFullFromType(typ) + " t_" + CppNameFromType(typ) + ";"
	}
	constheaders := ""
	constbodys := ""
	constbodyfooters := ""
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		constbody, constheader, constbodyfooter, msgs := CppFromConst(cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		constbodys += constbody
		constheaders += constheader
		constbodyfooters += constbodyfooter
		packageheader += "" +
			"\n    " + CppNameTypeFullFromConst(cnst) + " c_" + CppNameFromConst(cnst) + ";"
	}
	funcheaders := ""
	funcstaticdeclaration := ""
	funcstaticbody := ""
	funcbodyfooters := ""
	funcbodys := ""
	for _, fncid := range specialfuncorder {
		if fncid != "" {
			fncs, ok := pkg.mapfunc[fncid]
			if !ok {
				msg := NewMsg(":headerfunc func not found: " + pkg.name + "/" + fncid)
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				for _, fnc := range fncs {
					fncheader, fncheaderfooter := CppHeaderFromFunc(fnc)
					specialheader += fncheader
					funcstaticdeclaration += fncheaderfooter
					fncbody, staticfunction, fncbodyfooter, msgs := CppBodyFromFunc(fnc)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					funcbodys += fncbody
					funcbodyfooters += fncbodyfooter
					funcstaticbody += staticfunction
					packageheader += "" +
						"\n    " + CppNameTypeFullFromFunc(fnc) + " e_" + CppNameFromFunc(fnc) + ";" +
						"\n    " + CppNameTypeFullFromFunc(fnc) + " t_" + CppNameFromFunc(fnc) + ";"
				}
			}
		}
	}
	remainingkeys = ListStringFromListStringNotMatch(fnckeys, specialfuncorder)
	for _, fncid := range remainingkeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fncheader, fncheaderfooter := CppHeaderFromFunc(fnc)
			fncbody, staticfunction, fncbodyfooter, msgs := CppBodyFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			funcbodys += fncbody
			funcbodyfooters += fncbodyfooter
			funcheaders += fncheader
			funcstaticdeclaration += fncheaderfooter
			funcstaticbody += staticfunction
			packageheader += "" +
				"\n    " + CppNameTypeFullFromFunc(fnc) + " e_" + CppNameFromFunc(fnc) + ";" +
				"\n    " + CppNameTypeFullFromFunc(fnc) + " t_" + CppNameFromFunc(fnc) + ";"
		}
	}
	headerfilename := pkg.name
	ipos := IntFromStringFindLast(headerfilename, "/")
	if ipos >= 0 {
		headerfilename = headerfilename[ipos+1:]
	}
	body := "" +
		specialbody +
		"\n" +
		typebodys +
		constbodys +
		funcbodys +
		"\n  " + pkgname + "::vx_Class_package* vx_package = new " + pkgname + "::vx_Class_package();" +
		"\n" +
		typebodyfooters +
		constbodyfooters +
		funcbodyfooters
		//		emptytypes
	header := "" +
		forwardheader +
		"\n" +
		"\n  class vx_Class_package {" +
		"\n  public:" +
		packageheader +
		"\n  };" +
		"\n" +
		"\n" +
		specialfirst +
		specialheader +
		funcstaticdeclaration +
		typeheaders +
		constheaders +
		funcheaders +
		funcstaticbody
	headerimports := CppImportsFromPackage(pkg, "", header, false)
	headeroutput := "" +
		"#ifndef " + StringUCase(pkgname+"_hpp") +
		"\n#define " + StringUCase(pkgname+"_hpp") +
		"\n" +
		headerimports +
		"\nnamespace " + pkgname + " {" +
		"\n" +
		header +
		"\n}" +
		"\n#endif" +
		"\n"
	bodyimports := CppImportsFromPackage(pkg, "", body, false)
	output := "" +
		bodyimports +
		"#include \"" + headerfilename + ".hpp\"" +
		"\n" +
		"\nnamespace " + pkgname + " {" +
		"\n" +
		body +
		"\n}" +
		"\n"
	return output, headeroutput, msgblock
}

func CppFromText(text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	return output
}

func CppBodyFromType(typ *vxtype) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppBodyFromType")
	path := typ.pkgname + "/" + typ.name
	doc := "" +
		"type: " + typ.name
	if typ.doc != "" {
		doc += "\n" + typ.doc
	}
	if typ.deprecated != "" {
		doc += "\n" + typ.deprecated
	}
	pkgname := CppNameFromPkgName(typ.pkgname)
	typename := CppFromName(typ.alias)
	classname := "Class_" + typename
	fullclassname := CppNameClassFullFromType(typ)
	fulltypename := CppNameTypeFullFromType(typ)
	fulltname := CppNameTFromType(typ)
	fullename := CppNameEFromType(typ)
	constructor := "" +
		"\n      vx_core::refcount += 1;"
	destructor := "" +
		"\n      vx_core::refcount -= 1;" +
		"\n      if (this->vx_p_msgblock) {" +
		"\n        vx_core::vx_release_one(this->vx_p_msgblock);" +
		"\n      }"
	instancefuncs := ""
	vxdispose := "" +
		"\n    vx_core::vx_Type_listany " + fullclassname + "::vx_dispose() {return vx_core::emptylistany;}"
	createtext, msgs := CppFromValue(typ.createvalue, "", emptyfunc, 0, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isbody := true
		for _, createline := range createlines {
			trimline := StringTrim(createline)
			if trimline == "// :header" {
				isbody = false
			} else if trimline == "// :body" {
				isbody = true
			} else if isbody {
				if trimline == "" {
					instancefuncs += "\n"
				} else {
					instancefuncs += "\n    " + createline
				}
			}
		}
	}
	staticfuncs := ""
	valnew := ""
	valcopy := ""
	switch NameFromType(typ) {
	case "vx/core/any":
		valnew += "" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
	case "vx/core/anytype":
	case "vx/core/const":
	case "vx/core/list":
	case "vx/core/map":
	case "vx/core/struct":
	case "vx/core/func":
		instancefuncs += "" +
			"\n    vx_core::Type_funcdef " + classname + "::vx_funcdef() const {" +
			"\n      return vx_core::e_funcdef();" +
			"\n    }"
	case "vx/core/type":
	case "vx/core/boolean":
		valcopy = "" +
			"\n      vx_core::Type_boolean val = vx_core::vx_any_from_any(vx_core::t_boolean(), copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);"
		valnew = "" +
			"\n      bool booleanval = val->vx_boolean();" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_boolean()) {" +
			"\n          vx_core::Type_boolean valboolean = vx_core::vx_any_from_any(vx_core::t_boolean(), valsub);" +
			"\n          booleanval = booleanval || valboolean->vx_boolean();" +
			"\n        }" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n        output->vx_p_boolean = booleanval;" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      } else if (booleanval) {" +
			"\n        output = vx_core::c_true();" +
			"\n      } else {" +
			"\n        output = vx_core::c_false();" +
			"\n      }"
	case "vx/core/decimal":
		valcopy = "" +
			"\n      vx_core::Type_decimal val = vx_core::vx_any_from_any(vx_core::t_decimal(), copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);"
		valnew = "" +
			"\n      std::string sval = val->vx_string();" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_string()) {" +
			"\n          vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
			"\n          sval = valstring->vx_string();" +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_decimal = sval;" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
	case "vx/core/float":
		valcopy = "" +
			"\n      vx_core::Type_float val = vx_core::vx_any_from_any(vx_core::t_float(), copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);"
		valnew = "" +
			"\n      float floatval = val->vx_float();" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_decimal()) {" +
			"\n          vx_core::Type_decimal valnum = vx_core::vx_any_from_any(vx_core::t_decimal(), valsub);" +
			"\n          floatval += valnum->vx_float();" +
			"\n        } else if (valsubtype == vx_core::t_float()) {" +
			"\n          vx_core::Type_float valnum = vx_core::vx_any_from_any(vx_core::t_float(), valsub);" +
			"\n          floatval += valnum->vx_float();" +
			"\n        } else if (valsubtype == vx_core::t_int()) {" +
			"\n          vx_core::Type_int valnum = vx_core::vx_any_from_any(vx_core::t_int(), valsub);" +
			"\n          floatval += valnum->vx_int();" +
			"\n        } else if (valsubtype == vx_core::t_string()) {" +
			"\n          vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
			"\n          floatval += std::stof(valstring->vx_string());" +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_float = floatval;" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
	case "vx/core/int":
		valcopy = "" +
			"\n      vx_core::Type_int val = vx_core::vx_any_from_any(vx_core::t_int(), copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);"
		valnew = "" +
			"\n      long intval = val->vx_int();" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_int()) {" +
			"\n          vx_core::Type_int valnum = vx_core::vx_any_from_any(vx_core::t_int(), valsub);" +
			"\n          intval += valnum->vx_int();" +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_int = intval;" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		valcopy = "" +
			"\n      vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);"
		valnew = "" +
			"\n      std::string sb = val->vx_string();" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_string()) {" +
			"\n          vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
			"\n          sb += valstring->vx_string();" +
			"\n        } else if (valsubtype == vx_core::t_int()) {" +
			"\n          vx_core::Type_int valint = vx_core::vx_any_from_any(vx_core::t_int(), valsub);" +
			"\n          sb += vx_core::vx_string_from_int(valint->vx_int());" +
			"\n        } else if (valsubtype == vx_core::t_float()) {" +
			"\n          vx_core::Type_float valfloat = vx_core::vx_any_from_any(vx_core::t_float(), valsub);" +
			"\n          sb += vx_core::vx_string_from_int(valfloat->vx_float());" +
			"\n        } else if (valsubtype == vx_core::t_decimal()) {" +
			"\n          vx_core::Type_decimal valdecimal = vx_core::vx_any_from_any(vx_core::t_decimal(), valsub);" +
			"\n          sb += valdecimal->vx_string();" +
			"\n        } else {" +
			"\n          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(new " + typ.name + ") - Invalid Type: \" + vx_core::vx_string_from_any(valsub));" +
			"\n          msgblock = vx_core::vx_copy(msgblock, {msg});" +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_string = sb;" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
	}
	switch typ.extends {
	case ":list":
		destructor += "" +
			"\n      for (vx_core::Type_any any : this->vx_p_list) {" +
			"\n        vx_core::vx_release_one(any);" +
			"\n      }"
		allowcode := ""
		allowname := "any"
		allowclass := "vx_core::Type_any"
		allowttype := "vx_core::t_any()"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			if allowtype.isfunc {
				allowfunc := allowtype.vxfunc
				allowtype = allowfunc.vxtype
			}
			allowclass = CppNameTypeFullFromType(allowtype)
			allowempty := CppNameEFromType(allowtype)
			allowttype = CppNameTFromType(allowtype)
			allowname = CppNameFromType(allowtype)
			if allowname != "any" {
				allowcode = "" +
					"\n    " + allowclass + " " + classname + "::vx_get_" + allowname + "(vx_core::Type_int index) const {" +
					"\n      " + allowclass + " output = " + allowempty + ";" +
					"\n      long iindex = index->vx_int();" +
					"\n      std::vector<" + allowclass + "> listval = this->vx_p_list;" +
					"\n      if ((unsigned long long)iindex < listval.size()) {" +
					"\n        output = listval[iindex];" +
					"\n      }" +
					"\n      vx_core::vx_release_except(index, output);" +
					"\n      return output;" +
					"\n    }" +
					"\n"
			}
		}
		valsubif := ""
		if allowname == "any" {
			valsubif = "" +
				"\n        list.push_back(valsub);"
			allowname = ""
			instancefuncs += "" +
				"\n    // vx_list()" +
				"\n    vx_core::vx_Type_listany " + classname + "::vx_list() const {" +
				"\n      return this->vx_p_list;" +
				"\n    }" +
				"\n"
			allowcode += "" +
				"\n    // vx_get_any(index)" +
				"\n    vx_core::Type_any " + classname + "::vx_get_any(vx_core::Type_int index) const {" +
				"\n      vx_core::Type_any output = vx_core::e_any();" +
				"\n      long iindex = index->vx_int();" +
				"\n      std::vector<vx_core::Type_any> listval = this->vx_p_list;" +
				"\n      if ((unsigned long long)iindex < listval.size()) {" +
				"\n        output = listval[iindex];" +
				"\n      }" +
				"\n      vx_core::vx_release_except(index, output);" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		} else {
			valsubif = "" +
				"\n        vx_core::Type_any valtype = valsub->vx_type();" +
				"\n        if (valtype == " + allowttype + ") {" +
				"\n          " + allowclass + " castval = vx_core::vx_any_from_any(" + allowttype + ", valsub);" +
				"\n          list.push_back(castval);" +
				"\n        } else {" +
				"\n          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(" + typename + ") Invalid Value: \" + vx_core::vx_string_from_any(valsub) + \"\");" +
				"\n          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});" +
				"\n        }"
			instancefuncs += "" +
				"\n    // vx_list()" +
				"\n    vx_core::vx_Type_listany " + classname + "::vx_list() const {" +
				"\n      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);" +
				"\n    }" +
				"\n"
			allowcode += "" +
				"\n    std::vector<" + allowclass + "> " + classname + "::vx_list" + allowname + "() const {return vx_p_list;}" +
				"\n" +
				"\n    vx_core::Type_any " + fullclassname + "::vx_get_any(vx_core::Type_int index) const {" +
				"\n      return this->vx_get_" + allowname + "(index);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			allowcode +
			"\n    // vx_new_from_list(listval)" +
			"\n    vx_core::Type_any " + classname + "::vx_new_from_list(vx_core::vx_Type_listany listval) const {" +
			"\n      " + fulltypename + " output = " + fullename + ";" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();" +
			"\n      std::vector<" + allowclass + "> list;" +
			"\n      for (auto const& valsub : listval) {" +
			valsubif +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_list = list;" +
			"\n      for (vx_core::Type_any valadd : list) {" +
			"\n        vx_core::vx_reserve(valadd);" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }" +
			//			"\n      for (vx_core::Type_any val : listval) {" +
			"\n      vx_core::vx_release_except(listval, output);" +
			//			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
		valcopy = "" +
			"\n      " + fulltypename + " val = vx_core::vx_any_from_any(" + fulltname + ", copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);" +
			"\n      std::vector<" + allowclass + "> listval = val->vx_list" + allowname + "();"
		switch typ.name {
		case "msgblocklist":
			valnew = "" +
				"\n      for (vx_core::Type_any valsub : vals) {" +
				"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
				"\n        if (valsubtype == vx_core::t_msg()) {" +
				"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});"
		case "msglist":
			valnew = "" +
				"\n      for (vx_core::Type_any valsub : vals) {" +
				"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
				"\n        if (valsubtype == vx_core::t_msgblock()) {" +
				"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});"
		default:
			valnew = "" +
				"\n      for (vx_core::Type_any valsub : vals) {" +
				"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
				"\n        if (valsubtype == vx_core::t_msgblock()) {" +
				"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});" +
				"\n        } else if (valsubtype == vx_core::t_msg()) {" +
				"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});"
			//"\n        } else if (valsubtype == " + allowttype + ") {" +
			//"\n          " + allowclass + " valadd = vx_core::vx_any_from_any(" + allowttype + ", valsub);" +
			//"\n          listval.push_back(valadd);"
		}
		valnewelse := "" +
			"\n          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(new " + typ.name + ") - Invalid Type: \" + vx_core::vx_string_from_any(valsub));" +
			"\n          msgblock = vx_core::vx_copy(msgblock, {msg});"
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := CppNameTFromType(allowedtype)
			castval := "vx_core::vx_any_from_any(" + allowedtypename + ", valsub)"
			switch NameFromType(allowedtype) {
			case "vx/core/any":
				valnewelse = "" +
					"\n          listval.push_back(valsub);"
			}
			/*
				//if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "vx_core::t_nativeboolean"
					castval = "vx_core::t_boolean->vx_new(valsub)"
				case "vx/core/int":
					allowedtypename = "vx_core::t_nativeint"
					castval = "vx_core::t_int->vx_new(valsub)"
				case "vx/core/float":
					allowedtypename = "vx_core::t_nativefloat"
					castval = "vx_core::t_float->vx_new(valsub)"
				case "vx/core/string":
					allowedtypename = "vx_core::t_nativestring"
					castval = "vx_core::t_string->vx_new(valsub)"
				}
				//}
			*/
			switch NameFromType(allowedtype) {
			case "":
			case "vx/core/any":
			default:
				valnew += "" +
					"\n        } else if (valsubtype == " + allowedtypename + ") {" +
					"\n          listval.push_back(" + castval + ");" +
					"\n        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, " + allowedtypename + ")) {" +
					"\n          listval.push_back(" + castval + ");"
			}
		}
		switch NameFromType(typ) {
		case "vx/core/list":
		default:
			valnew += "" +
				"\n        } else if (valsubtype == " + fulltname + ") {" +
				"\n          " + fulltypename + " multi = vx_core::vx_any_from_any(" + fulltname + ", valsub);" +
				"\n          listval = vx_core::vx_listaddall(listval, multi->vx_list" + allowname + "());"
		}
		valnew += "" +
			"\n        } else {" +
			valnewelse +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_list = listval;" +
			"\n      for (vx_core::Type_any valadd : listval) {" +
			"\n        vx_core::vx_reserve(valadd);" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":map":
		destructor += "" +
			"\n      for (auto const& [key, val] : this->vx_p_map) {" +
			"\n        vx_core::vx_release_one(val);" +
			"\n      }"
		allowcode := ""
		allowname := "any"
		allowclass := "vx_core::Type_any"
		allowttype := "vx_core::t_any"
		allowtypes := ListAllowTypeFromType(typ)
		allowempty := "vx_core::e_any"
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = CppNameTypeFullFromType(allowtype)
			allowttype = CppNameTFromType(allowtype)
			allowempty = CppNameEFromType(allowtype)
			allowname = CppNameFromType(allowtype)
			allowcode = "" +
				"\n    // vx_get_" + allowname + "(key)" +
				"\n    " + allowclass + " " + classname + "::vx_get_" + allowname + "(vx_core::Type_string key) const {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      const " + fullclassname + "* map = this;" +
				"\n      std::string skey = key->vx_string();" +
				"\n      std::map<std::string, " + allowclass + "> mapval = map->vx_p_map;" +
				"\n      output = vx_core::vx_any_from_map(mapval, skey, " + allowempty + ");" +
				"\n      vx_core::vx_release_except(key, output);" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		}
		vxmap := ""
		if allowname == "any" {
			//			allowname = ""
			vxmap = "this->vx_p_map;"
		} else {
			vxmap = "vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);"
			allowcode += "" +
				"\n    // vx_get_any(key)" +
				"\n    vx_core::Type_any " + classname + "::vx_get_any(vx_core::Type_string key) const {" +
				"\n      return this->vx_get_" + allowname + "(key);" +
				"\n    }" +
				"\n" +
				"\n    // vx_map" + allowname + "()" +
				"\n    std::map<std::string, " + allowclass + "> " + classname + "::vx_map" + allowname + "() const {return this->vx_p_map;}" +
				"\n"
		}
		allowval := ""
		if allowname == "any" {
			allowval += "" +
				"\n        map[key] = val;"
		} else {
			allowval += "" +
				"\n        vx_core::Type_any valtype = val->vx_type();" +
				"\n        if (valtype == " + allowttype + ") {" +
				"\n          " + allowclass + " castval = vx_core::vx_any_from_any(" + allowttype + ", val);" +
				"\n          map[key] = castval;" +
				"\n        } else {" +
				"\n          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(" + typename + ") Invalid Value: \" + vx_core::vx_string_from_any(val) + \"\");" +
				"\n          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});" +
				"\n        }"
		}
		instancefuncs += "" +
			"\n    // vx_map()" +
			"\n    vx_core::vx_Type_mapany " + classname + "::vx_map() const {" +
			"\n      vx_core::vx_Type_mapany output = " + vxmap +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			allowcode +
			"\n    // vx_new_from_map(mapval)" +
			"\n    vx_core::Type_any " + classname + "::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {" +
			"\n      " + fulltypename + " output = " + fullename + ";" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();" +
			"\n      std::map<std::string, " + allowclass + "> map;" +
			"\n      for (auto const& iter : mapval) {" +
			"\n        std::string key = iter.first;" +
			"\n        vx_core::Type_any val = iter.second;" +
			allowval +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_map = map;" +
			"\n      for (auto const& [key, val] : map) {" +
			"\n        vx_core::vx_reserve(val);" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }" +
			"\n      for (auto const& [key, val] : mapval) {" +
			"\n        vx_core::vx_release_except(val, output);" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
		valcopy = "" +
			"\n      " + fulltypename + " valmap = vx_core::vx_any_from_any(" + fulltname + ", copyval);" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);"
		allowsub := ""
		if allowname == "any" {
			allowsub = "" +
				"\n          " + allowclass + " valany = valsub;"
		} else {
			allowsub = "" +
				"\n          " + allowclass + " valany = NULL;" +
				"\n          if (valsubtype == " + allowttype + ") {" +
				"\n            valany = vx_core::vx_any_from_any(" + allowttype + ", valsub);"
			for _, allowedtype := range typ.allowtypes {
				allowedtypename := CppNameTFromType(allowedtype)
				castval := "vx_core::vx_any_from_any(" + allowttype + ", valsub)"
				if allowedtypename != "" {
					allowsub += "" +
						"\n          } else if (valsubtype == " + allowedtypename + ") {" +
						"\n            valany = " + castval + ";"
				}
			}
			allowsub += "" +
				"\n          } else {" +
				"\n            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"Invalid Key/Value: \" + key + \" \"  + vx_core::vx_string_from_any(valsub) + \"\");" +
				"\n            msgblock = vx_core::vx_copy(msgblock, {msg});" +
				"\n          }"
		}
		valnew = "" +
			"\n      std::vector<std::string> keys;" +
			"\n      std::map<std::string, " + allowclass + "> mapval;" +
			"\n      std::string key = \"\";" +
			"\n      for (vx_core::Type_any valsub : vals) {" +
			"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
			"\n        if (valsubtype == vx_core::t_msgblock()) {" +
			"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});" +
			"\n        } else if (valsubtype == vx_core::t_msg()) {" +
			"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});" +
			"\n        } else if (key == \"\") {" +
			"\n          if (valsubtype == vx_core::t_string()) {" +
			"\n            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
			"\n            key = valstring->vx_string();" +
			"\n          } else {" +
			"\n            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"Key Expected: \" + vx_core::vx_string_from_any(valsub) + \"\");" +
			"\n            msgblock = vx_core::vx_copy(msgblock, {msg});" +
			"\n          }" +
			"\n        } else {" +
			allowsub +
			"\n          if (valany) {" +
			"\n            mapval[key] = valany;" +
			"\n            keys.push_back(key);" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
			"\n      output->vx_p_keys = keys;" +
			"\n      output->vx_p_map = mapval;" +
			"\n      for (auto const& [key, val] : mapval) {" +
			"\n        vx_core::vx_reserve(val);" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock()) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n        vx_core::vx_reserve(msgblock);" +
			"\n      }"
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":struct":
		vx_any := ""
		vx_map := ""
		valcopy = ""
		switch NameFromType(typ) {
		case "vx/core/msg":
			valcopy += "" +
				"\n      vx_core::Type_msg val = vx_core::vx_any_from_any(" + fulltname + ", copyval);"
		case "vx/core/msgblock":
			valcopy += "" +
				"\n      vx_core::Type_msgblock val = vx_core::e_msgblock();" +
				"\n      if (copyval) {" +
				"\n        val = vx_core::vx_any_from_any(vx_core::t_msgblock(), copyval);" +
				"\n      }"
		default:
			valcopy += "" +
				"\n      " + fulltypename + " val = vx_core::vx_any_from_any(" + fulltname + ", copyval);" +
				"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);"
		}
		props := ListPropertyTraitFromType(typ)
		var destroyfields []string
		switch len(props) {
		case 0:
		default:
			validkeys := ""
			valnewswitch := ""
			argassign := ""
			for _, arg := range props {
				validkeys += "" +
					"\n          } else if (testkey == \":" + arg.name + "\") {" +
					"\n            key = testkey;"
				argname := CppFromName(arg.name)
				destroyfields = append(destroyfields, "this->vx_p_"+argname)
				argassign += "" +
					"\n      if (output->vx_p_" + argname + " != vx_p_" + argname + ") {" +
					"\n        if (output->vx_p_" + argname + ") {" +
					"\n          vx_core::vx_release_one(output->vx_p_" + argname + ");" +
					"\n        }" +
					"\n        output->vx_p_" + argname + " = vx_p_" + argname + ";" +
					"\n        vx_core::vx_reserve(vx_p_" + argname + ");" +
					"\n      }"
				argclassname := CppNameTypeFromType(arg.vxtype)
				valcopy += "\n      " + argclassname + " vx_p_" + argname + " = val->" + argname + "();"
				vx_map += "\n      output[\":" + arg.name + "\"] = this->" + argname + "();"
				vx_any += "" +
					"\n      } else if (skey == \":" + arg.name + "\") {" +
					"\n        output = this->" + argname + "();"
				argttype := CppNameTFromType(arg.vxtype)
				argetype := CppNameEFromType(arg.vxtype)
				valnewswitch += "" +
					"\n          } else if (key == \":" + arg.name + "\") {"
				switch NameFromType(typ) {
				case "vx/core/msg", "vx/core/msgblock":
					valnewswitch += "" +
						"\n            if (valsubtype == " + argttype + ") {" +
						"\n              vx_p_" + argname + " = vx_core::vx_any_from_any(" + argttype + ", valsub);" +
						"\n            }"
				default:
					switch NameFromType(arg.vxtype) {
					case "vx/core/any":
						valnewswitch += "" +
							"\n            vx_p_" + argname + " = valsub;"
					default:
						valnewswitch += "" +
							"\n            if (valsubtype == " + argttype + ") {" +
							"\n              vx_p_" + argname + " = vx_core::vx_any_from_any(" + argttype + ", valsub);" +
							"\n            } else {" +
							"\n              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(new " + typ.name + " :" + arg.name + " \" + vx_core::vx_string_from_any(valsub) + \") - Invalid Value\");" +
							"\n              msgblock = vx_core::vx_copy(msgblock, {msg});" +
							"\n            }"
					}
				}
				instancefuncs += "" +
					"\n    // " + argname + "()" +
					"\n    " + argclassname + " " + classname + "::" + argname + "() const {" +
					"\n      " + argclassname + " output = this->vx_p_" + argname + ";" +
					"\n      if (!output) {" +
					"\n        output = " + argetype + ";" +
					"\n      }" +
					"\n      return output;" +
					"\n    }" +
					"\n"
			}
			defaultkey := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := CppFromName(lastarg.name)
				//argclassname := CppNameTypeFromType(lastarg.vxtype)
				argttype := CppNameTFromType(lastarg.vxtype)
				defaultkey += "" +
					"\n          } else if (valsubtype == " + argttype + ") { // default property" +
					"\n            vx_p_" + lastargname + " = vx_core::vx_any_from_any(" + argttype + ", valsub);" +
					"\n          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, " + argttype + ")) { // default property" +
					"\n            vx_p_" + lastargname + " = vx_core::vx_any_from_any(" + argttype + ", valsub);"
				/*
					switch NameFromType(lastarg.vxtype) {
					case "vx/core/boolean":
						defaultkey += "" +
							"\n          } else if (valsubtype == vx_core::t_nativeboolean) { // default property" +
							"\n            output->vx_p_" + lastargname + " = vx_core::t_boolean->vx_new(valsub);"
					case "vx/core/int":
						defaultkey += "" +
							"\n          } else if (valsubtype == vx_core::t_nativeint) { // default property" +
							"\n            output->vx_p_" + lastargname + " = vx_core::t_int->vx_new(valsub);"
					case "vx/core/float":
						defaultkey += "" +
							"\n          } else if (valsubtype == vx_core::t_nativefloat) { // default property" +
							"\n            output->vx_p_" + lastargname + " = vx_core::t_float->vx_new(valsub);"
					case "vx/core/string":
						defaultkey += "" +
							"\n          } else if (valsubtype == vx_core::t_nativestring) { // default property" +
							"\n            output->vx_p_" + lastargname + " = vx_core::t_string->vx_new(valsub);"
					}
				*/
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						//subargclassname := CppNameTypeFromType(allowtype)
						subargttype := CppNameTFromType(allowtype)
						defaultkey += "" +
							"\n          } else if (valsubtype == " + subargttype + ") { // default property" +
							"\n            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});" +
							"\n          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, " + subargttype + ")) { // default property" +
							"\n            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});"
						//							"\n            " + subargclassname + " valdefault = vx_core::vx_any_from_any(" + subargttype + ", valsub);" +
						//							"\n            " + argclassname + " vallist = output->vx_p_" + lastargname + ";" +
						//							"\n            if (!vallist) {" +
						//							"\n              vallist = vx_core::vx_new(" + CppNameTFromType(lastarg.vxtype) + ", {valdefault});" +
						//							"\n            } else {" +
						//							"\n              vallist = vx_core::vx_copy(" + CppNameTFromType(lastarg.vxtype) + ", {valdefault});" +
						//							"\n            }" +
						//							"\n            vx_p_" + lastargname + " = vallist;"
					}
				}
			}
			switch NameFromType(typ) {
			case "vx/core/msg":
				valnew = "" +
					"\n      std::string key = \"\";" +
					"\n      for (vx_core::Type_any valsub : vals) {" +
					"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
					"\n        if (key == \"\") {" +
					"\n          if (valsubtype == vx_core::t_string()) {" +
					"\n            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
					"\n            key = valstr->vx_string();" +
					"\n          }" +
					"\n        } else {" +
					"\n          if (false) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";"
			case "vx/core/msgblock":
				valnew = "" +
					"\n      std::string key = \"\";" +
					"\n      for (vx_core::Type_any valsub : vals) {" +
					"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
					"\n        if (valsubtype == vx_core::t_msgblock()) {" +
					"\n          vx_p_msgblocks = vx_core::vx_copy(vx_p_msgblocks, {valsub});" +
					"\n        } else if (valsubtype == vx_core::t_msg()) {" +
					"\n          vx_p_msgs = vx_core::vx_copy(vx_p_msgs, {valsub});" +
					"\n        } else if (valsubtype == vx_core::t_msgblocklist()) {" +
					"\n          vx_p_msgblocks = vx_core::vx_copy(vx_p_msgblocks, {valsub});" +
					"\n        } else if (valsubtype == vx_core::t_msglist()) {" +
					"\n          vx_p_msgs = vx_core::vx_copy(vx_p_msgs, {valsub});" +
					"\n        } else if (key == \"\") {" +
					"\n          if (valsubtype == vx_core::t_string()) {" +
					"\n            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
					"\n            key = valstr->vx_string();" +
					"\n          }" +
					"\n        } else {" +
					"\n          if (false) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
					"\n      if (vx_p_msgs != vx_core::e_msglist()) {" +
					"\n        output->vx_p_msgs = vx_p_msgs;" +
					"\n        vx_core::vx_reserve(vx_p_msgs);" +
					"\n      }" +
					"\n      if (vx_p_msgblocks != vx_core::e_msgblocklist()) {" +
					"\n        output->vx_p_msgblocks = vx_p_msgblocks;" +
					"\n        vx_core::vx_reserve(vx_p_msgblocks);" +
					"\n      }"
			default:
				valnew = "" +
					"\n      std::string key = \"\";" +
					"\n      for (vx_core::Type_any valsub : vals) {" +
					"\n        vx_core::Type_any valsubtype = valsub->vx_type();" +
					"\n        if (valsubtype == vx_core::t_msgblock()) {" +
					"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});" +
					"\n        } else if (valsubtype == vx_core::t_msg()) {" +
					"\n          msgblock = vx_core::vx_copy(msgblock, {valsub});" +
					"\n        } else if (key == \"\") {" +
					"\n          std::string testkey = \"\";" +
					"\n          if (valsubtype == vx_core::t_string()) {" +
					"\n            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);" +
					"\n            testkey = valstr->vx_string();" +
					"\n          }" +
					"\n          if (false) {" +
					validkeys +
					defaultkey +
					"\n          } else {" +
					"\n            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(new " + typ.name + ") - Invalid Key Type: \" + vx_core::vx_string_from_any(valsub));" +
					"\n            msgblock = vx_core::vx_copy(msgblock, {msg});" +
					"\n          }" +
					"\n        } else {" +
					"\n          if (false) {" +
					valnewswitch +
					"\n          } else {" +
					"\n            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext(\"(new " + typ.name + ") - Invalid Key: \" + key);" +
					"\n            msgblock = vx_core::vx_copy(msgblock, {msg});" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      output = " + CppPointerNewFromClassName(fullclassname) + ";" +
					argassign
			}
		}
		switch NameFromType(typ) {
		case "vx/core/msg":
		case "vx/core/msgblock":
		default:
			valnew += "" +
				"\n      if (msgblock != vx_core::e_msgblock()) {" +
				"\n        output->vx_p_msgblock = msgblock;" +
				"\n        vx_core::vx_reserve(msgblock);" +
				"\n      }"
		}
		instancefuncs += "" +
			"\n    // vx_get_any(key)" +
			"\n    vx_core::Type_any " + classname + "::vx_get_any(vx_core::Type_string key) const {" +
			"\n      vx_core::Type_any output = vx_core::e_any();" +
			"\n      std::string skey = key->vx_string();" +
			"\n      if (false) {" +
			vx_any +
			"\n      }" +
			"\n      vx_core::vx_release_except(key, output);" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    // vx_map()" +
			"\n    vx_core::vx_Type_mapany " + classname + "::vx_map() const {" +
			"\n      vx_core::vx_Type_mapany output;" +
			vx_map +
			"\n      return output;" +
			"\n    }" +
			"\n"
		destructor += "" +
			"\n      vx_core::vx_release_one({" +
			"\n        " + StringFromListStringJoin(destroyfields, ",\n        ") +
			"\n      });"
	}
	vxmsgblock := ""
	switch NameFromType(typ) {
	case "vx/core/msg":
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock vx_core::Class_msg::vx_msgblock() const {return vx_core::e_msgblock();}"
	case "vx/core/msgblock":
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock vx_core::Class_msgblock::vx_msgblock() const {return vx_core::e_msgblock();}"
	default:
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock " + classname + "::vx_msgblock() const {return this->vx_p_msgblock;}"
	}
	typedef := "" +
		"\n    vx_core::Type_typedef " + classname + "::vx_typedef() const {" +
		"\n      vx_core::Type_typedef output = " + CppTypeDefFromType(typ, "      ") + ";" +
		"\n      return output;" +
		"\n    }" +
		"\n"
	specialempty := ""
	switch NameFromType(typ) {
	case "vx/core/boolean":
		specialempty = "" +
			"\n      output = vx_core::c_false();"
	default:
		specialempty = "" +
			"\n      output = new " + classname + "();" +
			"\n      vx_core::vx_reserve_empty(output);"
	}
	footer := "" +
		"\n  " + fulltypename + " e_" + typename + "() {" +
		"\n    " + fulltypename + " output = " + pkgname + "::vx_package->e_" + typename + ";" +
		"\n    if (!output) {" +
		specialempty +
		"\n      " + pkgname + "::vx_package->e_" + typename + " = output;" +
		"\n    }" +
		"\n    return output;" +
		"\n  }" +
		"\n  " + fulltypename + " t_" + typename + "() {" +
		"\n    " + fulltypename + " output = " + pkgname + "::vx_package->t_" + typename + ";" +
		"\n    if (!output) {" +
		"\n      output = new " + classname + "();" +
		"\n      vx_core::vx_reserve_type(output);" +
		"\n      " + pkgname + "::vx_package->t_" + typename + " = output;" +
		"\n    }" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	output := "" +
		//"\n  /**" +
		//"\n   * " + StringFromStringIndent(doc, "   * ") +
		//"\n   * (type " + typ.name + ")" +
		//"\n   */" +
		"\n  // (type " + typ.name + ")" +
		"\n  // class " + classname + " {" +
		"\n    Abstract_" + typename + "::~Abstract_" + typename + "() {}" +
		"\n" +
		"\n    " + classname + "::" + classname + "() : Abstract_" + typename + "::Abstract_" + typename + "() {" +
		constructor +
		"\n    }" +
		"\n" +
		"\n    " + classname + "::~" + classname + "() {" +
		destructor +
		"\n    }" +
		"\n" +
		instancefuncs +
		"\n    vx_core::Type_any " + classname + "::vx_new(vx_core::vx_Type_listany vals) const {" +
		"\n      return this->vx_copy(" + fullename + ", vals);" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_any " + classname + "::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {" +
		"\n      " + pkgname + "::Type_" + typename + " output = " + fullename + ";" +
		valcopy +
		valnew +
		"\n      vx_core::vx_release_except(copyval, output);" +
		"\n      vx_core::vx_release_except(vals, output);" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		vxmsgblock +
		vxdispose +
		"\n    vx_core::Type_any " + classname + "::vx_empty() const {return " + fullename + ";}" +
		"\n    vx_core::Type_any " + classname + "::vx_type() const {return " + fulltname + ";}" +
		"\n" +
		typedef +
		staticfuncs +
		"\n  //}" +
		"\n"
	return output, footer, msgblock
}

func CppFromValue(value vxvalue, pkgname string, parentfn *vxfunc, indent int, encode bool, test bool, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFromValue")
	var output = ""
	sindent := StringRepeat("  ", indent)
	valstr := ""
	switch value.code {
	case ":arg":
		valarg := ArgFromValue(value)
		valstr = CppFromName(valarg.name)
		output += valstr
	case ":const":
		switch value.name {
		case "false", "true":
			valstr = "vx_core::vx_new_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = CppFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = CppNameFromPkgName(valconst.pkgname) + "::c_" + CppFromName(valconst.alias) + "()"
			}
		}
		output = valstr
	case ":func":
		fnc := FuncFromValue(value)
		subpath := path + "/" + fnc.name
		funcname := NameFromFunc(fnc)
		switch fnc.name {
		case "native":
			// (native :cpp)
			isNative := false
			var argtexts []string
			multiline := false
			argtext := ""
			nativeindent := "undefined"
			for _, arg := range fnc.listarg {
				var argvalue = arg.value
				valuetext := ""
				if argvalue.code == "string" {
					valuetext = StringValueFromValue(argvalue)
				}
				if valuetext == ":cpp" {
					isNative = true
				} else if BooleanFromStringStarts(valuetext, ":") {
					isNative = false
				} else if isNative {
					if argvalue.name == "newline" {
						argtext = "\n"
					} else {
						clstext, msgs := CppFromValue(argvalue, pkgname, parentfn, 0, false, test, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						argtext = clstext
						if nativeindent == "undefined" {
							nativeindent = "\n" + StringRepeat(" ", argvalue.textblock.charnum)
						} else if nativeindent != "" {
							argtext = StringFromStringFindReplace(argtext, nativeindent, "\n")
						}
					}
					if !multiline {
						if BooleanFromStringContains(argtext, "\n") {
							multiline = true
						} else if argvalue.name != "" {
							multiline = true
						}
					}
					argtext = StringRemoveQuotes(argtext)
					argtexts = append(argtexts, argtext)
				}
			}
			if len(argtexts) > 0 {
				if multiline {
					output += StringFromStringIndent(StringFromListStringJoin(argtexts, ""), sindent)
				} else {
					output += StringFromListStringJoin(argtexts, "")
				}
			}
		default:
			var argtexts []string
			funcargs := fnc.listarg
			isskip := false
			multiline := false
			multiflag := false
			switch funcname {
			case "vx/core/any<-struct":
				targetvalue := funcargs[0].value
				switch targetvalue.code {
				case ":arg":
					propvalue := funcargs[1].value
					switch propvalue.code {
					case "string":
						propname := StringValueFromValue(propvalue)
						if BooleanFromStringStarts(propname, ":") {
							propname = propname[1:]
						}
						structvalue := funcargs[0].value
						work, msgs := CppFromValue(structvalue, pkgname, fnc, 0, true, test, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						work = work + "->" + CppFromName(propname) + "()"
						argtexts = append(argtexts, work)
						isskip = true
					}
				default:
					output += CppNameFromPkgName(fnc.pkgname) + "::f_" + CppNameFromFunc(fnc) + "("
				}
			case "vx/core/fn":
			case "vx/core/let":
				if fnc.async {
					output += CppNameFromPkgName(fnc.pkgname) + "::f_let_async("
				} else {
					output += CppNameFromPkgName(fnc.pkgname) + "::f_" + CppNameFromFunc(fnc) + "("
				}
			default:
				output += CppNameFromPkgName(fnc.pkgname) + "::f_" + CppNameFromFunc(fnc) + "("
			}
			if !isskip {
				if fnc.isgeneric {
					switch funcname {
					case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
					default:
						if fnc.generictype != nil {
							genericarg := CppNameTFromTypeGeneric(fnc.vxtype)
							argtexts = append(argtexts, genericarg)
						}
					}
				}
				subindent := indent + 1
				for fncidx, funcarg := range funcargs {
					argsubpath := subpath + "/:arg/" + funcarg.name
					if fncidx == 0 && funcname == "vx/core/fn" {
					} else {
						var argvalue = funcarg.value
						argtext := ""
						if argvalue.code == ":func" && argvalue.name == "fn" {
							argfunc := FuncFromValue(argvalue)
							capturetext := CppCaptureFromFunc(argfunc, argsubpath)
							var lambdaargs []string
							var lambdavars []string
							arglist := ListLocalArgFromFunc(argfunc)
							for _, lambdaarg := range arglist {
								lambdaargs = append(lambdaargs, "vx_core::Type_any "+lambdaarg.name+"_any")
								argvaltype := ""
								argtype := lambdaarg.vxtype
								argvaltype = CppNameTypeFullFromType(argtype)
								argvaltname := CppNameTFromType(argtype)
								lambdavar := argvaltype + " " + lambdaarg.name + " = vx_core::vx_any_from_any(" + argvaltname + ", " + lambdaarg.name + "_any);"
								lambdavars = append(lambdavars, lambdavar)
							}
							lambdatext := StringFromListStringJoin(lambdaargs, ", ")
							lambdavartext := ""
							if len(lambdavars) > 0 {
								lambdavartext = "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
							}
							if argfunc.async {
								work, msgs := CppFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-key-value-async":
									argtext = "" +
										"vx_core::t_any_from_key_value_async()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-async":
									argtext = "" +
										"vx_core::t_any_from_reduce_async()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next-async":
									argtext = "" +
										"vx_core::t_any_from_reduce_next_async()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"vx_core::t_any_from_any_async()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"vx_core::t_any_from_func_async()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								work, msgs := CppFromValue(argvalue, pkgname, fnc, 1, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "" +
									"\n  vx_core::Type_any output_1 = " + work + ";" +
									"\n  return output_1;"
								switch funcarg.vxtype.name {
								case "any<-key-value":
									argtext = "" +
										"vx_core::t_any_from_key_value()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce":
									argtext = "" +
										"vx_core::t_any_from_reduce()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next":
									argtext = "" +
										"vx_core::t_any_from_reduce_next()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"vx_core::t_any_from_any()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"vx_core::t_any_from_func()->vx_fn_new({" + capturetext + "}, [" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							}
						} else if funcname == "vx/core/let" {
							capturetext := CppCaptureFromFunc(fnc, argsubpath)
							switch fncidx {
							case 0:
								argtext = ""
							case 1:
								var argasync = false
								arglist := ListLocalArgFromFunc(fnc)
								for _, lambdaarg := range arglist {
									if lambdaarg.async {
										argasync = true
									}
								}
								lambdatext := ""
								aftertext := ""
								if argasync {
									argindent := 1
									var lambdaargrelease []string
									for lambdaidx, lambdaarg := range arglist {
										lambdaargpath := argsubpath + ":lambdaarg/" + lambdaarg.name
										arglineindent := "\n" + StringRepeat("  ", argindent)
										lambdaargname := CppFromName(lambdaarg.alias)
										lambdatypename := CppNameTypeFromType(lambdaarg.vxtype)
										if lambdaarg.async {
											valuesubpath := lambdaargpath + "/:value"
											var localargs []string
											for i := lambdaidx; i < len(arglist); i++ {
												localarg := arglist[i]
												if localarg.async && i != lambdaidx {
													break
												} else {
													localargname := CppFromName(localarg.alias)
													localargs = append(localargs, localargname)
												}
											}
											lambdarelease := ""
											switch len(lambdaargrelease) {
											case 0:
											case 1:
												lambdarelease = arglineindent + "vx_core::vx_release_one(" + StringFromListStringJoin(lambdaargrelease, "") + ");"
											default:
												lambdarelease = arglineindent + "vx_core::vx_release_one({" + StringFromListStringJoin(lambdaargrelease, ", ") + "});"
											}
											valuecapturetext := CppCaptureFromValueListInner(funcarg.value, localargs, valuesubpath)
											lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											outputname := "output_" + StringFromInt(argindent)
											lambdatext += "" +
												arglineindent + "vx_core::vx_Type_async future_" + lambdaargname + " = " + lambdavaluetext + ";" +
												//												arglineindent + "std::function<vx_core::Type_any(" + CppNameTypeFromType(lambdaarg.vxtype) + ")> fn_any_any_" + CppFromName(lambdaarg.name) + " = [" + valuecapturetext + "](" + CppNameTypeFromType(lambdaarg.vxtype) + " " + CppFromName(lambdaarg.name) + ") {"
												arglineindent + "vx_core::vx_Type_fn_any_from_any fn_any_any_" + lambdaargname + " = [" + valuecapturetext + "](vx_core::Type_any any_" + lambdaargname + ") {" +
												arglineindent + "  " + lambdatypename + " " + lambdaargname + " = vx_core::vx_any_from_any(" + CppNameTFromType(lambdaarg.vxtype) + ", any_" + lambdaargname + ");" +
												arglineindent + "  vx_core::vx_ref_plus(" + lambdaargname + ");"
											aftertext += "" +
												arglineindent + "};" +
												arglineindent + "vx_core::vx_Type_async " + outputname + " = vx_core::vx_async_from_async_fn(future_" + lambdaargname + ", " + CppNameTFromType(lambdaarg.vxtype) + ", {" + valuecapturetext + "}, fn_any_any_" + lambdaargname + ");" +
												lambdarelease +
												arglineindent + "return " + outputname + ";"
											lambdaargrelease = []string{lambdaargname}
											argindent += 1
										} else {
											lambdaargrelease = append(lambdaargrelease, lambdaargname)
											lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + lambdatypename + " " + lambdaargname + " = " + lambdavaluetext + ";" +
												arglineindent + "vx_core::vx_ref_plus(" + lambdaargname + ");"
										}
									}
									work, msgs := CppFromValue(argvalue, pkgname, fnc, argindent, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									lambdarelease := ""
									switch len(lambdaargrelease) {
									case 0:
									case 1:
										lambdarelease = "\n    vx_core::vx_release_one_except(" + StringFromListStringJoin(lambdaargrelease, ", ") + ", output_" + StringFromInt(argindent) + ");"
									default:
										lambdarelease = "\n    vx_core::vx_release_one_except({" + StringFromListStringJoin(lambdaargrelease, ", ") + "}, output_" + StringFromInt(argindent) + ");"
									}
									argtext = "" +
										"vx_core::t_any_from_func_async()->vx_fn_new({" + capturetext + "}, [" + capturetext + "]() {" +
										lambdatext +
										"\n    vx_core::Type_any output_" + StringFromInt(argindent) + " = " + work + ";" +
										lambdarelease +
										"\n    return output_" + StringFromInt(argindent) + ";" +
										aftertext +
										"\n})"
								} else {
									argindent := 1
									arglineindent := "\n" + StringRepeat("  ", argindent)
									var lambdaargrelease []string
									for _, lambdaarg := range arglist {
										lambdaargname := CppFromName(lambdaarg.alias)
										lambdaargrelease = append(lambdaargrelease, lambdaargname)
										lambdaargpath := argsubpath + "/:arg/" + lambdaarg.name
										lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										lambdatext += "" +
											arglineindent + CppNameTypeFromType(lambdaarg.vxtype) + " " + lambdaargname + " = " + lambdavaluetext + ";" +
											arglineindent + "vx_core::vx_ref_plus(" + lambdaargname + ");"
									}
									work, msgs := CppFromValue(argvalue, pkgname, fnc, 0, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									outputname := "output_" + StringFromInt(argindent)
									lambdarelease := ""
									switch len(lambdaargrelease) {
									case 0:
									case 1:
										lambdarelease = arglineindent + "vx_core::vx_release_one_except(" + StringFromListStringJoin(lambdaargrelease, ", ") + ", " + outputname + ");"
									default:
										lambdarelease = arglineindent + "vx_core::vx_release_one_except({" + StringFromListStringJoin(lambdaargrelease, ", ") + "}, " + outputname + ");"
									}
									argtext = "" +
										"vx_core::t_any_from_func()->vx_fn_new({" + capturetext + "}, [" + capturetext + "]() {" +
										lambdatext +
										arglineindent + CppNameTypeFromType(fnc.vxtype) + " " + outputname + " = " + work + ";" +
										lambdarelease +
										arglineindent + "return " + outputname + ";" +
										"\n})"
								}
							}
						} else if funcname == "vx/core/fn" {
						} else if funcarg.vxtype.isfunc {
							switch argvalue.code {
							case ":arg":
								capturetext := CppCaptureFromValue(argvalue, argsubpath)
								argvaluearg := ArgFromValue(argvalue)
								if !argvaluearg.vxtype.isfunc {
									work, msgs := CppFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										"vx_core::t_any_from_func()->vx_fn_new({" + capturetext + "}, [" + capturetext + "]() {" +
										"\n  vx_core::Type_any output_" + StringFromInt(subindent) + " = " + work + ";" +
										"\n  return output_" + StringFromInt(subindent) + ";" +
										"\n})"
								}
							case ":funcref":
							default:
								funcargasync := funcarg.vxtype.vxfunc.async
								argfuncasync := false
								argfunctype := emptytype
								switch argvalue.code {
								case ":func":
									argfunc := FuncFromValue(argvalue)
									argfunctype = argfunc.vxtype
									argfuncasync = argfunc.async
								}
								converttoasync := false
								if funcargasync && !argfuncasync {
									converttoasync = true
								}
								workindent := indent + 1
								if converttoasync {
									workindent += 1
								}
								work, msgs := CppFromValue(argvalue, pkgname, fnc, workindent, true, test, argsubpath)
								if converttoasync {
									work = "vx_core::f_async(" + CppNameTFromType(argfunctype) + ",\n" + StringRepeat("  ", workindent) + work + "\n  )"
								}
								msgblock = MsgblockAddBlock(msgblock, msgs)
								if argvalue.code == ":func" && argvalue.name == "native" {
								} else {
									work = "" +
										"\n  " + CppNameTypeFromType(argvalue.vxtype) + " output_" + StringFromInt(workindent) + " = " + work + ";" +
										"\n  return output_" + StringFromInt(workindent) + ";"
								}
								capturetext := CppCaptureFromValue(argvalue, argsubpath)
								argtext = "" +
									CppNameTFromType(funcarg.vxtype) + "->vx_fn_new({" + capturetext + "}, [" + capturetext + "]() {" +
									work +
									"\n})"
							}
						}
						if argtext == "" {
							work, msgs := CppFromValue(argvalue, pkgname, fnc, 0, true, test, argsubpath)
							msgblock = MsgblockAddBlock(msgblock, msgs)
							argtext = work
						}
						if !multiline {
							if BooleanFromStringContains(argtext, "\n") {
								multiline = true
							} else if argvalue.name != "" {
								multiline = true
							} else if multiflag {
								multiline = true
							}
						}
						if funcarg.multi {
							ismultiarg := false
							if argvalue.code == ":arg" {
								argvaluearg := ArgFromValue(argvalue)
								if argvaluearg.multi {
									ismultiarg = true
								} else if funcarg.vxtype == argvaluearg.vxtype {
									ismultiarg = true
								}
							}
							if ismultiarg {
							} else if multiflag {
								argtext = "  " + StringFromStringIndent(argtext, "  ")
							} else {
								multiflag = true
								argtext = "" +
									"vx_core::vx_new(" + CppNameTFromType(funcarg.vxtype) + ", {" +
									"\n  " + StringFromStringIndent(argtext, "  ")
							}
						}
						if argtext != "" {
							switch funcarg.vxtype.extends {
							case ":list", ":map":
							default:
								if funcarg.vxtype.name != funcarg.value.vxtype.name {
									ok, _ := BooleanAllowFromTypeType(funcarg.vxtype, funcarg.value.vxtype)
									if ok {
										argtext = "(" + CppNameTypeFromType(funcarg.vxtype) + ")" + argtext
									}
								}
							}
							argtexts = append(argtexts, argtext)
						}
					}
				}
			}
			if fnc.context {
				argtexts = append(argtexts, "context")
			}
			if multiline {
				output += "\n" + sindent + "  " + StringFromStringIndent(StringFromListStringJoin(argtexts, ",\n"), sindent+"  ")
				if multiflag {
					output += "\n" + sindent + "  })"
				}
				switch fnc.name {
				case "fn":
				default:
					output += "\n" + sindent + ")"
				}
			} else {
				output += StringFromListStringJoin(argtexts, ", ")
				if multiflag {
					output += "})"
				}
				switch funcname {
				case "vx/core/fn":
				default:
					if !isskip {
						output += ")"
					}
				}
			}
		}
	case ":funcref":
		valfunc := FuncFromValue(value)
		valstr = ""
		valstr += CppNameTFromFunc(valfunc)
		output = sindent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = CppNameTFromType(valtype)
	case "string":
		valstr = StringValueFromValue(value)
		if valstr == "" {
		} else if BooleanFromStringStarts(valstr, ":") {
			output = valstr
		} else if BooleanFromStringStartsEnds(valstr, "\"", "\"") {
			valstr = valstr[1 : len(valstr)-1]
			if encode {
				output = StringFromStringFindReplace(valstr, "\n", "\\n")
			} else {
				output = valstr
			}
		} else if BooleanIsNumberFromString(valstr) {
			output = valstr
		} else {
			output = valstr
		}
		if encode {
			output = CppTypeStringValNew(output)
		}
	case "boolean":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::vx_new_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::vx_new_decimal_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::vx_new_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::vx_new_int(" + valstr + ")"
		}
	case "number":
		if encode {
			valstr = StringValueFromValue(value)
			output = valstr
		}
	default:
		//msg := MsgNew("Invalid Value Code:", value.code, ValueToText(value))
		//msgblock = MsgBlockAddError(msgblock, msg)
	}
	return output, msgblock
}

func CppFuncListFromListFunc(listfunc []*vxfunc) string {
	output := "vx_core::e_funclist()"
	if len(listfunc) > 0 {
		var listtext []string
		for _, fnc := range listfunc {
			typetext := CppNameTFromFunc(fnc)
			listtext = append(listtext, typetext)
		}
		output = "vx_core::vx_funclist_from_listfunc({" + StringFromListStringJoin(listtext, ", ") + "})"
	}
	return output
}

func CppGenericDefinitionFromFunc(fnc *vxfunc) string {
	output := ""
	var mapgeneric = make(map[string]string)
	if fnc.generictype != nil {
		returntype := CppGenericFromType(fnc.generictype)
		mapgeneric[fnc.vxtype.name] = "class " + returntype
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			if !argtype.isfunc {
				if argtype.isgeneric {
					_, ok := mapgeneric[argtype.name]
					if !ok {
						argtypename := CppGenericFromType(argtype)
						worktext := "class " + argtypename
						mapgeneric[argtype.name] = worktext
					}
				}
			}
		}
		generickeys := ListStringKeysFromStringMap(mapgeneric)
		for _, generickey := range generickeys {
			if output != "" {
				output += ", "
			}
			output += mapgeneric[generickey]
		}
		output = "template <" + output + "> "
	}
	return output
}

func CppGenericFromType(typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		switch typ.name {
		case "any-1":
			output = "T"
		case "any-2":
			output = "U"
		case "any-3":
			output = "V"
		case "list-1":
			output = "X"
		case "list-2":
			output = "Y"
		case "list-3":
			output = "Z"
		case "map-1":
			output = "N"
		case "map-2":
			output = "O"
		case "map-3":
			output = "P"
		case "struct-1":
			output = "Q"
		case "struct-2":
			output = "R"
		case "struct-3":
			output = "S"
		}
	} else {
		output = CppNameTypeFromType(typ)
	}
	return output
}

func CppGenericNameFromType(typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = "generic_" + StringFromStringFindReplace(typ.name, "-", "_")
	}
	return output
}

func CppImportsFromPackage(pkg *vxpackage, pkgprefix string, body string, test bool) string {
	output := ""
	if BooleanFromStringContains(body, "std::any") {
		output += "#include <any>\n"
	}
	if BooleanFromStringContains(body, "va_start(") {
		output += "#include <cstdarg>\n"
	}
	if BooleanFromStringContains(body, "std::exception") {
		output += "#include <exception>\n"
	}
	if BooleanFromStringContains(body, " std::function<") {
		output += "#include <functional>\n"
	}
	if BooleanFromStringContains(body, " std::future<") {
		output += "#include <future>\n"
	}
	if BooleanFromStringContains(body, " std::cout ") {
		output += "#include <iostream>\n"
	} else if BooleanFromStringContains(body, " std::ifstream ") {
		output += "#include <iostream>\n"
	} else if BooleanFromStringContains(body, " std::ofstream ") {
		output += "#include <iostream>\n"
	}
	if BooleanFromStringContains(body, " std::filesystem::") {
		output += "#include <filesystem>\n"
	}
	if BooleanFromStringContains(body, " std::ifstream ") {
		output += "#include <fstream>\n"
	} else if BooleanFromStringContains(body, " std::ofstream ") {
		output += "#include <fstream>\n"
	}
	if BooleanFromStringContains(body, "std::map<") {
		output += "#include <map>\n"
	}
	if BooleanFromStringContains(body, "std::shared_ptr") {
		output += "#include <memory>\n"
	}
	if BooleanFromStringContains(body, "std::set<") {
		output += "#include <set>\n"
	}
	if BooleanFromStringContains(body, "std::stringstream") {
		output += "#include <sstream>\n"
	}
	if BooleanFromStringContains(body, "std::string") {
		output += "#include <string>\n"
	}
	if BooleanFromStringContains(body, "std::vector<") {
		output += "#include <vector>\n"
	}
	slashcount := IntFromStringCount(pkg.name, "/")
	slashprefix := StringRepeat("../", slashcount)
	if test {
		output += "#include \"" + slashprefix + "../main/" + pkg.name + ".hpp\"\n"
	}
	if len(pkg.listlib) > 0 {
		for _, lib := range pkg.listlib {
			isskip := false
			libpath := lib.path
			if lib.lang != "" {
				if test {
					isskip = true
				} else if lib.lang == ":cpp" {
				} else {
					isskip = true
				}
			} else if !test && lib.path == "vx/test" {
				isskip = true
			} else if test {
				libpath = "../main/" + libpath
			}
			if !isskip {
				importline := "#include \"" + slashprefix + libpath + ".hpp\"\n"
				if IntFromStringFind(output, importline) < 0 {
					output += importline
				}
			}
		}
	}
	return output
}

func CppHeaderFromType(typ *vxtype) string {
	output := ""
	typename := CppNameFromType(typ)
	basics := "" +
		"\n    Class_" + typename + "();" +
		"\n    virtual ~Class_" + typename + "() override;" +
		"\n    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;" +
		"\n    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;" +
		"\n    virtual vx_core::Type_any vx_empty() const override;" +
		"\n    virtual vx_core::Type_any vx_type() const override;" +
		"\n    virtual vx_core::Type_typedef vx_typedef() const override;" +
		"\n    virtual vx_core::Type_msgblock vx_msgblock() const override;" +
		"\n    virtual vx_core::vx_Type_listany vx_dispose() override;"
	interfaces := ""
	createtext, _ := CppFromValue(typ.createvalue, "", emptyfunc, 0, true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isheader := false
		for _, createline := range createlines {
			trimline := StringTrim(createline)
			if trimline == "// :header" {
				isheader = true
			} else if trimline == "// :body" {
				isheader = false
			} else if isheader {
				if trimline == "" {
					basics += "\n"
				} else {
					//ipos := IntFromStringFindLast(createline, ")")
					//if ipos > 0 {
					//	createline = createline[0:ipos+1] + ";"
					//}
					interfaces += "\n    " + createline
				}
			}
		}
	}
	abstractinterfaces, classinterfaces := CppAbstractInterfaceFromInterface(typename, interfaces)
	switch NameFromType(typ) {
	case "vx/core/any":
		output = "" +
			"\n  // (type any)" +
			"\n  class Abstract_any {" +
			"\n  public:" +
			"\n    Abstract_any() {};" +
			"\n    virtual ~Abstract_any() = 0;" +
			"\n    long vx_p_iref = 0;" +
			"\n    vx_core::Type_msgblock vx_p_msgblock = NULL;" +
			"\n    virtual vx_core::Type_msgblock vx_msgblock() const {return this->vx_p_msgblock;};" +
			"\n    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const = 0;" +
			"\n    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const = 0;" +
			"\n    virtual vx_core::Type_any vx_empty() const = 0;" +
			"\n    virtual vx_core::Type_any vx_type() const = 0;" +
			"\n    virtual vx_core::Type_typedef vx_typedef() const = 0;" +
			"\n    virtual vx_core::vx_Type_listany vx_dispose() = 0;" +
			"\n  };" +
			"\n  class Class_any : public virtual Abstract_any {" +
			"\n  public:" +
			"\n    Class_any();" +
			"\n    virtual ~Class_any() override;" +
			"\n    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;" +
			"\n    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;" +
			"\n    virtual vx_core::Type_any vx_empty() const override;" +
			"\n    virtual vx_core::Type_any vx_type() const override;" +
			"\n    virtual vx_core::Type_typedef vx_typedef() const override;" +
			"\n    virtual vx_core::Type_msgblock vx_msgblock() const override;" +
			"\n    virtual vx_core::vx_Type_listany vx_dispose() override;" +
			"\n  };" +
			"\n"
	case "vx/core/boolean":
		output = "" +
			"\n  // (type boolean)" +
			"\n  class Abstract_boolean : public virtual vx_core::Abstract_any {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_boolean : public virtual vx_core::Abstract_boolean {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/decimal":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_decimal : public virtual vx_core::Abstract_number {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_decimal : public virtual vx_core::Abstract_decimal {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/float":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_float : public virtual vx_core::Abstract_number {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_float : public virtual vx_core::Abstract_float {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/func":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_func : public virtual vx_core::Abstract_any {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_func : public virtual vx_core::Abstract_func {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/int":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_int : public virtual vx_core::Abstract_number {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_int : public virtual vx_core::Abstract_int {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/string":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_string : public virtual vx_core::Abstract_any {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_string : public virtual vx_core::Abstract_string {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/list":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_list : public virtual vx_core::Abstract_any {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_list : public virtual vx_core::Abstract_list {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/map":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_map : public virtual vx_core::Abstract_any {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_map : public virtual vx_core::Abstract_map {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	case "vx/core/struct":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_struct : public virtual vx_core::Abstract_any {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_struct : public virtual vx_core::Abstract_struct {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	default:
		extends := ""
		switch typ.extends {
		case "boolean":
			extends = "public virtual vx_core::Abstract_boolean"
		case "decimal":
			extends = "public virtual vx_core::Abstract_decimal"
		case "float":
			extends = "public virtual vx_core::Abstract_float"
		case "int":
			extends = "public virtual vx_core::Abstract_int"
		case "string":
			extends = "public virtual vx_core::Abstract_string"
		case ":list":
			extends = "public virtual vx_core::Abstract_list"
			interfaces += "" +
				"\n    // vx_get_any(index)" +
				"\n    vx_core::Type_any vx_get_any(vx_core::Type_int index) const;" +
				"\n    // vx_list()" +
				"\n    vx_core::vx_Type_listany vx_list() const;" +
				"\n    // vx_new_from_list(T, List<T>)" +
				"\n    vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const;"
			allowclass := "vx_core::Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = CppNameTypeFullFromType(allowtype)
				allowname = CppNameFromType(allowtype)
			}
			interfaces += "" +
				"\n    std::vector<" + allowclass + "> vx_p_list;" +
				"\n"
			if allowname != "any" {
				interfaces += "" +
					"\n    // vx_list" + allowname + "()" +
					"\n    std::vector<" + allowclass + "> vx_list" + allowname + "() const;" +
					"\n    // vx_get_" + allowname + "(index)" +
					"\n    " + allowclass + " vx_get_" + allowname + "(vx_core::Type_int index) const;"
			}
		case ":map":
			extends = "public virtual vx_core::Abstract_map"
			allowclass := "vx_core::Type_any"
			interfaces += "" +
				"\n    // vx_get_any(key)" +
				"\n    vx_core::Type_any vx_get_any(vx_core::Type_string key) const;" +
				"\n    // vx_map()" +
				"\n    vx_core::vx_Type_mapany vx_map() const;" +
				"\n    // vx_new_from_map(T, Map<T>)" +
				"\n    vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const;"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = CppNameTypeFullFromType(allowtype)
				allowname = CppNameFromType(allowtype)
			}
			if allowname != "any" {
				interfaces += "" +
					"\n    std::map<std::string, " + allowclass + "> vx_p_map;" +
					"\n    // vx_map" + allowname + "()" +
					"\n    std::map<std::string, " + allowclass + "> vx_map" + allowname + "() const;" +
					"\n    // vx_get_" + allowname + "(key)" +
					"\n    " + allowclass + " vx_get_" + allowname + "(vx_core::Type_string key) const;"
			}
		case ":struct":
			extends = "public virtual vx_core::Abstract_struct"
			interfaces += "" +
				"\n    // vx_map()" +
				"\n    vx_core::vx_Type_mapany vx_map() const;" +
				"\n    // vx_get_any(key)" +
				"\n    vx_core::Type_any vx_get_any(vx_core::Type_string key) const;"
			if len(typ.traits) > 0 {
				var traitnames []string
				for _, trait := range typ.traits {
					traitname := "public virtual " + CppNameAbstractFullFromType(trait)
					traitnames = append(traitnames, traitname)
				}
				extends += ", " + StringFromListStringJoin(traitnames, ", ")
			}
			for _, arg := range ListPropertyTraitFromType(typ) {
				argclassname := CppNameTypeFromType(arg.vxtype)
				argname := CppFromName(arg.alias)
				interfaces += "" +
					"\n    // " + arg.name + "()" +
					"\n    " + argclassname + " vx_p_" + argname + " = NULL;" +
					"\n    " + argclassname + " " + argname + "() const;"
			}
		default:
			extends += "public virtual vx_core::Abstract_any"
		}
		abstractinterfaces, classinterfaces := CppAbstractInterfaceFromInterface(typename, interfaces)
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Abstract_" + typename + " : " + extends + " {" +
			"\n  public:" +
			abstractinterfaces +
			"\n  };" +
			"\n  class Class_" + typename + " : public virtual Abstract_" + typename + " {" +
			"\n  public:" +
			basics +
			classinterfaces +
			"\n  };" +
			"\n"
	}
	return output
}

func CppHeaderFnFromFunc(fnc *vxfunc) string {
	interfaces := ""
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any(vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-any-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-any-context":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_context)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-any-context-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any, vx_core::Type_context)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-key-value":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any(vx_core::Type_string, vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-func", "vx/core/any<-none":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any()> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-reduce":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-reduce-next":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any(vx_core::Type_any, vx_core::Type_any, vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-key-value-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::vx_Type_async(vx_core::Type_string, vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-func-async", "vx/core/any<-none-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::vx_Type_async()> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-reduce-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any, vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/any<-reduce-next-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::vx_Type_async(vx_core::Type_any, vx_core::Type_any, vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/boolean<-func", "vx/core/boolean<-none":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_boolean()> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/int<-func", "vx/core/int<-none":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_int()> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/string<-func", "vx/core/string<-none":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_string()> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	case "vx/core/none<-any":
		interfaces = "" +
			"\n    typedef std::function<void(vx_core::Type_any)> IFn;" +
			"\n    IFn fn;" +
			"\n    vx_core::vx_Type_listany lambdavars;"
	}
	return interfaces
}

func CppHeaderFromFunc(fnc *vxfunc) (string, string) {
	funcname := CppNameFromFunc(fnc)
	extends := ""
	abstractinterfaces := ""
	returntype := CppNameTypeFromType(fnc.vxtype)
	var listargtext []string
	var listsimpleargtext []string
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async", "vx/core/any<-key-value-async",
		"vx/core/any<-none-async", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next-async":
		listsimpleargtext = append(listsimpleargtext, "vx_core::Type_any generic_any_1")
	}
	if fnc.generictype != nil {
		returntype = CppPointerDefFromClassName(CppGenericFromType(fnc.generictype))
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			listargtext = append(listargtext, returntype+" generic_any_1")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if argtype.isgeneric {
				argtypename = CppPointerDefFromClassName(CppGenericFromType(argtype))
			} else {
				argtypename = CppNameTypeFromType(argtype)
			}
			argname := CppFromName(arg.alias)
			isskip := false
			switch NameFromFunc(fnc) {
			case "vx/core/let", "vx/core/let-async":
				// args is not included in let
				if argname == "args" {
					isskip = true
				}
			}
			if !isskip {
				listargtext = append(listargtext, argtypename+" "+argname)
				listsimpleargtext = append(listsimpleargtext, CppNameTypeFromType(argtype)+" "+argname)
			}
		}
	} else {
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := CppNameTypeFromType(argtype)
			argname := CppFromName(arg.alias)
			listargtext = append(listargtext, argtypename+" "+argname)
		}
	}
	argtext := StringFromListStringJoin(listargtext, ", ")
	simpleargtext := StringFromListStringJoin(listsimpleargtext, ", ")
	contextarg := ""
	if fnc.context {
		if argtext == "" {
			contextarg = "vx_core::Type_context context"
		} else {
			contextarg = ", vx_core::Type_context context"
		}
	}
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-context",
		"vx/core/any<-func", "vx/core/any<-key-value",
		"vx/core/any<-none", "vx/core/any<-reduce",
		"vx/core/any<-reduce-next":
		extends = "public vx_core::Abstract_func"
		abstractinterfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + " vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_" + funcname + "::IFn fn) const = 0;" +
			"\n    virtual vx_core::Type_any vx_" + funcname + "(" + simpleargtext + contextarg + ") const = 0;"
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async", "vx/core/any<-key-value-async",
		"vx/core/any<-none-async", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next-async":
		extends = "public vx_core::Abstract_func"
		abstractinterfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + " vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_" + funcname + "::IFn fn) const = 0;" +
			"\n    virtual vx_core::vx_Type_async vx_" + funcname + "(" + simpleargtext + contextarg + ") const = 0;"
	case "vx/core/boolean<-func", "vx/core/boolean<-none":
		extends = "public vx_core::Abstract_func"
		abstractinterfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + " vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_boolean_from_func::IFn fn) const = 0;" +
			"\n    virtual vx_core::Type_boolean vx_" + funcname + "(" + simpleargtext + contextarg + ") const = 0;"
	case "vx/core/int<-func", "vx/core/int<-none":
		extends = "public vx_core::Abstract_func"
		abstractinterfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + " vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_int_from_func::IFn fn) const = 0;" +
			"\n    virtual vx_core::Type_int vx_" + funcname + "(" + simpleargtext + contextarg + ") const = 0;"
	case "vx/core/string<-func", "vx/core/string<-none":
		extends = "public vx_core::Abstract_func"
		abstractinterfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + " vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_string_from_func::IFn fn) const = 0;" +
			"\n    virtual vx_core::Type_string vx_" + funcname + "(" + simpleargtext + contextarg + ") const = 0;"
	case "vx/core/none<-any":
		abstractinterfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + " vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_" + funcname + "::IFn fn) const = 0;" +
			"\n    vitrual vx_core::Type_none vx_" + funcname + "(" + simpleargtext + contextarg + ") const = 0;"
	default:
		if extends == "" {
			extends = "public vx_core::Abstract_func"
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
			default:
				switch len(fnc.listarg) {
				case 1:
					if fnc.async {
						if fnc.context {
							extends = "public vx_core::Abstract_any_from_any_context_async"
							abstractinterfaces += "" +
								"\n    virtual vx_core::Func_any_from_any_context_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context_async::IFn fn) const override = 0;" +
								"\n    virtual vx_core::vx_Type_async vx_any_from_any_context_async(vx_core::Type_any generic_any_1, vx_core::Type_any val, vx_core::Type_context context) const override = 0;"
						} else {
							extends = "public vx_core::Abstract_any_from_any_async"
							abstractinterfaces += "" +
								"\n    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;" +
								"\n    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;"
						}
					} else {
						if fnc.context {
							extends = "public vx_core::Abstract_any_from_any_context"
							abstractinterfaces += "" +
								"\n    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;" +
								"\n    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;"
						} else {
							extends = "public vx_core::Abstract_any_from_any"
							abstractinterfaces += "" +
								"\n    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;" +
								"\n    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;"
						}
					}
				}
			}
		}
	}
	if fnc.async {
		returntype = "vx_core::vx_Type_async"
	}
	if fnc.async {
		extends += ", public virtual vx_core::Abstract_replfunc_async"
		abstractinterfaces += "" +
			"\n    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;"
	} else {
		extends += ", public virtual vx_core::Abstract_replfunc"
		abstractinterfaces += "" +
			"\n    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;"
	}
	//	interfaces += "" +
	//		"\n    " + generictypes + returntype + " vx_f_" + funcname + "(" + argtext + contextarg + ");"
	fnheaders := CppHeaderFnFromFunc(fnc)
	classinterfaces := StringFromStringFindReplace(abstractinterfaces, " = 0;", ";")
	output := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  class Abstract_" + funcname + " : " + extends + " {" +
		"\n  public:" +
		"\n    Abstract_" + funcname + "() {};" +
		"\n    virtual ~Abstract_" + funcname + "() = 0;" +
		fnheaders +
		abstractinterfaces +
		"\n  };" +
		"\n  class Class_" + funcname + " : public virtual Abstract_" + funcname + " {" +
		"\n  public:" +
		"\n    Class_" + funcname + "();" +
		"\n    virtual ~Class_" + funcname + "() override;" +
		"\n    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;" +
		"\n    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;" +
		"\n    virtual vx_core::Type_funcdef vx_funcdef() const override;" +
		"\n    virtual vx_core::Type_typedef vx_typedef() const override;" +
		"\n    virtual vx_core::Type_msgblock vx_msgblock() const override;" +
		"\n    virtual vx_core::vx_Type_listany vx_dispose() override;" +
		"\n    virtual vx_core::Type_any vx_empty() const override;" +
		"\n    virtual vx_core::Type_any vx_type() const override;" +
		classinterfaces +
		"\n  };" +
		"\n"
	genericdefinition := CppGenericDefinitionFromFunc(fnc)
	headerfooter := ""
	if genericdefinition == "" {
		headerfooter = "" +
			"\n  // (func " + fnc.name + ")" +
			"\n  " + genericdefinition + returntype + " f_" + funcname + "(" + argtext + contextarg + ");" +
			"\n"
	}
	return output, headerfooter
}

func CppIndexFromFunc(fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func CppNameAbstractFullFromConst(cnst *vxconst) string {
	name := CppNameFromPkgName(cnst.pkgname)
	name += "::Abstract_"
	name += CppNameFromConst(cnst)
	return name
}

func CppNameAbstractFullFromFunc(fnc *vxfunc) string {
	name := CppNameFromPkgName(fnc.pkgname)
	name += "::Abstract_"
	name += CppNameFromFunc(fnc)
	return name
}

func CppNameAbstractFullFromType(typ *vxtype) string {
	name := CppNameFromPkgName(typ.pkgname)
	name += "::Abstract_"
	name += CppNameFromType(typ)
	return name
}

func CppNameClassFullFromConst(cnst *vxconst) string {
	name := CppNameFromPkgName(cnst.pkgname)
	name += "::Class_"
	name += CppNameFromConst(cnst)
	return name
}

func CppNameClassFullFromFunc(fnc *vxfunc) string {
	name := CppNameFromPkgName(fnc.pkgname)
	name += "::Class_"
	name += CppNameFromFunc(fnc)
	return name
}

func CppNameClassFullFromType(typ *vxtype) string {
	name := CppNameFromPkgName(typ.pkgname)
	name += "::Class_"
	name += CppNameFromType(typ)
	return name
}

func CppNameEFromType(typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = "vx_core::vx_empty(generic_" + CppFromName(typ.name) + ")"
	} else {
		output = "e_" + CppNameFromType(typ) + "()"
		if typ.pkgname != "" {
			output = CppNameFromPkgName(typ.pkgname) + "::" + output
		}
	}
	return output
}

func CppNameEFromFunc(fnc *vxfunc) string {
	name := "e_" + CppNameFromFunc(fnc) + "()"
	if fnc.pkgname != "" {
		name = CppNameFromPkgName(fnc.pkgname) + "::" + name
	}
	return name
}

func CppNameFromConst(cnst *vxconst) string {
	return CppFromName(cnst.alias)
}

func CppNameFromFunc(fnc *vxfunc) string {
	return CppFromName(fnc.alias) + CppIndexFromFunc(fnc)
}

func CppNameFromPkgName(pkgname string) string {
	output := pkgname
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func CppNameFromType(typ *vxtype) string {
	name := ""
	if typ.alias == "" {
		name += CppFromName(typ.name)
	} else {
		name += CppFromName(typ.alias)
	}
	return name
}

func CppNameTFromFunc(fnc *vxfunc) string {
	name := "t_" + CppNameFromFunc(fnc) + "()"
	if fnc.pkgname != "" {
		name = CppNameFromPkgName(fnc.pkgname) + "::" + name
	}
	return name
}

func CppNameTFromType(typ *vxtype) string {
	name := "t_" + CppNameFromType(typ) + "()"
	if typ.pkgname != "" {
		name = CppNameFromPkgName(typ.pkgname) + "::" + name
	}
	return name
}

func CppNameTFromTypeGeneric(typ *vxtype) string {
	name := ""
	if typ.isgeneric {
		name = "generic_" + CppFromName(typ.name)
	} else {
		name = CppNameTFromType(typ)
	}
	return name
}

func CppNameTypeFromType(typ *vxtype) string {
	name := CppNameTypeFullFromType(typ)
	switch name {
	case "vx_core::Type_none":
		name = "void"
	}
	return name
}

func CppNameTypeFullFromConst(cnst *vxconst) string {
	name := CppNameFromPkgName(cnst.pkgname)
	name += "::Const_"
	name += CppNameFromConst(cnst)
	return name
}

func CppNameTypeFullFromFunc(fnc *vxfunc) string {
	name := CppNameFromPkgName(fnc.pkgname)
	name += "::Func_"
	name += CppNameFromFunc(fnc)
	return name
}

func CppNameTypeFullFromType(typ *vxtype) string {
	name := CppNameFromPkgName(typ.pkgname)
	if typ.isfunc {
		name += "::Func_"
	} else {
		name += "::Type_"
	}
	name += CppNameFromType(typ)
	return name
}

func CppPointerDefFromClassName(text string) string {
	output := text + "*"
	if issharedpointer {
		output = "std::shared_ptr<" + text + ">"
	}
	return output
}

func CppPointerNewFromClassName(text string) string {
	output := "new " + text + "()"
	if issharedpointer {
		output = "std::make_shared<" + text + ">()"
	}
	return output
}

func CppPointerNullFromClassName(text string) string {
	output := "NULL"
	if issharedpointer {
		output = "std::shared_ptr<" + text + ">()"
	}
	return output
}

func CppReplFromFunc(fnc *vxfunc) string {
	output := ""
	replparams := ""
	argidx := 0
	var listargname []string
	pkgname := CppNameFromPkgName(fnc.pkgname)
	funcname := CppFromName(fnc.alias) + CppIndexFromFunc(fnc)
	classname := "Class_" + funcname
	outputtype := ""
	outputttype := ""
	//emptytype := ""
	returnvalue := ""
	switch NameFromType(fnc.vxtype) {
	case "vx/core/none":
		outputtype = "vx_core::Type_any"
		outputttype = "vx_core::t_any"
		//emptytype = "vx_core::e_any"
	default:
		outputtype = CppNameTypeFromType(fnc.vxtype)
		outputttype = CppNameTFromType(fnc.vxtype)
		//emptytype = CppNameEFromType(fnc.vxtype)
		returnvalue = "output = "
	}
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		default:
			if fnc.generictype != nil {
				replparam := outputtype + " generic_" + CppFromName(fnc.generictype.name) + " = vx_core::vx_any_from_any(" + outputttype + ", arglist->vx_get_any(vx_core::vx_new_int(" + StringFromInt(argidx) + ")));"
				replparams += "\n      " + replparam
				listargname = append(listargname, "generic_"+CppFromName(fnc.generictype.name))
			}
		}
	}
	for _, arg := range fnc.listarg {
		if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
		} else {
			argname := CppFromName(arg.alias)
			replparam := CppNameTypeFromType(arg.vxtype) + " " + argname + " = vx_core::vx_any_from_any(" + CppNameTFromType(arg.vxtype) + ", arglist->vx_get_any(vx_core::vx_new_int(" + StringFromInt(argidx) + ")));"
			replparams += "\n      " + replparam
			listargname = append(listargname, argname)
			argidx += 1
		}
	}
	if fnc.context {
		listargname = append(listargname, "context")
		replparam := "vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(" + StringFromInt(argidx) + ")));"
		replparams += "\n      " + replparam
	}
	if fnc.async {
		output = "" +
			"\n    vx_core::vx_Type_async " + classname + "::vx_repl(vx_core::Type_anylist arglist) {" +
			"\n      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any());" +
			replparams +
			"\n      output = " + pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      vx_core::vx_release(arglist);" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	} else {
		output = "" +
			"\n    vx_core::Type_any " + classname + "::vx_repl(vx_core::Type_anylist arglist) {" +
			"\n      vx_core::Type_any output = vx_core::e_any();" +
			replparams +
			"\n      " + returnvalue + pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      vx_core::vx_release_except(arglist, output);" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	return output
}

func CppStringFromProjectCmd(prj *vxproject, cmd *vxcommand) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppStringFromProjectCmd")
	files, msgs := CppFilesFromProjectCmd(prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	text := StringFromListFile(files)
	return text, msgblock
}

func CppTestCase(testvalues []vxvalue, testpkg string, testname string, testcasename string, fnc *vxfunc, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppTestCase")
	var output = ""
	if len(testvalues) > 0 {
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := CppFromValue(testvalue, testpkg, fnc, 6, true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n          vx_core::vx_new(vx_test::t_testdescribe(), {" +
				"\n            vx_core::vx_new_string(\":describename\"), vx_core::vx_new_string(\"" + CppTestFromValue(testvalue) + "\")," +
				"\n            vx_core::vx_new_string(\":testpkg\"), vx_core::vx_new_string(\"" + testpkg + "\")," +
				"\n            vx_core::vx_new_string(\":testresult\")," +
				"\n            " + descvaluetext +
				"\n          })"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		output = "" +
			"\n  vx_test::Type_testcase " + testcasename + "(vx_core::Type_context context) {" +
			"\n    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {" +
			"\n      vx_core::vx_new_string(\":passfail\"), vx_core::c_false()," +
			"\n      vx_core::vx_new_string(\":testpkg\"), vx_core::vx_new_string(\"" + testpkg + "\")," +
			"\n      vx_core::vx_new_string(\":casename\"), vx_core::vx_new_string(\"" + testname + "\")," +
			"\n      vx_core::vx_new_string(\":describelist\")," +
			"\n      vx_core::vx_any_from_any(" +
			"\n        vx_test::t_testdescribelist()," +
			"\n        vx_test::t_testdescribelist()->vx_new_from_list({" +
			describelist +
			"\n        })" +
			"\n      )" +
			"\n    });" +
			"\n    return output;" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func CppTestFromConst(cnst *vxconst) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppTestFromConst")
	testvalues := cnst.listtestvalue
	testpkg := cnst.pkgname
	testname := cnst.name
	testcasename := "c_" + CppFromName(cnst.alias)
	path := cnst.pkgname + "/" + cnst.name
	fnc := emptyfunc
	output, msgs := CppTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func CppTestFromFunc(fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppTestFromFunc")
	testvalues := fnc.listtestvalue
	testpkg := fnc.pkgname
	idx := CppIndexFromFunc(fnc)
	testname := fnc.name + idx
	funcname := CppFromName(fnc.alias) + idx
	testcasename := "f_" + funcname
	path := fnc.pkgname + "/" + fnc.name + StringIndexFromFunc(fnc)
	output, msgs := CppTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func CppTestFromPackage(pkg *vxpackage, prj *vxproject) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppTestFromPackage")
	pkgname := CppNameFromPkgName(pkg.name)
	typkeys := ListKeyFromMapType(pkg.maptype)
	var coverdoccnt = 0
	var coverdoctotal = 0
	var covertypecnt = 0
	var covertypetotal = 0
	var testall []string
	var covertype []string
	typeheaders := ""
	typetexts := ""
	for _, typid := range typkeys {
		covertypetotal += 1
		typ := pkg.maptype[typid]
		test, msgs := CppTestFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		covertype = append(covertype, "vx_core::vx_new_string(\":"+typid+"\"), vx_core::vx_new_int("+StringFromInt(len(typ.testvalues))+")")
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(testall, pkgname+"_test::t_"+CppFromName(typ.alias)+"(context)")
			typeheaders += "\n  vx_test::Type_testcase t_" + CppFromName(typ.alias) + "(vx_core::Type_context context);"
		}
		coverdoctotal += 1
		if typ.doc != "" {
			coverdoccnt += 1
		}
	}
	var coverconstcnt = 0
	var coverconsttotal = 0
	var coverconst []string
	var coverfunc []string
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	constheaders := ""
	consttexts := ""
	for _, cnstid := range cnstkeys {
		coverconsttotal += 1
		cnst := pkg.mapconst[cnstid]
		test, msgs := CppTestFromConst(cnst)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		coverconst = append(coverconst, "vx_core::vx_new_string(\":"+cnstid+"\"), vx_core::vx_new_int("+StringFromInt(len(cnst.listtestvalue))+")")
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(testall, pkgname+"_test::c_"+CppFromName(cnst.alias)+"(context)")
			constheaders += "\n  vx_test::Type_testcase c_" + CppFromName(cnst.alias) + "(vx_core::Type_context context);"
		}
		coverdoctotal += 1
		if cnst.doc != "" {
			coverdoccnt += 1
		}
	}
	var coverbigospacecnt = 0
	var coverbigospacetotal = 0
	var coverbigotimecnt = 0
	var coverbigotimetotal = 0
	var coverfunccnt = 0
	var coverfunctotal = 0
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	funcheaders := ""
	functexts := ""
	for _, fncid := range fnckeys {
		coverfunctotal += 1
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			test, msgs := CppTestFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			coverfunc = append(coverfunc, "vx_core::vx_new_string(\":"+fncid+CppIndexFromFunc(fnc)+"\"), vx_core::vx_new_int("+StringFromInt(len(fnc.listtestvalue))+")")
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(testall, pkgname+"_test::f_"+CppFromName(fnc.alias)+CppIndexFromFunc(fnc)+"(context)")
				funcheaders += "\n  vx_test::Type_testcase f_" + CppFromName(fnc.alias) + "(vx_core::Type_context context);"
			}
			coverdoctotal += 1
			if fnc.doc != "" {
				coverdoccnt += 1
			}
			coverbigospacetotal += 1
			if fnc.bigospace != "" {
				coverbigospacecnt += 1
			}
			coverbigotimetotal += 1
			if fnc.bigotime != "" {
				coverbigotimecnt += 1
			}
		}
	}
	coverconstpct := 100
	if coverconsttotal > 0 {
		coverconstpct = (coverconstcnt * 100 / coverconsttotal)
	}
	coverfuncpct := 100
	if coverfunctotal > 0 {
		coverfuncpct = (coverfunccnt * 100 / coverfunctotal)
	}
	covertypepct := 100
	if covertypetotal > 0 {
		covertypepct = (covertypecnt * 100 / covertypetotal)
	}
	coverbigospacepct := 100
	if coverbigospacetotal > 0 {
		coverbigospacepct = (coverbigospacecnt * 100 / coverbigospacetotal)
	}
	coverbigotimepct := 100
	if coverbigotimetotal > 0 {
		coverbigotimepct = (coverbigotimecnt * 100 / coverbigotimetotal)
	}
	coverdocpct := 100
	if coverdoctotal > 0 {
		coverdocpct = (coverdoccnt * 100 / coverdoctotal)
	}
	var covercnt = coverconstcnt + coverfunccnt + covertypecnt
	var covertotal = covertypetotal + coverconsttotal + coverfunctotal
	var coverpct = 100
	if covertotal > 0 {
		coverpct = (covercnt * 100 / covertotal)
	}
	testalltext := ""
	if len(testall) > 0 {
		frontdelim := "\n    listtestcase.push_back("
		backdelim := ");"
		testalltext = "" +
			frontdelim + strings.Join(testall, backdelim+frontdelim) + backdelim
	}
	body := "" +
		typetexts +
		consttexts +
		functexts +
		"\n  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {" +
		"\n    vx_core::vx_Type_listany listtestcase;" +
		testalltext +
		"\n    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(" +
		"\n      vx_test::t_testcaselist()," +
		"\n      vx_test::t_testcaselist()->vx_new_from_list(listtestcase)" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testcoveragesummary test_coveragesummary() {" +
		"\n    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary(), {" +
		"\n      vx_core::vx_new_string(\":testpkg\"), vx_core::vx_new_string(\"" + pkg.name + "\")," +
		"\n      vx_core::vx_new_string(\":constnums\"), " + CppTypeCoverageNumsValNew(coverconstpct, coverconstcnt, coverconsttotal) + "," +
		"\n      vx_core::vx_new_string(\":docnums\"), " + CppTypeCoverageNumsValNew(coverdocpct, coverdoccnt, coverdoctotal) + "," +
		"\n      vx_core::vx_new_string(\":funcnums\"), " + CppTypeCoverageNumsValNew(coverfuncpct, coverfunccnt, coverfunctotal) + "," +
		"\n      vx_core::vx_new_string(\":bigospacenums\"), " + CppTypeCoverageNumsValNew(coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + "," +
		"\n      vx_core::vx_new_string(\":bigotimenums\"), " + CppTypeCoverageNumsValNew(coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + "," +
		"\n      vx_core::vx_new_string(\":totalnums\"), " + CppTypeCoverageNumsValNew(coverpct, covercnt, covertotal) + "," +
		"\n      vx_core::vx_new_string(\":typenums\"), " + CppTypeCoverageNumsValNew(covertypepct, covertypecnt, covertypetotal) +
		"\n    });" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testcoveragedetail test_coveragedetail() {" +
		"\n    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail(), {" +
		"\n      vx_core::vx_new_string(\":testpkg\"), vx_core::vx_new_string(\"" + pkg.name + "\")," +
		"\n      vx_core::vx_new_string(\":typemap\"), vx_core::vx_new(vx_core::t_intmap(), {" +
		"\n        " + strings.Join(covertype, ",\n        ") +
		"\n      })," +
		"\n      vx_core::vx_new_string(\":constmap\"), vx_core::vx_new(vx_core::t_intmap(), {" +
		"\n        " + strings.Join(coverconst, ",\n        ") +
		"\n      })," +
		"\n      vx_core::vx_new_string(\":funcmap\"), vx_core::vx_new(vx_core::t_intmap(), {" +
		"\n        " + strings.Join(coverfunc, ",\n        ") +
		"\n      })" +
		"\n    });" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testpackage test_package(vx_core::Type_context context) {" +
		"\n    vx_test::Type_testcaselist testcaselist = " + pkgname + "_test::test_cases(context);" +
		"\n    vx_test::Type_testcoveragesummary testcoveragesummary = " + pkgname + "_test::test_coveragesummary();" +
		"\n    vx_test::Type_testcoveragedetail testcoveragedetail = " + pkgname + "_test::test_coveragedetail();" +
		"\n    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage(), {" +
		"\n      vx_core::vx_new_string(\":testpkg\"), vx_core::vx_new_string(\"" + pkg.name + "\")," +
		"\n      vx_core::vx_new_string(\":caselist\"), testcaselist," +
		"\n      vx_core::vx_new_string(\":coveragesummary\"), testcoveragesummary," +
		"\n      vx_core::vx_new_string(\":coveragedetail\"), testcoveragedetail" +
		"\n    });" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := CppImportsFromPackage(pkg, "", body, true)
	slashcount := IntFromStringCount(pkg.name, "/")
	slashprefix := StringRepeat("../", slashcount)
	simplename := pkg.name
	ipos := IntFromStringFindLast(simplename, "/")
	if ipos >= 0 {
		simplename = simplename[ipos+1:]
	}
	headertext := "" +
		"#ifndef " + StringUCase(pkgname+"_test_hpp") +
		"\n#define " + StringUCase(pkgname+"_test_hpp") +
		"\n#include \"" + slashprefix + "../main/vx/core.hpp\"" +
		"\n#include \"" + slashprefix + "../main/vx/test.hpp\"" +
		"\n" +
		"\nnamespace " + pkgname + "_test {" +
		"\n" +
		typeheaders +
		constheaders +
		funcheaders +
		"\n" +
		"\n  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);" +
		"\n  vx_test::Type_testcoveragesummary test_coveragesummary();" +
		"\n  vx_test::Type_testcoveragedetail test_coveragedetail();" +
		"\n  vx_test::Type_testpackage test_package(vx_core::Type_context context);" +
		"\n" +
		"\n}" +
		"\n#endif" +
		"\n"
	output := "" +
		imports +
		"\n#include \"" + simplename + "_test.hpp\"" +
		"\n" +
		"\nnamespace " + pkgname + "_test {" +
		"\n" +
		body +
		"\n}\n"
	return output, headertext, msgblock
}

func CppTestFromType(typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppTestFromType")
	testvalues := typ.testvalues
	testpkg := typ.pkgname
	testname := typ.name
	testcasename := "t_" + CppFromName(typ.alias)
	fnc := emptyfunc
	path := typ.pkgname + "/" + typ.name
	output, msgs := CppTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func CppTestFromValue(value vxvalue) string {
	var output = ""
	output = CppFromText(value.textblock.text)
	return output
}

func CppTypeCoverageNumsValNew(pct int, tests int, total int) string {
	return "" +
		"vx_core::vx_new(vx_test::t_testcoveragenums(), {" +
		"\n        vx_core::vx_new_string(\":pct\"), vx_core::vx_new_int(" + StringFromInt(pct) + "), " +
		"\n        vx_core::vx_new_string(\":tests\"), vx_core::vx_new_int(" + StringFromInt(tests) + "), " +
		"\n        vx_core::vx_new_string(\":total\"), vx_core::vx_new_int(" + StringFromInt(total) + ")" +
		"\n      })"
}

func CppTypeDefFromFunc(fnc *vxfunc, indent string) string {
	lineindent := "\n" + indent
	allowtypes := "vx_core::e_typelist()"
	disallowtypes := "vx_core::e_typelist()"
	allowfuncs := "vx_core::e_funclist()"
	disallowfuncs := "vx_core::e_funclist()"
	allowvalues := "vx_core::e_anylist()"
	disallowvalues := "vx_core::e_anylist()"
	properties := "vx_core::e_argmap()"
	traits := "vx_core::e_typelist()"
	output := "" +
		"vx_core::Class_typedef::vx_typedef_new(" +
		lineindent + "  \"" + fnc.pkgname + "\", // pkgname" +
		lineindent + "  \"" + fnc.name + "\", // name" +
		lineindent + "  \":func\", // extends" +
		lineindent + "  " + traits + ", // traits" +
		lineindent + "  " + allowtypes + ", // allowtypes" +
		lineindent + "  " + disallowtypes + ", // disallowtypes" +
		lineindent + "  " + allowfuncs + ", // allowfuncs" +
		lineindent + "  " + disallowfuncs + ", // disallowfuncs" +
		lineindent + "  " + allowvalues + ", // allowvalues" +
		lineindent + "  " + disallowvalues + ", // disallowvalues" +
		lineindent + "  " + properties + " // properties" +
		lineindent + ")"
	return output
}

func CppTypeDefFromType(typ *vxtype, indent string) string {
	lineindent := "\n" + indent
	allowtypes := CppTypeListFromListType(typ.allowtypes)
	disallowtypes := CppTypeListFromListType(typ.disallowtypes)
	allowfuncs := CppFuncListFromListFunc(typ.allowfuncs)
	disallowfuncs := CppFuncListFromListFunc(typ.disallowfuncs)
	allowvalues := CppConstListFromListConst(typ.allowvalues)
	disallowvalues := CppConstListFromListConst(typ.disallowvalues)
	properties := CppArgMapFromListArg(typ.properties, 4)
	traits := CppTypeListFromListType(typ.traits)
	output := "" +
		"vx_core::Class_typedef::vx_typedef_new(" +
		lineindent + "  \"" + typ.pkgname + "\", // pkgname" +
		lineindent + "  \"" + typ.name + "\", // name" +
		lineindent + "  \"" + typ.extends + "\", // extends" +
		lineindent + "  " + traits + ", // traits" +
		lineindent + "  " + allowtypes + ", // allowtypes" +
		lineindent + "  " + disallowtypes + ", // disallowtypes" +
		lineindent + "  " + allowfuncs + ", // allowfuncs" +
		lineindent + "  " + disallowfuncs + ", // disallowfuncs" +
		lineindent + "  " + allowvalues + ", // allowvalues" +
		lineindent + "  " + disallowvalues + ", // disallowvalues" +
		lineindent + "  " + properties + " // properties" +
		lineindent + ")"
	return output
}

func CppTypeDefMapFromProperties(args []vxarg, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(args) > 0 {
		var props []string
		for _, arg := range args {
			key := CppFromName(arg.alias)
			typ := CppTypeDefFromType(arg.vxtype, indent+"  ")
			props = append(props, "vx_core::keyvalue_from_key_value(\":"+key+"\", "+typ+")")
		}
		output = "" +
			"vx_core::hashmap_from_keyvalues(" +
			lineindent + "  " + StringFromListStringJoin(props, ","+lineindent+"  ") +
			lineindent + ")"
	}
	return output
}

func CppTypeIntValNew(val int) string {
	return "vx_core::vx_new_int(" + StringFromInt(val) + ")"
}

func CppTypeListFromListType(listtype []*vxtype) string {
	output := "vx_core::e_typelist()"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := CppNameTFromType(typ)
			listtext = append(listtext, typetext)
		}
		output = "vx_core::vx_typelist_from_listany({" + StringFromListStringJoin(listtext, ", ") + "})"
	}
	return output
}

func CppTypeStringValNew(val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return "vx_core::vx_new_string(\"" + valstr + "\")"
}

func CppWriteFromProjectCmd(prj *vxproject, cmd *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("CppWriteFromProjectCmd")
	files, msgs := CppFilesFromProjectCmd(prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	msgs = WriteListFile(files)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	switch cmd.code {
	case ":test":
		targetpath := PathFromProjectCmd(prj, cmd)
		ipos := IntFromStringFindLast(targetpath, "/")
		if ipos > 0 {
			targetpath = targetpath[0:ipos]
		}
		targetpath += "/test/resources"
		msgs := CppFolderCopyTestdataFromProjectPath(prj, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func CppApp(prj *vxproject) string {
	output := "" +
		`
#include <iostream>
#include "vx/core.hpp"

int main(int iarglen, char* arrayarg[]) {
  int output = 0;
	try {
    //vx_core::Type_context context = vx_core::e_context();
    std::vector<std::string> listarg = vx_core::vx_liststring_from_arraystring(iarglen, arrayarg);
    vx_core::Type_string output = vx_core::vx_new_string("Hello World");
    std::cout << output->vx_string() << std::endl;
		vx_core::vx_release(output);
		//vx_core::vx_release(context);
	  vx_core::vx_memory_leak_test();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    output = -1;
  } catch (...) {
    std::cerr << "Untrapped Error!" << std::endl;
    output = -1;
  }
	return output;
}
`
	return output
}

func CppAppTest(prj *vxproject) string {
	listpackage := prj.listpackage
	var listtestpackage []string
	imports := "" +
		"#include <iostream>" +
		"\n#include <stdexcept>" +
		"\n#include \"../main/vx/core.hpp\"" +
		"\n#include \"../main/vx/test.hpp\"" +
		"\n#include \"test_lib.hpp\"" +
		"\n"
	for _, pkg := range listpackage {
		pkgname := StringFromStringFindReplace(pkg.name, "/", "_")
		testpackage := pkgname + "_test::test_package(context)"
		listtestpackage = append(listtestpackage, testpackage)
		importline := "#include \"" + pkg.name + "_test.hpp\"\n"
		imports += importline
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",\n    ")
	output := "" +
		imports + `
/**
 * Unit test for whole App.
 */

vx_test::Type_testpackagelist testsuite(vx_core::Type_context context) {
  vx_test::Type_testpackagelist output = vx_core::vx_new(vx_test::t_testpackagelist(), {
    ` + testpackages + `
  });
  return output;
}

int main(int iarglen, char* arrayarg[]) {
  int output = 0;
  try {
    vx_core::vx_debug("Test Start");
    std::vector<std::string> listarg = vx_core::vx_liststring_from_arraystring(iarglen, arrayarg);
    vx_core::Type_context context = vx_core::e_context();
    test_lib::test_helloworld();
    test_lib::test_async_new_from_value();
    test_lib::test_async_from_async_fn();
    test_lib::test_run_testresult(context);
    test_lib::test_run_testdescribe(context);
    test_lib::test_run_testdescribelist(context);
    test_lib::test_run_testcase(context);
    test_lib::test_run_testcaselist(context);
    test_lib::test_run_testpackage(context);
    test_lib::test_run_testpackagelist(context);
    test_lib::test_resolve_testresult_anyfromfunc(context);
    test_lib::test_resolve_testresult_then(context);
    test_lib::test_resolve_testresult_thenelselist(context);
    test_lib::test_resolve_testresult_if(context);
    test_lib::test_resolve_testresult_f_resolve_testresult_async(context);
    test_lib::test_resolve_testresult_f_resolve_testresult(context);
    test_lib::test_run_testresult_async(context);
    test_lib::test_run_testdescribe_async(context);
    test_lib::test_run_testdescribelist_async_f_list_from_list_async(context);
    test_lib::test_run_testdescribelist_async(context);
    test_lib::test_run_testcase_async_f_resolvetestcase(context);
    test_lib::test_run_testcase_async_syncvalue(context);
    test_lib::test_run_testcase_async(context);
    test_lib::test_run_testcaselist_async(context);
    test_lib::test_run_testpackage_async(context);
    test_lib::test_run_testpackagelist_async(context);
    test_lib::test_pathfull_from_file(context);
    test_lib::test_read_file(context);
    test_lib::test_write_file(context);
    test_lib::test_tr_from_testdescribe_casename(context);
    test_lib::test_trlist_from_testcase(context);
    test_lib::test_trlist_from_testcaselist(context);
    test_lib::test_div_from_testcaselist(context);
    test_lib::test_div_from_testpackage(context);
    test_lib::test_div_from_testpackagelist(context);
    test_lib::test_node_from_testpackagelist(context);
    test_lib::test_html_from_testpackagelist(context);
    test_lib::test_write_testpackagelist(context);
    test_lib::test_write_node(context);
    test_lib::test_write_html(context);
    test_lib::test_write_testpackagelist_async(context);
    test_lib::test_run_all(testsuite(context), context);
    vx_core::vx_release(context);
    vx_core::vx_memory_leak_test();
    vx_core::vx_debug("Test End");
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    output = -1;
  } catch (...) {
    vx_core::vx_debug("Unexpected error");
    output = -1;
  }
  return output;
}
`
	return output
}

func CppTestLib() (string, string) {
	header := "" +
		`#ifndef TEST_LIB_HPP
#define TEST_LIB_HPP
#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"

namespace test_lib {

  vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase);

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase);

  vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist);

  // Blocking
  // Only use if running a single testcaselist
  vx_test::Type_testcaselist run_testcaselist_async(vx_test::Type_testcaselist testcaselist);

  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe describe);

  // Only use if running a single testdescribe
  vx_test::Type_testdescribe run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe);

  vx_test::Type_testdescribelist run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist);

  // Blocking
  // Only use if running a single testdescribelist
  vx_test::Type_testdescribelist run_testdescribelist_async(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist);

  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage);

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage run_testpackage_async(vx_test::Type_testpackage testpackage);

  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist);

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist);

  vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult);

	// Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult);

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context);

  bool test(std::string testname, std::string expected, std::string actual);

  bool test_helloworld();

  bool test_async_new_from_value();

  bool test_async_from_async_fn();

  bool test_div_from_testcaselist(vx_core::Type_context context);

  bool test_div_from_testpackage(vx_core::Type_context context);

  bool test_div_from_testpackagelist(vx_core::Type_context context);

  bool test_html_from_testpackagelist(vx_core::Type_context context);

  bool test_node_from_testpackagelist(vx_core::Type_context context);

  bool test_pathfull_from_file(vx_core::Type_context context);

  bool test_read_file(vx_core::Type_context context);

  bool test_resolve_testresult_anyfromfunc(vx_core::Type_context context);

  bool test_resolve_testresult_f_resolve_testresult(vx_core::Type_context context);

  bool test_resolve_testresult_f_resolve_testresult_async(vx_core::Type_context context);

  bool test_resolve_testresult_if(vx_core::Type_context context);

  bool test_resolve_testresult_then(vx_core::Type_context context);

  bool test_resolve_testresult_thenelselist(vx_core::Type_context context);

  bool test_run_all(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context);

  bool test_run_testcase(vx_core::Type_context context);

  bool test_run_testcase_async(vx_core::Type_context context);

  bool test_run_testcase_async_f_resolvetestcase(vx_core::Type_context context);

  bool test_run_testcase_async_syncvalue(vx_core::Type_context context);

  bool test_run_testcaselist(vx_core::Type_context context);

  bool test_run_testcaselist_async(vx_core::Type_context context);

  bool test_run_testdescribe(vx_core::Type_context context);

  bool test_run_testdescribe_async(vx_core::Type_context context);

  bool test_run_testdescribelist(vx_core::Type_context context);

  bool test_run_testdescribelist_async(vx_core::Type_context context);

  bool test_run_testdescribelist_async_f_list_from_list_async(vx_core::Type_context context);

  bool test_run_testpackage(vx_core::Type_context context);

  bool test_run_testpackage_async(vx_core::Type_context context);

  bool test_run_testpackagelist(vx_core::Type_context context);

  bool test_run_testpackagelist_async(vx_core::Type_context context);

  bool test_run_testresult(vx_core::Type_context context);

  bool test_run_testresult_async(vx_core::Type_context context);

  bool test_tr_from_testdescribe_casename(vx_core::Type_context context);

  bool test_trlist_from_testcase(vx_core::Type_context context);

  bool test_trlist_from_testcaselist(vx_core::Type_context context);

  bool test_write_file(vx_core::Type_context context);

  bool test_write_node(vx_core::Type_context context);

  bool test_write_html(vx_core::Type_context context);

  bool test_write_testpackagelist(vx_core::Type_context context);

  bool test_write_testpackagelist_async(vx_core::Type_context context);

}
#endif
`
	body := "" +
		`#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"
#include "../main/vx/web/html.hpp"

namespace test_lib {

  std::string read_test_file(std::string path, std::string filename) {
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string(path),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(filename)
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string output = string_file->vx_string();
    vx_core::vx_release(string_file);
    return output;
  }

  vx_test::Type_testresult sample_testresult1(vx_core::Type_context context) {
    vx_test::Type_testresult output;
    long irefcount = vx_core::refcount;
    output = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
    vx_core::vx_memory_leak_test("sample_testresult1", irefcount, 2);
    return output;
  }

  vx_test::Type_testresult sample_testresult2(vx_core::Type_context context) {
    vx_test::Type_testresult output;
    long irefcount = vx_core::refcount;
    output = vx_test::f_test_false(
      vx_core::vx_new_boolean(false),
      context
    );
    vx_core::vx_memory_leak_test("sample_testresult2", irefcount, 2);
    return output;
  }

  vx_test::Type_testdescribe sample_testdescribe1(vx_core::Type_context context) {
    vx_test::Type_testdescribe output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testdescribe(), {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      sample_testresult1(context)
    });
    vx_core::vx_memory_leak_test("sample_testdescribe1", irefcount, 5);
    return output;
  }

  vx_test::Type_testdescribe sample_testdescribe2(vx_core::Type_context context) {
    vx_test::Type_testdescribe output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testdescribe(), {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false false)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      sample_testresult2(context)
    });
    vx_core::vx_memory_leak_test("sample_testdescribe2", irefcount, 5);
    return output;
  }

  vx_test::Type_testdescribelist sample_testdescribelist(vx_core::Type_context context) {
    vx_test::Type_testdescribelist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testdescribelist(),
      vx_test::t_testdescribelist()->vx_new_from_list({
        sample_testdescribe1(context),
        sample_testdescribe2(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testdescribelist", irefcount, 11);
    return output;
  }

  vx_test::Type_testcase sample_testcase(vx_core::Type_context context) {
    vx_test::Type_testcase output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean"),
      vx_core::vx_new_string(":describelist"), sample_testdescribelist(context)
    });
    vx_core::vx_memory_leak_test("sample_testcase", irefcount, 14);
    return output;
  }

  vx_test::Type_testcase sample_testcase2(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("float"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4.5 (float 4.5))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_decimal_from_string("4.5"),
              vx_core::f_new(
                vx_core::t_float(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_decimal_from_string("4.5")
                })
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist sample_testcaselist(vx_core::Type_context context) {
    vx_test::Type_testcaselist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list({
        sample_testcase(context),
        sample_testcase2(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testcaselist", irefcount, 26);
    return output;
  }

  vx_test::Type_testpackage sample_testpackage(vx_core::Type_context context) {
    vx_test::Type_testpackage output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":caselist"), sample_testcaselist(context)
    });
    vx_core::vx_memory_leak_test("sample_testpackage", irefcount, 28);
    return output;
  }

  vx_test::Type_testpackagelist sample_testpackagelist(vx_core::Type_context context) {
    vx_test::Type_testpackagelist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testpackagelist(),
      vx_test::t_testpackagelist()->vx_new_from_list({
        sample_testpackage(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testpackagelist", irefcount, 29);
    return output;
  }

	vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::Type_any valexpected = testresult->expected();
    vx_core::Type_any valactual = testresult->actual();
    bool passfail = testresult->passfail()->vx_boolean();
    if (!passfail) {
      //std::string code = testresult->code()->vx_string();
      std::string expected = vx_core::vx_string_from_any(valexpected);
      std::string actual = vx_core::vx_string_from_any(valactual);
      std::string msg = testpkg + "/" + testname + "\n" + message;
      vx_core::vx_debug("--Test Result Fail-- " + msg);
      vx_core::vx_debug("---Expected---\n" + expected);
      vx_core::vx_debug("---Actual---\n" + actual);
      //vx_core::vx_debug(testresult);
      vx_core::vx_debug("");
    }
    return testresult;
  }

  // Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult(), async_testresult);
    vx_test::Type_testresult output = test_lib::run_testresult(testpkg, testname, message, testresult_resolved);
    vx_core::vx_release_except(testresult_resolved, output);
		return output;
  }

  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_reserve(testdescribe);
    vx_core::Type_string testcode = testdescribe->describename();
    std::string message = testcode->vx_string();
    vx_test::Type_testresult testresult = testdescribe->testresult();
    vx_test::Type_testresult testresult_resolved = test_lib::run_testresult(testpkg, casename, message, testresult);
    vx_test::Type_testdescribe output = vx_core::vx_copy(testdescribe, {
      vx_core::vx_new_string(":testresult"), testresult_resolved
    });
    vx_core::vx_release_one_except(testdescribe, output);
		return output;
  }

  // Blocking
  // Only use if running a single testdescribe
  vx_test::Type_testdescribe run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_Type_async async_testdescribe = vx_test::f_resolve_testdescribe(testdescribe);
    vx_test::Type_testdescribe testdescribe_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribe(), async_testdescribe);
    vx_test::Type_testdescribe output = test_lib::run_testdescribe(testpkg, casename, testdescribe_resolved);
		return output;
  }

  vx_test::Type_testdescribelist run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_reserve(testdescribelist);
    std::vector<vx_test::Type_testdescribe> listtestdescribe = testdescribelist->vx_listtestdescribe();
    vx_core::vx_Type_listany listtestdescribe_resolved;
    for (vx_test::Type_testdescribe testdescribe : listtestdescribe) {
      vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe(testpkg, casename, testdescribe);
			listtestdescribe_resolved.push_back(testdescribe_resolved);
    }
		vx_test::Type_testdescribelist output = vx_core::vx_any_from_any(
			vx_test::t_testdescribelist(),
			testdescribelist->vx_new_from_list(listtestdescribe_resolved)
		);
    vx_core::vx_release_one_except(testdescribelist, output);
    return output;
  }

  // Blocking
  // Only use if running a single testdescribelist
  vx_test::Type_testdescribelist run_testdescribelist_async(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_Type_async async_testdescribelist = vx_test::f_resolve_testdescribelist(testdescribelist);
    vx_test::Type_testdescribelist testdescribelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribelist(), async_testdescribelist);
    vx_test::Type_testdescribelist output = test_lib::run_testdescribelist(testpkg, casename, testdescribelist_resolved);
    return output;
  }

  vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase) {
    vx_core::vx_reserve(testcase);
    std::string testpkg = testcase->testpkg()->vx_string();
    std::string casename = testcase->casename()->vx_string();
    vx_test::Type_testdescribelist testdescribelist = testcase->describelist();
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist(testpkg, casename, testdescribelist);
    vx_test::Type_testcase output = vx_core::vx_copy(testcase, {
      vx_core::vx_new_string(":describelist"), testdescribelist_resolved
    });
    vx_core::vx_release_one_except(testcase, output);
		return output;
  }

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase) {
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_test::Type_testcase testcase_resolved = vx_core::vx_sync_from_async(vx_test::t_testcase(), async_testcase);
    vx_test::Type_testcase output = test_lib::run_testcase(testcase_resolved);
		return output;
  }

	vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_reserve(testcaselist);
    std::vector<vx_test::Type_testcase> listtestcase = testcaselist->vx_listtestcase();
    vx_core::vx_Type_listany listtestcase_resolved;
    for (vx_test::Type_testcase testcase : listtestcase) {
      vx_test::Type_testcase testcase_resolved = test_lib::run_testcase(testcase);
			listtestcase_resolved.push_back(testcase_resolved);
    }
		vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
			vx_test::t_testcaselist(),
			testcaselist->vx_new_from_list(listtestcase_resolved)
		);
    vx_core::vx_release_one_except(testcaselist, output);
    return output;
  }

  // Blocking
  // Only use if running a single testcaselist
  vx_test::Type_testcaselist run_testcaselist_async(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_Type_async async_testcaselist = vx_test::f_resolve_testcaselist(testcaselist);
    vx_test::Type_testcaselist testcaselist_resolved = vx_core::vx_sync_from_async(vx_test::t_testcaselist(), async_testcaselist);
    vx_test::Type_testcaselist output = test_lib::run_testcaselist(testcaselist_resolved);
    return output;
  }

  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage) {
    vx_core::vx_reserve(testpackage);
    vx_test::Type_testcaselist testcaselist = testpackage->caselist();
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist(testcaselist);
		vx_test::Type_testpackage output = vx_core::vx_copy(testpackage, {
      vx_core::vx_new_string(":caselist"), testcaselist_resolved
    });
    vx_core::vx_release_one_except(testpackage, output);
		return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage run_testpackage_async(vx_test::Type_testpackage testpackage) {
    vx_core::vx_Type_async async_testpackage = vx_test::f_resolve_testpackage(testpackage);
    vx_test::Type_testpackage testpackage_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackage(), async_testpackage);
    vx_test::Type_testpackage output = test_lib::run_testpackage(testpackage_resolved);
		return output;
  }

  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_reserve(testpackagelist);
    std::vector<vx_test::Type_testpackage> listtestpackage = testpackagelist->vx_listtestpackage();
    vx_core::vx_Type_listany listtestpackage_resolved;
    for (vx_test::Type_testpackage testpackage : listtestpackage) {
      vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage(testpackage);
			listtestpackage_resolved.push_back(testpackage_resolved);
    }
		vx_test::Type_testpackagelist output = vx_core::vx_any_from_any(
			vx_test::t_testpackagelist(),
			testpackagelist->vx_new_from_list(listtestpackage_resolved)
		);
    vx_core::vx_release_one_except(testpackagelist, output);
    return output;
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist(), async_testpackagelist);
    vx_test::Type_testpackagelist output = test_lib::run_testpackagelist(testpackagelist_resolved);
		return output;
  }

  vx_core::Type_boolean write_html(vx_web_html::Type_html htmlnode) {
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(htmlnode);
    vx_data_file::Type_file file = vx_test::f_file_testhtml();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_html);
    return output;
  }

  vx_core::Type_boolean write_node(vx_web_html::Type_html htmlnode) {
    vx_core::Type_string string_node = vx_core::f_string_from_any(htmlnode);
    vx_data_file::Type_file file = vx_test::f_file_testnode();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    return output;
  }

  vx_core::Type_boolean write_testpackagelist(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_core::Type_string string_node = vx_core::f_string_from_any(testpackagelist);
    vx_data_file::Type_file file = vx_test::f_file_test();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    return output;
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_reserve(testpackagelist_resolved);
    vx_core::Type_boolean write_testpackagelist = test_lib::write_testpackagelist(testpackagelist_resolved, context);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_core::vx_release_one(testpackagelist_resolved);
    vx_web_html::Type_html htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_core::vx_reserve(htmlnode);
    vx_core::Type_boolean write_node = test_lib::write_node(htmlnode);
    vx_core::Type_boolean write_html = test_lib::write_html(htmlnode);
    vx_core::vx_release_one(htmlnode);
    vx_core::Type_boolean output = vx_core::vx_new(vx_core::t_boolean(), {
      write_testpackagelist,
      write_node,
      write_html
    });
    return output;
  }

  bool test(std::string testname, std::string expected, std::string actual) {
    bool output = false;
    if (expected == actual) {
      vx_core::vx_debug("Test Pass: " + testname);
      output = true;
    } else {
      vx_core::vx_debug("Test Fail: " + testname);
      vx_core::vx_debug("Expected:\n" + expected);
      vx_core::vx_debug("Actual:\n" + actual);
    }
    return output;
  }

  bool test_helloworld() {
    std::string testname = "test_helloworld";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    std::string expected = "Hello World";
    std::string actual = helloworld->vx_string();
    bool output = test_lib::test(testname, expected, actual);
    vx_core::vx_release(helloworld);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_async_new_from_value() {
    std::string testname = "test_async_new_from_value";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    vx_core::vx_Type_async async = vx_core::vx_async_new_from_value(helloworld);
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string(), async);
    std::string expected = "Hello World";
    std::string actual = sync->vx_string();
    vx_core::vx_release(sync);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_async_from_async_fn() {
    std::string testname = "test_async_from_async_fn";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    vx_core::vx_Type_async async = vx_core::vx_async_new_from_value(helloworld);
    vx_core::vx_Type_async async1 = vx_core::vx_async_from_async_fn(
      async,
      vx_core::t_string(),
      {},
      [](vx_core::Type_any any) {
        return any;
      }
    );
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string(), async1);
    std::string expected = "Hello World";
    std::string actual = sync->vx_string();
    vx_core::vx_release(sync);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_div_from_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_div_from_testcaselist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 94);
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_div_from_testpackage(vx_core::Type_context context) {
    std::string testname = "test_div_from_testpackage";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackage testpackage = sample_testpackage(context);
    vx_web_html::Type_div div = vx_test::f_div_from_testpackage(testpackage);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_div_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_div_from_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_web_html::Type_div div = vx_test::f_div_from_testpackagelist(testpackagelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_html_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_html_from_testpackagelist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".html");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(div);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    std::string actual = string_html->vx_string();
    vx_core::vx_release(string_html);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_node_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_node_from_testpackagelist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 94);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(div);
    std::string actual = vx_core::vx_string_from_any(html);
    vx_core::vx_release(html);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_all(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_core::Type_boolean issuccess = test_lib::write_testpackagelist_async(testpackagelist, context);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(issuccess);
    vx_core::vx_release(issuccess);
    bool output = test_lib::test("Full Test Suite", expected, actual);
    return output;
  }

  bool test_run_testcase(vx_core::Type_context context) {
    std::string testname = "test_run_testcase";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_test::Type_testcase testcase_resolved = test_lib::run_testcase(testcase);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testcase_resolved);
    vx_core::vx_release(testcase_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcase_async(vx_core::Type_context context) {
    std::string testname = "test_run_testcase_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 14);
    vx_test::Type_testcase testcase_resolved = test_lib::run_testcase_async(testcase);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 14);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testcase_resolved);
    vx_core::vx_release(testcase_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcase_async_f_resolvetestcase(vx_core::Type_context context) {
    std::string testname = "test_run_testcase_async_f_resolvetestcase";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_core::vx_memory_leak_test(testname, irefcount, 22);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_async(async_testcase);
    vx_core::vx_release_async(async_testcase);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcase_async_syncvalue(vx_core::Type_context context) {
    std::string testname = "test_run_testcase_async_syncvalue";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname, irefcount, 14);
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_core::vx_memory_leak_test(testname, irefcount, 22);
    vx_core::vx_Type_async async_testdescribelist = async_testcase->async_parent;
    vx_core::vx_Type_listasync list_async_testdescribe = async_testdescribelist->listasync;
    vx_core::vx_Type_async async_testdescribe = list_async_testdescribe[0];
    vx_core::vx_Type_async async_testresult = async_testdescribe->async_parent;
    vx_core::vx_Type_async async_any = async_testresult->async_parent;
    vx_core::Type_any any = async_any->sync_value();
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 22);
    vx_core::Type_any testresult_resolved = async_testresult->sync_value();
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 21);
    vx_core::Type_any testdescribe_resolved = async_testdescribe->sync_value();
    vx_core::vx_memory_leak_test(testname + "-3", irefcount, 21);
    vx_core::Type_any testdescribelist_resolved = async_testdescribelist->sync_value();
    vx_core::vx_memory_leak_test(testname + "-4", irefcount, 19);
    vx_core::Type_any testcase_resolved = async_testcase->sync_value();
    vx_core::vx_memory_leak_test(testname + "-5", irefcount, 15);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testcase_resolved);
    vx_core::vx_release_async(async_testcase);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_run_testcaselist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist(testcaselist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testcaselist_resolved);
    vx_core::vx_release(testcaselist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcaselist_async(vx_core::Type_context context) {
    std::string testname = "test_run_testcaselist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist_async(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 26);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testcaselist_resolved);
    vx_core::vx_release(testcaselist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribe";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = sample_testdescribe1(context);
    vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe("vx/core", "boolean", testdescribe);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribe_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = sample_testdescribe1(context);
    vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe_async("vx/core", "boolean", testdescribe);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribelist(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribelist testdescribelist = sample_testdescribelist(context);
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist("vx/core", "boolean", testdescribelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testdescribelist_resolved);
    vx_core::vx_release(testdescribelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribelist_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribelist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribelist testdescribelist = sample_testdescribelist(context);
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist_async("vx/core", "boolean", testdescribelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testdescribelist_resolved);
    vx_core::vx_release(testdescribelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribelist_async_f_list_from_list_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribelist_async_f_list_from_list_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribelist testdescribelist = sample_testdescribelist(context);
    vx_core::vx_Type_async async_testdescribelist = vx_core::f_list_from_list_async(
      vx_test::t_testdescribelist(),
      testdescribelist,
      vx_test::t_resolve_testdescribe()
    );
    vx_test::Type_testdescribelist testdescribelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribelist(), async_testdescribelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testdescribelist_resolved);
    vx_core::vx_release(testdescribelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackage(vx_core::Type_context context) {
    std::string testname = "test_run_testpackage";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackage testpackage = sample_testpackage(context);
    vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage(testpackage);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testpackage_resolved);
    vx_core::vx_release(testpackage_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackage_async(vx_core::Type_context context) {
    std::string testname = "test_run_testpackage_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackage testpackage = sample_testpackage(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 28);
    vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage_async(testpackage);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 28);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testpackage_resolved);
    vx_core::vx_release(testpackage_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_run_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist(testpackagelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::vx_release(testpackagelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackagelist_async(vx_core::Type_context context) {
    std::string testname = "test_run_testpackagelist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 29);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 29);
    std::string actual = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::vx_release(testpackagelist_resolved);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult(vx_core::Type_context context) {
    std::string testname = "test_run_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_test::Type_testresult testresult_resolved = run_testresult("vx/core", "boolean", "", testresult);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_anyfromfunc(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_anyfromfunc";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Func_any_from_func anyfromfunc = vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
      vx_core::Type_any output_1 = testresult;
      return output_1;
    });
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(anyfromfunc);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult_async(vx_core::Type_context context) {
    std::string testname = "test_run_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_test::Type_testresult testresult_resolved = test_lib::run_testresult_async("vx/core", "boolean", "", testresult);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_f_resolve_testresult(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_f_resolve_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 2);
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 4);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult(), async_testresult);
    vx_core::vx_memory_leak_test(testname + "-3", irefcount, 2);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_f_resolve_testresult_async(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_f_resolve_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 2);
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 4);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_async(async_testresult);
    vx_core::vx_release_async(async_testresult);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_if(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_if";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_any output_2 = vx_core::f_if_2(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_then(
          vx_core::t_boolean_from_func()->vx_fn_new({fn_actual}, [fn_actual]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
            return output_1;
          }),
          vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
            vx_core::Type_any output_1 = testresult;
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
            vx_test::Type_testresult output_1 = vx_core::f_let(
              vx_test::t_testresult(),
              vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
                vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
                vx_core::vx_ref_plus(passfail);
                vx_test::Type_testresult output_1 = vx_core::f_copy(
                  testresult,
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":passfail"),
                    passfail,
                    vx_core::vx_new_string(":actual"),
                    actual
                  })
                );
                vx_core::vx_release_one_except(passfail, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(output_2);
    vx_core::vx_release(output_2);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_then(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_then";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_thenelse thenelse = vx_core::f_then(
      vx_core::t_boolean_from_func()->vx_fn_new({fn_actual}, [fn_actual]() {
        vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
        return output_1;
      }),
      vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
        vx_core::Type_any output_1 = testresult;
        return output_1;
      })
    );
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelse);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_thenelselist(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_thenelselist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_thenelselist thenelselist = vx_core::vx_new(vx_core::t_thenelselist(), {
      vx_core::f_then(
        vx_core::t_boolean_from_func()->vx_fn_new({fn_actual}, [fn_actual]() {
          vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
          return output_1;
        }),
        vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
          vx_core::Type_any output_1 = testresult;
          return output_1;
        })
      ),
      vx_core::f_else(
        vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
          vx_test::Type_testresult output_1 = vx_core::f_let(
            vx_test::t_testresult(),
            vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
              vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
              vx_core::vx_ref_plus(passfail);
              vx_test::Type_testresult output_1 = vx_core::f_copy(
                testresult,
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":passfail"),
                  passfail,
                  vx_core::vx_new_string(":actual"),
                  actual
                })
              );
              vx_core::vx_release_one_except(passfail, output_1);
              return output_1;
            })
          );
          return output_1;
        })
      )
    });
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelselist);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_pathfull_from_file(vx_core::Type_context context) {
    std::string testname = "test_pathfull_from_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string("string_read_from_file.txt")
    });
    vx_core::Type_string string_path = vx_data_file::f_pathfull_from_file(file);
    std::string expected = "src/test/resources/vx/string_read_from_file.txt";
    std::string actual = string_path->vx_string();
    vx_core::vx_release(string_path);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_read_file(vx_core::Type_context context) {
    std::string testname = "test_read_file";
    long irefcount = vx_core::refcount;
    std::string expected = "testdata";
    std::string actual = read_test_file("src/test/resources/vx", "string_read_from_file.txt");
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_tr_from_testdescribe_casename(vx_core::Type_context context) {
    std::string testname = "test_tr_from_testdescribe_casename";
    long irefcount = vx_core::refcount;
    vx_core::Type_string casename = vx_core::vx_new_string("vx/core/boolean");
    vx_test::Type_testdescribe testdescribe = sample_testdescribe1(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 6);
    vx_web_html::Type_tr tr = vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 22);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(tr);
    vx_core::vx_release(tr);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_trlist_from_testcase(vx_core::Type_context context) {
    std::string testname = "test_trlist_from_testcase";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 14);
    vx_web_html::Type_trlist trlist = vx_test::f_trlist_from_testcase(testcase);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 44);
    std::string actual = vx_core::vx_string_from_any(trlist);
    vx_core::vx_release(trlist);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_trlist_from_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_trlist_from_testcaselist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_web_html::Type_trlist trlist = vx_test::f_trlist_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 66);
    std::string actual = vx_core::vx_string_from_any(trlist);
    vx_core::vx_release(trlist);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_file(vx_core::Type_context context) {
    std::string testname = "test_write_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string("boolean_write_from_file_string.txt")
    });
    vx_core::Type_string string_file = vx_core::vx_new_string("writetext");
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file, string_file);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    vx_core::vx_release(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_node(vx_core::Type_context context) {
    std::string testname = "test_write_node";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::Type_string string_node = vx_core::f_string_from_any(testpackagelist);
    vx_data_file::Type_file file = vx_test::f_file_testnode();
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    vx_core::vx_release(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_html(vx_core::Type_context context) {
    std::string testname = "test_write_html";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 29);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(divtest);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    vx_data_file::Type_file file_html = vx_test::f_file_testhtml();
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file_html, string_html);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    vx_core::vx_release(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_write_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::Type_string string_vxlsp = vx_core::f_string_from_any(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 1);
    vx_data_file::Type_file file = vx_test::f_file_test();
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file, string_vxlsp);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    vx_core::vx_release(boolean_write);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_testpackagelist_async(vx_core::Type_context context) {
    std::string testname = "test_write_testpackagelist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 29);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 29);
    std::string snode = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::Type_string string_node = vx_core::vx_new_string(snode);
    vx_data_file::Type_file file_node = vx_test::f_file_testnode();
    vx_core::Type_boolean boolean_writenode = vx_data_file::vx_boolean_write_from_file_string(file_node, string_node);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_writenode);
    bool output = test_lib::test(testname + "-1", expected, actual);
    vx_data_file::Type_file file_html = vx_test::f_file_testhtml();
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(divtest);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    vx_core::Type_boolean boolean_writehtml = vx_data_file::vx_boolean_write_from_file_string(file_html, string_html);
    std::string expected1 = "true";
    std::string actual1 = vx_core::vx_string_from_any(boolean_writehtml);
    output = output && test_lib::test(testname + "-2", expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

}
`
	return body, header
}
