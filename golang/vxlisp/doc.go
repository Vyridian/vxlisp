package vxlisp

func HtmlFromConsts(consts []*vxconst, indent string) (string, string) {
	lineindent := "\n" + indent
	nav := ""
	detail := ""
	for _, cnst := range consts {
		nav += "" +
			lineindent + "<li class=\"nconst\" onclick=\"docjs.navigate('const_" + HtmlNameFromConst(cnst) + "')\">" +
			lineindent + "  (c) " + HtmlFromString(cnst.name) +
			lineindent + "</li>"
		detail += "" +
			lineindent + "<div class=\"d\" id=\"d_const_" + HtmlNameFromConst(cnst) + "\">" +
			lineindent + "  <div class=\"header\">" + HtmlLinkFromPackageName(cnst.pkgname) + " / " + HtmlLinkNameFromConst(cnst) + "</div>" +
			lineindent + "  <div class=\"lbl\">Constant:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlFromNameAlias(cnst.name, cnst.alias) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			lineindent + "  <div class=\"lbl\">Type:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlLinkFromType(cnst.vxtype) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			HtmlFromDoc(cnst.doc, indent+"  ") +
			HtmlFromListTestValue(cnst.listtestvalue, indent+"  ") +
			HtmlFromSourceCode(cnst.textblock.text, indent+"  ") +
			lineindent + "</div>"
	}
	return nav, detail
}

func HtmlFromDoc(doc string, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		lineindent + "<div class=\"lbl\">Description:</div>" +
		lineindent + "<ul>" +
		lineindent + "  <li>" +
		lineindent + "    <div class=\"txt\">" + HtmlFromString(doc) + "</div>" +
		lineindent + "  </li>" +
		lineindent + "</ul>"
	return output
}

func HtmlFromListFuncIndent(listfunc []*vxfunc, indent string) (string, string) {
	lineindent := "\n" + indent
	detail := ""
	nav := ""
	for _, fnc := range listfunc {
		nav += "" +
			lineindent + "<li class=\"nfunc\" onclick=\"docjs.navigate('func_" + HtmlNameFromFunc(fnc) + "')\">" +
			lineindent + "  (f) " + HtmlFromString(fnc.name) +
			lineindent + "</li>"
		arguments := "" +
			lineindent + "  <div class=\"lbl\">Arguments:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"table\">" +
			lineindent + "        <div class=\"th\">" +
			lineindent + "          <div class=\"td\">Name</div>" +
			lineindent + "          <div class=\"td\">Type</div>" +
			lineindent + "          <div class=\"td\">Generic</div>" +
			lineindent + "          <div class=\"td\">Description</div>" +
			lineindent + "        </div>"
		for _, arg := range fnc.listarg {
			argdoc := arg.doc
			arguments += "" +
				lineindent + "        <div class=\"tr\">" +
				lineindent + "          <div class=\"td\">" + HtmlFromString(arg.name) + "</div>" +
				lineindent + "          <div class=\"td\">" + HtmlLinkFromType(arg.vxtype) + "</div>" +
				lineindent + "          <div class=\"td\">" + argdoc + "</div>" +
				lineindent + "        </div>"
		}
		arguments += "" +
			lineindent + "      </div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>"
		detail += "" +
			lineindent + "<div class=\"d\" id=\"d_func_" + HtmlNameFromFunc(fnc) + "\">" +
			lineindent + "  <div class=\"header\">" + HtmlLinkFromPackageName(fnc.pkgname) + " / " + HtmlLinkNameFromFunc(fnc) + "</div>" +
			lineindent + "  <div class=\"lbl\">Function:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlFromNameAlias(fnc.name, fnc.alias) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			lineindent + "  <div class=\"lbl\">Return Type:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlLinkFromType(fnc.vxtype) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			arguments +
			HtmlFromDoc(fnc.doc, indent+"  ") +
			HtmlFromListTestValue(fnc.listtestvalue, indent+"  ") +
			HtmlFromSourceCode(fnc.textblock.text, indent+"  ") +
			lineindent + "</div>"
	}
	return nav, detail
}

func HtmlFromName(name string) string {
	return HtmlFromString(name)
}

func HtmlFromNameAlias(name string, alias string) string {
	output := ""
	if alias == "" || name == alias {
		output = HtmlFromString(name)
	} else {
		output = HtmlFromString(name) + " (alias: " + HtmlFromString(alias) + ")"
	}
	return output
}

func HtmlFromListPackage(listpackage []*vxpackage, indent string) (string, string) {
	lineindent := "\n" + indent
	detail := ""
	nav := ""
	for _, pkg := range listpackage {
		typenav, typedetail := HtmlFromListType(pkg.listtype, indent+"  ")
		constnav, constdetail := HtmlFromConsts(pkg.listconst, indent+"  ")
		funcnav, funcdetail := HtmlFromListFuncIndent(pkg.listfunc, indent+"  ")
		nav += "" +
			lineindent + "<div class=\"npackage\" onclick=\"docjs.navigate('pkg_" + HtmlNameFromPackage(pkg) + "')\">" +
			HtmlNameFromPackage(pkg) + "</div>" +
			lineindent + "<ul class=\"packagenav\" id=\"n_pkgnav_" + HtmlNameFromPackage(pkg) + "\">" +
			typenav +
			constnav +
			funcnav +
			lineindent + "</ul>"
		var pkgconsts []string
		for _, pkgconst := range pkg.listconst {
			pkgtext := HtmlLinkNameFromConst(pkgconst)
			pkgconsts = append(pkgconsts, pkgtext)
		}
		var pkgfuncs []string
		for _, pkgfunc := range pkg.listfunc {
			pkgtext := HtmlLinkNameFromFunc(pkgfunc)
			pkgfuncs = append(pkgfuncs, pkgtext)
		}
		var pkgtypes []string
		for _, pkgtype := range pkg.listtype {
			pkgtext := HtmlLinkNameFromType(pkgtype)
			pkgtypes = append(pkgtypes, pkgtext)
		}
		libraries := ""
		if len(pkg.listlib) > 0 {
			libraries += "" +
				lineindent + "  <ul>" +
				lineindent + "    <li>" +
				lineindent + "      <div class=\"table\">" +
				lineindent + "        <div class=\"th\">" +
				lineindent + "          <div class=\"td\">Name</div>" +
				lineindent + "          <div class=\"td\">Path</div>" +
				lineindent + "        </div>"
			for _, lib := range pkg.listlib {
				libraries += "" +
					lineindent + "        <div class=\"tr\">" +
					lineindent + "          <div class=\"td\">" + HtmlFromString(lib.name) + "</div>" +
					lineindent + "          <div class=\"td\">" + HtmlFromString(lib.path) + "</div>" +
					lineindent + "        </div>"
			}
			libraries += "" +
				lineindent + "      </div>" +
				lineindent + "    </li>" +
				lineindent + "  </ul>"
		}
		detail += "" +
			lineindent + "<div class=\"d\" id=\"d_pkg_" + HtmlNameFromPackage(pkg) + "\">" +
			lineindent + "  <div class=\"header\">" + HtmlLinkFromPackageName(pkg.name) + "</div>" +
			lineindent + "  <div class=\"lbl\">Package:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlFromName(pkg.name) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			HtmlFromDoc(pkg.doc, "        ") +
			lineindent + "  <div class=\"lbl\">Libraries:</div>" +
			libraries +
			lineindent + "  <div class=\"lbl\">Types:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + StringFromListStringJoin(pkgtypes, ", ") +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			lineindent + "  <div class=\"lbl\">Constants:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + StringFromListStringJoin(pkgconsts, ", ") +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			lineindent + "  <div class=\"lbl\">Functions:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + StringFromListStringJoin(pkgfuncs, ", ") +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			HtmlFromSourceCode(pkg.textblock.text, indent+"  ") +
			lineindent + "</div>" +
			typedetail +
			constdetail +
			funcdetail
	}
	return nav, detail
}

func HtmlFromProject(prj *vxproject) string {
	lineindent := "\n"
	nav, detail := HtmlFromListPackage(prj.listpackage, "      ")
	prjpackages := ""
	for _, pkg := range prj.listpackage {
		prjpackages += "" +
			lineindent + "        <ul>" +
			lineindent + "          <li>" + HtmlLinkFromPackageName(pkg.name) + "</li>" +
			lineindent + "        </ul>"
	}
	paths := ""
	if len(prj.listpath) > 0 {
		paths += "" +
			lineindent + "        <ul>" +
			lineindent + "          <li>" +
			lineindent + "            <div class=\"table\">" +
			lineindent + "              <div class=\"th\">" +
			lineindent + "                <div class=\"td\">Name</div>" +
			lineindent + "                <div class=\"td\">Path</div>" +
			lineindent + "              </div>"
		for _, path := range prj.listpath {
			paths += "" +
				lineindent + "              <div class=\"tr\">" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(path.name) + "</div>" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(path.path) + "</div>" +
				lineindent + "              </div>"
		}
		paths += "" +
			lineindent + "            </div>" +
			lineindent + "          </li>" +
			lineindent + "        </ul>"
	}
	commands := ""
	if len(prj.listcmd) > 0 {
		commands += "" +
			lineindent + "        <ul>" +
			lineindent + "          <li>" +
			lineindent + "            <div class=\"table\">" +
			lineindent + "              <div class=\"th\">" +
			lineindent + "                <div class=\"td\">Name</div>" +
			lineindent + "                <div class=\"td\">Code</div>" +
			lineindent + "                <div class=\"td\">Path</div>" +
			lineindent + "                <div class=\"td\">Language</div>" +
			lineindent + "                <div class=\"td\">Description</div>" +
			lineindent + "              </div>"
		for _, cmd := range prj.listcmd {
			commands += "" +
				lineindent + "              <div class=\"tr\">" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(cmd.name) + "</div>" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(cmd.code) + "</div>" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(cmd.path) + "</div>" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(cmd.lang) + "</div>" +
				lineindent + "                <div class=\"td\">" + HtmlFromString(cmd.doc) + "</div>" +
				lineindent + "              </div>"
		}
		commands += "" +
			lineindent + "            </div>" +
			lineindent + "          </li>" +
			lineindent + "        </ul>"
	}
	output := "" +
		`<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Project: ` + HtmlFromName(prj.name) + `</title>
	<style>
	  html {
		  height: 100%;
	  }

    body {
      font-family: Arial, Helvetica, sans-serif;
      height: 100%;
      margin: 0px;
    }

    .table {
      display: table;
    }

    .th {
      display: table-header-group;
      background-color: #f2f2f2;
    }

    .tr {
      display: table-row;
    }

    .td {
      display: table-cell;
      overflow: hidden;
      padding: 5px;
      text-overflow: ellipsis;
      min-width: 0px;
      white-space: nowrap;
      border-bottom: 1px solid #d0d0d0;
    }

    ul {
      margin-block-start: 0.5em;
      margin-block-end: 0.5em;
      padding-inline-start: 40px;  
    }

    .nav {
      width: 22%;
      height: 100%;
      overflow: auto;
    }

    .detail {
      width: 78%;
      height: 100%;
      overflow: auto;
    }

    .d {
      display: none;
    }

    .header {
      font-size: 130%;
      font-weight: bold;
      padding-bottom: 1em;
      padding-top: 1em;
    }

    .lbl {
      color: gray;
      font-weight: bold;
      font-size: 100%;
    }

    .nconst {
      color: brown;
      cursor: pointer;
    }

    .nconst:hover {
      color: red;
      background-color: transparent;
      text-decoration: underline;
    }

    .nfunc {
      color: green;
      cursor: pointer;
    }

    .nfunc:hover {
      color: red;
      background-color: transparent;
      text-decoration: underline;
    }

    .npackage {
      color: goldenrod;
      cursor: pointer;
      font-size: 110%;
    }

    .npackage:hover {
      color: red;
      background-color: transparent;
      text-decoration: underline;
    }

    .nproject {
      color: orange;
      cursor: pointer;
      font-size: 120%;
      padding-bottom: 3px;
    }

    .nproject:hover {
      color: red;
      background-color: transparent;
      text-decoration: underline;
    }

    .ntype {
      color: blue;
      cursor: pointer;
    }

    .ntype:hover {
      color: red;
      background-color: transparent;
      text-decoration: underline;
    }

    .packagenav {
      list-style-type: none;
      margin-block-start: 0.5em;
      margin-block-end: 0.5em;
      padding-inline-start: 5px;
    }

    .project {
      display: flex;
      flex-wrap: nowrap;
      height: 100%;
      width: 100%;
    }

    .source {
      display: block;
      font-family: monospace;
      unicode-bidi: embed;
      white-space: pre;
    }

    .test {
      display: block;
      font-family: monospace;
      unicode-bidi: embed;
      white-space: pre;
    }

    .txt {
      font-size: 100%;
    }
  </style>
  <script>
    const docjs = {
      selected: null,
/*
      packagename_click: function (element) {
        const elementid = element.id
        const navelement = document.getElementById('n_' + elementid)
        docjs.visibilitytoggle(navelement)
      },
*/
      navigate: function (elementid) {
        if (docjs.selected != null) {
          docjs.visibilityhide(docjs.selected)
          docjs.selected = null
        }
        const detailelement = document.getElementById('d_' + elementid)
        docjs.visibilityshow(detailelement)
        docjs.selected = detailelement
      },

      visibilityhide: function (element) {
        element.style.display = 'none'
      },

      visibilityshow: function (element) {
        element.style.display = 'block'
      },

      visibilitytoggle: function (element) {
        const style = element.style
        let display = style.display
        switch (display) {
        case 'none':
          docjs.visibilityshow(element)
          break
        default:
          docjs.visibilityhide(element)
          break
        }
      }
    }
	</script>
</head>
<body onload="docjs.navigate('prj')">
  <noscript>Warning: JavaScript disabled in browser.</noscript>
  <div class="project" id="project">
    <div class="nav" id="nav">
    <div class="nproject" onclick="docjs.navigate('prj')">project</div>
    ` + nav + `
    </div>
    <div class="detail" id="detail">
      <div class="d" id="d_prj">
			  <div class="lbl">Project:</div>
        <ul>
          <li>
            <div class="txt">` + HtmlFromName(prj.name) + `</div>
          </li>
        </ul>
        <div class="lbl">Version:</div>
        <ul>
          <li>
            <div class="txt">` + HtmlFromString(prj.version) + `</div>
          </li>
        </ul>
        <div class="lbl">Author:</div>
        <ul>
          <li>
            <div class="txt">` + HtmlFromString(prj.author) + `</div>
          </li>
        </ul>` +
		HtmlFromDoc(prj.doc, "        ") + `
        <div class=\"lbl\">Paths:</div>` +
		paths + `
        <div class="lbl">Commands:</div>` +
		commands + `
        <div class="lbl">Packages:</div>` +
		prjpackages +
		HtmlFromSourceCode(prj.textblock.text, "        ") + `
		  </div>
		  ` + detail + `
    </div>
  </div>
</body>
</html>`
	return output
}

func HtmlFromSourceCode(text string, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		lineindent + "<div class=\"lbl\">Source Code:</div>" +
		lineindent + "<ul>" +
		lineindent + "  <li>" +
		lineindent + "    <div class=\"source\">" + HtmlFromString(text) + "</div>" +
		lineindent + "  </li>" +
		lineindent + "</ul>"
	return output
}

func HtmlFromString(text string) string {
	output := text
	output = StringFromStringFindReplace(output, "&", "&amp;")
	output = StringFromStringFindReplace(output, "<", "&lt;")
	output = StringFromStringFindReplace(output, ">", "&gt;")
	output = StringFromStringFindReplace(output, "\"", "&quot;")
	return output
}

func HtmlFromListTestValue(listtestvalue []vxvalue, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		lineindent + "<div class=\"lbl\">Usage/Test Cases:</div>" +
		lineindent + "<ul>"
	for _, testvalue := range listtestvalue {
		output += "" +
			lineindent + "  <li><div class=\"test\">" + HtmlFromString(testvalue.textblock.text) + "</div></li>"
	}
	output += "" +
		lineindent + "</ul>"
	return output
}

func HtmlFromListType(listtype []*vxtype, indent string) (string, string) {
	lineindent := "\n" + indent
	nav := ""
	detail := ""
	for _, typ := range listtype {
		nav += "" +
			lineindent + "<li class=\"ntype\" onclick=\"docjs.navigate('type_" + HtmlNameFromType(typ) + "')\">" +
			lineindent + "  (t) " + HtmlFromString(typ.name) +
			lineindent + "</li>"
		allowfuncs := ""
		allowtypes := ""
		allowvalues := ""
		disallowfuncs := ""
		disallowtypes := ""
		disallowvalues := ""
		if len(typ.allowfuncs) > 0 {
			allowfuncs += "" +
				lineindent + "  <div class=\"lbl\">Allowed Functions:</div>" +
				lineindent + "  <ul>"
			for _, subfunc := range typ.allowfuncs {
				allowfuncs += "" +
					lineindent + "    <li>" +
					lineindent + "      <div class=\"txt\">" + HtmlLinkNameFromFunc(subfunc) + "</div>" +
					lineindent + "    </li>" +
					lineindent + "  </ul>"
			}
		}
		if len(typ.disallowfuncs) > 0 {
			disallowfuncs += "" +
				lineindent + "  <div class=\"lbl\">Disallow Functions:</div>" +
				lineindent + "  <ul>"
			for _, subfunc := range typ.disallowfuncs {
				disallowfuncs += "" +
					lineindent + "    <li>" +
					lineindent + "      <div class=\"txt\">" + HtmlLinkNameFromFunc(subfunc) + "</div>" +
					lineindent + "    </li>" +
					lineindent + "  </ul>"
			}
		}
		if len(typ.allowtypes) > 0 {
			allowtypes += "" +
				lineindent + "  <div class=\"lbl\">Allowed Types:</div>" +
				lineindent + "  <ul>"
			for _, subtyp := range typ.allowtypes {
				allowtypes += "" +
					lineindent + "    <li>" +
					lineindent + "      <div class=\"txt\">" + HtmlLinkNameFromType(subtyp) + "</div>" +
					lineindent + "    </li>" +
					lineindent + "  </ul>"
			}
		}
		if len(typ.disallowtypes) > 0 {
			disallowtypes += "" +
				lineindent + "  <div class=\"lbl\">Disallow Types:</div>" +
				lineindent + "  <ul>"
			for _, subtyp := range typ.disallowtypes {
				disallowtypes += "" +
					lineindent + "    <li>" +
					lineindent + "      <div class=\"txt\">" + HtmlLinkNameFromType(subtyp) + "</div>" +
					lineindent + "    </li>" +
					lineindent + "  </ul>"
			}
		}
		if len(typ.allowvalues) > 0 {
			allowvalues += "" +
				lineindent + "  <div class=\"lbl\">Allowed Values:</div>" +
				lineindent + "  <ul>"
			for _, subvalue := range typ.allowvalues {
				allowvalues += "" +
					lineindent + "    <li>" +
					lineindent + "      <div class=\"txt\">" + HtmlLinkNameFromConst(subvalue) + "</div>" +
					lineindent + "    </li>" +
					lineindent + "  </ul>"
			}
		}
		if len(typ.disallowvalues) > 0 {
			disallowvalues += "" +
				lineindent + "  <div class=\"lbl\">Disallow Values:</div>" +
				lineindent + "  <ul>"
			for _, subvalue := range typ.disallowvalues {
				disallowvalues += "" +
					lineindent + "    <li>" +
					lineindent + "      <div class=\"txt\">" + HtmlLinkNameFromConst(subvalue) + "</div>" +
					lineindent + "    </li>" +
					lineindent + "  </ul>"
			}
		}
		properties := ""
		if len(typ.properties) > 0 {
			properties += "" +
				lineindent + "  <div class=\"lbl\">Properties:</div>" +
				lineindent + "  <ul>" +
				lineindent + "    <li>" +
				lineindent + "      <div class=\"table\">" +
				lineindent + "        <div class=\"th\">" +
				lineindent + "          <div class=\"td\">Name</div>" +
				lineindent + "          <div class=\"td\">Type</div>" +
				lineindent + "          <div class=\"td\">Description</div>" +
				lineindent + "        </div>"
			for _, property := range typ.properties {
				properties += "" +
					lineindent + "        <div class=\"tr\">" +
					lineindent + "          <div class=\"td\">" + HtmlFromString(property.name) + "</div>" +
					lineindent + "          <div class=\"td\">" + HtmlLinkFromType(property.vxtype) + "</div>" +
					lineindent + "          <div class=\"td\">" + HtmlFromString(property.doc) + "</div>" +
					lineindent + "        </div>"
			}
			properties += "" +
				lineindent + "      </div>" +
				lineindent + "    </li>" +
				lineindent + "  </ul>"
		}
		detail += "" +
			lineindent + "<div class=\"d\" id=\"d_type_" + HtmlNameFromType(typ) + "\">" +
			lineindent + "  <div class=\"header\">" + HtmlLinkFromPackageName(typ.pkgname) + " / " + HtmlLinkNameFromType(typ) + "</div>" +
			lineindent + "  <div class=\"lbl\">Type:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlFromNameAlias(typ.name, typ.alias) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			lineindent + "  <div class=\"lbl\">Extends:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlFromString(typ.extends) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			HtmlFromDoc(typ.doc, indent+"  ") +
			lineindent + "  <div class=\"lbl\">Default:</div>" +
			lineindent + "  <ul>" +
			lineindent + "    <li>" +
			lineindent + "      <div class=\"txt\">" + HtmlFromString(typ.defaultvalue) + "</div>" +
			lineindent + "    </li>" +
			lineindent + "  </ul>" +
			properties +
			allowfuncs +
			allowtypes +
			allowvalues +
			disallowfuncs +
			disallowtypes +
			disallowvalues +
			HtmlFromListTestValue(typ.testvalues, indent+"  ") +
			HtmlFromSourceCode(typ.textblock.text, indent+"  ") +
			lineindent + "</div>"
	}
	return nav, detail
}

func HtmlLinkFromConst(cnst *vxconst) string {
	output := "" +
		"<span class=\"nconst\" onclick=\"docjs.navigate('const_" + HtmlNameFromConst(cnst) + "')\">" + HtmlFromString(cnst.pkgname) + "/" + HtmlFromString(cnst.name) + "</span>"
	return output
}

func HtmlLinkFromFunc(fnc *vxfunc) string {
	output := "" +
		"<span class=\"nfunc\" onclick=\"docjs.navigate('func_" + HtmlNameFromFunc(fnc) + "')\">" + HtmlFromString(fnc.pkgname) + "/" + HtmlFromString(fnc.name) + "</span>"
	return output
}

func HtmlLinkFromPackageName(pkgname string) string {
	output := "" +
		"<span class=\"npackage\" onclick=\"docjs.navigate('pkg_" + HtmlFromString(pkgname) + "')\">" + HtmlFromString(pkgname) + "</span>"
	return output
}

func HtmlLinkFromType(typ *vxtype) string {
	output := "" +
		"<span class=\"ntype\" onclick=\"docjs.navigate('type_" + HtmlNameFromType(typ) + "')\">" + HtmlFromString(typ.pkgname) + "/" + HtmlFromString(typ.name) + "</span>"
	return output
}

func HtmlLinkNameFromConst(cnst *vxconst) string {
	output := "" +
		"<span class=\"nconst\" onclick=\"docjs.navigate('const_" + HtmlNameFromConst(cnst) + "')\">" + HtmlFromString(cnst.name) + "</span>"
	return output
}

func HtmlLinkNameFromFunc(fnc *vxfunc) string {
	output := "" +
		"<span class=\"nfunc\" onclick=\"docjs.navigate('func_" + HtmlNameFromFunc(fnc) + "')\">" + HtmlFromString(fnc.name) + "</span>"
	return output
}

func HtmlLinkNameFromType(typ *vxtype) string {
	output := "" +
		"<span class=\"ntype\" onclick=\"docjs.navigate('type_" + HtmlNameFromType(typ) + "')\">" + HtmlFromString(typ.name) + "</span>"
	return output
}

func HtmlNameFromConst(cnst *vxconst) string {
	output := HtmlFromName(cnst.pkgname) + "/" + HtmlFromName(cnst.name)
	return output
}

func HtmlNameFromFunc(fnc *vxfunc) string {
	output := HtmlFromName(fnc.pkgname) + "/" + HtmlFromName(fnc.name)
	if fnc.idx > 0 {
		output += "_" + StringFromInt(fnc.idx)
	}
	return output
}

func HtmlNameFromPackage(pkg *vxpackage) string {
	output := HtmlFromName(pkg.name)
	return output
}

func HtmlNameFromType(typ *vxtype) string {
	output := HtmlFromName(typ.pkgname) + "/" + HtmlFromName(typ.name)
	return output
}

func WriteDocFromProjectCmd(project *vxproject, command *vxcommand) *vxmsgblock {
	msgblock := NewMsgBlock("WriteDocFromProjectCmd")
	html := HtmlFromProject(project)
	file := NewFile()
	file.name = "doc.html"
	file.path = PathFromProjectCmd(project, command)
	file.text = html
	msgs := WriteFile(file)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	return msgblock
}
