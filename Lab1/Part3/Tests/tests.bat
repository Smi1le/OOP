rem @echo off
SET program="%OOP_Lab1_Part3.exe"
if %program% == "" goto err

echo Test1
%program% input.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo Test2
%program% input2.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo Test3
%program% input3.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo Test4
%program% input4.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>;
