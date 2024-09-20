package vxlisp

import (
	"testing"
)

func TestTextblockParse(t *testing.T) {
	msgblock := NewMsgBlock("TestTextblockParse")
	blocktext := `(t1)

(f1
 "v1"
 v2
 (f2
  [k1 : t1 := v3 // comment
   k2 : t2 := (f4 "a" 1)]
/*
 Notes
 */
  v4))`
	textblock := NewTextblockFromText(blocktext)
	textblock.name = "samplepath/samplefile.vxlisp"
	textblock, msgs := TextblockParse(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expectedblock := NewTextblock()
	expectedblock.blocktype = ""
	expectedblock.name = textblock.name
	expectedblock.text = blocktext
	subblock := NewTextblock()
	subblock.blocktype = "("
	subblock.name = textblock.name
	subblock.text = "(t1)"
	subblock1 := NewTextblock()
	subblock1.blocktype = "text"
	subblock1.name = textblock.name
	subblock1.linenum = 1
	subblock1.charnum = 2
	subblock1.text = "t1"
	subblock.listtextblock = append(subblock.listtextblock, subblock1)
	expectedblock.listtextblock = append(expectedblock.listtextblock, subblock)
	subblock = NewTextblock()
	subblock.blocktype = "("
	subblock.name = textblock.name
	subblock.linenum = 3
	subblock.charnum = 1
	subblock.text = `(f1
 "v1"
 v2
 (f2
  [k1 : t1 := v3 // comment
   k2 : t2 := (f4 "a" 1)]
/*
 Notes
 */
  v4))`
	subblock1 = NewTextblock()
	subblock1.blocktype = "text"
	subblock1.name = textblock.name
	subblock1.linenum = 3
	subblock1.charnum = 2
	subblock1.text = "f1"
	subblock.listtextblock = append(subblock.listtextblock, subblock1)
	subblock1 = NewTextblock()
	subblock1.blocktype = "\""
	subblock1.name = textblock.name
	subblock1.linenum = 4
	subblock1.charnum = 2
	subblock1.text = "v1"
	subblock.listtextblock = append(subblock.listtextblock, subblock1)
	subblock1 = NewTextblock()
	subblock1.blocktype = "text"
	subblock1.name = textblock.name
	subblock1.linenum = 5
	subblock1.charnum = 2
	subblock1.text = "v2"
	subblock.listtextblock = append(subblock.listtextblock, subblock1)
	subblock1 = NewTextblock()
	subblock1.blocktype = "("
	subblock1.name = textblock.name
	subblock1.text = `(f2
 [k1 : t1 := v3 // comment
  k2 : t2 := (f4 "a" 1)]
/*
 Notes
 */
 v4)`
	subblock1.linenum = 6
	subblock1.charnum = 2
	subblock2 := NewTextblock()
	subblock2.blocktype = "text"
	subblock2.name = textblock.name
	subblock2.linenum = 6
	subblock2.charnum = 3
	subblock2.text = "f2"
	subblock1.listtextblock = append(subblock1.listtextblock, subblock2)
	subblock2 = NewTextblock()
	subblock2.blocktype = "["
	subblock2.name = textblock.name
	subblock2.linenum = 7
	subblock2.charnum = 3
	subblock2.text = `[k1 : t1 := v3 // comment
 k2 : t2 := (f4 "a" 1)]`
	subblock3 := NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 7
	subblock3.charnum = 4
	subblock3.text = "k1"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 7
	subblock3.charnum = 7
	subblock3.text = ":"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 7
	subblock3.charnum = 9
	subblock3.text = "t1"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 7
	subblock3.charnum = 12
	subblock3.text = ":="
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 7
	subblock3.charnum = 15
	subblock3.text = "v3"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "//"
	subblock3.name = textblock.name
	subblock3.linenum = 7
	subblock3.charnum = 18
	subblock3.text = " comment"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 8
	subblock3.charnum = 4
	subblock3.text = "k2"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 8
	subblock3.charnum = 7
	subblock3.text = ":"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 8
	subblock3.charnum = 9
	subblock3.text = "t2"
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "text"
	subblock3.name = textblock.name
	subblock3.linenum = 8
	subblock3.charnum = 12
	subblock3.text = ":="
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock3 = NewTextblock()
	subblock3.blocktype = "("
	subblock3.name = textblock.name
	subblock3.linenum = 8
	subblock3.charnum = 15
	subblock3.text = `(f4 "a" 1)`
	subblock4 := NewTextblock()
	subblock4.blocktype = "text"
	subblock4.name = textblock.name
	subblock4.linenum = 8
	subblock4.charnum = 16
	subblock4.text = "f4"
	subblock3.listtextblock = append(subblock3.listtextblock, subblock4)
	subblock4 = NewTextblock()
	subblock4.blocktype = "\""
	subblock4.name = textblock.name
	subblock4.linenum = 8
	subblock4.charnum = 19
	subblock4.text = "a"
	subblock3.listtextblock = append(subblock3.listtextblock, subblock4)
	subblock4 = NewTextblock()
	subblock4.blocktype = "text"
	subblock4.name = textblock.name
	subblock4.linenum = 8
	subblock4.charnum = 23
	subblock4.text = "1"
	subblock3.listtextblock = append(subblock3.listtextblock, subblock4)
	subblock2.listtextblock = append(subblock2.listtextblock, subblock3)
	subblock1.listtextblock = append(subblock1.listtextblock, subblock2)
	subblock2 = NewTextblock()
	subblock2.blocktype = "/*"
	subblock2.name = textblock.name
	subblock2.linenum = 9
	subblock2.charnum = 1
	subblock2.text = "/*\n Notes\n */"
	subblock1.listtextblock = append(subblock1.listtextblock, subblock2)
	subblock2 = NewTextblock()
	subblock2.blocktype = "text"
	subblock2.name = textblock.name
	subblock2.linenum = 12
	subblock2.charnum = 3
	subblock2.text = "v4"
	subblock1.listtextblock = append(subblock1.listtextblock, subblock2)
	subblock.listtextblock = append(subblock.listtextblock, subblock1)
	expectedblock.listtextblock = append(expectedblock.listtextblock, subblock)
	expected := StringFromTextblock(expectedblock)
	actual := StringFromTextblock(textblock)
	errortext := CompareText(expected, actual, 10, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}

func TestTextblockToTextWithin(t *testing.T) {
	msgblock := NewMsgBlock("TestTextblockToTextWithin")
	blocktext := `(type)

(const c1)
\/*
(const c2)
*\/

(func)`
	textblock := NewTextblockFromText(blocktext)
	expected := "type"
	actual := StringFromTextblockStartEnd(textblock, 1, 2, 1, 5)
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
	expected = "(const c1)"
	actual = StringFromTextblockStartEnd(textblock, 3, 1, 3, 10)
	errortext = CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}
