rem @echo off
SET program="%1"
if %program% == "" goto err

echo Test1
%program% "Tests/input.txt" >> out1.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "out1.txt" "Reference/reference1.txt"
if ERRORLEVEL 1 goto testFailed

echo Test2
%program% "Tests/input2.txt" >> out2.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "out2.txt" "Reference/reference2.txt"
if ERRORLEVEL 1 goto testFailed

echo Test3
%program% "Tests/input3.txt" >> out3.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "out3.txt" "Reference/reference3.txt"
if ERRORLEVEL 1 goto testFailed

echo Test4
%program% "Tests/input4.txt" >> out4.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "out4.txt" "Reference/reference4.txt"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:noFile
echo file is missing
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>;
