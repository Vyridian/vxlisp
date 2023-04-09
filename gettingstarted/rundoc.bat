cls
set currentfolder=%cd%
cd ../vxruntime
vxlisp_win64 doc --path %currentfolder%/vxlisp
cd %currentfolder%
