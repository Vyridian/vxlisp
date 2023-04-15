package vxlisp

import (
	"strings"
)

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
				lineindent + "vx_core::constdef_new(" +
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
			file.name = pkgname + ".h"
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
		cnstval = "\n      this->vxboolean = " + cnstval + ";"
		initval = "" +
			"\n    bool vx_boolean() {" +
			cnstval +
			"\n      return this->vxboolean;" +
			"\n    }"
	case "vx/core/decimal":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this->vxdecimal = " + cnstval + ";"
		initval = "" +
			"\n    String vx_decimal() {" +
			cnstval +
			"\n      return this->vxdecimal;" +
			"\n    }"
	case "vx/core/float":
		if cnstval == "" {
			cnstval = "f0"
		}
		cnstval = "\n      this->vxfloat = " + cnstval + ";"
		initval = "" +
			"\n    float vx_float() {" +
			cnstval +
			"\n      return this->vxdecimal;" +
			"\n    }"
	case "vx/core/int":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this->vxint = " + cnstval + ";"
		initval = "" +
			"\n    int vx_int() {" +
			cnstval +
			"\n      return this->vxint;" +
			"\n    }"
	case "vx/core/string":
		cnstval = "\n      this->vxstring = " + cnstval + ";"
		initval = "" +
			"\n    String vx_string() {" +
			cnstval +
			"\n      return this->vxstring;" +
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
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output.vxlist" + listtypename + " = val.vx_list" + listtypename + "();"
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
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output.vxmap" + maptypename + " = val.vx_map" + maptypename + "();"
			}
		case ":struct":
			clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";"
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						"\n      output.vx_p_" + CppFromName(prop.name) + " = val." + CppFromName(prop.name) + "();"

				}
			}
			/*
				clstext, msgs := CppFromValue(cnst.value, cnst.pkgname, emptyfunc, "        ", true, false, path)
				msgblock = MsgBlockAddBlock(msgblock, msgs)
				if clstext != "" {
					cnstval = "" +
						"\n      if ((this->vxmap == null) || (this->vxmap.size() == 0)) {" +
						"\n        " + cnsttypeclassname + " orig = " + clstext + ";" +
						"\n        this->vxmap = orig.vx_map();" +
						"\n      }"
					initval = "" +
						"\n    @Override" +
						"\n    std::map<std::string, vx_core::Type_any> vx_map() {" +
						cnstval +
						"\n      return this->vxmap;" +
						"\n    }"
				}
			*/
		}
	}
	extends := CppNameTypeFullFromType(cnsttype)
	headers := "" +
		"\n  // (const " + cnst.name + ")" +
		"\n  class " + cnstclassname + " : " + extends + " {" +
		"\n    vx_core::Type_constdef constdef();" +
		"\n    " + cnstclassname + " const_new();" +
		"\n  };" +
		"\n  const " + cnstclassname + " c_" + cnstname + ";" +
		"\n"
	output := "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  class " + cnstclassname + " : " + extends + " {" +
		"\n" +
		"\n    vx_core::Type_constdef constdef() {" +
		"\n      return vx_core::constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + CppTypeDefFromType(cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    " + cnstclassname + " const_new() {" +
		"\n      Const_" + cnstname + " output = new " + cnstclassname + "();" +
		const_new +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		initval +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  const " + cnstclassname + " c_" + cnstname + " = " + cnstclassname + ".const_new();" +
		"\n" +
		"\n"
	return output, headers, msgblock
}

func CppFromFunc(fnc *vxfunc) (string, string, *vxmsgblock) {
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
	f_suppresswarnings := ""
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
			argtext := "final T generic_any_1"
			listargtype = append(listargtype, argtext)
		default:
			if fnc.generictype != nil {
				genericargname := CppNameTFromTypeGeneric(fnc.generictype)
				argtext := "final " + CppGenericFromType(fnc.generictype) + " " + genericargname
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
	case "vx/core/let-async":
		argtext := "vx_core::Func_any_from_func_async fn_any_async"
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
			argtext := "final " + argtypename + " " + CppFromName(arg.alias)
			listargname = append(listargname, CppFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	if fnc.context {
		listargtype = append(listargtype, "final vx_core::Type_context context")
		listargname = append(listargname, "context")
	}
	//var funcgenerics []string
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = CppGenericFromType(fnc.generictype)
	} else {
		functypetext = returntype
	}
	if fnc.async {
		functypetext = "std::future<" + functypetext + ">"
	}
	contextarg := ""
	if fnc.context {
		contextarg = ", vx_core::Type_context context"
	}
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-context", "vx/core/any<-func",
		"vx/core/any<-none", "vx/core/any<-key-value",
		"vx/core/any<-reduce", "vx/core/any<-reduce-next":
		instancevars += "" +
			"\n    IFn fn = null;" +
			"\n" +
			"\n    Func_" + funcname + " fn_new(vx_core::Func_" + funcname + "::IFn fn) {" +
			"\n      Func_" + funcname + " output;" +
			"\n      output.fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async",
		"vx/core/any<-none-async", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce-async", "vx/core/any<-reduce-next-async":
		instancevars += "" +
			"\n    IFn fn = null;" +
			"\n" +
			"\n    // static" +
			"\n    Func_" + funcname + " fn_new(vx_core::Func_" + funcname + "::IFn fn) {" +
			"\n      Func_" + funcname + " output;" +
			"\n      output.fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/string<-func":
		instancefuncs += "" +
			"\n    vx_core::Func_any_from_func::IFn fn = null;" +
			"\n" +
			"\n    Func_" + funcname + " fn_new(vx_core::Func_any_from_func::IFn fn) {" +
			"\n      Func_" + funcname + " output;" +
			"\n      output.fn = fn;" +
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
							"\n      T inputval = vx_core::f_any_from_any(generic_any_1, value);" +
							"\n      std::future<T> output = vx_core::f_async(generic_any_1, inputval);"
					} else {
						asyncbody += "" +
							"\n      " + CppNameTypeFromType(arg.vxtype) + " inputval = vx_core::f_any_from_any(" + CppNameTFromType(arg.vxtype) + ", value);" +
							"\n      std::future<" + returntype + "> future = " + pkgname + "::f_" + funcname + "(" + subargnames + ");" +
							"\n      std::future<T> output = (std::future<T>)future;"
					}
					instancefuncs += "" +
						"\n    vx_core::Func_any_from_any" + contextname + "_async fn_new(vx_core::Func_any_from_any" + contextname + "_async::IFn fn) {return vx_core::e_any_from_any" + contextname + "_async;}" +
						"\n" +
						"\n    template <class T, class U> std::future<T> f_any_from_any" + contextname + "_async(T generic_any_1, final U value" + contextarg + ") {" +
						asyncbody +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					instancefuncs += "" +
						"\n    vx_core::Func_any_from_any" + contextname + " fn_new(vx_core::Func_any_from_any" + contextname + "::IFn fn) {return vx_core::e_any_from_any" + contextname + ";}" +
						"\n" +
						"\n    template <class T, class U> T f_any_from_any" + contextname + "(T generic_any_1, final U value" + contextarg + ") {" +
						"\n      T output = vx_core::f_empty(generic_any_1);" +
						"\n      " + argtypename + " inputval = (" + argtypename + ")value;" +
						"\n      vx_core::Type_any outputval = " + pkgname + "::f_" + funcname + "(" + subargnames + ");" +
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
	for _, item := range valuetexts {
		if BooleanFromStringContains(item, "@SuppressWarnings") {
			f_suppresswarnings += "\n  " + StringTrim(StringFromStringFindReplace(item, "\\\"", "\""))
		} else {
			chgvaluetexts = append(chgvaluetexts, item)
		}
	}
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
			lineindent + "  vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"Permission Denied: " + fnc.name + "\");" +
			lineindent + "  output = output.vx_copy(msg);" +
			lineindent + "}"
		indent += "  "
	}
	if fnc.messages {
		msgtop = lineindent + "try {"
		msgbottom = "" +
			lineindent + "} catch (std::exception err) {" +
			lineindent + "  vx_core::Type_msg msg = vx_core::t_msg.vx_new_from_exception(\"" + fnc.name + "\", err);" +
			lineindent + "  output = output.vx_copy(msg);" +
			lineindent + "}"
		indent += "  "
	}
	lineindent = "\n" + indent
	valuetext = StringFromListStringJoin(chgvaluetexts, "\n")
	if IntFromStringIndex(valuetext, "output ") >= 0 {
	} else if IntFromStringIndex(valuetext, "output.") >= 0 {
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
	switch NameFromFunc(fnc) {
	case "vx/core/new":
		f_suppresswarnings = "\n  @SuppressWarnings(\"unchecked\")"
	}
	returnvalue := ""
	interfacefn := CppHeaderFnFromFunc(fnc)
	if interfacefn == "" {
		if returntype != "void" {
			returnvalue += "\n      return "
		}
		returnvalue += pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");"
	} else if fnc.async {
		returnvalue += "" +
			"\n      std::future<T> output;" +
			"\n      if (fn == null) {" +
			"\n        output = std::future.completedFuture(vx_core::f_empty(generic_any_1));" +
			"\n      } else {" +
			"\n        std::future<vx_core::Type_any> future = fn.resolve(" + strings.Join(listargname, ", ") + ");" +
			"\n        output = vx_core::async_from_async(generic_any_1, future);" +
			"\n      }" +
			"\n      return output;"
	} else {
		if BooleanFromStringStarts(fnc.name, "boolean<-") {
			returnvalue += "" +
				"\n      vx_core::Type_boolean output = vx_core::c_false;" +
				"\n      if (fn != null) {" +
				"\n        output = vx_core::f_any_from_any(vx_core::t_boolean, fn.resolve(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		} else {
			returnvalue += "" +
				"\n      T output = vx_core::f_empty(generic_any_1);" +
				"\n      if (fn != null) {" +
				"\n        output = vx_core::f_any_from_any(generic_any_1, fn.resolve(" + strings.Join(listargname, ", ") + "));" +
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
			defaultvalue = lineindent + "std::future<" + returntype + "> output = vx_core::async_new_completed(" + CppNameEFromType(fnc.vxtype) + ");"
		} else if fnc.generictype != nil {
			defaultvalue = lineindent + returntype + " output = vx_core::f_empty(" + CppNameTFromTypeGeneric(fnc.generictype) + ");"
		} else {
			defaultvalue = lineindent + returntype + " output = " + CppNameEFromType(fnc.vxtype) + ";"
		}
	}
	headertext := CppHeaderFromFunc(fnc)
	doc := CppDocFromFunc(fnc)
	output := "" +
		doc +
		"\n  class Type_" + funcname + " : vx_core::Type_base {" +
		"\n" +
		instancevars +
		"\n    Func_" + funcname + " vx_new(std::any vals...) {" +
		"\n      Func_" + funcname + " output;" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    Func_" + funcname + " vx_copy(std::any vals...) {" +
		"\n      Func_" + funcname + " output;" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    vx_core::Type_typedef vx_typedef() {return vx_core::t_func.vx_typedef();}" +
		"\n" +
		"\n    vx_core::Type_funcdef vx_funcdef() {" +
		"\n      return vx_core::funcdef_new(" +
		"\n        \"" + fnc.pkgname + "\", // pkgname" +
		"\n        \"" + fnc.name + "\", // name" +
		"\n        " + StringFromInt(fnc.idx) + ", // idx" +
		"\n        " + StringFromBoolean(fnc.async) + ", // async" +
		"\n        " + CppTypeDefFromType(fnc.vxtype, "        ") + " // typedef" +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    Func_" + funcname + " vx_empty() {return e_" + funcname + ";}" +
		"\n    Func_" + funcname + " vx_type() {return t_" + funcname + ";}" +
		"\n" +
		staticvars +
		instancefuncs +
		"\n    " + genericdefinition + functypetext + " f_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		staticfuncs +
		returnvalue +
		"\n    }" +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  const " + CppNameFromPkgName(fnc.pkgname) + "::Func_" + funcname + " e_" + funcname + ";" +
		"\n  const " + CppNameFromPkgName(fnc.pkgname) + "::Func_" + funcname + " t_" + funcname + ";" +
		"\n" +
		f_suppresswarnings +
		"\n  static " + genericdefinition + functypetext + " f_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		debugtop +
		defaultvalue +
		permissiontop +
		msgtop +
		valuetext +
		msgbottom +
		permissionbottom +
		debugbottom +
		after
	return output, headertext, msgblock
}

func CppFuncDefsFromFuncs(funcs []*vxfunc, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(funcs) > 0 {
		var outputtypes []string
		for _, fnc := range funcs {
			name := "" +
				lineindent + "  vx_core::funcdef_new(" +
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
	specialheader := ""
	specialcode := ""
	switch pkg.name {
	case "vx/core":
		specialheader = "" +
			"\n  class Type_replfunc {" +
			"\n    vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);" +
			"\n  };" +
			"\n" +
			"\n  class Type_replfunc_async {" +
			"\n    std::future<vx_core::Type_any> vx_repl(vx_core::Type_anylist arglist);" +
			"\n  };" +
			"\n" +
			"\n  class Type_base {" +
			"\n    protected:" +
			"\n      int vx_iref;" +
			"\n      vx_core::Type_msgblock vxmsgblock;" +
			"\n      std::vector<Type_any> vx_dispose();" +
			"\n      vx_core::Type_msgblock vx_msgblock();" +
			"\n      bool vx_release();" +
			"\n      void vx_reserve();" +
			"\n  };" +
			"\n"
		specialcode = "" +
			"\n  class Type_base {" +
			"\n    protected:" +
			"\n      int vx_iref = 0;" +
			"\n      vx_core::Type_msgblock vxmsgblock = null;" +
			"\n      std::vector<vx_core::Type_any> Type_base::vx_dispose() {" +
			"\n        this->vx_iref = 0;" +
			"\n        this->vxmsgblock = null;" +
			"\n        return emptylistany;" +
			"\n      }" +
			"\n      vx_core::Type_msgblock vx_msgblock() {return vxmsgblock;}" +
			"\n      bool vx_release() {" +
			"\n        bool output = false;" +
			"\n        if (this->vx_iref < 0) {" +
			"\n        } else if (vx_iref == 0) {" +
			"\n          vx_iref = -1;" +
			"\n          output = true;" +
			"\n        } else {" +
			"\n          vx_iref -= 1;" +
			"\n        }" +
			"\n        return output;" +
			"\n      }" +
			"\n      void vx_reserve() {this->vx_iref += 1;}" +
			"\n  }" +
			"\n" +
			"\n  vx_core::Type_typedef typedef_new(" +
			"\n    String pkgname," +
			"\n    String name," +
			"\n    String extend," +
			"\n    vx_core::Type_typelist traits," +
			"\n    vx_core::Type_typelist allowtypes," +
			"\n    vx_core::Type_typelist disallowtypes," +
			"\n    vx_core::Type_funclist allowfuncs," +
			"\n    vx_core::Type_funclist disallowfuncs," +
			"\n    vx_core::Type_anylist allowvalues," +
			"\n    vx_core::Type_anylist disallowvalues," +
			"\n    vx_core::Type_argmap properties" +
			"\n  ) {" +
			"\n    vx_core::Type_typedef output;" +
			"\n    output.vx_p_pkgname = vx_core::t_string.vx_new_from_string(pkgname);" +
			"\n    output.vx_p_name = vx_core::t_string.vx_new_from_string(name);" +
			"\n    output.vx_p_extend = vx_core::t_string.vx_new_from_string(extend);" +
			"\n    output.vx_p_traits = traits;" +
			"\n    output.vx_p_allowtypes = allowtypes;" +
			"\n    output.vx_p_disallowtypes = disallowtypes;" +
			"\n    output.vx_p_allowfuncs = disallowfuncs;" +
			"\n    output.vx_p_disallowfuncs = disallowfuncs;" +
			"\n    output.vx_p_allowvalues = disallowvalues;" +
			"\n    output.vx_p_disallowvalues = disallowvalues;" +
			"\n    output.vx_p_properties = properties;" +
			"\n    return output;" +
			"\n  }" +
			"\n"
		/*
			specialcode = "" +
				"\n" +
				"\n  static std::vector<vx_core::Type_any> emptylistany = vx_core::immutablelist(new Arraystd::vector<vx_core::Type_any>());" +
				"\n" +
				"\n  static std::map<std::string, vx_core::Type_any> emptymapany = vx_core::immutablemap(new LinkedHashstd::map<std::string, vx_core::Type_any>());" +
				"\n" +
				"\n  static <T> std::vector<T> immutablelist(std::vector<T> listany) {" +
				"\n    return Collections.unmodifiableList(listany);" +
				"\n  }" +
				"\n" +
				"\n  static <T> std::map<std::string, T> immutablemap(std::map<std::string, T> mapany) {" +
				"\n    return Collections.unmodifiableMap(mapany);" +
				"\n  }" +
				"\n" +
				"\n  static class KeyValue<T> {" +
				"\n    String key = \"\";" +
				"\n    T value = null;" +
				"\n  }" +
				"\n" +
				"\n  static vx_core::Type_constdef constdef_new(" +
				"\n    String pkgname," +
				"\n    String name," +
				"\n    vx_core::Type_any typ" +
				"\n  ) {" +
				"\n    vx_core::Type_constdef output;" +
				"\n    output.vx_p_pkgname = vx_core::t_string.vx_new_from_string(pkgname);" +
				"\n    output.vx_p_name = vx_core::t_string.vx_new_from_string(name);" +
				"\n    output.vx_p_type = typ;" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static vx_core::Type_funcdef funcdef_new(" +
				"\n    String pkgname," +
				"\n    String name," +
				"\n    int idx," +
				"\n    bool async," +
				"\n    vx_core::Type_any typ" +
				"\n  ) {" +
				"\n    vx_core::Type_funcdef output;" +
				"\n    output.vx_p_pkgname = vx_core::t_string.vx_new_from_string(pkgname);" +
				"\n    output.vx_p_name = vx_core::t_string.vx_new_from_string(name);" +
				"\n    output.vx_p_idx = vx_core::t_int.vx_new_from_int(idx);" +
				"\n    output.vx_p_async = vx_core::t_boolean.vx_new_from_boolean(async);" +
				"\n    output.vx_p_type = typ;" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static vx_core::Type_any[] arrayany_from_anylist(vx_core::Type_anylist list) {" +
				"\n    return list.vx_list().toArray(new vx_core::Type_any[0]);" +
				"\n  }" +
				"\n" +
				"\n  @SafeVarargs" +
				"\n  static <T> std::vector<T> arraylist_from_array(T items...) {" +
				"\n    std::vector<T> output = new Arraystd::vector<T>(Arrays.asList(items));" +
				"\n    output = vx_core::immutablelist(output);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T extends vx_core::Type_any, U extends vx_core::Type_any> std::vector<T> arraylist_from_arraylist(T generic_any_1, final std::vector<U> listval) {" +
				"\n    std::vector<T> output = new Arraystd::vector<>();" +
				"\n    for (vx_core::Type_any value : listval) {" +
				"\n      T t_val = vx_core::f_any_from_any(generic_any_1, value);" +
				"\n      output.add(t_val);" +
				"\n    }" +
				"\n    output = vx_core::immutablelist(output);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T, U> std::vector<T> arraylist_from_arraylist_fn(std::vector<U> listval, final Function<U, T> fn_any_from_any) {" +
				"\n    std::vector<T> output = new Arraystd::vector<>();" +
				"\n    for (U value_u : listval) {" +
				"\n      T t_val = fn_any_from_any.apply(value_u);" +
				"\n      output.add(t_val);" +
				"\n    }" +
				"\n    output = vx_core::immutablelist(output);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T extends vx_core::Type_any, U extends vx_core::Type_any> std::vector<T> arraylist_from_linkedhashmap(T generic_any_1, final std::map<std::string, U> mapval) {" +
				"\n    std::vector<T> output = new Arraystd::vector<T>();" +
				"\n    Set<String> keys = mapval.keySet();" +
				"\n    for (String key : keys) {" +
				"\n      U u_val = mapval.get(key);" +
				"\n      T t_val = vx_core::f_any_from_any(generic_any_1, u_val);" +
				"\n      output.add(t_val);" +
				"\n    }" +
				"\n    output = vx_core::immutablelist(output);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T, U> std::vector<T> arraylist_from_linkedhashmap_fn(std::map<std::string, U> mapval, final BiFunction<String, U, T> fn_any_from_key_value) {" +
				"\n    std::vector<T> output = new Arraystd::vector<T>();" +
				"\n    Set<String> keys = mapval.keySet();" +
				"\n    for (String key : keys) {" +
				"\n      U u_val = mapval.get(key);" +
				"\n      T t_val = fn_any_from_key_value.apply(key, u_val);" +
				"\n      output.add(t_val);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T> std::future<T> async_new_completed(T val) {" +
				"\n    std::future<T> output = std::future.completedFuture(val);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T extends vx_core::Type_any, U extends vx_core::Type_any> std::future<T> async_from_async(T generic_any_1, final std::future<U> future) {" +
				"\n    std::future<T> output = future.thenApply(val -> {" +
				"\n      return vx_core::f_any_from_any(generic_any_1, val);" +
				"\n    });" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T, U> std::future<T> async_from_async_fn(std::future<U> future, final Function<? super U, ? extends T> fn) {" +
				"\n    std::future<T> output = future.thenApply(fn);" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T> std::future<std::vector<T>> async_arraylist_from_arraylist_async(std::vector<std::future<T>> list_future) {" +
				"\n    std::future<Void> allFutures = std::future.allOf(" +
				"\n      list_future.toArray(new std::future[list_future.size()])" +
				"\n    );" +
				"\n    std::future<std::vector<T>> output = allFutures.thenApply(v -> {" +
				"\n      std::vector<T> list = list_future.stream()" +
				"\n        .map(future -> future.join())" +
				"\n        .collect(Collectors.toList());" +
				"\n      return vx_core::immutablelist(list);" +
				"\n    });" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static void debug(std::any values...) {" +
				"\n    for (Object value : values) {" +
				"\n      String text = \"\";" +
				"\n      if (value == null) {" +
				"\n        text = \"null\";" +
				"\n      } else if (value instanceof vx_core::Type_any) {" +
				"\n        vx_core::Type_any val_any = (vx_core::Type_any)value;" +
				"\n        vx_core::Type_string valstring = vx_core::f_string_from_any(val_any);" +
				"\n        text = valstring.vx_string();" +
				"\n      } else {" +
				"\n        text = value.toString();" +
				"\n      }" +
				"\n      System.out.println(text);" +
				"\n    }" +
				"\n  }" +
				"\n" +
				"\n  @SafeVarargs" +
				"\n  static <T> LinkedHashstd::map<std::string, T> hashmap_from_keyvalues(KeyValue<T> keyvalues...) {" +
				"\n    LinkedHashstd::map<std::string, T> output = new LinkedHashstd::map<std::string, T>();" +
				"\n    for (KeyValue<T> keyvalue : keyvalues) {" +
				"\n      String key = keyvalue.key;" +
				"\n      T value = keyvalue.value;" +
				"\n      output.put(key, value);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T> KeyValue<T> keyvalue_from_key_value(String key, final T value) {" +
				"\n    KeyValue<T> output;" +
				"\n    output.key = key;" +
				"\n    output.value = value;" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T> std::map<std::string, T> map_from_list_fn(std::vector<T> listval, final Function<T, vx_core::Type_string> fn_any_from_any) {" +
				"\n    std::map<std::string, T> output;" +
				"\n    for (T val : listval) {" +
				"\n      vx_core::Type_string valkey = fn_any_from_any.apply(val);" +
				"\n      String key = valkey.vx_string();" +
				"\n      output.put(key, val);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  static <T extends vx_core::Type_any> LinkedHashstd::map<std::string, T> map_from_map(LinkedHashstd::map<std::string, vx_core::Type_any> mapval) {" +
				"\n    LinkedHashstd::map<std::string, T> output;" +
				"\n    Set<String> keys = mapval.keySet();" +
				"\n    for (String key : keys) {" +
				"\n      vx_core::Type_any value = mapval.get(key);" +
				"\n      try {" +
				"\n        @SuppressWarnings(\"unchecked\")" +
				"\n        T castval = (T)value;" +
				"\n        output.put(key, castval);" +
				"\n      } catch (Exception ex) {" +
				"\n        vx_core::debug(\"std::map<-map\", ex);" +
				"\n      }" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
				"\n  // Warning!: Blocking" +
				"\n  static <T extends vx_core::Type_any> T sync_from_async(T generic_any_1, final std::future<T> future) {" +
				"\n    T output = vx_core::f_empty(generic_any_1);" +
				"\n    try {" +
				"\n      output = future.get();" +
				"\n    } catch (Exception e) {" +
				"\n      vx_core::Type_msg msg = vx_core::t_msg.vx_new_from_exception(\"sync<-async\", e);" +
				"\n      vx_core::Type_any val = generic_any_1.vx_new(msg);" +
				"\n      output = vx_core::f_any_from_any(generic_any_1, val);" +
				"\n    }" +
				"\n    return output;" +
				"\n  }" +
				"\n" +
		*/
	}
	typkeys := ListKeyFromMapType(pkg.maptype)
	typeheaders := ""
	typetexts := ""
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typetext, typeheader, msgs := CppFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typetexts += typetext
		typeheaders += typeheader
	}
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	constheaders := ""
	consttexts := ""
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, constheader, msgs := CppFromConst(cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
		constheaders += constheader
	}
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	funcheaders := ""
	functexts := ""
	for _, fncid := range fnckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fnctext, fncheader, msgs := CppFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			functexts += fnctext
			funcheaders += fncheader
		}
	}
	body := "" +
		specialcode +
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
		specialheader +
		typeheaders +
		constheaders +
		funcheaders +
		"\n}" +
		"\n"
	output := "" +
		imports +
		"#include \"" + pkg.name + ".h\"" +
		"\n" +
		"\nnamespace " + pkgname + " {" +
		"\n" +
		body +
		"\n}" +
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

func CppFromType(typ *vxtype) (string, string, *vxmsgblock) {
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
	typename := CppFromName(typ.alias)
	instancefuncs := ""
	createtext, msgs := CppFromValue(typ.createvalue, "", emptyfunc, "    ", true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		instancefuncs += "\n    " + createtext + "\n"
	}
	staticfuncs := ""
	valnew := ""
	extendinterface := ""
	extendsclass := " : vx_core::Type_base"
	valcopy := ""
	switch NameFromType(typ) {
	case "vx/core/any":
		valnew += "" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/anytype":
		extendinterface = "vx_core::Type_any"
	case "vx/core/const":
	case "vx/core/list":
		extendinterface = "vx_core::Type_anytype"
		instancefuncs += "" +
			"\n" +
			"\n    template <class T> std::vector<T> vx_any(T generic_any_1) {" +
			"\n      return vx_core::arraylist_from_arraylist(generic_any_1, this->vx_list());" +
			"\n    }" +
			"\n" +
			"\n    template <class T> T vx_any_from_list(T generic_any_1, final int index) {" +
			"\n      return vx_any_from_list(generic_any_1, this->vx_list(), index);" +
			"\n    }" +
			"\n"
		staticfuncs = "" +
			"\n    template <class T> std::vector<T> list_new(T generic_any_1, final vx_core::Type_any vals...) {" +
			"\n      std::vector<vx_core::Type_any> listval = Arrays.asList(vals);" +
			"\n      return vx_core::arraylist_from_arraylist(generic_any_1, listval);" +
			"\n    }" +
			"\n" +
			"\n    template <class T> T vx_any_from_list(T generic_any_1, final std::vector<vx_core::Type_any> list, final int index) {" +
			"\n      T output = vx_core::f_empty(generic_any_1);" +
			"\n      if (list.size() > index) {" +
			"\n        output = vx_core::f_any_from_any(generic_any_1, list.get(index));" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    template <class T> T vx_any_first_from_list_fn(T generic_any_1, final vx_core::Type_list list, final Function<vx_core::Type_any, T> fn_any) {" +
			"\n      T output = vx_core::f_empty(generic_any_1);" +
			"\n      std::vector<vx_core::Type_any> listany = list.vx_list();" +
			"\n      for (vx_core::Type_any any : listany) {" +
			"\n        T tany = vx_core::f_any_from_any(generic_any_1, any);" +
			"\n        T val = fn_any.apply(tany);" +
			"\n        if (val != null) {" +
			"\n          output = val;" +
			"\n          break;" +
			"\n        }" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/map":
		extendinterface = "vx_core::Type_anytype"
	case "vx/core/struct":
		extendinterface = "vx_core::Type_map"
	case "vx/core/func":
		extendinterface = "vx_core::Type_anytype"
		instancefuncs += "" +
			"\n    vx_core::Type_funcdef vx_funcdef() {" +
			"\n      return vx_core::e_funcdef;" +
			"\n    }"
	case "vx/core/type":
		extendinterface = "vx_core::Type_anytype"
	case "vx/core/boolean":
		valcopy = "" +
			"\n      vx_core::Type_boolean val = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxboolean = val.vx_boolean();"
		valnew = "" +
			"\n      bool booleanval = false;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_boolean) {" +
			"\n          vx_core::Type_boolean valboolean = (vx_core::Type_boolean)valsub;" +
			"\n          booleanval = booleanval || valboolean.vx_boolean();" +
			"\n        } else if (valsub instanceof Boolean) {" +
			"\n          booleanval = booleanval || (Boolean)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxboolean = booleanval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/decimal":
		extendinterface = "vx_core::Type_number"
		valcopy = "" +
			"\n      vx_core::Type_decimal val = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxdecimal = val.vx_string();"
		valnew = "" +
			"\n      String sval = \"\";" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_string) {" +
			"\n          vx_core::Type_string valstring = (vx_core::Type_string)valsub;" +
			"\n          sval = valstring.vx_string();" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          sval = (String)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxdecimal = sval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/float":
		extendinterface = "vx_core::Type_number"
		valcopy = "" +
			"\n      vx_core::Type_float val = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxfloat = val.vx_float();"
		valnew = "" +
			"\n      float floatval = 0;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_decimal) {" +
			"\n          vx_core::Type_decimal valnum = (vx_core::Type_decimal)valsub;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (valsub instanceof vx_core::Type_float) {" +
			"\n          vx_core::Type_float valnum = (vx_core::Type_float)valsub;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (valsub instanceof vx_core::Type_int) {" +
			"\n          vx_core::Type_int valnum = (vx_core::Type_int)valsub;" +
			"\n          floatval += valnum.vx_int();" +
			"\n        } else if (valsub instanceof vx_core::Type_string) {" +
			"\n          vx_core::Type_string valstring = (vx_core::Type_string)valsub;" +
			"\n          floatval += Float.parseFloat(valstring.vx_string());" +
			"\n        } else if (valsub instanceof Float) {" +
			"\n          floatval += (Float)valsub;" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          floatval += (Integer)valsub;" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          floatval += Float.parseFloat((String)valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxfloat = floatval;" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/int":
		extendinterface = "vx_core::Type_number"
		valcopy = "" +
			"\n      vx_core::Type_int val = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxint = val.vx_int();"
		valnew = "" +
			"\n      int intval = 0;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_int) {" +
			"\n          vx_core::Type_int valnum = (vx_core::Type_int)valsub;" +
			"\n          intval += valnum.vx_int();" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          intval += (Integer)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxint = intval;" +
			"\n      if (msgblock != vx_core::t_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		valcopy = "" +
			"\n      vx_core::Type_string val = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxstring = val.vx_string();"
		valnew = "" +
			"\n      StringBuilder sb = new StringBuilder(output.vx_string());" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_string) {" +
			"\n          vx_core::Type_string valstring = (vx_core::Type_string)valsub;" +
			"\n          sb.append(valstring.vx_string());" +
			"\n        } else if (valsub instanceof vx_core::Type_int) {" +
			"\n          vx_core::Type_int valint = (vx_core::Type_int)valsub;" +
			"\n          sb.append(valint.vx_int());" +
			"\n        } else if (valsub instanceof vx_core::Type_float) {" +
			"\n          vx_core::Type_float valfloat = (vx_core::Type_float)valsub;" +
			"\n          sb.append(valfloat.vx_float());" +
			"\n        } else if (valsub instanceof vx_core::Type_decimal) {" +
			"\n          vx_core::Type_decimal valdecimal = (vx_core::Type_decimal)valsub;" +
			"\n          sb.append(valdecimal.vx_string());" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          sb.append((String)valsub);" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          sb.append((Integer)valsub);" +
			"\n        } else if (valsub instanceof Float) {" +
			"\n          sb.append((Float)valsub);" +
			"\n        } else {" +
			"\n          vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Type: \" + valsub.toString());" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxstring = sb.toString();" +
			"\n      if (msgblock != vx_core::t_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	}
	switch typ.extends {
	case ":list":
		allowcode := ""
		allowname := "any"
		allowclass := "vx_core::Type_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = CppNameTypeFullFromType(allowtype)
			allowempty := CppNameEFromType(allowtype)
			allowname = CppNameFromType(allowtype)
			allowcode = "" +
				"\n    " + allowclass + " vx_" + allowname + "(vx_core::Type_int index) {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      Type_" + typename + " list = this;" +
				"\n      int iindex = index.vx_int();" +
				"\n      std::vector<" + allowclass + "> listval = list.vxlist;" +
				"\n      if (iindex < listval.size()) {" +
				"\n        output = listval.get(iindex);" +
				"\n      }" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		}
		if allowname == "any" {
			allowname = ""
		} else {
			allowcode += "" +
				"\n    std::vector<" + allowclass + "> vx_list" + allowname + "() {return vxlist;}" +
				"\n" +
				"\n    vx_core::Type_any vx_any(vx_core::Type_int index) {" +
				"\n      return this->vx_" + allowname + "(index);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    protected std::vector<" + allowclass + "> vxlist = vx_core::immutablelist(new Arraystd::vector<" + allowclass + ">());" +
			"\n" +
			"\n    std::vector<vx_core::Type_any> vx_list() {return vx_core::immutablelist(new Arraystd::vector<vx_core::Type_any>(this->vxlist));}" +
			"\n" +
			allowcode
		valcopy = "" +
			"\n      Type_" + typename + " val = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      std::vector<" + allowclass + "> listval = new Arraystd::vector<>(val.vx_list" + allowname + "());"
		switch typ.name {
		case "msgblocklist":
			valnew = "" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof vx_core::Type_msg) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);"
		case "msglist":
			valnew = "" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);"
		default:
			valnew = "" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);" +
				"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);" +
				"\n        } else if (valsub instanceof " + allowclass + ") {" +
				"\n          listval.add((" + allowclass + ")valsub);"
		}
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := CppNameTypeFromType(allowedtype)
			castval := "(" + allowedtypename + ")valsub"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "Boolean"
					castval = "vx_core::t_boolean.vx_new(valsub)"
				case "vx/core/int":
					allowedtypename = "Integer"
					castval = "vx_core::t_int.vx_new(valsub)"
				case "vx/core/float":
					allowedtypename = "Float"
					castval = "vx_core::t_float.vx_new(valsub)"
				case "vx/core/string":
					allowedtypename = "String"
					castval = "vx_core::t_string.vx_new(valsub)"
				}
			}
			if allowedtypename != "" {
				valnew += "" +
					"\n        } else if (valsub instanceof " + allowedtypename + ") {" +
					"\n          listval.add(" + castval + ");"
			}
		}
		valnew += "" +
			"\n        } else if (valsub instanceof Type_" + typename + ") {" +
			"\n          Type_" + typename + " multi = (Type_" + typename + ")valsub;" +
			"\n          listval.addAll(multi.vx_list" + allowname + "());" +
			"\n        } else if (valsub instanceof List) {" +
			"\n          std::vector<?> listunknown = (std::vector<?>)valsub;" +
			"\n          for (Object item : listunknown) {" +
			"\n            if (item instanceof " + allowclass + ") {" +
			"\n              " + allowclass + " valitem = (" + allowclass + ")item;" +
			"\n              listval.add(valitem);" +
			"\n            }" +
			"\n          }" +
			"\n        } else {" +
			"\n          vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Type: \" + valsub.toString());" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxlist = vx_core::immutablelist(listval);" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
		if extendinterface == "" {
			extendinterface = "vx_core::Type_list"
		}
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":map":
		allowcode := ""
		allowname := "any"
		allowclass := "vx_core::Type_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = CppNameTypeFullFromType(allowtype)
			allowempty := CppNameEFromType(allowtype)
			allowname = CppNameFromType(allowtype)
			allowcode = "" +
				"\n    " + allowclass + " vx_" + allowname + "(vx_core::Type_string key) {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      Type_" + typename + " map = this;" +
				"\n      String skey = key.vx_string();" +
				"\n      std::map<std::string, " + allowclass + "> mapval = map.vxmap;" +
				"\n      output = mapval.getOrDefault(skey, " + allowempty + ");" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		}
		if allowname == "any" {
			allowname = ""
		} else {
			allowcode += "" +
				"\n    std::map<std::string, " + allowclass + "> vx_map" + allowname + "() {return vxmap;}" +
				"\n" +
				"\n    vx_core::Type_any vx_any(vx_core::Type_string key) {" +
				"\n      return this->vx_" + allowname + "(key);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    protected:" +
			"\n    std::map<std::string, " + allowclass + "> vxmap = vx_core::immutablemap(new LinkedHashstd::map<std::string, " + allowclass + ">());" +
			"\n" +
			"\n    public:" +
			"\n    std::map<std::string, vx_core::Type_any> vx_map() {return vx_core::immutablemap(new LinkedHashstd::map<std::string, vx_core::Type_any>(this->vxmap));}" +
			"\n" +
			allowcode +
			"\n    Type_" + typename + " vx_new_from_map(std::map<std::string, vx_core::Type_any> mapval) {" +
			"\n      Type_" + typename + " output;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;" +
			"\n      std::map<std::string, " + allowclass + "> map;" +
			"\n      Set<String> keys = mapval.keySet();" +
			"\n      for (String key : keys) {" +
			"\n        vx_core::Type_any val = mapval.get(key);" +
			"\n        if (val instanceof " + allowclass + ") {" +
			"\n          " + allowclass + " castval = (" + allowclass + ")val;" +
			"\n          map.put(key, castval);" +
			"\n        } else {" +
			"\n          vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(" + typename + ") Invalid Value: \" + val.toString() + \"\");" +
			"\n          msgblock = vx_core::t_msgblock.vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxmap = vx_core::immutablemap(map);" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
		valcopy = "" +
			"\n      Type_" + typename + " valmap = this;" +
			"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);"
		valnew = "" +
			"\n      std::map<std::string, " + allowclass + "> mapval;" +
			"\n      String key = \"\";" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
			"\n          msgblock = vx_core::t_msgblock.vx_copy(msgblock, valsub);" +
			"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
			"\n          msgblock = vx_core::t_msgblock.vx_copy(msgblock, valsub);" +
			"\n        } else if (key.equals(\"\")) {" +
			"\n          if (valsub instanceof vx_core::Type_string) {" +
			"\n            vx_core::Type_string valstring = (vx_core::Type_string)valsub;" +
			"\n            key = valstring.vx_string();" +
			"\n          } else if (valsub instanceof String) {" +
			"\n            key = (String)valsub;" +
			"\n          } else {" +
			"\n            vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"Key Expected: \" + valsub.toString() + \"\");" +
			"\n            msgblock = vx_core::t_msgblock.vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n        } else {" +
			"\n          " + allowclass + " valany = null;" +
			"\n          if (valsub instanceof " + allowclass + ") {" +
			"\n            valany = (" + allowclass + ")valsub;"
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := CppNameTypeFromType(allowedtype)
			castval := "(" + allowedtypename + ")valsub"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "Boolean"
					castval = "vx_core::t_boolean.vx_new(valsub);"
				case "vx/core/int":
					allowedtypename = "Integer"
					castval = "vx_core::t_int.vx_new(valsub);"
				case "vx/core/float":
					allowedtypename = "Float"
					castval = "vx_core::t_float.vx_new(valsub);"
				case "vx/core/string":
					allowedtypename = "String"
					castval = "vx_core::t_string.vx_new(valsub);"
				}
			}
			if allowedtypename != "" {
				valnew += "" +
					"\n          } else if (valsub instanceof " + allowedtypename + ") {" +
					"\n            valany = " + castval + ";"
			}
		}
		valnew += "" +
			"\n          } else {" +
			"\n            vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"Invalid Key/Value: \" + key + \" \"  + valsub.toString() + \"\");" +
			"\n            msgblock = vx_core::t_msgblock.vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n          if (valany != null) {" +
			"\n            mapval.put(key, valany);" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxmap = vx_core::immutablemap(mapval);" +
			"\n      if (msgblock != vx_core::e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
		if extendinterface == "" {
			extendinterface = "vx_core::Type_map"
		}
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":struct":
		vx_any := ""
		vx_map := ""
		valcopy = "" +
			"\n      Type_" + typename + " val = this;"
		switch NameFromType(typ) {
		case "vx/core/msgblock":
			valcopy += "" +
				"\n      vx_core::Type_msgblock msgblock = this;"
		default:
			valcopy += "" +
				"\n      vx_core::Type_msgblock msgblock = vx_core::t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);"
		}
		if extendinterface == "" {
			extendinterface = "vx_core::Type_struct"
		}
		props := ListPropertyTraitFromType(typ)
		switch len(props) {
		case 0:
			valnew = "" +
				"\n      if (msgblock != vx_core::e_msgblock) {" +
				"\n        output.vxmsgblock = msgblock;" +
				"\n      }"
		default:
			validkeys := "\n      Arraystd::vector<String> validkeys;"
			valnewswitch := ""
			for _, arg := range props {
				validkeys += "\n      validkeys.add(\":" + arg.name + "\");"
				argname := CppFromName(arg.name)
				valcopy += "\n      output.vx_p_" + argname + " = val." + argname + "();"
				vx_map += "\n      output.put(\":" + arg.name + "\", this->" + argname + "());"
				vx_any += "" +
					"\n      case \":" + arg.name + "\":" +
					"\n        output = this->" + argname + "();" +
					"\n        break;"
				argclassname := CppNameTypeFromType(arg.vxtype)
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						"\n            } else if (valsub instanceof Boolean) {" +
						"\n              output.vx_p_" + argname + " = vx_core::t_boolean.vx_new(valsub);"
				case "vx/core/int":
					argalt = "" +
						"\n            } else if (valsub instanceof Integer) {" +
						"\n              output.vx_p_" + argname + " = vx_core::t_int.vx_new(valsub);"
				case "vx/core/float":
					argalt = "" +
						"\n            } else if (valsub instanceof Float) {" +
						"\n              output.vx_p_" + argname + " = vx_core::t_float.vx_new(valsub);"
				case "vx/core/string":
					argalt = "" +
						"\n            } else if (valsub instanceof String) {" +
						"\n              output.vx_p_" + argname + " = vx_core::t_string.vx_new(valsub);"
				}
				valnewswitch += "" +
					"\n          case \":" + arg.name + "\":" +
					"\n            if (valsub instanceof " + argclassname + ") {" +
					"\n              output.vx_p_" + argname + " = (" + argclassname + ")valsub;" +
					argalt +
					"\n            } else {" +
					"\n              vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + " :" + arg.name + " \" + valsub.toString() + \") - Invalid Value\");" +
					"\n              msgblock = msgblock.vx_copy(msg);" +
					"\n            }" +
					"\n            break;"
				instancefuncs += "" +
					"\n    protected " + argclassname + " vx_p_" + argname + ";" +
					"\n" +
					"\n    " + argclassname + " " + argname + "() {" +
					"\n      return this->vx_p_" + argname + " == null ? " + CppNameEFromType(arg.vxtype) + " : this->vx_p_" + argname + ";" +
					//"\n      vx_core::Type_any valsub = this->vx_map().getOrDefault(\":" + arg.name + "\", " + CppNameEFromType(arg.vxtype) + ");" +
					//"\n      return vx_core::f_any_from_any(" + CppNameTFromType(arg.vxtype) + ", valsub);" +
					"\n    }" +
					"\n"
			}
			defaultkey := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := CppFromName(lastarg.name)
				argclassname := CppNameTypeFromType(lastarg.vxtype)
				defaultkey += "" +
					"\n          } else if (valsub instanceof " + argclassname + ") { // default property" +
					"\n            output.vx_p_" + lastargname + " = (" + argclassname + ")valsub;"
				switch NameFromType(lastarg.vxtype) {
				case "vx/core/boolean":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Boolean) { // default property" +
						"\n            output.vx_p_" + lastargname + " = vx_core::t_boolean.vx_new(valsub);"
				case "vx/core/int":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Integer) { // default property" +
						"\n            output.vx_p_" + lastargname + " = vx_core::t_int.vx_new(valsub);"
				case "vx/core/float":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Float) { // default property" +
						"\n            output.vx_p_" + lastargname + " = vx_core::t_float.vx_new(valsub);"
				case "vx/core/string":
					defaultkey += "" +
						"\n          } else if (valsub instanceof String) { // default property" +
						"\n            output.vx_p_" + lastargname + " = vx_core::t_string.vx_new(valsub);"
				}
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						subargclassname := CppNameTypeFromType(allowtype)
						defaultkey += "" +
							"\n          } else if (valsub instanceof " + subargclassname + ") { // default property" +
							"\n            " + subargclassname + " valdefault = (" + subargclassname + ")valsub;" +
							"\n            " + argclassname + " vallist = output.vx_p_" + lastargname + ";" +
							"\n            if (vallist == null) {" +
							"\n              vallist = " + CppNameTFromType(lastarg.vxtype) + ".vx_new(valdefault);" +
							"\n            } else {" +
							"\n              vallist = vallist.vx_copy(valdefault);" +
							"\n            }" +
							"\n            output.vx_p_" + lastargname + " = vallist;"
					}
				}
			}
			switch NameFromType(typ) {
			case "vx/core/msg":
				valnew = "" +
					"\n      String key = \"\";" +
					"\n      for (Object valsub : vals) {" +
					"\n        if (key == \"\") {" +
					"\n          if (valsub instanceof vx_core::Type_string) {" +
					"\n            vx_core::Type_string valstr = (vx_core::Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            key = (String)valsub;" +
					"\n          } else {" +
					"\n            vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + valsub.toString());" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }"
			case "vx/core/msgblock":
				valnew = "" +
					"\n      String key = \"\";" +
					"\n      for (Object valsub : vals) {" +
					"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
					"\n          vx_core::Type_msgblocklist msgblocks = this->msgblocks();" +
					"\n          msgblocks = msgblocks.vx_copy(valsub);" +
					"\n          output.vx_p_msgblocks = msgblocks;" +
					"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
					"\n          vx_core::Type_msglist msgs = this->msgs();" +
					"\n          msgs = msgs.vx_copy(valsub);" +
					"\n          output.vx_p_msgs = msgs;" +
					"\n        } else if (valsub instanceof vx_core::Type_msgblocklist) {" +
					"\n          vx_core::Type_msgblocklist msgblocks = this->msgblocks();" +
					"\n          msgblocks = msgblocks.vx_copy(valsub);" +
					"\n          output.vx_p_msgblocks = msgblocks;" +
					"\n        } else if (valsub instanceof vx_core::Type_msglist) {" +
					"\n          vx_core::Type_msglist msgs = this->msgs();" +
					"\n          msgs = msgs.vx_copy(valsub);" +
					"\n          output.vx_p_msgs = msgs;" +
					"\n        } else if (key == \"\") {" +
					"\n          if (valsub instanceof vx_core::Type_string) {" +
					"\n            vx_core::Type_string valstr = (vx_core::Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            key = (String)valsub;" +
					"\n          } else {" +
					"\n            vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + valsub.toString());" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }"
			default:
				valnew = "" +
					validkeys +
					"\n      String key = \"\";" +
					"\n      for (Object valsub : vals) {" +
					"\n        if (valsub instanceof vx_core::Type_msgblock) {" +
					"\n          msgblock = msgblock.vx_copy(valsub);" +
					"\n        } else if (valsub instanceof vx_core::Type_msg) {" +
					"\n          msgblock = msgblock.vx_copy(valsub);" +
					"\n        } else if (key == \"\") {" +
					"\n          String testkey = \"\";" +
					"\n          if (valsub instanceof vx_core::Type_string) {" +
					"\n            vx_core::Type_string valstr = (vx_core::Type_string)valsub;" +
					"\n            testkey = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            testkey = (String)valsub;" +
					"\n          }" +
					"\n          bool isvalidkey = validkeys.contains(testkey);" +
					"\n          if (isvalidkey) {" +
					"\n            key = testkey;" +
					defaultkey +
					"\n          } else {" +
					"\n            vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + valsub.toString());" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          default:" +
					"\n            vx_core::Type_msg msg = vx_core::t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key: \" + key);" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (msgblock != vx_core::e_msgblock) {" +
					"\n        output.vxmsgblock = msgblock;" +
					"\n      }"
			}
		}
		instancefuncs += "" +
			"\n    vx_core::Type_any vx_any(vx_core::Type_string key) {" +
			"\n      vx_core::Type_any output = vx_core::e_any;" +
			"\n      String skey = key.vx_string();" +
			"\n      switch (skey) {" +
			vx_any +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    std::map<std::string, vx_core::Type_any> vx_map() {" +
			"\n      std::map<std::string, vx_core::Type_any> output;" +
			vx_map +
			"\n      return vx_core::immutablemap(output);" +
			"\n    }" +
			"\n"
	default:
		if extendinterface == "" {
			extendinterface = "vx_core::Type_anytype"
		}
	}
	vxmsgblock := ""
	switch NameFromType(typ) {
	case "vx/core/msg":
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock vx_msgblock() {return vx_core::e_msgblock;}"
	case "vx/core/msgblock":
		vxmsgblock = "" +
			"\n    vx_core::Type_msgblock vx_msgblock() {return this;}"
	}
	headers := CppHeaderFromType(typ)
	pkgname := CppNameFromPkgName(typ.pkgname)
	typedef := "" +
		"\n    vx_core::Type_typedef vx_typedef() {" +
		"\n      return " + CppTypeDefFromType(typ, "      ") + ";" +
		"\n    }" +
		"\n"
	output := "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (type " + typ.name + ")" +
		"\n   */" +
		"\n  class Type_" + typename + extendsclass + " {" +
		"\n" +
		instancefuncs +
		"\n    Type_" + typename + " vx_new(std::any vals...) {return e_" + typename + ".vx_copy(vals);}" +
		"\n" +
		"\n    Type_" + typename + " vx_copy(std::any vals...) {" +
		"\n      Type_" + typename + " output;" +
		valcopy +
		valnew +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		vxmsgblock +
		"\n    " + pkgname + "::Type_" + typename + " vx_empty() {return e_" + typename + ";}" +
		"\n    " + pkgname + "::Type_" + typename + " vx_type() {return t_" + typename + ";}" +
		"\n" +
		typedef +
		staticfuncs +
		"\n  }" +
		"\n" +
		"\n  const " + pkgname + "::Type_" + typename + " e_" + typename + ";" +
		"\n  const " + pkgname + "::Type_" + typename + " t_" + typename + ";" +
		"\n"
	return output, headers, msgblock
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
			valstr = "vx_core::t_boolean.vx_new_from_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = CppFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = CppNameFromPkgName(valconst.pkgname) + ".c_" + CppFromName(valconst.alias)
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
					work = work + "." + CppFromName(propname) + "()"
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
							var lambdaargs []string
							var lambdavars []string
							arglist := ListLocalArgFromFunc(argfunc)
							for _, lambdaarg := range arglist {
								lambdaargs = append(lambdaargs, lambdaarg.name+"_any")
								argvaltype := ""
								argvalinstance := ""
								argtype := lambdaarg.vxtype
								argvaltype = CppNameTypeFullFromType(argtype)
								argvalinstance = CppNameTFromType(argtype)
								lambdavar := argvaltype + " " + lambdaarg.name + " = vx_core::f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any);"
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
										"vx_core::t_any_from_key_value_async.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-async":
									argtext = "" +
										"vx_core::t_any_from_reduce_async.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next-async":
									argtext = "" +
										"vx_core::t_any_from_reduce_next_async.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"vx_core::t_any_from_any_async.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"vx_core::t_any_from_func_async.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								work, msgs := CppFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-key-value":
									argtext = "" +
										"vx_core::t_any_from_key_value.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce":
									argtext = "" +
										"vx_core::t_any_from_reduce.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next":
									argtext = "" +
										"vx_core::t_any_from_reduce_next.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"vx_core::t_any_from_any.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"vx_core::t_any_from_func.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							}
						} else if funcname == "vx/core/let" {
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
									for _, lambdaarg := range arglist {
										arglineindent := "\n" + argindent
										if lambdaarg.async {
											lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + "final std::future<" + CppNameTypeFromType(lambdaarg.vxtype) + "> future_" + CppFromName(lambdaarg.name) + " = " + lambdavaluetext + ";" +
												arglineindent + "return vx_core::async_from_async_fn(future_" + CppFromName(lambdaarg.name) + ", (" + CppFromName(lambdaarg.name) + ") -> {"
											aftertext += "" +
												arglineindent + "});"
											argindent += "  "
										} else {
											lambdavaluetext, msgs := CppFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + "final " + CppNameTypeFromType(lambdaarg.vxtype) + " " + CppFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
										}
									}
									work, msgs := CppFromValue(argvalue, pkgname, fnc, "    ", true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										"vx_core::t_any_from_func_async.fn_new(() -> {" +
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
										lambdatext += arglineindent + CppNameTypeFromType(lambdaarg.vxtype) + " " + CppFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
									}
									work, msgs := CppFromValue(argvalue, pkgname, fnc, "", true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									argtext = "" +
										"vx_core::t_any_from_func.fn_new(() -> {" +
										lambdatext +
										arglineindent + "return " + work + ";" +
										"\n})"
								}
							}
						} else if funcname == "vx/core/fn" {
						} else if funcarg.vxtype.isfunc {
							switch argvalue.code {
							case ":arg":
								argvaluearg := ArgFromValue(argvalue)
								if !argvaluearg.vxtype.isfunc {
									work, msgs := CppFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										"vx_core::t_any_from_func.fn_new(() -> {" +
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
								argtext = "" +
									CppNameTFromType(funcarg.vxtype) + ".fn_new(() -> {" +
									work +
									"\n})"
							}
						}
						if argtext == "" {
							work, msgs := CppFromValue(argvalue, pkgname, fnc, "", true, test, argsubpath)
							argtext = work
							msgblock = MsgblockAddBlock(msgblock, msgs)
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
								argtext = subindent + StringFromStringIndent(argtext, subindent)
							} else {
								multiflag = true
								argtext = "" +
									CppNameTFromType(funcarg.vxtype) + ".vx_new(" +
									"\n" + subindent + StringFromStringIndent(argtext, subindent)
							}
						}
						if argtext != "" {
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
			output = "vx_core::t_boolean.vx_new_from_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::t_decimal.vx_new_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::t_float.vx_new_from_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = "vx_core::t_int.vx_new_from_int(" + valstr + ")"
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
	if BooleanFromStringContains(body, "std::map<") {
		output += "#include <map>\n"
	}
	if BooleanFromStringContains(body, "std::string") {
		output += "#include <string>\n"
	}
	if BooleanFromStringContains(body, "std::vector<") {
		output += "#include <vector>\n"
	}
	if BooleanFromStringContains(body, " std::future<") {
		output += "#include <future>\n"
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
			}
			if !isskip {
				importline := "#include \"" + libpath + ".h\"\n"
				if IntFromStringIndex(output, importline) < 0 {
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
	typename := CppNameTypeFullFromType(typ)
	basics := "" +
		"\n    " + typename + " vx_new(std::any vals...);" +
		"\n    " + typename + " vx_copy(std::any vals...);" +
		"\n    " + typename + " vx_empty();" +
		"\n    " + typename + " vx_type();"
	createtext, _ := CppFromValue(typ.createvalue, "", emptyfunc, "", true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isoverride := false
		for _, createline := range createlines {
			if createline == "@Override" {
				isoverride = true
			} else if isoverride {
				ipos := IntFromStringIndexLast(createline, ")")
				createline = createline[0:ipos+1] + ";"
				basics += "\n    " + createline
				isoverride = false
			}
		}
	}
	switch NameFromType(typ) {
	case "vx/core/any":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_any {" +
			basics +
			"\n    vx_core::Type_typedef vx_typedef();" +
			"\n    std::vector<vx_core::Type_any> vx_dispose();" +
			"\n    vx_core::Type_msgblock vx_msgblock();" +
			"\n    bool vx_release();" +
			"\n    void vx_reserve();" +
			"\n  };" +
			"\n"
	case "vx/core/boolean":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_boolean : vx_core::Type_any {" +
			basics +
			"\n  };" +
			"\n"
	case "vx/core/decimal":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_decimal : virtual vx_core::Type_number {" +
			basics +
			"\n  };" +
			"\n"
	case "vx/core/float":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_float : virtual vx_core::Type_number {" +
			basics +
			"\n  };" +
			"\n"
	case "vx/core/func":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_func : vx_core::Type_any {" +
			basics +
			"\n	   vx_core::Type_funcdef vx_funcdef();" +
			"\n  };" +
			"\n"
	case "vx/core/int":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_int : vx_core::Type_number {" +
			basics +
			"\n  };" +
			"\n"
	case "vx/core/string":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_string : vx_core::Type_any {" +
			basics +
			"\n  };" +
			"\n"
	case "vx/core/list":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_list : vx_core::Type_any {" +
			basics +
			"\n    std::vector<vx_core::Type_any> vx_list();" +
			"\n    vx_core::Type_any vx_any(vx_core::Type_int index);" +
			"\n  };" +
			"\n"
	case "vx/core/map":
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_map : vx_core::Type_any {" +
			basics +
			"\n    vx_core::Type_map vx_new_from_map(std::map<std::string, vx_core::Type_any> mapval);" +
			"\n    vx_core::Type_any vx_any(vx_core::Type_string key);" +
			"\n    std::map<std::string, vx_core::Type_any> vx_map();" +
			"\n  };" +
			"\n"
	case "vx/core/struct":
		output = "" +
			"\n  class Type_struct : vx_core::Type_any {" +
			basics +
			"\n    vx_core::Type_any vx_any(vx_core::Type_string key);" +
			"\n    std::map<std::string, vx_core::Type_any> vx_map();" +
			"\n  };" +
			"\n"
	default:
		extras := ""
		switch NameFromType(typ) {
		case "vx/core/msg":
			basics = "" +
				"\n    " + typename + " vx_new(std::any vals...);" +
				"\n    " + typename + " vx_copy(std::any vals...);" +
				"\n    " + typename + " vx_empty();" +
				"\n    " + typename + " vx_type();" +
				"\n    vx_core::Type_typedef vx_typedef();"
			extras += "" +
				"\n    Type_msg vx_new_error(std::string text);" +
				"\n    Type_msg vx_new_from_exception(std::string text, std::exception err);"
		case "vx/core/msgblock":
			basics = "" +
				"\n    " + typename + " vx_new(std::any vals...);" +
				"\n    " + typename + " vx_copy(std::any vals...);" +
				"\n    " + typename + " vx_empty();" +
				"\n    " + typename + " vx_type();" +
				"\n    vx_core::Type_typedef vx_typedef();"
			extras += "" +
				"\n    vx_core::Type_msgblock vx_msgblock_from_copy_arrayval(vx_core::Type_any copy, std::any vals...);"
		}
		extends := ""
		switch typ.extends {
		case "boolean":
			extends += "vx_core::Type_boolean"
		case "decimal":
			extends += "vx_core::Type_decimal"
		case "float":
			extends += "vx_core::Type_float"
		case "int":
			extends += "vx_core::Type_int"
		case "string":
			extends += "vx_core::Type_string"
		case ":list":
			extends += "vx_core::Type_list"
			allowclass := "vx_core::Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = CppNameTypeFullFromType(allowtype)
				allowname = CppNameFromType(allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    std::vector<" + allowclass + "> vx_list" + allowname + "();" +
					"\n    " + allowclass + " vx_" + allowname + "(vx_core::Type_int index);"
			}
		case ":map":
			extends = "vx_core::Type_map"
			allowclass := "vx_core::Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = CppNameTypeFullFromType(allowtype)
				allowname = CppNameFromType(allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    std::map<std::string, " + allowclass + "> vx_map" + allowname + "();" +
					"\n    " + allowclass + " vx_" + allowname + "(vx_core::Type_string key);"
			}
		case ":struct":
			extends = "vx_core::Type_struct"
			if len(typ.traits) > 0 {
				var traitnames []string
				for _, trait := range typ.traits {
					traitnames = append(traitnames, CppNameTypeFullFromType(trait))
				}
				extends = StringFromListStringJoin(traitnames, ", ")
			}
			for _, arg := range ListPropertyTraitFromType(typ) {
				extras += "\n    " + CppNameTypeFromType(arg.vxtype) + " " + CppFromName(arg.alias) + "();"
			}
		default:
			extends += "vx_core::Type_any"
		}
		typename := CppNameFromType(typ)
		pkgname := CppNameFromPkgName(typ.pkgname)
		output = "" +
			"\n  // (type " + typ.name + ")" +
			"\n  class Type_" + typename + " : " + extends + " {" +
			basics +
			extras +
			"\n  };" +
			"\n  extern const " + pkgname + "::Type_" + typename + " e_" + typename + ";" +
			"\n  extern const " + pkgname + "::Type_" + typename + " t_" + typename + ";" +
			"\n"
	}
	return output
}

func CppHeaderFnFromFunc(fnc *vxfunc) string {
	interfaces := ""
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any resolve(vx_core::Type_any val);" +
			"\n    };"
	case "vx/core/any<-any-async":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      std::future<vx_core::Type_any> resolve(vx_core::Type_any val);" +
			"\n    };"
	case "vx/core/any<-any-context":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any resolve(vx_core::Type_any val, vx_core::Type_context context);" +
			"\n    };"
	case "vx/core/any<-any-context-async":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      std::future<vx_core::Type_any> resolve(vx_core::Type_any val, vx_core::Type_context context);" +
			"\n    };"
	case "vx/core/any<-key-value":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any resolve(vx_core::Type_string key, vx_core::Type_any val);" +
			"\n    };"
	case "vx/core/any<-func", "vx/core/any<-none":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any resolve();" +
			"\n    };"
	case "vx/core/any<-reduce":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any resolve(vx_core::Type_any reduce, vx_core::Type_any item);" +
			"\n    };"
	case "vx/core/any<-reduce-next":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any resolve(vx_core::Type_any reduce, vx_core::Type_any current, vx_core::Type_any next);" +
			"\n    };"
	case "vx/core/any<-key-value-async":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      std::future<vx_core::Type_any> resolve(vx_core::Type_string key, vx_core::Type_any val);" +
			"\n    };"
	case "vx/core/any<-func-async", "vx/core/any<-none-async":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      std::future<vx_core::Type_any> resolve();" +
			"\n    };"
	case "vx/core/any<-reduce-async":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      std::future<vx_core::Type_any> resolve(vx_core::Type_any reduce, vx_core::Type_any item);" +
			"\n    };"
	case "vx/core/any<-reduce-next-async":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      std::future<vx_core::Type_any> resolve(vx_core::Type_any reduce, vx_core::Type_any current, vx_core::Type_any next);" +
			"\n    };"
	case "vx/core/boolean<-func", "vx/core/boolean<-none":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_boolean resolve();" +
			"\n    };"
	case "vx/core/none<-any":
		interfaces = "" +
			"\n    class IFn {" +
			"\n      vx_core::Type_any void resolve(vx_core::Type_any val);" +
			"\n    };"
	}
	return interfaces
}

func CppHeaderFromFunc(fnc *vxfunc) string {
	funcname := CppNameFromFunc(fnc)
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
			listargtext = append(listargtext, returntype+" generic_any_1")
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
				listargtext = append(listargtext, argtypename+" "+argname)
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
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
		extends = "virtual vx_core::Type_func"
		interfaces += "" +
			"\n    vx_core::Func_" + funcname + " fn_new(vx_core::Func_" + funcname + "::IFn fn);"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		extends = "virtual vx_core::Type_func"
		interfaces += "" +
			"\n    vx_core::Func_" + funcname + " fn_new(vx_core::Func_any_from_func::IFn fn);"
	case "vx/core/none<-any":
	default:
		if extends == "" {
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
				extends = "virtual vx_core::Type_func"
			default:
				switch len(fnc.listarg) {
				case 1:
					extends = "virtual vx_core::Func_any_from_any"
					if fnc.context {
						extends += "_context"
					}
					if fnc.async {
						extends += "_async"
					}
				default:
					extends = "virtual vx_core::Type_func"
				}
			}
		}
	}
	if fnc.async {
		returntype = "std::future<" + returntype + ">"
	}
	contextarg := ""
	if fnc.context {
		if argtext == "" {
			contextarg = "vx_core::Type_context context"
		} else {
			contextarg = ", vx_core::Type_context context"
		}
	}
	if extends == "virtual vx_core::Type_func" {
		if fnc.async {
			extends += ", virtual vx_core::Type_replfunc_async"
		} else {
			extends += ", virtual vx_core::Type_replfunc"
		}
	}
	interfaces += "" +
		"\n    " + generictypes + returntype + " f_" + funcname + "(" + argtext + contextarg + ");"
	fnheaders := CppHeaderFnFromFunc(fnc)
	output := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  class Func_" + funcname + " : " + extends + " {" +
		"\n  public:" +
		fnheaders +
		interfaces +
		"\n  };" +
		"\n"
	return output
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

/*
func CppPackagePathFromPrefixName(pkgprefix string, pkgname string) (string, string) {
	pkgpath := pkgprefix + "/" + pkgname
	ipos := IntFromStringIndexLast(pkgpath, "/")
	name := StringSubstring(pkgpath, ipos+1, len(pkgpath))
	pkgpath = StringSubstring(pkgpath, 0, ipos)
	pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
	pkgpath = CppFromName(pkgpath)
	name = CppNameFromPkgName(name)
	return pkgpath, name
}
*/

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
				replparam := outputtype + " generic_" + CppFromName(fnc.generictype.name) + " = vx_core::f_any_from_any(" + outputttype + ", arglist.vx_any(vx_core::t_int.vx_new_from_int(" + StringFromInt(argidx) + ")));"
				replparams += "\n      " + replparam
				listargname = append(listargname, "generic_"+CppFromName(fnc.generictype.name))
			}
		}
	}
	for _, arg := range fnc.listarg {
		if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
		} else {
			argname := CppFromName(arg.alias)
			replparam := CppNameTypeFromType(arg.vxtype) + " " + argname + " = vx_core::f_any_from_any(" + CppNameTFromType(arg.vxtype) + ", arglist.vx_any(vx_core::t_int.vx_new_from_int(" + StringFromInt(argidx) + ")));"
			replparams += "\n      " + replparam
			listargname = append(listargname, argname)
			argidx += 1
		}
	}
	if fnc.context {
		listargname = append(listargname, "context")
		replparam := "vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist.vx_any(vx_core::t_int.vx_new_from_int(" + StringFromInt(argidx) + ")));"
		replparams += "\n      " + replparam
	}
	if fnc.async {
		output = "" +
			"\n    std::future<vx_core::Type_any> vx_repl(vx_core::Type_anylist arglist) {" +
			"\n      std::future<vx_core::Type_any> output = std::future.completedFuture(vx_core::e_any);" +
			replparams +
			"\n      std::future<" + outputtype + "> future = " + pkgname + "::f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      output = vx_core::async_from_async(vx_core::t_any, future);" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	} else {
		output = "" +
			"\n    vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) {" +
			"\n      vx_core::Type_any output = vx_core::e_any;" +
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
				"\n        vx_test::t_testdescribe.vx_new(" +
				"\n          \":describename\", \"" + CppTestFromValue(testvalue) + "\"," +
				"\n          \":testresult\"," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		output = "" +
			"\n  static vx_test::Type_testcase " + testcasename + "(vx_core::Type_context context) {" +
			"\n    vx_test::Type_testcase output = vx_test::t_testcase.vx_new(" +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + testpkg + "\"," +
			"\n      \":casename\", \"" + testname + "\"," +
			"\n      \":describelist\"," +
			"\n      vx_test::t_testdescribelist.vx_new(" + describelist +
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
	path := fnc.pkgname + "/" + fnc.name
	output, msgs := CppTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func CppTestFromPackage(pkg *vxpackage, prj *vxproject) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("CppTestFromPackage")
	pkgname := CppFromName(pkg.name)
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
		covertype = append(covertype, "      \":"+typid+"\", "+StringFromInt(len(typ.testvalues)))
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(testall, pkgname+"Test::t_"+CppFromName(typ.alias)+"(context)")
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
		coverconst = append(coverconst, "      \":"+cnstid+"\", "+StringFromInt(len(cnst.listtestvalue)))
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(testall, pkgname+"Test.c_"+CppFromName(cnst.alias)+"(context)")
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
			coverfunc = append(coverfunc, "      \":"+fncid+CppIndexFromFunc(fnc)+"\", "+StringFromInt(len(fnc.listtestvalue)))
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(testall, pkgname+"Test::f_"+CppFromName(fnc.alias)+CppIndexFromFunc(fnc)+"(context)")
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
	body := "" +
		typetexts +
		consttexts +
		functexts +
		"\n  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {" +
		"\n    std::vector<vx_core::Type_any> arraylisttestcase = new Arraystd::vector<>(Arrays.asList(" +
		"\n      " + strings.Join(testall, ",\n      ") +
		"\n    ));" +
		"\n    vx_test::Type_testcaselist output = vx_test::t_testcaselist.vx_new(arraylisttestcase);" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testcoveragesummary test_coveragesummary() {" +
		"\n    return vx_test::t_testcoveragesummary.vx_new(" +
		"\n      \":testpkg\",   \"" + pkg.name + "\", " +
		"\n      \":constnums\", " + CppTypeCoverageNumsValNew(coverconstpct, coverconstcnt, coverconsttotal) + ", " +
		"\n      \":docnums\", " + CppTypeCoverageNumsValNew(coverdocpct, coverdoccnt, coverdoctotal) + ", " +
		"\n      \":funcnums\", " + CppTypeCoverageNumsValNew(coverfuncpct, coverfunccnt, coverfunctotal) + ", " +
		"\n      \":ospacenums\", " + CppTypeCoverageNumsValNew(coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + ", " +
		"\n      \":otimenums\", " + CppTypeCoverageNumsValNew(coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + ", " +
		"\n      \":totalnums\", " + CppTypeCoverageNumsValNew(coverpct, covercnt, covertotal) + ", " +
		"\n      \":typenums\", " + CppTypeCoverageNumsValNew(covertypepct, covertypecnt, covertypetotal) +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testcoveragedetail test_coveragedetail() {" +
		"\n    return vx_test::t_testcoveragedetail.vx_new(" +
		"\n      \":testpkg\", \"" + pkg.name + "\"," +
		"\n      \":typemap\", vx_core::t_intmap.vx_new(" +
		"\n  " + strings.Join(covertype, ",\n  ") +
		"\n      )," +
		"\n      \":constmap\", vx_core::t_intmap.vx_new(" +
		"\n  " + strings.Join(coverconst, ",\n  ") +
		"\n      )," +
		"\n      \":funcmap\", vx_core::t_intmap.vx_new(" +
		"\n  " + strings.Join(coverfunc, ",\n  ") +
		"\n      )" +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  vx_test::Type_testpackage test_package(vx_core::Type_context context) {" +
		"\n    vx_test::Type_testcaselist testcaselist = test_cases(context);" +
		"\n    vx_test::Type_testpackage output = vx_test::t_testpackage.vx_new(" +
		"\n      \":testpkg\", \"" + pkg.name + "\", " +
		"\n      \":caselist\", testcaselist," +
		"\n      \":coveragesummary\", test_coveragesummary()," +
		"\n      \":coveragedetail\", test_coveragedetail()" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := CppImportsFromPackage(pkg, "", body, true)
	headertext := ""
	output := "" +
		imports +
		"\nnamespace " + pkgname + "Test {" +
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
		"vx_test::t_testcoveragenums.vx_new(" +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
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
		"vx_core::typedef_new(" +
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
	return "vx_core::t_int.vx_new_from_int(" + StringFromInt(val) + ")"
}

func CppTypeListFromListType(listtype []*vxtype) string {
	output := "vx_core::e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := CppNameTFromType(typ)
			listtext = append(listtext, typetext)
		}
		output = "vx_core::t_typelist.vx_new(" + StringFromListStringJoin(listtext, ", ") + ")"
	}
	return output
}

func CppTypeStringValNew(val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return "vx_core::t_string.vx_new_from_string(\"" + valstr + "\")"
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
		ipos := IntFromStringIndexLast(targetpath, "/")
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
	imports := ""
	for _, pkg := range listpackage {
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringUCaseFirst(pkgname)
		testpackage := "\n    " + pkgname + "Test.test_package(context)"
		listtestpackage = append(listtestpackage, testpackage)
		importline := "import " + StringFromStringFindReplace(pkgpath, "/", ".") + ".*;\n"
		if importline == "import com.vxlisp.vx.*;\n" {
		} else if BooleanFromStringContains(imports, importline) {
		} else {
			imports += importline
		}
		tests += "" +
			`  @Test
  @DisplayName("` + pkg.name + `")
  void test_` + StringFromStringFindReplace(pkg.name, "/", "_") + `() {
	  vx_test::Type_testpackage testpackage = ` + pkgname + `Test::test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

`
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",")
	output := "" +
		imports +
		`
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for whole App.
 */
class AppTest {

  vx_core::Type_context context = vx_core::t_context.vx_new();

` + tests +
		`
  @Test
	@DisplayName("writetestsuite")
  void test_writetestsuite() {
    vx_test::Type_testpackagelist testpackagelist = vx_test::t_testpackagelist.vx_new(` +
		testpackages +
		`
    );
    TestLib.write_testpackagelist_async(testpackagelist, context);
  }

}
`
	return output
}

func CppTestLib() string {
	return "" +
		`package com.vxlisp.vx;

import Cpp.util.*;
import Cpp.util.concurrent.std::future;
import static org.junit.jupiter.api.Assertions.*;
import com.vxlisp.vx.data.File;
import com.vxlisp.vx.Test;
import com.vxlisp.vx.web.Html;

namespace TestLib {

  bool run_testcase(vx_test::Type_testcase testcase) {
    String testpkg = testcase.testpkg().vx_string();
    String casename = testcase.casename().vx_string();
    vx_test::Type_testdescribelist testdescribelist = testcase.describelist();
    return run_testdescribelist(testpkg, casename, testdescribelist);
  }

  // Blocking
  // Only use if running a single testcase
  bool run_testcase_async(vx_test::Type_testcase testcase) {
    std::future<vx_test::Type_testcase> async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_core::Type_any work = vx_core::sync_from_async(vx_test::t_testcase, async_testcase);
    vx_test::Type_testcase testcase_resolved = (vx_test::Type_testcase)work;
    return run_testcase(testcase_resolved);
  }

  bool run_testcaselist(vx_test::Type_testcaselist testcaselist) {
    std::vector<vx_test::Type_testcase> listtestcase = testcaselist.vx_listtestcase();
    for (vx_test::Type_testcase testcase : listtestcase) {
      run_testcase(testcase);
    }
    return true;
  }

  bool run_testdescribe(String testpkg, final String casename, final vx_test::Type_testdescribe describe) {
    vx_core::Type_string testcode = describe.describename();
    String message = testcode.vx_string();
    vx_test::Type_testresult testresult = describe.testresult();
    return run_testresult(testpkg, casename, message, testresult);
  }

  // Blocking
  // Only use if running a single testdescribe
  bool run_testdescribe_async(String testpkg, final String casename, final vx_test::Type_testdescribe testdescribe) {
    std::future<vx_test::Type_testdescribe> async_testdescribe = vx_test::f_resolve_testdescribe(testdescribe);
    vx_test::Type_testdescribe testdescribe_resolved = vx_core::sync_from_async(vx_test::t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  bool run_testdescribelist(String testpkg, final String casename, final vx_test::Type_testdescribelist testdescribelist) {
    bool output = true;
    std::vector<vx_test::Type_testdescribe> listtestdescribe = testdescribelist.vx_listtestdescribe();
    for (vx_test::Type_testdescribe testdescribe : listtestdescribe) {
      bool testoutput = run_testdescribe(testpkg, casename, testdescribe);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  bool run_testpackage(vx_test::Type_testpackage testpackage) {
    vx_test::Type_testcaselist testcaselist = testpackage.caselist();
    return run_testcaselist(testcaselist);
  }

  bool run_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    bool output = true;
    std::vector<vx_test::Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (vx_test::Type_testpackage testpackage : listtestpackage) {
      bool testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  bool run_testpackage_async(vx_test::Type_testpackage testpackage) {
    std::future<vx_test::Type_testpackage> async_testpackage = vx_test::f_resolve_testpackage(testpackage);
    vx_test::Type_testpackage testpackage_resolved = vx_core::sync_from_async(vx_test::t_testpackage, async_testpackage);
    return run_testpackage(testpackage_resolved);
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  bool run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist) {
    std::future<vx_test::Type_testpackagelist> async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::sync_from_async(vx_test::t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  bool run_testresult(String testpkg, final String testname, final String message, final vx_test::Type_testresult testresult) {
    vx_core::Type_any valexpected = testresult.expected();
    vx_core::Type_any valactual = testresult.actual();
    bool passfail = testresult.passfail().vx_boolean();
    String code = testresult.code().vx_string();
    String expected = vx_core::f_string_from_any(valexpected).vx_string();
    String actual = vx_core::f_string_from_any(valactual).vx_string();
    String msg = testpkg + "/" + testname + " " + message;
    if (!passfail) {
      System.out.println(msg);
      System.out.println(expected);
      System.out.println(actual);
      vx_core::f_log(testresult);
    }
    switch (code) {
    case ":ne":
      assertNotEquals(expected, actual, msg);
      break;
    default:
      assertEquals(expected, actual, msg);
      break;
    }
    return true;
  }

  // Blocking
  bool run_testresult_async(String testpkg, final String testname, final String message, vx_test::Type_testresult testresult) {
    std::future<vx_test::Type_testresult> async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult testresult_resolved = vx_core::sync_from_async(vx_test::t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  bool write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, final vx_core::Type_context context) {
    bool output = false;
    std::future<vx_test::Type_testpackagelist> async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::sync_from_async(vx_test::t_testpackagelist, async_testpackagelist);
    vx_file::Type_file filetest = vx_test::f_file_test();
    vx_core::Type_boolean valboolean = vx_file::f_boolean_write_from_file_any(filetest, testpackagelist_resolved, context);
    output = valboolean.vx_boolean();
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_data_file::Type_file filenode = vx_test::f_file_testnode();
    valboolean = vx_data_file::f_boolean_write_from_file_any(filenode, htmlnode, context);
    output = output && valboolean.vx_boolean();
    vx_file::Type_file filehtml = vx_test::f_file_testhtml();
    vx_core::Type_string shtml = vx_web_html::f_string_from_html(htmlnode);
    valboolean = vx_data_file::f_boolean_write_from_file_string(filehtml, shtml, context);
    output = output && valboolean.vx_boolean();
    return output;
  }

}
`
}
