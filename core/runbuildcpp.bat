cls
set currentfolder=%cd%
cd ../golang
go run . srccpp testcpp :path %currentfolder%/vxlisp
cd %currentfolder%
