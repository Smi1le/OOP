rem @echo off
SET program="%OOP_Lab1_Part3.exe"
if %program% == "" goto err

echo Test1
%program% input.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt reference1.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo 44444444444444444444444444

echo Test2
%program% input2.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed

echo Test3
%program% input3.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed

echo Test4
%program% input4.txt
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed

echo Test5
%program% input5.txt
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
