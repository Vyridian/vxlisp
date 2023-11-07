package vxlisp

type vxtextblock struct {
	name          string
	blocktype     string
	linenum       int
	charnum       int
	text          string
	listtextblock []*vxtextblock
}

var emptytextblock = NewTextblock()

func NewTextblock() *vxtextblock {
	output := new(vxtextblock)
	output.linenum = 1
	output.charnum = 1
	return output
}

func NewTextblockFromText(text string) *vxtextblock {
	output := NewTextblock()
	output.text = text
	return output
}

func StringFromTextblock(textblock *vxtextblock) string {
	return StringFromTextblockIndent(textblock, "")
}

func StringFromTextblockStartEnd(textblock *vxtextblock, startline int, startchar int, endline int, endchar int) string {
	output := ""
	text := textblock.text
	startlinenum := startline - textblock.linenum
	endlinenum := endline - textblock.linenum
	startpos := 0
	endpos := 0
	if startlinenum == 0 {
		startpos = startchar - textblock.charnum
	} else {
		startpos = IntFromStringFindNth(text, "\n", startlinenum) + startchar
	}
	if endlinenum == 0 {
		endpos = endchar - textblock.charnum + 1
	} else {
		endpos = IntFromStringFindNth(text, "\n", endlinenum) + endchar + 1
	}
	output = StringSubstring(text, startpos, endpos)
	if startchar > 1 {
		outdent := StringRepeat(" ", startchar-1)
		suboutputs := ListStringFromStringSplitByDelims(output, "/*", "*/")
		var chgoutputs []string
		for _, suboutput := range suboutputs {
			if !BooleanFromStringStarts(suboutput, "/*") {
				suboutput = StringOutdentLines(suboutput, outdent)
			}
			chgoutputs = append(chgoutputs, suboutput)
		}
		output = StringFromListStringJoin(chgoutputs, "")
	}
	return output
}

func StringFromTextblocks(textblocks []*vxtextblock, indent string) string {
	var output = ""
	if len(textblocks) == 0 {
		output = "(textblocklist)"
	} else {
		if indent != "" {
			output += "\n" + indent
		}
		output += "(textblocklist\n"
		for _, textblock := range textblocks {
			output += StringFromTextblockIndent(textblock, indent+" ")
		}
		output += indent + ")"
	}
	return output
}

func StringFromTextblockIndent(textblock *vxtextblock, indent string) string {
	text := textblock.text
	if IntFromStringFind(textblock.text, "\n") >= 0 {
		text = "\n" + text
	}
	output := "" +
		indent + "(textblock" +
		"\n" + indent + " :name       " + textblock.name +
		"\n" + indent + " :blocktype  " + textblock.blocktype +
		"\n" + indent + " :linenum    " + StringFromInt(textblock.linenum) +
		"\n" + indent + " :charnum    " + StringFromInt(textblock.charnum) +
		"\n" + indent + " :text       \"" + text + "\"" +
		"\n" + indent + " :textblocks " + StringFromTextblocks(textblock.listtextblock, indent+"  ") +
		")\n"
	return output
}

func TextblockParse(textblock *vxtextblock) (*vxtextblock, *vxmsgblock) {
	msgblock := NewMsgBlock("TextblockParse")
	output := textblock
	BLOCKTYPE_UNDEFINED := ""
	BLOCKTYPE_COMMENTBLOCK := "/*"
	BLOCKTYPE_QUOTEBLOCK := "`"
	BLOCKTYPE_QUOTE := "\""
	BLOCKTYPE_PARENS := "("
	BLOCKTYPE_SQRBRACKETS := "["
	BLOCKTYPE_CLYBRACKETS := "{"
	BLOCKTYPE_COMMENT := "//"
	BLOCKTYPE_TEXT := "text"
	linenum := 1
	charnum := 0
	phrase := textblock
	state := BLOCKTYPE_UNDEFINED
	phrase.blocktype = state
	blockstack := []*vxtextblock{}
	word := ""
	lastchar := ""
	quoteindent := 0
	startline := 0
	startchar := 0
	text := textblock.text
	text = StringFromStringFindReplace(text, "\r\n", "\n")
	text = StringFromStringFindReplace(text, "\r", "\n")
	for _, rune := range text {
		char := string(rune)
		switch char {
		case "\n":
			linenum += 1
			charnum = 0
		default:
			charnum += 1
		}
		switch state {
		case BLOCKTYPE_UNDEFINED:
			switch char {
			case "\n", "\t", " ", "/":
			case "(":
				blockstack = append(blockstack, phrase)
				phrase = NewTextblock()
				phrase.name = textblock.name
				phrase.linenum = linenum
				phrase.charnum = charnum
				phrase.blocktype = BLOCKTYPE_PARENS
				state = BLOCKTYPE_PARENS
			default:
				if lastchar == "/" && char == "*" {
					state = BLOCKTYPE_COMMENTBLOCK
				} else {
					msg := NewMsgFromTextblock(textblock, "Invalid Character", char, "line:", linenum, "char:", charnum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			}
		case BLOCKTYPE_COMMENT:
			switch char {
			case "\n":
				wordtextblock := NewTextblockFromText(word)
				wordtextblock.blocktype = BLOCKTYPE_COMMENT
				wordtextblock.name = textblock.name
				wordtextblock.linenum = startline
				wordtextblock.charnum = startchar
				phrase.listtextblock = append(phrase.listtextblock, wordtextblock)
				startline = 0
				startchar = 0
				word = ""
				state = phrase.blocktype
			default:
				word += char
			}
		case BLOCKTYPE_COMMENTBLOCK:
			word += char
			if lastchar == "*" && char == "/" {
				wordtextblock := NewTextblockFromText(word)
				wordtextblock.blocktype = BLOCKTYPE_COMMENTBLOCK
				wordtextblock.name = textblock.name
				wordtextblock.linenum = startline
				wordtextblock.charnum = startchar
				phrase.listtextblock = append(phrase.listtextblock, wordtextblock)
				startline = 0
				startchar = 0
				word = ""
				state = phrase.blocktype
			}
		case BLOCKTYPE_QUOTEBLOCK:
			switch char {
			case "`":
				wordtextblock := NewTextblockFromText(word)
				wordtextblock.blocktype = BLOCKTYPE_QUOTEBLOCK
				wordtextblock.name = textblock.name
				wordtextblock.linenum = startline
				wordtextblock.charnum = startchar
				phrase.listtextblock = append(phrase.listtextblock, wordtextblock)
				startline = 0
				startchar = 0
				word = ""
				state = phrase.blocktype
			default:
				word += char
			}
		case BLOCKTYPE_QUOTE:
			switch char {
			case "\"":
				if lastchar == "\\" {
					word += char
				} else {
					if IntFromStringFind(word, "\n") >= 0 {
						indentchars := StringRepeat(" ", quoteindent)
						wordlines := ListStringFromStringSplit(word, "\n")
						for wordidx, wordline := range wordlines {
							switch wordidx {
							case 0:
								word += wordline
							default:
								if quoteindent == 0 {
								} else if BooleanFromStringStarts(wordline, indentchars) {
									wordlines[wordidx] = wordline[len(indentchars):]
								}
							}
						}
						word = StringFromListStringJoin(wordlines, "\n")
					}
					wordtextblock := NewTextblockFromText(word)
					wordtextblock.blocktype = BLOCKTYPE_QUOTE
					wordtextblock.name = textblock.name
					wordtextblock.linenum = startline
					wordtextblock.charnum = startchar
					phrase.listtextblock = append(phrase.listtextblock, wordtextblock)
					startline = 0
					startchar = 0
					word = ""
					state = phrase.blocktype
				}
			default:
				if startline == 0 {
					startline = linenum
					startchar = charnum
				}
				word += char
			}
		case BLOCKTYPE_PARENS, BLOCKTYPE_CLYBRACKETS, BLOCKTYPE_SQRBRACKETS:
			switch char {
			case "\n", "\t", " ":
				if len(word) > 0 {
					wordtextblock := NewTextblockFromText(word)
					wordtextblock.blocktype = BLOCKTYPE_TEXT
					wordtextblock.name = textblock.name
					wordtextblock.linenum = startline
					wordtextblock.charnum = startchar
					phrase.listtextblock = append(phrase.listtextblock, wordtextblock)
					startline = 0
					startchar = 0
					word = ""
				}
			case "/":
				word += char
				if BooleanFromStringStarts(word, "//") {
					startline = linenum
					startchar = charnum - 1
					word = ""
					state = BLOCKTYPE_COMMENT
				}
			case "\"":
				if len(word) > 0 {
					msg := NewMsgFromTextblock(textblock, "New Quote started without Whitespace", linenum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
				startline = linenum
				startchar = charnum
				word = ""
				quoteindent = charnum
				state = BLOCKTYPE_QUOTE
			case "`":
				if len(word) > 0 {
					msg := NewMsgFromTextblock(textblock, "New Block Quote started without Whitespace Line:", linenum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
				startline = linenum
				startchar = charnum
				word = ""
				state = BLOCKTYPE_QUOTEBLOCK
			case "(":
				if lastchar == "\n" {
					msg := NewMsgFromTextblock(textblock, "New Open Paren started without completed Close Paren Line:", linenum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
				if len(word) > 0 {
					msg := NewMsgFromTextblock(textblock, "New Open Paren started without Whitespace Line:", linenum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
				blockstack = append(blockstack, phrase)
				phrase = NewTextblock()
				phrase.name = textblock.name
				phrase.linenum = linenum
				phrase.charnum = charnum
				phrase.blocktype = BLOCKTYPE_PARENS
				startline = 0
				startchar = 0
				word = ""
				state = BLOCKTYPE_PARENS
			case "[":
				if len(word) > 0 {
					msg := NewMsgFromTextblock(textblock, "New [] started without Whitespace", linenum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
				blockstack = append(blockstack, phrase)
				phrase = NewTextblock()
				phrase.name = textblock.name
				phrase.linenum = linenum
				phrase.charnum = charnum
				phrase.blocktype = BLOCKTYPE_SQRBRACKETS
				startline = 0
				startchar = 0
				word = ""
				state = BLOCKTYPE_SQRBRACKETS
			case "{":
				if len(word) > 0 {
					msg := NewMsgFromTextblock(textblock, "New {} started without Whitespace", linenum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
				blockstack = append(blockstack, phrase)
				phrase = NewTextblock()
				phrase.name = textblock.name
				phrase.linenum = linenum
				phrase.charnum = charnum
				phrase.blocktype = BLOCKTYPE_CLYBRACKETS
				startline = 0
				startchar = 0
				word = ""
				state = BLOCKTYPE_CLYBRACKETS
			case ")", "]", "}":
				var pair = state + char
				switch pair {
				case "()", "[]", "{}":
					if len(word) > 0 {
						wordtextblock := NewTextblockFromText(word)
						wordtextblock.blocktype = BLOCKTYPE_TEXT
						wordtextblock.name = textblock.name
						wordtextblock.linenum = startline
						wordtextblock.charnum = startchar
						phrase.listtextblock = append(phrase.listtextblock, wordtextblock)
						word = ""
					}
					phrase.text = StringFromTextblockStartEnd(textblock, phrase.linenum, phrase.charnum, linenum, charnum)
					var prevphrase *vxtextblock
					prevphrase, blockstack = TextblocksPop(blockstack)
					prevphrase.listtextblock = append(prevphrase.listtextblock, phrase)
					phrase = prevphrase
					startline = 0
					startchar = 0
					state = phrase.blocktype
				default:
					msg := NewMsgFromTextblock(textblock, "Mismatched Delimiters: ", state, char, linenum, charnum)
					msgblock = MsgblockAddError(msgblock, msg)
				}
			default:
				word += char
				if lastchar == "/" && char == "*" {
					if len(word) > 2 {
						msg := NewMsgFromTextblock(textblock, "New Comment Block started without whitespace", linenum)
						msgblock = MsgblockAddError(msgblock, msg)
					}
					startline = linenum
					startchar = charnum - 1
					state = BLOCKTYPE_COMMENTBLOCK
				} else if startline == 0 {
					startline = linenum
					startchar = charnum
				}
			}
		}
		lastchar = char
	}
	for _, stateblock := range blockstack {
		state = stateblock.blocktype
		switch state {
		case BLOCKTYPE_UNDEFINED:
		default:
			var delim = "Unknown"
			switch state {
			case BLOCKTYPE_CLYBRACKETS:
				delim = "Curly Brackets"
			case BLOCKTYPE_PARENS:
				delim = "Quotes"
			case BLOCKTYPE_QUOTE:
				delim = "Quotes"
			case BLOCKTYPE_QUOTEBLOCK:
				delim = "Block Quotes"
			case BLOCKTYPE_SQRBRACKETS:
				delim = "Square Brackets"
			}
			msg := NewMsgFromTextblock(textblock, "Mismatched Delimiter: ", delim)
			msgblock = MsgblockAddError(msgblock, msg)
		}
	}
	output = phrase
	return output, msgblock
}

func TextblocksPop(textblocks []*vxtextblock) (*vxtextblock, []*vxtextblock) {
	block := textblocks[len(textblocks)-1]
	blocks := textblocks[:len(textblocks)-1]
	return block, blocks
}
