	/********************************************** DEFINICIONES **********************************************/

%{
#include <stdio.h>
#include <string.h>
#include "symtable.h"

extern int yylex(void);
// Archivo fuente a ser traducido
extern FILE *yyin;
// Reconoce tokens del input y es retornado al parser
extern char *yytext; 
// Numero de linea del codigo fuente
extern int yylineno; 

// Archivo objeto con la 	
FILE *yysalida; 
symrec *sym_table = (symrec *)0;
symrec *s;
symrec *symtable_set_type;

// Booleano cuando se encuentra funciones 
int boolFuncion=0;
// Booleano cuando se encuentra error 
int sin_error=1;
// Manejo de corchetes para vectores
int corchete=0;
// Para manejo de tamano de vector
int tam_vector=0;
// Para manejo de array multidimensional 
int cant_corchetes=0;

%}

%union {
	int tipo;
	double val;
	char *nombre;
	struct symrec *tptr;
}

%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN

%token <nombre> IDENTIFIER CONSTANT
%token <tipo> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID

%type <tipo> type_specifier declaration_specifiers type_qualifier
%type <nombre> direct_declarator declarator init_declarator init_declarator_list function_definition
%type <tptr> declaration 

%left INC_OP DEC_OP

%nonassoc IF_AUX
%nonassoc ELSE

%start translation_unit

	/********************************************** REGLAS **********************************************/

%%
primary_expression
	/* En caso de ser un identificador, ya guarda el mismo identificador en el archivo */
	: IDENTIFIER { fprintf(yysalida, "%s", yytext); }
	| CONSTANT { if (!tam_vector) fprintf(yysalida, "%s", yytext); else tam_vector=0; }
	| '(' { fprintf(yysalida, "( "); } expression ')' { fprintf(yysalida, " )"); }
	;
	
/* Tokens que guarda ya en el archivo */
postfix_expression
	: primary_expression
	| postfix_expression '[' { fprintf(yysalida, "[ "); } expression ']' { fprintf(yysalida, " ]"); }
	| postfix_expression '(' { fprintf(yysalida, "( "); } ')' { fprintf(yysalida, " )"); }
	| postfix_expression '(' { fprintf(yysalida, "( "); } argument_expression_list ')' { fprintf(yysalida, " )"); }
	| postfix_expression INC_OP { fprintf(yysalida, "++"); }
	| postfix_expression DEC_OP { fprintf(yysalida, "--"); }
	;
	
argument_expression_list
	: assignment_expression
	| argument_expression_list ',' { fprintf(yysalida, ", "); } assignment_expression
	;
	
unary_expression
	: postfix_expression
	/* operacion de incremento/decremento que guarda en el archivo yysalida */
	| INC_OP { fprintf(yysalida, "++"); } unary_expression
	| DEC_OP { fprintf(yysalida, "--"); } unary_expression
	| unary_operator cast_expression
	;

/* Sale los siguientes tokens y se guarda en archivo como esta */
unary_operator
	: '&' { fprintf(yysalida, " & "); }
	| '*' { fprintf(yysalida, " * "); }
	| '+' { fprintf(yysalida, " + "); }
	| '-' { fprintf(yysalida, " - "); }
	| '~' { fprintf(yysalida, " ~ "); }
	| '!' { fprintf(yysalida, " ! "); }
	;

cast_expression
	: unary_expression
	;

/* Operadores de multiplicacion, division, mod */	
multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' { fprintf(yysalida, " * "); } cast_expression
	| multiplicative_expression '/' { fprintf(yysalida, " / "); } cast_expression
	| multiplicative_expression '%' { fprintf(yysalida, " %% "); } cast_expression
	;
/* Operadores de suma, resta */	
additive_expression
	: multiplicative_expression
	| additive_expression '+' { fprintf(yysalida, " + "); } multiplicative_expression
	| additive_expression '-' { fprintf(yysalida, " - "); } multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP { fprintf(yysalida, " << "); } additive_expression
	| shift_expression RIGHT_OP { fprintf(yysalida, " >> "); } additive_expression
	;

/* Operadores relacionales menor, mayor, menor igual, mayor igual */	
relational_expression
	: shift_expression
	| relational_expression '<' { fprintf(yysalida, " < "); } shift_expression
	| relational_expression '>' { fprintf(yysalida, " > "); } shift_expression
	| relational_expression LE_OP { fprintf(yysalida, " <= "); } shift_expression
	| relational_expression GE_OP { fprintf(yysalida, " >= "); } shift_expression
	;

/* Operadores de igualdad, igual y distinto */
equality_expression
	: relational_expression
	| equality_expression EQ_OP { fprintf(yysalida, " == "); } relational_expression
	| equality_expression NE_OP { fprintf(yysalida, " != "); } relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' { fprintf(yysalida, " & "); } equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' { fprintf(yysalida, " ^ "); } and_expression
	;	

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' { fprintf(yysalida, " | "); } exclusive_or_expression
	;

/* Operador AND logico */
logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP { fprintf(yysalida, " && "); } inclusive_or_expression
	;

/* Operador OR logico */
logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP { fprintf(yysalida, " || "); } logical_and_expression
	;

/* Expresion condicional */
conditional_expression
	: logical_or_expression
	| logical_or_expression '?' { fprintf(yysalida, " ? "); } expression ':' { fprintf(yysalida, " : "); } conditional_expression
	;
	
assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;
	
assignment_operator
	: '=' { fprintf(yysalida, " = "); }
	| MUL_ASSIGN { fprintf(yysalida, " *= "); }
	| DIV_ASSIGN { fprintf(yysalida, " /= "); }
	| MOD_ASSIGN { fprintf(yysalida, " %%= "); }
	| ADD_ASSIGN { fprintf(yysalida, " += "); }
	| SUB_ASSIGN { fprintf(yysalida, " -= "); }
	| LEFT_ASSIGN { fprintf(yysalida, " <<= "); }
	| RIGHT_ASSIGN { fprintf(yysalida, " >>= "); }
	| AND_ASSIGN { fprintf(yysalida, " &= "); }
	| XOR_ASSIGN { fprintf(yysalida, " ^= "); }
	| OR_ASSIGN { fprintf(yysalida, " |= "); }
	;

expression
	: assignment_expression
	| expression ',' { fprintf(yysalida, ", "); } assignment_expression
	;
	
constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	{
		for(symtable_set_type=sym_table; symtable_set_type!=(symrec *)0; symtable_set_type=(symrec *)symtable_set_type->next)
		{
			if(symtable_set_type->type==-1)
			{
				symtable_set_type->type=$1;
			}
		}
		if (cant_corchetes==1 && corchete==1)
		{
			fprintf(yysalida, " );\n");
			cant_corchetes=0;
			corchete=0;
		}
		else
			fprintf(yysalida, ";\n");
						
	}
	| declaration_specifiers init_declarator_list error { yyerror("Msj: Falta un \";\". "); yyerrok; }
	;

declaration_specifiers
	: type_specifier 
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list	
	: init_declarator
	| init_declarator_list ',' { fprintf(yysalida, ";\n"); } init_declarator
	;

init_declarator
	: declarator
 	{
		s = getsym($1);
		if (s==(symrec *)0)
		{
			printf("Empty variable declarator.\n");
			s = putsym($1, -1, 0);
		}
		else
		{
			printf("Error: Variable declarada anteriormente.\n");
			yyerrok;	
		}
	}
	| declarator	
	{
		s = getsym($1);
		if(s==(symrec *)0)
		{
			printf("Non empty variable declarator.\n");
			s = putsym($1, -1, 0);
		}
		else
		{
			printf("Error: Variable declarada anteriormente.\n");
			yyerrok;	
		}
	}
	'=' { if (corchete==0) fprintf(yysalida, "="); } initializer 
	;

type_specifier
	: CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| VOID
	;

declarator
	: direct_declarator {$$=$1;}
	;

direct_declarator
	/*TODO: Si es la declaracion de una funcion, pone FUNCTION YYTEXT, si es parametro pone YYTEXT, si es variable pone var YYTEXT */
	: IDENTIFIER { if (boolFuncion){ fprintf(yysalida, "function %s", yytext); boolFuncion=0; } else fprintf(yysalida, "var %s", yytext); $$=$1; } //TAG: agregamos var a todo lo que no sea funcion
	| direct_declarator '[' { tam_vector=1; if (!cant_corchetes) fprintf(yysalida, "=new Array( "); cant_corchetes=1; }
	 constant_expression ']' { corchete=1; }
	| direct_declarator '['  { if (!cant_corchetes) fprintf(yysalida, "=new Array( "); cant_corchetes=1; }
	  ']' { corchete=1; }
	| direct_declarator '(' { fprintf(yysalida, "( "); } ')' { fprintf(yysalida, " )"); }
	| direct_declarator '(' { fprintf(yysalida, "( "); } parameter_type_list ')' { fprintf(yysalida, " )"); }
	;

parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' { fprintf(yysalida, ", "); } parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	{
		s = getsym($2);
	    if(s==(symrec *)0)
	    {
	        printf("Parameter_declaration.\n");	    	
	        s = putsym($2, $1, 0);
	    }
	    else
	    {
	        printf("Error: Variable declarada anteriormente.\n");
	        yyerrok;
	    }
	}
	| declaration_specifiers
	;

initializer_list
: initializer
	| initializer_list ',' { fprintf(yysalida, " ,"); } initializer
	;

initializer
	:  assignment_expression /*primary_expression*/ 
	| '{' initializer_list '}'
	;

type_qualifier
	: CONST { fprintf(yysalida, "const "); }
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;
	
labeled_statement
	: CASE { fprintf(yysalida, "case "); } constant_expression ':' { fprintf(yysalida, ": "); } statement
	| DEFAULT { fprintf(yysalida, "default "); } ':' { fprintf(yysalida, ": "); } statement
	;
	
compound_statement
	: '{' { fprintf(yysalida, "{ "); } '}' { fprintf(yysalida, " }\n"); }
	| '{' { fprintf(yysalida, "{\n"); } statement_list '}' { fprintf(yysalida, "}\n"); }
	/*| '{' { fprintf(yysalida, "{\n"); } declaration_list '}' { fprintf(yysalida, "}\n"); }*/
	| '{' { fprintf(yysalida, "{\n"); } declaration_list statement_list '}' { fprintf(yysalida, "}\n"); }
	| '{' error { yyerror("Msj: Falta un \"}\"."); yyerrok; }
	;

declaration_list
	: declaration
	| declaration_list declaration
	; 

statement_list
	: statement
	| statement_list statement
	|
	;

expression_statement
	: ';' { fprintf(yysalida, ";\n"); }
	| expression ';' { fprintf(yysalida, ";\n"); }
	;
	
else_statement
	: ELSE { fprintf(yysalida, "else"); } statement
	| %prec IF_AUX
	;	

selection_statement
	: IF { fprintf(yysalida, "if"); } '(' { fprintf(yysalida, "( "); } expression ')' { fprintf(yysalida, " )"); } statement else_statement
	| SWITCH { fprintf(yysalida, "switch"); } '(' { fprintf(yysalida, "( "); } expression ')' { fprintf(yysalida, " )"); } statement
	;
	
iteration_statement
	: WHILE { fprintf(yysalida, "while"); } '(' { fprintf(yysalida, "( "); } expression ')' { fprintf(yysalida, " )"); } statement
	| DO { fprintf(yysalida, "do"); } statement WHILE { fprintf(yysalida, "while"); } '(' { fprintf(yysalida, "( "); } expression ')' { fprintf(yysalida, " )"); } ';' { fprintf(yysalida, ";\n"); }
	| FOR { fprintf(yysalida, "for"); } '(' { fprintf(yysalida, "( "); } expression_statement expression_statement expression ')' { fprintf(yysalida, " )"); } statement
	;
	
jump_statement
	: CONTINUE { fprintf(yysalida, "continue"); } ';' { fprintf(yysalida, ";\n"); }
	| BREAK { fprintf(yysalida, "break"); } ';' { fprintf(yysalida, ";\n"); }
	| RETURN { fprintf(yysalida, "return"); } ';' { fprintf(yysalida, ";\n"); }
	| RETURN { fprintf(yysalida, "return "); } expression ';' { fprintf(yysalida, ";\n"); }
	| CONTINUE error { yyerror("Msj: Falta un \";\" despues de continue en la sentencia."); yyerrok; }
	| BREAK error { yyerror ("Msj: Falta un \";\" despues de break en la sentencia."); yyerrok;}
	;

external_declaration
	: function_definition { boolFuncion=1; }
	| declaration 
	;

function_definition
	: declaration_specifiers declarator compound_statement	
	{
		s = getsym($2);
		if(s==(symrec *)0)
		{
			printf("Function_definition.\n");
			s = putsym($2,$1,1);
		}
		else
		{
			printf("Error: Funcion declarada anteriormente.");
			yyerrok;
		}
	}
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

	/********************************************** FUNCIONES **********************************************/

%%
#include <stdio.h>

yyerror(s)
char *s;
{
	sin_error=0;
	printf("%s: Linea %d cerca de --> %s\n", s, yylineno, yylval.nombre);
}

symrec * putsym(sym_name, sym_type, b_function)
	char *sym_name;
	int sym_type;
	int b_function;
{
	//Solo para debug
	printf("\t%s, %d, %d\n", sym_name,
			sym_type, 
			b_function);

	symrec *ptr;
	ptr = (symrec *) malloc(sizeof(symrec));
	ptr->name = (char *) malloc(strlen(sym_name) + 1);
	strcpy(ptr->name, sym_name);
	ptr->type = sym_type;
	ptr->value = 0; //set value to 0
	ptr->function = b_function;
	ptr->next =(struct symrec *) sym_table;
	sym_table = ptr;
	return ptr;
}
symrec * getsym(sym_name)
	char *sym_name;
{
	symrec *ptr;
	for(ptr = sym_table; ptr != (symrec*)0; ptr = (symrec *)ptr->next)
		if(strcmp(ptr->name, sym_name) == 0)
		{
			printf("simbolo: %s\n", ptr->name);
			return ptr;
		}
	return 0;
}

const char *tipo_id(int tipo){
	switch(tipo){
		case(282):
			return "CHAR";
		case(283):
			return "SHORT";
		case(284):
			return "INT";
		case(285):
			return "LONG";
		case(286):
			return "SIGNED";
		case(287):
			return "UNSIGNED";
		case(288):
			return "FLOAT";
		case(289):
			return "DOUBLE";
		case(290):
			return "CONST";
		case(291):
			return "VOID";
		default:
			return "NO";
	}
}

const char *tipo_var(int tipo){
	switch(tipo){
		case(1):
			return "Funcion";
		case(0):
			return "Variable";
		default:
			return "NO";
	}
}

/*---------------------------------------------------------------*
*							  MAIN                               *
*----------------------------------------------------------------*/
int main(int argc,char **argv)
{
	/* Debe tener 3 parametros, ejecutable.exe /path/to/fuente.c /path/to/objeto.js */
	if (argc<3)
	{
		printf("Modo incorrecto de uso\n Forma correcta => %s archivo.c archivo.js\n", argv[0]);
		return 0;
	}
	if ((yyin = fopen(argv[1],"rt")) == NULL) /*  */
	{
		printf("No se pudo abrir el archivo de lectura.\n");
                return 0;
	}
	if ((yysalida=fopen(argv[2], "w")) == NULL)
	{
		printf("No se pudo abrir el archivo para escritura.\n");
                return 0;
	}
	
	fprintf(yysalida, "\n");//BORRAR especifico de php
	yyparse();
	fprintf(yysalida, "\n");//BORRAR especifico de php
	fclose(yyin);
	fclose(yysalida);
	
	if(sin_error)
		printf("\n***La traducción del archivo %s ha sido finalizada***\nArchivo traducido destino => %s\n", argv[1], argv[2]);
	else
		printf("\nNo se pudo finalizar la traducción.\n");

	FILE *simbolos;
	strcat(argv[1], ".txt");
	simbolos=fopen(argv[1], "w+");
	symrec * ptr_table;
	fprintf(simbolos, "NOMBRE, TIPO, VARIABLE O FUNCION.\n");
	for(ptr_table = sym_table; ptr_table!=(symrec *)0; ptr_table=(symrec *)ptr_table->next)
	{
		fprintf(simbolos, "\t%s, %d, %s\n", ptr_table->name,
			ptr_table->type, 
			tipo_var(ptr_table->function));
	}

	fclose(simbolos);
	return 0;
}
