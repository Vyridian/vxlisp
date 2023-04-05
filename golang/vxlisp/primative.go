package vxlisp

import (
	"sort"
	"strconv"
	"strings"
)

func NewMapString() map[string]string {
	return make(map[string]string)
}

func BooleanFromListStringContains(liststring []string, contains string) bool {
	output := false
	pos := IntFromListStringIndex(liststring, contains)
	if pos >= 0 {
		output = true
	}
	return output
}

func BooleanFromStringContains(str string, contains string) bool {
	return strings.Contains(str, contains)
}

func BooleanFromStringEnds(str string, ends string) bool {
	return strings.HasSuffix(str, ends)
}

func BooleanFromStringStarts(str string, starts string) bool {
	return strings.HasPrefix(str, starts)
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

func IntFromListStringIndex(texts []string, index string) int {
	output := -1
	for pos, text := range texts {
		if text == index {
			output = pos
		}
	}
	return output
}

func IntFromStringIndex(str string, index string) int {
	return strings.Index(str, index)
}

func IntFromStringIndexLast(str string, indexlast string) int {
	return strings.LastIndex(str, indexlast)
}

func IntFromStringIndexNth(str string, index string, nth int) int {
	output := -1
	i := 0
	for m := 1; m <= nth; m++ {
		x := strings.Index(str[i:], index)
		if x < 0 {
			break
		}
		i += x
		if m == nth {
			output = i
			break
		}
		i += len(index)
	}
	return output
}

func ListStringFromStringSplitByDelims(str string, startdelim string, enddelim string) []string {
	var output []string
	worktext := str
	isdone := false
	for ok := true; ok; ok = !isdone {
		startpos := IntFromStringIndex(worktext, startdelim)
		if startpos < 0 {
			isdone = true
			output = append(output, worktext)
		} else {
			output = append(output, worktext[0:startpos])
			worktext = worktext[startpos:]
			endpos := IntFromStringIndex(worktext, enddelim)
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

func ListStringFromStringSplit(str string, delim string) []string {
	return strings.Split(str, delim)
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

func StringFromInt(intval int) string {
	return strconv.Itoa(intval)
}

func StringFromStringIndent(str string, indent string) string {
	output := StringFromStringFindReplace(str, "\n", "\n"+indent)
	return output
}

func StringFromListString(liststring []string) string {
	output := ""
	if len(liststring) > 0 {
		output = "(stringlist " + StringFromListStringJoin(liststring, " ") + ")"
	}
	return output
}

func StringFromListStringJoin(liststring []string, delim string) string {
	return strings.Join(liststring, delim)
}

func StringOutdentLines(str string, indent string) string {
	return StringFromStringFindReplace(str, "\n"+indent, "\n")
}

func StringRemoveQuotes(str string) string {
	var output = ""
	if strings.HasPrefix(str, "`") && strings.HasSuffix(str, "`") {
		output = str[1 : len(str)-1]
	} else if strings.HasPrefix(str, "\"") && strings.HasSuffix(str, "\"") {
		output = str[1 : len(str)-1]
		output = StringFromStringFindReplace(output, "\\\"", "\"")
	} else {
		output = str
	}
	return output
}

func StringRepeat(str string, repeat int) string {
	return strings.Repeat(str, repeat)
}

func StringFromStringFindReplace(str string, find string, replace string) string {
	return strings.ReplaceAll(str, find, replace)
}

func StringSubstring(str string, startpos int, endpos int) string {
	startnum := startpos
	endnum := endpos
	if startnum < 0 {
		startnum = 0
	}
	if endnum < startnum {
		endnum = startnum
	}
	if len(str) < startnum {
		startnum = 0
	}
	if len(str) < endnum {
		endnum = len(str)
	}
	return str[startnum:endnum]
}

func StringTrim(str string) string {
	return strings.TrimSpace(str)
}

func StringUCaseFirst(str string) string {
	output := ""
	if len(str) > 0 {
		output = strings.ToUpper(str[0:1]) + str[1:]
	}
	return output
}
