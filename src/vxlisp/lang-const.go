package vxlisp

func LangConst(
	lang *vxlang,
	cnst *vxconst,
	project *vxproject,
	pkg *vxpackage) (string, string, *vxmsgblock) {
	msgblock := NewMsgBlock("LangConst")
	output := ""
	g_ifuncdepth = 0
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
	doc += "{" + cnsttype.name + "}"
	cnstname := LangFromName(cnst.alias)
	cnstclassname := "Const_" + cnstname
	const_new := "" +
		LangVarClass(lang, "outval", cnst.vxtype, 3,
			LangSpecificAsClass(lang, "output", cnst.vxtype)) +
		"\n      outval.vx_p_constdef = constdef()" + lang.lineend
	cnstval := LangConstValFromConst(lang, cnst, project)
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
		const_new += "\n      outval.vxboolean = " + cnstval + lang.lineend
	case "vx/core/decimal":
		if cnstval == "" {
			cnstval = "0"
		}
		const_new += "\n      outval.vxdecimal = " + cnstval + lang.lineend
	case "vx/core/float":
		if cnstval == "" {
			cnstval = "f0"
		}
		const_new = "\n      outval.vxfloat = " + cnstval + lang.lineend
	case "vx/core/int":
		if cnstval == "" {
			cnstval = "0"
		}
		const_new += "\n      outval.vxint = " + cnstval + lang.lineend
	case "vx/core/string":
		if BooleanFromStringStartsEnds(cnstval, "\"", "\"") {
			cnstval = cnstval[1 : len(cnstval)-1]
			cnstval = LangSpecificFromText(lang, cnstval)
			cnstval = "\"" + cnstval + "\""
		}
		const_new += "\n      outval.vxstring = " + cnstval + lang.lineend
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
					LangVar(lang, "value", cnsttype, 3, clstext) +
					"\n      outval.vx_p_list = value.vx_list" + listtypename + "()" + lang.lineend
			}
		case ":map":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 4, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				maptypename := LangNameFromType(lang, allowtype)
				if maptypename == "any" {
					maptypename = ""
				}
				const_new += "" +
					LangVar(lang, "value", cnsttype, 3, clstext) +
					"\n      outval.vx_p_map = val.vx_map" + maptypename + "()" + lang.lineend
			}
		case ":struct":
			clstext, msgs := LangFromValue(lang, cnst.value, cnst.pkgname, emptyfunc, 3, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					LangVar(lang, "value", cnsttype, 3, clstext)
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						"\n      outval.vx_p_" + LangFromName(prop.name) + " = value." + LangFromName(prop.name) + "()" + lang.lineend
				}
			}
		}
	}
	e_type := ""
	//_, funcstatic := LangFuncInstanceStatic(lang)
	switch NameFromConst(cnst) {
	case "vx/core/false":
		e_type = LangValStatic(lang, "e_boolean", booleantype, 1, LangPkgNameDot(lang, "vx/core")+"c_false")
	}
	doc = "" +
		"\n  /**" +
		"\n   * " + StringFromStringIndent(doc, "   * ") +
		"\n   */"
		/// FIXME
	if lang == langkotlin {
		doc = ""
	}
	argoutput := NewArg("output")
	argoutput.vxtype = cnst.vxtype
	argoutput.isfinal = false
	listarg := NewListArg()
	listarg = append(listarg, argoutput)
	funcconstnew := NewFunc()
	funcconstnew.name = "const_new"
	funcconstnew.vxtype = nonetype
	funcconstnew.listarg = listarg
	staticopen, staticclose := LangSpecificConstStaticOpenClose(lang)
	output += "" +
		doc +
		LangSpecificConstClassHeader(lang, cnst, 1) +
		staticopen +
		LangConstVxConstdef(lang, cnst) +
		LangFuncHeaderStatic(lang, cnstname, funcconstnew, 2, 0, const_new) +
		staticclose +
		"\n  }" +
		"\n" +
		LangValStatic(lang, "c_"+cnstname, cnst.vxtype, 1, ":new") +
		"\n" +
		e_type +
		"\n"
	constlate := "" +
		"\n    " + cnstclassname + ".const_new(c_" + cnstname + ")" + lang.lineend
	return output, constlate, msgblock
}

func LangConstC(lang *vxlang, cnst *vxconst) string {
	name := "c_" + LangFromName(cnst.alias)
	if cnst.pkgname != "" {
		name = LangSpecificPkgName(lang, cnst.pkgname) + lang.pkgref + name
	}
	return name
}

func LangConstName(cnst *vxconst) string {
	return LangFromName(cnst.alias)
}

func LangConstValFromConst(
	lang *vxlang,
	cnst *vxconst,
	project *vxproject) string {
	cnstval := StringValueFromValue(cnst.value)
	switch NameFromConst(cnst) {
	case "vx/core/path-test-resources":
		cnstval = "\"src/test/resources\""
		for _, cmd := range project.listcmd {
			if cmd.code != ":test" {
			} else if cmd.lang == lang {
				path := cmd.path
				switch lang {
				case langjava:
					ipos := IntFromStringFindLast(path, "/test/")
					if ipos >= 0 {
						path = path[0 : ipos+5]
					}
				}
				ipos := IntFromStringFind(path, "/"+lang.name+"/")
				if ipos >= 0 {
					path = path[ipos+len(lang.name)+2:]
				}
				switch lang {
				case langkotlin:
					if BooleanFromStringStarts(path, "app/") {
						path = path[4:]
					}
				}
				cnstval = "\"" + path + "/resources\""
			}
		}
	}
	return cnstval
}

func LangConstVxConstdef(
	lang *vxlang,
	cnst *vxconst) string {
	cnsttype := cnst.vxtype
	fnc := NewFunc()
	fnc.name = "constdef"
	fnc.vxtype = constdeftype
	constname := LangConstName(cnst)
	body := "" +
		LangPkgNameDot(lang, "vx/core") + "constdef_new(" +
		"\n        \"" + cnst.pkgname + "\", // pkgname" +
		"\n        \"" + cnst.name + "\", // name" +
		"\n        " + LangTypeT(lang, cnsttype) +
		"\n      )"
	output := "" +
		LangFuncHeaderStatic(lang, constname, fnc, 2, 0,
			LangVar(lang, "output", constdeftype, 3, body))
	return output
}
