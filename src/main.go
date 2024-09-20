package main

import (
	"os"
	"vxlisp-compiler/vxlisp"
)

func main() {
	args := os.Args
	vxlisp.ExecuteProjectFromArgs(args)
}
