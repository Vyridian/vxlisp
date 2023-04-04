package vxlisp

import (
	"strings"
)

func JavaConstDefsFromListConst(values []*vxconst, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	var outputvalues []string
	if len(values) > 0 {
		for _, val := range values {
			name := "" +
				lineindent + "Core.constdef_new(" +
				lineindent + "  \"" + val.pkgname + "\"," +
				lineindent + "  \"" + val.name + "\"," +
				lineindent + "  null" +
				lineindent + ")"
			outputvalues = append(outputvalues, name)
		}
		output = "Core.arraylist_from_array(" + strings.Join(outputvalues, ",") + lineindent + ")"
	}
	return output
}

func JavaDebugFromFunc(fnc *vxfunc, lineindent string) (string, string) {
	debugstart := ""
	debugend := ""
	if fnc.debug {
		debugstart = lineindent + "Core.debug(\"" + fnc.name + "\", \"start\""
		for _, arg := range fnc.listarg {
			debugstart += ", " + JavaTypeStringValNew(arg.name+"=") + ", " + JavaFromName(arg.alias)
		}
		debugstart += ");"
		debugend = lineindent + "Core.debug(\"" + fnc.name + "\", \"end\", output);"
	}
	return debugstart, debugend
}

func JavaDocFromFunc(fnc *vxfunc) string {
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
	doc += "@function " + JavaFromName(fnc.alias)
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

func JavaEmptyValueFromType(typ *vxtype) string {
	return JavaEmptyValueFromTypeIndent(typ, "")
}

func JavaEmptyValueFromTypeIndent(typ *vxtype, indent string) string {
	output := "\"\""
	if len(indent) < 10 {
		output = typ.defaultvalue
		switch typ.extends {
		case "string":
			output = "\"" + output + "\""
		case ":list":
			output = "Core.f_type_to_list(" + JavaNameFromPkgName(typ.pkgname) + ".t_" + typ.name + ")"
		default:
			if len(typ.properties) > 0 {
				output = "{\n"
				for _, property := range typ.properties {
					propdefault := JavaEmptyValueFromTypeIndent(property.vxtype, indent+"  ")
					output += indent + "    " + JavaFromName(property.name) + ": " + propdefault + ","
					if property.doc != "" {
						output += " // " + property.doc
					}
					output += "\n"
				}
				output += "" +
					indent + "    vxtype: " + JavaNameFromPkgName(typ.pkgname) + ".t_" + JavaFromName(typ.name) +
					"\n" + indent + "  }"
			} else if output == "" || strings.HasPrefix(output, ":") {
				output = "\"" + output + "\""
			}
		}
	}
	return output
}

func JavaFilesFromProjectCmd(prj *vxproject, cmd *vxcmd) ([]*vxfile, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaFilesFromProjectCmd")
	var files []*vxfile
	cmdpaths := ListStringSplitFromStringDelim(cmd.path, "/")
	cmdpathlen := len(cmdpaths)
	domainname := cmdpaths[cmdpathlen-1]
	urlsuffix := cmdpaths[cmdpathlen-2]
	pkgprefix := urlsuffix + "." + domainname
	pkgs := prj.listpackage
	switch cmd.code {
	case ":test":
		file := NewFile()
		file.name = "Appcom.sarvalex.vx.Test.java"
		file.path = cmd.path + "/vx"
		file.text = JavaAppTest(prj, pkgprefix)
		files = append(files, file)
		file = NewFile()
		file.name = "TestLib.java"
		file.path = cmd.path + "/vx"
		file.text = JavaTestLib()
		files = append(files, file)
	}
	for _, pkg := range pkgs {
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringUCaseFirst(pkgname)
		switch cmd.code {
		case ":source":
			text, msgs := JavaFromPackage(pkg, prj, pkgprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + ".java"
			file.path = cmd.path + "/" + pkgpath
			file.text = text
			files = append(files, file)
		case ":test":
			text, msgs := JavaTestFromPackage(pkg, prj, pkgprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + "com.sarvalex.vx.Test.java"
			file.path = cmd.path + "/" + pkgpath
			file.text = text
			files = append(files, file)
		}
	}
	return files, msgblock
}

func JavaFromConst(cnst *vxconst, pkg *vxpackage) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaFromConst")
	var output = ""
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
	cnstname := JavaFromName(cnst.alias)
	cnstclassname := "Const_" + cnstname
	cnsttypename := JavaNameFromType(cnst.vxtype)
	cnsttypeclassname := JavaNameTypeFullFromType(cnsttype)
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
		cnstval = "\n      this.vxboolean = " + cnstval + ";"
		initval = "" +
			"\n    @Override" +
			"\n    public boolean vx_boolean() {" +
			cnstval +
			"\n      return this.vxboolean;" +
			"\n    }"
	case "vx/core/decimal":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this.vxdecimal = " + cnstval + ";"
		initval = "" +
			"\n    @Override" +
			"\n    public String vx_decimal() {" +
			cnstval +
			"\n      return this.vxdecimal;" +
			"\n    }"
	case "vx/core/float":
		if cnstval == "" {
			cnstval = "f0"
		}
		cnstval = "\n      this.vxfloat = " + cnstval + ";"
		initval = "" +
			"\n    @Override" +
			"\n    public float vx_float() {" +
			cnstval +
			"\n      return this.vxdecimal;" +
			"\n    }"
	case "vx/core/int":
		if cnstval == "" {
			cnstval = "0"
		}
		cnstval = "\n      this.vxint = " + cnstval + ";"
		initval = "" +
			"\n    @Override" +
			"\n    public int vx_int() {" +
			cnstval +
			"\n      return this.vxint;" +
			"\n    }"
	case "vx/core/string":
		cnstval = "\n      this.vxstring = " + cnstval + ";"
		initval = "" +
			"\n    @Override" +
			"\n    public String vx_string() {" +
			cnstval +
			"\n      return this.vxstring;" +
			"\n    }"
	default:
		switch cnsttype.extends {
		case ":list":
			clstext, msgs := JavaFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
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
			clstext, msgs := JavaFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
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
			clstext, msgs := JavaFromValue(cnst.value, cnst.pkgname, emptyfunc, "      ", true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";"
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						"\n      output.vx_p_" + JavaFromName(prop.name) + " = val." + JavaFromName(prop.name) + "();"

				}
			}
			/*
				clstext, msgs := JavaFromValue(cnst.value, cnst.pkgname, emptyfunc, "        ", true, false, path)
				msgblock = MsgBlockAddBlock(msgblock, msgs)
				if clstext != "" {
					cnstval = "" +
						"\n      if ((this.vxmap == null) || (this.vxmap.size() == 0)) {" +
						"\n        " + cnsttypeclassname + " orig = " + clstext + ";" +
						"\n        this.vxmap = orig.vx_map();" +
						"\n      }"
					initval = "" +
						"\n    @Override" +
						"\n    public Map<String, Core.Type_any> vx_map() {" +
						cnstval +
						"\n      return this.vxmap;" +
						"\n    }"
				}
			*/
		}
	}
	extends := JavaNameClassFullFromType(cnsttype)
	output += "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  public static class " + cnstclassname + " extends " + extends + " {" +
		"\n" +
		"\n    public Core.Type_constdef constdef() {" +
		"\n      return Core.constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + JavaTypeDefFromType(cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    public static " + cnstclassname + " const_new() {" +
		"\n      Const_" + cnstname + " output = new " + cnstclassname + "();" +
		const_new +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		initval +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  public static final " + cnstclassname + " c_" + cnstname + " = " + cnstclassname + ".const_new();" +
		"\n" +
		"\n"
	return output, msgblock
}

func JavaFromFunc(fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaFromFunc")
	var listargtype []string
	var listargname []string
	funcname := JavaFromName(fnc.alias) + JavaIndexFromFunc(fnc)
	returntype := ""
	if fnc.generictype == nil {
		returntype = JavaGenericFromType(fnc.vxtype)
	} else {
		returntype = JavaGenericFromType(fnc.generictype)
	}
	pkgname := JavaNameFromPkgName(fnc.pkgname)
	instancevars := ""
	staticvars := ""
	instancefuncs := ""
	staticfuncs := ""
	f_suppresswarnings := ""
	path := fnc.pkgname + "/" + fnc.name + JavaIndexFromFunc(fnc)
	genericdefinition := JavaGenericDefinitionFromFunc(fnc)
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
				genericargname := JavaNameTFromTypeGeneric(fnc.generictype)
				argtext := "final " + JavaGenericFromType(fnc.generictype) + " " + genericargname
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, genericargname)
			}
		}
	}
	switch NameFromFunc(fnc) {
	case "vx/core/let":
		argtext := "Core.Func_any_from_func fn_any"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any")
	case "vx/core/let-async":
		argtext := "Core.Func_any_from_func_async fn_any_async"
		listargtype = append(listargtype, argtext)
		listargname = append(listargname, "fn_any_async")
	default:
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if fnc.generictype != nil && argtype.isgeneric {
				argtypename = JavaGenericFromType(argtype)
			} else {
				argtypename = JavaNameTypeFromType(argtype)
			}
			argtext := "final " + argtypename + " " + JavaFromName(arg.alias)
			listargname = append(listargname, JavaFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	if fnc.context {
		listargtype = append(listargtype, "final Core.Type_context context")
		listargname = append(listargname, "context")
	}
	//var funcgenerics []string
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = JavaGenericFromType(fnc.generictype)
	} else {
		functypetext = returntype
	}
	if fnc.async {
		functypetext = "CompletableFuture<" + functypetext + ">"
	}
	contextarg := ""
	if fnc.context {
		contextarg = ", final Core.Type_context context"
	}
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-context", "vx/core/any<-func",
		"vx/core/any<-none", "vx/core/any<-key-value",
		"vx/core/any<-reduce", "vx/core/any<-reduce-next":
		instancevars += "" +
			"\n    public IFn fn = null;" +
			"\n" +
			"\n    @Override" +
			"\n    public Func_" + funcname + " fn_new(Core.Class_" + funcname + ".IFn fn) {" +
			"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
			"\n      output.fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-async", "vx/core/any<-any-context-async",
		"vx/core/any<-func-async",
		"vx/core/any<-none-async", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce-async", "vx/core/any<-reduce-next-async":
		instancevars += "" +
			"\n    public IFn fn = null;" +
			"\n" +
			"\n    // static" +
			"\n    public Func_" + funcname + " fn_new(Core.Class_" + funcname + ".IFn fn) {" +
			"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
			"\n      output.fn = fn;" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/string<-func":
		instancefuncs += "" +
			"\n    public Core.Class_any_from_func.IFn fn = null;" +
			"\n" +
			"\n    @Override" +
			"\n    public Func_" + funcname + " fn_new(Core.Class_any_from_func.IFn fn) {" +
			"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
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
				argtypename = JavaNameTypeFromType(arg.vxtype)
				subargnames := "inputval"
				switch NameFromFunc(fnc) {
				case "vx/core/empty":
				default:
					if fnc.generictype != nil {
						subargnames = JavaNameTFromType(fnc.vxtype) + ", inputval"
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
							"\n      T inputval = Core.f_any_from_any(generic_any_1, value);" +
							"\n      CompletableFuture<T> output = Core.f_async(generic_any_1, inputval);"
					} else {
						asyncbody += "" +
							"\n      " + JavaNameTypeFromType(arg.vxtype) + " inputval = Core.f_any_from_any(" + JavaNameTFromType(arg.vxtype) + ", value);" +
							"\n      CompletableFuture<" + returntype + "> future = " + pkgname + ".f_" + funcname + "(" + subargnames + ");" +
							"\n      @SuppressWarnings(\"unchecked\")" +
							"\n      CompletableFuture<T> output = (CompletableFuture<T>)future;"
					}
					instancefuncs += "" +
						"\n    @Override" +
						"\n    public Core.Func_any_from_any" + contextname + "_async fn_new(Core.Class_any_from_any" + contextname + "_async.IFn fn) {return Core.e_any_from_any" + contextname + "_async;}" +
						"\n" +
						"\n    @Override" +
						"\n    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any" + contextname + "_async(final T generic_any_1, final U value" + contextarg + ") {" +
						asyncbody +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					instancefuncs += "" +
						"\n    @Override" +
						"\n    public Core.Func_any_from_any" + contextname + " fn_new(Core.Class_any_from_any" + contextname + ".IFn fn) {return Core.e_any_from_any" + contextname + ";}" +
						"\n" +
						"\n    @Override" +
						"\n    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any" + contextname + "(final T generic_any_1, final U value" + contextarg + ") {" +
						"\n      T output = Core.f_empty(generic_any_1);" +
						"\n      " + argtypename + " inputval = (" + argtypename + ")value;" +
						"\n      Core.Type_any outputval = " + pkgname + ".f_" + funcname + "(" + subargnames + ");" +
						"\n      output = Core.f_any_from_any(generic_any_1, outputval);" +
						"\n      return output;" +
						"\n    }" +
						"\n"
				}
			}
		}
	}
	repltext := JavaReplFromFunc(fnc)
	instancefuncs += repltext
	valuetext, msgs := JavaFromValue(fnc.value, fnc.pkgname, fnc, "", true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	valuetexts := ListStringSplitFromStringDelim(valuetext, "\n")
	var chgvaluetexts []string
	for _, item := range valuetexts {
		if BooleanFromStringContains(item, "@SuppressWarnings") {
			f_suppresswarnings += "\n  " + StringTrim(StringReplace(item, "\\\"", "\""))
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
		permissiontop = lineindent + "if (Core.f_boolean_permission_from_any(" + JavaNameTFromFunc(fnc) + ", context)) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			lineindent + "  Core.Type_msg msg = Core.t_msg.vx_new_error(\"Permission Denied: " + fnc.name + "\");" +
			lineindent + "  output = output.vx_copy(msg);" +
			lineindent + "}"
		indent += "  "
	}
	if fnc.messages {
		msgtop = lineindent + "try {"
		msgbottom = "" +
			lineindent + "} catch (Exception err) {" +
			lineindent + "  Core.Type_msg msg = Core.t_msg.vx_new_from_exception(\"" + fnc.name + "\", err);" +
			lineindent + "  output = output.vx_copy(msg);" +
			lineindent + "}"
		indent += "  "
	}
	lineindent = "\n" + indent
	valuetext = StringJoinFromListString(chgvaluetexts, "\n")
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
	interfacefn := JavaInterfaceFnFromFunc(fnc)
	debugtop, debugbottom := JavaDebugFromFunc(fnc, lineindent)
	switch NameFromFunc(fnc) {
	case "vx/core/new":
		f_suppresswarnings = "\n  @SuppressWarnings(\"unchecked\")"
	}
	returnvalue := ""
	if interfacefn == "" {
		if returntype != "void" {
			returnvalue += "\n      return "
		}
		returnvalue += pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");"
	} else if fnc.async {
		returnvalue += "" +
			"\n      CompletableFuture<T> output;" +
			"\n      if (fn == null) {" +
			"\n        output = CompletableFuture.completedFuture(Core.f_empty(generic_any_1));" +
			"\n      } else {" +
			"\n        CompletableFuture<Core.Type_any> future = fn.resolve(" + strings.Join(listargname, ", ") + ");" +
			"\n        output = Core.async_from_async(generic_any_1, future);" +
			"\n      }" +
			"\n      return output;"
	} else {
		if BooleanFromStringStarts(fnc.name, "boolean<-") {
			returnvalue += "" +
				"\n      Core.Type_boolean output = Core.c_false;" +
				"\n      if (fn != null) {" +
				"\n        output = Core.f_any_from_any(Core.t_boolean, fn.resolve(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		} else {
			returnvalue += "" +
				"\n      T output = Core.f_empty(generic_any_1);" +
				"\n      if (fn != null) {" +
				"\n        output = Core.f_any_from_any(generic_any_1, fn.resolve(" + strings.Join(listargname, ", ") + "));" +
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
			/*
				} else if BooleanFromListStringContains(fnc.listgeneric, ":1") {
					if fnc.async {
						defaultvalue = "" +
							lineindent + "T value_empty = Core.f_empty(generic_any_1);" +
							lineindent + "CompletableFuture<T> output = Core.async_new_completed(value_empty);"
					} else {
						defaultvalue = lineindent + "T output = Core.f_empty(generic_any_1);"
					}
			*/
		} else if fnc.async {
			defaultvalue = lineindent + "CompletableFuture<" + returntype + "> output = Core.async_new_completed(" + JavaNameEFromType(fnc.vxtype) + ");"
		} else if fnc.generictype != nil {
			defaultvalue = lineindent + returntype + " output = Core.f_empty(" + JavaNameTFromTypeGeneric(fnc.generictype) + ");"
		} else {
			defaultvalue = lineindent + returntype + " output = " + JavaNameEFromType(fnc.vxtype) + ";"
		}
	}
	interfacefunc := JavaInterfaceFromFunc(fnc)
	doc := JavaDocFromFunc(fnc)
	output := "" +
		doc +
		interfacefunc +
		"\n  public static class Class_" + funcname + " extends Core.Class_base implements Func_" + funcname + " {" +
		"\n" +
		//"\n    protected Core.Type_msgblock vxmsgblock = null;" +
		//"\n" +
		instancevars +
		"\n    @Override" +
		"\n    public Func_" + funcname + " vx_new(Object... vals) {" +
		"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    @Override" +
		"\n    public Func_" + funcname + " vx_copy(Object... vals) {" +
		"\n      Class_" + funcname + " output = new Class_" + funcname + "();" +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		"\n    @Override" +
		"\n    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}" +
		"\n" +
		"\n    @Override" +
		"\n    public Core.Type_funcdef vx_funcdef() {" +
		"\n      return Core.funcdef_new(" +
		"\n        \"" + fnc.pkgname + "\", // pkgname" +
		"\n        \"" + fnc.name + "\", // name" +
		"\n        " + StringFromInt(fnc.idx) + ", // idx" +
		"\n        " + StringFromBoolean(fnc.async) + ", // async" +
		"\n        " + JavaTypeDefFromType(fnc.vxtype, "        ") + " // typedef" +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    @Override" +
		"\n    public Func_" + funcname + " vx_empty() {return e_" + funcname + ";}" +
		"\n    @Override" +
		"\n    public Func_" + funcname + " vx_type() {return t_" + funcname + ";}" +
		"\n" +
		staticvars +
		interfacefn +
		instancefuncs +
		"\n    @Override" +
		"\n    public " + genericdefinition + functypetext + " f_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		staticfuncs +
		returnvalue +
		"\n    }" +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  public static final Func_" + funcname + " e_" + funcname + " = new " + JavaNameFromPkgName(fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n  public static final Func_" + funcname + " t_" + funcname + " = new " + JavaNameFromPkgName(fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n" +
		f_suppresswarnings +
		"\n  public static " + genericdefinition + functypetext + " f_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
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

func JavaFuncDefsFromFuncs(funcs []*vxfunc, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(funcs) > 0 {
		var outputtypes []string
		for _, fnc := range funcs {
			name := "" +
				lineindent + "  Core.funcdef_new(" +
				lineindent + "    \"" + fnc.pkgname + "\"," +
				lineindent + "    \"" + fnc.name + "\"," +
				lineindent + "    " + StringFromInt(fnc.idx) + "," +
				lineindent + "    " + StringFromBoolean(fnc.async) + "," +
				lineindent + "    null" +
				lineindent + "  )"
			outputtypes = append(outputtypes, name)
		}
		output = "Core.arraylist_from_array(" + StringJoinFromListString(outputtypes, ",") + lineindent + ")"
	}
	return output
}

func JavaFromGenericCode(generic string) string {
	var output = ""
	switch generic {
	case ":1":
		output = "T"
	case ":2":
		output = "U"
	case ":3":
		output = "V"
	case ":4":
		output = "W"
	case ":5":
		output = "X"
	case ":1a":
		output = "Y"
	case ":2a":
		output = "Z"
	case ":3a":
		output = "Q"
	case ":4a":
		output = "R"
	case ":5a":
		output = "S"
	}
	return output
}

func JavaFromName(name string) string {
	output := name
	if output == "extends" {
		output = "extend"
	}
	output = StringReplace(output, "->", "_to_")
	output = StringReplace(output, "<-", "_from_")
	output = StringReplace(output, "<", "lt")
	output = StringReplace(output, ">", "gt")
	output = StringReplace(output, "?", "is")
	output = StringReplace(output, "-", "_")
	output = StringReplace(output, "/", "_")
	return output
}

func JavaFromPackage(pkg *vxpackage, prj *vxproject, pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaFromPackage")
	pkgpath, pkgname := JavaPackagePathFromPrefixName(pkgprefix, pkg.name)
	specialcode := ""
	switch pkg.name {
	case "vx/core":
		specialcode = "" +
			"\n  public static interface Type_replfunc {" +
			"\n    public Core.Type_any vx_repl(Core.Type_anylist arglist);" +
			"\n  }" +
			"\n" +
			"\n  public static interface Type_replfunc_async {" +
			"\n    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist);" +
			"\n  }" +
			"\n" +
			"\n  public static List<Core.Type_any> emptylistany = Core.immutablelist(new ArrayList<Core.Type_any>());" +
			"\n" +
			"\n  public static Map<String, Core.Type_any> emptymapany = Core.immutablemap(new LinkedHashMap<String, Core.Type_any>());" +
			"\n" +
			"\n  public static <T> List<T> immutablelist(List<T> listany) {" +
			"\n    return Collections.unmodifiableList(listany);" +
			"\n  }" +
			"\n" +
			"\n  public static <T> Map<String, T> immutablemap(Map<String, T> mapany) {" +
			"\n    return Collections.unmodifiableMap(mapany);" +
			"\n  }" +
			"\n" +
			"\n  public static class Class_base {" +
			"\n    protected int vx_iref = 0;" +
			"\n    protected Core.Type_msgblock vxmsgblock = null;" +
			"\n    public List<Type_any> vx_dispose() {" +
			"\n      this.vx_iref = 0;" +
			"\n      this.vxmsgblock = null;" +
			"\n      return emptylistany;" +
			"\n    }" +
			"\n    public Core.Type_msgblock vx_msgblock() {return vxmsgblock;}" +
			"\n    public boolean vx_release() {" +
			"\n      boolean output = false;" +
			"\n      if (this.vx_iref < 0) {" +
			"\n      } else if (vx_iref == 0) {" +
			"\n        vx_iref = -1;" +
			"\n        output = true;" +
			"\n      } else {" +
			"\n        vx_iref -= 1;" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n    public void vx_reserve() {this.vx_iref += 1;}" +
			"\n  }" +
			"\n" +
			"\n  public static class KeyValue<T> {" +
			"\n    public String key = \"\";" +
			"\n    public T value = null;" +
			"\n  }" +
			"\n" +
			"\n  public static Core.Type_constdef constdef_new(" +
			"\n    String pkgname," +
			"\n    String name," +
			"\n    Core.Type_any typ" +
			"\n  ) {" +
			"\n    Core.Class_constdef output = new Core.Class_constdef();" +
			"\n    output.vx_p_pkgname = Core.t_string.vx_new_from_string(pkgname);" +
			"\n    output.vx_p_name = Core.t_string.vx_new_from_string(name);" +
			"\n    output.vx_p_type = typ;" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static Core.Type_funcdef funcdef_new(" +
			"\n    String pkgname," +
			"\n    String name," +
			"\n    int idx," +
			"\n    boolean async," +
			"\n    Core.Type_any typ" +
			"\n  ) {" +
			"\n    Core.Class_funcdef output = new Core.Class_funcdef();" +
			"\n    output.vx_p_pkgname = Core.t_string.vx_new_from_string(pkgname);" +
			"\n    output.vx_p_name = Core.t_string.vx_new_from_string(name);" +
			"\n    output.vx_p_idx = Core.t_int.vx_new_from_int(idx);" +
			"\n    output.vx_p_async = Core.t_boolean.vx_new_from_boolean(async);" +
			"\n    output.vx_p_type = typ;" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static Core.Type_any[] arrayany_from_anylist(final Core.Type_anylist list) {" +
			"\n    return list.vx_list().toArray(new Core.Type_any[0]);" +
			"\n  }" +
			"\n" +
			"\n  @SafeVarargs" +
			"\n  public static <T> List<T> arraylist_from_array(final T... items) {" +
			"\n    List<T> output = new ArrayList<T>(Arrays.asList(items));" +
			"\n    output = Core.immutablelist(output);" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T extends Core.Type_any, U extends Core.Type_any> List<T> arraylist_from_arraylist(final T generic_any_1, final List<U> listval) {" +
			"\n    List<T> output = new ArrayList<>();" +
			"\n    for (Core.Type_any value : listval) {" +
			"\n      T t_val = Core.f_any_from_any(generic_any_1, value);" +
			"\n      output.add(t_val);" +
			"\n    }" +
			"\n    output = Core.immutablelist(output);" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T, U> List<T> arraylist_from_arraylist_fn(final List<U> listval, final Function<U, T> fn_any_from_any) {" +
			"\n    List<T> output = new ArrayList<>();" +
			"\n    for (U value_u : listval) {" +
			"\n      T t_val = fn_any_from_any.apply(value_u);" +
			"\n      output.add(t_val);" +
			"\n    }" +
			"\n    output = Core.immutablelist(output);" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T extends Core.Type_any, U extends Core.Type_any> List<T> arraylist_from_linkedhashmap(final T generic_any_1, final Map<String, U> mapval) {" +
			"\n    List<T> output = new ArrayList<T>();" +
			"\n    Set<String> keys = mapval.keySet();" +
			"\n    for (String key : keys) {" +
			"\n      U u_val = mapval.get(key);" +
			"\n      T t_val = Core.f_any_from_any(generic_any_1, u_val);" +
			"\n      output.add(t_val);" +
			"\n    }" +
			"\n    output = Core.immutablelist(output);" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T, U> List<T> arraylist_from_linkedhashmap_fn(final Map<String, U> mapval, final BiFunction<String, U, T> fn_any_from_key_value) {" +
			"\n    List<T> output = new ArrayList<T>();" +
			"\n    Set<String> keys = mapval.keySet();" +
			"\n    for (String key : keys) {" +
			"\n      U u_val = mapval.get(key);" +
			"\n      T t_val = fn_any_from_key_value.apply(key, u_val);" +
			"\n      output.add(t_val);" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T> CompletableFuture<T> async_new_completed(final T val) {" +
			"\n    CompletableFuture<T> output = CompletableFuture.completedFuture(val);" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> async_from_async(T generic_any_1, final CompletableFuture<U> future) {" +
			"\n    CompletableFuture<T> output = future.thenApply(val -> {" +
			"\n      return Core.f_any_from_any(generic_any_1, val);" +
			"\n    });" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T, U> CompletableFuture<T> async_from_async_fn(final CompletableFuture<U> future, final Function<? super U, ? extends T> fn) {" +
			"\n    CompletableFuture<T> output = future.thenApply(fn);" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T> CompletableFuture<List<T>> async_arraylist_from_arraylist_async(final List<CompletableFuture<T>> list_future) {" +
			"\n    CompletableFuture<Void> allFutures = CompletableFuture.allOf(" +
			"\n      list_future.toArray(new CompletableFuture[list_future.size()])" +
			"\n    );" +
			"\n    CompletableFuture<List<T>> output = allFutures.thenApply(v -> {" +
			"\n      List<T> list = list_future.stream()" +
			"\n        .map(future -> future.join())" +
			"\n        .collect(Collectors.toList());" +
			"\n      return Core.immutablelist(list);" +
			"\n    });" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static void debug(Object... values) {" +
			"\n    for (Object value : values) {" +
			"\n      String text = \"\";" +
			"\n      if (value == null) {" +
			"\n        text = \"null\";" +
			"\n      } else if (value instanceof Core.Type_any) {" +
			"\n        Core.Type_any val_any = (Core.Type_any)value;" +
			"\n        Core.Type_string valstring = Core.f_string_from_any(val_any);" +
			"\n        text = valstring.vx_string();" +
			"\n      } else {" +
			"\n        text = value.toString();" +
			"\n      }" +
			"\n      System.out.println(text);" +
			"\n    }" +
			"\n  }" +
			"\n" +
			"\n  @SafeVarargs" +
			"\n  public static <T> LinkedHashMap<String, T> hashmap_from_keyvalues(final KeyValue<T>... keyvalues) {" +
			"\n    LinkedHashMap<String, T> output = new LinkedHashMap<String, T>();" +
			"\n    for (KeyValue<T> keyvalue : keyvalues) {" +
			"\n      String key = keyvalue.key;" +
			"\n      T value = keyvalue.value;" +
			"\n      output.put(key, value);" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T> KeyValue<T> keyvalue_from_key_value(final String key, final T value) {" +
			"\n    KeyValue<T> output = new KeyValue<T>();" +
			"\n    output.key = key;" +
			"\n    output.value = value;" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T> Map<String, T> map_from_list_fn(final List<T> listval, final Function<T, Core.Type_string> fn_any_from_any) {" +
			"\n    Map<String, T> output = new LinkedHashMap<>();" +
			"\n    for (T val : listval) {" +
			"\n      Core.Type_string valkey = fn_any_from_any.apply(val);" +
			"\n      String key = valkey.vx_string();" +
			"\n      output.put(key, val);" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static <T extends Core.Type_any> LinkedHashMap<String, T> map_from_map(final LinkedHashMap<String, Core.Type_any> mapval) {" +
			"\n    LinkedHashMap<String, T> output = new LinkedHashMap<String, T>();" +
			"\n    Set<String> keys = mapval.keySet();" +
			"\n    for (String key : keys) {" +
			"\n      Core.Type_any value = mapval.get(key);" +
			"\n      try {" +
			"\n        @SuppressWarnings(\"unchecked\")" +
			"\n        T castval = (T)value;" +
			"\n        output.put(key, castval);" +
			"\n      } catch (Exception ex) {" +
			"\n        Core.debug(\"map<-map\", ex);" +
			"\n      }" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  // Warning!: Blocking" +
			"\n  public static <T extends Core.Type_any> T sync_from_async(final T generic_any_1, final CompletableFuture<T> future) {" +
			"\n    T output = Core.f_empty(generic_any_1);" +
			"\n    try {" +
			"\n      output = future.get();" +
			"\n    } catch (Exception e) {" +
			"\n      Core.Type_msg msg = Core.t_msg.vx_new_from_exception(\"sync<-async\", e);" +
			"\n      Core.Type_any val = generic_any_1.vx_new(msg);" +
			"\n      output = Core.f_any_from_any(generic_any_1, val);" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  public static Core.Type_typedef typedef_new(" +
			"\n    String pkgname," +
			"\n    String name," +
			"\n    String extend," +
			"\n    Core.Type_typelist traits," +
			"\n    Core.Type_typelist allowtypes," +
			"\n    Core.Type_typelist disallowtypes," +
			"\n    Core.Type_funclist allowfuncs," +
			"\n    Core.Type_funclist disallowfuncs," +
			"\n    Core.Type_anylist allowvalues," +
			"\n    Core.Type_anylist disallowvalues," +
			"\n    Core.Type_argmap properties" +
			"\n  ) {" +
			"\n    Core.Class_typedef output = new Core.Class_typedef();" +
			"\n    output.vx_p_pkgname = Core.t_string.vx_new_from_string(pkgname);" +
			"\n    output.vx_p_name = Core.t_string.vx_new_from_string(name);" +
			"\n    output.vx_p_extend = Core.t_string.vx_new_from_string(extend);" +
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
	}
	typkeys := ListKeyFromMapType(pkg.maptype)
	typetexts := ""
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typetext, msgs := JavaFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typetexts += typetext
	}
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	consttexts := ""
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, msgs := JavaFromConst(cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
	}
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	functexts := ""
	for _, fncid := range fnckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fnctext, msgs := JavaFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			functexts += fnctext
		}
	}
	body := "" +
		specialcode +
		"\n" +
		typetexts +
		consttexts +
		functexts
		//		emptytypes
	imports := JavaImportsFromPackage(pkg, pkgprefix, body, false)
	output := "" +
		"package " + pkgpath + ";" +
		"\n" +
		imports +
		"\n" +
		"\npublic final class " + pkgname + " {" +
		"\n" +
		body +
		"\n}" +
		"\n"
	return output, msgblock
}

func JavaFromText(text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	return output
}

func JavaFromType(typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaFromType")
	output := ""
	path := typ.pkgname + "/" + typ.name
	doc := "" +
		"type: " + typ.name
	if typ.doc != "" {
		doc += "\n" + typ.doc
	}
	if typ.deprecated != "" {
		doc += "\n" + typ.deprecated
	}
	typename := JavaFromName(typ.alias)
	instancefuncs := ""
	createtext, msgs := JavaFromValue(typ.createvalue, "", emptyfunc, "    ", true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		instancefuncs += "\n    " + createtext + "\n"
	}
	staticfuncs := ""
	valnew := ""
	extendinterface := ""
	extendsclass := " extends Core.Class_base"
	valcopy := ""
	switch NameFromType(typ) {
	case "vx/core/any":
		valnew += "" +
			"\n      Core.Type_msgblock msgblock = Core.e_msgblock;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/anytype":
		extendinterface = "Core.Type_any"
	case "vx/core/const":
	case "vx/core/list":
		extendinterface = "Core.Type_anytype"
		instancefuncs += "" +
			"\n" +
			"\n    public <T extends Core.Type_any> List<T> vx_any(final T generic_any_1) {" +
			"\n      return Core.arraylist_from_arraylist(generic_any_1, this.vx_list());" +
			"\n    }" +
			"\n" +
			"\n    public <T extends Core.Type_any> T vx_any_from_list(final T generic_any_1, final int index) {" +
			"\n      return vx_any_from_list(generic_any_1, this.vx_list(), index);" +
			"\n    }" +
			"\n"
		staticfuncs = "" +
			"\n    public static <T extends Core.Type_any> List<T> list_new(final T generic_any_1, final Core.Type_any... vals) {" +
			"\n      List<Core.Type_any> listval = Arrays.asList(vals);" +
			"\n      return Core.arraylist_from_arraylist(generic_any_1, listval);" +
			"\n    }" +
			"\n" +
			"\n    public static <T extends Core.Type_any> T vx_any_from_list(final T generic_any_1, final List<Core.Type_any> list, final int index) {" +
			"\n      T output = Core.f_empty(generic_any_1);" +
			"\n      if (list.size() > index) {" +
			"\n        output = Core.f_any_from_any(generic_any_1, list.get(index));" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    public static <T extends Core.Type_any> T vx_any_first_from_list_fn(final T generic_any_1, final Core.Type_list list, final Function<Core.Type_any, T> fn_any) {" +
			"\n      T output = Core.f_empty(generic_any_1);" +
			"\n      List<Core.Type_any> listany = list.vx_list();" +
			"\n      for (Core.Type_any any : listany) {" +
			"\n        T tany = Core.f_any_from_any(generic_any_1, any);" +
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
		extendinterface = "Core.Type_anytype"
	case "vx/core/struct":
		extendinterface = "Core.Type_map"
	case "vx/core/func":
		extendinterface = "Core.Type_anytype"
		instancefuncs += "" +
			"\n    public Core.Type_funcdef vx_funcdef() {" +
			"\n      return Core.e_funcdef;" +
			"\n    }"
	case "vx/core/type":
		extendinterface = "Core.Type_anytype"
	case "vx/core/boolean":
		valcopy = "" +
			"\n      Core.Type_boolean val = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxboolean = val.vx_boolean();"
		valnew = "" +
			"\n      boolean booleanval = false;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_boolean) {" +
			"\n          Core.Type_boolean valboolean = (Core.Type_boolean)valsub;" +
			"\n          booleanval = booleanval || valboolean.vx_boolean();" +
			"\n        } else if (valsub instanceof Boolean) {" +
			"\n          booleanval = booleanval || (Boolean)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxboolean = booleanval;" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/decimal":
		extendinterface = "Core.Type_number"
		valcopy = "" +
			"\n      Core.Type_decimal val = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxdecimal = val.vx_string();"
		valnew = "" +
			"\n      String sval = \"\";" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_string) {" +
			"\n          Core.Type_string valstring = (Core.Type_string)valsub;" +
			"\n          sval = valstring.vx_string();" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          sval = (String)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxdecimal = sval;" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/float":
		extendinterface = "Core.Type_number"
		valcopy = "" +
			"\n      Core.Type_float val = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxfloat = val.vx_float();"
		valnew = "" +
			"\n      float floatval = 0;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_decimal) {" +
			"\n          Core.Type_decimal valnum = (Core.Type_decimal)valsub;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (valsub instanceof Core.Type_float) {" +
			"\n          Core.Type_float valnum = (Core.Type_float)valsub;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (valsub instanceof Core.Type_int) {" +
			"\n          Core.Type_int valnum = (Core.Type_int)valsub;" +
			"\n          floatval += valnum.vx_int();" +
			"\n        } else if (valsub instanceof Core.Type_string) {" +
			"\n          Core.Type_string valstring = (Core.Type_string)valsub;" +
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
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/int":
		extendinterface = "Core.Type_number"
		valcopy = "" +
			"\n      Core.Type_int val = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxint = val.vx_int();"
		valnew = "" +
			"\n      int intval = 0;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_int) {" +
			"\n          Core.Type_int valnum = (Core.Type_int)valsub;" +
			"\n          intval += valnum.vx_int();" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          intval += (Integer)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxint = intval;" +
			"\n      if (msgblock != Core.t_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		valcopy = "" +
			"\n      Core.Class_string val = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      output.vxstring = val.vx_string();"
		valnew = "" +
			"\n      StringBuilder sb = new StringBuilder(output.vx_string());" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_string) {" +
			"\n          Core.Type_string valstring = (Core.Type_string)valsub;" +
			"\n          sb.append(valstring.vx_string());" +
			"\n        } else if (valsub instanceof Core.Type_int) {" +
			"\n          Core.Type_int valint = (Core.Type_int)valsub;" +
			"\n          sb.append(valint.vx_int());" +
			"\n        } else if (valsub instanceof Core.Type_float) {" +
			"\n          Core.Type_float valfloat = (Core.Type_float)valsub;" +
			"\n          sb.append(valfloat.vx_float());" +
			"\n        } else if (valsub instanceof Core.Type_decimal) {" +
			"\n          Core.Type_decimal valdecimal = (Core.Type_decimal)valsub;" +
			"\n          sb.append(valdecimal.vx_string());" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          sb.append((String)valsub);" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          sb.append((Integer)valsub);" +
			"\n        } else if (valsub instanceof Float) {" +
			"\n          sb.append((Float)valsub);" +
			"\n        } else {" +
			"\n          Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Type: \" + valsub.toString());" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxstring = sb.toString();" +
			"\n      if (msgblock != Core.t_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
	}
	switch typ.extends {
	case ":list":
		allowcode := ""
		allowname := "any"
		allowclass := "Core.Type_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = JavaNameTypeFullFromType(allowtype)
			allowempty := JavaNameEFromType(allowtype)
			allowname = JavaNameFromType(allowtype)
			allowcode = "" +
				"\n    @Override" +
				"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_int index) {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      Class_" + typename + " list = this;" +
				"\n      int iindex = index.vx_int();" +
				"\n      List<" + allowclass + "> listval = list.vxlist;" +
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
				"\n    @Override" +
				"\n    public List<" + allowclass + "> vx_list" + allowname + "() {return vxlist;}" +
				"\n" +
				"\n    @Override" +
				"\n    public Core.Type_any vx_any(final Core.Type_int index) {" +
				"\n      return this.vx_" + allowname + "(index);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    protected List<" + allowclass + "> vxlist = Core.immutablelist(new ArrayList<" + allowclass + ">());" +
			"\n" +
			"\n    @Override" +
			"\n    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}" +
			"\n" +
			allowcode
		valcopy = "" +
			"\n      Type_" + typename + " val = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
			"\n      List<" + allowclass + "> listval = new ArrayList<>(val.vx_list" + allowname + "());"
		switch typ.name {
		case "msgblocklist":
			valnew = "" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof Core.Type_msg) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);"
		case "msglist":
			valnew = "" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof Core.Type_msgblock) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);"
		default:
			valnew = "" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof Core.Type_msgblock) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);" +
				"\n        } else if (valsub instanceof Core.Type_msg) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);" +
				"\n        } else if (valsub instanceof " + allowclass + ") {" +
				"\n          listval.add((" + allowclass + ")valsub);"
		}
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := JavaNameTypeFromType(allowedtype)
			castval := "(" + allowedtypename + ")valsub"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "Boolean"
					castval = "Core.t_boolean.vx_new(valsub)"
				case "vx/core/int":
					allowedtypename = "Integer"
					castval = "Core.t_int.vx_new(valsub)"
				case "vx/core/float":
					allowedtypename = "Float"
					castval = "Core.t_float.vx_new(valsub)"
				case "vx/core/string":
					allowedtypename = "String"
					castval = "Core.t_string.vx_new(valsub)"
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
			"\n          List<?> listunknown = (List<?>)valsub;" +
			"\n          for (Object item : listunknown) {" +
			"\n            if (item instanceof " + allowclass + ") {" +
			"\n              " + allowclass + " valitem = (" + allowclass + ")item;" +
			"\n              listval.add(valitem);" +
			"\n            }" +
			"\n          }" +
			"\n        } else {" +
			"\n          Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Type: \" + valsub.toString());" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxlist = Core.immutablelist(listval);" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
		if extendinterface == "" {
			extendinterface = "Core.Type_list"
		}
		if len(typ.allowtypes) == 0 && len(typ.allowfuncs) == 0 && len(typ.allowvalues) == 0 {
			MsgLog("Missing allowed types", typ.name)
		}
	case ":map":
		allowcode := ""
		allowname := "any"
		allowclass := "Core.Type_any"
		allowtypes := ListAllowTypeFromType(typ)
		if len(allowtypes) > 0 {
			allowtype := allowtypes[0]
			allowclass = JavaNameTypeFullFromType(allowtype)
			allowempty := JavaNameEFromType(allowtype)
			allowname = JavaNameFromType(allowtype)
			allowcode = "" +
				"\n    @Override" +
				"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_string key) {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      Class_" + typename + " map = this;" +
				"\n      String skey = key.vx_string();" +
				"\n      Map<String, " + allowclass + "> mapval = map.vxmap;" +
				"\n      output = mapval.getOrDefault(skey, " + allowempty + ");" +
				"\n      return output;" +
				"\n    }" +
				"\n"
		}
		if allowname == "any" {
			allowname = ""
		} else {
			allowcode += "" +
				"\n    @Override" +
				"\n    public Map<String, " + allowclass + "> vx_map" + allowname + "() {return vxmap;}" +
				"\n" +
				"\n    @Override" +
				"\n    public Core.Type_any vx_any(final Core.Type_string key) {" +
				"\n      return this.vx_" + allowname + "(key);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    protected Map<String, " + allowclass + "> vxmap = Core.immutablemap(new LinkedHashMap<String, " + allowclass + ">());" +
			"\n" +
			"\n    @Override" +
			"\n    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vxmap));}" +
			"\n" +
			allowcode +
			"\n    @Override" +
			"\n    public Type_" + typename + " vx_new_from_map(final Map<String, Core.Type_any> mapval) {" +
			"\n      Class_" + typename + " output = new Class_" + typename + "();" +
			"\n      Core.Type_msgblock msgblock = Core.e_msgblock;" +
			"\n      Map<String, " + allowclass + "> map = new LinkedHashMap<>();" +
			"\n      Set<String> keys = mapval.keySet();" +
			"\n      for (String key : keys) {" +
			"\n        Core.Type_any val = mapval.get(key);" +
			"\n        if (val instanceof " + allowclass + ") {" +
			"\n          " + allowclass + " castval = (" + allowclass + ")val;" +
			"\n          map.put(key, castval);" +
			"\n        } else {" +
			"\n          Core.Type_msg msg = Core.t_msg.vx_new_error(\"(" + typename + ") Invalid Value: \" + val.toString() + \"\");" +
			"\n          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxmap = Core.immutablemap(map);" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
		valcopy = "" +
			"\n      Type_" + typename + " valmap = this;" +
			"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(valmap, vals);"
		valnew = "" +
			"\n      Map<String, " + allowclass + "> mapval = new LinkedHashMap<>(valmap.vx_map" + allowname + "());" +
			"\n      String key = \"\";" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);" +
			"\n        } else if (key.equals(\"\")) {" +
			"\n          if (valsub instanceof Core.Type_string) {" +
			"\n            Core.Type_string valstring = (Core.Type_string)valsub;" +
			"\n            key = valstring.vx_string();" +
			"\n          } else if (valsub instanceof String) {" +
			"\n            key = (String)valsub;" +
			"\n          } else {" +
			"\n            Core.Type_msg msg = Core.t_msg.vx_new_error(\"Key Expected: \" + valsub.toString() + \"\");" +
			"\n            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n        } else {" +
			"\n          " + allowclass + " valany = null;" +
			"\n          if (valsub instanceof " + allowclass + ") {" +
			"\n            valany = (" + allowclass + ")valsub;"
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := JavaNameTypeFromType(allowedtype)
			castval := "(" + allowedtypename + ")valsub"
			if allowedtypename == allowclass {
				switch NameFromType(allowedtype) {
				case "vx/core/boolean":
					allowedtypename = "Boolean"
					castval = "Core.t_boolean.vx_new(valsub);"
				case "vx/core/int":
					allowedtypename = "Integer"
					castval = "Core.t_int.vx_new(valsub);"
				case "vx/core/float":
					allowedtypename = "Float"
					castval = "Core.t_float.vx_new(valsub);"
				case "vx/core/string":
					allowedtypename = "String"
					castval = "Core.t_string.vx_new(valsub);"
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
			"\n            Core.Type_msg msg = Core.t_msg.vx_new_error(\"Invalid Key/Value: \" + key + \" \"  + valsub.toString() + \"\");" +
			"\n            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n          if (valany != null) {" +
			"\n            mapval.put(key, valany);" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      output.vxmap = Core.immutablemap(mapval);" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }"
		if extendinterface == "" {
			extendinterface = "Core.Type_map"
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
				"\n      Core.Type_msgblock msgblock = this;"
		default:
			valcopy += "" +
				"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);"
		}
		if extendinterface == "" {
			extendinterface = "Core.Type_struct"
		}
		props := ListPropertyTraitFromType(typ)
		switch len(props) {
		case 0:
			valnew = "" +
				"\n      if (msgblock != Core.e_msgblock) {" +
				"\n        output.vxmsgblock = msgblock;" +
				"\n      }"
		default:
			validkeys := "\n      ArrayList<String> validkeys = new ArrayList<>();"
			valnewswitch := ""
			for _, arg := range props {
				validkeys += "\n      validkeys.add(\":" + arg.name + "\");"
				argname := JavaFromName(arg.name)
				valcopy += "\n      output.vx_p_" + argname + " = val." + argname + "();"
				vx_map += "\n      output.put(\":" + arg.name + "\", this." + argname + "());"
				vx_any += "" +
					"\n      case \":" + arg.name + "\":" +
					"\n        output = this." + argname + "();" +
					"\n        break;"
				argclassname := JavaNameTypeFromType(arg.vxtype)
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						"\n            } else if (valsub instanceof Boolean) {" +
						"\n              output.vx_p_" + argname + " = Core.t_boolean.vx_new(valsub);"
				case "vx/core/int":
					argalt = "" +
						"\n            } else if (valsub instanceof Integer) {" +
						"\n              output.vx_p_" + argname + " = Core.t_int.vx_new(valsub);"
				case "vx/core/float":
					argalt = "" +
						"\n            } else if (valsub instanceof Float) {" +
						"\n              output.vx_p_" + argname + " = Core.t_float.vx_new(valsub);"
				case "vx/core/string":
					argalt = "" +
						"\n            } else if (valsub instanceof String) {" +
						"\n              output.vx_p_" + argname + " = Core.t_string.vx_new(valsub);"
				}
				valnewswitch += "" +
					"\n          case \":" + arg.name + "\":" +
					"\n            if (valsub instanceof " + argclassname + ") {" +
					"\n              output.vx_p_" + argname + " = (" + argclassname + ")valsub;" +
					argalt +
					"\n            } else {" +
					"\n              Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + " :" + arg.name + " \" + valsub.toString() + \") - Invalid Value\");" +
					"\n              msgblock = msgblock.vx_copy(msg);" +
					"\n            }" +
					"\n            break;"
				instancefuncs += "" +
					"\n    protected " + argclassname + " vx_p_" + argname + ";" +
					"\n" +
					"\n    @Override" +
					"\n    public " + argclassname + " " + argname + "() {" +
					"\n      return this.vx_p_" + argname + " == null ? " + JavaNameEFromType(arg.vxtype) + " : this.vx_p_" + argname + ";" +
					//"\n      Core.Type_any valsub = this.vx_map().getOrDefault(\":" + arg.name + "\", " + JavaNameEFromType(arg.vxtype) + ");" +
					//"\n      return Core.f_any_from_any(" + JavaNameTFromType(arg.vxtype) + ", valsub);" +
					"\n    }" +
					"\n"
			}
			defaultkey := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := JavaFromName(lastarg.name)
				argclassname := JavaNameTypeFromType(lastarg.vxtype)
				defaultkey += "" +
					"\n          } else if (valsub instanceof " + argclassname + ") { // default property" +
					"\n            output.vx_p_" + lastargname + " = (" + argclassname + ")valsub;"
				switch NameFromType(lastarg.vxtype) {
				case "vx/core/boolean":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Boolean) { // default property" +
						"\n            output.vx_p_" + lastargname + " = Core.t_boolean.vx_new(valsub);"
				case "vx/core/int":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Integer) { // default property" +
						"\n            output.vx_p_" + lastargname + " = Core.t_int.vx_new(valsub);"
				case "vx/core/float":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Float) { // default property" +
						"\n            output.vx_p_" + lastargname + " = Core.t_float.vx_new(valsub);"
				case "vx/core/string":
					defaultkey += "" +
						"\n          } else if (valsub instanceof String) { // default property" +
						"\n            output.vx_p_" + lastargname + " = Core.t_string.vx_new(valsub);"
				}
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						subargclassname := JavaNameTypeFromType(allowtype)
						defaultkey += "" +
							"\n          } else if (valsub instanceof " + subargclassname + ") { // default property" +
							"\n            " + subargclassname + " valdefault = (" + subargclassname + ")valsub;" +
							"\n            " + argclassname + " vallist = output.vx_p_" + lastargname + ";" +
							"\n            if (vallist == null) {" +
							"\n              vallist = " + JavaNameTFromType(lastarg.vxtype) + ".vx_new(valdefault);" +
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
					"\n          if (valsub instanceof Core.Type_string) {" +
					"\n            Core.Type_string valstr = (Core.Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            key = (String)valsub;" +
					"\n          } else {" +
					"\n            Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + valsub.toString());" +
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
					"\n        if (valsub instanceof Core.Type_msgblock) {" +
					"\n          Core.Type_msgblocklist msgblocks = this.msgblocks();" +
					"\n          msgblocks = msgblocks.vx_copy(valsub);" +
					"\n          output.vx_p_msgblocks = msgblocks;" +
					"\n        } else if (valsub instanceof Core.Type_msg) {" +
					"\n          Core.Type_msglist msgs = this.msgs();" +
					"\n          msgs = msgs.vx_copy(valsub);" +
					"\n          output.vx_p_msgs = msgs;" +
					"\n        } else if (valsub instanceof Core.Type_msgblocklist) {" +
					"\n          Core.Type_msgblocklist msgblocks = this.msgblocks();" +
					"\n          msgblocks = msgblocks.vx_copy(valsub);" +
					"\n          output.vx_p_msgblocks = msgblocks;" +
					"\n        } else if (valsub instanceof Core.Type_msglist) {" +
					"\n          Core.Type_msglist msgs = this.msgs();" +
					"\n          msgs = msgs.vx_copy(valsub);" +
					"\n          output.vx_p_msgs = msgs;" +
					"\n        } else if (key == \"\") {" +
					"\n          if (valsub instanceof Core.Type_string) {" +
					"\n            Core.Type_string valstr = (Core.Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            key = (String)valsub;" +
					"\n          } else {" +
					"\n            Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + valsub.toString());" +
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
					"\n        if (valsub instanceof Core.Type_msgblock) {" +
					"\n          msgblock = msgblock.vx_copy(valsub);" +
					"\n        } else if (valsub instanceof Core.Type_msg) {" +
					"\n          msgblock = msgblock.vx_copy(valsub);" +
					"\n        } else if (key == \"\") {" +
					"\n          String testkey = \"\";" +
					"\n          if (valsub instanceof Core.Type_string) {" +
					"\n            Core.Type_string valstr = (Core.Type_string)valsub;" +
					"\n            testkey = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            testkey = (String)valsub;" +
					"\n          }" +
					"\n          boolean isvalidkey = validkeys.contains(testkey);" +
					"\n          if (isvalidkey) {" +
					"\n            key = testkey;" +
					defaultkey +
					"\n          } else {" +
					"\n            Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key Type: \" + valsub.toString());" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          default:" +
					"\n            Core.Type_msg msg = Core.t_msg.vx_new_error(\"(new " + typ.name + ") - Invalid Key: \" + key);" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (msgblock != Core.e_msgblock) {" +
					"\n        output.vxmsgblock = msgblock;" +
					"\n      }"
			}
		}
		instancefuncs += "" +
			"\n    @Override" +
			"\n    public Core.Type_any vx_any(final Core.Type_string key) {" +
			"\n      Core.Type_any output = Core.e_any;" +
			"\n      String skey = key.vx_string();" +
			"\n      switch (skey) {" +
			vx_any +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n" +
			"\n    @Override" +
			"\n    public Map<String, Core.Type_any> vx_map() {" +
			"\n      Map<String, Core.Type_any> output = new LinkedHashMap<>();" +
			vx_map +
			"\n      return Core.immutablemap(output);" +
			"\n    }" +
			"\n"
	default:
		if extendinterface == "" {
			extendinterface = "Core.Type_anytype"
		}
	}
	vxmsgblock := ""
	switch NameFromType(typ) {
	case "vx/core/msg":
		vxmsgblock = "" +
			"\n    @Override" +
			"\n    public Core.Type_msgblock vx_msgblock() {return Core.e_msgblock;}"
	case "vx/core/msgblock":
		vxmsgblock = "" +
			"\n    @Override" +
			"\n    public Core.Type_msgblock vx_msgblock() {return this;}"
	}
	sinterface := JavaInterfaceFromType(typ)
	typedef := "" +
		"\n    @Override" +
		"\n    public Core.Type_typedef vx_typedef() {" +
		"\n      return " + JavaTypeDefFromType(typ, "      ") + ";" +
		"\n    }" +
		"\n"
	output += "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (type " + typ.name + ")" +
		"\n   */" +
		sinterface +
		"\n  public static class Class_" + typename + extendsclass + " implements Type_" + JavaNameFromType(typ) + " {" +
		"\n" +
		instancefuncs +
		"\n    @Override" +
		"\n    public Type_" + typename + " vx_new(final Object... vals) {return e_" + typename + ".vx_copy(vals);}" +
		"\n" +
		"\n    @Override" +
		"\n    public Type_" + typename + " vx_copy(final Object... vals) {" +
		"\n      Class_" + typename + " output = new Class_" + typename + "();" +
		valcopy +
		valnew +
		"\n      return output;" +
		"\n    }" +
		"\n" +
		vxmsgblock +
		"\n    @Override" +
		"\n    public Type_" + typename + " vx_empty() {return e_" + typename + ";}" +
		"\n    @Override" +
		"\n    public Type_" + typename + " vx_type() {return t_" + typename + ";}" +
		"\n" +
		typedef +
		staticfuncs +
		"\n  }" +
		"\n" +
		"\n  public static final Type_" + typename + " e_" + typename + " = new Class_" + typename + "();" +
		"\n  public static final Type_" + typename + " t_" + typename + " = new Class_" + typename + "();" +
		"\n"
	return output, msgblock
}

func JavaFromValue(value vxvalue, pkgname string, parentfn *vxfunc, indent string, encode bool, test bool, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaFromValue")
	var output = ""
	valstr := ""
	switch value.code {
	case ":arg":
		valarg := ArgFromValue(value)
		valstr = JavaFromName(valarg.name)
		output += valstr
	case ":const":
		switch value.name {
		case "false", "true":
			valstr = "Core.t_boolean.vx_new_from_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = JavaFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = JavaNameFromPkgName(valconst.pkgname) + ".c_" + JavaFromName(valconst.alias)
			}
		}
		output = valstr
	case ":func":
		fnc := FuncFromValue(value)
		subpath := path + "/" + fnc.name
		funcname := NameFromFunc(fnc)
		switch fnc.name {
		case "native":
			// (native :java)
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
				if valuetext == ":java" {
					isNative = true
				} else if BooleanFromStringStarts(valuetext, ":") {
					isNative = false
				} else if isNative {
					if argvalue.name == "newline" {
						argtext = "\n"
					} else {
						clstext, msgs := JavaFromValue(argvalue, pkgname, parentfn, "", false, test, subpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						argtext = clstext
						if nativeindent == "undefined" {
							nativeindent = "\n" + StringRepeat(" ", argvalue.textblock.charnum)
						} else if nativeindent != "" {
							argtext = StringReplace(argtext, nativeindent, "\n")
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
					output += StringFromStringIndent(StringJoinFromListString(argtexts, ""), indent)
				} else {
					output += StringJoinFromListString(argtexts, "")
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
					work, msgs := JavaFromValue(structvalue, pkgname, fnc, "", true, test, subpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					work = work + "." + JavaFromName(propname) + "()"
					argtexts = append(argtexts, work)
					isskip = true
				}
			case "vx/core/fn":
			case "vx/core/let":
				if fnc.async {
					output += JavaNameFromPkgName(fnc.pkgname) + ".f_let_async("
				} else {
					output += JavaNameFromPkgName(fnc.pkgname) + ".f_" + JavaNameFromFunc(fnc) + "("
				}
			default:
				output += JavaNameFromPkgName(fnc.pkgname) + ".f_" + JavaNameFromFunc(fnc) + "("
			}
			if !isskip {
				if fnc.isgeneric {
					switch funcname {
					case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
					default:
						if fnc.generictype != nil {
							genericarg := JavaNameTFromTypeGeneric(fnc.vxtype)
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
								argvaltype = JavaNameTypeFullFromType(argtype)
								argvalinstance = JavaNameTFromType(argtype)
								lambdavar := argvaltype + " " + lambdaarg.name + " = Core.f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any);"
								lambdavars = append(lambdavars, lambdavar)
							}
							lambdatext := StringJoinFromListString(lambdaargs, ", ")
							lambdavartext := "\n  " + StringJoinFromListString(lambdavars, "\n  ")
							if argfunc.async {
								work, msgs := JavaFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-key-value-async":
									argtext = "" +
										"Core.t_any_from_key_value_async.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-async":
									argtext = "" +
										"Core.t_any_from_reduce_async.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next-async":
									argtext = "" +
										"Core.t_any_from_reduce_next_async.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"Core.t_any_from_any_async.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"Core.t_any_from_func_async.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								work, msgs := JavaFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-key-value":
									argtext = "" +
										"Core.t_any_from_key_value.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce":
									argtext = "" +
										"Core.t_any_from_reduce.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								case "any<-reduce-next":
									argtext = "" +
										"Core.t_any_from_reduce_next.fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											"Core.t_any_from_any.fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											"Core.t_any_from_func.fn_new((" + lambdatext + ") -> {" +
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
											lambdavaluetext, msgs := JavaFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + "final CompletableFuture<" + JavaNameTypeFromType(lambdaarg.vxtype) + "> future_" + JavaFromName(lambdaarg.name) + " = " + lambdavaluetext + ";" +
												arglineindent + "return Core.async_from_async_fn(future_" + JavaFromName(lambdaarg.name) + ", (" + JavaFromName(lambdaarg.name) + ") -> {"
											aftertext += "" +
												arglineindent + "});"
											argindent += "  "
										} else {
											lambdavaluetext, msgs := JavaFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + "final " + JavaNameTypeFromType(lambdaarg.vxtype) + " " + JavaFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
										}
									}
									work, msgs := JavaFromValue(argvalue, pkgname, fnc, "    ", true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										"Core.t_any_from_func_async.fn_new(() -> {" +
										lambdatext +
										"\n    return " + work + ";" +
										aftertext +
										"\n})"
								} else {
									argindent := "  "
									arglineindent := "\n" + argindent
									for _, lambdaarg := range arglist {
										lambdaargpath := argsubpath + "/:arg/" + lambdaarg.name
										lambdavaluetext, msgs := JavaFromValue(lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										lambdatext += arglineindent + "final " + JavaNameTypeFromType(lambdaarg.vxtype) + " " + JavaFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
									}
									work, msgs := JavaFromValue(argvalue, pkgname, fnc, "", true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									argtext = "" +
										"Core.t_any_from_func.fn_new(() -> {" +
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
									work, msgs := JavaFromValue(argvalue, pkgname, fnc, subindent, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										"Core.t_any_from_func.fn_new(() -> {" +
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
								work, msgs := JavaFromValue(argvalue, pkgname, fnc, workindent, true, test, argsubpath)
								if converttoasync {
									work = "Core.f_async(" + JavaNameTFromType(argfunctype) + ",\n" + workindent + work + "\n  )"
								}
								msgblock = MsgblockAddBlock(msgblock, msgs)
								if argvalue.code == ":func" && argvalue.name == "native" {
								} else {
									work = "\n  return " + work + ";"
								}
								argtext = "" +
									JavaNameTFromType(funcarg.vxtype) + ".fn_new(() -> {" +
									work +
									"\n})"
							}
						}
						if argtext == "" {
							work, msgs := JavaFromValue(argvalue, pkgname, fnc, "", true, test, argsubpath)
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
									JavaNameTFromType(funcarg.vxtype) + ".vx_new(" +
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
				output += "\n" + indent + "  " + StringFromStringIndent(StringJoinFromListString(argtexts, ",\n"), indent+"  ")
				if multiflag {
					output += "\n" + indent + "  )"
				}
				switch fnc.name {
				case "fn":
				default:
					output += "\n" + indent + ")"
				}
			} else {
				output += StringJoinFromListString(argtexts, ", ")
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
		valstr += JavaNameFromPkgName(valfunc.pkgname) + ".t_" + JavaFromName(valfunc.alias)
		output = indent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = JavaNameFromPkgName(valtype.pkgname) + ".t_" + JavaFromName(valtype.alias)
	case "string":
		valstr = StringValueFromValue(value)
		if valstr == "" {
		} else if BooleanFromStringStarts(valstr, ":") {
			output = valstr
		} else if BooleanFromStringStartsEnds(valstr, "\"", "\"") {
			valstr = valstr[1 : len(valstr)-1]
			if encode {
				output = StringReplace(valstr, "\n", "\\n")
			} else {
				output = valstr
			}
		} else if BooleanIsNumberFromString(valstr) {
			output = valstr
		} else {
			output = valstr
		}
		if encode {
			output = JavaTypeStringValNew(output)
		}
	case "boolean":
		if encode {
			valstr = StringValueFromValue(value)
			output = "Core.t_boolean.vx_new_from_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = "Core.t_decimal.vx_new_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = "Core.t_float.vx_new_from_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = "Core.t_int.vx_new_from_int(" + valstr + ")"
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

func JavaGenericDefinitionFromFunc(fnc *vxfunc) string {
	output := ""
	var mapgeneric = make(map[string]string)
	if fnc.generictype != nil {
		returntype := JavaGenericFromType(fnc.generictype)
		mapgeneric[fnc.vxtype.name] = returntype + " extends " + JavaNameTypeFromType(fnc.vxtype)
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			if !argtype.isfunc {
				if argtype.isgeneric {
					_, ok := mapgeneric[argtype.name]
					if !ok {
						argtypename := JavaGenericFromType(argtype)
						worktext := argtypename + " extends " + JavaNameTypeFromType(arg.vxtype)
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
		output = "<" + output + "> "
	}
	return output
}

func JavaGenericFromType(typ *vxtype) string {
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
		output = JavaNameTypeFromType(typ)
	}
	return output
}

func JavaImportsFromPackage(pkg *vxpackage, pkgprefix string, body string, test bool) string {
	output := ""
	if BooleanFromStringContains(body, "Arrays.") {
		output += "\nimport java.util.Arrays;"
	}
	if BooleanFromStringContains(body, " ArrayList<") {
		output += "\nimport java.util.ArrayList;"
	}
	if BooleanFromStringContains(body, "Collections.") {
		output += "\nimport java.util.Collections;"
	}
	if BooleanFromStringContains(body, " CompletableFuture<") {
		output += "\nimport java.util.concurrent.CompletableFuture;"
	}
	if BooleanFromStringContains(body, " ConcurrentLinkedDeque<") {
		output += "\nimport java.util.concurrent.ConcurrentLinkedDeque;"
	}
	if BooleanFromStringContains(body, " ConcurrentHashMap<") {
		output += "\nimport java.util.concurrent.ConcurrentHashMap;"
	}
	if BooleanFromStringContains(body, " Deque<") {
		output += "\nimport java.util.Deque;"
	}
	if BooleanFromStringContains(body, " LinkedHashMap<") {
		output += "\nimport java.util.LinkedHashMap;"
	}
	if BooleanFromStringContains(body, " List<") {
		output += "\nimport java.util.List;"
	}
	if BooleanFromStringContains(body, " Map<") {
		output += "\nimport java.util.Map;"
	}
	if BooleanFromStringContains(body, " Set<") {
		output += "\nimport java.util.Set;"
	}
	pkgpath, _ := PackagePathNameFromName(pkg.name)
	if len(pkg.listlib) > 0 {
		for _, lib := range pkg.listlib {
			isskip := false
			libpath := lib.path
			libpkgpath, _ := PackagePathNameFromName(lib.path)
			if lib.lang != "" {
				if test {
					isskip = true
				} else if lib.lang == ":java" {
				} else {
					isskip = true
				}
			} else if libpkgpath == pkgpath {
				isskip = true
			} else {
				libpath = pkgprefix + "/" + libpkgpath + "*"
				libpath = StringReplace(libpath, "/", ".")
			}
			if !isskip {
				importline := "\nimport " + libpath + ";"
				if IntFromStringIndex(output, importline) < 0 {
					output += importline
				}
			}
		}
		output += "\n"
	}
	return output
}

func JavaIndexFromFunc(fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func JavaInterfaceFromType(typ *vxtype) string {
	output := ""
	typename := JavaNameTypeFullFromType(typ)
	basics := "" +
		"\n    public " + typename + " vx_new(final Object... vals);" +
		"\n    public " + typename + " vx_copy(final Object... vals);" +
		"\n    public " + typename + " vx_empty();" +
		"\n    public " + typename + " vx_type();"
	createtext, _ := JavaFromValue(typ.createvalue, "", emptyfunc, "", true, false, "")
	if createtext != "" {
		createlines := ListStringSplitFromStringDelim(createtext, "\n")
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
			"\n  public interface Type_any {" +
			basics +
			"\n    public Core.Type_typedef vx_typedef();" +
			"\n    public List<Type_any> vx_dispose();" +
			"\n    public Core.Type_msgblock vx_msgblock();" +
			"\n    public boolean vx_release();" +
			"\n    public void vx_reserve();" +
			"\n  }" +
			"\n"
	case "vx/core/boolean":
		output = "" +
			"\n  public interface Type_boolean extends Core.Type_any {" +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/decimal":
		output = "" +
			"\n  public interface Type_decimal extends Core.Type_number {" +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/float":
		output = "" +
			"\n  public interface Type_float extends Core.Type_number {" +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/func":
		output = "" +
			"\n  public interface Type_func extends Core.Type_any {" +
			basics +
			"\n	   public Core.Type_funcdef vx_funcdef();" +
			"\n  }" +
			"\n"
	case "vx/core/int":
		output = "" +
			"\n  public interface Type_int extends Core.Type_number {" +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/string":
		output = "" +
			"\n  public interface Type_string extends Core.Type_any {" +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/list":
		output = "" +
			"\n  public interface Type_list extends Core.Type_any {" +
			basics +
			"\n    public List<Core.Type_any> vx_list();" +
			"\n    public Core.Type_any vx_any(final Core.Type_int index);" +
			"\n  }" +
			"\n"
	case "vx/core/map":
		output = "" +
			"\n  public interface Type_map extends Core.Type_any {" +
			basics +
			"\n    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval);" +
			"\n    public Core.Type_any vx_any(final Core.Type_string key);" +
			"\n    public Map<String, Core.Type_any> vx_map();" +
			"\n  }" +
			"\n"
	case "vx/core/struct":
		output = "" +
			"\n  public interface Type_struct extends Core.Type_any {" +
			basics +
			"\n    public Core.Type_any vx_any(final Core.Type_string key);" +
			"\n    public Map<String, Core.Type_any> vx_map();" +
			"\n  }" +
			"\n"
	default:
		extras := ""
		switch NameFromType(typ) {
		case "vx/core/msg":
			basics = "" +
				"\n    public " + typename + " vx_new(final Object... vals);" +
				"\n    public " + typename + " vx_copy(final Object... vals);" +
				"\n    public " + typename + " vx_empty();" +
				"\n    public " + typename + " vx_type();" +
				"\n    public Core.Type_typedef vx_typedef();"
			extras += "" +
				"\n    public Type_msg vx_new_error(final String text);" +
				"\n    public Type_msg vx_new_from_exception(final String text, final Exception err);"
		case "vx/core/msgblock":
			basics = "" +
				"\n    public " + typename + " vx_new(final Object... vals);" +
				"\n    public " + typename + " vx_copy(final Object... vals);" +
				"\n    public " + typename + " vx_empty();" +
				"\n    public " + typename + " vx_type();" +
				"\n    public Core.Type_typedef vx_typedef();"
			extras += "" +
				"\n    public Type_msgblock vx_msgblock_from_copy_arrayval(final Core.Type_any copy, final Object... vals);"
		}
		extends := ""
		switch typ.extends {
		case "boolean":
			extends += "Core.Type_boolean"
		case "decimal":
			extends += "Core.Type_decimal"
		case "float":
			extends += "Core.Type_float"
		case "int":
			extends += "Core.Type_int"
		case "string":
			extends += "Core.Type_string"
		case ":list":
			extends += "Core.Type_list"
			allowclass := "Core.Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = JavaNameTypeFullFromType(allowtype)
				allowname = JavaNameFromType(allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    public List<" + allowclass + "> vx_list" + allowname + "();" +
					"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_int index);"
			}
		case ":map":
			extends = "Core.Type_map"
			allowclass := "Core.Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = JavaNameTypeFullFromType(allowtype)
				allowname = JavaNameFromType(allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    public Map<String, " + allowclass + "> vx_map" + allowname + "();" +
					"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_string key);"
			}
		case ":struct":
			extends = "Core.Type_struct"
			if len(typ.traits) > 0 {
				var traitnames []string
				for _, trait := range typ.traits {
					traitnames = append(traitnames, JavaNameTypeFullFromType(trait))
				}
				extends = StringJoinFromListString(traitnames, ", ")
			}
			for _, arg := range ListPropertyTraitFromType(typ) {
				extras += "\n    public " + JavaNameTypeFromType(arg.vxtype) + " " + JavaFromName(arg.alias) + "();"
			}
		default:
			extends += "Core.Type_any"
		}
		typename := JavaNameFromType(typ)
		output = "" +
			"\n  public interface Type_" + typename + " extends " + extends + " {" +
			basics +
			extras +
			"\n  }" +
			"\n"
	}
	return output
}

func JavaInterfaceFnFromFunc(fnc *vxfunc) string {
	interfaces := ""
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any resolve(Core.Type_any val);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-async":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public CompletableFuture<Core.Type_any> resolve(Core.Type_any val);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-context":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any resolve(Core.Type_any val, Core.Type_context context);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-any-context-async":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public CompletableFuture<Core.Type_any> resolve(Core.Type_any val, Core.Type_context context);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-key-value":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any resolve(Core.Type_string key, Core.Type_any val);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-func", "vx/core/any<-none":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any resolve();" +
			"\n    }" +
			"\n"
	case "vx/core/any<-reduce":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any resolve(Core.Type_any reduce, Core.Type_any item);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-reduce-next":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any resolve(Core.Type_any reduce, Core.Type_any current, Core.Type_any next);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-key-value-async":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public CompletableFuture<Core.Type_any> resolve(Core.Type_string key, Core.Type_any val);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-func-async", "vx/core/any<-none-async":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public CompletableFuture<Core.Type_any> resolve();" +
			"\n    }" +
			"\n"
	case "vx/core/any<-reduce-async":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public CompletableFuture<Core.Type_any> resolve(Core.Type_any reduce, Core.Type_any item);" +
			"\n    }" +
			"\n"
	case "vx/core/any<-reduce-next-async":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public CompletableFuture<Core.Type_any> resolve(Core.Type_any reduce, Core.Type_any current, Core.Type_any next);" +
			"\n    }" +
			"\n"
	case "vx/core/boolean<-func", "vx/core/boolean<-none":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_boolean resolve();" +
			"\n    }" +
			"\n"
	case "vx/core/none<-any":
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public Core.Type_any void resolve(Core.Type_any val);" +
			"\n    }" +
			"\n"
	}
	return interfaces
}

func JavaInterfaceFromFunc(fnc *vxfunc) string {
	funcname := JavaNameFromFunc(fnc)
	extends := ""
	interfaces := ""
	generictypes := JavaGenericDefinitionFromFunc(fnc)
	returntype := JavaNameTypeFromType(fnc.vxtype)
	var listargtext []string
	if fnc.generictype != nil {
		returntype = JavaGenericFromType(fnc.generictype)
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			listargtext = append(listargtext, "final "+returntype+" generic_any_1")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if argtype.isgeneric {
				argtypename = JavaGenericFromType(argtype)
			} else {
				argtypename = JavaNameTypeFromType(argtype)
			}
			argname := JavaFromName(arg.alias)
			isskip := false
			switch NameFromFunc(fnc) {
			case "vx/core/let", "vx/core/let-async":
				// args is not included in let
				if argname == "args" {
					isskip = true
				}
			}
			if !isskip {
				listargtext = append(listargtext, "final "+argtypename+" "+argname)
			}
		}
	} else {
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := JavaNameTypeFromType(argtype)
			argname := JavaFromName(arg.alias)
			listargtext = append(listargtext, "final "+argtypename+" "+argname)
		}
	}
	argtext := StringJoinFromListString(listargtext, ", ")
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
		extends = "Core.Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " fn_new(Core.Class_" + funcname + ".IFn fn);"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		extends = "Core.Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " fn_new(Core.Class_any_from_func.IFn fn);"
	case "vx/core/none<-any":
	default:
		if extends == "" {
			switch NameFromType(fnc.vxtype) {
			case "vx/core/none":
				extends = "Core.Type_func"
			default:
				switch len(fnc.listarg) {
				case 1:
					extends = "Core.Func_any_from_any"
					if fnc.context {
						extends += "_context"
					}
					if fnc.async {
						extends += "_async"
					}
				default:
					extends = "Core.Type_func"
				}
			}
		}
	}
	if fnc.async {
		returntype = "CompletableFuture<" + returntype + ">"
	}
	contextarg := ""
	if fnc.context {
		if argtext == "" {
			contextarg = "Core.Type_context context"
		} else {
			contextarg = ", Core.Type_context context"
		}
	}
	if extends == "Core.Type_func" {
		if fnc.async {
			extends += ", Core.Type_replfunc_async"
		} else {
			extends += ", Core.Type_replfunc"
		}
	}
	interfaces += "" +
		"\n    public " + generictypes + returntype + " f_" + funcname + "(" + argtext + contextarg + ");"
	output := "" +
		"\n  public static interface Func_" + funcname + " extends " + extends + " {" +
		interfaces +
		"\n  }" +
		"\n"
	return output
}

func JavaNameClassFullFromType(typ *vxtype) string {
	name := JavaNameFromPkgName(typ.pkgname)
	name += ".Class_"
	name += JavaNameFromType(typ)
	return name
}

func JavaNameEFromType(typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = "Core.f_empty(generic_" + JavaFromName(typ.name) + ")"
	} else {
		output = "e_" + JavaNameFromType(typ)
		if typ.pkgname != "" {
			output = JavaNameFromPkgName(typ.pkgname) + "." + output
		}
	}
	return output
}

func JavaNameFromFunc(fnc *vxfunc) string {
	return JavaFromName(fnc.alias) + JavaIndexFromFunc(fnc)
}

func JavaNameFromPkgName(pkgname string) string {
	output := ""
	ipos := IntFromStringIndexLast(pkgname, "/")
	output = StringSubstring(pkgname, ipos+1, len(pkgname))
	output = StringUCaseFirst(output)
	output = StringReplace(output, "<", "lt")
	output = StringReplace(output, ">", "gt")
	output = StringReplace(output, "?", "is")
	output = StringReplace(output, "-", "_")
	output = StringReplace(output, "/", "_")
	return output
}

func JavaNameFromType(typ *vxtype) string {
	name := ""
	if typ.alias == "" {
		name += JavaFromName(typ.name)
	} else {
		name += JavaFromName(typ.alias)
	}
	return name
}

func JavaNameTFromFunc(fnc *vxfunc) string {
	name := "t_" + JavaNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = JavaNameFromPkgName(fnc.pkgname) + "." + name
	}
	return name
}

func JavaNameTFromType(typ *vxtype) string {
	name := "t_" + JavaNameFromType(typ)
	if typ.pkgname != "" {
		name = JavaNameFromPkgName(typ.pkgname) + "." + name
	}
	return name
}

func JavaNameTFromTypeGeneric(typ *vxtype) string {
	name := ""
	if typ.isgeneric {
		name = "generic_" + JavaFromName(typ.name)
	} else {
		name = JavaNameTFromType(typ)
	}
	return name
}

func JavaNameTypeFromType(typ *vxtype) string {
	name := JavaNameTypeFullFromType(typ)
	switch name {
	case "Core.Type_none":
		name = "void"
	}
	return name
}

func JavaNameTypeFullFromType(typ *vxtype) string {
	name := JavaNameFromPkgName(typ.pkgname)
	if typ.isfunc {
		name += ".Func_"
	} else {
		name += ".Type_"
	}
	name += JavaNameFromType(typ)
	return name
}

func JavaPackagePathFromPrefixName(pkgprefix string, pkgname string) (string, string) {
	pkgpath := pkgprefix + "/" + pkgname
	ipos := IntFromStringIndexLast(pkgpath, "/")
	name := StringSubstring(pkgpath, ipos+1, len(pkgpath))
	pkgpath = StringSubstring(pkgpath, 0, ipos)
	pkgpath = StringReplace(pkgpath, "/", ".")
	pkgpath = JavaFromName(pkgpath)
	name = JavaNameFromPkgName(name)
	return pkgpath, name
}

func JavaReplFromFunc(fnc *vxfunc) string {
	output := ""
	replparams := ""
	argidx := 0
	var listargname []string
	pkgname := JavaNameFromPkgName(fnc.pkgname)
	funcname := JavaFromName(fnc.alias) + JavaIndexFromFunc(fnc)
	outputtype := ""
	outputttype := ""
	//emptytype := ""
	returnvalue := ""
	switch NameFromType(fnc.vxtype) {
	case "vx/core/none":
		outputtype = "Core.Type_any"
		outputttype = "Core.t_any"
		//emptytype = "Core.e_any"
	default:
		outputtype = JavaNameTypeFromType(fnc.vxtype)
		outputttype = JavaNameTFromType(fnc.vxtype)
		//emptytype = JavaNameEFromType(fnc.vxtype)
		returnvalue = "output = "
	}
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		default:
			if fnc.generictype != nil {
				replparam := outputtype + " generic_" + JavaFromName(fnc.generictype.name) + " = Core.f_any_from_any(" + outputttype + ", arglist.vx_any(Core.t_int.vx_new_from_int(" + StringFromInt(argidx) + ")));"
				replparams += "\n      " + replparam
				listargname = append(listargname, "generic_"+JavaFromName(fnc.generictype.name))
			}
		}
	}
	for _, arg := range fnc.listarg {
		if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
		} else {
			argname := JavaFromName(arg.alias)
			replparam := JavaNameTypeFromType(arg.vxtype) + " " + argname + " = Core.f_any_from_any(" + JavaNameTFromType(arg.vxtype) + ", arglist.vx_any(Core.t_int.vx_new_from_int(" + StringFromInt(argidx) + ")));"
			replparams += "\n      " + replparam
			listargname = append(listargname, argname)
			argidx += 1
		}
	}
	if fnc.context {
		listargname = append(listargname, "context")
		replparam := "Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(" + StringFromInt(argidx) + ")));"
		replparams += "\n      " + replparam
	}
	if fnc.async {
		output = "" +
			"\n    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {" +
			"\n      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);" +
			replparams +
			"\n      CompletableFuture<" + outputtype + "> future = " + pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      output = Core.async_from_async(Core.t_any, future);" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	} else {
		output = "" +
			"\n    public Core.Type_any vx_repl(Core.Type_anylist arglist) {" +
			"\n      Core.Type_any output = Core.e_any;" +
			replparams +
			"\n      " + returnvalue + pkgname + ".f_" + funcname + "(" + strings.Join(listargname, ", ") + ");" +
			"\n      return output;" +
			"\n    }" +
			"\n"
	}
	return output
}

func JavaStringFromProjectCmd(prj *vxproject, cmd *vxcmd) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaStringFromProjectCmd")
	files, msgs := JavaFilesFromProjectCmd(prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	text := StringFromListFile(files)
	return text, msgblock
}

func JavaTestCase(testvalues []vxvalue, testpkg string, testname string, testcasename string, fnc *vxfunc, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaTestCase")
	var output = ""
	if len(testvalues) > 0 {
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := JavaFromValue(testvalue, testpkg, fnc, "            ", true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n        com.sarvalex.vx.Test.t_testdescribe.vx_new(" +
				"\n          \":describename\", \"" + JavaTestFromValue(testvalue) + "\"," +
				"\n          \":testresult\"," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringJoinFromListString(desctexts, ",")
		output = "" +
			"\n  static com.sarvalex.vx.Test.Type_testcase " + testcasename + "(final Core.Type_context context) {" +
			"\n    com.sarvalex.vx.Test.Type_testcase output = com.sarvalex.vx.Test.t_testcase.vx_new(" +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + testpkg + "\"," +
			"\n      \":casename\", \"" + testname + "\"," +
			"\n      \":describelist\"," +
			"\n      com.sarvalex.vx.Test.t_testdescribelist.vx_new(" + describelist +
			"\n      )" +
			"\n    );" +
			"\n    return output;" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func JavaTestFromConst(cnst *vxconst) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaTestFromConst")
	testvalues := cnst.listtestvalue
	testpkg := cnst.pkgname
	testname := cnst.name
	testcasename := "c_" + JavaFromName(cnst.alias)
	path := cnst.pkgname + "/" + cnst.name
	fnc := emptyfunc
	output, msgs := JavaTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func JavaTestFromFunc(fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaTestFromFunc")
	testvalues := fnc.listtestvalue
	testpkg := fnc.pkgname
	idx := JavaIndexFromFunc(fnc)
	testname := fnc.name + idx
	funcname := JavaFromName(fnc.alias) + idx
	testcasename := "f_" + funcname
	path := fnc.pkgname + "/" + fnc.name
	output, msgs := JavaTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func JavaTestFromPackage(pkg *vxpackage, prj *vxproject, pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaTestFromPackage")
	pkgpath, pkgname := JavaPackagePathFromPrefixName(pkgprefix, pkg.name)
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
		test, msgs := JavaTestFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		covertype = append(covertype, "      \":"+typid+"\", "+StringFromInt(len(typ.testvalues)))
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(testall, pkgname+"com.sarvalex.vx.Test.t_"+JavaFromName(typ.alias)+"(context)")
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
		test, msgs := JavaTestFromConst(cnst)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		coverconst = append(coverconst, "      \":"+cnstid+"\", "+StringFromInt(len(cnst.listtestvalue)))
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(testall, pkgname+"com.sarvalex.vx.Test.c_"+JavaFromName(cnst.alias)+"(context)")
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
			test, msgs := JavaTestFromFunc(fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			coverfunc = append(coverfunc, "      \":"+fncid+JavaIndexFromFunc(fnc)+"\", "+StringFromInt(len(fnc.listtestvalue)))
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(testall, pkgname+"com.sarvalex.vx.Test.f_"+JavaFromName(fnc.alias)+JavaIndexFromFunc(fnc)+"(context)")
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
		"\n  public static com.sarvalex.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {" +
		"\n    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(" +
		"\n      " + strings.Join(testall, ",\n      ") +
		"\n    ));" +
		"\n    com.sarvalex.vx.Test.Type_testcaselist output = com.sarvalex.vx.Test.t_testcaselist.vx_new(arraylisttestcase);" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  public static com.sarvalex.vx.Test.Type_testcoveragesummary test_coveragesummary() {" +
		"\n    return com.sarvalex.vx.Test.t_testcoveragesummary.vx_new(" +
		"\n      \":testpkg\",   \"" + pkg.name + "\", " +
		"\n      \":constnums\", " + JavaTypeCoverageNumsValNew(coverconstpct, coverconstcnt, coverconsttotal) + ", " +
		"\n      \":docnums\", " + JavaTypeCoverageNumsValNew(coverdocpct, coverdoccnt, coverdoctotal) + ", " +
		"\n      \":funcnums\", " + JavaTypeCoverageNumsValNew(coverfuncpct, coverfunccnt, coverfunctotal) + ", " +
		"\n      \":ospacenums\", " + JavaTypeCoverageNumsValNew(coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + ", " +
		"\n      \":otimenums\", " + JavaTypeCoverageNumsValNew(coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + ", " +
		"\n      \":totalnums\", " + JavaTypeCoverageNumsValNew(coverpct, covercnt, covertotal) + ", " +
		"\n      \":typenums\", " + JavaTypeCoverageNumsValNew(covertypepct, covertypecnt, covertypetotal) +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  public static com.sarvalex.vx.Test.Type_testcoveragedetail test_coveragedetail() {" +
		"\n    return com.sarvalex.vx.Test.t_testcoveragedetail.vx_new(" +
		"\n      \":testpkg\", \"" + pkg.name + "\"," +
		"\n      \":typemap\", Core.t_intmap.vx_new(" +
		"\n  " + strings.Join(covertype, ",\n  ") +
		"\n      )," +
		"\n      \":constmap\", Core.t_intmap.vx_new(" +
		"\n  " + strings.Join(coverconst, ",\n  ") +
		"\n      )," +
		"\n      \":funcmap\", Core.t_intmap.vx_new(" +
		"\n  " + strings.Join(coverfunc, ",\n  ") +
		"\n      )" +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  public static com.sarvalex.vx.Test.Type_testpackage test_package(final Core.Type_context context) {" +
		"\n    com.sarvalex.vx.Test.Type_testcaselist testcaselist = test_cases(context);" +
		"\n    com.sarvalex.vx.Test.Type_testpackage output = com.sarvalex.vx.Test.t_testpackage.vx_new(" +
		"\n      \":testpkg\", \"" + pkg.name + "\", " +
		"\n      \":caselist\", testcaselist," +
		"\n      \":coveragesummary\", test_coveragesummary()," +
		"\n      \":coveragedetail\", test_coveragedetail()" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := JavaImportsFromPackage(pkg, pkgprefix, body, true)
	output := "" +
		"\npackage " + pkgpath + ";" +
		"\n" +
		imports +
		"\n" +
		"\npublic final class " + pkgname + "Test {" +
		"\n" +
		body +
		"\n}\n"
	return output, msgblock
}

func JavaTestFromType(typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JavaTestFromType")
	testvalues := typ.testvalues
	testpkg := typ.pkgname
	testname := typ.name
	testcasename := "t_" + JavaFromName(typ.alias)
	fnc := emptyfunc
	path := typ.pkgname + "/" + typ.name
	output, msgs := JavaTestCase(testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func JavaTestFromValue(value vxvalue) string {
	var output = ""
	output = JavaFromText(value.textblock.text)
	return output
}

func JavaTypeCoverageNumsValNew(pct int, tests int, total int) string {
	return "" +
		"com.sarvalex.vx.Test.t_testcoveragenums.vx_new(" +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
		")"
}

func JavaTypeDefFromType(typ *vxtype, indent string) string {
	lineindent := "\n" + indent
	allowtypes := JavaTypeListFromListType(typ.allowtypes)
	disallowtypes := JavaTypeListFromListType(typ.disallowtypes)
	allowfuncs := "Core.e_funclist"
	disallowfuncs := "Core.e_funclist"
	allowvalues := "Core.e_anylist"
	disallowvalues := "Core.e_anylist"
	properties := "Core.e_argmap"
	traits := JavaTypeListFromListType(typ.traits)
	output := "" +
		"Core.typedef_new(" +
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

func JavaTypeDefMapFromProperties(args []vxarg, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(args) > 0 {
		var props []string
		for _, arg := range args {
			key := JavaFromName(arg.alias)
			typ := JavaTypeDefFromType(arg.vxtype, indent+"  ")
			props = append(props, "Core.keyvalue_from_key_value(\":"+key+"\", "+typ+")")
		}
		output = "" +
			"Core.hashmap_from_keyvalues(" +
			lineindent + "  " + StringJoinFromListString(props, ","+lineindent+"  ") +
			lineindent + ")"
	}
	return output
}

func JavaTypeIntValNew(val int) string {
	return "Core.t_int.vx_new_from_int(" + StringFromInt(val) + ")"
}

func JavaTypeListFromListType(listtype []*vxtype) string {
	output := "Core.e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := JavaNameTFromType(typ)
			listtext = append(listtext, typetext)
		}
		output = "Core.t_typelist.vx_new(" + StringJoinFromListString(listtext, ", ") + ")"
	}
	return output
}

func JavaTypeStringValNew(val string) string {
	valstr := StringReplace(val, "\n", "\\n")
	return "Core.t_string.vx_new_from_string(\"" + valstr + "\")"
}

func WriteJavaFromProjectCmd(prj *vxproject, cmd *vxcmd) *vxmsgblock {
	msgblock := NewMsgBlock("WriteJavaFromProjectCmd")
	files, msgs := JavaFilesFromProjectCmd(prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	msgs = WriteListFile(files)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return msgblock
}

func JavaAppTest(prj *vxproject, pkgprefix string) string {
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
		testpackage := "\n    " + pkgname + "com.sarvalex.vx.Test.test_package(context)"
		listtestpackage = append(listtestpackage, testpackage)
		importline := "import " + pkgprefix + "." + StringReplace(pkgpath, "/", ".") + ".*;\n"
		if importline == "import com.sarvalex.vx.*;\n" {
		} else if BooleanFromStringContains(imports, importline) {
		} else {
			imports += importline
		}
		tests += "" +
			`  @Test
  @DisplayName("` + pkg.name + `")
  void test_` + StringReplace(pkg.name, "/", "_") + `() {
	  com.sarvalex.vx.Test.Type_testpackage testpackage = ` + pkgname + `com.sarvalex.vx.Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

`
	}
	testpackages := StringJoinFromListString(listtestpackage, ",")
	output := "" +
		`package com.sarvalex.vx;

` + imports +
		`
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for whole App.
 */
public class AppTest {

  Core.Type_context context = Core.t_context.vx_new();

` + tests +
		`
  @Test
	@DisplayName("writetestsuite")
  void test_writetestsuite() {
    com.sarvalex.vx.Test.Type_testpackagelist testpackagelist = com.sarvalex.vx.Test.t_testpackagelist.vx_new(` +
		testpackages +
		`
    );
    TestLib.write_testpackagelist_async(testpackagelist, context);
  }

}
`
	return output
}

func JavaTestLib() string {
	return "" +
		`package com.sarvalex.vx;

import java.util.*;
import java.util.concurrent.CompletableFuture;
import static org.junit.jupiter.api.Assertions.*;
import com.sarvalex.vx.data.File;
import com.sarvalex.vx.Test;
import com.sarvalex.vx.web.Html;

public class TestLib {

  public static boolean run_testcase(final Test.Type_testcase testcase) {
    String testpkg = testcase.testpkg().vx_string();
    String casename = testcase.casename().vx_string();
    Test.Type_testdescribelist testdescribelist = testcase.describelist();
    return run_testdescribelist(testpkg, casename, testdescribelist);
  }

  // Blocking
  // Only use if running a single testcase
  public static boolean run_testcase_async(final Test.Type_testcase testcase) {
    CompletableFuture<Test.Type_testcase> async_testcase = Test.f_resolve_testcase(testcase);
    Core.Type_any work = Core.sync_from_async(Test.t_testcase, async_testcase);
    Test.Type_testcase testcase_resolved = (Test.Type_testcase)work;
    return run_testcase(testcase_resolved);
  }

  public static boolean run_testcaselist(final Test.Type_testcaselist testcaselist) {
    List<Test.Type_testcase> listtestcase = testcaselist.vx_listtestcase();
    for (Test.Type_testcase testcase : listtestcase) {
      run_testcase(testcase);
    }
    return true;
  }

  public static boolean run_testdescribe(final String testpkg, final String casename, final Test.Type_testdescribe describe) {
    Core.Type_string testcode = describe.describename();
    String message = testcode.vx_string();
    Test.Type_testresult testresult = describe.testresult();
    return run_testresult(testpkg, casename, message, testresult);
  }

  // Blocking
  // Only use if running a single testdescribe
  public static boolean run_testdescribe_async(final String testpkg, final String casename, final Test.Type_testdescribe testdescribe) {
    CompletableFuture<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);
    Test.Type_testdescribe testdescribe_resolved = Core.sync_from_async(Test.t_testdescribe, async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  public static boolean run_testdescribelist(final String testpkg, final String casename, final Test.Type_testdescribelist testdescribelist) {
    boolean output = true;
    List<Test.Type_testdescribe> listtestdescribe = testdescribelist.vx_listtestdescribe();
    for (Test.Type_testdescribe testdescribe : listtestdescribe) {
      boolean testoutput = run_testdescribe(testpkg, casename, testdescribe);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  public static boolean run_testpackage(final Test.Type_testpackage testpackage) {
    Test.Type_testcaselist testcaselist = testpackage.caselist();
    return run_testcaselist(testcaselist);
  }

  public static boolean run_testpackagelist(final com.sarvalex.vx.Test.Type_testpackagelist testpackagelist) {
    boolean output = true;
    List<com.sarvalex.vx.Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (com.sarvalex.vx.Test.Type_testpackage testpackage : listtestpackage) {
      boolean testoutput = run_testpackage(testpackage);
      if (!testoutput) {
        output = false;
      }
    }
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  public static boolean run_testpackage_async(final Test.Type_testpackage testpackage) {
    CompletableFuture<Test.Type_testpackage> async_testpackage = Test.f_resolve_testpackage(testpackage);
    Test.Type_testpackage testpackage_resolved = Core.sync_from_async(Test.t_testpackage, async_testpackage);
    return run_testpackage(testpackage_resolved);
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static boolean run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = Core.sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  public static boolean run_testresult(final String testpkg, final String testname, final String message, final Test.Type_testresult testresult) {
    Core.Type_any valexpected = testresult.expected();
    Core.Type_any valactual = testresult.actual();
    boolean passfail = testresult.passfail().vx_boolean();
    String code = testresult.code().vx_string();
    String expected = Core.f_string_from_any(valexpected).vx_string();
    String actual = Core.f_string_from_any(valactual).vx_string();
    String msg = testpkg + "/" + testname + " " + message;
    if (!passfail) {
      System.out.println(msg);
      System.out.println(expected);
      System.out.println(actual);
      Core.f_log(testresult);
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
  public static boolean run_testresult_async(final String testpkg, final String testname, final String message, Test.Type_testresult testresult) {
    CompletableFuture<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);
    Test.Type_testresult testresult_resolved = Core.sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  public static boolean write_testpackagelist_async(final Test.Type_testpackagelist testpackagelist, final Core.Type_context context) {
    boolean output = false;
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = Core.sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    File.Type_file filetest = Test.f_file_test();
    Core.Type_boolean valboolean = File.f_boolean_write_from_file_any(filetest, testpackagelist_resolved, context);
    output = valboolean.vx_boolean();
    Html.Type_div divtest = Test.f_div_from_testpackagelist(testpackagelist_resolved);
    Html.Type_html htmlnode = Test.f_html_from_divtest(divtest);
    File.Type_file filenode = Test.f_file_testnode();
    valboolean = File.f_boolean_write_from_file_any(filenode, htmlnode, context);
    output = output && valboolean.vx_boolean();
    File.Type_file filehtml = Test.f_file_testhtml();
    Core.Type_string shtml = Html.f_string_from_html(htmlnode);
    valboolean = File.f_boolean_write_from_file_string(filehtml, shtml, context);
    output = output && valboolean.vx_boolean();
    return output;
  }

}
`
}
