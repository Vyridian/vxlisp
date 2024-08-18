cls
set currentfolder=%cd%
cd ../golang
go run . doc  srccpp testcpp srccsharp testcsharp srcjava testjava srcjs testjs srckotlin testkotlin :path %currentfolder%/vxlisp
cd %currentfolder%
