set MATLAB=F:\MAT

cd .

if "%1"=="" ("F:\MAT\bin\win64\gmake"  -f feedback_control.mk all) else ("F:\MAT\bin\win64\gmake"  -f feedback_control.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
