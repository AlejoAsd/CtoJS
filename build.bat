echo off
set target=traductor
flex %target%.l
bison -d %target%.y
gcc lex.yy.c %target%.tab.c -o %target%
cp %target%.exe pruebas
echo on