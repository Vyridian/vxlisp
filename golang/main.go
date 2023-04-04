package main

import (
	"os"
	"sarvalex/vxlisp"
)

func main() {
	args := os.Args
	vxlisp.ExecuteProjectFromArgs(args)
}
