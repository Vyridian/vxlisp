package main

import (
	"os"
	"vxlisp/vxlisp"
)

func main() {
	args := os.Args
	vxlisp.ExecuteProjectFromArgs(args)
}
