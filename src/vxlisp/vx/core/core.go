package vx_core

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"testing"
)

var outputlog = false
var outputFile *os.File
var outputWriter *bufio.Writer

func V_any_from_any_keyn(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_generic Type_generic = V_generic_from_any(type_any)
	var output *Type_any = type_generic.p_any_from_any_keyn(
		type_any,
		keyn)
	return output
}

func V_anylist_from_listtype_anylist_anylist(
	listtype []*Type_type,
	orig_anylist *Type_anylist,
	type_anylist *Type_anylist) *Type_anylist {
	return E_anylist
}

func V_booleann_from_liststringn_containsn(
	liststringn []string,
	containsn string) bool {
	output := false
	pos := V_intn_from_liststringn_findn(
		liststringn,
		containsn)
	if pos >= 0 {
		output = true
	}
	return output
}

func V_booleann_from_stringn_containsn(
	stringn string,
	contains string) bool {
	return strings.Contains(
		stringn,
		contains)
}

func V_booleann_from_stringn_startsn(
	stringn string,
	startsn string) bool {
	return strings.HasPrefix(
		stringn,
		startsn)
}

// V_code_from_any
func V_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_generic Type_generic = V_generic_from_any(
		type_any)
	var output string = type_generic.p_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
	return output
}

func V_code_from_listany(
	type_lang *Type_scope,
	indent int,
	path string,
	listany []*Type_any) string {
	var liststring []string = []string{}
	for _, type_any := range listany {
		var stringn string = V_code_from_any(
			type_lang,
			indent,
			path,
			type_any)
		liststring = append(liststring, stringn)
	}
	var output string = V_stringn_from_liststringn_joinn(
		liststring,
		"")
	return output
}

// V_code_const_name
func V_code_const_name(
	type_scope *Type_scope,
	type_const *Type_const) string {
	var type_lang = type_scope.P_lang
	var prefix = "c_"
	switch type_lang {
	case C_lang_go:
		prefix = "C_"
	}
	var output string = "" +
		V_code_pkgnamen(
			type_scope,
			type_const.P_pkgname) +
		prefix +
		V_code_namen(
			type_scope,
			type_const.P_name)
	return output
}

// V_code_pkgnamen
func V_code_pkgnamen(
	type_scope *Type_scope,
	pkgnamen string) string {
	var type_lang *Type_lang = type_scope.P_lang
	var type_package = type_scope.P_package
	var isskip bool = false
	var output string = ""
	switch type_lang {
	case C_lang_csharp:
		output = V_stringn_ucasefirst_from_stringn_delimn(
			pkgnamen,
			"/")
		output = V_stringn_from_stringn_findn_replacen(
			output,
			"/",
			".")
	case C_lang_go:
		if type_package.P_path == pkgnamen {
			isskip = true
		} else {
			output = V_stringn_ucasefirst_from_stringn_delimn(
				pkgnamen,
				"/")
		}
	case C_lang_java:
		ipos := V_intn_from_stringn_findlastn(
			pkgnamen,
			"/")
		output = V_stringn_from_string_startn_endn(
			pkgnamen,
			ipos+1,
			len(pkgnamen))
		output = V_stringn_uppercasefirst(output)
	case C_lang_swift:
		output = V_stringn_ucasefirst_from_stringn_delimn(
			pkgnamen,
			"/")
		output = V_stringn_from_stringn_findn_replacen(
			output,
			"/",
			"_")
	default:
		output = pkgnamen
	}
	if !isskip {
		output = "" +
			V_code_namen(
				type_scope,
				output) +
			type_lang.P_pkgref
	}
	return output
}

func V_code_e(
	type_scope *Type_scope,
	type_type *Type_type) string {
	var output = ""
	var type_lang *Type_lang = type_scope.P_lang
	switch type_type {
	case T_boolean:
		var prefix = "c_"
		switch type_lang {
		case C_lang_go:
			prefix = "C_"
		}
		output = "" +
			V_code_type_pkgname(
				type_scope,
				type_type) +
			prefix +
			"false"
	case T_booleann:
		output = "false"
	default:
		var prefix = "e_"
		switch type_lang {
		case C_lang_go:
			prefix = "E_"
		}
		output = "" +
			V_code_type_pkgname(
				type_scope,
				type_type) +
			prefix +
			V_code_type_name(
				type_scope,
				type_type)
	}
	return output
}

func V_code_func_var(
	type_scope *Type_scope,
	indent int,
	type_var *Type_var) string {
	var output = ""
	var type_lang *Type_lang = type_scope.P_lang
	var lineindent string = V_code_lineindent(type_scope, indent)
	switch type_lang {
	case C_lang_go:
		output = "" +
			lineindent +
			V_code_name(
				type_scope,
				type_var.P_name) +
			" " +
			V_code_type_typename(
				type_scope,
				type_var.P_type)
	case C_lang_swift:
		output = "" +
			lineindent +
			"_ " +
			V_code_name(
				type_scope,
				type_var.P_name) +
			" : " +
			V_code_type_typename(
				type_scope,
				type_var.P_type)
	}
	return output
}

// V_code_lineindent
func V_code_lineindent(
	type_scope *Type_scope,
	indent int) string {
	var output string = ""
	var type_lang *Type_lang = type_scope.P_lang
	output += "\n" +
		V_stringn_from_stringn_repeatn(
			V_stringn_from_string(type_lang.P_indent),
			indent)
	return output
}

// V_code_name
func V_code_name(
	type_scope *Type_scope,
	type_string *Type_string) string {
	return V_code_namen(
		type_scope,
		V_stringn_from_string(type_string))
}

// V_code_namen
func V_code_namen(
	type_scope *Type_scope,
	namen string) string {
	output := namen
	if output == "extends" {
		output = "extend"
	}
	output = V_stringn_from_stringn_findn_replacen(
		output,
		"->",
		"_to_")
	output = V_stringn_from_stringn_findn_replacen(output, "<-", "_from_")
	output = V_stringn_from_stringn_findn_replacen(output, "<", "lt")
	output = V_stringn_from_stringn_findn_replacen(output, ">", "gt")
	output = V_stringn_from_stringn_findn_replacen(output, "?", "is")
	output = V_stringn_from_stringn_findn_replacen(output, "-", "_")
	output = V_stringn_from_stringn_findn_replacen(output, "/", "_")
	return output
}

func V_code_t(
	type_scope *Type_scope,
	type_type *Type_type) string {
	var type_lang *Type_lang = type_scope.P_lang
	var prefix = "t_"
	switch type_lang {
	case C_lang_go:
		prefix = "T_"
	}
	var output = V_code_type_pkgname(
		type_scope,
		type_type) +
		prefix +
		V_code_type_name(
			type_scope,
			type_type)
	return output
}

// V_code_type_name
func V_code_type_name(
	type_scope *Type_scope,
	type_type *Type_type) string {
	var output = ""
	if type_type != nil {
		output = V_code_namen(
			type_scope, type_type.P_name)
	}
	return output
}

// V_code_type_pkgname
func V_code_type_pkgname(
	type_scope *Type_scope,
	type_type *Type_type) string {
	var output = "" +
		V_code_pkgnamen(
			type_scope,
			type_type.P_pkgname)
	return output
}

// V_code_type_typename
func V_code_type_typename(
	type_scope *Type_scope,
	type_type *Type_type) string {
	var output = ""
	var type_lang *Type_lang = type_scope.P_lang
	switch type_type.P_path {
	case "booleann":
		switch type_lang {
		case C_lang_go:
			output = "bool"
		case C_lang_swift:
			output = "Bool"
		default:
			output = "Boolean"
		}
	case "floatn":
		switch type_lang {
		case C_lang_go:
			output = "float"
		default:
			output = "Float"
		}
	case "intn":
		switch type_lang {
		case C_lang_go:
			output = "int"
		default:
			output = "Int"
		}
	case "stringn":
		switch type_lang {
		case C_lang_go:
			output = "string"
		default:
			output = "String"
		}
	default:
		switch type_lang {
		case C_lang_go:
			output = "" +
				"*" +
				V_code_type_pkgname(
					type_scope,
					type_type) +
				"Type_" +
				V_code_type_name(
					type_scope,
					type_type)
		default:
			output = "" +
				V_code_type_pkgname(
					type_scope,
					type_type) +
				"Type_" +
				V_code_type_name(
					type_scope,
					type_type)
		}
	}
	return output
}

func V_code_var_name(
	type_scope *Type_scope,
	type_var *Type_var) string {
	var output string = V_code_name(
		type_scope,
		type_var.P_name)
	return output
}

func V_extends_from_any(
	type_any *Type_any) *Type_string {
	var output = V_extends_from_type(
		V_type_from_any(
			type_any))
	return output
}

func V_extends_from_type(
	type_type *Type_type) *Type_string {
	var output = type_type.P_extends
	return output
}

func V_file_stringn_read_from_filenamen(
	filenamen string) (string, *Type_msgblock) {
	text := ""
	msgblock := V_msgblock_from_namen("V_file_stringn_read_from_filenamen")
	var readfilename = filenamen
	var isabsolute = filepath.IsAbs(filenamen)
	if !isabsolute {
		folder, err := os.Getwd()
		for err == nil {
			_, statErr := os.Stat(filepath.Join(folder, "go.mod"))
			if statErr == nil {
				break
			}
			parent := filepath.Dir(folder)
			if parent == folder {
				err = fmt.Errorf("go.mod not found from %s", folder)
				break
			}
			folder = parent
		}
		readfilename = filepath.Join(folder, filenamen)
	}
	content, err := os.ReadFile(readfilename)
	if err == nil {
		text = string(content)
	} else {
		fmt.Println(filenamen)
		fmt.Println(os.Getwd())
		fmt.Println(err)
		msgblock = V_msgblock_from_msgblock_errorn(
			msgblock,
			err)
	}
	return text, msgblock
}

func V_intn_from_liststringn_findn(
	liststringn []string,
	findn string) int {
	output := -1
	for pos, text := range liststringn {
		if text == findn {
			output = pos
		}
	}
	return output
}

func V_intn_from_stringn_findn(
	stringn string,
	findn string) int {
	return strings.Index(stringn, findn)
}

func V_intn_from_stringn_findlastn(
	stringn string,
	findlastn string) int {
	return strings.LastIndex(stringn, findlastn)
}

func V_is_empty(
	type_any *Type_any) *Type_boolean {
	var output *Type_boolean = C_false
	if type_any == E_any {
		output = C_true
	} else {
		var type_const *Type_const = type_any.P_type_const
		if type_const == nil {
		} else if type_const.P_isempty {
			output = C_true
		}
	}
	return output
}

func V_lineindent(
	indent int) string {
	var output = ""
	if indent > 0 {
		output = "\n" + V_stringn_from_stringn_repeatn(" ", indent)
	}
	return output
}

// V_listany_from_any
func V_listany_from_any(
	type_any *Type_any) []*Type_any {
	var type_generic Type_generic = V_generic_from_any(type_any)
	var output []*Type_any = type_generic.p_listany_from_any(
		type_any)
	return output
}

// V_listkey_from_any
func V_listkey_from_any(
	type_any *Type_any) []string {
	var type_generic Type_generic = V_generic_from_any(type_any)
	var output []string = type_generic.p_listkey_from_any(
		type_any)
	return output
}

func V_liststringn_from_liststring(
	liststring []*Type_string) []string {
	var output []string = []string{}
	for _, type_string := range liststring {
		var stringn = V_stringn_from_string(type_string)
		output = append(output, stringn)
	}
	return output
}

func V_log_any(
	type_any *Type_any) {
	var displayn = V_stringn_display_from_any(type_any)
	V_log_stringn(displayn)
}

func V_log_stringn(
	stringn string) {
	fmt.Println(stringn)
	if outputlog {
		_, err := fmt.Fprintln(outputWriter, stringn)
		if err != nil {
			fmt.Println(err)
		}
	}
}

// V_mapany_from_any
func V_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var type_generic Type_generic = V_generic_from_any(
		type_any)
	var output map[string]*Type_any = type_generic.p_mapany_from_any(
		type_any)
	return output
}

func V_stringn_compare_expectedn_actualn(
	expected string,
	actual string,
	size int,
	msgblock *Type_msgblock) string {
	foundline := 0
	errortext := ""
	if msgblock.P_iserror {
		errortext = V_stringn_display_from_any(msgblock.type_any)
	} else if expected != actual {
		expectedlines := V_liststringn_from_stringn_splitn(
			expected,
			"\n")
		actuallines := V_liststringn_from_stringn_splitn(
			actual,
			"\n")
		var maxlen = len(expectedlines)
		if maxlen < len(actuallines) {
			maxlen = len(actuallines)
		}
		foundline = -1
		for line := 0; line < maxlen; line++ {
			expectedline := ""
			actualline := ""
			if line < len(expectedlines) {
				expectedline = expectedlines[line]
			}
			if line < len(actuallines) {
				actualline = actuallines[line]
			}
			if expectedline != actualline {
				foundline = line
				break
			}
		}
		var errortexts []string
		if foundline > -1 {
			var startline = foundline - size
			var endline = foundline + size
			if startline < 0 {
				startline = 0
			}
			if endline > maxlen {
				endline = maxlen - 1
			}
			padding := 0
			for line := startline; line < endline; line++ {
				expectedline := ""
				if line < len(expectedlines) {
					expectedline = expectedlines[line]
				}
				if len(expectedline) > padding {
					padding = len(expectedline)
				}
			}
			for line := startline; line <= endline; line++ {
				expectedline := ""
				actualline := ""
				if line < len(expectedlines) {
					expectedline = expectedlines[line]
				}
				if line < len(actuallines) {
					actualline = actuallines[line]
				}
				paddingtext := ""
				if len(expectedline) < padding {
					paddingtext = V_stringn_from_stringn_repeatn(
						" ",
						padding-len(expectedline))
				}
				errortext := expectedline + paddingtext + " -> " + actualline
				if expectedline != actualline {
					errortext += " * Error *"
				}
				errortexts = append(errortexts, errortext)
			}
		}
		errortext = "Line: " + V_stringn_from_intn(foundline) + "\n" + V_stringn_from_liststringn_joinn(errortexts, "\n")
	}
	return errortext
}

// V_string_copy
func V_string_copy(
	copyval *Type_string,
	anylist *Type_anylist) *Type_string {
	var output *Type_string = copyval
	var merged_anylist *Type_anylist = V_anylist_from_listtype_anylist_anylist(
		[]*Type_type{T_string},
		E_anylist,
		anylist)
	var stringn = ""
	var stringlist *Type_stringlist = V_stringlist_from_anylist(
		merged_anylist)
	var liststringn []string = V_liststringn_from_liststring(
		stringlist.P_liststring)
	stringn = V_stringn_from_liststringn_joinn(
		liststringn,
		"")
	var ischanged = false
	if copyval.P_stringn != stringn {
		ischanged = true
	}
	if ischanged {
		output = V_string_create()
		output.P_stringn = stringn
	}
	return output
}

func V_stringn_display_from_any(
	type_any *Type_any) string {
	return V_stringn_display_from_any_indent(
		type_any, 0)
}

func V_stringn_display_from_any_indent(
	type_any *Type_any,
	indent int) string {
	return V_stringn_display_from_any_indent_first(
		type_any, indent, true)
}

func V_stringn_display_from_any_indent_value(
	type_any *Type_any,
	indent int) string {
	return V_stringn_display_from_any_indent_first(
		type_any, indent, false)
}

func V_stringn_display_from_any_indent_first(
	type_any *Type_any,
	indent int,
	firstn bool) string {
	var output = ""
	var lineindent = V_lineindent(indent)
	var indentfirst = ""
	if firstn {
		indentfirst = lineindent
	}
	var type_const = type_any.P_type_const
	if indent != 0 && type_const != nil {
		output = indentfirst + type_const.P_name
	} else {
		var type_type = type_any.P_type_type
		var typepath = type_type.P_path
		switch typepath {
		case "vx/core/boolean":
			var type_boolean = V_boolean_cast(type_any)
			if type_boolean == C_true {
				output = indentfirst + "true"
			} else {
				output = indentfirst + "false"
			}
		case "vx/core/decimal":
		case "vx/core/float":
		case "vx/core/int":
		case "vx/core/number":
		case "vx/core/string":
			var type_string = V_string_cast(type_any)
			var stringn = type_string.P_stringn
			output = indentfirst + "\"" + stringn + "\""
		case "vx/core/type":
			var typelabel = typepath
			if type_type.P_pkgname == "vx/core" {
				typelabel = type_type.P_name
			}
			output = indentfirst + typelabel + " //" + typepath
		default:
			var props = ""
			var extends = type_type.P_extends
			switch extends {
			case C_extends_list:
				var listany []*Type_any = V_listany_from_any(type_any)
				if len(listany) > 0 {
					var listprop []string = []string{}
					for _, item_any := range listany {
						var prop = V_stringn_display_from_any_indent(
							item_any, indent+1)
						listprop = append(listprop, prop)
					}
					props = V_stringn_from_liststringn(
						listprop)
				}
			case C_extends_map, C_extends_struct, C_extends_func:
				var listkey []string = V_listkey_from_any(
					type_any)
				if len(listkey) > 0 {
					var mapany map[string]*Type_any = V_mapany_from_any(
						type_any)
					var listprop []string = []string{}
					var lineindent1 = V_lineindent(indent + 1)
					var lineindent2 = V_lineindent(indent + 2)
					for _, key := range listkey {
						var item_any, ok = mapany[key]
						if ok {
							if V_booleann_from_stringn_containsn(
								key,
								" ") {
								key = "\"" + key + "\""
							} else {
								key = ":" + key
							}
							/*
								if item_any == nil {
									V_log_stringn(typepath)
									V_log_stringn("key " + key)
									println("nil value")
									item_any = E_any
								}
							*/
							if V_is_empty(item_any) == C_false {
								var valuen = V_stringn_display_from_any_indent_value(
									item_any, indent+2)
								var prop = ""
								if V_booleann_from_stringn_containsn(
									valuen, "\n") {
									prop = lineindent1 + key + lineindent2 + valuen
								} else {
									prop = lineindent1 + key + " " + valuen
								}
								listprop = append(listprop, prop)
							}
						}
					}
					props = V_stringn_from_liststringn(listprop)
				}
			}
			var typelabel = typepath
			if type_type.P_pkgname == "vx/core" {
				typelabel = type_type.P_name
			}
			if type_const != nil {
				if type_const.P_isempty {
					typelabel = "empty " + typelabel
				} else if type_const.P_istype {
					typelabel = "type " + typelabel
				}
			}
			output = indentfirst + "(" + typelabel + props + ")"
		}
	}
	return output
}

func V_stringn_from_intn(
	intn int) string {
	return strconv.Itoa(intn)
}

func V_stringn_from_stringn_aftern(
	stringn string,
	aftern string) string {
	var output = ""
	var posn = V_intn_from_stringn_findn(
		stringn,
		aftern)
	if posn < 0 {
		output = stringn
	} else {
		output = stringn[posn+len(aftern):]
	}
	return output
}

func V_stringn_from_stringn_afterlastn(
	stringn string,
	afterlastn string) string {
	var output = ""
	var posn = V_intn_from_stringn_findlastn(
		stringn,
		afterlastn)
	if posn < 0 {
		output = stringn
	} else {
		output = stringn[posn+len(afterlastn):]
	}
	return output
}

func V_stringn_from_stringn_findn_replacen(
	stringn string,
	findn string,
	replacen string) string {
	var output string = strings.ReplaceAll(stringn, findn, replacen)
	return output
}

func V_stringn_from_stringn_repeatn(
	stringn string,
	repeatn int) string {
	var output string = strings.Repeat(stringn, repeatn)
	return output
}

func V_stringn_from_string_startn_endn(
	stringn string,
	startn int,
	endn int) string {
	startnum := startn
	endnum := endn
	if startnum < 0 {
		startnum = 0
	}
	if endnum < 0 {
		endnum = len(stringn) + endnum
	}
	if endnum < startnum {
		endnum = startnum
	}
	if len(stringn) < startnum {
		startnum = 0
	}
	if len(stringn) < endnum {
		endnum = len(stringn)
	}
	return stringn[startnum:endnum]
}

func V_stringn_ucasefirst_from_stringn_delimn(
	stringn string,
	delimn string) string {
	liststring := V_liststringn_from_stringn_splitn(
		stringn,
		delimn)
	for i, text := range liststring {
		liststring[i] = V_stringn_uppercasefirst(text)
	}
	output := V_stringn_from_liststringn_joinn(
		liststring,
		delimn)
	return output
}

func V_stringlist_from_anylist(
	type_anylist *Type_anylist) *Type_stringlist {
	var liststring []*Type_string = []*Type_string{}
	var listany []*Type_any = type_anylist.P_listany
	for _, type_any := range listany {
		var typenamen = V_typenamen_from_any(type_any)
		switch typenamen {
		case "vx/core/string":
			var type_string = V_string_cast(type_any)
			liststring = append(liststring, type_string)
		}
	}
	var output *Type_stringlist = V_stringlist_create()
	output.P_liststring = liststring
	return output
}

func V_stringn_from_liststringn(
	liststringn []string) string {
	var output string = V_stringn_from_liststringn_joinn(
		liststringn,
		"")
	return output
}

func V_stringn_from_liststringn_joinn(
	liststringn []string,
	joinn string) string {
	var output string = strings.Join(
		liststringn,
		joinn)
	return output
}

func V_stringn_from_string(
	type_string *Type_string) string {
	return type_string.P_stringn
}

func V_liststringn_from_stringn_splitn(
	stringn string,
	splitn string) []string {
	return strings.Split(stringn, splitn)
}

func V_stringn_stripcolon(
	stringn string) string {
	var output string = stringn
	if V_booleann_from_stringn_startsn(
		stringn, ":") {
		output = V_stringn_from_stringn_aftern(
			stringn, ":")
	}
	return output
}

func V_stringn_uppercase(
	stringn string) string {
	var output string = ""
	if len(stringn) > 0 {
		output = strings.ToUpper(stringn)
	}
	return output
}

func V_stringn_uppercasefirst(
	stringn string) string {
	var output string = ""
	if len(stringn) > 0 {
		output = strings.ToUpper(stringn[0:1]) + stringn[1:]
	}
	return output
}

func f_string(
	anylist *Type_anylist) *Type_string {
	var output *Type_string = V_string_copy(E_string, anylist)
	return output
}

func V_test_from_file(
	t *testing.T,
	testnamen string,
	actualn string) bool {
	var filename = "testdata/" + testnamen + ".txt"
	var expectedn, _ = V_file_stringn_read_from_filenamen(filename)
	var output bool = false
	if expectedn == actualn {
		output = true
	} else {
		msgblock := V_msgblock_from_namen("Test_" + testnamen)
		errortext := V_stringn_compare_expectedn_actualn(expectedn, actualn, 10, msgblock)
		if errortext != "" {
			t.Error(errortext)
		}
	}
	return output
}

func V_type_return_from_type(
	type_type *Type_type) *Type_type {
	var output = type_type
	var type_func = V_func_from_type(type_type)
	if type_func != E_func {
		output = type_func.P_return_type
	}
	return output
}

func V_typenamen_from_any(
	type_any *Type_any) string {
	var output = V_typenamen_from_type(
		V_type_from_any(type_any))
	return output
}

func V_typenamen_from_type(
	type_type *Type_type) string {
	var output = type_type.P_name
	return output
}

// Type_generic
type Type_generic interface {
	p_any_from_any_indexn(
		type_any *Type_any,
		indexn int) *Type_any
	p_any_from_any_keyn(
		type_any *Type_any,
		keyn string) *Type_any
	p_count_from_any(
		type_any *Type_any) []*Type_any
	p_code_from_any(
		lang *Type_scope,
		indent int,
		path string,
		type_any *Type_any) string
	p_func() *Type_func
	p_listany_from_any(
		type_any *Type_any) []*Type_any
	p_listkey_from_any(
		type_any *Type_any) []string
	p_mapany_from_any(
		type_any *Type_any) map[string]*Type_any
}

// Type_generic
type Type_generic_base struct {
	Type_generic
}

func (type_generic Type_generic_base) p_any_from_any_keyn(
	type_any *Type_any,
	keyn string) *Type_any {
	var output *Type_any = E_any
	return output
}

func (type_generic Type_generic_base) p_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	var output *Type_any = E_any
	return output
}

func (type_generic Type_generic_base) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output string = ""
	return output
}

func (type_generic Type_generic_base) p_count_any(
	type_any *Type_any) int {
	var output int = 0
	var type_type *Type_type = type_any.P_type_type
	switch type_type.P_extends {
	case C_extends_list:
		var listany []*Type_any = type_generic.p_listany_from_any(type_any)
		output = len(listany)
	case C_extends_map, C_extends_struct, C_extends_func:
		var listkey []string = type_generic.p_listkey_from_any(type_any)
		output = len(listkey)
	}
	return output
}

func (type_generic Type_generic_base) p_func() *Type_func {
	var output *Type_func = E_func
	return output
}

func (type_generic Type_generic_base) p_listany_from_any(
	type_any *Type_any) []*Type_any {
	var output []*Type_any = []*Type_any{}
	return output
}

func (type_generic Type_generic_base) p_listkey_from_any(
	type_any *Type_any) []string {
	var output []string = V_type_listkey_from_any(
		type_any)
	return output
}

func (type_generic Type_generic_base) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var output map[string]*Type_any = make(map[string]*Type_any)
	var listkey []string = V_listkey_from_any(type_any)
	if len(listkey) > 0 {
		for _, keyn := range listkey {
			if keyn != "" {
				var value_any *Type_any = V_any_from_any_keyn(
					type_any,
					keyn)
				if value_any != nil {
					output[keyn] = value_any
				}
			}
		}
	}
	return output
}

// V_generic_from_any
func V_generic_from_any(
	type_any *Type_any) Type_generic {
	var type_type *Type_type = V_type_from_any(type_any)
	var output Type_generic = V_generic_from_type(type_type)
	return output
}

// V_generic_from_type
func V_generic_from_type(
	type_type *Type_type) Type_generic {
	var output Type_generic = E_generic_any
	if type_type.type_generic != nil {
		output = type_type.type_generic
	}
	return output
}

// Type_any
type Type_any struct {
	P_type_type  *Type_type
	P_type_const *Type_const
	P_isrun      bool
	backref      any
}

// Type_any_generic
type Type_any_generic struct {
	Type_generic_base
}

func (type_generic Type_any_generic) p_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

// V_any_from_type_backref
func V_any_from_type_backref(
	type_type *Type_type,
	backref any) *Type_any {
	var output *Type_any = V_any_create()
	output.P_type_type = type_type
	output.backref = backref
	return output
}

// V_any_from_type_backref_type
func V_any_from_type_backref_any(
	type_type *Type_type,
	value *Type_any) {
	value.P_type_type = type_type
	value.backref = value
}

// V_any_empty_from_type_backref_any
func V_any_empty_from_type_backref_any(
	type_type *Type_type,
	value *Type_any) {
	value.P_type_type = type_type
	value.backref = value
	value.P_type_const = V_const_empty(type_type)
	type_type.P_path = type_type.P_pkgname + "/" + type_type.P_name
	type_type.type_any.P_type_const = V_const_type(type_type)
}

// V_any_constructor
func V_any_constructor() *Type_any {
	var output = new(Type_any)
	return output
}

// V_any_create
func V_any_create() *Type_any {
	var output = V_any_constructor()
	V_any_initialize(output)
	return output
}

// V_any_initialize
func V_any_initialize(
	value *Type_any) {
	V_any_from_type_backref_any(
		T_any,
		value)
}

// V_any_startup
func V_any_startup() *Type_type {
	var t_variable = T_any
	var e_variable = E_any
	V_any_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"any",
		E_string,
		e_variable)
	return t_variable
}

// Type_anylist
type Type_anylist struct {
	type_any  *Type_any
	P_listany []*Type_any
}

// Type_anylist_generic
type Type_anylist_generic struct {
	Type_generic_base
}

func (type_generic Type_anylist_generic) p_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	return V_anylist_any_from_any_indexn(
		type_any,
		indexn)
}

func (type_generic Type_anylist_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_anylist_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_anylist_generic) p_listany_from_any(
	type_any *Type_any) []*Type_any {
	var output []*Type_any = V_anylist_listany_from_any(
		type_any)
	return output
}

func V_anylist_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_anylist *Type_anylist = V_anylist_cast(type_any)
	var output *Type_any = V_anylist_any_from_anylist_indexn(
		type_anylist,
		indexn)
	return output
}

func V_anylist_any_from_anylist_indexn(
	type_anylist *Type_anylist,
	indexn int) *Type_any {
	var output *Type_any = E_any
	var listvalue []*Type_any = type_anylist.P_listany
	if len(listvalue) >= indexn {
		output = listvalue[indexn-1]
	}
	return output
}

func V_anylist_code_from_any(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_anylist = V_anylist_cast(
		type_any)
	var listprop []string
	var isrun = type_anylist.type_any.P_isrun
	var subindent = indent
	var lineindent = ""
	var join = ""
	if !isrun {
		join = ","
		subindent += 1
	}
	for _, type_any := range type_anylist.P_listany {
		var prop = V_code_from_any(
			type_scope,
			subindent,
			path,
			type_any)
		listprop = append(listprop, prop)
	}
	var output = V_stringn_from_liststringn_joinn(
		listprop,
		join)
	if !isrun {
		lineindent = V_code_lineindent(
			type_scope,
			indent)
		output = "" +
			lineindent + V_code_type_pkgname(
			type_scope,
			T_anylist) +
			"v_anylist(" +
			output +
			lineindent + ")"
	}
	return output
}

func V_anylist_listany_from_any(
	type_any *Type_any) []*Type_any {
	var type_anylist *Type_anylist = V_anylist_cast(
		type_any)
	var output []*Type_any = type_anylist.P_listany
	return output
}

// V_anylist_cast
func V_anylist_cast(
	type_any *Type_any) *Type_anylist {
	var output *Type_anylist = E_anylist
	var type_anylist, ok = type_any.backref.(*Type_anylist)
	if ok {
		output = type_anylist
	}
	return output
}

func A_anylist_from_listany(
	listany []*Type_any) *Type_any {
	var type_anylist *Type_anylist = V_anylist_from_listany(
		listany)
	var output = type_anylist.type_any
	return output
}

func A_anylist_run_from_listany(
	listany []*Type_any) *Type_any {
	var type_anylist *Type_anylist = V_anylist_from_listany(
		listany)
	type_anylist.type_any.P_isrun = true
	var output = type_anylist.type_any
	return output
}

func V_anylist_from_listany(
	listany []*Type_any) *Type_anylist {
	var output = V_anylist_create()
	output.P_listany = listany
	return output
}

// V_anylist_constructor
func V_anylist_constructor() *Type_anylist {
	var output = new(Type_anylist)
	return output
}

// V_anylist_create
func V_anylist_create() *Type_anylist {
	var output = V_anylist_constructor()
	V_anylist_initialize(output)
	return output
}

// V_anylist_initialize
func V_anylist_initialize(
	value *Type_anylist) {
	value.type_any = V_any_from_type_backref(
		T_anylist,
		value)
	value.P_listany = []*Type_any{}
}

// V_anylist_startup
func V_anylist_startup() *Type_type {
	var t_variable = T_anylist
	var e_variable = E_anylist
	V_anylist_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"anylist",
		C_extends_list,
		e_variable.type_any)
	t_variable.type_generic = new(Type_anylist_generic)
	return t_variable
}

// Type_boolean
type Type_boolean struct {
	type_any   *Type_any
	P_booleann bool
}

// Type_boolean_generic
type Type_boolean_generic struct {
	Type_generic_base
}

func (type_generic Type_boolean_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_boolean_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func V_boolean_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var type_boolean = V_boolean_cast(type_any)
	if type_boolean != C_true {
		type_boolean = C_false
	}
	output = V_code_const_name(
		type_lang,
		V_const_from_any(type_boolean.type_any))
	return output
}

func V_boolean_from_booleann(
	booleann bool) *Type_boolean {
	var output *Type_boolean = C_false
	if booleann {
		output = C_true
	}
	return output
}

func V_booleann_from_boolean(
	type_boolean *Type_boolean) bool {
	var output bool = false
	if type_boolean == C_true {
		output = true
	}
	return output
}

// A_boolean_cast_any
func A_boolean_cast_any(
	value *Type_boolean) *Type_any {
	var output *Type_any = value.type_any
	return output
}

// V_boolean_cast
func V_boolean_cast(
	type_any *Type_any) *Type_boolean {
	var output *Type_boolean = C_false
	var value, ok = type_any.backref.(*Type_boolean)
	if ok {
		output = value
	}
	return output
}

// V_boolean_constructor
func V_boolean_constructor() *Type_boolean {
	var output = new(Type_boolean)
	return output
}

// V_boolean_create
func V_boolean_create() *Type_boolean {
	var output = V_boolean_constructor()
	V_boolean_initialize(output)
	return output
}

// V_boolean_initialize
func V_boolean_initialize(
	value *Type_boolean) {
	value.type_any = V_any_from_type_backref(
		T_boolean,
		value)
	value.P_booleann = false
}

// V_boolean_startup
func V_boolean_startup() *Type_type {
	var t_variable = T_boolean
	var e_variable = C_false
	V_boolean_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"boolean",
		E_string,
		e_variable.type_any)
	t_variable.type_generic = new(Type_boolean_generic)
	return t_variable
}

// Type_booleann
type Type_booleann struct {
	type_any *Type_any
}

// V_booleann_constructor
func V_booleann_constructor() *Type_booleann {
	var output = new(Type_booleann)
	return output
}

// V_booleann_create
func V_booleann_create() *Type_booleann {
	var output = V_booleann_constructor()
	V_booleann_initialize(output)
	return output
}

// V_booleann_initialize
func V_booleann_initialize(
	value *Type_booleann) {
	value.type_any = V_any_from_type_backref(
		T_booleann,
		value)
}

// V_booleann_startup
func V_booleann_startup() *Type_type {
	var t_variable = T_booleann
	var e_variable = E_booleann
	V_booleann_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"",
		"booleann",
		E_string,
		e_variable.type_any)
	return t_variable
}

// Type_const
type Type_const struct {
	P_pkgname    string
	P_name       string
	P_path       string
	P_isempty    bool
	P_istype     bool
	P_const_type *Type_type
}

// V_const_empty
func V_const_empty(
	type_type *Type_type) *Type_const {
	var typepath = type_type.P_path
	if type_type.P_pkgname == "vx/core" {
		typepath = type_type.P_name
	}
	var output = V_const_create()
	output.P_name = "(empty " + typepath + ")"
	output.P_isempty = true
	return output
}

// V_const_type
func V_const_type(
	type_type *Type_type) *Type_const {
	var output = V_const_create()
	output.P_path = type_type.P_path
	output.P_pkgname = type_type.P_pkgname
	output.P_name = type_type.P_name
	output.P_istype = true
	return output
}

func V_const_from_pkgnamen_namen_any(
	pkgnamen string,
	namen string,
	type_any *Type_any) *Type_const {
	var output *Type_const = V_const_create()
	if pkgnamen == "" {
		output.P_path = namen
	} else {
		output.P_path = pkgnamen + "/" + namen
	}
	output.P_pkgname = pkgnamen
	output.P_name = namen
	type_any.P_type_const = output
	return output
}

// V_const_from_any
func V_const_from_any(
	type_any *Type_any) *Type_const {
	var output = type_any.P_type_const
	return output
}

// V_const_constructor
func V_const_constructor() *Type_const {
	var output = new(Type_const)
	return output
}

// V_const_initialize
func V_const_initialize(
	type_const *Type_const) {
	// type_const.type_any = V_any_from_type_backref(
	//
	//	t_const,
	//	type_const)
	type_const.P_path = ""
	type_const.P_pkgname = ""
	type_const.P_name = ""
	type_const.P_isempty = false
	type_const.P_istype = false
	type_const.P_const_type = E_type
}

// V_const_create
func V_const_create() *Type_const {
	var output = V_const_constructor()
	V_const_initialize(E_const)
	return output
}

// V_const_startup
func V_const_startup() *Type_type {
	var t_variable = T_const
	var e_variable = E_const
	V_const_initialize(e_variable)
	t_variable.P_pkgname = "vx/core"
	t_variable.P_name = "const"
	t_variable.P_path = t_variable.P_pkgname + "/" + t_variable.P_name
	return t_variable
}

// Type_func
type Type_func struct {
	type_any       *Type_any
	P_func_type    *Type_type
	P_return_type  *Type_type
	P_generic_type *Type_type
	P_type_varlist *Type_varlist
	P_value_any    *Type_any
	P_context      bool
	P_async        bool
}

// Type_func_generic
type Type_func_generic struct {
	Type_generic_base
}

func (type_generic Type_func_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_func_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_func_generic) p_any_from_any_keyn(
	type_any *Type_any,
	keyn string) *Type_any {
	return V_func_any_from_any_keyn(
		type_any,
		keyn)
}

func V_func_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

func V_func_any_from_any_keyn(
	type_any *Type_any,
	keyn string) *Type_any {
	var output *Type_any = E_any
	var type_func = V_func_cast(type_any)
	var key string = V_stringn_stripcolon(keyn)
	switch key {
	case "type":
		output = type_func.P_func_type.type_any
	case "return":
		output = type_func.P_return_type.type_any
	case "varlist":
		output = type_func.P_type_varlist.type_any
	case "value":
		output = type_func.P_value_any
	}
	return output
}

// A_func_cast
func A_func_cast(
	type_func *Type_func) *Type_any {
	return type_func.type_any
}

// V_func_cast
func V_func_cast(
	type_any *Type_any) *Type_func {
	var output *Type_func = E_func
	var type_func, ok = type_any.backref.(*Type_func)
	if ok {
		output = type_func
	}
	return output
}

// V_func_from_type_return_varlist_value
func V_func_from_type_return_varlist_value(
	func_type *Type_type,
	return_type *Type_type,
	type_varlist *Type_varlist,
	value_any *Type_any) *Type_func {
	var output = V_func_create()
	output.P_func_type = func_type
	output.P_return_type = return_type
	output.P_type_varlist = type_varlist
	output.P_value_any = value_any
	return output
}

// A_func_from_type
func A_func_from_type(
	type_type *Type_type) *Type_any {
	var output *Type_any = A_func_cast(
		V_func_from_type(
			type_type))
	return output
}

// V_func_from_type
func V_func_from_type(
	type_type *Type_type) *Type_func {
	var type_generic Type_generic = V_generic_from_type(type_type)
	var output *Type_func = type_generic.p_func()
	return output
}

// V_func_constructor
func V_func_constructor() *Type_func {
	var output = new(Type_func)
	return output
}

// V_func_create
func V_func_create() *Type_func {
	var output = V_func_constructor()
	V_func_initialize(output)
	return output
}

// V_func_initialize
func V_func_initialize(
	value *Type_func) {
	value.type_any = V_any_from_type_backref(
		T_func,
		value)
	value.P_func_type = E_type
	value.P_return_type = E_type
	value.P_generic_type = E_type
	value.P_type_varlist = E_varlist
	value.P_value_any = E_any
	value.P_context = false
	value.P_async = false
}

// V_func_startup
func V_func_startup() *Type_type {
	var t_variable = T_func
	var e_variable = E_func
	V_func_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"func",
		C_extends_func,
		e_variable.type_any)
	t_variable.type_generic = new(Type_func_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("type", T_type),
			V_var_from_namen_type("return", T_type),
			V_var_from_namen_type("varlist", T_varlist),
			V_var_from_namen_type("value", T_any)})
	return t_variable
}

// Type_func_declare
type Type_func_declare struct {
	type_any *Type_any
	P_type   *Type_type
	P_prefix *Type_string
}

// Type_func_declare_generic
type Type_func_declare_generic struct {
	Type_generic_base
}

func (type_generic Type_func_declare_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_func_declare_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_func_declare_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_func_declare_mapany_from_any(type_any)
}

func V_func_declare_code_from_any(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/v_func_declare_code_from_any"
	var type_lang = type_scope.P_lang
	var lineindent = V_code_lineindent(type_scope, indent)
	var lineindent1 = V_code_lineindent(type_scope, indent+1)
	var type_func_declare = V_func_declare_cast(type_any)
	var prefix = type_func_declare.P_prefix
	var prefixn = V_stringn_from_string(prefix)
	switch type_lang {
	case C_lang_go:
		prefixn = V_stringn_uppercase(prefixn)
	}
	var type_type = type_func_declare.P_type
	var type_func = V_func_from_type(type_type)
	var funcnamen = prefixn + V_code_type_name(
		type_scope,
		type_type)
	var return_type = type_func.P_return_type
	var type_varlist = type_func.P_type_varlist
	var value_any = type_func.P_value_any
	var returntypen = V_code_type_typename(
		type_scope,
		return_type)
	var body string = ""
	if V_type_from_any(value_any) == T_anylist {
		var listany []*Type_any = V_listany_from_any(value_any)
		body += V_code_from_listany(
			type_scope,
			indent+1,
			subpath,
			listany)
	} else {
		body = V_code_from_any(
			type_scope,
			indent+1,
			subpath,
			value_any)
	}
	var listvar = type_varlist.P_listvar
	var output = ""
	var props string = ""
	if len(listvar) > 0 {
		var listprop []string = []string{}
		for _, type_var := range listvar {
			var namen = V_code_var_name(
				type_scope,
				type_var)
			var var_type *Type_type = type_var.P_type
			var vartypen string = V_code_type_typename(
				type_scope,
				var_type)
			var prop = ""
			switch type_lang {
			case C_lang_go:
				prop = lineindent + " " + namen + " " + vartypen
			case C_lang_swift:
				prop = lineindent + "  _ " + namen + " : " + vartypen
			}
			listprop = append(listprop, prop)
		}
		props = V_stringn_from_liststringn_joinn(listprop, ",")
	}
	switch type_lang {
	case C_lang_go:
		var outputdeclare = ""
		var outputline = ""
		var returnline = ") {"
		if return_type != E_type {
			returnline = ") " + returntypen + " {"
			outputline = lineindent1 + "return output"
			if body == "" {
				outputdeclare = "" +
					lineindent1 +
					"var output " +
					returntypen +
					" = " +
					V_code_e(
						type_scope,
						return_type)
			}
		}
		output = "" +
			lineindent + "// " + funcnamen +
			lineindent + "func " + funcnamen + "(" +
			props +
			returnline +
			outputdeclare +
			body +
			outputline +
			lineindent + "}"
	case C_lang_swift:
		var outputdeclare = ""
		var outputline = ""
		var returnline = ") {"
		if return_type != E_type {
			returnline = lineindent + ") -> " + returntypen + " {"
			outputline = lineindent1 + "return output"
			if body == "" {
				outputdeclare = "" +
					lineindent1 +
					"var output " +
					returntypen +
					" = " +
					V_code_e(
						type_scope,
						return_type)
			}
		}
		output = "" +
			lineindent + "// " + funcnamen +
			lineindent + "public static func " + funcnamen + "(" +
			props +
			returnline +
			outputdeclare +
			body +
			outputline +
			lineindent + "}"
	}
	return output
}

func V_func_declare_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_func_declare = V_func_declare_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_type *Type_type = value.P_type
	var p_prefix *Type_string = value.P_prefix
	if p_type != E_type {
		output["type"] = A_type_cast_any(p_type)
	}
	if p_prefix != E_string {
		output["prefix"] = V_string_cast_any(p_prefix)
	}
	return output
}

// V_func_declare_cast
func V_func_declare_cast(
	type_any *Type_any) *Type_func_declare {
	var output *Type_func_declare = E_func_declare
	var type_func_declare, ok = type_any.backref.(*Type_func_declare)
	if ok {
		output = type_func_declare
	}
	return output
}

// V_func_declare_constructor
func V_func_declare_constructor() *Type_func_declare {
	var output = new(Type_func_declare)
	return output
}

// V_func_declare_create
func V_func_declare_create() *Type_func_declare {
	var output = V_func_declare_constructor()
	V_func_declare_initialize(output)
	return output
}

// V_func_declare_initialize
func V_func_declare_initialize(
	value *Type_func_declare) {
	value.type_any = V_any_from_type_backref(
		T_func_declare,
		value)
	value.P_type = E_type
}

// V_func_declare_startup
func V_func_declare_startup() *Type_type {
	var t_variable = T_func_declare
	var e_variable = E_func_declare
	V_func_declare_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"func-declare",
		C_extends_func,
		e_variable.type_any)
	t_variable.type_generic = new(Type_func_declare_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("type", T_type),
			V_var_from_namen_type("prefix", T_stringn)})
	return t_variable
}

// A_func_declare
func A_func_declare(
	type_type *Type_type) *Type_any {
	var output = V_func_declare_create()
	output.P_type = type_type
	output.P_prefix = E_string
	return output.type_any
}

// A_func_declare_v
func A_func_declare_v(
	type_type *Type_type) *Type_any {
	var output = V_func_declare_create()
	output.P_type = type_type
	output.P_prefix = V_string_from_stringn("v_")
	return output.type_any
}

// Type_if
type Type_if struct {
	type_any       *Type_any
	P_return_type  *Type_type
	P_thenelselist *Type_thenelselist
}

// Type_if_generic
type Type_if_generic struct {
	Type_generic_base
}

func (type_generic Type_if_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_if_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_if_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_if_mapany_from_any(type_any)
}

func V_if_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/v_if_code_from_any"
	var type_if = V_if_cast(type_any)
	var type_thenelselist = type_if.P_thenelselist
	var listthenelse = type_thenelselist.P_listthenelse
	var output = ""
	if len(listthenelse) > 0 {
		var prop string = ""
		var listprop []string = []string{}
		var isfound = false
		if type_if.type_any.P_isrun {
			for _, type_thenelse := range listthenelse {
				var coden = V_stringn_from_string(type_thenelse.P_code)
				switch coden {
				case ":then":
					var if_any = type_thenelse.P_if
					if C_true.type_any == if_any {
						var then_any = type_thenelse.P_then
						prop = V_code_from_any(type_lang, indent, subpath, then_any)
						listprop = append(listprop, prop)
						isfound = true
					}
				case ":else":
					var then_any = type_thenelse.P_then
					prop = V_code_from_any(type_lang, indent, subpath, then_any)
					listprop = append(listprop, prop)
					isfound = true
				}
				if isfound {
					break
				}
			}
		} else {
			var lineindent = V_code_lineindent(
				type_lang,
				indent)
			for thenelseidx, type_thenelse := range listthenelse {
				var if_any = type_thenelse.P_if
				var then_any = type_thenelse.P_then
				var if_type = V_type_from_any(if_any)
				var if_stringn string = ""
				switch if_type {
				case T_var:
					var type_var *Type_var = V_var_cast(if_any)
					if_stringn = V_code_var_name(
						type_lang,
						type_var)
				default:
					if_stringn = V_code_from_any(
						type_lang,
						indent+1,
						subpath,
						if_any)
				}
				var then_stringn = V_code_from_any(
					type_lang,
					indent+1,
					subpath,
					then_any)
				if thenelseidx == 0 {
					prop = "" +
						lineindent + "if " + if_stringn + " {" +
						then_stringn
				} else {
					prop = "" +
						lineindent + "} else if + " + if_stringn + " {" +
						then_stringn
				}
				listprop = append(listprop, prop)
			}
			prop = lineindent + "}"
			listprop = append(listprop, prop)
		}
		output = V_stringn_from_liststringn_joinn(
			listprop,
			"")
	}
	return output
}

func V_if_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_if = V_if_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_return_type *Type_type = value.P_return_type
	var p_thenelselist *Type_thenelselist = value.P_thenelselist
	if p_return_type != E_type {
		output["return-type"] = A_type_cast_any(p_return_type)
	}
	if p_thenelselist != E_thenelselist {
		output["thenelselist"] = A_thenelselist_cast_any(p_thenelselist)
	}
	return output
}

// V_any_from_if
func V_any_from_if(
	type_if *Type_if) *Type_any {
	return type_if.type_any
}

// V_if_cast
func V_if_cast(
	type_any *Type_any) *Type_if {
	var output *Type_if = E_if
	var type_if, ok = type_any.backref.(*Type_if)
	if ok {
		output = type_if
	}
	return output
}

// A_if_from_type_if_then
func A_if_from_type_if_then(
	return_type *Type_type,
	if_any *Type_any,
	then_any *Type_any) *Type_any {
	var type_if = V_if_create()
	type_if.P_return_type = return_type
	var type_thenelse *Type_thenelse = V_then_from_if_then(
		if_any,
		then_any)
	var listthenelse []*Type_thenelse = []*Type_thenelse{}
	listthenelse = append(listthenelse, type_thenelse)
	var type_thenelselist = V_thenelselist_from_listthenelse(
		listthenelse)
	type_if.P_thenelselist = type_thenelselist
	var output *Type_any = type_if.type_any
	return output
}

// A_if_run_from_type_booleann_then
func A_if_run_from_type_booleann_then(
	return_type *Type_type,
	booleann bool,
	then_any *Type_any) *Type_any {
	var type_if = V_if_create()
	type_if.P_return_type = return_type
	type_if.type_any.P_isrun = true
	var type_thenelse *Type_thenelse = V_then_from_booleann(
		booleann,
		then_any)
	var listthenelse []*Type_thenelse = []*Type_thenelse{}
	listthenelse = append(listthenelse, type_thenelse)
	var type_thenelselist = V_thenelselist_from_listthenelse(
		listthenelse)
	type_if.P_thenelselist = type_thenelselist
	var output *Type_any = type_if.type_any
	return output
}

// A_if_run_from_type_listthenelse
func A_if_run_from_type_listthenelse(
	return_type *Type_type,
	listthenelse []*Type_thenelse) *Type_any {
	var type_if = V_if_create()
	type_if.P_return_type = return_type
	type_if.type_any.P_isrun = true
	var type_thenelselist = V_thenelselist_from_listthenelse(
		listthenelse)
	type_if.P_thenelselist = type_thenelselist
	var output *Type_any = type_if.type_any
	return output
}

// V_if_constructor
func V_if_constructor() *Type_if {
	var output = new(Type_if)
	return output
}

// V_if_create
func V_if_create() *Type_if {
	var output = V_if_constructor()
	V_if_initialize(output)
	return output
}

// V_if_initialize
func V_if_initialize(
	value *Type_if) {
	value.type_any = V_any_from_type_backref(
		T_if,
		value)
	value.P_thenelselist = E_thenelselist
}

// V_if_startup
func V_if_startup() *Type_type {
	var t_variable = T_if
	var e_variable = E_if
	V_if_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"if",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_if_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("return-type", T_type),
			V_var_from_namen_type("thenelselist", T_thenelselist)})
	return t_variable
}

// Type_lang
type Type_lang struct {
	type_any *Type_any
	P_name   *Type_string
	P_indent *Type_string
	P_pkgref string
}

func V_indentn_from_lang(
	type_lang *Type_lang) string {
	return V_stringn_from_string(type_lang.P_indent)
}

func V_namen_from_lang(
	type_lang *Type_lang) string {
	return V_stringn_from_string(type_lang.P_name)
}

// V_lang_constructor
func V_lang_constructor() *Type_lang {
	var output = new(Type_lang)
	return output
}

// V_lang_create
func V_lang_create() *Type_lang {
	var output = V_lang_constructor()
	V_lang_initialize(output)
	return output
}

// V_lang_initialize
func V_lang_initialize(
	value *Type_lang) {
	value.type_any = V_any_from_type_backref(
		T_lang,
		value)
	value.P_name = E_string
	value.P_indent = E_string
}

// V_lang_startup
func V_lang_startup() *Type_type {
	var t_variable = T_lang
	var e_variable = E_lang
	V_lang_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"lang",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

// Type_package
type Type_package struct {
	type_any *Type_any
	P_path   string
}

// V_package_constructor
func V_package_constructor() *Type_package {
	var output = new(Type_package)
	return output
}

// V_package_create
func V_package_create() *Type_package {
	var output = V_package_constructor()
	V_package_initialize(output)
	return output
}

// V_package_initialize
func V_package_initialize(
	value *Type_package) {
	value.type_any = V_any_from_type_backref(
		T_scope,
		value)
	value.P_path = ""
}

// V_package_startup
func V_package_startup() *Type_type {
	var t_variable = T_package
	var e_variable = E_package
	V_package_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"package",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

// Type_project
type Type_project struct {
	type_any *Type_any
}

// V_project_constructor
func V_project_constructor() *Type_project {
	var output = new(Type_project)
	return output
}

// V_project_create
func V_project_create() *Type_project {
	var output = V_project_constructor()
	V_project_initialize(output)
	return output
}

// V_project_initialize
func V_project_initialize(
	value *Type_project) {
	value.type_any = V_any_from_type_backref(
		T_scope,
		value)
}

// V_project_startup
func V_project_startup() *Type_type {
	var t_variable = T_project
	var e_variable = E_project
	V_project_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"project",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

// Type_scope
type Type_scope struct {
	type_any  *Type_any
	P_lang    *Type_lang
	P_project *Type_project
	P_package *Type_package
}

// V_scope_constructor
func V_scope_constructor() *Type_scope {
	var output = new(Type_scope)
	return output
}

// V_scope_create
func V_scope_create() *Type_scope {
	var output = V_scope_constructor()
	V_scope_initialize(output)
	return output
}

// V_scope_initialize
func V_scope_initialize(
	value *Type_scope) {
	value.type_any = V_any_from_type_backref(
		T_scope,
		value)
	value.P_lang = E_lang
	value.P_project = E_project
	value.P_package = E_package
}

// V_scope_startup
func V_scope_startup() *Type_type {
	var t_variable = T_scope
	var e_variable = E_scope
	V_scope_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"scope",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

type Type_list struct {
	type_any *Type_any
}

// V_list_constructor
func V_list_constructor() *Type_list {
	var output = new(Type_list)
	return output
}

// V_list_create
func V_list_create() *Type_list {
	var output = V_list_constructor()
	V_list_initialize(output)
	return output
}

// V_list_initialize
func V_list_initialize(
	value *Type_list) {
	value.type_any = V_any_from_type_backref(
		T_list,
		value)
}

// V_list_startup
func V_list_startup() *Type_type {
	var t_variable = T_list
	var e_variable = E_list
	V_list_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"list",
		C_extends_list,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_list_generic)
	return t_variable
}

type Type_map struct {
	type_any *Type_any
}

// V_map_constructor
func V_map_constructor() *Type_map {
	var output = new(Type_map)
	return output
}

// V_map_create
func V_map_create() *Type_map {
	var output = V_map_constructor()
	V_map_initialize(output)
	return output
}

// V_map_initialize
func V_map_initialize(
	value *Type_map) {
	value.type_any = V_any_from_type_backref(
		T_map,
		value)
}

// V_map_startup
func V_map_startup() *Type_type {
	var t_variable = T_map
	var e_variable = E_map
	V_map_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"map",
		C_extends_map,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_map_generic)
	return t_variable
}

// Type_msg
type Type_msg struct {
	type_any *Type_any
	errorn   error
	P_coden  string
}

func V_msg_from_errorn(
	errorn error) *Type_msg {
	var output = V_msg_create()
	output.errorn = errorn
	return output
}

// V_msg_constructor
func V_msg_constructor() *Type_msg {
	var output = new(Type_msg)
	return output
}

// V_msg_create
func V_msg_create() *Type_msg {
	var output = V_msg_constructor()
	V_msg_initialize(output)
	return output
}

// V_msg_initialize
func V_msg_initialize(
	value *Type_msg) {
	value.type_any = V_any_from_type_backref(
		T_msg,
		value)
}

// V_msg_startup
func V_msg_startup() *Type_type {
	var t_variable = T_msg
	var e_variable = E_msg
	V_msg_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"msg",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

// Type_msgblock
type Type_msgblock struct {
	type_any  *Type_any
	P_namen   string
	P_iserror bool
	// P_type_msglist *Type_msglist
	// P_type_msgblocklist *Type_msgblocklist
}

func V_msgblock_from_msgblock_errorn(
	type_msgblock *Type_msgblock,
	errorn error) *Type_msgblock {
	var type_msg *Type_msg = V_msg_from_errorn(errorn)
	var output *Type_msgblock = V_msgblock_from_msgblock_msg(type_msgblock, type_msg)
	return output
}

func V_msgblock_from_msgblock_msg(
	type_msgblock *Type_msgblock,
	type_msg *Type_msg) *Type_msgblock {
	var output *Type_msgblock = V_msgblock_copy(
		type_msgblock,
		V_anylist_from_listany(
			[]*Type_any{
				type_msg.type_any}))
	return output
}

func V_msgblock_from_namen(
	namen string) *Type_msgblock {
	var output *Type_msgblock = V_msgblock_create()
	output.P_namen = namen
	return output
}

// V_msgblock_copy
func V_msgblock_copy(
	copyval *Type_msgblock,
	type_anylist *Type_anylist) *Type_msgblock {
	var output = copyval
	return output
}

// V_msgblock_constructor
func V_msgblock_constructor() *Type_msgblock {
	var output = new(Type_msgblock)
	return output
}

// V_msgblock_create
func V_msgblock_create() *Type_msgblock {
	var output = V_msgblock_constructor()
	V_msgblock_initialize(output)
	return output
}

// V_msgblock_initialize
func V_msgblock_initialize(
	value *Type_msgblock) {
	value.type_any = V_any_from_type_backref(
		T_msgblock,
		value)
}

// V_msgblock_startup
func V_msgblock_startup() *Type_type {
	var t_variable = T_msgblock
	var e_variable = E_msgblock
	V_msgblock_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"msgblock",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

/*
type Type_scope struct {
	type_any *Type_any
	P_mapvar map[string]*Type_var
}
*/

// Type_string
type Type_string struct {
	type_any  *Type_any
	P_stringn string
}

// Type_string_generic
type Type_string_generic struct {
	Type_generic_base
}

func (type_generic Type_string_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_string_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func V_string_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	//var subpath = path + "/v_string_code_from_any"
	var type_string = V_string_cast(type_any)
	var stringn = type_string.P_stringn
	var output = stringn
	if indent > 0 && V_booleann_from_stringn_startsn(output, "\n") {
		var lineindent = V_code_lineindent(
			type_lang,
			indent)
		output = V_stringn_from_stringn_findn_replacen(
			output,
			"\n",
			lineindent)
	}
	return output
}

func V_string_cast_any(
	type_string *Type_string) *Type_any {
	var output = type_string.type_any
	return output
}

func V_string_cast(
	type_any *Type_any) *Type_string {
	var output *Type_string = E_string
	var value, ok = type_any.backref.(*Type_string)
	if ok {
		output = value
	}
	return output
}

func A_string_from_stringn(
	stringn string) *Type_any {
	var output = V_string_cast_any(
		V_string_from_stringn(stringn))
	return output
}

func V_string_from_stringn(
	stringn string) *Type_string {
	var output = V_string_create()
	output.P_stringn = stringn
	return output
}

// V_string_constructor
func V_string_constructor() *Type_string {
	var output = new(Type_string)
	return output
}

// V_string_create
func V_string_create() *Type_string {
	var output = V_string_constructor()
	V_string_initialize(output)
	return output
}

// V_string_initialize
func V_string_initialize(
	value *Type_string) {
	value.type_any = V_any_from_type_backref(
		T_string,
		value)
	value.P_stringn = ""
}

// V_string_startup
func V_string_startup() *Type_type {
	var t_variable = T_string
	var e_variable = E_string
	V_string_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"string",
		E_string,
		e_variable.type_any)
	t_variable.type_generic = new(Type_string_generic)
	return t_variable
}

// Type_stringlist
type Type_stringlist struct {
	type_any     *Type_any
	P_liststring []*Type_string
}

// Type_stringlist_generic
type Type_stringlist_generic struct {
	Type_generic_base
}

func (type_generic Type_stringlist_generic) p_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	return V_stringlist_any_from_any_indexn(
		type_any,
		indexn)
}

func (type_generic Type_stringlist_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_stringlist_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_stringlist_generic) p_listany_from_any(
	type_any *Type_any) []*Type_any {
	return V_stringlist_listany_from_any(type_any)
}

func V_stringlist_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_stringlist *Type_stringlist = V_stringlist_cast(type_any)
	var type_string *Type_string = V_stringlist_string_from_stringlist_indexn(
		type_stringlist,
		indexn)
	var output *Type_any = type_string.type_any
	return output
}

func V_stringlist_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = "" +
		"f_stringlist_from_liststringn(" +
		"\n  [" +
		"\n   \"\"" +
		"\n  ]" +
		")"
	return output
}

func V_stringlist_listany_from_any(
	type_any *Type_any) []*Type_any {
	var type_stringlist *Type_stringlist = V_stringlist_cast(type_any)
	var output []*Type_any = V_stringlist_listany_from_liststring(type_stringlist.P_liststring)
	return output
}

func V_stringlist_listany_from_liststring(
	liststring []*Type_string) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_string := range liststring {
		output = append(output, type_string.type_any)
	}
	return output
}

func V_stringlist_string_from_stringlist_indexn(
	type_stringlist *Type_stringlist,
	indexn int) *Type_string {
	var output *Type_string = E_string
	var listvalue []*Type_string = type_stringlist.P_liststring
	if len(listvalue) >= indexn {
		output = listvalue[indexn-1]
	}
	return output
}

func A_stringlist_cast(
	value *Type_stringlist) *Type_any {
	return value.type_any
}

func V_stringlist_cast(
	type_any *Type_any) *Type_stringlist {
	var output *Type_stringlist = E_stringlist
	var value, ok = type_any.backref.(*Type_stringlist)
	if ok {
		output = value
	}
	return output
}

func A_stringlist_from_liststringn(
	liststringn []string) *Type_any {
	var type_stringlist *Type_stringlist = V_stringlist_from_liststringn(
		liststringn)
	var output *Type_any = type_stringlist.type_any
	return output
}

func V_stringlist_from_liststringn(
	liststringn []string) *Type_stringlist {
	var output *Type_stringlist = V_stringlist_create()
	var liststring []*Type_string
	for _, stringn := range liststringn {
		var type_string = V_string_from_stringn(stringn)
		liststring = append(liststring, type_string)
	}
	output.P_liststring = liststring
	return output
}

// V_stringlist_constructor
func V_stringlist_constructor() *Type_stringlist {
	var output = new(Type_stringlist)
	return output
}

// V_stringlist_create
func V_stringlist_create() *Type_stringlist {
	var output = V_stringlist_constructor()
	V_stringlist_initialize(output)
	return output
}

// V_stringlist_initialize
func V_stringlist_initialize(
	value *Type_stringlist) {
	value.type_any = V_any_from_type_backref(
		T_stringlist,
		value)
	value.P_liststring = []*Type_string{}
}

// V_stringlist_startup
func V_stringlist_startup() *Type_type {
	var t_variable = T_stringlist
	var e_variable = E_stringlist
	V_stringlist_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"stringlist",
		C_extends_list,
		e_variable.type_any)
	t_variable.type_generic = new(Type_stringlist_generic)
	return t_variable
}

// Type_stringmap
type Type_stringmap struct {
	type_any  *Type_any
	listkey   []string
	mapstring map[string]*Type_string
}

// Type_stringmap_generic
type Type_stringmap_generic struct {
	Type_generic_base
}

func (type_generic Type_stringmap_generic) p_any_from_any_keyn(
	type_any *Type_any,
	keyn string) *Type_any {
	var output *Type_any = V_stringmap_any_from_any_keyn(
		type_any,
		keyn)
	return output
}

func (type_generic Type_stringmap_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_stringmap_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_stringmap_generic) p_listkey_from_any(
	type_any *Type_any) []string {
	var output []string = V_stringmap_listkey_from_any(
		type_any)
	return output
}

func V_stringmap_any_from_any_keyn(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_stringmap *Type_stringmap = V_stringmap_cast(type_any)
	var type_string *Type_string = V_stringmap_string_from_stringmap_keyn(
		type_stringmap,
		keyn)
	var output *Type_any = E_any
	if type_string != E_string {
		output = V_string_cast_any(
			type_string)
	}
	return output
}

func V_stringmap_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = "" +
		"f_stringmap_from_liststringn(" +
		"\n  [" +
		"\n   \"\"" +
		"\n  ]" +
		")"
	return output
}

func V_stringmap_listkey_from_any(
	type_any *Type_any) []string {
	var type_stringmap *Type_stringmap = V_stringmap_cast(type_any)
	var output []string = type_stringmap.listkey
	return output
}

func V_stringmap_string_from_stringmap_keyn(
	type_stringmap *Type_stringmap,
	keyn string) *Type_string {
	var output = E_string
	var mapstring map[string]*Type_string = type_stringmap.mapstring
	var type_string, ok = mapstring[keyn]
	if ok {
		output = type_string
	}
	return output
}

func V_stringmap_cast(
	type_any *Type_any) *Type_stringmap {
	var output *Type_stringmap = E_stringmap
	var value, ok = type_any.backref.(*Type_stringmap)
	if ok {
		output = value
	}
	return output
}

func V_stringmap_cast_any(
	value *Type_stringmap) *Type_any {
	return value.type_any
}

func A_stringmap_from_liststringn(
	liststringn []string) *Type_any {
	var type_stringmap *Type_stringmap = V_stringmap_from_liststringn(
		liststringn)
	var output *Type_any = type_stringmap.type_any
	return output
}

func V_stringmap_from_liststringn(
	liststringn []string) *Type_stringmap {
	var output *Type_stringmap = V_stringmap_create()
	var listkey []string = []string{}
	var mapstring map[string]*Type_string = map[string]*Type_string{}
	var key = ""
	for _, stringn := range liststringn {
		if stringn == "" {
		} else if key == "" {
			key = stringn
			if V_booleann_from_stringn_startsn(
				key,
				":") {
				key = V_stringn_from_stringn_aftern(
					key,
					":")
			}
		} else {
			if !V_booleann_from_liststringn_containsn(
				listkey,
				key) {
				listkey = append(listkey, key)
			}
			var type_string = V_string_from_stringn(stringn)
			mapstring[key] = type_string
			key = ""
		}
	}
	if len(listkey) > 0 {
		output.listkey = listkey
		output.mapstring = mapstring
	}
	return output
}

// V_stringmap_constructor
func V_stringmap_constructor() *Type_stringmap {
	var output = new(Type_stringmap)
	return output
}

// V_stringmap_create
func V_stringmap_create() *Type_stringmap {
	var output = V_stringmap_constructor()
	V_stringmap_initialize(output)
	return output
}

// V_stringmap_initialize
func V_stringmap_initialize(
	value *Type_stringmap) {
	value.type_any = V_any_from_type_backref(
		T_stringmap,
		value)
	value.listkey = []string{}
	value.mapstring = map[string]*Type_string{}
}

// V_stringmap_startup
func V_stringmap_startup() *Type_type {
	var t_variable = T_stringmap
	var e_variable = E_stringmap
	V_stringmap_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"stringmap",
		C_extends_map,
		e_variable.type_any)
	t_variable.type_generic = new(Type_stringmap_generic)
	return t_variable
}

type Type_struct struct {
	type_any *Type_any
}

// V_struct_constructor
func V_struct_constructor() *Type_struct {
	var output = new(Type_struct)
	return output
}

// V_struct_create
func V_struct_create() *Type_struct {
	var output = V_struct_constructor()
	V_struct_initialize(output)
	return output
}

// V_struct_initialize
func V_struct_initialize(
	value *Type_struct) {
	value.type_any = V_any_from_type_backref(
		T_struct,
		value)
}

// V_struct_startup
func V_struct_startup() *Type_type {
	var t_variable = T_struct
	var e_variable = E_struct
	V_struct_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"struct",
		C_extends_struct,
		e_variable.type_any)
	//t_variable.type_generic = new(Type_struct_generic)
	return t_variable
}

// Type_thenelse
type Type_thenelse struct {
	type_any *Type_any
	P_code   *Type_string
	P_if     *Type_any
	P_then   *Type_any
}

// Type_thenelse_generic
type Type_thenelse_generic struct {
	Type_generic_base
}

func (type_generic Type_thenelse_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_thenelse_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_thenelse_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_thenelse_mapany_from_any(type_any)
}

func V_thenelse_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

func V_thenelse_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_thenelse = V_thenelse_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_code *Type_string = value.P_code
	var p_if *Type_any = value.P_if
	var p_then *Type_any = value.P_then
	if p_code != E_string {
		output["code"] = V_string_cast_any(p_code)
	}
	if p_if != E_any {
		output["if"] = p_if
	}
	if p_then != E_any {
		output["then"] = p_then
	}
	return output
}

// V_else
func V_else(
	else_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = V_thenelse_create()
	output.P_code = V_string_from_stringn(":else")
	output.P_then = else_any
	return output
}

// V_then_from_booleann
func V_then_from_booleann(
	booleann bool,
	then_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = V_thenelse_create()
	output.P_code = V_string_from_stringn(":then")
	if booleann {
		output.P_if = C_true.type_any
	}
	output.P_then = then_any
	return output
}

// V_then_from_if_then
func V_then_from_if_then(
	if_any *Type_any,
	then_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = V_thenelse_create()
	output.P_code = V_string_from_stringn(":then")
	output.P_if = if_any
	output.P_then = then_any
	return output
}

func V_thenelse_cast(
	type_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = E_thenelse
	var value, ok = type_any.backref.(*Type_thenelse)
	if ok {
		output = value
	}
	return output
}

// V_thenelse_constructor
func V_thenelse_constructor() *Type_thenelse {
	var output = new(Type_thenelse)
	return output
}

// V_thenelse_create
func V_thenelse_create() *Type_thenelse {
	var output = V_thenelse_constructor()
	V_thenelse_initialize(output)
	return output
}

// V_thenelse_initialize
func V_thenelse_initialize(
	value *Type_thenelse) {
	value.type_any = V_any_from_type_backref(
		t_thenelse,
		value)
	value.P_if = C_false.type_any
	value.P_then = E_any
}

// V_thenelse_startup
func V_thenelse_startup() *Type_type {
	var t_variable = t_thenelse
	var e_variable = E_thenelse
	V_thenelse_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"thenelse",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_thenelse_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("code", T_string),
			V_var_from_namen_type("if", T_any),
			V_var_from_namen_type("then", T_any)})
	return t_variable
}

// Type_thenelselist
type Type_thenelselist struct {
	type_any       *Type_any
	P_listthenelse []*Type_thenelse
}

// Type_thenelselist_generic
type Type_thenelselist_generic struct {
	Type_generic_base
}

func (type_generic Type_thenelselist_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_thenelselist_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_thenelselist_generic) p_listany_from_any(
	type_any *Type_any) []*Type_any {
	return V_thenelselist_listany_from_any(type_any)
}

func V_thenelselist_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

func V_thenelselist_listany_from_any(
	type_any *Type_any) []*Type_any {
	var type_thenelselist *Type_thenelselist = V_thenelselist_cast(type_any)
	var output []*Type_any = V_thenelselist_listany_from_listthenelse(
		type_thenelselist.P_listthenelse)
	return output
}

func V_thenelselist_listany_from_listthenelse(
	listthenelse []*Type_thenelse) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_thenelse := range listthenelse {
		output = append(output, type_thenelse.type_any)
	}
	return output
}

// V_thenelselist_from_listthenelse
func V_thenelselist_from_listthenelse(
	listthenelse []*Type_thenelse) *Type_thenelselist {
	var output = V_thenelselist_create()
	output.P_listthenelse = listthenelse
	return output
}

// A_thenelselist_cast_any
func A_thenelselist_cast_any(
	value *Type_thenelselist) *Type_any {
	var output *Type_any = value.type_any
	return output
}

// V_thenelselist_cast
func V_thenelselist_cast(
	type_any *Type_any) *Type_thenelselist {
	var output *Type_thenelselist = E_thenelselist
	var value, ok = type_any.backref.(*Type_thenelselist)
	if ok {
		output = value
	}
	return output
}

// V_thenelselist_constructor
func V_thenelselist_constructor() *Type_thenelselist {
	var output = new(Type_thenelselist)
	return output
}

// V_thenelselist_create
func V_thenelselist_create() *Type_thenelselist {
	var output = V_thenelselist_constructor()
	V_thenelselist_initialize(output)
	return output
}

// V_thenelselist_initialize
func V_thenelselist_initialize(
	value *Type_thenelselist) {
	value.type_any = V_any_from_type_backref(
		T_thenelselist,
		value)
	value.P_listthenelse = []*Type_thenelse{}
}

// V_thenelselist_startup
func V_thenelselist_startup() *Type_type {
	var t_variable = T_thenelselist
	var e_variable = E_thenelselist
	V_thenelselist_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"thenelselist",
		C_extends_list,
		e_variable.type_any)
	t_variable.type_generic = new(Type_thenelselist_generic)
	return t_variable
}

// Type_type
type Type_type struct {
	type_any         *Type_any
	type_generic     Type_generic
	P_path           string
	P_pkgname        string
	P_name           string
	P_alias          string
	P_idx            int
	P_extends        *Type_string
	P_empty_any      *Type_any
	P_propertylist   *Type_varlist
	P_container_type *Type_type
	P_allowtypes     *Type_typelist
}

// Type_type_generic
type Type_type_generic struct {
	Type_generic_base
}

func (type_generic Type_type_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_type_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func V_type_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

func V_type_listkey_from_any(
	type_any *Type_any) []string {
	var output []string = []string{}
	var type_type = type_any.P_type_type
	var type_varlist = type_type.P_propertylist
	if type_varlist != E_varlist {
		var listvar = type_varlist.P_listvar
		for _, type_var := range listvar {
			var prop *Type_string = type_var.P_name
			var propn string = V_stringn_from_string(prop)
			output = append(output, propn)
		}
	}
	return output
}

func V_type_t_startup(
	type_type *Type_type,
	pkgname string,
	name string,
	extends_string *Type_string,
	empty_any *Type_any) {
	var path string = ""
	switch pkgname {
	case "":
		path = name
	default:
		path = pkgname + "/" + name
	}
	type_type.P_path = path
	type_type.P_pkgname = pkgname
	type_type.P_name = name
	type_type.P_alias = name
	type_type.P_idx = 0
	type_type.P_extends = extends_string
	type_type.type_any = V_any_from_type_backref(type_type, type_type)
	type_type.type_any.P_type_const = V_const_type(type_type)
	type_type.P_empty_any = empty_any
	type_type.P_propertylist = E_varlist
	type_type.P_container_type = E_type
	type_type.P_allowtypes = E_typelist
	empty_any.P_type_const = V_const_empty(type_type)
}

// V_type_from_any
func V_type_from_any(
	type_any *Type_any) *Type_type {
	var output = type_any.P_type_type
	return output
}

// A_type_cast_any
func A_type_cast_any(
	type_type *Type_type) *Type_any {
	var output = type_type.type_any
	return output
}

// V_type_cast
func V_type_cast(
	type_any *Type_any) *Type_type {
	var output *Type_type = E_type
	var value, ok = type_any.backref.(*Type_type)
	if ok {
		output = value
	}
	return output
}

// V_type_constructor
func V_type_constructor() *Type_type {
	var output = new(Type_type)
	return output
}

// V_type_create
func V_type_create() *Type_type {
	var output = V_type_constructor()
	V_type_initialize(output)
	return output
}

// V_type_initialize
func V_type_initialize(
	value *Type_type) {
	value.type_any = V_any_from_type_backref(
		T_type,
		T_type)
	value.P_path = ""
	value.P_pkgname = ""
	value.P_name = ""
	value.P_alias = ""
	value.P_idx = 0
	value.P_extends = E_string
	value.P_empty_any = E_any
	value.P_propertylist = E_varlist
	value.P_container_type = E_type
	value.P_allowtypes = E_typelist
}

// V_type_startup
func V_type_startup() *Type_type {
	var t_variable = T_type
	var e_variable = E_type
	V_type_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"type",
		E_string,
		e_variable.type_any)
	return t_variable
}

// Type_typelist
type Type_typelist struct {
	type_any   *Type_any
	P_listtype []*Type_type
}

// Type_typelist_generic
type Type_typelist_generic struct {
	Type_generic_base
}

func (type_generic Type_typelist_generic) p_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	return V_typelist_any_from_any_indexn(
		type_any,
		indexn)
}

func (type_generic Type_typelist_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_typelist_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_typelist_generic) p_listany_from_any(
	type_any *Type_any) []*Type_any {
	return V_typelist_listany_from_any(type_any)
}

func V_typelist_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_typelist *Type_typelist = V_typelist_cast(type_any)
	var type_type *Type_type = V_typelist_type_from_typelist_indexn(
		type_typelist,
		indexn)
	var output *Type_any = type_type.type_any
	return output
}

func V_typelist_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = "" +
		"f_typelist_from_listtype(" +
		"\n  [" +
		"\n   \"\"" +
		"\n  ]" +
		")"
	return output
}

func V_typelist_listany_from_any(
	type_any *Type_any) []*Type_any {
	var type_typelist *Type_typelist = V_typelist_cast(type_any)
	var output []*Type_any = V_typelist_listany_from_listtype(type_typelist.P_listtype)
	return output
}

func V_typelist_listany_from_listtype(
	listtype []*Type_type) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_type := range listtype {
		output = append(output, type_type.type_any)
	}
	return output
}

func V_typelist_type_from_typelist_indexn(
	type_typelist *Type_typelist,
	indexn int) *Type_type {
	var output *Type_type = E_type
	var listvalue []*Type_type = type_typelist.P_listtype
	if len(listvalue) >= indexn {
		output = listvalue[indexn-1]
	}
	return output
}

func V_typelist_cast(
	type_any *Type_any) *Type_typelist {
	var output *Type_typelist = E_typelist
	var value, ok = type_any.backref.(*Type_typelist)
	if ok {
		output = value
	}
	return output
}

func V_typelist_from_listtype(
	listtype []*Type_type) *Type_typelist {
	var output *Type_typelist = V_typelist_create()
	output.P_listtype = listtype
	return output
}

// V_typelist_constructor
func V_typelist_constructor() *Type_typelist {
	var output = new(Type_typelist)
	return output
}

// V_typelist_create
func V_typelist_create() *Type_typelist {
	var output = V_typelist_constructor()
	V_typelist_initialize(output)
	return output
}

// V_typelist_initialize
func V_typelist_initialize(
	value *Type_typelist) {
	value.type_any = V_any_from_type_backref(
		T_typelist,
		value)
	value.P_listtype = []*Type_type{}
}

// V_typelist_startup
func V_typelist_startup() *Type_type {
	var t_variable = T_typelist
	var e_variable = E_typelist
	V_typelist_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"typelist",
		C_extends_list,
		e_variable.type_any)
	t_variable.type_generic = new(Type_typelist_generic)
	return t_variable
}

type Type_var struct {
	type_any   *Type_any
	P_name     *Type_string
	P_type     *Type_type
	P_value    *Type_any
	P_mutable  *Type_boolean
	P_nullable *Type_boolean
}

// Type_var_generic
type Type_var_generic struct {
	Type_generic_base
}

func (type_generic Type_var_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_var_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_var_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_var_mapany_from_any(type_any)
}

func V_var_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_var *Type_var = V_var_cast(type_any)
	var value *Type_any = type_var.P_value
	var output = V_code_from_any(
		type_lang,
		indent,
		path,
		value)
	return output
}

func V_var_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_var = V_var_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_name *Type_string = value.P_name
	var p_type *Type_type = value.P_type
	var value_any *Type_any = value.P_value
	var p_mutable *Type_boolean = value.P_mutable
	var p_nullable *Type_boolean = value.P_nullable
	if p_name != E_string {
		output["name"] = V_string_cast_any(p_name)
	}
	if p_type != E_type {
		output["type"] = A_type_cast_any(p_type)
	}
	if value_any != E_any {
		output["value"] = value_any
	}
	if p_mutable != C_false {
		output["mutable"] = A_boolean_cast_any(p_mutable)
	}
	if p_mutable != C_false {
		output["nullable"] = A_boolean_cast_any(p_nullable)
	}
	return output
}

func V_var_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_from_stringn(namen)
	output.P_mutable = C_false
	return output
}

func V_var_mutable_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_from_stringn(namen)
	output.P_mutable = V_boolean_from_booleann(true)
	return output
}

func A_var_cast_any(
	value *Type_var) *Type_any {
	var output *Type_any = value.type_any
	return output
}

func V_var_cast(
	type_any *Type_any) *Type_var {
	var output *Type_var = E_var
	var value, ok = type_any.backref.(*Type_var)
	if ok {
		output = value
	}
	return output
}

// V_var_constructor
func V_var_constructor() *Type_var {
	var output = new(Type_var)
	return output
}

// V_var_create
func V_var_create() *Type_var {
	var output = V_var_constructor()
	V_var_initialize(output)
	return output
}

// V_var_initialize
func V_var_initialize(
	value *Type_var) {
	value.type_any = V_any_from_type_backref(
		T_var,
		value)
	value.P_name = E_string
	value.P_type = E_type
	value.P_value = E_any
	value.P_mutable = C_false
	value.P_nullable = C_false
}

// V_var_startup
func V_var_startup() *Type_type {
	var t_variable = T_var
	var e_variable = E_var
	V_var_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_var_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("name", T_string),
			V_var_from_namen_type("type", T_type),
			V_var_from_namen_type("mutable", T_boolean),
			V_var_from_namen_type("value", T_any)})
	return t_variable
}

type Type_var_declare struct {
	type_any *Type_any
	P_var    *Type_var
	P_value  *Type_any
}

// Type_var_declare_generic
type Type_var_declare_generic struct {
	Type_generic_base
}

func (type_generic Type_var_declare_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_var_declare_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_var_declare_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_var_declare_mapany_from_any(type_any)
}

func V_var_declare_code_from_any(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var subpath = path + "/v_var_declare_code_from_any"
	var type_lang *Type_lang = type_scope.P_lang
	var type_var_declare = V_var_declare_cast(type_any)
	var type_var = type_var_declare.P_var
	var var_type = type_var.P_type
	var mutable = type_var.P_mutable
	var value_any = type_var_declare.P_value
	var typen string = V_code_type_typename(
		type_scope,
		var_type)
	var varnamen string = V_code_name(
		type_scope,
		type_var.P_name)
	var valuen = ""
	if value_any == E_any {
		valuen = V_code_e(
			type_scope,
			var_type)
	} else {
		valuen = V_code_from_any(
			type_scope,
			indent+1,
			subpath,
			value_any)
	}
	var lineindent = V_code_lineindent(
		type_scope,
		indent)
	switch type_lang {
	case C_lang_go:
		output = lineindent + "var " + varnamen + " " + typen + " = " + valuen
	case C_lang_swift:
		if mutable == C_true {
			output = lineindent + "var " + varnamen + " : " + typen + " = " + valuen
		} else {
			output = lineindent + "let " + varnamen + " : " + typen + " = " + valuen
		}
	}
	return output
}

func V_var_declare_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_var_declare = V_var_declare_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_var *Type_var = value.P_var
	var p_value *Type_any = value.P_value
	if p_var != E_var {
		output["var"] = A_var_cast_any(p_var)
	}
	if p_value != E_any {
		output["value"] = p_value
	}
	return output
}

func A_var_declare(
	type_var *Type_var,
	value_any *Type_any) *Type_any {
	var output = V_var_declare_create()
	output.P_var = type_var
	output.P_value = value_any
	return output.type_any
}

// A_var_declare_cast
func A_var_declare_cast(
	value *Type_var_declare) *Type_any {
	var output *Type_any = value.type_any
	return output
}

// V_var_declare_cast
func V_var_declare_cast(
	type_any *Type_any) *Type_var_declare {
	var output = E_var_declare
	var value, ok = type_any.backref.(*Type_var_declare)
	if ok {
		output = value
	}
	return output
}

// V_var_declare_constructor
func V_var_declare_constructor() *Type_var_declare {
	var output = new(Type_var_declare)
	return output
}

// V_var_declare_create
func V_var_declare_create() *Type_var_declare {
	var output = V_var_declare_constructor()
	V_var_declare_initialize(output)
	return output
}

// V_var_declare_initialize
func V_var_declare_initialize(
	value *Type_var_declare) {
	value.type_any = V_any_from_type_backref(
		T_var_declare,
		value)
	value.P_var = E_var
	value.P_value = E_any
}

// V_var_declare_startup
func V_var_declare_startup() *Type_type {
	var t_variable = T_var_declare
	var e_variable = E_var_declare
	V_var_declare_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-declare",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_var_declare_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("var", T_var),
			V_var_from_namen_type("value", T_any)})
	return t_variable
}

type Type_var_method struct {
	type_any  *Type_any
	P_var     *Type_var
	P_method  *Type_string
	P_varlist *Type_varlist
}

// Type_var_method_generic
type Type_var_method_generic struct {
	Type_generic_base
}

func (type_generic Type_var_method_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_var_method_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func V_var_method_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var type_var_method = V_var_method_cast(type_any)
	var p_var = type_var_method.P_var
	var p_method = type_var_method.P_method
	var varnamen = V_code_name(type_lang, p_var.P_name)
	var methodn = V_stringn_from_string(p_method)
	var valuen = ""
	if methodn != "" {
		valuen = methodn
	}
	switch type_lang {
	default:
		output = varnamen + "." + valuen + "()"
	}
	return output
}

func V_var_method_cast(
	type_any *Type_any) *Type_var_method {
	var output = E_var_method
	var value, ok = type_any.backref.(*Type_var_method)
	if ok {
		output = value
	}
	return output
}

func A_var_method(
	type_var *Type_var,
	method_string *Type_string,
	type_varlist *Type_varlist) *Type_any {
	var output = V_var_method_create()
	output.P_var = type_var
	output.P_method = method_string
	output.P_varlist = type_varlist
	return output.type_any
}

// V_var_method_constructor
func V_var_method_constructor() *Type_var_method {
	var output = new(Type_var_method)
	return output
}

// V_var_method_create
func V_var_method_create() *Type_var_method {
	var output = V_var_method_constructor()
	V_var_method_initialize(output)
	return output
}

// V_var_method_initialize
func V_var_method_initialize(
	value *Type_var_method) {
	value.type_any = V_any_from_type_backref(
		T_var_method,
		value)
	value.P_var = E_var
	value.P_method = E_string
	value.P_varlist = E_varlist
}

// V_var_method_startup
func V_var_method_startup() *Type_type {
	var t_variable = T_var_method
	var e_variable = E_var_method
	V_var_method_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-method",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_var_method_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("var", T_var),
			V_var_from_namen_type("method", T_string),
			V_var_from_namen_type("varlist", T_varlist)})
	return t_variable
}

type Type_var_property struct {
	type_any   *Type_any
	P_var      *Type_var
	P_property *Type_string
}

// Type_var_method_generic
type Type_var_property_generic struct {
	Type_generic_base
}

func (type_generic Type_var_property_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_var_property_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_var_property_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_var_property_mapany_from_any(type_any)
}

func V_var_property_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var type_var_property = V_var_property_cast(type_any)
	var type_var = type_var_property.P_var
	var property_string = type_var_property.P_property
	var varnamen = V_code_name(type_lang, type_var.P_name)
	var valuen = ""
	valuen = V_stringn_from_string(property_string)
	switch type_lang {
	default:
		output = varnamen + "." + valuen
	}
	return output
}

func V_var_property_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_var_property = V_var_property_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_var *Type_var = value.P_var
	var p_property *Type_string = value.P_property
	if p_var != E_var {
		output["var"] = A_var_cast_any(p_var)
	}
	if p_property != E_string {
		output["property"] = V_string_cast_any(p_property)
	}
	return output
}

func V_var_property_cast(
	type_any *Type_any) *Type_var_property {
	var output = E_var_property
	var value, ok = type_any.backref.(*Type_var_property)
	if ok {
		output = value
	}
	return output
}

func A_var_propertyn(
	type_var *Type_var,
	propertyn string) *Type_any {
	var output = V_var_property_create()
	output.P_var = type_var
	output.P_property = V_string_from_stringn(propertyn)
	return output.type_any
}

// V_var_property_constructor
func V_var_property_constructor() *Type_var_property {
	var output = new(Type_var_property)
	return output
}

// V_var_property_create
func V_var_property_create() *Type_var_property {
	var output = V_var_property_constructor()
	V_var_property_initialize(output)
	return output
}

// V_var_property_initialize
func V_var_property_initialize(
	value *Type_var_property) {
	value.type_any = V_any_from_type_backref(
		T_var_property,
		value)
	value.P_var = E_var
	value.P_property = E_string
}

// V_var_property_startup
func V_var_property_startup() *Type_type {
	var t_variable = T_var_property
	var e_variable = E_var_property
	V_var_property_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-property",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_var_property_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("var", T_var),
			V_var_from_namen_type("property", T_string)})
	return t_variable
}

type Type_var_set struct {
	type_any *Type_any
	P_var    *Type_var
	P_value  *Type_any
}

// Type_var_set_generic
type Type_var_set_generic struct {
	Type_generic_base
}

func (type_generic Type_var_set_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_var_set_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_var_set_generic) p_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	return V_var_set_mapany_from_any(type_any)
}

func V_var_set_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var subpath = path + "/v_var_set_code_from_any"
	var type_var_set = V_var_set_cast(type_any)
	var type_var = type_var_set.P_var
	var varnamen = V_code_name(type_lang, type_var.P_name)
	var value_any = type_var_set.P_value
	var valuen = V_code_from_any(
		type_lang,
		indent+1,
		subpath,
		value_any)
	var lineindent = V_code_lineindent(type_lang, indent)
	switch type_lang {
	default:
		output = lineindent + varnamen + " = " + valuen
	}
	return output
}

func V_var_set_mapany_from_any(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_var_set = V_var_set_cast(type_any)
	var output map[string]*Type_any = make(map[string]*Type_any)
	var p_var *Type_var = value.P_var
	var p_value *Type_any = value.P_value
	if p_var != E_var {
		output["var"] = A_var_cast_any(p_var)
	}
	if p_value != E_any {
		output["value"] = p_value
	}
	return output
}

func A_var_set_cast_any(
	type_var_set *Type_var_set) *Type_any {
	var output *Type_any = type_var_set.type_any
	return output
}

func V_var_set_cast(
	type_any *Type_any) *Type_var_set {
	var output = E_var_set
	var value, ok = type_any.backref.(*Type_var_set)
	if ok {
		output = value
	}
	return output
}

func A_var_set(
	type_var *Type_var,
	value_any *Type_any) *Type_any {
	var output = V_var_set_create()
	output.P_var = type_var
	output.P_value = value_any
	return output.type_any
}

// V_var_set_constructor
func V_var_set_constructor() *Type_var_set {
	var output = new(Type_var_set)
	return output
}

// V_var_set_create
func V_var_set_create() *Type_var_set {
	var output = V_var_set_constructor()
	V_var_set_initialize(output)
	return output
}

// V_var_set_initialize
func V_var_set_initialize(
	value *Type_var_set) {
	value.type_any = V_any_from_type_backref(
		T_var_set,
		value)
}

// V_var_set_startup
func V_var_set_startup() *Type_type {
	var t_variable = T_var_set
	var e_variable = E_var_set
	V_var_set_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-set",
		C_extends_struct,
		e_variable.type_any)
	t_variable.type_generic = new(Type_var_set_generic)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_from_namen_type("var", T_var),
			V_var_from_namen_type("value", T_any)})
	return t_variable
}

// Type_varlist
type Type_varlist struct {
	type_any  *Type_any
	P_listvar []*Type_var
}

// Type_varlist_generic
type Type_varlist_generic struct {
	Type_generic_base
}

func (type_generic Type_varlist_generic) p_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	return V_varlist_any_from_any_indexn(
		type_any,
		indexn)
}

func (type_generic Type_varlist_generic) p_code_from_any(
	type_lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	return V_varlist_code_from_any(
		type_lang,
		indent,
		path,
		type_any)
}

func (type_generic Type_varlist_generic) p_listany_from_any(
	type_any *Type_any) []*Type_any {
	return V_varlist_listany_from_any(
		type_any)
}

func V_varlist_any_from_any_indexn(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_varlist *Type_varlist = V_varlist_cast(type_any)
	var type_var *Type_var = V_varlist_var_from_varlist_indexn(
		type_varlist,
		indexn)
	var output *Type_any = type_var.type_any
	return output
}

func V_varlist_code_from_any(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = "" +
		"f_varlist(" +
		")"
	return output
}

func V_varlist_listany_from_any(
	type_any *Type_any) []*Type_any {
	var type_varlist *Type_varlist = V_varlist_cast(type_any)
	var output []*Type_any = V_varlist_listany_from_listvar(type_varlist.P_listvar)
	return output
}

func V_varlist_listany_from_listvar(
	listvar []*Type_var) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, value := range listvar {
		output = append(output, A_var_cast_any(value))
	}
	return output
}

func V_varlist_var_from_varlist_indexn(
	type_varlist *Type_varlist,
	indexn int) *Type_var {
	var output *Type_var = E_var
	var listvalue []*Type_var = type_varlist.P_listvar
	if len(listvalue) <= indexn {
		var value *Type_var = listvalue[indexn-1]
		output = value
	}
	return output
}

func V_varlist_cast(
	type_any *Type_any) *Type_varlist {
	var output *Type_varlist = E_varlist
	var value, ok = type_any.backref.(*Type_varlist)
	if ok {
		output = value
	}
	return output
}

// V_varlist_from_listvar
func V_varlist_from_listvar(
	listvar []*Type_var) *Type_varlist {
	var output *Type_varlist = V_varlist_create()
	output.P_listvar = listvar
	return output
}

// V_varlist_constructor
func V_varlist_constructor() *Type_varlist {
	var output = new(Type_varlist)
	return output
}

// V_varlist_create
func V_varlist_create() *Type_varlist {
	var output = V_varlist_constructor()
	V_varlist_initialize(output)
	return output
}

// V_varlist_initialize
func V_varlist_initialize(
	value *Type_varlist) {
	value.type_any = V_any_from_type_backref(
		T_varlist,
		value)
	value.P_listvar = []*Type_var{}
}

// V_varlist_startup
func V_varlist_startup() *Type_type {
	var t_variable = T_varlist
	var e_variable = E_varlist
	V_varlist_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"varlist",
		C_extends_list,
		e_variable.type_any)
	t_variable.type_generic = new(Type_varlist_generic)
	return t_variable
}

// Type_boolean_from_booleann_generic
type Type_boolean_from_booleann_generic struct {
	Type_generic_base
}

func (type_generic Type_boolean_from_booleann_generic) p_func() *Type_func {
	var output *Type_func = V_boolean_from_booleann_func()
	return output
}

// V_boolean_from_booleann_func
func V_boolean_from_booleann_func() *Type_func {
	var t_variable = T_boolean_from_booleann
	var var_output_boolean = V_var_mutable_from_namen_type(
		"output",
		T_boolean)
	var var_booleann = V_var_from_namen_type(
		"booleann",
		T_booleann)
	var output *Type_func = V_func_from_type_return_varlist_value(
		t_variable,
		T_boolean,
		V_varlist_from_listvar(
			[]*Type_var{
				var_booleann}),
		A_anylist_from_listany(
			[]*Type_any{
				A_var_declare( // var output : Vx_Core.Type_boolean = Vx_Core.c_false
					var_output_boolean,
					E_any),
				A_if_from_type_if_then( // if booleann {
					T_boolean,
					var_booleann.type_any,
					A_var_set( // output = Vx_Core.c_true
						var_output_boolean,
						C_true.type_any))}))
	return output
}

// V_boolean_from_booleann_startup
func V_boolean_from_booleann_startup() *Type_type {
	var t_variable = T_boolean_from_booleann
	var e_variable = E_boolean_from_booleann
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"boolean<-booleann",
		C_extends_func,
		e_variable.type_any)
	t_variable.type_generic = new(Type_boolean_from_booleann_generic)
	return t_variable
}

func V_const_false_startup() *Type_any {
	var c_variable = C_false
	V_boolean_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"false",
		type_any)
	c_variable.P_booleann = false
	return c_variable.type_any
}

func V_const_true_startup() *Type_any {
	var c_variable = C_true
	V_boolean_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"true",
		type_any)
	c_variable.P_booleann = true
	return c_variable.type_any
}

func V_const_lang_c_startup() *Type_any {
	var c_variable = C_lang_c
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-c",
		type_any)
	c_variable.P_name = V_string_from_stringn("c")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_cpp_startup() *Type_any {
	var c_variable = C_lang_cpp
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-cpp",
		type_any)
	c_variable.P_name = V_string_from_stringn("cpp")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_csharp_startup() *Type_any {
	var c_variable = C_lang_csharp
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-csharp",
		type_any)
	c_variable.P_name = V_string_from_stringn("csharp")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_go_startup() *Type_any {
	var c_variable = C_lang_go
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-go",
		type_any)
	c_variable.P_name = V_string_from_stringn("go")
	c_variable.P_indent = V_string_from_stringn(" ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_java_startup() *Type_any {
	var c_variable = C_lang_java
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-java",
		type_any)
	c_variable.P_name = V_string_from_stringn("java")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_js_startup() *Type_any {
	var c_variable = C_lang_js
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-js",
		type_any)
	c_variable.P_name = V_string_from_stringn("js")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_kotlin_startup() *Type_any {
	var c_variable = C_lang_kotlin
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-kotlin",
		type_any)
	c_variable.P_name = V_string_from_stringn("kotlin")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_py_startup() *Type_any {
	var c_variable = C_lang_py
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-py",
		type_any)
	c_variable.P_name = V_string_from_stringn("py")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_rust_startup() *Type_any {
	var c_variable = C_lang_rust
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-rust",
		type_any)
	c_variable.P_name = V_string_from_stringn("rust")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_swift_startup() *Type_any {
	var c_variable = C_lang_swift
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-swift",
		type_any)
	c_variable.P_name = V_string_from_stringn("swift")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

func V_const_lang_ts_startup() *Type_any {
	var c_variable = C_lang_ts
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.type_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-ts",
		type_any)
	c_variable.P_name = V_string_from_stringn("ts")
	c_variable.P_indent = V_string_from_stringn("  ")
	c_variable.P_pkgref = "."
	return c_variable.type_any
}

var T_any *Type_type = V_type_constructor()
var T_anylist *Type_type = V_type_constructor()
var T_async *Type_type = V_type_constructor()
var T_boolean *Type_type = V_type_constructor()
var T_boolean_from_booleann *Type_type = V_type_constructor()
var T_booleann *Type_type = V_type_constructor()
var T_const *Type_type = V_type_constructor()
var T_context *Type_type = V_type_constructor()
var T_copy *Type_type = V_type_constructor()
var T_decimal *Type_type = V_type_constructor()
var T_empty *Type_type = V_type_constructor()
var T_func *Type_type = V_type_constructor()
var T_func_declare *Type_type = V_type_constructor()
var T_if *Type_type = V_type_constructor()
var T_lang *Type_type = V_type_constructor()
var T_list *Type_type = V_type_constructor()
var T_map *Type_type = V_type_constructor()
var T_msg *Type_type = V_type_constructor()
var T_msgblock *Type_type = V_type_constructor()
var T_new *Type_type = V_type_constructor()
var T_package *Type_type = V_type_constructor()
var T_packagemap *Type_type = V_type_constructor()
var T_project *Type_type = V_type_constructor()
var T_scope *Type_type = V_type_constructor()
var T_string *Type_type = V_type_constructor()
var T_stringn *Type_type = V_type_constructor()
var T_stringlist *Type_type = V_type_constructor()
var T_stringmap *Type_type = V_type_constructor()
var T_struct *Type_type = V_type_constructor()
var t_thenelse *Type_type = V_type_constructor()
var T_thenelselist *Type_type = V_type_constructor()
var T_type *Type_type = V_type_constructor()
var T_typelist *Type_type = V_type_constructor()
var T_var *Type_type = V_type_constructor()
var T_var_declare *Type_type = V_type_constructor()
var T_var_method *Type_type = V_type_constructor()
var T_var_property *Type_type = V_type_constructor()
var T_var_set *Type_type = V_type_constructor()
var T_varlist *Type_type = V_type_constructor()

var E_any *Type_any = V_any_constructor()
var E_anylist *Type_anylist = V_anylist_constructor()
var E_booleann *Type_booleann = V_booleann_constructor()
var E_const *Type_const = V_const_constructor()
var E_func *Type_func = V_func_constructor()
var E_func_declare *Type_func_declare = V_func_declare_constructor()
var E_if *Type_if = V_if_constructor()
var E_lang *Type_lang = V_lang_constructor()
var E_list *Type_list = V_list_constructor()
var E_map *Type_map = V_map_constructor()
var E_msg *Type_msg = V_msg_constructor()
var E_msgblock *Type_msgblock = V_msgblock_constructor()
var E_package *Type_package = V_package_constructor()
var E_project *Type_project = V_project_constructor()
var E_scope *Type_scope = V_scope_constructor()
var E_string *Type_string = V_string_constructor()
var E_stringlist *Type_stringlist = V_stringlist_constructor()
var E_stringmap *Type_stringmap = V_stringmap_constructor()
var E_struct *Type_struct = V_struct_constructor()
var E_thenelse *Type_thenelse = V_thenelse_constructor()
var E_thenelselist *Type_thenelselist = V_thenelselist_constructor()
var E_type *Type_type = V_type_constructor()
var E_typelist *Type_typelist = V_typelist_constructor()
var E_var *Type_var = V_var_constructor()
var E_var_declare *Type_var_declare = V_var_declare_constructor()
var E_var_method *Type_var_method = V_var_method_constructor()
var E_var_property *Type_var_property = V_var_property_constructor()
var E_var_set *Type_var_set = V_var_set_constructor()
var E_varlist *Type_varlist = V_varlist_constructor()
var E_boolean_from_booleann *Type_type = V_type_constructor()

var E_generic_any *Type_any_generic = new(Type_any_generic)

var C_false *Type_boolean = V_boolean_constructor()
var C_true *Type_boolean = V_boolean_constructor()
var C_extends_func *Type_string = V_string_constructor()
var C_extends_list *Type_string = V_string_constructor()
var C_extends_map *Type_string = V_string_constructor()
var C_extends_struct *Type_string = V_string_constructor()
var C_lang_c *Type_lang = V_lang_constructor()
var C_lang_cpp *Type_lang = V_lang_constructor()
var C_lang_csharp *Type_lang = V_lang_constructor()
var C_lang_java *Type_lang = V_lang_constructor()
var C_lang_js *Type_lang = V_lang_constructor()
var C_lang_go *Type_lang = V_lang_constructor()
var C_lang_kotlin *Type_lang = V_lang_constructor()
var C_lang_py *Type_lang = V_lang_constructor()
var C_lang_rust *Type_lang = V_lang_constructor()
var C_lang_swift *Type_lang = V_lang_constructor()
var C_lang_ts *Type_lang = V_lang_constructor()
var C_var_context *Type_var = V_var_constructor()

var c_listtype []*Type_type = []*Type_type{
	V_any_startup(),
	V_anylist_startup(),
	V_boolean_startup(),
	V_booleann_startup(),
	V_const_startup(),
	V_func_startup(),
	V_func_declare_startup(),
	V_lang_startup(),
	V_list_startup(),
	V_map_startup(),
	V_msg_startup(),
	V_msgblock_startup(),
	V_package_startup(),
	V_project_startup(),
	V_scope_startup(),
	V_string_startup(),
	V_stringlist_startup(),
	V_stringmap_startup(),
	V_struct_startup(),
	V_thenelse_startup(),
	V_thenelselist_startup(),
	V_type_startup(),
	V_typelist_startup(),
	V_var_startup(),
	V_var_declare_startup(),
	V_var_method_startup(),
	V_var_property_startup(),
	V_var_set_startup(),
	V_varlist_startup(),
	V_boolean_from_booleann_startup(),
	V_if_startup()}

var c_listconst []*Type_any = []*Type_any{
	V_const_false_startup(),
	V_const_true_startup(),
	V_const_lang_c_startup(),
	V_const_lang_cpp_startup(),
	V_const_lang_csharp_startup(),
	V_const_lang_go_startup(),
	V_const_lang_js_startup(),
	V_const_lang_java_startup(),
	V_const_lang_kotlin_startup(),
	V_const_lang_py_startup(),
	V_const_lang_rust_startup(),
	V_const_lang_swift_startup(),
	V_const_lang_ts_startup()}
