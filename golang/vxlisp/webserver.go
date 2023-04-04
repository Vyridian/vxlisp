package vxlisp

import (
	"log"
	"net/http"
)

func WebServerStart() {

	http.Handle("/", http.FileServer(http.Dir("../projects/myproject/build")))

	log.Fatal(http.ListenAndServe(":8081", nil))

}
