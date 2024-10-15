package vxlisp

import (
	"strings"
)

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
	output.future = "Async"
	output.indent = "  "
	output.lineend = ";"
	output.typeref = "->"
	output.memmanage = true
	return output
}

func NewLangCsharp() *vxlang {
	output := new(vxlang)
	output.name = "csharp"
	output.sourcename = "Core"
	output.sourcefile = ".cs"
	output.pkgpath = "Vx.Core"
	output.pkgname = "Vx.Core"
	output.pkgref = "."
	output.future = "Task"
	output.indent = "  "
	output.lineend = ";"
	output.itfext = ":"
	output.classext = ":"
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
	output.future = "CompletableFuture"
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
	output.future = "CompletableFuture"
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

func LangSpecificAsTypeText(
	lang *vxlang,
	svar string,
	stype string) string {
	output := ""
	switch lang {
	case langcsharp:
		switch stype {
		case "bool":
			output = "(bool)" + svar
		case "float":
			output = "(float)" + svar
		case "int":
			output = "Convert.ToInt32(" + svar + ")"
		default:
			output = "(" + stype + ")" + svar
		}
	case langjava:
		output = "(" + stype + ")" + svar
	case langkotlin:
		output = svar + " as " + stype
	}
	return output
}

func LangSpecificConstClassHeader(
	lang *vxlang,
	cnst *vxconst,
	indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	constname := "Const_" + LangFromName(cnst.alias)
	switch lang {
	case langcsharp:
		output = lineindent + "public class " + constname + " {"
	case langjava:
		output = lineindent + "public static class " + constname + " {"
	case langkotlin:
		output = "" +
			lineindent + "class " + constname + " {" +
			lineindent + "  constructor() {}"
	}
	return output
}

func LangSpecificFinalVar(
	lang *vxlang) string {
	var output = ""
	switch lang {
	case langjava:
		output = "final "
	}
	return output
}

func LangSpecificForListHeader(
	lang *vxlang,
	forvar string,
	typ *vxtype,
	listvar string,
	indent int) string {
	sindent := "\n" + StringRepeat("  ", indent)
	output := ""
	switch lang {
	case langcsharp:
		output = sindent + "foreach (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " in " + listvar + ") {"
	case langjava:
		output = sindent + "for (" + LangNameTypeFullFromType(lang, typ) + " " + forvar + " : " + listvar + ") {"
	case langkotlin:
		output = sindent + "for (" + forvar + " : " + LangNameTypeFullFromType(lang, typ) + " in " + listvar + ") {"
	}
	return output
}

func LangSpecificFuncInterface(
	lang *vxlang,
	fnc *vxfunc,
	extends string,
	interfaces string,
	indent int) string {
	output := ""
	funcname := LangFuncName(fnc)
	lineindent := LangIndent(lang, indent, true)
	switch lang {
	case langcsharp:
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "public interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	case langjava:
		if extends != "" {
			extends = " extends " + extends
		}
		output = lineindent + "public interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	case langkotlin:
		if extends != "" {
			extends = " : " + extends
		}
		output = lineindent + "interface Func_" + funcname + extends + " {" +
			interfaces +
			lineindent + "}\n"
	}
	return output
}

func LangSpecificFuncOverride(
	lang *vxlang,
	fnc *vxfunc,
	sindent string) (string, string, string) {
	override1 := ""
	override2 := ""
	override3 := ""
	if fnc.isoverride {
		switch lang {
		case langcsharp:
			override3 = "override "
		case langjava:
			override1 = sindent + "@Override"
		case langkotlin:
			override2 = "override "
		}
	}
	if fnc.isimplement {
		switch lang {
		case langjava:
			override1 = sindent + "@Override"
		case langkotlin:
			override2 = "override "
		}
	}
	if fnc.isimplement2 {
		switch lang {
		case langcsharp:
			override3 = sindent + "new "
		}
	}
	return override1, override2, override3
}

func LangSpecificFromText(
	lang *vxlang,
	text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	switch lang {
	case langkotlin:
		output = strings.ReplaceAll(output, "$", "\\$")
	}
	return output
}

func LangSpecificFuncClassHeader(
	lang *vxlang,
	fnc *vxfunc,
	indent int) string {
	output := ""
	lineindent := LangIndent(lang, indent, true)
	funcname := LangFuncName(fnc)
	extends := LangPkgNameDot(lang, "vx/core") + "Class_base"
	switch lang {
	case langcsharp:
		output = lineindent + "public class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {"
	case langjava:
		output = lineindent + "public static class Class_" + funcname + " extends " + extends + " implements Func_" + funcname + " {"
	case langkotlin:
		output = "" +
			lineindent + "class Class_" + funcname + " : " + extends + ", Func_" + funcname + " {" +
			lineindent + "  constructor() {}"
	}
	return output
}

func LangSpecificNamespaceFromPackage(
	lang *vxlang,
	pkgname string) (string, string) {
	namespaceopen := ""
	namespaceclose := ""
	switch lang {
	case langcpp:
		namespaceopen = "\nnamespace " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case langcsharp:
		ipos := IntFromStringFindLast(pkgname, ".")
		after := StringSubstring(pkgname, ipos+1, len(pkgname))
		namespaceopen = "\npublic static class " + after + " {\n\n"
		namespaceclose = "\n}\n"
	case langjava:
		namespaceopen = "\npublic final class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case langjs:
		namespaceopen = "\nexport default class " + pkgname + " {\n\n"
		namespaceclose = "\n}\n"
	case langkotlin:
		namespaceopen = "" +
			"\nobject " + pkgname + " {" +
			"\n" +
			"\n"
		namespaceclose = "\n}\n"
	}
	return namespaceopen, namespaceclose
}

func LangSpecificPackageLine(
	lang *vxlang,
	pkgname string,
	pkgpath string) string {
	output := ""
	switch lang {
	case langcsharp:
		ipos := IntFromStringFindLast(pkgname, "/")
		csnamespace := StringSubstring(pkgname, 0, ipos)
		csnamespace = StringFromStringFindReplace(csnamespace, "/", ".")
		csnamespace = StringUCaseFirstFromStringDelim(csnamespace, ".")
		output = "namespace " + csnamespace + lang.lineend + "\n"
	case langjava, langkotlin:
		output = "package " + pkgpath + lang.lineend + "\n"
	}
	return output
}

func LangSpecificTestImport(
	lang *vxlang,
	pkg *vxpackage,
	imports string) string {
	project := pkg.project
	pkgname := pkg.name
	output := ""
	importline := ""
	switch lang {
	case langcpp:
		importline = "#include \"" + pkgname + "test.hpp\""
	case langcsharp:
		importline = "using Xunit" + lang.lineend
	case langjava:
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		name := StringSubstring(pkgname, ipos+1, len(pkgname))
		name = StringUCaseFirst(name)
		importname := project.javadomain + "." + path + "." + name + "Test"
		importline = "import " + importname + lang.lineend
	case langkotlin:
		ipos := IntFromStringFindLast(pkgname, "/")
		path := StringSubstring(pkgname, 0, ipos)
		path = StringFromStringFindReplace(path, "/", ".")
		importname := project.javadomain + "." + path + ".*"
		importline = "import " + importname + lang.lineend
	}
	if !BooleanFromStringContains(imports, importline) {
		output = importline + "\n"
	}
	return output
}

func LangSpecificTestLib(
	lang *vxlang,
	namespaceopen string,
	namespaceclose string,
	commontests string,
	spath string) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"using Xunit;" +
			"\n" +
			"\nnamespace AppTest;" +
			"\n" +
			namespaceopen +
			"\n  public class TestOutputWriter : TextWriter {" +
			"\n" +
			"\n    private readonly Xunit.Abstractions.ITestOutputHelper _output;" +
			"\n" +
			"\n    public TestOutputWriter(Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n      _output = output;" +
			"\n    }" +
			"\n" +
			"\n    public override System.Text.Encoding Encoding => System.Text.Encoding.UTF8;" +
			"\n" +
			"\n			 public override void WriteLine(int message) {" +
			"\n				  _output.WriteLine(\"\" + message);" +
			"\n  		}" +
			"\n" +
			"\n  		public override void WriteLine(string? message) {" +
			"\n  				_output.WriteLine(message);" +
			"\n  		}" +
			"\n" +
			"\n  }" +
			"\n" +
			"\n  public static bool EnableConsole(" +
			"\n    Xunit.Abstractions.ITestOutputHelper output) {" +
			"\n    TestOutputWriter converter = new TestOutputWriter(output);" +
			"\n    System.Console.SetOut(converter);" +
			"\n    return true;" +
			"\n  }" +
			"\n" +
			"\n  public static string spath = " + spath + ";" +
			"\n" +
			commontests +
			namespaceclose
	case langjava:
		output = "" +
			"import java.util.*;" +
			"\nimport java.util.concurrent.CompletableFuture;" +
			"\nimport static org.junit.jupiter.api.Assertions.*;" +
			"\nimport com.vxlisp.vx.*;" +
			"\nimport com.vxlisp.vx.data.File;" +
			"\nimport com.vxlisp.vx.Test;" +
			"\nimport com.vxlisp.vx.web.Html;" +
			"\n" +
			namespaceopen +
			"\n  public static String spath = " + spath + ";" +
			"\n" +
			commontests +
			"\n" +
			"\n  // Blocking" +
			"\n  // Only use if running a single testdescribe" +
			"\n  public static " + LangTypeName(lang, rawbooltype) +
			" run_testdescribe_async(final " + LangTypeName(lang, rawstringtype) + " testpkg, final " + LangTypeName(lang, rawstringtype) + " casename, final Test.Type_testdescribe testdescribe) {" +
			"\n    " + lang.future + "<Test.Type_testdescribe> async_testdescribe = Test.f_resolve_testdescribe(testdescribe);" +
			"\n    Test.Type_testdescribe testdescribe_resolved = " + LangPkgNameDot(lang, "vx/core") + "vx_sync_from_async(Test.t_testdescribe, async_testdescribe);" +
			"\n    return run_testdescribe(testpkg, casename, testdescribe_resolved);" +
			"\n  }" +
			"\n" +
			"\n  public static " + LangTypeName(lang, rawbooltype) + " run_testpackagelist(final Test.Type_testpackagelist testpackagelist) {" +
			"\n    " + LangTypeName(lang, rawbooltype) + " output = true;" +
			"\n    List<Test.Type_testpackage> listtestpackage = testpackagelist.vx_listtestpackage();" +
			"\n    for (Test.Type_testpackage testpackage : listtestpackage) {" +
			"\n      " + LangTypeName(lang, rawbooltype) + " testoutput = run_testpackage(testpackage);" +
			"\n      if (!testoutput) {" +
			"\n        output = false;" +
			"\n      }" +
			"\n    }" +
			"\n    return output;" +
			"\n  }" +
			"\n" +
			"\n  // Blocking" +
			"\n  // This is the preferred way of calling testsuite (1 block per testsuite)" +
			"\n  public static " + LangTypeName(lang, rawbooltype) + " run_testpackagelist_async(final Test.Type_testpackagelist testpackagelist) {" +
			"\n    CompletableFuture<Test.Type_testpackagelist> async_testpackagelist = Test.f_resolve_testpackagelist(testpackagelist);" +
			"\n    Test.Type_testpackagelist testpackagelist_resolved = " + LangPkgNameDot(lang, "vx/core") + "vx_sync_from_async(Test.t_testpackagelist, async_testpackagelist);" +
			"\n    return run_testpackagelist(testpackagelist_resolved);" +
			"\n  }" +
			"\n" +
			"\n  // Blocking" +
			"\n  public static " + LangTypeName(lang, rawbooltype) + " run_testresult_async(final " + LangTypeName(lang, rawstringtype) + " testpkg, final " + LangTypeName(lang, rawstringtype) + " testname, final " + LangTypeName(lang, rawstringtype) + " message, Test.Type_testresult testresult) {" +
			"\n    " + lang.future + "<Test.Type_testresult> async_testresult = Test.f_resolve_testresult(testresult);" +
			"\n    Test.Type_testresult testresult_resolved = " + LangPkgNameDot(lang, "vx/core") + "vx_sync_from_async(Test.t_testresult, async_testresult);" +
			"\n    return run_testresult(testpkg, testname, message, testresult_resolved);" +
			"\n  }" +
			"\n" +
			namespaceclose
	case langkotlin:
		output = "" +
			"import java.util.*" +
			"\nimport java.util.concurrent.CompletableFuture" +
			"\nimport org.junit.jupiter.api.Assertions.*" +
			"\nimport com.vxlisp.vx.*" +
			"\nimport com.vxlisp.vx.data.*" +
			"\nimport com.vxlisp.vx.web.*" +
			"\n" +
			namespaceopen +
			"\n  val spath : String = " + spath +
			"\n" +
			commontests +
			namespaceclose

	}
	return output
}

func LangSpecificTestPackage(
	lang *vxlang,
	pkg *vxpackage,
	testpackagetype *vxtype) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "" +
			"\n  [Fact]" +
			"\n  public void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			LangVar(lang, "testpackage", testpackagetype, 2,
				"Test"+
					LangPkgName(lang, pkg.name)+
					"Test.test_package(context)") +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langjava:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"" + pkg.name + "\")" +
			"\n  void test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() {" +
			"\n    com.vxlisp.vx.Test.Type_testpackage testpackage = " + LangPkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	case langkotlin:
		output = "" +
			"\n  @Test" +
			"\n  @DisplayName(\"" + pkg.name + "\")" +
			"\n  fun test_" + StringFromStringFindReplace(pkg.name, "/", "_") + "() : Unit {" +
			"\n    val testpackage : vx_test.Type_testpackage = " + LangPkgName(lang, pkg.name) + "Test.test_package(context)" + lang.lineend +
			"\n    TestLib.run_testpackage_async(testpackage)" + lang.lineend +
			"\n  }" +
			"\n"
	}
	return output
}

func LangSpecificTestPackagePrefix(
	lang *vxlang) string {
	output := ""
	switch lang {
	case langcsharp:
		output = "Test"
	}
	return output
}

func LangSpecificTypeClassHeader(
	lang *vxlang,
	typ *vxtype,
	indent int) string {
	output := ""
	lineindent := LangIndent(
		lang, indent, true)
	typename := LangFromName(typ.alias)
	switch lang {
	case langcsharp:
		output = lineindent + "public class Class_" + typename + " : " + LangPkgNameDot(lang, "vx/core") + "Class_base, Type_" + LangNameFromType(lang, typ) + " {"
	case langjava:
		output = lineindent + "public static class Class_" + typename + " extends " + LangPkgNameDot(lang, "vx/core") + "Class_base implements Type_" + LangNameFromType(lang, typ) + " {"
	case langkotlin:
		output = "" +
			lineindent + "class Class_" + typename + " : " + LangPkgNameDot(lang, "vx/core") + "Class_base, Type_" + LangNameFromType(lang, typ) + " {" +
			lineindent + "  constructor() {}"
	}
	return output
}

func LangSpecificTypeInterfaceBasics(
	lang *vxlang,
	typ *vxtype) bool {
	output := true
	switch lang {
	case langcsharp, langjava, langkotlin:
		switch NameFromType(typ) {
		case "vx/core/any":
		default:
			output = false
		}
	}
	return output
}

func LangSpecificTypeInterfaceHeader(
	lang *vxlang,
	typ *vxtype,
	extendtypes []*vxtype,
	indent int,
	body string) string {
	lineindent := LangIndent(lang, indent, true)
	output := ""
	extendtext := ""
	var extendtexts []string
	for _, extendtype := range extendtypes {
		extendpart := LangTypeName(lang, extendtype)
		extendtexts = append(extendtexts, extendpart)
	}
	extendtext = StringFromListStringJoin(extendtexts, ", ")
	switch lang {
	case langcsharp:
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {" +
			body +
			lineindent + "}\n"
	case langjava:
		if extendtext != "" {
			extendtext = " extends " + extendtext
		}
		output = lineindent + "public interface Type_" + LangNameFromType(lang, typ) + extendtext + " {" +
			body +
			lineindent + "}\n"
	case langkotlin:
		if extendtext != "" {
			extendtext = " : " + extendtext
		}
		output = lineindent + "interface Type_" + LangNameFromType(lang, typ) + extendtext + " {" +
			body +
			lineindent + "}\n"
	}
	return output
}

func LangSpecificTypeNameSimple(
	lang *vxlang,
	typ *vxtype,
	simple bool) string {
	name := ""
	alias := typ.alias
	switch typ {
	case rawbooltype:
		switch lang {
		case langcsharp:
			name = "bool"
		case langjava:
			name = "boolean"
		case langkotlin:
			name = "Boolean"
		}
	case rawbooleantype:
		switch lang {
		case langcsharp:
			name = "bool"
		case langjava:
			name = "Boolean"
		case langkotlin:
			name = "Boolean"
		}
	case rawfloattype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "Float"
		}
	case rawifntype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "IFn"
		}
	case rawinttype:
		switch lang {
		case langcsharp, langjava:
			name = "int"
		case langkotlin:
			name = "Int"
		}
	case rawintegertype:
		switch lang {
		case langcsharp, langjava:
			name = "Integer"
		case langkotlin:
			name = "Int"
		}
	case rawlisttype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "List"
		}
	case rawlistanytype:
		switch lang {
		case langcsharp, langjava, langkotlin:
			name = "List<" + LangSpecificTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawlistunknowntype:
		switch lang {
		case langcsharp:
			name = "List<object>"
		case langjava:
			name = "List<?>"
		case langkotlin:
			name = "List<*>"
		}
	case rawmaptype:
		switch lang {
		case langcsharp:
			name = "Vx.Core.Map"
		case langjava, langkotlin:
			name = "Map"
		}
	case rawmapanytype:
		switch lang {
		case langcpp:
			name = "std::map<string, " + LangSpecificTypeNameSimple(lang, anytype, true) + ">"
		case langcsharp:
			name = "Vx.Core.Map<string, " + LangSpecificTypeNameSimple(lang, anytype, true) + ">"
		case langjava, langkotlin:
			name = "Map<String, " + LangSpecificTypeNameSimple(lang, anytype, true) + ">"
		}
	case rawstringtype:
		switch lang {
		case langcpp:
			name = "std::string"
		case langcsharp:
			name = "string"
		default:
			name = "String"
		}
	case rawobjecttype:
		switch lang {
		case langcsharp:
			name = "object"
		case langjava:
			name = "Object"
		case langkotlin:
			name = "Any"
		}
	case rawvoidtype:
		switch lang {
		case langkotlin:
			name = "Unit"
		default:
			name = "void"
		}
	default:
		if typ.isfunc {
			name = LangFuncName(typ.vxfunc)
		} else if alias == "" {
			name = LangFromName(typ.name)
		} else if typ.isgeneric {
			if simple {
				if BooleanFromStringStarts(alias, "generic-") {
					alias = StringFromStringFindReplace(alias, "generic-", "")
					ipos := IntFromStringFindLast(alias, "-")
					alias = alias[0:ipos]
				}
			} else {
				alias = LangGenericFromType(lang, typ)
			}
			name = LangFromName(alias)
		} else {
			name = LangFromName(alias)
		}
	}
	return name
}

func LangSpecificVxListAdd(
	lang *vxlang,
	varname string,
	indent int,
	value string) string {
	output := ""
	sindent := "\n" + StringRepeat("  ", indent)
	switch lang {
	case langcsharp:
		output = sindent + varname + ".Add(" + value + ")" + lang.lineend
	default:
		output = sindent + varname + ".add(" + value + ")" + lang.lineend
	}
	return output
}
