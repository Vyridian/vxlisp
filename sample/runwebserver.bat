cls
set currentfolder=%cd%
cd ../dist
vxlisp_win64 webserver --path %currentfolder%/vxlisp
cd %currentfolder%
