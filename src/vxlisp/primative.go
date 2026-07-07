package vxlisp

import (
	"sort"
	"strconv"
	"strings"
	vx_core "vxlisp/vxlisp/vx/core"
)

func NewMapString() map[string]string {
	return make(map[string]string)
}

func BooleanFromStringEnds(str string, ends string) bool {
	return strings.HasSuffix(str, ends)
}

func BooleanFromStringEquals(str string, equals string) bool {
	return str == equals
}

func BooleanFromStringStartsEnds(str string, starts string, ends string) bool {
	return strings.HasPrefix(str, starts) && strings.HasSuffix(str, ends)
}

func BooleanIsIntFromString(str string) bool {
	_, err := strconv.ParseInt(str, 10, 32)
	return err == nil
}

func BooleanIsNumberFromString(text string) bool {
	_, err := strconv.ParseFloat(text, 64)
	return err == nil
}

func FloatFromString(str string) float64 {
	output, _ := strconv.ParseFloat(str, 64)
	return output
}

func FloatFromInt(intval int) float64 {
	return float64(intval)
}

func IntCountFromStringFind(str string, find string) int {
	return strings.Count(str, find)
}

func IntFromFloat(floatval float64) int {
	return int(floatval)
}

func IntFromString(str string) int {
	output, _ := strconv.Atoi(str)
	return output
}

func IntFromStringCount(str string, scount string) int {
	output := strings.Count(str, scount)
	return output
}

func IntFromStringFindNth(str string, find string, nth int) int {
	var output = -1
	i := 0
	for m := 1; m <= nth; m++ {
		x := strings.Index(str[i:], find)
		if x < 0 {
			break
		}
		i += x
		if m == nth {
			output = i
			break
		}
		i += len(find)
	}
	return output
}

func IntFromStringFindStart(str string, find string, start int) int {
	output := strings.Index(str[start:], find)
	if output >= 0 {
		output += start
	}
	return output
}

func ListStringFromListStringMatch(liststring []string, listmatch []string) []string {
	var output []string
	mapnotmatch := MapStringFromListStringValue(listmatch, "")
	for _, text := range liststring {
		_, ok := mapnotmatch[text]
		if ok {
			output = append(output, text)
		}
	}
	return output
}

func ListStringFromListStringNotMatch(liststring []string, listnotmatch []string) []string {
	var output []string
	mapnotmatch := MapStringFromListStringValue(listnotmatch, "")
	for _, text := range liststring {
		_, ok := mapnotmatch[text]
		if !ok {
			output = append(output, text)
		}
	}
	return output
}

func ListStringFromStringSplitByDelims(str string, startdelim string, enddelim string) []string {
	var output []string
	worktext := str
	isdone := false
	for ok := true; ok; ok = !isdone {
		startpos := vx_core.V_intn_from_stringn_findn(worktext, startdelim)
		if startpos < 0 {
			isdone = true
			output = append(output, worktext)
		} else {
			output = append(output, worktext[0:startpos])
			worktext = worktext[startpos:]
			endpos := vx_core.V_intn_from_stringn_findn(worktext, enddelim)
			if endpos < 0 {
				output = append(output, worktext)
				isdone = true
			} else {
				breakpos := endpos + len(enddelim)
				before := worktext[0:breakpos]
				after := worktext[breakpos:]
				output = append(output, before)
				worktext = after
			}
		}
	}
	return output
}

func ListStringKeysFromStringMap(mapstring map[string]string) []string {
	var listkey []string
	for key := range mapstring {
		listkey = append(listkey, key)
	}
	return ListStringSort(listkey)
}

func ListStringSort(liststring []string) []string {
	sort.Strings(liststring)
	return liststring
}

func ListStringUniques(liststring []string) []string {
	var output []string
	if len(liststring) > 0 {
		textmap := map[string]string{}
		for _, text := range liststring {
			textmap[text] = ""
		}
		output = ListStringKeysFromStringMap(textmap)
		sort.Strings(output)
	}
	return output
}

func MapStringFromListStringValue(liststring []string, value string) map[string]string {
	output := NewMapString()
	for _, text := range liststring {
		output[text] = value
	}
	return output
}

func StringByteFromBoolean(booleanval bool) string {
	if booleanval {
		return "1"
	} else {
		return "0"
	}
}

func StringFromBoolean(booleanval bool) string {
	output := "false"
	if booleanval {
		output = "true"
	}
	return output
}

func StringFromStringBefore(text string, before string) string {
	output := text
	if BooleanFromStringEnds(text, before) {
		output = text[0 : len(text)-len(before)]
	}
	return output
}

func StringFromStringFromTo(text string, from string, to string) string {
	output := ""
	if text == "" {
	} else if from == "" && to == "" {
	} else {
		ifrom := 0
		ito := len(text)
		if from != "" {
			ifrom = vx_core.V_intn_from_stringn_findn(text, from)
			if ifrom < 0 {
				ifrom = 0
			}
		}
		if to != "" {
			ito = vx_core.V_intn_from_stringn_findn(text, to)
			if ito < 0 {
				ito = len(text)
			}
		}
		output = text[ifrom:ito]
	}
	return output
}

func StringFromStringIndent2(str string, indent int) string {
	output := vx_core.V_stringn_from_stringn_findn_replacen(str, "\n", "\n"+vx_core.V_stringn_from_stringn_repeatn("  ", indent))
	return output
}

func StringFromStringIndent(str string, indent string) string {
	output := vx_core.V_stringn_from_stringn_findn_replacen(str, "\n", "\n"+indent)
	return output
}

func StringFromListString(liststring []string) string {
	output := ""
	if len(liststring) > 0 {
		output = "(stringlist " + vx_core.V_stringn_from_liststringn_joinn(liststring, " ") + ")"
	}
	return output
}

func StringOutdentLines(str string, indent string) string {
	return vx_core.V_stringn_from_stringn_findn_replacen(str, "\n"+indent, "\n")
}

func StringRemoveQuotes(str string) string {
	var output = ""
	if strings.HasPrefix(str, "`") && strings.HasSuffix(str, "`") {
		output = str[1 : len(str)-1]
	} else if strings.HasPrefix(str, "\"") && strings.HasSuffix(str, "\"") {
		output = str[1 : len(str)-1]
		output = vx_core.V_stringn_from_stringn_findn_replacen(output, "\\\"", "\"")
	} else {
		output = str
	}
	return output
}

func StringTrim(str string) string {
	return strings.TrimSpace(str)
}
