/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "traductor.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>

/*Data type for links in the chain of symbols*/
struct symrec
{
	char *name;			/* name of symbol */
	int type;			/* type of symbol */
	double value;				/* value of a VAR */
	int function;
	struct symrec *next;		/* link field */
};

typedef struct symrec symrec;

/*The symbol table: a chain of 'struct symrec'*/
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();

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


#line 115 "traductor.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "traductor.tab.h".  */
#ifndef YY_YY_TRADUCTOR_TAB_H_INCLUDED
# define YY_YY_TRADUCTOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PTR_OP = 258,
    INC_OP = 259,
    DEC_OP = 260,
    LEFT_OP = 261,
    RIGHT_OP = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    AND_OP = 267,
    OR_OP = 268,
    MUL_ASSIGN = 269,
    DIV_ASSIGN = 270,
    MOD_ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    LEFT_ASSIGN = 274,
    RIGHT_ASSIGN = 275,
    AND_ASSIGN = 276,
    XOR_ASSIGN = 277,
    OR_ASSIGN = 278,
    TYPE_NAME = 279,
    CASE = 280,
    DEFAULT = 281,
    IF = 282,
    ELSE = 283,
    SWITCH = 284,
    WHILE = 285,
    DO = 286,
    FOR = 287,
    CONTINUE = 288,
    BREAK = 289,
    RETURN = 290,
    IDENTIFIER = 291,
    CONSTANT = 292,
    CHAR = 293,
    SHORT = 294,
    INT = 295,
    LONG = 296,
    SIGNED = 297,
    UNSIGNED = 298,
    FLOAT = 299,
    DOUBLE = 300,
    CONST = 301,
    VOID = 302,
    IF_AUX = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "traductor.y" /* yacc.c:355  */

	int tipo;
	double val;
	char *nombre;
	struct symrec *tptr;

#line 211 "traductor.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRADUCTOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "traductor.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    61,    54,     2,
      49,    50,    55,    56,    53,    57,     2,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    69,
      62,    68,    63,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    65,    71,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    86,    86,    91,    92,    92,    93,
      93,    94,    94,    95,    96,   100,   101,   101,   105,   107,
     107,   108,   108,   109,   114,   115,   116,   117,   118,   119,
     123,   128,   129,   129,   130,   130,   131,   131,   135,   136,
     136,   137,   137,   141,   142,   142,   143,   143,   148,   149,
     149,   150,   150,   151,   151,   152,   152,   157,   158,   158,
     159,   159,   163,   164,   164,   168,   169,   169,   173,   174,
     174,   179,   180,   180,   185,   186,   186,   191,   192,   192,
     192,   196,   197,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   215,   216,   216,   220,   224,   243,
     247,   248,   249,   250,   254,   255,   255,   259,   274,   287,
     273,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     303,   308,   309,   309,   311,   311,   313,   313,   314,   314,
     318,   322,   323,   323,   327,   341,   345,   346,   346,   350,
     351,   355,   359,   360,   361,   362,   363,   364,   368,   368,
     368,   369,   369,   369,   373,   373,   374,   374,   376,   376,
     377,   381,   382,   386,   387,   388,   392,   393,   397,   397,
     398,   402,   402,   402,   402,   403,   403,   403,   403,   407,
     407,   407,   407,   408,   408,   408,   408,   408,   409,   409,
     409,   409,   413,   413,   414,   414,   415,   415,   416,   416,
     417,   418,   422,   423,   427,   441,   442,   446,   447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "CONTINUE", "BREAK", "RETURN", "IDENTIFIER", "CONSTANT", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOID", "IF_AUX", "'('", "')'", "'['", "']'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "$@1", "postfix_expression", "$@2", "$@3", "$@4",
  "argument_expression_list", "$@5", "unary_expression", "$@6", "$@7",
  "unary_operator", "cast_expression", "multiplicative_expression", "$@8",
  "$@9", "$@10", "additive_expression", "$@11", "$@12", "shift_expression",
  "$@13", "$@14", "relational_expression", "$@15", "$@16", "$@17", "$@18",
  "equality_expression", "$@19", "$@20", "and_expression", "$@21",
  "exclusive_or_expression", "$@22", "inclusive_or_expression", "$@23",
  "logical_and_expression", "$@24", "logical_or_expression", "$@25",
  "conditional_expression", "$@26", "$@27", "assignment_expression",
  "assignment_operator", "expression", "$@28", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list", "$@29",
  "init_declarator", "$@30", "$@31", "type_specifier", "declarator",
  "direct_declarator", "$@32", "$@33", "$@34", "$@35",
  "parameter_type_list", "parameter_list", "$@36", "parameter_declaration",
  "initializer_list", "$@37", "initializer", "type_qualifier", "statement",
  "labeled_statement", "$@38", "$@39", "$@40", "$@41",
  "compound_statement", "$@42", "$@43", "$@44", "declaration_list",
  "statement_list", "expression_statement", "else_statement", "$@45",
  "selection_statement", "$@46", "$@47", "$@48", "$@49", "$@50", "$@51",
  "iteration_statement", "$@52", "$@53", "$@54", "$@55", "$@56", "$@57",
  "$@58", "$@59", "$@60", "$@61", "jump_statement", "$@62", "$@63", "$@64",
  "$@65", "external_declaration", "function_definition",
  "translation_unit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    40,
      41,    91,    93,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59,
     123,   125
};
# endif

#define YYPACT_NINF -214

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-214)))

#define YYTABLE_NINF -197

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     479,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,     6,   251,   467,   -13,   251,  -214,  -214,
     457,     7,  -214,    -6,  -214,   203,  -214,     6,  -214,   467,
      13,     5,  -214,  -214,  -214,  -214,  -214,  -214,    11,  -214,
    -214,    12,   390,   251,    20,  -214,  -214,    44,   251,    49,
      50,     6,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,     8,     9,    41,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,    10,   118,    49,
    -214,    -9,    -1,    68,    19,    90,    73,    52,    65,   132,
      -8,  -214,  -214,   -35,  -214,  -214,  -214,   250,  -214,  -214,
    -214,  -214,   344,  -214,     6,   117,   116,  -214,  -214,  -214,
     119,  -214,  -214,   141,    49,    49,    49,   103,   124,   125,
     127,   390,   130,  -214,   111,  -214,   112,   113,    49,    49,
    -214,  -214,   133,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,    49,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
     297,  -214,  -214,  -214,  -214,   141,  -214,  -214,  -214,  -214,
     126,  -214,  -214,  -214,  -214,   154,  -214,  -214,  -214,  -214,
     -32,   -21,   135,    49,    49,  -214,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,  -214,   251,   -36,  -214,
    -214,   390,    49,    49,    49,  -214,   425,  -214,  -214,  -214,
      -5,  -214,    71,  -214,  -214,  -214,    -9,    -9,    -1,    -1,
      68,    68,    68,    68,    19,    19,    90,    73,    52,    65,
     132,   -28,  -214,  -214,  -214,  -214,   390,  -214,    34,    40,
      42,   142,   425,  -214,  -214,  -214,  -214,   141,  -214,  -214,
    -214,  -214,  -214,    49,    49,    49,  -214,   390,   390,   390,
      49,    61,  -214,  -214,   164,  -214,  -214,    62,  -214,  -214,
    -214,  -214,   390,   390,   136,  -214,  -214,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   121,   111,   112,   113,   114,   117,   118,   115,   116,
     141,   119,   203,     0,   100,     0,   120,   102,   207,   202,
       0,     0,   104,   107,   101,     0,   161,     0,   206,     0,
     128,   122,   103,     1,   208,    99,   105,    98,     0,   204,
     160,     0,   165,     0,   107,   162,   205,     0,     0,     0,
       0,     0,   109,   155,    19,    21,   148,   151,   171,   175,
     179,   183,   188,     0,     0,   198,     2,     3,     4,    24,
      25,    26,    27,    28,    29,   166,     6,    18,    30,     0,
      31,    38,    43,    48,    57,    62,    65,    68,    71,    74,
      77,    81,    94,     0,   163,   142,   143,     0,   144,   145,
     146,   147,   165,   127,   135,     0,   130,   131,    30,    97,
       0,   125,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,   201,     0,     0,     0,     0,
      13,    14,    11,     7,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    83,     0,    23,    32,    34,    36,
      39,    41,    44,    46,    53,    55,    49,    51,    58,    60,
      63,    66,    69,    72,    75,    78,    95,   167,   157,   164,
       0,   134,   129,   132,   123,     0,   139,   110,    20,    22,
       0,   152,   172,   176,   180,     0,   189,   193,   195,   197,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,     0,     0,   136,
     149,     0,     0,     0,     0,   184,     0,   199,     5,    10,
       0,    15,     0,    33,    35,    37,    40,    42,    45,    47,
      54,    56,    50,    52,    59,    61,    64,    67,    70,    73,
      76,     0,    96,   133,   137,   140,     0,   153,     0,     0,
       0,     0,     0,    12,    16,     8,    79,     0,   150,   173,
     177,   181,   185,     0,     0,     0,   138,     0,     0,     0,
       0,     0,    17,    80,   170,   178,   182,     0,   190,   168,
     174,   186,     0,     0,     0,   191,   169,   187
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   -49,
    -214,  -214,  -214,   -76,   -74,  -214,  -214,  -214,   -73,  -214,
    -214,  -134,  -214,  -214,   -65,  -214,  -214,  -214,  -214,   -15,
    -214,  -214,    -4,  -214,   -10,  -214,    -2,  -214,     0,  -214,
    -214,  -214,   -48,  -214,  -214,  -102,  -214,  -105,  -214,    93,
      -3,     2,  -214,  -214,   161,  -214,  -214,  -214,    -7,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,     1,  -214,  -214,
    -171,  -214,   -90,  -214,  -214,  -214,  -214,  -214,    18,  -214,
    -214,  -214,   171,   114,  -213,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
     195,  -214,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    76,   129,    77,   194,   192,   193,   230,   274,    78,
     114,   115,    79,    80,    81,   196,   197,   198,    82,   199,
     200,    83,   201,   202,    84,   205,   206,   203,   204,    85,
     207,   208,    86,   209,    87,   210,    88,   211,    89,   212,
      90,   213,    91,   214,   275,    92,   145,    93,   215,   110,
      12,    27,    21,    51,    22,    38,   113,    14,    15,    16,
      49,    50,    47,    48,   105,   106,   217,   107,   218,   267,
     177,    17,    94,    95,   116,   256,   117,   221,    96,    41,
      42,    43,    29,    97,    98,   290,   293,    99,   118,   222,
     277,   119,   223,   278,   100,   120,   224,   279,   121,   261,
     280,   294,   122,   226,   292,   101,   124,   126,   127,   128,
      18,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   109,    13,   146,   219,   164,    23,   169,    35,   123,
     125,   176,    26,   262,   130,   131,    24,   254,   166,    32,
      44,   166,    13,   190,   191,   166,    45,   154,   155,   228,
     108,   185,   166,    28,   167,   255,    30,   227,    31,   266,
      26,    39,     1,   195,    44,   263,   147,    46,   264,   273,
     104,   148,   149,    54,    55,   150,   151,  -124,   165,   132,
      36,   133,  -108,  -126,    25,   178,   179,   108,   109,   240,
     241,   242,   243,   176,   152,   153,    37,  -192,  -194,    52,
     169,   156,   157,    53,   269,    66,    67,   166,  -108,   232,
     270,   231,   271,   166,   103,   166,   276,   171,    68,    45,
     158,   159,   111,    69,    70,    71,    72,    73,    74,   251,
    -196,   288,   291,   252,   166,   166,   161,   258,   259,   260,
     233,   234,   235,   265,   166,   236,   237,   160,   238,   239,
     162,   257,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   244,   245,   163,    54,    55,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   176,   268,   172,   281,   173,
     181,   174,   282,   182,   183,   287,   184,    66,    67,   186,
     187,   188,   189,    -9,   225,   229,   144,   284,   285,   286,
      68,   272,   289,   220,   246,    69,    70,    71,    72,    73,
      74,   248,   295,   296,    40,   297,   247,  -156,  -156,   180,
     249,   175,   112,   250,   102,    34,   170,     0,   253,   104,
       0,     0,     0,     0,     0,     0,   108,   283,  -156,  -156,
    -156,     0,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,     0,  -156,     0,    54,    55,     0,  -156,  -156,  -156,
    -156,  -156,  -156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -156,  -156,  -154,    56,    57,    58,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    68,
       0,    54,    55,     0,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      25,   168,    56,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,    54,    55,
       0,    69,    70,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    25,   216,    56,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    68,    54,    55,     0,     0,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    25,    56,    57,    58,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    75,
      25,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    75,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
      49,    49,     0,    79,   175,    13,    13,    97,     1,     1,
       1,   113,    15,   226,     4,     5,    14,    53,    53,    17,
      27,    53,    20,   128,   129,    53,    29,     8,     9,    50,
      79,   121,    53,    15,    69,    71,    49,    69,    51,    67,
      43,    23,    36,   145,    51,    50,    55,    29,    53,   262,
      48,    60,    61,     4,     5,    56,    57,    52,    66,    49,
      53,    51,    68,    50,    70,   114,   115,   116,   116,   203,
     204,   205,   206,   175,     6,     7,    69,    69,    69,    68,
     170,    62,    63,    71,    50,    36,    37,    53,    68,   194,
      50,   193,    50,    53,    50,    53,   267,   104,    49,   102,
      10,    11,    52,    54,    55,    56,    57,    58,    59,   214,
      69,    50,    50,   215,    53,    53,    64,   222,   223,   224,
     196,   197,   198,    52,    53,   199,   200,    54,   201,   202,
      65,   221,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   207,   208,    12,     4,     5,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   267,   256,    50,   273,    53,
      67,    52,   274,    49,    49,   280,    49,    36,    37,    49,
      69,    69,    69,    50,    30,    50,    68,   277,   278,   279,
      49,    49,    28,    67,   209,    54,    55,    56,    57,    58,
      59,   211,   292,   293,     1,    69,   210,     4,     5,   116,
     212,    70,    51,   213,    43,    20,   102,    -1,   217,   217,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   275,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,     4,     5,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    49,
      -1,     4,     5,    -1,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,     4,     5,
      -1,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     4,     5,    -1,    -1,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    69,
      70,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    69,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   122,   123,   129,   130,   131,   143,   182,   183,
     184,   124,   126,   130,   123,    70,   122,   123,   150,   154,
      49,    51,   123,     0,   182,     1,    53,    69,   127,   150,
       1,   151,   152,   153,   130,   122,   150,   134,   135,   132,
     133,   125,    68,    71,     4,     5,    25,    26,    27,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    49,    54,
      55,    56,    57,    58,    59,    69,    73,    75,    81,    84,
      85,    86,    90,    93,    96,   101,   104,   106,   108,   110,
     112,   114,   117,   119,   144,   145,   150,   155,   156,   159,
     166,   177,   154,    50,   123,   136,   137,   139,    81,   114,
     121,    52,   126,   128,    82,    83,   146,   148,   160,   163,
     167,   170,   174,     1,   178,     1,   179,   180,   181,    74,
       4,     5,    49,    51,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    68,   118,    85,    55,    60,    61,
      56,    57,     6,     7,     8,     9,    62,    63,    10,    11,
      54,    64,    65,    12,    13,    66,    53,    69,    71,   144,
     155,   130,    50,    53,    52,    70,   117,   142,    81,    81,
     121,    67,    49,    49,    49,   144,    49,    69,    69,    69,
     119,   119,    77,    78,    76,   117,    87,    88,    89,    91,
      92,    94,    95,    99,   100,    97,    98,   102,   103,   105,
     107,   109,   111,   113,   115,   120,    71,   138,   140,   142,
      67,   149,   161,   164,   168,    30,   175,    69,    50,    50,
      79,   117,   119,    85,    85,    85,    86,    86,    90,    90,
      93,    93,    93,    93,    96,    96,   101,   104,   106,   108,
     110,   119,   117,   139,    53,    71,   147,   144,   119,   119,
     119,   171,   156,    50,    53,    52,    67,   141,   144,    50,
      50,    50,    49,   156,    80,   116,   142,   162,   165,   169,
     172,   119,   117,   114,   144,   144,   144,   119,    50,    28,
     157,    50,   176,   158,   173,   144,   144,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    74,    73,    75,    76,    75,    77,
      75,    78,    75,    75,    75,    79,    80,    79,    81,    82,
      81,    83,    81,    81,    84,    84,    84,    84,    84,    84,
      85,    86,    87,    86,    88,    86,    89,    86,    90,    91,
      90,    92,    90,    93,    94,    93,    95,    93,    96,    97,
      96,    98,    96,    99,    96,   100,    96,   101,   102,   101,
     103,   101,   104,   105,   104,   106,   107,   106,   108,   109,
     108,   110,   111,   110,   112,   113,   112,   114,   115,   116,
     114,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   120,   119,   121,   122,   122,
     123,   123,   123,   123,   124,   125,   124,   126,   127,   128,
     126,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   131,   132,   131,   133,   131,   134,   131,   135,   131,
     136,   137,   138,   137,   139,   139,   140,   141,   140,   142,
     142,   143,   144,   144,   144,   144,   144,   144,   146,   147,
     145,   148,   149,   145,   151,   150,   152,   150,   153,   150,
     150,   154,   154,   155,   155,   155,   156,   156,   158,   157,
     157,   160,   161,   162,   159,   163,   164,   165,   159,   167,
     168,   169,   166,   170,   171,   172,   173,   166,   174,   175,
     176,   166,   178,   177,   179,   177,   180,   177,   181,   177,
     177,   177,   182,   182,   183,   183,   183,   184,   184
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     4,     1,     0,     5,     0,
       4,     0,     5,     2,     2,     1,     0,     4,     1,     0,
       3,     0,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     0,     4,
       0,     4,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     1,     0,     4,     1,     0,     0,
       7,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     3,     3,
       1,     2,     1,     2,     1,     0,     4,     1,     0,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     0,     4,     0,     4,     0,     5,
       1,     1,     0,     4,     2,     1,     1,     0,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     0,     0,     5,     0,     3,     0,     4,     0,     5,
       2,     1,     2,     1,     2,     0,     1,     2,     0,     3,
       0,     0,     0,     0,     9,     0,     0,     0,     8,     0,
       0,     0,     8,     0,     0,     0,     0,    11,     0,     0,
       0,    10,     0,     3,     0,     3,     0,     3,     0,     4,
       2,     2,     1,     1,     3,     3,     2,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 84 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "%s", yytext); }
#line 1611 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "traductor.y" /* yacc.c:1646  */
    { if (!tam_vector) fprintf(yysalida, "%s", yytext); else tam_vector=0; }
#line 1617 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 1623 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 1629 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "[ "); }
#line 1635 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ]"); }
#line 1641 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 1647 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 93 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 1653 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 94 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 1659 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 94 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 1665 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 95 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "++"); }
#line 1671 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 96 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "--"); }
#line 1677 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 101 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ", "); }
#line 1683 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "++"); }
#line 1689 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 108 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "--"); }
#line 1695 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 114 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " & "); }
#line 1701 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 115 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " * "); }
#line 1707 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 116 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " + "); }
#line 1713 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 117 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " - "); }
#line 1719 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 118 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ~ "); }
#line 1725 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ! "); }
#line 1731 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " * "); }
#line 1737 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " / "); }
#line 1743 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 131 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " %% "); }
#line 1749 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 136 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " + "); }
#line 1755 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 137 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " - "); }
#line 1761 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 142 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " << "); }
#line 1767 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 143 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " >> "); }
#line 1773 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " < "); }
#line 1779 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 150 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " > "); }
#line 1785 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 151 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " <= "); }
#line 1791 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 152 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " >= "); }
#line 1797 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 158 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " == "); }
#line 1803 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 159 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " != "); }
#line 1809 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 164 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " & "); }
#line 1815 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 169 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ^ "); }
#line 1821 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 174 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " | "); }
#line 1827 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 180 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " && "); }
#line 1833 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 186 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " || "); }
#line 1839 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 192 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ? "); }
#line 1845 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 192 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " : "); }
#line 1851 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 201 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " = "); }
#line 1857 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 202 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " *= "); }
#line 1863 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 203 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " /= "); }
#line 1869 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 204 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " %%= "); }
#line 1875 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 205 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " += "); }
#line 1881 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 206 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " -= "); }
#line 1887 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 207 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " <<= "); }
#line 1893 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 208 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " >>= "); }
#line 1899 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 209 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " &= "); }
#line 1905 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 210 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ^= "); }
#line 1911 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 211 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " |= "); }
#line 1917 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 216 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ", "); }
#line 1923 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 225 "traductor.y" /* yacc.c:1646  */
    {
		for(symtable_set_type=sym_table; symtable_set_type!=(symrec *)0; symtable_set_type=(symrec *)symtable_set_type->next)
		{
			if(symtable_set_type->type==-1)
			{
				symtable_set_type->type=(yyvsp[-2].tipo);
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
#line 1946 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 243 "traductor.y" /* yacc.c:1646  */
    { yyerror("Falta un \";\". "); yyerrok; }
#line 1952 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 255 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 1958 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 260 "traductor.y" /* yacc.c:1646  */
    {
		s = getsym((yyvsp[0].nombre));
		if (s==(symrec *)0)
		{
			printf("Empty variable declarator.\n");
			s = putsym((yyvsp[0].nombre), -1, 0);
		}
		else
		{
			printf("Error: Variable declarada anteriormente.\n");
			yyerrok;	
		}
	}
#line 1976 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 274 "traductor.y" /* yacc.c:1646  */
    {
		s = getsym((yyvsp[0].nombre));
		if(s==(symrec *)0)
		{
			printf("Non empty variable declarator.\n");
			s = putsym((yyvsp[0].nombre), -1, 0);
		}
		else
		{
			printf("Error: Variable declarada anteriormente.\n");
			yyerrok;	
		}
	}
#line 1994 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 287 "traductor.y" /* yacc.c:1646  */
    { if (corchete==0) fprintf(yysalida, "="); }
#line 2000 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 303 "traductor.y" /* yacc.c:1646  */
    {(yyval.nombre)=(yyvsp[0].nombre);}
#line 2006 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 308 "traductor.y" /* yacc.c:1646  */
    { if (boolFuncion){ fprintf(yysalida, "function %s", yytext); boolFuncion=0; } else fprintf(yysalida, "var %s", yytext); (yyval.nombre)=(yyvsp[0].nombre); }
#line 2012 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 309 "traductor.y" /* yacc.c:1646  */
    { tam_vector=1; if (!cant_corchetes) fprintf(yysalida, "=new Array( "); cant_corchetes=1; }
#line 2018 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 310 "traductor.y" /* yacc.c:1646  */
    { corchete=1; }
#line 2024 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 311 "traductor.y" /* yacc.c:1646  */
    { if (!cant_corchetes) fprintf(yysalida, "=new Array( "); cant_corchetes=1; }
#line 2030 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 312 "traductor.y" /* yacc.c:1646  */
    { corchete=1; }
#line 2036 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 313 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2042 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 313 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2048 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 314 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2054 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 314 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2060 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 323 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ", "); }
#line 2066 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 328 "traductor.y" /* yacc.c:1646  */
    {
		s = getsym((yyvsp[0].nombre));
	    if(s==(symrec *)0)
	    {
	        printf("Parameter_declaration.\n");	    	
	        s = putsym((yyvsp[0].nombre), (yyvsp[-1].tipo), 0);
	    }
	    else
	    {
	        printf("Error: Variable declarada anteriormente.\n");
	        yyerrok;
	    }
	}
#line 2084 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 346 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " ,"); }
#line 2090 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 355 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "const "); }
#line 2096 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 368 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "case "); }
#line 2102 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 368 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ": "); }
#line 2108 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 369 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "default "); }
#line 2114 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 369 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ": "); }
#line 2120 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 373 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "{ "); }
#line 2126 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 373 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " }\n"); }
#line 2132 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 374 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "{\n"); }
#line 2138 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 374 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "}\n"); }
#line 2144 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 376 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "{\n"); }
#line 2150 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 376 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "}\n"); }
#line 2156 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 377 "traductor.y" /* yacc.c:1646  */
    { yyerror("Msj: Falta un \"}\"."); yyerrok; }
#line 2162 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 392 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2168 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 393 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2174 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 397 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "else"); }
#line 2180 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 402 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "if"); }
#line 2186 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 402 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2192 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 402 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2198 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 403 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "switch"); }
#line 2204 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 403 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2210 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 403 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2216 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 407 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "while"); }
#line 2222 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 407 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2228 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 407 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2234 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 408 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "do"); }
#line 2240 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 408 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "while"); }
#line 2246 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 408 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2252 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 408 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2258 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 408 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2264 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 409 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "for"); }
#line 2270 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 409 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "( "); }
#line 2276 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 409 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, " )"); }
#line 2282 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 413 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "continue"); }
#line 2288 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 413 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2294 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 414 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "break"); }
#line 2300 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 414 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2306 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 415 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "return"); }
#line 2312 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 415 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2318 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 416 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, "return "); }
#line 2324 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 416 "traductor.y" /* yacc.c:1646  */
    { fprintf(yysalida, ";\n"); }
#line 2330 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 417 "traductor.y" /* yacc.c:1646  */
    { yyerror("Msj: Falta un \";\" despues de continue en la sentencia."); yyerrok; }
#line 2336 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 418 "traductor.y" /* yacc.c:1646  */
    { yyerror ("Msj: Falta un \";\" despues de break en la sentencia."); yyerrok;}
#line 2342 "traductor.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 428 "traductor.y" /* yacc.c:1646  */
    {
		s = getsym((yyvsp[-1].nombre));
		if(s==(symrec *)0)
		{
			printf("Function_definition.\n");
			s = putsym((yyvsp[-1].nombre),(yyvsp[-2].tipo),1);
		}
		else
		{
			printf("Error: Funcion declarada anteriormente.");
			yyerrok;
		}
	}
#line 2360 "traductor.tab.c" /* yacc.c:1646  */
    break;


#line 2364 "traductor.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 452 "traductor.y" /* yacc.c:1906  */

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

const char * tipo_id(int tipo){
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

const char * tipo_var(int tipo){
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
	/* Debe tener 2 parametros, ejecutable.exe /path/to/fuente.c*/
	if (argc != 2)
	{
		printf("Error\n Forma de uso correcta: %s archivo.c\n", argv[0]);
		return 0;
	}
	if ((yyin = fopen(argv[1],"rt")) == NULL) /*  */
	{
		printf("No se pudo abrir el archivo fuente.\n");
                return 0;
	}
	char to[strlen(argv[1])+1];
  	strncpy(to, argv[1], strlen(argv[1])-1);
	strcat(to,"js\0");
	if ((yysalida=fopen(to, "w")) == NULL)//la salida es en el mismo path, fuente.js
	{
		printf("No se pudo crear el archivo destino.\n");
                return 0;
	}
	
	fprintf(yysalida, "\n");//BORRAR especifico de php
	yyparse();
	fprintf(yysalida, "\n");//BORRAR especifico de php
	fclose(yyin);
	fclose(yysalida);
	
	if(sin_error)
		printf("\nTraduccion finalizada, archivo destino %s\n",to);
	else
		printf("\nNo se pudo finalizar la traduccion.\n");

	//TODO sacar el archivo auxiliar
	FILE *simbolos;
	strcat(argv[1], ".txt");
	simbolos = fopen(argv[1], "w+");
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
