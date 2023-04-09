cls
set currentfolder=%cd%
cd ../vxruntime
vxlisp_win64 srcjs testjs srcjava testjava --path %currentfolder%/vxlisp
cd %currentfolder%
