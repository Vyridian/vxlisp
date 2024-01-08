package vxlisp

import (
	"sort"
	"strings"
)

func JsDocFromFunc(fnc *vxfunc) string {
	var doc = ""
	var argsdoc = ""
	switch NameFromFunc(fnc) {
	case "vx/core/new", "vx/core/copy", "vx/core/empty":
	default:
		if fnc.vxtype.isgeneric || fnc.generictype != nil {
			argsdoc += "\n@param  {typemap} generic"
		}
	}
	for _, arg := range fnc.listarg {
		argsdoc += "\n@param "
		if arg.vxtype.name != "" {
			argsdoc += " {" + JsFromName(arg.vxtype.alias) + "}"
		}
		if arg.multi {
			argsdoc += " ..."
		}
		argsdoc += " " + JsFromName(arg.alias)
		if arg.doc != "" {
			argsdoc += " " + arg.doc
		}
	}
	if fnc.async {
		doc += "\n@async "
	}
	doc += "@function " + JsFromName(fnc.alias)
	if fnc.doc != "" {
		doc += "\n" + fnc.doc
	}
	if fnc.deprecated != "" {
		doc += "\n" + fnc.deprecated
	}
	doc += "" +
		argsdoc +
		"\n@return {" + fnc.vxtype.name + "}"
	return doc
}

func JsEmptyValueFromType(typ *vxtype) string {
	return JsEmptyValueFromTypeIndent(typ, "  ")
}

func JsEmptyValueFromTypeIndent(typ *vxtype, indent string) string {
	output := "\"\""
	if len(indent) < 10 {
		output = typ.defaultvalue
		switch typ.extends {
		case "string":
			output = "\"" + output + "\""
		case ":list":
			output = "vx_core.f_type_to_list(" + JsFromName(typ.pkgname) + ".t_" + typ.name + ")"
		default:
			properties := ListPropertyTraitFromType(typ)
			if len(properties) > 0 {
				var proptexts []string
				for _, property := range properties {
					propdefault := JsEmptyValueFromTypeIndent(property.vxtype, indent+"  ")
					if propdefault != "\"\"" {
						proptext := "\"" + property.name + "\": " + propdefault
						if property.doc != "" {
							proptext += " // " + property.doc
						}
						proptexts = append(proptexts, proptext)
					}
				}
				output = "" +
					"{" +
					"\n" + indent + "    " + StringFromListStringJoin(proptexts, ",\n"+indent+"    ") +
					"\n" + indent + "  }"
			} else if output == "" || strings.HasPrefix(output, ":") {
				output = "\"" + output + "\""
				//			if !strings.HasPrefix(defaultvalue, "\"") {
				//				defaultvalue = "\"" + defaultvalue + "\""
				//			}
			}
		}
	}
	return output
}

func JsFilesFromProjectCmd(lang *vxlang, project *vxproject, command *vxcommand) ([]*vxfile, *vxmsgblock) {
	msgblock := NewMsgBlock("JsFilesFromProjectCmd")
	var files []*vxfile
	cmdpath := PathFromProjectCmd(project, command)
	switch command.code {
	case ":source":
		file := NewFile()
		file.name = "app.js"
		file.path = cmdpath
		file.text = JsApp(project, command)
		files = append(files, file)
	case ":test":
		file := NewFile()
		file.name = "app_test.js"
		file.path = cmdpath
		file.text = JsAppTest(project, command)
		files = append(files, file)
	}
	pkgs := project.listpackage
	for _, pkg := range pkgs {
		pkgname := pkg.name
		pkgpath := ""
		pos := strings.LastIndex(pkgname, "/")
		if pos >= 0 {
			pkgpath = pkgname[0:pos]
			pkgname = pkgname[pos+1:]
		}
		switch command.code {
		case ":source":
			jstext, msgs := JsFromPackage(lang, pkg, project)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + ".js"
			file.path = cmdpath + "/" + pkgpath
			file.text = jstext
			files = append(files, file)
		case ":test":
			jstext, msgs := JsTestFromPackage(lang, pkg, project, command)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			file := NewFile()
			file.name = pkgname + "_test.js"
			file.path = cmdpath + "/" + pkgpath
			file.text = jstext
			files = append(files, file)
		}
	}
	return files, msgblock
}

func JsFromArg(arg vxarg, indent string) string {
	output := "{}"
	if arg.name != "" {
		var props []string
		key := arg.name
		typ := JsNameTFromType(arg.vxtype)
		props = append(props, "\"name\" : \""+key+"\"")
		props = append(props, "\"type\" : "+typ)
		props = append(props, "\"multi\": "+StringFromBoolean(arg.multi))
		output = "{" +
			"\n" + indent + "  " +
			StringFromListStringJoin(props, ",\n"+indent+"  ") +
			"\n" + indent + "}"
	}
	return output
}

func JsFromArgs(args []vxarg, indent string) string {
	var output = "{"
	if len(args) > 0 {
		var props []string
		for _, arg := range args {
			key := arg.name
			argtext := JsFromArg(arg, indent+"  ")
			props = append(props, "\""+key+"\": "+argtext)
		}
		output += "" +
			"\n" + indent + "  " +
			StringFromListStringJoin(props, ",\n"+indent+"  ") +
			"\n" + indent
	}
	output += "}"
	return output
}

func JsFromConst(lang *vxlang, cnst *vxconst, pkg *vxpackage) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsFromConst")
	path := cnst.pkgname + "/" + cnst.name
	doc := ""
	doc += "Constant: " + cnst.name + "\n"
	if cnst.doc != "" {
		doc += cnst.doc + "\n"
	}
	if cnst.deprecated != "" {
		doc += cnst.deprecated + "\n"
	}
	cnsttype := cnst.vxtype
	var properties []string
	doc += "{" + cnsttype.name + "}"
	pkgname := JsFromName(cnst.pkgname)
	cnstname := JsFromName(cnst.alias)
	startval := ""
	var value = ""
	if cnst.value.code == "" {
		value = JsEmptyValueFromType(cnsttype)
	} else {
		clstextjs, msgs := JsFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 2, true, false, path)
		value = clstextjs
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	propertyprefix := pkgname + ".c_" + cnstname
	switch NameFromType(cnsttype) {
	case "vx/core/boolean":
		startval = value
	case "vx/core/float", "vx/core/int":
		startval = value
	case "vx/core/string":
		startval = value
	default:
		startval = "{vx_type: " + JsNameTFromType(cnsttype) + ", vx_constdef: {pkgname: '" + cnst.pkgname + "', name: '" + cnst.name + "'}}"
		switch cnst.vxtype.extends {
		case ":list":
			startval = "Object.assign([], " + startval + ")"
		}
		if value != "\"\"" {
			properties = append(properties, "Object.assign("+propertyprefix+", "+value+")")
		}
	}
	output := "" +
		"  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  static c_" + cnstname + " = " + startval +
		"\n" +
		"\n"
	statics := ""
	if len(properties) > 0 {
		statics = "" +
			"\n    // (const " + cnst.name + ")" +
			"\n    " + strings.Join(properties, "\n    ") +
			"\n"
	}
	return output, statics, msgblock
}

func JsFromFunc(lang *vxlang, fnc *vxfunc) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsFromFunc")
	var args []string
	funcname := NameFromFunc(fnc)
	path := funcname + JsIndexFromFunc(fnc)
	genericvars := ""
	switch funcname {
	case "vx/core/new", "vx/core/copy", "vx/core/empty":
	default:
		if fnc.vxtype.isgeneric || fnc.generictype != nil {
			args = append(args, "generic")
			keys := ListKeyFromMapType(fnc.mapgeneric)
			for _, key := range keys {
				genericvars += "" +
					"\n    const generic_" + JsFromName(key) + " = generic[\"" + key + "\"]"
			}
		}
	}
	if fnc.context {
		args = append(args, "context")
	}
	for _, arg := range fnc.listarg {
		argname := JsFromName(arg.alias)
		if arg.multi {
			args = append(args, "..."+argname)
		} else {
			args = append(args, argname)
		}
	}
	doc := JsDocFromFunc(fnc)
	indent := 2
	footer := ""
	jsfuncname := JsFromName(fnc.alias) + JsIndexFromFunc(fnc)
	var properties []string
	properties = append(properties, "name          : \""+fnc.name+"\"")
	properties = append(properties, "pkgname       : \""+fnc.pkgname+"\"")
	properties = append(properties, "extends       : \":func\"")
	properties = append(properties, "idx           : "+StringFromInt(fnc.idx))
	properties = append(properties, "allowfuncs    : []")
	properties = append(properties, "disallowfuncs : []")
	properties = append(properties, "allowtypes    : []")
	properties = append(properties, "disallowtypes : []")
	properties = append(properties, "allowvalues   : []")
	properties = append(properties, "disallowvalues: []")
	properties = append(properties, "traits        : []")
	properties = append(properties, "properties    : []")
	properties = append(properties, "proplast      : {}")
	properties = append(properties, "fn            : "+JsFromName(fnc.pkgname)+".f_"+jsfuncname)
	proptext := ""
	if len(properties) > 0 {
		proptext = "\n      " + strings.Join(properties, ",\n      ")
	}
	jstname := JsFromName(fnc.pkgname) + ".t_" + jsfuncname
	statics := "" +
		"\n    // (func " + fnc.name + ")" +
		"\n    " + jstname + "['vx_type'] = vx_core.t_type" +
		"\n    " + jstname + "['vx_value'] = {" +
		proptext +
		"\n    }" +
		"\n"
	sindent := StringRepeat("  ", indent)
	lineindent := "\n" + sindent
	if fnc.vxtype.name != "none" {
		footer += lineindent + "return output"
	}
	footer += "\n  }\n\n"
	header := "" +
		"\n  // (func " + fnc.name + ")" +
		"\n  static "
	if fnc.async {
		header += "async "
	}
	header += "f_" + jsfuncname + "(" + strings.Join(args, ", ") + ") {"
	logheader := ""
	logfooter := ""
	if fnc.debug {
		logheader += lineindent + "console.log(\"" + fnc.name + "\", \"start\""
		for _, arg := range fnc.listarg {
			logheader += ", \"" + arg.name + "=\", " + arg.alias
		}
		logheader += ")\n"
		logfooter = lineindent + "console.log(\"" + fnc.name + "\", \"end\", output)"
	}
	defaultvalue := ""
	switch funcname {
	case "vx/core/new", "vx/core/copy", "vx/core/empty":
		defaultvalue = lineindent + "let output"
	default:
		if fnc.vxtype.name == "none" {
		} else {
			if fnc.generictype != nil {
				defaultvalue = "vx_core.f_empty(generic_" + JsFromName(fnc.generictype.name) + ")"
			} else {
				defaultvalue = JsNameEFromType(fnc.vxtype)
			}
			if fnc.async {
				defaultvalue = "Promise.resolve(" + defaultvalue + ")"
			}
			defaultvalue = lineindent + "let output = " + defaultvalue
		}
		for _, arg := range fnc.listarg {
			if arg.multi {
				defaultvalue += lineindent + arg.alias + " = vx_core.f_new(" + JsNameTFromType(arg.vxtype) + ", ..." + arg.alias + ")"
			}
		}
	}
	tryheader := ""
	tryfooter := ""
	if fnc.messages {
		tryheader += lineindent + "try {"
		tryfooter = "" +
			lineindent + "} catch (err) {" +
			lineindent + "  console.log(err)" +
			lineindent + "}"
		indent += 1
	}
	valuetext, msgs := JsFromValue(lang, fnc.value, fnc.pkgname, fnc, indent, true, false, path)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	if strings.Index(valuetext, "output ") > 0 {
	} else if strings.Index(valuetext, "output.") > 0 {
	} else if fnc.vxtype.name == "none" {
	} else if valuetext == "" {
	} else {
		valuetext = "output = " + valuetext
	}
	body := ""
	if valuetext != "" {
		body = "" +
			"\n" + sindent + valuetext
	}
	output := "" +
		"  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  static t_" + jsfuncname + " = {}" +
		"\n  static e_" + jsfuncname + " = {vx_type: " + JsFromName(fnc.pkgname) + ".t_" + jsfuncname + "}" +
		"\n" +
		header +
		logheader +
		genericvars +
		defaultvalue +
		tryheader +
		body +
		tryfooter +
		logfooter +
		footer
	return output, statics, msgblock
}

func JsFromName(name string) string {
	output := name
	output = StringFromStringFindReplace(output, "->", "_to_")
	output = StringFromStringFindReplace(output, "<-", "_from_")
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func JsFromPackage(lang *vxlang, pkg *vxpackage, prj *vxproject) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsFromPackage")
	imports := ""
	if len(pkg.listlib) > 0 {
		depth := IntCountFromStringFind(pkg.name, "/")
		prefix := StringRepeat("../", depth)
		for _, lib := range pkg.listlib {
			isskip := false
			if lib.name == "vx/test" {
				isskip = true
			} else if lib.lang != "" {
				if lib.lang == ":js" {
				} else {
					isskip = true
				}
			}
			if !isskip {
				libpath := prefix + lib.path + ".js"
				imports += "\nimport " + JsFromName(lib.path) + " from \"" + libpath + "\""
			}
		}
		imports += "\n"
	}
	allempty := ""
	emptytypes := ""
	pkgname := JsFromName(pkg.name)
	specialcode := prj.mapnative[pkg.name+"_js.txt"]
	statics := ""
	constkeys := ListKeyFromMapConst(pkg.mapconst)
	var constvalues []string
	for _, constid := range constkeys {
		cnst := pkg.mapconst[constid]
		constname := JsFromName(cnst.alias)
		constvalue := "\"" + cnst.name + "\": " + pkgname + ".c_" + constname
		constvalues = append(constvalues, constvalue)
	}
	typkeys := ListKeyFromMapType(pkg.maptype)
	alltypes := ""
	var emptyvalues []string
	var typevalues []string
	for _, typid := range typkeys {
		typ := pkg.maptype[typid]
		typetext, statictext, msgs := JsFromType(typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		alltypes += typetext
		statics += statictext
		typename := JsFromName(typ.alias)
		typeval := ""
		switch typid {
		case "boolean":
			typeval = "false"
		case "float", "int":
			typeval = "0"
		case "string":
			typeval = "''"
		default:
			if typ.extends == ":list" {
				typeval = "[]"
				statics += "" +
					"\n    " + pkgname + ".e_" + typename + "['vx_type'] = " + pkgname + ".t_" + typename +
					"\n"
			} else {
				typeval = "{}"
				statics += "" +
					"\n    " + pkgname + ".e_" + typename + "['vx_type'] = " + pkgname + ".t_" + typename +
					"\n    " + pkgname + ".e_" + typename + "['vx_value'] = {}" +
					"\n"
			}
		}
		emptytypes += "" +
			"\n  static e_" + typename + " = " + typeval
		emptyvalue := "\"" + typ.name + "\": " + pkgname + ".e_" + typename
		emptyvalues = append(emptyvalues, emptyvalue)
		typevalue := "\"" + typ.name + "\": " + pkgname + ".t_" + typename
		typevalues = append(typevalues, typevalue)
	}
	var funcvalues []string
	funckeys := ListKeyFromMapFunc(pkg.mapfunc)
	for _, fncid := range funckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			jsfuncname := JsFromName(fnc.alias) + JsIndexFromFunc(fnc)
			emptyvalue := "\"" + fnc.name + StringIndexFromFunc(fnc) + "\": " + pkgname + ".e_" + jsfuncname
			emptyvalues = append(emptyvalues, emptyvalue)
			funcvalue := "\"" + fnc.name + StringIndexFromFunc(fnc) + "\": " + pkgname + ".t_" + jsfuncname
			funcvalues = append(funcvalues, funcvalue)
		}
	}
	pkgdef := "" +
		"\n    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {" +
		"\n      " + StringFromListStringJoin(constvalues, ",\n      ") +
		"\n    })" +
		"\n    const emptymap = vx_core.vx_new_map(vx_core.t_map, {" +
		"\n      " + StringFromListStringJoin(emptyvalues, ",\n      ") +
		"\n    })" +
		"\n    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {" +
		"\n      " + StringFromListStringJoin(funcvalues, ",\n      ") +
		"\n    })" +
		"\n    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {" +
		"\n      " + StringFromListStringJoin(typevalues, ",\n      ") +
		"\n    })" +
		"\n    const pkg = vx_core.vx_new_struct(vx_core.t_package, {" +
		"\n      \"name\": \"" + pkg.name + "\"," +
		"\n      \"constmap\": constmap," +
		"\n      \"emptymap\": emptymap," +
		"\n      \"funcmap\": funcmap," +
		"\n      \"typemap\": typemap" +
		"\n    })" +
		"\n    vx_core.vx_global_package_set(pkg)" +
		"\n"
	allempty += "" +
		"  // empty types" +
		emptytypes +
		//		"\n" +
		//		"\n  static c_empty = {" +
		//		"\n    " + StringFromListStringJoin(emptyvalues, ",\n    ") +
		//		"\n  }" +
		"\n"
	allconsts := ""
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	for _, cnstid := range cnstkeys {
		cnst := pkg.mapconst[cnstid]
		consttext, statictext, msgs := JsFromConst(lang, cnst, pkg)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		allconsts += consttext
		statics += statictext
	}
	allfuncs := ""
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	for _, fncid := range fnckeys {
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			fnctext, fncstatics, msgs := JsFromFunc(lang, fnc)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			allfuncs += fnctext
			statics += fncstatics
		}
	}
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname)
	output := "" +
		"'strict mode'" +
		"\n" + imports +
		"\n" +
		namespaceopen +
		specialcode +
		alltypes +
		allconsts +
		allfuncs +
		allempty +
		"\n" +
		"\n  static {" +
		pkgdef +
		statics +
		"\n  }" +
		namespaceclose
	return output, msgblock
}

func JsFromPackageName(name string) string {
	output := name
	if strings.HasPrefix(name, "vx/") {
		output = StringFromStringFindReplace(output, "vx/", "vx.")
	} else {
		output = "vx." + output
	}
	output = StringFromStringFindReplace(output, "<", "lt")
	output = StringFromStringFindReplace(output, ">", "gt")
	output = StringFromStringFindReplace(output, "?", "is")
	output = StringFromStringFindReplace(output, "-", "_")
	output = StringFromStringFindReplace(output, "/", "_")
	return output
}

func JsFromText(text string) string {
	var output = text
	output = strings.ReplaceAll(output, "\n", "\\n")
	output = strings.ReplaceAll(output, "\\\"", "\\\\\"")
	output = strings.ReplaceAll(output, "\"", "\\\"")
	return output
}

func JsFromType(typ *vxtype) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsFromType")
	var doc = ""
	doc += "type: " + typ.name
	if typ.doc != "" {
		doc += "\n" + typ.doc
	}
	if typ.deprecated != "" {
		doc += "\n" + typ.deprecated
	}
	listproperties := ListPropertyTraitFromType(typ)
	lastproperty := emptyarg
	if len(listproperties) > 0 {
		lastproperty = listproperties[len(listproperties)-1]
	}
	var properties []string
	properties = append(properties, "name          : \""+typ.name+"\"")
	properties = append(properties, "pkgname       : \""+typ.pkgname+"\"")
	properties = append(properties, "extends       : \""+typ.extends+"\"")
	properties = append(properties, "allowfuncs    : "+JsNamesFromListFunc(typ.allowfuncs))
	properties = append(properties, "disallowfuncs : "+JsNamesFromListFunc(typ.disallowfuncs))
	properties = append(properties, "allowtypes    : "+JsNamesTFromListType(typ.allowtypes))
	properties = append(properties, "disallowtypes : "+JsNamesTFromListType(typ.disallowtypes))
	properties = append(properties, "allowvalues   : "+JsNamesFromListValue(typ.allowvalues))
	properties = append(properties, "disallowvalues: "+JsNamesFromListValue(typ.disallowvalues))
	properties = append(properties, "traits        : "+JsNamesTFromListType(typ.traits))
	properties = append(properties, "properties    : "+JsFromArgs(listproperties, "      "))
	properties = append(properties, "proplast      : "+JsFromArg(lastproperty, "      "))
	pkgname := JsFromName(typ.pkgname)
	typename := JsFromName(typ.alias)
	proptext := ""
	if len(properties) > 0 {
		proptext = "\n      " + strings.Join(properties, ",\n      ")
	}
	statics := "" +
		"\n    // (type " + typ.name + ")" +
		"\n    " + pkgname + ".t_" + typename + "['vx_type'] = vx_core.t_type" +
		"\n    " + pkgname + ".t_" + typename + "['vx_value'] = {" +
		proptext +
		"\n    }"
	output := "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */" +
		"\n  static t_" + typename + " = {}" +
		"\n"
	return output, statics, msgblock
}

func JsFromValue(lang *vxlang, value vxvalue, pkgname string, parentfn *vxfunc, indent int, encode bool, test bool, path string) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsFromValue")
	sindent := StringRepeat("  ", indent)
	output := ""
	// constants, types, or function objects
	valstr := ""
	subpath := path + "/:value"
	switch value.code {
	case ":arg":
		valarg := ArgFromValue(value)
		valstr = JsFromName(valarg.name)
		switch parentfn.name {
		case "new", "empty":
		default:
			if valarg.multi {
				valstr = "..." + valstr
			}
		}
		output += valstr
	case ":const":
		switch value.name {
		case "false", "true":
			valstr = value.name
		default:
			if value.pkg == ":native" {
				valstr = JsFromName(value.name)
			} else {
				valconst := ConstFromValue(value)
				valstr = JsFromName(valconst.pkgname) + ".c_" + JsFromName(valconst.alias)
			}
		}
		output = sindent + valstr
	case ":func":
		fnc := FuncFromValue(value)
		subpath += "/" + fnc.name + JsIndexFromFunc(fnc)
		funcname := NameFromFunc(fnc)
		if fnc.debug {
			output += "vx_core.f_log_1({\"any-1\": " + JsNameTFromType(fnc.vxtype) + "}, \"" + funcname + "\", "
		}
		switch fnc.name {
		case "native":
			// (native :js)
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
				if valuetext == ":js" {
					isNative = true
				} else if valuetext != ":auto" && BooleanFromStringStarts(valuetext, ":") {
					isNative = false
				} else if isNative {
					if argvalue.name == "newline" {
						argtext = "\n"
					} else {
						clstextjs, msgs := JsFromValue(lang, argvalue, pkgname, parentfn, 0, false, test, subpath)
						argtext = clstextjs
						msgblock = MsgblockAddBlock(msgblock, msgs)
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
					if argtext == ":auto" {
						argtext = LangNativeAutoFromFunc(lang, parentfn)
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
			multiline := false
			multiflag := false
			if fnc.async {
				output += "await "
			}
			switch funcname {
			case "vx/core/fn":
			case "vx/core/let":
				if fnc.async {
					output += JsNameFromPkgName(fnc.pkgname) + ".f_let_async("
				} else {
					output += JsNameFromPkgName(fnc.pkgname) + ".f_let("
				}
			default:
				output += JsFromName(fnc.pkgname) + ".f_" + JsFromName(fnc.alias) + JsIndexFromFunc(fnc) + "("
			}
			switch funcname {
			case "vx/core/new", "vx/core/copy", "vx/core/empty", "vx/core/fn":
			default:
				if fnc.vxtype.isgeneric || fnc.generictype != nil {
					generictext := JsNamesTFromMapType(fnc.mapgeneric)
					argtexts = append(argtexts, generictext)
				}
			}
			if fnc.context {
				argtexts = append(argtexts, "context")
			}
			//subindent := indent + "  "
			for fncidx, funcarg := range funcargs {
				argsubpath := subpath + "/:arg/" + funcarg.name
				if fncidx == 0 && fnc.name == "fn" {
				} else {
					var argvalue = funcarg.value
					argtext := ""
					if argvalue.code == ":func" && argvalue.name == "fn" {
						argfunc := FuncFromValue(argvalue)
						var lambdaargs []string
						arglist := ListLocalArgFromFunc(argfunc)
						for _, lambdaarg := range arglist {
							lambdaargs = append(lambdaargs, lambdaarg.name)
						}
						lambdatext := strings.Join(lambdaargs, ", ")
						work, msgs := JsFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						if funcarg.vxtype.name == "any<-key-value" {
							argtext = "([" + lambdatext + "]) => " + work
						} else {
							argtext = "(" + lambdatext + ") => " + work
						}
						argtext = "vx_core.f_new(" + JsNameTFromType(funcarg.vxtype) + ", " + argtext + ")"
					} else if funcname == "vx/core/let" {
						var lambdaargs []string
						arglist := ListLocalArgFromFunc(fnc)
						switch fncidx {
						case 0:
							argtext = "[]"
						case 1:
							for _, lambdaarg := range arglist {
								lambdavaluetext, msgs := JsFromValue(lang, lambdaarg.value, pkgname, fnc, 1, true, test, argsubpath)
								msgblock = MsgblockAddBlock(msgblock, msgs)
								lambdatext := "const " + JsFromName(lambdaarg.name) + " = " + lambdavaluetext
								lambdaargs = append(lambdaargs, lambdatext)
							}
							lambdatext := strings.Join(lambdaargs, "\n  ")
							work, msgs := JsFromValue(lang, argvalue, pkgname, fnc, 1, true, test, argsubpath)
							msgblock = MsgblockAddBlock(msgblock, msgs)
							argtext = "() => {" +
								"\n  " + lambdatext +
								"\n  return " + work +
								"\n}"
							if parentfn.async {
								argtext = "async " + argtext
							}
							argtext = "vx_core.f_new(" + JsNameTFromType(funcarg.vxtype) + ", " + argtext + ")"
						}
					} else if funcname == "vx/core/fn" {
					} else if funcarg.vxtype.isfunc {
						work, msgs := JsFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
						msgblock = MsgblockAddBlock(msgblock, msgs)
						iswrapnew := true
						switch argvalue.code {
						case ":arg":
							argvaluearg := ArgFromValue(argvalue)
							if argvaluearg.vxtype.isfunc {
								argtext = work
								iswrapnew = false
							} else {
								argtext = "() => {return " + work + "}"
							}
						case ":funcref":
							argtext = work
						default:
							argtext = "() => {return " + work + "}"
						}
						if iswrapnew {
							argtext = "vx_core.f_new(" + JsNameTFromType(funcarg.vxtype) + ", " + argtext + ")"
						}
					}
					if argtext == "" {
						work, msgs := JsFromValue(lang, argvalue, pkgname, fnc, 0, true, test, argsubpath)
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
					if argtext != "" {
						argtexts = append(argtexts, argtext)
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
				switch fnc.name {
				case "fn":
				default:
					output += ")"
				}
			}
		}
		if fnc.debug {
			output += ")"
		}
	case ":funcref":
		valfunc := FuncFromValue(value)
		valstr = ""
		//if valfunc.async {
		//	valstr += "await "
		//}
		valstr += JsFromName(valfunc.pkgname) + ".t_" + JsFromName(valfunc.alias)
		output = sindent + valstr
	case ":type":
		valtype := TypeFromValue(value)
		valstr = JsFromName(valtype.pkgname) + ".t_" + JsFromName(valtype.alias)
		output = sindent + valstr
	case "decimal", "int", "number", "string":
		valstr = StringValueFromValue(value)
		if valstr == "" {
		} else if BooleanFromStringStarts(valstr, ":") {
			output = "\"" + valstr + "\""
		} else if BooleanFromStringStartsEnds(valstr, "\"", "\"") {
			output = valstr[1 : len(valstr)-1]
			if encode {
				output = JsFromText(output)
			}
			output = "\"" + output + "\""
		} else if BooleanIsNumberFromString(valstr) {
			output = valstr
		} else if encode {
			output = JsFromText(output)
		} else {
			output = valstr
		}
	default:
		//msg := MsgNew("Invalid Value Code:", value.code, "\n"+ValueToText(value), "\n"+FuncToText(parentfn))
		//msgblock = MsgBlockAddError(msgblock, msg)
	}
	return output, msgblock
}

func JsIndexFromFunc(fnc *vxfunc) string {
	return StringIndexFromFunc(fnc)
}

func JsNameEFromType(typ *vxtype) string {
	name := ""
	name = "e_" + JsNameFromType(typ)
	if typ.pkgname != "" {
		name = JsNameFromPkgName(typ.pkgname) + "." + name
	}
	return name
}

func JsNameFFromFunc(fnc *vxfunc) string {
	name := ""
	name = "f_" + JsFromName(fnc.name)
	if fnc.pkgname != "" {
		name = JsNameFromPkgName(fnc.pkgname) + "." + name
	}
	return name
}

func JsNameFromPkgName(pkgname string) string {
	output := JsFromName(pkgname)
	return output
}

func JsNameFromType(typ *vxtype) string {
	name := ""
	/*
		switch typ.name {
		case "generic-1":
			name = "generics{\":1\"}"
		case "generic-2":
			name = "generics{\":2\"}"
		case "generic-3":
			name = "generics[2]"
		default:
	*/
	if typ.alias == "" {
		name += JsFromName(typ.name)
	} else {
		name += JsFromName(typ.alias)
	}
	//	}
	return name
}

func JsNameTFromType(typ *vxtype) string {
	name := ""
	name = "t_" + JsNameFromType(typ)
	if typ.pkgname != "" {
		name = JsNameFromPkgName(typ.pkgname) + "." + name
	}
	return name
}

func JsNamesFromListFunc(listfunc []*vxfunc) string {
	var outputtypes []string
	for _, fnc := range listfunc {
		name := "f_" + JsFromName(fnc.alias)
		if fnc.pkgname != "" {
			name = JsFromName(fnc.pkgname) + "." + name
		}
		outputtypes = append(outputtypes, name)
	}
	return "[" + StringFromListStringJoin(outputtypes, ", ") + "]"
}

func JsNamesTFromListType(listtype []*vxtype) string {
	var outputtypes []string
	for _, typ := range listtype {
		name := JsNameTFromType(typ)
		outputtypes = append(outputtypes, name)
	}
	return "[" + strings.Join(outputtypes, ", ") + "]"
}

func JsNamesFromListValue(listvalue []*vxconst) string {
	var output []string
	for _, val := range listvalue {
		name := "c_" + JsFromName(val.alias)
		if val.pkgname != "" {
			name = JsFromName(val.pkgname) + "." + name
		}
		output = append(output, name)
	}
	return "[" + strings.Join(output, ", ") + "]"
}

func JsNamesTFromMapType(maptype map[string]*vxtype) string {
	var outputtypes []string
	listkey := make([]string, 0, len(maptype))
	for id := range maptype {
		listkey = append(listkey, id)
	}
	sort.Strings(listkey)
	for _, key := range listkey {
		typ := maptype[key]
		name := JsNameTFromType(typ)
		outputtypes = append(outputtypes, "\""+key+"\": "+name)
	}
	return "{" + strings.Join(outputtypes, ", ") + "}"
}

func JsTestFromConst(lang *vxlang, cnst *vxconst) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsTestFromConst")
	output := ""
	path := cnst.pkgname + "/" + cnst.name
	if len(cnst.listtestvalue) > 0 {
		var listtestdescribe []string
		for _, testvalue := range cnst.listtestvalue {
			clstextjs, msgs := JsFromValue(lang, testvalue, cnst.pkgname, emptyfunc, 7, true, true, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			clstext := "" +
				"\n          vx_core.f_new(" +
				"\n            vx_test.t_testdescribe," +
				"\n            \":describename\", \"" + JsTestFromValue(testvalue) + "\"," +
				"\n            \":testresult\"," +
				"\n            " + clstextjs +
				"\n          )"
			listtestdescribe = append(listtestdescribe, clstext)
		}
		testdescribes := strings.Join(listtestdescribe, ",\n")
		output = "" +
			"\n  static c_" + JsFromName(cnst.alias) + "(context) {" +
			"\n    const output = vx_core.f_new(" +
			"\n      vx_test.t_testcase," +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + cnst.pkgname + "\"," +
			"\n      \":casename\", \"" + cnst.name + "\"," +
			"\n      \":describelist\"," +
			"\n        vx_core.f_new(" +
			"\n          vx_test.t_testdescribelist," +
			testdescribes +
			"\n        )" +
			"\n    )" +
			"\n    return output" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func JsTestFromFunc(lang *vxlang, fnc *vxfunc) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsTestFromFunc")
	output := ""
	path := fnc.pkgname + "/" + fnc.name + JsIndexFromFunc(fnc)
	if len(fnc.listtestvalue) > 0 {
		var listtestdescribe []string
		for _, testvalue := range fnc.listtestvalue {
			clstextjs, msgs := JsFromValue(lang, testvalue, fnc.pkgname, emptyfunc, 6, true, true, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			clstext := "" +
				"\n          vx_core.f_new(" +
				"\n            vx_test.t_testdescribe," +
				"\n            \":describename\", \"" + JsTestFromValue(testvalue) + "\"," +
				"\n            \":testresult\"," +
				"\n            " + clstextjs +
				"\n          )"
			listtestdescribe = append(listtestdescribe, clstext)
		}
		testdescribes := strings.Join(listtestdescribe, ",")
		output = "" +
			"\n  static f_" + JsFromName(fnc.alias) + JsIndexFromFunc(fnc) + "(context) {" +
			"\n    const output = vx_core.f_new(" +
			"\n      vx_test.t_testcase," +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + fnc.pkgname + "\"," +
			"\n      \":casename\", \"" + fnc.name + "\"," +
			"\n      \":describelist\"," +
			"\n        vx_core.f_new(" +
			"\n          vx_test.t_testdescribelist," +
			testdescribes +
			"\n        )" +
			"\n    )" +
			"\n    return output" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func JsTestFromPackage(lang *vxlang, pkg *vxpackage, prj *vxproject, command *vxcommand) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsTestFromPackage")
	imports := ""
	depth := IntCountFromStringFind(pkg.name, "/") + 1
	prefix := StringRepeat("../", depth)
	libpath := prefix + "src/" + pkg.name + ".js"
	imports += "\nimport " + JsFromName(pkg.name) + " from \"" + libpath + "\""
	if len(pkg.listlib) > 0 {
		for _, lib := range pkg.listlib {
			isskip := false
			if lib.lang != "" {
				if lib.lang == ":js" {
				} else {
					isskip = true
				}
			}
			if !isskip {
				libpath = prefix + "src/" + lib.path + ".js"
				imports += "\nimport " + JsFromName(lib.path) + " from \"" + libpath + "\""
			}
		}
	}
	imports += "\n"
	testdescribes := ""
	pkgname := JsFromName(pkg.alias)
	typkeys := ListKeyFromMapType(pkg.maptype)
	coverdoccnt := 0
	coverdoctotal := 0
	covertypecnt := 0
	covertypetotal := 0
	var testall []string
	var covertype []string
	for _, typid := range typkeys {
		covertypetotal += 1
		typ := pkg.maptype[typid]
		test, msgs := JsTestFromType(lang, typ)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		covertype = append(covertype, "\""+typid+"\", "+StringFromInt(len(typ.testvalues)))
		if command.filter == "" {
		} else if NameFromType(typ) != command.filter {
			test = ""
		}
		if test != "" {
			covertypecnt += 1
			testdescribes += test
			testall = append(testall, pkgname+"_test.t_"+JsFromName(typ.alias)+"()")
		}
		coverdoctotal += 1
		if typ.doc != "" {
			coverdoccnt += 1
		}
	}
	coverconstcnt := 0
	coverconsttotal := 0
	var coverconst []string
	var coverfunc []string
	cnstkeys := ListKeyFromMapConst(pkg.mapconst)
	for _, cnstid := range cnstkeys {
		coverconsttotal += 1
		cnst := pkg.mapconst[cnstid]
		test, msgs := JsTestFromConst(lang, cnst)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		coverconst = append(coverconst, "\""+cnstid+"\", "+StringFromInt(len(cnst.listtestvalue)))
		if command.filter == "" {
		} else if NameFromConst(cnst) != command.filter {
			test = ""
		}
		if test != "" {
			coverconstcnt += 1
			testdescribes += test
			testall = append(testall, pkgname+"_test.c_"+JsFromName(cnst.alias)+"()")
		}
		coverdoctotal += 1
		if cnst.doc != "" {
			coverdoccnt += 1
		}
	}
	coverbigospacecnt := 0
	coverbigospacetotal := 0
	coverbigotimecnt := 0
	coverbigotimetotal := 0
	coverfunccnt := 0
	coverfunctotal := 0
	fnckeys := ListKeyFromMapFunc(pkg.mapfunc)
	for _, fncid := range fnckeys {
		isfound := false
		fncs := pkg.mapfunc[fncid]
		for _, fnc := range fncs {
			switch fnc.clientserver {
			case ":server":
			default:
				isfound = true
				test, msgs := JsTestFromFunc(lang, fnc)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				msgblock = MsgblockAddBlock(msgblock, msgs)
				coverfunc = append(coverfunc, "\""+fncid+JsIndexFromFunc(fnc)+"\", "+StringFromInt(len(fnc.listtestvalue)))
				if command.filter == "" {
				} else if NameFromFunc(fnc) != command.filter {
					test = ""
				}
				if test != "" {
					coverfunccnt += 1
					testdescribes += test
					testall = append(testall, pkgname+"_test.f_"+JsFromName(fnc.alias)+JsIndexFromFunc(fnc)+"(context)")
				}
				coverdoctotal += 1
				if fnc.doc != "" {
					coverdoccnt += 1
				}
			}
		}
		if isfound {
			coverfunctotal += 1
		}
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
	covercnt := coverconstcnt + coverfunccnt + covertypecnt
	covertotal := covertypetotal + coverconsttotal + coverfunctotal
	coverpct := 100
	if covertotal > 0 {
		coverpct = (covercnt * 100 / covertotal)
	}
	covertypemap := ""
	if len(covertype) > 0 {
		covertypemap = ",\n          " + strings.Join(covertype, ",\n          ")
	}
	coverconstmap := ""
	if len(coverconst) > 0 {
		coverconstmap = ",\n          " + strings.Join(coverconst, ",\n          ")
	}
	coverfuncmap := ""
	if len(coverfunc) > 0 {
		coverfuncmap = ",\n          " + strings.Join(coverfunc, ",\n          ")
	}
	testcases := ""
	if len(testall) > 0 {
		testcases = ",\n      " + strings.Join(testall, ",\n      ")
	}
	namespaceopen, namespaceclose := LangNamespaceFromPackage(lang, pkgname+"_test")
	output := "" +
		"'strict mode'" +
		"\n" + imports +
		namespaceopen +
		"\n  static test_package(context) {" +
		"\n    const testcaselist = " + pkgname + "_test.test_cases(context)" +
		"\n    const output = vx_core.f_new(" +
		"\n      vx_test.t_testpackage," +
		"\n      \":testpkg\", \"" + pkg.name + "\"," +
		"\n      \":caselist\", testcaselist," +
		"\n      \":coveragesummary\", " + pkgname + "_test.test_coveragesummary()," +
		"\n      \":coveragedetail\", " + pkgname + "_test.test_coveragedetail()" +
		"\n    );" +
		"\n    return output;" +
		"\n  }" +
		"\n" +
		"\n  static test_coveragesummary() {" +
		"\n    return vx_core.f_new(" +
		"\n      vx_test.t_testcoveragesummary," +
		"\n      \"testpkg\",   \"" + pkg.name + "\", " +
		"\n      \"constnums\", " + JsTypeCoverageNumsValNew(coverconstpct, coverconstcnt, coverconsttotal) + ", " +
		"\n      \"docnums\", " + JsTypeCoverageNumsValNew(coverdocpct, coverdoccnt, coverdoctotal) + ", " +
		"\n      \"funcnums\", " + JsTypeCoverageNumsValNew(coverfuncpct, coverfunccnt, coverfunctotal) + ", " +
		"\n      \"bigospacenums\", " + JsTypeCoverageNumsValNew(coverbigospacepct, coverbigospacecnt, coverbigospacetotal) + ", " +
		"\n      \"bigotimenums\", " + JsTypeCoverageNumsValNew(coverbigotimepct, coverbigotimecnt, coverbigotimetotal) + ", " +
		"\n      \"totalnums\", " + JsTypeCoverageNumsValNew(coverpct, covercnt, covertotal) + ", " +
		"\n      \"typenums\", " + JsTypeCoverageNumsValNew(covertypepct, covertypecnt, covertypetotal) +
		"\n    )" +
		"\n  }" +
		"\n" +
		"\n  static test_coveragedetail() {" +
		"\n    return vx_core.f_new(" +
		"\n      vx_test.t_testcoveragedetail," +
		"\n      \"testpkg\", \"" + pkg.name + "\"," +
		"\n      \"typemap\"," +
		"\n        vx_core.f_new(" +
		"\n          vx_core.t_intmap" +
		covertypemap +
		"\n        )," +
		"\n      \"constmap\"," +
		"\n        vx_core.f_new(" +
		"\n          vx_core.t_intmap" +
		coverconstmap +
		"\n        )," +
		"\n      \"funcmap\"," +
		"\n        vx_core.f_new(" +
		"\n          vx_core.t_intmap" +
		coverfuncmap +
		"\n        )" +
		"\n    )" +
		"\n  }" +
		"\n" +
		testdescribes +
		"\n  static test_cases(context) {" +
		"\n    const output = vx_core.f_new(" +
		"\n      vx_test.t_testcaselist" +
		testcases +
		"\n    )" +
		"\n    return output" +
		"\n  }" +
		namespaceclose
	return output, msgblock
}

func JsTestFromType(lang *vxlang, typ *vxtype) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsTestFromType")
	output := ""
	path := typ.pkgname + "/" + typ.name
	if len(typ.testvalues) > 0 {
		var listtestdescribe []string
		for _, testvalue := range typ.testvalues {
			clstextjs, msgs := JsFromValue(lang, testvalue, typ.pkgname, emptyfunc, 6, true, true, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			clstext := "" +
				"\n          vx_core.f_new(" +
				"\n            vx_test.t_testdescribe," +
				"\n            \":describename\", \"" + JsTestFromValue(testvalue) + "\"," +
				"\n            \":testresult\", " + clstextjs +
				"\n          )"
			listtestdescribe = append(listtestdescribe, clstext)
		}
		testdescribes := strings.Join(listtestdescribe, ",")
		output = "" +
			"\n  static t_" + JsFromName(typ.alias) + "(context) {" +
			"\n    const output = vx_core.f_new(" +
			"\n      vx_test.t_testcase," +
			"\n      \":passfail\", false," +
			"\n      \":testpkg\", \"" + typ.pkgname + "\"," +
			"\n      \":casename\", \"" + typ.name + "\"," +
			"\n      \":describelist\"," +
			"\n        vx_core.f_new(" +
			"\n          vx_test.t_testdescribelist," +
			testdescribes +
			"\n        )" +
			"\n    )" +
			"\n    return output" +
			"\n  }" +
			"\n"
	}
	return output, msgblock
}

func JsTestFromValue(value vxvalue) string {
	var output = ""
	output = JsFromText(value.textblock.text)
	return output
}

func JsTextFromProjectCmd(lang *vxlang, project *vxproject, command *vxcommand) (string, *vxmsgblock) {
	msgblock := NewMsgBlock("JsTextFromProjectCmd")
	prjjs, msgs := JsFilesFromProjectCmd(lang, project, command)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	text := StringFromListFile(prjjs)
	return text, msgblock
}

func JsTypeCoverageNumsValNew(pct int, tests int, total int) string {
	return "" +
		"vx_core.f_new(" +
		"vx_test.t_testcoveragenums, " +
		"\":pct\", " + StringFromInt(pct) + ", " +
		"\":tests\", " + StringFromInt(tests) + ", " +
		"\":total\", " + StringFromInt(total) +
		")"
}

func JsWriteFromProjectCmd(lang *vxlang, project *vxproject, command *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("WriteJsFromProjectCmd")
	files, msgs := JsFilesFromProjectCmd(lang, project, command)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	msgs = WriteListFile(files)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	switch command.code {
	case ":test":
		sourcepath := PathFromProjectPath(project, "./testdata")
		if BooleanExistsFromPath(sourcepath) {
			targetpath := PathFromProjectCmd(project, command)
			targetpath += "/resources"
			msgs := FolderCopyFromSourceTarget(sourcepath, targetpath)
			msgblock = MsgblockAddBlock(msgblock, msgs)
		}
	}

	return msgblock
}

func JsApp(project *vxproject, cmd *vxcommand) string {
	includetext := ""
	contexttext := `
    const context = vx_core.f_context_main(arglist)`
	maintext := `
    const output = vx_core::f_main(arglist)`
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
			if contextfunc.pkgname != mainfunc.pkgname {
				switch contextfunc.pkgname {
				case "", "vx/core":
				default:
					importname := StringFromStringFindReplace(contextfunc.pkgname, "/", "_")
					includetext += "\nimport " + importname + " from \"../src/" + contextfunc.pkgname + ".js\""
				}
			}
			if contextfunc.async {
				contexttext = `
    const context = await ` + JsNameFFromFunc(contextfunc) + `(...arglist)`
			} else {
				contexttext = `
    const context = ` + JsNameFFromFunc(contextfunc) + `(...arglist)`
			}
		}
		if mainfunc != emptyfunc {
			switch mainfunc.pkgname {
			case "", "vx/core":
			default:
				importname := StringFromStringFindReplace(mainfunc.pkgname, "/", "_")
				includetext += "\nimport " + importname + " from \"../src/" + mainfunc.pkgname + ".js\""
			}
			params := ""
			if mainfunc.context {
				params += "context, "
			}
			params += "...arglist"
			mainfunctext := JsNameFFromFunc(mainfunc) + "(" + params + ")"
			if mainfunc.async {
				maintext = `
    const output = await ` + mainfunctext
			} else {
				maintext = `
    const output = ` + mainfunctext
			}
		}
	}

	output := "" +
		`'strict mode'

import vx_core from "../src/vx/core.js"
import vx_type from "../src/vx/type.js"
import vx_web_htmldoc from "../src/vx/web/htmldoc.js"` +
		includetext + `

export default class app {

  static async f_main(arglist) {` +
		contexttext +
		maintext + `
    return output
  }

  static async f_htmlmain() {
    const argtext = vx_web_htmldoc.f_string_from_id("args")
    const elem = document.getElementById("args")
    const arglist = vx_type.f_stringlist_from_string_split(argtext, " ")
    const mainstring = await app.f_main(arglist)
    vx_web_htmldoc.f_boolean_write_from_id_htmltext("display", mainstring)
  }

}

`
	return output
}

func JsAppTest(project *vxproject, command *vxcommand) string {
	includetext := ""
	contexttext := `
    const context = vx_core.f_context_main(arglist)`
	if command.context == "" {
	} else {
		contextfunc := FuncFromProjectFuncname(project, command.context)
		if command.context != "" && contextfunc == emptyfunc {
			MsgLog("Error! Context Not Found: (project (cmd :context " + command.context + "))")
		}
		if contextfunc != emptyfunc {
			switch contextfunc.pkgname {
			case "", "vx/core":
			default:
				importname := StringFromStringFindReplace(contextfunc.pkgname, "/", "_")
				includetext += "\nimport " + importname + " from \"../src/" + contextfunc.pkgname + ".js\"\n"
			}
		}
		if contextfunc.async {
			contexttext = `
    const context = await ` + JsNameFFromFunc(contextfunc) + `(...arglist)`
		} else {
			contexttext = `
    const context = ` + JsNameFFromFunc(contextfunc) + `(...arglist)`
		}
	}
	listpackage := project.listpackage
	var listimport []string
	var listtest []string
	for _, pkg := range listpackage {
		iscontinue := true
		if command.filter == "" {
		} else if !BooleanFromStringStarts(command.filter, pkg.name) {
			iscontinue = false
		}
		if iscontinue {
			importname := StringFromStringFindReplace(pkg.name, "/", "_")
			importpath := StringFromStringFindReplace(pkg.name, "/", "/")
			packageimport := "import " + importname + "_test from \"./" + importpath + "_test.js\""
			packagetest := importname + "_test.test_package(context)"
			listimport = append(listimport, packageimport)
			listtest = append(listtest, packagetest)
		}
	}
	packageimports := StringFromListStringJoin(listimport, "\n")
	packagetests := StringFromListStringJoin(listtest, ",\n      ")
	output := "" +
		`'strict mode'

import vx_core from "../src/vx/core.js"
import vx_test from "../src/vx/test.js"
import vx_web_html from "../src/vx/web/html.js"
import vx_web_htmldoc from "../src/vx/web/htmldoc.js"` +
		includetext +
		packageimports + `

export default class app_test {

  static async f_displaytestsuite() {
			 const arglist = []` +
		contexttext + `
    const stylesheet = vx_test.c_stylesheet_test
    const testpackagelist = app_test.f_testpackagelist_from_all_test(context)
    const resolvedtestpackagelist = await vx_test.f_resolve_testpackagelist(testpackagelist)
    const div = vx_test.f_div_from_testpackagelist(resolvedtestpackagelist)
    const htmltext = vx_web_html.f_string_from_div_indent(div, 0)
    vx_web_htmldoc.f_boolean_write_from_stylesheet(stylesheet)
    vx_web_htmldoc.f_boolean_write_from_id_htmltext("testdisplay", htmltext)
  }

  static f_testpackagelist_from_all_test(context) {
    const testpackagelist = vx_core.f_new(
      vx_test.t_testpackagelist,
      ` + packagetests + `
    )
    return testpackagelist
  }

}`
	return output
}
