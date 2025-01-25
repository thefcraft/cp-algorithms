@echo off
g++ -DDEBUG main.cpp -o main
if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b %errorlevel%
)
main.exe