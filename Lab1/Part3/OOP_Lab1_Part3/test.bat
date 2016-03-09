rem @echo off
SET program = "%1"

echo Test1
%program% "Tests/input.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt "Tests/reference1.txt"
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo 44444444444444444444444444

echo Test2
%program% "Tests/input2.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed

echo Test3
%program% "Tests/input3.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed

echo Test4
%program% "Tests/input4.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed

echo Test5
%program% "Tests/input5.txt"
if ERRORLEVEL 2 goto noFile
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
