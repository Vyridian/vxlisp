package main

import (
	"os"
	"vxcompiler/vxlisp"
)

func main() {
	args := os.Args
	vxlisp.ExecuteProjectFromArgs(args)
}
