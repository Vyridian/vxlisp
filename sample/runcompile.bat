cls
set currentfolder=%cd%
cd ../dist
vxlisp_win64 srcjs testjs srcjava testjava --path %currentfolder%/vxlisp
cd %currentfolder%
