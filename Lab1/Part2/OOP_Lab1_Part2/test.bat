rem @echo off
SET program="%1"
if %program% == "" goto err

mkdir Out
echo Test1
%program% 16 32 7ffffffe >> out1.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out1.txt" "Reference/reference1.txt"

echo Test2
%program% 16 32 7fffffff >> out2.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out2.txt" "Reference/reference2.txt"

echo Test3 
%program% 3 20 2000120001210002010 >> out3.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out3.txt" "Reference/reference3.txt"

echo Test4
%program% 7 11 021542331666 >> out4.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out4.txt" "Reference/reference4.txt"

echo OK
exit /B

:testFailed
echo Testing failed

:err
echo Usage: test.bat <Path to program>;