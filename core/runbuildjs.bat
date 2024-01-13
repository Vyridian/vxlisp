cls
set currentfolder=%cd%
cd ../golang
go run . doc srcjs testjs :path %currentfolder%/vxlisp
cd %currentfolder%
