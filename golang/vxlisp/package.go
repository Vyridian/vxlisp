package vxlisp

type vxpackage struct {
	name      string
	alias     string
	doc       string
	listlib   []*vxlibrary
	textblock *vxtextblock
	listconst []*vxconst
	listfunc  []*vxfunc
	listtype  []*vxtype
	mapconst  map[string]*vxconst
	mapfunc   map[string][]*vxfunc
	maptype   map[string]*vxtype
	project   *vxproject
}

func NewMapPackage() map[string]*vxpackage {
	return make(map[string]*vxpackage)
}

func NewPackage() *vxpackage {
	output := new(vxpackage)
	output.listlib = emptylistlibrary
	output.textblock = emptytextblock
	return output
}

func LibraryPathFromPackage(pkg *vxpackage, libname string) string {
	output := ""
	if libname == pkg.name {
		output = libname
	} else {
		for _, lib := range pkg.listlib {
			if lib.name == libname {
				output = lib.path
			}
		}
	}
	return output
}

func ListPackageLink(listpackage []*vxpackage) ([]*vxpackage, *vxmsgblock) {
	msgblock := NewMsgBlock("PackagesLink")
	listpackage = ListPackageUpdateMaps(listpackage)
	pkgmap := MapPackageFromListPackage(listpackage)
	for _, pkg := range listpackage {
		pkgname := pkg.name
		path := pkgname
		scopes := ListScopeFromPackage(pkg, pkgmap)
		_, msgs := ListTypeLink(pkg.listtype, scopes, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	for _, pkg := range listpackage {
		pkgname := pkg.name
		path := pkgname
		scopes := ListScopeFromPackage(pkg, pkgmap)
		_, msgs := ListConstLink(pkg.listconst, scopes, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	for _, pkg := range listpackage {
		pkgname := pkg.name
		path := pkgname
		scopes := ListScopeFromPackage(pkg, pkgmap)
		_, msgs := ListFuncLink(pkg.listfunc, scopes, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	for _, pkg := range listpackage {
		pkgname := pkg.name
		path := pkgname
		scopes := ListScopeFromPackage(pkg, pkgmap)
		_, msgs := ListTypeLinkValues(pkg.listtype, scopes, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		_, msgs = ListConstLinkValues(pkg.listconst, scopes, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		_, msgs = ListFuncLinkValues(pkg.listfunc, scopes, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return listpackage, msgblock
}

func ListPackageUpdateMaps(listpackage []*vxpackage) []*vxpackage {
	for _, pkg := range listpackage {
		typmap := MapTypeFromListType(pkg.listtype)
		pkg.maptype = typmap
		constmap := MapConstFromListConst(pkg.listconst)
		pkg.mapconst = constmap
		funcmap := MapFuncFromListFunc(pkg.listfunc)
		pkg.mapfunc = funcmap
	}
	return listpackage
}

func ListPackageValidate(listpackage []*vxpackage) ([]*vxpackage, *vxmsgblock) {
	msgblock := NewMsgBlock("ListPackageValidate")
	for _, pkg := range listpackage {
		path := pkg.name
		// funcs
		_, msgs := ListFuncValidate(pkg.listfunc, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		// types
		_, msgs = ListTypeValidate(pkg.listtype, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
		// consts
		_, msgs = ListConstValidate(pkg.listconst, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return listpackage, msgblock
}

func ListPackageValidateLibraries(listpackage []*vxpackage, prj *vxproject) ([]*vxpackage, *vxmsgblock) {
	msgblock := NewMsgBlock("ListPackageValidateLibraries")
	mappackage := MapPackageFromListPackage(listpackage)
	mapprjlib := MapLibraryFromListLibrary(prj.listlib)
	for _, pkg := range listpackage {
		listlib := pkg.listlib
		for _, lib := range listlib {
			libpath := lib.path
			_, ok := mappackage[libpath]
			if !ok {
				libname := lib.name
				prjlib, ok := mapprjlib[libname]
				if ok {
					lib.path = prjlib.path
					lib.lang = prjlib.lang
				} else {
					msg := NewMsgFromTextblock(pkg.textblock, "Package Path Not Found in Project", StringFromLibrary(lib))
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
		}
	}
	return listpackage, msgblock
}

func ListPackageValidateTypes(listpackage []*vxpackage) ([]*vxpackage, *vxmsgblock) {
	msgblock := NewMsgBlock("ListPackageValidateTypes")
	for _, pkg := range listpackage {
		pkgname := pkg.name
		path := pkgname
		_, msgs := ListTypeValidate(pkg.listtype, path)
		msgblock = MsgblockAddBlock(msgblock, msgs)
	}
	return listpackage, msgblock
}

func ListScopeFromPackage(pkg *vxpackage, pkgmap map[string]*vxpackage) []vxscope {
	var scopes []vxscope
	var scopefound = false
	for _, lib := range pkg.listlib {
		libname := lib.name
		libpath := lib.path
		liblang := lib.lang
		if libname == "" {
			libname = libpath
		}
		if libpath == pkg.name {
			scopefound = true
		} else if liblang != "" {
		} else {
			libpkg, ok := pkgmap[libpath]
			if ok {
				scope := ScopeNew()
				scope.pkgname = libpath
				scope.mapconst = libpkg.mapconst
				scope.mapfunc = libpkg.mapfunc
				scope.maptype = libpkg.maptype
				scopes = append(scopes, scope)
			} else {
				MsgLog("Package Missing:", libname, libpath, len(pkgmap))
			}
		}
	}
	if !scopefound {
		scope := ScopeNew()
		scope.pkgname = pkg.name
		scope.mapconst = pkg.mapconst
		scope.mapfunc = pkg.mapfunc
		scope.maptype = pkg.maptype
		scopes = append(scopes, scope)
	}
	return scopes
}

func MapPackageFromListPackage(listpackage []*vxpackage) map[string]*vxpackage {
	var pkgmap = NewMapPackage()
	for _, pkg := range listpackage {
		pkgmap[pkg.name] = pkg
	}
	return pkgmap
}

func PackageFromTextblock(textblock *vxtextblock) (*vxpackage, *vxmsgblock) {
	msgblock := NewMsgBlock("PackageFromTextblock")
	pkg := NewPackage()
	pkgfound := false
	for _, subtextblock := range textblock.listtextblock {
		switch subtextblock.blocktype {
		case "/*":
		case "(":
			listwordtextblock := subtextblock.listtextblock
			if len(listwordtextblock) < 2 {
				msg := NewMsgFromTextblock(subtextblock, "Empty Block Found")
				msgblock = MsgblockAddError(msgblock, msg)
			} else {
				phrasetypeblock := listwordtextblock[0]
				phrasetype := phrasetypeblock.text
				switch phrasetype {
				case "package":
					if pkgfound {
						msg := NewMsgFromTextblock(subtextblock, "Invalid BlockType:", subtextblock.blocktype)
						msgblock = MsgblockAddError(msgblock, msg)
					} else {
						pkgfound = true
						pkg.textblock = textblock
						lastprop := ""
						var liststandardlib []string
						liststandardlib = append(liststandardlib, "vx/core")
						liststandardlib = append(liststandardlib, "vx/test")
						for i, wordtextblock := range subtextblock.listtextblock {
							prop := wordtextblock.text
							switch i {
							case 0:
								switch prop {
								case "package":
								default:
									msg := NewMsgFromTextblock(textblock, "Invalid Package:", prop)
									msgblock = MsgblockAddError(msgblock, msg)
								}
							case 1:
								pkg.name = prop
								for _, standardlib := range liststandardlib {
									if standardlib == pkg.name {
									} else {
										libpath := standardlib
										lib := NewLibrary()
										lib.name = libpath
										lib.path = libpath
										pkg.listlib = append(pkg.listlib, lib)
									}
								}
							default:
								switch wordtextblock.blocktype {
								case "//":
								default:
									if BooleanFromStringStarts(prop, ":") {
										switch prop {
										case ":alias", ":doc", ":libs":
											lastprop = prop
										default:
											msg := NewMsgFromTextblock(wordtextblock, "Invalid Keyword:", prop)
											msgblock = MsgblockAddError(msgblock, msg)
										}
									} else {
										switch lastprop {
										case ":alias":
											pkg.alias = prop
											lastprop = ""
										case ":doc":
											pkg.doc = prop
											lastprop = ""
										case ":libs":
											lib, msgs := LibraryFromTextblock(wordtextblock)
											msgblock = MsgblockAddBlock(msgblock, msgs)
											pkg.listlib = append(pkg.listlib, lib)
										default:
											msg := NewMsgFromTextblock(wordtextblock, "Invalid Keyword:", prop)
											msgblock = MsgblockAddError(msgblock, msg)
										}
									}
								}
							}
						}
						if pkg.alias == "" {
							pkg.alias = StringFromStringFindReplace(pkg.name, "/", "_")
						}

					}
				case "const":
					if !pkgfound {
						msg := NewMsgFromTextblock(subtextblock, "Const Found Before Package")
						msgblock = MsgblockAddError(msgblock, msg)
					}
					cnst, msgs := ConstFromTextblock(subtextblock, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					pkg.listconst = append(pkg.listconst, cnst)
				case "func":
					if !pkgfound {
						msg := NewMsgFromTextblock(subtextblock, "Func Found Before Package")
						msgblock = MsgblockAddError(msgblock, msg)
					}
					fnc, msgs := FuncFromTextblock(subtextblock, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					pkg.listfunc = append(pkg.listfunc, fnc)
				case "type":
					if !pkgfound {
						msg := NewMsgFromTextblock(subtextblock, "Type Found Before Package")
						msgblock = MsgblockAddError(msgblock, msg)
					}
					typ, msgs := TypeFromTextblock(subtextblock, pkg)
					msgblock = MsgblockAddBlock(msgblock, msgs)
					pkg.listtype = append(pkg.listtype, typ)
				default:
					msg := NewMsgFromTextblock(subtextblock, "Invalid Block Found", phrasetype)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
		default:
			msg := NewMsgFromTextblock(subtextblock, "Invalid BlockType:", subtextblock.blocktype)
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	return pkg, msgblock
}

func PackagePathNameFromName(pkgname string) (string, string) {
	path := ""
	name := ""
	ipos := IntFromStringIndexLast(pkgname, "/")
	if ipos > 0 {
		path = pkgname[0 : ipos+1]
		name = pkgname[ipos+1:]

	}
	return path, name
}

func StringFromPackage(pkg *vxpackage) string {
	return StringFromPackageIndent(pkg, "")
}

func StringFromPackageIndent(pkg *vxpackage, indent string) string {
	lineindent := "\n" + indent
	output := "" +
		"{package" +
		lineindent + ":name  \"" + pkg.name + "\"" +
		lineindent + ":alias \"" + pkg.alias + "\"" +
		lineindent + ":doc   \"" + pkg.doc + "\"" +
		lineindent + ":libs " + StringFromListLibraryIndent(pkg.listlib, indent+" ") +
		lineindent + ":types " + StringFromListTypeIndent(pkg.listtype, indent+" ") +
		lineindent + ":consts " + StringFromListConstIndent(pkg.listconst, indent+" ") +
		lineindent + ":funcs " + StringFromListFuncIndent(pkg.listfunc, indent+" ") +
		"}"
	StringFromTextblock(pkg.textblock)
	return output
}
