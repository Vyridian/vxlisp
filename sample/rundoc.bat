cls
set currentfolder=%cd%
cd ../dist
vxlisp_win64 doc --path %currentfolder%/vxlisp
cd %currentfolder%
