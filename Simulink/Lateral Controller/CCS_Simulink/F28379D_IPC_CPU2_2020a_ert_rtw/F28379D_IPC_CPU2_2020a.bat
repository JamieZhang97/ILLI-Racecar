cd .

if "%1"=="" ("D:\Matlab\Matlab2020a\bin\win64\gmake"  -B -f F28379D_IPC_CPU2_2020a.mk all) else ("D:\Matlab\Matlab2020a\bin\win64\gmake"  -B -f F28379D_IPC_CPU2_2020a.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
