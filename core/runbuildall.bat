cls
set currentfolder=%cd%
cd ../golang
go run . doc srcjs testjs srcjava testjava srccpp testcpp :path %currentfolder%/vxlisp
cd %currentfolder%
