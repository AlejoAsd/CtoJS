/* Definiciones */
D           [0-9]
L           [a-zA-Z_]
H           [a-fA-F0-9]
E           [Ee][+-]?{D}+
FS          (f|F|l|L)
IS          (u|U|l|L)*

/* Header */
%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "traductor.tab.h"

/*Estructura de datos para links en lookahead cadena de símbolos*/
struct symrec
{
    char *name;             /* nombre del símbolo */
    int type;               /* tipo del símbolo */
    double value;           /* valor de lookahead variable */
    int function;
    struct symrec *next;    /* puntero al próximo registro */
};

typedef struct symrec symrec;

/*Tabla de símbolos*/
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();

int yylineno;
void comentario(void);
void comentariolinea(void);
void count();

%}

/* Definición de tokens */
%%
"/*"            { comentario(); }
"//"            { comentariolinea(); }
"#include ""<"((_|{L}*)"."{L}*)">"  { /* vacio */ }
"const"         { return(CONST); }

"char"          { yylval.tipo = CHAR; return(CHAR); }
"double"        { yylval.tipo = DOUBLE; return(DOUBLE); }
"float"         { yylval.tipo = FLOAT; return(FLOAT); }
"int"           { yylval.tipo = INT; return(INT); }
"long"          { yylval.tipo = LONG; return(LONG); }
"short"         { yylval.tipo = SHORT; return(SHORT); }
"signed"        { yylval.tipo = SIGNED; return(SIGNED); }
"unsigned"      { yylval.tipo = UNSIGNED; return(UNSIGNED); }
"void"          { yylval.tipo = VOID; return(VOID); }

"continue"      { return CONTINUE; }
"default"       { return DEFAULT; }
"do"            { return DO; }
"if"            { return IF; }
"else"          { return ELSE; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"for"           { return FOR; }
"while"         { return WHILE; }
"return"        { return RETURN; }
"break"         { return BREAK; }

{L}({L}|{D})*   { yylval.nombre = strdup(yytext); return(IDENTIFIER); }
0[xX]{H}+{IS}?      { yylval.nombre = strdup(yytext); return(CONSTANT); }
0{D}+{IS}?      { yylval.nombre = strdup(yytext); return(CONSTANT); }
{D}+{IS}?       { yylval.nombre = strdup(yytext); return(CONSTANT); }
L?'(\\.|[^\\'])+'   { yylval.nombre = strdup(yytext); return(CONSTANT); }

(-)?{D}+{E}{FS}?        { yylval.nombre = strdup(yytext); return(CONSTANT); }
(-)?{D}*"."{D}+({E})?{FS}?  { yylval.nombre = strdup(yytext); return(CONSTANT); }
(-)?{D}+"."{D}*({E})?{FS}?  { yylval.nombre = strdup(yytext); return(CONSTANT); }

">>="           { return(RIGHT_ASSIGN); }
"<<="           { return(LEFT_ASSIGN); }
"+="            { return(ADD_ASSIGN); }
"-="            { return(SUB_ASSIGN); }
"*="            { return(MUL_ASSIGN); }
"/="            { return(DIV_ASSIGN); }
"%="            { return(MOD_ASSIGN); }
"&="            { return(AND_ASSIGN); }
"^="            { return(XOR_ASSIGN); }
"|="            { return(OR_ASSIGN); }
">>"            { return(RIGHT_OP); }
"<<"            { return(LEFT_OP); }
"++"            { return(INC_OP); }
"--"            { return(DEC_OP); }
"&&"            { return(AND_OP); }
"||"            { return(OR_OP); }
"<="            { return(LE_OP); }
">="            { return(GE_OP); }
"=="            { return(EQ_OP); }
"!="            { return(NE_OP); }
";"             { return(';'); }
","             { return(','); }
("{"|"<%")      { return('{'); }
("}"|"%>")      { return('}'); }
":"             { return(':'); }
"="             { return('='); }
"("             { return('('); }
")"             { return(')'); }
("["|"<:")      { return('['); }
("]"|":>")      { return(']'); }
"."             { return('.'); }
"&"             { return('&'); }
"!"             { return('!'); }
"~"             { return('~'); }
"-"             { return('-'); }
"+"             { return('+'); }
"*"             { return('*'); }
"/"             { return('/'); }
"%"             { return('%'); }
"<"             { return('<'); }
">"             { return('>'); }
"^"             { return('^'); }
"|"             { return('|'); }
"?"             { return('?'); }

[ \t\v\f]       { count(); }
\n              { ++yylineno; }
.               { /* Se ignoran caracteres no reconocidos */ }

%%

yywrap()
{
    return(1);
}


int column = 0;

void count()
{
    int i;

    for (i = 0; yytext[i] != '\0'; i++)
    {
        if (yytext[i] == '\n')
        {
            column = 0;
        }
        else if (yytext[i] == '\t')
        {
            column += 8 - (column % 8);
        }
        else
        {
            column++;
        }
    }
}

// Adelanta el cursor hasta terminar un comentario multilínea
void comentario(void)
{
    // Guardar el caracter actual
    int cursor = input();
    // Guardar el lookahead
    int lookahead = input();

    while (lookahead != EOF && !(cursor == '*' && lookahead == '/')) 
    {
        // Incrementar el contador de líneas si corresponde
        if (cursor == '\n')
            ++yylineno;
        // Avanzar lookahead posición del cursor y el lookahead
        cursor = lookahead; 
        lookahead = input();
    }

    // Asegurar que se cierre el comentario
    if(lookahead == EOF)
    {
        printf("No se cerró el comentario.\n");
    }
}

// Adelanta el cursor hasta terminar un comentario de línea
void comentariolinea()
{
    // Cursor
    int cursor = input();

    // Recorrer lookahead línea hasta encontrar el salto de línea
    while (cursor != '\n' && cursor != EOF)
    {
        cursor = input();
    }

    // Aumentar el contador de líneas si corresponde
    if(cursor == '\n')
    {
        yylineno += 1;
    }
}