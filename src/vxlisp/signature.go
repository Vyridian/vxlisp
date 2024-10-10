package vxlisp

type vxsignature struct {
	name          string
	idx           int
	vxtype        *vxtype
	listgeneric   []string
	listsignature []*vxsignature
	multi         bool
}

func NewSignature() *vxsignature {
	return new(vxsignature)
}

func NewTypeFromSignature(
	typ *vxtype) *vxsignature {
	output := NewSignature()
	output.name = NameFromType(typ)
	output.vxtype = typ
	return output
}

func IsSignatureMatch(
	template *vxsignature,
	actual *vxsignature,
	index int,
	path string) bool {
	var output = true
	templatelen := len(template.listsignature)
	actuallen := len(actual.listsignature)
	templatetype := template.vxtype
	actualtype := actual.vxtype
	if template == emptysignature {
	} else if templatetype.isfunc {
		var templatesignature *vxsignature
		for i, actualsignature := range actual.listsignature {
			if i >= templatelen {
				templatesignature = template.listsignature[templatelen-1]
			} else {
				templatesignature = template.listsignature[i]
			}
			output = IsSignatureMatch(
				templatesignature, actualsignature, i, path)
		}
	} else if actualtype.isfunc && NameFromType(templatetype) == "vx/core/any" {
		output = true
	} else if templatelen == 0 && actuallen == 0 {
		var multi = template.multi
		if templatetype == nil {
			output = false
		} else if actualtype == nil {
			output = false
		} else if templatetype == actualtype {
			//} else if len(template.listgeneric) > 0 {
			//	_, output, _ = BooleanTypeGenericMatch(templatetype, actualtype, multi, index, path)
		} else {
			_, output, _ = BooleanMatchFromTypeType(
				templatetype, actualtype, multi, index, path)
		}
	} else if templatelen == 0 || actuallen == 0 {
		output = false
	} else if templatelen > actuallen {
		output = false
	} else if templatelen < actuallen {
		lastsignature := template.listsignature[templatelen-1]
		if !lastsignature.multi {
			output = false
		} else {
			var templatesignature *vxsignature
			output = true
			for i, actualsignature := range actual.listsignature {
				if i >= templatelen {
					templatesignature = template.listsignature[templatelen-1]
				} else {
					templatesignature = template.listsignature[i]
				}
				ispass := IsSignatureMatch(
					templatesignature, actualsignature, i, path)
				if !ispass {
					output = false
					break
				}
			}
		}
	} else {
		output = true
		for i, actualsignature := range actual.listsignature {
			templatesignature := template.listsignature[i]
			ispass := IsSignatureMatch(
				templatesignature, actualsignature, i, path)
			if !ispass {
				output = false
			}
		}
	}
	return output
}

func SignatureFromFunc(
	fnc *vxfunc,
	path string) *vxsignature {
	var output = NewSignature()
	output.name = NameFromFunc(fnc)
	output.idx = fnc.idx
	output.vxtype = fnc.vxtype
	var listsignature []*vxsignature
	listsignature = append(
		listsignature, NewTypeFromSignature(fnc.vxtype))
	switch NameFromFunc(fnc) {
	case "vx/core/fn":
		fnargs := FuncFnGetArgList(fnc)
		for _, arg := range fnargs {
			argsignature := NewTypeFromSignature(arg.vxtype)
			argsignature.name = arg.name
			if arg.multi {
				argsignature.multi = true
			}
			listsignature = append(
				listsignature, argsignature)
		}
	default:
		for _, arg := range fnc.listarg {
			argtype := arg.vxtype
			argvalue := arg.value
			argvaluetype := argvalue.vxtype
			if argvaluetype != emptytype {
				argtype = argvaluetype
			}
			var argsignature *vxsignature
			if argtype.isfunc {
				argfunc := argtype.vxfunc
				subpath := path + "/" + argfunc.name
				argsignature = SignatureFromFunc(
					argfunc, subpath)
				argsignature.vxtype = argtype
			} else if argvalue.code == ":func" && argvalue.name == "fn" {
				argfunc := FuncFromValue(argvalue)
				subpath := path + "/" + argfunc.name
				argsignature = SignatureFromFunc(
					argfunc, subpath)
				argsignature.vxtype = argtype
			} else {
				argsignature = NewTypeFromSignature(argtype)
				argsignature.name = arg.name
			}
			if arg.multi {
				argsignature.multi = true
			}
			listsignature = append(
				listsignature, argsignature)
		}
	}
	if len(listsignature) > 0 {
		output.listsignature = listsignature
	}
	return output
}

func StringFromSignature(signature *vxsignature) string {
	return StringIndentFromSignature(signature, "")
}

func StringFromListSignature(signatures []*vxsignature) string {
	return StringIndentFromListSignature(signatures, "")
}

func StringIndentFromSignature(signature *vxsignature, indent string) string {
	lineindent := "\n" + indent
	subsignatures := ""
	if len(signature.listsignature) > 0 {
		subsignatures = lineindent + " :signatures " + StringIndentFromListSignature(signature.listsignature, indent+" ")
	}
	multi := ""
	if signature.multi {
		multi = lineindent + " :multi " + StringFromBoolean(true)
	}
	idx := ""
	if signature.idx > 0 {
		idx = lineindent + " :idx      " + StringFromInt(signature.idx)
	}
	output := "" +
		"(signature" +
		lineindent + " :name     " + signature.name +
		idx +
		lineindent + " :type     " + NameFromType(signature.vxtype) +
		lineindent + " :generics " + StringFromListString(signature.listgeneric) +
		subsignatures +
		multi + ")"
	return output
}

func StringIndentFromListSignature(listsignature []*vxsignature, indent string) string {
	lineindent := "\n" + indent + " "
	output := "(signaturelist"
	for _, signature := range listsignature {
		output += lineindent + StringIndentFromSignature(signature, indent+" ")
	}
	output += ")"
	return output
}
