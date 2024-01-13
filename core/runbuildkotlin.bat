cls
set currentfolder=%cd%
cd ../golang
go run . doc srckotlin testkotlin :path %currentfolder%/vxlisp
cd %currentfolder%
