cls
set currentfolder=%cd%
cd ../golang
go run . doc srcswift testswift --path %currentfolder%/vxlisp
cd %currentfolder%
