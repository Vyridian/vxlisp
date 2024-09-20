cls
set GOOS=windows
set GOARCH=amd64
set currentfolder=%cd%
cd ..
go build -o ../vxlisp/dist/vxlisp_win64.exe -ldflags="-s -w"
set GOOS=linux
set GOARCH=amd64
go build -o ../vxlisp/dist/vxlisp_linux64 -ldflags="-s -w"
set GOOS=darwin
set GOARCH=amd64
go build -o ../vxlisp/dist/vxlisp_mac64 -ldflags="-s -w"
cd %currentfolder%
