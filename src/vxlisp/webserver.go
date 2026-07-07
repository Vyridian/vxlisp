package vxlisp

import (
	"log"
	"net/http"
	vx_core "vxlisp/vxlisp/vx/core"
)

func WebServerStart(project *vxproject, command *vxcommand) {
	path := PathFromProjectCmd(project, command)
	port := command.port
	if port == 0 {
		port = 8081
	}

	MsgPrint("Webserver running on http://localhost:" + vx_core.V_stringn_from_intn(port) + "/public")
	http.Handle("/", http.FileServer(http.Dir(path)))

	log.Fatal(http.ListenAndServe(":"+vx_core.V_stringn_from_intn(port), nil))

}
