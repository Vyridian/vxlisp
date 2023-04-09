cls
set currentfolder=%cd%
cd ../vxruntime
vxlisp_win64 webserver --path %currentfolder%/vxlisp
cd %currentfolder%
