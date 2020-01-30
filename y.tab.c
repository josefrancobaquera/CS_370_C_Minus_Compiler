/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING = 259,
     NUM = 260,
     IF = 261,
     INT = 262,
     VOID = 263,
     RETURN = 264,
     ELSE = 265,
     WHILE = 266,
     READ = 267,
     WRITE = 268,
     LE = 269,
     GE = 270,
     EQ = 271,
     NE = 272,
     IFX = 273
   };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define NUM 260
#define IF 261
#define INT 262
#define VOID 263
#define RETURN 264
#define ELSE 265
#define WHILE 266
#define READ 267
#define WRITE 268
#define LE 269
#define GE 270
#define EQ 271
#define NE 272
#define IFX 273




/* Copy the first part of user declarations.  */
#line 23 "Lab6CMinus.y"


/* Begin Specifications */

/*
   #include several directories, including the header files 
   for Lab6AST which will be the file responsible for
   printing our our Abstract Syntax Tree. In addition, 
   include the symtable.h file since it will allow for us 
   to check semantic actions.
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lab6AST.h"
#include "symtable.h"
#include "EMITAST.h"

/*
   Extern the global variables found in lex. lineCunter will allow
   us to print the error line number if an error is found. mydebug 
   will allow us to turn off or on the comments that are printed 
   when we encounter a token. 
*/

/* Define a new function that will find the maximum
 of the two parameters. */
#define max(x,y) (((x) > (y) ? (x): (y)))
int lineCounter; 
int mydebug;
int level = 0;
int maxOffset;
FILE *fp;

/* 
   Declare two global int variables. One will keep track of the globalOffset and
   another one will be used as a temp variable for whenever we want to change
   the globalOffset.
*/
int globalOffset = 0;
int goffset = 0;

#define maxSize 26

/*
   regs will keep track of the value of the variable and actualSize will
   keep track of the number of variables declared.
*/

int regs[ maxSize ];
int actualSize = 0;


/*
   yyerror function. This function is called by yyparse if
   an error is found. The paramter is a string, meaning that 
   it can be sent a specific string message error.
*/

void yyerror ( s ) 
   char *s;
{

   /* If an error is found, print the line number in which they are found. */
   printf( "ERROR FOUND ON LINE NUMBER: %d.\n", lineCounter );
   
} /* end yyerror function */




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 106 "Lab6CMinus.y"
{
   int value;
   int level;
   char * string;
   ASTnode *node;
   enum OPERATORS operator;
}
/* Line 193 of yacc.c.  */
#line 213 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 226 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,    32,    30,    24,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    25,
      27,    29,    30,    31,    40,    42,    44,    46,    50,    53,
      58,    59,    65,    66,    69,    70,    73,    75,    77,    79,
      81,    83,    85,    87,    89,    92,    94,   100,   108,   114,
     118,   122,   125,   129,   133,   137,   139,   141,   146,   148,
     152,   154,   156,   158,   160,   162,   164,   166,   170,   172,
     174,   176,   180,   182,   184,   188,   190,   192,   194,   199,
     200,   202,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    -1,    37,    -1,    37,    36,    -1,
      38,    -1,    40,    -1,    39,     3,    19,    -1,    39,     3,
      20,     5,    21,    19,    -1,     7,    -1,     8,    -1,    -1,
      -1,    39,     3,    22,    41,    43,    42,    23,    46,    -1,
       8,    -1,    44,    -1,    45,    -1,    45,    24,    44,    -1,
      39,     3,    -1,    39,     3,    20,    21,    -1,    -1,    25,
      47,    48,    49,    26,    -1,    -1,    38,    48,    -1,    -1,
      50,    49,    -1,    51,    -1,    46,    -1,    52,    -1,    53,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      19,    -1,    19,    -1,     6,    22,    58,    23,    50,    -1,
       6,    22,    58,    23,    50,    10,    50,    -1,    11,    22,
      58,    23,    50,    -1,    59,    27,    51,    -1,     9,    58,
      19,    -1,     9,    19,    -1,    12,    59,    19,    -1,    13,
      58,    19,    -1,    13,     4,    19,    -1,    60,    -1,     3,
      -1,     3,    20,    58,    21,    -1,    62,    -1,    60,    61,
      62,    -1,    14,    -1,    28,    -1,    29,    -1,    15,    -1,
      16,    -1,    17,    -1,    64,    -1,    62,    63,    64,    -1,
      30,    -1,    31,    -1,    66,    -1,    64,    65,    66,    -1,
      32,    -1,    33,    -1,    22,    58,    23,    -1,     5,    -1,
      59,    -1,    67,    -1,     3,    22,    68,    23,    -1,    -1,
      69,    -1,    58,    -1,    58,    24,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   133,   134,   138,   139,   142,   160,   178,
     179,   182,   197,   182,   217,   218,   221,   222,   226,   243,
     262,   262,   280,   281,   285,   286,   290,   291,   292,   293,
     294,   295,   296,   297,   300,   307,   311,   315,   322,   327,
     342,   345,   350,   354,   356,   362,   365,   391,   418,   419,
     438,   439,   440,   441,   442,   443,   446,   447,   465,   466,
     469,   470,   487,   488,   491,   492,   496,   497,   500,   530,
     531,   534,   543
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "NUM", "IF", "INT",
  "VOID", "RETURN", "ELSE", "WHILE", "READ", "WRITE", "LE", "GE", "EQ",
  "NE", "IFX", "';'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "$accept", "program",
  "declarationlist", "declaration", "vardeclaration", "typespecifier",
  "fundeclaration", "@1", "@2", "params", "paramlist", "param",
  "compoundstmt", "@3", "localdeclarations", "statementlist", "statement",
  "expressionstmt", "selectionstmt", "iterationstmt", "assignmentstmt",
  "returnstmt", "readstmt", "writestmt", "expression", "var",
  "simpleexpression", "relop", "additiveexpression", "addop", "term",
  "multop", "factor", "call", "args", "arglist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    59,
      91,    93,    40,    41,    44,   123,   125,    61,    60,    62,
      43,    45,    42,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    41,    42,    40,    43,    43,    44,    44,    45,    45,
      47,    46,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    53,    54,
      55,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    68,
      68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     0,     0,     8,     1,     1,     1,     3,     2,     4,
       0,     5,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     3,
       3,     2,     3,     3,     3,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     4,     0,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     3,     5,     0,     6,     1,
       4,     0,     7,     0,    11,     0,     0,     0,    10,     0,
      12,    15,    16,     8,    18,     0,     0,     0,     0,    17,
      19,    20,    13,    22,    22,     0,    24,    23,     0,    46,
      65,     0,     0,     0,     0,     0,    35,     0,    27,     0,
      24,    26,    28,    29,    30,    31,    32,    33,     0,    66,
      45,    48,    56,    60,    67,     0,    69,     0,    41,     0,
      66,     0,    46,     0,     0,     0,     0,    21,    25,    34,
       0,    50,    53,    54,    55,    51,    52,     0,    58,    59,
       0,    62,    63,     0,     0,    71,     0,    70,     0,    40,
       0,    42,    44,    43,    64,    39,    49,    57,    61,    47,
       0,    68,     0,     0,    72,    36,    38,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    16,    25,    20,
      21,    22,    48,    33,    36,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    70,    60,    87,    61,    90,
      62,    93,    63,    64,    96,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int8 yypact[] =
{
      38,  -111,  -111,     5,  -111,    38,  -111,     9,  -111,  -111,
    -111,    21,  -111,    12,  -111,    27,    51,     8,    47,    61,
    -111,  -111,    50,  -111,    55,    48,    38,    57,    54,  -111,
    -111,  -111,  -111,    38,    38,    77,    10,  -111,    41,    22,
    -111,    60,    15,    62,    80,     6,  -111,    33,  -111,    59,
      10,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    67,    63,
      37,    32,    35,  -111,  -111,    33,    33,    33,  -111,    68,
    -111,    33,    69,    72,    73,    74,    65,  -111,  -111,  -111,
      28,  -111,  -111,  -111,  -111,  -111,  -111,    33,  -111,  -111,
      33,  -111,  -111,    33,    75,    70,    76,  -111,    78,  -111,
      79,  -111,  -111,  -111,  -111,  -111,    32,    35,  -111,  -111,
      33,  -111,    10,    10,  -111,    85,  -111,    10,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,    92,  -111,    39,    23,  -111,  -111,  -111,  -111,
      81,  -111,    82,  -111,    64,    53,  -110,    20,  -111,  -111,
    -111,  -111,  -111,  -111,   -41,   -36,  -111,  -111,    17,  -111,
      16,  -111,    18,  -111,  -111,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      59,    69,   115,   116,    75,     9,    76,   118,    73,    39,
      74,    40,    11,    39,    59,    40,    41,    15,    39,    42,
      40,    43,    44,    45,    94,    95,    98,    23,    47,    46,
     100,    39,    47,    40,    68,    31,    39,    47,    40,    19,
      12,    13,    65,    14,    66,     1,     2,    46,    17,    19,
      47,    81,    82,    83,    84,    47,    35,    35,     1,    18,
      12,    13,    88,    89,    24,    85,    86,    91,    92,    95,
     -14,    28,    34,    34,    26,    27,    59,    59,    30,    31,
      38,    59,    67,    72,    71,    77,    79,    99,   104,    65,
      80,   101,   102,   103,   110,   117,   109,    10,    37,   111,
     105,   112,   113,    78,   106,   114,   107,    29,     0,     0,
      32,   108
};

static const yytype_int8 yycheck[] =
{
      36,    42,   112,   113,    45,     0,    47,   117,    44,     3,
       4,     5,     3,     3,    50,     5,     6,     5,     3,     9,
       5,    11,    12,    13,    65,    66,    67,    19,    22,    19,
      71,     3,    22,     5,    19,    25,     3,    22,     5,    16,
      19,    20,    20,    22,    22,     7,     8,    19,    21,    26,
      22,    14,    15,    16,    17,    22,    33,    34,     7,     8,
      19,    20,    30,    31,     3,    28,    29,    32,    33,   110,
      23,    23,    33,    34,    24,    20,   112,   113,    21,    25,
       3,   117,    22,     3,    22,    26,    19,    19,    23,    20,
      27,    19,    19,    19,    24,    10,    21,     5,    34,    23,
      80,    23,    23,    50,    87,   110,    90,    26,    -1,    -1,
      28,    93
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    35,    36,    37,    38,    39,    40,     0,
      36,     3,    19,    20,    22,     5,    41,    21,     8,    39,
      43,    44,    45,    19,     3,    42,    24,    20,    23,    44,
      21,    25,    46,    47,    38,    39,    48,    48,     3,     3,
       5,     6,     9,    11,    12,    13,    19,    22,    46,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    62,    64,    66,    67,    20,    22,    22,    19,    58,
      59,    22,     3,    59,     4,    58,    58,    26,    49,    19,
      27,    14,    15,    16,    17,    28,    29,    61,    30,    31,
      63,    32,    33,    65,    58,    58,    68,    69,    58,    19,
      58,    19,    19,    19,    23,    51,    62,    64,    66,    21,
      24,    23,    23,    23,    69,    50,    50,    10,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 129 "Lab6CMinus.y"
    { rootNode = (yyvsp[(1) - (1)].node); }
    break;

  case 3:
#line 133 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 4:
#line 134 "Lab6CMinus.y"
    { (yyvsp[(1) - (2)].node)->next = (yyvsp[(2) - (2)].node); 
                                                (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 5:
#line 138 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 139 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 142 "Lab6CMinus.y"
    { if( Search( (yyvsp[(2) - (3)].string), level, 0 ) == NULL ) { /* A variable declaration can be "regular." */
                                           (yyval.node) = ASTCreateNode( VARDEC ); /* Create a ASTnode of type VARDEC. */
                                           (yyval.node)->operator = (yyvsp[(1) - (3)].operator); /* Store the operator type and the name of the vardeclaration in the node's payload. */    
                                           (yyval.node)->symbol = Insert( (yyvsp[(2) - (3)].string), (yyvsp[(1) - (3)].operator), 0, level, 1, globalOffset, NULL, 0 ); /* Make symbol point to the newly created SymbTab created. */
                                           (yyval.node)->name = (yyvsp[(2) - (3)].string); /* Store the name of the variable in the ASTCreateNode node. */
                                           (yyval.node)->value = 0; /* Store 0 as the value. This will help us differenciate between an array and an int declaration. */
                                           (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (3)].operator); /* Store the type of the declaration in the attribute. */
                                           globalOffset++; /* Increment the global offset. Since this is an integer declaration, offeset increments by 1. */ 
                                           } /* end if */
                                        else {
                                           /* If the variable is already declared, print out an error. */
                                           yyerror( ); 
                                           printf( "Type of Error --> '%s' already defined.\n", (yyvsp[(2) - (3)].string) );
                                           exit( 1 );         
                                        } /* end else */
                                        
                                }
    break;

  case 8:
#line 160 "Lab6CMinus.y"
    { if( Search( (yyvsp[(2) - (6)].string), level, 0 ) == NULL ) { /* Check if the variable being declared is already declared in level 0. */
                                                       (yyval.node) = ASTCreateNode( VARDEC ); /* Create a ASTnode of type VARDEC. */ 
                                                       (yyval.node)->operator = (yyvsp[(1) - (6)].operator); /* Store the operator type and the name of the vardeclaration in the node's payload. */
                                                       (yyval.node)->symbol = Insert( (yyvsp[(2) - (6)].string), (yyvsp[(1) - (6)].operator), 0, level, (yyvsp[(4) - (6)].value), globalOffset, NULL, 1 ); /* Make symbol point to the newly created SymbTab created. */
                                                       (yyval.node)->name= (yyvsp[(2) - (6)].string); /* Store the operator type and the name of the vardeclaration in the node's payload. */ 
                                                       (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (6)].operator); /* Store the type of the declaration in the attribute. */
                                                       (yyval.node)->value = (yyvsp[(4) - (6)].value); /* In addition, store the value of the array into the node's payload. */
                                                       globalOffset = globalOffset + (yyvsp[(4) - (6)].value); /* Update the globalOffset. This offeset will increment by the number located inside the brakets. */   
                                                    } /* end if */
                                                    else {
                                                       /* If the variable was already declared in level 0, print out an error and exit. */
                                                       yyerror( ); 
                                                       printf( "Type of Error --> '%s' already defined.\n", (yyvsp[(2) - (6)].string) );
                                                       exit( 1 ); 
                                                    } /* end else */
                                                  }
    break;

  case 9:
#line 178 "Lab6CMinus.y"
    { (yyval.operator) = INTTYPE; }
    break;

  case 10:
#line 179 "Lab6CMinus.y"
    { (yyval.operator) = VOIDTYPE; }
    break;

  case 11:
#line 182 "Lab6CMinus.y"
    { if( Search( (yyvsp[(2) - (3)].string), level, 0 ) == NULL ){ /* Check if the function has already been declared on level 0. */
                                          Insert( (yyvsp[(2) - (3)].string), (yyvsp[(1) - (3)].operator), 1, level, 0, 0, NULL, 0 ); /* Insert a new symbol in the symboltable that will keep track of the function being declared . */
                                          goffset = globalOffset; /* Remember the globalOffset before changing it. */ 
                                          globalOffset = 2; /* Change globalOffset to 2 since each function will need to have one word for the base pointer and one word for the stack pointer. */
                                          maxOffset = globalOffset; /* Update maxOffset to be the same as globalOffset. */
                                          /* Should the two prev, prev lines be swtiched? */
                                        } /* end if */
                                        else {
                                           /* If the function was already declared, print an error and exit. */
                                           yyerror( ); 
                                           printf( "Type of Error --> '%s' already defined.\n", (yyvsp[(2) - (3)].string) );
                                           exit( 1 ); 
                                        } /* end else */
                                     }
    break;

  case 12:
#line 197 "Lab6CMinus.y"
    {
                                        /* Make fparms of the newly created node point to the params. */
                                        (Search((yyvsp[(2) - (5)].string), 0, 0))->fparms = (yyvsp[(5) - (5)].node);
                                     }
    break;

  case 13:
#line 204 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( FUNDEC ); /* Create a ASTnode of type FUNDEC. */
                                   (yyval.node)->operator = (yyvsp[(1) - (8)].operator); /* Store the type and name of the fundeclaration into the node's payload. */
                                   (yyval.node)->name = (yyvsp[(2) - (8)].string); /* Store the name on the node's payload. */
                                   (yyval.node)->stmt0 = (yyvsp[(5) - (8)].node); /* stmt0 will point to the function's parameters while stmt1 will point to the */
                                   (yyval.node)->stmt1 = (yyvsp[(8) - (8)].node); /*Change these $$*/ 
                                   (yyval.node)->symbol = Search( (yyvsp[(2) - (8)].string), 0, 0 ); /* Make symbol point to the created function node in the symboltable.  */
                                   (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (8)].operator); /* Update the type of declaration of the AST node.  */   
                                   (yyval.node)->value = maxOffset; /* Store the new maxOffset in the node's payload. */
                                   (Search((yyvsp[(2) - (8)].string), 0, 0))->mysize = maxOffset; /* Store the new maxOffset in the node's payload. */
                                   globalOffset = goffset; /* Restore the globalOffset to its original value. */                 
                                 }
    break;

  case 14:
#line 217 "Lab6CMinus.y"
    { (yyval.node) = NULL; }
    break;

  case 15:
#line 218 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:
#line 221 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 17:
#line 222 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); /* Make paramlist point to the first node created in paramlist. */
                                  (yyvsp[(1) - (3)].node)->next =(yyvsp[(3) - (3)].node); /* Since this is a list, we need to use "next." */
                                }
    break;

  case 18:
#line 226 "Lab6CMinus.y"
    { if( Search( (yyvsp[(2) - (2)].string), level + 1, 0 ) == NULL ) { /* Check if the param being declared has already beeen declared in the same level. */
                              (yyval.node) = ASTCreateNode( PARAM ); /* Create a new ASTnode node type PARAM. */
                              (yyval.node)->operator = (yyvsp[(1) - (2)].operator); /* Store the operator type on the node's payload. */
                              (yyval.node)->name = (yyvsp[(2) - (2)].string); /* Store the name on the node's payload. */
                              (yyval.node)->value = 10; /* Use a "dummy" variable to distinguish the param as an array. */
                              (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (2)].operator); /* Update the type of declaration of the AST node. */
                              (yyval.node)->symbol = Insert((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].operator), 0, level + 1, 1, globalOffset, NULL, 0 ); /* Make symbol point to the newly created symbol table node. */
                              globalOffset++; /* Since this is an int, the globalOffset increments by 1. */
                           /* Params will always be level 1. */
                           } /* end if */
                           else {
                              /* If the variable was already declared, print an error and exit. */
                              yyerror( ); 
                              printf( "Type of Error --> '%s' already defined.\n", (yyvsp[(2) - (2)].string) );
                              exit( 1 ); 
                           } /* end else*/
                           }
    break;

  case 19:
#line 243 "Lab6CMinus.y"
    { if( Search( (yyvsp[(2) - (4)].string), level + 1, 0 ) == NULL ) { /* Check if the param being declared has already beeen declared in the same level. */
                                       (yyval.node) = ASTCreateNode( PARAM ); /* Create a new ASTnode node type PARAM. */
                                       (yyval.node)->operator = (yyvsp[(1) - (4)].operator); /* Store the operator type on the node's payload. */
                                       (yyval.node)->name = (yyvsp[(2) - (4)].string); /* Store the name on the node's payload. */
                                       (yyval.node)->value = 11; /* Use a "dummy" variable to distinguish the param as an array. */
                                       (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (4)].operator); /* Update the type of declaration of the AST node. */
                                       (yyval.node)->symbol = Insert( (yyvsp[(2) - (4)].string), (yyvsp[(1) - (4)].operator), 0, level + 1, 1, globalOffset, NULL, 1 ); /* Make symbol point to the newly created symbol table node. */
                                       globalOffset++; /* Even though this is an array, globalOffset still increments by 1. */
                                      /* Params will always be level 1. */
                                } /* end if */
                                else {
                                   /* If the variable was already declared, print an error and exit. */
                                   yyerror( ); 
                                   printf( "Type of Error --> '%s' already defined.\n", (yyvsp[(2) - (4)].string) );
                                   exit( 1 ); 
                                } /* end else*/
                            }
    break;

  case 20:
#line 262 "Lab6CMinus.y"
    { level++; }
    break;

  case 21:
#line 264 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode(BLOCK); /* Create a new ASTnode node type BLOCK. */
                                                         if( (yyvsp[(3) - (5)].node) == NULL) { /*No local declarations found. stmt0 will point to NULL. */ 
                                                            (yyval.node)->stmt1 = (yyvsp[(4) - (5)].node); /* Make stmt1 point to the first node created in statementlist. */
                                                         } /* end if */
                                                         else{
                                                            (yyval.node)->stmt0 = (yyvsp[(3) - (5)].node); /* Make stmt0 point to the first node created in localdeclarations. */
                                                            (yyval.node)->stmt1 = (yyvsp[(4) - (5)].node); /* Make stmt1 point to the first node created in statementlist. */
                                                         } /* end else */ 
                                                         if( mydebug ) {
                                                            Display( ); /* Display the symbol table if mydebug is true. */
                                                         } /* end if */
                                                         maxOffset= max(maxOffset, globalOffset); /* maxOffset will be the bigger value between maxOffset and globalOffset. */
                                                         globalOffset = globalOffset - Delete(level); /* Update the globalOffset and Delete all variables at the current level. */ 
                                                         level--; /* Decrement level by 1 since we are exiting out a compoundstmt. */ }
    break;

  case 22:
#line 280 "Lab6CMinus.y"
    { (yyval.node) = NULL; }
    break;

  case 23:
#line 281 "Lab6CMinus.y"
    { (yyvsp[(1) - (2)].node)->next = (yyvsp[(2) - (2)].node); /* Since this is a list, we need to use "next." */
                                                       (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 24:
#line 285 "Lab6CMinus.y"
    { (yyval.node) = NULL; }
    break;

  case 25:
#line 286 "Lab6CMinus.y"
    { (yyvsp[(1) - (2)].node)->next = (yyvsp[(2) - (2)].node); /* Since this is a list, we need to use "next." */
                                          (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 26:
#line 290 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
#line 291 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 28:
#line 292 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 29:
#line 293 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 30:
#line 294 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:
#line 295 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 32:
#line 296 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:
#line 297 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 34:
#line 300 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( EXPRSTMT ); /* Create a new ASTnode node type EXPRSTMT. */
                                  (yyval.node)->stmt0 = (yyvsp[(1) - (2)].node); /* stmt0 will point to the first node created in the nonterminal expression. */
                                  (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (2)].node)->typeOfDeclaration; /* */
                                  (yyval.node)->name = CreateTemp( ); /* Create a temp string and store it into name. */
                                  (yyval.node)->symbol = Insert( (yyval.node)->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                  globalOffset++;
                                }
    break;

  case 35:
#line 307 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( EXPRSTMT ); /* Create a new ASTnode node type EXPRSTMT. */
                       (yyval.node)->stmt0 = NULL; }
    break;

  case 36:
#line 311 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( IFSTMT ); /* Create a new ASTnode node type IFSTMT. */
                                                            (yyval.node)->stmt0 = (yyvsp[(3) - (5)].node); /* stmt0 will point to the first node created in the nonterminal expression. */
                                                            (yyval.node)->stmt1 = (yyvsp[(5) - (5)].node); /* stmt1 will point to the first node created in the nonterminal statement. */
                                                            (yyval.node)->stmt2 = NULL; }
    break;

  case 37:
#line 315 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( IFSTMT ); /* Create a new ASTnode node type IFSTMT. */
                                                                 (yyval.node)->stmt0 = (yyvsp[(3) - (7)].node); /* stmt0 will point to the first node created in the nonterminal expression. */
                                                                 (yyval.node)->stmt1 = (yyvsp[(5) - (7)].node); /* stmt1 will point to the first node created in the nonterminal statement. */
                                                                 (yyval.node)->stmt2 = (yyvsp[(7) - (7)].node); }
    break;

  case 38:
#line 322 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( ITSTMT ); /* Create a new ASTnode node type ITSTMT. */
                                                     (yyval.node)->stmt0 = (yyvsp[(3) - (5)].node); /* Make stmt0 point to the first node created in the nonterminal expression. */
                                                     (yyval.node)->stmt1 = (yyvsp[(5) - (5)].node); }
    break;

  case 39:
#line 327 "Lab6CMinus.y"
    { (yyval.node)=ASTCreateNode(ASSIGN); /* Create a new ASTnode node type ASSIGN. */
                                           if( ( (yyvsp[(1) - (3)].node)->typeOfDeclaration == VOIDTYPE ) || ( (yyvsp[(1) - (3)].node)->typeOfDeclaration != (yyvsp[(3) - (3)].node) ->typeOfDeclaration ) ) {
                                              /* Check the the right hand side is not a void and that the right and left hand side match in types. */
                                              /* If they do not match, print an error and exit. */
                                              yyerror( );
                                              printf( "Type of Error --> Assignment statement mismatch. Left is not the same as right.\n" );
                                              exit( 1 );
                                           } /* end if */
                                           (yyval.node)->stmt0 = (yyvsp[(1) - (3)].node); /* stmt0 will point to the first node created in the nonterminal var. */
                                           (yyval.node)->stmt1 = (yyvsp[(3) - (3)].node);                                           
                                           }
    break;

  case 40:
#line 342 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode(RETURNSTMT); /* Create a new ASTnode node type RETURNSTMT. */
                                     (yyval.node)->stmt0 = (yyvsp[(2) - (3)].node); 
                                     }
    break;

  case 41:
#line 345 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode(RETURNSTMT); /* Create a new ASTnode node type RETURNSTMT. */
                          (yyval.node)->stmt0 = NULL; 
                          }
    break;

  case 42:
#line 350 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode(READSTMT); /* Create a new ASTnode node type READSTMT. */
                          (yyval.node)->stmt0 = (yyvsp[(2) - (3)].node); }
    break;

  case 43:
#line 354 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( WRITESTMT); /* Create a new ASTnode node type WRITESTMT. */
                                   (yyval.node)->stmt0 = (yyvsp[(2) - (3)].node); }
    break;

  case 44:
#line 356 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode( WRITESTMT); /* A user can also write a string into the screen. */
                                (yyval.node)->stmt0 = NULL; /* If stmt0 points to NULL, we know that the user wants to write a string. */
                                (yyval.node)->name = (yyvsp[(2) - (3)].string); /* Store the string into the node's payload. */
                                (yyval.node)->label = CreateLabel( ); }
    break;

  case 45:
#line 362 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 46:
#line 365 "Lab6CMinus.y"
    { struct SymbTab *p;
           if ( ( p = Search( (yyvsp[(1) - (1)].string), level, 1 ) ) == NULL ) { /* Check if the variable has been declared before. */
              /* If the variable was not found, print an error and exit. */
              yyerror( ); 
              printf( "Type of Error --> '%s' is undeclared.\n", (yyvsp[(1) - (1)].string) );
              exit( 1 ); 
           } /* end if */
           if( p->IsAFunc == 1 ) {
              /* If the variable is a function type, print an error and exit. */
              yyerror( ); 
              printf( "Type of Error --> Incompatible types. '%s' is function variable.\n", (yyvsp[(1) - (1)].string) );
              exit( 1 ); 
           } /* end inner if */ 
           if( p->isArray == 1 ) {
             /* If the variable is an array, print an error and exit. */
              yyerror( ); 
              printf( "Type of Error --> Incompatible types. '%s' is a an array variable.\n", (yyvsp[(1) - (1)].string) );
              exit( 1 ); 
           } /* end if */
              (yyval.node) = ASTCreateNode(IDENT); /* Create a new ASTnode node type IDENT. */
              (yyval.node)->name = (yyvsp[(1) - (1)].string); /* Store the name on the node's payload. */
              (yyval.node)->stmt0 = NULL; /* Since this is not an array, point stmt0 to NULL since there are no expression. */
              (yyval.node)->symbol = p; /* Make symbol point to the variable found in the symbol table. */
              (yyval.node)->value = 15; /* Store a "dummy number" that will allow us to distinguish between both var nodes. */
              (yyval.node)->typeOfDeclaration = p->Type; /* Inherit the type. */
         }
    break;

  case 47:
#line 391 "Lab6CMinus.y"
    { struct SymbTab *p;
                             if ( ( p = Search( (yyvsp[(1) - (4)].string), level, 1 ) ) == NULL ) { 
                                 /* Check that the variable has been defined in other previous levels. */
                                 /* If the varible has not been defined, print an error message and exit. */
                                 yyerror( ); 
                                 printf( "Type of Error --> '%s' is undeclared.\n", (yyvsp[(1) - (4)].string) );
                                 exit( 1 ); 
                              } /* end if */
                             if ( p->IsAFunc == 1 ) {
                                /* If the variable is a function type, print an error and exit. */
                                yyerror( ); 
                                printf( "Type of Error --> Incompatible types. '%s' is function variable.\n", (yyvsp[(1) - (4)].string) );
                                exit( 1 ); 
                             } /* end if */
                             if( p->isArray == 0 ) {
                                /* If the variable being used is not an array, print an error and exit. */
                                yyerror( ); 
                                printf( "Type of Error --> Incompatible types. '%s' is a scalar.\n", (yyvsp[(1) - (4)].string) );
                                exit( 1 ); 
                             } /* end if */
                                (yyval.node)=ASTCreateNode(IDENT); /* Create a new ASTnode node type IDENT. */
                                (yyval.node)->name = (yyvsp[(1) - (4)].string); /* Store the name on the node's payload. */
                                (yyval.node)->stmt0 = (yyvsp[(3) - (4)].node); /* stmt0 will point to the nodes created in expression.*/
                                (yyval.node)->symbol = p; /* Inherit the type. */
                                (yyval.node)->typeOfDeclaration = p->Type; /* Inherit the type. */
                             }
    break;

  case 48:
#line 418 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 49:
#line 419 "Lab6CMinus.y"
    { /* We need to to type checking. */
                                                               /* Do type checking. */
                                                               if( (yyvsp[(1) - (3)].node)->typeOfDeclaration != (yyvsp[(3) - (3)].node)->typeOfDeclaration) {
                                                                  /* If the right type does not equalto left type, print an error and exit. */
                                                                  yyerror( );
                                                                  printf( "Type of Error --> Simpleexpression expression type mismatch.\n" );
                                                                  exit( 1 ); 
                                                               } /* end if */
                                                                  (yyval.node) = ASTCreateNode( EXPR ); /* Create a new ASTnode node type EXPR. */
                                                                  (yyval.node)->stmt0 = (yyvsp[(1) - (3)].node); /* stmt0 will point to the nodes created in simpleexpression. */
                                                                  (yyval.node)->operator = (yyvsp[(2) - (3)].operator); /* Store the operator type on the node's payload. */
                                                                  (yyval.node)->stmt1 = (yyvsp[(3) - (3)].node); /* stmt1 will point to the nodes created in additiveexpression. */
                                                                  (yyval.node)->typeOfDeclaration = INTTYPE; /* We already checked that we do not use void type */
                                                                  (yyval.node)->name = CreateTemp( ); /* Create a temp variable that will allow us to do expression assembly. */
                                                                  (yyval.node)->symbol = Insert( (yyval.node)->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                                                  globalOffset++; /* Increment globalOffset by 1. */
                                                               }
    break;

  case 50:
#line 438 "Lab6CMinus.y"
    { (yyval.operator) = LESSTHANEQUAL; }
    break;

  case 51:
#line 439 "Lab6CMinus.y"
    { (yyval.operator) = LESSTHAN; }
    break;

  case 52:
#line 440 "Lab6CMinus.y"
    { (yyval.operator) = GREATERTHAN; }
    break;

  case 53:
#line 441 "Lab6CMinus.y"
    { (yyval.operator) = GREATERTHANEQUAL; }
    break;

  case 54:
#line 442 "Lab6CMinus.y"
    { (yyval.operator) = EQUAL; }
    break;

  case 55:
#line 443 "Lab6CMinus.y"
    { (yyval.operator) = NOTEQUAL; }
    break;

  case 56:
#line 446 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:
#line 447 "Lab6CMinus.y"
    { /* We need to to type checking. */
                                                              if( (yyvsp[(1) - (3)].node)->typeOfDeclaration != (yyvsp[(3) - (3)].node)->typeOfDeclaration) {
                                                                 /* If the right type does not equalto left type, print an error and exit. */
                                                                  yyerror( );
                                                                  printf( "Type of Error --> Additive expression type mismatch.\n" );
                                                                  exit( 1 ); 
                                                               } /* end if */
                                                                  (yyval.node) = ASTCreateNode( EXPR ); /* Create a new ASTnode node type EXPR. */
                                                                  (yyval.node)->stmt0 = (yyvsp[(1) - (3)].node); /* stmt0 will point to the nodes created in simpleexpression. */
                                                                  (yyval.node)->operator = (yyvsp[(2) - (3)].operator); /* Store the operator type on the node's payload. */
                                                                  (yyval.node)->stmt1 = (yyvsp[(3) - (3)].node); /* stmt1 will point to the nodes created in additiveexpression. */
                                                                  (yyval.node)->typeOfDeclaration = INTTYPE; /* We already checked that we do not use void type */
                                                                  (yyval.node)->name = CreateTemp( ); /* Create a temp variable that will allow us to do expression assembly. */
                                                                  (yyval.node)->symbol = Insert( (yyval.node)->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                                                  globalOffset++; /* Increment globalOffset by 1. */
                                                               }
    break;

  case 58:
#line 465 "Lab6CMinus.y"
    { (yyval.operator) = PLUS; }
    break;

  case 59:
#line 466 "Lab6CMinus.y"
    { (yyval.operator) = MINUS; }
    break;

  case 60:
#line 469 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 61:
#line 470 "Lab6CMinus.y"
    {  /* We need to to type checking. */  if( (yyvsp[(1) - (3)].node)->typeOfDeclaration != (yyvsp[(3) - (3)].node)->typeOfDeclaration) {
                                                                  /* If the right type does not equalto left type, print an error and exit. */
                                                                  yyerror( );
                                                                  printf( "Type of Error --> Term expression type mismatch.\n" );
                                                                  exit( 1 ); 
                                                               } /* end if */
                                                                  (yyval.node) = ASTCreateNode( EXPR ); /* Create a new ASTnode node type EXPR. */
                                                                  (yyval.node)->stmt0 = (yyvsp[(1) - (3)].node); /* stmt0 will point to the nodes created in simpleexpression. */
                                                                  (yyval.node)->operator = (yyvsp[(2) - (3)].operator); /* Store the operator type on the node's payload. */
                                                                  (yyval.node)->stmt1 = (yyvsp[(3) - (3)].node); /* stmt1 will point to the nodes created in additiveexpression. */
                                                                  (yyval.node)->typeOfDeclaration = INTTYPE; /* We already checked that we do not use void type */
                                                                  (yyval.node)->name = CreateTemp( ); /* Create a temp variable that will allow us to do expression assembly. */
                                                                  (yyval.node)->symbol = Insert( (yyval.node)->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                                                  globalOffset++; /* Increment globalOffset by 1. */
                                                               }
    break;

  case 62:
#line 487 "Lab6CMinus.y"
    {(yyval.operator) = MULT; }
    break;

  case 63:
#line 488 "Lab6CMinus.y"
    {(yyval.operator) = DIV; }
    break;

  case 64:
#line 491 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 65:
#line 492 "Lab6CMinus.y"
    { (yyval.node) = ASTCreateNode(NUMBER);  /* Create a new ASTnode node type NUMBER. */
               (yyval.node)->value = (yyvsp[(1) - (1)].value); 
               (yyval.node)->typeOfDeclaration = INTTYPE;
               }
    break;

  case 66:
#line 496 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 67:
#line 497 "Lab6CMinus.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 68:
#line 500 "Lab6CMinus.y"
    { struct SymbTab *p;
                         /* First check if the function has already been declared. */
                         if( ( p = Search( (yyvsp[(1) - (4)].string), 0, 0 ) ) == NULL ) { 
                            /* If the function name is not inside the symbol table, print an error message and exit. */
                             yyerror( );
                             printf( "Type of Error --> Undeclared Function %s.\n", (yyvsp[(1) - (4)].string) );
                             exit( 1 ); 
                         } 
                         /* Check if the variable found is a function type. */
                         if( p->IsAFunc != 1 ) {
                            /* If the variable found is not a funtion type, print an error message and exit. */
                            yyerror( );
                            printf( "Type of Error --> %s is not a function.\n", (yyvsp[(1) - (4)].string) );
                            exit( 1 ); 
                         } /* end if */
                         /* Compare formal and actual paramters. */
                         if( CompareFormals( p->fparms, (yyvsp[(3) - (4)].node) ) != 1 ) {
                            /* If the formal and actual parameters do not match, print an error and exit. */
                            yyerror( );
                            printf( "Type of Error --> Formal and Actual Parameter Mistmatch. Type or length mismatch.\n", (yyvsp[(1) - (4)].string) );
                            exit( 1 ); 
                         } /* end if */
                         (yyval.node) = ASTCreateNode( CALL ); /* Create a new ASTnode node type CALL. */
                         (yyval.node)->stmt0 = (yyvsp[(3) - (4)].node); /* stmt0 will point to the nodes created in args. */
                         (yyval.node)->name = (yyvsp[(1) - (4)].string); /* Store the name of the ID inside the node's payload. */
                         (yyval.node)->typeOfDeclaration = p->Type; /* Update the type. */
                         (yyval.node)->symbol = p; /* Make symbol point to the variable found. */  
                       }
    break;

  case 69:
#line 530 "Lab6CMinus.y"
    { (yyval.node) = NULL; }
    break;

  case 70:
#line 531 "Lab6CMinus.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 71:
#line 534 "Lab6CMinus.y"
    { (yyval.node)=ASTCreateNode( ARGLIST ); /* Create a new ASTnode node type ARGLIST. */
                                   (yyval.node)->name = CreateTemp( ); /* Create a temp variable since an argument can be an expression. */
                                   (yyval.node)->next = NULL; /* Make stmt0 point to the expression. However, make "next" */
                                   (yyval.node)->stmt0 = (yyvsp[(1) - (1)].node);  /* point to NULL since there are no more expressions found. */
                                   (yyval.node)->symbol = Insert( (yyval.node)->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0 ); /* Insert the argument into the symbol table. */
                                   (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (1)].node)->typeOfDeclaration; /* Update the globalOffset by 1. */
                                   globalOffset++; /* Update the globalOffset by 1. */
                                   
                     }
    break;

  case 72:
#line 543 "Lab6CMinus.y"
    { (yyval.node)=ASTCreateNode( ARGLIST ); /* Create a new ASTnode node type ARGLIST. */
                                   (yyval.node)->name = CreateTemp( ); /* Create a temp variable since an argument can be an expression. */
                                   (yyval.node)->next = (yyvsp[(3) - (3)].node); /* Since this is a list, we need to make the node's "next" point to the arglist. */
                                   (yyval.node)->stmt0 = (yyvsp[(1) - (3)].node); /* stmt0 will point to the expression. */            
                                   (yyval.node)->symbol = Insert( (yyval.node)->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0 ); /* Insert the argument into the symbol table. */
                                   (yyval.node)->typeOfDeclaration = (yyvsp[(1) - (3)].node)->typeOfDeclaration; /* Update the globalOffset by 1. */
                                   globalOffset++; /* Increment globalOffset by 1. */
                                 }
    break;


/* Line 1267 of yacc.c.  */
#line 2164 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 555 "Lab6CMinus.y"
 /* End of rules, start of program. */

/* Main Function */
main( int argv, char * argc[ ] ) {

   // Declare several variables to make creating a file easier.
   int i = 0;
   int flag = 0;
   char * s;
 
   // Check for all the arguments that are passed down by the user.
   while( i < argv ) {
   
      // If the user inputted the debug flag, set mydebug to 1. 
      if( strcmp( argc[i], "-d" ) == 0 ) { 
         mydebug = 1;
      } // end if.
      
      // If the user inputed the executable flag, the element next to it must 
      // be the name of the file we want. Update fp.
      if( strcmp( argc[ i ], "-o") == 0 ) {
         flag = 1;
         sprintf( s, "%s.asm", argc[ i + 1 ] );
         fp = fopen( s, "w" );
      } // end if. 
        
      // Increment i.
      i++;
   
   } // end while.
   
   // If fp equals to null, the user did not enter the -o flag. Exit
   // since if we run the program, we will get a segment fault. 
   if( fp == NULL ) {
      printf( "ERROR: MUST HAVE A FILE NAME WITH AN EXECUTABLE FLAG -o with file name.\n" );
      printf( "Making a default file named default.asm\n" );
      sprintf( s, "default.asm" );
      fp = fopen( s, "w" );
      //exit(1);
   } // end if.
   
   // Parse the tree.
   yyparse();
   
   if( mydebug ) {
      /* Print a meaningful message.*/
      printf( "The input has been syntactically checked. Here is the AST.\n");
      
      /* This is were we can print the AST starting at the rootNode. */
      /* NOTE: We comment the ASTprint( ) since it makes the output cluttered. */ 
      ASTprint( 0, rootNode);   

      /* Display the symbol table and print a meaningful message. */

      printf( "\nMain symbol table START\n" );
      Display( );
      printf( "\nMain symbol table END\n\n" );

   } // end if.
   
   // Call emitAST with the root node in order to produce the assembly code.
   emitAST( fp, rootNode );
   
   // Close the FILE object.
   fclose( fp );

} // end main.

