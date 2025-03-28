package vxlisp

import (
	"bufio"
	"fmt"
	"os"
)

var outputlog = false
var outputFile *os.File
var outputWriter *bufio.Writer

const MSGTYPE_ERROR = "Error"
const MSGTYPE_EXCEPTION = "Exception"
const MSGTYPE_INFO = "Info"
const MSGTYPE_WARNING = "Warning"

type vxmsg struct {
	msgtype string
	text    string
}

type vxmsgblock struct {
	name         string
	iserror      bool
	iswarning    bool
	listmsg      []*vxmsg
	listmsgblock []*vxmsgblock
}

var emptymsg = NewMsg()

func NewMsg(
	data ...interface{}) *vxmsg {
	output := new(vxmsg)
	var listtext []string
	for _, msg := range data {
		listtext = append(listtext, fmt.Sprint(msg))
	}
	output.text = StringFromListStringJoin(listtext, ", ")
	return output
}

func NewMsgBlock(
	name string) *vxmsgblock {
	output := new(vxmsgblock)
	output.name = name
	return output
}

func NewMsgFromTextblock(
	textblock *vxtextblock,
	line int,
	char int,
	path string,
	code string,
	data ...any) *vxmsg {
	output := new(vxmsg)
	var listsdata []string
	for _, msg := range data {
		listsdata = append(
			listsdata, fmt.Sprint(msg))
	}
	header := path
	if line > 0 {
		header += " Line:" + StringFromInt(line)
	}
	if char > 0 {
		header += " Char:" + StringFromInt(char)
	}
	header += "\n" + code + ":\n"
	textblockdata := "" +
		"\n" + textblock.name +
		" Line:" + StringFromInt(textblock.linenum) +
		" Char:" + StringFromInt(textblock.charnum)
	sdata := StringFromListStringJoin(listsdata, "\n")
	body := textblock.text
	if line < 10 {
	} else if textblock.linenum == 1 && textblock.charnum == 1 {
		startline := line - 5
		endline := line + 5
		istartpos := IntFromStringFindNth(body, "\n", startline)
		iendpos := IntFromStringFindNth(body, "\n", endline)
		if istartpos > 0 && iendpos > 0 {
			body = body[istartpos:iendpos]
		}
	}
	output.text = "" +
		header +
		sdata +
		textblockdata +
		"\n" +
		body +
		"\n" +
		header +
		sdata +
		"\n"
	return output
}

func IsErrorFromMsgblock(
	msgblock *vxmsgblock) bool {
	return msgblock.iserror
}

func IsWarningFromMsgblock(
	msgblock *vxmsgblock) bool {
	return msgblock.iswarning
}

func MsgLog(
	output ...interface{}) {
	fmt.Println(output...)
	if outputlog {
		_, err := fmt.Fprintln(outputWriter, output...)
		if err != nil {
			fmt.Println(err)
		}
	}
}

func MsgPrint(
	output ...interface{}) {
	fmt.Println(output...)
}

func MsgStartLog() {
	var err error
	outputFile, err = os.Create("build.log")
	if err != nil {
		panic(err)
	}
	outputWriter = bufio.NewWriter(outputFile)
	outputlog = true
}

func MsgStopLog() {
	if outputlog {
		outputWriter.Flush()
		outputFile.Close()
	}
}

func MsgblockAddBlock(
	msgblock *vxmsgblock,
	addblock *vxmsgblock) *vxmsgblock {
	var output = msgblock
	if addblock.iserror {
		output.iserror = true
	}
	if addblock.iswarning {
		output.iswarning = true
	}
	output.listmsgblock = append(output.listmsgblock, addblock)
	return output
}

func MsgblockAddError(
	msgblock *vxmsgblock,
	msg *vxmsg) *vxmsgblock {
	var output = msgblock
	if msg != emptymsg {
		msg.msgtype = MSGTYPE_ERROR
		output.iserror = true
		output.listmsg = append(output.listmsg, msg)
	}
	return output
}

func MsgblockAddException(
	msgblock *vxmsgblock,
	err error) *vxmsgblock {
	var output = msgblock
	if err != nil {
		msg := NewMsg(err.Error())
		msg.msgtype = MSGTYPE_EXCEPTION
		output.iserror = true
		output = MsgblockAddError(msgblock, msg)
	}
	return output
}

func MsgblockAddInfo(
	msgblock *vxmsgblock,
	msg *vxmsg) *vxmsgblock {
	var output = msgblock
	if msg != emptymsg {
		msg.msgtype = MSGTYPE_INFO
		output.listmsg = append(output.listmsg, msg)
	}
	return output
}

func MsgblockAddWarning(
	msgblock *vxmsgblock,
	msg *vxmsg) *vxmsgblock {
	var output = msgblock
	if msg != emptymsg {
		msg.msgtype = MSGTYPE_WARNING
		output.iswarning = true
		output.listmsg = append(output.listmsg, msg)
	}
	return output
}

func MsgblockLog(
	msgblock *vxmsgblock) {
	text := StringFromMsgblock(msgblock)
	fmt.Println(text)
	_, err := fmt.Fprintln(outputWriter, text)
	if err != nil {
		fmt.Println(err)
	}
}

func StringFromMsgblock(
	msgblock *vxmsgblock) string {
	var text string
	if len(msgblock.listmsg) > 0 {
		text += msgblock.name + "\n\n"
		for _, msg := range msgblock.listmsg {
			text += msg.msgtype + ": " + msg.text + "\n"
		}
	}
	if len(msgblock.listmsgblock) > 0 {
		for _, submsgs := range msgblock.listmsgblock {
			text += StringFromMsgblock(submsgs)
		}
	}
	return text
}

func StringFromListMsg(
	listmsg []*vxmsg) string {
	var text string
	for _, msg := range listmsg {
		text += msg.msgtype + " " + msg.text
	}
	return text
}
