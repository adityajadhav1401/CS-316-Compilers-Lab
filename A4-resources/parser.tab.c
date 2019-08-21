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
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <assert.h>
	int yylex(void);
    void yyerror(string s){};
    extern int yylineno;
    Procedure * main_procedure;

#line 75 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INTEGER_NUMBER = 258,
    DOUBLE_NUMBER = 259,
    ARITHOP = 260,
    INTEGER = 261,
    FLOAT = 262,
    ASSIGN = 263,
    VOID = 264,
    RETURN = 265,
    LESS_THAN = 266,
    GREATER_THAN = 267,
    LESS_THAN_EQUAL = 268,
    GREATER_THAN_EQUAL = 269,
    EQUAL = 270,
    NOT_EQUAL = 271,
    NOT = 272,
    AND = 273,
    OR = 274,
    WHILE = 275,
    DO = 276,
    IF = 277,
    ELSE = 278,
    NAME = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "parser.y" /* yacc.c:355  */

	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	list<Symbol_Table_Entry *> * symbol_entry_list;
	Basic_Block * basic_block;
	Procedure * procedure;
	Program * program;
	Sequence_Ast * sequence_ast;

#line 155 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 172 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    29,    27,    36,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    35,
       2,     2,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    71,    84,    85,    90,    88,   109,   110,
     113,   116,   123,   126,   136,   148,   153,   160,   161,   168,
     172,   179,   180,   183,   186,   189,   192,   201,   202,   209,
     223,   226,   231,   234,   239,   248,   262,   267,   272,   276,
     277,   280,   290,   300,   310,   320,   330,   343,   353,   363,
     366,   372,   382,   392,   396,   400,   403,   409,   430,   435,
     438
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_NUMBER", "DOUBLE_NUMBER",
  "ARITHOP", "INTEGER", "FLOAT", "ASSIGN", "VOID", "RETURN", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "EQUAL",
  "NOT_EQUAL", "NOT", "AND", "OR", "WHILE", "DO", "IF", "ELSE", "NAME",
  "':'", "'?'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'",
  "';'", "','", "$accept", "program", "$@1", "declaration_list",
  "procedure_definition", "$@2", "optional_variable_declaration_list",
  "variable_declaration_list", "variable_declaration", "declaration",
  "variable_list", "statement_list", "sequence_list", "statement",
  "open_statement", "closed_statement", "iterative_matched_statement",
  "iterative_unmatched_statement", "simple_assignment_statement",
  "conditional_expression", "logical_expression", "relational_expression",
  "expression", "term", "identifier", "variable", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    58,    63,    43,    45,    42,
      47,    40,    41,   123,   125,    59,    44
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,   -19,   -19,     7,   -40,    14,   -40,   -13,   -40,    -7,
      -7,   -40,     2,   -40,   -40,    12,    21,   -40,   -40,    -4,
      17,    24,    14,   -40,    14,   -40,    92,    27,   138,    33,
     -40,     9,   138,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
      63,     9,    53,    54,     9,   -40,   -40,     9,    44,     9,
     -40,   146,   -40,     3,    -5,   -40,   -40,   -40,   100,   -40,
       9,   109,    90,    51,    52,   111,   -40,   -40,   120,     9,
       9,     9,     9,     9,     9,     9,     9,     9,    44,    44,
     -40,    44,    44,   -40,   -40,    65,   138,     9,     9,   138,
     -40,   -40,    68,    83,    90,    90,    90,    90,    90,    90,
      -5,    -5,   -40,   -40,   -40,   -40,   -40,   129,   131,   -40,
      84,     9,    56,    74,   138,    90,   -40,   -40,   -40,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     2,     4,    10,     0,    15,    13,
      14,     1,     0,    11,    12,     0,     0,     3,    16,     0,
       0,     0,     9,     6,     8,    17,     0,     0,     0,     0,
      57,     0,     0,     7,    18,    22,    21,    29,    25,    27,
       0,     0,     0,     0,     0,    59,    60,     0,     0,     0,
      50,     0,    39,     0,    49,    53,    54,    55,     0,    19,
       0,     0,     0,     0,     0,     0,    38,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,    28,    20,     0,     0,     0,     0,     0,
      40,    36,    37,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    51,    52,    34,    32,    30,     0,     0,    23,
      21,     0,     0,     0,     0,    35,    33,    31,    24,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,   -40,    93,    -1,   -40,
     117,   -40,   -40,   -24,   -25,   -27,   -40,   -40,   -40,   -40,
      -3,   -40,   -21,    -9,   -39,   -26,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    12,     4,    17,    25,    23,     5,     6,     7,
       9,    26,    58,    34,    35,    36,    37,    38,    39,    50,
      51,    52,    62,    54,    55,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    43,    40,    42,    13,     8,    40,    11,    59,    67,
      53,    16,    45,    46,    72,    73,    74,    75,    76,    77,
       1,     2,    14,    13,    81,    82,    47,    20,    53,    15,
      78,    79,    40,    30,    84,    80,    18,    48,    61,    85,
      49,    65,   102,   103,    66,    19,    68,    45,    46,    21,
      93,    94,    95,    96,    97,    98,    99,    22,    41,   106,
      40,   105,   110,    40,    44,   109,    91,    92,    30,   100,
     101,    60,    48,    63,    64,    31,    72,    73,    74,    75,
      76,    77,    87,    88,   107,   108,    69,   119,    40,   118,
     115,   116,    78,    79,    72,    73,    74,    75,    76,    77,
     104,    72,    73,    74,    75,    76,    77,   114,   111,   117,
      78,    79,    27,    28,    29,    24,    30,    78,    79,    10,
      27,    28,    29,    31,    30,    32,    33,    69,    70,    69,
      70,    31,     0,    32,    83,    71,     0,    71,    69,    70,
       0,    86,     0,    89,     0,     0,    71,    69,    70,    69,
      70,     0,    90,     0,     0,    71,     0,    71,    27,    28,
      29,   112,    30,   113,    69,    70,     0,     0,     0,    31,
       0,    32,    71
};

static const yytype_int8 yycheck[] =
{
      26,    28,    28,    28,     5,    24,    32,     0,    32,    48,
      31,     9,     3,     4,    11,    12,    13,    14,    15,    16,
       6,     7,    35,    24,    29,    30,    17,    31,    49,    36,
      27,    28,    58,    24,    58,    32,    24,    28,    41,    60,
      31,    44,    81,    82,    47,    24,    49,     3,     4,    32,
      71,    72,    73,    74,    75,    76,    77,    33,    31,    86,
      86,    86,    89,    89,    31,    89,    69,    70,    24,    78,
      79,     8,    28,    20,    20,    31,    11,    12,    13,    14,
      15,    16,    31,    31,    87,    88,    18,   114,   114,   114,
     111,    35,    27,    28,    11,    12,    13,    14,    15,    16,
      35,    11,    12,    13,    14,    15,    16,    23,    25,    35,
      27,    28,    20,    21,    22,    22,    24,    27,    28,     2,
      20,    21,    22,    31,    24,    33,    34,    18,    19,    18,
      19,    31,    -1,    33,    34,    26,    -1,    26,    18,    19,
      -1,    32,    -1,    32,    -1,    -1,    26,    18,    19,    18,
      19,    -1,    32,    -1,    -1,    26,    -1,    26,    20,    21,
      22,    32,    24,    32,    18,    19,    -1,    -1,    -1,    31,
      -1,    33,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    38,    40,    44,    45,    46,    24,    47,
      47,     0,    39,    45,    35,    36,     9,    41,    24,    24,
      31,    32,    33,    43,    44,    42,    48,    20,    21,    22,
      24,    31,    33,    34,    50,    51,    52,    53,    54,    55,
      62,    31,    51,    52,    31,     3,     4,    17,    28,    31,
      56,    57,    58,    59,    60,    61,    62,    63,    49,    50,
       8,    57,    59,    20,    20,    57,    57,    61,    57,    18,
      19,    26,    11,    12,    13,    14,    15,    16,    27,    28,
      32,    29,    30,    34,    50,    59,    32,    31,    31,    32,
      32,    57,    57,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    35,    51,    52,    57,    57,    50,
      52,    25,    32,    32,    23,    59,    35,    35,    51,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    42,    41,    43,    43,
      44,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    54,    54,    55,    56,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     0,     0,     9,     1,     0,
       1,     2,     2,     2,     2,     1,     3,     0,     2,     1,
       2,     1,     1,     5,     7,     1,     7,     1,     3,     1,
       5,     7,     5,     7,     4,     5,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     3,     1,
       1
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
#line 71 "parser.y" /* yacc.c:1646  */
    {
							if((yyvsp[0].symbol_table) != NULL)
							{
								(yyvsp[0].symbol_table)->set_table_scope(global);
								program_object.set_global_table(*(yyvsp[0].symbol_table));
							}
						}
#line 1348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "parser.y" /* yacc.c:1646  */
    {							
							(yyval.program) = &program_object;
							(yyval.program)->set_procedure((yyvsp[0].procedure),yylineno);
						}
#line 1357 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval.symbol_table) = (yyvsp[0].symbol_table); }
#line 1363 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.symbol_table) = NULL; }
#line 1369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "parser.y" /* yacc.c:1646  */
    {
									main_procedure = new Procedure(void_data_type,*(yyvsp[-4].string_value),yylineno);
	        	           			
	        	           			if((yyvsp[0].symbol_table) != NULL)
	        	           			{
	        	           				(yyvsp[0].symbol_table)->set_table_scope(local);
	        	           				main_procedure->set_local_list(*(yyvsp[0].symbol_table));
	        	           			}
								}
#line 1383 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "parser.y" /* yacc.c:1646  */
    {
        	           				(yyval.procedure) = main_procedure;
	        	           			if((yyvsp[-1].ast_list) != NULL && (yyval.procedure) != NULL)
	        	           			{	        	           				
	        	           				(yyval.procedure)->set_ast_list(*((yyvsp[-1].ast_list)));	        	           				
	        	           			}
        	           			}
#line 1395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.symbol_table) = (yyvsp[0].symbol_table); }
#line 1401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.symbol_table) = NULL; }
#line 1407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_table) = (yyvsp[0].symbol_table);
										}
#line 1415 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_table) = (yyvsp[-1].symbol_table);
											(yyval.symbol_table)->append_list(*(yyvsp[0].symbol_table),yylineno);
										}
#line 1424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.symbol_table) = (yyvsp[-1].symbol_table); }
#line 1430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "parser.y" /* yacc.c:1646  */
    {
										Symbol_Table *st = new Symbol_Table();
										st->set_table_scope(local);
										for (list<Symbol_Table_Entry *>::iterator it = (yyvsp[0].symbol_entry_list)->begin(); it != (yyvsp[0].symbol_entry_list)->end(); it++) {
											(*it)->set_data_type(int_data_type);
											(*it)->set_symbol_scope(local);
											st->push_symbol(*it);
										}
										(yyval.symbol_table) = st;
									}
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "parser.y" /* yacc.c:1646  */
    {
										Symbol_Table *st = new Symbol_Table();
										st->set_table_scope(local);
										for (list<Symbol_Table_Entry *>::iterator it = (yyvsp[0].symbol_entry_list)->begin(); it != (yyvsp[0].symbol_entry_list)->end(); it++) {
											(*it)->set_data_type(double_data_type);
											(*it)->set_symbol_scope(local);
											st->push_symbol(*it);
										}
										(yyval.symbol_table) = st;
									}
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 148 "parser.y" /* yacc.c:1646  */
    {
										(yyval.symbol_entry_list) = new list<Symbol_Table_Entry*>();
										Symbol_Table_Entry *ste = new Symbol_Table_Entry(*(yyvsp[0].string_value),void_data_type,yylineno);  
										(yyval.symbol_entry_list)->push_back(ste);
									}
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "parser.y" /* yacc.c:1646  */
    {
										Symbol_Table_Entry *ste = new Symbol_Table_Entry(*(yyvsp[0].string_value),void_data_type,yylineno);  
										(yyvsp[-2].symbol_entry_list)->push_back(ste);
										(yyval.symbol_entry_list) = (yyvsp[-2].symbol_entry_list);
									}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_list) = new list<Ast *>();}
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 162 "parser.y" /* yacc.c:1646  */
    {
										(yyvsp[-1].ast_list)->push_back((yyvsp[0].ast));
										(yyval.ast_list) = (yyvsp[-1].ast_list);
									}
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "parser.y" /* yacc.c:1646  */
    { 
										(yyval.sequence_ast) = new Sequence_Ast(yylineno);
										(yyval.sequence_ast)->ast_push_back((yyvsp[0].ast));
									}
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 173 "parser.y" /* yacc.c:1646  */
    {
										(yyvsp[-1].sequence_ast)->ast_push_back((yyvsp[0].ast));
										(yyval.sequence_ast) = (yyvsp[-1].sequence_ast);
									}
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast); }
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast); }
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Selection_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast),  NULL, yylineno);
									}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 186 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
									}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
									}
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast); }
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[-1].sequence_ast);
									}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno, false);
									}
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 226 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast), yylineno, true);
									}
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 231 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno, false);
									}
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 234 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast), yylineno, true);
									}
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 239 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Assignment_Ast((yyvsp[-3].ast), (yyvsp[-1].ast), yylineno);
                                        if (!(yyval.ast)->check_ast()) {
											printf("cs316: Error Assignment statement data type not compatible, Line number : %d\n",yylineno);
											exit(0);
										}	
								}
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 249 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Conditional_Expression_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast),yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-4].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}
									}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 262 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_and, (yyvsp[0].ast), yylineno);
										(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										// no need to check LHS and RHS compatibility as they will always be int	
									}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 267 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_or, (yyvsp[0].ast), yylineno);
										(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										// no need to check LHS and RHS compatibility as they will always be int	
 									}
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 272 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Logical_Expr_Ast(NULL, _logical_not, (yyvsp[0].ast), yylineno);
										(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
									}
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 280 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_than, (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}
									}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 290 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_than, (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 300 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), less_equalto, (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 310 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), greater_equalto, (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 320 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), equalto, (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 330 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Relational_Expr_Ast((yyvsp[-2].ast), not_equalto, (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 343 "parser.y" /* yacc.c:1646  */
    {
                                     	(yyval.ast) = new Plus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}
									}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 353 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Minus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 363 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[0].ast);
									}
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 367 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[0].ast);
									}
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 372 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Mult_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 382 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new Divide_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
										if ((yyval.ast)->check_ast()) {
											(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}									
									}
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 392 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[0].ast);
									}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 396 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[0].ast);
									}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 400 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[0].ast);
									}
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 403 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = new UMinus_Ast((yyvsp[0].ast), NULL, yylineno);
										(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
									}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 409 "parser.y" /* yacc.c:1646  */
    {
										assert(main_procedure != NULL);
										if (main_procedure->variable_in_symbol_list_check(*(yyvsp[0].string_value))) {
											Symbol_Table_Entry *ste = &main_procedure->get_symbol_table_entry(*(yyvsp[0].string_value));
											assert(ste != NULL);
											ste->set_symbol_scope(local);
											(yyval.ast) = new Name_Ast(*(yyvsp[0].string_value),*ste,yylineno);
											(yyval.ast)->set_data_type(ste->get_data_type());
										}
										else if (program_object.variable_in_symbol_list_check(*(yyvsp[0].string_value))) {
											Symbol_Table_Entry *ste = &program_object.get_symbol_table_entry(*(yyvsp[0].string_value));
											ste->set_symbol_scope(global);
											(yyval.ast) = new Name_Ast(*(yyvsp[0].string_value),*ste,yylineno);
											(yyval.ast)->set_data_type(ste->get_data_type());
										}
										else {
											printf("cs316: Error Variable undeclared, Line number : %d\n",yylineno);
											exit(0);
										}	
										
									}
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 430 "parser.y" /* yacc.c:1646  */
    {
										(yyval.ast) = (yyvsp[-1].ast);
									}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 435 "parser.y" /* yacc.c:1646  */
    {										
										(yyval.ast) = new Number_Ast<int>((yyvsp[0].integer_value), int_data_type, yylineno);
									}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 438 "parser.y" /* yacc.c:1646  */
    {										
										(yyval.ast) = new Number_Ast<double>((yyvsp[0].double_value), double_data_type, yylineno);
									}
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1928 "parser.tab.c" /* yacc.c:1646  */
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
#line 443 "parser.y" /* yacc.c:1906  */

