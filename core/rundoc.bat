cls
set currentfolder=%cd%
cd ../golang
go run . doc :path %currentfolder%/vxlisp
cd %currentfolder%
