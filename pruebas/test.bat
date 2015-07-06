echo off
cls
set target=traductor
cd ..
flex %target%.l
bison -d %target%.y
gcc lex.yy.c %target%.tab.c -o %target%
cp %target%.exe pruebas
cd pruebas

::: Start Testing
set results=
:: Funciones
set file=funciones
echo Translating %file%
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Vectores
set file=vectores
echo Translating %file%
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Matrices
set file=matrices
echo Translating %file%
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Condicionales
set file=condicionales
echo Translating %file%
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Loops
set file=loops
echo Translating %file%
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1

echo =================
echo Results: %results%