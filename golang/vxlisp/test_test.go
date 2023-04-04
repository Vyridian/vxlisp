package vxlisp

func CompareInt(expected int, actual int, msgblock *vxmsgblock) string {
	errortext := ""
	if msgblock.iserror {
		errortext = StringFromMsgblock(msgblock)
	} else if expected != actual {
		errortext = StringFromInt(expected) + " != " + StringFromInt(actual)
	}
	return errortext
}

func CompareText(expected string, actual string, size int, msgblock *vxmsgblock) string {
	foundline := 0
	errortext := ""
	if msgblock.iserror {
		errortext = StringFromMsgblock(msgblock)
	} else if expected != actual {
		expectedlines := ListStringSplitFromStringDelim(expected, "\n")
		actuallines := ListStringSplitFromStringDelim(actual, "\n")
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
					paddingtext = StringRepeat(" ", padding-len(expectedline))
				}
				errortext := expectedline + paddingtext + " -> " + actualline
				if expectedline != actualline {
					errortext += " * Error *"
				}
				errortexts = append(errortexts, errortext)
			}
		}
		errortext = "Line: " + StringFromInt(foundline) + "\n" + StringJoinFromListString(errortexts, "\n")
	}
	return errortext
}
