cls
xcopy ..\core\vxlisp ..\vxlispruntime\vxlisp /s /y /i
xcopy ..\core\doc ..\vxlispruntime\doc /s /y /i
xcopy ..\core\doc\doc.html ..\doc.html /y
xcopy ..\core\cpp\src\test\resources\testsuite.html ..\testsuite_cpp.html /y
xcopy ..\core\csharp\test\resources\testsuite.html ..\testsuite_csharp.html /y
xcopy ..\core\java\src\test\resources\testsuite.html ..\testsuite_java.html /y
