cls
set currentfolder=%cd%
cd ../golang
go run . doc srccsharp testcsharp :path %currentfolder%/vxlisp
cd %currentfolder%
