cls
set currentfolder=%cd%
cd ../src
go test -v ./...
cd %currentfolder%
