cls
set currentfolder=%cd%
cd ../vxruntime
vxlisp_win64 doc srcjs testjs srcjava testjava --path %currentfolder%/vxlisp
cd %currentfolder%
