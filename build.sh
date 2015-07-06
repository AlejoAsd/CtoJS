flex traductor.l
bison -d traductor.y
gcc lex.yy.c traductor.tab.c -o traductor
cp traductor pruebas/