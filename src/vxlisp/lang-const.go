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
	cnsttype := cnst.vxtype
	cnstname := LangFromName(cnst.alias)
	cnstclassname := "Const_" + cnstname
	const_new := "" +
		LangVarClass(lang, 3, cnst.vxtype,
			"outval",
			LangNativeAsClass(lang, "output", cnst.vxtype)) +
		LangVarSet(lang, 3,
			"outval.vx_p_constdef",
			"constdef()")
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
			cnstval = LangNativeFromText(lang, cnstval)
			cnstval = "\"" + cnstval + "\""
		}
		const_new += "\n      outval.vxstring = " + cnstval + lang.lineend
	default:
		switch cnsttype.extends {
		case ":list":
			clstext, msgs := LangFromValue(lang, 3, cnst.value, cnst.pkgname, emptyfunc, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				listtypename := LangNameFromType(lang, allowtype)
				if listtypename == "any" {
					listtypename = ""
				}
				const_new += "" +
					LangVar(lang, 3, cnsttype,
						"value", clstext) +
					LangVarSet(lang, 3,
						"outval.vx_p_list",
						"value.vx_list"+listtypename+"()")
			}
		case ":map":
			clstext, msgs := LangFromValue(lang, 4, cnst.value, cnst.pkgname, emptyfunc, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				allowtype, _ := TypeAllowFromType(cnsttype)
				maptypename := LangNameFromType(lang, allowtype)
				if maptypename == "any" {
					maptypename = ""
				}
				const_new += "" +
					LangVar(lang, 3, cnsttype,
						"value", clstext) +
					LangVarSet(lang, 3,
						"outval.vx_p_map",
						"val.vx_map"+maptypename+"()")
			}
		case ":struct":
			clstext, msgs := LangFromValue(lang, 3, cnst.value, cnst.pkgname, emptyfunc, true, false, path)
			msgblock = MsgblockAddBlock(msgblock, msgs)
			if clstext != "" {
				const_new += "" +
					LangVar(lang, 3, cnsttype,
						"value", clstext)
				for _, prop := range ListPropertyTraitFromType(cnst.vxtype) {
					const_new += "" +
						LangVarSet(lang, 3,
							"outval.vx_p_"+LangFromName(prop.name),
							"value."+LangFromName(prop.name)+"()")
				}
			}
		}
	}
	e_type := ""
	//_, funcstatic := LangFuncInstanceStatic(lang)
	switch NameFromConst(cnst) {
	case "vx/core/false":
		e_type = LangValStatic(lang, 1, booleantype,
			"e_boolean", LangPkgNameDot(lang, "vx/core")+"c_false") + "\n"
	}
	doc := LangNativeConstDoc(lang, cnst)
	argoutput := NewArg("output")
	argoutput.vxtype = cnst.vxtype
	argoutput.isfinal = false
	listarg := NewListArg()
	listarg = append(listarg, argoutput)
	funcconstnew := NewFunc()
	funcconstnew.name = "const_new"
	funcconstnew.vxtype = nonetype
	funcconstnew.listarg = listarg
	staticopen, staticclose := LangNativeConstStaticOpenClose(lang)
	output += "" +
		doc +
		LangNativeConstClassHeader(lang, cnst, 1) +
		staticopen +
		LangConstVxConstdef(lang, cnst) +
		LangFuncHeaderStatic(lang, 2,
			cnstname, funcconstnew, 0, const_new) +
		staticclose +
		"\n  }" +
		"\n" +
		LangValStatic(lang, 1, cnst.vxtype,
			"c_"+cnstname, ":new") +
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
		name = LangPkgName(lang, cnst.pkgname) + lang.pkgref + name
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
				path := LangNativeTestResourcesPath(
					lang, cmd)
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
		LangFuncHeaderStatic(lang, 2,
			constname, fnc, 0,
			LangVar(lang, 3, constdeftype,
				"output", body))
	return output
}
