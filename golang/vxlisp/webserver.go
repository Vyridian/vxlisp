package vxlisp

import (
	"log"
	"net/http"
)

func WebServerStart(project *vxproject, command *vxcommand) {
	path := PathFromProjectCmd(project, command)
	port := command.port
	if port == 0 {
		port = 8081
	}

	MsgPrint("Webserver running on http://localhost:" + StringFromInt(port) + "/html")
	http.Handle("/", http.FileServer(http.Dir(path)))

	log.Fatal(http.ListenAndServe(":"+StringFromInt(port), nil))

}
