package vxlisp

import (
	"testing"
)

func TestStringIndexNth(t *testing.T) {
	msgblock := NewMsgBlock("TestStringIndexNth")
	text := "abccdce"
	expected := 5
	actual := IntFromStringIndexNth(text, "c", 3)
	errortext := CompareInt(expected, actual, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}
}
