package vxlisp

import (
	"strings"
)

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
				lineindent + "vx_core::Type_constdef::vx_constdef_new(" +
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
	output := "" +
		"  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (func " + fnc.name + ")" +
		"\n   */"
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
	case ":test":
		file := NewFile()
		file.name = "app_test.cpp"
		file.path = cmdpath + "/vx"
		file.text = CppAppTest(project, "")
		files = append(files, file)
		file = NewFile()
		file.name = "test_lib.cpp"
		file.path = cmdpath + "/vx"
		file.text = CppTestLib()
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
			text, _, msgs := CppTestFromPackage(pkg, project)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + "_test.cpp"
			file.path = cmdpath + "/" + pkgpath
			file.text = text
			files = append(files, file)
		}
	}
	return files, msgblock
}

func CppFromConst(cnst *vxconst, pkg *vxpackage) (string, string, *vxmsgblock) {
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
	cnstclassname := "Const_" + cnstname
	cnsttypename := CppNameFromType(cnst.vxtype)
	cnsttypeclassname := CppNameTypeFullFromType(cnsttype)
	pkgname := CppNameFromPkgName(cnst.pkgname)
	initval := ""
	const_new := ""
	cnstval := StringValueFromValue(cnst.value)
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
		cnstval = "\n      this->vx_p_boolean = " + cnstval + ";"
		initval = "" +
			"\n    bool " + cnsttypeclassname + "::vx_boolean() {" +
			cnstval +
			"\n      return this->vx_p_boolean;" +
			"\n    }"
	case "vx/core/decimal":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this->vx_p_decimal = " + cnstval + ";"
		initval = "" +
			"\n    std::string " + cnsttypeclassname + "::vx_decimal() {" +
			cnstval +
			"\n      return this->vx_p_decimal;" +
			"\n    }"
	case "vx/core/float":
		if cnstval == "" {
			cnstval = "f0"
		}
		cnstval = "\n      this->vx_p_float = " + cnstval + ";"
		initval = "" +
			"\n    float " + cnsttypeclassname + "::vx_float() {" +
			cnstval +
			"\n      return this->vx_p_float;" +
			"\n    }"
	case "vx/core/int":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this->vx_p_int = " + cnstval + ";"
		initval = "" +
			"\n    int " + cnsttypeclassname + "::vx_int() {" +
			cnstval +
			"\n      return this->vx_p_int;" +
			"\n    }"
	case "vx/core/string":
		cnstval = "\n      this->vx_p_string = " + cnstval + ";"
		initval = "" +
			"\n    std::string " + cnsttypeclassname + "::vx_string() {" +
			cnstval +
			"\n      return this->vx_p_string;" +
			"\n    }"
	default:
		switch cnsttype.extends {
		case ":list":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				listtypename := cnsttypename
				if listtypename == "any" {
					listtypename = ""
				}
				const_new += "" +
					"\n      " + cnsttypeclassname + "* val = " + clstext + ";" +
					"\n      output->vx_p_list" + listtypename + " = val->vx_list" + listtypename + "();"
			}
		case ":map":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				maptypename := cnsttypename
				if maptypename == "any" {
					maptypename = ""
				}
				const_new += "" +
					"\n      " + cnsttypeclassname + "* val = " + clstext + ";" +
					"\n      output->vx_p_map" + maptypename + " = val->vx_map" + maptypename + "();"
			}
		case ":struct":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					"\n      " + cnsttypeclassname + "* val = " + clstext + ";"
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						"\n      output->vx_p_" + CppFromName(prop.name) + " = val->" + CppFromName(prop.name) + "();"

				}
			}
			/*
				clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "        ", true, false, path)
				msgblock = MsgBlockAddBlock(msgblock, msgs)
				if clstext != "" {
					cnstval = "" +
						"\n      if ((this->vx_p_map == null) || (this->vx_p_map.size() == 0)) {" +
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
	extends := CppNameTypeFullFromType(cnsttype)
	headers := "" +
		"\n  // (const " + cnst.name + ")" +
		"\n  class " + cnstclassname + " : public " + extends + " {" +
		"\n  public:" +
		"\n    vx_core::Type_constdef* vx_constdef();" +
		"\n    static " + cnstclassname + "* vx_const_new();" +
		"\n  };" +
		//"\n  extern " + cnstclassname + "* c_" + cnstname + ";" +
		"\n"
	output := "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  //class " + cnstclassname + " {" +
		"\n" +
		"\n    // vx_constdef()" +
		"\n    vx_core::Type_constdef* " + pkgname + "::" + cnstclassname + "::vx_constdef() {" +
		"\n      return vx_core::Type_constdef::vx_constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + CppTypeDefFromType(cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    // vx_const_new()" +
		"\n    " + pkgname + "::" + cnstclassname + "* " + pkgname + "::" + cnstclassname + "::vx_const_new() {" +
		"\n      " + pkgname + "::" + cnstclassname + "* output = new " + pkgname + "::" + cnstclassname + "();" +
		const_new +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		initval +
		"\n" +
		"\n  //}" +
		"\n" +
		"\n  " + pkgname + "::" + cnstclassname + "* " + pkgname + "::c_" + cnstname + " = " + pkgname + "::" + cnstclassname + "::vx_const_new();" +
		"\n" +
		"\n"
	return output, headers, msgblock
}

func CppFromFunc(fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFromFunc")
	var listargtype []string
	var listargname []string
	funcname := CppFromName(fnc.alias) + CppIndexFromFunc(fnc)
	returntype := ""
	if fnc.generictype == nil {
		returntype = CppGenericFromType(fnc.vxtype)
	} else {
		returntype = CppGenericFromType(fnc.generictype)
	}
	pkgname := CppNameFromPkgName(fnc.pkgname)
	instancevars := ""
	staticvars := ""
	instancefuncs := ""
	staticfuncs := ""
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
			argtext := "T* generic_any_1"
			listargtype = append(listargtype, argtext)
		default:
			if fnc.generictype != nil {
				genericargname := CppNameTFromTypeGeneric(fnc.generictype)
				argtext := CppGenericFromType(fnc.generictype) + "* " + genericargname
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, genericargname)
			}
		}
	}
	switch NameFromFunc(fnc) {
	case "vx/core/let":
		argtext := "vx_core::Func_any_from_func* fn_any"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any")
	case "vx/core/let-async":
		argtext := "vx_core::Func_any_from_func_async* fn_any_async"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any_async")
	default:
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if fnc.generictype != nil && argtype.isgeneric {
				argtypename = CppGenericFromType(argtype)
			} else {
				argtypename = CppNameTypeFromType(argtype)
			}
			argtext := argtypename + "* " + CppFromName(arg.alias)
			listargname = append(listargname, CppFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	if fnc.context {
		listargtype = append(listargtype, "vx_core::Type_context* context")
		listargname = append(listargname, "context")
	}
	//var funcgenerics []string
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = CppGenericFromType(fnc.generictype) + "*"
	} else {
		functypetext = returntype + "*"
	}
	if fnc.async {
		functypetext = "vx_core::Async<" + functypetext + ">*"
	}
	contextarg := ""
	if fnc.context {
		contextarg = ", vx_core::Type_context* context"
	}
	fullfuncname := pkgname + "::Func_" + funcname
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-context", "vx/core/any<-func",
		"vx/core/any<-none", "vx/core/any<-key-value",
		"vx/core/any<-reduce", "vx/core/any<-reduce-next":
		instancevars += "" +
			"\n    " + fullfuncname + "* " + fullfuncname + "::fn_new(vx_core::Func_" + funcname + "::IFn fn) {" +
			"\n      " + fullfuncname + "* output;" +
			"\n      output->fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async",
		"vx/core/any<-none-async", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce-async", "vx/core/any<-reduce-next-async":
		instancevars += "" +
			"\n    // static" +
			"\n    " + fullfuncname + "* " + fullfuncname + "::fn_new(vx_core::Func_" + funcname + "::IFn fn) {" +
			"\n      " + fullfuncname + "* output;" +
			"\n      output->fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		instancefuncs += "" +
			"\n    " + fullfuncname + "* " + fullfuncname + "::fn_new(vx_core::Func_any_from_func::IFn fn) {" +
			"\n      " + fullfuncname + "* output;" +
			"\n      output->fn = fn;" +
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
							"\n      T* inputval = vx_core::f_any_from_any(generic_any_1, value);" +
							"\n      vx_core::Async<T*>* output = vx_core::f_async(generic_any_1, inputval);"
					} else {
						asyncbody += "" +
							"\n      " + CppNameTypeFromType(arg.vxtype) + "* inputval = vx_core::f_any_from_any(" + CppNameTFromType(arg.vxtype) + ", value);" +
							"\n      vx_core::Async<" + returntype + "*>* future = " + pkgname + "::f_" + funcname + "(" + subargnames + ");" +
							"\n      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;"
					}
					instancefuncs += "" +
						"\n    vx_core::Func_any_from_any" + contextname + "_async* " + fullfuncname + "::fn_new(vx_core::Func_any_from_any" + contextname + "_async::IFn fn) {return vx_core::e_any_from_any" + contextname + "_async;}" +
						"\n" +
						"\n    template <class T, class U> vx_core::Async<T*>* " + fullfuncname + "::f_any_from_any" + contextname + "_async(T* generic_any_1, U* value" + contextarg + ") {" +
						asyncbody +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					instancefuncs += "" +
						"\n    vx_core::Func_any_from_any" + contextname + "* " + fullfuncname + "::fn_new(vx_core::Func_any_from_any" + contextname + "::IFn fn) {return vx_core::e_any_from_any" + contextname + ";}" +
						"\n" +
						"\n    template <class T, class U> T* " + fullfuncname + "::f_any_from_any" + contextname + "(T* generic_any_1, U* value" + contextarg + ") {" +
						"\n      T* output = vx_core::f_empty(generic_any_1);" +
						"\n      " + argtypename + "* inputval = (" + argtypename + ")value;" +
						"\n      vx_core::Type_any* outputval = " + pkgname + "::f_" + funcname + "(" + subargnames + ");" +
						"\n      output = vx_core::f_any_from_any(generic_any_1, outputval);" +
						"\n      return output;" +
						"\n    }" +
						"\n"
				}
			}
		}
	}
	repltext := CppReplFromFunc(fnc)
	instancefuncs += repltext
	valuetext, msgs := CppFromValue(fnc.value, fnc.pkgname, fnc, "", true, false, path)
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
		permissiontop = lineindent + "if (vx_core::f_boolean_permission_from_any(" + CppNameTFromFunc(fnc) + ", context)) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			lineindent + "  vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"Permission Denied: " + fnc.name + "\");" +
			lineindent + "  output = output->vx_copy(msg);" +
			lineindent + "}"
		indent += "  "
	}
	if fnc.messages {
		msgtop = lineindent + "try {"
		msgbottom = "" +
			lineindent + "} catch (std::exception err) {" +
			lineindent + "  vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception(\"" + fnc.name + "\", err);" +
			lineindent + "  output = output->vx_copy(msg);" +
			lineindent + "}"
		indent += "  "
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
		valuetext = "\n" + indent + StringFromStringIndent(valuetext, indent)
	}
	debugtop, debugbottom := CppDebugFromFunc(fnc, lineindent)
	returnvalue := ""
	interfacefn := CppHeaderFnFromFunc(fnc)
	if interfacefn == "" {
		if returntype != "void" {
			returnvalue += "\n      return "
		}
		returnvalue += pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");"
	} else if fnc.async {
		returnvalue += "" +
			"\n      vx_core::Async<T*>* output;" +
			"\n      if (fn == NULL) {" +
			"\n        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));" +
			"\n      } else {" +
			"\n        vx_core::Async<vx_core::Type_any*>* future = fn(" + strings.Join(listargname, ", ") + ");" +
			"\n        output = vx_core::async_from_async(generic_any_1, future);" +
			"\n      }" +
			"\n      return output;"
	} else {
		if BooleanFromStringStarts(fnc.name, "boolean<-") {
			returnvalue += "" +
				"\n      vx_core::Type_boolean* output = vx_core::c_false;" +
				"\n      if (fn != NULL) {" +
				"\n        output = vx_core::f_any_from_any(vx_core::t_boolean, fn(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "int<-") {
			returnvalue += "" +
				"\n      vx_core::Type_int* output = vx_core::e_int;" +
				"\n      if (fn != NULL) {" +
				"\n        output = vx_core::f_any_from_any(vx_core::t_int, fn(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "string<-") {
			returnvalue += "" +
				"\n      vx_core::Type_string* output = vx_core::e_string;" +
				"\n      if (fn != NULL) {" +
				"\n        output = vx_core::f_any_from_any(vx_core::t_string, fn(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		} else {
			returnvalue += "" +
				"\n      T* output = vx_core::f_empty(generic_any_1);" +
				"\n      if (fn != NULL) {" +
				"\n        output = vx_core::f_any_from_any(generic_any_1, fn(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		}
		if returntype != "void" {
			returnvalue += "\n      return output;"
		}
	}
	after := ""
	if fnc.vxtype.name == "none" {
	} else {
		after += lineindent + "return output;"
	}
	after += "\n  }\n\n"
	defaultvalue := ""
	switch NameFromFunc(fnc) {
	case "vx/core/new", "vx/core/copy", "vx/core/empty":
	default:
		if fnc.vxtype.name == "none" {
		} else if fnc.async {
			defaultvalue = lineindent + "vx_core::Async<" + returntype + "*>* output = vx_core::async_new_from_val(" + CppNameEFromType(fnc.vxtype) + ");"
		} else if fnc.generictype != nil {
			defaultvalue = lineindent + returntype + "* output = vx_core::f_empty(" + CppNameTFromTypeGeneric(fnc.generictype) + ");"
		} else {
			defaultvalue = lineindent + returntype + "* output = " + CppNameEFromType(fnc.vxtype) + ";"
		}
	}
	doc := CppDocFromFunc(fnc)
	output := "" +
		doc +
		"\n  //class Func_" + funcname + " {" +
		"\n" +
		instancevars +
		"\n    template<class... Args> " + fullfuncname + "* " + fullfuncname + "::vx_new(Args*... args) {" +
		"\n      " + pkgname + "::Func_" + funcname + "* output;" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    template<class... Args> " + fullfuncname + "* " + fullfuncname + "::vx_copy(Args*... args) {" +
		"\n      " + pkgname + "::Func_" + funcname + "* output;" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_typedef* " + fullfuncname + "::vx_typedef() {return " + pkgname + "::t_" + funcname + "->vx_typedef();}" +
		"\n" +
		"\n    vx_core::Type_funcdef* " + fullfuncname + "::vx_funcdef() {" +
		"\n      return vx_core::Type_funcdef::vx_funcdef_new(" +
		"\n        \"" + fnc.pkgname + "\", // pkgname" +
		"\n        \"" + fnc.name + "\", // name" +
		"\n        " + StringFromInt(fnc.idx) + ", // idx" +
		"\n        " + StringFromBoolean(fnc.async) + ", // async" +
		"\n        " + CppTypeDefFromType(fnc.vxtype, "        ") + " // typedef" +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    " + fullfuncname + "* " + fullfuncname + "::vx_empty() {return " + pkgname + "::e_" + funcname + ";}" +
		"\n    " + fullfuncname + "* " + fullfuncname + "::vx_type() {return " + pkgname + "::t_" + funcname + ";}" +
		"\n" +
		staticvars +
		instancefuncs +
		"\n    " + genericdefinition + functypetext + " " + fullfuncname + "::vx_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		staticfuncs +
		returnvalue +
		"\n    }" +
		"\n" +
		"\n  //}" +
		"\n" +
		"\n  " + fullfuncname + "* " + pkgname + "::e_" + funcname + " = new " + fullfuncname + "();" +
		"\n  " + fullfuncname + "* " + pkgname + "::t_" + funcname + " = new " + fullfuncname + "();" +
		"\n" +
		"\n  " + genericdefinition + functypetext + " " + pkgname + "::f_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		debugtop +
		defaultvalue +
		permissiontop +
		msgtop +
		valuetext +
		msgbottom +
		permissionbottom +
		debugbottom +
		after
	return output, msgblock
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
	/*
		switch pkg.name {
		case "vx/core1":
			specialheader = ""
			specialbody = "" +
			specialcode = "" +
				"\n" +
				"\n  class KeyValue<T> {" +
				"\n    std::string key = \"\";" +
				"\n    T value = null;" +
				"\n  }" +
				"\n" +
				"\n  vx_core::Type_any[] arrayany_from_anylist(vx_core::Type_anylist* list) {" +
				"\n    return list->vx_list().toArray(new vx_core::Type_any[0]);" +
				"\n  }" +
				"\n" +
				"\n  <T> std::vector<T*> arraylist_from_array(T* items...) {" +
				"\n    std::vector<T*> output = new std::vector<T>(Arrays.asList(items));" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T extends vx_core::Type_any, U extends vx_core::Type_any> std::vector<T*> arraylist_from_arraylist(T* generic_any_1, std::vector<U*> listval) {" +
				"\n    std::vector<T*> output;" +
				"\n    for (vx_core::Type_any value : listval) {" +
				"\n      T t_val = vx_core::f_any_from_any(generic_any_1, value);" +
				"\n      output.push_back(t_val);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T, U> std::vector<T*> arraylist_from_arraylist_fn(std::vector<U*> listval, Function<U*, T*> fn_any_from_any) {" +
				"\n    std::vector<*> output;" +
				"\n    for (U* value_u : listval) {" +
				"\n      T* t_val = fn_any_from_any->apply(value_u);" +
				"\n      output.push_back(t_val);" +
				"\n    }" +
				"\n    output = vx_core::immutablelist(output);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T extends vx_core::Type_any, U extends vx_core::Type_any> std::vector<T> arraylist_from_linkedhashmap(T generic_any_1, std::map<std::string, U> mapval) {" +
				"\n    std::vector<T> output = new std::vector<T>();" +
				"\n    std::set<std:string> keys = mapval.keySet();" +
				"\n    for (std::string key : keys) {" +
				"\n      U u_val = mapval.get(key);" +
				"\n      T t_val = vx_core::f_any_from_any(generic_any_1, u_val);" +
				"\n      output.push_back(t_val);" +
				"\n    }" +
				"\n    output = vx_core::immutablelist(output);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T, U> std::vector<T> arraylist_from_linkedhashmap_fn(std::map<std::string, U> mapval, BiFunction<String, U, T> fn_any_from_key_value) {" +
				"\n    std::vector<T> output = new std::vector<T>();" +
				"\n    std::set<std::string> keys = mapval.keySet();" +
				"\n    for (std::string key : keys) {" +
				"\n      U u_val = mapval.get(key);" +
				"\n      T t_val = fn_any_from_key_value.apply(key, u_val);" +
				"\n      output.push_back(t_val);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T> vx_core::Async<std::vector<T>> async_arraylist_from_arraylist_async(std::vector<vx_core::Async<T>> list_future) {" +
				"\n    vx_core::Async<Void> allFutures = vx_core::Async.allOf(" +
				"\n      list_future.toArray(new vx_core::Async[list_future.size()])" +
				"\n    );" +
				"\n    vx_core::Async<std::vector<T*>> output = allFutures.thenApply(v -> {" +
				"\n      std::vector<T*> list = list_future.stream()" +
				"\n        .map(future -> future.join())" +
				"\n        .collect(Collectors.toList());" +
				"\n      return vx_core::immutablelist(list);" +
				"\n    });" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  void debug(std::any* values...) {" +
				"\n    for (std::any* value : values) {" +
				"\n      std::string text = \"\";" +
				"\n      if (value == null) {" +
				"\n        text = \"null\";" +
				"\n      } else if (value == vx_core::t_any) {" +
				"\n        vx_core::Type_any* val_any = (vx_core::Type_any)value;" +
				"\n        vx_core::Type_string* valstring = vx_core::f_string_from_any(val_any);" +
				"\n        text = valstring->vx_string();" +
				"\n      } else {" +
				"\n        text = vx_core::string_from_any(value);" +
				"\n      }" +
				"\n      System.out.println(text);" +
				"\n    }" +
				"\n  }" +
				"\n" +
				"\n  <T> LinkedHashstd::map<std::string, T> hashmap_from_keyvalues(KeyValue<T> keyvalues...) {" +
				"\n    LinkedHashstd::map<std::string, T> output = new LinkedHashstd::map<std::string, T>();" +
				"\n    for (KeyValue<T> keyvalue : keyvalues) {" +
				"\n      std::string key = keyvalue.key;" +
				"\n      T value = keyvalue.value;" +
				"\n      output[key] = value;" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T> KeyValue<T> keyvalue_from_key_value(std::string key, T value) {" +
				"\n    KeyValue<T> output;" +
				"\n    output.key = key;" +
				"\n    output.value = value;" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T*> std::map<std::string, T*> map_from_list_fn(std::vector<T*> listval, Function<T*, vx_core::Type_string> fn_any_from_any) {" +
				"\n    std::map<std::string, T*> output;" +
				"\n    for (T* val : listval) {" +
				"\n      vx_core::Type_string valkey = fn_any_from_any->apply(val);" +
				"\n      std::string key = valkey->vx_string();" +
				"\n      output[key] = val;" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  <T extends vx_core::Type_any> LinkedHashstd::map<std::string, T> map_from_map(LinkedHashstd::map<std::string, vx_core::Type_any> mapval) {" +
				"\n    LinkedHashstd::map<std::string, T> output;" +
				"\n    std::set<std::string> keys = mapval.keySet();" +
				"\n    for (std::string key : keys) {" +
				"\n      vx_core::Type_any value = mapval.get(key);" +
				"\n      try {" +
				"\n        @SuppressWarnings(\"unchecked\")" +
				"\n        T castval = (T)value;" +
				"\n        output[key] = castval;" +
				"\n      } catch (Exception ex) {" +
				"\n        vx_core::debug(\"std::map<-map\", ex);" +
				"\n      }" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  // Warning!: Blocking" +
				"\n  <T extends vx_core::Type_any> T sync_from_async(T generic_any_1, vx_core::Async<T> future) {" +
				"\n    T output = vx_core::f_empty(generic_any_1);" +
				"\n    try {" +
				"\n      output = future.get();" +
				"\n    } catch (Exception e) {" +
				"\n      vx_core::Type_msg* msg = vx_core::t_msg->vx_new_from_exception(\"sync<-async\", e);" +
				"\n      vx_core::Type_any* val = generic_any_1->vx_new(msg);" +
				"\n      output = vx_core::f_any_from_any(generic_any_1, val);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
		}
	*/
	forwardheader := "\n  // forward declarations"
	typkeys := ListKeyFromMapType(pkg.maptype)
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typename := CppFromName(typ.alias)
		forwardheader += "" +
			"\n  class Type_" + typename + ";" +
			"\n  extern Type_" + typename + "* e_" + typename + ";" +
			"\n  extern Type_" + typename + "* t_" + typename + ";"
	}
	for _, constid := range cnstkeys {
		cnst := pkg.mapconst[constid]
		constname := CppFromName(cnst.alias)
		forwardheader += "" +
			"\n  class Const_" + constname + ";" +
			"\n  extern Const_" + constname + "* c_" + constname + ";"
	}
	for _, funcid := range fnckeys {
		fncs := pkg.mapfunc[funcid]
		for _, fnc := range fncs {
			funcname := CppFromName(fnc.alias)
			forwardheader += "" +
				"\n  class Func_" + funcname + ";" +
				"\n  extern Func_" + funcname + "* e_" + funcname + ";" +
				"\n  extern Func_" + funcname + "* t_" + funcname + ";"
		}
	}
	typeheaders := ""
	typetexts := ""
	for _, typid := range specialtypeorder {
		if typid != "" {
			typ, ok := pkg.maptype[typid]
			if !ok {
				msg := NewMsg(":headertype type not found: " + pkg.name + "/" + typid)
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				typeheader := CppHeaderFromType(typ)
				typetext, msgs := CppFromType(typ)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				typetexts += typetext
				specialheader += typeheader
			}
		}
	}
	remainingkeys := ListStringFromListStringNotMatch(typkeys, specialtypeorder)
	for _, typid := range remainingkeys {
		typ := pkg.maptype[typid]
		typeheader := CppHeaderFromType(typ)
		typetext, msgs := CppFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typetexts += typetext
		typeheaders += typeheader
	}
	constheaders := ""
	consttexts := ""
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, constheader, msgs := CppFromConst(cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
		constheaders += constheader
	}
	funcheaders := ""
	funcheaderfooters := ""
	functexts := ""
	for _, fncid := range specialfuncorder {
		if fncid != "" {
			fncs, ok := pkg.mapfunc[fncid]
			if !ok {
				msg := NewMsg(":headerfunc func not found: " + pkg.name + "/" + fncid)
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				for _, fnc := range fncs {
					fncheader, fncheaderfooter := CppHeaderFromFunc(fnc)
					fnctext, msgs := CppFromFunc(fnc)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					functexts += fnctext
					specialheader += fncheader
					funcheaderfooters += fncheaderfooter
				}
			}
		}
	}
	remainingkeys = ListStringFromListStringNotMatch(fnckeys, specialfuncorder)
	for _, fncid := range remainingkeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fncheader, fncheaderfooter := CppHeaderFromFunc(fnc)
			fnctext, msgs := CppFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			functexts += fnctext
			funcheaders += fncheader
			funcheaderfooters += fncheaderfooter
		}
	}
	body := "" +
		specialbody +
		"\n" +
		typetexts +
		consttexts +
		functexts
		//		emptytypes
	imports := CppImportsFromPackage(pkg, "", body, false)
	headertext := "" +
		"#pragma once" +
		"\n" +
		imports +
		"\nnamespace " + pkgname + " {" +
		"\n" +
		forwardheader +
		"\n" +
		"\n" +
		specialfirst +
		specialheader +
		typeheaders +
		constheaders +
		funcheaders +
		funcheaderfooters +
		"\n}" +
		"\n"
	output := "" +
		imports +
		"#include \"" + pkg.name + ".hpp\"" +
		"\n" +
		"\n//namespace " + pkgname + " {" +
		body +
		"\n//}" +
		"\n"
	return output, headertext, msgblock
}

func CppFromText(text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	return output
}

func CppFromType(typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFromType")
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
	fulltypename := pkgname + "::Type_" + typename
	instancefuncs := ""
	createtext, msgs := CppFromValue(typ.createvalue, "", emptyfunc, "", true, false, path)
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
			"\n      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
	case "vx/core/anytype":
	case "vx/core/const":
	case "vx/core/list":
		instancefuncs += "" +
			"\n" +
			"\n    template <class T> std::vector<T*> " + fulltypename + "::vx_any(T* generic_any_1) {" +
			"\n      return vx_core::arraylist_from_arraylist(generic_any_1, this->vx_list());" +
			"\n    }" +
			"\n" +
			"\n    template <class T> T* " + fulltypename + "::vx_any_from_list(T* generic_any_1, int index) {" +
			"\n      return vx_any_from_list(generic_any_1, this->vx_list(), index);" +
			"\n    }" +
			"\n"
		staticfuncs = "" +
			"\n    template <class T> std::vector<T*> " + fulltypename + "::list_new(T* generic_any_1, vx_core::Type_any* vals...) {" +
			"\n      std::vector<vx_core::Type_any*> listval = Arrays.asList(vals);" +
			"\n      return vx_core::arraylist_from_arraylist(generic_any_1, listval);" +
			"\n    }" +
			"\n" +
			"\n    template <class T> T* " + fulltypename + "::vx_any_from_list(T* generic_any_1, std::vector<vx_core::Type_any*> list, int index) {" +
			"\n      T* output = vx_core::f_empty(generic_any_1);" +
			"\n      if (list.size() > index) {" +
			"\n        output = vx_core::f_any_from_any(generic_any_1, list[index]);" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    template <class T> T* " + fulltypename + "::vx_any_first_from_list_fn(T* generic_any_1, vx_core::Type_list* list, Function<vx_core::Type_any*, T*> fn_any) {" +
			"\n      T* output = vx_core::f_empty(generic_any_1);" +
			"\n      std::vector<vx_core::Type_any*> listany = list->vx_list();" +
			"\n      for (vx_core::Type_any* any : listany) {" +
			"\n        T* tany = vx_core::f_any_from_any(generic_any_1, any);" +
			"\n        T* val = fn_any->apply(tany);" +
			"\n        if (val != NULL) {" +
			"\n          output = val;" +
			"\n          break;" +
			"\n        }" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/map":
	case "vx/core/struct":
	case "vx/core/func":
		instancefuncs += "" +
			"\n    vx_core::Type_funcdef* " + fulltypename + "::vx_funcdef() {" +
			"\n      return vx_core::e_funcdef;" +
			"\n    }"
	case "vx/core/type":
	case "vx/core/boolean":
		valcopy = "" +
			"\n      vx_core::Type_boolean* val = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output->vx_p_boolean = val->vx_boolean();"
		valnew = "" +
			"\n      bool booleanval = false;" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_boolean) {" +
			"\n          vx_core::Type_boolean* valboolean = vx_core::any_from_any(vx_core::t_boolean, valsub);" +
			"\n          booleanval = booleanval || valboolean->vx_boolean();" +
			"\n        } else if (valsubtype == vx_core::t_nativeboolean) {" +
			"\n          booleanval = booleanval || vx_core::any_from_any(true, valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_boolean = booleanval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
	case "vx/core/decimal":
		valcopy = "" +
			"\n      vx_core::Type_decimal* val = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output->vx_p_decimal = val->vx_string();"
		valnew = "" +
			"\n      std::string sval = \"\";" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_string) {" +
			"\n          vx_core::Type_string* valstring = vx_core::any_from_any(vx_core::t_string, valsub);" +
			"\n          sval = valstring->vx_string();" +
			"\n        } else if (valsubtype == vx_core::t_nativestring) {" +
			"\n          sval = vx_core::any_from_any(\"\", valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_decimal = sval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
	case "vx/core/float":
		valcopy = "" +
			"\n      vx_core::Type_float* val = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output->vx_p_float = val->vx_float();"
		valnew = "" +
			"\n      float floatval = 0;" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype =- vx_core::t_decimal) {" +
			"\n          vx_core::Type_decimal* valnum = vx_core::any_from_any(vx_core::t_decimal, valsub);" +
			"\n          floatval += valnum->vx_float();" +
			"\n        } else if (valsubtype == vx_core::t_float) {" +
			"\n          vx_core::Type_float* valnum = vx_core::any_from_any(vx_core::t_float, valsub);" +
			"\n          floatval += valnum->vx_float();" +
			"\n        } else if (valsubtype == vx_core::t_int) {" +
			"\n          vx_core::Type_int* valnum = vx_core::any_from_any(vx_core::t_int, valsub);" +
			"\n          floatval += valnum->vx_int();" +
			"\n        } else if (valsubtype == vx_core::t_string) {" +
			"\n          vx_core::Type_string* valstring = vx_core::any_from_any(vx_core::t_string, valsub);" +
			"\n          floatval += Float.parseFloat(valstring->vx_string());" +
			"\n        } else if (valsubtype == vx_core::t_nativefloat) {" +
			"\n          floatval += vx_core::any_from_any(0f, valsub);" +
			"\n        } else if (valsubtype == vx_core::t_nativeint) {" +
			"\n          floatval += vx_core::any_from_any(0, valsub);" +
			"\n        } else if (valsubtype == vx_core::t_nativestring) {" +
			"\n          std::string ssubtype = vx_core::any_from_any(\"\", valsub);" +
			"\n          floatval += Float.parseFloat(ssubtype);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_float = floatval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
	case "vx/core/int":
		valcopy = "" +
			"\n      vx_core::Type_int* val = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output->vx_p_int = val->vx_int();"
		valnew = "" +
			"\n      int intval = 0;" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_int) {" +
			"\n          vx_core::Type_int valnum = vx_core::any_from_any(vx_core::t_int, valsub);" +
			"\n          intval += valnum->vx_int();" +
			"\n        } else if (valsubtype == vx_core::t_nativeint) {" +
			"\n          intval += vx_core::any_from_any(0, valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_int = intval;" +
			"\n      if (msgblock != vx_core::t_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		valcopy = "" +
			"\n      vx_core::Type_string* val = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output->vx_p_string = val->vx_string();"
		valnew = "" +
			"\n      string sb = output->vx_string();" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = msgblock->vx_copy(valsub);" +
			"\n        } else if (valsubtype == vx_core::t_string) {" +
			"\n          vx_core::Type_string valstring = vx_core::any_from_any(vx_core::t_string, valsub);" +
			"\n          sb.append(valstring->vx_string());" +
			"\n        } else if (valsubtype == vx_core::t_int) {" +
			"\n          vx_core::Type_int valint = vx_core::any_from_any(vx_core::t_int, valsub);" +
			"\n          sb.append(valint->vx_int());" +
			"\n        } else if (valsubtype == vx_core::t_float) {" +
			"\n          vx_core::Type_float valfloat = vx_core::any_from_any(vx_core::t_float, valsub);" +
			"\n          sb.append(valfloat->vx_float());" +
			"\n        } else if (valsubtype == vx_core::t_decimal) {" +
			"\n          vx_core::Type_decimal valdecimal = vx_core::any_from_any(vx_core::t_decimal, valsub);" +
			"\n          sb.append(valdecimal->vx_string());" +
			"\n        } else if (valsubtype == vx_core::t_nativestring) {" +
			"\n          sb.append(vx_core::any_from_any(\"\", valsub));" +
			"\n        } else if (valsubtype == vx_core::t_nativeint) {" +
			"\n          sb.append(vx_core::any_from_any(0, valsub));" +
			"\n        } else if (valsubtype == vx_core::t_nativefloat) {" +
			"\n          sb.append(vx_core::any_from_any(0f, valsub));" +
			"\n        } else {" +
			"\n          vx_core::Type_msg msg* = vx_core::t_msg->vx_new_error(\"(new " + typ.name + ") - Invalid Type: \" + vx_core::string_from_any(valsub));" +
			"\n          msgblock = msgblock->vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_string = sb;" +
			"\n      if (msgblock != vx_core::t_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
	}
	switch typ.extends {
	case ":list":
		allowcode := ""
		allowname := "any"
		allowclass := "vx_core::Type_any"
		allowttype := "vx_core::t_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = CppNameTypeFullFromType(allowtype)
			allowempty := CppNameEFromType(allowtype)
			allowttype = CppNameTFromType(allowtype)
			allowname = CppNameFromType(allowtype)
			allowcode = "" +
				"\n    " + allowclass + "* " + fulltypename + "::vx_" + allowname + "(vx_core::Type_int* index) {" +
				"\n      " + allowclass + "* output = " + allowempty + ";" +
				"\n      " + pkgname + "::Type_" + typename + "* list = this;" +
				"\n      int iindex = index->vx_int();" +
				"\n      std::vector<" + allowclass + "*> listval = list->vx_p_list;" +
				"\n      if (iindex < listval.size()) {" +
				"\n        output = listval[iindex];" +
				"\n      }" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		}
		if allowname == "any" {
			allowname = ""
		} else {
			allowcode += "" +
				"\n    std::vector<" + allowclass + "*> " + fulltypename + "::vx_list" + allowname + "() {return vx_p_list;}" +
				"\n" +
				"\n    vx_core::Type_any* " + fulltypename + "::vx_any(vx_core::Type_int* index) {" +
				"\n      return this->vx_" + allowname + "(index);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    std::vector<vx_core::Type_any*> " + fulltypename + "::vx_list() {" +
			"\n      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);" +
			"\n    }" +
			"\n" +
			allowcode
		valcopy = "" +
			"\n      " + fulltypename + "* val = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      std::vector<" + allowclass + "*> listval = val->vx_list" + allowname + "();"
		switch typ.name {
		case "msgblocklist":
			valnew = "" +
				"\n      for (std::any* valsub : vals) {" +
				"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
				"\n        if (valsubtype == vx_core::t_msg) {" +
				"\n          msgblock = msgblock->vx_copy(valsub);"
		case "msglist":
			valnew = "" +
				"\n      for (std::any* valsub : vals) {" +
				"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
				"\n        if (valsubtype == vx_core::t_msgblock) {" +
				"\n          msgblock = msgblock->vx_copy(valsub);"
		default:
			valnew = "" +
				"\n      for (std::any* valsub : vals) {" +
				"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
				"\n        if (valsubtype == vx_core::t_msgblock) {" +
				"\n          msgblock = msgblock->vx_copy(valsub);" +
				"\n        } else if (valsubtype == vx_core::t_msg) {" +
				"\n          msgblock = msgblock->vx_copy(valsub);"
			//"\n        } else if (valsubtype == " + allowttype + ") {" +
			//"\n          " + allowclass + "* valadd = vx_core::any_from_any(" + allowttype + ", valsub);" +
			//"\n          listval.push_back(valadd);"
		}
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := CppNameTFromType(allowedtype)
			castval := "vx_core::any_from_any(" + allowedtypename + ", valsub)"
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
			if allowedtypename != "" {
				valnew += "" +
					"\n        } else if (valsubtype == " + allowedtypename + ") {" +
					"\n          listval.push_back(" + castval + ");"
			}
		}
		valnew += "" +
			"\n        } else if (valsubtype == " + pkgname + "::t_" + typename + ") {" +
			"\n          " + fulltypename + "* multi = vx_core::any_from_any(" + pkgname + "::t_" + typename + ", valsub);" +
			"\n          listval = vx_core::listaddall(listval, multi->vx_list" + allowname + "());" +
			"\n        } else if (valsubtype == vx_core::t_nativelist) {" +
			"\n          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);" +
			"\n          for (std::any* item : listunknown) {" +
			"\n            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);" +
			"\n            if (itemtype == " + allowttype + ") {" +
			"\n              " + allowclass + "* valitem = vx_core::any_from_any(" + allowttype + ", item);" +
			"\n              listval.push_back(valitem);" +
			"\n            }" +
			"\n          }" +
			"\n        } else {" +
			"\n          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(new " + typ.name + ") - Invalid Type: \" + vx_core::string_from_any(valsub));" +
			"\n          msgblock = msgblock->vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_list = listval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":map":
		allowcode := ""
		allowname := "any"
		allowclass := "vx_core::Type_any"
		allowttype := "vx_core::t_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = CppNameTypeFullFromType(allowtype)
			allowttype = CppNameTFromType(allowtype)
			allowempty := CppNameEFromType(allowtype)
			allowname = CppNameFromType(allowtype)
			allowcode = "" +
				"\n    // vx_" + allowname + "(key)" +
				"\n    " + allowclass + "* " + fulltypename + "::vx_" + allowname + "(vx_core::Type_string* key) {" +
				"\n      " + allowclass + "* output = " + allowempty + ";" +
				"\n      " + fulltypename + "* map = this;" +
				"\n      std::string skey = key->vx_string();" +
				"\n      std::map<std::string, " + allowclass + "*> mapval = map->vx_p_map;" +
				"\n      output = vx_core::any_from_map(mapval, skey, " + allowempty + ");" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		}
		if allowname == "any" {
			allowname = ""
		} else {
			allowcode += "" +
				"\n    // vx_any(key)" +
				"\n    vx_core::Type_any* " + fulltypename + "::vx_any(vx_core::Type_string* key) {" +
				"\n      return this->vx_" + allowname + "(key);" +
				"\n    }" +
				"\n" +
				"\n    // vx_map" + allowname + "()" +
				"\n    std::map<std::string, " + allowclass + "*> " + fulltypename + "::vx_map" + allowname + "() {return vx_p_map;}" +
				"\n"
		}
		instancefuncs += "" +
			"\n    // vx_map()" +
			"\n    std::map<std::string, vx_core::Type_any*> " + fulltypename + "::vx_map() {" +
			"\n      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);" +
			"\n    }" +
			"\n" +
			allowcode +
			"\n    // vx_new_from_map(mapval)" +
			"\n    " + fulltypename + "* " + fulltypename + "::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {" +
			"\n      " + fulltypename + "* output;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;" +
			"\n      std::map<std::string, " + allowclass + "*> map;" +
			"\n      for (auto const& iter : mapval) {" +
			"\n        std::string key = iter.first;" +
			"\n        vx_core::Type_any* val = iter.second;" +
			"\n        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);" +
			"\n        if (valtype == " + allowttype + ") {" +
			"\n          " + allowclass + "* castval = vx_core::any_from_any(" + allowttype + ", val);" +
			"\n          map[key] = castval;" +
			"\n        } else {" +
			"\n          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(" + typename + ") Invalid Value: \" + vx_core::string_from_any(val) + \"\");" +
			"\n          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_map = map;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
		valcopy = "" +
			"\n      " + fulltypename + "* valmap = this;" +
			"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);"
		valnew = "" +
			"\n      std::map<std::string, " + allowclass + "*> mapval;" +
			"\n      std::string key = \"\";" +
			"\n      for (std::any* valsub : vals) {" +
			"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
			"\n        if (valsubtype == vx_core::t_msgblock) {" +
			"\n          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);" +
			"\n        } else if (valsubtype == vx_core::t_msg) {" +
			"\n          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);" +
			"\n        } else if (key == \"\") {" +
			"\n          if (valsubtype == vx_core::t_string) {" +
			"\n            vx_core::Type_string* valstring = vx_core::any_from_any(vx_core::t_string, valsub);" +
			"\n            key = valstring->vx_string();" +
			"\n          } else if (valsubtype == vx_core::t_nativestring) {" +
			"\n            key = vx_core_::any_from_any(\"\", valsub);" +
			"\n          } else {" +
			"\n            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"Key Expected: \" + vx_core::string_from_any(valsub) + \"\");" +
			"\n            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n        } else {" +
			"\n          " + allowclass + "* valany;" +
			"\n          if (valsubtype == " + allowttype + ") {" +
			"\n            valany = vx_core::any_from_any(" + allowttype + ", valsub);"
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := CppNameTFromType(allowedtype)
			castval := "vx_core::any_from_any(" + allowttype + ", valsub)"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "vx_core::t_nativeboolean"
					castval = "vx_core::t_boolean->vx_new(valsub);"
				case "vx/core/int":
					allowedtypename = "vx_core::t_nativeint"
					castval = "vx_core::t_int->vx_new(valsub);"
				case "vx/core/float":
					allowedtypename = "vx_core::t_nativefloat"
					castval = "vx_core::t_float->vx_new(valsub);"
				case "vx/core/string":
					allowedtypename = "vx_core::t_nativestring"
					castval = "vx_core::t_string->vx_new(valsub);"
				}
			}
			if allowedtypename != "" {
				valnew += "" +
					"\n          } else if (valsubtype == " + allowedtypename + ") {" +
					"\n            valany = " + castval + ";"
			}
		}
		valnew += "" +
			"\n          } else {" +
			"\n            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"Invalid Key/Value: \" + key + \" \"  + vx_core::string_from_any(valsub) + \"\");" +
			"\n            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n          if (valany != NULL) {" +
			"\n            mapval[key] = valany;" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      output->vx_p_map = mapval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output->vx_p_msgblock = msgblock;" +
			"\n      }"
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":struct":
		vx_any := ""
		vx_map := ""
		valcopy = "" +
			"\n      Type_" + typename + "* val = this;"
		switch NameFromType(typ) {
		case "vx/core/msgblock":
			valcopy += "" +
				"\n      vx_core::Type_msgblock* msgblock = this;"
		default:
			valcopy += "" +
				"\n      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);"
		}
		props := ListPropertyTraitFromType(typ)
		switch len(props) {
		case 0:
			valnew = "" +
				"\n      if (msgblock != vx_core::e_msgblock) {" +
				"\n        output->vx_p_msgblock = msgblock;" +
				"\n      }"
		default:
			validkeys := "\n      std::set<std::string> validkeys;"
			valnewswitch := ""
			for _, arg := range props {
				validkeys += "\n      validkeys.insert(\":" + arg.name + "\");"
				argname := CppFromName(arg.name)
				valcopy += "\n      output->vx_p_" + argname + " = val->" + argname + "();"
				vx_map += "\n      output[\":" + arg.name + "\"] = this->" + argname + "();"
				vx_any += "" +
					"\n      } else if (skey == \":" + arg.name + "\") {" +
					"\n        output = this->" + argname + "();"
				argclassname := CppNameTypeFromType(arg.vxtype)
				argttype := CppNameTFromType(arg.vxtype)
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						"\n            } else if (valsubtype == vx_core::t_nativeboolean) {" +
						"\n              output->vx_p_" + argname + " = vx_core::t_boolean->vx_new(valsub);"
				case "vx/core/int":
					argalt = "" +
						"\n            } else if (valsubtype == vx_core::t_nativeint) {" +
						"\n              output->vx_p_" + argname + " = vx_core::t_int->vx_new(valsub);"
				case "vx/core/float":
					argalt = "" +
						"\n            } else if (valsubtype == vx_core::t_nativefloat) {" +
						"\n              output->vx_p_" + argname + " = vx_core::t_float->vx_new(valsub);"
				case "vx/core/string":
					argalt = "" +
						"\n            } else if (valsubtype == vx_core::t_nativestring) {" +
						"\n              output->vx_p_" + argname + " = vx_core::t_string->vx_new(valsub);"
				}
				valnewswitch += "" +
					"\n          } else if (key == \":" + arg.name + "\") {" +
					"\n            if (valsubtype == " + argttype + ") {" +
					"\n              output->vx_p_" + argname + " = vx_core::any_from_any(" + argttype + ", valsub);" +
					argalt +
					"\n            } else {" +
					"\n              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(new " + typ.name + " :" + arg.name + " \" + vx_core::string_from_any(valsub) + \") - Invalid Value\");" +
					"\n              msgblock = msgblock->vx_copy(msg);" +
					"\n            }"
				instancefuncs += "" +
					"\n    // " + argname + "()" +
					"\n    " + argclassname + "* " + fulltypename + "::" + argname + "() {" +
					"\n      " + argclassname + "* output = this->vx_p_" + argname + ";" +
					"\n      if (output == NULL) {" +
					"\n        output = " + argttype + ";" +
					"\n      }" +
					"\n    }" +
					"\n"
			}
			defaultkey := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := CppFromName(lastarg.name)
				argclassname := CppNameTypeFromType(lastarg.vxtype)
				argttype := CppNameTFromType(lastarg.vxtype)
				defaultkey += "" +
					"\n          } else if (valsubtype == " + argttype + ") { // default property" +
					"\n            output->vx_p_" + lastargname + " = vx_core::any_from_any(" + argttype + ", valsub);"
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
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						subargclassname := CppNameTypeFromType(allowtype)
						subargttype := CppNameTFromType(allowtype)
						defaultkey += "" +
							"\n          } else if (valsubtype == " + subargttype + ") { // default property" +
							"\n            " + subargclassname + "* valdefault = vx_core::any_from_any(" + subargttype + ", valsub);" +
							"\n            " + argclassname + "* vallist = output->vx_p_" + lastargname + ";" +
							"\n            if (vallist == null) {" +
							"\n              vallist = " + CppNameTFromType(lastarg.vxtype) + "->vx_new(valdefault);" +
							"\n            } else {" +
							"\n              vallist = vallist->vx_copy(valdefault);" +
							"\n            }" +
							"\n            output->vx_p_" + lastargname + " = vallist;"
					}
				}
			}
			switch NameFromType(typ) {
			case "vx/core/msg":
				valnew = "" +
					"\n      std::string key = \"\";" +
					"\n      for (std::any* valsub : vals) {" +
					"\n        if (key == \"\") {" +
					"\n          vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
					"\n          if (valsubtype == vx_core::t_string) {" +
					"\n            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);" +
					"\n            key = valstr->vx_string();" +
					"\n          } else if (valsubtype == vx_core::t_nativestring) {" +
					"\n            key = vx_core::any_from_any(\"\", valsub);" +
					"\n          } else {" +
					"\n            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + vx_core::string_from_any(valsub));" +
					"\n            msgblock = msgblock->vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          if (false) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }"
			case "vx/core/msgblock":
				valnew = "" +
					"\n      std::string key = \"\";" +
					"\n      for (std::any* valsub : vals) {" +
					"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
					"\n        if (valsubtype == vx_core::t_msgblock) {" +
					"\n          vx_core::Type_msgblocklist* msgblocks = this->msgblocks();" +
					"\n          msgblocks = msgblocks->vx_copy(valsub);" +
					"\n          output->vx_p_msgblocks = msgblocks;" +
					"\n        } else if (valsubtype == vx_core::t_msg) {" +
					"\n          vx_core::Type_msglist msgs = this->msgs();" +
					"\n          msgs = msgs->vx_copy(valsub);" +
					"\n          output->vx_p_msgs = msgs;" +
					"\n        } else if (valsubtype == vx_core::t_msgblocklist) {" +
					"\n          vx_core::Type_msgblocklist msgblocks = this->msgblocks();" +
					"\n          msgblocks = msgblocks->vx_copy(valsub);" +
					"\n          output->vx_p_msgblocks = msgblocks;" +
					"\n        } else if (valsubtype == vx_core::t_msglist) {" +
					"\n          vx_core::Type_msglist msgs = this->msgs();" +
					"\n          msgs = msgs->vx_copy(valsub);" +
					"\n          output->vx_p_msgs = msgs;" +
					"\n        } else if (key == \"\") {" +
					"\n          if (valsubtype == vx_core::t_string) {" +
					"\n            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);" +
					"\n            key = valstr->vx_string();" +
					"\n          } else if (valsubtype == vx_core::t_nativestring) {" +
					"\n            key = vx_core::any_from_any(\"\", valsub);" +
					"\n          } else {" +
					"\n            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + vx_core::string_from_any(valsub));" +
					"\n            msgblock = msgblock->vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          if (false) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }"
			default:
				valnew = "" +
					validkeys +
					"\n      std::string key = \"\";" +
					"\n      for (std::any* valsub : vals) {" +
					"\n        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);" +
					"\n        if (valsubtype == vx_core::t_msgblock) {" +
					"\n          msgblock = msgblock->vx_copy(valsub);" +
					"\n        } else if (valsubtype == vx_core::t_msg) {" +
					"\n          msgblock = msgblock->vx_copy(valsub);" +
					"\n        } else if (key == \"\") {" +
					"\n          std::string testkey = \"\";" +
					"\n          if (valsubtype == vx_core::t_string) {" +
					"\n            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);" +
					"\n            testkey = valstr->vx_string();" +
					"\n          } else if (valsubtype == vx_core::t_nativestring) {" +
					"\n            testkey = vx_core::any_from_any(\"\", valsub);" +
					"\n          }" +
					"\n          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);" +
					"\n          if (isvalidkey) {" +
					"\n            key = testkey;" +
					defaultkey +
					"\n          } else {" +
					"\n            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + vx_core::string_from_any(valsub));" +
					"\n            msgblock = msgblock->vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          if (false) {" +
					valnewswitch +
					"\n          } else {" +
					"\n            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error(\"(new " + typ.name + ") - Invalid Key: \" + key);" +
					"\n            msgblock = msgblock->vx_copy(msg);" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (msgblock != vx_core::e_msgblock) {" +
					"\n        output->vx_p_msgblock = msgblock;" +
					"\n      }"
			}
		}
		instancefuncs += "" +
			"\n    // vx_any(key)" +
			"\n    vx_core::Type_any* " + fulltypename + "::vx_any(vx_core::Type_string* key) {" +
			"\n      vx_core::Type_any* output = vx_core::e_any;" +
			"\n      std::string skey = key->vx_string();" +
			"\n      if (false) {" +
			vx_any +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    // vx_map()" +
			"\n    std::map<std::string, vx_core::Type_any*> " + fulltypename + "::vx_map() {" +
			"\n      std::map<std::string, vx_core::Type_any*> output;" +
			vx_map +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	vxmsgblock := ""
	switch NameFromType(typ) {
	case "vx/core/msg":
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock* vx_msgblock() {return vx_core::e_msgblock;}"
	case "vx/core/msgblock":
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock* vx_msgblock() {return this;}"
	}
	typedef := "" +
		"\n    vx_core::Type_typedef* " + fulltypename + "::vx_typedef() {" +
		"\n      return " + CppTypeDefFromType(typ, "      ") + ";" +
		"\n    }" +
		"\n"
	output := "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (type " + typ.name + ")" +
		"\n   */" +
		"\n  //class Type_" + typename + " {" +
		instancefuncs +
		"\n    template<typename... Args> " + fulltypename + "* " + fulltypename + "::vx_new(Args*... args) {return " + pkgname + "::e_" + typename + "->vx_copy(args...);}" +
		"\n    template<typename... Args> " + fulltypename + "* " + fulltypename + "::vx_copy(Args*... args) {" +
		"\n      " + pkgname + "::Type_" + typename + "* output;" +
		"\n      const int size = sizeof...(args);" +
		"\n      const std::any vals[size];" +
		//		"\n    " + pkgname + "::Type_" + typename + "* " + pkgname + "::Type_" + typename + "::vx_new(std::any* val) {return " + pkgname + "::e_" + typename + "->vx_copy(val);}" +
		//		"\n    " + pkgname + "::Type_" + typename + "* " + pkgname + "::Type_" + typename + "::vx_new(std::vector<std::any*> vals) {return " + pkgname + "::e_" + typename + "->vx_copy(vals);}" +
		//		"\n" +
		//		"\n    " + pkgname + "::Type_" + typename + "* " + pkgname + "::Type_" + typename + "::vx_copy(std::any* val) {return this->vx_copy({val});}" +
		//		"\n    " + pkgname + "::Type_" + typename + "* " + pkgname + "::Type_" + typename + "::vx_copy(std::vector<std::any*> vals) {" +
		//		"\n      " + pkgname + "::Type_" + typename + "* output;" +
		valcopy +
		valnew +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		vxmsgblock +
		"\n    " + fulltypename + "* " + fulltypename + "::vx_empty() {return " + pkgname + "::e_" + typename + ";}" +
		"\n    " + fulltypename + "* " + fulltypename + "::vx_type() {return " + pkgname + "::t_" + typename + ";}" +
		"\n" +
		typedef +
		staticfuncs +
		"\n  //}" +
		"\n"
	return output, msgblock
}

func CppFromValue(value vxvalue, pkgname string, parentfn *vxfunc, indent string, encode bool, test bool, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppFromValue")
	var output = ""
	valstr := ""
	switch value.code {
	case ":arg":
		valarg := ArgFromValue(value)
		valstr = CppFromName(valarg.name)
		output += valstr
	case ":const":
		switch value.name {
		case "false", "true":
			valstr = "vx_core::t_boolean->vx_new_from_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = CppFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = CppNameFromPkgName(valconst.pkgname) + "::c_" + CppFromName(valconst.alias)
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
						clstext, msgs := CppFromValue(argvalue, pkgname, parentfn, "", false, test, subpath)
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
					output += StringFromStringIndent(StringFromListStringJoin(argtexts, ""), indent)
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
				propvalue := funcargs[1].value
				switch propvalue.code {
				case "string":
					propname := StringValueFromValue(propvalue)
					if BooleanFromStringStarts(propname, ":") {
						propname = propname[1:]
					}
					structvalue := funcargs[0].value
					work, msgs := CppFromValue(structvalue, pkgname, fnc, "", true, test, subpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					work = work + "->" + CppFromName(propname) + "()"
					argtexts = append(argtexts, work)
					isskip = true
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
				subindent := indent + "  "
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
								lambdaargs = append(lambdaargs, "vx_core::Type_any* "+lambdaarg.name+"_any")
								argvaltype := ""
								argvalinstance := ""
								argtype := lambdaarg.vxtype
								argvaltype = CppNameTypeFullFromType(argtype)
								argvalinstance = CppNameTFromType(argtype)
								lambdavar := argvaltype + "* " + lambdaarg.name + " = vx_core::f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any);"
								lambdavars = append(lambdavars, lambdavar)
							}
							lambdatext := StringFromListStringJoin(lambdaargs, ", ")
							lambdavartext := "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
							if argfunc.async {
								work, msgs := CppFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-key-value-async":
									argtext = "" +
										"vx_core::t_any_from_key_value_async->fn_new([" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-async":
									argtext = "" +
										"vx_core::t_any_from_reduce_async->fn_new([" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next-async":
									argtext = "" +
										"vx_core::t_any_from_reduce_next_async->fn_new([" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"vx_core::t_any_from_any_async->fn_new([" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"vx_core::t_any_from_func_async->fn_new([" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								work, msgs := CppFromValue(argvalue, pkgname, fnc, "  ", true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-key-value":
									argtext = "" +
										"vx_core::t_any_from_key_value->fn_new([" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce":
									argtext = "" +
										"vx_core::t_any_from_reduce->fn_new([" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next":
									argtext = "" +
										"vx_core::t_any_from_reduce_next->fn_new([" + capturetext + "](" + lambdatext + ") {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"vx_core::t_any_from_any->fn_new([" + capturetext + "](" + lambdatext + ") {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"vx_core::t_any_from_func->fn_new([" + capturetext + "](" + lambdatext + ") {" +
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
									argindent := "  "
									for lambdaidx, lambdaarg := range arglist {
										lambdaargpath := argsubpath + ":lambdaarg/" + lambdaarg.name
										arglineindent := "\n" + argindent
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
											valuecapturetext := CppCaptureFromValueListInner(funcarg.value, localargs, valuesubpath)
											lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + "vx_core::Async<" + CppNameTypeFromType(lambdaarg.vxtype) + "*>* future_" + CppFromName(lambdaarg.name) + " = " + lambdavaluetext + ";" +
												arglineindent + "vx_core::Async<vx_core::Type_any*>* output = vx_core::Async<vx_core::Type_any*>::map<vx_core::Type_any*, " + CppNameTypeFromType(lambdaarg.vxtype) + "*>(vx_core::t_any, future_" + CppFromName(lambdaarg.name) + ", [" + valuecapturetext + "](" + CppNameTypeFromType(lambdaarg.vxtype) + "* " + CppFromName(lambdaarg.name) + ") {"
											aftertext += "" +
												arglineindent + "});" +
												arglineindent + "return output;"
											argindent += "  "
										} else {
											lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + CppNameTypeFromType(lambdaarg.vxtype) + "* " + CppFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
										}
									}
									work, msgs := CppFromValue(argvalue, pkgname, fnc, "    ", true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										"vx_core::t_any_from_func_async->fn_new([" + capturetext + "]() {" +
										lambdatext +
										"\n    return " + work + ";" +
										aftertext +
										"\n})"
								} else {
									argindent := "  "
									arglineindent := "\n" + argindent
									for _, lambdaarg := range arglist {
										lambdaargpath := argsubpath + "/:arg/" + lambdaarg.name
										lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										lambdatext += arglineindent + CppNameTypeFromType(lambdaarg.vxtype) + "* " + CppFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
									}
									work, msgs := CppFromValue(argvalue, pkgname, fnc, "", true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									argtext = "" +
										"vx_core::t_any_from_func->fn_new([" + capturetext + "]() {" +
										lambdatext +
										arglineindent + "return " + work + ";" +
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
										"vx_core::t_any_from_func->fn_new([" + capturetext + "]() {" +
										"\n  return " + work + ";" +
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
								workindent := "  "
								if converttoasync {
									workindent += "  "
								}
								work, msgs := CppFromValue(argvalue, pkgname, fnc, workindent, true, test, argsubpath)
								if converttoasync {
									work = "vx_core::f_async(" + CppNameTFromType(argfunctype) + ",\n" + workindent + work + "\n  )"
								}
								msgblock = MsgblockAddBlock(msgblock, msgs)
								if argvalue.code == ":func" && argvalue.name == "native" {
								} else {
									work = "\n  return " + work + ";"
								}
								capturetext := CppCaptureFromValue(argvalue, argsubpath)
								argtext = "" +
									CppNameTFromType(funcarg.vxtype) + "->fn_new([" + capturetext + "]() {" +
									work +
									"\n})"
							}
						}
						if argtext == "" {
							work, msgs := CppFromValue(argvalue, pkgname, fnc, "", true, test, argsubpath)
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
									CppNameTFromType(funcarg.vxtype) + "->vx_new(" +
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
										argtext = "(" + CppNameTypeFromType(funcarg.vxtype) + "*)" + argtext
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
				output += "\n" + indent + "  " + StringFromStringIndent(StringFromListStringJoin(argtexts, ",\n"), indent+"  ")
				if multiflag {
					output += "\n" + indent + "  )"
				}
				switch fnc.name {
				case "fn":
				default:
					output += "\n" + indent + ")"
				}
			} else {
				output += StringFromListStringJoin(argtexts, ", ")
				if multiflag {
					output += ")"
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
		valstr += CppNameFromPkgName(valfunc.pkgname) + "::t_" + CppFromName(valfunc.alias)
		output = indent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = CppNameFromPkgName(valtype.pkgname) + "::t_" + CppFromName(valtype.alias)
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
			output = "vx_core::t_boolean->vx_new_from_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::t_decimal->vx_new_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::t_float->vx_new_from_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::t_int->vx_new_from_int(" + valstr + ")"
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

func CppImportsFromPackage(pkg *vxpackage, pkgprefix string, body string, test bool) string {
	output := ""
	if BooleanFromStringContains(body, "std::any") {
		output += "#include <any>\n"
	}
	if BooleanFromStringContains(body, "std::exception") {
		output += "#include <exception>\n"
	}
	if BooleanFromStringContains(body, " std::function<") {
		output += "#include <functional>\n"
	}
	if BooleanFromStringContains(body, " std::shared_future<") {
		output += "#include <future>\n"
	}
	if BooleanFromStringContains(body, " std::cout ") {
		output += "#include <iostream>\n"
	}
	if BooleanFromStringContains(body, "std::map<") {
		output += "#include <map>\n"
	}
	if BooleanFromStringContains(body, "std::set<") {
		output += "#include <set>\n"
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
		output += "#include \"" + slashprefix + "../src/" + pkg.name + ".hpp\"\n"
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
				libpath = "../src/" + libpath
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

func CppIndexFromFunc(fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func CppHeaderFromType(typ *vxtype) string {
	output := ""
	pkgname := CppNameFromPkgName(typ.pkgname)
	typename := CppNameFromType(typ)
	fulltypename := pkgname + "::Type_" + typename
	basics := "" +
		"\n    template<class... Args> " + fulltypename + "* vx_new(Args*... args);" +
		"\n    template<class... Args> " + fulltypename + "* vx_copy(Args*... args);" +
		"\n    virtual " + fulltypename + "* vx_empty();" +
		"\n    virtual " + fulltypename + "* vx_type();" +
		"\n    virtual vx_core::Type_typedef* vx_typedef();"
	extras := ""
	createtext, _ := CppFromValue(typ.createvalue, "", emptyfunc, "", true, false, "")
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
					ipos := IntFromStringFindLast(createline, ")")
					if ipos > 0 {
						createline = createline[0:ipos+1] + ";"
					}
					extras += "\n    " + createline
				}
			}
		}
	}
	switch NameFromType(typ) {
	case "vx/core/any":
		output = "" +
			"\n  // (type any)" +
			"\n  class Type_any : public std::any {" +
			"\n  public:" +
			"\n    int vx_iref;" +
			"\n    vx_core::Type_msgblock* vx_p_msgblock;" +
			"\n    virtual vx_core::Type_msgblock* vx_msgblock();" +
			"\n    virtual std::vector<vx_core::Type_any*> vx_dispose();" +
			"\n    virtual bool vx_release();" +
			"\n    virtual void vx_reserve();" +
			basics +
			extras +
			"\n  };" +
			"\n"
	case "vx/core/boolean":
		output = "" +
			"\n  // (type boolean)" +
			"\n  class Type_boolean : public virtual vx_core::Type_any {" +
			"\n  public:" +
			basics +
			extras +
			"\n  };" +
			"\n"
	case "vx/core/decimal":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_decimal : public virtual vx_core::Type_number {" +
			"\n  public:" +
			basics +
			extras +
			"\n  };" +
			"\n"
	case "vx/core/float":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_float : public virtual vx_core::Type_number {" +
			"\n  public:" +
			basics +
			extras +
			"\n  };" +
			"\n"
	case "vx/core/func":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_func : public virtual vx_core::Type_any {" +
			"\n  public:" +
			basics +
			extras +
			"\n    virtual vx_core::Type_funcdef* vx_funcdef();" +
			"\n  };" +
			"\n"
	case "vx/core/int":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_int : public vx_core::Type_number {" +
			"\n  public:" +
			basics +
			extras +
			"\n  };" +
			"\n"
	case "vx/core/string":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_string : public virtual vx_core::Type_any {" +
			"\n  public:" +
			basics +
			extras +
			"\n  };" +
			"\n"
	case "vx/core/list":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_list : public vx_core::Type_any {" +
			"\n  public:" +
			basics +
			extras +
			"\n    std::vector<vx_core::Type_any*> vx_p_list;" +
			"\n    virtual std::vector<vx_core::Type_any*> vx_list();" +
			"\n    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);" +
			"\n  };" +
			"\n"
	case "vx/core/map":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_map : public vx_core::Type_any {" +
			"\n  public:" +
			basics +
			extras +
			"\n    std::map<std::string, vx_core::Type_any*> vx_p_map;" +
			"\n    virtual std::map<std::string, vx_core::Type_any*> vx_map();" +
			"\n    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);" +
			"\n    virtual vx_core::Type_map* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);" +
			"\n  };" +
			"\n"
	case "vx/core/struct":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_struct : public vx_core::Type_any {" +
			"\n  public:" +
			basics +
			extras +
			"\n    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);" +
			"\n    virtual std::map<std::string, vx_core::Type_any*> vx_map();" +
			"\n  };" +
			"\n"
	default:
		switch NameFromType(typ) {
		case "vx/core/msg":
			basics = "" +
				"\n    template<class... Args> " + fulltypename + "* vx_new(Args*... args);" +
				"\n    template<class... Args> " + fulltypename + "* vx_copy(Args*... args);" +
				"\n    virtual " + fulltypename + "* vx_empty();" +
				"\n    virtual " + fulltypename + "* vx_type();" +
				"\n    virtual vx_core::Type_typedef* vx_typedef();"
			extras += "" +
				"\n    virtual vx_core::Type_msg* vx_new_error(std::string text);" +
				"\n    virtual vx_core::Type_msg* vx_new_from_exception(std::string text, std::exception err);"
		case "vx/core/msgblock":
			basics = "" +
				"\n    template<class... Args> " + fulltypename + "* vx_new(Args*... args);" +
				"\n    template<class... Args> " + fulltypename + "* vx_copy(Args*... args);" +
				"\n    virtual " + fulltypename + "* vx_empty();" +
				"\n    virtual " + fulltypename + "* vx_type();" +
				"\n    virtual vx_core::Type_typedef* vx_typedef();"
			extras += "" +
				"\n    virtual vx_core::Type_msgblock* vx_msgblock_from_copy_arrayval(vx_core::Type_any* copy, std::vector<std::any*> vals);"
		}
		extends := ""
		switch typ.extends {
		case "boolean":
			extends += "public virtual vx_core::Type_boolean"
		case "decimal":
			extends += "public virtual vx_core::Type_decimal"
		case "float":
			extends += "public virtual vx_core::Type_float"
		case "int":
			extends += "public virtual vx_core::Type_int"
		case "string":
			extends += "public virtual vx_core::Type_string"
		case ":list":
			extends += "public virtual vx_core::Type_list"
			extras += "" +
				"\n    // vx_any(index)" +
				"\n    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);" +
				"\n    // vx_list()" +
				"\n    virtual std::vector<vx_core::Type_any*> vx_list();"
			allowclass := "vx_core::Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = CppNameTypeFullFromType(allowtype)
				allowname = CppNameFromType(allowtype)
			}
			extras += "" +
				"\n    std::vector<" + allowclass + "*> vx_p_list;" +
				"\n"
			if allowname != "any" {
				extras += "" +
					"\n    // vx_list" + allowname + "()" +
					"\n    virtual std::vector<" + allowclass + "*> vx_list" + allowname + "();" +
					"\n    // vx_" + allowname + "(index)" +
					"\n    virtual " + allowclass + "* vx_" + allowname + "(vx_core::Type_int* index);"
			}
		case ":map":
			extends = "public virtual vx_core::Type_map"
			allowclass := "vx_core::Type_any"
			extras += "" +
				"\n    // vx_any(key)" +
				"\n    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);" +
				"\n    // vx_map()" +
				"\n    virtual std::map<std::string, vx_core::Type_any*> vx_map();"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = CppNameTypeFullFromType(allowtype)
				allowname = CppNameFromType(allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    std::map<std::string, " + allowclass + "*> vx_p_map;" +
					"\n    // vx_map" + allowname + "()" +
					"\n    virtual std::map<std::string, " + allowclass + "*> vx_map" + allowname + "();" +
					"\n    // vx_" + allowname + "(key)" +
					"\n    virtual " + allowclass + "* vx_" + allowname + "(vx_core::Type_string* key);" +
					"\n    virtual " + fulltypename + "* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);"
			}
		case ":struct":
			extends = "public virtual vx_core::Type_struct"
			extras += "" +
				"\n    // vx_any(key)" +
				"\n    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);" +
				"\n    // vx_map()" +
				"\n    virtual std::map<std::string, vx_core::Type_any*> vx_map();"
			if len(typ.traits) > 0 {
				var traitnames []string
				for _, trait := range typ.traits {
					traitname := "public virtual " + CppNameTypeFullFromType(trait)
					traitnames = append(traitnames, traitname)
				}
				extends += ", " + StringFromListStringJoin(traitnames, ", ")
			}
			for _, arg := range ListPropertyTraitFromType(typ) {
				argclassname := CppNameTypeFromType(arg.vxtype)
				argname := CppFromName(arg.alias)
				extras += "" +
					"\n    // " + arg.name + "()" +
					"\n    " + argclassname + "* vx_p_" + argname + ";" +
					"\n    virtual " + argclassname + "* " + argname + "();"
			}
		default:
			extends += "public vx_core::Type_any"
		}
		typename := CppNameFromType(typ)
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_" + typename + " : " + extends + " {" +
			"\n  public:" +
			basics +
			extras +
			"\n  };" +
			"\n"
	}
	//	output += "" +
	//		"\n  extern " + pkgname + "::Type_" + typename + "* e_" + typename + ";" +
	//		"\n  extern " + pkgname + "::Type_" + typename + "* t_" + typename + ";" +
	//		"\n"
	return output
}

func CppHeaderFnFromFunc(fnc *vxfunc) string {
	interfaces := ""
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*(vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-any-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Async<vx_core::Type_any*>(vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-any-context":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*(vx_core::Type_any*, vx_core::Type_context*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-any-context-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_any*, vx_core::Type_context*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-key-value":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*(vx_core::Type_string*, vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-func", "vx/core/any<-none":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*()> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-reduce":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*(vx_core::Type_any*, vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-reduce-next":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*(vx_core::Type_any*, vx_core::Type_any*, vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-key-value-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_string*, vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-func-async", "vx/core/any<-none-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Async<vx_core::Type_any*>*()> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-reduce-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_any*, vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/any<-reduce-next-async":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Async<vx_core::Type_any*>*(vx_core::Type_any*, vx_core::Type_any*, vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		interfaces = "" +
			"\n    typedef std::function<vx_core::Type_any*()> IFn;" +
			"\n    IFn fn;"
	case "vx/core/none<-any":
		interfaces = "" +
			"\n    typedef std::function<void(vx_core::Type_any*)> IFn;" +
			"\n    IFn fn;"
	}
	return interfaces
}

func CppHeaderFromFunc(fnc *vxfunc) (string, string) {
	funcname := CppNameFromFunc(fnc)
	pkgname := CppNameFromPkgName(fnc.pkgname)
	extends := ""
	interfaces := ""
	generictypes := CppGenericDefinitionFromFunc(fnc)
	returntype := CppNameTypeFromType(fnc.vxtype)
	var listargtext []string
	if fnc.generictype != nil {
		returntype = CppGenericFromType(fnc.generictype)
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			listargtext = append(listargtext, returntype+"* generic_any_1")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if argtype.isgeneric {
				argtypename = CppGenericFromType(argtype)
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
				listargtext = append(listargtext, argtypename+"* "+argname)
			}
		}
	} else {
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := CppNameTypeFromType(argtype)
			argname := CppFromName(arg.alias)
			listargtext = append(listargtext, argtypename+"* "+argname)
		}
	}
	argtext := StringFromListStringJoin(listargtext, ", ")
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
		extends = "public vx_core::Type_func"
		interfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + "* fn_new(vx_core::Func_" + funcname + "::IFn fn);"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		extends = "public vx_core::Type_func"
		interfaces += "" +
			"\n    virtual vx_core::Func_" + funcname + "* fn_new(vx_core::Func_any_from_func::IFn fn);"
	case "vx/core/none<-any":
	default:
		if extends == "" {
			extends = "public vx_core::Type_func"
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
			default:
				switch len(fnc.listarg) {
				case 1:
					if fnc.async {
						if fnc.context {
							extends = "public vx_core::Func_any_from_any_context_async"
							interfaces += "" +
								"\n    virtual vx_core::Func_any_from_any_context_async* fn_new(vx_core::Func_any_from_any_context_async::IFn fn);" +
								"\n    template <class T, class U> vx_core::Async<T*>* f_any_from_any_context_async(T* generic_any_1, U* value, vx_core::Type_context* context);"
						} else {
							extends = "public vx_core::Func_any_from_any_async"
							interfaces += "" +
								"\n    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);" +
								"\n    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);"
						}
					} else {
						if fnc.context {
							extends = "public vx_core::Func_any_from_any_context"
							interfaces += "" +
								"\n    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);" +
								"\n    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);"
						} else {
							extends = "public vx_core::Func_any_from_any"
							interfaces += "" +
								"\n    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);" +
								"\n    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);"
						}
					}
				}
			}
		}
	}
	returntype += "*"
	if fnc.async {
		returntype = "vx_core::Async<" + returntype + ">*"
	}
	contextarg := ""
	if fnc.context {
		if argtext == "" {
			contextarg = "vx_core::Type_context* context"
		} else {
			contextarg = ", vx_core::Type_context* context"
		}
	}
	if fnc.async {
		extends += ", public virtual vx_core::Type_replfunc_async"
		interfaces += "" +
			"\n    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);"
	} else {
		extends += ", public virtual vx_core::Type_replfunc"
		interfaces += "" +
			"\n    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);"
	}
	interfaces += "" +
		"\n    " + generictypes + returntype + " vx_" + funcname + "(" + argtext + contextarg + ");"
	fnheaders := CppHeaderFnFromFunc(fnc)
	output := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  class Func_" + funcname + " : " + extends + " {" +
		"\n  public:" +
		"\n    template<class... Args> " + pkgname + "::Func_" + funcname + "* vx_new(Args*... args);" +
		"\n    template<class... Args> " + pkgname + "::Func_" + funcname + "* vx_copy(Args*... args);" +
		"\n    virtual vx_core::Type_funcdef* vx_funcdef();" +
		"\n    virtual vx_core::Type_typedef* vx_typedef();" +
		"\n    virtual " + pkgname + "::Func_" + funcname + "* vx_empty();" +
		"\n    virtual " + pkgname + "::Func_" + funcname + "* vx_type();" +
		fnheaders +
		interfaces +
		"\n  };" +
		//		"\n  extern Func_" + funcname + "* e_" + funcname + ";" +
		//		"\n  extern Func_" + funcname + "* t_" + funcname + ";" +
		"\n"
	headerfooter := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  " + generictypes + returntype + " f_" + funcname + "(" + argtext + contextarg + ");" +
		"\n"
	return output, headerfooter
}

func CppNameEFromType(typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = "vx_core::f_empty(generic_" + CppFromName(typ.name) + ")"
	} else {
		output = "e_" + CppNameFromType(typ)
		if typ.pkgname != "" {
			output = CppNameFromPkgName(typ.pkgname) + "::" + output
		}
	}
	return output
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
	name := "t_" + CppNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = CppNameFromPkgName(fnc.pkgname) + "::" + name
	}
	return name
}

func CppNameTFromType(typ *vxtype) string {
	name := "t_" + CppNameFromType(typ)
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

func CppReplFromFunc(fnc *vxfunc) string {
	output := ""
	replparams := ""
	argidx := 0
	var listargname []string
	pkgname := CppNameFromPkgName(fnc.pkgname)
	funcname := CppFromName(fnc.alias) + CppIndexFromFunc(fnc)
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
				replparam := outputtype + "* generic_" + CppFromName(fnc.generictype.name) + " = vx_core::f_any_from_any(" + outputttype + ", arglist->vx_any(vx_core::t_int->vx_new_from_int(" + StringFromInt(argidx) + ")));"
				replparams += "\n      " + replparam
				listargname = append(listargname, "generic_"+CppFromName(fnc.generictype.name))
			}
		}
	}
	for _, arg := range fnc.listarg {
		if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
		} else {
			argname := CppFromName(arg.alias)
			replparam := CppNameTypeFromType(arg.vxtype) + "* " + argname + " = vx_core::f_any_from_any(" + CppNameTFromType(arg.vxtype) + ", arglist->vx_any(vx_core::t_int->vx_new_from_int(" + StringFromInt(argidx) + ")));"
			replparams += "\n      " + replparam
			listargname = append(listargname, argname)
			argidx += 1
		}
	}
	if fnc.context {
		listargname = append(listargname, "context")
		replparam := "vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(" + StringFromInt(argidx) + ")));"
		replparams += "\n      " + replparam
	}
	if fnc.async {
		output = "" +
			"\n    vx_core::Async<vx_core::Type_any*>* " + pkgname + "::Func_" + funcname + "::vx_repl(vx_core::Type_anylist* arglist) {" +
			"\n      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);" +
			replparams +
			"\n      vx_core::Async<" + outputtype + "*>* future = " + pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      output = vx_core::async_from_async(vx_core::t_any, future);" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	} else {
		output = "" +
			"\n    vx_core::Type_any* " + pkgname + "::Func_" + funcname + "::vx_repl(vx_core::Type_anylist* arglist) {" +
			"\n      vx_core::Type_any* output = vx_core::e_any;" +
			replparams +
			"\n      " + returnvalue + pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
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
			descvaluetext, msgs := CppFromValue(testvalue, testpkg, fnc, "            ", true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n        vx_test::t_testdescribe->vx_new(" +
				"\n          vx_core::t_string->vx_new_from_string(\":describename\"), vx_core::t_string->vx_new_from_string(\"" + CppTestFromValue(testvalue) + "\")," +
				"\n          vx_core::t_string->vx_new_from_string(\":testresult\")," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		output = "" +
			"\n  vx_test::Type_testcase* " + testcasename + "(vx_core::Type_context* context) {" +
			"\n    vx_test::Type_testcase* output = vx_test::t_testcase->vx_new(" +
			"\n      vx_core::t_string->vx_new_from_string(\":passfail\"), vx_core::c_false," +
			"\n      vx_core::t_string->vx_new_from_string(\":testpkg\"), vx_core::t_string->vx_new_from_string(\"" + testpkg + "\")," +
			"\n      vx_core::t_string->vx_new_from_string(\":casename\"), vx_core::t_string->vx_new_from_string(\"" + testname + "\")," +
			"\n      vx_core::t_string->vx_new_from_string(\":describelist\")," +
			"\n      vx_test::t_testdescribelist->vx_new(" + describelist +
			"\n      )" +
			"\n    );" +
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
	typetexts := ""
	for _, typid := range typkeys {
		covertypetotal += 1
		typ := pkg.maptype[typid]
		test, msgs := CppTestFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		covertype = append(covertype, "      vx_core::t_string->vx_new_from_string(\":"+typid+"\"), vx_core::t_int->vx_new_from_int("+StringFromInt(len(typ.testvalues))+")")
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(testall, pkgname+"_test::t_"+CppFromName(typ.alias)+"(context)")
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
	consttexts := ""
	for _, cnstid := range cnstkeys {
		coverconsttotal += 1
		cnst := pkg.mapconst[cnstid]
		test, msgs := CppTestFromConst(cnst)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		coverconst = append(coverconst, "      vx_core::t_string->vx_new_from_string(\":"+cnstid+"\"), vx_core::t_int->vx_new_from_int("+StringFromInt(len(cnst.listtestvalue))+")")
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(testall, pkgname+"_test::c_"+CppFromName(cnst.alias)+"(context)")
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
	functexts := ""
	for _, fncid := range fnckeys {
		coverfunctotal += 1
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			test, msgs := CppTestFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			coverfunc = append(coverfunc, "      vx_core::t_string->vx_new_from_string(\":"+fncid+CppIndexFromFunc(fnc)+"\"), vx_core::t_int->vx_new_from_int("+StringFromInt(len(fnc.listtestvalue))+")")
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(testall, pkgname+"_test::f_"+CppFromName(fnc.alias)+CppIndexFromFunc(fnc)+"(context)")
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
		frontdelim := "\n    arraylisttestcase->push_back("
		backdelim := ");"
		testalltext = "" +
			frontdelim + strings.Join(testall, backdelim+frontdelim) + backdelim
	}
	body := "" +
		typetexts +
		consttexts +
		functexts +
		"\n  vx_test::Type_testcaselist* test_cases(vx_core::Type_context* context) {" +
		"\n    std::vector<vx_core::Type_any*>* arraylisttestcase;" +
		testalltext +
		"\n    vx_test::Type_testcaselist* output = vx_test::t_testcaselist->vx_new(arraylisttestcase);" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testcoveragesummary* test_coveragesummary() {" +
		"\n    return vx_test::t_testcoveragesummary->vx_new(" +
		"\n      vx_core::t_string->vx_new_from_string(\":testpkg\"), vx_core::t_string->vx_new_from_string(\"" + pkg.name + "\")," +
		"\n      vx_core::t_string->vx_new_from_string(\":constnums\"), " + CppTypeCoverageNumsValNew(coverconstpct, coverconstcnt, coverconsttotal) + "," +
		"\n      vx_core::t_string->vx_new_from_string(\":docnums\"), " + CppTypeCoverageNumsValNew(coverdocpct, coverdoccnt, coverdoctotal) + "," +
		"\n      vx_core::t_string->vx_new_from_string(\":funcnums\"), " + CppTypeCoverageNumsValNew(coverfuncpct, coverfunccnt, coverfunctotal) + "," +
		"\n      vx_core::t_string->vx_new_from_string(\":ospacenums\"), " + CppTypeCoverageNumsValNew(coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + "," +
		"\n      vx_core::t_string->vx_new_from_string(\":otimenums\"), " + CppTypeCoverageNumsValNew(coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + "," +
		"\n      vx_core::t_string->vx_new_from_string(\":totalnums\"), " + CppTypeCoverageNumsValNew(coverpct, covercnt, covertotal) + "," +
		"\n      vx_core::t_string->vx_new_from_string(\":typenums\"), " + CppTypeCoverageNumsValNew(covertypepct, covertypecnt, covertypetotal) +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testcoveragedetail* test_coveragedetail() {" +
		"\n    return vx_test::t_testcoveragedetail->vx_new(" +
		"\n      vx_core::t_string->vx_new_from_string(\":testpkg\"), vx_core::t_string->vx_new_from_string(\"" + pkg.name + "\")," +
		"\n      vx_core::t_string->vx_new_from_string(\":typemap\"), vx_core::t_intmap->vx_new(" +
		"\n  " + strings.Join(covertype, ",\n  ") +
		"\n      )," +
		"\n      vx_core::t_string->vx_new_from_string(\":constmap\"), vx_core::t_intmap->vx_new(" +
		"\n  " + strings.Join(coverconst, ",\n  ") +
		"\n      )," +
		"\n      vx_core::t_string->vx_new_from_string(\":funcmap\"), vx_core::t_intmap->vx_new(" +
		"\n  " + strings.Join(coverfunc, ",\n  ") +
		"\n      )" +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testpackage* test_package(vx_core::Type_context* context) {" +
		"\n    vx_test::Type_testcaselist* testcaselist = test_cases(context);" +
		"\n    vx_test::Type_testpackage* output = vx_test::t_testpackage->vx_new(" +
		"\n      vx_core::t_string->vx_new_from_string(\":testpkg\"), vx_core::t_string->vx_new_from_string(\"" + pkg.name + "\"), " +
		"\n      vx_core::t_string->vx_new_from_string(\":caselist\"), testcaselist," +
		"\n      vx_core::t_string->vx_new_from_string(\":coveragesummary\"), test_coveragesummary()," +
		"\n      vx_core::t_string->vx_new_from_string(\":coveragedetail\"), test_coveragedetail()" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := CppImportsFromPackage(pkg, "", body, true)
	headertext := ""
	output := "" +
		imports +
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
		"vx_test::t_testcoveragenums->vx_new(" +
		"vx_core::t_string->vx_new_from_string(\":pct\"), vx_core::t_int->vx_new_from_int(" + StringFromInt(pct) + "), " +
		"vx_core::t_string->vx_new_from_string(\":tests\"), vx_core::t_int->vx_new_from_int(" + StringFromInt(tests) + "), " +
		"vx_core::t_string->vx_new_from_string(\":total\"), vx_core::t_int->vx_new_from_int(" + StringFromInt(total) + ")" +
		")"
}

func CppTypeDefFromType(typ *vxtype, indent string) string {
	lineindent := "\n" + indent
	allowtypes := CppTypeListFromListType(typ.allowtypes)
	disallowtypes := CppTypeListFromListType(typ.disallowtypes)
	allowfuncs := "vx_core::e_funclist"
	disallowfuncs := "vx_core::e_funclist"
	allowvalues := "vx_core::e_anylist"
	disallowvalues := "vx_core::e_anylist"
	properties := "vx_core::e_argmap"
	traits := CppTypeListFromListType(typ.traits)
	output := "" +
		"vx_core::Type_typedef::vx_typedef_new(" +
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
	return "vx_core::t_int->vx_new_from_int(" + StringFromInt(val) + ")"
}

func CppTypeListFromListType(listtype []*vxtype) string {
	output := "vx_core::e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := CppNameTFromType(typ)
			listtext = append(listtext, typetext)
		}
		output = "vx_core::t_typelist->vx_new(" + StringFromListStringJoin(listtext, ", ") + ")"
	}
	return output
}

func CppTypeStringValNew(val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return "vx_core::t_string->vx_new_from_string(\"" + valstr + "\")"
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
		targetpath += "/resources"
		msgs := CppFolderCopyTestdataFromProjectPath(prj, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func CppAppTest(prj *vxproject, pkgprefix string) string {
	listpackage := prj.listpackage
	var listtestpackage []string
	tests := ""
	imports := "" +
		"#include <iostream>" +
		"\n#include \"test_lib.cpp\"" +
		"\n"
	for _, pkg := range listpackage {
		pkgname := StringFromStringFindReplace(pkg.name, "/", "_")
		testpackage := "\n      " + pkgname + "_test::test_package(context)"
		listtestpackage = append(listtestpackage, testpackage)
		importline := "#include \"../" + pkg.name + "_test.cpp\"\n"
		imports += importline
		tests += "" +
			`
  // (package "` + pkg.name + `")
  bool test_` + pkgname + `() {
	  vx_test::Type_testpackage* testpackage = ` + pkgname + `_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }

`
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",")
	output := "" +
		imports +
		`
/**
 * Unit test for whole App.
 */
namespace app_test {

  vx_core::Type_context* context = vx_core::t_context->vx_new();

` + tests +
		`
	// test_writetestsuite
  vx_core::Type_boolean* test_writetestsuite() {
    vx_test::Type_testpackagelist* testpackagelist = vx_test::t_testpackagelist->vx_new(` +
		testpackages +
		`
    );
    return test_lib::write_testpackagelist_async(testpackagelist, context);
  }

	int main(int argc, char* argv[]) {
    std::string current_exec_name = argv[0]; // Name of the current exec program
    std::vector<std::string> all_args;
    if (argc > 1) {
      all_args.assign(argv + 1, argv + argc);
    }
    int output = 1;
    vx_core::Type_boolean* writetest = test_writetestsuite();
		vx_core::Type_string* stringwritetest = vx_core::f_string_from_any(writetest);
		std::string swritetest = stringwritetest->vx_string();
		std::cout << swritetest;
    return output;
  }

}
`
	return output
}

func CppTestLib() string {
	return "" +
		`#include "../../src/vx/core.hpp"
#include "../../src/vx/test.hpp"
#include "../../src/vx/data/file.hpp"

namespace test_lib {

  vx_test::Type_testresult* run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult* testresult) {
    vx_core::Type_any* valexpected = testresult->expected();
    vx_core::Type_any* valactual = testresult->actual();
    bool passfail = testresult->passfail()->vx_boolean();
    std::string code = testresult->code()->vx_string();
    std::string expected = vx_core::f_string_from_any(valexpected)->vx_string();
    std::string actual = vx_core::f_string_from_any(valactual)->vx_string();
    std::string msg = testpkg + "/" + testname + " " + message;
    if (!passfail) {
//      System.out.println(msg);
//      System.out.println(expected);
//      System.out.println(actual);
      vx_core::f_log(testresult);
    }
//    if (code == ":ne") {
//      assertNotEquals(expected, actual, msg);
//    } else {
//      assertEquals(expected, actual, msg);
//    }
    return testresult;
  }

  // Blocking
  vx_test::Type_testresult* run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult* testresult) {
    vx_core::Async<vx_test::Type_testresult*>* async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult* testresult_resolved = vx_core::sync_from_async(vx_test::t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }

  vx_test::Type_testdescribe* run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe* describe) {
    vx_core::Type_string* testcode = describe->describename();
    std::string message = testcode->vx_string();
    vx_test::Type_testresult* testresult = describe->testresult();
    vx_test::Type_testresult* testresultresolved = run_testresult(testpkg, casename, message, testresult);
    vx_test::Type_testdescribe* output = describe->vx_copy(vx_core::t_string->vx_new_from_string(":testresult"), testresultresolved);
		return output;
  }

  // Blocking
  // Only use if running a single testdescribe
  vx_test::Type_testdescribe* run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe* testdescribe) {
    vx_core::Async<vx_test::Type_testdescribe*>* async_testdescribe = vx_test::f_resolve_testdescribe(testdescribe);
    vx_test::Type_testdescribe* testdescribe_resolved = vx_core::sync_from_async(vx_test::t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  vx_test::Type_testdescribelist* run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist* testdescribelist) {
    std::vector<vx_test::Type_testdescribe*> listtestdescribe = testdescribelist->vx_listtestdescribe();
    std::vector<vx_test::Type_testdescribe*> listtestdescribe_resolved;
    for (vx_test::Type_testdescribe* testdescribe : listtestdescribe) {
      vx_test::Type_testdescribe* testdescribe_resolved = run_testdescribe(testpkg, casename, testdescribe);
			listtestdescribe_resolved.push_back(testdescribe_resolved);
    }
		vx_test::Type_testdescribelist* output = testdescribelist->vx_copy(&listtestdescribe_resolved);
    return output;
  }

	vx_test::Type_testcase* run_testcase(vx_test::Type_testcase* testcase) {
    std::string testpkg = testcase->testpkg()->vx_string();
    std::string casename = testcase->casename()->vx_string();
    vx_test::Type_testdescribelist* testdescribelist = testcase->describelist();
    vx_test::Type_testdescribelist* testdescribelist_resolved = run_testdescribelist(testpkg, casename, testdescribelist);
		vx_test::Type_testcase* output = testcase->vx_copy(vx_core::t_string->vx_new_from_string(":describelist"), testdescribelist_resolved);
		return output;
  }

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase* run_testcase_async(vx_test::Type_testcase* testcase) {
    vx_core::Async<vx_test::Type_testcase*>* async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_test::Type_testcase* testcase_resolved = vx_core::sync_from_async(vx_test::t_testcase, async_testcase);
    return run_testcase(testcase_resolved);
  }

	vx_test::Type_testcaselist* run_testcaselist(vx_test::Type_testcaselist* testcaselist) {
    std::vector<vx_test::Type_testcase*> listtestcase = testcaselist->vx_listtestcase();
    std::vector<vx_test::Type_testcase*> listtestcase_resolved;
    for (vx_test::Type_testcase* testcase : listtestcase) {
      vx_test::Type_testcase* testcase_resolved = run_testcase(testcase);
			listtestcase_resolved.push_back(testcase_resolved);
    }
		vx_test::Type_testcaselist* output = testcaselist->vx_copy(&listtestcase_resolved);
    return output;
  }

  vx_test::Type_testpackage* run_testpackage(vx_test::Type_testpackage* testpackage) {
    vx_test::Type_testcaselist* testcaselist = testpackage->caselist();
    vx_test::Type_testcaselist* testcaselist_resolved = run_testcaselist(testcaselist);
		vx_test::Type_testpackage* output = testpackage->vx_copy(vx_core::t_string->vx_new_from_string(":caselist"), testcaselist_resolved);
		return output;
  }

  vx_test::Type_testpackagelist* run_testpackagelist(vx_test::Type_testpackagelist* testpackagelist) {
    std::vector<vx_test::Type_testpackage*> listtestpackage = testpackagelist->vx_listtestpackage();
    std::vector<vx_test::Type_testpackage*> listtestpackage_resolved;
    for (vx_test::Type_testpackage* testpackage : listtestpackage) {
      vx_test::Type_testpackage* testpackage_resolved = run_testpackage(testpackage);
			listtestpackage_resolved.push_back(testpackage_resolved);
    }
		vx_test::Type_testpackagelist* output = testpackagelist->vx_copy(&listtestpackage_resolved);
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage* run_testpackage_async(vx_test::Type_testpackage* testpackage) {
    vx_core::Async<vx_test::Type_testpackage*>* async_testpackage = vx_test::f_resolve_testpackage(testpackage);
    vx_test::Type_testpackage* testpackage_resolved = vx_core::sync_from_async(vx_test::t_testpackage, async_testpackage);
    return run_testpackage(testpackage_resolved);
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist* run_testpackagelist_async(vx_test::Type_testpackagelist* testpackagelist) {
    vx_core::Async<vx_test::Type_testpackagelist*>* async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist* testpackagelist_resolved = vx_core::sync_from_async(vx_test::t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean* write_testpackagelist_async(vx_test::Type_testpackagelist* testpackagelist, vx_core::Type_context* context) {
    vx_core::Async<vx_test::Type_testpackagelist*>* async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist* testpackagelist_resolved = vx_core::sync_from_async(vx_test::t_testpackagelist, async_testpackagelist);
    vx_data_file::Type_file* filetest = vx_test::f_file_test();
    vx_core::Type_boolean* booleanwritetest = vx_data_file::f_boolean_write_from_file_any(filetest, testpackagelist_resolved, context);
    vx_web_html::Type_div* divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html* htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_data_file::Type_file* filenode = vx_test::f_file_testnode();
    vx_core::Type_boolean* booleanwritenode = vx_data_file::f_boolean_write_from_file_any(filenode, htmlnode, context);
    vx_data_file::Type_file* filehtml = vx_test::f_file_testhtml();
    vx_core::Type_string* shtml = vx_web_html::f_string_from_html(htmlnode);
    vx_core::Type_boolean* booleanwritehtml = vx_data_file::f_boolean_write_from_file_string(filehtml, shtml, context);
    vx_core::Type_boolean* output = vx_core::t_boolean->vx_new(booleanwritetest, booleanwritenode, booleanwritehtml);
    return output;
  }

}
`
}
