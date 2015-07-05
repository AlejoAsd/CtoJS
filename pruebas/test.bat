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
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Vectores
set file=vectores
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Matrices
set file=matrices
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Condicionales
set file=condicionales
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-
:: Loops
set file=loops
traductor.exe %file%.c %file%.js 
node %file%.js && set results=%results%1
set results=%results%-

echo =================
echo Results: %results%