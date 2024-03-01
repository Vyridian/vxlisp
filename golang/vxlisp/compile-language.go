package vxlisp

import (
	"strings"
)

type vxlang struct {
	name       string
	sourcename string
	sourcefile string
	headerfile string
	pkgpath    string
	pkgname    string
	pkgref     string
	indent     string
	lineend    string
	itfext     string
	classext   string
	typeref    string
}

var langcpp = NewLangCpp()
var langcsharp = NewLangCsharp()
var langjava = NewLangJava()
var langjs = NewLangJs()
var langkotlin = NewLangKotlin()
var langswift = NewLangSwift()

func NewLangCpp() *vxlang {
	output := new(vxlang)
	output.name = "cpp"
	output.sourcename = "core"
	output.sourcefile = ".cpp"
	output.headerfile = ".hpp"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "::"
	output.indent = "  "
	output.lineend = ";"
	output.typeref = "->"
	return output
}

func NewLangCsharp() *vxlang {
	output := new(vxlang)
	output.name = "csharp"
	output.sourcename = "Core"
	output.sourcefile = ".cs"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ";"
	output.typeref = "."
	return output
}

func NewLangJava() *vxlang {
	output := new(vxlang)
	output.name = "java"
	output.sourcename = "Core"
	output.sourcefile = ".java"
	output.pkgpath = "vx_core"
	output.pkgname = "Core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ";"
	output.itfext = "extends"
	output.classext = "extends"
	output.typeref = "."
	return output
}

func NewLangJs() *vxlang {
	output := new(vxlang)
	output.name = "js"
	output.sourcename = "core"
	output.sourcefile = ".js"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ""
	output.typeref = "."
	return output
}

func NewLangKotlin() *vxlang {
	output := new(vxlang)
	output.name = "kotlin"
	output.sourcename = "Core"
	output.sourcefile = ".kt"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ""
	output.classext = ":"
	output.typeref = "."
	return output
}

func NewLangSwift() *vxlang {
	output := new(vxlang)
	output.name = "swift"
	output.sourcename = "Core"
	output.sourcefile = ".swift"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.indent = "  "
	output.lineend = ""
	output.typeref = "."
	return output
}

func LangFolderCopyTestdataFromProjectPath(project *vxproject, targetpath string) *vxmsgblock {
	msgblock := NewMsgBlock("LangFileCopyTestdataFromProjectPath")
	sourcepath := PathFromProjectPath(project, "./testdata")
	if BooleanExistsFromPath(sourcepath) {
		msgs := FolderCopyFromSourceTarget(sourcepath, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	for _, subproject := range project.listproject {
		msgs := LangFolderCopyTestdataFromProjectPath(subproject, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func LangClassHeaderFromType(lang *vxlang, typ *vxtype, indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	typename := LangFromName(typ.alias)
	switch lang.name {
	case "csharp":
		output = lineindent + "class Class_" + typename + " : vx_core.Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	case "java":
		output = lineindent + "public static class Class_" + typename + " extends Core.Class_base implements Type_" + LangNameFromType(lang, typ) + " {"
	case "kotlin":
		output = lineindent + "class Class_" + typename + " : vx_core.Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	}
	return output
}

func LangConstDefsFromListConst(values []*vxconst, indent string) string {
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

func LangDebugFromFunc(lang *vxlang, fnc *vxfunc, lineindent string) (string, string) {
	debugstart := ""
	debugend := ""
	if fnc.debug {
		debugstart = lineindent + "Core.vx_log(\"" + fnc.name + "\", \"start\""
		for _, arg := range fnc.listarg {
			debugstart += ", " + LangTypeStringValNew(arg.name+"=") + ", " + LangFromName(arg.alias)
		}
		debugstart += ")" + lang.lineend
		debugend = lineindent + "Core.vx_log(\"" + fnc.name + "\", \"end\", output)" + lang.lineend
	}
	return debugstart, debugend
}

func LangDocFromFunc(fnc *vxfunc) string {
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
	doc += "@function " + LangFromName(fnc.alias)
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

func LangEmptyValueFromType(lang *vxlang, typ *vxtype) string {
	return LangEmptyValueFromTypeIndent(lang, typ, "")
}

func LangEmptyValueFromTypeIndent(lang *vxlang, typ *vxtype, indent string) string {
	output := "\"\""
	if len(indent) < 10 {
		output = typ.defaultvalue
		switch typ.extends {
		case "string":
			output = "\"" + output + "\""
		case ":list":
			output = "Core.f_type_to_list(" + LangNameFromPkgName(lang, typ.pkgname) + ".t_" + typ.name + ")"
		default:
			if len(typ.properties) > 0 {
				output = "{\n"
				for _, property := range typ.properties {
					propdefault := LangEmptyValueFromTypeIndent(lang, property.vxtype, indent+"  ")
					output += indent + "    " + LangFromName(property.name) + ": " + propdefault + ","
					if property.doc != "" {
						output += " // " + property.doc
					}
					output += "\n"
				}
				output += "" +
					indent + "    vxtype: " + LangNameFromPkgName(lang, typ.pkgname) + ".t_" + LangFromName(typ.name) +
					"\n" + indent + "  }"
			} else if output == "" || strings.HasPrefix(output, ":") {
				output = "\"" + output + "\""
			}
		}
	}
	return output
}

func LangFilesFromProjectCmd(lang *vxlang, project *vxproject, command *vxcommand) ([]*vxfile, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFilesFromProjectCmd")
	var files []*vxfile
	cmdpath := PathFromProjectCmd(project, command)
	pkgprefix := ""
	switch lang.name {
	case "csharp":
	case "java", "kotlin":
		pkgprefix = project.javadomain + "."
	}
	switch command.code {
	case ":source":
		file := NewFile()
		file.name = "App" + lang.sourcefile
		file.path = cmdpath
		file.text = LangApp(lang, project, command)
		files = append(files, file)
	case ":test":
		file := NewFile()
		file.name = "AppTest" + lang.sourcefile
		file.path = cmdpath
		file.text = LangAppTest(lang, project, command, pkgprefix)
		files = append(files, file)
		file = NewFile()
		file.name = "TestLib" + lang.sourcefile
		file.path = cmdpath
		file.text = LangTestLib(lang)
		files = append(files, file)
	}
	pkgs := ListPackageFromProject(project)
	for _, pkg := range pkgs {
		subproject := pkg.project
		subprefix := ""
		switch lang.name {
		case "csharp":
		case "java", "kotlin":
			subprefix = subproject.javadomain + "/"
		}
		subdomainpath := StringFromStringFindReplace(subprefix, ".", "/")
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		pkgname = StringUCaseFirst(pkgname)
		switch command.code {
		case ":source":
			text, msgs := LangFromPackage(lang, pkg, project, subprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + lang.sourcefile
			file.path = cmdpath + "/" + subdomainpath + pkgpath
			file.text = text
			files = append(files, file)
		case ":test":
			text, msgs := LangTestFromPackage(lang, pkg, project, command, subprefix)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + "Test" + lang.sourcefile
			file.path = cmdpath + "/" + subdomainpath + pkgpath
			file.text = text
			files = append(files, file)
		}
	}
	return files, msgblock
}

func LangFromConst(lang *vxlang, cnst *vxconst, pkg *vxpackage) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromConst")
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
	cnstname := LangFromName(cnst.alias)
	cnstclassname := "Const_" + cnstname
	cnsttypeclassname := LangNameTypeFullFromType(lang, cnsttype)
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
		if BooleanFromStringStartsEnds(cnstval, "\"", "\"") {
			cnstval = cnstval[1 : len(cnstval)-1]
			cnstval = LangFromText(cnstval)
			cnstval = "\"" + cnstval + "\""
		}
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
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				listtypename := LangNameFromType(lang, allowtype)
				if listtypename == "any" {
					listtypename = ""
				}
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output.vx_p_list = val.vx_list" + listtypename + "();"
			}
		case ":map":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				maptypename := LangNameFromType(lang, allowtype)
				if maptypename == "any" {
					maptypename = ""
				}
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";" +
					"\n      output.vx_p_map = val.vx_map" + maptypename + "();"
			}
		case ":struct":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					"\n      " + cnsttypeclassname + " val = " + clstext + ";"
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						"\n      output.vx_p_" + LangFromName(prop.name) + " = val." + LangFromName(prop.name) + "();"

				}
			}
		}
	}
	extends := LangNameClassFullFromType(lang, cnsttype)
	output += "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  public static class " + cnstclassname + " " + lang.classext + " " + extends + " implements Core.vx_Type_const {" +
		"\n" +
		"\n    @Override" +
		"\n    public Core.Type_constdef vx_constdef() {" +
		"\n      return Core.constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + LangTypeDefFromType(lang, cnsttype, "        ") +
		"\n      );" +
		"\n    }" +
		"\n" +
		"\n    public static void const_new(" + cnstclassname + " output) {" +
		const_new +
		"\n    }" +
		"\n" +
		initval +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  public static final " + cnstclassname + " c_" + cnstname + " = new " + cnstclassname + "();" +
		"\n" +
		"\n"
	constlate := "" +
		"\n    " + cnstclassname + ".const_new(c_" + cnstname + ");"
	return output, constlate, msgblock
}

func LangFromFunc(lang *vxlang, fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromFunc")
	var listargtype []string
	var listargname []string
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
	returntype := ""
	if fnc.generictype == nil {
		returntype = LangGenericFromType(lang, fnc.vxtype)
	} else {
		returntype = LangGenericFromType(lang, fnc.generictype)
	}
	pkgname := LangNameFromPkgName(lang, fnc.pkgname)
	instancevars := ""
	staticvars := ""
	instancefuncs := ""
	staticfuncs := ""
	f_suppresswarnings := ""
	path := fnc.pkgname + "/" + fnc.name + LangIndexFromFunc(fnc)
	genericdefinition := LangGenericDefinitionFromFunc(lang, fnc)
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		case "vx/core/any<-any", "vx/core/any<-any-async",
			"vx/core/any<-any-context", "vx/core/any<-any-context-async",
			"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
			"vx/core/any<-int",
			"vx/core/any<-func", "vx/core/any<-func-async",
			"vx/core/any<-key-value", "vx/core/any<-key-value-async",
			"vx/core/any<-none", "vx/core/any<-none-async",
			"vx/core/any<-reduce", "vx/core/any<-reduce-async",
			"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
			argtext := "final T generic_any_1"
			listargtype = append(listargtype, argtext)
		default:
			if fnc.generictype != nil {
				genericargname := LangNameTFromTypeGeneric(lang, fnc.generictype)
				argtext := "final " + LangGenericFromType(lang, fnc.generictype) + " " + genericargname
				listargtype = append(listargtype, argtext)
				listargname = append(listargname, genericargname)
			}
		}
	}
	if fnc.context {
		listargtype = append(listargtype, "final Core.Type_context context")
		listargname = append(listargname, "context")
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
				argtypename = LangGenericFromType(lang, argtype)
			} else {
				argtypename = LangNameTypeFromTypeSimple(lang, argtype, true)
			}
			argtext := "final " + argtypename + " " + LangFromName(arg.alias)
			listargname = append(listargname, LangFromName(arg.alias))
			if arg.multi {
				listargtype = append(listargtype, argtext)
			} else {
				listargtype = append(listargtype, argtext)
			}
		}
	}
	//var funcgenerics []string
	functypetext := ""
	if fnc.generictype != nil {
		functypetext = LangGenericFromType(lang, fnc.generictype)
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
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
		"vx/core/any<-int",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async",
		"vx/core/boolean<-any":
		instancevars += "" +
			"\n    public IFn fn = null;" +
			"\n" +
			"\n    @Override" +
			"\n    public Func_" + funcname + " vx_fn_new(Core.Class_" + funcname + ".IFn fn) {" +
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
			"\n    public Func_" + funcname + " vx_fn_new(Core.Class_any_from_func.IFn fn) {" +
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
				argtypename = LangNameTypeFromTypeSimple(lang, arg.vxtype, true)
				subargnames := "inputval"
				contextname := ""
				if fnc.context {
					contextname = "_context"
					subargnames = "context, inputval"
				}
				switch NameFromFunc(fnc) {
				case "vx/core/empty":
				default:
					if fnc.generictype != nil {
						subargnames = LangNameTFromTypeSimple(lang, fnc.vxtype, true) + ", " + subargnames
					}
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
							"\n      " + LangNameTypeFromType(lang, arg.vxtype) + " inputval = Core.f_any_from_any(" + LangNameTFromType(lang, arg.vxtype) + ", value);" +
							"\n      CompletableFuture<" + returntype + "> future = " + pkgname + ".f_" + funcname + "(" + subargnames + ");" +
							"\n      @SuppressWarnings(\"unchecked\")" +
							"\n      CompletableFuture<T> output = (CompletableFuture<T>)future;"
					}
					instancefuncs += "" +
						"\n    @Override" +
						"\n    public Core.Func_any_from_any" + contextname + "_async vx_fn_new(Core.Class_any_from_any" + contextname + "_async.IFn fn) {return Core.e_any_from_any" + contextname + "_async;}" +
						"\n" +
						"\n    @Override" +
						"\n    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any" + contextname + "_async(final T generic_any_1" + contextarg + ", final U value) {" +
						asyncbody +
						"\n      return output;" +
						"\n    }" +
						"\n"
				} else {
					instancefuncs += "" +
						"\n    @Override" +
						"\n    public Core.Func_any_from_any" + contextname + " vx_fn_new(Core.Class_any_from_any" + contextname + ".IFn fn) {return Core.e_any_from_any" + contextname + ";}" +
						"\n" +
						"\n    @Override" +
						"\n    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any" + contextname + "(final T generic_any_1" + contextarg + ", final U value) {" +
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
	repltext := LangReplFromFunc(lang, fnc)
	instancefuncs += repltext
	valuetext, msgs := LangFromValue(lang, fnc.value, fnc.pkgname, fnc, 0, true, false, path)
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
	subindent := indent
	lineindent := "\n" + indent
	msgtop := ""
	msgbottom := ""
	permissiontop := ""
	permissionbottom := ""
	if fnc.permission {
		permissiontop = lineindent + "if (Core.f_boolean_permission_from_func(context, " + LangNameTFromFunc(lang, fnc) + ").vx_boolean()) {"
		permissionbottom = "" +
			lineindent + "} else {" +
			LangVar(lang, "msg", msgtype, "Core.vx_msg_from_error(\"vx/core/func\", \":permissiondenied\", Core.vx_new_string(\""+fnc.name+"\"))", 3, true, false) +
			lineindent + "  output = output.vx_copy(msg);" +
			lineindent + "}"
		subindent += "  "
	}
	linesubindent := "\n" + subindent
	if fnc.messages {
		msgtop = linesubindent + "try {"
		msgbottom = "" +
			linesubindent + "} catch (Exception err) {" +
			linesubindent + "  Core.Type_msg msg = Core.vx_msg_from_exception(\"" + fnc.pkgname + "/" + fnc.name + "\", err);" +
			linesubindent + "  output = output.vx_copy(msg);" +
			linesubindent + "}"
		subindent += "  "
	}
	linesubindent = "\n" + subindent
	valuetext = StringFromListStringJoin(chgvaluetexts, "\n")
	if IntFromStringFind(valuetext, "output ") >= 0 {
	} else if IntFromStringFind(valuetext, "output.") >= 0 {
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
		valuetext = linesubindent + StringFromStringIndent(valuetext, subindent)
	}
	interfacefn := LangInterfaceFnFromFunc(lang, fnc)
	debugtop, debugbottom := LangDebugFromFunc(lang, fnc, lineindent)
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
		} else if BooleanFromStringStarts(fnc.name, "int<-") {
			returnvalue += "" +
				"\n      Core.Type_int output = Core.e_int;" +
				"\n      if (fn != null) {" +
				"\n        output = Core.f_any_from_any(Core.t_int, fn.resolve(" + strings.Join(listargname, ", ") + "));" +
				"\n      }"
		} else if BooleanFromStringStarts(fnc.name, "string<-") {
			returnvalue += "" +
				"\n      Core.Type_string output = Core.e_string;" +
				"\n      if (fn != null) {" +
				"\n        output = Core.f_any_from_any(Core.t_string, fn.resolve(" + strings.Join(listargname, ", ") + "));" +
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
		} else if fnc.async {
			defaultvalue = lineindent + "CompletableFuture<" + returntype + "> output = Core.async_new_completed(" + LangNameEFromType(lang, fnc.vxtype) + ");"
		} else if fnc.generictype != nil {
			defaultvalue = lineindent + returntype + " output = Core.f_empty(" + LangNameTFromTypeGeneric(lang, fnc.generictype) + ");"
		} else {
			defaultvalue = lineindent + returntype + " output = " + LangNameEFromType(lang, fnc.vxtype) + ";"
		}
	}
	interfacefunc := LangInterfaceFromFunc(lang, fnc)
	doc := LangDocFromFunc(fnc)
	output := "" +
		doc +
		interfacefunc +
		"\n  public static class Class_" + funcname + " " + lang.classext + " Core.Class_base implements Func_" + funcname + " {" +
		"\n" +
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
		"\n        " + LangTypeDefFromType(lang, fnc.vxtype, "        ") + " // typedef" +
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
		"\n    public " + genericdefinition + functypetext + " vx_" + funcname + "(" + strings.Join(listargtype, ", ") + ") {" +
		staticfuncs +
		returnvalue +
		"\n    }" +
		"\n" +
		"\n  }" +
		"\n" +
		"\n  public static final Func_" + funcname + " e_" + funcname + " = new " + LangNameFromPkgName(lang, fnc.pkgname) + ".Class_" + funcname + "();" +
		"\n  public static final Func_" + funcname + " t_" + funcname + " = new " + LangNameFromPkgName(lang, fnc.pkgname) + ".Class_" + funcname + "();" +
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

func LangFromName(name string) string {
	output := name
	if output == "extends" {
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

func LangFromPackage(lang *vxlang, pkg *vxpackage, project *vxproject, pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromPackage")
	pkgpath, pkgname := LangPackagePathFromPrefixName(lang, pkgprefix, pkg.name)
	specialcode := project.mapnative[pkg.name+"_"+lang.name+".txt"]
	typkeys := ListKeyFromMapType(pkg.maptype)
	typetexts := ""
	packageline := "package " + pkgpath + lang.lineend + "\n"
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname)
	packagestatic := "" +
		"\n    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();" +
		"\n    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();" +
		"\n    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();"
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typetext, msgs := LangFromType(typ, lang)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		typetexts += typetext
		packagestatic += "" +
			"\n    maptype.put(\"" + typ.name + "\", " + LangNameTFromType(lang, typ) + ");"
	}
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	consttexts := ""
	statics := "\n  static {"
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, constlate, msgs := LangFromConst(lang, cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		consttexts += consttext
		statics += constlate
		packagestatic += "" +
			"\n    mapconst.put(\"" + cnst.name + "\", " + LangNameCFromConst(lang, cnst) + ");"
	}
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	functexts := ""
	for _, fncid := range fnckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fnctext, msgs := LangFromFunc(lang, fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			functexts += fnctext
			packagestatic += "" +
				"\n    mapfunc.put(\"" + fnc.name + LangIndexFromFunc(fnc) + "\", " + LangNameTFromFunc(lang, fnc) + ");"
		}
	}
	packagestatic += "" +
		"\n    Core.vx_global_package_set(\"" + pkg.name + "\", maptype, mapconst, mapfunc);"
	statics += "" +
		packagestatic +
		"\n  }" +
		"\n"
	body := "" +
		specialcode +
		typetexts +
		consttexts +
		functexts +
		statics
		//		emptytypes
	imports := LangImportsFromPackage(lang, pkg, pkgprefix, body, false)
	output := "" +
		packageline +
		imports +
		namespaceopen +
		body +
		namespaceclose
	return output, msgblock
}

func LangFromText(text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	return output
}

func LangFromType(typ *vxtype, lang *vxlang) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromType")
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
	typename := LangFromName(typ.alias)
	typepath := NameFromType(typ)
	instancefuncs := ""
	createtext, msgs := LangFromValue(lang, typ.createvalue, "", emptyfunc, 2, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if createtext != "" {
		instancefuncs += "\n    " + createtext + "\n"
	}
	staticfuncs := ""
	valnew := ""
	extendinterface := ""
	valcopy := "" +
		"\n      boolean ischanged = false;" +
		"\n      Class_" + typename + " val = this;" +
		"\n      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);" +
		"\n      if (this instanceof Core.vx_Type_const) {" +
		"\n        ischanged = true;" +
		"\n      }"
	switch NameFromType(typ) {
	case "vx/core/any":
		valnew += "" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_any work = new Class_any();" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
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
		valcopy += "" +
			"\n      boolean booleanval = val.vx_boolean();"
		valnew = "" +
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
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_boolean work = new Class_boolean();" +
			"\n        work.vxboolean = booleanval;" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      } else if (booleanval) {" +
			"\n        output = Core.c_true;" +
			"\n      } else {" +
			"\n        output = Core.c_false;" +
			"\n      }"
	case "vx/core/decimal":
		extendinterface = "Core.Type_number"
		valcopy += "" +
			"\n      String sval = val.vx_string();"
		valnew = "" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_string) {" +
			"\n          Core.Type_string valstring = (Core.Type_string)valsub;" +
			"\n          ischanged = true;" +
			"\n          sval = valstring.vx_string();" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          ischanged = true;" +
			"\n          sval = (String)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_decimal work = new Class_decimal();" +
			"\n        work.vxdecimal = sval;" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/float":
		extendinterface = "Core.Type_number"
		valcopy += "" +
			"\n      float floatval = val.vx_float();"
		valnew = "" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_decimal) {" +
			"\n          Core.Type_decimal valnum = (Core.Type_decimal)valsub;" +
			"\n          ischanged = true;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (valsub instanceof Core.Type_float) {" +
			"\n          Core.Type_float valnum = (Core.Type_float)valsub;" +
			"\n          ischanged = true;" +
			"\n          floatval += valnum.vx_float();" +
			"\n        } else if (valsub instanceof Core.Type_int) {" +
			"\n          Core.Type_int valnum = (Core.Type_int)valsub;" +
			"\n          ischanged = true;" +
			"\n          floatval += valnum.vx_int();" +
			"\n        } else if (valsub instanceof Core.Type_string) {" +
			"\n          Core.Type_string valstring = (Core.Type_string)valsub;" +
			"\n          ischanged = true;" +
			"\n          floatval += Float.parseFloat(valstring.vx_string());" +
			"\n        } else if (valsub instanceof Float) {" +
			"\n          ischanged = true;" +
			"\n          floatval += (Float)valsub;" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          ischanged = true;" +
			"\n          floatval += (Integer)valsub;" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          ischanged = true;" +
			"\n          floatval += Float.parseFloat((String)valsub);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_float work = new Class_float();" +
			"\n        work.vxfloat = floatval;" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/int":
		extendinterface = "Core.Type_number"
		valcopy += "" +
			"\n      int intval = val.vx_int();"
		valnew = "" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_int) {" +
			"\n          ischanged = true;" +
			"\n          Core.Type_int valnum = (Core.Type_int)valsub;" +
			"\n          intval += valnum.vx_int();" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          ischanged = true;" +
			"\n          intval += (Integer)valsub;" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_int work = new Class_int();" +
			"\n        work.vxint = intval;" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
			"\n      }"
	case "vx/core/msg":
	case "vx/core/msgblock":
	case "vx/core/string":
		valcopy += "" +
			"\n      StringBuilder sb = new StringBuilder(val.vx_string());"
		valnew = "" +
			"\n      Core.Type_msg msg;" +
			"\n      for (Object valsub : vals) {" +
			"\n        if (valsub instanceof Core.Type_msgblock) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_msg) {" +
			"\n          msgblock = msgblock.vx_copy(valsub);" +
			"\n        } else if (valsub instanceof Core.Type_string) {" +
			"\n          Core.Type_string valstring = (Core.Type_string)valsub;" +
			"\n          String ssub = valstring.vx_string();" +
			"\n          if (!ssub.equals(\"\")) {" +
			"\n            ischanged = true;" +
			"\n            sb.append(ssub);" +
			"\n          }" +
			"\n        } else if (valsub instanceof Core.Type_int) {" +
			"\n          Core.Type_int valint = (Core.Type_int)valsub;" +
			"\n          ischanged = true;" +
			"\n          sb.append(valint.vx_int());" +
			"\n        } else if (valsub instanceof Core.Type_float) {" +
			"\n          Core.Type_float valfloat = (Core.Type_float)valsub;" +
			"\n          ischanged = true;" +
			"\n          sb.append(valfloat.vx_float());" +
			"\n        } else if (valsub instanceof Core.Type_decimal) {" +
			"\n          Core.Type_decimal valdecimal = (Core.Type_decimal)valsub;" +
			"\n          ischanged = true;" +
			"\n          sb.append(valdecimal.vx_string());" +
			"\n        } else if (valsub instanceof String) {" +
			"\n          String ssub2 = (String)valsub;" +
			"\n          if (!ssub2.equals(\"\")) {" +
			"\n            ischanged = true;" +
			"\n            sb.append(ssub2);" +
			"\n          }" +
			"\n        } else if (valsub instanceof Integer) {" +
			"\n          ischanged = true;" +
			"\n          sb.append((Integer)valsub);" +
			"\n        } else if (valsub instanceof Float) {" +
			"\n          ischanged = true;" +
			"\n          sb.append((Float)valsub);" +
			"\n        } else if (valsub instanceof Core.Type_any) {" +
			"\n          Core.Type_any anysub = (Core.Type_any)valsub;" +
			"\n          msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", anysub);" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        } else {" +
			"\n          msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", Core.vx_new_string(valsub.toString()));" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        String vxstring = sb.toString();" +
			"\n        Class_string work = new Class_string();" +
			"\n        work.vxstring = vxstring;" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
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
			allowclass = LangNameTypeFullFromType(lang, allowtype)
			allowempty := LangNameEFromType(lang, allowtype)
			allowname = LangNameFromType(lang, allowtype)
			allowcode = "" +
				"\n    @Override" +
				"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_int index) {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      Class_" + typename + " list = this;" +
				"\n      int iindex = index.vx_int();" +
				"\n      List<" + allowclass + "> listval = list.vx_p_list;" +
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
				"\n    public List<" + allowclass + "> vx_list" + allowname + "() {return vx_p_list;}" +
				"\n" +
				"\n    @Override" +
				"\n    public Core.Type_any vx_any(final Core.Type_int index) {" +
				"\n      return this.vx_" + allowname + "(index);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    protected List<" + allowclass + "> vx_p_list = Core.immutablelist(new ArrayList<" + allowclass + ">());" +
			"\n" +
			"\n    @Override" +
			"\n    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}" +
			"\n" +
			allowcode
		valcopy += "" +
			"\n      List<" + allowclass + "> listval = new ArrayList<>(val.vx_list" + allowname + "());"
		switch typ.name {
		case "msgblocklist":
			valnew = "" +
				"\n      Core.Type_msg msg;" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof Core.Type_msg) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);"
		case "msglist":
			valnew = "" +
				"\n      Core.Type_msg msg;" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof Core.Type_msgblock) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);"
		default:
			valnew = "" +
				"\n      Core.Type_msg msg;" +
				"\n      for (Object valsub : vals) {" +
				"\n        if (valsub instanceof Core.Type_msgblock) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);" +
				"\n        } else if (valsub instanceof Core.Type_msg) {" +
				"\n          msgblock = msgblock.vx_copy(valsub);" +
				"\n        } else if (valsub instanceof " + allowclass + ") {" +
				"\n          ischanged = true;" +
				"\n          listval.add((" + allowclass + ")valsub);"
		}
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := LangNameTypeFromType(lang, allowedtype)
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
					"\n          ischanged = true;" +
					"\n          listval.add(" + castval + ");"
			}
		}
		valnew += "" +
			"\n        } else if (valsub instanceof Type_" + typename + ") {" +
			"\n          Type_" + typename + " multi = (Type_" + typename + ")valsub;" +
			"\n          ischanged = true;" +
			"\n          listval.addAll(multi.vx_list" + allowname + "());" +
			"\n        } else if (valsub instanceof List) {" +
			"\n          List<?> listunknown = (List<?>)valsub;" +
			"\n          for (Object item : listunknown) {" +
			"\n            if (item instanceof " + allowclass + ") {" +
			"\n              " + allowclass + " valitem = (" + allowclass + ")item;" +
			"\n              ischanged = true;" +
			"\n              listval.add(valitem);" +
			"\n            }" +
			"\n          }" +
			"\n        } else if (valsub instanceof Core.Type_any) {" +
			"\n          Core.Type_any anysub = (Core.Type_any)valsub;" +
			"\n          msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", anysub);" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        } else {" +
			"\n          msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidtype\", Core.vx_new_string(valsub.toString()));" +
			"\n          msgblock = msgblock.vx_copy(msg);" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_" + typename + " work = new Class_" + typename + "();" +
			"\n        work.vx_p_list = Core.immutablelist(listval);" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
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
			allowclass = LangNameTypeFullFromType(lang, allowtype)
			allowempty := LangNameEFromType(lang, allowtype)
			allowname = LangNameFromType(lang, allowtype)
			allowcode = "" +
				"\n    @Override" +
				"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_string key) {" +
				"\n      " + allowclass + " output = " + allowempty + ";" +
				"\n      Class_" + typename + " map = this;" +
				"\n      String skey = key.vx_string();" +
				"\n      Map<String, " + allowclass + "> mapval = map.vx_p_map;" +
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
				"\n    public Map<String, " + allowclass + "> vx_map" + allowname + "() {return vx_p_map;}" +
				"\n" +
				"\n    @Override" +
				"\n    public Core.Type_any vx_any(final Core.Type_string key) {" +
				"\n      return this.vx_" + allowname + "(key);" +
				"\n    }" +
				"\n"
		}
		instancefuncs += "" +
			"\n    protected Map<String, " + allowclass + "> vx_p_map = Core.immutablemap(new LinkedHashMap<String, " + allowclass + ">());" +
			"\n" +
			"\n    @Override" +
			"\n    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}" +
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
			"\n          Core.Type_msg msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidvalue\", val);" +
			"\n          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);" +
			"\n        }" +
			"\n      }" +
			"\n      output.vx_p_map = Core.immutablemap(map);" +
			"\n      if (msgblock != Core.e_msgblock) {" +
			"\n        output.vxmsgblock = msgblock;" +
			"\n      }" +
			"\n      return output;" +
			"\n    }" +
			"\n"
		valcopy += "" +
			"\n      Map<String, " + allowclass + "> mapval = new LinkedHashMap<>(val.vx_map" + allowname + "());"
		valnew = "" +
			"\n      Core.Type_msg msg;" +
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
			"\n            Core.Type_any msgval;" +
			"\n            if (valsub instanceof Core.Type_any) {" +
			"\n              msgval = (Core.Type_any)valsub;" +
			"\n            } else {" +
			"\n              msgval = Core.vx_new_string(valsub.toString());" +
			"\n            }" +
			"\n            msg = Core.vx_msg_from_error(\"" + typepath + "\", \":keyexpected\", msgval);" +
			"\n            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n        } else {" +
			"\n          " + allowclass + " valany = null;" +
			"\n          if (valsub instanceof " + allowclass + ") {" +
			"\n            valany = (" + allowclass + ")valsub;"
		for _, allowedtype := range typ.allowtypes {
			allowedtypename := LangNameTypeFromType(lang, allowedtype)
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
			"\n            Core.Type_any msgval;" +
			"\n            if (valsub instanceof Core.Type_any) {" +
			"\n              msgval = (Core.Type_any)valsub;" +
			"\n            } else {" +
			"\n              msgval = Core.vx_new_string(valsub.toString());" +
			"\n            }" +
			"\n            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();" +
			"\n            mapany.put(\"key\", Core.vx_new_string(key));" +
			"\n            mapany.put(\"value\", msgval);" +
			"\n            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);" +
			"\n            msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidkeyvalue\", msgmap);" +
			"\n            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);" +
			"\n          }" +
			"\n          if (valany != null) {" +
			"\n            ischanged = true;" +
			"\n            if (key.startsWith(\":\")) {" +
			"\n              key = key.substring(1);" +
			"\n            }" +
			"\n            mapval.put(key, valany);" +
			"\n            key = \"\";" +
			"\n          }" +
			"\n        }" +
			"\n      }" +
			"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
			"\n        Class_" + typename + " work = new Class_" + typename + "();" +
			"\n        work.vx_p_map = Core.immutablemap(mapval);" +
			"\n        if (msgblock != Core.e_msgblock) {" +
			"\n          work.vxmsgblock = msgblock;" +
			"\n        }" +
			"\n        output = work;" +
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
		valcopyend := ""
		switch NameFromType(typ) {
		case "vx/core/msg":
			valcopy = "" +
				"\n      boolean ischanged = false;" +
				"\n      Class_" + typename + " val = this;" +
				"\n      if (this instanceof Core.vx_Type_const) {" +
				"\n        ischanged = true;" +
				"\n      }"
		case "vx/core/msgblock":
			valcopy = "" +
				"\n      boolean ischanged = false;" +
				"\n      Class_" + typename + " val = this;" +
				"\n      Core.Type_msgblock msgblock = this;" +
				"\n      if (this instanceof Core.vx_Type_const) {" +
				"\n        ischanged = true;" +
				"\n      }"
		}
		if extendinterface == "" {
			extendinterface = "Core.Type_struct"
		}
		props := ListPropertyTraitFromType(typ)
		switch len(props) {
		case 0:
			valnew = "" +
				"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
				"\n        Class_" + typename + " work = new Class_" + typename + "();" +
				"\n        if (msgblock != Core.e_msgblock) {" +
				"\n          work.vxmsgblock = msgblock;" +
				"\n        }" +
				"\n        output = work;" +
				"\n      }"
		default:
			validkeys := "\n      ArrayList<String> validkeys = new ArrayList<>();"
			valnewswitch := ""
			for _, arg := range props {
				validkeys += "\n      validkeys.add(\":" + arg.name + "\");"
				argname := LangFromName(arg.name)
				valcopy += "\n      " + LangNameTypeFromType(lang, arg.vxtype) + " vx_p_" + argname + " = val." + argname + "();"
				valcopyend += "\n        work.vx_p_" + argname + " = vx_p_" + argname + ";"
				vx_map += "\n      output.put(\":" + arg.name + "\", this." + argname + "());"
				vx_any += "" +
					"\n      case \":" + arg.name + "\":" +
					"\n        output = this." + argname + "();" +
					"\n        break;"
				argclassname := LangNameTypeFromType(lang, arg.vxtype)
				argalt := ""
				switch NameFromType(arg.vxtype) {
				case "vx/core/boolean":
					argalt = "" +
						"\n            } else if (valsub instanceof Boolean) {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = Core.t_boolean.vx_new(valsub);"
				case "vx/core/int":
					argalt = "" +
						"\n            } else if (valsub instanceof Integer) {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = Core.t_int.vx_new(valsub);"
				case "vx/core/float":
					argalt = "" +
						"\n            } else if (valsub instanceof Float) {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = Core.t_float.vx_new(valsub);"
				case "vx/core/string":
					argalt = "" +
						"\n            } else if (valsub instanceof String) {" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + argname + " = Core.t_string.vx_new(valsub);"
				}
				valnewswitcherr := ""
				switch NameFromType(typ) {
				case "vx/core/msg":
				default:
					valnewswitcherr = "" +
						"\n            } else {" +
						"\n              Core.Type_any msgval;" +
						"\n              if (valsub instanceof Core.Type_any) {" +
						"\n                msgval = (Core.Type_any)valsub;" +
						"\n              } else {" +
						"\n                msgval = Core.vx_new_string(valsub.toString());" +
						"\n              }" +
						"\n              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();" +
						"\n              mapany.put(\"key\", Core.vx_new_string(\"" + arg.name + "\"));" +
						"\n              mapany.put(\"value\", msgval);" +
						"\n              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);" +
						"\n              msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidvalue\", msgmap);" +
						"\n              msgblock = msgblock.vx_copy(msg);"
				}
				valnewswitch += "" +
					"\n          case \":" + arg.name + "\":" +
					"\n            if (valsub == vx_p_" + argname + ") {" +
					"\n            } else if (valsub instanceof " + argclassname + ") {" +
					"\n              ischanged = true;" +
					"\n              vx_p_" + argname + " = (" + argclassname + ")valsub;" +
					argalt +
					valnewswitcherr +
					"\n            }" +
					"\n            break;"
				instancefuncs += "" +
					"\n    protected " + argclassname + " vx_p_" + argname + ";" +
					"\n" +
					"\n    @Override" +
					"\n    public " + argclassname + " " + argname + "() {" +
					"\n      return this.vx_p_" + argname + " == null ? " + LangNameEFromType(lang, arg.vxtype) + " : this.vx_p_" + argname + ";" +
					//"\n      Core.Type_any valsub = this.vx_map().getOrDefault(\":" + arg.name + "\", " + LangNameEFromType(arg.vxtype) + ");" +
					//"\n      return Core.f_any_from_any(" + LangNameTFromType(arg.vxtype) + ", valsub);" +
					"\n    }" +
					"\n"
			}
			defaultkey := ""
			defaultstring := ""
			lastarg := props[len(props)-1]
			if lastarg.isdefault {
				lastargname := LangFromName(lastarg.name)
				argclassname := LangNameTypeFromType(lang, lastarg.vxtype)
				defaultkey += "" +
					"\n          } else if (valsub instanceof " + argclassname + ") { // default property" +
					"\n            ischanged = true;" +
					"\n            vx_p_" + lastargname + " = (" + argclassname + ")valsub;"
				switch NameFromType(lastarg.vxtype) {
				case "vx/core/boolean":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Boolean) { // default property" +
						"\n            ischanged = true;" +
						"\n            vx_p_" + lastargname + " = Core.t_boolean.vx_new(valsub);"
				case "vx/core/int":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Integer) { // default property" +
						"\n            ischanged = true;" +
						"\n            vx_p_" + lastargname + " = Core.t_int.vx_new(valsub);"
				case "vx/core/float":
					defaultkey += "" +
						"\n          } else if (valsub instanceof Float) { // default property" +
						"\n            ischanged = true;" +
						"\n            vx_p_" + lastargname + " = Core.t_float.vx_new(valsub);"
				case "vx/core/string":
					defaultstring += "" +
						"\n            } else if (valsub instanceof Core.Type_string) { // default property" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + lastargname + " = (Core.Type_string)valsub;" +
						"\n            } else if (valsub instanceof String) { // default property" +
						"\n              ischanged = true;" +
						"\n              vx_p_" + lastargname + " = Core.t_string.vx_new(valsub);"
				}
				if lastarg.vxtype.extends == ":list" {
					for _, allowtype := range lastarg.vxtype.allowtypes {
						subargclassname := LangNameTypeFromType(lang, allowtype)
						defaultkey += "" +
							"\n          } else if (valsub instanceof " + subargclassname + ") { // default property" +
							"\n            " + subargclassname + " valdefault = (" + subargclassname + ")valsub;" +
							"\n            " + argclassname + " vallist = vx_p_" + lastargname + ";" +
							"\n            if (vallist == null) {" +
							"\n              vallist = " + LangNameTFromType(lang, lastarg.vxtype) + ".vx_new(valdefault);" +
							"\n            } else {" +
							"\n              vallist = vallist.vx_copy(valdefault);" +
							"\n            }" +
							"\n            ischanged = true;" +
							"\n            vx_p_" + lastargname + " = vallist;"
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
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged) {" +
					"\n        Class_" + typename + " work = new Class_" + typename + "();" +
					valcopyend +
					"\n        output = work;" +
					"\n      }"
			case "vx/core/msgblock":
				valnew = "" +
					"\n      String key = \"\";" +
					"\n      Core.Type_msg msg;" +
					"\n      for (Object valsub : vals) {" +
					"\n        if (valsub instanceof Core.Type_msgblock) {" +
					"\n          if (valsub != Core.e_msgblock) {" +
					"\n            vx_p_msgblocks = vx_p_msgblocks.vx_copy(valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (valsub instanceof Core.Type_msgblocklist) {" +
					"\n          if (valsub != Core.e_msgblocklist) {" +
					"\n            vx_p_msgblocks = vx_p_msgblocks.vx_copy(valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (valsub instanceof Core.Type_msg) {" +
					"\n          if (valsub != Core.e_msg) {" +
					"\n            vx_p_msgs = vx_p_msgs.vx_copy(valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (valsub instanceof Core.Type_msglist) {" +
					"\n          if (valsub != Core.e_msglist) {" +
					"\n            vx_p_msgs = vx_p_msgs.vx_copy(valsub);" +
					"\n            ischanged = true;" +
					"\n          }" +
					"\n        } else if (key == \"\") {" +
					"\n          if (valsub instanceof Core.Type_string) {" +
					"\n            Core.Type_string valstr = (Core.Type_string)valsub;" +
					"\n            key = valstr.vx_string();" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            key = (String)valsub;" +
					"\n          } else {" +
					"\n            //Core.Type_any msgval;" +
					"\n            //if (valsub instanceof Core.Type_any) {" +
					"\n            //  msgval = (Core.Type_any)valsub;" +
					"\n            //} else {" +
					"\n            //  msgval = Core.vx_new_string(valsub.toString());" +
					"\n            //}" +
					"\n            //msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidkeytype\", msgval);" +
					"\n            //msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged) {" +
					"\n        if ((vx_p_msgs.vx_list().size() == 0) && (vx_p_msgblocks.vx_list().size() == 1)) {" +
					"\n          output = vx_p_msgblocks.vx_listmsgblock().get(0);" +
					"\n        } else {" +
					"\n          Class_" + typename + " work = new Class_" + typename + "();" +
					"\n          work.vx_p_msgs = vx_p_msgs;" +
					"\n          work.vx_p_msgblocks = vx_p_msgblocks;" +
					"\n          output = work;" +
					"\n        }" +
					"\n      }"
			default:
				valnew = "" +
					validkeys +
					"\n      String key = \"\";" +
					"\n      Core.Type_msg msg;" +
					"\n      for (Object valsub : vals) {" +
					"\n        if (valsub instanceof Core.Type_msgblock) {" +
					"\n          msgblock = msgblock.vx_copy(valsub);" +
					"\n        } else if (valsub instanceof Core.Type_msg) {" +
					"\n          msgblock = msgblock.vx_copy(valsub);" +
					"\n        } else if (key == \"\") {" +
					"\n          boolean istestkey = false;" +
					"\n          String testkey = \"\";" +
					"\n          if (valsub instanceof Core.Type_string) {" +
					"\n            Core.Type_string valstr = (Core.Type_string)valsub;" +
					"\n            testkey = valstr.vx_string();" +
					"\n            istestkey = true;" +
					"\n          } else if (valsub instanceof String) {" +
					"\n            testkey = (String)valsub;" +
					"\n            istestkey = true;" +
					defaultkey +
					"\n          } else {" +
					"\n            Core.Type_any msgval;" +
					"\n            if (valsub instanceof Core.Type_any) {" +
					"\n              msgval = (Core.Type_any)valsub;" +
					"\n            } else {" +
					"\n              msgval = Core.vx_new_string(valsub.toString());" +
					"\n            }" +
					"\n            msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidkeytype\", msgval);" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n          if (istestkey) {" +
					"\n            if (!testkey.startsWith(\":\")) {" +
					"\n              testkey = \":\" + testkey;" +
					"\n            }" +
					"\n            boolean isvalidkey = validkeys.contains(testkey);" +
					"\n            if (isvalidkey) {" +
					"\n              key = testkey;" +
					defaultstring +
					"\n            } else {" +
					"\n              Core.Type_any msgval = Core.vx_new_string(testkey);" +
					"\n              msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidkey\", msgval);" +
					"\n              msgblock = msgblock.vx_copy(msg);" +
					"\n            }" +
					"\n          }" +
					"\n        } else {" +
					"\n          switch (key) {" +
					valnewswitch +
					"\n          default:" +
					"\n            Core.Type_any msgval = Core.vx_new_string(key);" +
					"\n            msg = Core.vx_msg_from_error(\"" + typepath + "\", \":invalidkey\", msgval);" +
					"\n            msgblock = msgblock.vx_copy(msg);" +
					"\n          }" +
					"\n          key = \"\";" +
					"\n        }" +
					"\n      }" +
					"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
					"\n        Class_" + typename + " work = new Class_" + typename + "();" +
					valcopyend +
					"\n        if (msgblock != Core.e_msgblock) {" +
					"\n          work.vxmsgblock = msgblock;" +
					"\n        }" +
					"\n        output = work;" +
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
		if valnew == "" {
			valnew = "" +
				"\n      if (ischanged || (msgblock != Core.e_msgblock)) {" +
				"\n        Class_" + typename + " work = new Class_" + typename + "();" +
				"\n        if (msgblock != Core.e_msgblock) {" +
				"\n          work.vxmsgblock = msgblock;" +
				"\n        }" +
				"\n        output = work;" +
				"\n      }"
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
	sinterface := LangInterfaceFromType(lang, typ)
	typedef := "" +
		"\n    @Override" +
		"\n    public Core.Type_typedef vx_typedef() {" +
		"\n      return " + LangTypeDefFromType(lang, typ, "      ") + ";" +
		"\n    }" +
		"\n"
	output += "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   * (type " + typ.name + ")" +
		"\n   */" +
		sinterface +
		LangClassHeaderFromType(lang, typ, 1) +
		"\n" +
		instancefuncs +
		"\n    @Override" +
		"\n    public Type_" + typename + " vx_new(final Object... vals) {" +
		"\n      return e_" + typename + ".vx_copy(vals);" +
		"\n    }" +
		"\n" +
		"\n    @Override" +
		"\n    public Type_" + typename + " vx_copy(final Object... vals) {" +
		"\n      Type_" + typename + " output = this;" +
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

func LangFromValue(lang *vxlang, value vxvalue, pkgname string, parentfn *vxfunc, indent int, encode bool, test bool, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangFromValue")
	var output = ""
	valstr := ""
	sindent := StringRepeat("  ", indent)
	switch value.code {
	case ":arg":
		valarg := ArgFromValue(value)
		valstr = LangFromName(valarg.name)
		output += valstr
	case ":const":
		switch value.name {
		case "false", "true":
			valstr = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + value.name + ")"
		default:
			if value.pkg == ":native" {
				valstr = LangFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = LangNameFromPkgName(lang, valconst.pkgname) + ".c_" + LangFromName(valconst.alias)
			}
		}
		output = valstr
	case ":func":
		fnc := FuncFromValue(value)
		subpath := path + "/" + fnc.name
		funcname := NameFromFunc(fnc)
		if fnc.debug {
			output += LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "f_log_1(" + LangNameTFromType(lang, fnc.vxtype) + ", " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_string(\"" + funcname + "\"), "
		}
		switch fnc.name {
		case "native":
			// (native)
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
				if valuetext == (":" + lang.name) {
					isNative = true
				} else if valuetext != ":auto" && BooleanFromStringStarts(valuetext, ":") {
					isNative = false
				} else if isNative {
					if argvalue.name == "newline" {
						argtext = "\n"
					} else {
						clstext, msgs := LangFromValue(lang, argvalue, pkgname, parentfn, 0, false, test, subpath)
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
						argtext = StringRemoveQuotes(argtext)
						if argtext == ":auto" {
							argtext = LangNativeAutoFromFunc(lang, parentfn)
						}
					}
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
				propvalue := funcargs[1].value
				switch propvalue.code {
				case "string":
					propname := StringValueFromValue(propvalue)
					if BooleanFromStringStarts(propname, ":") {
						propname = propname[1:]
					}
					structvalue := funcargs[0].value
					work, msgs := LangFromValue(lang, structvalue, pkgname, fnc, 0, true, test, subpath)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					work = work + lang.typeref + LangFromName(propname) + "()"
					argtexts = append(argtexts, work)
					isskip = true
				}
			case "vx/core/fn":
			case "vx/core/let":
				if fnc.async {
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_let_async("
				} else {
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangNameFromFunc(fnc) + "("
				}
			default:
				if fnc.argname != "" {
					output += LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_any_from_func("
					argtexts = append(argtexts, LangNameTFromType(lang, fnc.vxtype))
					argtexts = append(argtexts, LangFromName(fnc.argname))
					if lang == langcpp {
						multiflag = true
					}
				} else {
					output += LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangNameFromFunc(fnc) + "("
				}
			}
			if !isskip {
				if fnc.isgeneric {
					switch funcname {
					case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
					default:
						if fnc.generictype != nil {
							genericarg := LangNameTFromTypeGeneric(lang, fnc.vxtype)
							argtexts = append(argtexts, genericarg)
						}
					}
				}
				if fnc.context {
					argtexts = append(argtexts, "context")
				}
				subindent := indent + 1
				ssubindent := StringRepeat("  ", subindent)
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
								argvaltype = LangNameTypeFullFromType(lang, argtype)
								argvalinstance = LangNameTFromType(lang, argtype)
								lambdavar := argvaltype + " " + lambdaarg.name + " = " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "f_any_from_any(" + argvalinstance + ", " + lambdaarg.name + "_any);"
								lambdavars = append(lambdavars, lambdavar)
							}
							lambdatext := StringFromListStringJoin(lambdaargs, ", ")
							lambdavartext := "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
							if argfunc.async {
								work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-any-key-value-async", "any<-key-value-async",
									"any<-reduce-async", "any<-reduce-next-async":
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_any_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func_async" + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									}
								}
							} else {
								work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								work = "\n  return " + work + ";"
								switch funcarg.vxtype.name {
								case "any<-int",
									"any<-any-key-value", "any<-key-value",
									"any<-reduce", "any<-reduce-next",
									"boolean<-any":
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										work +
										"\n})"
								default:
									if len(arglist) == 1 {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_any" + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
											lambdavartext +
											work +
											"\n})"
									} else {
										argtext = "" +
											LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func" + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
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
									argindent := 1
									for _, lambdaarg := range arglist {
										arglineindent := "\n" + StringRepeat("  ", argindent)
										if lambdaarg.async {
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += "" +
												arglineindent + "final CompletableFuture<" + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + "> future_" + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";" +
												arglineindent + "return " + LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "async_from_async_fn(future_" + LangFromName(lambdaarg.name) + ", (" + LangFromName(lambdaarg.name) + ") -> {"
											aftertext += "" +
												arglineindent + "});"
											argindent += 1
										} else {
											lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, argsubpath)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											lambdatext += arglineindent + "final " + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
										}
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 2, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argtext = "" +
										LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func_async" + lang.typeref + "vx_fn_new(() -> {" +
										lambdatext +
										"\n    return " + work + ";" +
										aftertext +
										"\n})"
								} else {
									argindent := 1
									arglineindent := "\n" + StringRepeat("  ", argindent)
									for _, lambdaarg := range arglist {
										lambdaargpath := argsubpath + "/:arg/" + lambdaarg.name
										lambdavaluetext, msgs := LangFromValue(lang, lambdaarg.value, pkgname, fnc, argindent, true, test, lambdaargpath)
										msgblock = MsgblockAddBlock(msgblock, msgs)
										lambdatext += arglineindent + "final " + LangNameTypeFromTypeSimple(lang, lambdaarg.vxtype, true) + " " + LangFromName(lambdaarg.name) + " = " + lambdavaluetext + ";"
									}
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									work = StringFromStringIndent(work, "  ")
									argtext = "" +
										LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_any_from_func" + lang.typeref + "vx_fn_new(() -> {" +
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
									work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, subindent, true, test, argsubpath)
									msgblock = MsgblockAddBlock(msgblock, msgs)
									argvaluefuncname := "any_from_func"
									switch NameFromType(funcarg.vxtype) {
									case "vx/core/boolean<-func":
										argvaluefuncname = "boolean_from_func"
									}
									argtext = "" +
										LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_" + argvaluefuncname + lang.typeref + "vx_fn_new(() -> {" +
										"\n  return " + work + ";" +
										"\n})"
								}
							case ":funcref":
								switch funcarg.vxtype.name {
								case "any<-any-key-value", "any<-any-key-value-async",
									"any<-key-value", "any<-key-value-async",
									"any<-reduce", "any<-reduce-async",
									"any<-reduce-next", "any<-reduce-next-async":
									funcargfunc := FuncFromValue(argvalue)
									funcarglist := funcargfunc.listarg
									lambdatext, lambdavartext, lambdaargtext := LangLambdaFromArgList(lang, funcarglist, funcargfunc.isgeneric)
									work := LangNameFFromFunc(lang, funcargfunc) + "(" + lambdaargtext + ")"
									outputtype := LangNameTypeFromType(lang, anytype)
									if funcargfunc.async {
										outputtype = "CompletableFuture<Core.Type_any>"
									}
									argtext = "" +
										LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new((" + lambdatext + ") -> {" +
										lambdavartext +
										"\n  " + outputtype + " output_" + StringFromInt(subindent) + " = " + work + lang.lineend +
										"\n  return output_" + StringFromInt(subindent) + lang.lineend +
										"\n})"
								}
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
								workindent := 1
								if converttoasync {
									workindent += 1
								}
								work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, workindent, true, test, argsubpath)
								if converttoasync {
									sworkindent := StringRepeat("  ", workindent)
									work = "Core.f_async(" + LangNameTFromType(lang, argfunctype) + ",\n" + sworkindent + work + "\n  )"
								}
								msgblock = MsgblockAddBlock(msgblock, msgs)
								if argvalue.code == ":func" && argvalue.name == "native" {
								} else {
									work = "\n  return " + work + ";"
								}
								argtext = "" +
									LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_fn_new(() -> {" +
									work +
									"\n})"
							}
						}
						if argtext == "" {
							work, msgs := LangFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
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
								argtext = ssubindent + StringFromStringIndent(argtext, ssubindent)
							} else {
								multiflag = true
								argtext = "" +
									LangNameTFromType(lang, funcarg.vxtype) + lang.typeref + "vx_new(" +
									"\n" + ssubindent + StringFromStringIndent(argtext, ssubindent)
							}
						}
						if argtext != "" {
							argtexts = append(argtexts, argtext)
						}
					}
				}
			}
			if multiline {
				output += "\n" + sindent + "  " + StringFromStringIndent(StringFromListStringJoin(argtexts, ",\n"), sindent+"  ")
				if multiflag {
					output += "\n" + sindent + "  )"
				}
				switch fnc.name {
				case "fn":
				default:
					output += "\n" + sindent + ")"
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
		if fnc.debug {
			output += ")"
		}
	case ":funcref":
		valfunc := FuncFromValue(value)
		valstr = ""
		valstr += LangNameFromPkgName(lang, valfunc.pkgname) + lang.typeref + "t_" + LangFromName(valfunc.alias)
		output = sindent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		output = LangNameFromPkgName(lang, valtype.pkgname) + lang.typeref + "t_" + LangFromName(valtype.alias)
	case "string":
		valstr = StringValueFromValue(value)
		if valstr == "" {
		} else if BooleanFromStringStarts(valstr, ":") {
			output = valstr
		} else if BooleanFromStringStartsEnds(valstr, "\"", "\"") {
			valstr = valstr[1 : len(valstr)-1]
			if encode {
				output = LangFromText(valstr)
			} else {
				output = valstr
			}
		} else if BooleanIsNumberFromString(valstr) {
			output = valstr
		} else {
			output = valstr
		}
		if encode {
			output = LangTypeStringValNew(output)
		}
	case "boolean":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_boolean(" + valstr + ")"
		}
	case "decimal":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "t_decimal" + lang.typeref + "vx_new_from_string(\"" + valstr + "\")"
		}
	case "float":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_float(" + valstr + ")"
		}
	case "int":
		if encode {
			valstr = StringValueFromValue(value)
			output = LangNameFromPkgName(lang, "vx/core") + lang.pkgref + "vx_new_int(" + valstr + ")"
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

func LangFuncHeader(lang *vxlang, fnc *vxfunc, ispackage bool) string {
	output := ""
	return output
}

func LangFuncHeaderCall(lang *vxlang, fnc *vxfunc, ispackage bool) string {
	output := ""
	return output
}

func LangFuncHeaderInterface(lang *vxlang, fnc *vxfunc, ispackage bool) string {
	output := ""
	return output
}

func LangGenericDefinitionFromFunc(lang *vxlang, fnc *vxfunc) string {
	output := ""
	var mapgeneric = make(map[string]string)
	if fnc.generictype != nil {
		returntype := LangGenericFromType(lang, fnc.generictype)
		mapgeneric[fnc.vxtype.name] = returntype + " extends " + LangNameTypeFromTypeSimple(lang, fnc.vxtype, true)
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			if !argtype.isfunc {
				if argtype.isgeneric {
					_, ok := mapgeneric[argtype.name]
					if !ok {
						argtypename := LangGenericFromType(lang, argtype)
						worktext := argtypename + " extends " + LangNameTypeFromTypeSimple(lang, arg.vxtype, true)
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

func LangGenericFromType(lang *vxlang, typ *vxtype) string {
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
		output = LangNameTypeFromType(lang, typ)
	}
	return output
}

func LangImport(lang *vxlang, project *vxproject, pkgname string, imports string) string {
	output := ""
	importline := ""
	switch lang.name {
	case "cpp":
		importline = "#include \"" + pkgname + ".hpp\""
	case "csharp":
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "using " + path + ";"
	case "java":
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name
		importline = "import " + importname + lang.lineend
	default:
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "import " + path + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangImportTest(lang *vxlang, project *vxproject, pkgname string, imports string) string {
	output := ""
	importline := ""
	switch lang.name {
	case "cpp":
		importline = "#include \"" + pkgname + "test.hpp\""
	case "csharp":
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "using " + path + ";"
	case "java":
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name + "Test"
		importline = "import " + importname + lang.lineend
	default:
		path := StringFromStringFindReplace(pkgname, "/", ".")
		importline = "import " + path + "test" + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangImportsFromPackage(lang *vxlang, pkg *vxpackage, pkgprefix string, body string, test bool) string {
	output := ""
	switch lang.name {
	case "java":
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
				} else if lib.lang == (":" + lang.name) {
				} else {
					isskip = true
				}
			} else if libpkgpath == pkgpath {
				isskip = true
			} else {
				libprefix := pkgpath
				if lib.pkg != nil {
					switch lang.name {
					case "java", "kotlin":
						libprefix = lib.pkg.project.javadomain
					}
				}
				libpath = libprefix + "/" + libpkgpath + "*"
				libpath = StringFromStringFindReplace(libpath, "/", ".")
			}
			if !isskip {
				importline := "\nimport " + libpath + lang.lineend
				if IntFromStringFind(output, importline) < 0 {
					output += importline
				}
			}
		}
		if output != "" {
			output += "\n"
		}
	}
	return output
}

func LangIndexFromFunc(fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func LangInterfaceFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	typename := LangNameTypeFullFromType(lang, typ)
	basics := "" +
		"\n    public " + typename + " vx_new(final Object... vals);" +
		"\n    public " + typename + " vx_copy(final Object... vals);" +
		"\n    public " + typename + " vx_empty();" +
		"\n    public " + typename + " vx_type();"
	createtext, _ := LangFromValue(lang, typ.createvalue, "", emptyfunc, 0, true, false, "")
	if createtext != "" {
		createlines := ListStringFromStringSplit(createtext, "\n")
		isoverride := false
		for _, createline := range createlines {
			if createline == "@Override" {
				isoverride = true
			} else if isoverride {
				ipos := IntFromStringFindLast(createline, ")")
				createline = createline[0:ipos+1] + ";"
				basics += "\n    " + createline
				isoverride = false
			}
		}
	}
	switch NameFromType(typ) {
	case "vx/core/any":
		output = "" +
			LangInterfaceHeader(lang, anytype, emptylisttype, 1) +
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
			LangInterfaceHeader(lang, booleantype, []*vxtype{anytype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/decimal":
		output = "" +
			LangInterfaceHeader(lang, decimaltype, []*vxtype{numbertype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/float":
		output = "" +
			LangInterfaceHeader(lang, floattype, []*vxtype{numbertype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/func":
		output = "" +
			LangInterfaceHeader(lang, functype, []*vxtype{anytype}, 1) +
			basics +
			"\n	   public Core.Type_funcdef vx_funcdef();" +
			"\n  }" +
			"\n"
	case "vx/core/int":
		output = "" +
			LangInterfaceHeader(lang, inttype, []*vxtype{numbertype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/string":
		output = "" +
			LangInterfaceHeader(lang, stringtype, []*vxtype{anytype}, 1) +
			basics +
			"\n  }" +
			"\n"
	case "vx/core/list":
		output = "" +
			LangInterfaceHeader(lang, listtype, []*vxtype{anytype}, 1) +
			basics +
			"\n    public List<Core.Type_any> vx_list();" +
			"\n    public Core.Type_any vx_any(final Core.Type_int index);" +
			"\n  }" +
			"\n"
	case "vx/core/map":
		output = "" +
			LangInterfaceHeader(lang, maptype, []*vxtype{anytype}, 1) +
			basics +
			"\n    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval);" +
			"\n    public Core.Type_any vx_any(final Core.Type_string key);" +
			"\n    public Map<String, Core.Type_any> vx_map();" +
			"\n  }" +
			"\n"
	case "vx/core/struct":
		output = "" +
			LangInterfaceHeader(lang, structtype, []*vxtype{anytype}, 1) +
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
		var extends []*vxtype
		switch typ.extends {
		case "boolean":
			extends = append(extends, booleantype)
		case "decimal":
			extends = append(extends, decimaltype)
		case "float":
			extends = append(extends, floattype)
		case "int":
			extends = append(extends, inttype)
		case "string":
			extends = append(extends, stringtype)
		case ":list":
			extends = append(extends, listtype)
			allowclass := "Core.Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = LangNameTypeFullFromType(lang, allowtype)
				allowname = LangNameFromType(lang, allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    public List<" + allowclass + "> vx_list" + allowname + "();" +
					"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_int index);"
			}
		case ":map":
			extends = append(extends, maptype)
			allowclass := "Core.Type_any"
			allowname := "any"
			allowtypes := ListAllowTypeFromType(typ)
			if len(allowtypes) > 0 {
				allowtype := allowtypes[0]
				allowclass = LangNameTypeFullFromType(lang, allowtype)
				allowname = LangNameFromType(lang, allowtype)
			}
			if allowname != "any" {
				extras += "" +
					"\n    public Map<String, " + allowclass + "> vx_map" + allowname + "();" +
					"\n    public " + allowclass + " vx_" + allowname + "(final Core.Type_string key);"
			}
		case ":struct":
			extends = append(extends, structtype)
			if len(typ.traits) > 0 {
				extends = append(extends, typ.traits...)
			}
			for _, arg := range ListPropertyTraitFromType(typ) {
				extras += "\n    public " + LangNameTypeFromType(lang, arg.vxtype) + " " + LangFromName(arg.alias) + "();"
			}
		default:
			extends = append(extends, anytype)
		}
		output = "" +
			LangInterfaceHeader(lang, typ, extends, 1) +
			basics +
			extras +
			"\n  }" +
			"\n"
	}
	return output
}

func LangInterfaceFnFromFunc(lang *vxlang, fnc *vxfunc) string {
	interfaces := ""
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
		"vx/core/any<-int",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async",
		"vx/core/boolean<-any",
		"vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/none<-any":
		returntype := "Core.Type_any"
		switch NameFromType(fnc.vxtype) {
		case "vx/core/none":
			returntype = "void"
		default:
			if fnc.async {
				returntype = "CompletableFuture<Core.Type_any>"
			}
		}
		var args []string
		if fnc.context {
			args = append(args, "Core.Type_context context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argname := LangFromName(arg.alias)
			argtypename := LangNameTypeFromTypeSimple(lang, argtype, true)
			args = append(args, argtypename+" "+argname)
		}
		argnames := StringFromListStringJoin(args, ", ")
		interfaces = "" +
			"\n    @FunctionalInterface" +
			"\n    public static interface IFn {" +
			"\n      public " + returntype + " resolve(" + argnames + ");" +
			"\n    }" +
			"\n"
	}
	return interfaces
}

func LangInterfaceFromFunc(lang *vxlang, fnc *vxfunc) string {
	funcname := LangNameFromFunc(fnc)
	extends := ""
	interfaces := ""
	generictypes := LangGenericDefinitionFromFunc(lang, fnc)
	returntype := LangNameTypeFromType(lang, fnc.vxtype)
	var listargtext []string
	if fnc.generictype != nil {
		returntype = LangGenericFromType(lang, fnc.generictype)
		switch NameFromFunc(fnc) {
		case "vx/core/new", "vx/core/copy", "vx/core/empty":
		default:
			listargtext = append(listargtext, "final "+returntype+" generic_any_1")
		}
		if fnc.context {
			listargtext = append(listargtext, "final Core.Type_context context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := ""
			if argtype.isgeneric {
				argtypename = LangGenericFromType(lang, argtype)
			} else {
				argtypename = LangNameTypeFromType(lang, argtype)
			}
			argname := LangFromName(arg.alias)
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
		if fnc.context {
			listargtext = append(listargtext, "final Core.Type_context context")
		}
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argtypename := LangNameTypeFromTypeSimple(lang, argtype, true)
			argname := LangFromName(arg.alias)
			listargtext = append(listargtext, "final "+argtypename+" "+argname)
		}
	}
	argtext := StringFromListStringJoin(listargtext, ", ")
	switch NameFromFunc(fnc) {
	case "vx/core/any<-any", "vx/core/any<-any-async",
		"vx/core/any<-any-context", "vx/core/any<-any-context-async",
		"vx/core/any<-any-key-value", "vx/core/any<-any-key-value-async",
		"vx/core/any<-func", "vx/core/any<-func-async",
		"vx/core/any<-key-value", "vx/core/any<-key-value-async",
		"vx/core/any<-none", "vx/core/any<-none-async",
		"vx/core/any<-reduce", "vx/core/any<-reduce-async",
		"vx/core/any<-reduce-next", "vx/core/any<-reduce-next-async":
		extends = "Core.Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(Core.Class_" + funcname + ".IFn fn);"
	case "vx/core/any<-int":
		extends = "Core.Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(Core.Class_any_from_int.IFn fn);"
	case "vx/core/boolean<-any":
		extends = "Core.Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(Core.Class_boolean_from_any.IFn fn);"
	case "vx/core/boolean<-func", "vx/core/boolean<-none",
		"vx/core/int<-func", "vx/core/int<-none",
		"vx/core/string<-func", "vx/core/string<-none":
		extends = "Core.Type_func"
		interfaces += "" +
			"\n    public Func_" + funcname + " vx_fn_new(Core.Class_any_from_func.IFn fn);"
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
	if extends == "Core.Type_func" {
		if fnc.async {
			extends += ", Core.Type_replfunc_async"
		} else {
			extends += ", Core.Type_replfunc"
		}
	}
	interfaces += "" +
		"\n    public " + generictypes + returntype + " vx_" + funcname + "(" + argtext + ");"
	output := "" +
		"\n  public static interface Func_" + funcname + " " + lang.itfext + " " + extends + " {" +
		interfaces +
		"\n  }" +
		"\n"
	return output
}

func LangInterfaceHeader(lang *vxlang, typ *vxtype, extendtypes []*vxtype, indent int) string {
	lineindent := LangIndent(lang, indent, true)
	output := ""
	extendtext := ""
	var extendtexts []string
	for _, extendtype := range extendtypes {
		extendpart := LangNameTypeFromType(lang, extendtype)
		extendtexts = append(extendtexts, extendpart)
	}
	extendtext = StringFromListStringJoin(extendtexts, ", ")
	switch lang.name {
	case "csharp":
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "interface Type_" + LangNameFromType(lang, typ) + extendtext + " {"
	case "java":
		if extendtext != "" {
			extendtext = " extends " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {"
	case "kotlin":
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "interface Type_" + LangNameFromType(lang, typ) + extendtext + " {"
	}
	return output
}

func LangLambdaFromArgList(lang *vxlang, arglist []vxarg, isgeneric bool) (string, string, string) {
	var lambdatypenames []string
	var lambdavars []string
	var lambdaargnames []string
	if isgeneric {
		lambdaargname := LangNameTFromType(lang, anytype)
		lambdaargnames = append(lambdaargnames, lambdaargname)
	}
	for _, lambdaarg := range arglist {
		argvaltype := ""
		argtype := lambdaarg.vxtype
		lambdaargname := LangFromName(lambdaarg.alias) + "_lmb"
		lambdaargnames = append(lambdaargnames, lambdaargname)
		switch NameFromType(argtype) {
		case "vx/core/any", "vx/core/any-1":
			argtypename := LangNameTypeFromType(lang, anytype)
			lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname)
		default:
			switch lambdaarg.name {
			case "key":
				argtypename := LangNameTypeFromType(lang, argtype)
				lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname)
			default:
				argvaltype = LangNameTypeFullFromType(lang, argtype)
				argvaltname := LangNameTFromType(lang, argtype)
				argtypename := LangNameTypeFromType(lang, anytype)
				lambdatypenames = append(lambdatypenames, argtypename+" "+lambdaargname+"_any")
				corepkgname := LangNameFromPkgName(lang, "vx/core")
				lambdavar := argvaltype + " " + lambdaargname + " = " + corepkgname + lang.pkgref + "f_any_from_any(" + argvaltname + ", " + lambdaargname + "_any)" + lang.lineend
				lambdavars = append(lambdavars, lambdavar)
			}
		}
	}
	lambdanames := StringFromListStringJoin(lambdaargnames, ", ")
	lambdatext := StringFromListStringJoin(lambdatypenames, ", ")
	lambdavartext := ""
	if len(lambdavars) > 0 {
		lambdavartext = "\n  " + StringFromListStringJoin(lambdavars, "\n  ")
	}
	return lambdatext, lambdavartext, lambdanames
}

func LangNameCFromConst(lang *vxlang, cnst *vxconst) string {
	name := "c_" + LangFromName(cnst.alias)
	if cnst.pkgname != "" {
		name = LangNameFromPkgName(lang, cnst.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameClassFullFromType(lang *vxlang, typ *vxtype) string {
	name := LangNameFromPkgName(lang, typ.pkgname)
	name += ".Class_"
	name += LangNameFromType(lang, typ)
	return name
}

func LangNameEFromType(lang *vxlang, typ *vxtype) string {
	output := ""
	if typ.isgeneric {
		output = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref
		if lang == langcpp {
			output += "vx_empty"
		} else {
			output += "f_empty"
		}
		output += "(generic_" + LangFromName(typ.name) + ")"
	} else {
		output = "e_" + LangNameFromType(lang, typ)
		if typ.pkgname != "" {
			output = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref + output
		}
	}
	return output
}

func LangNameEFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "e_" + LangNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameFFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "f_" + LangNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameFromArg(lang *vxlang, arg vxarg) string {
	return LangFromName(arg.alias)
}

func LangNameFromConst(cnst *vxconst) string {
	return LangFromName(cnst.alias)
}

func LangNameFromFunc(fnc *vxfunc) string {
	return LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
}

func LangNameFromFuncFull(lang *vxlang, fnc *vxfunc) string {
	return LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "f_" + LangNameFromFunc(fnc)
}

func LangNameFromPkgName(lang *vxlang, pkgname string) string {
	output := ""
	switch lang.name {
	case "java":
		ipos := IntFromStringFindLast(pkgname, "/")
		output = StringSubstring(pkgname, ipos+1, len(pkgname))
		output = StringUCaseFirst(output)
	default:
		output = pkgname
	}
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func LangNameFromType(lang *vxlang, typ *vxtype) string {
	return LangNameFromTypeSimple(lang, typ, false)
}

func LangNameFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	alias := typ.alias
	if alias == "" {
		name += LangFromName(typ.name)
	} else {
		if simple && BooleanFromStringStarts(alias, "generic-") {
			alias = StringFromStringFindReplace(alias, "generic-", "")
			ipos := IntFromStringFindLast(alias, "-")
			alias = alias[0:ipos]
		}
		name += LangFromName(alias)
	}
	return name
}

func LangNameTFromFunc(lang *vxlang, fnc *vxfunc) string {
	name := "t_" + LangNameFromFunc(fnc)
	if fnc.pkgname != "" {
		name = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameTFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTFromTypeSimple(lang, typ, false)
}

func LangNameTFromTypeGeneric(lang *vxlang, typ *vxtype) string {
	name := ""
	if typ.isgeneric {
		name = "generic_" + LangFromName(typ.name)
	} else {
		name = LangNameTFromType(lang, typ)
	}
	return name
}

func LangNameTFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := "t_" + LangNameFromTypeSimple(lang, typ, simple)
	if typ.pkgname != "" {
		name = LangNameFromPkgName(lang, typ.pkgname) + lang.pkgref + name
	}
	return name
}

func LangNameTypeFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTypeFromTypeSimple(lang, typ, false)
}

func LangNameTypeFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := LangNameTypeFullFromTypeSimple(lang, typ, simple)
	switch NameFromType(typ) {
	case "vx/core/none":
		name = "void"
	}
	return name
}

func LangNameTypeFullFromType(lang *vxlang, typ *vxtype) string {
	return LangNameTypeFullFromTypeSimple(lang, typ, false)
}

func LangNameTypeFullFromTypeSimple(lang *vxlang, typ *vxtype, simple bool) string {
	name := ""
	switch typ {
	case anylisttype:
		name = lang.pkgname + lang.pkgref + "Type_anylist"
	case contexttype:
		name = lang.pkgname + lang.pkgref + "Type_context"
	case stringtype:
		name = lang.pkgname + lang.pkgref + "Type_string"
	case stringprimitivetype:
		name = "String"
	default:
		name = LangNameFromPkgName(lang, typ.pkgname)
		if typ.isfunc {
			name += lang.pkgref + "Func_"
		} else {
			name += lang.pkgref + "Type_"
		}
		name += LangNameFromTypeSimple(lang, typ, simple)
	}
	return name
}

func LangNamespaceFromPackage(lang *vxlang, pkgname string) (string, string) {
	namespaceopen := ""
	namespaceclose := ""
	switch lang.name {
	case "cpp":
		namespaceopen = "\nnamespace " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "csharp":
		namespaceopen = "\nnamespace " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "java":
		namespaceopen = "\npublic final class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "js":
		namespaceopen = "\nexport default class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case "kotlin":
		namespaceopen = "" +
			"\nclass final class " + pkgname + " {" +
			"\n		companion object {\n\n"
		namespaceclose = "\n}\n}\n"
	}
	return namespaceopen, namespaceclose
}

func LangNativeAutoFromFunc(lang *vxlang, fnc *vxfunc) string {
	output := ""
	var listargname []string
	if fnc.generictype != nil {
		argname := LangNameTFromTypeGeneric(lang, fnc.generictype)
		listargname = append(listargname, argname)
	}
	if fnc.context {
		argname := "context"
		listargname = append(listargname, argname)
	}
	for _, arg := range fnc.listarg {
		argname := LangNameFromArg(lang, arg)
		listargname = append(listargname, argname)
	}
	argnames := StringFromListStringJoin(listargname, ", ")
	output = LangNameFromPkgName(lang, fnc.pkgname) + lang.pkgref + "vx_" + LangNameFromFunc(fnc) + "(" + argnames + ")" + lang.lineend
	switch lang.name {
	case "cpp":
		if fnc.generictype != nil {
			argname := LangNameTFromTypeGeneric(lang, fnc.generictype)
			output = "" +
				"vx_core::Type_any result = " + output +
				"\noutput = vx_core::vx_any_from_any(" + argname + ", result);"
		}
	}
	return output
}

func LangPackagePathFromPrefixName(lang *vxlang, pkgprefix string, pkgname string) (string, string) {
	pkgpath := ""
	name := ""
	switch lang.name {
	case "java":
		pkgpath = pkgprefix + pkgname
		ipos := IntFromStringFindLast(pkgpath, "/")
		name = StringSubstring(pkgpath, ipos+1, len(pkgpath))
		pkgpath = StringSubstring(pkgpath, 0, ipos)
		pkgpath = StringFromStringFindReplace(pkgpath, "/", ".")
		pkgpath = LangFromName(pkgpath)
		name = LangNameFromPkgName(lang, name)
	case "kotlin":
		name = LangNameFromPkgName(lang, pkgname)
		pkgpath = name
	default:
		name = LangNameFromPkgName(lang, pkgname)
		pkgpath = name
	}
	return pkgpath, name
}

func LangReplFromFunc(lang *vxlang, fnc *vxfunc) string {
	output := ""
	replparams := ""
	argidx := 0
	var listargname []string
	pkgname := LangNameFromPkgName(lang, fnc.pkgname)
	funcname := LangFromName(fnc.alias) + LangIndexFromFunc(fnc)
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
		outputtype = LangNameTypeFromTypeSimple(lang, fnc.vxtype, true)
		outputttype = LangNameTFromTypeSimple(lang, fnc.vxtype, true)
		//emptytype = LangNameEFromType(fnc.vxtype)
		returnvalue = "output = "
	}
	if fnc.isgeneric {
		switch NameFromFunc(fnc) {
		case "vx/core/copy", "vx/core/empty", "vx/core/new":
		default:
			if fnc.generictype != nil {
				replparam := outputtype + " generic_" + LangFromName(fnc.generictype.name) + " = Core.f_any_from_any(" + outputttype + ", arglist.vx_any(Core.vx_new_int(" + StringFromInt(argidx) + ")));"
				replparams += "\n      " + replparam
				listargname = append(listargname, "generic_"+LangFromName(fnc.generictype.name))
			}
		}
	}
	if fnc.context {
		listargname = append(listargname, "context")
		replparam := "Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(" + StringFromInt(argidx) + ")));"
		replparams += "\n      " + replparam
	}
	for _, arg := range fnc.listarg {
		if (funcname == "let" || funcname == "let_async") && arg.name == "args" {
		} else {
			argname := LangFromName(arg.alias)
			replparam := LangNameTypeFromTypeSimple(lang, arg.vxtype, true) + " " + argname + " = Core.f_any_from_any(" + LangNameTFromTypeSimple(lang, arg.vxtype, true) + ", arglist.vx_any(Core.vx_new_int(" + StringFromInt(argidx) + ")));"
			replparams += "\n      " + replparam
			listargname = append(listargname, argname)
			argidx += 1
		}
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

/*
func LangStringFromProjectCmd(prj *vxproject, cmd *vxcommand) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangStringFromProjectCmd")
	files, msgs := LangFilesFromProjectCmd(prj, cmd)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	text := StringFromListFile(files)
	return text, msgblock
}
*/

func LangTestCase(lang *vxlang, testvalues []vxvalue, testpkg string, testname string, testcasename string, fnc *vxfunc, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestCase")
	var output = ""
	if len(testvalues) > 0 {
		var desctexts []string
		for idx, testvalue := range testvalues {
			subpath := path + "/tests" + StringFromInt(idx+1)
			descvaluetext, msgs := LangFromValue(lang, testvalue, testpkg, fnc, 6, true, true, subpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			desctext := "" +
				"\n        Test.t_testdescribe.vx_new(" +
				"\n          \":describename\", \"" + LangTestFromValue(testvalue) + "\"," +
				"\n          \":testresult\"," +
				"\n            " + descvaluetext +
				"\n        )"
			desctexts = append(desctexts, desctext)
		}
		describelist := StringFromListStringJoin(desctexts, ",")
		output = "" +
			"\n  static Test.Type_testcase " + testcasename + "(final Core.Type_context context) {" +
			"\n    Test.Type_testcase output = Test.t_testcase.vx_new(" +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + testpkg + "\"," +
			"\n      \":casename\", \"" + testname + "\"," +
			"\n      \":describelist\"," +
			"\n      Test.t_testdescribelist.vx_new(" + describelist +
			"\n      )" +
			"\n    );" +
			"\n    return output;" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func LangTestFromConst(lang *vxlang, cnst *vxconst) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromConst")
	testvalues := cnst.listtestvalue
	testpkg := cnst.pkgname
	testname := cnst.name
	testcasename := "c_" + LangFromName(cnst.alias)
	path := cnst.pkgname + "/" + cnst.name
	fnc := emptyfunc
	output, msgs := LangTestCase(lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromFunc(lang *vxlang, fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromFunc")
	testvalues := fnc.listtestvalue
	testpkg := fnc.pkgname
	idx := LangIndexFromFunc(fnc)
	testname := fnc.name + idx
	funcname := LangFromName(fnc.alias) + idx
	testcasename := "f_" + funcname
	path := fnc.pkgname + "/" + fnc.name
	output, msgs := LangTestCase(lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromPackage(lang *vxlang, pkg *vxpackage, prj *vxproject, command *vxcommand, pkgprefix string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromPackage")
	pkgpath, pkgname := LangPackagePathFromPrefixName(lang, pkgprefix, pkg.name)
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
		test, msgs := LangTestFromType(lang, typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		covertype = append(covertype, "      \":"+typid+"\", "+StringFromInt(len(typ.testvalues)))
		if command.filter == "" {
		} else if NameFromType(typ) != command.filter {
			test = ""
		}
		if test != "" {
			covertypecnt += 1
			typetexts += test
			testall = append(testall, pkgname+"Test.t_"+LangFromName(typ.alias)+"(context)")
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
		test, msgs := LangTestFromConst(lang, cnst)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		coverconst = append(coverconst, "      \":"+cnstid+"\", "+StringFromInt(len(cnst.listtestvalue)))
		if command.filter == "" {
		} else if NameFromConst(cnst) != command.filter {
			test = ""
		}
		if test != "" {
			coverconstcnt += 1
			consttexts += test
			testall = append(testall, pkgname+"Test.c_"+LangFromName(cnst.alias)+"(context)")
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
			test, msgs := LangTestFromFunc(lang, fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			coverfunc = append(coverfunc, "      \":"+fncid+LangIndexFromFunc(fnc)+"\", "+StringFromInt(len(fnc.listtestvalue)))
			if command.filter == "" {
			} else if NameFromFunc(fnc) != command.filter {
				test = ""
			}
			if test != "" {
				coverfunccnt += 1
				functexts += test
				testall = append(testall, pkgname+"Test.f_"+LangFromName(fnc.alias)+LangIndexFromFunc(fnc)+"(context)")
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
		"\n  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {" +
		"\n    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(" +
		"\n      " + strings.Join(testall, ",\n      ") +
		"\n    ));" +
		"\n    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  public static Test.Type_testcoveragesummary test_coveragesummary() {" +
		"\n    return Test.t_testcoveragesummary.vx_new(" +
		"\n      \":testpkg\",   \"" + pkg.name + "\", " +
		"\n      \":constnums\", " + LangTypeCoverageNumsValNew(coverconstpct, coverconstcnt, coverconsttotal) + ", " +
		"\n      \":docnums\", " + LangTypeCoverageNumsValNew(coverdocpct, coverdoccnt, coverdoctotal) + ", " +
		"\n      \":funcnums\", " + LangTypeCoverageNumsValNew(coverfuncpct, coverfunccnt, coverfunctotal) + ", " +
		"\n      \":bigospacenums\", " + LangTypeCoverageNumsValNew(coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + ", " +
		"\n      \":bigotimenums\", " + LangTypeCoverageNumsValNew(coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + ", " +
		"\n      \":totalnums\", " + LangTypeCoverageNumsValNew(coverpct, covercnt, covertotal) + ", " +
		"\n      \":typenums\", " + LangTypeCoverageNumsValNew(covertypepct, covertypecnt, covertypetotal) +
		"\n    );" +
		"\n  }" +
		"\n" +
		"\n  public static Test.Type_testcoveragedetail test_coveragedetail() {" +
		"\n    return Test.t_testcoveragedetail.vx_new(" +
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
		"\n  public static Test.Type_testpackage test_package(final Core.Type_context context) {" +
		"\n    Test.Type_testcaselist testcaselist = test_cases(context);" +
		"\n    Test.Type_testpackage output = Test.t_testpackage.vx_new(" +
		"\n      \":testpkg\", \"" + pkg.name + "\", " +
		"\n      \":caselist\", testcaselist," +
		"\n      \":coveragesummary\", test_coveragesummary()," +
		"\n      \":coveragedetail\", test_coveragedetail()" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n"
	imports := LangImportsFromPackage(lang, pkg, pkgprefix, body, true)
	output := "" +
		"\npackage " + pkgpath + lang.lineend +
		"\n" +
		imports +
		"\npublic final class " + pkgname + "Test {" +
		"\n" +
		body +
		"\n}\n"
	return output, msgblock
}

func LangTestFromType(lang *vxlang, typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangTestFromType")
	testvalues := typ.testvalues
	testpkg := typ.pkgname
	testname := typ.name
	testcasename := "t_" + LangFromName(typ.alias)
	fnc := emptyfunc
	path := typ.pkgname + "/" + typ.name
	output, msgs := LangTestCase(lang, testvalues, testpkg, testname, testcasename, fnc, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return output, msgblock
}

func LangTestFromValue(value vxvalue) string {
	var output = ""
	output = LangFromText(value.textblock.text)
	return output
}

func LangTypeCoverageNumsValNew(pct int, tests int, total int) string {
	return "" +
		"Test.t_testcoveragenums.vx_new(" +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
		")"
}

func LangTypeDefFromType(lang *vxlang, typ *vxtype, indent string) string {
	lineindent := "\n" + indent
	allowtypes := LangTypeListFromListType(lang, typ.allowtypes)
	disallowtypes := LangTypeListFromListType(lang, typ.disallowtypes)
	allowfuncs := "Core.e_funclist"
	disallowfuncs := "Core.e_funclist"
	allowvalues := "Core.e_anylist"
	disallowvalues := "Core.e_anylist"
	properties := "Core.e_argmap"
	traits := LangTypeListFromListType(lang, typ.traits)
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

func LangTypeDefMapFromProperties(lang *vxlang, args []vxarg, indent string) string {
	output := "null"
	lineindent := "\n" + indent
	if len(args) > 0 {
		var props []string
		for _, arg := range args {
			key := LangFromName(arg.alias)
			typ := LangTypeDefFromType(lang, arg.vxtype, indent+"  ")
			props = append(props, "Core.keyvalue_from_key_value(\":"+key+"\", "+typ+")")
		}
		output = "" +
			"Core.hashmap_from_keyvalues(" +
			lineindent + "  " + StringFromListStringJoin(props, ","+lineindent+"  ") +
			lineindent + ")"
	}
	return output
}

func LangTypeIntValNew(val int) string {
	return "Core.vx_new_int(" + StringFromInt(val) + ")"
}

func LangTypeListFromListType(lang *vxlang, listtype []*vxtype) string {
	output := "Core.e_typelist"
	if len(listtype) > 0 {
		var listtext []string
		for _, typ := range listtype {
			typetext := LangNameTFromType(lang, typ)
			listtext = append(listtext, typetext)
		}
		output = "Core.t_typelist.vx_new(" + StringFromListStringJoin(listtext, ", ") + ")"
	}
	return output
}

func LangTypeStringValNew(val string) string {
	valstr := StringFromStringFindReplace(val, "\n", "\\n")
	return "Core.vx_new_string(\"" + valstr + "\")"
}

func LangWriteFromProjectCmd(lang *vxlang, prj *vxproject, cmd *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("LangWriteFromProjectCmd")
	files, msgs := LangFilesFromProjectCmd(lang, prj, cmd)
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
		msgs := LangFolderCopyTestdataFromProjectPath(prj, targetpath)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return msgblock
}

func LangIndent(lang *vxlang, indent int, line bool) string {
	output := ""
	if line {
		output += "\n"
	}
	output += StringRepeat(lang.indent, indent)
	return output
}

func LangVar(lang *vxlang, varname string, vartype *vxtype, varvalue string, indent int, isconst bool, isfuture bool) string {
	output := LangIndent(lang, indent, true)
	switch lang.name {
	case "java":
		typetext := ""
		typetext = LangNameTypeFullFromType(lang, vartype)
		if isfuture {
			typetext = "CompletableFuture<" + typetext + ">"
		}
		output += typetext + " " + varname
		if varvalue != "" {
			output += " = " + varvalue
		}
		output += ";"
	case "kotlin":
		if isconst {
			output += "val"
		} else {
			output += "var"
		}
		output += " " + varname
		output += " : " + LangNameTypeFullFromType(lang, vartype)
		if varvalue != "" {
			if isfuture {
				output += " = await " + varvalue
			} else if (varvalue == "\"\"") && (vartype == stringprimitivetype) {
			} else {
				output += " = " + varvalue
			}
		}
	}
	return output
}

func LangVarSet(lang *vxlang, varname string, varvalue string, indent int) string {
	output := LangIndent(lang, indent, true)
	output += varname
	output += " = " + varvalue
	switch lang.name {
	case "java":
		output += ";"
	}
	return output
}

func LangApp(lang *vxlang, project *vxproject, cmd *vxcommand) string {
	indent0 := LangIndent(lang, 0, true)
	indent1 := LangIndent(lang, 1, true)
	indent2 := LangIndent(lang, 2, true)
	indent3 := LangIndent(lang, 3, true)
	imports := ""
	imports = LangImport(lang, project, "vx/core", imports)
	contexttext := LangVar(lang, "context", contexttype, "Core.f_context_main(arglist)", 3, true, false)
	maintext := "" +
		LangVar(lang, "mainval", stringtype, "Core.f_main(arglist)", 3, true, false) +
		LangVarSet(lang, "output", "mainval.vx_string()", 3)
	if cmd.context == "" && cmd.main == "" {
	} else {
		contextfunc := FuncFromProjectFuncname(project, cmd.context)
		mainfunc := FuncFromProjectFuncname(project, cmd.main)
		if cmd.context != "" && contextfunc == emptyfunc {
			MsgLog("Error! Context Not Found: (project (cmd :context " + cmd.context + "))")
		}
		if cmd.main != "" && mainfunc == emptyfunc {
			MsgLog("Error! Main Not Found: (project (cmd :main " + cmd.main + "))")
		}
		if contextfunc != emptyfunc {
			if contextfunc.pkgname == "" {
			} else if contextfunc.pkgname != mainfunc.pkgname {
				imports += LangImport(lang, project, contextfunc.pkgname, imports)
			}
			if contextfunc.async {
				contexttext = "" +
					LangVar(lang, "asynccontext", contexttype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 3, true, true) +
					LangVar(lang, "context", contexttype, "Core.vx_sync_from_async(vx_core::t_context, asynccontext)", 3, true, false)
			} else {
				contexttext = LangVar(lang, "context", contexttype, LangNameFFromFunc(lang, contextfunc)+"(arglist)", 3, true, false)
			}
		}
		if mainfunc != emptyfunc {
			if mainfunc.pkgname != "" {
				imports += LangImport(lang, project, mainfunc.pkgname, imports)
			}
			params := "arglist"
			if mainfunc.context {
				params = "context, arglist"
			}
			mainfunctext := LangNameFFromFunc(lang, mainfunc) + "(" + params + ")"
			if mainfunc.async {
				maintext = "" +
					LangVar(lang, "asyncstring", stringtype, mainfunctext, 3, true, true) +
					LangVar(lang, "mainstring", stringtype, "Core.vx_sync_from_async(Core.t_string, asyncstring)", 3, true, false)
			} else {
				maintext = LangVar(lang, "mainstring", stringtype, mainfunctext, 3, true, false)
			}
		}
	}
	packageopen := ""
	classopen := ""
	classclose := ""
	mainopen := ""
	mainclose := ""
	tryopen := ""
	tryclose := ""
	outputopen := ""
	outputclose := ""
	outputprint := ""
	arglistinit := ""
	outputopen = LangVar(lang, "output", stringprimitivetype, "\"\"", 3, false, false)
	outputclose = LangVarSet(lang, "output", "mainstring.vx_string()", 3)
	switch lang.name {
	case "java":
		classopen = indent0 + "public final class App {\n"
		classclose = indent0 + "}\n"
		mainopen = indent1 + "public static void main(String[] args) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (Exception e) {" +
			indent3 + "System.out.println(\"Untrapped Error!\" + e.toString());" +
			indent2 + "}"
		arglistinit = LangVar(lang, "arglist", anylisttype, "Core.vx_anylist_from_arraystring(args)", 3, true, false)
		outputprint = indent3 + "System.out.println(output);"
	case "kotlin":
		packageopen = indent0 + "package App\n"
		mainopen = indent1 + "fun main(args : Array<String>) {"
		mainclose = indent1 + "}\n"
		tryopen = indent2 + "try {"
		tryclose = "" +
			indent2 + "} catch (e : Exception) {" +
			indent3 + "println(e.toString())" +
			indent2 + "}"
		arglistinit = LangVar(lang, "arglist", anylisttype, "vx_core.vx_anylist_from_arraystring(args)", 3, true, false)
		outputprint = indent3 + "println(output)"
	}
	output := `/**
 * App
 */
` +
		imports +
		packageopen +
		classopen +
		mainopen +
		tryopen +
		outputopen +
		arglistinit +
		contexttext +
		maintext +
		outputclose +
		outputprint +
		tryclose +
		mainclose +
		classclose
	return output
}

func LangAppTest(lang *vxlang, project *vxproject, command *vxcommand, pkgprefix string) string {
	imports := ""
	imports += LangImport(lang, project, "vx/core", imports)
	contexttext := `
  Core.Type_anylist arglist = Core.e_anylist;
  Core.Type_context context = ` + pkgprefix + `vx.Test.f_context_test(arglist);`
	if command.context == "" {
	} else {
		contextfunc := FuncFromProjectFuncname(project, command.context)
		if command.context != "" && contextfunc == emptyfunc {
			MsgLog("Error! Context Not Found: (project (cmd :context " + command.context + "))")
		}
		if contextfunc != emptyfunc {
			switch contextfunc.pkgname {
			case "vx/test":
			default:
				imports += LangImport(lang, project, contextfunc.pkgname, imports)
			}
			libprefix := ""
			switch lang.name {
			case "java", "kotlin":
				libprefix = project.javadomain + "."
			}
			pkgname := contextfunc.pkgname
			pkgpath := ""
			pos := strings.LastIndex(pkgname, "/")
			if pos >= 0 {
				pkgpath = pkgname[0:pos]
				pkgpath = libprefix + StringFromStringFindReplace(pkgpath, "/", ".")
			}
			if contextfunc.async {
				contexttext = `
  Core.Type_anylist arglist = Core.e_anylist;
  CompletableFuture<Core.Type_context> asynccontext = ` + pkgpath + `.` + LangNameFFromFunc(lang, contextfunc) + `(arglist);
  Core.Type_context context = Core.vx_sync_from_async(vx_core::t_context, asynccontext);`
			} else {
				contexttext = `
  Core.Type_anylist arglist = Core.e_anylist;
  Core.Type_context context = ` + pkgpath + `.` + LangNameFFromFunc(lang, contextfunc) + `(arglist);`
			}
		}
	}
	tests := ""
	listpackage := project.listpackage
	var listtestpackage []string
	for _, pkg := range listpackage {
		iscontinue := true
		if command.filter == "" {
		} else if !BooleanFromStringStarts(command.filter, pkg.name) {
			iscontinue = false
		}
		if iscontinue {
			pkgname := pkg.name
			if pkg.name != "" {
				imports += LangImportTest(lang, project, pkgname, imports)
				pos := strings.LastIndex(pkgname, "/")
				if pos >= 0 {
					pkgname = pkgname[pos+1:]
				}
				pkgname = StringUCaseFirst(pkgname)
				testpackage := "\n    " + pkgname + "Test.test_package(context)"
				listtestpackage = append(listtestpackage, testpackage)
				tests += `
  @Test
  @DisplayName("` + pkg.name + `")
  void test_` + StringFromStringFindReplace(pkg.name, "/", "_") + `() {
	  com.vxlisp.vx.Test.Type_testpackage testpackage = ` + pkgname + `Test.test_package(context);
	  TestLib.run_testpackage_async(testpackage);
  }

`
			}
		}
	}
	testpackages := StringFromListStringJoin(listtestpackage, ",")
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "AppTest")
	output := `
` + imports + `
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * Unit test for whole App.
 */` +
		namespaceopen +
		contexttext + `
` + tests + `
  @Test
  @DisplayName("writetestsuite")
  void test_writetestsuite() {
    com.vxlisp.vx.Test.Type_testpackagelist testpackagelist = com.vxlisp.vx.Test.t_testpackagelist.vx_new(` +
		testpackages +
		`
    );
    TestLib.write_testpackagelist_async(context, testpackagelist);
  }` +
		namespaceclose
	return output
}

func LangTestLib(lang *vxlang) string {
	output := ""
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, "TestLib")
	switch lang.name {
	case "java":
		output = `
import java.util.*;
import java.util.concurrent.CompletableFuture;
import static org.junit.jupiter.api.Assertions.*;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.File;
import com.vxlisp.vx.Test;
import com.vxlisp.vx.web.Html;
` + namespaceopen + `
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
    Core.Type_any work = Core.vx_sync_from_async(Test.t_testcase, async_testcase);
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
    Test.Type_testdescribe testdescribe_resolved = Core.vx_sync_from_async(Test.t_testdescribe, async_testdescribe);
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

  public static boolean run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    boolean output = true;
    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();
    for (Test.Type_testpackage testpackage : listtestpackage) {
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
    Test.Type_testpackage testpackage_resolved = Core.vx_sync_from_async(Test.t_testpackage, async_testpackage);
    return run_testpackage(testpackage_resolved);
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  public static boolean run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = Core.vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
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
    Test.Type_testresult testresult_resolved = Core.vx_sync_from_async(Test.t_testresult, async_testresult);
    return run_testresult(testpkg, testname, message, testresult_resolved);
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  public static boolean write_testpackagelist_async(final Core.Type_context context, final Test.Type_testpackagelist testpackagelist) {
    boolean output = false;
    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);
    Test.Type_testpackagelist testpackagelist_resolved = Core.vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);
    File.Type_file filetest = Test.f_file_test();
    Core.Type_boolean valboolean = File.f_boolean_write_from_file_any(context, filetest, testpackagelist_resolved);
    output = valboolean.vx_boolean();
    Html.Type_div divtest = Test.f_div_from_testpackagelist(testpackagelist_resolved);
    Html.Type_html htmlnode = Test.f_html_from_divtest(divtest);
    File.Type_file filenode = Test.f_file_testnode();
    valboolean = File.f_boolean_write_from_file_any(context, filenode, htmlnode);
    output = output && valboolean.vx_boolean();
    File.Type_file filehtml = Test.f_file_testhtml();
    Core.Type_string shtml = Html.f_string_from_html(htmlnode);
    valboolean = File.f_boolean_write_from_file_string(context, filehtml, shtml);
    output = output && valboolean.vx_boolean();
    return output;
  }
` +
			namespaceclose
	}
	return output
}
