/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.yy"

/* $Id: yacc.yy,v 1.18 2011-05-02 10:38:24 matuzaki Exp $
 *
 *    Copyright (c) 1997-1998, Makino Takaki
 *
 *    You may distribute this file under the terms of the Artistic License.
 *
 */

static const char rcsid[] = "$Id: yacc.yy,v 1.18 2011-05-02 10:38:24 matuzaki Exp $";
	
#define IN_BISON_FILE

#include "lconfig.h"
#include "structur.h"
#include "machine.h"
#include "builtin.h"
#include "proc.h"
#include "parse.h"
#include "lilfes.h"

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#else
#include <malloc.h>
#endif
#include <setjmp.h>

namespace lilfes {

using std::strcat;
using std::strcpy;
using std::strlen;
using std::string;

extern int codeoutflag;
static core_p save;

void yyerror(void *parm, const char* s);
//void yyerr(machine *m, const char* s);
//#define YYERROR_VERBOSE
//#define yyerror(X) yyerr(PARM->mach,(X))

#define progalter 0

#define ERRBUF 100
#define YYMAXDEPTH  250000
#define YYINITDEPTH 70000
// Avoid bison bug for C++ output
#define YYSTACK_USE_ALLOCA 0
#define __attribute__(X) 

//#define DEBUG
// #define YYDEBUG 1
//#define YYPARSE_PARAM parm
//#define YYLEX_PARAM parm
#define PARM ((parser_control *)parm)
bool compiled = false;
bool errored = false;

bool warn_old_feature_notation = false;

#if defined(PROFILE)
static prof *profx;
#endif	/* defined(PROFILE) */

FSP prog_types;
FSP prog_list;
FSP prog_list_top;
FSP prog_vars;
FSP prog_vars_top;

static string progalter_fprefix = "__";
static string progalter_tprefix = "__";

void CheckSingleton(machine *m, const string &where);

int yyparse();

//std::istream *input_stream = NULL;
//std::ostream *output_stream = NULL;
//std::ostream *error_stream = NULL;
std::istream *input_stream = &std::cin;
std::ostream *output_stream = &std::cout;
std::ostream *error_stream = &std::cerr;
bool constraint_status = true;

void change_modulename(char *);
char *my_malloc(int);
char *my_strdup(char *);

void hook()
{

}


bool bi_feature(char *s)
{
	if( strcmp(s, "hd") == 0 )	return true;
	if( strcmp(s, "tl") == 0 )	return true;
	if( strcmp(s, "chead") == 0 )	return true;
	if( strcmp(s, "cbody") == 0 )	return true;
	if( strcmp(s, "arg1") == 0 )	return true;
	if( strcmp(s, "arg2") == 0 )	return true;
	if( strcmp(s, "arg3") == 0 )	return true;
	if( strcmp(s, "arg4") == 0 )	return true;
	if( strcmp(s, "arg5") == 0 )	return true;
	if( strcmp(s, "arg6") == 0 )	return true;
	if( strcmp(s, "arg7") == 0 )	return true;
	if( strcmp(s, "arg8") == 0 )	return true;
	if( strcmp(s, "arg9") == 0 )	return true;
	if( strcmp(s, "arg10") == 0 )	return true;
	if( strcmp(s, "arg11") == 0 )	return true;
	if( strcmp(s, "arg12") == 0 )	return true;
	if( strcmp(s, "arg13") == 0 )	return true;
	if( strcmp(s, "arg14") == 0 )	return true;
	if( strcmp(s, "arg15") == 0 )	return true;
	return false;
}

bool bi_type(char *s)
{
	if( strcmp(s, "bot") == 0 )	return true;
	if( strcmp(s, "integer") == 0 )	return true;
	if( strcmp(s, "string") == 0 )	return true;
	if( strcmp(s, "float") == 0 )	return true;
	if( strcmp(s, "feature") == 0 )	return true;
	if( strcmp(s, "list") == 0 )	return true;
	if( strcmp(s, "cons") == 0 )	return true;
	if( strcmp(s, "nil") == 0 )	return true;
	if( strcmp(s, "true") == 0 )	return true;
	if( strcmp(s, "fail") == 0 )	return true;
	if( strcmp(s, "is") == 0 )	return true;
	if( strcmp(s, "type_attr") == 0 )	return true;
	if( strcmp(s, "final") == 0 )	return true;
	if( strcmp(s, "extendable") == 0 )	return true;
	if( strcmp(s, "pred") == 0 )	return true;
	if( strcmp(s, "pred/1") == 0 )	return true;
	if( strcmp(s, "pred/2") == 0 )	return true;
	if( strcmp(s, "pred/3") == 0 )	return true;
	if( strcmp(s, "pred/4") == 0 )	return true;
	if( strcmp(s, "pred/5") == 0 )	return true;
	if( strcmp(s, "pred/6") == 0 )	return true;
	if( strcmp(s, "pred/7") == 0 )	return true;
	if( strcmp(s, "pred/8") == 0 )	return true;
	if( strcmp(s, "pred/9") == 0 )	return true;
	if( strcmp(s, "pred/10") == 0 )	return true;
	if( strcmp(s, "pred/11") == 0 )	return true;
	if( strcmp(s, "pred/12") == 0 )	return true;
	if( strcmp(s, "pred/13") == 0 )	return true;
	if( strcmp(s, "pred/14") == 0 )	return true;
	if( strcmp(s, "pred/15") == 0 )	return true;
	if( strcmp(s, "<") == 0 )	return true;
	if( strcmp(s, "<=") == 0 )	return true;
	if( strcmp(s, ">") == 0 )	return true;
	if( strcmp(s, ">=") == 0 )	return true;
	if( strcmp(s, "=") == 0 )	return true;
	if( strcmp(s, "=\\=") == 0 )	return true;
	if( strcmp(s, "=:=") == 0 )	return true;
	if( strcmp(s, ":-") == 0 )	return true;
	if( strcmp(s, ":-/1") == 0 )	return true;
	if( strcmp(s, ":-/2") == 0 )	return true;
	if( strcmp(s, "?-") == 0 )	return true;
	if( strcmp(s, ",") == 0 )	return true;
	if( strcmp(s, ";") == 0 )	return true;
	if( strcmp(s, "+") == 0 )	return true;
	if( strcmp(s, "-") == 0 )	return true;
	if( strcmp(s, "*") == 0 )	return true;
	if( strcmp(s, "/") == 0 )	return true;
	if( strcmp(s, "//") == 0 )	return true;
	if( strcmp(s, "mod") == 0 )	return true;
	if( strcmp(s, "^") == 0 )	return true;
	if( strcmp(s, "\\/") == 0 )	return true;
	if( strcmp(s, "/\\") == 0 )	return true;
	if( strcmp(s, "#") == 0 )	return true;
	if( strcmp(s, "\\+") == 0 )	return true;
	if( strcmp(s, "\\=") == 0 )	return true;
	return false;
}

} // namespace lilfes


#line 260 "yacc.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_ATOM = 3,                   /* TOK_ATOM  */
  YYSYMBOL_TOK_FEAT = 4,                   /* TOK_FEAT  */
  YYSYMBOL_TOK_VAR = 5,                    /* TOK_VAR  */
  YYSYMBOL_TOK_STARTP = 6,                 /* TOK_STARTP  */
  YYSYMBOL_TOK_MODULENAME = 7,             /* TOK_MODULENAME  */
  YYSYMBOL_TOK_INTEGER = 8,                /* TOK_INTEGER  */
  YYSYMBOL_TOK_STRING = 9,                 /* TOK_STRING  */
  YYSYMBOL_TOK_DOUBLE = 10,                /* TOK_DOUBLE  */
  YYSYMBOL_TOK_INVALID = 11,               /* TOK_INVALID  */
  YYSYMBOL_TOK_IS = 12,                    /* TOK_IS  */
  YYSYMBOL_TOK_MOD = 13,                   /* TOK_MOD  */
  YYSYMBOL_TOK_EOF = 14,                   /* TOK_EOF  */
  YYSYMBOL_SUBSUMED_BY = 15,               /* SUBSUMED_BY  */
  YYSYMBOL_ATTR_DEF = 16,                  /* ATTR_DEF  */
  YYSYMBOL_ATOMP = 17,                     /* ATOMP  */
  YYSYMBOL_LISTEND = 18,                   /* LISTEND  */
  YYSYMBOL_MEANS = 19,                     /* MEANS  */
  YYSYMBOL_MACRO_DEF = 20,                 /* MACRO_DEF  */
  YYSYMBOL_QUERY = 21,                     /* QUERY  */
  YYSYMBOL_UMEANS = 22,                    /* UMEANS  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_IF_THEN = 24,                   /* IF_THEN  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_CMP_L = 27,                     /* CMP_L  */
  YYSYMBOL_CMP_LE = 28,                    /* CMP_LE  */
  YYSYMBOL_CMP_G = 29,                     /* CMP_G  */
  YYSYMBOL_CMP_GE = 30,                    /* CMP_GE  */
  YYSYMBOL_CMP_EQ = 31,                    /* CMP_EQ  */
  YYSYMBOL_CMP_NE = 32,                    /* CMP_NE  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_NOT_UNIFIABLE = 34,             /* NOT_UNIFIABLE  */
  YYSYMBOL_BIT_OR = 35,                    /* BIT_OR  */
  YYSYMBOL_36_ = 36,                       /* '#'  */
  YYSYMBOL_BIT_AND = 37,                   /* BIT_AND  */
  YYSYMBOL_38_ = 38,                       /* '\\'  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_INTDIV = 43,                    /* INTDIV  */
  YYSYMBOL_USIGN = 44,                     /* USIGN  */
  YYSYMBOL_45_ = 45,                       /* '^'  */
  YYSYMBOL_46_ = 46,                       /* '&'  */
  YYSYMBOL_FEATURE = 47,                   /* FEATURE  */
  YYSYMBOL_48_ = 48,                       /* '.'  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_top = 55,                       /* top  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_period = 57,                    /* period  */
  YYSYMBOL_typedef = 58,                   /* typedef  */
  YYSYMBOL_flagsdef = 59,                  /* flagsdef  */
  YYSYMBOL_flagsdefx = 60,                 /* flagsdefx  */
  YYSYMBOL_introdef = 61,                  /* introdef  */
  YYSYMBOL_subsumedef = 62,                /* subsumedef  */
  YYSYMBOL_apptype = 63,                   /* apptype  */
  YYSYMBOL_optional_equal = 64,            /* optional_equal  */
  YYSYMBOL_optional_sharp = 65,            /* optional_sharp  */
  YYSYMBOL_atom_or_atomop = 66,            /* atom_or_atomop  */
  YYSYMBOL_atom_with_module = 67,          /* atom_with_module  */
  YYSYMBOL_feature_with_module = 68,       /* feature_with_module  */
  YYSYMBOL_optional_module_qualifier = 69, /* optional_module_qualifier  */
  YYSYMBOL_newfeat = 70,                   /* newfeat  */
  YYSYMBOL_newtype = 71,                   /* newtype  */
  YYSYMBOL_command = 72,                   /* command  */
  YYSYMBOL_x_desc = 73,                    /* x_desc  */
  YYSYMBOL_desc = 74,                      /* desc  */
  YYSYMBOL_i_desc = 75,                    /* i_desc  */
  YYSYMBOL_ix_desc = 76,                   /* ix_desc  */
  YYSYMBOL_c_desc = 77,                    /* c_desc  */
  YYSYMBOL_cx_desc = 78,                   /* cx_desc  */
  YYSYMBOL_arglist = 79,                   /* arglist  */
  YYSYMBOL_lists = 80,                     /* lists  */
  YYSYMBOL_nelistp = 81,                   /* nelistp  */
  YYSYMBOL_atom = 82,                      /* atom  */
  YYSYMBOL_atomtok = 83,                   /* atomtok  */
  YYSYMBOL_startp = 84,                    /* startp  */
  YYSYMBOL_modulename = 85                 /* modulename  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 287 "yacc.yy"


#include "in.h"

using std::make_pair;
using std::string;

namespace lilfes {

_HASHMAP<string, parsevar *> vars;

void CleanupVars() {
	for( _HASHMAP<string, parsevar *>::const_iterator it = vars.begin();
		 it != vars.end(); ++it ) {
		delete it->second;
	}
	vars.clear();
}

int yylex(YYSTYPE *yylvalp, void *parm);


#line 402 "yacc.cc"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   843

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    36,     2,     2,    46,     2,
      51,    52,    41,    39,    25,    40,    48,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,    38,    49,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    53,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    24,    26,
      27,    28,    29,    30,    31,    32,    34,    35,    37,    43,
      44,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   312,   312,   313,   314,   315,   316,   316,   323,   324,
     327,   328,   329,   330,   331,   335,   338,   339,   340,   341,
     345,   346,   347,   348,   349,   353,   354,   355,   359,   360,
     363,   365,   367,   369,   372,   372,   372,   375,   405,   429,
     442,   467,   468,   472,   485,   498,   511,   553,   573,   887,
     905,   922,   930,  1005,  1009,  1014,  1019,  1026,  1027,  1033,
    1034,  1036,  1043,  1050,  1057,  1064,  1071,  1078,  1085,  1092,
    1098,  1105,  1112,  1118,  1124,  1141,  1148,  1155,  1161,  1168,
    1174,  1181,  1188,  1195,  1202,  1209,  1216,  1223,  1230,  1239,
    1240,  1242,  1249,  1256,  1263,  1270,  1277,  1284,  1291,  1298,
    1304,  1311,  1318,  1324,  1330,  1347,  1354,  1361,  1367,  1373,
    1379,  1389,  1399,  1409,  1416,  1423,  1430,  1437,  1444,  1451,
    1458,  1465,  1475,  1481,  1508,  1509,  1514,  1524,  1541,  1556,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1570,  1574,  1612,  1659,  1660
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_ATOM", "TOK_FEAT",
  "TOK_VAR", "TOK_STARTP", "TOK_MODULENAME", "TOK_INTEGER", "TOK_STRING",
  "TOK_DOUBLE", "TOK_INVALID", "TOK_IS", "TOK_MOD", "TOK_EOF",
  "SUBSUMED_BY", "ATTR_DEF", "ATOMP", "LISTEND", "MEANS", "MACRO_DEF",
  "QUERY", "UMEANS", "';'", "IF_THEN", "','", "NOT", "CMP_L", "CMP_LE",
  "CMP_G", "CMP_GE", "CMP_EQ", "CMP_NE", "'='", "NOT_UNIFIABLE", "BIT_OR",
  "'#'", "BIT_AND", "'\\\\'", "'+'", "'-'", "'*'", "'/'", "INTDIV",
  "USIGN", "'^'", "'&'", "FEATURE", "'.'", "']'", "'['", "'('", "')'",
  "'|'", "$accept", "top", "$@1", "period", "typedef", "flagsdef",
  "flagsdefx", "introdef", "subsumedef", "apptype", "optional_equal",
  "optional_sharp", "atom_or_atomop", "atom_with_module",
  "feature_with_module", "optional_module_qualifier", "newfeat", "newtype",
  "command", "x_desc", "desc", "i_desc", "ix_desc", "c_desc", "cx_desc",
  "arglist", "lists", "nelistp", "atom", "atomtok", "startp", "modulename", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -73,   269,   -73,   -73,    -9,   -73,   -73,   -73,     1,   -73,
     -73,   -73,   -73,   -73,   -73,    39,   -73,    39,   318,   -73,
      39,    39,    39,   -73,   -73,   -73,   318,    39,   -73,    14,
     318,     7,   119,   -73,   -73,   318,     0,   -73,   -73,   -73,
     503,   -73,   -73,   -73,   318,    70,    14,   -73,   -73,   575,
     575,   318,   318,   318,   318,   318,   318,   -73,   715,   -73,
     258,   -23,   -23,   433,   -30,   -73,   468,   -73,   -73,   -73,
     610,     1,    84,   -73,   409,     3,   301,   -73,   -73,   358,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,   -73,   610,   -22,   -73,   -73,
     -73,   -73,   715,   715,   715,   341,    -5,    -5,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   -73,   -73,    20,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   126,     1,   -73,   -73,
       4,   -73,   -73,   409,   -73,   762,   -23,   540,   540,   575,
     645,   680,   159,   159,   159,   159,   159,   159,   762,   762,
     622,   622,   258,   548,   548,    82,    82,   -23,   -20,   -73,
     318,   -73,   797,    -5,   610,   610,   750,   750,   750,   750,
     750,   750,   797,   797,   658,   658,   341,   689,   689,   132,
     132,    -5,   -13,   -73,   -73,   610,    -4,   -73,     1,   -73,
     -73,   610,   -73,   398,   -73,    42,   -31,   -73,    12,    60,
      18,   -73,   -73,    62,    23,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     6,    34,    39,    50,   141,   143,    54,
      56,    55,    35,    36,     3,   136,   135,   137,     0,   133,
       0,   129,   130,   131,   132,   134,   124,     0,     4,     0,
       0,     0,     0,    37,   140,   139,     0,     5,    57,    89,
       0,    90,    51,   138,     0,     0,     0,   144,    34,   107,
     108,   136,   137,     0,     0,   129,   130,    59,   109,    60,
      99,   102,   103,   126,     0,   125,     0,     9,     8,    14,
      15,    41,     0,    12,     0,    41,     0,    10,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,   122,     0,    40,   142,
      38,     7,    77,    78,    79,    69,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    58,     0,    24,    42,    17,    19,    13,
     136,   137,   129,   130,   139,    27,     0,    41,    20,    16,
      41,    18,    11,     0,    25,   113,   114,   105,   106,   111,
     112,   110,   116,   117,   118,   119,   120,   121,   100,   101,
      97,    98,    96,    91,    92,    94,    95,   115,    93,   104,
       0,    52,    80,    81,    75,    76,    83,    84,    85,    86,
      87,    88,    70,    71,    67,    68,    66,    61,    62,    64,
      65,    82,    63,    74,   128,   127,    30,    22,    41,    21,
      26,   123,    31,    28,    23,     0,    43,    29,     0,    33,
       0,    46,    44,     0,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -15,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -33,   -73,   -72,   -73,   -61,   -73,   -73,   -73,
     139,   -17,   -73,   164,   -73,   -73,   -73,   -55,   -70,   -73,
     -73,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    46,    69,    28,    29,    30,    31,    32,   226,
     223,   230,    33,    34,    35,   144,   145,    36,    37,    38,
      57,    63,    59,    40,    41,   107,    64,    65,    42,    43,
      44,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    58,   154,   190,   155,   229,   -47,   154,     8,   164,
       8,     8,   110,    70,   158,    79,    73,    77,    78,   142,
     -32,    67,   103,   104,   216,   105,   104,   106,    67,   222,
     191,   111,    71,   139,   112,   113,   114,   115,   116,   117,
     138,   139,    48,     5,     6,     7,     8,     9,    10,    11,
     228,    12,    13,   157,   218,    68,    72,   149,    15,    16,
      17,   162,    68,   146,   231,    18,   156,   146,   232,   233,
     234,   156,    19,    48,   108,   235,   109,    20,    21,    22,
      23,    24,    12,    13,    25,   214,     0,     0,     0,    26,
      27,   154,     0,   220,     0,    81,   217,     0,    67,   219,
     147,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   110,   215,   102,   148,   103,   104,    48,
     108,     0,    68,    67,     0,     0,     0,     0,    12,    13,
      39,     0,     0,     0,    74,   119,     0,     0,     0,   146,
       0,   154,   146,   227,    39,   156,    39,   224,    75,    39,
      39,    39,     0,     0,     0,     0,    39,    68,    76,     0,
       0,    80,    81,   221,     0,   137,     0,   138,   139,    49,
       0,    50,     0,     0,    60,    61,    62,     0,     0,     0,
       0,    66,    93,    94,    95,    96,    97,     0,    98,    99,
     100,   101,   102,     0,   103,   104,     0,     0,     0,     0,
     146,     0,     0,     0,     0,   156,     0,     0,     0,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     2,
       3,    81,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,    13,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,    18,     0,    98,    99,   100,
     101,   102,    19,   103,   104,     0,     0,    20,    21,    22,
      23,    24,     0,     0,    25,    67,     0,   159,     0,    26,
      27,    48,     5,     6,     7,     8,     9,    10,    11,     0,
      12,    13,     0,     0,     0,     0,     0,    51,    16,    52,
     160,     0,     0,   161,    53,     0,     0,     0,     0,    68,
       0,    19,     0,     0,   119,     0,    54,    55,    56,    23,
      24,    48,     5,    25,     0,     8,     0,     0,    26,    27,
      12,    13,     0,     0,     0,     0,     0,   150,    16,   151,
     133,   134,   135,   136,   137,     0,   138,   139,     0,     0,
       0,    19,     0,     0,     0,     0,     0,   152,   153,    23,
      24,    48,     5,    25,   225,     8,     0,     0,   163,     0,
      12,    13,    48,     5,     0,     0,     8,   150,    16,   151,
       0,    12,    13,     0,     0,     0,     0,     0,   150,    16,
     151,    19,     0,     0,     0,     0,     0,   152,   153,    23,
      24,     0,    19,    25,     0,   118,   119,     0,   152,   153,
      23,    24,   120,   121,    25,     0,     0,     0,   140,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,   133,   134,   135,   136,   137,     0,   138,   139,
      80,    81,     0,     0,     0,     0,   141,    82,    83,     0,
       0,    84,    85,    86,     0,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    98,    99,   100,
     101,   102,     0,   103,   104,    80,    81,    67,     0,     0,
     143,     0,    82,    83,     0,     0,    84,    85,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,    98,    99,   100,   101,   102,     0,   103,   104,
       0,    68,    80,    81,     0,     0,     0,     0,     0,    82,
      83,    81,     0,    84,    85,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,    98,
      99,   100,   101,   102,     0,   103,   104,    80,    81,   100,
     101,   102,     0,   103,   104,     0,     0,     0,    84,    85,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,    98,    99,   100,   101,   102,     0,
     103,   104,   118,   119,     0,     0,     0,     0,     0,   120,
     121,     0,     0,     0,     0,    81,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   133,
     134,   135,   136,   137,     0,   138,   139,    80,    81,    97,
       0,    98,    99,   100,   101,   102,     0,   103,   104,    85,
      86,   119,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,    98,    99,   100,   101,   102,     0,
     103,   104,    80,    81,     0,   132,     0,   133,   134,   135,
     136,   137,   119,   138,   139,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,    98,
      99,   100,   101,   102,     0,   103,   104,   118,   119,     0,
     135,   136,   137,     0,   138,   139,     0,     0,     0,     0,
       0,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,   133,   134,   135,   136,   137,     0,
     138,   139,   118,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   130,   131,   132,     0,   133,
     134,   135,   136,   137,     0,   138,   139,    95,    96,    97,
       0,    98,    99,   100,   101,   102,     0,   103,   104,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   132,     0,   133,   134,   135,   136,
     137,     0,   138,   139
};

static const yytype_int16 yycheck[] =
{
       8,    18,    74,    25,    74,    36,    15,    79,     7,    79,
       7,     7,    45,    30,    75,    15,    31,    32,    35,    49,
      51,    14,    45,    46,     4,    40,    46,    44,    14,    33,
      52,    46,    25,    46,    51,    52,    53,    54,    55,    56,
      45,    46,     3,     4,     5,     6,     7,     8,     9,    10,
       8,    12,    13,    50,    50,    48,    49,    72,    19,    20,
      21,    76,    48,    71,    52,    26,    74,    75,     8,    51,
       8,    79,    33,     3,     4,    52,     6,    38,    39,    40,
      41,    42,    12,    13,    45,   140,    -1,    -1,    -1,    50,
      51,   163,    -1,   163,    -1,    13,   157,    -1,    14,   160,
      16,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   156,   141,    43,    42,    45,    46,     3,
       4,    -1,    48,    14,    -1,    -1,    -1,    -1,    12,    13,
       1,    -1,    -1,    -1,    25,    13,    -1,    -1,    -1,   157,
      -1,   223,   160,   223,    15,   163,    17,   218,    39,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    48,    49,    -1,
      -1,    12,    13,   190,    -1,    43,    -1,    45,    46,    15,
      -1,    17,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       1,    13,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    -1,    39,    40,    41,
      42,    43,    33,    45,    46,    -1,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    45,    14,    -1,    16,    -1,    50,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      39,    -1,    -1,    42,    26,    -1,    -1,    -1,    -1,    48,
      -1,    33,    -1,    -1,    13,    -1,    38,    39,    40,    41,
      42,     3,     4,    45,    -1,     7,    -1,    -1,    50,    51,
      12,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      39,    40,    41,    42,    43,    -1,    45,    46,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,     3,     4,    45,     6,     7,    -1,    -1,    50,    -1,
      12,    13,     3,     4,    -1,    -1,     7,    19,    20,    21,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    33,    45,    -1,    12,    13,    -1,    39,    40,
      41,    42,    19,    20,    45,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    -1,    45,    46,
      12,    13,    -1,    -1,    -1,    -1,    53,    19,    20,    -1,
      -1,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    45,    46,    12,    13,    14,    -1,    -1,
      52,    -1,    19,    20,    -1,    -1,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    -1,    45,    46,
      -1,    48,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,
      20,    13,    -1,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    46,    12,    13,    41,
      42,    43,    -1,    45,    46,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    13,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    46,    12,    13,    37,
      -1,    39,    40,    41,    42,    43,    -1,    45,    46,    24,
      25,    13,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    12,    13,    -1,    37,    -1,    39,    40,    41,
      42,    43,    13,    45,    46,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    46,    12,    13,    -1,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    46,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    -1,    45,    46,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    12,    13,    14,    19,    20,    21,    26,    33,
      38,    39,    40,    41,    42,    45,    50,    51,    58,    59,
      60,    61,    62,    66,    67,    68,    71,    72,    73,    74,
      77,    78,    82,    83,    84,    85,    56,    85,     3,    77,
      77,    19,    21,    26,    38,    39,    40,    74,    75,    76,
      77,    77,    77,    75,    80,    81,    77,    14,    48,    57,
      75,    25,    49,    57,    25,    39,    49,    57,    75,    15,
      12,    13,    19,    20,    23,    24,    25,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    39,    40,
      41,    42,    43,    45,    46,    57,    75,    79,     4,     6,
      66,    57,    75,    75,    75,    75,    75,    75,    12,    13,
      19,    20,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    39,    40,    41,    42,    43,    45,    46,
      25,    53,    49,    52,    69,    70,    85,    16,    42,    57,
      19,    21,    39,    40,    68,    82,    85,    50,    70,    16,
      39,    42,    57,    50,    82,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      25,    52,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    81,    75,     4,    70,    50,    70,
      82,    75,    33,    64,    70,     6,    63,    82,     8,    36,
      65,    52,     8,    51,     8,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    55,    57,    57,
      58,    58,    58,    58,    58,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    71,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    84,    84,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     0,     4,     1,     1,
       2,     3,     2,     3,     2,     2,     3,     3,     3,     3,
       3,     4,     4,     5,     3,     3,     4,     3,     0,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     2,     1,
       2,     0,     1,     4,     6,     8,     6,     1,     2,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     2,     3,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     2,     3,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     0,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (parm, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parm); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *parm)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parm);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *parm)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parm);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *parm)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parm);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parm); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *parm)
{
  YY_USE (yyvaluep);
  YY_USE (parm);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *parm)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, parm);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* top: %empty  */
#line 312 "yacc.yy"
                        { }
#line 1922 "yacc.cc"
    break;

  case 3: /* top: top TOK_EOF  */
#line 313 "yacc.yy"
                        { }
#line 1928 "yacc.cc"
    break;

  case 4: /* top: top typedef  */
#line 314 "yacc.yy"
                        { errored = false; free_dups(); CleanupVars();  }
#line 1934 "yacc.cc"
    break;

  case 5: /* top: top command  */
#line 315 "yacc.yy"
                        { errored = false; free_dups(); CleanupVars();  }
#line 1940 "yacc.cc"
    break;

  case 6: /* $@1: %empty  */
#line 316 "yacc.yy"
                    { if( PARM->mach->getLexer()->Isatty() ) { PARM->mach->getLexer()->Flush(); YYABORT; } }
#line 1946 "yacc.cc"
    break;

  case 7: /* top: top error $@1 period  */
#line 317 "yacc.yy"
                  { yyerrok; PARM->mach->getLexer()->SetParsing(false); errored = false; }
#line 1952 "yacc.cc"
    break;

  case 8: /* period: '.'  */
#line 323 "yacc.yy"
                        { }
#line 1958 "yacc.cc"
    break;

  case 9: /* period: TOK_EOF  */
#line 324 "yacc.yy"
                    { INERR(PARM->mach,"Incomplete statement (No period at EOF)");  }
#line 1964 "yacc.cc"
    break;

  case 10: /* typedef: subsumedef period  */
#line 327 "yacc.yy"
                                 { if( (yyvsp[-1].typeval) != NULL ) {  (yyvsp[-1].typeval)->Fix(); procedure::NewTypeNotify(); if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) { prog_types.Follow(hd).Coerce((yyvsp[-1].typeval)); prog_types = prog_types.Follow(tl); } } }
#line 1970 "yacc.cc"
    break;

  case 11: /* typedef: subsumedef ']' period  */
#line 328 "yacc.yy"
                                 { if( (yyvsp[-2].typeval) != NULL ) {  (yyvsp[-2].typeval)->Fix(); procedure::NewTypeNotify(); if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) { prog_types.Follow(hd).Coerce((yyvsp[-2].typeval)); prog_types = prog_types.Follow(tl); } } }
#line 1976 "yacc.cc"
    break;

  case 12: /* typedef: introdef period  */
#line 329 "yacc.yy"
                                 { if( (yyvsp[-1].typeval) != NULL ) {  (yyvsp[-1].typeval)->Fix(); procedure::NewTypeNotify(); if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) { prog_types.Follow(hd).Coerce((yyvsp[-1].typeval)); prog_types = prog_types.Follow(tl); } } }
#line 1982 "yacc.cc"
    break;

  case 13: /* typedef: introdef ']' period  */
#line 330 "yacc.yy"
                                 { if( (yyvsp[-2].typeval) != NULL ) {  (yyvsp[-2].typeval)->Fix(); procedure::NewTypeNotify(); if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) { prog_types.Follow(hd).Coerce((yyvsp[-2].typeval)); prog_types = prog_types.Follow(tl); } } }
#line 1988 "yacc.cc"
    break;

  case 14: /* typedef: flagsdef period  */
#line 331 "yacc.yy"
                                 { if( (yyvsp[-1].typeval) != NULL ) {          vars.clear(); procedure::NewTypeNotify(); if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) { prog_types.Follow(hd).Coerce((yyvsp[-1].typeval)); prog_types = prog_types.Follow(tl); } } }
#line 1994 "yacc.cc"
    break;

  case 15: /* flagsdef: flagsdefx i_desc  */
#line 335 "yacc.yy"
                         { if( (yyvsp[-1].typeval) != NULL && (yyvsp[0].pval) != CORE_P_INVALID ) { (yyvsp[-1].typeval)->SetAttribute(FSP(PARM->mach, (yyvsp[0].pval))); (yyval.typeval) = (yyvsp[-1].typeval); } else (yyval.typeval) = NULL; }
#line 2000 "yacc.cc"
    break;

  case 16: /* flagsdefx: subsumedef ']' ATTR_DEF  */
#line 338 "yacc.yy"
                                  { if( (yyvsp[-2].typeval) != NULL ) (yyvsp[-2].typeval)->Fix(); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2006 "yacc.cc"
    break;

  case 17: /* flagsdefx: introdef ']' ATTR_DEF  */
#line 339 "yacc.yy"
                                  { if( (yyvsp[-2].typeval) != NULL ) (yyvsp[-2].typeval)->Fix(); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2012 "yacc.cc"
    break;

  case 18: /* flagsdefx: subsumedef ']' '/'  */
#line 340 "yacc.yy"
                                  { INWARN(PARM->mach, "Attribute definition '/' is obsolete; use './' instead"); if( (yyvsp[-2].typeval) != NULL ) (yyvsp[-2].typeval)->Fix(); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2018 "yacc.cc"
    break;

  case 19: /* flagsdefx: introdef ']' '/'  */
#line 341 "yacc.yy"
                                  { INWARN(PARM->mach, "Attribute definition '/' is obsolete; use './' instead"); if( (yyvsp[-2].typeval) != NULL ) (yyvsp[-2].typeval)->Fix(); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2024 "yacc.cc"
    break;

  case 20: /* introdef: subsumedef '+' newfeat  */
#line 345 "yacc.yy"
                                   { if( (yyvsp[-2].typeval) != NULL ) (yyvsp[-2].typeval)->AddFeature((yyvsp[0].appfeatval).feat, (yyvsp[0].appfeatval).app); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2030 "yacc.cc"
    break;

  case 21: /* introdef: subsumedef ']' '+' newfeat  */
#line 346 "yacc.yy"
                                       { if( (yyvsp[-3].typeval) != NULL ) (yyvsp[-3].typeval)->AddFeature((yyvsp[0].appfeatval).feat, (yyvsp[0].appfeatval).app); (yyval.typeval) = (yyvsp[-3].typeval); }
#line 2036 "yacc.cc"
    break;

  case 22: /* introdef: subsumedef '+' '[' newfeat  */
#line 347 "yacc.yy"
                                       { if( (yyvsp[-3].typeval) != NULL ) (yyvsp[-3].typeval)->AddFeature((yyvsp[0].appfeatval).feat, (yyvsp[0].appfeatval).app); (yyval.typeval) = (yyvsp[-3].typeval); }
#line 2042 "yacc.cc"
    break;

  case 23: /* introdef: subsumedef ']' '+' '[' newfeat  */
#line 348 "yacc.yy"
                                           { if( (yyvsp[-4].typeval) != NULL ) (yyvsp[-4].typeval)->AddFeature((yyvsp[0].appfeatval).feat, (yyvsp[0].appfeatval).app); (yyval.typeval) = (yyvsp[-4].typeval); }
#line 2048 "yacc.cc"
    break;

  case 24: /* introdef: introdef ',' newfeat  */
#line 349 "yacc.yy"
                                   { if( (yyvsp[-2].typeval) != NULL ) (yyvsp[-2].typeval)->AddFeature((yyvsp[0].appfeatval).feat, (yyvsp[0].appfeatval).app); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2054 "yacc.cc"
    break;

  case 25: /* subsumedef: newtype SUBSUMED_BY atom  */
#line 353 "yacc.yy"
                                   { if( (yyvsp[-2].typeval) != NULL && (yyvsp[0].typeval) != NULL ) (yyvsp[-2].typeval)->SetAsChildOf((yyvsp[0].typeval)); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2060 "yacc.cc"
    break;

  case 26: /* subsumedef: newtype SUBSUMED_BY '[' atom  */
#line 354 "yacc.yy"
                                       { if( (yyvsp[-3].typeval) != NULL && (yyvsp[0].typeval) != NULL ) (yyvsp[-3].typeval)->SetAsChildOf((yyvsp[0].typeval)); (yyval.typeval) = (yyvsp[-3].typeval); }
#line 2066 "yacc.cc"
    break;

  case 27: /* subsumedef: subsumedef ',' atom  */
#line 355 "yacc.yy"
                                   { if( (yyvsp[-2].typeval) != NULL && (yyvsp[0].typeval) != NULL ) (yyvsp[-2].typeval)->SetAsChildOf((yyvsp[0].typeval)); (yyval.typeval) = (yyvsp[-2].typeval); }
#line 2072 "yacc.cc"
    break;

  case 28: /* apptype: %empty  */
#line 359 "yacc.yy"
                                        { (yyval.typeval) = bot; }
#line 2078 "yacc.cc"
    break;

  case 29: /* apptype: atom  */
#line 360 "yacc.yy"
                                                { (yyval.typeval) = (yyvsp[0].typeval); }
#line 2084 "yacc.cc"
    break;

  case 37: /* atom_with_module: atom_or_atomop  */
#line 376 "yacc.yy"
{
	if( progalter && !bi_type((yyvsp[0].str)))
	{
		(yyval.typeval) = (type *)module::CurrentModule()->Search(progalter_tprefix + (yyvsp[0].str));
		if( (yyval.typeval) == NULL )
		{
			(yyval.typeval) = (type *)module::CurrentModule()->Search((yyvsp[0].str));
			if( (yyval.typeval) != NULL && ! (yyval.typeval)->IsBuiltIn() )
				(yyval.typeval) = NULL;
		}
	      }
	else 
	  {
	    (yyval.typeval) = (type *)module::CurrentModule()->Search(((yyvsp[0].str)));
	  }
	if( (yyval.typeval) == NULL ) 
	{
//		INWARN(PARM->mach, "Type '" << $1 << "' is undefined; treated as a subtype of 'bot'");
		(yyval.typeval) = new type(progalter && !bi_type((yyvsp[0].str)) ? (progalter_tprefix + (yyvsp[0].str)) : (yyvsp[0].str), module::CurrentModule());
		(yyval.typeval)->SetAsChildOf(bot);
		(yyval.typeval)->Fix();
		INWARN(PARM->mach, (yyval.typeval)->GetProperName() << " <- [bot]. is assumed implicitly");
		procedure::NewTypeNotify();
		if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
			prog_types.Follow(hd).Coerce((yyval.typeval));
			prog_types = prog_types.Follow(tl);
		}
	}
}
#line 2118 "yacc.cc"
    break;

  case 38: /* atom_with_module: modulename atom_or_atomop  */
#line 406 "yacc.yy"
{
          module *m = module::SearchModule((yyvsp[-1].str));
	  if(m == NULL)
	    {
	      INERR(PARM->mach,"Could not find module " << (yyvsp[-1].str) << ".");
	      errored = true;
	      (yyval.typeval) = NULL;
	    }
	  else 
	    {
	      type * m_type = m->Search((yyvsp[0].str));
	      if(m_type == NULL)
		{
		  INERR(PARM->mach,"Could not find atom " << (yyvsp[-1].str) << ":" << (yyvsp[0].str) <<".");
		  errored = true;
		  (yyval.typeval) = NULL;
		}
	      else (yyval.typeval) = m_type;
	    }
	}
#line 2143 "yacc.cc"
    break;

  case 39: /* feature_with_module: TOK_FEAT  */
#line 430 "yacc.yy"
                        {
				type *f =  module::CurrentModule()->Search((yyvsp[0].str));

				if (f == NULL)
				{
					INERR(PARM->mach,"Unknown feature name '" << (yyvsp[0].str) << "'.");
					errored = true;
					(yyval.typeval) = NULL;
				}
				else 
					(yyval.typeval) = (type *)f;
			}
#line 2160 "yacc.cc"
    break;

  case 40: /* feature_with_module: modulename TOK_FEAT  */
#line 443 "yacc.yy"
                        {
				module * m = module::SearchModule((yyvsp[-1].str));
				if(m ==NULL)
				{
					INERR(PARM->mach,"Unknown module name '"<< (yyvsp[-1].str) << "'.");
					errored = true;
					(yyval.typeval) = NULL;
				}
				else 
				{
				type *f = m->Search((yyvsp[0].str));
					if(f == NULL)
					{
						INERR(PARM->mach,"Unknown feature name '"<< (yyvsp[-1].str) << ":"<< (yyvsp[0].str) <<"'.");
						errored = true;
						(yyval.typeval) = NULL;
					}
					else
						(yyval.typeval) = f;
				}
			}
#line 2186 "yacc.cc"
    break;

  case 41: /* optional_module_qualifier: %empty  */
#line 467 "yacc.yy"
                             { (yyval.modval) = module::CurrentModule(); }
#line 2192 "yacc.cc"
    break;

  case 42: /* optional_module_qualifier: modulename  */
#line 468 "yacc.yy"
                     { (yyval.modval) = module::SearchModule((yyvsp[0].str)); }
#line 2198 "yacc.cc"
    break;

  case 43: /* newfeat: optional_module_qualifier TOK_FEAT optional_equal apptype  */
#line 473 "yacc.yy"
                { 
			string fname = (!bi_type((yyvsp[-2].str))) ? (yyvsp[-2].str) : (progalter_fprefix + (yyvsp[-2].str));
			if( ((yyval.appfeatval).feat = (feature *)feature::Search(module::CurrentModule()->Search(fname))) == NULL )
			{
				(yyval.appfeatval).feat = new feature(fname, (yyvsp[-3].modval), 0/*$4*/,module::CurrentModule()->GetInterfaceMode()); 
				if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
					prog_types.Follow(hd).Coerce((yyval.appfeatval).feat->GetRepType());
					prog_types = prog_types.Follow(tl);
				}
			}
			(yyval.appfeatval).app = (yyvsp[0].typeval);
		}
#line 2215 "yacc.cc"
    break;

  case 44: /* newfeat: optional_module_qualifier TOK_FEAT optional_equal apptype '#' TOK_INTEGER  */
#line 486 "yacc.yy"
                { 
			string fname = (!progalter || bi_feature((yyvsp[-4].str))) ? (yyvsp[-4].str) : (progalter_fprefix + (yyvsp[-4].str));
			if( ((yyval.appfeatval).feat = (feature *)feature::Search((module::CurrentModule()->Search(fname)))) == NULL )
			{
				(yyval.appfeatval).feat = new feature(fname, (yyvsp[-5].modval), (yyvsp[0].ival),module::CurrentModule()->GetInterfaceMode()); 
				if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
					prog_types.Follow(hd).Coerce((yyval.appfeatval).feat->GetRepType());
					prog_types = prog_types.Follow(tl);
				}
			}
			(yyval.appfeatval).app = (yyvsp[-2].typeval);
		}
#line 2232 "yacc.cc"
    break;

  case 45: /* newfeat: optional_module_qualifier TOK_FEAT optional_equal apptype optional_sharp '(' TOK_INTEGER ')'  */
#line 499 "yacc.yy"
                { 
			string fname = (!progalter || bi_feature((yyvsp[-6].str))) ? (yyvsp[-6].str) : (progalter_fprefix + (yyvsp[-6].str));
			if( ((yyval.appfeatval).feat = (feature *)feature::Search((module::CurrentModule()->Search(fname)))) == NULL )
			{
				(yyval.appfeatval).feat = new feature(fname, (yyvsp[-7].modval), (yyvsp[-1].ival),module::CurrentModule()->GetInterfaceMode()); 
				if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
					prog_types.Follow(hd).Coerce((yyval.appfeatval).feat->GetRepType());
					prog_types = prog_types.Follow(tl);
				}
			}
			(yyval.appfeatval).app = (yyvsp[-4].typeval);
		}
#line 2249 "yacc.cc"
    break;

  case 46: /* newfeat: optional_module_qualifier TOK_FEAT optional_equal TOK_STARTP TOK_INTEGER ')'  */
#line 512 "yacc.yy"
                { 
			string fname = (!progalter || bi_feature((yyvsp[-4].str))) ? (yyvsp[-4].str) : (progalter_fprefix + (yyvsp[-4].str));
			if( ((yyval.appfeatval).feat = (feature *)feature::Search((module::CurrentModule()->Search(fname)))) == NULL )
				(yyval.appfeatval).feat = new feature(fname, (yyvsp[-5].modval), (yyvsp[-1].ival),module::CurrentModule()->GetInterfaceMode()); 
			type *tt;
			if( progalter && !bi_type((yyvsp[-2].str)) )
			{
				tt = (type *)((yyvsp[-5].modval)->Search(progalter_tprefix + (yyvsp[-2].str)));
				if( tt == NULL )
				{
					tt = (type *)((yyvsp[-5].modval)->Search((yyvsp[-2].str)));
					if( tt != NULL && ! tt->IsBuiltIn() )
						tt = NULL;
				}
			}
			else
				tt = (type *)(yyvsp[-5].modval)->Search((yyvsp[-2].str));

			if( tt == NULL ) 
			{
//				INWARN(PARM->mach, "Type '" << $4 << "' is undefined; treated as a subtype of 'bot'");
				tt = new type((yyvsp[-2].str), (yyvsp[-5].modval));
				tt->SetAsChildOf(bot);
				tt->Fix();
				INWARN(PARM->mach, tt->GetProperName() << " <- [bot]. is assumed implicitly");
				procedure::NewTypeNotify();
				if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
					prog_types.Follow(hd).Coerce(tt);
					prog_types = prog_types.Follow(tl);
				}
			}
			if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
				prog_types.Follow(hd).Coerce((yyval.appfeatval).feat->GetRepType());
				prog_types = prog_types.Follow(tl);
			}
			(yyval.appfeatval).app = tt;
		}
#line 2291 "yacc.cc"
    break;

  case 47: /* newtype: TOK_ATOM  */
#line 554 "yacc.yy"
                { 
			module::UseCurrentModule();
			string tname = !progalter ? (yyvsp[0].str) : (progalter_tprefix + (yyvsp[0].str));
			const type *t = module::CurrentModule()->Search(tname);
			if( t != NULL && t->GetModule() == module::CurrentModule() )
			{
				INERR(PARM->mach,"Type '" << (yyvsp[0].str) << "' is defined twice");
				errored = true;
				(yyval.typeval) = NULL;
			}
			else
			{
				(yyval.typeval) = new type(tname,module::CurrentModule(),module::CurrentModule()->GetInterfaceMode()); 
			}
		}
#line 2311 "yacc.cc"
    break;

  case 48: /* command: c_desc period  */
#line 574 "yacc.yy"
        {
//		hook();
//		int slot = PARM->mach->GetCurrentSlot();
		bool say_no = false;
		lilfesFlexLexer *prevlexer = PARM->mach->getLexer();
		
		if( (yyvsp[-1].pval) == CORE_P_INVALID )
		{
			if( ! errored )
				INERR(PARM->mach,"Cannot generate a feature structure");
			errored = true;
		}
		else 
		{
			FSP rfs(PARM->mach, (yyvsp[-1].pval));	// root feature structure
			const type *t = rfs.GetType();

			if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() )
			{
//				std::cout << "---" << std::endl;
//				std::cout << rfs.DisplayAVM();
//				std::cout << (ptr_int)rfs.GetType() << std::endl;
//				std::cout << (ptr_int)type::Search(":-/1") << std::endl;

                          // include/1 is no more implemented
// 				if( rfs.GetType() == module::CoreModule()->Search(":-/1") &&
// 					( rfs.Follow(f_cbody).GetType()->IsSubType(module::BuiltinModule()->Search("include")) ) )
// 				{
// 					// Pasted from include/1
// 					FSP arg1 = rfs.Follow(f_cbody).Follow(f_arg[1]);
// 					if( ! arg1.IsString() )
// 					{
// 						INERR(PARM->mach,"include/1 requires a file name");
// 					}
// 					else
// 					{
// 						char *buf = new char[strlen(arg1.ReadString()) + strlen(PARM->mach->getLexer()->InFile())];
// 						char *p;
						
// 						strcpy(buf, PARM->mach->getLexer()->InFile());
// 					#ifdef WIN32
// 						p = strrchr(buf, '\\');
// 					#else
// 						p = strrchr(buf, '/');
// 					#endif
// 						if( p == NULL )
// 							strcpy(buf, arg1.ReadString());
// 						else
// 							strcpy(p+1, arg1.ReadString());
						
// 					//	std::cout << buf << std::endl;
// 						if( (! pushfile( PARM->mach, buf, PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) ) )
// 							if( (! pushfile( PARM->mach, arg1.ReadString(), PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() )) )
// 							{
// 								INERR(PARM->mach,"Cannot open include file: '" << arg1.ReadString() << "'");
// 							}
// 						delete buf;
// 					}
// 				}
//                              else
                          if( rfs.GetType() == module::CoreModule()->Search(":-/1") &&
					(rfs.Follow(f_cbody).GetType()->GetModule() == module::DirectiveModule()) )
				{
					FSP arg1 = rfs.Follow(f_cbody);
					const type *t = arg1.GetType();

					procedure *pc = procedure::Search(t);
					procthunk *pt = pc->GetThunk();
					ASSERT( pt != NULL );

					int nf = t->GetNFeatures();
					PARM->mach->SetRP(nf);
					if( arg1.IsLeaf() )
					{
						for( int i=0; i<nf; i++ )
							PARM->mach->WriteLocal(i, PTR2c(FSP(PARM->mach).GetAddress()));
					}
					else
					{
						for( int i=0; i<nf; i++ )
							PARM->mach->WriteLocal(i, PTR2c(arg1.FollowNth(i).GetAddress()));
					}

					pt->exec(*PARM->mach);
				}
				else {
//				std::cout << "---" << std::endl;
					if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() != 2 )	// 2 means ensure_in_prog...
					{
						prog_list.Follow(hd).Unify(rfs);
						prog_list.Follow(f_lilfesfileinfo)
								 .Follow(f_lilfesfilename)
								 .Unify(FSP(PARM->mach,(PARM->mach->getLexer()->InFile())));
						prog_list.Follow(f_lilfesfileinfo)
								 .Follow(f_lilfesfileline)
								 .Unify(FSP(PARM->mach,(mint)(PARM->mach->getLexer()->Lineno())));
						prog_list = prog_list.Follow(tl);
					}
					if( PARM->mach->getLexer()->ProgVars() )
					{
						FSP varlist = prog_vars.Follow(hd);
						for( _HASHMAP<string, parsevar *>::const_iterator it = vars.begin();
						it != vars.end(); ++it )
						{
							parsevar *pv = it->second;
							if( it->second->GetName()[0] != '_')
							{
								FSP v = varlist.Follow(hd);
								v.Follow(hd).Unify(FSP(PARM->mach, pv->GetName())); 
								v.Follow(tl).Follow(hd).Unify(FSP(PARM->mach, pv->addr())); 
								v.Follow(tl).Follow(tl).Coerce(nil);
								varlist = varlist.Follow(tl);
							}
						}
						varlist.Coerce(nil);
						prog_vars = prog_vars.Follow(tl);
					}
				}
			}
			else if( rfs.IsLeaf() && t->GetIndex(f_cbody) != -1 )
			{
				INERR(PARM->mach,"Missing clause body");
				errored = true;
			}
			else
			{
				if( rfs.GetType()->IsSubType(t_query) )	// Add DispResult
				{
					FSP varlist(PARM->mach), varlisttop = varlist;
					for( _HASHMAP<string, parsevar *>::const_iterator it = vars.begin();
						 it != vars.end(); ++it )
					{
						parsevar *pv = it->second;
						if( pv->GetName()[0] != '_')
						{
							FSP v = varlist.Follow(hd);
							v.Follow(hd).Unify(FSP(PARM->mach, pv->GetName())); 
							v.Follow(tl).Follow(hd).Unify(FSP(PARM->mach, pv->addr())); 
							v.Follow(tl).Follow(tl).Coerce(nil);
							varlist = varlist.Follow(tl);
						}
					}
					varlist.Coerce(nil);

					FSP newrfs(PARM->mach);
					newrfs.Coerce(module::CoreModule()->Search(":-/1"));
					newrfs.Follow(f_cbody).Coerce(module::CoreModule()->Search(","));
					newrfs.Follow(f_cbody).Follow(f_arg[1]).Unify(rfs.Follow(f_cbody));
					newrfs.Follow(f_cbody).Follow(f_arg[2]).Coerce(module::BuiltinModule()->Search("disp_result"));
					newrfs.Follow(f_cbody).Follow(f_arg[2]).Follow(f_arg[1]).Unify(varlisttop);

					rfs = newrfs;
					say_no = true;
				}
				else
				{
					if( t->GetIndex(f_chead) != -1 )
						CheckSingleton(PARM->mach,rfs.Follow(f_chead).GetType()->GetProperName());
					else if( t->IsSubType(t_pred[0]) )
					{
						if( t == t_cut || t == t_comma || t == t_semicolon || t->IsSubType(t_equal) )
						{
							INERR(PARM->mach,t->GetProperName() << " - not redefinable");
							goto ERR_EXIT;
						}
						else
							CheckSingleton(PARM->mach, rfs.GetType()->GetName());
					}
				}

//				std::cout << rfs.DisplayAVM();
				{
					if( t->GetIndex(f_chead) != -1 )
					{
						// p :- q ... Optimize equals
						//PARM->mach->EnableConstraint(true);
						PARM->mach->EnableConstraint(constraint_status);
						while(1) {
						//while(0) {
							FSP f = rfs.Follow(f_cbody);
							if( f.GetType()->IsSubType(t_equal) )
								if( f.Follow(f_arg[1]).Unify(f.Follow(f_arg[2])) )
								{
									rfs = FSP(rfs.Follow(f_chead));
									break;
								}
								else
								{
									// warn?
									break;
								}
							else 
								if( f.GetType()->IsSubType(t_comma) &&
									f.Follow(f_arg[1]).GetType()->IsSubType(t_equal) )
								{
									FSP g = f.Follow(f_arg[1]);
									if( g.Follow(f_arg[1]).Unify(g.Follow(f_arg[2])) )
									{
										FSP h(PARM->mach);
										h.Follow(f_chead).Unify(rfs.Follow(f_chead));
										h.Follow(f_cbody).Unify(f.Follow(f_arg[2]));
										rfs = h;
										continue;
									}
									else
									{
										// warn?
										break;
									}
								}
								else
									break;
						}
						PARM->mach->EnableConstraint(false);
					}
				}
				
				ShareList sl;
				sl.AddMark(rfs);
				sl.MakeShare();
				
				ptree *pt = GenPTreeOfClause(sl, rfs);
				extern ptree *parsetop; parsetop = pt;
				if( pt != NULL ) 
				{
	#ifdef DEBUG
//					std::cout << pt->OutputTree();
	#endif
					parseinfo *info = new parseinfo(PARM->mach);
					pt->CollectInfo(0, info);
					codelist *l = pt->Compile(0, info);
					l->EndCode();
	#ifdef DEBUG
					if( DEB )
					{
						l->DebugOutput();
						std::cout << "toparg : " << (info->toparg ? info->toparg->GetName() : "(none)") << std::endl;
					}
	#endif
//					if (! strcmp(((pclause *)pt)->GetRepType()->GetSimpleName(), "assert_cky_lexical") )
//						l->DebugOutput();
//					if (! strcmp(((pclause *)pt)->GetRepType()->GetSimpleName(), "unary_rule_check") )
//						l->DebugOutput();

					if( t->GetIndex(f_chead) != -1 || t->IsSubType(pred))	// in case of p :- q...
					{
						procedure *p = procedure::New(((pclause *)pt)->GetRepType(), info->ndefarg);
						if     ( info->is_toparg && info->toparg == t_int )
							p->AddCodelistINT(l, info->toparg, info->toparg_int);
						else if( info->is_toparg && info->toparg == t_stg )
							p->AddCodelistSTG(l, info->toparg, info->toparg_stg);
						else
							p->AddCodelist(l, info->toparg);
					}
					else if( pt->GetClassName() == pclause::className )
				delete l;
					{
	#ifdef DEBUG
						if( DEB )
						{
							std::cout << "@@VARS@@" << std::endl;
							for( _HASHMAP<string, parsevar *>::const_iterator it = vars.begin();
								 it != vars.end(); ++it )
							{
							 	parsevar *it = it->second;
								std::cout << pv->GetName() << ": " << std::hex << cp2int(pv->addr()) << std::dec << std::endl;
							}
						}
	#endif
	#if defined(PROFILE)
						delete profx;
	#endif	/* defined(PROFILE) */
						CleanupVars();
						bool result;
						{
							P1("Running");
							PARM->mach->EnableConstraint(constraint_status);
							result = PARM->mach->Execute(*l);
							constraint_status = PARM->mach->GetConstraintEnabled();
							PARM->mach->EnableConstraint(false);
						}
						if( say_no )
							(*output_stream) << (result ? "yes" : "no") << std::endl;
	#if defined(PROFILE)
						profx = new prof("Compiling");
	#endif	/* defined(PROFILE) */
					delete[] l->Share();
					}
					delete l;
					delete pt;
					for (PInfoMap::const_iterator it = info->hash.begin(); it != info->hash.end(); ++it) {
						delete it->second;
					}
					delete info;
				}
				else
				{
					INERR(PARM->mach,"Cannot generate parse tree");
				}
				if( PARM->mach->getLexer() && ! PARM->mach->getLexer()->ProgInput() )
				{
					PARM->mach->SwitchOldHeap(save);
					PARM->mach->ClearStack();
					save = PARM->mach->SwitchNewHeap();
				}
			}
		}
ERR_EXIT:
		CleanupVars();
		if( PARM->mach->getLexer() == prevlexer && ! PARM->mach->getLexer()->IsSkip())
			module::UseCurrentModule();
	}
#line 2628 "yacc.cc"
    break;

  case 49: /* x_desc: feature_with_module i_desc  */
#line 888 "yacc.yy"
                        { 
				const feature *f;

				if( (yyvsp[-1].typeval) == NULL || (f = feature::Search((yyvsp[-1].typeval))) == NULL || (yyvsp[0].pval) == CORE_P_INVALID )
				{
					(yyval.pval) = CORE_P_INVALID;
				} 
				else {
					(yyval.pval) = PARM->mach->AllocNew(); 
					core_p p = PARM->mach->FollowFeature((yyval.pval), f);
					if( PARM->mach->Unify(p, (yyvsp[0].pval)) == false )
					{
						INERR(PARM->mach,"Feature '" << f->GetName() << "' is restricted to '" << f->GetBaseType()->GetAppType(f)->GetName() << "', and cannot take '" << FSP(PARM->mach,(yyvsp[0].pval)).GetType()->GetName() << "'");
						(yyval.pval) = CORE_P_INVALID;
					      }
				      }
			      }
#line 2650 "yacc.cc"
    break;

  case 50: /* x_desc: TOK_VAR  */
#line 906 "yacc.yy"
                        {
				if( (yyvsp[0].str)[0] == '_' && (yyvsp[0].str)[1] == '\0' )
				{
					(yyval.pval) = PARM->mach->AllocNew();
				}
				else
				{
					_HASHMAP<string, parsevar *>::const_iterator it = vars.find((yyvsp[0].str));
					if( it == vars.end() )
					{
						it = vars.insert(make_pair((yyvsp[0].str), new parsevar((yyvsp[0].str), PARM->mach->AllocNew()))).first;
					}
					it->second->IncCount();
					(yyval.pval) = it->second->addr();
				}
			}
#line 2671 "yacc.cc"
    break;

  case 51: /* x_desc: atom  */
#line 923 "yacc.yy"
                        {
				if( (yyvsp[0].typeval) == NULL )
					(yyval.pval) = CORE_P_INVALID;
				else
					(yyval.pval) = PARM->mach->AllocNew(VAR2c((yyvsp[0].typeval)));
//				{ $$ = PARM->mach->AllocNew(); FSP(PARM->mach, $$).Coerce($1);}
			}
#line 2683 "yacc.cc"
    break;

  case 52: /* x_desc: startp arglist ')'  */
#line 931 "yacc.yy"
                        {
				(yyval.pval) = (yyvsp[-1].pval);
				if( (yyvsp[-2].typeval) == NULL || (yyvsp[-1].pval) == CORE_P_INVALID )
				  {
				    (yyval.pval) = CORE_P_INVALID;
				  }
				else 
				{
					int i;
					type *t1 = (yyvsp[-2].typeval);
					type *t2 = (type *)c2STR(PARM->mach->ReadHeap(PARM->mach->Deref((yyvsp[-1].pval))));
					type *t3 = (type *)t1->TypeUnify(t2);
					// Search the arity
					cell c = PARM->mach->ReadHeap(PARM->mach->Deref((yyvsp[-1].pval)));
					for( i=0; i<MAXARGS; i++ )
						if( c == STR2c(t_pred[i]) )
							break;

					if( i >= MAXARGS )
						ABORT("Arglist contains unknown type??");
					
					if( t3 == NULL )
					{
						if( t1->TypeUnify(pred) == NULL )
						{
							INERR(PARM->mach,"Type '" << t1->GetName() << "' used as a " << i << "-arity predicate");
							(yyval.pval) = CORE_P_INVALID;
						}
						else if( t1->TypeUnify(t_pred[1]) == NULL )
						{
							std::ostringstream oss;
							oss << t1->GetSimpleName() << "/" << i;

							if( t1->GetModule()->Search(oss.str().c_str()) )
							{
								INERR(PARM->mach,"Functor " << t1->GetProperName() << " cannot be used;  Existing type " << (t1->GetModule()->Search(oss.str().c_str()))->GetProperName() << " prevents internal type generation");
								(yyval.pval) = CORE_P_INVALID;
							} else {
								t3 = new type(oss.str().c_str(),t1->GetModule(),t1->IsExported()); t3->SetAsChildOf(t1); t3->SetAsChildOf(t2);
								t3->Fix();
								procedure::NewTypeNotify();
								if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
									prog_types.Follow(hd).Coerce(t3);
									prog_types = prog_types.Follow(tl);
								}
							}
						}
						else
						{ // we have no type for a correct arity
							INERR(PARM->mach,"Predicate '" << t1->GetName() << "' cannot take " << i << "-arity");
							(yyval.pval) = CORE_P_INVALID;
						}
					}
					else if( i < MAXARGS-1 && t1->TypeUnify(t_pred[i+1]) == t3 )
					{
						// we have no type for a correct arity
						INERR(PARM->mach,"Predicate '" << t1->GetName() << "' cannot take " << i << "-arity");
						(yyval.pval) = CORE_P_INVALID;
					}
					else if( i==3 && (t1==t_plus || t1==t_minus || t1==t_aster || t1==t_slash || t1==t_intdiv || t1==t_modulo ) )
					{
						INWARN(PARM->mach, "Obsolete Usage of '" << t1->GetName() << "'; use 'is'-expression instead");
					}
					
					if( (yyval.pval) != CORE_P_INVALID )
						if( PARM->mach->CoerceType((yyvsp[-1].pval), (yyvsp[-2].typeval)) == false )
						{
							if( (yyvsp[-2].typeval) != NULL && (yyvsp[-1].pval) != CORE_P_INVALID )
								ABORT("arglist failed?");
							(yyval.pval) = CORE_P_INVALID;
						}
				      }
			      }
#line 2761 "yacc.cc"
    break;

  case 53: /* x_desc: '[' lists ']'  */
#line 1006 "yacc.yy"
                        {
				(yyval.pval) = (yyvsp[-1].pval);
			}
#line 2769 "yacc.cc"
    break;

  case 54: /* x_desc: TOK_INTEGER  */
#line 1010 "yacc.yy"
                        {
				FSP F(PARM->mach, (mint)(yyvsp[0].ival));
				(yyval.pval) = F.GetAddr();
			}
#line 2778 "yacc.cc"
    break;

  case 55: /* x_desc: TOK_DOUBLE  */
#line 1015 "yacc.yy"
                        {
				FSP F(PARM->mach, (mfloat)(yyvsp[0].dval));
				(yyval.pval) = F.GetAddr();
			}
#line 2787 "yacc.cc"
    break;

  case 56: /* x_desc: TOK_STRING  */
#line 1020 "yacc.yy"
                        {
				FSP F(PARM->mach, (yyvsp[0].str));
				(yyval.pval) = F.GetAddr();
			}
#line 2796 "yacc.cc"
    break;

  case 58: /* desc: '(' c_desc ')'  */
#line 1028 "yacc.yy"
                        {
				(yyval.pval) = (yyvsp[-1].pval);
			}
#line 2804 "yacc.cc"
    break;

  case 61: /* ix_desc: i_desc '+' i_desc  */
#line 1037 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_plus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2815 "yacc.cc"
    break;

  case 62: /* ix_desc: i_desc '-' i_desc  */
#line 1044 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_minus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2826 "yacc.cc"
    break;

  case 63: /* ix_desc: i_desc '^' i_desc  */
#line 1051 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_circm));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2837 "yacc.cc"
    break;

  case 64: /* ix_desc: i_desc '*' i_desc  */
#line 1058 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_aster));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2848 "yacc.cc"
    break;

  case 65: /* ix_desc: i_desc '/' i_desc  */
#line 1065 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_slash));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2859 "yacc.cc"
    break;

  case 66: /* ix_desc: i_desc BIT_AND i_desc  */
#line 1072 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitand));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2870 "yacc.cc"
    break;

  case 67: /* ix_desc: i_desc BIT_OR i_desc  */
#line 1079 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitor));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2881 "yacc.cc"
    break;

  case 68: /* ix_desc: i_desc '#' i_desc  */
#line 1086 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitxor));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2892 "yacc.cc"
    break;

  case 69: /* ix_desc: '\\' i_desc  */
#line 1093 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitnot));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2902 "yacc.cc"
    break;

  case 70: /* ix_desc: i_desc '=' i_desc  */
#line 1099 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_equal));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2913 "yacc.cc"
    break;

  case 71: /* ix_desc: i_desc NOT_UNIFIABLE i_desc  */
#line 1106 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_notuni));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2924 "yacc.cc"
    break;

  case 72: /* ix_desc: '+' i_desc  */
#line 1113 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_plus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2934 "yacc.cc"
    break;

  case 73: /* ix_desc: '-' i_desc  */
#line 1119 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_minus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2944 "yacc.cc"
    break;

  case 74: /* ix_desc: i_desc '&' i_desc  */
#line 1125 "yacc.yy"
                        {
				(yyval.pval) = (yyvsp[-2].pval);
				if( PARM->mach->Unify((yyvsp[-2].pval), (yyvsp[0].pval)) == false )
				{
					if( (yyvsp[-2].pval) != CORE_P_INVALID && (yyvsp[0].pval) != CORE_P_INVALID )
					{
						INERR(PARM->mach,"Cannot unify these two TFSs");
						outform of("Cannot unify: ");
						    of.AddAtRight(FSP(PARM->mach,(yyvsp[-2].pval)).DisplayAVM());
						of.AddAtRight(outform(" & "));
						    of.AddAtRight(FSP(PARM->mach,(yyvsp[0].pval)).DisplayAVM());
						std::cout << of;
					}
					(yyval.pval) = CORE_P_INVALID;
				}
			}
#line 2965 "yacc.cc"
    break;

  case 75: /* ix_desc: i_desc MEANS i_desc  */
#line 1142 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_means));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_chead), (yyvsp[-2].pval)) == false
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_cbody), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2976 "yacc.cc"
    break;

  case 76: /* ix_desc: i_desc MACRO_DEF i_desc  */
#line 1149 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_macro));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2987 "yacc.cc"
    break;

  case 77: /* ix_desc: MEANS i_desc  */
#line 1156 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_means));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_cbody), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 2997 "yacc.cc"
    break;

  case 78: /* ix_desc: QUERY i_desc  */
#line 1162 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_query));
				if( PARM->mach->Unify(PARM->mach->FollowFeature(PARM->mach->FollowFeature((yyval.pval), f_cbody), hd), (yyvsp[0].pval)) == false
				 || PARM->mach->CoerceType(PARM->mach->FollowFeature(PARM->mach->FollowFeature((yyval.pval), f_cbody), tl), nil) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3008 "yacc.cc"
    break;

  case 79: /* ix_desc: NOT i_desc  */
#line 1169 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_not));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3018 "yacc.cc"
    break;

  case 80: /* ix_desc: i_desc TOK_IS i_desc  */
#line 1175 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_is));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3029 "yacc.cc"
    break;

  case 81: /* ix_desc: i_desc TOK_MOD i_desc  */
#line 1182 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_modulo));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3040 "yacc.cc"
    break;

  case 82: /* ix_desc: i_desc INTDIV i_desc  */
#line 1189 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_intdiv));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3051 "yacc.cc"
    break;

  case 83: /* ix_desc: i_desc CMP_L i_desc  */
#line 1196 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpl));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3062 "yacc.cc"
    break;

  case 84: /* ix_desc: i_desc CMP_LE i_desc  */
#line 1203 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmple));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3073 "yacc.cc"
    break;

  case 85: /* ix_desc: i_desc CMP_G i_desc  */
#line 1210 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpg));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3084 "yacc.cc"
    break;

  case 86: /* ix_desc: i_desc CMP_GE i_desc  */
#line 1217 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpge));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3095 "yacc.cc"
    break;

  case 87: /* ix_desc: i_desc CMP_EQ i_desc  */
#line 1224 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpeq));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3106 "yacc.cc"
    break;

  case 88: /* ix_desc: i_desc CMP_NE i_desc  */
#line 1231 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpne));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3117 "yacc.cc"
    break;

  case 91: /* cx_desc: c_desc '+' c_desc  */
#line 1243 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_plus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3128 "yacc.cc"
    break;

  case 92: /* cx_desc: c_desc '-' c_desc  */
#line 1250 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_minus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3139 "yacc.cc"
    break;

  case 93: /* cx_desc: c_desc '^' c_desc  */
#line 1257 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_circm));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3150 "yacc.cc"
    break;

  case 94: /* cx_desc: c_desc '*' c_desc  */
#line 1264 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_aster));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3161 "yacc.cc"
    break;

  case 95: /* cx_desc: c_desc '/' c_desc  */
#line 1271 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_slash));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3172 "yacc.cc"
    break;

  case 96: /* cx_desc: c_desc BIT_AND c_desc  */
#line 1278 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitand));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3183 "yacc.cc"
    break;

  case 97: /* cx_desc: c_desc BIT_OR c_desc  */
#line 1285 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitor));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3194 "yacc.cc"
    break;

  case 98: /* cx_desc: c_desc '#' c_desc  */
#line 1292 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitxor));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3205 "yacc.cc"
    break;

  case 99: /* cx_desc: '\\' c_desc  */
#line 1299 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_bitnot));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3215 "yacc.cc"
    break;

  case 100: /* cx_desc: c_desc '=' c_desc  */
#line 1305 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_equal));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3226 "yacc.cc"
    break;

  case 101: /* cx_desc: c_desc NOT_UNIFIABLE c_desc  */
#line 1312 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_notuni));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3237 "yacc.cc"
    break;

  case 102: /* cx_desc: '+' c_desc  */
#line 1319 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_plus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3247 "yacc.cc"
    break;

  case 103: /* cx_desc: '-' c_desc  */
#line 1325 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_minus));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3257 "yacc.cc"
    break;

  case 104: /* cx_desc: c_desc '&' c_desc  */
#line 1331 "yacc.yy"
                        {
				(yyval.pval) = (yyvsp[-2].pval);
				if( PARM->mach->Unify((yyvsp[-2].pval), (yyvsp[0].pval)) == false )
				{
					if( (yyvsp[-2].pval) != CORE_P_INVALID && (yyvsp[0].pval) != CORE_P_INVALID )
					{
						INERR(PARM->mach,"Cannot unify these two TFSs");
						outform of("Cannot unify: ");
						of.AddAtRight(FSP(PARM->mach,(yyvsp[-2].pval)).DisplayAVM());
						of.AddAtRight(outform(" & "));
						of.AddAtRight(FSP(PARM->mach,(yyvsp[0].pval)).DisplayAVM());
						std::cout << of;
					}
					(yyval.pval) = CORE_P_INVALID;
				}
			}
#line 3278 "yacc.cc"
    break;

  case 105: /* cx_desc: c_desc MEANS c_desc  */
#line 1348 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_means));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_chead), (yyvsp[-2].pval)) == false
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_cbody), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3289 "yacc.cc"
    break;

  case 106: /* cx_desc: c_desc MACRO_DEF c_desc  */
#line 1355 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_macro));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3300 "yacc.cc"
    break;

  case 107: /* cx_desc: MEANS c_desc  */
#line 1362 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_means));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_cbody), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3310 "yacc.cc"
    break;

  case 108: /* cx_desc: QUERY c_desc  */
#line 1368 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_query));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_cbody), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3320 "yacc.cc"
    break;

  case 109: /* cx_desc: NOT i_desc  */
#line 1374 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_not));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3330 "yacc.cc"
    break;

  case 110: /* cx_desc: c_desc ',' c_desc  */
#line 1380 "yacc.yy"
                        {
				if( (yyvsp[-2].pval) == CORE_P_INVALID || (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else {
					(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_comma));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval));
				}
			}
#line 3344 "yacc.cc"
    break;

  case 111: /* cx_desc: c_desc ';' c_desc  */
#line 1390 "yacc.yy"
                        {
				if( (yyvsp[-2].pval) == CORE_P_INVALID || (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else {
					(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_semicolon));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval));
				}
			}
#line 3358 "yacc.cc"
    break;

  case 112: /* cx_desc: c_desc IF_THEN c_desc  */
#line 1400 "yacc.yy"
                        {
				if( (yyvsp[-2].pval) == CORE_P_INVALID || (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else {
					(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_ifthen));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval));
				}
			}
#line 3372 "yacc.cc"
    break;

  case 113: /* cx_desc: c_desc TOK_IS c_desc  */
#line 1410 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_is));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3383 "yacc.cc"
    break;

  case 114: /* cx_desc: c_desc TOK_MOD c_desc  */
#line 1417 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_modulo));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3394 "yacc.cc"
    break;

  case 115: /* cx_desc: c_desc INTDIV c_desc  */
#line 1424 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_intdiv));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3405 "yacc.cc"
    break;

  case 116: /* cx_desc: c_desc CMP_L c_desc  */
#line 1431 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpl));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3416 "yacc.cc"
    break;

  case 117: /* cx_desc: c_desc CMP_LE c_desc  */
#line 1438 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmple));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3427 "yacc.cc"
    break;

  case 118: /* cx_desc: c_desc CMP_G c_desc  */
#line 1445 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpg));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3438 "yacc.cc"
    break;

  case 119: /* cx_desc: c_desc CMP_GE c_desc  */
#line 1452 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpge));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3449 "yacc.cc"
    break;

  case 120: /* cx_desc: c_desc CMP_EQ c_desc  */
#line 1459 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpeq));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3460 "yacc.cc"
    break;

  case 121: /* cx_desc: c_desc CMP_NE c_desc  */
#line 1466 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew(VAR2c(t_cmpne));
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[-2].pval)) == false 
				 || PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[2]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3471 "yacc.cc"
    break;

  case 122: /* arglist: i_desc  */
#line 1476 "yacc.yy"
                        {
				(yyval.pval) = PARM->mach->AllocNew();
				if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[1]), (yyvsp[0].pval)) == false )
					(yyval.pval) = CORE_P_INVALID;
			}
#line 3481 "yacc.cc"
    break;

  case 123: /* arglist: arglist ',' i_desc  */
#line 1482 "yacc.yy"
                        {
				int i;
				if( (yyvsp[-2].pval) == CORE_P_INVALID || (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else
				{
					cell c = PARM->mach->ReadHeap(PARM->mach->Deref((yyvsp[-2].pval)));
					for( i=0; i<MAXARGS; i++ )
						if( c == STR2c(t_pred[i]) )
							break;
					if( i >= MAXARGS )
						ABORT("Arglist contains unknown type?");
					else if( i == MAXARGS-1 )
						INERR(PARM->mach,"Argument list length over " << MAXARGS);
					else
					{
						(yyval.pval) = (yyvsp[-2].pval);
						if( PARM->mach->Unify(PARM->mach->FollowFeature((yyval.pval), f_arg[i+1]), (yyvsp[0].pval)) == false )
							(yyval.pval) = CORE_P_INVALID;
					}
				}
			}
#line 3508 "yacc.cc"
    break;

  case 124: /* lists: %empty  */
#line 1508 "yacc.yy"
                    { (yyval.pval) = PARM->mach->AllocNew(VAR2c(nil)); }
#line 3514 "yacc.cc"
    break;

  case 125: /* lists: nelistp  */
#line 1510 "yacc.yy"
                        { (yyval.pval) = (yyvsp[0].pval); }
#line 3520 "yacc.cc"
    break;

  case 126: /* nelistp: i_desc  */
#line 1515 "yacc.yy"
                        {
				if( (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else {
					(yyval.pval) = PARM->mach->AllocNew();
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), hd), (yyvsp[0].pval));
					PARM->mach->CoerceType(PARM->mach->FollowFeature((yyval.pval), tl), nil);
				}
			}
#line 3534 "yacc.cc"
    break;

  case 127: /* nelistp: i_desc '|' i_desc  */
#line 1525 "yacc.yy"
                        {
				if( (yyvsp[-2].pval) == CORE_P_INVALID || (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else {
					(yyval.pval) = PARM->mach->AllocNew();
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), hd), (yyvsp[-2].pval));
					if( PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), tl), (yyvsp[0].pval)) == false )
					{
						INERR(PARM->mach,"Tail of a list is restricted to 'list', and cannot take '" << FSP(PARM->mach,(yyvsp[0].pval)).GetType()->GetName() << "'");
//						outform of("Containee: ");
//						of.AddAtRight(FSP(PARM->mach, $3).DisplayAVM());
//						std::cout << of;
						(yyval.pval) = CORE_P_INVALID;
					}
				}
			}
#line 3555 "yacc.cc"
    break;

  case 128: /* nelistp: i_desc ',' nelistp  */
#line 1542 "yacc.yy"
                        {
				if( (yyvsp[-2].pval) == CORE_P_INVALID || (yyvsp[0].pval) == CORE_P_INVALID )
					(yyval.pval) = CORE_P_INVALID;
				else {
					(yyval.pval) = PARM->mach->AllocNew();
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), hd), (yyvsp[-2].pval));
					PARM->mach->Unify     (PARM->mach->FollowFeature((yyval.pval), tl), (yyvsp[0].pval));
				}
			}
#line 3569 "yacc.cc"
    break;

  case 129: /* atom: '+'  */
#line 1556 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_plus; }
#line 3575 "yacc.cc"
    break;

  case 130: /* atom: '-'  */
#line 1557 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_minus; }
#line 3581 "yacc.cc"
    break;

  case 131: /* atom: '*'  */
#line 1558 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_aster; }
#line 3587 "yacc.cc"
    break;

  case 132: /* atom: '/'  */
#line 1559 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_slash; }
#line 3593 "yacc.cc"
    break;

  case 133: /* atom: '='  */
#line 1560 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_equal; }
#line 3599 "yacc.cc"
    break;

  case 134: /* atom: '^'  */
#line 1561 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_circm; }
#line 3605 "yacc.cc"
    break;

  case 135: /* atom: MACRO_DEF  */
#line 1562 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_macro; }
#line 3611 "yacc.cc"
    break;

  case 136: /* atom: MEANS  */
#line 1563 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_means; }
#line 3617 "yacc.cc"
    break;

  case 137: /* atom: QUERY  */
#line 1564 "yacc.yy"
                                                { (yyval.typeval)= (type *)t_query; }
#line 3623 "yacc.cc"
    break;

  case 138: /* atom: atomtok  */
#line 1565 "yacc.yy"
                                        { (yyval.typeval) = (yyvsp[0].typeval); }
#line 3629 "yacc.cc"
    break;

  case 139: /* atom: feature_with_module  */
#line 1566 "yacc.yy"
                                                        { (yyval.typeval) = (yyvsp[0].typeval); }
#line 3635 "yacc.cc"
    break;

  case 141: /* startp: TOK_STARTP  */
#line 1575 "yacc.yy"
                        { 
				if( progalter && !bi_type((yyvsp[0].str)) )
				{
					(yyval.typeval) = (type *)module::CurrentModule()->Search(progalter_tprefix + (yyvsp[0].str));
					if( (yyval.typeval) == NULL )
					{
						(yyval.typeval) = (type *)module::CurrentModule()->Search((yyvsp[0].str));
						if( (yyval.typeval) != NULL && ! (yyval.typeval)->IsBuiltIn() )
							(yyval.typeval) = NULL;
					}
				}
				else
					(yyval.typeval) = (type *)module::CurrentModule()->Search((yyvsp[0].str));

				if( (yyval.typeval) == NULL ) 
				{ // This is predicate; make the entry
//					INWARN(PARM->mach, "Type '" << $1 << "' is undefined; treated as a subtype of 'pred'");
					(yyval.typeval) = new type(progalter ? (progalter_tprefix + (yyvsp[0].str)) : (yyvsp[0].str),module::CurrentModule());
					(yyval.typeval)->SetAsChildOf(pred);
					(yyval.typeval)->Fix();
					INWARN(PARM->mach, (yyval.typeval)->GetProperName() << " <- [pred]. is assumed implicitly");
					procedure::NewTypeNotify();
					if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {

						prog_types.Follow(hd).Coerce((yyval.typeval));
						prog_types = prog_types.Follow(tl);
					}
				}
				else
				{
					if( (yyval.typeval)->TypeUnify(pred) == NULL )
					{
						INERR(PARM->mach,"Type '" << (yyvsp[0].str) << "' is not a subtype of 'pred' but used as a predicate");
						(yyval.typeval) = NULL;
					}
				}
			}
#line 3677 "yacc.cc"
    break;

  case 142: /* startp: modulename TOK_STARTP  */
#line 1613 "yacc.yy"
                        {
                                module *m = module::SearchModule((yyvsp[-1].str));
                                if (m == NULL)
                                        {
					  INERR(PARM->mach,"Unknown module name \"" << (yyvsp[-1].str) <<"\"");
					  errored = true;
					  (yyval.typeval) = NULL;
					}
				if( progalter )
				{
					(yyval.typeval) = (type *)m->Search(progalter_tprefix + (yyvsp[0].str));
					if( (yyval.typeval) == NULL )
					{
						(yyval.typeval) = (type *)m->Search((yyvsp[0].str));
						if( (yyval.typeval) != NULL && ! (yyval.typeval)->IsBuiltIn() )
							(yyval.typeval) = NULL;
					}
				}
				else
					(yyval.typeval) = (type *)m->Search((yyvsp[0].str));

				if( (yyval.typeval) == NULL ) 
				{ // This is predicate; make the entry
//					INWARN(PARM->mach, "Type '" << $2 << "' is undefined; treated as a subtype of 'pred'");
					(yyval.typeval) = new type(progalter ? (progalter_tprefix + (yyvsp[0].str)) : (yyvsp[0].str),m);
					(yyval.typeval)->SetAsChildOf(pred);
					(yyval.typeval)->Fix();
					INWARN(PARM->mach, (yyval.typeval)->GetProperName() << " <- [pred]. is assumed implicitly");
					procedure::NewTypeNotify();
					if( PARM->mach->getLexer() && PARM->mach->getLexer()->ProgInput() ) {
						prog_types.Follow(hd).Coerce((yyval.typeval));
						prog_types = prog_types.Follow(tl);
					}
				}
				else
				{
					if( (yyval.typeval)->TypeUnify(pred) == NULL )
					{
						INERR(PARM->mach,"Type " << (yyvsp[0].str) << " is not a subtype of 'pred' but used as a predicate");
						(yyval.typeval) = NULL;
					}
				}
			}
#line 3725 "yacc.cc"
    break;

  case 143: /* modulename: TOK_MODULENAME  */
#line 1659 "yacc.yy"
                                 { (yyval.str) = (yyvsp[0].str); }
#line 3731 "yacc.cc"
    break;

  case 144: /* modulename: TOK_MODULENAME modulename  */
#line 1660 "yacc.yy"
                                            { 
				(yyval.str) = my_malloc( strlen((yyvsp[-1].str))+strlen((yyvsp[0].str))+2 );
				strcpy((yyval.str), (yyvsp[-1].str));
				strcat((yyval.str), ":");
				strcat((yyval.str), (yyvsp[0].str));
			}
#line 3742 "yacc.cc"
    break;


#line 3746 "yacc.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (parm, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval, parm);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parm);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (parm, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parm);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parm);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1667 "yacc.yy"


struct token_key tokens[] =
{
		{"+", '+'},
		{"-", '-'},
		{"*", '*'},
		{"/", '/'},
		{"=", '='},
		{"&", '&'},
		{"\\", '\\'},
		{"#", '#'},
		{";", ';'},
		{":", ':'},
		{"^", '^'},
		{"<-", SUBSUMED_BY },
		{"?-", QUERY },
		{":-", MEANS },
		{"<=", CMP_LE },
		{"<",  CMP_L },
		{">=", CMP_GE },
		{">", CMP_G },
		{"=:=", CMP_EQ },
		{"=\\=", CMP_NE },
		{":=", MACRO_DEF },
		{"//", INTDIV },
		{"->", IF_THEN },
		{"\\+", NOT },
		{"\\=", NOT_UNIFIABLE },
		{"\\/", BIT_OR },
		{"/\\", BIT_AND },
		{"./",  ATTR_DEF },
		{NULL, 0}
};

_HASHMAP<string, token_key *> *token_hash;


static void init() 
{ 
#ifdef DEBUG
	std::cout << "Initialize " << __FILE__ << std::endl;
#endif
//	input_stream = & std::cin;
//	output_stream = & std::cout;
//	error_stream = & std::cerr;

	token_hash = new _HASHMAP<string, token_key *>;
	for( int i=0; tokens[i].str != NULL; i++ )
	{
//		std::cout << i << " " << tokens[i].str << " " << tokens[i].token_code << std::endl;
		token_hash->insert(make_pair(tokens[i].GetKey(), &tokens[i]));
	}
}
static void term() 
{ 
/*
	if( input_stream != &std::cin )
		delete input_stream;
	if( output_stream != &std::cout )
		delete output_stream;
	if( error_stream != &std::cerr )
		delete error_stream;
*/
	delete token_hash;
}
static InitFunction IF(init, 100);
static TermFunction TF(term, 100);

void yyerror(void *parm, const char* s) {
        INERR(((parser_control *)parm)->mach, s);
	//INERR(m, s);
}

void machine::parse(lexer_t lex)
{
#ifdef PROFILE
#if PROFILE >= 1
	profx = new prof("Compiling");
#endif
#endif
	save = SwitchNewHeap();
	lexer_t oldlex = getLexer();
#if YYDEBUG
	yydebug = 1;
#endif
	setLexer(lex);
	parser_control parm( this );
        constraint_status = GetConstraintEnabled();
        EnableConstraint( false );  // disable complex constraint during parsing
	while( yyparse(&parm) )
	{
		getLexer()->Flush(); 
		getLexer()->SetFirstRun();
	}
        EnableConstraint( constraint_status );
#ifdef PROFILE
#if PROFILE >= 1
	delete profx;
#endif
#endif
	setLexer(oldlex);
}

void machine::parse()
{
#ifdef PROFILE
#if PROFILE >= 1
	profx = new prof("Compiling");
#endif
#endif
	save = SwitchNewHeap();
	parser_control parm( this );
        constraint_status = GetConstraintEnabled();
        EnableConstraint( false );  // disable complex constraint during parsing
	while( yyparse(&parm) )
	{
		getLexer()->Flush(); 
		getLexer()->SetFirstRun();
	}
        EnableConstraint( constraint_status );
#ifdef PROFILE
#if PROFILE >= 1
	delete profx;
#endif
#endif
}


void CheckSingleton(machine *m, const string &where)
{
	P2("Check Singleton");

	ShareList sl;
	std::ostringstream oss;

	int nsingle = 0;

	for( _HASHMAP<string, parsevar *>::const_iterator it = vars.begin();
		 it != vars.end(); ++it )
	{
		parsevar *p = it->second;
		if( p->GetCount() == 1 && p->GetName()[0] != '_' )
		{
			if( nsingle == 0 )
			{
				oss << "[" << p->GetName();
			}
			else
			{
				oss << ", " << p->GetName();
			}
			nsingle++;
		}
	}

	if( nsingle != 0 )
	{
		oss << "]";

		if( nsingle == 1 )
		{
			INWARN(m, oss.str() << " - singleton variable in " << where);
		}
		else
		{
			INWARN(m, oss.str() << " - singleton variables in " << where);
		}
	}
}

#define STRBUFSIZE 2000

struct strbuf
{
	struct strbuf *next;
	char buf[STRBUFSIZE];
};

static struct strbuf *root = NULL;
static char *bufp = NULL;
static int bufremain = 0;

char *my_malloc(int len)
{
	char *ret;
	struct strbuf *newbuf;
	int buflen;
	
	if( bufremain >= len )
	{
		ret = bufp;
		bufp += len;
		bufremain -= len;
/*		printf("A:%08p\n", ret);*/
		return ret;
	}

	buflen = sizeof(struct strbuf);
	if( len > STRBUFSIZE )
	{
		buflen = buflen - STRBUFSIZE + len;
	}
	
	newbuf = (struct strbuf *)new char[buflen];
	newbuf->next = root;
	root = newbuf;
	bufp = newbuf->buf;
	bufremain = buflen - (sizeof(struct strbuf) - STRBUFSIZE);
	return my_malloc(len);
}


char *my_strdup(char *str)
{
	int len = strlen(str) + 1;

	return strcpy(my_malloc(len), str);
}

void free_dups()
{
/*	printf("F\n");*/
	struct strbuf *next;
	while( root != NULL )
	{
		next = root->next;
		delete[] (char *)root;
		root = next;
	}
	bufp = NULL;
	bufremain = 0;
}

void error_open_file(char *s)
{
	std::cout << "Error: Cannot open input file '" << s << "'" << std::endl;
}

void success_open_file(char *s)
{
	std::cout << s << ":" << std::endl;
}

int token_search(char *str)
{
	_HASHMAP<string, token_key *>::const_iterator it = token_hash->find(str);
// std::cout << "TOKEN: " << str << " " << (tk==NULL ? 0 : tk->token_code) << std::endl;
	if( it == token_hash->end() )
	{
		return TOK_ATOM;
	}
	else
	{
		return it->second->token_code;
	}
}

} // namespace
