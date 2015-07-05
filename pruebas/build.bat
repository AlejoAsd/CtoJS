@echo off
cls

:: Set targets
if "%1" == "" (set target=funciones) else (set target=%1)
if "%2" == "" (set output=prueba) else (set target=%2)
echo Targetting %target%.c
echo Outputting %output%.js
echo[

:: Compile translator
set program=traductor
cd ..
flex %program%.l
bison -d %program%.y
gcc lex.yy.c %program%.tab.c -o %program%
cp %program%.exe pruebas
cd pruebas

:: Translate target
traductor.exe %target%.c %output%.js