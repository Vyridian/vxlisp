cls
SET GOOS=windows
SET GOARCH=amd64
go build -o ../dist/vxlisp_win64.exe -ldflags="-s -w"
SET GOOS=linux
SET GOARCH=amd64
go build -o ../dist/vxlisp_linux64 -ldflags="-s -w"
SET GOOS=darwin
SET GOARCH=amd64
go build -o ../dist/vxlisp_mac64 -ldflags="-s -w"
