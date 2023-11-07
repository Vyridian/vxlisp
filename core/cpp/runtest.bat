cls
rem make cleanmain
rem make cleantest
rem del app_test.exe
make apptest
rem build/main/vx/repl.o build/main/vx/data/xml.o build/main/vx/web/http.o 
rem build/test/vx/repl_test.o build/test/vx/data/xml_test.o build/test/vx/web/http_test.o
rem g++ -o app_test.exe build/test/app_test.o build/main/vx/core.o build/main/vx/type.o build/main/vx/collection.o build/main/vx/event.o build/main/vx/sample.o build/main/vx/state.o build/main/vx/data/table.o build/main/vx/data/textblock.o build/main/vx/web/html.o build/main/vx/web/htmldoc.o build/main/vx/data/csv.o build/main/vx/data/db.o build/main/vx/data/file.o build/main/vx/data/tree.o build/main/vx/test.o build/test/test_lib.o build/test/vx/collection_test.o build/test/vx/core_test.o build/test/vx/event_test.o build/test/vx/sample_test.o build/test/vx/state_test.o build/test/vx/test_test.o build/test/vx/type_test.o build/test/vx/data/csv_test.o build/test/vx/data/db_test.o build/test/vx/data/file_test.o build/test/vx/data/table_test.o build/test/vx/data/textblock_test.o build/test/vx/data/tree_test.o build/test/vx/web/html_test.o build/test/vx/web/htmldoc_test.o build/main/vx/data/xml.o 
app_test.exe
