package vxlisp

type vxscope struct {
	pkgname  string
	pkgshort string
	maparg   map[string]vxarg
	mapconst map[string]*vxconst
	mapfunc  map[string][]*vxfunc
	maptype  map[string]*vxtype
}

func ScopeNew() vxscope {
	return *new(vxscope)
}

func ArgFromListScope(listscope []vxscope, argname string) (vxarg, bool) {
	var arg vxarg
	var ok = false
	for _, scope := range listscope {
		argmap := scope.maparg
		arg, ok = argmap[argname]
		if ok {
			break
		}
	}
	return arg, ok
}

func ConstFromListScope(listscope []vxscope, pkgname string, cnstname string) (*vxconst, bool) {
	var cnst *vxconst
	var ok = false
	if pkgname == "" {
		var ipos = IntFromStringFindLast(cnstname, "/")
		if ipos > 0 {
			cnstname = cnstname[ipos+1:]
		}
	}
	for _, scope := range listscope {
		if pkgname == "" {
			mapconst := scope.mapconst
			cnst, ok = mapconst[cnstname]
			if ok {
				break
			}
		} else if (scope.pkgname == pkgname) || (scope.pkgshort == pkgname) {
			mapconst := scope.mapconst
			cnst, ok = mapconst[cnstname]
			break
		}
	}
	return cnst, ok
}

func FuncFromListScope(listscope []vxscope, pkgname string, fncname string, signature *vxsignature, path string) (*vxfunc, bool) {
	var fnc *vxfunc
	var listfunc []*vxfunc
	var ok = false
	for _, scope := range listscope {
		if (pkgname == "") || (scope.pkgname == pkgname) || (scope.pkgshort == pkgname) {
			mapfunc := scope.mapfunc
			listfunc, ok = mapfunc[fncname]
			if ok {
				if len(listfunc) == 1 {
					fnc = listfunc[0]
				} else {
					var isfound = false
					for _, lookupfunc := range listfunc {
						if signature == emptysignature {
							fnc = lookupfunc
							isfound = true
						} else {
							lookupsignature := SignatureFromFunc(lookupfunc, path)
							if IsSignatureMatch(lookupsignature, signature, 0, path) {
								fnc = lookupfunc
								isfound = true
							}
						}
						if isfound {
							break
						}
					}
					if !isfound {
						ok = false
					}
				}
				break
			}
		}
	}
	return fnc, ok
}

func ListScopeAddFuncArg(listscope []vxscope, fnc *vxfunc) []vxscope {
	output := listscope
	if len(fnc.listarg) > 0 || fnc.context {
		funcscope := ScopeFromFunc(fnc)
		funcscope.pkgname = ":args"
		output = append([]vxscope{funcscope}, listscope...)
	}
	return output
}

func ListScopeAddFuncLocalArg(listscope []vxscope, fnc *vxfunc) []vxscope {
	output := listscope
	localargs := ListArgLocalFromFunc(fnc)
	if len(localargs) > 0 {
		funcscope := ScopeFromListFuncArg(localargs)
		funcscope.pkgname = ":localargs"
		output = append([]vxscope{funcscope}, listscope...)
	}
	return output
}

func StringFromScope(scope vxscope) string {
	return StringFromScopeIndent(scope, "")
}

func StringFromScopeIndent(scope vxscope, indent string) string {
	output := "" +
		indent + "(scope" +
		"\n" + indent + " :name    " + scope.pkgname +
		"\n" + indent + " :argmap  " + StringFromListStringJoin(ListKeyFromMapArg(scope.maparg), ", ") +
		//"\n" + indent + " :argmap  " + TextFromArgMapIndent(scope.argmap, indent) +
		"\n" + indent + " :cnstmap " + StringFromListStringJoin(ListKeyFromMapConst(scope.mapconst), ", ") +
		"\n" + indent + " :funcmap " + StringFromListStringJoin(ListKeyFromMapFunc(scope.mapfunc), ", ") +
		"\n" + indent + " :typemap " + StringFromListStringJoin(ListKeyFromMapType(scope.maptype), ", ") +
		"\n" + indent + ")" +
		"\n"
	return output
}

func StringFromListScope(listscope []vxscope) string {
	return StringFromListScopeIndent(listscope, "")
}

func StringFromListScopeIndent(listscope []vxscope, indent string) string {
	output := indent + "(scopelist\n"
	for _, scope := range listscope {
		output += StringFromScopeIndent(scope, indent+"  ")
	}
	output += indent + ")\n"
	return output
}

func TypeFromListScope(listscope []vxscope, pkgname string, typename string, path string) (*vxtype, bool) {
	var typ *vxtype
	var ok = false
	isgeneric := false
	origname := typename
	ipos := IntFromStringFindLast(typename, "-1")
	if ipos < 0 {
		ipos = IntFromStringFindLast(typename, "-2")
	}
	if ipos < 0 {
		ipos = IntFromStringFindLast(typename, "-3")
	}
	if ipos < 0 {
		ipos = IntFromStringFindLast(typename, "-4")
	}
	if ipos < 0 {
		ipos = IntFromStringFindLast(typename, "-5")
	}
	if ipos >= 0 {
		typename = StringSubstring(typename, 0, ipos)
		isgeneric = true
	}
	for _, scope := range listscope {
		if pkgname == "" {
			typmap := scope.maptype
			typ, ok = typmap[typename]
			if ok {
				break
			}
		} else if (scope.pkgname == pkgname) || (scope.pkgshort == pkgname) {
			typmap := scope.maptype
			typ, ok = typmap[typename]
			break
		}
	}
	if ok && isgeneric {
		typ = NewTypeCopy(typ)
		typ.name = origname
		typ.alias = "generic-" + origname
		typ.isgeneric = true
	}
	return typ, ok
}

func TypeOrFuncFromListScope(listscope []vxscope, pkgname string, typename string, path string) (*vxtype, bool) {
	typ, ok := TypeFromListScope(listscope, pkgname, typename, path)
	if !ok {
		lookupfunc, okfunc := FuncFromListScope(listscope, pkgname, typename, emptysignature, path)
		if okfunc {
			ok = true
			typ = NewTypeFromFunc(lookupfunc)
		}
	}
	return typ, ok
}
