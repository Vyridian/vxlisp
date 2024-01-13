cls
set currentfolder=%cd%
cd ../golang
go run . webserver :path %currentfolder%/vxlisp
cd %currentfolder%
