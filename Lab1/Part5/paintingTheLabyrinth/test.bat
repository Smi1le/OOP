rem @echo off
SET program="%1"
echo 1
#if %program% == "" goto err

echo Test 1
%program% "Tests/input1.txt" "output1.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "output1.txt" "Reference/reference1.txt"
if ERRORLEVEL 1 goto testFailed

echo Test 2
%program% "Tests/input2.txt" "output2.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "output2.txt" "Reference/reference2.txt"
if ERRORLEVEL 1 goto testFailed

echo Test 3
%program% "Tests/input3.txt" "output3.txt"
if ERRORLEVEL 2 goto noFile
if ERRORLEVEL 1 goto testFailed
fc.exe "output3.txt" "Reference/reference3.txt"
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
