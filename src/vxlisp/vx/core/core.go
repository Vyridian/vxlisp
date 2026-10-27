package vx_core

import (
	"bufio"
	"fmt"
	"maps"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"testing"
)

var outputlog = false
var outputFile *os.File
var outputWriter *bufio.Writer

func V_anylist_from_listtype_anylist_anylist(
	listtype []*Type_type,
	orig_anylist *Type_anylist,
	type_anylist *Type_anylist) *Type_anylist {
	return E_anylist
}

func V_booleann_from_liststringn_containsn(
	liststringn []string,
	containsn string) bool {
	var output bool = false
	var posn int = V_intn_from_liststringn_findn(
		liststringn,
		containsn)
	if posn >= 0 {
		output = true
	}
	return output
}

func V_booleann_from_stringn_endsn(
	stringn string,
	endsn string) bool {
	return strings.HasSuffix(stringn, endsn)
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

func V_code_from_listany(
	type_scope *Type_scope,
	indent int,
	path string,
	listany []*Type_any) string {
	var liststring []string = []string{}
	var subpath string = path + "/code<-listany"
	for _, type_any := range listany {
		var stringn string = V_code_any(
			type_scope,
			indent,
			subpath,
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
	var output string = ""
	var type_lang = type_scope.P_lang
	var prefix = "c_"
	if type_const.P_istype {
		prefix = "t_"
	} else if type_const.P_isempty {
		if type_const != C_false.P_any.P_const {
			prefix = "e_"
		}
	}
	switch type_lang {
	case C_lang_go:
		prefix = V_stringn_uppercase(
			prefix)
	}
	output = "" +
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
				output)
		if output != "" {
			output += type_lang.P_pkgref
		}
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
			V_stringn_cast_string(type_lang.P_indent),
			indent)
	return output
}

// V_code_name
func V_code_name(
	type_scope *Type_scope,
	type_string *Type_string) string {
	var output string = V_code_namen(
		type_scope,
		V_stringn_cast_string(
			type_string))
	return output
}

// V_code_namen
func V_code_namen(
	type_scope *Type_scope,
	namen string) string {
	var output string = namen
	output = V_stringn_from_stringn_findn_replacen(
		output,
		"<-",
		"_from_")
	output = V_stringn_from_stringn_findn_replacen(
		output,
		"->",
		"_to_")
	output = V_stringn_from_stringn_findn_replacen(
		output,
		"-",
		"_")
	output = V_stringn_from_stringn_findn_replacen(
		output,
		"/",
		"_")
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
	var output string = ""
	var type_lang *Type_lang = type_scope.P_lang
	switch type_type {
	case T_booleann:
		switch type_lang {
		case C_lang_go:
			output = "bool"
		case C_lang_swift:
			output = "Bool"
		default:
			output = "Boolean"
		}
	case T_floatn:
		switch type_lang {
		case C_lang_go:
			output = "float64"
		default:
			output = "Float"
		}
	case T_intn:
		switch type_lang {
		case C_lang_go:
			output = "int"
		default:
			output = "Int"
		}
	case T_stringn:
		switch type_lang {
		case C_lang_go:
			output = "string"
		default:
			output = "String"
		}
	case T_cast_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_cast_funcn"
	case T_code_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_code_funcn"
	case T_copy_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_copy_funcn"
	case T_count_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_count_funcn"
	case T_func_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_func_funcn"
	case T_get_keyn_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_get_keyn_funcn"
	case T_get_indexn_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_get_indexn_funcn"
	case T_listany_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_listany_funcn"
	case T_listkeyn_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_listkey_funcn"
	case T_mapany_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_mapany_funcn"
	case T_new_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_new_funcn"
	case T_set_keyn_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_set_keyn_funcn"
	case T_set_indexn_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_set_indexn_funcn"
	case T_shutdown_funcn:
		output = V_code_type_pkgname(
			type_scope,
			type_type) +
			"Type_shutdown_funcn"
	default:
		if type_type.P_isnative {
			var p_container *Type_type = type_type.P_container
			var containertypen string = ""
			switch p_container {
			case T_floatn:
				switch type_lang {
				case C_lang_go:
					containertypen = "float"
				default:
					containertypen = "Float"
				}
			case T_intn:
				switch type_lang {
				case C_lang_go:
					containertypen = "int"
				default:
					containertypen = "Int"
				}
			case T_stringn:
				switch type_lang {
				case C_lang_go:
					containertypen = "string"
				default:
					containertypen = "String"
				}
			default:
				switch type_lang {
				case C_lang_go:
					containertypen = "" +
						"*" +
						V_code_type_pkgname(
							type_scope,
							p_container) +
						"Type_" +
						V_code_type_name(
							type_scope,
							p_container)
				case C_lang_swift:
					containertypen = "" +
						V_code_type_pkgname(
							type_scope,
							p_container) +
						"Type_" +
						V_code_type_name(
							type_scope,
							p_container)
				}
			}
			switch type_type.P_extends {
			case C_extends_list:
				switch type_lang {
				case C_lang_go:
					output = "" +
						"[]" +
						containertypen
				case C_lang_swift:
					output = "" +
						"[" +
						containertypen +
						"]"
				default:
					output = "" +
						"[" +
						containertypen +
						"]"
				}
			case C_extends_map:
				switch type_lang {
				case C_lang_go:
					output = "" +
						"map[string]*" +
						V_code_type_pkgname(
							type_scope,
							p_container) +
						"Type_" +
						V_code_type_name(
							type_scope,
							p_container)
				case C_lang_swift:
					output = "" +
						"[String:" +
						V_code_type_pkgname(
							type_scope,
							p_container) +
						"Type_" +
						V_code_type_name(
							type_scope,
							p_container) +
						"]"
				default:
					output = "" +
						V_code_type_pkgname(
							type_scope,
							p_container) +
						"Type_" +
						V_code_type_name(
							type_scope,
							p_container)
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
		} else {
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
	}
	return output
}

func V_code_var_name(
	type_scope *Type_scope,
	type_var *Type_var) string {
	var output string = V_code_name(
		type_scope,
		type_var.P_name)
	if type_var.P_public == C_true {
		var type_lang *Type_lang = type_scope.P_lang
		switch type_lang {
		case C_lang_go:
			output = "P_" + output
		default:
			output = "p_" + output
		}
	}
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
	msgblock := V_msgblock_from_namen(
		"V_file_stringn_read_from_filenamen")
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
		var type_const *Type_const = type_any.P_const
		if type_const == nil {
		} else if type_const.P_isempty {
			output = C_true
		}
	}
	return output
}

func V_listany_immutable(
	listany []*Type_any) []*Type_any {
	var output []*Type_any = []*Type_any{}
	copy(output, listany)
	return output
}

func V_listany_mutable(
	listany []*Type_any) []*Type_any {
	var output []*Type_any = []*Type_any{}
	copy(output, listany)
	return output
}

func V_mapany_immutable(
	mapany map[string]*Type_any) map[string]*Type_any {
	var output map[string]*Type_any = maps.Clone(mapany)
	return output
}

func V_mapany_mutable(
	mapany map[string]*Type_any) map[string]*Type_any {
	var output map[string]*Type_any = maps.Clone(mapany)
	return output
}

func V_lineindent(
	indent int) string {
	var output = ""
	if indent > 0 {
		output = "\n" +
			V_stringn_from_stringn_repeatn(
				" ",
				indent)
	}
	return output
}

func V_liststringn_from_liststring(
	liststring []*Type_string) []string {
	var output []string = []string{}
	for _, type_string := range liststring {
		var stringn = V_stringn_cast_string(
			type_string)
		output = append(output, stringn)
	}
	return output
}

func V_log_any(
	type_any *Type_any) {
	var displayn = V_stringn_display_from_any(
		type_any)
	V_log_stringn(
		displayn)
}

func V_log_listany(
	listany []*Type_any) {
	if len(listany) == 0 {
		V_log_stringn("[]")
	} else {
		V_log_stringn("[")
		for _, type_any := range listany {
			V_log_any(
				type_any)
		}
		V_log_stringn("]")
	}
}

func V_log_liststringn(
	liststringn []string) {
	if len(liststringn) == 0 {
		V_log_stringn("[]")
	} else {
		V_log_stringn("[")
		for _, stringn := range liststringn {
			V_log_stringn(
				stringn)
		}
		V_log_stringn("]")
	}
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

func V_stringn_cast_intn(
	intn int) string {
	var output string = strconv.Itoa(intn)
	return output
}

func V_stringn_cast_floatn(
	floatn float64) string {
	return strconv.FormatFloat(floatn, 'f', 6, 64)
}

func V_stringn_compare_expectedn_actualn(
	expected string,
	actual string,
	size int,
	msgblock *Type_msgblock) string {
	foundline := 0
	errortext := ""
	if msgblock.P_iserror {
		errortext = V_stringn_display_from_any(
			msgblock.P_any)
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
		errortext = "Line: " +
			V_stringn_cast_intn(foundline) +
			"\n" +
			V_stringn_from_liststringn_joinn(
				errortexts,
				"\n")
	}
	return errortext
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
	var type_const = type_any.P_const
	if indent != 0 && type_const != nil {
		var constpath = type_const.P_path
		var constname = type_const.P_name
		if type_const.P_pkgname == "vx/core" {
			constpath = constname
		}
		if type_const.P_isempty {
			if constpath != "false" {
				constpath = "(empty " +
					constpath +
					")"
			}
		}
		output = indentfirst +
			constpath
	} else {
		var type_type = type_any.P_type
		var typepath = type_type.P_path
		switch typepath {
		case "vx/core/boolean":
			var type_boolean = V_boolean_cast(
				type_any)
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
			var type_string = V_string_cast(
				type_any)
			var stringn = type_string.P_stringn
			output = indentfirst +
				"\"" +
				stringn +
				"\""
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
				var listany []*Type_any = V_listany_any(type_any)
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
				var listkey []string = V_listkey_any(
					type_any)
				if len(listkey) > 0 {
					var mapany map[string]*Type_any = V_mapany_any(
						type_any)
					var listprop []string = []string{}
					var lineindent1 = V_lineindent(
						indent + 1)
					var lineindent2 = V_lineindent(
						indent + 2)
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
							var valuen = V_stringn_display_from_any_indent_value(
								item_any,
								indent+
									2)
							var prop = ""
							if V_booleann_from_stringn_containsn(
								valuen, "\n") {
								prop = lineindent1 +
									key +
									lineindent2 +
									valuen
							} else {
								prop = lineindent1 +
									key +
									" " +
									valuen
							}
							listprop = append(listprop, prop)
						}
					}
					props = V_stringn_from_liststringn(
						listprop)
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
		var typenamen = V_typenamen_from_any(
			type_any)
		switch typenamen {
		case "vx/core/string":
			var type_string = V_string_cast(
				type_any)
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

func V_stringn_cast_string(
	type_string *Type_string) string {
	var output string = type_string.P_stringn
	return output
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

func V_t_copy_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_any)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var,
				anylist_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_copy_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							V_cast_var(
								any_var)))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								V_cast_var(
									generic_var),
								V_cast_var(
									any_var),
								V_cast_var(
									anylist_var)})))})
	default:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var,
				anylist_var})
		var t_x_cast_any *Type_type = V_t_x_cast_x(
			type_scope,
			type_type,
			T_any)
		var t_x_copy *Type_type = V_t_x_copy(
			type_scope,
			type_type)
		var value_var *Type_var = V_var_new_from_namen_type(
			"value",
			type_type)
		var copy_var *Type_var = V_var_new_from_namen_type(
			"copy-value",
			type_type)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					value_var,
					A_func_call_any(
						t_x_cast_any,
						V_cast_var(
							any_var))),
				A_var_declare(
					copy_var,
					A_func_call(
						t_x_copy,
						V_anylist_from_listany(
							[]*Type_any{
								V_cast_var(
									value_var),
								V_cast_var(
									anylist_var)}))),
				A_var_declare(
					output_var,
					A_var_propertyn(
						copy_var,
						"any"))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"copy-"+
			typenamen,
		T_any,
		type_varlist,
		value)
	return output
}

func V_t_x_copy(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var t_copy_funcn *Type_type = V_t_p_copy_funcn(
		type_scope)
	var t_generic_from_any *Type_type = V_t_generic_from_any(
		type_scope)
	var value_var *Type_var = V_var_new_from_namen_type(
		"value",
		type_type)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var output_var *Type_var = V_var_new_mutable_from_namen_type(
		"output",
		type_type)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		var generic_var *Type_var = V_var_new_mutable_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call_any(
						t_generic_from_any,
						value_var.P_any)),
				A_var_declare(
					output_var,
					A_var_method(
						generic_var,
						t_copy_funcn,
						V_anylist_from_listany(
							[]*Type_any{
								value_var.P_any,
								anylist_var.P_any})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen+
			"-copy",
		type_type,
		V_varlist_from_listvar(
			[]*Type_var{
				value_var,
				anylist_var}),
		value)
	return output
}

func V_t_p_copy_funcn(
	type_scope *Type_scope) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"p-copy-funcn",
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				any_var,
				anylist_var}),
		value)
	return output
}

func V_t_count_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_intn)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_count_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							V_cast_var(
								any_var)))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								V_cast_var(
									generic_var),
								V_cast_var(
									any_var)})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"count-"+
			typenamen,
		T_intn,
		type_varlist,
		value)
	return output
}

func V_t_f_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_type)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		type_type)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var value *Type_any = E_any
	var type_varlist *Type_varlist = E_varlist
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				type_var,
				anylist_var})
		var t_new_x *Type_type = V_t_new_x(
			type_scope,
			type_type)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					output_var,
					A_func_call(
						t_new_x,
						V_anylist_from_listany(
							[]*Type_any{
								V_cast_var(
									type_var),
								V_cast_var(
									anylist_var)})))})
	default:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				anylist_var})
		var t_x_new_any *Type_type = V_t_x_new(
			type_scope,
			type_type)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					output_var,
					A_func_call_any(
						t_x_new_any,
						V_cast_var(
							anylist_var)))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen,
		type_type,
		type_varlist,
		value)
	output.P_prefix = "f"
	return output
}

func V_t_generic_from_any(
	type_scope *Type_scope) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"generic<-any",
		T_generic,
		V_varlist_from_listvar(
			[]*Type_var{
				any_var}),
		value)
	return output
}

func V_t_generic_from_type(
	type_scope *Type_scope) *Type_type {
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_any)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"generic<-type",
		T_generic,
		V_varlist_from_listvar(
			[]*Type_var{
				type_var}),
		value)
	return output
}

func V_t_get_keyn_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var keyn_var *Type_var = V_var_new_from_namen_type(
		"keyn",
		T_stringn)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_any)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var,
				keyn_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_get_keyn_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							any_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								any_var.P_any,
								keyn_var.P_any})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"get-keyn-"+
			typenamen,
		T_any,
		type_varlist,
		value)
	return output
}

func V_t_get_indexn_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var indexn_var *Type_var = V_var_new_from_namen_type(
		"indexn",
		T_intn)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_any)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var,
				indexn_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_get_indexn_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							any_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								any_var.P_any,
								indexn_var.P_any})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"get-indexn-"+
			typenamen,
		T_any,
		type_varlist,
		value)
	return output
}

func V_t_listany() *Type_type {
	var output *Type_type = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"listany",
		C_extends_list,
		T_any,
		true)
	return output
}

func V_t_listany_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var t_listany *Type_type = V_t_listany()
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		t_listany)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_listany_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							any_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								any_var.P_any})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"listany-"+
			typenamen,
		t_listany,
		type_varlist,
		value)
	return output
}

func V_t_listkey_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var t_listkey *Type_type = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"listkey",
		C_extends_list,
		T_stringn,
		true)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		t_listkey)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_listkeyn_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							any_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								any_var.P_any})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"listkey-"+
			typenamen,
		t_listkey,
		type_varlist,
		value)
	return output
}

func V_t_listtype() *Type_type {
	var output *Type_type = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"listtype",
		C_extends_list,
		T_type,
		true)
	return output
}

func V_t_listvar() *Type_type {
	var output *Type_type = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"listvar",
		C_extends_list,
		T_var,
		true)
	return output
}

func V_t_mapany_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var t_mapany *Type_type = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"mapany",
		C_extends_map,
		T_any,
		true)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		t_mapany)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var type_varlist *Type_varlist = E_varlist
	var value *Type_any = E_any
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				any_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_mapany_funcn)
		var t_generic_from_any *Type_type = V_t_generic_from_any(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_any,
						V_anylist_from_any(
							any_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								any_var.P_any})))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"mapany-"+
			typenamen,
		t_mapany,
		type_varlist,
		value)
	return output
}

func V_t_new_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_type)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_any)
	var typenamen string = "new-" + V_typenamen_from_type(
		type_type)
	var value *Type_any = E_any
	var type_varlist *Type_varlist = E_varlist
	switch type_type {
	case T_any:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				type_var,
				anylist_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_new_funcn)
		var t_generic_from_type *Type_type = V_t_generic_from_type(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_type,
						V_anylist_from_any(
							type_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								type_var.P_any,
								anylist_var.P_any})))})
	default:
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				anylist_var})
		var t_x_new_any *Type_type = V_t_x_new(
			type_scope,
			type_type)
		var value_var *Type_var = V_var_new_from_namen_type(
			"value",
			type_type)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					value_var,
					A_func_call_any(
						t_x_new_any,
						V_cast_var(
							anylist_var))),
				A_var_declare(
					output_var,
					A_var_propertyn(
						value_var,
						"any"))})
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen,
		T_any,
		type_varlist,
		value)
	return output
}

func V_t_x_new(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var t_x_copy *Type_type = V_t_x_copy(
		type_scope,
		type_type)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		type_type)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var value *Type_any = A_anylist_from_listany(
		[]*Type_any{
			A_var_declare(
				output_var,
				A_func_call(
					t_x_copy,
					V_anylist_from_listany(
						[]*Type_any{
							V_empty(
								type_type),
							V_cast_var(
								anylist_var)})))})
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen+
			"-new",
		type_type,
		V_varlist_from_listvar(
			[]*Type_var{
				anylist_var}),
		value)
	return output
}

func V_t_p_new_funcn(
	type_scope *Type_scope) *Type_type {
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_type)
	var anylist_var *Type_var = V_var_new_from_namen_type(
		"type-anylist",
		T_anylist)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"p-new-funcn",
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				type_var,
				anylist_var}),
		value)
	return output
}

func V_t_log_liststringn(
	type_scope *Type_scope) *Type_type {
	var t_liststringn = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"liststringn",
		C_extends_list,
		T_stringn,
		true)
	var stringn_var *Type_var = V_var_new_from_namen_type(
		"liststringn",
		t_liststringn)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"log-liststringn",
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				stringn_var}),
		value)
	return output
}

func V_t_release_any(
	type_scope *Type_scope) *Type_type {
	var t_shutdown_any *Type_type = V_t_shutdown_x(
		type_scope,
		T_any)
	var t_typenamen_from_any *Type_type = V_t_typenamen_from_any(
		type_scope)
	var any_var *Type_var = V_var_new_mutable_from_namen_type(
		"type-any",
		T_any)
	var value *Type_any = A_anylist_from_listany(
		[]*Type_any{
			A_var_set_propertyn_operatorn(
				any_var,
				"refcount",
				"-=",
				A_int_cast_intn(
					1)),
			A_if_from_if_then(
				A_le(
					A_var_propertyn(
						any_var,
						"refcount"),
					A_int_cast_intn(
						0)),
				A_anylist_run_from_listany(
					[]*Type_any{
						A_if_from_if_then(
							A_lt(
								A_var_propertyn(
									any_var,
									"refcount"),
								A_int_cast_intn(
									0)),
							A_func_call_any(
								T_log_stringn,
								A_plus_new_from_type_any_any(
									T_stringn,
									A_string_cast_stringn(
										"Error: Negative Refcount - "),
									A_func_call_any(
										t_typenamen_from_any,
										V_cast_var(
											any_var))))),
						A_func_call_any(
							t_shutdown_any,
							V_cast_var(
								any_var))}))})
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"release-any",
		E_type,
		V_varlist_from_listvar(
			[]*Type_var{
				any_var}),
		value)
	return output
}

func V_t_shutdown_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var t_shutdown_funcn *Type_type = V_t_p_shutdown_funcn(
		type_scope,
		type_type)
	var t_generic_from_any *Type_type = V_t_generic_from_any(
		type_scope)
	var any_var *Type_var = V_var_new_mutable_from_namen_type(
		"type-any",
		T_any)
	var generic_var *Type_var = V_var_new_mutable_from_namen_type(
		"type-generic",
		T_generic)
	var typenamen string = V_typenamen_from_type(
		type_type)
	var value *Type_any = A_anylist_from_listany(
		[]*Type_any{
			A_var_declare(
				generic_var,
				A_func_call_any(
					t_generic_from_any,
					any_var.P_any)),
			A_var_method(
				generic_var,
				t_shutdown_funcn,
				V_anylist_from_any(
					any_var.P_any))})
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"shutdown-"+typenamen,
		E_type,
		V_varlist_from_listvar(
			[]*Type_var{
				any_var}),
		value)
	return output
}

func V_t_p_shutdown_funcn(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"p-shutdown-funcn",
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				any_var}),
		value)
	return output
}

func V_t_typenamen_from_any(
	type_scope *Type_scope) *Type_type {
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"typenamen<-any",
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				any_var}),
		value)
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
		msgblock := V_msgblock_from_namen(
			"Test_" + testnamen)
		errortext := V_stringn_compare_expectedn_actualn(
			expectedn,
			actualn,
			10,
			msgblock)
		if errortext != "" {
			t.Error(errortext)
		}
	}
	return output
}

func V_test_file_from_testnamen_mapactualn(
	t *testing.T,
	testnamen string,
	mapactualn map[string]string) bool {
	var output bool = true
	for langnamen, actualn := range mapactualn {
		var testnamelangn string = testnamen +
			"-" +
			langnamen
		var testbool bool = V_test_from_file(
			t,
			testnamelangn,
			actualn)
		output = output && testbool
	}
	return output
}

func V_type_return_from_type(
	type_type *Type_type) *Type_type {
	var output = type_type
	var type_func = V_func_from_type(
		type_type)
	if type_func != E_func {
		output = type_func.P_return
	}
	return output
}

func V_typenamen_from_any(
	type_any *Type_any) string {
	var output = V_typenamen_from_type(
		V_type_from_any(
			type_any))
	return output
}

func V_typenamen_from_type(
	type_type *Type_type) string {
	var output = type_type.P_name
	return output
}

type Type_cast_funcn func(type_type *Type_type, type_any *Type_any) *Type_any
type Type_code_funcn func(type_scope *Type_scope, indent int, path string, type_any *Type_any) string
type Type_count_funcn func(type_any *Type_any) int
type Type_copy_funcn func(type_any *Type_any, type_anylist *Type_anylist) *Type_any
type Type_func_funcn func(type_type *Type_type) *Type_func
type Type_get_keyn_funcn func(type_any *Type_any, keyn string) *Type_any
type Type_get_indexn_funcn func(type_any *Type_any, indexn int) *Type_any
type Type_listany_funcn func(type_any *Type_any) []*Type_any
type Type_listkey_funcn func(type_any *Type_any) []string
type Type_mapany_funcn func(type_any *Type_any) map[string]*Type_any
type Type_new_funcn func(type_anylist *Type_anylist) *Type_any
type Type_set_keyn_funcn func(type_any *Type_any, keyn string, value *Type_any)
type Type_set_indexn_funcn func(type_any *Type_any, indexn int, value *Type_any)
type Type_shutdown_funcn func(type_any *Type_any)

// (type generic)
type Type_generic struct {
	P_any              *Type_any
	P_cast_funcn       Type_cast_funcn
	P_code_funcn       Type_code_funcn
	P_copy_funcn       Type_copy_funcn
	P_count_funcn      Type_count_funcn
	P_func_funcn       Type_func_funcn
	P_get_keyn_funcn   Type_get_keyn_funcn
	P_get_indexn_funcn Type_get_indexn_funcn
	P_listany_funcn    Type_listany_funcn
	P_listkey_funcn    Type_listkey_funcn
	P_mapany_funcn     Type_mapany_funcn
	P_new_funcn        Type_new_funcn
	P_set_keyn_funcn   Type_set_keyn_funcn
	P_set_indexn_funcn Type_set_indexn_funcn
	P_shutdown_funcn   Type_shutdown_funcn
}

// V_generic_constructor
func V_generic_constructor() *Type_generic {
	var output = new(Type_generic)
	return output
}

// V_generic_initialize
func V_generic_initialize(
	value *Type_generic) {
	value.P_any = V_any_from_type_backref(
		T_generic,
		value)
	value.P_cast_funcn = nil
	value.P_code_funcn = nil
	value.P_copy_funcn = nil
	value.P_count_funcn = nil
	value.P_func_funcn = nil
	value.P_get_keyn_funcn = nil
	value.P_get_indexn_funcn = nil
	value.P_listany_funcn = nil
	value.P_listkey_funcn = nil
	value.P_mapany_funcn = nil
	value.P_new_funcn = nil
	value.P_set_keyn_funcn = nil
	value.P_set_indexn_funcn = nil
	value.P_shutdown_funcn = nil
}

// V_generic_create
func V_generic_create() *Type_generic {
	var output = V_generic_constructor()
	V_generic_initialize(output)
	return output
}

// V_generic_shutdown
func V_generic_shutdown(
	value *Type_generic) {
	value.P_cast_funcn = nil
	value.P_code_funcn = nil
	value.P_copy_funcn = nil
	value.P_count_funcn = nil
	value.P_func_funcn = nil
	value.P_get_keyn_funcn = nil
	value.P_get_indexn_funcn = nil
	value.P_listany_funcn = nil
	value.P_listkey_funcn = nil
	value.P_mapany_funcn = nil
	value.P_new_funcn = nil
	value.P_set_keyn_funcn = nil
	value.P_set_indexn_funcn = nil
	value.P_shutdown_funcn = nil
	V_any_shutdown(
		value.P_any)
	V_global_release()
}

// V_generic_startup
func V_generic_startup() *Type_type {
	var t_variable = T_generic
	var e_variable = E_generic
	V_generic_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"generic",
		E_string,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"cast-funcn",
				T_cast_funcn),
			V_var_new_public_from_namen_type(
				"code-funcn",
				T_code_funcn),
			V_var_new_public_from_namen_type(
				"copy-funcn",
				T_copy_funcn),
			V_var_new_public_from_namen_type(
				"count-funcn",
				T_count_funcn),
			V_var_new_public_from_namen_type(
				"func-funcn",
				T_func_funcn),
			V_var_new_public_from_namen_type(
				"get-keyn-funcn",
				T_get_keyn_funcn),
			V_var_new_public_from_namen_type(
				"get-indexn-funcn",
				T_get_indexn_funcn),
			V_var_new_public_from_namen_type(
				"listany-funcn",
				T_listany_funcn),
			V_var_new_public_from_namen_type(
				"listkey-funcn",
				T_listkeyn_funcn),
			V_var_new_public_from_namen_type(
				"mapany-funcn",
				T_mapany_funcn),
			V_var_new_public_from_namen_type(
				"new-funcn",
				T_new_funcn),
			V_var_new_public_from_namen_type(
				"set-keyn-funcn",
				T_set_keyn_funcn),
			V_var_new_public_from_namen_type(
				"set-indexn-funcn",
				T_set_indexn_funcn),
			V_var_new_public_from_namen_type(
				"shutdown-funcn",
				T_shutdown_funcn)})
	var output *Type_type = t_variable
	return output
}

func V_cast_generic(
	type_generic *Type_generic,
	type_type *Type_type,
	type_any *Type_any) *Type_any {
	var output *Type_any = E_any
	var call_funcn Type_cast_funcn = type_generic.P_cast_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_type,
			type_any)
	}
	return output
}

func V_count_generic(
	type_generic *Type_generic,
	type_any *Type_any) int {
	var output int = 0
	var call_funcn Type_count_funcn = type_generic.P_count_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any)
	} else {
		var type_type *Type_type = type_any.P_type
		switch type_type.P_extends {
		case C_extends_list:
			var listany []*Type_any = V_listany_any(
				type_any)
			output = len(listany)
		case C_extends_map, C_extends_struct, C_extends_func:
			var listkey []string = V_listkey_any(
				type_any)
			output = len(listkey)
		}
	}
	return output
}

func V_copy_generic(
	type_generic *Type_generic,
	type_any *Type_any,
	type_anylist *Type_anylist) *Type_any {
	var output *Type_any = E_any
	var call_funcn Type_copy_funcn = type_generic.P_copy_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any,
			type_anylist)
	}
	return output
}

func V_func_generic(
	type_generic *Type_generic,
	type_type *Type_type) *Type_func {
	var output *Type_func = E_func
	var call_funcn Type_func_funcn = type_generic.P_func_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_type)
	}
	return output
}

// V_generic_from_any
func V_generic_from_any(
	type_any *Type_any) *Type_generic {
	var type_type *Type_type = V_type_from_any(
		type_any)
	var output *Type_generic = V_generic_from_type(
		type_type)
	return output
}

// V_generic_from_type
func V_generic_from_type(
	type_type *Type_type) *Type_generic {
	var output *Type_generic = E_generic
	if type_type.type_generic != nil {
		output = type_type.type_generic
	}
	return output
}

func V_get_keyn_generic(
	type_generic *Type_generic,
	type_any *Type_any,
	keyn string) *Type_any {
	var output *Type_any = E_any
	var call_funcn Type_get_keyn_funcn = type_generic.P_get_keyn_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any,
			keyn)
	} else {
		var mapany map[string]*Type_any = V_mapany_generic(
			type_generic,
			type_any)
		var value, ok = mapany[keyn]
		if ok {
			output = value
		}
	}
	return output
}

func V_get_indexn_generic(
	type_generic *Type_generic,
	type_any *Type_any,
	indexn int) *Type_any {
	var output *Type_any = E_any
	var call_funcn Type_get_indexn_funcn = type_generic.P_get_indexn_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any,
			indexn)
	} else {
		var listany []*Type_any = V_listany_generic(
			type_generic,
			type_any)
		if indexn > 0 || indexn <= len(listany) {
			var value *Type_any = listany[indexn]
			output = value
		}
	}
	return output
}

func V_listany_generic(
	type_generic *Type_generic,
	type_any *Type_any) []*Type_any {
	var output []*Type_any = []*Type_any{}
	var call_funcn Type_listany_funcn = type_generic.P_listany_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any)
	}
	return output
}

func V_listkey_generic(
	type_generic *Type_generic,
	type_any *Type_any) []string {
	var output []string = []string{}
	var call_funcn Type_listkey_funcn = type_generic.P_listkey_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any)
	} else {
		var type_type = type_any.P_type
		var type_varlist = type_type.P_propertylist
		if type_varlist != E_varlist {
			var listvar = type_varlist.P_listvar
			for _, type_var := range listvar {
				var prop *Type_string = type_var.P_name
				var propn string = V_stringn_cast_string(
					prop)
				output = append(output, propn)
			}
		}
	}
	return output
}

func V_mapany_generic(
	type_generic *Type_generic,
	type_any *Type_any) map[string]*Type_any {
	var output map[string]*Type_any = map[string]*Type_any{}
	var call_funcn Type_mapany_funcn = type_generic.P_mapany_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_any)
	} else {
		var listkey []string = V_listkey_generic(
			type_generic,
			type_any)
		if len(listkey) > 0 {
			for _, keyn := range listkey {
				if keyn != "" {
					var value_any *Type_any = V_get_keyn_generic(
						type_generic,
						type_any,
						keyn)
					if V_is_empty(value_any) == C_false {
						output[keyn] = value_any
					}
				}
			}
		}
	}
	return output
}

func V_new_generic(
	type_generic *Type_generic,
	type_type *Type_type,
	type_anylist *Type_anylist) *Type_any {
	var output *Type_any = E_any
	var call_funcn Type_new_funcn = type_generic.P_new_funcn
	if call_funcn != nil {
		output = call_funcn(
			type_anylist)
	}
	return output
}

func V_shutdown_generic(
	type_generic *Type_generic,
	type_any *Type_any) {
	var call_funcn Type_shutdown_funcn = type_generic.P_shutdown_funcn
	if call_funcn != nil {
		call_funcn(
			type_any)
	}
}

// (type any)
type Type_any struct {
	backref    any
	refcount   int
	P_type     *Type_type
	P_const    *Type_const
	P_msgblock *Type_msgblock
	P_delta    *Type_delta
	P_isrun    bool
}

// V_any_constructor
func V_any_constructor() *Type_any {
	var output *Type_any = new(Type_any)
	return output
}

// V_any_create
func V_any_create() *Type_any {
	var output *Type_any = V_any_constructor()
	V_any_initialize(output)
	return output
}

// V_any_initialize
func V_any_initialize(
	value *Type_any) {
	value.P_type = T_any
	value.backref = value
}

// V_any_shutdown
func V_any_shutdown(
	value *Type_any) {
	value.backref = nil
	var type_msgblock *Type_msgblock = value.P_msgblock
	if type_msgblock != E_msgblock {
		value.P_msgblock = E_msgblock
		V_release_any(
			type_msgblock.P_any)
	}
	var type_const *Type_const = value.P_const
	if type_const != E_const {
		value.P_const = E_const
		V_release_any(
			type_const.P_any)
	}
	value.P_type = E_type
	V_global_release()
}

// V_any_startup
func V_any_startup() *Type_type {
	var t_variable = T_any
	var e_variable = E_any
	V_any_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"any",
		E_string,
		e_variable)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_private_from_namen_type(
				"backref",
				T_any),
			V_var_new_private_from_namen_type(
				"refcount",
				T_intn),
			V_var_new_public_from_namen_type(
				"type",
				T_type),
			V_var_new_public_from_namen_type(
				"const",
				T_const),
			V_var_new_public_from_namen_type(
				"msgblock",
				T_msgblock),
			V_var_new_public_from_namen_type(
				"delta",
				T_delta),
			V_var_new_public_from_namen_type(
				"isrun",
				T_booleann)})
	var output *Type_type = t_variable
	return output
}

// V_cast_any
func V_cast_any(
	type_type *Type_type,
	type_any *Type_any) *Type_any {
	var type_generic *Type_generic = V_generic_from_type(
		type_type)
	var output *Type_any = V_cast_generic(
		type_generic,
		type_type,
		type_any)
	return output
}

// V_copy_any
func V_copy_any(
	type_any *Type_any,
	type_anylist *Type_anylist) *Type_any {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output *Type_any = V_copy_generic(
		type_generic,
		type_any,
		type_anylist)
	return output
}

// V_any_from_type_backref
func V_any_from_type_backref(
	type_type *Type_type,
	backref any) *Type_any {
	var output *Type_any = V_any_create()
	output.P_type = type_type
	output.backref = backref
	return output
}

// V_count_any
func V_count_any(
	type_any *Type_any) int {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output int = V_count_generic(
		type_generic,
		type_any)
	return output
}

// V_empty_from_any
func V_empty_from_any(
	type_any *Type_any) *Type_any {
	var type_type *Type_type = type_any.P_type
	var output *Type_any = type_type.P_empty
	return output
}

// V_get_keyn_any
func V_get_keyn_any(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output *Type_any = V_get_keyn_generic(
		type_generic,
		type_any,
		keyn)
	return output
}

// V_get_indexn_any
func V_get_indexn_any(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output *Type_any = V_get_indexn_generic(
		type_generic,
		type_any,
		indexn)
	return output
}

// V_listany_any
func V_listany_any(
	type_any *Type_any) []*Type_any {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output []*Type_any = V_listany_generic(
		type_generic,
		type_any)
	return output
}

// V_listkey_any
func V_listkey_any(
	type_any *Type_any) []string {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output []string = V_listkey_generic(
		type_generic,
		type_any)
	return output
}

// V_mapany_any
func V_mapany_any(
	type_any *Type_any) map[string]*Type_any {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	var output map[string]*Type_any = V_mapany_generic(
		type_generic,
		type_any)
	return output
}

// V_new_any
func V_new_any(
	type_type *Type_type,
	type_anylist *Type_anylist) *Type_any {
	var type_generic *Type_generic = V_generic_from_type(
		type_type)
	var output *Type_any = V_new_generic(
		type_generic,
		type_type,
		type_anylist)
	return output
}

// V_release_any
func V_release_any(
	type_any *Type_any) {
	type_any.refcount -= 1
	if type_any.refcount <= 0 {
		if type_any.refcount < 0 {
			V_log_stringn(
				"Error: Negative Refcount - " +
					V_typenamen_from_any(
						type_any))
		}
		V_shutdown_any(
			type_any)
	}
}

// V_release_except_listany
func V_release_except_listany(
	except_any *Type_any,
	listany []*Type_any) {
	for _, type_any := range listany {
		if type_any != except_any {
			V_release_any(
				type_any)
		}
	}
}

// V_release_listany
func V_release_listany(
	listany []*Type_any) {
	for _, type_any := range listany {
		V_release_any(
			type_any)
	}
}

// V_reserve_any
func V_reserve_any(
	type_any *Type_any) {
	type_any.refcount += 1
}

// v_reserve_listany
func v_reserve_listany(
	listany []*Type_any) {
	for _, type_any := range listany {
		V_reserve_any(
			type_any)
	}
}

// V_shutdown_any
func V_shutdown_any(
	type_any *Type_any) {
	var type_generic *Type_generic = V_generic_from_any(
		type_any)
	V_shutdown_generic(
		type_generic,
		type_any)
}

// V_code_any
func V_code_any(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output string = ""
	var type_type *Type_type = type_any.P_type
	var subpath string = path + "/code<-any/" + type_type.P_name
	var type_const *Type_const = nil
	switch type_type {
	case T_const:
		switch type_any {
		case T_const.P_any:
			type_const = V_const_from_any(
				type_any)
		default:
			type_const = V_const_cast(
				type_any)
		}
	default:
		type_const = V_const_from_any(
			type_any)
	}
	if type_const != nil {
		switch type_any {
		case E_booleann.P_any:
			output = "false"
		case E_intn.P_any:
			output = "0"
		case E_stringn.P_any:
			output = "\"\""
		case E_none.P_any:
			var type_lang *Type_lang = type_scope.P_lang
			switch type_lang {
			case C_lang_go, C_lang_swift:
				output = "nil"
			default:
				output = "null"
			}
		default:
			output = V_code_const_name(
				type_scope,
				type_const)
		}
	} else {
		var type_generic *Type_generic = V_generic_from_any(
			type_any)
		if type_generic.P_code_funcn != nil {
			output = type_generic.P_code_funcn(
				type_scope,
				indent,
				subpath,
				type_any)
		}
	}
	return output
}

// F_any
func F_any(
	type_type *Type_type,
	type_anylist *Type_anylist) *Type_any {
	var output *Type_any = V_new_any(
		type_type,
		type_anylist)
	return output
}

// (type anylist)
type Type_anylist struct {
	P_any     *Type_any
	P_listany []*Type_any
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_anylist
	type_generic.P_get_indexn_funcn = V_get_indexn_anylist
	type_generic.P_listany_funcn = V_listany_anylist
	t_variable.type_generic = type_generic
	return t_variable
}

func V_get_from_anylist_indexn(
	type_anylist *Type_anylist,
	indexn int) *Type_any {
	var output *Type_any = E_any
	var listvalue []*Type_any = type_anylist.P_listany
	if len(listvalue) >= indexn {
		output = listvalue[indexn-1]
	}
	return output
}

func V_get_indexn_anylist(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_anylist *Type_anylist = V_anylist_cast(
		type_any)
	var output *Type_any = V_get_from_anylist_indexn(
		type_anylist,
		indexn)
	return output
}

func V_code_anylist(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_anylist = V_anylist_cast(
		type_any)
	var listprop []string
	var isrun = type_anylist.P_any.P_isrun
	var subindent = indent
	var lineindent = ""
	var join = ""
	if !isrun {
		join = ","
		subindent += 1
	}
	for _, type_any := range type_anylist.P_listany {
		var prop = V_code_any(
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

// V_cast_anylist
func V_cast_anylist(
	value *Type_anylist) *Type_any {
	var output *Type_any = value.P_any
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

func V_listany_anylist(
	type_any *Type_any) []*Type_any {
	var type_anylist *Type_anylist = V_anylist_cast(
		type_any)
	var output []*Type_any = type_anylist.P_listany
	return output
}

func A_anylist_from_listany(
	listany []*Type_any) *Type_any {
	var type_anylist *Type_anylist = V_anylist_from_listany(
		listany)
	var output = type_anylist.P_any
	return output
}

func A_anylist_run_from_listany(
	listany []*Type_any) *Type_any {
	var type_anylist *Type_anylist = V_anylist_from_listany(
		listany)
	type_anylist.P_any.P_isrun = true
	var output = type_anylist.P_any
	return output
}

func V_anylist_from_any(
	type_any *Type_any) *Type_anylist {
	var output = V_anylist_create()
	output.P_listany = []*Type_any{
		type_any}
	return output
}

func V_anylist_from_listany(
	listany []*Type_any) *Type_anylist {
	var output = V_anylist_create()
	output.P_listany = listany
	return output
}

func V_anylist_run_from_any(
	type_any *Type_any) *Type_anylist {
	var output *Type_anylist = V_anylist_from_any(
		type_any)
	output.P_any.P_isrun = true
	return output
}

// (type anymap)
type Type_anymap struct {
	P_any     *Type_any
	P_listkey []string
	P_mapany  map[string]*Type_any
}

// V_anymap_constructor
func V_anymap_constructor() *Type_anymap {
	var output *Type_anymap = new(Type_anymap)
	return output
}

// V_anymap_create
func V_anymap_create() *Type_anymap {
	var output *Type_anymap = V_anymap_constructor()
	V_anymap_initialize(
		output)
	return output
}

// V_anymap_initialize
func V_anymap_initialize(
	value *Type_anymap) {
	value.P_any = V_any_from_type_backref(
		T_anymap,
		value)
	value.P_listkey = []string{}
	value.P_mapany = map[string]*Type_any{}
}

// V_anymap_startup
func V_anymap_startup() *Type_type {
	var t_variable = T_anymap
	var e_variable = E_anymap
	V_anymap_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"anymap",
		C_extends_map,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_anymap
	type_generic.P_listkey_funcn = V_listkey_anymap
	type_generic.P_mapany_funcn = V_mapany_anymap
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_anymap
func V_cast_anymap(
	value *Type_anymap) *Type_any {
	return value.P_any
}

// V_anymap_cast
func V_anymap_cast(
	type_any *Type_any) *Type_anymap {
	var output *Type_anymap = E_anymap
	var value, ok = type_any.backref.(*Type_anymap)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_anymap(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_anymap *Type_anymap = V_anymap_cast(
		type_any)
	var output *Type_any = V_any_from_anymap_keyn(
		type_anymap,
		keyn)
	return output
}

func V_listkey_anymap(
	type_any *Type_any) []string {
	var value *Type_anymap = V_anymap_cast(
		type_any)
	var output []string = value.P_listkey
	return output
}

func V_mapany_anymap(
	type_any *Type_any) map[string]*Type_any {
	var value *Type_anymap = V_anymap_cast(
		type_any)
	var output map[string]*Type_any = value.P_mapany
	return output
}

func V_any_from_anymap_keyn(
	type_anymap *Type_anymap,
	keyn string) *Type_any {
	var output *Type_any = E_any
	var mapany map[string]*Type_any = type_anymap.P_mapany
	var value, ok = mapany[keyn]
	if ok {
		output = value
	}
	return output
}

func V_anylist_from_anymap(
	type_anymap *Type_anymap) *Type_anylist {
	var output *Type_anylist = E_anylist
	var listkey []string = type_anymap.P_listkey
	var mapany map[string]*Type_any = type_anymap.P_mapany
	var listany []*Type_any = []*Type_any{}
	for _, keyn := range listkey {
		var value, ok = mapany[keyn]
		if ok {
			if value != E_any {
				listany = append(listany, value)
			}
		}
	}
	if len(listany) > 0 {
		output = V_anylist_create()
		output.P_listany = listany
	}
	return output
}

func V_anymap_from_listkey_listany(
	listkey []string,
	listany []*Type_any) *Type_anymap {
	var output *Type_anymap = E_anymap
	if len(listkey) > 0 {
		var ilen int = len(listany)
		var listkeyvalid []string = []string{}
		var mapany map[string]*Type_any = map[string]*Type_any{}
		for idx, keyn := range listkey {
			if idx <= ilen {
				var value *Type_any = listany[idx]
				if value != E_any {
					listkeyvalid = append(listkeyvalid, keyn)
					mapany[keyn] = value
				}
			}
		}
		if len(listkeyvalid) > 0 {
			output = V_anymap_create()
			output.P_listkey = listkeyvalid
			output.P_mapany = mapany
		}
	}
	return output
}

// Type_async
type Type_async struct {
	P_any        *Type_any
	P_type       *Type_type
	P_lazy_fn    *Type_fn
	P_isresolved bool
}

// (type boolean)
type Type_boolean struct {
	P_any      *Type_any
	P_booleann bool
}

// V_boolean_constructor
func V_boolean_constructor() *Type_boolean {
	var output *Type_boolean = new(Type_boolean)
	return output
}

// V_boolean_create
func V_boolean_create() *Type_boolean {
	var output *Type_boolean = V_boolean_constructor()
	V_boolean_initialize(
		output)
	return output
}

// V_boolean_initialize
func V_boolean_initialize(
	value *Type_boolean) {
	value.P_any = V_any_from_type_backref(
		T_boolean,
		value)
	value.P_booleann = false
}

// V_boolean_shutdown
func V_boolean_shutdown(
	value *Type_boolean) {
	value.P_booleann = false
	V_any_shutdown(
		value.P_any)
	V_global_release()
}

// V_boolean_startup
func V_boolean_startup() *Type_type {
	var t_variable *Type_type = T_boolean
	var e_variable *Type_boolean = C_false
	V_boolean_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"boolean",
		E_string,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"booleann",
				T_booleann)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_boolean
	type_generic.P_copy_funcn = V_copy_boolean
	type_generic.P_new_funcn = V_new_boolean
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_boolean
func V_cast_boolean(
	value *Type_boolean) *Type_any {
	var output *Type_any = value.P_any
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

// V_boolean_copy
func V_boolean_copy(
	value *Type_boolean,
	type_anylist *Type_anylist) *Type_boolean {
	var output *Type_boolean = C_false
	return output
}

// V_copy_boolean
func V_copy_boolean(
	type_any *Type_any,
	type_anylist *Type_anylist) *Type_any {
	var value *Type_boolean = V_boolean_cast(
		type_any)
	var copy_value *Type_boolean = V_boolean_copy(
		value,
		type_anylist)
	var output *Type_any = copy_value.P_any
	return output
}

// V_boolean_new
func V_boolean_new(
	type_anylist *Type_anylist) *Type_boolean {
	var output *Type_boolean = V_boolean_copy(
		C_false,
		type_anylist)
	return output
}

// V_new_boolean
func V_new_boolean(
	type_anylist *Type_anylist) *Type_any {
	var value *Type_boolean = V_boolean_new(
		type_anylist)
	var output *Type_any = value.P_any
	return output
}

// V_code_boolean
func V_code_boolean(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var type_boolean = V_boolean_cast(
		type_any)
	if type_boolean != C_true {
		type_boolean = C_false
	}
	output = V_code_const_name(
		type_scope,
		V_const_from_any(
			V_cast_boolean(
				type_boolean)))
	return output
}

// F_boolean
func F_boolean(
	type_anylist *Type_anylist) *Type_boolean {
	var output *Type_boolean = V_boolean_new(
		type_anylist)
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

func A_boolean_from_booleann(
	booleann bool) *Type_any {
	var output *Type_any = V_cast_boolean(
		V_boolean_from_booleann(
			booleann))
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

// Type_booleann
type Type_booleann struct {
	P_any      *Type_any
	P_booleann bool
}

// V_booleann_constructor
func V_booleann_constructor() *Type_booleann {
	var output = new(Type_booleann)
	return output
}

// V_booleann_create
func V_booleann_create() *Type_booleann {
	var output = V_booleann_constructor()
	V_booleann_initialize(
		output)
	output.P_booleann = false
	return output
}

// V_booleann_initialize
func V_booleann_initialize(
	value *Type_booleann) {
	value.P_any = V_any_from_type_backref(
		T_booleann,
		value)
}

// V_booleann_startup
func V_booleann_startup() *Type_type {
	var t_variable = T_booleann
	var e_variable = E_booleann
	V_booleann_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"booleann",
		E_string,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"booleann",
				T_booleann)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_booleann
	t_variable.type_generic = type_generic
	return t_variable
}

func V_cast_booleann(
	type_booleann *Type_booleann) *Type_any {
	var output *Type_any = type_booleann.P_any
	return output
}

func V_booleann_cast(
	type_any *Type_any) *Type_booleann {
	var output *Type_booleann = E_booleann
	var value, ok = type_any.backref.(*Type_booleann)
	if ok {
		output = value
	}
	return output
}

func V_booleann_new_from_boolean(
	type_boolean *Type_boolean) *Type_booleann {
	var output *Type_booleann = V_booleann_create()
	output.P_booleann = type_boolean.P_booleann
	return output
}

func V_code_booleann(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_booleann = V_booleann_cast(
		type_any)
	var booleann bool = type_booleann.P_booleann
	var output = ""
	if booleann {
		output = "true"
	} else {
		output = "false"
	}
	return output
}

// (type const)
type Type_const struct {
	P_any     *Type_any
	P_pkgname string
	P_name    string
	P_path    string
	P_isempty bool
	P_istype  bool
	P_type    *Type_type
}

// V_const_constructor
func V_const_constructor() *Type_const {
	var output = new(Type_const)
	return output
}

// V_const_initialize
func V_const_initialize(
	value *Type_const) {
	value.P_any = V_any_from_type_backref(
		T_const,
		value)
	value.P_path = ""
	value.P_pkgname = ""
	value.P_name = ""
	value.P_isempty = false
	value.P_istype = false
	value.P_type = E_type
}

// V_const_create
func V_const_create() *Type_const {
	var output = V_const_constructor()
	V_const_initialize(
		output)
	return output
}

// V_const_startup
func V_const_startup() *Type_type {
	var t_variable = T_const
	var e_variable = E_const
	V_const_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"const",
		C_extends_struct,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"pkgname",
				T_stringn),
			V_var_new_public_from_namen_type(
				"name",
				T_stringn),
			V_var_new_public_from_namen_type(
				"path",
				T_stringn),
			V_var_new_public_from_namen_type(
				"isempty",
				T_booleann),
			V_var_new_public_from_namen_type(
				"istype",
				T_booleann),
			V_var_new_public_from_namen_type(
				"type",
				T_type)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_const
	t_variable.type_generic = type_generic
	e_variable.P_path = t_variable.P_path
	e_variable.P_pkgname = t_variable.P_pkgname
	e_variable.P_name = t_variable.P_name
	e_variable.P_isempty = true
	var output *Type_type = t_variable
	return output
}

// V_const_empty
func V_const_empty(
	type_type *Type_type) *Type_const {
	var output *Type_const = V_const_create()
	switch type_type {
	case T_boolean:
		output.P_name = "false"
	default:
		output.P_name = type_type.P_name
	}
	output.P_pkgname = type_type.P_pkgname
	output.P_type = type_type
	output.P_path = output.P_pkgname +
		"/" +
		output.P_name
	output.P_isempty = true
	return output
}

// V_const_type
func V_const_type(
	type_type *Type_type) *Type_const {
	var output *Type_const = V_const_create()
	output.P_path = type_type.P_path
	output.P_pkgname = type_type.P_pkgname
	output.P_name = type_type.P_name
	output.P_type = type_type
	output.P_istype = true
	return output
}

// V_const_from_pkgnamen_namen_any
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
	output.P_type = type_any.P_type
	type_any.P_const = output
	return output
}

// V_cast_const
func V_cast_const(
	value *Type_const) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_const_cast
func V_const_cast(
	type_any *Type_any) *Type_const {
	var output *Type_const = E_const
	var value, ok = type_any.backref.(*Type_const)
	if ok {
		output = value
	}
	return output
}

// V_const_from_any
func V_const_from_any(
	type_any *Type_any) *Type_const {
	var output = type_any.P_const
	return output
}

// V_get_keyn_const
func V_get_keyn_const(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_const = V_const_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "path":
		output = A_string_cast_stringn(
			value.P_path)
	case "pkgname":
		output = A_string_cast_stringn(
			value.P_pkgname)
	case "name":
		output = A_string_cast_stringn(
			value.P_name)
	case "isempty":
		output = A_boolean_from_booleann(
			value.P_isempty)
	case "istype":
		output = A_boolean_from_booleann(
			value.P_istype)
	case "type":
		output = V_cast_type(
			value.P_type)
	}
	return output
}

// V_t_const_from_pkgnamen_namen_any
func V_t_const_from_pkgnamen_namen_any(
	type_scope *Type_scope,
	type_const *Type_const) *Type_type {
	var namen_var *Type_var = V_var_new_from_namen_type(
		"pkgnamen",
		T_stringn)
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_type)
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var listany []*Type_any = []*Type_any{}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"const<-pkgnamen-namen-any",
		T_type,
		V_varlist_from_listvar(
			[]*Type_var{
				namen_var,
				type_var,
				any_var}),
		A_anylist_from_listany(
			listany))
	return output
}

func V_t_const_x_constructor(
	type_scope *Type_scope,
	type_const *Type_const) *Type_type {
	var listany []*Type_any = []*Type_any{}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"const-"+
			type_const.P_name+
			"-constructor",
		T_type,
		E_varlist,
		A_anylist_from_listany(
			listany))
	return output
}

func V_t_const_x_startup(
	type_scope *Type_scope,
	type_const *Type_const) *Type_type {
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_any)
	var type_type *Type_type = type_const.P_type
	var c_variable_var *Type_var = V_var_new_mutable_from_namen_type(
		"c-variable",
		T_boolean)
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var const_var *Type_var = V_var_new_mutable_from_namen_type(
		"type-const",
		T_const)
	var t_x_initialize *Type_type = V_t_x_initialize(
		type_scope,
		type_type)
	var t_const_from_pkgnamen_namen_any *Type_type = V_t_const_from_pkgnamen_namen_any(
		type_scope,
		type_const)
	var namen string = type_const.P_name
	var listany []*Type_any = []*Type_any{}
	switch type_const {
	case C_false.P_any.P_const:
		listany = []*Type_any{
			A_var_declare(
				c_variable_var,
				E_any),
			A_var_set_propertyn(
				c_variable_var,
				"booleann",
				V_cast_booleann(
					V_booleann_new_from_boolean(
						C_false)))}
	default:
		listany = []*Type_any{
			A_var_declare(
				c_variable_var,
				E_any),
			A_func_call_any(
				t_x_initialize,
				c_variable_var.P_any),
			A_var_declare(
				any_var,
				A_var_propertyn(
					c_variable_var,
					"any")),
			A_var_declare(
				const_var,
				A_func_call(
					t_const_from_pkgnamen_namen_any,
					V_anylist_from_listany(
						[]*Type_any{
							A_string_cast_stringn(
								"vx/core"),
							A_string_cast_stringn(
								"false"),
							any_var.P_any})))}
	}
	listany = append(listany, A_var_declare(
		output_var,
		A_var_propertyn(
			c_variable_var,
			"any")))
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"const-"+
			namen+
			"-startup",
		T_any,
		E_varlist,
		A_anylist_from_listany(
			listany))
	return output
}

// (func const-declare)
type Type_const_declare struct {
	P_any   *Type_any
	P_const *Type_const
	P_part  *Type_enum
}

// V_const_declare_constructor
func V_const_declare_constructor() *Type_const_declare {
	var output *Type_const_declare = new(Type_const_declare)
	return output
}

// V_const_declare_create
func V_const_declare_create() *Type_const_declare {
	var output *Type_const_declare = V_const_declare_constructor()
	V_const_declare_initialize(
		output)
	return output
}

// V_const_declare_initialize
func V_const_declare_initialize(
	value *Type_const_declare) {
	value.P_any = V_any_from_type_backref(
		T_const_declare,
		value)
	value.P_const = E_const
	value.P_part = E_enum
}

// V_const_declare_startup
func V_const_declare_startup() *Type_type {
	var t_variable *Type_type = T_const_declare
	var e_variable *Type_const_declare = E_const_declare
	V_const_declare_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"const-declare",
		C_extends_func,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"const",
				T_const),
			V_var_new_public_from_namen_type(
				"part",
				T_const)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_const_declare
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_const_declare
func V_cast_const_declare(
	value *Type_const_declare) *Type_any {
	return value.P_any
}

// V_const_declare_cast
func V_const_declare_cast(
	type_any *Type_any) *Type_const_declare {
	var output *Type_const_declare = E_const_declare
	var value, ok = type_any.backref.(*Type_const_declare)
	if ok {
		output = value
	}
	return output
}

func V_code_const_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	//var subpath = path + "/v-code-const-declare"
	var type_lang *Type_lang = type_scope.P_lang
	/*
		var lineindent string = V_code_lineindent(
			type_scope,
			indent)
	*/
	var type_const_declare *Type_const_declare = V_const_declare_cast(
		type_any)
	var p_const *Type_const = type_const_declare.P_const
	var p_part *Type_enum = type_const_declare.P_part
	var type_type *Type_type = p_const.P_type
	var constnamen string = V_code_namen(
		type_scope,
		p_const.P_name)
	var subindent int = 0
	switch type_lang {
	case C_lang_go:
		constnamen = "C_" + constnamen
	case C_lang_swift:
		subindent = 1
		constnamen = "c_" + constnamen
	default:
		constnamen = "c_" + constnamen
	}
	var output string = ""
	switch p_part {
	case C_enum_const_startup:
		var t_x_startup *Type_type = V_t_const_x_startup(
			type_scope,
			p_const)
		var type_func_declare *Type_func_declare = V_func_declare(
			t_x_startup)
		output = V_code_from_func_declare(
			type_scope,
			subindent,
			path,
			type_func_declare)
	case C_enum_c_const:
		var t_x_constructor *Type_type = V_t_x_constructor(
			type_scope,
			type_type)
		var value *Type_any = A_func_call(
			t_x_constructor,
			E_anylist)
		var type_var *Type_var = V_var_new_from_namen_type(
			constnamen,
			type_type)
		var var_declare_any *Type_any = A_var_declare(
			type_var,
			value)
		output = V_code_var_declare(
			type_scope,
			subindent,
			path,
			var_declare_any)
		/*
			switch type_lang {
			case C_lang_go:
				output = "var C_" + constnamen + " " + typetypenamen + " = " + code_constructor
			case C_lang_swift:
				output = lineindent + "public static let c_" + constnamen + " : " + typetypenamen + " = " + code_constructor
			}
		*/
	}
	return output
}

func V_const_declare_new_from_const_part(
	type_const *Type_const,
	part_enum *Type_enum) *Type_const_declare {
	var output *Type_const_declare = V_const_declare_create()
	output.P_const = type_const
	output.P_part = part_enum
	return output
}

func A_const_declare_new_from_const_part(
	type_const *Type_const,
	part_enum *Type_enum) *Type_any {
	var type_const_declare *Type_const_declare = V_const_declare_new_from_const_part(
		type_const,
		part_enum)
	var output *Type_any = V_cast_const_declare(
		type_const_declare)
	return output
}

// (type constlist)
type Type_constlist struct {
	P_any       *Type_any
	P_listconst []*Type_const
}

// V_constlist_constructor
func V_constlist_constructor() *Type_constlist {
	var output = new(Type_constlist)
	return output
}

// V_constlist_create
func V_constlist_create() *Type_constlist {
	var output = V_constlist_constructor()
	V_constlist_initialize(
		output)
	return output
}

// V_constlist_initialize
func V_constlist_initialize(
	value *Type_constlist) {
	value.P_any = V_any_from_type_backref(
		T_constlist,
		value)
	value.P_listconst = []*Type_const{}
}

// V_constlist_startup
func V_constlist_startup() *Type_type {
	var t_variable = T_constlist
	var e_variable = E_constlist
	V_constlist_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"constlist",
		C_extends_list,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_indexn_funcn = V_get_indexn_constlist
	type_generic.P_listany_funcn = V_listany_constlist
	type_generic.P_code_funcn = V_code_constlist
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_constlist
func V_cast_constlist(
	value *Type_constlist) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_constlist_cast
func V_constlist_cast(
	type_any *Type_any) *Type_constlist {
	var output *Type_constlist = E_constlist
	var value, ok = type_any.backref.(*Type_constlist)
	if ok {
		output = value
	}
	return output
}

func V_get_indexn_constlist(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_constlist *Type_constlist = V_constlist_cast(
		type_any)
	var type_const *Type_const = V_constlist_type_from_constlist_indexn(
		type_constlist,
		indexn)
	var output *Type_any = type_const.P_any
	return output
}

func V_code_constlist(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = "" +
		"f_constlist_from_listtype(" +
		"\n  [" +
		"\n   \"\"" +
		"\n  ]" +
		")"
	return output
}

func V_listany_constlist(
	type_any *Type_any) []*Type_any {
	var type_constlist *Type_constlist = V_constlist_cast(
		type_any)
	var output []*Type_any = V_constlist_listany_from_listconst(
		type_constlist.P_listconst)
	return output
}

func V_constlist_listany_from_listconst(
	listconst []*Type_const) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_const := range listconst {
		output = append(output, type_const.P_any)
	}
	return output
}

func V_constlist_type_from_constlist_indexn(
	type_constlist *Type_constlist,
	indexn int) *Type_const {
	var output *Type_const = E_const
	var listvalue []*Type_const = type_constlist.P_listconst
	if len(listvalue) >= indexn {
		output = listvalue[indexn-1]
	}
	return output
}

func V_constlist_from_listconst(
	listconst []*Type_const) *Type_constlist {
	var output *Type_constlist = V_constlist_create()
	output.P_listconst = listconst
	return output
}

func V_constlist_from_constmap(
	type_constmap *Type_constmap) *Type_constlist {
	var listkey []string = type_constmap.P_listkey
	var listvalue []*Type_const = []*Type_const{}
	for _, keyn := range listkey {
		var value *Type_const = V_const_from_constmap_keyn(
			type_constmap,
			keyn)
		if value != E_const {
			listvalue = append(listvalue, value)
		}
	}
	var output *Type_constlist = E_constlist
	if len(listvalue) > 0 {
		output.P_listconst = listvalue
	}
	return output
}

// (type constmap)
type Type_constmap struct {
	P_any      *Type_any
	P_listkey  []string
	P_mapconst map[string]*Type_const
}

// V_constmap_constructor
func V_constmap_constructor() *Type_constmap {
	var output = new(Type_constmap)
	return output
}

// V_constmap_create
func V_constmap_create() *Type_constmap {
	var output = V_constmap_constructor()
	V_constmap_initialize(output)
	return output
}

// V_constmap_initialize
func V_constmap_initialize(
	value *Type_constmap) {
	value.P_any = V_any_from_type_backref(
		T_constmap,
		value)
	value.P_listkey = []string{}
	value.P_mapconst = map[string]*Type_const{}
}

// V_constmap_startup
func V_constmap_startup() *Type_type {
	var t_variable = T_constmap
	var e_variable = E_constmap
	V_constmap_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"constmap",
		C_extends_map,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_constmap
	type_generic.P_listkey_funcn = V_listkey_constmap
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_constmap
func V_cast_constmap(
	value *Type_constmap) *Type_any {
	return value.P_any
}

// V_constmap_cast
func V_constmap_cast(
	type_any *Type_any) *Type_constmap {
	var output *Type_constmap = E_constmap
	var value, ok = type_any.backref.(*Type_constmap)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_constmap(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_constmap *Type_constmap = V_constmap_cast(
		type_any)
	var type_const *Type_const = V_const_from_constmap_keyn(
		type_constmap,
		keyn)
	var output *Type_any = E_any
	if type_const != E_const {
		output = V_cast_const(
			type_const)
	}
	return output
}

func V_listkey_constmap(
	type_any *Type_any) []string {
	var type_constmap *Type_constmap = V_constmap_cast(
		type_any)
	var output []string = type_constmap.P_listkey
	return output
}

func V_const_from_constmap_keyn(
	type_constmap *Type_constmap,
	keyn string) *Type_const {
	var output *Type_const = E_const
	var mapvalue map[string]*Type_const = type_constmap.P_mapconst
	var value, ok = mapvalue[keyn]
	if ok {
		output = value
	}
	return output
}

func V_constmap_from_listconst(
	listconst []*Type_const) *Type_constmap {
	var listkey []string = []string{}
	var mapvalue map[string]*Type_const = map[string]*Type_const{}
	for _, value := range listconst {
		var keyn string = value.P_path
		listkey = append(listkey, keyn)
		mapvalue[keyn] = value
	}
	var output *Type_constmap = E_constmap
	if len(listkey) > 0 {
		output = V_constmap_create()
		output.P_listkey = listkey
		output.P_mapconst = mapvalue
	}
	return output
}

// (func copy)
type Type_copy struct {
	P_any *Type_any
}

// V_copy_constructor
func V_copy_constructor() *Type_copy {
	var output = new(Type_copy)
	return output
}

// V_copy_initialize
func V_copy_initialize(
	value *Type_copy) {
	value.P_any = V_any_from_type_backref(
		T_copy,
		value)
}

// V_copy_startup
func V_copy_startup() *Type_type {
	var t_variable *Type_type = T_copy
	var e_variable *Type_copy = E_copy
	V_copy_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"copy",
		C_extends_func,
		e_variable.P_any)
	var output *Type_type = t_variable
	return output
}

// delta
type Type_delta struct {
	P_any *Type_any
}

// V_delta_constructor
func V_delta_constructor() *Type_delta {
	var output = new(Type_delta)
	return output
}

// V_delta_initialize
func V_delta_initialize(
	value *Type_delta) {
	value.P_any = V_any_from_type_backref(
		T_delta,
		value)
}

// V_delta_create
func V_delta_create() *Type_delta {
	var output = V_delta_constructor()
	V_delta_initialize(
		E_delta)
	return output
}

// V_delta_startup
func V_delta_startup() *Type_type {
	var t_variable *Type_type = T_delta
	var e_variable *Type_delta = E_delta
	V_delta_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"delta",
		E_string,
		e_variable.P_any)
	var output *Type_type = t_variable
	return output
}

// (type enum)
type Type_enum struct {
	P_any *Type_any
}

// V_cast_enum
func V_cast_enum(
	type_enum *Type_enum) *Type_any {
	var output *Type_any = type_enum.P_any
	return output
}

// V_enum_constructor
func V_enum_constructor() *Type_enum {
	var output = new(Type_enum)
	return output
}

// V_enum_create
func V_enum_create() *Type_enum {
	var output = V_enum_constructor()
	V_enum_initialize(output)
	return output
}

// V_enum_initialize
func V_enum_initialize(
	value *Type_enum) {
	value.P_any = V_any_from_type_backref(
		T_enum,
		value)
}

// V_enum_startup
func V_enum_startup() *Type_type {
	var t_variable = T_enum
	var e_variable = E_enum
	V_enum_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"enum",
		E_string,
		e_variable.P_any)
	return t_variable
}

// (type +)
type Type_plus struct {
	P_any     *Type_any
	P_type    *Type_type
	P_anylist *Type_anylist
}

// V_plus_constructor
func V_plus_constructor() *Type_plus {
	var output = new(Type_plus)
	return output
}

// V_plus_create
func V_plus_create() *Type_plus {
	var output = V_plus_constructor()
	V_plus_initialize(
		output)
	return output
}

// V_plus_initialize
func V_plus_initialize(
	value *Type_plus) {
	value.P_any = V_any_from_type_backref(
		T_plus,
		value)
	value.P_type = E_type
	value.P_anylist = E_anylist
}

// V_plus_startup
func V_plus_startup() *Type_type {
	var t_variable = T_plus
	var e_variable = E_plus
	V_plus_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"+",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_plus
	type_generic.P_func_funcn = V_func_plus
	type_generic.P_code_funcn = V_code_plus
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"anylist",
				T_any)})
	var output *Type_type = t_variable
	return output
}

// V_cast_plus
func V_cast_plus(
	value *Type_plus) *Type_any {
	return value.P_any
}

// V_plus_cast
func V_plus_cast(
	type_any *Type_any) *Type_plus {
	var output *Type_plus = E_plus
	var value, ok = type_any.backref.(*Type_plus)
	if ok {
		output = value
	}
	return output
}

func V_func_plus(
	type_type *Type_type) *Type_func {
	var output *Type_func = V_func_new_from_type_return_varlist_value(
		type_type,
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"type-anylist",
					T_anylist)}),
		E_any)
	return output
}

func V_get_keyn_plus(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_plus = V_plus_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "type":
		var p_type *Type_type = value.P_type
		if p_type != E_type {
			output = V_cast_type(
				p_type)
		}
	case "anylist":
		var p_anylist *Type_anylist = value.P_anylist
		if p_anylist != E_anylist {
			output = V_cast_anylist(
				p_anylist)
		}
	}
	return output
}

func V_plus_new_from_type_any_any(
	type_type *Type_type,
	val1 *Type_any,
	val2 *Type_any) *Type_plus {
	var output *Type_plus = V_plus_create()
	var type_anylist *Type_anylist = V_anylist_from_listany(
		[]*Type_any{
			val1,
			val2})
	output.P_type = type_type
	output.P_anylist = type_anylist
	return output
}

func A_plus_new_from_type_any_any(
	type_type *Type_type,
	val1 *Type_any,
	val2 *Type_any) *Type_any {
	var value *Type_plus = V_plus_new_from_type_any_any(
		type_type,
		val1,
		val2)
	var output *Type_any = V_cast_plus(
		value)
	return output
}

func V_code_plus(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/v-code-plus"
	var lineindent string = V_code_lineindent(
		type_scope,
		indent)
	var type_plus *Type_plus = V_plus_cast(
		type_any)
	var p_anylist *Type_anylist = type_plus.P_anylist
	var listany []*Type_any = p_anylist.P_listany
	var liststringn []string = []string{}
	var prop string = ""
	for idx, type_any := range listany {
		var subindent int = indent
		if idx > 0 {
			subindent += 1
		}
		var valn string = V_code_any(
			type_scope,
			subindent,
			subpath,
			type_any)
		if idx == 0 {
			prop = lineindent + valn
			liststringn = append(liststringn, prop)
		} else {
			prop = " +" + valn
			liststringn = append(liststringn, prop)
		}
	}
	var output string = V_stringn_from_liststringn(
		liststringn)
	return output
}

func F_plus(
	type_type *Type_type,
	type_anylist *Type_anylist) *Type_any {
	var output *Type_any = E_any
	return output
}

// (type ==)
type Type_eqeq struct {
	P_any  *Type_any
	P_val1 *Type_any
	P_val2 *Type_any
}

func V_get_keyn_eqeq(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_eqeq = V_eqeq_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "val1":
		var p_val1 *Type_any = value.P_val1
		if p_val1 != E_any {
			output = p_val1
		}
	case "val2":
		var p_val2 *Type_any = value.P_val2
		if p_val2 != E_any {
			output = p_val2
		}
	}
	return output
}

func V_code_eqeq(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/v_code_from_any_eqeq"
	var type_lang *Type_lang = type_scope.P_lang
	var type_eqeq *Type_eqeq = V_eqeq_cast(
		type_any)
	var p_val1 *Type_any = type_eqeq.P_val1
	var p_val2 *Type_any = type_eqeq.P_val2
	var p_val1n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val1)
	var p_val2n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val2)
	var output = ""
	switch type_lang {
	default:
		output = p_val1n + " == " + p_val2n
	}
	return output
}

func V_func_eqeq(
	type_type *Type_type) *Type_func {
	var output *Type_func = E_func
	return output
}

func A_eqeq(
	val1_any *Type_any,
	val2_any *Type_any) *Type_any {
	var type_eqeq *Type_eqeq = V_eqeq_create()
	type_eqeq.P_val1 = val1_any
	type_eqeq.P_val2 = val2_any
	var output *Type_any = V_cast_eqeq(
		type_eqeq)
	return output
}

// V_cast_eqeq
func V_cast_eqeq(
	value *Type_eqeq) *Type_any {
	return value.P_any
}

// V_eqeq_cast
func V_eqeq_cast(
	type_any *Type_any) *Type_eqeq {
	var output *Type_eqeq = E_eqeq
	var value, ok = type_any.backref.(*Type_eqeq)
	if ok {
		output = value
	}
	return output
}

// V_eqeq_constructor
func V_eqeq_constructor() *Type_eqeq {
	var output = new(Type_eqeq)
	return output
}

// V_eqeq_create
func V_eqeq_create() *Type_eqeq {
	var output = V_eqeq_constructor()
	V_eqeq_initialize(output)
	return output
}

// V_eqeq_initialize
func V_eqeq_initialize(
	value *Type_eqeq) {
	value.P_any = V_any_from_type_backref(
		T_eqeq,
		value)
	value.P_val1 = E_any
	value.P_val2 = E_any
}

// V_eqeq_startup
func V_eqeq_startup() *Type_type {
	var t_variable = T_eqeq
	var e_variable = E_eqeq
	V_eqeq_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"==",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_eqeq
	type_generic.P_func_funcn = V_func_eqeq
	type_generic.P_code_funcn = V_code_eqeq
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"val1",
				T_any),
			V_var_new_public_from_namen_type(
				"val2",
				T_any)})
	var output *Type_type = t_variable
	return output
}

// Type_noteqeq
type Type_noteqeq struct {
	P_any  *Type_any
	P_val1 *Type_any
	P_val2 *Type_any
}

// V_cast_noteqeq
func V_cast_noteqeq(
	value *Type_noteqeq) *Type_any {
	return value.P_any
}

// V_noteqeq_cast
func V_noteqeq_cast(
	type_any *Type_any) *Type_noteqeq {
	var output *Type_noteqeq = E_noteqeq
	var value, ok = type_any.backref.(*Type_noteqeq)
	if ok {
		output = value
	}
	return output
}

// V_noteqeq_constructor
func V_noteqeq_constructor() *Type_noteqeq {
	var output = new(Type_noteqeq)
	return output
}

// V_noteqeq_create
func V_noteqeq_create() *Type_noteqeq {
	var output = V_noteqeq_constructor()
	V_noteqeq_initialize(output)
	return output
}

// V_noteqeq_initialize
func V_noteqeq_initialize(
	value *Type_noteqeq) {
	value.P_any = V_any_from_type_backref(
		T_noteqeq,
		value)
	value.P_val1 = E_any
	value.P_val2 = E_any
}

// V_noteqeq_startup
func V_noteqeq_startup() *Type_type {
	var t_variable = T_noteqeq
	var e_variable = E_noteqeq
	V_noteqeq_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"==",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_noteqeq
	type_generic.P_func_funcn = V_func_noteqeq
	type_generic.P_code_funcn = V_code_noteqeq
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"val1",
				T_any),
			V_var_new_public_from_namen_type(
				"val2",
				T_any)})
	return t_variable
}

func V_get_keyn_noteqeq(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_noteqeq = V_noteqeq_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "val1":
		var p_val1 *Type_any = value.P_val1
		if p_val1 != E_any {
			output = p_val1
		}
	case "val2":
		var p_val2 *Type_any = value.P_val2
		if p_val2 != E_any {
			output = p_val2
		}
	}
	return output
}

func V_code_noteqeq(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/code-noteqeq"
	var type_lang *Type_lang = type_scope.P_lang
	var type_noteqeq *Type_noteqeq = V_noteqeq_cast(
		type_any)
	var p_val1 *Type_any = type_noteqeq.P_val1
	var p_val2 *Type_any = type_noteqeq.P_val2
	var p_val1n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val1)
	var p_val2n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val2)
	var output = ""
	switch type_lang {
	case C_lang_swift:
		output = p_val1n + " !== " + p_val2n
	default:
		output = p_val1n + " != " + p_val2n
	}
	return output
}

func V_func_noteqeq(
	type_type *Type_type) *Type_func {
	var output *Type_func = E_func
	return output
}

func A_noteqeq(
	val1_any *Type_any,
	val2_any *Type_any) *Type_any {
	var type_noteqeq *Type_noteqeq = V_noteqeq_create()
	type_noteqeq.P_val1 = val1_any
	type_noteqeq.P_val2 = val2_any
	var output *Type_any = V_cast_noteqeq(
		type_noteqeq)
	return output
}

// Type_lt
type Type_lt struct {
	P_any  *Type_any
	P_val1 *Type_any
	P_val2 *Type_any
}

// V_cast_lt
func V_cast_lt(
	value *Type_lt) *Type_any {
	return value.P_any
}

// V_lt_cast
func V_lt_cast(
	type_any *Type_any) *Type_lt {
	var output *Type_lt = E_lt
	var value, ok = type_any.backref.(*Type_lt)
	if ok {
		output = value
	}
	return output
}

// V_lt_constructor
func V_lt_constructor() *Type_lt {
	var output = new(Type_lt)
	return output
}

// V_lt_create
func V_lt_create() *Type_lt {
	var output = V_lt_constructor()
	V_lt_initialize(output)
	return output
}

// V_lt_initialize
func V_lt_initialize(
	value *Type_lt) {
	value.P_any = V_any_from_type_backref(
		T_lt,
		value)
	value.P_val1 = E_any
	value.P_val2 = E_any
}

// V_lt_startup
func V_lt_startup() *Type_type {
	var t_variable = T_lt
	var e_variable = E_lt
	V_lt_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"<",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_lt
	type_generic.P_func_funcn = V_func_lt
	type_generic.P_code_funcn = V_code_lt
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"val1",
				T_any),
			V_var_new_public_from_namen_type(
				"val2",
				T_any)})
	return t_variable
}

func V_get_keyn_lt(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_lt = V_lt_cast(type_any)
	var output *Type_any = E_any
	switch keyn {
	case "val1":
		var p_val1 *Type_any = value.P_val1
		if p_val1 != E_any {
			output = p_val1
		}
	case "val2":
		var p_val2 *Type_any = value.P_val2
		if p_val2 != E_any {
			output = p_val2
		}
	}
	return output
}

func V_code_lt(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/v_code_from_any_lt"
	var type_lang *Type_lang = type_scope.P_lang
	var type_lt *Type_lt = V_lt_cast(
		type_any)
	var p_val1 *Type_any = type_lt.P_val1
	var p_val2 *Type_any = type_lt.P_val2
	var p_val1n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val1)
	var p_val2n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val2)
	var output = ""
	switch type_lang {
	default:
		output = p_val1n + " < " + p_val2n
	}
	return output
}

func V_func_lt(
	type_type *Type_type) *Type_func {
	var output *Type_func = E_func
	return output
}

func A_lt(
	val1_any *Type_any,
	val2_any *Type_any) *Type_any {
	var type_lt *Type_lt = V_lt_create()
	type_lt.P_val1 = val1_any
	type_lt.P_val2 = val2_any
	var output *Type_any = V_cast_lt(
		type_lt)
	return output
}

// Type_le
type Type_le struct {
	P_any  *Type_any
	P_val1 *Type_any
	P_val2 *Type_any
}

// V_le_constructor
func V_le_constructor() *Type_le {
	var output = new(Type_le)
	return output
}

// V_le_create
func V_le_create() *Type_le {
	var output = V_le_constructor()
	V_le_initialize(
		output)
	return output
}

// V_le_initialize
func V_le_initialize(
	value *Type_le) {
	value.P_any = V_any_from_type_backref(
		T_le,
		value)
	value.P_val1 = E_any
	value.P_val2 = E_any
}

// V_le_startup
func V_le_startup() *Type_type {
	var t_variable = T_le
	var e_variable = E_le
	V_le_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"<=",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_le
	type_generic.P_func_funcn = V_func_le
	type_generic.P_code_funcn = V_code_le
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"val1",
				T_any),
			V_var_new_public_from_namen_type(
				"val2",
				T_any)})
	var output *Type_type = t_variable
	return output
}

// V_cast_le
func V_cast_le(
	value *Type_le) *Type_any {
	return value.P_any
}

// V_le_cast
func V_le_cast(
	type_any *Type_any) *Type_le {
	var output *Type_le = E_le
	var value, ok = type_any.backref.(*Type_le)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_le(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_le = V_le_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "val1":
		var p_val1 *Type_any = value.P_val1
		if p_val1 != E_any {
			output = p_val1
		}
	case "val2":
		var p_val2 *Type_any = value.P_val2
		if p_val2 != E_any {
			output = p_val2
		}
	}
	return output
}

func V_code_le(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/v_code_from_any_le"
	var type_lang *Type_lang = type_scope.P_lang
	var type_le *Type_le = V_le_cast(
		type_any)
	var p_val1 *Type_any = type_le.P_val1
	var p_val2 *Type_any = type_le.P_val2
	var p_val1n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val1)
	var p_val2n string = V_code_any(
		type_scope,
		indent,
		subpath,
		p_val2)
	var output = ""
	switch type_lang {
	default:
		output = p_val1n + " <= " + p_val2n
	}
	return output
}

func V_func_le(
	type_type *Type_type) *Type_func {
	var output *Type_func = E_func
	return output
}

func A_le(
	val1_any *Type_any,
	val2_any *Type_any) *Type_any {
	var type_le *Type_le = V_le_create()
	type_le.P_val1 = val1_any
	type_le.P_val2 = val2_any
	var output *Type_any = V_cast_le(
		type_le)
	return output
}

// Type_float
type Type_float struct {
	P_any    *Type_any
	P_floatn float64
}

func V_code_from_any_float(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var type_float = V_float_cast(type_any)
	output = "" + V_stringn_cast_floatn(
		type_float.P_floatn)
	return output
}

func V_float_from_floatn(
	floatn float64) *Type_float {
	var output *Type_float = V_float_create()
	output.P_floatn = floatn
	return output
}

func V_floatn_from_float(
	type_float *Type_float) float64 {
	var output float64 = type_float.P_floatn
	return output
}

// V_cast_float
func V_cast_float(
	value *Type_float) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_float_cast
func V_float_cast(
	type_any *Type_any) *Type_float {
	var output *Type_float = E_float
	var value, ok = type_any.backref.(*Type_float)
	if ok {
		output = value
	}
	return output
}

// V_float_constructor
func V_float_constructor() *Type_float {
	var output = new(Type_float)
	return output
}

// V_float_create
func V_float_create() *Type_float {
	var output = V_float_constructor()
	V_float_initialize(output)
	return output
}

// V_float_initialize
func V_float_initialize(
	value *Type_float) {
	value.P_any = V_any_from_type_backref(
		T_float,
		value)
	value.P_floatn = 0
}

// V_float_startup
func V_float_startup() *Type_type {
	var t_variable = T_float
	var e_variable = E_float
	V_float_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"float",
		E_string,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_from_any_float
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"floatn",
				T_floatn)})
	return t_variable
}

// Type_floatn
type Type_floatn struct {
	P_any *Type_any
}

// V_floatn_constructor
func V_floatn_constructor() *Type_floatn {
	var output = new(Type_floatn)
	return output
}

// V_floatn_create
func V_floatn_create() *Type_floatn {
	var output = V_floatn_constructor()
	V_floatn_initialize(output)
	return output
}

// V_floatn_initialize
func V_floatn_initialize(
	value *Type_floatn) {
	value.P_any = V_any_from_type_backref(
		T_floatn,
		value)
}

// V_floatn_startup
func V_floatn_startup() *Type_type {
	var t_variable = T_floatn
	var e_variable = E_floatn
	V_floatn_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"floatn",
		E_string,
		e_variable.P_any)
	return t_variable
}

// Type_fn
type Type_fn struct {
	P_any   *Type_any
	P_type  *Type_type
	P_funcn func() *Type_any
}

func V_any_from_fn(
	type_fn *Type_fn) *Type_any {
	var output *Type_any = E_any
	var funcn func() *Type_any = type_fn.P_funcn
	if funcn != nil {
		output = funcn()
	}
	return output
}

func V_fn_from_type_funcn(
	type_type *Type_type,
	funcn func() *Type_any) *Type_fn {
	var output *Type_fn = V_fn_create()
	output.P_type = type_type
	output.P_funcn = funcn
	return output
}

// V_fn_constructor
func V_fn_constructor() *Type_fn {
	var output = new(Type_fn)
	return output
}

// V_fn_create
func V_fn_create() *Type_fn {
	var output = V_fn_constructor()
	V_fn_initialize(output)
	return output
}

// V_fn_initialize
func V_fn_initialize(
	value *Type_fn) {
	value.P_any = V_any_from_type_backref(
		T_fn,
		value)
}

// V_fn_startup
func V_fn_startup() *Type_type {
	var t_variable = T_fn
	var e_variable = E_fn
	V_fn_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"fn",
		E_string,
		e_variable.P_any)
	return t_variable
}

// Type_func
type Type_func struct {
	P_any          *Type_any
	P_func_type    *Type_type
	P_return       *Type_type
	P_generic_type *Type_type
	P_arglist      *Type_varlist
	P_value        *Type_any
	P_context      *Type_boolean
	P_async        *Type_boolean
}

func V_code_func(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

func V_get_keyn_func(
	type_any *Type_any,
	keyn string) *Type_any {
	var output *Type_any = E_any
	var type_func = V_func_cast(
		type_any)
	var key string = V_stringn_stripcolon(
		keyn)
	switch key {
	case "type":
		output = type_func.P_func_type.P_any
	case "return":
		output = type_func.P_return.P_any
	case "arglist":
		output = type_func.P_arglist.P_any
	case "value":
		output = type_func.P_value
	case "context":
		output = type_func.P_context.P_any
	case "async":
		output = type_func.P_async.P_any
	}
	return output
}

// V_cast_func
func V_cast_func(
	type_func *Type_func) *Type_any {
	var output *Type_any = type_func.P_any
	return output
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

// V_func_new_from_type_return_varlist_value
func V_func_new_from_type_return_varlist_value(
	func_type *Type_type,
	return_type *Type_type,
	type_varlist *Type_varlist,
	value_any *Type_any) *Type_func {
	var output = V_func_create()
	output.P_func_type = func_type
	output.P_return = return_type
	output.P_arglist = type_varlist
	output.P_value = value_any
	return output
}

// A_func_from_type
func A_func_from_type(
	type_type *Type_type) *Type_any {
	var output *Type_any = V_cast_func(
		V_func_from_type(
			type_type))
	return output
}

// V_func_from_type
func V_func_from_type(
	type_type *Type_type) *Type_func {
	var output *Type_func = type_type.P_func
	if output == E_func {
		var type_generic *Type_generic = V_generic_from_type(
			type_type)
		if type_generic.P_func_funcn != nil {
			output = type_generic.P_func_funcn(
				type_type)
		}
	}
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
	value.P_any = V_any_from_type_backref(
		T_func,
		value)
	value.P_func_type = E_type
	value.P_return = E_type
	value.P_generic_type = E_type
	value.P_arglist = E_varlist
	value.P_value = E_any
	value.P_context = C_false
	value.P_async = C_false
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_func
	type_generic.P_code_funcn = V_code_func
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"type",
				T_type),
			V_var_new_public_from_namen_type(
				"return",
				T_type),
			V_var_new_public_from_namen_type(
				"arglist",
				T_varlist),
			V_var_new_public_from_namen_type(
				"value",
				T_any),
			V_var_new_public_from_namen_type(
				"context",
				T_boolean),
			V_var_new_public_from_namen_type(
				"async",
				T_boolean)})
	return t_variable
}

// Type_func_call
type Type_func_call struct {
	P_any      *Type_any
	P_type     *Type_type
	P_prefix   *Type_string
	P_anylist  *Type_anylist
	P_ismethod *Type_boolean
}

func V_code_func_call(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_func_call *Type_func_call = V_func_call_cast(
		type_any)
	var output string = V_code_from_func_call(
		type_scope,
		indent,
		path,
		type_func_call)
	return output
}

func V_get_keyn_func_call(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_func_call = V_func_call_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "type":
		var p_type *Type_type = value.P_type
		if p_type != E_type {
			output = V_cast_type(
				p_type)
		}
	case "prefix":
		var p_prefix *Type_string = value.P_prefix
		if p_prefix != E_string {
			output = V_cast_string(
				p_prefix)
		}
	case "anylist":
		var p_anylist *Type_anylist = value.P_anylist
		if p_anylist != E_anylist {
			output = V_cast_anylist(
				p_anylist)
		}
	case "ismethod":
		var p_ismethod *Type_boolean = value.P_ismethod
		if p_ismethod == C_false {
			output = V_cast_boolean(
				p_ismethod)
		}
	}
	return output
}

func V_code_from_func_call(
	type_scope *Type_scope,
	indent int,
	path string,
	type_func_call *Type_func_call) string {
	var subpath string = path + "/code<-func-call"
	var type_lang *Type_lang = type_scope.P_lang
	var lineindent string = V_code_lineindent(
		type_scope,
		indent)
	var lineindent1 string = V_code_lineindent(
		type_scope,
		indent+1)
	var lineindent2 string = V_code_lineindent(
		type_scope,
		indent+2)
	var type_type *Type_type = type_func_call.P_type
	var ismethod *Type_boolean = type_func_call.P_ismethod
	var pkgnamen string = ""
	if ismethod == C_false {
		pkgnamen = V_code_type_pkgname(
			type_scope,
			type_type)
	}
	var prefix *Type_string = type_func_call.P_prefix
	var prefixn string = type_type.P_prefix
	if ismethod == C_true {
	} else if prefix != E_string {
		prefixn = V_stringn_cast_string(
			prefix)
	} else if prefixn == "" {
		prefixn = "v"
	}
	if prefixn != "" {
		prefixn += "_"
	}
	switch type_lang {
	case C_lang_go:
		if V_pkgnamen_from_scope(
			type_scope) == type_type.P_pkgname {
			pkgnamen = ""
		}
		prefixn = V_stringn_uppercase(
			prefixn)
	}
	var type_func *Type_func = V_func_from_type(
		type_type)
	var funcnamen = pkgnamen +
		prefixn +
		V_code_type_name(
			type_scope,
			type_type)
	var type_varlist *Type_varlist = type_func.P_arglist
	var type_anylist *Type_anylist = type_func_call.P_anylist
	var listvar []*Type_var = type_varlist.P_listvar
	if len(listvar) == 1 {
		var first_var *Type_var = listvar[0]
		var first_type *Type_type = first_var.P_type
		if first_type.P_isnative && first_type.P_extends == C_extends_list {
			type_anylist = V_anylist_from_listany(
				[]*Type_any{
					V_cast_anylist(
						type_anylist)})
		}
	}
	var listany []*Type_any = type_anylist.P_listany
	var output = ""
	var props string = ""
	if len(listvar) > 0 {
		var listany_count int = len(listany)
		var listprop []string = []string{}
		for var_i, type_var := range listvar {
			var var_type *Type_type = type_var.P_type
			var value *Type_any = E_any
			if var_i < listany_count {
				value = listany[var_i]
			}
			var valuen string = ""
			if var_type.P_isnative && var_type.P_extends == C_extends_list {
				var value_type *Type_type = value.P_type
				if value_type == T_anylist {
					var sublist_anylist *Type_anylist = V_anylist_cast(
						value)
					var listsubprop []string = []string{}
					var subprop string = ""
					var sublist []*Type_any = sublist_anylist.P_listany
					for _, sub_any := range sublist {
						var sub_type *Type_type = V_type_from_any(
							sub_any)
						subprop = V_code_any(
							type_scope,
							indent+2,
							subpath,
							sub_any)
						switch var_type.P_container {
						case T_stringn:
							switch sub_type {
							case T_string:
								subprop = lineindent2 +
									subprop
							}
						}
						listsubprop = append(listsubprop, subprop)
					}
					valuen = V_stringn_from_liststringn_joinn(
						listsubprop,
						",")
				} else if value == E_any {
				} else {
					valuen = V_code_any(
						type_scope,
						indent+2,
						subpath,
						value)
				}
				switch type_lang {
				case C_lang_go:
					valuen = "[]" + V_code_type_typename(
						type_scope,
						var_type.P_container) +
						"{" +
						valuen +
						"}"
				case C_lang_swift:
					if valuen == "" {
						valuen = "[]"
					} else {
						valuen = "[" +
							valuen +
							lineindent1 +
							"]"
					}
				}
			} else {
				valuen = V_code_any(
					type_scope,
					indent+1,
					subpath,
					value)
				if V_booleann_from_stringn_startsn(
					valuen,
					lineindent1) {
					valuen = V_stringn_from_stringn_aftern(
						valuen,
						lineindent1)
				}
			}
			var prop string = lineindent1 + valuen
			listprop = append(listprop, prop)
		}
		props = V_stringn_from_liststringn_joinn(
			listprop,
			",")
	}
	switch type_lang {
	case C_lang_go:
		output = "" +
			lineindent + funcnamen + "(" + props + ")"
	default:
		output = "" +
			lineindent + funcnamen + "(" + props + ")"
	}
	return output
}

// A_func_call
func A_func_call(
	type_type *Type_type,
	type_anylist *Type_anylist) *Type_any {
	var type_func_call *Type_func_call = V_func_call(
		type_type,
		type_anylist)
	var output *Type_any = type_func_call.P_any
	return output
}

// V_func_call
func V_func_call(
	type_type *Type_type,
	type_anylist *Type_anylist) *Type_func_call {
	var output = V_func_call_create()
	output.P_type = type_type
	output.P_anylist = type_anylist
	return output
}

// A_func_call_any
func A_func_call_any(
	type_type *Type_type,
	type_any *Type_any) *Type_any {
	var type_func_call *Type_func_call = V_func_call_any(
		type_type,
		type_any)
	var output *Type_any = type_func_call.P_any
	return output
}

// V_func_call_any
func V_func_call_any(
	type_type *Type_type,
	type_any *Type_any) *Type_func_call {
	var type_anylist = V_anylist_from_any(
		type_any)
	var output = V_func_call_create()
	output.P_type = type_type
	output.P_anylist = type_anylist
	return output
}

// V_cast_func_call
func V_cast_func_call(
	type_func_call *Type_func_call) *Type_any {
	var output *Type_any = type_func_call.P_any
	return output
}

// V_func_call_cast
func V_func_call_cast(
	type_any *Type_any) *Type_func_call {
	var output *Type_func_call = E_func_call
	var type_func_call, ok = type_any.backref.(*Type_func_call)
	if ok {
		output = type_func_call
	}
	return output
}

// V_func_call_constructor
func V_func_call_constructor() *Type_func_call {
	var output = new(Type_func_call)
	return output
}

// V_func_call_create
func V_func_call_create() *Type_func_call {
	var output = V_func_call_constructor()
	V_func_call_initialize(
		output)
	return output
}

// V_func_call_initialize
func V_func_call_initialize(
	value *Type_func_call) {
	value.P_any = V_any_from_type_backref(
		T_func_call,
		value)
	value.P_type = E_type
	value.P_prefix = E_string
	value.P_anylist = E_anylist
	value.P_ismethod = C_false
}

// V_func_call_startup
func V_func_call_startup() *Type_type {
	var t_variable = T_func_call
	var e_variable = E_func_call
	V_func_call_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"func-call",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_func_call
	type_generic.P_code_funcn = V_code_func_call
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"type",
				T_type),
			V_var_new_public_from_namen_type(
				"prefix",
				T_string),
			V_var_new_public_from_namen_type(
				"anylist",
				T_anylist),
			V_var_new_public_from_namen_type(
				"ismethod",
				T_boolean)})
	var output *Type_type = t_variable
	return output
}

// Type_func_declare
type Type_func_declare struct {
	P_any    *Type_any
	P_type   *Type_type
	P_prefix *Type_string
}

func V_code_func_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_func_declare = V_func_declare_cast(
		type_any)
	var output string = V_code_from_func_declare(
		type_scope,
		indent,
		path,
		type_func_declare)
	return output
}

func V_get_keyn_func_declare(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_func_declare = V_func_declare_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "type":
		var p_type *Type_type = value.P_type
		if p_type != E_type {
			output = V_cast_type(
				p_type)
		}
	case "prefix":
		var p_prefix *Type_string = value.P_prefix
		if p_prefix != E_string {
			output = V_cast_string(
				p_prefix)
		}
	}
	return output
}

func V_code_from_func_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_func_declare *Type_func_declare) string {
	var type_lang *Type_lang = type_scope.P_lang
	var lineindent string = V_code_lineindent(
		type_scope,
		indent)
	var lineindent1 string = V_code_lineindent(
		type_scope,
		indent+1)
	var type_type *Type_type = type_func_declare.P_type
	var subpath string = path +
		"/code<-func-declare/" +
		type_type.P_name
	var prefix *Type_string = type_func_declare.P_prefix
	var prefixn string = type_type.P_prefix
	if prefix != E_string {
		prefixn = V_stringn_cast_string(
			prefix)
	}
	if prefixn == "" {
		prefixn = "v"
	}
	prefixn += "_"
	switch type_lang {
	case C_lang_go:
		prefixn = V_stringn_uppercase(
			prefixn)
	}
	var type_func = V_func_from_type(
		type_type)
	var funcnamen = prefixn + V_code_type_name(
		type_scope,
		type_type)
	var return_type = type_func.P_return
	var type_varlist = type_func.P_arglist
	var value_any = type_func.P_value
	if value_any == E_any && return_type != E_type {
		var output_var *Type_var = V_var_new_from_namen_type(
			"output",
			return_type)
		value_any = A_var_declare(
			output_var,
			E_any)
	}
	var returntypen = V_code_type_typename(
		type_scope,
		return_type)
	var body string = ""
	if V_type_from_any(
		value_any) == T_anylist {
		var listany []*Type_any = V_listany_any(
			value_any)
		body = V_code_from_listany(
			type_scope,
			indent+1,
			subpath,
			listany)
	} else {
		body = V_code_any(
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
			switch namen {
			case "backref":
				switch type_lang {
				case C_lang_go:
					vartypen = "any"
				case C_lang_swift:
					vartypen = "AnyObject"
				}
			}
			var prop = ""
			switch type_lang {
			case C_lang_go:
				prop = lineindent1 +
					namen +
					" " +
					vartypen
			case C_lang_swift:
				prop = lineindent1 +
					"_ " +
					namen +
					" : " +
					vartypen
			}
			listprop = append(listprop, prop)
		}
		props = V_stringn_from_liststringn_joinn(
			listprop,
			",")
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
			lineindent + "}" +
			"\n"
	case C_lang_swift:
		var outputdeclare = ""
		var outputline = ""
		var returnline = lineindent + ") {"
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
			lineindent + "}" +
			"\n"
	}
	return output
}

// A_func_declare
func A_func_declare(
	type_type *Type_type) *Type_any {
	var type_func_declare = V_func_declare_create()
	type_func_declare.P_type = type_type
	type_func_declare.P_prefix = E_string
	var output *Type_any = type_func_declare.P_any
	return output
}

// V_func_declare
func V_func_declare(
	type_type *Type_type) *Type_func_declare {
	var output = V_func_declare_create()
	output.P_type = type_type
	return output
}

// V_cast_func_declare
func V_cast_func_declare(
	type_func_declare *Type_func_declare) *Type_any {
	var output *Type_any = type_func_declare.P_any
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
	value.P_any = V_any_from_type_backref(
		T_func_declare,
		value)
	value.P_type = E_type
	value.P_prefix = E_string
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_func_declare
	type_generic.P_code_funcn = V_code_func_declare
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"type",
				T_type),
			V_var_new_public_from_namen_type(
				"prefix",
				T_string)})
	return t_variable
}

// (type global)
type Type_global struct {
	P_refcount int
	P_project  *Type_project
}

// global_constructor
func V_global_constructor() *Type_global {
	var output *Type_global = new(Type_global)
	output.P_refcount = 0
	return output
}

func V_t_global_register_from_pathn_listtype_listconst(
	type_scope *Type_scope) *Type_type {
	var t_listtype *Type_type = V_t_listtype()
	var t_listany *Type_type = V_t_listany()
	var type_varlist *Type_varlist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_from_namen_type(
				"pathn",
				T_stringn),
			V_var_new_from_namen_type(
				"listtype",
				t_listtype),
			V_var_new_from_namen_type(
				"listany",
				t_listany)})
	var type_any *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"global-register<-pathn-listtype-listconst",
		T_booleann,
		type_varlist,
		type_any)
	return output
}

func V_global_register_from_package(
	type_scope *Type_scope,
	type_package *Type_package) *Type_func_call {
	var t_global_register *Type_type = V_t_global_register_from_pathn_listtype_listconst(
		type_scope)
	var pathn string = type_package.P_path
	var p_path_string *Type_string = V_string_cast_stringn(pathn)
	var type_typemap *Type_typemap = type_package.P_typemap
	var type_typelist *Type_typelist = V_typelist_from_typemap(
		type_typemap)
	var type_constmap *Type_constmap = type_package.P_constmap
	var type_constlist *Type_constlist = V_constlist_from_constmap(
		type_constmap)
	var p_listtype []*Type_any = []*Type_any{}
	var p_listconst []*Type_any = []*Type_any{}
	for _, type_type := range type_typelist.P_listtype {
		var t_x_startup *Type_type = V_t_x_startup(
			type_scope,
			type_type)
		var func_call *Type_any = A_func_call(
			t_x_startup,
			E_anylist)
		p_listtype = append(p_listtype, func_call)
	}
	for _, type_const := range type_constlist.P_listconst {
		var t_x_startup *Type_type = V_t_const_x_startup(
			type_scope,
			type_const)
		var func_call *Type_any = A_func_call(
			t_x_startup,
			E_anylist)
		p_listconst = append(p_listconst, func_call)
	}
	var type_anylist *Type_anylist = V_anylist_from_listany(
		[]*Type_any{
			p_path_string.P_any,
			A_anylist_run_from_listany(
				p_listtype),
			A_anylist_run_from_listany(
				p_listconst)})
	var output *Type_func_call = V_func_call(
		t_global_register,
		type_anylist)
	return output
}

func A_global_register_from_package(
	type_scope *Type_scope,
	type_package *Type_package) *Type_any {
	var type_func_call *Type_func_call = V_global_register_from_package(
		type_scope,
		type_package)
	var func_call_any *Type_any = type_func_call.P_any
	var isregistered_var *Type_var = V_var_new_from_namen_type(
		"isregistered",
		T_booleann)
	var type_var_declare *Type_var_declare = V_var_declare(
		isregistered_var,
		func_call_any)
	var output *Type_any = type_var_declare.P_any
	return output
}

func V_global_register_from_pathn_listtype_listconst(
	pathn string,
	listtype []*Type_type,
	listany []*Type_any) bool {
	if pathn == "vx/core" {
		G_global.P_project = V_project_create()
	}
	var listkey []string = []string{}
	var listconstany []*Type_any = []*Type_any{}
	var listconst []*Type_const = []*Type_const{}
	for _, type_any := range listany {
		var type_const *Type_const = V_const_from_any(
			type_any)
		if type_const != E_const {
			var namen string = type_const.P_name
			listkey = append(listkey, namen)
			listconstany = append(listconstany, type_any)
			listconst = append(listconst, type_const)
		}
	}
	var anymap *Type_anymap = V_anymap_from_listkey_listany(
		listkey,
		listconstany)
	var constmap *Type_constmap = V_constmap_from_listconst(
		listconst)
	var typemap *Type_typemap = V_typemap_from_listtype(
		listtype)
	var type_package *Type_package = V_package_create()
	type_package.P_path = pathn
	type_package.P_anymap = anymap
	type_package.P_constmap = constmap
	type_package.P_typemap = typemap
	return true
}

// global_release
func V_global_release() {
	G_global.P_refcount -= 1
}

// global_reserve
func V_global_reserve() {
	G_global.P_refcount += 1
}

// V_t_global_release
func V_t_global_release(
	type_scope *Type_scope) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"global-release",
		E_type,
		E_varlist,
		E_any)
	return output
}

// V_t_global_reserve
func V_t_global_reserve(
	type_scope *Type_scope) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"global-reserve",
		E_type,
		E_varlist,
		E_any)
	return output
}

// (func if)
type Type_if struct {
	P_any          *Type_any
	P_return_type  *Type_type
	P_thenelselist *Type_thenelselist
}

func V_code_if(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/code-if"
	var type_lang *Type_lang = type_scope.P_lang
	var type_if = V_if_cast(type_any)
	var type_thenelselist = type_if.P_thenelselist
	var listthenelse = type_thenelselist.P_listthenelse
	var output = ""
	if len(listthenelse) > 0 {
		var prop string = ""
		var listprop []string = []string{}
		var isfound = false
		if type_if.P_any.P_isrun {
			for _, type_thenelse := range listthenelse {
				var coden = V_stringn_cast_string(
					type_thenelse.P_code)
				switch coden {
				case ":then":
					var if_any = type_thenelse.P_if
					if C_true.P_any == if_any {
						var then_any = type_thenelse.P_then
						if then_any != E_any {
							prop = V_code_any(
								type_scope,
								indent,
								subpath,
								then_any)
							listprop = append(listprop, prop)
						}
						isfound = true
					}
				case ":else":
					var then_any = type_thenelse.P_then
					if then_any != E_any {
						prop = V_code_any(type_scope, indent, subpath, then_any)
						listprop = append(listprop, prop)
					}
					isfound = true
				}
				if isfound {
					break
				}
			}
		} else {
			var lineindent = V_code_lineindent(
				type_scope,
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
						type_scope,
						type_var)
				default:
					if_stringn = V_code_any(
						type_scope,
						indent+1,
						subpath,
						if_any)
				}
				var then_stringn string = ""
				if then_any != E_any {
					then_stringn = V_code_any(
						type_scope,
						indent+1,
						subpath,
						then_any)
				}
				var parenopen string = ""
				var parenclose string = ""
				switch type_lang {
				case C_lang_java, C_lang_js:
					parenopen = "("
					parenclose = ")"
				}
				if thenelseidx == 0 {
					prop = "" +
						lineindent + "if " + parenopen + if_stringn + parenclose + " {" +
						then_stringn
				} else {
					prop = "" +
						lineindent + "} else if + " + parenopen + if_stringn + parenclose + " {" +
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

func V_get_keyn_if(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_if = V_if_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "return-type":
		var p_return_type *Type_type = value.P_return_type
		if p_return_type != E_type {
			output = V_cast_type(
				p_return_type)
		}
	case "thenelselist":
		var p_thenelselist *Type_thenelselist = value.P_thenelselist
		if p_thenelselist != E_thenelselist {
			output = V_cast_thenelselist(
				p_thenelselist)
		}
	}
	return output
}

func V_func_if(
	type_type *Type_type) *Type_func {
	var output *Type_func = E_func
	return output
}

// A_if_from_if_then
func A_if_from_if_then(
	if_any *Type_any,
	then_any *Type_any) *Type_any {
	var type_if *Type_if = V_if_from_type_if_then(
		E_type,
		if_any,
		then_any)
	var output *Type_any = type_if.P_any
	return output
}

// A_if_from_type_if_then
func A_if_from_type_if_then(
	return_type *Type_type,
	if_any *Type_any,
	then_any *Type_any) *Type_any {
	var type_if *Type_if = V_if_from_type_if_then(
		return_type,
		if_any,
		then_any)
	var output *Type_any = type_if.P_any
	return output
}

// V_if_from_type_if_then
func V_if_from_type_if_then(
	return_type *Type_type,
	if_any *Type_any,
	then_any *Type_any) *Type_if {
	var output *Type_if = V_if_create()
	output.P_return_type = return_type
	var type_thenelse *Type_thenelse = V_then_from_if_then(
		if_any,
		then_any)
	var listthenelse []*Type_thenelse = []*Type_thenelse{}
	listthenelse = append(listthenelse, type_thenelse)
	var type_thenelselist = V_thenelselist_from_listthenelse(
		listthenelse)
	output.P_thenelselist = type_thenelselist
	return output
}

// A_if_run_from_type_booleann_then
func A_if_run_from_type_booleann_then(
	return_type *Type_type,
	booleann bool,
	then_any *Type_any) *Type_any {
	var type_if = V_if_create()
	type_if.P_return_type = return_type
	type_if.P_any.P_isrun = true
	var type_thenelse *Type_thenelse = V_then_from_booleann(
		booleann,
		then_any)
	var listthenelse []*Type_thenelse = []*Type_thenelse{}
	listthenelse = append(listthenelse, type_thenelse)
	var type_thenelselist = V_thenelselist_from_listthenelse(
		listthenelse)
	type_if.P_thenelselist = type_thenelselist
	var output *Type_any = type_if.P_any
	return output
}

// A_if_run_from_type_listthenelse
func A_if_run_from_type_listthenelse(
	return_type *Type_type,
	listthenelse []*Type_thenelse) *Type_any {
	var type_if = V_if_create()
	type_if.P_return_type = return_type
	type_if.P_any.P_isrun = true
	var type_thenelselist = V_thenelselist_from_listthenelse(
		listthenelse)
	type_if.P_thenelselist = type_thenelselist
	var output *Type_any = type_if.P_any
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
	value.P_any = V_any_from_type_backref(
		T_if,
		value)
	value.P_return_type = E_type
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
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_if
	type_generic.P_func_funcn = V_func_if
	type_generic.P_code_funcn = V_code_if
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type("return-type", T_type),
			V_var_new_public_from_namen_type("thenelselist", T_thenelselist)})
	return t_variable
}

// V_cast_if
func V_cast_if(
	value *Type_if) *Type_any {
	return value.P_any
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

// (type int)
type Type_int struct {
	P_any  *Type_any
	P_intn int
}

// V_int_constructor
func V_int_constructor() *Type_int {
	var output = new(Type_int)
	return output
}

// V_int_create
func V_int_create() *Type_int {
	var output = V_int_constructor()
	V_int_initialize(output)
	return output
}

// V_int_initialize
func V_int_initialize(
	value *Type_int) {
	value.P_any = V_any_from_type_backref(
		T_int,
		value)
	value.P_intn = 0
}

// V_int_startup
func V_int_startup() *Type_type {
	var t_variable = T_int
	var e_variable = E_int
	V_int_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"int",
		E_string,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_from_any_int
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"intn",
				T_intn)})
	return t_variable
}

// V_cast_int
func V_cast_int(
	value *Type_int) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_int_cast
func V_int_cast(
	type_any *Type_any) *Type_int {
	var output *Type_int = E_int
	var value, ok = type_any.backref.(*Type_int)
	if ok {
		output = value
	}
	return output
}

func V_code_from_any_int(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_int = V_int_cast(
		type_any)
	var output string = V_stringn_cast_intn(
		type_int.P_intn)
	return output
}

// A_int_cast_intn
func A_int_cast_intn(
	intn int) *Type_any {
	var type_int *Type_int = V_int_cast_intn(
		intn)
	var output *Type_any = V_cast_int(
		type_int)
	return output
}

// V_int_cast_intn
func V_int_cast_intn(
	intn int) *Type_int {
	var output *Type_int = V_int_create()
	output.P_intn = intn
	return output
}

// V_intn_cast_int
func V_intn_cast_int(
	type_int *Type_int) int {
	var output int = type_int.P_intn
	return output
}

// (type intn)
type Type_intn struct {
	P_any *Type_any
}

// V_intn_constructor
func V_intn_constructor() *Type_intn {
	var output = new(Type_intn)
	return output
}

// V_intn_create
func V_intn_create() *Type_intn {
	var output = V_intn_constructor()
	V_intn_initialize(output)
	return output
}

// V_intn_initialize
func V_intn_initialize(
	value *Type_intn) {
	value.P_any = V_any_from_type_backref(
		T_intn,
		value)
}

// V_intn_startup
func V_intn_startup() *Type_type {
	var t_variable = T_intn
	var e_variable = E_intn
	V_intn_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"intn",
		E_string,
		e_variable.P_any)
	return t_variable
}

// Type_lang
type Type_lang struct {
	P_any        *Type_any
	P_name       *Type_string
	P_indent     *Type_string
	P_pkgref     string
	P_typeref    string
	P_isrefcount bool
}

func V_indentn_from_lang(
	type_lang *Type_lang) string {
	return V_stringn_cast_string(type_lang.P_indent)
}

func V_namen_from_lang(
	type_lang *Type_lang) string {
	return V_stringn_cast_string(type_lang.P_name)
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
	value.P_any = V_any_from_type_backref(
		T_lang,
		value)
	value.P_name = E_string
	value.P_indent = E_string
	value.P_pkgref = ""
	value.P_typeref = ""
	value.P_isrefcount = false
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
		e_variable.P_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

type Type_list struct {
	P_any *Type_any
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	//t_variable.type_generic = new(Type_list_generic)
	return t_variable
}

// (type log-stringn)
type Type_log_stringn struct {
	P_any     *Type_any
	P_stringn string
}

// V_log_stringn_constructor
func V_log_stringn_constructor() *Type_log_stringn {
	var output = new(Type_log_stringn)
	return output
}

// V_log_stringn_create
func V_log_stringn_create() *Type_log_stringn {
	var output = V_log_stringn_constructor()
	V_log_stringn_initialize(
		output)
	return output
}

// V_log_stringn_initialize
func V_log_stringn_initialize(
	value *Type_log_stringn) {
	value.P_any = V_any_from_type_backref(
		T_log_stringn,
		value)
	value.P_stringn = ""
}

// V_log_stringn_startup
func V_log_stringn_startup() *Type_type {
	var t_variable = T_log_stringn
	var e_variable = E_log_stringn
	V_log_stringn_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"log-stringn",
		C_extends_func,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_func_funcn = V_func_log_stringn
	type_generic.P_code_funcn = V_code_log_stringn
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"stringn",
				T_stringn)})
	var output *Type_type = t_variable
	return output
}

// V_cast_log_stringn
func V_cast_log_stringn(
	value *Type_log_stringn) *Type_any {
	return value.P_any
}

// V_log_stringn_cast
func V_log_stringn_cast(
	type_any *Type_any) *Type_log_stringn {
	var output *Type_log_stringn = E_log_stringn
	var value, ok = type_any.backref.(*Type_log_stringn)
	if ok {
		output = value
	}
	return output
}

func V_func_log_stringn(
	type_type *Type_type) *Type_func {
	var output *Type_func = V_func_new_from_type_return_varlist_value(
		type_type,
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"stringn",
					T_stringn)}),
		E_any)
	return output
}

func F_log_stringn(
	type_type *Type_type,
	val1 *Type_any,
	val2 *Type_any) *Type_any {
	var output *Type_any = E_any
	return output
}

// V_code_log_stringn
func V_code_log_stringn(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_string *Type_string = V_string_cast(
		type_any)
	var stringn string = type_string.P_stringn
	var output string = stringn
	if indent > 0 && V_booleann_from_stringn_startsn(
		output,
		"\n") {
		var lineindent = V_code_lineindent(
			type_scope,
			indent)
		output = V_stringn_from_stringn_findn_replacen(
			output,
			"\n",
			lineindent)
	}
	output = "\"" + output + "\""
	return output
}

// (type map)
type Type_map struct {
	P_any *Type_any
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	//t_variable.type_generic = new(Type_map_generic)
	return t_variable
}

// Type_msg
type Type_msg struct {
	P_any   *Type_any
	errorn  error
	P_coden string
}

// V_msg_constructor
func V_msg_constructor() *Type_msg {
	var output = new(Type_msg)
	return output
}

// V_msg_create
func V_msg_create() *Type_msg {
	var output = V_msg_constructor()
	V_msg_initialize(
		output)
	return output
}

// V_msg_initialize
func V_msg_initialize(
	value *Type_msg) {
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

func V_msg_from_errorn(
	errorn error) *Type_msg {
	var output = V_msg_create()
	output.errorn = errorn
	return output
}

// Type_msgblock
type Type_msgblock struct {
	P_any     *Type_any
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

// V_cast_msgblock
func V_cast_msgblock(
	value *Type_msgblock) *Type_any {
	var output = value.P_any
	return output
}

// V_msgblock_cast
func V_msgblock_cast(
	type_any *Type_any) *Type_msgblock {
	var output *Type_msgblock = E_msgblock
	var value, ok = type_any.backref.(*Type_msgblock)
	if ok {
		output = value
	}
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

func V_msgblock_from_msgblock_msg(
	type_msgblock *Type_msgblock,
	type_msg *Type_msg) *Type_msgblock {
	var output *Type_msgblock = V_msgblock_copy(
		type_msgblock,
		V_anylist_from_listany(
			[]*Type_any{
				type_msg.P_any}))
	return output
}

func V_msgblock_from_namen(
	namen string) *Type_msgblock {
	var output *Type_msgblock = V_msgblock_create()
	output.P_namen = namen
	return output
}

// (func new)
type Type_new struct {
	P_any *Type_any
}

// V_new_constructor
func V_new_constructor() *Type_new {
	var output = new(Type_new)
	return output
}

// V_new_initialize
func V_new_initialize(
	value *Type_new) {
	value.P_any = V_any_from_type_backref(
		T_new,
		value)
}

// V_new_startup
func V_new_startup() *Type_type {
	var t_variable *Type_type = T_new
	var e_variable *Type_new = E_new
	V_new_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"new",
		C_extends_func,
		e_variable.P_any)
	var output *Type_type = t_variable
	return output
}

// (type none)
type Type_none struct {
	P_any *Type_any
}

// V_none_constructor
func V_none_constructor() *Type_none {
	var output = new(Type_none)
	return output
}

// V_none_create
func V_none_create() *Type_none {
	var output = V_none_constructor()
	V_none_initialize(
		output)
	return output
}

// V_none_initialize
func V_none_initialize(
	value *Type_none) {
	value.P_any = V_any_from_type_backref(
		T_none,
		value)
}

// V_none_startup
func V_none_startup() *Type_type {
	var t_variable = T_none
	var e_variable = E_none
	V_none_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"none",
		E_string,
		e_variable.P_any)
	return t_variable
}

func V_cast_none(
	type_none *Type_none) *Type_any {
	var output *Type_any = type_none.P_any
	return output
}

// (type package)
type Type_package struct {
	P_any      *Type_any
	P_path     string
	P_anymap   *Type_anymap
	P_constmap *Type_constmap
	P_typemap  *Type_typemap
}

// V_package_constructor
func V_package_constructor() *Type_package {
	var output = new(Type_package)
	return output
}

// V_package_create
func V_package_create() *Type_package {
	var output = V_package_constructor()
	V_package_initialize(
		output)
	return output
}

// V_package_initialize
func V_package_initialize(
	value *Type_package) {
	value.P_any = V_any_from_type_backref(
		T_package,
		value)
	value.P_path = ""
	value.P_anymap = E_anymap
	value.P_constmap = E_constmap
	value.P_typemap = E_typemap
}

// V_package_startup
func V_package_startup() *Type_type {
	var t_variable = T_package
	var e_variable = E_package
	V_package_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"package",
		C_extends_struct,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"path",
				T_stringn),
			V_var_new_public_from_namen_type(
				"anymap",
				T_anymap),
			V_var_new_public_from_namen_type(
				"constmap",
				T_constmap),
			V_var_new_public_from_namen_type(
				"typemap",
				T_typemap)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_package
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_package
func V_cast_package(
	value *Type_package) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_package_cast
func V_package_cast(
	type_any *Type_any) *Type_package {
	var output *Type_package = E_package
	var value, ok = type_any.backref.(*Type_package)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_package(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_package = V_package_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "path":
		output = V_cast_string(
			V_string_cast_stringn(
				value.P_path))
	case "anymap":
		output = V_cast_anymap(
			value.P_anymap)
	case "constmap":
		output = V_cast_constmap(
			value.P_constmap)
	case "typemap":
		output = V_cast_typemap(
			value.P_typemap)
	}
	return output
}

func V_code_all_from_package(
	type_scope *Type_scope,
	indent int,
	path string,
	type_package *Type_package) string {
	var subpath string = path + "/code-all<-package"
	var type_lang *Type_lang = type_scope.P_lang
	var langindent int = 0
	switch type_lang {
	case C_lang_go:
		langindent = 0
	default:
		langindent = 1
	}
	var listany []*Type_any = []*Type_any{
		A_package_declare_new_from_package_part(
			type_package,
			C_enum_struct),
		A_package_declare_new_from_package_part(
			type_package,
			C_enum_const_startup),
		A_package_declare_new_from_package_part(
			type_package,
			C_enum_t_type),
		A_package_declare_new_from_package_part(
			type_package,
			C_enum_e_type),
		A_package_declare_new_from_package_part(
			type_package,
			C_enum_c_const),
		A_package_declare_new_from_package_part(
			type_package,
			C_enum_startup),
		A_global_register_from_package(
			type_scope,
			type_package)}
	var output string = V_code_from_listany(
		type_scope,
		langindent,
		subpath,
		listany)
	return output
}

// (func package_declare)
type Type_package_declare struct {
	P_any     *Type_any
	P_package *Type_package
	P_part    *Type_enum
}

// V_package_declare_constructor
func V_package_declare_constructor() *Type_package_declare {
	var output *Type_package_declare = new(Type_package_declare)
	return output
}

// V_package_declare_create
func V_package_declare_create() *Type_package_declare {
	var output *Type_package_declare = V_package_declare_constructor()
	V_package_declare_initialize(
		output)
	return output
}

// V_package_declare_initialize
func V_package_declare_initialize(
	value *Type_package_declare) {
	value.P_any = V_any_from_type_backref(
		T_package_declare,
		value)
}

// V_package_declare_startup
func V_package_declare_startup() *Type_type {
	var t_variable *Type_type = T_package_declare
	var e_variable *Type_package_declare = E_package_declare
	V_package_declare_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"package-declare",
		C_extends_struct,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"package",
				T_const),
			V_var_new_public_from_namen_type(
				"part",
				T_enum)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_package_declare
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_package_declare
func V_cast_package_declare(
	value *Type_package_declare) *Type_any {
	return value.P_any
}

// V_package_declare_cast
func V_package_declare_cast(
	type_any *Type_any) *Type_package_declare {
	var output *Type_package_declare = E_package_declare
	var value, ok = type_any.backref.(*Type_package_declare)
	if ok {
		output = value
	}
	return output
}

func A_all_from_package_part(
	type_package *Type_package,
	part_enum *Type_enum) *Type_any {
	var listany []*Type_any = []*Type_any{}
	var type_typemap *Type_typemap = type_package.P_typemap
	var type_typelist *Type_typelist = V_typelist_from_typemap(
		type_typemap)
	var listtype []*Type_type = type_typelist.P_listtype
	var type_any *Type_any = E_any
	switch part_enum {
	case C_enum_struct:
		for _, type_type := range listtype {
			type_any = A_type_declare_new_from_type_part(
				type_type,
				E_enum)
			listany = append(listany, type_any)
		}
	case C_enum_const_startup:
		var type_constmap *Type_constmap = type_package.P_constmap
		var type_constlist *Type_constlist = V_constlist_from_constmap(
			type_constmap)
		var listconst []*Type_const = type_constlist.P_listconst
		for _, type_const := range listconst {
			var type_const_declare *Type_const_declare = V_const_declare_new_from_const_part(
				type_const,
				C_enum_const_startup)
			type_any = type_const_declare.P_any
			listany = append(listany, type_any)
		}
	case C_enum_t_type:
		for _, type_type := range listtype {
			type_any = A_type_declare_new_from_type_part(
				type_type,
				C_enum_t_type)
			listany = append(listany, type_any)
		}
	case C_enum_e_type:
		for _, type_type := range listtype {
			type_any = A_type_declare_new_from_type_part(
				type_type,
				C_enum_e_type)
			listany = append(listany, type_any)
		}
	case C_enum_c_const:
		var type_constmap *Type_constmap = type_package.P_constmap
		var type_constlist *Type_constlist = V_constlist_from_constmap(
			type_constmap)
		var listconst []*Type_const = type_constlist.P_listconst
		for _, type_const := range listconst {
			var type_const_declare *Type_const_declare = V_const_declare_new_from_const_part(
				type_const,
				C_enum_c_const)
			type_any = type_const_declare.P_any
			listany = append(listany, type_any)
		}
	}
	var output *Type_any = A_anylist_run_from_listany(
		listany)
	return output
}

func V_code_package_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var subpath = path + "/code-package-declare"
	var type_package_declare *Type_package_declare = V_package_declare_cast(
		type_any)
	var p_package *Type_package = type_package_declare.P_package
	var p_part *Type_enum = type_package_declare.P_part
	var all_any *Type_any = A_all_from_package_part(
		p_package,
		p_part)
	var output string = V_code_any(
		type_scope,
		indent,
		subpath,
		all_any)
	return output
}

func A_package_declare_new_from_package_part(
	type_package *Type_package,
	part_enum *Type_enum) *Type_any {
	var value *Type_package_declare = V_package_declare_new_from_package_part(
		type_package,
		part_enum)
	var output *Type_any = value.P_any
	return output
}

func V_package_declare_new_from_package_part(
	type_package *Type_package,
	part_enum *Type_enum) *Type_package_declare {
	var output *Type_package_declare = V_package_declare_create()
	output.P_package = type_package
	output.P_part = part_enum
	return output
}

/*
func V_code_package_register(
	type_scope *Type_scope,
	indent int,
	path string,
	type_package *Type_package) string {
	var package_declare *Type_package_declare = V_package_declare_create()
	package_declare.P_package = type_package
	package_declare.P_part = C_enum_startup
	var output string = V_code_package_declare(
		type_scope,
		indent,
		path,
		V_cast_package_declare(
			package_declare))
	return output
}
*/

// (type packagemap)
type Type_packagemap struct {
	P_any        *Type_any
	P_listkey    []string
	P_mappackage map[string]*Type_package
}

// V_packagemap_constructor
func V_packagemap_constructor() *Type_packagemap {
	var output = new(Type_packagemap)
	return output
}

// V_packagemap_create
func V_packagemap_create() *Type_packagemap {
	var output = V_packagemap_constructor()
	V_packagemap_initialize(
		output)
	return output
}

// V_packagemap_initialize
func V_packagemap_initialize(
	value *Type_packagemap) {
	value.P_any = V_any_from_type_backref(
		T_packagemap,
		value)
	value.P_listkey = []string{}
	value.P_mappackage = map[string]*Type_package{}
}

// V_packagemap_startup
func V_packagemap_startup() *Type_type {
	var t_variable = T_packagemap
	var e_variable = E_packagemap
	V_packagemap_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"packagemap",
		C_extends_map,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_packagemap
	type_generic.P_listkey_funcn = V_listkey_packagemap
	type_generic.P_mapany_funcn = V_mapany_packagemap
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_packagemap
func V_cast_packagemap(
	value *Type_packagemap) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_packagemap_cast
func V_packagemap_cast(
	type_any *Type_any) *Type_packagemap {
	var output *Type_packagemap = E_packagemap
	var value, ok = type_any.backref.(*Type_packagemap)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_packagemap(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_packagemap *Type_packagemap = V_packagemap_cast(
		type_any)
	var type_package *Type_package = V_package_from_packagemap_keyn(
		type_packagemap,
		keyn)
	var output *Type_any = E_any
	if type_package != E_package {
		output = type_package.P_any
	}
	return output
}

func V_listkey_packagemap(
	type_any *Type_any) []string {
	var type_packagemap *Type_packagemap = V_packagemap_cast(
		type_any)
	var output []string = type_packagemap.P_listkey
	return output
}

func V_mapany_packagemap(
	type_any *Type_any) map[string]*Type_any {
	var type_packagemap *Type_packagemap = V_packagemap_cast(
		type_any)
	var listkey []string = type_packagemap.P_listkey
	var mappackage map[string]*Type_package = type_packagemap.P_mappackage
	var output map[string]*Type_any = map[string]*Type_any{}
	for _, keyn := range listkey {
		var type_package *Type_package = V_package_from_mappackage_keyn(
			mappackage,
			keyn)
		var value *Type_any = V_cast_package(
			type_package)
		output[keyn] = value
	}
	return output
}

func V_package_from_mappackage_keyn(
	mappackage map[string]*Type_package,
	keyn string) *Type_package {
	var output *Type_package = E_package
	var value, ok = mappackage[keyn]
	if ok {
		output = value
	}
	return output
}

func V_package_from_packagemap_keyn(
	type_packagemap *Type_packagemap,
	keyn string) *Type_package {
	var mapvalue map[string]*Type_package = type_packagemap.P_mappackage
	var output *Type_package = V_package_from_mappackage_keyn(
		mapvalue,
		keyn)
	return output
}

func V_packagemap_from_listpackage(
	listpackage []*Type_package) *Type_packagemap {
	var listkey []string = []string{}
	var mapvalue map[string]*Type_package = map[string]*Type_package{}
	for _, value := range listpackage {
		var keyn string = value.P_path
		if keyn != "" {
			if !V_booleann_from_liststringn_containsn(
				listkey,
				keyn) {
				listkey = append(listkey, keyn)
			}
			mapvalue[keyn] = value
		}
	}
	var output *Type_packagemap = E_packagemap
	if len(listkey) > 0 {
		output = V_packagemap_create()
		output.P_listkey = listkey
		output.P_mappackage = mapvalue
	}
	return output
}

// (type project)
type Type_project struct {
	P_any        *Type_any
	P_name       string
	P_packagemap *Type_packagemap
}

// V_project_constructor
func V_project_constructor() *Type_project {
	var output = new(Type_project)
	return output
}

// V_project_create
func V_project_create() *Type_project {
	var output = V_project_constructor()
	V_project_initialize(
		output)
	return output
}

// V_project_initialize
func V_project_initialize(
	value *Type_project) {
	value.P_any = V_any_from_type_backref(
		T_project,
		value)
	value.P_packagemap = E_packagemap
}

// V_project_startup
func V_project_startup() *Type_type {
	var t_variable = T_project
	var e_variable = E_project
	V_project_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"project",
		C_extends_struct,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"name",
				T_stringn),
			V_var_new_public_from_namen_type(
				"packagemap",
				T_packagemap)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_project
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_project
func V_cast_project(
	value *Type_project) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_project_cast
func V_project_cast(
	type_any *Type_any) *Type_project {
	var output *Type_project = E_project
	var value, ok = type_any.backref.(*Type_project)
	if ok {
		output = value
	}
	return output
}

// V_get_keyn_project
func V_get_keyn_project(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_project = V_project_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "packagemap":
		output = V_cast_packagemap(
			value.P_packagemap)
	}
	return output
}

func V_const_from_project_pkgnamen_constnamen(
	type_project *Type_project,
	pkgnamen string,
	constnamen string) *Type_any {
	var type_package *Type_package = V_package_from_project_pkgnamen(
		type_project,
		pkgnamen)
	var output *Type_any = V_any_from_anymap_keyn(
		type_package.P_anymap,
		constnamen)
	return output
}

func V_package_from_project_pkgnamen(
	type_project *Type_project,
	pkgnamen string) *Type_package {
	var output *Type_package = V_package_from_packagemap_keyn(
		type_project.P_packagemap,
		pkgnamen)
	return output
}

func V_type_from_project_pkgnamen_typenamen(
	type_project *Type_project,
	pkgnamen string,
	typenamen string) *Type_type {
	var type_package *Type_package = V_package_from_project_pkgnamen(
		type_project,
		pkgnamen)
	var pathn string = pkgnamen +
		"/" +
		typenamen
	var output *Type_type = V_type_from_typemap_keyn(
		type_package.P_typemap,
		pathn)
	return output
}

// Type_scope
type Type_scope struct {
	P_any     *Type_any
	P_lang    *Type_lang
	P_project *Type_project
	P_package *Type_package
}

// V_pkgnamen_from_scope
func V_pkgnamen_from_scope(
	type_scope *Type_scope) string {
	var type_package *Type_package = type_scope.P_package
	var output string = type_package.P_path
	return output
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
	value.P_any = V_any_from_type_backref(
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
	V_scope_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"scope",
		C_extends_struct,
		e_variable.P_any)
	//t_variable.type_generic = new(Type_lang_generic)
	return t_variable
}

// (type string)
type Type_string struct {
	P_any     *Type_any
	P_stringn string
}

// V_string_constructor
func V_string_constructor() *Type_string {
	var output *Type_string = new(Type_string)
	return output
}

// V_string_create
func V_string_create() *Type_string {
	var output *Type_string = V_string_constructor()
	V_string_initialize(
		output)
	return output
}

// V_string_initialize
func V_string_initialize(
	value *Type_string) {
	value.P_any = V_any_from_type_backref(
		T_string,
		value)
	value.P_stringn = ""
}

// V_string_shutdown
func V_string_shutdown(
	value *Type_string) {
	value.P_stringn = ""
	V_any_shutdown(
		value.P_any)
	V_global_release()
}

// V_string_startup
func V_string_startup() *Type_type {
	var t_variable *Type_type = T_string
	var e_variable *Type_string = E_string
	V_string_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"string",
		E_string,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"stringn",
				T_stringn)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_copy_funcn = V_copy_string
	type_generic.P_new_funcn = V_new_string
	type_generic.P_code_funcn = V_code_string
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_string
func V_cast_string(
	type_string *Type_string) *Type_any {
	var output *Type_any = type_string.P_any
	return output
}

// V_string_cast
func V_string_cast(
	type_any *Type_any) *Type_string {
	var output *Type_string = E_string
	var value, ok = type_any.backref.(*Type_string)
	if ok {
		output = value
	}
	return output
}

// V_string_copy
func V_string_copy(
	value *Type_string,
	type_anylist *Type_anylist) *Type_string {
	var output *Type_string = value
	var merged_anylist *Type_anylist = V_anylist_from_listtype_anylist_anylist(
		[]*Type_type{T_string},
		E_anylist,
		type_anylist)
	var stringn = ""
	var stringlist *Type_stringlist = V_stringlist_from_anylist(
		merged_anylist)
	var liststringn []string = V_liststringn_from_liststring(
		stringlist.P_liststring)
	stringn = V_stringn_from_liststringn_joinn(
		liststringn,
		"")
	var ischanged = false
	if value.P_stringn != stringn {
		ischanged = true
	}
	if ischanged {
		output = V_string_create()
		output.P_stringn = stringn
	}
	return output
}

// V_copy_string
func V_copy_string(
	type_any *Type_any,
	type_anylist *Type_anylist) *Type_any {
	return E_any
}

// V_string_new
func V_string_new(
	type_anylist *Type_anylist) *Type_string {
	var output *Type_string = V_string_copy(
		E_string,
		type_anylist)
	return output
}

// V_new_string
func V_new_string(
	type_anylist *Type_anylist) *Type_any {
	return E_any
}

// F_string
func F_string(
	type_anylist *Type_anylist) *Type_string {
	var output *Type_string = V_string_new(
		type_anylist)
	return output
}

// V_code_string
func V_code_string(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_string *Type_string = V_string_cast(
		type_any)
	var stringn string = type_string.P_stringn
	var output string = stringn
	if indent > 0 && V_booleann_from_stringn_startsn(
		output,
		"\n") {
		var lineindent = V_code_lineindent(
			type_scope,
			indent)
		output = V_stringn_from_stringn_findn_replacen(
			output,
			"\n",
			lineindent)
	}
	output = "\"" + output + "\""
	return output
}

// A_string_cast_stringn
func A_string_cast_stringn(
	stringn string) *Type_any {
	var type_string *Type_string = V_string_cast_stringn(
		stringn)
	var output *Type_any = V_cast_string(
		type_string)
	return output
}

// V_string_cast_stringn
func V_string_cast_stringn(
	stringn string) *Type_string {
	var output *Type_string = E_string
	if stringn != "" {
		output = V_string_create()
		output.P_stringn = stringn
	}
	return output
}

// (type stringn)
type Type_stringn struct {
	P_any     *Type_any
	P_stringn string
}

// V_stringn_constructor
func V_stringn_constructor() *Type_stringn {
	var output *Type_stringn = new(Type_stringn)
	return output
}

// V_stringn_create
func V_stringn_create() *Type_stringn {
	var output *Type_stringn = V_stringn_constructor()
	V_stringn_initialize(
		output)
	return output
}

// V_stringn_initialize
func V_stringn_initialize(
	value *Type_stringn) {
	value.P_any = V_any_from_type_backref(
		T_stringn,
		value)
	value.P_stringn = ""
}

// V_stringn_startup
func V_stringn_startup() *Type_type {
	var t_variable *Type_type = T_stringn
	var e_variable *Type_stringn = E_stringn
	V_stringn_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"stringn",
		E_string,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_stringn
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_stringn
func V_cast_stringn(
	type_stringn *Type_stringn) *Type_any {
	var output *Type_any = type_stringn.P_any
	return output
}

// V_stringn_cast
func V_stringn_cast(
	type_any *Type_any) *Type_stringn {
	var output *Type_stringn = E_stringn
	var value, ok = type_any.backref.(*Type_stringn)
	if ok {
		output = value
	}
	return output
}

// V_stringn_new_from_stringn
func V_stringn_new_from_stringn(
	stringn string) *Type_stringn {
	var output *Type_stringn = V_stringn_create()
	output.P_stringn = stringn
	return output
}

func V_code_stringn(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_stringn *Type_stringn = V_stringn_cast(
		type_any)
	var output string = "\"" + type_stringn.P_stringn + "\""
	return output
}

// (type stringlist)
type Type_stringlist struct {
	P_any        *Type_any
	P_liststring []*Type_string
}

// V_get_indexn_stringlist
func V_get_indexn_stringlist(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_stringlist *Type_stringlist = V_stringlist_cast_any(type_any)
	var type_string *Type_string = V_stringlist_string_from_stringlist_indexn(
		type_stringlist,
		indexn)
	var output *Type_any = type_string.P_any
	return output
}

// V_code_stringlist
func V_code_stringlist(
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

// V_listany_stringlist
func V_listany_stringlist(
	type_any *Type_any) []*Type_any {
	var type_stringlist *Type_stringlist = V_stringlist_cast_any(
		type_any)
	var output []*Type_any = V_stringlist_listany_from_liststring(
		type_stringlist.P_liststring)
	return output
}

func V_stringlist_listany_from_liststring(
	liststring []*Type_string) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_string := range liststring {
		output = append(output, type_string.P_any)
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

func V_stringlist_cast_any(
	type_any *Type_any) *Type_stringlist {
	var output *Type_stringlist = E_stringlist
	var value, ok = type_any.backref.(*Type_stringlist)
	if ok {
		output = value
	}
	return output
}

func V_any_stringlist_cast(
	value *Type_stringlist) *Type_any {
	var output *Type_any = value.P_any
	return output
}

func A_stringlist_from_liststringn(
	liststringn []string) *Type_any {
	var type_stringlist *Type_stringlist = V_stringlist_from_liststringn(
		liststringn)
	var output *Type_any = type_stringlist.P_any
	return output
}

func V_stringlist_from_liststringn(
	liststringn []string) *Type_stringlist {
	var output *Type_stringlist = V_stringlist_create()
	var liststring []*Type_string
	for _, stringn := range liststringn {
		var type_string = V_string_cast_stringn(stringn)
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_stringlist
	type_generic.P_get_indexn_funcn = V_get_indexn_stringlist
	type_generic.P_listany_funcn = V_listany_stringlist
	t_variable.type_generic = type_generic
	return t_variable
}

// (type stringmap)
type Type_stringmap struct {
	P_any       *Type_any
	P_listkey   []string
	P_mapstring map[string]*Type_string
}

// V_stringmap_constructor
func V_stringmap_constructor() *Type_stringmap {
	var output *Type_stringmap = new(Type_stringmap)
	return output
}

// V_stringmap_create
func V_stringmap_create() *Type_stringmap {
	var output *Type_stringmap = V_stringmap_constructor()
	V_stringmap_initialize(
		output)
	return output
}

// V_stringmap_initialize
func V_stringmap_initialize(
	value *Type_stringmap) {
	value.P_any = V_any_from_type_backref(
		T_stringmap,
		value)
	value.P_listkey = []string{}
	value.P_mapstring = map[string]*Type_string{}
}

// V_stringmap_startup
func V_stringmap_startup() *Type_type {
	var t_variable = T_stringmap
	var e_variable = E_stringmap
	V_stringmap_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"stringmap",
		C_extends_map,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_stringmap
	type_generic.P_listkey_funcn = V_listkey_stringmap
	//	type_generic.P_code_funcn = V_code_stringmap
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_stringmap
func V_cast_stringmap(
	value *Type_stringmap) *Type_any {
	return value.P_any
}

// V_stringmap_cast
func V_stringmap_cast(
	type_any *Type_any) *Type_stringmap {
	var output *Type_stringmap = E_stringmap
	var value, ok = type_any.backref.(*Type_stringmap)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_stringmap(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_stringmap *Type_stringmap = V_stringmap_cast(
		type_any)
	var type_string *Type_string = V_string_from_stringmap_keyn(
		type_stringmap,
		keyn)
	var output *Type_any = E_any
	if type_string != E_string {
		output = V_cast_string(
			type_string)
	}
	return output
}

/*
func V_code_stringmap(
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
*/

func V_listkey_stringmap(
	type_any *Type_any) []string {
	var type_stringmap *Type_stringmap = V_stringmap_cast(
		type_any)
	var output []string = type_stringmap.P_listkey
	return output
}

func V_string_from_stringmap_keyn(
	type_stringmap *Type_stringmap,
	keyn string) *Type_string {
	var output = E_string
	var mapstring map[string]*Type_string = type_stringmap.P_mapstring
	var type_string, ok = mapstring[keyn]
	if ok {
		output = type_string
	}
	return output
}

func A_stringmap_from_liststringn(
	liststringn []string) *Type_any {
	var type_stringmap *Type_stringmap = V_stringmap_from_liststringn(
		liststringn)
	var output *Type_any = type_stringmap.P_any
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
			var type_string = V_string_cast_stringn(stringn)
			mapstring[key] = type_string
			key = ""
		}
	}
	if len(listkey) > 0 {
		output.P_listkey = listkey
		output.P_mapstring = mapstring
	}
	return output
}

type Type_struct struct {
	P_any *Type_any
}

// V_struct_constructor
func V_struct_constructor() *Type_struct {
	var output = new(Type_struct)
	return output
}

// V_struct_create
func V_struct_create() *Type_struct {
	var output = V_struct_constructor()
	V_struct_initialize(
		output)
	return output
}

// V_struct_initialize
func V_struct_initialize(
	value *Type_struct) {
	value.P_any = V_any_from_type_backref(
		T_struct,
		value)
}

// V_struct_startup
func V_struct_startup() *Type_type {
	var t_variable = T_struct
	var e_variable = E_struct
	V_struct_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"struct",
		C_extends_struct,
		e_variable.P_any)
	//t_variable.type_generic = new(Type_struct_generic)
	return t_variable
}

// Type_thenelse
type Type_thenelse struct {
	P_any  *Type_any
	P_code *Type_string
	P_if   *Type_any
	P_then *Type_any
}

func V_get_keyn_thenelse(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_thenelse = V_thenelse_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "code":
		output = value.P_code.P_any
	case "if":
		var p_if *Type_any = value.P_if
		output = p_if
	case "then":
		var p_then *Type_any = value.P_then
		output = p_then
	}
	return output
}

func V_code_thenelse(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

// V_else
func V_else(
	else_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = V_thenelse_create()
	output.P_code = V_string_cast_stringn(":else")
	output.P_then = else_any
	return output
}

// V_then_from_booleann
func V_then_from_booleann(
	booleann bool,
	then_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = V_thenelse_create()
	output.P_code = V_string_cast_stringn(":then")
	if booleann {
		output.P_if = C_true.P_any
	}
	output.P_then = then_any
	return output
}

// V_then_from_if_then
func V_then_from_if_then(
	if_any *Type_any,
	then_any *Type_any) *Type_thenelse {
	var output *Type_thenelse = V_thenelse_create()
	output.P_code = V_string_cast_stringn(":then")
	output.P_if = if_any
	output.P_then = then_any
	return output
}

// V_cast_thenelse
func V_cast_thenelse(
	value *Type_thenelse) *Type_any {
	var output *Type_any = E_any
	if value != E_thenelse {
		output = value.P_any
	}
	return output
}

// V_thenelse_cast
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
	value.P_any = V_any_from_type_backref(
		t_thenelse,
		value)
	value.P_if = C_false.P_any
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_thenelse
	type_generic.P_code_funcn = V_code_thenelse
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type("code", T_string),
			V_var_new_public_from_namen_type("if", T_any),
			V_var_new_public_from_namen_type("then", T_any)})
	return t_variable
}

// Type_thenelselist
type Type_thenelselist struct {
	P_any          *Type_any
	P_listthenelse []*Type_thenelse
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_thenelselist
	type_generic.P_get_indexn_funcn = V_get_indexn_thenelselist
	type_generic.P_listany_funcn = V_listany_thenelselist
	t_variable.type_generic = type_generic
	return t_variable
}

func V_get_indexn_thenelselist(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_thenelselist *Type_thenelselist = V_thenelselist_cast(
		type_any)
	var type_thenelse *Type_thenelse = V_thenelse_from_thenelselist_indexn(
		type_thenelselist,
		indexn)
	var output *Type_any = V_cast_thenelse(
		type_thenelse)
	return output
}

func V_code_thenelselist(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	return output
}

func V_listany_thenelselist(
	type_any *Type_any) []*Type_any {
	var type_thenelselist *Type_thenelselist = V_thenelselist_cast(
		type_any)
	var output []*Type_any = V_thenelselist_listany_from_listthenelse(
		type_thenelselist.P_listthenelse)
	return output
}

func V_thenelselist_listany_from_listthenelse(
	listthenelse []*Type_thenelse) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_thenelse := range listthenelse {
		output = append(output, type_thenelse.P_any)
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

func V_thenelse_from_thenelselist_indexn(
	type_thenelselist *Type_thenelselist,
	indexn int) *Type_thenelse {
	var listthenelse []*Type_thenelse = type_thenelselist.P_listthenelse
	var output *Type_thenelse = E_thenelse
	if indexn < len(listthenelse) {
		output = listthenelse[indexn+1]
	}
	return output
}

// V_cast_thenelselist
func V_cast_thenelselist(
	value *Type_thenelselist) *Type_any {
	var output *Type_any = value.P_any
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

// (type type)
type Type_type struct {
	type_generic   *Type_generic
	P_any          *Type_any
	P_path         string
	P_pkgname      string
	P_name         string
	P_alias        string
	P_idx          int
	P_extends      *Type_string
	P_empty        *Type_any
	P_propertylist *Type_varlist
	P_container    *Type_type
	P_allowtypes   *Type_typelist
	P_func         *Type_func
	P_isnative     bool
	P_prefix       string
}

// V_type_constructor
func V_type_constructor() *Type_type {
	var output *Type_type = new(Type_type)
	return output
}

// V_type_create
func V_type_create() *Type_type {
	var output *Type_type = V_type_constructor()
	V_type_initialize(
		output)
	return output
}

// V_type_initialize
func V_type_initialize(
	value *Type_type) {
	value.P_any = V_any_from_type_backref(
		T_type,
		value)
	value.type_generic = E_generic
	value.P_path = ""
	value.P_pkgname = ""
	value.P_name = ""
	value.P_alias = ""
	value.P_idx = 0
	value.P_extends = E_string
	value.P_empty = E_any
	value.P_propertylist = E_varlist
	value.P_container = E_type
	value.P_allowtypes = E_typelist
	value.P_func = E_func
	value.P_isnative = false
	value.P_prefix = ""
}

// V_type_shutdown
func V_type_shutdown(
	value *Type_type) {
	if value.type_generic != E_generic {
		V_generic_shutdown(
			value.type_generic)
		value.type_generic = E_generic
	}
	value.P_path = ""
	value.P_pkgname = ""
	value.P_name = ""
	value.P_alias = ""
	value.P_idx = 0
	if value.P_extends != E_string {
		V_release_any(
			V_cast_string(
				value.P_extends))
		value.P_extends = E_string
	}
	if value.P_empty != E_any {
		V_release_any(
			value.P_empty)
		value.P_empty = E_any
	}
	if value.P_propertylist != E_varlist {
		V_release_any(
			V_cast_varlist(
				value.P_propertylist))
		value.P_propertylist = E_varlist
	}
	value.P_container = E_type
	if value.P_allowtypes != E_typelist {
		V_release_any(
			V_cast_typelist(
				value.P_allowtypes))
		value.P_allowtypes = E_typelist
	}
	if value.P_func != E_func {
		V_release_any(
			V_cast_func(
				value.P_func))
		value.P_func = E_func
	}
	value.P_isnative = false
	V_any_shutdown(
		value.P_any)
	V_global_release()
	value.P_prefix = ""
}

// V_type_startup
func V_type_startup() *Type_type {
	var t_variable *Type_type = T_type
	var e_variable *Type_type = E_type
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"type",
		E_string,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_private_from_namen_type(
				"type-generic",
				T_generic),
			V_var_new_public_from_namen_type(
				"path",
				T_stringn),
			V_var_new_public_from_namen_type(
				"pkgname",
				T_stringn),
			V_var_new_public_from_namen_type(
				"name",
				T_stringn),
			V_var_new_public_from_namen_type(
				"alias",
				T_stringn),
			V_var_new_public_from_namen_type(
				"idx",
				T_intn),
			V_var_new_public_from_namen_type(
				"extends",
				T_string),
			V_var_new_public_from_namen_type(
				"empty",
				T_any),
			V_var_new_public_from_namen_type(
				"propertylist",
				T_varlist),
			V_var_new_public_from_namen_type(
				"container",
				T_type),
			V_var_new_public_from_namen_type(
				"allowtypes",
				T_typelist),
			V_var_new_public_from_namen_type(
				"func",
				T_func),
			V_var_new_public_from_namen_type(
				"isnative",
				T_booleann),
			V_var_new_public_from_namen_type(
				"prefix",
				T_stringn)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_code_funcn = V_code_type
	type_generic.P_copy_funcn = V_copy_type
	type_generic.P_new_funcn = V_new_type
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_type
func V_cast_type(
	value *Type_type) *Type_any {
	var output *Type_any = value.P_any
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

// V_type_copy
func V_type_copy(
	value *Type_type,
	type_anylist *Type_anylist) *Type_type {
	var output *Type_type = E_type
	return output
}

// V_copy_type
func V_copy_type(
	type_any *Type_any,
	type_anylist *Type_anylist) *Type_any {
	var value *Type_type = V_type_cast(
		type_any)
	var copy_value *Type_type = V_type_copy(
		value,
		type_anylist)
	var output *Type_any = V_cast_type(
		copy_value)
	return output
}

// V_type_new
func V_type_new(
	type_anylist *Type_anylist) *Type_type {
	var output *Type_type = V_type_copy(
		E_type,
		type_anylist)
	return output
}

// V_new_type
func V_new_type(
	type_anylist *Type_anylist) *Type_any {
	var value *Type_type = V_type_new(
		type_anylist)
	var output *Type_any = V_cast_type(
		value)
	return output
}

// V_empty
func V_empty(
	type_type *Type_type) *Type_any {
	var output *Type_any = type_type.P_empty
	return output
}

// F_type
func F_type(
	type_anylist *Type_anylist) *Type_type {
	var output *Type_type = V_type_new(
		type_anylist)
	return output
}

// V_code_type
func V_code_type(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var type_type *Type_type = V_type_cast(
		type_any)
	var type_lang *Type_lang = type_scope.P_lang
	var pkgnamen = V_code_pkgnamen(
		type_scope,
		V_pkgnamen_from_scope(
			type_scope))
	var typenamen = V_code_type_name(
		type_scope,
		type_type)
	switch type_lang {
	case C_lang_go:
		if pkgnamen == type_type.P_pkgname {
			pkgnamen = ""
		}
		output = pkgnamen + "T_" + typenamen
	default:
		output = pkgnamen + "t_" + typenamen
	}
	return output
}

func V_code_t_from_listtype(
	type_scope *Type_scope,
	indent int,
	path string,
	listtype []*Type_type) string {
	var listoutput []string
	for _, type_type := range listtype {
		var prop string = V_code_type_t_from_type(
			type_scope,
			indent,
			path,
			type_type)
		listoutput = append(listoutput, prop)
	}
	var output = V_stringn_from_liststringn(
		listoutput)
	return output
}

func V_code_type_t_from_type(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type *Type_type) string {
	var type_declare *Type_type_declare = V_type_declare_new_from_type_part(
		type_type,
		C_enum_t_type)
	var output string = V_code_type_declare(
		type_scope,
		indent,
		path,
		V_cast_type_declare(
			type_declare))
	return output
}

func V_type_new_from_pkgnamen_namen_extends_type_native(
	pkgnamen string,
	namen string,
	extends_string *Type_string,
	type_type *Type_type,
	isnativen bool) *Type_type {
	var t_variable *Type_type = V_type_create()
	var e_variable *Type_type = V_type_create()
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		pkgnamen,
		namen,
		extends_string,
		e_variable.P_any)
	if type_type != E_type {
		t_variable.P_container = type_type
		t_variable.P_allowtypes = V_typelist_from_listtype(
			[]*Type_type{
				type_type})
	}
	t_variable.P_isnative = isnativen
	return t_variable
}

func V_type_new_func_from_scope_namen(
	type_scope *Type_scope,
	namen string) *Type_type {
	var pkgnamen string = type_scope.P_package.P_path
	var t_variable *Type_type = V_type_create()
	var e_variable *Type_type = V_type_create()
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		pkgnamen,
		namen,
		C_extends_func,
		e_variable.P_any)
	var output *Type_type = t_variable
	return output
}

func V_type_new_func_from_scope_namen_return_varlist_value(
	type_scope *Type_scope,
	namen string,
	return_type *Type_type,
	type_varlist *Type_varlist,
	value_any *Type_any) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen(
		type_scope,
		namen)
	var type_func *Type_func = V_func_new_from_type_return_varlist_value(
		output,
		return_type,
		type_varlist,
		value_any)
	output.P_func = type_func
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
	type_type.P_any = V_any_from_type_backref(
		type_type,
		type_type)
	type_type.P_any.P_const = V_const_type(
		type_type)
	type_type.P_any.P_type = type_type
	type_type.P_empty = empty_any
	type_type.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_private_from_namen_type(
				"type-generic",
				T_generic),
			V_var_new_public_from_namen_type(
				"path",
				T_stringn),
			V_var_new_public_from_namen_type(
				"pkgname",
				T_stringn),
			V_var_new_public_from_namen_type(
				"name",
				T_stringn),
			V_var_new_public_from_namen_type(
				"alias",
				T_stringn),
			V_var_new_public_from_namen_type(
				"idx",
				T_intn),
			V_var_new_public_from_namen_type(
				"extends",
				T_string),
			V_var_new_public_from_namen_type(
				"empty",
				T_any),
			V_var_new_public_from_namen_type(
				"propertylist",
				T_varlist),
			V_var_new_public_from_namen_type(
				"container",
				T_type),
			V_var_new_public_from_namen_type(
				"allowtypes",
				T_typelist),
			V_var_new_public_from_namen_type(
				"func",
				T_func),
			V_var_new_public_from_namen_type(
				"isnative",
				T_booleann)})
	type_type.P_container = E_type
	type_type.P_allowtypes = E_typelist
	type_type.P_func = E_func
	type_type.P_isnative = false
	empty_any.P_const = V_const_empty(
		type_type)
}

// V_type_from_any
func V_type_from_any(
	type_any *Type_any) *Type_type {
	var output = type_any.P_type
	return output
}

// (type type-declare)
type Type_type_declare struct {
	P_any  *Type_any
	P_type *Type_type
	P_part *Type_enum
}

// V_type_declare_constructor
func V_type_declare_constructor() *Type_type_declare {
	var output = new(Type_type_declare)
	return output
}

// V_type_declare_create
func V_type_declare_create() *Type_type_declare {
	var output = V_type_declare_constructor()
	V_type_declare_initialize(output)
	return output
}

// V_type_declare_initialize
func V_type_declare_initialize(
	value *Type_type_declare) {
	value.P_any = V_any_from_type_backref(
		T_type_declare,
		value)
	value.P_type = E_type
	value.P_part = E_enum
}

// V_type_declare_startup
func V_type_declare_startup() *Type_type {
	var t_variable = T_type_declare
	var e_variable = E_type_declare
	V_type_declare_initialize(e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-declare",
		C_extends_struct,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_type_declare
	type_generic.P_code_funcn = V_code_type_declare
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"type",
				T_type),
			V_var_new_public_from_namen_type(
				"part",
				T_string)})
	return t_variable
}

// V_cast_type_declare
func V_cast_type_declare(
	value *Type_type_declare) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_type_declare_cast
func V_type_declare_cast(
	type_any *Type_any) *Type_type_declare {
	var output = E_type_declare
	var value, ok = type_any.backref.(*Type_type_declare)
	if ok {
		output = value
	}
	return output
}

func V_code_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_type_declare *Type_type_declare = V_type_declare_cast(
		type_any)
	var output string = V_code_from_type_declare(
		type_scope,
		indent,
		path,
		type_type_declare)
	return output
}

func code_type_declare_from_type(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type *Type_type) string {
	var subpath string = path + "/code-type-declare<-type"
	var output string = V_code_from_type_declare(
		type_scope,
		indent,
		subpath,
		V_type_declare_new_from_type(
			type_type))
	return output
}

func V_code_from_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type_declare *Type_type_declare) string {
	var type_lang *Type_lang = type_scope.P_lang
	var p_part *Type_enum = type_type_declare.P_part
	var p_type *Type_type = type_type_declare.P_type
	var langindent int = indent
	var subpath string = path + "/code-type-declare/" + p_type.P_name
	switch type_lang {
	case C_lang_go:
		langindent = 0
	case C_lang_swift:
		langindent = 1
	}
	var sub_type *Type_type = nil
	var listtype []*Type_type = []*Type_type{}
	switch p_part {
	case E_enum:
		var liststandard []*Type_type = []*Type_type{
			V_t_x_struct(
				type_scope,
				p_type),
			V_t_x_constructor(
				type_scope,
				p_type),
			V_t_x_create(
				type_scope,
				p_type),
			V_t_x_initialize(
				type_scope,
				p_type),
			V_t_x_shutdown(
				type_scope,
				p_type),
			V_t_x_startup(
				type_scope,
				p_type)}
		listtype = append(listtype, liststandard...)
		var listcustom []*Type_type = V_listtype_custom_from_type_declare(
			type_scope,
			langindent,
			path,
			type_type_declare)
		if len(listcustom) > 0 {
			listtype = append(listtype, listcustom...)
		}
	case C_enum_constructor:
		sub_type = V_t_x_constructor(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	case C_enum_create:
		sub_type = V_t_x_create(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	case C_enum_custom:
		var listcustom []*Type_type = V_listtype_custom_from_type_declare(
			type_scope,
			langindent,
			path,
			type_type_declare)
		if len(listcustom) > 0 {
			listtype = append(listtype, listcustom...)
		}
	case C_enum_e_type:
		switch p_type {
		case T_boolean:
		default:
			sub_type = V_t_e_x(
				type_scope,
				p_type)
			listtype = append(listtype, sub_type)
		}
	case C_enum_initialize:
		sub_type = V_t_x_initialize(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	case C_enum_shutdown:
		sub_type = V_t_x_shutdown(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	case C_enum_startup:
		sub_type = V_t_x_startup(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	case C_enum_struct:
		sub_type = V_t_x_struct(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	case C_enum_t_type:
		sub_type = V_t_t_x(
			type_scope,
			p_type)
		listtype = append(listtype, sub_type)
	default:
		println(p_part)
	}
	var output string = V_code_from_listtype_type_declare(
		type_scope,
		langindent,
		subpath,
		listtype)
	return output
}

func V_code_struct_listvar_from_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type *Type_type) string {
	var listvar []*Type_var = []*Type_var{}
	switch type_type {
	case T_any:
	default:
		var any_var = V_var_new_public_from_namen_type(
			"any", T_any)
		listvar = append(listvar, any_var)
	}
	var origlistvar []*Type_var = type_type.P_propertylist.P_listvar
	listvar = append(listvar, origlistvar...)
	var type_lang *Type_lang = type_scope.P_lang
	var lineindent = V_code_lineindent(
		type_scope,
		indent)
	var maxlen int = 0
	switch type_lang {
	case C_lang_go:
		for _, type_var := range listvar {
			var varname = V_code_var_name(
				type_scope,
				type_var)
			if len(varname) > maxlen {
				maxlen = len(varname)
			}
		}
	}
	var prop = ""
	var listoutput []string = []string{}
	for _, type_var := range listvar {
		var var_type = type_var.P_type
		var varname = V_code_var_name(
			type_scope,
			type_var)
		var vartype = V_code_type_typename(
			type_scope,
			var_type)
		switch type_lang {
		case C_lang_go:
			var outdent string = ""
			if varname == "backref" {
				vartype = "any"
			}
			if len(varname) < maxlen {
				outdent = V_stringn_from_stringn_repeatn(
					" ",
					maxlen-len(varname))
			}
			prop = lineindent + varname + outdent + " " + vartype
		case C_lang_swift:
			switch var_type {
			case T_any:
				if varname == "backref" {
					vartype = "AnyObject?"
				} else {
					vartype += "!"
				}
			case T_booleann, T_floatn, T_intn, T_stringn:
			case T_get_keyn_funcn, T_get_indexn_funcn, T_cast_funcn, T_code_funcn, T_copy_funcn, T_func_funcn, T_count_funcn, T_listany_funcn, T_listkeyn_funcn, T_mapany_funcn, T_new_funcn, T_set_keyn_funcn, T_set_indexn_funcn, T_shutdown_funcn:
			default:
				vartype += "!"
			}
			prop = lineindent + "var " + varname + " : " + vartype
		default:
			prop = lineindent + "public var " + varname + " : " + vartype
		}
		listoutput = append(listoutput, prop)
	}
	var output = V_stringn_from_liststringn_joinn(
		listoutput,
		"")
	return output
}

func V_code_from_type_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type *Type_type) string {
	var output string = ""
	var type_lang *Type_lang = type_scope.P_lang
	switch type_type.P_name {
	case "e-type":
		var lineindent = V_code_lineindent(
			type_scope,
			indent)
		var p_func *Type_func = type_type.P_func
		var p_type *Type_type = p_func.P_return
		var typenamen string = V_code_type_name(
			type_scope,
			p_type)
		var t_typenamen string = V_code_type_typename(
			type_scope,
			p_type)
		var pkgname string = V_code_type_pkgname(
			type_scope,
			T_type)
		switch type_lang {
		case C_lang_go:
			output = lineindent +
				"var E_" +
				typenamen +
				" " +
				t_typenamen +
				" = V_" +
				typenamen +
				"_constructor()"
		case C_lang_swift:
			output = lineindent +
				"public static let e_" +
				typenamen +
				" : " +
				t_typenamen +
				" = " +
				pkgname +
				"v_" +
				typenamen +
				"_constructor()"
		default:
			output = lineindent +
				"public static let e_" +
				typenamen +
				" : " +
				t_typenamen +
				" = " +
				pkgname +
				"v_" +
				typenamen +
				"_constructor()"
		}
	case "t-type":
		var lineindent = V_code_lineindent(
			type_scope,
			indent)
		var p_func *Type_func = type_type.P_func
		var p_type *Type_type = p_func.P_return
		var typenamen string = V_code_type_name(
			type_scope,
			p_type)
		var type_typenamen string = V_code_type_name(
			type_scope,
			T_type)
		var t_typenamen string = V_code_type_typename(
			type_scope,
			T_type)
		var pkgname string = V_code_type_pkgname(
			type_scope,
			T_type)
		switch type_lang {
		case C_lang_go:
			output = lineindent +
				"var T_" +
				typenamen +
				" " +
				t_typenamen +
				" = " +
				pkgname +
				"V_" +
				type_typenamen +
				"_constructor()"
		case C_lang_swift:
			var pkgname string = V_code_type_pkgname(
				type_scope,
				T_type)
			output = lineindent +
				"public static let t_" +
				typenamen +
				" : " +
				t_typenamen +
				" = " +
				pkgname +
				"v_" +
				type_typenamen +
				"_constructor()"
		default:
			output = lineindent +
				"public static let t_" +
				typenamen +
				" : " +
				t_typenamen +
				" = " +
				pkgname +
				"v_" +
				typenamen + "_constructor()"
		}
	case "type-t-struct":
		var type_func *Type_func = type_type.P_func
		var type_varlist *Type_varlist = type_func.P_arglist
		var type_var *Type_var = V_var_from_varlist_indexn(
			type_varlist,
			1)
		var sub_type *Type_type = type_var.P_type
		output = V_code_struct_from_type_type_declare(
			type_scope,
			indent,
			path,
			sub_type)
	default:
		var func_declare *Type_func_declare = V_func_declare(
			type_type)
		output = V_code_from_func_declare(
			type_scope,
			indent,
			path,
			func_declare)
	}
	return output
}

func V_code_from_listtype_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	listtype []*Type_type) string {
	var listprop []string = []string{}
	var subpath string = path + "/code<-listtype-type-declare"
	for _, type_type := range listtype {
		var prop string = V_code_from_type_type_declare(
			type_scope,
			indent,
			subpath,
			type_type)
		listprop = append(listprop, prop)
	}
	var output string = V_stringn_from_liststringn_joinn(
		listprop,
		"")
	return output
}

func V_listtype_custom_from_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type_declare *Type_type_declare) []*Type_type {
	var output []*Type_type = []*Type_type{}
	var type_type = type_type_declare.P_type
	var sub_type *Type_type = E_type
	switch type_type {
	case T_any:
		sub_type = V_t_any_from_type_backref(
			type_scope)
		output = append(output, sub_type)
	}
	sub_type = V_t_x_cast_x(
		type_scope,
		T_any,
		type_type)
	output = append(output, sub_type)
	switch type_type {
	case T_any:
	default:
		sub_type = V_t_x_cast_x(
			type_scope,
			type_type,
			T_any)
		output = append(output, sub_type)
	}
	switch type_type {
	case T_any:
	default:
		sub_type = V_t_x_copy(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	sub_type = V_t_copy_x(
		type_scope,
		type_type)
	output = append(output, sub_type)
	switch type_type {
	case T_any:
		sub_type = V_t_count_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	switch type_type {
	case T_any, T_type:
		sub_type = V_t_empty_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	switch type_type {
	case T_any:
		sub_type = V_t_get_keyn_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	switch type_type {
	case T_any:
		sub_type = V_t_get_indexn_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	if type_type == T_any || type_type.P_extends == C_extends_list {
		sub_type = V_t_listany_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	if type_type == T_any || type_type.P_extends == C_extends_map || type_type.P_extends == C_extends_struct {
		sub_type = V_t_listkey_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
		sub_type = V_t_mapany_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	switch type_type {
	case T_any:
	default:
		sub_type = V_t_x_new(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	sub_type = V_t_new_x(
		type_scope,
		type_type)
	output = append(output, sub_type)
	switch type_type {
	case T_any:
		sub_type = V_t_release_any(
			type_scope)
		output = append(output, sub_type)
	}
	switch type_type {
	case T_any:
		sub_type = V_t_shutdown_x(
			type_scope,
			type_type)
		output = append(output, sub_type)
	}
	sub_type = V_t_f_x(
		type_scope,
		type_type)
	output = append(output, sub_type)
	return output
}

func V_code_struct_from_type_type_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_type *Type_type) string {
	var output = ""
	var type_lang *Type_lang = type_scope.P_lang
	var typenamen = V_code_type_name(
		type_scope,
		type_type)
	var lineindent = V_code_lineindent(
		type_scope,
		indent)
	var code_listvar string = V_code_struct_listvar_from_type_declare(
		type_scope,
		indent+1,
		path,
		type_type)
	var typedeclares string = ""
	switch type_lang {
	case C_lang_go:
		switch type_type {
		case T_generic:
			typedeclares = "" +
				lineindent + "type Type_cast_funcn func(type_type *Type_type, type_any *Type_any) *Type_any" +
				lineindent + "type Type_code_funcn func(type_scope *Type_scope, indent int, path string, type_any *Type_any) string" +
				lineindent + "type Type_copy_funcn func(type_any *Type_any, type_anylist *Type_anylist) *Type_any" +
				lineindent + "type Type_count_funcn func(type_any *Type_any) int" +
				lineindent + "type Type_func_funcn func(type_type *Type_type) *Type_func" +
				lineindent + "type Type_get_keyn_funcn func(type_any *Type_any, keyn string) *Type_any" +
				lineindent + "type Type_get_indexn_funcn func(type_any *Type_any, indexn int) *Type_any" +
				lineindent + "type Type_listany_funcn func(type_any *Type_any) []*Type_any" +
				lineindent + "type Type_listkey_funcn func(type_any *Type_any) []string" +
				lineindent + "type Type_mapany_funcn func(type_any *Type_any) map[string]*Type_any" +
				lineindent + "type Type_new_funcn func(type_anylist *Type_anylist) *Type_any" +
				lineindent + "type Type_set_keyn_funcn func(type_any *Type_any, keyn string, value *Type_any)" +
				lineindent + "type Type_set_indexn_funcn func(type_any *Type_any, indexn int, value *Type_any)" +
				lineindent + "type Type_shutdown_funcn func(type_any *Type_any)" +
				"\n"
		}
		output = "" +
			typedeclares +
			lineindent + "// (type " + typenamen + ")" +
			lineindent + "type Type_" + typenamen + " struct {" +
			code_listvar +
			lineindent + "}" +
			"\n"
	case C_lang_swift:
		switch type_type {
		case T_generic:
			typedeclares = "" +
				lineindent + "typealias Type_cast_funcn = func (_ type_type : Vx_Core.Type_type, _ type_any : Vx_Core.Type_any) -> Vx_Core.Type_any" +
				lineindent + "typealias Type_code_funcn : func (_ type_scope : Vx_Core.Type_scope, _ indent : Int, _ path : String, _ type_any : Vx_Core.Type_any) -> String" +
				lineindent + "typealias Type_copy_funcn : func (_ type_any : Vx_Core.Type_any, _ type_anylist : Vx_Core.Type_anylist) -> Vx_Core.Type_any" +
				lineindent + "typealias Type_count_funcn : func (_ type_any : Vx_Core.Type_any) -> Int" +
				lineindent + "typealias Type_func_funcn : func (_ type_type : Vx_Core.Type_type) -> Vx_Core.Type_func" +
				lineindent + "typealias Type_get_keyn_funcn : func (_ type_any : Vx_Core.Type_any, _ keyn : String) -> Vx_Core.Type_any" +
				lineindent + "typealias Type_get_indexn_funcn : func (_ type_any : Vx_Core.Type_any, _ indexn : Int) -> Vx_Core.Type_any" +
				lineindent + "typealias Type_listany_funcn : func (_ type_any : Vx_Core.Type_any) -> [Vx_Core.Type_any]" +
				lineindent + "typealias Type_listkey_funcn : func (_ type_any : Vx_Core.Type_any) -> [String]" +
				lineindent + "typealias Type_mapany_funcn : func (_ type_any : Vx_Core.Type_any) -> [String:Vx_Core.Type_any]" +
				lineindent + "typealias Type_new_funcn : func (_ type_anylist : Vx_Core.Type_anylist) -> Vx_Core.Type_any" +
				lineindent + "typealias Type_set_keyn_funcn : func (_ type_any : Vx_Core.Type_any, _ keyn : String, _ value : Vx_Core.Type_any)" +
				lineindent + "typealias Type_set_indexn_funcn : func (_ type_any : Vx_Core.Type_any, _ indexn : Int, _ value : Vx_Core.Type_any)" +
				lineindent + "typealias Type_shutdown_funcn : func (_ type_any : Vx_Core.Type_any)" +
				"\n"
		}
		output = "" +
			typedeclares +
			lineindent + "// (type " + typenamen + ")" +
			lineindent + "public class Type_" + typenamen + " {" +
			code_listvar +
			lineindent + "  public init() {}" +
			lineindent + "}" +
			"\n"
	}
	return output
}

func V_t_x_cast_x(
	type_scope *Type_scope,
	output_type *Type_type,
	input_type *Type_type) *Type_type {
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		output_type)
	var varnamen string = "value"
	switch input_type {
	case T_any:
		varnamen = "type-any"
		if output_type != T_any {
			output_var.P_mutable = C_true
		}
	}
	var value_var *Type_var = V_var_new_from_namen_type(
		varnamen,
		input_type)
	var type_varlist *Type_varlist = V_varlist_from_listvar(
		[]*Type_var{
			value_var})
	var value *Type_any = E_any
	if output_type == T_any && input_type == T_any {
		var type_var *Type_var = V_var_new_from_namen_type(
			"type-type",
			T_type)
		var any_var *Type_var = V_var_new_from_namen_type(
			"type-any",
			input_type)
		type_varlist = V_varlist_from_listvar(
			[]*Type_var{
				type_var,
				any_var})
		var t_x_generic *Type_type = V_t_x_generic(
			type_scope,
			T_cast_funcn)
		var t_generic_from_type *Type_type = V_t_generic_from_type(
			type_scope)
		var generic_var *Type_var = V_var_new_from_namen_type(
			"type-generic",
			T_generic)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					generic_var,
					A_func_call(
						t_generic_from_type,
						V_anylist_from_any(
							type_var.P_any))),
				A_var_declare(
					output_var,
					A_func_call(
						t_x_generic,
						V_anylist_from_listany(
							[]*Type_any{
								generic_var.P_any,
								type_var.P_any,
								any_var.P_any})))})
	} else if output_type == T_any {
		value = A_var_declare(
			output_var,
			A_var_propertyn(
				value_var,
				"any"))
	} else if input_type == T_any {
		value = A_anylist_run_from_listany(
			[]*Type_any{
				A_var_declare(
					output_var,
					E_any),
				A_var_set_operatorn(
					output_var,
					"backref",
					V_cast_type(
						input_type))})
	} else if output_type == T_string && input_type == T_stringn {
	} else if output_type == T_stringn && input_type == T_string {
	}
	var typenamen string = ""
	if output_type == T_any {
		typenamen = "cast-" +
			input_type.P_name
	} else if input_type == T_any {
		typenamen = output_type.P_name +
			"-cast"
	} else {
		typenamen = output_type.P_name +
			"-cast-" +
			input_type.P_name
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen,
		output_type,
		type_varlist,
		value)
	return output
}

func V_t_p_cast_funcn(
	type_scope *Type_scope) *Type_type {
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_type)
	var any_var *Type_var = V_var_new_from_namen_type(
		"type-any",
		T_any)
	var value *Type_any = E_any
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"p-cast-funcn",
		T_any,
		V_varlist_from_listvar(
			[]*Type_var{
				type_var,
				any_var}),
		value)
	return output
}

func V_t_x_generic(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var typenamen string = ""
	var output_type *Type_type = E_type
	var generic_var *Type_var = V_var_new_from_namen_type(
		"type-generic",
		T_generic)
	var type_var *Type_var = E_var
	var any_var *Type_var = E_var
	var anylist_var *Type_var = E_var
	var keyn_var *Type_var = E_var
	var indexn_var *Type_var = E_var
	var value_var *Type_var = E_var
	switch type_type {
	case T_cast_funcn, T_new_funcn:
		type_var = V_var_new_from_namen_type(
			"type-type",
			T_type)
	}
	switch type_type {
	case T_cast_funcn, T_copy_funcn, T_count_funcn, T_get_keyn_funcn, T_get_indexn_funcn, T_listany_funcn, T_listkeyn_funcn, T_mapany_funcn, T_set_keyn_funcn, T_set_indexn_funcn:
		any_var = V_var_new_from_namen_type(
			"type-any",
			T_any)
	}
	switch type_type {
	case T_copy_funcn, T_new_funcn:
		anylist_var = V_var_new_from_namen_type(
			"type-anylist",
			T_anylist)
	}
	switch type_type {
	case T_get_keyn_funcn, T_set_keyn_funcn:
		keyn_var = V_var_new_from_namen_type(
			"keyn",
			T_stringn)
	}
	switch type_type {
	case T_get_indexn_funcn, T_set_indexn_funcn:
		indexn_var = V_var_new_from_namen_type(
			"indexn",
			T_intn)
	}
	switch type_type {
	case T_set_keyn_funcn, T_set_indexn_funcn:
		value_var = V_var_new_from_namen_type(
			"value",
			T_any)
	}
	var value *Type_any = E_any
	var listvar []*Type_var = []*Type_var{}
	listvar = append(listvar, generic_var)
	switch type_type {
	case T_cast_funcn:
		typenamen = "cast-generic"
		output_type = T_any
		listvar = append(listvar, type_var)
		listvar = append(listvar, any_var)
	case T_copy_funcn:
		typenamen = "copy-generic"
		output_type = T_any
		listvar = append(listvar, any_var)
		listvar = append(listvar, anylist_var)
	case T_count_funcn:
		typenamen = "count-generic"
		output_type = T_intn
		listvar = append(listvar, any_var)
	case T_get_keyn_funcn:
		typenamen = "get-keyn-generic"
		output_type = T_any
		listvar = append(listvar, any_var)
		listvar = append(listvar, keyn_var)
	case T_get_indexn_funcn:
		typenamen = "get-indexn-generic"
		output_type = T_any
		listvar = append(listvar, any_var)
		listvar = append(listvar, indexn_var)
	case T_listany_funcn:
		typenamen = "listany-generic"
		output_type = V_type_new_from_pkgnamen_namen_extends_type_native(
			"",
			"listany",
			C_extends_list,
			T_any,
			true)
		listvar = append(listvar, any_var)
	case T_listkeyn_funcn:
		typenamen = "listkey-generic"
		output_type = V_type_new_from_pkgnamen_namen_extends_type_native(
			"",
			"listkey",
			C_extends_list,
			T_string,
			true)
		listvar = append(listvar, any_var)
	case T_mapany_funcn:
		typenamen = "mapany-generic"
		output_type = V_type_new_from_pkgnamen_namen_extends_type_native(
			"",
			"mapany",
			C_extends_map,
			T_any,
			true)
		listvar = append(listvar, any_var)
	case T_new_funcn:
		typenamen = "new-generic"
		output_type = T_any
		listvar = append(listvar, type_var)
		listvar = append(listvar, anylist_var)
	case T_set_keyn_funcn:
		typenamen = "set-keyn-generic"
		listvar = append(listvar, any_var)
		listvar = append(listvar, keyn_var)
		listvar = append(listvar, value_var)
	case T_set_indexn_funcn:
		typenamen = "set-indexn-generic"
		listvar = append(listvar, any_var)
		listvar = append(listvar, indexn_var)
		listvar = append(listvar, value_var)
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen,
		output_type,
		V_varlist_from_listvar(
			listvar),
		value)
	return output
}

func V_t_any_from_type_backref(
	type_scope *Type_scope) *Type_type {
	var output *Type_type = T_any_from_type_backref
	if output == nil {
		output = V_type_new_func_from_scope_namen(
			type_scope,
			"any<-type-backref",
		)
		T_any_from_type_backref = output
		var t_any_create *Type_type = V_t_x_create(
			type_scope,
			T_any)
		var type_var *Type_var = V_var_new_from_namen_type(
			"type-type",
			T_type)
		var backref_var *Type_var = V_var_new_from_namen_type(
			"backref",
			T_any)
		var output_var *Type_var = V_var_new_mutable_from_namen_type(
			"output",
			T_any)
		var value *Type_any = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					output_var,
					A_func_call(
						t_any_create,
						E_anylist)),
				A_var_set_propertyn(
					output_var,
					"type",
					V_cast_var(
						type_var)),
				A_var_set_propertyn(
					output_var,
					"backref",
					V_cast_var(
						backref_var))})
		var type_func *Type_func = V_func_new_from_type_return_varlist_value(
			output,
			T_any,
			V_varlist_from_listvar(
				[]*Type_var{
					type_var,
					backref_var}),
			value)
		output.P_func = type_func
	}
	return output
}

func V_t_e_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"e-type",
		type_type,
		E_varlist,
		E_any)
	return output
}

func V_t_empty_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var typenamen string = ""
	var value *Type_any = E_any
	var listvar []*Type_var = []*Type_var{}
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		T_any)
	var type_var *Type_var = V_var_new_from_namen_type(
		"type-type",
		T_type)
	switch type_type {
	case T_any:
		typenamen = "empty<-any"
		var any_var *Type_var = V_var_new_from_namen_type(
			"type-any",
			T_any)
		listvar = append(listvar, any_var)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_declare(
					type_var,
					A_var_propertyn(
						any_var,
						"type")),
				A_var_declare(
					output_var,
					A_var_propertyn(
						type_var,
						"empty"))})
	case T_type:
		typenamen = "empty"
		listvar = append(listvar, type_var)
		value = A_var_declare(
			output_var,
			A_var_propertyn(
				type_var,
				"empty"))
	}
	var varlist *Type_varlist = V_varlist_from_listvar(
		listvar)
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		typenamen,
		T_any,
		varlist,
		value)
	return output
}

func V_t_t_x(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"t-type",
		type_type,
		E_varlist,
		E_any)
	return output
}

func V_t_type_t_startup(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"type-t-startup",
		T_empty,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"type-type",
					T_type),
				V_var_new_from_namen_type(
					"pkgname",
					T_stringn),
				V_var_new_from_namen_type(
					"name",
					T_stringn),
				V_var_new_from_namen_type(
					"extends",
					T_string),
				V_var_new_from_namen_type(
					"empty-any",
					T_any)}),
		E_any)
	return output
}

func V_t_x_constructor(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var type_lang *Type_lang = type_scope.P_lang
	var output_var *Type_var = V_var_new_from_namen_type(
		"output",
		type_type)
	var t_global_reserve = V_t_global_reserve(
		type_scope)
	var value *Type_any = A_anylist_from_listany(
		[]*Type_any{
			A_if_run_from_type_booleann_then(
				T_any,
				type_lang.P_isrefcount,
				A_func_call(
					t_global_reserve,
					E_anylist)),
			A_var_declare(
				output_var,
				V_cast_enum(
					C_enum_new))})
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		type_type.P_name+"-constructor",
		type_type,
		E_varlist,
		value)
	return output
}

func V_t_x_create(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var t_x_constructor = V_t_x_constructor(
		type_scope,
		type_type)
	var t_x_initialize = V_t_x_initialize(
		type_scope,
		type_type)
	var output_var = V_var_new_mutable_from_namen_type(
		"output",
		type_type)
	var value *Type_any = A_anylist_from_listany(
		[]*Type_any{
			A_var_declare(
				output_var,
				A_func_call(
					t_x_constructor,
					E_anylist)),
			A_func_call(
				t_x_initialize,
				V_anylist_from_listany(
					[]*Type_any{
						V_cast_var(
							output_var)}))})
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		type_type.P_alias+"-create",
		type_type,
		E_varlist,
		value)
	return output
}

func V_t_x_initialize(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var t_any_from_type_backref *Type_type = V_t_any_from_type_backref(
		type_scope)
	var value_var *Type_var = V_var_new_from_namen_type(
		"value",
		type_type)
	var listany []*Type_any = []*Type_any{}
	var type_any *Type_any = E_any
	switch type_type {
	case T_any:
		type_any = A_var_set_propertyn(
			value_var,
			"type",
			V_cast_type(
				type_type))
		listany = append(listany, type_any)
		type_any = A_var_set_propertyn(
			value_var,
			"backref",
			V_cast_var(
				value_var))
		listany = append(listany, type_any)
	default:
		switch type_type {
		default:
			type_any = A_var_set_propertyn(
				value_var,
				"any",
				A_func_call(
					t_any_from_type_backref,
					V_anylist_from_listany(
						[]*Type_any{
							V_cast_type(
								type_type),
							V_cast_var(
								value_var)})))
		}
		listany = append(listany, type_any)
		var p_propertylist *Type_varlist = type_type.P_propertylist
		var listproperty []*Type_var = p_propertylist.P_listvar
		for _, type_var := range listproperty {
			var var_type *Type_type = type_var.P_type
			var propertyn string = V_code_var_name(
				type_scope,
				type_var)
			type_any = A_var_set_propertyn(
				value_var,
				propertyn,
				V_empty(
					var_type))
			listany = append(listany, type_any)
		}
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		type_type.P_name+"-initialize",
		E_type,
		V_varlist_from_listvar(
			[]*Type_var{
				value_var}),
		A_anylist_from_listany(
			listany))
	return output
}

func V_t_x_shutdown(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var value *Type_any = E_any
	var value_var *Type_var = V_var_new_mutable_from_namen_type(
		"value",
		type_type)
	var t_global_release *Type_type = V_t_global_release(
		type_scope)
	var t_release_any *Type_type = V_t_release_any(
		type_scope)
	switch type_type {
	case T_any:
		var msgblock_var = V_var_new_from_namen_type(
			"type-msgblock",
			T_msgblock)
		var const_var = V_var_new_from_namen_type(
			"type-const",
			T_const)
		value = A_anylist_from_listany(
			[]*Type_any{
				A_var_set_propertyn(
					value_var,
					"backref",
					V_cast_type(
						E_type)),
				A_var_declare(
					msgblock_var,
					A_var_propertyn(
						value_var,
						"msgblock")),
				A_if_from_if_then(
					A_noteqeq(
						V_cast_var(
							msgblock_var),
						V_cast_msgblock(
							E_msgblock)),
					A_anylist_run_from_listany(
						[]*Type_any{
							A_var_set_propertyn(
								value_var,
								"msgblock",
								V_cast_msgblock(
									E_msgblock)),
							A_func_call(
								t_release_any,
								V_anylist_run_from_any(
									A_var_propertyn(
										msgblock_var,
										"type_any")))})),
				A_var_declare(
					const_var,
					A_var_propertyn(
						value_var,
						"const")),
				A_if_from_if_then(
					A_noteqeq(
						V_cast_var(
							const_var),
						V_cast_const(
							E_const)),
					A_anylist_run_from_listany(
						[]*Type_any{
							A_var_set_propertyn(
								value_var,
								"const",
								V_cast_const(
									E_const)),
							A_func_call_any(
								t_release_any,
								A_var_propertyn(
									const_var,
									"type_any"))})),
				A_var_set_propertyn(
					value_var,
					"type",
					V_cast_type(
						E_type)),
				A_func_call(
					t_global_release,
					E_anylist)})
	default:
		var listany []*Type_any = []*Type_any{}
		var propertylist *Type_varlist = type_type.P_propertylist
		var listproperty []*Type_var = propertylist.P_listvar
		var sub_any *Type_any = E_any
		for _, property_var := range listproperty {
			var property_type = property_var.P_type
			var propertyname string = V_stringn_cast_string(
				property_var.P_name)
			switch property_type {
			case T_booleann, T_floatn, T_intn, T_stringn, T_type:
				sub_any = A_var_set_propertyn(
					value_var,
					propertyname,
					V_empty(
						property_type))
				listany = append(listany, sub_any)
			case T_generic:
				var t_generic_shutdown *Type_type = V_t_x_shutdown(
					type_scope,
					T_generic)
				sub_any = A_if_from_if_then(
					A_noteqeq(
						A_var_propertyn(
							value_var,
							"type-generic"),
						V_empty(
							property_type)),
					A_anylist_run_from_listany(
						[]*Type_any{
							A_func_call_any(
								t_generic_shutdown,
								A_var_propertyn(
									value_var,
									"type-generic")),
							A_var_set_propertyn(
								value_var,
								propertyname,
								V_empty(
									property_type))}))
				listany = append(listany, sub_any)
			default:
				var t_any_cast_x *Type_type = V_t_x_cast_x(
					type_scope,
					T_any,
					property_type)
				var release_any *Type_any = A_var_propertyn(
					value_var,
					propertyname)
				switch property_type {
				case T_any:
				default:
					release_any = A_func_call_any(
						t_any_cast_x,
						release_any)
				}
				sub_any = A_if_from_if_then(
					A_noteqeq(
						A_var_propertyn(
							value_var,
							propertyname),
						V_empty(
							property_type)),
					A_anylist_run_from_listany(
						[]*Type_any{
							A_func_call_any(
								t_release_any,
								release_any),
							A_var_set_propertyn(
								value_var,
								propertyname,
								V_empty(
									property_type))}))
				listany = append(listany, sub_any)
			}
		}
		var t_any_shutdown *Type_type = V_t_x_shutdown(
			type_scope,
			T_any)
		sub_any = A_func_call_any(
			t_any_shutdown,
			A_var_propertyn(
				value_var,
				"any"))
		listany = append(listany, sub_any)
		sub_any = A_func_call(
			t_global_release,
			E_anylist)
		listany = append(listany, sub_any)
		value = A_anylist_from_listany(
			listany)
	}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		type_type.P_name+"-shutdown",
		E_type,
		V_varlist_from_listvar(
			[]*Type_var{
				value_var}),
		value)
	return output
}

func V_t_x_startup(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var type_lang *Type_lang = type_scope.P_lang
	var output_var = V_var_new_from_namen_type(
		"output",
		T_type)
	var t_variable_var = V_var_new_mutable_from_namen_type(
		"t-variable",
		T_type)
	var e_variable_var = V_var_new_mutable_from_namen_type(
		"e-variable",
		type_type)
	var t_x_initialize *Type_type = V_t_x_initialize(
		type_scope,
		type_type)
	var t_type_t_startup *Type_type = V_t_type_t_startup(
		type_scope,
		type_type)
	var t_varlist_from_listvar *Type_type = V_varlist_t_varlist_from_listvar(
		type_scope,
		type_type)
	var t_var_new_private_from_namen_type *Type_type = V_t_var_new_private_from_namen_type(
		type_scope,
		type_type)
	var t_var_new_public_from_namen_type *Type_type = V_t_var_new_public_from_namen_type(
		type_scope,
		type_type)
	var type_propertylist *Type_varlist = type_type.P_propertylist
	var listproperty_listvar []*Type_var = type_propertylist.P_listvar
	var listproperty_listany []*Type_any = []*Type_any{}
	var property_any *Type_any = E_any
	for _, property_var := range listproperty_listvar {
		var name_any *Type_any = V_cast_string(
			property_var.P_name)
		var type_any *Type_any = V_cast_type(
			property_var.P_type)
		var t_var_from_namen_type *Type_type = t_var_new_public_from_namen_type
		if property_var.P_private == C_true {
			t_var_from_namen_type = t_var_new_private_from_namen_type
		}
		property_any = A_func_call(
			t_var_from_namen_type,
			V_anylist_from_listany(
				[]*Type_any{
					name_any,
					type_any}))
		listproperty_listany = append(listproperty_listany, property_any)
	}
	var e_variable_any *Type_any = E_any
	switch type_type {
	case T_any:
		e_variable_any = V_cast_var(
			e_variable_var)
	default:
		e_variable_any = A_var_propertyn(
			e_variable_var,
			"any")
	}
	var listany []*Type_any = []*Type_any{
		A_var_declare(
			t_variable_var,
			V_cast_type(
				type_type)),
		A_var_declare(
			e_variable_var,
			E_any),
		A_func_call(
			t_x_initialize,
			V_anylist_from_listany(
				[]*Type_any{
					V_cast_var(
						e_variable_var)})),
		A_func_call(
			t_type_t_startup,
			V_anylist_from_listany(
				[]*Type_any{
					V_cast_var(
						t_variable_var),
					A_string_cast_stringn(
						type_type.P_pkgname),
					A_string_cast_stringn(
						type_type.P_name),
					V_cast_string(
						E_string),
					e_variable_any})),
		A_var_set_propertyn(
			t_variable_var,
			"propertylist",
			A_func_call(
				t_varlist_from_listvar,
				V_anylist_from_listany(
					listproperty_listany)))}
	var line_any *Type_any = E_any
	var type_generic *Type_generic = V_generic_from_type(
		type_type)
	if type_generic != E_generic {
		var generic_var *Type_var = V_var_new_mutable_from_namen_type(
			"type-generic",
			T_generic)
		var t_generic_create = V_t_x_create(
			type_scope,
			T_generic)
		line_any = A_var_declare(
			generic_var,
			A_func_call(
				t_generic_create,
				E_anylist))
		listany = append(listany, line_any)
		var x_funcn_namen string = ""
		var x_funcn_var *Type_var = E_var
		// code
		if type_generic.P_code_funcn != nil {
			x_funcn_namen = "v-code-" + type_type.P_name
			switch type_lang {
			case C_lang_go:
				x_funcn_namen = V_stringn_uppercasefirst(
					x_funcn_namen)
			}
			x_funcn_var = V_var_new_from_pkgnamen_namen_type(
				type_type.P_pkgname,
				x_funcn_namen,
				T_code_funcn)
			line_any = A_var_set_propertyn(
				generic_var,
				"code-funcn",
				V_cast_var(
					x_funcn_var))
			listany = append(listany, line_any)
		}
		// copy
		x_funcn_namen = "v-copy-" + type_type.P_name
		switch type_lang {
		case C_lang_go:
			x_funcn_namen = V_stringn_uppercasefirst(
				x_funcn_namen)
		}
		x_funcn_var = V_var_new_from_pkgnamen_namen_type(
			type_type.P_pkgname,
			x_funcn_namen,
			T_code_funcn)
		line_any = A_var_set_propertyn(
			generic_var,
			"copy-funcn",
			V_cast_var(
				x_funcn_var))
		listany = append(listany, line_any)
		// new
		x_funcn_namen = "v-new-" + type_type.P_name
		switch type_lang {
		case C_lang_go:
			x_funcn_namen = V_stringn_uppercasefirst(
				x_funcn_namen)
		}
		x_funcn_var = V_var_new_from_pkgnamen_namen_type(
			type_type.P_pkgname,
			x_funcn_namen,
			T_code_funcn)
		line_any = A_var_set_propertyn(
			generic_var,
			"new-funcn",
			x_funcn_var.P_any)
		listany = append(listany, line_any)
		line_any = A_var_set_propertyn(
			t_variable_var,
			"type-generic",
			generic_var.P_any)
		listany = append(listany, line_any)
	}
	line_any = A_var_declare(
		output_var,
		V_cast_var(
			t_variable_var))
	listany = append(listany, line_any)
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		type_type.P_alias+"-startup",
		T_type,
		E_varlist,
		A_anylist_from_listany(
			listany))
	return output
}

func V_t_x_const_startup(
	type_scope *Type_scope,
	type_const *Type_const) *Type_type {
	var listany []*Type_any = []*Type_any{}
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		type_const.P_name+"-startup",
		T_any,
		E_varlist,
		A_anylist_from_listany(
			listany))
	return output
}

func V_t_x_struct(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"type-t-struct",
		T_empty,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"type-type",
					type_type)}),
		E_any)
	return output
}

func V_get_keyn_type_declare(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_type_declare = V_type_declare_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "type":
		var p_type *Type_type = value.P_type
		output = V_cast_type(
			p_type)
	}
	return output
}

func A_type_declare_new_from_type(
	type_type *Type_type) *Type_any {
	var type_type_declare *Type_type_declare = V_type_declare_new_from_type(
		type_type)
	var output *Type_any = type_type_declare.P_any
	return output
}

func A_type_declare_new_from_type_part(
	type_type *Type_type,
	part_enum *Type_enum) *Type_any {
	var type_type_declare *Type_type_declare = V_type_declare_new_from_type_part(
		type_type,
		part_enum)
	var output *Type_any = type_type_declare.P_any
	return output
}

func V_type_declare_new_from_type(
	type_type *Type_type) *Type_type_declare {
	var output = V_type_declare_create()
	output.P_type = type_type
	return output
}

func V_type_declare_new_from_type_part(
	type_type *Type_type,
	part_enum *Type_enum) *Type_type_declare {
	var output = V_type_declare_create()
	output.P_type = type_type
	output.P_part = part_enum
	return output
}

// (type typelist)
type Type_typelist struct {
	P_any      *Type_any
	P_listtype []*Type_type
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_indexn_funcn = V_get_indexn_typelist
	type_generic.P_listany_funcn = V_listany_typelist
	type_generic.P_code_funcn = V_code_typelist
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_typelist
func V_cast_typelist(
	value *Type_typelist) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_typelist_cast
func V_typelist_cast(
	type_any *Type_any) *Type_typelist {
	var output *Type_typelist = E_typelist
	var value, ok = type_any.backref.(*Type_typelist)
	if ok {
		output = value
	}
	return output
}

func V_get_indexn_typelist(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_typelist *Type_typelist = V_typelist_cast(type_any)
	var type_type *Type_type = V_typelist_type_from_typelist_indexn(
		type_typelist,
		indexn)
	var output *Type_any = type_type.P_any
	return output
}

func V_code_typelist(
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

func V_listany_typelist(
	type_any *Type_any) []*Type_any {
	var type_typelist *Type_typelist = V_typelist_cast(
		type_any)
	var output []*Type_any = V_typelist_listany_from_listtype(
		type_typelist.P_listtype)
	return output
}

func V_typelist_listany_from_listtype(
	listtype []*Type_type) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, type_type := range listtype {
		output = append(output, type_type.P_any)
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

func V_typelist_from_listtype(
	listtype []*Type_type) *Type_typelist {
	var output *Type_typelist = V_typelist_create()
	output.P_listtype = listtype
	return output
}

// (type typemap)
type Type_typemap struct {
	P_any     *Type_any
	P_listkey []string
	P_maptype map[string]*Type_type
}

// V_typemap_constructor
func V_typemap_constructor() *Type_typemap {
	var output = new(Type_typemap)
	return output
}

// V_typemap_create
func V_typemap_create() *Type_typemap {
	var output = V_typemap_constructor()
	V_typemap_initialize(output)
	return output
}

// V_typemap_initialize
func V_typemap_initialize(
	value *Type_typemap) {
	value.P_any = V_any_from_type_backref(
		T_typemap,
		value)
	value.P_listkey = []string{}
	value.P_maptype = map[string]*Type_type{}
}

// V_typemap_startup
func V_typemap_startup() *Type_type {
	var t_variable = T_typemap
	var e_variable = E_typemap
	V_typemap_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"typemap",
		C_extends_map,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_typemap
	type_generic.P_listkey_funcn = V_listkey_typemap
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_typemap
func V_cast_typemap(
	value *Type_typemap) *Type_any {
	return value.P_any
}

// V_typemap_cast
func V_typemap_cast(
	type_any *Type_any) *Type_typemap {
	var output *Type_typemap = E_typemap
	var value, ok = type_any.backref.(*Type_typemap)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_typemap(
	type_any *Type_any,
	keyn string) *Type_any {
	var type_typemap *Type_typemap = V_typemap_cast(
		type_any)
	var type_type *Type_type = V_type_from_typemap_keyn(
		type_typemap,
		keyn)
	var output *Type_any = E_any
	if type_type != E_type {
		output = V_cast_type(
			type_type)
	}
	return output
}

func V_listkey_typemap(
	type_any *Type_any) []string {
	var type_typemap *Type_typemap = V_typemap_cast(
		type_any)
	var output []string = type_typemap.P_listkey
	return output
}

func V_type_from_typemap_keyn(
	type_typemap *Type_typemap,
	keyn string) *Type_type {
	var output *Type_type = E_type
	var mapvalue map[string]*Type_type = type_typemap.P_maptype
	var value, ok = mapvalue[keyn]
	if ok {
		output = value
	}
	return output
}

func V_typelist_from_typemap(
	type_typemap *Type_typemap) *Type_typelist {
	var listkey []string = type_typemap.P_listkey
	var listvalue []*Type_type = []*Type_type{}
	for _, keyn := range listkey {
		var value *Type_type = V_type_from_typemap_keyn(
			type_typemap,
			keyn)
		if value != E_type {
			listvalue = append(listvalue, value)
		}
	}
	var output *Type_typelist = E_typelist
	if len(listvalue) > 0 {
		output.P_listtype = listvalue
	}
	return output
}

func V_typemap_from_listtype(
	listtype []*Type_type) *Type_typemap {
	var listkey []string = []string{}
	var mapvalue map[string]*Type_type = map[string]*Type_type{}
	for _, value := range listtype {
		var keyn string = value.P_path
		listkey = append(listkey, keyn)
		mapvalue[keyn] = value
	}
	var output *Type_typemap = E_typemap
	if len(listkey) > 0 {
		output = V_typemap_create()
		output.P_listkey = listkey
		output.P_maptype = mapvalue
	}
	return output
}

type Type_var struct {
	P_any      *Type_any
	P_pkgname  *Type_string
	P_name     *Type_string
	P_type     *Type_type
	P_value    *Type_any
	P_mutable  *Type_boolean
	P_nullable *Type_boolean
	P_private  *Type_boolean
	P_public   *Type_boolean
}

// V_var_constructor
func V_var_constructor() *Type_var {
	var output = new(Type_var)
	return output
}

// V_var_create
func V_var_create() *Type_var {
	var output = V_var_constructor()
	V_var_initialize(
		output)
	return output
}

// V_var_initialize
func V_var_initialize(
	value *Type_var) {
	value.P_any = V_any_from_type_backref(
		T_var,
		value)
	value.P_pkgname = E_string
	value.P_name = E_string
	value.P_type = E_type
	value.P_value = E_any
	value.P_mutable = C_false
	value.P_nullable = C_false
	value.P_private = C_false
	value.P_public = C_false
}

// V_var_startup
func V_var_startup() *Type_type {
	var t_variable = T_var
	var e_variable = E_var
	V_var_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var",
		C_extends_struct,
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"pkgname",
				T_string),
			V_var_new_public_from_namen_type(
				"name",
				T_string),
			V_var_new_public_from_namen_type(
				"type",
				T_type),
			V_var_new_public_from_namen_type(
				"value",
				T_any),
			V_var_new_public_from_namen_type(
				"mutable",
				T_boolean),
			V_var_new_public_from_namen_type(
				"nullable",
				T_boolean),
			V_var_new_public_from_namen_type(
				"private",
				T_boolean),
			V_var_new_public_from_namen_type(
				"public",
				T_boolean)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_var
	type_generic.P_code_funcn = V_code_from_any_var
	t_variable.type_generic = type_generic
	var output *Type_type = t_variable
	return output
}

// V_cast_var
func V_cast_var(
	value *Type_var) *Type_any {
	var output *Type_any = value.P_any
	return output
}

// V_var_cast
func V_var_cast(
	type_any *Type_any) *Type_var {
	var output *Type_var = E_var
	var value, ok = type_any.backref.(*Type_var)
	if ok {
		output = value
	}
	return output
}

func V_code_from_any_var(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_var = V_var_cast(
		type_any)
	var output = V_code_var(
		type_scope,
		indent,
		path,
		type_var)
	return output
}

func V_get_keyn_var(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_var = V_var_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "pkgname":
		var p_pkgname *Type_string = value.P_pkgname
		output = V_cast_string(
			p_pkgname)
	case "name":
		var p_name *Type_string = value.P_name
		output = V_cast_string(
			p_name)
	case "type":
		var p_type *Type_type = value.P_type
		output = V_cast_type(
			p_type)
	case "value":
		var value_any *Type_any = value.P_value
		output = value_any
	case "mutable":
		var p_mutable *Type_boolean = value.P_mutable
		output = V_cast_boolean(
			p_mutable)
	case "nullable":
		var p_nullable *Type_boolean = value.P_nullable
		output = V_cast_boolean(
			p_nullable)
	case "private":
		var p_private *Type_boolean = value.P_private
		output = V_cast_boolean(
			p_private)
	case "public":
		var p_public *Type_boolean = value.P_public
		output = V_cast_boolean(
			p_public)
	}
	return output
}

func V_code_var(
	type_scope *Type_scope,
	indentn int,
	pathn string,
	type_var *Type_var) string {
	var p_pkgname *Type_string = type_var.P_pkgname
	var pkgnamen string = V_code_pkgnamen(
		type_scope,
		p_pkgname.P_stringn)
	var output string = pkgnamen + V_code_name(
		type_scope,
		type_var.P_name)
	return output
}

func V_var_property_from_var_namen(
	type_var *Type_var,
	namen string) *Type_var {
	var output *Type_var = E_var
	if namen == "any" {
		output = V_var_new_public_from_namen_type(
			"any",
			T_any)
	} else {
		var var_type *Type_type = type_var.P_type
		var propertylist *Type_varlist = var_type.P_propertylist
		var listproperty []*Type_var = propertylist.P_listvar
		for _, property_var := range listproperty {
			if V_stringn_cast_string(
				property_var.P_name) == namen {
				output = property_var
				break
			}
		}
	}
	return output
}

func V_var_new_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_cast_stringn(
		namen)
	return output
}

func V_var_new_from_pkgnamen_namen_type(
	pkgnamen string,
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_pkgname = V_string_cast_stringn(
		pkgnamen)
	output.P_name = V_string_cast_stringn(
		namen)
	return output
}

func V_var_new_mutable_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_cast_stringn(
		namen)
	output.P_mutable = V_boolean_from_booleann(
		true)
	return output
}

func V_var_new_nullable_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_cast_stringn(
		namen)
	output.P_mutable = V_boolean_from_booleann(
		true)
	output.P_nullable = V_boolean_from_booleann(
		true)
	return output
}

func V_var_new_private_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_cast_stringn(namen)
	output.P_mutable = C_false
	output.P_private = C_true
	return output
}

func V_var_new_public_from_namen_type(
	namen string,
	type_type *Type_type) *Type_var {
	var output = V_var_create()
	output.P_type = type_type
	output.P_name = V_string_cast_stringn(namen)
	output.P_mutable = C_false
	output.P_public = C_true
	return output
}

func V_t_var_new_private_from_namen_type(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"var-new-private<-namen-type",
		T_var,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"namen",
					T_stringn),
				V_var_new_from_namen_type(
					"type-type",
					T_type)}),
		E_any)
	return output
}

func V_t_var_new_public_from_namen_type(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"var-new-public<-namen-type",
		T_var,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"namen",
					T_stringn),
				V_var_new_from_namen_type(
					"type-type",
					T_type)}),
		E_any)
	return output
}

func V_var_from_func_namen(
	type_func *Type_func,
	namen string) *Type_var {
	var output *Type_var = E_var
	var varlist *Type_varlist = type_func.P_arglist
	var listproperty []*Type_var = varlist.P_listvar
	for _, property_var := range listproperty {
		if V_stringn_cast_string(
			property_var.P_name) == namen {
			output = property_var
			break
		}
	}
	return output
}

// (type var-declare)
type Type_var_declare struct {
	P_any   *Type_any
	P_var   *Type_var
	P_value *Type_any
}

func V_code_var_declare(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = ""
	var subpath = path + "/code<-any-var-declare"
	var type_lang *Type_lang = type_scope.P_lang
	var type_var_declare = V_var_declare_cast(
		type_any)
	var type_var = type_var_declare.P_var
	var var_type = type_var.P_type
	var mutable = type_var.P_mutable
	var nullable = type_var.P_nullable
	var value_any = type_var_declare.P_value
	var typen string = V_code_type_typename(
		type_scope,
		var_type)
	if nullable == C_true {
		switch type_lang {
		case C_lang_swift:
			typen += "!"
		}
	}
	var varnamen string = V_code_name(
		type_scope,
		type_var.P_name)
	var valuen = ""
	switch value_any {
	case E_any:
		if nullable == C_true {
			switch type_lang {
			case C_lang_go, C_lang_swift:
				valuen = ""
			default:
				valuen = "null"
			}
		} else {
			valuen = V_code_e(
				type_scope,
				var_type)
		}
	case C_enum_new.P_any:
		var typenamen string = V_code_type_typename(
			type_scope,
			var_type)
		switch type_lang {
		case C_lang_go:
			typenamen = V_stringn_from_stringn_aftern(
				typenamen,
				"*")
			valuen = "" +
				"new(" +
				typenamen +
				")"
		case C_lang_java:
			valuen = "" +
				"new " +
				typenamen +
				"()"
		case C_lang_swift:
			valuen = "" +
				typenamen +
				"()"
		}
	default:
		valuen = V_code_any(
			type_scope,
			indent,
			subpath,
			value_any)
		var lineindent = V_code_lineindent(
			type_scope,
			indent)
		if V_booleann_from_stringn_startsn(
			valuen,
			lineindent) {
			valuen = V_stringn_from_stringn_aftern(
				valuen,
				lineindent)
		}
	}
	var lineindent = V_code_lineindent(
		type_scope,
		indent)
	var operator string = " = "
	if valuen == "" {
		operator = ""
	}
	switch type_lang {
	case C_lang_go:
		output = lineindent + "var " + varnamen + " " + typen + operator + valuen
	case C_lang_swift:
		var prefixn string = ""
		if indent == 1 {
			prefixn = "public static "
		}
		if mutable == C_true {
			output = lineindent + prefixn + "var " + varnamen + " : " + typen + operator + valuen
		} else {
			output = lineindent + prefixn + "let " + varnamen + " : " + typen + operator + valuen
		}
	}
	return output
}

func V_get_keyn_var_declare(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_var_declare = V_var_declare_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "var":
		var p_var *Type_var = value.P_var
		output = V_cast_var(p_var)
	case "value":
		var p_value *Type_any = value.P_value
		output = p_value
	}
	return output
}

func V_var_declare(
	type_var *Type_var,
	value *Type_any) *Type_var_declare {
	var output *Type_var_declare = V_var_declare_create()
	output.P_var = type_var
	output.P_value = value
	return output
}

func A_var_declare(
	type_var *Type_var,
	value *Type_any) *Type_any {
	var type_var_declare *Type_var_declare = V_var_declare(
		type_var,
		value)
	var output *Type_any = V_cast_var_declare(
		type_var_declare)
	return output
}

// V_cast_var_declare
func V_cast_var_declare(
	value *Type_var_declare) *Type_any {
	var output *Type_any = value.P_any
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_var_declare
	type_generic.P_code_funcn = V_code_var_declare
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"var",
				T_var),
			V_var_new_public_from_namen_type(
				"value",
				T_any)})
	return t_variable
}

type Type_var_method struct {
	P_any     *Type_any
	P_var     *Type_var
	P_method  *Type_type
	P_anylist *Type_anylist
}

// V_var_method_constructor
func V_var_method_constructor() *Type_var_method {
	var output = new(Type_var_method)
	return output
}

// V_var_method_create
func V_var_method_create() *Type_var_method {
	var output = V_var_method_constructor()
	V_var_method_initialize(
		output)
	return output
}

// V_var_method_initialize
func V_var_method_initialize(
	value *Type_var_method) {
	value.P_any = V_any_from_type_backref(
		T_var_method,
		value)
	value.P_var = E_var
	value.P_method = E_type
	value.P_anylist = E_anylist
}

// V_var_method_startup
func V_var_method_startup() *Type_type {
	var t_variable = T_var_method
	var e_variable = E_var_method
	V_var_method_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-method",
		C_extends_struct,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_var_method
	type_generic.P_code_funcn = V_code_from_any_var_method
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"var",
				T_var),
			V_var_new_public_from_namen_type(
				"method",
				T_type),
			V_var_new_public_from_namen_type(
				"varlist",
				T_anylist)})
	return t_variable
}

func V_get_keyn_var_method(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_var_method = V_var_method_cast_any(type_any)
	var output *Type_any = E_any
	switch keyn {
	case "var":
		var p_var *Type_var = value.P_var
		output = V_cast_var(
			p_var)
	case "method":
		var p_method *Type_type = value.P_method
		output = V_cast_type(
			p_method)
	case "anylist":
		var p_anylist *Type_anylist = value.P_anylist
		output = V_cast_anylist(
			p_anylist)
	}
	return output
}

func V_code_from_any_var_method(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_lang *Type_lang = type_scope.P_lang
	var type_var_method *Type_var_method = V_var_method_cast_any(
		type_any)
	var p_var *Type_var = type_var_method.P_var
	var p_method *Type_type = type_var_method.P_method
	var p_anylist *Type_anylist = type_var_method.P_anylist
	var type_func_call = V_func_call_create()
	type_func_call.P_type = p_method
	type_func_call.P_anylist = p_anylist
	type_func_call.P_ismethod = C_true
	var varnamen = V_code_name(
		type_scope,
		p_var.P_name)
	var valuen = V_code_from_func_call(
		type_scope,
		indent,
		path,
		type_func_call)
	var lineindent string = V_code_lineindent(
		type_scope,
		indent)
	if V_booleann_from_stringn_startsn(
		valuen,
		lineindent) {
		valuen = V_stringn_from_stringn_aftern(
			valuen,
			lineindent)
	}
	switch type_lang {
	case C_lang_go:
		if V_booleann_from_stringn_startsn(
			valuen,
			"p_") {
			valuen = V_stringn_uppercasefirst(
				valuen)
		}
	}
	var output string = lineindent +
		varnamen +
		type_lang.P_typeref +
		valuen
	return output
}

func V_var_method_cast_any(
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
	method_type *Type_type,
	type_anylist *Type_anylist) *Type_any {
	var output *Type_var_method = V_var_method_create()
	output.P_var = type_var
	output.P_method = method_type
	output.P_anylist = type_anylist
	return output.P_any
}

type Type_var_property struct {
	P_any      *Type_any
	P_var      *Type_var
	P_property *Type_string
}

// V_var_property_constructor
func V_var_property_constructor() *Type_var_property {
	var output = new(Type_var_property)
	return output
}

// V_var_property_create
func V_var_property_create() *Type_var_property {
	var output = V_var_property_constructor()
	V_var_property_initialize(
		output)
	return output
}

// V_var_property_initialize
func V_var_property_initialize(
	value *Type_var_property) {
	value.P_any = V_any_from_type_backref(
		T_var_property,
		value)
	value.P_var = E_var
	value.P_property = E_string
}

// V_var_property_startup
func V_var_property_startup() *Type_type {
	var t_variable = T_var_property
	var e_variable = E_var_property
	V_var_property_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"var-property",
		C_extends_struct,
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_var_property
	type_generic.P_code_funcn = V_code_var_property
	t_variable.type_generic = type_generic
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"var",
				T_var),
			V_var_new_public_from_namen_type(
				"property",
				T_string)})
	return t_variable
}

func V_code_var_property(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var type_var_property = V_var_property_cast(
		type_any)
	var type_var *Type_var = type_var_property.P_var
	var property_string *Type_string = type_var_property.P_property
	var varnamen string = V_code_name(
		type_scope,
		type_var.P_name)
	var propertyn string = V_stringn_cast_string(
		property_string)
	var prefixn = V_prefixn_from_var_propertyn(
		type_scope,
		type_var,
		propertyn)
	var output string = ""
	var type_lang *Type_lang = type_scope.P_lang
	output = varnamen +
		type_lang.P_typeref +
		prefixn +
		V_code_namen(
			type_scope,
			propertyn)
	return output
}

func V_cast_var_property(
	value *Type_var_property) *Type_any {
	var output *Type_any = value.P_any
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

func V_get_keyn_var_property(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_var_property = V_var_property_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "var":
		var p_var *Type_var = value.P_var
		output = V_cast_var(
			p_var)
	case "property":
		var p_property *Type_string = value.P_property
		output = V_cast_string(
			p_property)
	}
	return output
}

func V_set_keyn_var_property(
	type_any *Type_any,
	keyn string,
	value_any *Type_any) {
	var value *Type_var_property = V_var_property_cast(
		type_any)
	switch keyn {
	case "var":
		value.P_var = V_var_cast(
			value_any)
	case "property":
		value.P_property = V_string_cast(
			value_any)
	}
}

func V_prefixn_from_var_propertyn(
	type_scope *Type_scope,
	type_var *Type_var,
	propertyn string) string {
	var type_lang *Type_lang = type_scope.P_lang
	var property_var *Type_var = V_var_property_from_var_namen(
		type_var,
		propertyn)
	var prefixn string = ""
	if property_var.P_public == C_true {
		prefixn = "p_"
		switch type_lang {
		case C_lang_go:
			prefixn = "P_"
		}
	}
	return prefixn
}

func A_var_propertyn(
	type_var *Type_var,
	propertyn string) *Type_any {
	var type_var_property *Type_var_property = V_var_propertyn(
		type_var,
		propertyn)
	var output *Type_any = type_var_property.P_any
	return output
}

func V_var_propertyn(
	type_var *Type_var,
	propertyn string) *Type_var_property {
	var output *Type_var_property = V_var_property_create()
	output.P_var = type_var
	output.P_property = V_string_cast_stringn(
		propertyn)
	return output
}

type Type_var_set struct {
	P_any      *Type_any
	P_var      *Type_var
	P_property *Type_string
	P_operator *Type_string
	P_value    *Type_any
}

// V_var_set_constructor
func V_var_set_constructor() *Type_var_set {
	var output = new(Type_var_set)
	return output
}

// V_var_set_create
func V_var_set_create() *Type_var_set {
	var output = V_var_set_constructor()
	V_var_set_initialize(
		output)
	return output
}

// V_var_set_initialize
func V_var_set_initialize(
	value *Type_var_set) {
	value.P_any = V_any_from_type_backref(
		T_var_set,
		value)
	value.P_var = E_var
	value.P_property = E_string
	value.P_operator = E_string
	value.P_value = E_any
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
		e_variable.P_any)
	t_variable.P_propertylist = V_varlist_from_listvar(
		[]*Type_var{
			V_var_new_public_from_namen_type(
				"var",
				T_var),
			V_var_new_public_from_namen_type(
				"property",
				T_string),
			V_var_new_public_from_namen_type(
				"operator",
				T_string),
			V_var_new_public_from_namen_type(
				"value",
				T_any)})
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_keyn_funcn = V_get_keyn_var_set
	type_generic.P_code_funcn = V_code_from_any_var_set
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_var_set
func V_cast_var_set(
	type_var_set *Type_var_set) *Type_any {
	var output *Type_any = type_var_set.P_any
	return output
}

// V_var_set_cast
func V_var_set_cast(
	type_any *Type_any) *Type_var_set {
	var output = E_var_set
	var value, ok = type_any.backref.(*Type_var_set)
	if ok {
		output = value
	}
	return output
}

func V_get_keyn_var_set(
	type_any *Type_any,
	keyn string) *Type_any {
	var value *Type_var_set = V_var_set_cast(
		type_any)
	var output *Type_any = E_any
	switch keyn {
	case "var":
		var p_var *Type_var = value.P_var
		output = V_cast_var(
			p_var)
	case "property":
		var p_property *Type_string = value.P_property
		output = V_cast_string(
			p_property)
	case "operator":
		var p_operator *Type_string = value.P_operator
		output = V_cast_string(
			p_operator)
	case "value":
		var p_value *Type_any = value.P_value
		output = p_value
	}
	return output
}

func V_code_from_any_var_set(
	type_scope *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output string = ""
	var subpath string = path + "/code<-any-var-set"
	var type_lang *Type_lang = type_scope.P_lang
	var type_var_set = V_var_set_cast(
		type_any)
	var type_var = type_var_set.P_var
	var p_property *Type_string = type_var_set.P_property
	var p_operator *Type_string = type_var_set.P_operator
	var propertyn = V_code_name(
		type_scope,
		p_property)
	var operatorn string = V_stringn_cast_string(
		p_operator)
	if operatorn == "" {
		operatorn = "="
	}
	var varnamen = V_code_var_name(
		type_scope,
		type_var)
	var value_any *Type_any = type_var_set.P_value
	var valuen string = ""
	if V_stringn_cast_string(
		p_property) == "backref" && value_any == E_type.P_any {
		switch type_lang {
		case C_lang_go, C_lang_swift:
			valuen = "nil"
		}
	} else {
		valuen = V_code_any(
			type_scope,
			indent,
			subpath,
			value_any)
	}
	var lineindent string = V_code_lineindent(
		type_scope,
		indent)
	if V_booleann_from_stringn_startsn(
		valuen,
		lineindent) {
		valuen = V_stringn_from_stringn_aftern(
			valuen,
			lineindent)
	}
	switch operatorn {
	case "backref":
		var lineindent1 string = V_code_lineindent(
			type_scope,
			indent+1)
		var var_type *Type_type = type_var.P_type
		var tname string = V_code_t(
			type_scope,
			var_type)
		var propertytypen string = V_code_type_typename(
			type_scope,
			var_type)
		switch type_lang {
		case C_lang_go:
			output = "" +
				lineindent + "var value, ok = type_any.backref.(" + propertytypen + ")" +
				lineindent + "if ok {" +
				lineindent1 + "output = value" +
				lineindent + "}"
		case C_lang_swift:
			output = "" +
				lineindent + "if type_any.type_type === " + tname + " {" +
				lineindent1 + "output = unsafeBitCast(type_any.backref, to: " + propertytypen + ".self)" +
				lineindent + "}"
		}
	default:
		if propertyn == "" {
			output = lineindent +
				varnamen +
				" " +
				operatorn +
				" " +
				valuen
		} else {
			var prefixn = V_prefixn_from_var_propertyn(
				type_scope,
				type_var,
				p_property.P_stringn)
			output = lineindent +
				varnamen +
				type_lang.P_typeref +
				prefixn +
				propertyn +
				" " +
				operatorn +
				" " +
				valuen
		}
	}
	return output
}

func A_var_set(
	type_var *Type_var,
	value_any *Type_any) *Type_any {
	var output = V_var_set_create()
	output.P_var = type_var
	output.P_value = value_any
	return output.P_any
}

func A_var_set_operatorn(
	type_var *Type_var,
	operatorn string,
	value_any *Type_any) *Type_any {
	var output = V_var_set_create()
	output.P_var = type_var
	output.P_operator = V_string_cast_stringn(
		operatorn)
	output.P_value = value_any
	return output.P_any
}

func A_var_set_propertyn(
	type_var *Type_var,
	propertyn string,
	value_any *Type_any) *Type_any {
	var output = V_var_set_create()
	output.P_var = type_var
	output.P_property = V_string_cast_stringn(
		propertyn)
	output.P_value = value_any
	return output.P_any
}

func A_var_set_propertyn_operatorn(
	type_var *Type_var,
	propertyn string,
	operator string,
	value_any *Type_any) *Type_any {
	var output = V_var_set_create()
	output.P_var = type_var
	output.P_property = V_string_cast_stringn(
		propertyn)
	output.P_operator = V_string_cast_stringn(
		operator)
	output.P_value = value_any
	return output.P_any
}

// Type_varlist
type Type_varlist struct {
	P_any     *Type_any
	P_listvar []*Type_var
}

func V_get_indexn_varlist(
	type_any *Type_any,
	indexn int) *Type_any {
	var type_varlist *Type_varlist = V_varlist_cast(
		type_any)
	var type_var *Type_var = V_var_from_varlist_indexn(
		type_varlist,
		indexn)
	var output *Type_any = type_var.P_any
	return output
}

func V_code_varlist(
	lang *Type_scope,
	indent int,
	path string,
	type_any *Type_any) string {
	var output = "" +
		"f_varlist(" +
		")"
	return output
}

func V_listany_varlist(
	type_any *Type_any) []*Type_any {
	var type_varlist *Type_varlist = V_varlist_cast(
		type_any)
	var output []*Type_any = V_varlist_listany_from_listvar(
		type_varlist.P_listvar)
	return output
}

func V_varlist_listany_from_listvar(
	listvar []*Type_var) []*Type_any {
	var output []*Type_any = []*Type_any{}
	for _, value := range listvar {
		output = append(output, V_cast_var(value))
	}
	return output
}

func V_varlist_t_varlist_from_listvar(
	type_scope *Type_scope,
	type_type *Type_type) *Type_type {
	var t_listvar = V_type_new_from_pkgnamen_namen_extends_type_native(
		"",
		"listvar",
		C_extends_list,
		T_var,
		true)
	var output *Type_type = V_type_new_func_from_scope_namen_return_varlist_value(
		type_scope,
		"varlist<-listvar",
		T_varlist,
		V_varlist_from_listvar(
			[]*Type_var{
				V_var_new_from_namen_type(
					"listvar",
					t_listvar)}),
		E_any)
	return output
}

func V_var_from_varlist_indexn(
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

func V_cast_varlist(
	value *Type_varlist) *Type_any {
	var output *Type_any = E_any
	if value != E_varlist {
		output = value.P_any
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

// V_varlist_from_var
func V_varlist_from_var(
	type_var *Type_var) *Type_varlist {
	var output *Type_varlist = V_varlist_create()
	output.P_listvar = []*Type_var{
		type_var}
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
	value.P_any = V_any_from_type_backref(
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_get_indexn_funcn = V_get_indexn_varlist
	type_generic.P_listany_funcn = V_listany_varlist
	type_generic.P_code_funcn = V_code_varlist
	t_variable.type_generic = type_generic
	return t_variable
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
		e_variable.P_any)
	var type_generic *Type_generic = V_generic_create()
	type_generic.P_func_funcn = V_func_from_type_boolean_from_booleann
	t_variable.type_generic = type_generic
	return t_variable
}

// V_cast_funcn_startup
func V_cast_funcn_startup() *Type_type {
	var t_variable = T_cast_funcn
	var e_variable = E_cast_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"cast",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_code_funcn_startup
func V_code_funcn_startup() *Type_type {
	var t_variable = T_code_funcn
	var e_variable = E_code_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"code-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_copy_funcn_startup
func V_copy_funcn_startup() *Type_type {
	var t_variable = T_copy_funcn
	var e_variable = E_copy_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"copy-funcn",
		C_extends_func,
		e_variable.P_any)
	var output *Type_type = t_variable
	return output
}

// V_count_funcn_startup
func V_count_funcn_startup() *Type_type {
	var t_variable = T_count_funcn
	var e_variable = E_count_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"count-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_func_from_type_boolean_from_booleann
func V_func_from_type_boolean_from_booleann(
	type_type *Type_type) *Type_func {
	var t_variable = T_boolean_from_booleann
	var var_output_boolean = V_var_new_mutable_from_namen_type(
		"output",
		T_boolean)
	var var_booleann = V_var_new_from_namen_type(
		"booleann",
		T_booleann)
	var output *Type_func = V_func_new_from_type_return_varlist_value(
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
				A_if_from_if_then( // if booleann {
					var_booleann.P_any,
					A_var_set( // output = Vx_Core.c_true
						var_output_boolean,
						C_true.P_any))}))
	return output
}

// V_func_funcn_startup
func V_func_funcn_startup() *Type_type {
	var t_variable = T_func_funcn
	var e_variable = E_func_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"func<-type-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_get_keyn_funcn_startup
func V_get_keyn_funcn_startup() *Type_type {
	var t_variable = T_get_keyn_funcn
	var e_variable = E_get_keyn_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"get-keyn-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_get_indexn_funcn_startup
func V_get_indexn_funcn_startup() *Type_type {
	var t_variable = T_get_indexn_funcn
	var e_variable = E_get_indexn_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"get-indexn-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_listany_funcn_startup
func V_listany_funcn_startup() *Type_type {
	var t_variable = T_listany_funcn
	var e_variable = E_listany_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"listany-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_listkeyn_funcn_startup
func V_listkeyn_funcn_startup() *Type_type {
	var t_variable = T_listkeyn_funcn
	var e_variable = E_listkeyn_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"listkeyn-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_mapany_funcn_startup
func V_mapany_funcn_startup() *Type_type {
	var t_variable = T_mapany_funcn
	var e_variable = E_mapany_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"mapany-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_new_funcn_startup
func V_new_funcn_startup() *Type_type {
	var t_variable = T_new_funcn
	var e_variable = E_new_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"new-funcn",
		C_extends_func,
		e_variable.P_any)
	var output *Type_type = t_variable
	return output
}

// V_set_keyn_funcn_startup
func V_set_keyn_funcn_startup() *Type_type {
	var t_variable = T_set_keyn_funcn
	var e_variable = E_set_keyn_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"set-keyn-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_set_indexn_funcn_startup
func V_set_indexn_funcn_startup() *Type_type {
	var t_variable = T_set_indexn_funcn
	var e_variable = E_set_indexn_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"set-indexn-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_shutdown_funcn_startup
func V_shutdown_funcn_startup() *Type_type {
	var t_variable = T_shutdown_funcn
	var e_variable = E_shutdown_funcn
	V_type_initialize(
		e_variable)
	V_type_t_startup(
		t_variable,
		"vx/core",
		"shutdown-funcn",
		C_extends_func,
		e_variable.P_any)
	return t_variable
}

// V_const_false_startup
func V_const_false_startup() *Type_any {
	var c_variable = C_false
	c_variable.P_booleann = false
	var output *Type_any = c_variable.P_any
	return output
}

func V_const_true_startup() *Type_any {
	var c_variable = C_true
	V_boolean_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	var type_const *Type_const = V_const_from_pkgnamen_namen_any(
		"vx/core",
		"true",
		type_any)
	type_const.P_isempty = false
	c_variable.P_booleann = true
	var output *Type_any = c_variable.P_any
	return output
}

func V_const_lang_c_startup() *Type_any {
	var c_variable = C_lang_c
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-c",
		type_any)
	c_variable.P_name = V_string_cast_stringn("c")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "->"
	return c_variable.P_any
}

func V_const_lang_cpp_startup() *Type_any {
	var c_variable = C_lang_cpp
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-cpp",
		type_any)
	c_variable.P_name = V_string_cast_stringn("cpp")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "->"
	return c_variable.P_any
}

func V_const_lang_csharp_startup() *Type_any {
	var c_variable = C_lang_csharp
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-csharp",
		type_any)
	c_variable.P_name = V_string_cast_stringn("csharp")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_go_startup() *Type_any {
	var c_variable = C_lang_go
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-go",
		type_any)
	c_variable.P_name = V_string_cast_stringn("go")
	c_variable.P_indent = V_string_cast_stringn("\t")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_java_startup() *Type_any {
	var c_variable = C_lang_java
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-java",
		type_any)
	c_variable.P_name = V_string_cast_stringn("java")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_js_startup() *Type_any {
	var c_variable = C_lang_js
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-js",
		type_any)
	c_variable.P_name = V_string_cast_stringn("js")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_kotlin_startup() *Type_any {
	var c_variable = C_lang_kotlin
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-kotlin",
		type_any)
	c_variable.P_name = V_string_cast_stringn("kotlin")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_py_startup() *Type_any {
	var c_variable = C_lang_py
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-py",
		type_any)
	c_variable.P_name = V_string_cast_stringn("py")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_rust_startup() *Type_any {
	var c_variable = C_lang_rust
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-rust",
		type_any)
	c_variable.P_name = V_string_cast_stringn("rust")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

func V_const_lang_swift_startup() *Type_any {
	var c_variable = C_lang_swift
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-swift",
		type_any)
	c_variable.P_name = V_string_cast_stringn("swift")
	c_variable.P_indent = V_string_cast_stringn("  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	c_variable.P_isrefcount = true
	var output *Type_any = c_variable.P_any
	return output
}

func V_const_lang_ts_startup() *Type_any {
	var c_variable = C_lang_ts
	V_lang_initialize(
		c_variable)
	var type_any *Type_any = c_variable.P_any
	V_const_from_pkgnamen_namen_any(
		"vx/core",
		"lang-ts",
		type_any)
	c_variable.P_name = V_string_cast_stringn(
		"ts")
	c_variable.P_indent = V_string_cast_stringn(
		"  ")
	c_variable.P_pkgref = "."
	c_variable.P_typeref = "."
	return c_variable.P_any
}

var G_global *Type_global = V_global_constructor()

var T_any *Type_type = V_type_constructor()
var T_anylist *Type_type = V_type_constructor()
var T_anymap *Type_type = V_type_constructor()
var T_async *Type_type = V_type_constructor()
var T_boolean *Type_type = V_type_constructor()
var T_booleann *Type_type = V_type_constructor()
var T_const *Type_type = V_type_constructor()
var T_constlist *Type_type = V_type_constructor()
var T_constmap *Type_type = V_type_constructor()
var T_delta *Type_type = V_type_constructor()
var T_context *Type_type = V_type_constructor()
var T_decimal *Type_type = V_type_constructor()
var T_enum *Type_type = V_type_constructor()
var T_float *Type_type = V_type_constructor()
var T_floatn *Type_type = V_type_constructor()
var T_fn *Type_type = V_type_constructor()
var T_func *Type_type = V_type_constructor()
var T_generic *Type_type = V_type_constructor()
var T_if *Type_type = V_type_constructor()
var T_int *Type_type = V_type_constructor()
var T_intn *Type_type = V_type_constructor()
var T_lang *Type_type = V_type_constructor()
var T_list *Type_type = V_type_constructor()
var T_map *Type_type = V_type_constructor()
var T_msg *Type_type = V_type_constructor()
var T_msgblock *Type_type = V_type_constructor()
var T_none *Type_type = V_type_constructor()
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
var T_type_declare *Type_type = V_type_constructor()
var T_typelist *Type_type = V_type_constructor()
var T_typemap *Type_type = V_type_constructor()
var T_var *Type_type = V_type_constructor()
var T_var_declare *Type_type = V_type_constructor()
var T_var_method *Type_type = V_type_constructor()
var T_var_property *Type_type = V_type_constructor()
var T_var_set *Type_type = V_type_constructor()
var T_varlist *Type_type = V_type_constructor()
var T_plus *Type_type = V_type_constructor()
var T_eqeq *Type_type = V_type_constructor()
var T_noteqeq *Type_type = V_type_constructor()
var T_lt *Type_type = V_type_constructor()
var T_le *Type_type = V_type_constructor()
var T_boolean_from_booleann *Type_type = V_type_constructor()
var T_const_declare *Type_type = V_type_constructor()
var T_copy *Type_type = V_type_constructor()
var T_empty *Type_type = V_type_constructor()
var T_func_call *Type_type = V_type_constructor()
var T_func_declare *Type_type = V_type_constructor()
var T_log_stringn *Type_type = V_type_constructor()
var T_new *Type_type = V_type_constructor()
var T_package_declare *Type_type = V_type_constructor()
var T_cast_funcn *Type_type = V_type_constructor()
var T_code_funcn *Type_type = V_type_constructor()
var T_copy_funcn *Type_type = V_type_constructor()
var T_func_funcn *Type_type = V_type_constructor()
var T_count_funcn *Type_type = V_type_constructor()
var T_get_keyn_funcn *Type_type = V_type_constructor()
var T_get_indexn_funcn *Type_type = V_type_constructor()
var T_listany_funcn *Type_type = V_type_constructor()
var T_listkeyn_funcn *Type_type = V_type_constructor()
var T_mapany_funcn *Type_type = V_type_constructor()
var T_new_funcn *Type_type = V_type_constructor()
var T_set_keyn_funcn *Type_type = V_type_constructor()
var T_set_indexn_funcn *Type_type = V_type_constructor()
var T_shutdown_funcn *Type_type = V_type_constructor()
var T_any_from_type_backref *Type_type = nil

var E_any *Type_any = V_any_constructor()
var E_anylist *Type_anylist = V_anylist_constructor()
var E_anymap *Type_anymap = V_anymap_constructor()
var E_booleann *Type_booleann = V_booleann_constructor()
var E_const *Type_const = V_const_constructor()
var E_constlist *Type_constlist = V_constlist_constructor()
var E_constmap *Type_constmap = V_constmap_constructor()
var E_delta *Type_delta = V_delta_constructor()
var E_enum *Type_enum = V_enum_constructor()
var E_float *Type_float = V_float_constructor()
var E_floatn *Type_floatn = V_floatn_constructor()
var E_fn *Type_fn = V_fn_constructor()
var E_func *Type_func = V_func_constructor()
var E_generic *Type_generic = V_generic_constructor()
var E_if *Type_if = V_if_constructor()
var E_int *Type_int = V_int_constructor()
var E_intn *Type_intn = V_intn_constructor()
var E_lang *Type_lang = V_lang_constructor()
var E_list *Type_list = V_list_constructor()
var E_map *Type_map = V_map_constructor()
var E_msg *Type_msg = V_msg_constructor()
var E_msgblock *Type_msgblock = V_msgblock_constructor()
var E_none *Type_none = V_none_constructor()
var E_package *Type_package = V_package_constructor()
var E_packagemap *Type_packagemap = V_packagemap_constructor()
var E_project *Type_project = V_project_constructor()
var E_scope *Type_scope = V_scope_constructor()
var E_string *Type_string = V_string_constructor()
var E_stringn *Type_stringn = V_stringn_constructor()
var E_stringlist *Type_stringlist = V_stringlist_constructor()
var E_stringmap *Type_stringmap = V_stringmap_constructor()
var E_struct *Type_struct = V_struct_constructor()
var E_thenelse *Type_thenelse = V_thenelse_constructor()
var E_thenelselist *Type_thenelselist = V_thenelselist_constructor()
var E_type *Type_type = V_type_constructor()
var E_type_declare *Type_type_declare = V_type_declare_constructor()
var E_typelist *Type_typelist = V_typelist_constructor()
var E_typemap *Type_typemap = V_typemap_constructor()
var E_var *Type_var = V_var_constructor()
var E_var_declare *Type_var_declare = V_var_declare_constructor()
var E_var_method *Type_var_method = V_var_method_constructor()
var E_var_property *Type_var_property = V_var_property_constructor()
var E_var_set *Type_var_set = V_var_set_constructor()
var E_varlist *Type_varlist = V_varlist_constructor()
var E_plus *Type_plus = V_plus_constructor()
var E_eqeq *Type_eqeq = V_eqeq_constructor()
var E_noteqeq *Type_noteqeq = V_noteqeq_constructor()
var E_lt *Type_lt = V_lt_constructor()
var E_le *Type_le = V_le_constructor()
var E_boolean_from_booleann *Type_type = V_type_constructor()
var E_const_declare *Type_const_declare = V_const_declare_constructor()
var E_copy *Type_copy = V_copy_constructor()
var E_func_call *Type_func_call = V_func_call_constructor()
var E_func_declare *Type_func_declare = V_func_declare_constructor()
var E_log_stringn *Type_log_stringn = V_log_stringn_constructor()
var E_new *Type_new = V_new_constructor()
var E_package_declare *Type_package_declare = V_package_declare_constructor()
var E_cast_funcn *Type_type = V_type_constructor()
var E_code_funcn *Type_type = V_type_constructor()
var E_copy_funcn *Type_type = V_type_constructor()
var E_count_funcn *Type_type = V_type_constructor()
var E_func_funcn *Type_type = V_type_constructor()
var E_get_keyn_funcn *Type_type = V_type_constructor()
var E_get_indexn_funcn *Type_type = V_type_constructor()
var E_listany_funcn *Type_type = V_type_constructor()
var E_listkeyn_funcn *Type_type = V_type_constructor()
var E_mapany_funcn *Type_type = V_type_constructor()
var E_new_funcn *Type_type = V_type_constructor()
var E_set_keyn_funcn *Type_type = V_type_constructor()
var E_set_indexn_funcn *Type_type = V_type_constructor()
var E_shutdown_funcn *Type_type = V_type_constructor()

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
var C_operator_notnull *Type_enum = V_enum_constructor()
var C_enum_c_const *Type_enum = V_enum_constructor()
var C_enum_constructor *Type_enum = V_enum_constructor()
var C_enum_const_startup *Type_enum = V_enum_constructor()
var C_enum_create *Type_enum = V_enum_constructor()
var C_enum_custom *Type_enum = V_enum_constructor()
var C_enum_e_type *Type_enum = V_enum_constructor()
var C_enum_initialize *Type_enum = V_enum_constructor()
var C_enum_new *Type_enum = V_enum_constructor()
var C_enum_shutdown *Type_enum = V_enum_constructor()
var C_enum_startup *Type_enum = V_enum_constructor()
var C_enum_struct *Type_enum = V_enum_constructor()
var C_enum_t_type *Type_enum = V_enum_constructor()
var C_enum_x_cast_any *Type_enum = V_enum_constructor()
var C_var_context *Type_var = V_var_constructor()

var isregistered bool = V_global_register_from_pathn_listtype_listconst(
	"vx/core",
	[]*Type_type{
		V_any_startup(),
		V_anylist_startup(),
		V_anymap_startup(),
		V_boolean_startup(),
		V_booleann_startup(),
		V_const_startup(),
		V_constlist_startup(),
		V_constmap_startup(),
		V_delta_startup(),
		V_enum_startup(),
		V_float_startup(),
		V_floatn_startup(),
		V_fn_startup(),
		V_func_startup(),
		V_func_call_startup(),
		V_func_declare_startup(),
		V_generic_startup(),
		V_int_startup(),
		V_intn_startup(),
		V_lang_startup(),
		V_list_startup(),
		V_map_startup(),
		V_msg_startup(),
		V_msgblock_startup(),
		V_none_startup(),
		V_package_startup(),
		V_package_declare_startup(),
		V_packagemap_startup(),
		V_project_startup(),
		V_scope_startup(),
		V_string_startup(),
		V_stringn_startup(),
		V_stringlist_startup(),
		V_stringmap_startup(),
		V_struct_startup(),
		V_thenelse_startup(),
		V_thenelselist_startup(),
		V_type_startup(),
		V_type_declare_startup(),
		V_typelist_startup(),
		V_typemap_startup(),
		V_var_startup(),
		V_var_declare_startup(),
		V_var_method_startup(),
		V_var_property_startup(),
		V_var_set_startup(),
		V_varlist_startup(),
		V_plus_startup(),
		V_eqeq_startup(),
		V_noteqeq_startup(),
		V_lt_startup(),
		V_le_startup(),
		V_boolean_from_booleann_startup(),
		V_const_declare_startup(),
		V_copy_startup(),
		V_log_stringn_startup(),
		V_new_startup(),
		V_cast_funcn_startup(),
		V_code_funcn_startup(),
		V_copy_funcn_startup(),
		V_func_funcn_startup(),
		V_get_keyn_funcn_startup(),
		V_get_indexn_funcn_startup(),
		V_if_startup(),
		V_count_funcn_startup(),
		V_listany_funcn_startup(),
		V_listkeyn_funcn_startup(),
		V_mapany_funcn_startup(),
		V_new_funcn_startup(),
		V_set_indexn_funcn_startup(),
		V_set_keyn_funcn_startup(),
		V_shutdown_funcn_startup()},
	[]*Type_any{
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
		V_const_lang_ts_startup()})
