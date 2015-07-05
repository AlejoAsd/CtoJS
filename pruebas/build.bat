echo off
set target=traductor
cd ..
flex %target%.l
bison -d %target%.y
gcc lex.yy.c %target%.tab.c -o %target%
cp %target%.exe pruebas
cd pruebas
traductor.exe funciones.c prueba.js
echo on