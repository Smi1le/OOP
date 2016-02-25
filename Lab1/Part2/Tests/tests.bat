rem @echo off
SET program="%OOP_Lab1_Part2.exe"
if %program% == "" goto err

echo Test1
%program% 16 32 7ffffffe
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo Test2
%program% 16 32 7fffffff
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo Test3 
%program% 3 20 2000120001210002010
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo Test4
%program% 7 11 021542331666
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK

echo OK
exit /B

:testFailed
echo Testing failed

:err
echo Usage: test.bat <Path to program>;