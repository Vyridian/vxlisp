DIR_ROOT=.
DIR_MAIN=main
DIR_TEST=test
DIRS_SUB=vx vx/data vx/web
DIRS_INC=$(DIR_ROOT)/include/

CC=g++
OPT=-O3
DEPFLAGS=-MP -MD
CFLAGS=-lstdc++ -Wextra -g $(foreach DIR,$(DIRS_INC),-I$(DIR) $(OPT) $(DEPFLAGS))

DIR_MAINCPP=$(DIR_ROOT)/src/$(DIR_MAIN)
DIR_MAINDEP=$(DIR_ROOT)/deps/$(DIR_MAIN)
DIR_MAINOBJ=$(DIR_ROOT)/build/$(DIR_MAIN)
DIR_TESTCPP=$(DIR_ROOT)/src/$(DIR_TEST)
DIR_TESTDEP=$(DIR_ROOT)/deps/$(DIR_TEST)
DIR_TESTOBJ=$(DIR_ROOT)/build/$(DIR_TEST)

FILE_MAINAPP=$(DIR_MAINOBJ)/app.exe
FILE_TESTAPP=$(DIR_TESTOBJ)/app_test.exe

FILE_MAINOBJAPP=$(DIR_MAINOBJ)/app.o
FILE_MAINDEPAPP=$(DIR_MAINDEP)/app.d
FILE_TESTOBJAPP=$(DIR_TESTOBJ)/app_test.o $(DIR_TESTOBJ)/test_lib.o

FILES_MAINCPP=$(foreach DIR,$(DIRS_SUB),$(wildcard $(DIR_MAINCPP)/$(DIR)/*.cpp))
FILES_MAINDEP=$(patsubst $(DIR_MAINCPP)/%.cpp,$(DIR_MAINDEP)/%.d,$(FILES_MAINCPP))
FILES_MAINOBJ=$(patsubst $(DIR_MAINCPP)/%.cpp,$(DIR_MAINOBJ)/%.o,$(FILES_MAINCPP))

FILES_TESTCPP=$(foreach DIR,$(DIRS_SUB),$(wildcard $(DIR_TESTCPP)/$(DIR)/*.cpp))
FILES_TESTDEP=$(patsubst $(DIR_TESTCPP)/%.cpp,$(DIR_TESTDEP)/%.d,$(FILES_TESTCPP))
FILES_TESTOBJ=$(patsubst $(DIR_TESTCPP)/%.cpp,$(DIR_TESTOBJ)/%.o,$(FILES_TESTCPP))

all:
	appmain
	apptest

appmain: $(FILES_MAINOBJ) $(FILE_MAINOBJAPP)
	$(CC) -o $(FILE_MAINAPP) $^

apptest: $(FILES_TESTOBJ) $(FILE_TESTOBJAPP)
	$(CC) -o $(FILE_TESTAPP) $^ $(FILES_MAINOBJ)

clean:
	cleanmain
	cleantest

cleanmain:
	rm -rf $(FILE_MAINAPP) $(FILE_MAINOBJAPP) $(FILE_MAINDEPAPP) $(FILES_MAINOBJ) $(FILES_MAINDEP)

cleantest:
	rm -rf $(FILE_TESTAPP) $(FILES_TESTOBJ) $(FILES_TESTDEP)

echomaincpp:
	echo $(DIR_MAINCPP)
	echo $(FILES_MAINCPP)

echomaindep:
	echo $(DIR_MAINDEP)
	echo $(FILES_MAINDEP)

echomainobj:
	echo $(DIR_MAINOBJ)
	echo $(FILES_MAINOBJ)

echotestcpp:
	echo $(DIR_TESTCPP)
	echo $(FILES_TESTCPP)

echotestdep:
	echo $(DIR_TESTDEP)
	echo $(FILES_TESTDEP)

echotestobj:
	echo $(DIR_TESTOBJ)
	echo $(FILES_TESTOBJ)

$(DIR_MAINOBJ)/%.o:$(DIR_MAINCPP)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -MF"$(patsubst $(DIR_MAINOBJ)/%.o,$(DIR_MAINDEP)/%.d,./$@)"

$(DIR_TESTOBJ)/%.o:$(DIR_TESTCPP)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -MF"$(patsubst $(DIR_TESTOBJ)/%.o,$(DIR_TESTDEP)/%.d,./$@)"
