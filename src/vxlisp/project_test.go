package vxlisp

import (
	"testing"
)

func TestProjectFromTextblock(t *testing.T) {
	msgblock := NewMsgBlock("TestProjectFromTextblock")
	typetext := `(project myproject
 :version "0.1"
 :author  "Joe"
 :doc     "Project doc"
 :libs
  (lib javaniofile
   :path "java.nio.file.*"
   :lang :java)
 :paths
  (path projectpath
   :path ../projects/myproject)
 :cmds
  (cmd doc
   :code      :doc
   :path      *projectpath*/build/doc
   :doc       "Build documentation html")
	(cmd webserver
   :code      :webserver
   :doc       "Run Simple Web Server")
  (cmd srcjs
   :code      :source
   :lang      :js
   :path      *projectpath*/build/js/src)
  (cmd testjs
   :code      :test
   :lang      :js
   :path      *projectpath*/build/js/test)
  (cmd srcjava
   :code      :source
   :lang      :java
   :path      *projectpath*/build/java/src)
  (cmd testjava
   :code      :test
   :lang      :java
   :path      *projectpath*/build/java/test)
)`
	textblock := NewTextblockFromText(typetext)
	textblock.name = "testfile.vxlisp"
	prj, msgs := ProjectFromTextblock(textblock)
	msgblock = MsgblockAddBlock(msgblock, msgs)
	expectedprj := NewProject("myproject")
	expectedprj.author = "Joe"
	expectedprj.version = "0.1"
	expectedprj.doc = "Project doc"

	lib := NewLibrary()
	lib.name = "javaniofile"
	lib.path = "java.nio.file.*"
	lib.lang = ":java"
	expectedprj.listlib = append(expectedprj.listlib, lib)

	cmd := NewCommand()
	cmd.name = "doc"
	cmd.code = ":doc"
	cmd.path = "*projectpath*/build/doc"
	cmd.doc = "Build documentation html"
	expectedprj.listcmd = append(expectedprj.listcmd, cmd)

	cmd = NewCommand()
	cmd.name = "webserver"
	cmd.code = ":webserver"
	cmd.doc = "Run Simple Web Server"
	expectedprj.listcmd = append(expectedprj.listcmd, cmd)

	cmd = NewCommand()
	cmd.name = "srcjs"
	cmd.code = ":source"
	cmd.langcode = ":js"
	cmd.path = "*projectpath*/build/js/src"
	expectedprj.listcmd = append(expectedprj.listcmd, cmd)

	cmd = NewCommand()
	cmd.name = "testjs"
	cmd.code = ":test"
	cmd.langcode = ":js"
	cmd.path = "*projectpath*/build/js/test"
	expectedprj.listcmd = append(expectedprj.listcmd, cmd)

	cmd = NewCommand()
	cmd.name = "srcjava"
	cmd.code = ":source"
	cmd.langcode = ":java"
	cmd.path = "*projectpath*/build/java/src"
	expectedprj.listcmd = append(expectedprj.listcmd, cmd)

	cmd = NewCommand()
	cmd.name = "testjava"
	cmd.code = ":test"
	cmd.langcode = ":java"
	cmd.path = "*projectpath*/build/java/test"
	expectedprj.listcmd = append(expectedprj.listcmd, cmd)

	path := NewPath()
	path.name = "projectpath"
	path.path = "../projects/myproject"
	expectedprj.listpath = append(expectedprj.listpath, path)

	expected := StringFromProject(expectedprj)
	actual := StringFromProject(prj)
	errortext := CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}

	expected = `(cmdlist
 (cmd
  :name doc
  :code :doc
  :lang 
  :path *projectpath*/build/doc
  :doc  Build documentation html)
 (cmd
  :name testjs
  :code :test
  :lang :js
  :path *projectpath*/build/js/test
  :doc  ))`
	cmdtexts := []string{"doc", "testjs"}
	cmds := ListCommandFromProject(prj, cmdtexts)
	actual = StringFromListCmd(cmds)
	errortext = CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}

	expected = "../projects/myproject/build/java/test"
	actual = StringPathFromProjectCmd(prj, cmd)
	errortext = CompareText(expected, actual, 20, msgblock)
	if errortext != "" {
		t.Error(errortext)
	}

}
