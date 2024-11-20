/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         defyyparse
#define yylex           defyylex
#define yyerror         defyyerror
#define yydebug         defyydebug
#define yynerrs         defyynerrs

/* First part of user prologue.  */
#line 58 "def.y"

#include <stdlib.h>
#include <string.h>
#include "defrReader.hpp"
#include "defiUser.hpp"
#include "defrCallBacks.hpp"
#include "lex.h"

#define DEF_MAX_INT 2147483647
#define YYDEBUG 1     // this is temp fix for pcr 755132 
// TX_DIR:TRANSLATION ON


#include "defrData.hpp"
#include "defrSettings.hpp"
#include "defrCallBacks.hpp"

BEGIN_LEFDEF_PARSER_NAMESPACE

// Macro to describe how we handle a callback.
// If the function was set then call it.
// If the function returns non zero then there was an error
// so call the error routine and exit.
//
#define CALLBACK(func, typ, data) \
    if (!defData->errors) {\
      if (func) { \
        if ((defData->defRetVal = (*func)(typ, data, defData->session->UserData)) == PARSE_OK) { \
        } else if (defData->defRetVal == STOP_PARSE) { \
          return defData->defRetVal; \
        } else { \
          defData->defError(6010, "An error has been reported in callback."); \
          return defData->defRetVal; \
        } \
      } \
    }

#define CHKERR() \
    if (defData->checkErrors()) { \
      return 1; \
    }

#define CHKPROPTYPE(propType, propName, name) \
    if (propType == 'N') { \
       defData->warningMsg = (char*)malloc(strlen(propName)+strlen(name)+40); \
       sprintf(defData->warningMsg, "The PropName %s is not defined for %s.", \
               propName, name); \
       defData->defWarning(7010, defData->warningMsg); \
       free(defData->warningMsg); \
    }

int yylex(YYSTYPE *pYylval, defrData *defData)
{
    return defData->defyylex(pYylval);
}


void yyerror(defrData *defData, const char *s)
{
    return defData->defyyerror(s);
}




#define FIXED 1
#define COVER 2
#define PLACED 3
#define UNPLACED 4

#line 146 "def.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_DEFYY_DEF_TAB_H_INCLUDED
# define YY_DEFYY_DEF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int defyydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    QSTRING = 258,
    T_STRING = 259,
    SITE_PATTERN = 260,
    NUMBER = 261,
    K_HISTORY = 262,
    K_NAMESCASESENSITIVE = 263,
    K_DESIGN = 264,
    K_VIAS = 265,
    K_TECH = 266,
    K_UNITS = 267,
    K_ARRAY = 268,
    K_FLOORPLAN = 269,
    K_SITE = 270,
    K_CANPLACE = 271,
    K_CANNOTOCCUPY = 272,
    K_DIEAREA = 273,
    K_PINS = 274,
    K_DEFAULTCAP = 275,
    K_MINPINS = 276,
    K_WIRECAP = 277,
    K_TRACKS = 278,
    K_GCELLGRID = 279,
    K_DO = 280,
    K_BY = 281,
    K_STEP = 282,
    K_LAYER = 283,
    K_ROW = 284,
    K_RECT = 285,
    K_COMPS = 286,
    K_COMP_GEN = 287,
    K_SOURCE = 288,
    K_WEIGHT = 289,
    K_EEQMASTER = 290,
    K_FIXED = 291,
    K_COVER = 292,
    K_UNPLACED = 293,
    K_PLACED = 294,
    K_FOREIGN = 295,
    K_REGION = 296,
    K_REGIONS = 297,
    K_NETS = 298,
    K_START_NET = 299,
    K_MUSTJOIN = 300,
    K_ORIGINAL = 301,
    K_USE = 302,
    K_STYLE = 303,
    K_PATTERN = 304,
    K_PATTERNNAME = 305,
    K_ESTCAP = 306,
    K_ROUTED = 307,
    K_NEW = 308,
    K_SNETS = 309,
    K_SHAPE = 310,
    K_WIDTH = 311,
    K_VOLTAGE = 312,
    K_SPACING = 313,
    K_NONDEFAULTRULE = 314,
    K_NONDEFAULTRULES = 315,
    K_N = 316,
    K_S = 317,
    K_E = 318,
    K_W = 319,
    K_FN = 320,
    K_FE = 321,
    K_FS = 322,
    K_FW = 323,
    K_GROUPS = 324,
    K_GROUP = 325,
    K_SOFT = 326,
    K_MAXX = 327,
    K_MAXY = 328,
    K_MAXHALFPERIMETER = 329,
    K_CONSTRAINTS = 330,
    K_NET = 331,
    K_PATH = 332,
    K_SUM = 333,
    K_DIFF = 334,
    K_SCANCHAINS = 335,
    K_START = 336,
    K_FLOATING = 337,
    K_ORDERED = 338,
    K_STOP = 339,
    K_IN = 340,
    K_OUT = 341,
    K_RISEMIN = 342,
    K_RISEMAX = 343,
    K_FALLMIN = 344,
    K_FALLMAX = 345,
    K_WIREDLOGIC = 346,
    K_MAXDIST = 347,
    K_ASSERTIONS = 348,
    K_DISTANCE = 349,
    K_MICRONS = 350,
    K_END = 351,
    K_IOTIMINGS = 352,
    K_RISE = 353,
    K_FALL = 354,
    K_VARIABLE = 355,
    K_SLEWRATE = 356,
    K_CAPACITANCE = 357,
    K_DRIVECELL = 358,
    K_FROMPIN = 359,
    K_TOPIN = 360,
    K_PARALLEL = 361,
    K_TIMINGDISABLES = 362,
    K_THRUPIN = 363,
    K_MACRO = 364,
    K_PARTITIONS = 365,
    K_TURNOFF = 366,
    K_FROMCLOCKPIN = 367,
    K_FROMCOMPPIN = 368,
    K_FROMIOPIN = 369,
    K_TOCLOCKPIN = 370,
    K_TOCOMPPIN = 371,
    K_TOIOPIN = 372,
    K_SETUPRISE = 373,
    K_SETUPFALL = 374,
    K_HOLDRISE = 375,
    K_HOLDFALL = 376,
    K_VPIN = 377,
    K_SUBNET = 378,
    K_XTALK = 379,
    K_PIN = 380,
    K_SYNTHESIZED = 381,
    K_DEFINE = 382,
    K_DEFINES = 383,
    K_DEFINEB = 384,
    K_IF = 385,
    K_THEN = 386,
    K_ELSE = 387,
    K_FALSE = 388,
    K_TRUE = 389,
    K_EQ = 390,
    K_NE = 391,
    K_LE = 392,
    K_LT = 393,
    K_GE = 394,
    K_GT = 395,
    K_OR = 396,
    K_AND = 397,
    K_NOT = 398,
    K_SPECIAL = 399,
    K_DIRECTION = 400,
    K_RANGE = 401,
    K_FPC = 402,
    K_HORIZONTAL = 403,
    K_VERTICAL = 404,
    K_ALIGN = 405,
    K_MIN = 406,
    K_MAX = 407,
    K_EQUAL = 408,
    K_BOTTOMLEFT = 409,
    K_TOPRIGHT = 410,
    K_ROWS = 411,
    K_TAPER = 412,
    K_TAPERRULE = 413,
    K_VERSION = 414,
    K_DIVIDERCHAR = 415,
    K_BUSBITCHARS = 416,
    K_PROPERTYDEFINITIONS = 417,
    K_STRING = 418,
    K_REAL = 419,
    K_INTEGER = 420,
    K_PROPERTY = 421,
    K_BEGINEXT = 422,
    K_ENDEXT = 423,
    K_NAMEMAPSTRING = 424,
    K_ON = 425,
    K_OFF = 426,
    K_X = 427,
    K_Y = 428,
    K_COMPONENT = 429,
    K_MASK = 430,
    K_MASKSHIFT = 431,
    K_COMPSMASKSHIFT = 432,
    K_SAMEMASK = 433,
    K_PINPROPERTIES = 434,
    K_TEST = 435,
    K_COMMONSCANPINS = 436,
    K_SNET = 437,
    K_COMPONENTPIN = 438,
    K_REENTRANTPATHS = 439,
    K_SHIELD = 440,
    K_SHIELDNET = 441,
    K_NOSHIELD = 442,
    K_VIRTUAL = 443,
    K_ANTENNAPINPARTIALMETALAREA = 444,
    K_ANTENNAPINPARTIALMETALSIDEAREA = 445,
    K_ANTENNAPINGATEAREA = 446,
    K_ANTENNAPINDIFFAREA = 447,
    K_ANTENNAPINMAXAREACAR = 448,
    K_ANTENNAPINMAXSIDEAREACAR = 449,
    K_ANTENNAPINPARTIALCUTAREA = 450,
    K_ANTENNAPINMAXCUTCAR = 451,
    K_SIGNAL = 452,
    K_POWER = 453,
    K_GROUND = 454,
    K_CLOCK = 455,
    K_TIEOFF = 456,
    K_ANALOG = 457,
    K_SCAN = 458,
    K_RESET = 459,
    K_RING = 460,
    K_STRIPE = 461,
    K_FOLLOWPIN = 462,
    K_IOWIRE = 463,
    K_COREWIRE = 464,
    K_BLOCKWIRE = 465,
    K_FILLWIRE = 466,
    K_BLOCKAGEWIRE = 467,
    K_PADRING = 468,
    K_BLOCKRING = 469,
    K_BLOCKAGES = 470,
    K_PLACEMENT = 471,
    K_SLOTS = 472,
    K_FILLS = 473,
    K_PUSHDOWN = 474,
    K_NETLIST = 475,
    K_DIST = 476,
    K_USER = 477,
    K_TIMING = 478,
    K_BALANCED = 479,
    K_STEINER = 480,
    K_TRUNK = 481,
    K_FIXEDBUMP = 482,
    K_FENCE = 483,
    K_FREQUENCY = 484,
    K_GUIDE = 485,
    K_MAXBITS = 486,
    K_PARTITION = 487,
    K_TYPE = 488,
    K_ANTENNAMODEL = 489,
    K_DRCFILL = 490,
    K_OXIDE1 = 491,
    K_OXIDE2 = 492,
    K_OXIDE3 = 493,
    K_OXIDE4 = 494,
    K_OXIDE5 = 495,
    K_OXIDE6 = 496,
    K_OXIDE7 = 497,
    K_OXIDE8 = 498,
    K_OXIDE9 = 499,
    K_OXIDE10 = 500,
    K_OXIDE11 = 501,
    K_OXIDE12 = 502,
    K_OXIDE13 = 503,
    K_OXIDE14 = 504,
    K_OXIDE15 = 505,
    K_OXIDE16 = 506,
    K_OXIDE17 = 507,
    K_OXIDE18 = 508,
    K_OXIDE19 = 509,
    K_OXIDE20 = 510,
    K_OXIDE21 = 511,
    K_OXIDE22 = 512,
    K_OXIDE23 = 513,
    K_OXIDE24 = 514,
    K_OXIDE25 = 515,
    K_OXIDE26 = 516,
    K_OXIDE27 = 517,
    K_OXIDE28 = 518,
    K_OXIDE29 = 519,
    K_OXIDE30 = 520,
    K_OXIDE31 = 521,
    K_OXIDE32 = 522,
    K_CUTSIZE = 523,
    K_CUTSPACING = 524,
    K_DESIGNRULEWIDTH = 525,
    K_DIAGWIDTH = 526,
    K_ENCLOSURE = 527,
    K_HALO = 528,
    K_GROUNDSENSITIVITY = 529,
    K_HARDSPACING = 530,
    K_LAYERS = 531,
    K_MINCUTS = 532,
    K_NETEXPR = 533,
    K_OFFSET = 534,
    K_ORIGIN = 535,
    K_ROWCOL = 536,
    K_STYLES = 537,
    K_POLYGON = 538,
    K_PORT = 539,
    K_SUPPLYSENSITIVITY = 540,
    K_VIA = 541,
    K_VIARULE = 542,
    K_WIREEXT = 543,
    K_EXCEPTPGNET = 544,
    K_FILLWIREOPC = 545,
    K_OPC = 546,
    K_PARTIAL = 547,
    K_ROUTEHALO = 548
  };
#endif

/* Value type.  */



int defyyparse (defrData *defData);

#endif /* !YY_DEFYY_DEF_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  301
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  985
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1696

#define YYUNDEFTOK  2
#define YYMAXUTOK   548


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     297,   298,   299,   296,   300,   295,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   294,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   223,   223,   226,   227,   227,   253,   254,   267,   285,
     286,   287,   290,   290,   290,   290,   291,   291,   291,   291,
     292,   292,   292,   293,   293,   293,   294,   294,   294,   295,
     295,   295,   295,   296,   299,   299,   299,   299,   300,   300,
     300,   301,   301,   301,   302,   302,   302,   303,   303,   303,
     303,   308,   308,   315,   340,   340,   346,   346,   352,   352,
     358,   365,   364,   376,   377,   380,   380,   389,   389,   398,
     398,   407,   407,   416,   416,   425,   425,   434,   434,   445,
     444,   455,   454,   475,   477,   477,   482,   482,   488,   493,
     498,   504,   505,   508,   516,   523,   530,   530,   542,   542,
     555,   556,   557,   558,   559,   560,   561,   562,   565,   564,
     577,   580,   592,   593,   596,   607,   610,   613,   619,   620,
     623,   624,   625,   623,   638,   639,   641,   647,   653,   659,
     680,   680,   700,   700,   720,   724,   748,   749,   748,   774,
     775,   774,   817,   817,   850,   870,   888,   906,   924,   942,
     942,   960,   960,   979,   997,   997,  1015,  1032,  1033,  1047,
    1048,  1055,  1056,  1069,  1070,  1093,  1117,  1118,  1141,  1165,
    1170,  1175,  1180,  1185,  1190,  1195,  1200,  1205,  1210,  1215,
    1220,  1225,  1230,  1235,  1240,  1245,  1250,  1255,  1260,  1265,
    1270,  1275,  1280,  1285,  1290,  1295,  1300,  1305,  1310,  1315,
    1320,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,  1346,
    1347,  1347,  1350,  1356,  1358,  1356,  1372,  1382,  1420,  1423,
    1431,  1432,  1435,  1435,  1439,  1440,  1443,  1455,  1464,  1475,
    1474,  1508,  1513,  1515,  1518,  1520,  1521,  1532,  1533,  1536,
    1537,  1537,  1540,  1541,  1544,  1550,  1579,  1585,  1588,  1591,
    1597,  1598,  1601,  1602,  1601,  1613,  1614,  1617,  1617,  1624,
    1625,  1624,  1651,  1651,  1661,  1663,  1661,  1686,  1687,  1693,
    1705,  1717,  1729,  1729,  1742,  1745,  1748,  1749,  1752,  1759,
    1765,  1771,  1778,  1779,  1782,  1788,  1794,  1800,  1801,  1804,
    1805,  1804,  1814,  1817,  1822,  1823,  1826,  1826,  1829,  1844,
    1845,  1848,  1863,  1872,  1882,  1884,  1887,  1904,  1907,  1914,
    1915,  1918,  1925,  1926,  1929,  1935,  1941,  1941,  1949,  1950,
    1955,  1961,  1962,  1965,  1965,  1965,  1965,  1965,  1966,  1966,
    1966,  1966,  1967,  1967,  1967,  1970,  1977,  1977,  1983,  1983,
    1991,  1992,  1995,  2001,  2003,  2005,  2007,  2012,  2014,  2020,
    2031,  2044,  2043,  2065,  2066,  2086,  2086,  2106,  2106,  2110,
    2111,  2114,  2125,  2134,  2144,  2147,  2147,  2162,  2164,  2167,
    2174,  2181,  2196,  2196,  2205,  2207,  2209,  2212,  2218,  2224,
    2227,  2234,  2235,  2238,  2249,  2253,  2253,  2256,  2255,  2264,
    2264,  2272,  2273,  2276,  2276,  2290,  2290,  2297,  2297,  2306,
    2307,  2314,  2319,  2320,  2324,  2323,  2342,  2345,  2362,  2362,
    2380,  2380,  2383,  2386,  2389,  2392,  2395,  2398,  2401,  2401,
    2412,  2414,  2414,  2417,  2418,  2417,  2464,  2469,  2479,  2463,
    2493,  2493,  2497,  2503,  2504,  2507,  2518,  2527,  2537,  2539,
    2541,  2543,  2545,  2549,  2548,  2559,  2559,  2562,  2563,  2563,
    2566,  2567,  2570,  2572,  2574,  2577,  2579,  2581,  2585,  2589,
    2592,  2592,  2598,  2617,  2597,  2631,  2648,  2665,  2666,  2671,
    2682,  2696,  2703,  2714,  2738,  2772,  2806,  2831,  2832,  2833,
    2833,  2844,  2843,  2853,  2864,  2872,  2879,  2886,  2892,  2900,
    2908,  2916,  2925,  2933,  2940,  2947,  2955,  2964,  2965,  2967,
    2968,  2971,  2975,  2975,  2980,  3000,  3001,  3005,  3009,  3029,
    3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3065,  3067,
    3069,  3071,  3074,  3077,  3078,  3081,  3084,  3085,  3088,  3088,
    3089,  3089,  3092,  3106,  3105,  3127,  3128,  3127,  3134,  3138,
    3144,  3145,  3144,  3185,  3185,  3218,  3219,  3218,  3251,  3254,
    3257,  3260,  3260,  3263,  3266,  3269,  3278,  3281,  3284,  3284,
    3288,  3292,  3293,  3294,  3295,  3296,  3297,  3298,  3299,  3300,
    3303,  3317,  3317,  3372,  3372,  3381,  3381,  3399,  3400,  3399,
    3407,  3408,  3411,  3423,  3432,  3442,  3443,  3448,  3449,  3452,
    3454,  3456,  3458,  3462,  3479,  3482,  3482,  3501,  3509,  3500,
    3517,  3522,  3529,  3536,  3539,  3545,  3546,  3549,  3555,  3555,
    3566,  3567,  3570,  3577,  3578,  3581,  3583,  3583,  3586,  3586,
    3588,  3594,  3604,  3609,  3610,  3613,  3624,  3633,  3643,  3644,
    3647,  3655,  3663,  3672,  3679,  3683,  3686,  3700,  3714,  3715,
    3718,  3719,  3729,  3742,  3742,  3747,  3747,  3752,  3757,  3763,
    3764,  3766,  3768,  3768,  3777,  3778,  3781,  3782,  3785,  3790,
    3795,  3800,  3806,  3817,  3828,  3831,  3837,  3838,  3841,  3847,
    3847,  3854,  3855,  3860,  3861,  3864,  3864,  3868,  3868,  3871,
    3870,  3879,  3879,  3883,  3883,  3885,  3885,  3903,  3910,  3911,
    3920,  3934,  3935,  3939,  3938,  3949,  3950,  3963,  3984,  4015,
    4016,  4020,  4019,  4028,  4029,  4042,  4063,  4095,  4096,  4099,
    4108,  4111,  4122,  4123,  4126,  4132,  4132,  4138,  4139,  4143,
    4148,  4153,  4158,  4159,  4158,  4167,  4174,  4175,  4173,  4181,
    4182,  4182,  4188,  4189,  4195,  4195,  4197,  4203,  4209,  4215,
    4216,  4219,  4220,  4219,  4224,  4226,  4229,  4231,  4233,  4235,
    4238,  4239,  4243,  4242,  4246,  4245,  4250,  4251,  4253,  4253,
    4255,  4255,  4258,  4262,  4269,  4270,  4273,  4274,  4273,  4282,
    4282,  4290,  4290,  4298,  4304,  4305,  4304,  4310,  4310,  4316,
    4323,  4326,  4333,  4334,  4337,  4343,  4343,  4349,  4350,  4357,
    4358,  4360,  4364,  4365,  4367,  4370,  4371,  4374,  4374,  4380,
    4380,  4386,  4386,  4392,  4392,  4398,  4398,  4404,  4404,  4409,
    4417,  4416,  4420,  4421,  4424,  4429,  4435,  4436,  4439,  4440,
    4442,  4444,  4446,  4448,  4452,  4453,  4456,  4459,  4462,  4465,
    4469,  4473,  4474,  4477,  4477,  4486,  4487,  4490,  4491,  4494,
    4493,  4506,  4506,  4509,  4511,  4513,  4515,  4518,  4520,  4526,
    4527,  4530,  4534,  4535,  4538,  4539,  4538,  4548,  4549,  4551,
    4551,  4555,  4556,  4559,  4570,  4579,  4589,  4591,  4595,  4599,
    4600,  4603,  4612,  4613,  4612,  4632,  4631,  4648,  4649,  4652,
    4678,  4700,  4701,  4704,  4713,  4713,  4732,  4753,  4774,  4792,
    4824,  4825,  4830,  4830,  4848,  4866,  4900,  4936,  4937,  4940,
    4946,  4945,  4971,  4973,  4977,  4981,  4982,  4985,  4993,  4994,
    4993,  5001,  5002,  5005,  5011,  5010,  5023,  5025,  5029,  5033,
    5034,  5037,  5044,  5045,  5044,  5054,  5055,  5054,  5063,  5064,
    5067,  5073,  5072,  5091,  5092,  5094,  5095,  5100,  5119,  5129,
    5130,  5132,  5133,  5138,  5158,  5168,  5178,  5181,  5199,  5203,
    5204,  5207,  5208,  5207,  5218,  5219,  5222,  5227,  5229,  5227,
    5236,  5236,  5242,  5242,  5248,  5248,  5254,  5257,  5258,  5261,
    5267,  5273,  5281,  5281,  5285,  5286,  5289,  5300,  5309,  5320,
    5322,  5339,  5343,  5344,  5348,  5347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QSTRING", "T_STRING", "SITE_PATTERN",
  "NUMBER", "K_HISTORY", "K_NAMESCASESENSITIVE", "K_DESIGN", "K_VIAS",
  "K_TECH", "K_UNITS", "K_ARRAY", "K_FLOORPLAN", "K_SITE", "K_CANPLACE",
  "K_CANNOTOCCUPY", "K_DIEAREA", "K_PINS", "K_DEFAULTCAP", "K_MINPINS",
  "K_WIRECAP", "K_TRACKS", "K_GCELLGRID", "K_DO", "K_BY", "K_STEP",
  "K_LAYER", "K_ROW", "K_RECT", "K_COMPS", "K_COMP_GEN", "K_SOURCE",
  "K_WEIGHT", "K_EEQMASTER", "K_FIXED", "K_COVER", "K_UNPLACED",
  "K_PLACED", "K_FOREIGN", "K_REGION", "K_REGIONS", "K_NETS",
  "K_START_NET", "K_MUSTJOIN", "K_ORIGINAL", "K_USE", "K_STYLE",
  "K_PATTERN", "K_PATTERNNAME", "K_ESTCAP", "K_ROUTED", "K_NEW", "K_SNETS",
  "K_SHAPE", "K_WIDTH", "K_VOLTAGE", "K_SPACING", "K_NONDEFAULTRULE",
  "K_NONDEFAULTRULES", "K_N", "K_S", "K_E", "K_W", "K_FN", "K_FE", "K_FS",
  "K_FW", "K_GROUPS", "K_GROUP", "K_SOFT", "K_MAXX", "K_MAXY",
  "K_MAXHALFPERIMETER", "K_CONSTRAINTS", "K_NET", "K_PATH", "K_SUM",
  "K_DIFF", "K_SCANCHAINS", "K_START", "K_FLOATING", "K_ORDERED", "K_STOP",
  "K_IN", "K_OUT", "K_RISEMIN", "K_RISEMAX", "K_FALLMIN", "K_FALLMAX",
  "K_WIREDLOGIC", "K_MAXDIST", "K_ASSERTIONS", "K_DISTANCE", "K_MICRONS",
  "K_END", "K_IOTIMINGS", "K_RISE", "K_FALL", "K_VARIABLE", "K_SLEWRATE",
  "K_CAPACITANCE", "K_DRIVECELL", "K_FROMPIN", "K_TOPIN", "K_PARALLEL",
  "K_TIMINGDISABLES", "K_THRUPIN", "K_MACRO", "K_PARTITIONS", "K_TURNOFF",
  "K_FROMCLOCKPIN", "K_FROMCOMPPIN", "K_FROMIOPIN", "K_TOCLOCKPIN",
  "K_TOCOMPPIN", "K_TOIOPIN", "K_SETUPRISE", "K_SETUPFALL", "K_HOLDRISE",
  "K_HOLDFALL", "K_VPIN", "K_SUBNET", "K_XTALK", "K_PIN", "K_SYNTHESIZED",
  "K_DEFINE", "K_DEFINES", "K_DEFINEB", "K_IF", "K_THEN", "K_ELSE",
  "K_FALSE", "K_TRUE", "K_EQ", "K_NE", "K_LE", "K_LT", "K_GE", "K_GT",
  "K_OR", "K_AND", "K_NOT", "K_SPECIAL", "K_DIRECTION", "K_RANGE", "K_FPC",
  "K_HORIZONTAL", "K_VERTICAL", "K_ALIGN", "K_MIN", "K_MAX", "K_EQUAL",
  "K_BOTTOMLEFT", "K_TOPRIGHT", "K_ROWS", "K_TAPER", "K_TAPERRULE",
  "K_VERSION", "K_DIVIDERCHAR", "K_BUSBITCHARS", "K_PROPERTYDEFINITIONS",
  "K_STRING", "K_REAL", "K_INTEGER", "K_PROPERTY", "K_BEGINEXT",
  "K_ENDEXT", "K_NAMEMAPSTRING", "K_ON", "K_OFF", "K_X", "K_Y",
  "K_COMPONENT", "K_MASK", "K_MASKSHIFT", "K_COMPSMASKSHIFT", "K_SAMEMASK",
  "K_PINPROPERTIES", "K_TEST", "K_COMMONSCANPINS", "K_SNET",
  "K_COMPONENTPIN", "K_REENTRANTPATHS", "K_SHIELD", "K_SHIELDNET",
  "K_NOSHIELD", "K_VIRTUAL", "K_ANTENNAPINPARTIALMETALAREA",
  "K_ANTENNAPINPARTIALMETALSIDEAREA", "K_ANTENNAPINGATEAREA",
  "K_ANTENNAPINDIFFAREA", "K_ANTENNAPINMAXAREACAR",
  "K_ANTENNAPINMAXSIDEAREACAR", "K_ANTENNAPINPARTIALCUTAREA",
  "K_ANTENNAPINMAXCUTCAR", "K_SIGNAL", "K_POWER", "K_GROUND", "K_CLOCK",
  "K_TIEOFF", "K_ANALOG", "K_SCAN", "K_RESET", "K_RING", "K_STRIPE",
  "K_FOLLOWPIN", "K_IOWIRE", "K_COREWIRE", "K_BLOCKWIRE", "K_FILLWIRE",
  "K_BLOCKAGEWIRE", "K_PADRING", "K_BLOCKRING", "K_BLOCKAGES",
  "K_PLACEMENT", "K_SLOTS", "K_FILLS", "K_PUSHDOWN", "K_NETLIST", "K_DIST",
  "K_USER", "K_TIMING", "K_BALANCED", "K_STEINER", "K_TRUNK",
  "K_FIXEDBUMP", "K_FENCE", "K_FREQUENCY", "K_GUIDE", "K_MAXBITS",
  "K_PARTITION", "K_TYPE", "K_ANTENNAMODEL", "K_DRCFILL", "K_OXIDE1",
  "K_OXIDE2", "K_OXIDE3", "K_OXIDE4", "K_OXIDE5", "K_OXIDE6", "K_OXIDE7",
  "K_OXIDE8", "K_OXIDE9", "K_OXIDE10", "K_OXIDE11", "K_OXIDE12",
  "K_OXIDE13", "K_OXIDE14", "K_OXIDE15", "K_OXIDE16", "K_OXIDE17",
  "K_OXIDE18", "K_OXIDE19", "K_OXIDE20", "K_OXIDE21", "K_OXIDE22",
  "K_OXIDE23", "K_OXIDE24", "K_OXIDE25", "K_OXIDE26", "K_OXIDE27",
  "K_OXIDE28", "K_OXIDE29", "K_OXIDE30", "K_OXIDE31", "K_OXIDE32",
  "K_CUTSIZE", "K_CUTSPACING", "K_DESIGNRULEWIDTH", "K_DIAGWIDTH",
  "K_ENCLOSURE", "K_HALO", "K_GROUNDSENSITIVITY", "K_HARDSPACING",
  "K_LAYERS", "K_MINCUTS", "K_NETEXPR", "K_OFFSET", "K_ORIGIN", "K_ROWCOL",
  "K_STYLES", "K_POLYGON", "K_PORT", "K_SUPPLYSENSITIVITY", "K_VIA",
  "K_VIARULE", "K_WIREEXT", "K_EXCEPTPGNET", "K_FILLWIREOPC", "K_OPC",
  "K_PARTIAL", "K_ROUTEHALO", "';'", "'-'", "'+'", "'('", "')'", "'*'",
  "','", "$accept", "def_file", "version_stmt", "$@1", "case_sens_stmt",
  "rules", "rule", "design_section", "design_name", "$@2", "end_design",
  "tech_name", "$@3", "array_name", "$@4", "floorplan_name", "$@5",
  "history", "prop_def_section", "$@6", "property_defs", "property_def",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "property_type_and_val", "$@16", "$@17", "opt_num_val", "units",
  "divider_char", "bus_bit_chars", "canplace", "$@18", "cannotoccupy",
  "$@19", "orient", "die_area", "$@20", "pin_cap_rule", "start_def_cap",
  "pin_caps", "pin_cap", "end_def_cap", "pin_rule", "start_pins", "pins",
  "pin", "$@21", "$@22", "$@23", "pin_options", "pin_option", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "pin_layer_mask_opt", "pin_via_mask_opt", "pin_poly_mask_opt",
  "pin_layer_spacing_opt", "pin_poly_spacing_opt", "pin_oxide", "use_type",
  "pin_layer_opt", "$@34", "end_pins", "row_rule", "$@35", "$@36",
  "row_do_option", "row_step_option", "row_options", "row_option", "$@37",
  "row_prop_list", "row_prop", "tracks_rule", "$@38", "track_start",
  "track_type", "track_opts", "track_mask_statement", "same_mask",
  "track_layer_statement", "$@39", "track_layers", "track_layer",
  "gcellgrid", "extension_section", "extension_stmt", "via_section", "via",
  "via_declarations", "via_declaration", "$@40", "$@41", "layer_stmts",
  "layer_stmt", "$@42", "$@43", "$@44", "$@45", "$@46", "$@47",
  "layer_viarule_opts", "$@48", "firstPt", "nextPt", "otherPts", "pt",
  "mask", "via_end", "regions_section", "regions_start", "regions_stmts",
  "regions_stmt", "$@49", "$@50", "rect_list", "region_options",
  "region_option", "$@51", "region_prop_list", "region_prop",
  "region_type", "comps_maskShift_section", "comps_section", "start_comps",
  "layer_statement", "maskLayer", "comps_rule", "comp", "comp_start",
  "comp_id_and_name", "$@52", "comp_net_list", "comp_options",
  "comp_option", "comp_extension_stmt", "comp_eeq", "$@53",
  "comp_generate", "$@54", "opt_pattern", "comp_source", "source_type",
  "comp_region", "comp_pnt_list", "comp_halo", "$@55", "halo_soft",
  "comp_routehalo", "$@56", "comp_property", "$@57", "comp_prop_list",
  "comp_prop", "comp_region_start", "comp_foreign", "$@58", "opt_paren",
  "comp_type", "maskShift", "$@59", "placement_status", "weight",
  "end_comps", "nets_section", "start_nets", "net_rules", "one_net",
  "net_and_connections", "net_start", "$@60", "net_name", "$@61", "$@62",
  "net_connections", "net_connection", "$@63", "$@64", "$@65", "conn_opt",
  "net_options", "net_option", "$@66", "$@67", "$@68", "$@69", "$@70",
  "$@71", "$@72", "$@73", "$@74", "$@75", "$@76", "net_prop_list",
  "net_prop", "netsource_type", "vpin_stmt", "$@77", "vpin_begin", "$@78",
  "vpin_layer_opt", "$@79", "vpin_options", "vpin_status", "net_type",
  "paths", "new_path", "$@80", "path", "$@81", "$@82", "virtual_statement",
  "rect_statement", "path_item_list", "path_item", "$@83", "$@84",
  "path_pt", "virtual_pt", "rect_pts", "opt_taper_style_s",
  "opt_taper_style", "opt_taper", "$@85", "opt_style", "opt_spaths",
  "opt_shape_style", "end_nets", "shape_type", "snets_section",
  "snet_rules", "snet_rule", "snet_options", "snet_option",
  "snet_other_option", "$@86", "$@87", "$@88", "$@89", "$@90", "$@91",
  "$@92", "$@93", "$@94", "$@95", "orient_pt", "shield_layer", "$@96",
  "snet_width", "$@97", "snet_voltage", "$@98", "snet_spacing", "$@99",
  "$@100", "snet_prop_list", "snet_prop", "opt_snet_range", "opt_range",
  "pattern_type", "spaths", "snew_path", "$@101", "spath", "$@102",
  "$@103", "width", "start_snets", "end_snets", "groups_section",
  "groups_start", "group_rules", "group_rule", "start_group", "$@104",
  "group_members", "group_member", "group_options", "group_option",
  "$@105", "$@106", "group_region", "group_prop_list", "group_prop",
  "group_soft_options", "group_soft_option", "groups_end",
  "assertions_section", "constraint_section", "assertions_start",
  "constraints_start", "constraint_rules", "constraint_rule",
  "operand_rule", "operand", "$@107", "$@108", "operand_list",
  "wiredlogic_rule", "$@109", "opt_plus", "delay_specs", "delay_spec",
  "constraints_end", "assertions_end", "scanchains_section",
  "scanchain_start", "scanchain_rules", "scan_rule", "start_scan", "$@110",
  "scan_members", "opt_pin", "scan_member", "$@111", "$@112", "$@113",
  "$@114", "$@115", "$@116", "opt_common_pins", "floating_inst_list",
  "one_floating_inst", "$@117", "floating_pins", "ordered_inst_list",
  "one_ordered_inst", "$@118", "ordered_pins", "partition_maxbits",
  "scanchain_end", "iotiming_section", "iotiming_start", "iotiming_rules",
  "iotiming_rule", "start_iotiming", "$@119", "iotiming_members",
  "iotiming_member", "$@120", "$@121", "iotiming_drivecell_opt", "$@122",
  "$@123", "iotiming_frompin", "$@124", "iotiming_parallel", "risefall",
  "iotiming_end", "floorplan_contraints_section", "fp_start", "fp_stmts",
  "fp_stmt", "$@125", "$@126", "h_or_v", "constraint_type",
  "constrain_what_list", "constrain_what", "$@127", "$@128",
  "row_or_comp_list", "row_or_comp", "$@129", "$@130",
  "timingdisables_section", "timingdisables_start", "timingdisables_rules",
  "timingdisables_rule", "$@131", "$@132", "$@133", "$@134",
  "td_macro_option", "$@135", "$@136", "$@137", "timingdisables_end",
  "partitions_section", "partitions_start", "partition_rules",
  "partition_rule", "start_partition", "$@138", "turnoff", "turnoff_setup",
  "turnoff_hold", "partition_members", "partition_member", "$@139",
  "$@140", "$@141", "$@142", "$@143", "$@144", "minmaxpins", "$@145",
  "min_or_max_list", "min_or_max_member", "pin_list",
  "risefallminmax1_list", "risefallminmax1", "risefallminmax2_list",
  "risefallminmax2", "partitions_end", "comp_names", "comp_name", "$@146",
  "subnet_opt_syn", "subnet_options", "subnet_option", "$@147", "$@148",
  "subnet_type", "pin_props_section", "begin_pin_props", "opt_semi",
  "end_pin_props", "pin_prop_list", "pin_prop_terminal", "$@149", "$@150",
  "pin_prop_options", "pin_prop", "$@151", "pin_prop_name_value_list",
  "pin_prop_name_value", "blockage_section", "blockage_start",
  "blockage_end", "blockage_defs", "blockage_def", "blockage_rule",
  "$@152", "$@153", "$@154", "layer_blockage_rules", "layer_blockage_rule",
  "mask_blockage_rule", "comp_blockage_rule", "$@155",
  "placement_comp_rules", "placement_comp_rule", "$@156",
  "rectPoly_blockage_rules", "rectPoly_blockage", "$@157", "slot_section",
  "slot_start", "slot_end", "slot_defs", "slot_def", "slot_rule", "$@158",
  "$@159", "geom_slot_rules", "geom_slot", "$@160", "fill_section",
  "fill_start", "fill_end", "fill_defs", "fill_def", "$@161", "$@162",
  "fill_rule", "$@163", "$@164", "geom_fill_rules", "geom_fill", "$@165",
  "fill_layer_mask_opc_opt", "opt_mask_opc_l", "fill_layer_opc",
  "fill_via_pt", "fill_via_mask_opc_opt", "opt_mask_opc", "fill_via_opc",
  "fill_mask", "fill_viaMask", "nondefaultrule_section",
  "nondefault_start", "nondefault_end", "nondefault_defs",
  "nondefault_def", "$@166", "$@167", "nondefault_options",
  "nondefault_option", "$@168", "$@169", "$@170", "$@171", "$@172",
  "nondefault_layer_options", "nondefault_layer_option",
  "nondefault_prop_opt", "$@173", "nondefault_prop_list",
  "nondefault_prop", "styles_section", "styles_start", "styles_end",
  "styles_rules", "styles_rule", "$@174", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,    59,    45,    43,    40,    41,    42,
      44
};
# endif

#define YYPACT_NINF (-1192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-572)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -98, -1192,    81,   102,   110, -1192,   201,    82,  -150,  -142,
    -111, -1192,   394, -1192, -1192, -1192, -1192, -1192,   180, -1192,
     108, -1192, -1192, -1192, -1192, -1192,   244,   252,   213,   213,
   -1192,   257,   260,   272,   275,   300,   326,   342,   349,   353,
     216,   396,   403,   421,   425,   431,   435, -1192, -1192, -1192,
     440,   445,   450,   461,   469, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192,   483, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192,   -40, -1192, -1192,   493,    -8,
     508,   427,   528,   535,   555,   565,   278,   306, -1192, -1192,
   -1192, -1192,   582,   590,   307,   310,   311,   312,   313,   314,
     320,   321,   322, -1192,   324,   325,   327,   328,   329,   330,
   -1192,    35,   332,   339,   340,   344,   346,    47,   -49, -1192,
     -48,   -47,   -33,   -31,   -30,   -26,   -25,   -22,   -21,   -19,
     -11,   -10,    -6,     1,    36,    44,    50, -1192, -1192,    51,
     347, -1192,   352,   614,   363,   364,   625,   630,    11,   278,
   -1192, -1192,   623,   655, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   601,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   656,
     641, -1192, -1192,   644, -1192, -1192, -1192,   639,   659, -1192,
   -1192, -1192,   628, -1192, -1192,   634, -1192, -1192, -1192, -1192,
   -1192,   629, -1192, -1192, -1192, -1192, -1192,   619, -1192, -1192,
   -1192,   605, -1192, -1192, -1192, -1192,   585,   284, -1192, -1192,
   -1192, -1192,   600, -1192,   607, -1192, -1192, -1192, -1192,   591,
     393, -1192, -1192, -1192,   545, -1192, -1192,   586,   249, -1192,
   -1192,   584, -1192, -1192, -1192, -1192,   516, -1192, -1192, -1192,
     481,    41, -1192, -1192,    10,   489,   679, -1192, -1192, -1192,
     490,    17, -1192, -1192, -1192,   705,    52,   439,   672, -1192,
   -1192, -1192, -1192,   428, -1192, -1192,   717,   719,    13,    14,
   -1192, -1192,   720,   721,   434, -1192, -1192, -1192, -1192, -1192,
   -1192,   567, -1192, -1192, -1192, -1192,   710, -1192, -1192,   730,
     729, -1192,   732, -1192,   733, -1192,   735,  -128,     9, -1192,
      84,  -114, -1192,   -95, -1192,   736,   737, -1192, -1192, -1192,
     446,   447, -1192, -1192, -1192, -1192,   738,    60, -1192, -1192,
      88, -1192,   742, -1192, -1192, -1192, -1192,   453, -1192,   753,
     151, -1192,   754, -1192, -1192, -1192,   278, -1192, -1192, -1192,
   -1192,   -15, -1192, -1192, -1192,   -12, -1192,   699, -1192, -1192,
   -1192,   756, -1192,   637,   637,   465,   466,   470,   472,  -182,
     740,   766, -1192,   770,   772,   773,   774,   776,   777, -1192,
     778,   821,   822,   824,   464,   800, -1192, -1192,   827, -1192,
      18, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,    19, -1192, -1192, -1192,   278, -1192, -1192, -1192, -1192,
     531, -1192, -1192,   544, -1192, -1192, -1192,   804, -1192,   462,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   170,
     829,   830,   162,   162,   831,   227, -1192, -1192,   268, -1192,
   -1192,   832, -1192,   121, -1192, -1192,   267,   833,   835,   836,
   -1192,   731, -1192,   283, -1192, -1192,   837,   839, -1192,   278,
     278,     4,   840,   278, -1192, -1192, -1192,   841,   842,   278,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192,   823,   825, -1192, -1192, -1192, -1192,
   -1192, -1192,   843,   637,    53,    53,    53,    53,    53,    53,
      53,    53,    53,   553,   775,   846, -1192,   278, -1192, -1192,
     158,   847, -1192, -1192, -1192,   278, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192,   848, -1192,   278,   278,   637, -1192,   851,
    -100,   850, -1192, -1192, -1192,   515,   852,   -13,   853, -1192,
   -1192, -1192, -1192,   854, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,   278, -1192,   158,   855, -1192,   515,   856,   -13,   857,
     337, -1192, -1192, -1192, -1192,   858, -1192, -1192,   859, -1192,
   -1192,   862, -1192,     5, -1192, -1192, -1192,   864, -1192,    40,
     130,   561, -1192,   354, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,   865, -1192, -1192,   866, -1192,    58, -1192, -1192, -1192,
     867,   869,    33,   375, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192,   574, -1192,   278, -1192, -1192, -1192,   278,
     278, -1192, -1192,   278,   278,   235,   278,   868,   870,   581,
   -1192,   874, -1192, -1192,   875,   587,   589,   592,   594,   595,
     596,   597,   598,   599, -1192, -1192,   707,   270,   278,   278,
     876, -1192, -1192, -1192, -1192, -1192, -1192,   880,   637,   881,
     890,   892,   826, -1192, -1192,   278, -1192,   602, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192,   894, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192,   896,   897,   898, -1192,   899,   900, -1192,
     901,   902,   904,   278,   906, -1192, -1192,   907, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192,   908,   909,   910,   911, -1192,
     912, -1192,   913,   914,   915, -1192, -1192, -1192,   916, -1192,
     162, -1192, -1192, -1192,   813,   917,   918,   919,   920,   923,
   -1192, -1192,   924,   624,   925,   632, -1192,   927,   926,   928,
     309,   817,   642, -1192, -1192,   643, -1192, -1192,   386,   929,
     931,   934,   935,   936,   937, -1192, -1192,    -9, -1192,   278,
      37, -1192,   278, -1192, -1192, -1192,   278, -1192,    15, -1192,
   -1192,   278,   921,   922, -1192,   930, -1192,   796,   796, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   939,
     938,   651,   932, -1192,    54, -1192, -1192, -1192, -1192,   278,
     271,   942, -1192, -1192,    20,   187,   890, -1192, -1192, -1192,
     943,   946, -1192,     8, -1192,   947, -1192, -1192, -1192, -1192,
     224,   899, -1192, -1192,   902, -1192, -1192,   903, -1192, -1192,
   -1192,   278, -1192,   951, -1192,   952,   248,   911, -1192, -1192,
   -1192,   688, -1192,   933, -1192,    21,   294, -1192,   948, -1192,
     953, -1192, -1192, -1192, -1192,   949,   957,   958,   949,   959,
   -1192,   734, -1192, -1192,   960,   962, -1192,   963,   964,   965,
   -1192, -1192, -1192,   968,   969, -1192, -1192, -1192, -1192,   970,
     971, -1192,   972,   973, -1192,   274,   668, -1192, -1192, -1192,
     974, -1192, -1192,   278,   -16,   219,   278, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192,   975,   976,   977, -1192,   978,   979,
     979, -1192,   801, -1192, -1192, -1192, -1192, -1192, -1192,   981,
     982,   983, -1192, -1192, -1192, -1192,   -59, -1192, -1192, -1192,
     984, -1192,   637, -1192, -1192, -1192, -1192,   985,   988, -1192,
   -1192, -1192,   680, -1192, -1192, -1192, -1192, -1192,   903, -1192,
   -1192, -1192,   383,   278, -1192, -1192, -1192, -1192, -1192, -1192,
     989,   278, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,   990, -1192, -1192, -1192,   278, -1192,   991,   992,   993,
   -1192,   996, -1192,   700, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,   997,   998, -1192,   891, -1192, -1192, -1192, -1192, -1192,
     280,   999,   940, -1192,   437,   390,   438,   437,   390,   438,
   -1192,   845, -1192,   -14, -1192, -1192, -1192,  1001, -1192,   278,
   -1192,  -103, -1192, -1192, -1192, -1192,   -96, -1192,   708, -1192,
   -1192, -1192, -1192,  1002, -1192,  1003,  1004,  1005,  -141,   986,
     987,   994,   288,  1006, -1192, -1192, -1192, -1192, -1192, -1192,
    1011,  1013,  1014,  1015,  1016,  1017,  1018,  1021,  1022, -1192,
     196, -1192, -1192,  1023, -1192,  1024,  1026,  1027, -1192,   724,
      39,   902, -1192, -1192, -1192, -1192,   278, -1192,   886, -1192,
     915,   278,   278, -1192, -1192,   915, -1192, -1192, -1192, -1192,
     449, -1192, -1192,   739,   741,   743, -1192, -1192, -1192,   941,
   -1192,   398, -1192,  1029, -1192, -1192,  1028,  1031,  1033,  1034,
     390, -1192,  1036,  1037,  1038,  1041, -1192, -1192,   390, -1192,
    1042, -1192,  1043, -1192, -1192, -1192,  1044, -1192, -1192,   278,
    1045, -1192,  1046, -1192,   278, -1192,   278,  1000,  1049,  1048,
   -1192, -1192, -1192,  1051,  1053,  1054, -1192,   861, -1192, -1192,
     289, -1192,  1011,   759, -1192, -1192,  1055, -1192, -1192,   759,
     767, -1192, -1192, -1192, -1192,  1056,   768,   768,   768, -1192,
   -1192, -1192,  1059, -1192, -1192,    22, -1192, -1192, -1192, -1192,
   -1192,   637,  1060, -1192,   933,   278, -1192,   290, -1192, -1192,
   -1192, -1192,  1063, -1192,  1064, -1192,   779,  1065, -1192, -1192,
   -1192,   780,  1066, -1192,    63,  1067,  1069,  1071,  1072, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192,  1068, -1192, -1192,
   -1192, -1192,  1073,   467, -1192, -1192,  1074,  1075,  1008, -1192,
   -1192,   198, -1192, -1192,   278, -1192,  1011,   944,   278,  1076,
   -1192,   803,  1080, -1192,   -18, -1192,   787,   788,   789,  1084,
     118, -1192,  1085,    23,    24, -1192, -1192,  1086, -1192,   278,
      79, -1192, -1192,  1087,  1089,  1090, -1192,  1091, -1192, -1192,
   -1192, -1192, -1192,  1092,  1093, -1192, -1192, -1192, -1192, -1192,
    1096, -1192, -1192, -1192, -1192, -1192,   802,   807,  1097, -1192,
   -1192, -1192,   515, -1192,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,   549, -1192,  1094, -1192, -1192, -1192, -1192,
     637, -1192,  1107,   278, -1192,   278,  1108,   482, -1192, -1192,
   -1192, -1192, -1192,  1111, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192,    16,    29,    30,    32,    12, -1192,   278,  1110,
     337, -1192,   792,   806,  1113, -1192,   828,   828, -1192,  1112,
    1114,   499, -1192, -1192, -1192, -1192,  1115,  1118,  1119, -1192,
   -1192,  1109,  1109,  1109,  1109,  1116,  1117,  1109,  1120, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192,  1122, -1192,  1123,  1124,  1125, -1192, -1192, -1192,
     278,  1126, -1192, -1192, -1192,   834,  1127,   902,   838, -1192,
     844, -1192,   849, -1192,   860, -1192,   588,   863,  1128,   872,
   -1192, -1192, -1192, -1192, -1192, -1192,    12,   873,   877,   878,
    1032,    42, -1192,  1129, -1192, -1192, -1192, -1192, -1192,     6,
   -1192,   554, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192,   966,   278,   871,  1009,
     879, -1192,   903, -1192, -1192, -1192, -1192,  1133,  1121,  1134,
   -1192,   105,    25, -1192,  1139,  1145, -1192,  1144, -1192, -1192,
   -1192, -1192,  1146,  1147,  1148, -1192, -1192, -1192, -1192,   980,
    1152,  1153,  1155,  1157,  1007,  1156,   882, -1192,   887, -1192,
   -1192,  1138,  1159,  1160,   618, -1192,   883,    26,    27,  1169,
    1171, -1192,  1174,  1177, -1192, -1192, -1192,  1178,   -17, -1192,
   -1192, -1192, -1192,  1179,     2, -1192,  1180,   278, -1192,  1181,
    1162,  1183,  1184,  1158,   895, -1192,   893,   905,   945,   950,
     954,   955,   956,   961, -1192,  1187,  1188,   278, -1192,  1189,
    1190,   278,  1191,  1194,  1172,  1195,  1196,  1182,  1198,  1199,
   -1192, -1192, -1192, -1192,   967,   995, -1192, -1192, -1192, -1192,
     278, -1192, -1192,   278,  1010,  1202,  1201,  1173,  1012,  1203,
    1185,  1204,  1208,  1209, -1192,   278, -1192,  1210,  1211,  1212,
   -1192,  1192,  1214,  1215,  1218,  1219, -1192,  1019, -1192,  1220,
    1221,  1197,  1222,  1020,  1025,   278,  1030, -1192,  1223,  1224,
    1035, -1192, -1192,  1225, -1192,  1226, -1192,  1227, -1192,  1039,
    1040,  1228,  1229,  1230,  1231, -1192
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,     4,     0,     6,     0,     1,     0,     0,     0,     0,
       0,    11,     0,     5,     7,     8,    60,    51,     0,    54,
       0,    56,    58,    96,    98,   108,     0,     0,     0,     0,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,   246,   309,
       0,     0,     0,     0,     0,    10,    12,    38,     2,    48,
      34,    41,    43,    46,    50,    40,    35,    36,    37,    39,
      44,   112,    45,   118,    47,    49,     0,    42,    17,    33,
     250,    27,   287,    19,    15,   312,    23,   381,    30,   523,
      21,   605,    13,    16,   638,   638,    28,   666,    22,   712,
      20,   739,    32,   764,    25,   782,    26,   852,    14,   869,
      29,   905,    18,   919,    24,     0,    31,   982,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   232,
     233,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
      63,     0,   849,     0,     0,     0,     0,     0,     0,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   951,   949,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     274,   117,     0,     0,   308,   286,   380,   601,   947,   604,
     637,   665,   636,   711,   763,   781,   738,    94,    95,     0,
     311,   306,   310,   850,   848,   867,   903,   917,   980,     0,
       0,   113,   110,     0,   120,   119,   116,     0,     0,   252,
     251,   248,     0,   289,   288,     0,   316,   313,   321,   318,
     307,     0,   385,   382,   402,   384,   379,     0,   526,   524,
     522,     0,   608,   606,   610,   603,     0,     0,   639,   640,
     641,   634,     0,   635,     0,   669,   667,   671,   664,     0,
       0,   713,   717,   710,     0,   741,   740,     0,     0,   765,
     762,     0,   785,   783,   795,   780,     0,   854,   847,   853,
       0,     0,   866,   870,     0,     0,     0,   902,   906,   911,
       0,     0,   916,   920,   928,     0,     0,     0,     0,   979,
     983,    52,    55,     0,    57,    59,     0,     0,     0,     0,
     276,   275,     0,     0,     0,    65,    77,    71,    81,    73,
      67,     0,    75,    69,    79,    64,     0,   115,   212,     0,
       0,   284,     0,   285,     0,   378,     0,     0,   315,   509,
       0,     0,   602,     0,   633,     0,   613,   663,   643,   645,
       0,     0,   652,   656,   662,   709,     0,     0,   736,   715,
       0,   737,     0,   779,   766,   769,   771,     0,   830,     0,
       0,   851,     0,   868,   872,   875,     0,   900,   897,   904,
     908,     0,   918,   925,   922,     0,   952,     0,   946,   950,
     981,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,   253,   290,     0,   314,
       0,   335,   322,   334,   330,   323,   324,   329,   331,   332,
     333,     0,   328,   325,   327,     0,   326,   320,   319,   387,
       0,   386,   383,     0,   432,   403,   420,   447,   525,     0,
     560,   527,   531,   528,   529,   530,   609,   612,   611,     0,
       0,     0,     0,     0,     0,     0,   670,   668,     0,   687,
     672,     0,   714,     0,   725,   718,     0,     0,     0,     0,
     773,   787,   784,     0,   809,   796,     0,     0,   890,     0,
       0,     0,     0,     0,   914,   907,   912,     0,     0,     0,
     931,   921,   929,   954,   948,   984,   100,   102,   103,   101,
     104,   107,   106,   105,     0,     0,   278,   280,   279,   281,
     109,   277,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,   317,   338,
       0,     0,   336,   374,   375,   370,   376,   365,   364,   357,
     247,   372,   351,     0,   348,     0,   347,     0,   391,     0,
       0,     0,   455,   456,   410,     0,     0,     0,     0,   457,
     418,   445,   426,     0,   430,   421,   423,   407,   408,   404,
     448,     0,   543,     0,     0,   551,     0,     0,     0,     0,
       0,   573,   575,   577,   558,     0,   535,   549,     0,   540,
     545,   532,   607,     0,   620,   614,   644,     0,   649,     0,
       0,   654,   642,     0,   657,   675,   677,   679,   681,   683,
     685,     0,   734,   735,     0,   722,     0,   744,   745,   742,
       0,     0,     0,   789,   786,   797,   799,   801,   803,   805,
     807,   855,   873,   876,   899,     0,   871,   898,   909,     0,
       0,   926,   923,     0,     0,     0,     0,     0,     0,     0,
     214,    88,    86,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   121,   235,     0,     0,   294,
       0,   343,   344,   345,   346,   342,   377,     0,     0,     0,
       0,     0,   353,   355,   349,     0,   369,   388,   389,   442,
     438,   439,   440,   441,   406,   413,     0,   201,   202,   203,
     204,   205,   206,   207,   208,   416,   417,   592,   589,   590,
     591,   412,   415,     0,     0,     0,   414,     0,     0,   424,
       0,     0,     0,     0,     0,   548,   554,     0,   556,   557,
     553,   555,   510,   511,   512,   513,   514,   515,   516,   519,
     520,   521,   518,   517,   538,     0,     0,     0,     0,   539,
       0,   550,     0,     0,     0,   618,   628,   616,     0,   647,
       0,   650,   648,   655,     0,     0,     0,     0,     0,     0,
     691,   699,     0,   688,     0,     0,   721,     0,     0,     0,
       0,     0,     0,   774,   777,     0,   790,   791,   792,     0,
       0,     0,     0,     0,     0,   857,   877,     0,   891,     0,
       0,   913,     0,   933,   939,   930,     0,   953,     0,   955,
     966,     0,     0,     0,   245,   216,    89,   587,   587,    90,
      66,    78,    72,    82,    74,    68,    76,    70,    80,     0,
       0,     0,   239,   254,     0,   268,   256,   267,   292,     0,
       0,   340,   337,   371,     0,     0,   358,   359,   373,   354,
       0,     0,   350,     0,   392,     0,   411,   419,   446,   427,
       0,   431,   433,   422,     0,   409,   462,   405,   458,   449,
     443,     0,   552,     0,   576,     0,     0,   559,   580,   536,
     541,   561,   597,   534,   593,     0,   615,   623,     0,   651,
       0,   658,   659,   660,   661,   673,   678,   680,   673,     0,
     684,   707,   716,   723,     0,     0,   746,     0,     0,     0,
     750,   767,   770,     0,     0,   772,   793,   794,   788,     0,
       0,   818,     0,     0,   818,     0,   874,   895,   892,   894,
       0,   276,   910,     0,     0,     0,     0,   957,   972,   956,
     964,   960,   962,   276,     0,     0,     0,   220,     0,    91,
      91,   122,   237,   230,   240,   234,   257,   272,   262,     0,
       0,     0,   259,   264,   293,   291,     0,   295,   341,   339,
       0,   367,     0,   362,   363,   361,   360,     0,     0,   393,
     397,   395,     0,   831,   436,   437,   435,   434,   425,   497,
     460,   459,   450,     0,   574,   578,   583,   584,   582,   581,
     570,     0,   562,   564,   565,   563,   566,   569,   568,   567,
     546,     0,   595,   594,   622,     0,   619,     0,     0,     0,
     629,   617,   646,     0,   674,   676,   693,   692,   701,   700,
     682,     0,     0,   686,   729,   719,   720,   748,   747,   749,
       0,     0,     0,   778,     0,     0,   802,     0,     0,   808,
     856,     0,   858,     0,   878,   881,   882,     0,   896,   901,
     276,     0,   927,   934,   935,   936,     0,   276,     0,   940,
     941,   942,   276,     0,   974,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    87,    85,   124,   238,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,   368,   366,     0,   356,     0,     0,     0,   390,   428,
       0,     0,   453,   454,   452,   444,     0,   544,   585,   537,
       0,     0,     0,   600,   505,     0,   621,   630,   631,   632,
       0,   624,   653,   695,   703,     0,   708,   730,   724,     0,
     743,     0,   751,     0,   775,   812,     0,     0,     0,     0,
     800,   824,     0,     0,     0,     0,   819,   812,   806,   859,
       0,   884,     0,   886,   887,   888,     0,   889,   893,   915,
       0,   937,     0,   943,   938,   924,   932,     0,   973,     0,
     961,   963,   985,     0,     0,     0,   215,     0,   221,   588,
       0,   244,   242,   282,   273,   263,     0,   270,   269,   282,
       0,   299,   304,   305,   298,     0,   399,   399,   399,   833,
     837,   832,     0,   501,   502,     0,   463,   498,   500,   499,
     461,     0,     0,   579,   572,     0,   276,     0,   596,   626,
     627,   625,     0,   694,     0,   702,   689,     0,   726,   752,
     754,     0,     0,   798,     0,     0,     0,     0,     0,   825,
     820,   822,   821,   823,   804,   861,   879,     0,   883,   880,
     944,   945,     0,     0,   975,   965,     0,     0,   218,   222,
     123,     0,   125,   127,     0,   241,   242,     0,     0,     0,
     260,     0,   297,   352,     0,   400,     0,     0,     0,     0,
     429,   504,     0,     0,     0,   467,   451,     0,   276,   547,
       0,   598,   506,     0,     0,     0,   731,     0,   756,   756,
     768,   776,   810,     0,     0,   813,   826,   828,   827,   829,
     860,   885,   958,   977,   978,   976,     0,     0,     0,   217,
     224,   136,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,   139,   135,   130,   142,
       0,   243,     0,     0,   271,     0,     0,     0,   300,   401,
     394,   398,   396,     0,   843,   844,   845,   841,   846,   838,
     839,   503,     0,     0,     0,     0,   464,   586,   542,     0,
       0,   467,     0,     0,     0,   727,   753,   755,   816,     0,
       0,     0,   862,   967,    97,    99,     0,   223,     0,   134,
     128,   209,   209,   209,   209,     0,     0,   209,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   156,     0,   129,     0,     0,     0,   144,   283,   258,
       0,     0,   302,   303,   301,   835,     0,     0,     0,   484,
       0,   486,     0,   485,     0,   487,   469,     0,     0,     0,
     477,   478,   468,   483,   508,   507,   599,   696,   704,     0,
     732,     0,   757,   811,   814,   815,   864,   865,   863,   959,
     219,     0,   225,   137,   210,   145,   146,   147,   148,   149,
     151,   153,   154,   133,   140,   131,   159,     0,     0,     0,
       0,   842,   840,   488,   490,   489,   491,     0,   471,     0,
     466,   481,     0,   465,     0,     0,   690,     0,   728,   760,
     758,   817,     0,     0,     0,   968,   227,   228,   226,   157,
       0,     0,     0,     0,   161,     0,     0,   276,     0,   836,
     834,     0,     0,     0,   470,   479,     0,     0,     0,     0,
       0,   733,     0,     0,   970,   969,   971,     0,   163,   211,
     150,   152,   155,     0,   166,   160,     0,   261,   265,     0,
       0,     0,     0,   472,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,   158,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     492,   494,   493,   495,   697,   705,   761,   759,   164,   165,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,   143,     0,     0,     0,
     496,     0,     0,     0,     0,     0,   276,     0,   474,     0,
       0,     0,     0,     0,     0,   141,     0,   475,     0,     0,
       0,   698,   706,     0,   473,     0,   480,     0,   476,     0,
       0,     0,     0,     0,     0,   266
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,   282, -1192, -1192,   181, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192,  -403, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192,  -591, -1191, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192,  1186, -1192, -1192, -1192, -1192, -1192,   -80,   115,
   -1192, -1192,  -343, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,  -497,
    -187,  -942,  -126,    31, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   645, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   373,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192,    34, -1192, -1192,
   -1192, -1192, -1192, -1192,  1077, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192,  -630, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
     359, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
     783,  -878, -1192, -1192,   114, -1192, -1192, -1192, -1192,  -155,
   -1192, -1192, -1192, -1119, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192,  -149, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192,   358, -1192,   418,   660,   117, -1192, -1192,   116,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192,  1165, -1192, -1192,
    -250, -1192, -1192,   790, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,   348, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192,  -891, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192,   -67, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,    90, -1192, -1192, -1192, -1192,   331, -1192,   197, -1039,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192,   769, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192,   448, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192,   315, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
    1047, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192, -1192,
   -1192, -1192
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     7,    12,    55,    56,    57,   118,
      58,    59,   120,    60,   122,    61,   123,    62,    63,   150,
     209,   335,   413,   418,   421,   415,   417,   420,   414,   422,
     416,   675,   838,   837,  1105,    64,    65,    66,    67,   124,
      68,   125,   524,    69,   126,    70,    71,   157,   221,   222,
      72,    73,   158,   225,   339,   849,  1107,  1210,  1292,  1465,
    1462,  1418,  1559,  1464,  1564,  1466,  1561,  1562,  1563,  1588,
    1566,  1594,  1617,  1621,  1461,   725,  1515,  1560,   226,    74,
     133,   835,   967,  1349,  1102,  1208,  1350,  1417,  1512,    75,
     227,    76,   131,   851,   852,  1109,   975,  1110,  1295,  1296,
      77,    78,  1305,    79,    80,   160,   230,   342,   546,   687,
     856,  1111,  1117,  1375,  1113,  1118,  1623,   857,  1112,   189,
     531,   409,   321,  1298,   231,    81,    82,   161,   234,   344,
     547,   689,   860,   987,  1221,  1302,  1378,  1224,    83,    84,
      85,   151,   212,   162,   237,   238,   239,   346,   348,   347,
     432,   433,   434,   697,   435,   690,   989,   436,   695,   437,
     566,   438,   702,   870,   439,   871,   440,   700,   866,   867,
     441,   442,   699,   992,   443,   444,   701,   445,   446,   240,
      86,    87,   163,   243,   244,   245,   350,   451,   568,   875,
     707,   874,  1125,  1127,  1126,  1306,   351,   455,   741,   740,
     716,   733,   738,   739,   884,   735,  1003,  1230,   737,   881,
     882,   714,   456,  1012,   457,   734,   591,   742,  1135,  1136,
     589,   887,  1011,  1131,   888,  1009,  1315,  1490,  1491,  1396,
    1492,  1604,  1576,  1493,  1543,  1540,  1130,  1237,  1238,  1312,
    1239,  1247,  1322,   246,   764,    88,   164,   249,   353,   461,
     462,   774,   770,  1020,   772,  1021,   744,   773,  1142,   747,
     768,  1030,  1139,  1140,   463,   765,   464,   766,   465,   767,
    1138,   897,   898,  1243,   969,   731,   903,  1033,  1145,   904,
    1031,  1401,  1144,    89,   250,    90,    91,   165,   253,   254,
     355,   356,   468,   469,   615,   907,   905,  1036,  1041,  1151,
     906,  1040,   255,    92,    93,    94,    95,   166,   258,   259,
     618,   470,   471,   619,   260,   474,   784,   475,   624,   263,
     261,    96,    97,   168,   266,   267,   366,   367,  1045,   480,
     789,   790,   791,   792,   793,   794,   920,   916,  1047,  1153,
    1253,   917,  1049,  1154,  1255,  1053,   268,    98,    99,   169,
     271,   272,   481,   370,   485,   797,  1054,  1158,  1327,  1500,
    1159,  1257,  1548,   636,   273,   100,   101,   170,   276,   372,
     800,   639,   930,  1060,  1162,  1328,  1329,  1406,  1502,  1583,
    1582,   102,   103,   171,   279,   487,  1061,   488,   489,   805,
     933,  1262,   934,   280,   104,   105,   172,   283,   284,   379,
     644,   808,   938,   380,   495,   809,   810,   811,   812,   813,
     814,  1263,  1408,  1264,  1335,  1503,  1066,  1176,  1170,  1171,
     285,  1129,  1231,  1309,  1530,  1310,  1389,  1477,  1476,  1390,
     106,   107,   214,   288,   173,   289,   382,   815,   945,  1072,
    1275,  1340,  1412,   108,   109,   292,   174,   293,   294,   497,
     816,   498,   946,  1074,  1075,  1076,  1277,   653,   818,  1077,
     501,   388,   500,   110,   111,   297,   175,   298,   299,   502,
     820,   391,   506,   660,   112,   113,   302,   176,   303,   508,
     824,   304,   507,   823,   395,   512,   664,   954,  1083,  1084,
    1088,   955,  1089,  1090,  1085,  1091,   114,   115,   398,   306,
     178,   305,   513,   665,   829,  1093,  1413,  1096,  1097,  1095,
    1509,  1555,   830,  1094,  1198,  1284,   116,   117,   309,   179,
     310,   666
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     190,   525,   320,   655,   431,   748,  1008,   363,   454,  1079,
     460,  1236,   999,   447,   509,   503,  1486,   318,   509,   405,
     407,  1098,  1478,   564,   479,  1034,   990,   484,  1313,  1392,
    1394,  1577,  1606,  1608,   386,  1480,  1482,   494,  1484,   210,
     386,  1615,  1487,   957,  1180,   393,   775,   223,   228,   232,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
    1619,     1,   947,   235,  1552,   241,   247,   503,   219,   384,
     251,   256,  1190,  1549,   262,   264,   776,   269,   727,  1192,
     709,     5,  1332,    11,   976,   274,   277,  1232,   449,    -9,
     281,    -9,    -9,    -9,    -9,    -9,    -9,   286,    -9,    -9,
      -9,    -9,    -9,   977,   978,    -9,    -9,  1119,  1379,  1574,
       6,    -9,   530,    -9,     8,   188,   358,   359,   360,   361,
     710,   711,   712,   713,    -9,    -9,   614,  1399,  1321,   450,
     670,  1269,   290,  1000,  1400,  1575,    -9,   803,  1189,  1269,
     295,   804,    -9,   220,    13,  1194,   300,   307,   397,   560,
    1196,    -9,    14,  1202,  1384,  1385,   188,    -9,   798,   799,
    1181,  1182,    -9,   822,   706,   948,   429,   826,   430,   831,
    1386,   777,   560,  1165,  1120,    -9,  1177,  1387,    -9,    -9,
     452,   958,   453,    15,   559,   560,   119,  1488,  1191,    -9,
     993,   994,    -9,   995,   561,  1193,  1233,  1234,  1550,   458,
    1489,   459,   121,  1183,  1184,  1185,   358,   359,   360,   361,
     949,   728,   729,   730,  1333,  1334,   671,   672,   673,   632,
     633,   560,   674,   634,   635,   143,  1351,  1004,  1005,    -9,
    1006,  1516,  1517,  1518,   553,   554,  1521,   556,   358,   359,
     360,   361,    -9,    -9,    -9,  1352,   224,   229,   233,    -9,
     127,  1016,  1017,  1616,  1018,   177,  1186,   385,   128,    -9,
     499,    -9,   236,   134,   242,   242,   135,   510,   504,   252,
     257,   510,  1620,   257,   265,  1187,   270,  1553,   136,   505,
    1081,   137,   511,   950,   275,   278,   181,   387,   560,   282,
     959,   562,   960,   387,  1554,   863,   287,    -9,   656,    -9,
      -9,   961,   962,   394,  1319,  1388,   138,  1001,   448,  1235,
     319,   563,   406,   408,  1479,   565,   188,   188,   188,   567,
     504,  1314,  1393,  1395,  1578,  1607,  1609,  1481,  1483,   211,
    1485,   291,   139,   979,   980,   981,  1235,   982,   779,   296,
     780,   983,  1353,  1354,   855,   301,   308,   177,   140,   625,
     626,   627,   628,   374,   477,   141,   478,   375,   376,   142,
     358,   359,   360,   361,    -9,   560,  1037,  1038,  1039,   781,
     781,     9,    10,   654,   190,   362,  1398,   659,   691,   692,
     693,   694,   482,   663,   483,   129,   130,  1355,  1356,  1357,
    1358,  1359,  1360,  1361,  1362,   645,   646,   647,   648,   649,
     650,    16,   144,    17,    18,    19,    20,    21,    22,   145,
      23,    24,    25,    26,    27,   637,   638,    28,    29,  1132,
    1133,   688,  1134,    30,  1222,    31,  1223,   146,   782,   698,
     780,   147,  1363,   377,   148,   560,    32,    33,   149,   704,
     705,   785,   786,   787,   788,   492,   152,   493,    34,   629,
     560,   153,  1249,  1250,    35,  1251,   154,  1605,  1087,   926,
     927,   928,   929,    36,   612,   743,   613,   155,   819,    37,
    1343,  1344,  1364,  1345,    38,   156,  1365,  1166,  1167,  1168,
    1169,  1366,  1367,  1368,  1369,  1472,  1473,    39,  1474,   159,
      40,    41,   592,   806,   807,   593,   594,   180,   572,   573,
     630,    42,  1506,  1507,    43,  1508,   936,   937,   595,   596,
     597,   598,   182,   599,   579,  1086,   188,   600,   601,   602,
     603,   622,   183,   623,  1141,  1172,  1173,  1174,  1175,   827,
     909,   828,   184,   821,   190,   632,   633,   825,   190,   185,
     190,    44,   752,   753,   754,   755,   756,   757,   758,   759,
     760,   761,  1259,  1260,    45,    46,    47,  1556,  1557,   186,
    1558,    48,   858,   859,   853,   985,   854,   986,  1070,   187,
    1071,    49,   762,    50,  1160,   188,  1161,   570,   571,   872,
     572,   573,  1206,  1290,  1207,  1291,  1320,  1235,   192,  1122,
     574,   575,   576,   577,   193,   578,   579,  1307,  1308,  1532,
     191,   194,   324,   580,   195,   196,   197,   198,   199,    51,
     325,    52,    53,  1537,   200,   201,   202,   890,   203,   204,
     313,   205,   206,   207,   208,  1597,   213,   763,   604,   560,
     326,   316,   951,   215,   216,   953,   317,   605,   217,   956,
     218,   311,   327,  1602,   963,  1246,   312,   606,   322,   516,
     517,   518,   519,   520,   521,   522,   523,   314,   315,   323,
     328,   337,   336,   338,   340,   345,   581,   582,   583,   341,
     343,   329,   349,   352,   354,   364,    54,   330,   357,   516,
     517,   518,   519,   520,   521,   522,   523,   365,   368,   607,
     369,   608,   371,   373,   378,   381,   383,   331,   516,   517,
     518,   519,   520,   521,   522,   523,   389,   390,   392,   396,
     584,   560,   717,   718,   719,   720,   721,   722,   723,   724,
     401,   400,   402,   403,  1675,   404,   410,   411,   412,   419,
     585,   586,   423,   984,   424,   425,   426,   427,   991,   428,
     466,   467,   476,   472,   473,   609,   486,   490,   610,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,   491,   496,   514,
     544,  1419,   515,   526,   527,  1013,  1080,   532,   528,  1092,
     529,   587,   533,   588,   534,   332,   535,   536,   537,  1035,
     538,   539,   540,   333,   334,  1429,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,  1459,  1460,   676,   677,   678,
     679,   680,   681,   682,   683,   541,   542,   545,   569,   190,
     543,   548,   590,   616,   617,   621,   631,   640,  1316,   641,
     642,   651,   643,   652,   658,   661,   662,   684,   667,   669,
     668,   685,   686,   696,   703,   708,   715,   783,   726,   732,
     736,   746,   749,   751,   769,   771,  -533,  1293,   778,   795,
     817,   801,   796,   802,   832,   834,   833,   836,  1470,   839,
     861,   840,   850,   841,   862,   864,   842,  1137,   843,   844,
     845,   846,   847,   848,   865,   190,   868,   869,   876,   873,
     877,   878,   879,   880,   883,   910,   886,   885,   889,  1146,
     891,   892,   893,   894,   895,   896,   899,   900,   901,   902,
     908,   919,   931,   911,   912,   913,   914,   915,   918,   921,
     922,   923,   924,   939,   925,   940,   932,   935,   941,   942,
     943,   944,   968,   971,   972,   973,   988,   964,   965,   997,
     998,  1002,  1042,  1044,  1245,   966,  1010,  1014,  1015,  1043,
     974,  1046,  1048,  1051,  1073,  1052,  1055,  1467,  1056,  1057,
    1058,  1059,  1062,  1063,  1064,  1065,  1067,  1068,  1128,  1108,
    1078,  1099,  1100,  1101,  1103,  1104,  1032,  1114,  1115,  1116,
    1121,  1123,  1124,  -571,  1152,  1157,  1143,  1147,  1148,  1149,
    1150,  1155,  1195,  1163,  1156,  1188,  1197,  1199,  1200,  1201,
    1241,  1179,  1209,  1203,  1204,  1211,   190,  1213,  1214,  1215,
    1205,  1229,  1216,  1217,  1218,  1219,  1220,  1289,  1226,  1225,
    1227,  1228,  1242,  1261,  1265,  1348,  1252,  1266,  1254,  1267,
    1268,  1256,  1270,  1271,  1272,  1164,  1258,  1273,  1276,  1278,
    1279,  1280,  1281,  1283,  1285,  1297,  1282,  1286,  1318,  1287,
    1288,  1299,  1303,  1301,  1304,  1311,  1317,  1323,  1324,  1326,
    1331,  1376,  1341,  1336,  1330,  1337,  1325,  1338,  1339,  1342,
    1346,  1347,  1374,  1538,  1377,  1380,  1381,  1382,  1383,  1391,
    1497,  1402,  1397,  1403,  1404,  1405,  1414,  1463,  1409,  1410,
    1411,  1415,  1420,  1416,  1498,  1421,  1422,  1423,  1424,  1425,
    1426,  1427,  1428,  1468,  1471,  1475,  1494,  1499,  1504,  1372,
    1505,  1510,  1511,  1513,  1643,  1501,  1523,  1524,  1525,  1526,
    1529,  1531,  1528,  1551,  1541,  1569,  1533,  1514,  1547,  1571,
    1573,  1565,  1534,  1579,  1519,  1520,  1572,  1535,  1522,  1580,
    1581,  1106,  1584,  1585,  1586,  1587,  1589,  1590,  1536,  1591,
    1539,  1592,  1595,  1598,  1599,  1600,  1601,  1568,  1370,  1542,
    1544,  1603,  1373,  1610,  1545,  1611,  1546,  1570,  1612,  1596,
    1235,  1613,  1593,  1628,  1614,  1618,  1622,  1624,  1625,  1626,
    1627,  1630,  1629,  1638,  1639,  1641,  1642,  1644,  1645,  1646,
    1659,  1647,  1648,  1631,  1650,  1651,  1657,  1658,  1649,  1661,
    1663,  1662,  1664,  1665,  1667,   132,  1371,  1668,  1669,  1670,
    1671,  1672,  1673,  1674,  1679,  1212,  1677,  1678,  1680,  1684,
    1685,  1687,  1688,  1689,  1692,  1693,  1694,  1695,   745,   996,
    1007,   248,   611,  1632,  1294,  1240,  1496,  1469,  1633,   190,
    1300,  1495,  1634,  1635,  1636,  1019,   970,  1244,   750,  1637,
     167,  1248,  1407,   620,  1652,  1178,  1050,  1274,   952,  1082,
     657,     0,     0,     0,     0,  1069,     0,     0,     0,     0,
       0,     0,     0,  1527,     0,     0,     0,     0,     0,     0,
       0,     0,  1653,     0,     0,     0,     0,     0,     0,  1683,
       0,     0,     0,     0,     0,     0,     0,     0,  1656,     0,
    1660,     0,  1691,     0,     0,  1676,     0,     0,  1681,     0,
       0,     0,     0,  1682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1686,     0,  1690,     0,     0,     0,     0,
    1567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1655,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1666,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1640,     0,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1654
};

static const yytype_int16 yycheck[] =
{
     126,   404,   189,   500,   347,   596,   884,   257,   351,   951,
     353,  1130,     4,     4,    30,    30,     4,     6,    30,     6,
       6,   963,     6,     4,   367,     4,     6,   370,     6,     6,
       6,     6,     6,     6,    30,     6,     6,   380,     6,     4,
      30,    58,    30,    28,    58,    28,    41,    96,    96,    96,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      58,   159,    71,    96,    58,    96,    96,    30,    21,    28,
      96,    96,   175,    31,    96,    96,    71,    96,    91,   175,
     180,     0,    19,     1,    30,    96,    96,    48,     4,     7,
      96,     9,    10,    11,    12,    13,    14,    96,    16,    17,
      18,    19,    20,    49,    50,    23,    24,   166,   126,     4,
       8,    29,   294,    31,     4,   297,    76,    77,    78,    79,
     220,   221,   222,   223,    42,    43,   469,    48,  1247,    45,
     533,  1170,    96,   125,    55,    30,    54,   104,  1080,  1178,
      96,   108,    60,    96,   294,  1087,    96,    96,    96,   167,
    1092,    69,   294,   294,    36,    37,   297,    75,   100,   101,
     174,   175,    80,   660,   567,   174,   294,   664,   296,   666,
      52,   166,   167,  1064,   233,    93,  1067,    59,    96,    97,
     294,   166,   296,   294,   166,   167,     6,   175,   291,   107,
       3,     4,   110,     6,   176,   291,   157,   158,   156,   294,
     188,   296,    94,   217,   218,   219,    76,    77,    78,    79,
     219,   224,   225,   226,   151,   152,   163,   164,   165,    98,
      99,   167,   169,   102,   103,     9,    28,     3,     4,   147,
       6,  1422,  1423,  1424,    36,    37,  1427,    39,    76,    77,
      78,    79,   160,   161,   162,    47,   295,   295,   295,   167,
       6,     3,     4,   270,     6,   295,   270,   216,     6,   177,
     386,   179,   295,     6,   295,   295,     6,   283,   283,   295,
     295,   283,   270,   295,   295,   289,   295,   271,     6,   294,
     296,     6,   294,   292,   295,   295,   294,   283,   167,   295,
     275,   273,   277,   283,   288,   698,   295,   215,   294,   217,
     218,   286,   287,   286,  1246,   187,     6,   299,   299,   297,
     299,   293,   299,   299,   298,   441,   297,   297,   297,   445,
     283,   299,   299,   299,   299,   299,   299,   298,   298,   294,
     298,   295,     6,   279,   280,   281,   297,   283,   298,   295,
     300,   287,   144,   145,   687,   295,   295,   295,     6,    81,
      82,    83,    84,   104,   294,     6,   296,   108,   109,     6,
      76,    77,    78,    79,   282,   167,    72,    73,    74,   619,
     620,   170,   171,   499,   500,    91,  1318,   503,   220,   221,
     222,   223,   294,   509,   296,   172,   173,   189,   190,   191,
     192,   193,   194,   195,   196,   112,   113,   114,   115,   116,
     117,     7,     6,     9,    10,    11,    12,    13,    14,     6,
      16,    17,    18,    19,    20,   148,   149,    23,    24,    36,
      37,   547,    39,    29,   228,    31,   230,     6,   298,   555,
     300,     6,   234,   184,     3,   167,    42,    43,     3,   565,
     566,    87,    88,    89,    90,   294,     6,   296,    54,   181,
     167,     6,     3,     4,    60,     6,     6,  1576,   955,   150,
     151,   152,   153,    69,   294,   591,   296,     6,   655,    75,
       3,     4,   274,     6,    80,     6,   278,    87,    88,    89,
      90,   283,   284,   285,   286,     3,     4,    93,     6,     6,
      96,    97,    30,   118,   119,    33,    34,     4,    36,    37,
     232,   107,     3,     4,   110,     6,   120,   121,    46,    47,
      48,    49,     4,    51,    52,   296,   297,    55,    56,    57,
      58,   294,    95,   296,  1021,    87,    88,    89,    90,   294,
     780,   296,     4,   659,   660,    98,    99,   663,   664,     4,
     666,   147,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   154,   155,   160,   161,   162,     3,     4,     4,
       6,   167,   688,   689,   294,   294,   296,   296,   294,     4,
     296,   177,   235,   179,   294,   297,   296,    33,    34,   705,
      36,    37,   294,   294,   296,   296,   296,   297,     6,   992,
      46,    47,    48,    49,     4,    51,    52,  1227,  1228,  1477,
     294,   294,     1,    59,   294,   294,   294,   294,   294,   215,
       9,   217,   218,    25,   294,   294,   294,   743,   294,   294,
       6,   294,   294,   294,   294,  1567,   294,   290,   166,   167,
      29,     6,   819,   294,   294,   822,     6,   175,   294,   826,
     294,   294,    41,    25,   831,  1142,   294,   185,    25,    61,
      62,    63,    64,    65,    66,    67,    68,   294,   294,     4,
      59,    20,     6,    19,    25,    31,   122,   123,   124,    10,
      42,    70,    43,    54,    69,    75,   282,    76,    93,    61,
      62,    63,    64,    65,    66,    67,    68,    80,    97,   227,
     297,   229,   147,   107,   110,   179,   215,    96,    61,    62,
      63,    64,    65,    66,    67,    68,   217,    28,   218,     4,
     166,   167,   197,   198,   199,   200,   201,   202,   203,   204,
      48,   282,   294,     6,  1666,     6,     6,     6,   294,   162,
     186,   187,    22,   859,     4,     6,     4,     4,   864,     4,
       4,     4,     4,   297,   297,   283,     4,   294,   286,    61,
      62,    63,    64,    65,    66,    67,    68,     4,     4,    60,
     296,  1352,     6,   298,   298,   891,   953,    27,   298,   956,
     298,   227,     6,   229,     4,   174,     4,     4,     4,   905,
       4,     4,     4,   182,   183,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   535,   536,   537,
     538,   539,   540,   541,   542,     4,     4,    27,   297,   955,
       6,     4,    28,     4,     4,     4,     4,     4,  1241,     4,
       4,     4,   111,     4,     4,     4,     4,   294,    25,     6,
      25,    76,     6,     6,     6,     4,     6,   296,     6,     6,
       6,     6,     6,     6,     6,     6,     4,  1210,     4,     4,
     296,     4,     6,     4,     6,   294,     6,     3,  1375,     4,
       4,   294,   175,   294,     4,     4,   294,  1013,   294,   294,
     294,   294,   294,   294,     4,  1021,     4,    71,     4,   297,
       4,     4,     4,     4,     4,    92,     4,     6,     4,  1035,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,   297,   105,     6,     6,     6,     6,     4,     4,     4,
     298,     4,     6,     4,     6,     4,   294,   294,     4,     4,
       4,     4,   146,     4,     6,   294,     4,    26,    26,     6,
       4,     4,     4,     4,  1141,    25,    53,     6,     6,     6,
      28,     4,     4,     4,   296,   231,     6,  1370,     6,     6,
       6,     6,     4,     4,     4,     4,     4,     4,   298,   178,
       6,     6,     6,     6,     6,     6,    53,     6,     6,     6,
       6,     6,     4,     4,   294,   104,     6,     6,     6,     6,
       4,     4,   294,     4,     6,     4,     4,     4,     4,     4,
    1136,   166,     6,    27,    27,     4,  1142,     4,     4,     4,
      26,   297,     6,     6,     6,     4,     4,   166,     4,     6,
       4,     4,   146,     4,     6,    27,   297,     6,   297,     6,
       6,   298,     6,     6,     6,   105,   105,     6,     6,     6,
       6,     6,     6,     4,     6,   296,    56,     6,  1245,     6,
       6,     6,     6,   296,   296,     6,     6,     4,     4,     4,
       4,   268,     4,     6,   294,     6,   297,     6,     6,     6,
       6,     6,     6,  1486,     4,   298,   298,   298,     4,     4,
     298,     4,     6,     4,     4,     4,   294,     3,     6,     6,
       4,   294,     4,     6,   298,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     4,     6,     4,     6,   175,
       6,     6,     4,     4,  1621,   297,     4,     4,     4,     4,
     296,     4,     6,     4,     6,   126,   298,    28,   106,     6,
       6,   175,   298,     4,    28,    28,    25,   298,    28,     4,
       6,   970,     6,     6,     6,   175,     4,     4,   298,     4,
     297,     4,     6,   276,    26,     6,     6,   296,  1294,   297,
     297,  1574,  1298,     4,   297,     4,   298,   298,     4,   297,
     297,     4,   175,    25,     6,     6,     6,     6,    26,     6,
       6,   298,   297,     6,     6,     6,     6,     6,     4,    27,
      27,     6,     6,   298,     6,     6,     4,     6,    26,     6,
       6,    26,     4,     4,     4,    29,  1296,     6,     6,    27,
       6,     6,     4,     4,    27,  1110,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,   593,   866,
     881,   164,   459,   298,  1210,  1131,  1401,  1373,   298,  1375,
    1219,  1400,   298,   298,   298,   897,   838,  1140,   598,   298,
      95,  1145,  1329,   473,   297,  1068,   918,  1177,   820,   954,
     501,    -1,    -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,
     298,    -1,   272,    -1,    -1,   296,    -1,    -1,   298,    -1,
      -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,    -1,   296,    -1,    -1,    -1,    -1,
    1527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1643,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1617,    -1,    -1,    -1,  1621,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1640
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   159,   302,   303,   304,     0,     8,   305,     4,   170,
     171,     1,   306,   294,   294,   294,     7,     9,    10,    11,
      12,    13,    14,    16,    17,    18,    19,    20,    23,    24,
      29,    31,    42,    43,    54,    60,    69,    75,    80,    93,
      96,    97,   107,   110,   147,   160,   161,   162,   167,   177,
     179,   215,   217,   218,   282,   307,   308,   309,   311,   312,
     314,   316,   318,   319,   336,   337,   338,   339,   341,   344,
     346,   347,   351,   352,   380,   390,   392,   401,   402,   404,
     405,   426,   427,   439,   440,   441,   481,   482,   546,   584,
     586,   587,   604,   605,   606,   607,   622,   623,   648,   649,
     666,   667,   682,   683,   695,   696,   731,   732,   744,   745,
     764,   765,   775,   776,   797,   798,   817,   818,   310,     6,
     313,    94,   315,   317,   340,   342,   345,     6,     6,   172,
     173,   393,   393,   381,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     9,     6,     6,     6,     6,     3,     3,
     320,   442,     6,     6,     6,     6,     6,   348,   353,     6,
     406,   428,   444,   483,   547,   588,   608,   608,   624,   650,
     668,   684,   697,   735,   747,   767,   778,   295,   801,   820,
       4,   294,     4,    95,     4,     4,     4,     4,   297,   420,
     423,   294,     6,     4,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   321,
       4,   294,   443,   294,   733,   294,   294,   294,   294,    21,
      96,   349,   350,    96,   295,   354,   379,   391,    96,   295,
     407,   425,    96,   295,   429,    96,   295,   445,   446,   447,
     480,    96,   295,   484,   485,   486,   544,    96,   485,   548,
     585,    96,   295,   589,   590,   603,    96,   295,   609,   610,
     615,   621,    96,   620,    96,   295,   625,   626,   647,    96,
     295,   651,   652,   665,    96,   295,   669,    96,   295,   685,
     694,    96,   295,   698,   699,   721,    96,   295,   734,   736,
      96,   295,   746,   748,   749,    96,   295,   766,   768,   769,
      96,   295,   777,   779,   782,   802,   800,    96,   295,   819,
     821,   294,   294,     6,   294,   294,     6,     6,     6,   299,
     421,   423,    25,     4,     1,     9,    29,    41,    59,    70,
      76,    96,   174,   182,   183,   322,     6,    20,    19,   355,
      25,    10,   408,    42,   430,    31,   448,   450,   449,    43,
     487,   497,    54,   549,    69,   591,   592,    93,    76,    77,
      78,    79,    91,   611,    75,    80,   627,   628,    97,   297,
     654,   147,   670,   107,   104,   108,   109,   184,   110,   700,
     704,   179,   737,   215,    28,   216,    30,   283,   762,   217,
      28,   772,   218,    28,   286,   785,     4,    96,   799,   801,
     282,    48,   294,     6,     6,     6,   299,     6,   299,   422,
       6,     6,   294,   323,   329,   326,   331,   327,   324,   162,
     328,   325,   330,    22,     4,     6,     4,     4,     4,   294,
     296,   403,   451,   452,   453,   455,   458,   460,   462,   465,
     467,   471,   472,   475,   476,   478,   479,     4,   299,     4,
      45,   488,   294,   296,   403,   498,   513,   515,   294,   296,
     403,   550,   551,   565,   567,   569,     4,     4,   593,   594,
     612,   613,   297,   297,   616,   618,     4,   294,   296,   403,
     630,   653,   294,   296,   403,   655,     4,   686,   688,   689,
     294,     4,   294,   296,   403,   705,     4,   750,   752,   423,
     763,   761,   770,    30,   283,   294,   773,   783,   780,    30,
     283,   294,   786,   803,    60,     6,    61,    62,    63,    64,
      65,    66,    67,    68,   343,   343,   298,   298,   298,   298,
     294,   421,    27,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,   296,    27,   409,   431,     4,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   166,
     167,   176,   273,   293,     4,   423,   461,   423,   489,   297,
      33,    34,    36,    37,    46,    47,    48,    49,    51,    52,
      59,   122,   123,   124,   166,   186,   187,   227,   229,   521,
      28,   517,    30,    33,    34,    46,    47,    48,    49,    51,
      55,    56,    57,    58,   166,   175,   185,   227,   229,   283,
     286,   521,   294,   296,   403,   595,     4,     4,   611,   614,
     614,     4,   294,   296,   619,    81,    82,    83,    84,   181,
     232,     4,    98,    99,   102,   103,   664,   148,   149,   672,
       4,     4,     4,   111,   701,   112,   113,   114,   115,   116,
     117,     4,     4,   758,   423,   420,   294,   762,     4,   423,
     774,     4,     4,   423,   787,   804,   822,    25,    25,     6,
     343,   163,   164,   165,   169,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   294,    76,     6,   410,   423,   432,
     456,   220,   221,   222,   223,   459,     6,   454,   423,   473,
     468,   477,   463,     6,   423,   423,   343,   491,     4,   180,
     220,   221,   222,   223,   512,     6,   501,   197,   198,   199,
     200,   201,   202,   203,   204,   376,     6,    91,   224,   225,
     226,   576,     6,   502,   516,   506,     6,   509,   503,   504,
     500,   499,   518,   423,   557,   459,     6,   560,   376,     6,
     576,     6,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   235,   290,   545,   566,   568,   570,   561,     6,
     553,     6,   555,   558,   552,    41,    71,   166,     4,   298,
     300,   611,   298,   296,   617,    87,    88,    89,    90,   631,
     632,   633,   634,   635,   636,     4,     6,   656,   100,   101,
     671,     4,     4,   104,   108,   690,   118,   119,   702,   706,
     707,   708,   709,   710,   711,   738,   751,   296,   759,   421,
     771,   423,   420,   784,   781,   423,   420,   294,   296,   805,
     813,   420,     6,     6,   294,   382,     3,   334,   333,     4,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   356,
     175,   394,   395,   294,   296,   403,   411,   418,   423,   423,
     433,     4,     4,   343,     4,     4,   469,   470,     4,    71,
     464,   466,   423,   297,   492,   490,     4,     4,     4,     4,
       4,   510,   511,     4,   505,     6,     4,   522,   525,     4,
     423,     4,     4,     4,     4,     4,     4,   572,   573,     4,
       4,     4,     4,   577,   580,   597,   601,   596,     4,   611,
      92,     6,     6,     6,     6,     4,   638,   642,     4,   297,
     637,     4,   298,     4,     6,     6,   150,   151,   152,   153,
     673,   105,   294,   691,   693,   294,   120,   121,   703,     4,
       4,     4,     4,     4,     4,   739,   753,    71,   174,   219,
     292,   421,   773,   421,   788,   792,   421,    28,   166,   275,
     277,   286,   287,   421,    26,    26,    25,   383,   146,   575,
     575,     4,     6,   294,    28,   397,    30,    49,    50,   279,
     280,   281,   283,   287,   423,   294,   296,   434,     4,   457,
       6,   423,   474,     3,     4,     6,   470,     6,     4,     4,
     125,   299,     4,   507,     3,     4,     6,   511,   522,   526,
      53,   523,   514,   423,     6,     6,     3,     4,     6,   573,
     554,   556,    61,    62,    63,    64,    65,    66,    67,    68,
     562,   581,    53,   578,     4,   423,   598,    72,    73,    74,
     602,   599,     4,     6,     4,   629,     4,   639,     4,   643,
     629,     4,   231,   646,   657,     6,     6,     6,     6,     6,
     674,   687,     4,     4,     4,     4,   717,     4,     4,   717,
     294,   296,   740,   296,   754,   755,   756,   760,     6,   422,
     421,   296,   786,   789,   790,   795,   296,   420,   791,   793,
     794,   796,   421,   806,   814,   810,   808,   809,   422,     6,
       6,     6,   385,     6,     6,   335,   335,   357,   178,   396,
     398,   412,   419,   415,     6,     6,     6,   413,   416,   166,
     233,     6,   343,     6,     4,   493,   495,   494,   298,   722,
     537,   524,    36,    37,    39,   519,   520,   423,   571,   563,
     564,   420,   559,     6,   583,   579,   423,     6,     6,     6,
       4,   600,   294,   640,   644,     4,     6,   104,   658,   661,
     294,   296,   675,     4,   105,   664,    87,    88,    89,    90,
     719,   720,    87,    88,    89,    90,   718,   664,   719,   166,
      58,   174,   175,   217,   218,   219,   270,   289,     4,   422,
     175,   291,   175,   291,   422,   294,   422,     4,   815,     4,
       4,     4,   294,    27,    27,    26,   294,   296,   386,     6,
     358,     4,   400,     4,     4,     4,     6,     6,     6,     4,
       4,   435,   228,   230,   438,     6,     4,     4,     4,   297,
     508,   723,    48,   157,   158,   297,   534,   538,   539,   541,
     525,   423,   146,   574,   577,   421,   420,   542,   580,     3,
       4,     6,   297,   641,   297,   645,   298,   662,   105,   154,
     155,     4,   692,   712,   714,     6,     6,     6,     6,   720,
       6,     6,     6,     6,   712,   741,     6,   757,     6,     6,
       6,     6,    56,     4,   816,     6,     6,     6,     6,   166,
     294,   296,   359,   403,   478,   399,   400,   296,   424,     6,
     424,   296,   436,     6,   296,   403,   496,   496,   496,   724,
     726,     6,   540,     6,   299,   527,   343,     6,   421,   422,
     296,   534,   543,     4,     4,   297,     4,   659,   676,   677,
     294,     4,    19,   151,   152,   715,     6,     6,     6,     6,
     742,     4,     6,     3,     4,     6,     6,     6,    27,   384,
     387,    28,    47,   144,   145,   189,   190,   191,   192,   193,
     194,   195,   196,   234,   274,   278,   283,   284,   285,   286,
     423,   399,   175,   423,     6,   414,   268,     4,   437,   126,
     298,   298,   298,     4,    36,    37,    52,    59,   187,   727,
     730,     4,     6,   299,     6,   299,   530,     6,   422,    48,
      55,   582,     4,     4,     4,     4,   678,   678,   713,     6,
       6,     4,   743,   807,   294,   294,     6,   388,   362,   376,
       4,     6,     6,     6,     6,     6,     6,     6,     6,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   375,   361,     3,   364,   360,   366,   343,     6,   423,
     420,     6,     3,     4,     6,     4,   729,   728,     6,   298,
       6,   298,     6,   298,     6,   298,     4,    30,   175,   188,
     528,   529,   531,   534,     6,   545,   530,   298,   298,     4,
     660,   297,   679,   716,     6,     6,     3,     4,     6,   811,
       6,     4,   389,     4,    28,   377,   377,   377,   377,    28,
      28,   377,    28,     4,     4,     4,     4,   421,     6,   296,
     725,     4,   522,   298,   298,   298,   298,    25,   343,   297,
     536,     6,   297,   535,   297,   297,   298,   106,   663,    31,
     156,     4,    58,   271,   288,   812,     3,     4,     6,   363,
     378,   367,   368,   369,   365,   175,   371,   421,   296,   126,
     298,     6,    25,     6,     4,    30,   533,     6,   299,     4,
       4,     6,   681,   680,     6,     6,     6,   175,   370,     4,
       4,     4,     4,   175,   372,     6,   297,   422,   276,    26,
       6,     6,    25,   343,   532,   534,     6,   299,     6,   299,
       4,     4,     4,     4,     6,    58,   270,   373,     6,    58,
     270,   374,     6,   417,     6,    26,     6,     6,    25,   297,
     298,   298,   298,   298,   298,   298,   298,   298,     6,     6,
     423,     6,     6,   420,     6,     4,    27,     6,     6,    26,
       6,     6,   297,   297,   423,   421,   298,     4,     6,    27,
     298,     6,    26,     6,     4,     4,   421,     4,     6,     6,
      27,     6,     6,     4,     4,   422,   296,     6,     6,    27,
       6,   298,   298,   269,     6,     6,   298,     6,     6,     6,
     296,   272,     6,     6,     6,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   301,   302,   303,   304,   303,   305,   305,   305,   306,
     306,   306,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   310,   309,   311,   313,   312,   315,   314,   317,   316,
     318,   320,   319,   321,   321,   323,   322,   324,   322,   325,
     322,   326,   322,   327,   322,   328,   322,   329,   322,   330,
     322,   331,   322,   322,   333,   332,   334,   332,   332,   332,
     332,   335,   335,   336,   337,   338,   340,   339,   342,   341,
     343,   343,   343,   343,   343,   343,   343,   343,   345,   344,
     346,   347,   348,   348,   349,   350,   351,   352,   353,   353,
     355,   356,   357,   354,   358,   358,   359,   359,   359,   359,
     360,   359,   361,   359,   359,   359,   362,   363,   359,   364,
     365,   359,   366,   359,   359,   359,   359,   359,   359,   367,
     359,   368,   359,   359,   369,   359,   359,   370,   370,   371,
     371,   372,   372,   373,   373,   373,   374,   374,   374,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   376,   376,   376,   376,   376,   376,   376,   376,   377,
     378,   377,   379,   381,   382,   380,   383,   383,   384,   384,
     385,   385,   387,   386,   388,   388,   389,   389,   389,   391,
     390,   392,   393,   393,   394,   395,   395,   396,   396,   397,
     398,   397,   399,   399,   400,   401,   402,   403,   404,   405,
     406,   406,   408,   409,   407,   410,   410,   412,   411,   413,
     414,   411,   415,   411,   416,   417,   411,   411,   411,   418,
     418,   418,   419,   418,   420,   421,   422,   422,   423,   423,
     423,   423,   424,   424,   425,   426,   427,   428,   428,   430,
     431,   429,   432,   432,   433,   433,   435,   434,   434,   436,
     436,   437,   437,   437,   438,   438,   439,   440,   441,   442,
     442,   443,   444,   444,   445,   446,   448,   447,   449,   449,
     449,   450,   450,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   452,   454,   453,   456,   455,
     457,   457,   458,   459,   459,   459,   459,   460,   460,   461,
     461,   463,   462,   464,   464,   466,   465,   468,   467,   469,
     469,   470,   470,   470,   471,   473,   472,   474,   474,   475,
     475,   475,   477,   476,   478,   478,   478,   479,   480,   481,
     482,   483,   483,   484,   485,   487,   486,   489,   488,   490,
     488,   491,   491,   493,   492,   494,   492,   495,   492,   496,
     496,   496,   497,   497,   499,   498,   498,   498,   500,   498,
     501,   498,   498,   498,   498,   498,   498,   498,   502,   498,
     498,   503,   498,   504,   505,   498,   506,   507,   508,   498,
     509,   498,   498,   510,   510,   511,   511,   511,   512,   512,
     512,   512,   512,   514,   513,   516,   515,   517,   518,   517,
     519,   519,   520,   520,   520,   521,   521,   521,   522,   522,
     524,   523,   526,   527,   525,   528,   529,   530,   530,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   532,
     531,   533,   531,   531,   534,   534,   534,   534,   534,   534,
     534,   534,   535,   535,   535,   535,   536,   537,   537,   538,
     538,   539,   540,   539,   541,   542,   542,   543,   543,   544,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   546,   547,   547,   548,   549,   549,   550,   550,
     550,   550,   551,   552,   551,   553,   554,   551,   551,   551,
     555,   556,   551,   557,   551,   558,   559,   551,   551,   551,
     551,   560,   551,   551,   551,   551,   551,   551,   561,   551,
     551,   562,   562,   562,   562,   562,   562,   562,   562,   562,
     563,   564,   563,   566,   565,   568,   567,   570,   571,   569,
     572,   572,   573,   573,   573,   574,   574,   575,   575,   576,
     576,   576,   576,   577,   577,   579,   578,   581,   582,   580,
     583,   584,   585,   586,   587,   588,   588,   589,   591,   590,
     592,   592,   593,   594,   594,   595,   596,   595,   597,   595,
     595,   598,   598,   599,   599,   600,   600,   600,   601,   601,
     602,   602,   602,   603,   604,   605,   606,   607,   608,   608,
     609,   609,   610,   612,   611,   613,   611,   611,   611,   614,
     614,   614,   616,   615,   617,   617,   618,   618,   619,   619,
     619,   619,   620,   621,   622,   623,   624,   624,   625,   627,
     626,   628,   628,   629,   629,   631,   630,   632,   630,   633,
     630,   634,   630,   635,   630,   636,   630,   630,   637,   637,
     637,   638,   638,   640,   639,   641,   641,   641,   641,   642,
     642,   644,   643,   645,   645,   645,   645,   646,   646,   647,
     648,   649,   650,   650,   651,   653,   652,   654,   654,   655,
     655,   655,   656,   657,   655,   655,   659,   660,   658,   661,
     662,   661,   663,   663,   664,   664,   665,   666,   667,   668,
     668,   670,   671,   669,   672,   672,   673,   673,   673,   673,
     674,   674,   676,   675,   677,   675,   678,   678,   680,   679,
     681,   679,   682,   683,   684,   684,   686,   687,   685,   688,
     685,   689,   685,   685,   691,   692,   690,   693,   690,   694,
     695,   696,   697,   697,   698,   700,   699,   701,   701,   702,
     702,   702,   703,   703,   703,   704,   704,   706,   705,   707,
     705,   708,   705,   709,   705,   710,   705,   711,   705,   705,
     713,   712,   714,   714,   715,   715,   716,   716,   717,   717,
     718,   718,   718,   718,   719,   719,   720,   720,   720,   720,
     721,   722,   722,   724,   723,   725,   725,   726,   726,   728,
     727,   729,   727,   730,   730,   730,   730,   731,   732,   733,
     733,   734,   735,   735,   737,   738,   736,   739,   739,   741,
     740,   742,   742,   743,   743,   743,   744,   745,   746,   747,
     747,   748,   750,   751,   749,   752,   749,   753,   753,   754,
     754,   754,   754,   755,   757,   756,   756,   756,   756,   756,
     758,   758,   760,   759,   759,   759,   759,   761,   761,   762,
     763,   762,   764,   765,   766,   767,   767,   768,   770,   771,
     769,   772,   772,   773,   774,   773,   775,   776,   777,   778,
     778,   779,   780,   781,   779,   783,   784,   782,   785,   785,
     786,   787,   786,   788,   788,   789,   789,   790,   791,   792,
     792,   793,   793,   794,   795,   796,   797,   798,   799,   800,
     800,   802,   803,   801,   804,   804,   805,   806,   807,   805,
     808,   805,   809,   805,   810,   805,   805,   811,   811,   812,
     812,   812,   814,   813,   815,   815,   816,   816,   816,   817,
     818,   819,   820,   820,   822,   821
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     0,     4,     0,     3,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     2,     0,     4,     0,     4,     0,     4,
       1,     0,     5,     0,     2,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     2,     0,     4,     0,     4,     1,     2,
       2,     0,     1,     5,     3,     3,     0,    14,     0,    14,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       3,     2,     0,     2,     5,     2,     3,     3,     0,     2,
       0,     0,     0,    10,     0,     2,     2,     1,     3,     3,
       0,     4,     0,     4,     3,     2,     0,     0,     9,     0,
       0,    11,     0,     9,     3,     4,     4,     4,     4,     0,
       6,     0,     6,     4,     0,     6,     3,     0,     2,     0,
       2,     0,     2,     0,     2,     2,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     3,     2,     0,     0,    11,     0,     5,     0,     3,
       0,     2,     0,     4,     0,     2,     2,     2,     2,     0,
       9,     2,     1,     1,     2,     0,     3,     0,     1,     0,
       0,     4,     0,     2,     1,     8,     1,     2,     3,     3,
       0,     2,     0,     0,     6,     0,     2,     0,     7,     0,
       0,    10,     0,     4,     0,     0,    24,     1,     1,     4,
       4,     6,     0,     4,     1,     1,     0,     2,     4,     4,
       4,     4,     0,     3,     2,     4,     3,     0,     2,     0,
       0,     7,     2,     3,     0,     2,     0,     4,     3,     0,
       2,     2,     2,     2,     1,     1,     3,     3,     3,     0,
       2,     1,     0,     2,     3,     2,     0,     4,     0,     2,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     5,
       0,     1,     3,     1,     1,     1,     1,     2,     2,     2,
       3,     0,     8,     0,     1,     0,     6,     0,     4,     1,
       2,     2,     2,     2,     2,     0,     6,     1,     2,     3,
       2,     4,     0,     4,     2,     2,     2,     3,     2,     3,
       3,     0,     2,     3,     1,     0,     3,     0,     3,     0,
       6,     0,     2,     0,     6,     0,     6,     0,     6,     0,
       1,     2,     0,     2,     0,     4,     3,     2,     0,     4,
       0,     4,     3,     3,     3,     3,     3,     3,     0,     4,
       1,     0,     4,     0,     0,     5,     0,     0,     0,     8,
       0,     4,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     0,     6,     0,     4,     0,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     0,     6,     2,     2,     0,     2,     1,
       3,     2,     4,    10,     8,     9,    11,     1,     1,     0,
      10,     0,     4,     1,     4,     4,     4,     4,     5,     5,
       5,     5,     4,     4,     4,     4,     6,     0,     2,     1,
       1,     1,     0,     3,     2,     0,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     2,     3,     0,     2,     1,     1,
       1,     1,     2,     0,     4,     0,     0,     6,     3,     3,
       0,     0,     9,     0,     6,     0,     0,     8,     3,     2,
       3,     0,     4,     3,     3,     3,     3,     3,     0,     4,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     2,     0,     5,     0,     4,     0,     0,     7,
       1,     2,     2,     2,     2,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     2,     0,     3,     0,     0,     7,
       1,     3,     2,     3,     3,     0,     2,     4,     0,     3,
       0,     2,     1,     0,     2,     3,     0,     4,     0,     4,
       1,     2,     1,     0,     2,     2,     2,     2,     0,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     0,     2,
       1,     1,     4,     0,     3,     0,     6,     4,     4,     1,
       2,     3,     0,     8,     0,     1,     0,     2,     3,     3,
       3,     3,     2,     2,     3,     3,     0,     2,     3,     0,
       3,     0,     2,     0,     1,     0,     5,     0,     4,     0,
       4,     0,     5,     0,     4,     0,     5,     1,     0,     4,
       8,     0,     2,     0,     3,     0,     4,     8,    12,     0,
       2,     0,     3,     0,     4,     8,    12,     0,     2,     2,
       3,     3,     0,     2,     3,     0,     6,     0,     2,     5,
       5,     3,     0,     0,     6,     1,     0,     0,     6,     0,
       0,     3,     0,     2,     1,     1,     2,     4,     3,     0,
       2,     0,     0,     8,     1,     1,     1,     2,     2,     2,
       0,     2,     0,     4,     0,     4,     0,     2,     0,     5,
       0,     5,     3,     3,     0,     2,     0,     0,    10,     0,
       6,     0,     6,     3,     0,     0,     6,     0,     3,     2,
       3,     3,     0,     2,     3,     0,     4,     0,     3,     0,
       1,     1,     0,     1,     1,     0,     2,     0,     7,     0,
       6,     0,     5,     0,     7,     0,     6,     0,     5,     1,
       0,     4,     0,     2,     3,     3,     0,     2,     0,     2,
       2,     2,     2,     2,     1,     2,     3,     3,     3,     3,
       2,     0,     2,     0,     6,     0,     2,     0,     2,     0,
       3,     0,     3,     1,     1,     1,     1,     3,     3,     0,
       1,     2,     0,     2,     0,     0,     7,     0,     2,     0,
       4,     0,     2,     2,     2,     2,     3,     3,     2,     0,
       2,     4,     0,     0,     6,     0,     4,     0,     2,     3,
       3,     1,     1,     3,     0,     4,     2,     2,     2,     2,
       0,     2,     0,     4,     2,     2,     3,     0,     2,     3,
       0,     6,     3,     3,     2,     0,     2,     3,     0,     0,
       6,     0,     2,     3,     0,     6,     3,     3,     2,     0,
       2,     3,     0,     0,     8,     0,     0,     7,     0,     2,
       3,     0,     6,     0,     2,     1,     1,     2,     2,     0,
       2,     1,     1,     2,     3,     3,     4,     3,     2,     0,
       2,     0,     0,     6,     0,     2,     2,     0,     0,     8,
       0,     4,     0,     4,     0,     5,     1,     0,     2,     2,
       2,     2,     0,     4,     0,     2,     2,     2,     2,     3,
       3,     2,     0,     2,     0,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (defData, YY_("syntax error: cannot back up")); \
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
                  Type, Value, defData); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, defrData *defData)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (defData);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, defrData *defData)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, defData);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, defrData *defData)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , defData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, defData); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, defrData *defData)
{
  YYUSE (yyvaluep);
  YYUSE (defData);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (defrData *defData)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, defData);
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
  case 4:
#line 227 "def.y"
                { defData->dumb_mode = 1; defData->no_num = 1; }
#line 3080 "def.tab.c"
    break;

  case 5:
#line 228 "def.y"
      {
        defData->VersionNum = defrData::convert_defname2num((yyvsp[-1].string));
        if (defData->VersionNum > CURRENT_VERSION) {
          char temp[300];
          sprintf(temp,
          "The execution has been stopped because the DEF parser %.1f does not support DEF file with version %s.\nUpdate your DEF file to version 5.8 or earlier.",
                  CURRENT_VERSION, (yyvsp[-1].string));
          defData->defError(6503, temp);
          return 1;
        }
        if (defData->callbacks->VersionStrCbk) {
          CALLBACK(defData->callbacks->VersionStrCbk, defrVersionStrCbkType, (yyvsp[-1].string));
        } else if (defData->callbacks->VersionCbk) {
            CALLBACK(defData->callbacks->VersionCbk, defrVersionCbkType, defData->VersionNum);
        }
        if (defData->VersionNum > 5.3 && defData->VersionNum < 5.4)
          defData->defIgnoreVersion = 1;
        if (defData->VersionNum < 5.6)     // default to false before 5.6
          defData->names_case_sensitive = defData->session->reader_case_sensitive;
        else
          defData->names_case_sensitive = 1;
        defData->hasVer = 1;
        defData->doneDesign = 0;
    }
#line 3109 "def.tab.c"
    break;

  case 7:
#line 255 "def.y"
      {
        if (defData->VersionNum < 5.6) {
          defData->names_case_sensitive = 1;
          if (defData->callbacks->CaseSensitiveCbk)
            CALLBACK(defData->callbacks->CaseSensitiveCbk, defrCaseSensitiveCbkType,
                     defData->names_case_sensitive); 
          defData->hasNameCase = 1;
        } else
          if (defData->callbacks->CaseSensitiveCbk) // write error only if cbk is set 
             if (defData->caseSensitiveWarnings++ < defData->settings->CaseSensitiveWarnings)
               defData->defWarning(7011, "The NAMESCASESENSITIVE statement is obsolete in version 5.6 and later.\nThe DEF parser will ignore this statement.");
      }
#line 3126 "def.tab.c"
    break;

  case 8:
#line 268 "def.y"
      {
        if (defData->VersionNum < 5.6) {
          defData->names_case_sensitive = 0;
          if (defData->callbacks->CaseSensitiveCbk)
            CALLBACK(defData->callbacks->CaseSensitiveCbk, defrCaseSensitiveCbkType,
                     defData->names_case_sensitive);
          defData->hasNameCase = 1;
        } else {
          if (defData->callbacks->CaseSensitiveCbk) { // write error only if cbk is set 
            if (defData->caseSensitiveWarnings++ < defData->settings->CaseSensitiveWarnings) {
              defData->defError(6504, "Def parser version 5.7 and later does not support NAMESCASESENSITIVE OFF.\nEither remove this optional construct or set it to ON.");
              CHKERR();
            }
          }
        }
      }
#line 3147 "def.tab.c"
    break;

  case 51:
#line 308 "def.y"
                      {defData->dumb_mode = 1; defData->no_num = 1; }
#line 3153 "def.tab.c"
    break;

  case 52:
#line 309 "def.y"
      {
            if (defData->callbacks->DesignCbk)
              CALLBACK(defData->callbacks->DesignCbk, defrDesignStartCbkType, (yyvsp[-1].string));
            defData->hasDes = 1;
          }
#line 3163 "def.tab.c"
    break;

  case 53:
#line 316 "def.y"
          {
            defData->doneDesign = 1;
            if (defData->callbacks->DesignEndCbk)
              CALLBACK(defData->callbacks->DesignEndCbk, defrDesignEndCbkType, 0);
            // 11/16/2001 - pcr 408334
            // Return 1 if there is any defData->errors during parsing
            if (defData->errors)
                return 1;

            if (!defData->hasVer) {
              char temp[300];
              sprintf(temp, "No VERSION statement found, using the default value %2g.", defData->VersionNum);
              defData->defWarning(7012, temp);            
            }
            if (!defData->hasNameCase && defData->VersionNum < 5.6)
              defData->defWarning(7013, "The DEF file is invalid if NAMESCASESENSITIVE is undefined.\nNAMESCASESENSITIVE is a mandatory statement in the DEF file with version 5.6 and earlier.\nTo define the NAMESCASESENSITIVE statement, refer to the LEF/DEF 5.5 and earlier Language Reference manual.");
            if (!defData->hasBusBit && defData->VersionNum < 5.6)
              defData->defWarning(7014, "The DEF file is invalid if BUSBITCHARS is undefined.\nBUSBITCHARS is a mandatory statement in the DEF file with version 5.6 and earlier.\nTo define the BUSBITCHARS statement, refer to the LEF/DEF 5.5 and earlier Language Reference manual.");
            if (!defData->hasDivChar && defData->VersionNum < 5.6)
              defData->defWarning(7015, "The DEF file is invalid if DIVIDERCHAR is undefined.\nDIVIDERCHAR is a mandatory statement in the DEF file with version 5.6 and earlier.\nTo define the DIVIDERCHAR statement, refer to the LEF/DEF 5.5 and earlier Language Reference manual.");
            if (!defData->hasDes)
              defData->defWarning(7016, "DESIGN is a mandatory statement in the DEF file. Ensure that it exists in the file.");
          }
#line 3191 "def.tab.c"
    break;

  case 54:
#line 340 "def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 3197 "def.tab.c"
    break;

  case 55:
#line 341 "def.y"
          { 
            if (defData->callbacks->TechnologyCbk)
              CALLBACK(defData->callbacks->TechnologyCbk, defrTechNameCbkType, (yyvsp[-1].string));
          }
#line 3206 "def.tab.c"
    break;

  case 56:
#line 346 "def.y"
                    {defData->dumb_mode = 1; defData->no_num = 1;}
#line 3212 "def.tab.c"
    break;

  case 57:
#line 347 "def.y"
          { 
            if (defData->callbacks->ArrayNameCbk)
              CALLBACK(defData->callbacks->ArrayNameCbk, defrArrayNameCbkType, (yyvsp[-1].string));
          }
#line 3221 "def.tab.c"
    break;

  case 58:
#line 352 "def.y"
                            { defData->dumb_mode = 1; defData->no_num = 1; }
#line 3227 "def.tab.c"
    break;

  case 59:
#line 353 "def.y"
          { 
            if (defData->callbacks->FloorPlanNameCbk)
              CALLBACK(defData->callbacks->FloorPlanNameCbk, defrFloorPlanNameCbkType, (yyvsp[-1].string));
          }
#line 3236 "def.tab.c"
    break;

  case 60:
#line 359 "def.y"
          { 
            if (defData->callbacks->HistoryCbk)
              CALLBACK(defData->callbacks->HistoryCbk, defrHistoryCbkType, &defData->History_text[0]);
          }
#line 3245 "def.tab.c"
    break;

  case 61:
#line 365 "def.y"
          {
            if (defData->callbacks->PropDefStartCbk)
              CALLBACK(defData->callbacks->PropDefStartCbk, defrPropDefStartCbkType, 0);
          }
#line 3254 "def.tab.c"
    break;

  case 62:
#line 370 "def.y"
          { 
            if (defData->callbacks->PropDefEndCbk)
              CALLBACK(defData->callbacks->PropDefEndCbk, defrPropDefEndCbkType, 0);
            defData->real_num = 0;     // just want to make sure it is reset 
          }
#line 3264 "def.tab.c"
    break;

  case 64:
#line 378 "def.y"
            { }
#line 3270 "def.tab.c"
    break;

  case 65:
#line 380 "def.y"
                       {defData->dumb_mode = 1; defData->no_num = 1; defData->Prop.clear(); }
#line 3276 "def.tab.c"
    break;

  case 66:
#line 382 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("design", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->DesignProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3288 "def.tab.c"
    break;

  case 67:
#line 389 "def.y"
                { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3294 "def.tab.c"
    break;

  case 68:
#line 391 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("net", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->NetProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3306 "def.tab.c"
    break;

  case 69:
#line 398 "def.y"
                 { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3312 "def.tab.c"
    break;

  case 70:
#line 400 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("specialnet", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->SNetProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3324 "def.tab.c"
    break;

  case 71:
#line 407 "def.y"
                   { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3330 "def.tab.c"
    break;

  case 72:
#line 409 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("region", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->RegionProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3342 "def.tab.c"
    break;

  case 73:
#line 416 "def.y"
                  { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3348 "def.tab.c"
    break;

  case 74:
#line 418 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("group", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->GroupProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3360 "def.tab.c"
    break;

  case 75:
#line 425 "def.y"
                      { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3366 "def.tab.c"
    break;

  case 76:
#line 427 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("component", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->CompProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3378 "def.tab.c"
    break;

  case 77:
#line 434 "def.y"
                { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3384 "def.tab.c"
    break;

  case 78:
#line 436 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("row", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->RowProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3396 "def.tab.c"
    break;

  case 79:
#line 445 "def.y"
          { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3402 "def.tab.c"
    break;

  case 80:
#line 447 "def.y"
            {
              if (defData->callbacks->PropCbk) {
                defData->Prop.setPropType("componentpin", (yyvsp[-2].string));
                CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
              }
              defData->session->CompPinProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
            }
#line 3414 "def.tab.c"
    break;

  case 81:
#line 455 "def.y"
          { defData->dumb_mode = 1 ; defData->no_num = 1; defData->Prop.clear(); }
#line 3420 "def.tab.c"
    break;

  case 82:
#line 457 "def.y"
            {
              if (defData->VersionNum < 5.6) {
                if (defData->nonDefaultWarnings++ < defData->settings->NonDefaultWarnings) {
                  defData->defMsg = (char*)malloc(1000); 
                  sprintf (defData->defMsg,
                     "The NONDEFAULTRULE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6505, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              } else {
                if (defData->callbacks->PropCbk) {
                  defData->Prop.setPropType("nondefaultrule", (yyvsp[-2].string));
                  CALLBACK(defData->callbacks->PropCbk, defrPropCbkType, &defData->Prop);
                }
                defData->session->NDefProp.setPropType(defData->DEFCASE((yyvsp[-2].string)), defData->defPropDefType);
              }
            }
#line 3443 "def.tab.c"
    break;

  case 83:
#line 475 "def.y"
                    { yyerrok; yyclearin;}
#line 3449 "def.tab.c"
    break;

  case 84:
#line 477 "def.y"
                                 { defData->real_num = 0; }
#line 3455 "def.tab.c"
    break;

  case 85:
#line 478 "def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropInteger();
              defData->defPropDefType = 'I';
            }
#line 3464 "def.tab.c"
    break;

  case 86:
#line 482 "def.y"
                 { defData->real_num = 1; }
#line 3470 "def.tab.c"
    break;

  case 87:
#line 483 "def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropReal();
              defData->defPropDefType = 'R';
              defData->real_num = 0;
            }
#line 3480 "def.tab.c"
    break;

  case 88:
#line 489 "def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropString();
              defData->defPropDefType = 'S';
            }
#line 3489 "def.tab.c"
    break;

  case 89:
#line 494 "def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropQString((yyvsp[0].string));
              defData->defPropDefType = 'Q';
            }
#line 3498 "def.tab.c"
    break;

  case 90:
#line 499 "def.y"
            {
              if (defData->callbacks->PropCbk) defData->Prop.setPropNameMapString((yyvsp[0].string));
              defData->defPropDefType = 'S';
            }
#line 3507 "def.tab.c"
    break;

  case 92:
#line 506 "def.y"
            { if (defData->callbacks->PropCbk) defData->Prop.setNumber((yyvsp[0].dval)); }
#line 3513 "def.tab.c"
    break;

  case 93:
#line 509 "def.y"
          {
            if (defData->callbacks->UnitsCbk) {
              if (defData->defValidNum((int)(yyvsp[-1].dval)))
                CALLBACK(defData->callbacks->UnitsCbk,  defrUnitsCbkType, (yyvsp[-1].dval));
            }
          }
#line 3524 "def.tab.c"
    break;

  case 94:
#line 517 "def.y"
          {
            if (defData->callbacks->DividerCbk)
              CALLBACK(defData->callbacks->DividerCbk, defrDividerCbkType, (yyvsp[-1].string));
            defData->hasDivChar = 1;
          }
#line 3534 "def.tab.c"
    break;

  case 95:
#line 524 "def.y"
          { 
            if (defData->callbacks->BusBitCbk)
              CALLBACK(defData->callbacks->BusBitCbk, defrBusBitCbkType, (yyvsp[-1].string));
            defData->hasBusBit = 1;
          }
#line 3544 "def.tab.c"
    break;

  case 96:
#line 530 "def.y"
                     {defData->dumb_mode = 1;defData->no_num = 1; }
#line 3550 "def.tab.c"
    break;

  case 97:
#line 532 "def.y"
            {
              if (defData->callbacks->CanplaceCbk) {
                defData->Canplace.setName((yyvsp[-11].string));
                defData->Canplace.setLocation((yyvsp[-10].dval),(yyvsp[-9].dval));
                defData->Canplace.setOrient((yyvsp[-8].integer));
                defData->Canplace.setDo((yyvsp[-6].dval),(yyvsp[-4].dval),(yyvsp[-2].dval),(yyvsp[-1].dval));
                CALLBACK(defData->callbacks->CanplaceCbk, defrCanplaceCbkType,
                &(defData->Canplace));
              }
            }
#line 3565 "def.tab.c"
    break;

  case 98:
#line 542 "def.y"
                             {defData->dumb_mode = 1;defData->no_num = 1; }
#line 3571 "def.tab.c"
    break;

  case 99:
#line 544 "def.y"
            {
              if (defData->callbacks->CannotOccupyCbk) {
                defData->CannotOccupy.setName((yyvsp[-11].string));
                defData->CannotOccupy.setLocation((yyvsp[-10].dval),(yyvsp[-9].dval));
                defData->CannotOccupy.setOrient((yyvsp[-8].integer));
                defData->CannotOccupy.setDo((yyvsp[-6].dval),(yyvsp[-4].dval),(yyvsp[-2].dval),(yyvsp[-1].dval));
                CALLBACK(defData->callbacks->CannotOccupyCbk, defrCannotOccupyCbkType,
                        &(defData->CannotOccupy));
              }
            }
#line 3586 "def.tab.c"
    break;

  case 100:
#line 555 "def.y"
               {(yyval.integer) = 0;}
#line 3592 "def.tab.c"
    break;

  case 101:
#line 556 "def.y"
               {(yyval.integer) = 1;}
#line 3598 "def.tab.c"
    break;

  case 102:
#line 557 "def.y"
               {(yyval.integer) = 2;}
#line 3604 "def.tab.c"
    break;

  case 103:
#line 558 "def.y"
               {(yyval.integer) = 3;}
#line 3610 "def.tab.c"
    break;

  case 104:
#line 559 "def.y"
               {(yyval.integer) = 4;}
#line 3616 "def.tab.c"
    break;

  case 105:
#line 560 "def.y"
               {(yyval.integer) = 5;}
#line 3622 "def.tab.c"
    break;

  case 106:
#line 561 "def.y"
               {(yyval.integer) = 6;}
#line 3628 "def.tab.c"
    break;

  case 107:
#line 562 "def.y"
               {(yyval.integer) = 7;}
#line 3634 "def.tab.c"
    break;

  case 108:
#line 565 "def.y"
          {
            defData->Geometries.Reset();
          }
#line 3642 "def.tab.c"
    break;

  case 109:
#line 569 "def.y"
          {
            if (defData->callbacks->DieAreaCbk) {
               defData->DieArea.addPoint(&defData->Geometries);
               CALLBACK(defData->callbacks->DieAreaCbk, defrDieAreaCbkType, &(defData->DieArea));
            }
          }
#line 3653 "def.tab.c"
    break;

  case 110:
#line 578 "def.y"
            { }
#line 3659 "def.tab.c"
    break;

  case 111:
#line 581 "def.y"
        {
          if (defData->VersionNum < 5.4) {
             if (defData->callbacks->DefaultCapCbk)
                CALLBACK(defData->callbacks->DefaultCapCbk, defrDefaultCapCbkType, ROUND((yyvsp[0].dval)));
          } else {
             if (defData->callbacks->DefaultCapCbk) // write error only if cbk is set 
                if (defData->defaultCapWarnings++ < defData->settings->DefaultCapWarnings)
                   defData->defWarning(7017, "The DEFAULTCAP statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
#line 3674 "def.tab.c"
    break;

  case 114:
#line 597 "def.y"
          {
            if (defData->VersionNum < 5.4) {
              if (defData->callbacks->PinCapCbk) {
                defData->PinCap.setPin(ROUND((yyvsp[-3].dval)));
                defData->PinCap.setCap((yyvsp[-1].dval));
                CALLBACK(defData->callbacks->PinCapCbk, defrPinCapCbkType, &(defData->PinCap));
              }
            }
          }
#line 3688 "def.tab.c"
    break;

  case 115:
#line 608 "def.y"
            { }
#line 3694 "def.tab.c"
    break;

  case 116:
#line 611 "def.y"
            { }
#line 3700 "def.tab.c"
    break;

  case 117:
#line 614 "def.y"
          { 
            if (defData->callbacks->StartPinsCbk)
              CALLBACK(defData->callbacks->StartPinsCbk, defrStartPinsCbkType, ROUND((yyvsp[-1].dval)));
          }
#line 3709 "def.tab.c"
    break;

  case 120:
#line 623 "def.y"
         {defData->dumb_mode = 1; defData->no_num = 1; }
#line 3715 "def.tab.c"
    break;

  case 121:
#line 624 "def.y"
         {defData->dumb_mode = 1; defData->no_num = 1; }
#line 3721 "def.tab.c"
    break;

  case 122:
#line 625 "def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              defData->Pin.Setup((yyvsp[-4].string), (yyvsp[0].string));
            }
            defData->hasPort = 0;
            defData->hadPortOnce = 0;
          }
#line 3733 "def.tab.c"
    break;

  case 123:
#line 633 "def.y"
          { 
            if (defData->callbacks->PinCbk)
              CALLBACK(defData->callbacks->PinCbk, defrPinCbkType, &defData->Pin);
          }
#line 3742 "def.tab.c"
    break;

  case 126:
#line 642 "def.y"
          {
            if (defData->callbacks->PinCbk)
              defData->Pin.setSpecial();
          }
#line 3751 "def.tab.c"
    break;

  case 127:
#line 648 "def.y"
          { 
            if (defData->callbacks->PinExtCbk)
              CALLBACK(defData->callbacks->PinExtCbk, defrPinExtCbkType, &defData->History_text[0]);
          }
#line 3760 "def.tab.c"
    break;

  case 128:
#line 654 "def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.setDirection((yyvsp[0].string));
          }
#line 3769 "def.tab.c"
    break;

  case 129:
#line 660 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The NETEXPR statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6506, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.setNetExpr((yyvsp[0].string));

            }
          }
#line 3793 "def.tab.c"
    break;

  case 130:
#line 680 "def.y"
                                  { defData->dumb_mode = 1; }
#line 3799 "def.tab.c"
    break;

  case 131:
#line 681 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The SUPPLYSENSITIVITY statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6507, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.setSupplySens((yyvsp[0].string));
            }
          }
#line 3822 "def.tab.c"
    break;

  case 132:
#line 700 "def.y"
                                  { defData->dumb_mode = 1; }
#line 3828 "def.tab.c"
    break;

  case 133:
#line 701 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The GROUNDSENSITIVITY statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6508, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.setGroundSens((yyvsp[0].string));
            }
          }
#line 3851 "def.tab.c"
    break;

  case 134:
#line 721 "def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) defData->Pin.setUse((yyvsp[0].string));
          }
#line 3859 "def.tab.c"
    break;

  case 135:
#line 725 "def.y"
          {
            if (defData->VersionNum < 5.7) {
               if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                 if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                     (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                   defData->defMsg = (char*)malloc(10000);
                   sprintf (defData->defMsg,
                     "The PORT in PINS is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                   defData->defError(6555, defData->defMsg);
                   free(defData->defMsg);
                   CHKERR();
                 }
               }
            } else {
               if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                   defData->Pin.addPort();
               }

               defData->hasPort = 1;
               defData->hadPortOnce = 1;
            }
          }
#line 3886 "def.tab.c"
    break;

  case 136:
#line 748 "def.y"
                      { defData->dumb_mode = 1; }
#line 3892 "def.tab.c"
    break;

  case 137:
#line 749 "def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              if (defData->hasPort) {
                 defData->Pin.addPortLayer((yyvsp[0].string));
              } else if (defData->hadPortOnce) {
                 if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                   (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                   defData->defError(7418, "syntax error");
                   CHKERR();
                 }
              } else {
                 defData->Pin.addLayer((yyvsp[0].string));
              }
            }
          }
#line 3912 "def.tab.c"
    break;

  case 138:
#line 765 "def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              if (defData->hasPort)
                 defData->Pin.addPortLayerPts((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
              else if (!defData->hadPortOnce)
                 defData->Pin.addLayerPts((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
            }
          }
#line 3925 "def.tab.c"
    break;

  case 139:
#line 774 "def.y"
                        { defData->dumb_mode = 1; }
#line 3931 "def.tab.c"
    break;

  case 140:
#line 775 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The POLYGON statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6509, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort) {
                   defData->Pin.addPortPolygon((yyvsp[0].string));
                } else if (defData->hadPortOnce) {
                   if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                     (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                     defData->defError(7418, "syntax error");
                     CHKERR();
                   }
                } else {
                   defData->Pin.addPolygon((yyvsp[0].string));
                }
              }
            }
            
            defData->Geometries.Reset();            
          }
#line 3967 "def.tab.c"
    break;

  case 141:
#line 807 "def.y"
          {
            if (defData->VersionNum >= 5.6) {  // only add if 5.6 or beyond
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolygonPts(&defData->Geometries);
                else if (!defData->hadPortOnce)
                   defData->Pin.addPolygonPts(&defData->Geometries);
              }
            }
          }
#line 3982 "def.tab.c"
    break;

  case 142:
#line 817 "def.y"
                    { defData->dumb_mode = 1; }
#line 3988 "def.tab.c"
    break;

  case 143:
#line 818 "def.y"
          {
            if (defData->VersionNum < 5.7) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The PIN VIA statement is available in version 5.7 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6556, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort) {
                   defData->Pin.addPortVia((yyvsp[-5].string), (int)(yyvsp[-2].dval),
                                               (int)(yyvsp[-1].dval), (yyvsp[-4].integer));
                } else if (defData->hadPortOnce) {
                   if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                     (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                     defData->defError(7418, "syntax error");
                     CHKERR();
                   }
                } else {
                   defData->Pin.addVia((yyvsp[-5].string), (int)(yyvsp[-2].dval),
                                               (int)(yyvsp[-1].dval), (yyvsp[-4].integer));
                }
              }
            }
          }
#line 4024 "def.tab.c"
    break;

  case 144:
#line 851 "def.y"
          {
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
              if (defData->hasPort) {
                 defData->Pin.setPortPlacement((yyvsp[-2].integer), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
                 defData->hasPort = 0;
                 defData->hadPortOnce = 1;
              } else if (defData->hadPortOnce) {
                 if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                   (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                   defData->defError(7418, "syntax error");
                   CHKERR();
                 }
              } else {
                 defData->Pin.setPlacement((yyvsp[-2].integer), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
              }
            }
          }
#line 4046 "def.tab.c"
    break;

  case 145:
#line 871 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINPARTIALMETALAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6510, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinPartialMetalArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4068 "def.tab.c"
    break;

  case 146:
#line 889 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINPARTIALMETALSIDEAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6511, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinPartialMetalSideArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4090 "def.tab.c"
    break;

  case 147:
#line 907 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINGATEAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6512, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
                defData->Pin.addAPinGateArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
            }
#line 4112 "def.tab.c"
    break;

  case 148:
#line 925 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINDIFFAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6513, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinDiffArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4134 "def.tab.c"
    break;

  case 149:
#line 942 "def.y"
                                                    {defData->dumb_mode=1;}
#line 4140 "def.tab.c"
    break;

  case 150:
#line 943 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINMAXAREACAR statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6514, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinMaxAreaCar((int)(yyvsp[-3].dval), (yyvsp[0].string)); 
          }
#line 4162 "def.tab.c"
    break;

  case 151:
#line 960 "def.y"
                                                        {defData->dumb_mode=1;}
#line 4168 "def.tab.c"
    break;

  case 152:
#line 962 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINMAXSIDEAREACAR statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6515, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinMaxSideAreaCar((int)(yyvsp[-3].dval), (yyvsp[0].string)); 
          }
#line 4190 "def.tab.c"
    break;

  case 153:
#line 980 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINPARTIALCUTAREA statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6516, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinPartialCutArea((int)(yyvsp[-1].dval), (yyvsp[0].string)); 
          }
#line 4212 "def.tab.c"
    break;

  case 154:
#line 997 "def.y"
                                                   {defData->dumb_mode=1;}
#line 4218 "def.tab.c"
    break;

  case 155:
#line 998 "def.y"
          {
            if (defData->VersionNum <= 5.3) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAPINMAXCUTCAR statement is available in version 5.4 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6517, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAPinMaxCutCar((int)(yyvsp[-3].dval), (yyvsp[0].string)); 
          }
#line 4240 "def.tab.c"
    break;

  case 156:
#line 1016 "def.y"
          {  // 5.5 syntax 
            if (defData->VersionNum < 5.5) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The ANTENNAMODEL statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6518, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
          }
#line 4260 "def.tab.c"
    break;

  case 158:
#line 1034 "def.y"
         { 
           if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->pinWarnings, defData->settings->PinWarnings)) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortLayerMask((int)(yyvsp[0].dval));
                else
                   defData->Pin.addLayerMask((int)(yyvsp[0].dval));
              }
           }
         }
#line 4275 "def.tab.c"
    break;

  case 159:
#line 1047 "def.y"
        { (yyval.integer) = 0; }
#line 4281 "def.tab.c"
    break;

  case 160:
#line 1049 "def.y"
         { 
           if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->pinWarnings, defData->settings->PinWarnings)) {
             (yyval.integer) = (yyvsp[0].dval);
           }
         }
#line 4291 "def.tab.c"
    break;

  case 162:
#line 1057 "def.y"
         { 
           if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->pinWarnings, defData->settings->PinWarnings)) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolyMask((int)(yyvsp[0].dval));
                else
                   defData->Pin.addPolyMask((int)(yyvsp[0].dval));
              }
           }
         }
#line 4306 "def.tab.c"
    break;

  case 164:
#line 1071 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The SPACING statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6519, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortLayerSpacing((int)(yyvsp[0].dval));
                else
                   defData->Pin.addLayerSpacing((int)(yyvsp[0].dval));
              }
            }
          }
#line 4333 "def.tab.c"
    break;

  case 165:
#line 1094 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "DESIGNRULEWIDTH statement is a version 5.6 and later syntax.\nYour def file is defined with version %g", defData->VersionNum);
                  defData->defError(6520, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortLayerDesignRuleWidth((int)(yyvsp[0].dval));
                else
                   defData->Pin.addLayerDesignRuleWidth((int)(yyvsp[0].dval));
              }
            }
          }
#line 4360 "def.tab.c"
    break;

  case 167:
#line 1119 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "SPACING statement is a version 5.6 and later syntax.\nYour def file is defined with version %g", defData->VersionNum);
                  defData->defError(6521, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolySpacing((int)(yyvsp[0].dval));
                else
                   defData->Pin.addPolySpacing((int)(yyvsp[0].dval));
              }
            }
          }
#line 4387 "def.tab.c"
    break;

  case 168:
#line 1142 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if ((defData->pinWarnings++ < defData->settings->PinWarnings) &&
                    (defData->pinWarnings++ < defData->settings->PinExtWarnings)) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The DESIGNRULEWIDTH statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                  defData->defError(6520, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            } else {
              if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk) {
                if (defData->hasPort)
                   defData->Pin.addPortPolyDesignRuleWidth((int)(yyvsp[0].dval));
                else
                   defData->Pin.addPolyDesignRuleWidth((int)(yyvsp[0].dval));
              }
            }
          }
#line 4414 "def.tab.c"
    break;

  case 169:
#line 1166 "def.y"
          { defData->aOxide = 1;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4423 "def.tab.c"
    break;

  case 170:
#line 1171 "def.y"
          { defData->aOxide = 2;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4432 "def.tab.c"
    break;

  case 171:
#line 1176 "def.y"
          { defData->aOxide = 3;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4441 "def.tab.c"
    break;

  case 172:
#line 1181 "def.y"
          { defData->aOxide = 4;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4450 "def.tab.c"
    break;

  case 173:
#line 1186 "def.y"
          { defData->aOxide = 5;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4459 "def.tab.c"
    break;

  case 174:
#line 1191 "def.y"
          { defData->aOxide = 6;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4468 "def.tab.c"
    break;

  case 175:
#line 1196 "def.y"
          { defData->aOxide = 7;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4477 "def.tab.c"
    break;

  case 176:
#line 1201 "def.y"
          { defData->aOxide = 8;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4486 "def.tab.c"
    break;

  case 177:
#line 1206 "def.y"
          { defData->aOxide = 9;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4495 "def.tab.c"
    break;

  case 178:
#line 1211 "def.y"
          { defData->aOxide = 10;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4504 "def.tab.c"
    break;

  case 179:
#line 1216 "def.y"
          { defData->aOxide = 11;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4513 "def.tab.c"
    break;

  case 180:
#line 1221 "def.y"
          { defData->aOxide = 12;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4522 "def.tab.c"
    break;

  case 181:
#line 1226 "def.y"
          { defData->aOxide = 13;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4531 "def.tab.c"
    break;

  case 182:
#line 1231 "def.y"
          { defData->aOxide = 14;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4540 "def.tab.c"
    break;

  case 183:
#line 1236 "def.y"
          { defData->aOxide = 15;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4549 "def.tab.c"
    break;

  case 184:
#line 1241 "def.y"
          { defData->aOxide = 16;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4558 "def.tab.c"
    break;

  case 185:
#line 1246 "def.y"
          { defData->aOxide = 17;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4567 "def.tab.c"
    break;

  case 186:
#line 1251 "def.y"
          { defData->aOxide = 18;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4576 "def.tab.c"
    break;

  case 187:
#line 1256 "def.y"
          { defData->aOxide = 19;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4585 "def.tab.c"
    break;

  case 188:
#line 1261 "def.y"
          { defData->aOxide = 20;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4594 "def.tab.c"
    break;

  case 189:
#line 1266 "def.y"
          { defData->aOxide = 21;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4603 "def.tab.c"
    break;

  case 190:
#line 1271 "def.y"
          { defData->aOxide = 22;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4612 "def.tab.c"
    break;

  case 191:
#line 1276 "def.y"
          { defData->aOxide = 23;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4621 "def.tab.c"
    break;

  case 192:
#line 1281 "def.y"
          { defData->aOxide = 24;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4630 "def.tab.c"
    break;

  case 193:
#line 1286 "def.y"
          { defData->aOxide = 25;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4639 "def.tab.c"
    break;

  case 194:
#line 1291 "def.y"
          { defData->aOxide = 26;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4648 "def.tab.c"
    break;

  case 195:
#line 1296 "def.y"
          { defData->aOxide = 27;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4657 "def.tab.c"
    break;

  case 196:
#line 1301 "def.y"
          { defData->aOxide = 28;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4666 "def.tab.c"
    break;

  case 197:
#line 1306 "def.y"
          { defData->aOxide = 29;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4675 "def.tab.c"
    break;

  case 198:
#line 1311 "def.y"
          { defData->aOxide = 30;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4684 "def.tab.c"
    break;

  case 199:
#line 1316 "def.y"
          { defData->aOxide = 31;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4693 "def.tab.c"
    break;

  case 200:
#line 1321 "def.y"
          { defData->aOxide = 32;
            if (defData->callbacks->PinCbk || defData->callbacks->PinExtCbk)
              defData->Pin.addAntennaModel(defData->aOxide);
          }
#line 4702 "def.tab.c"
    break;

  case 201:
#line 1328 "def.y"
          { (yyval.string) = (char*)"SIGNAL"; }
#line 4708 "def.tab.c"
    break;

  case 202:
#line 1330 "def.y"
          { (yyval.string) = (char*)"POWER"; }
#line 4714 "def.tab.c"
    break;

  case 203:
#line 1332 "def.y"
          { (yyval.string) = (char*)"GROUND"; }
#line 4720 "def.tab.c"
    break;

  case 204:
#line 1334 "def.y"
          { (yyval.string) = (char*)"CLOCK"; }
#line 4726 "def.tab.c"
    break;

  case 205:
#line 1336 "def.y"
          { (yyval.string) = (char*)"TIEOFF"; }
#line 4732 "def.tab.c"
    break;

  case 206:
#line 1338 "def.y"
          { (yyval.string) = (char*)"ANALOG"; }
#line 4738 "def.tab.c"
    break;

  case 207:
#line 1340 "def.y"
          { (yyval.string) = (char*)"SCAN"; }
#line 4744 "def.tab.c"
    break;

  case 208:
#line 1342 "def.y"
          { (yyval.string) = (char*)"RESET"; }
#line 4750 "def.tab.c"
    break;

  case 209:
#line 1346 "def.y"
          { (yyval.string) = (char*)""; }
#line 4756 "def.tab.c"
    break;

  case 210:
#line 1347 "def.y"
                  {defData->dumb_mode=1;}
#line 4762 "def.tab.c"
    break;

  case 211:
#line 1348 "def.y"
          { (yyval.string) = (yyvsp[0].string); }
#line 4768 "def.tab.c"
    break;

  case 212:
#line 1351 "def.y"
        { 
          if (defData->callbacks->PinEndCbk)
            CALLBACK(defData->callbacks->PinEndCbk, defrPinEndCbkType, 0);
        }
#line 4777 "def.tab.c"
    break;

  case 213:
#line 1356 "def.y"
                {defData->dumb_mode = 2; defData->no_num = 2; }
#line 4783 "def.tab.c"
    break;

  case 214:
#line 1358 "def.y"
        {
          if (defData->callbacks->RowCbk) {
            defData->rowName = (yyvsp[-4].string);
            defData->Row.setup((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-2].dval), (yyvsp[-1].dval), (yyvsp[0].integer));
          }
        }
#line 4794 "def.tab.c"
    break;

  case 215:
#line 1366 "def.y"
        {
          if (defData->callbacks->RowCbk) 
            CALLBACK(defData->callbacks->RowCbk, defrRowCbkType, &defData->Row);
        }
#line 4803 "def.tab.c"
    break;

  case 216:
#line 1372 "def.y"
        {
          if (defData->VersionNum < 5.6) {
            if (defData->callbacks->RowCbk) {
              if (defData->rowWarnings++ < defData->settings->RowWarnings) {
                defData->defError(6523, "Invalid ROW statement defined in the DEF file. The DO statement which is required in the ROW statement is not defined.\nUpdate your DEF file with a DO statement.");
                CHKERR();
              }
            }
          }
        }
#line 4818 "def.tab.c"
    break;

  case 217:
#line 1383 "def.y"
        {
          // 06/05/2002 - pcr 448455 
          // Check for 1 and 0 in the correct position 
          // 07/26/2002 - Commented out due to pcr 459218 
          if (defData->hasDoStep) {
            // 04/29/2004 - pcr 695535 
            // changed the testing 
            if ((((yyvsp[-1].dval) == 1) && (defData->yStep == 0)) ||
                (((yyvsp[-3].dval) == 1) && (defData->xStep == 0))) {
              // do nothing 
            } else 
              if (defData->VersionNum < 5.6) {
                if (defData->callbacks->RowCbk) {
                  if (defData->rowWarnings++ < defData->settings->RowWarnings) {
                    defData->defMsg = (char*)malloc(1000);
                    sprintf(defData->defMsg,
                            "The DO statement in the ROW statement with the name %s has invalid syntax.\nThe valid syntax is \"DO numX BY 1 STEP spaceX 0 | DO 1 BY numY STEP 0 spaceY\".\nSpecify the valid syntax and try again.", defData->rowName);
                    defData->defWarning(7018, defData->defMsg);
                    free(defData->defMsg);
                    }
                  }
              }
          }
          // pcr 459218 - Error if at least numX or numY does not equal 1 
          if (((yyvsp[-3].dval) != 1) && ((yyvsp[-1].dval) != 1)) {
            if (defData->callbacks->RowCbk) {
              if (defData->rowWarnings++ < defData->settings->RowWarnings) {
                defData->defError(6524, "Invalid syntax specified. The valid syntax is either \"DO 1 BY num or DO num BY 1\". Specify the valid syntax and try again.");
                CHKERR();
              }
            }
          }
          if (defData->callbacks->RowCbk)
            defData->Row.setDo(ROUND((yyvsp[-3].dval)), ROUND((yyvsp[-1].dval)), defData->xStep, defData->yStep);
        }
#line 4858 "def.tab.c"
    break;

  case 218:
#line 1420 "def.y"
        {
          defData->hasDoStep = 0;
        }
#line 4866 "def.tab.c"
    break;

  case 219:
#line 1424 "def.y"
        {
          defData->hasDoStep = 1;
          defData->Row.setHasDoStep();
          defData->xStep = (yyvsp[-1].dval);
          defData->yStep = (yyvsp[0].dval);
        }
#line 4877 "def.tab.c"
    break;

  case 222:
#line 1435 "def.y"
                            {defData->dumb_mode = DEF_MAX_INT; }
#line 4883 "def.tab.c"
    break;

  case 223:
#line 1437 "def.y"
         { defData->dumb_mode = 0; }
#line 4889 "def.tab.c"
    break;

  case 226:
#line 1444 "def.y"
        {
          if (defData->callbacks->RowCbk) {
             char propTp;
             char* str = defData->ringCopy("                       ");
             propTp =  defData->session->RowProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "ROW");
             // For backword compatibility, also set the string value 
             sprintf(str, "%g", (yyvsp[0].dval));
             defData->Row.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 4905 "def.tab.c"
    break;

  case 227:
#line 1456 "def.y"
        {
          if (defData->callbacks->RowCbk) {
             char propTp;
             propTp =  defData->session->RowProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "ROW");
             defData->Row.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 4918 "def.tab.c"
    break;

  case 228:
#line 1465 "def.y"
        {
          if (defData->callbacks->RowCbk) {
             char propTp;
             propTp =  defData->session->RowProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "ROW");
             defData->Row.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 4931 "def.tab.c"
    break;

  case 229:
#line 1475 "def.y"
        {
          if (defData->callbacks->TrackCbk) {
            defData->Track.setup((yyvsp[-1].string));
          }
        }
#line 4941 "def.tab.c"
    break;

  case 230:
#line 1481 "def.y"
        {
          if (((yyvsp[-4].dval) <= 0) && (defData->VersionNum >= 5.4)) {
            if (defData->callbacks->TrackCbk)
              if (defData->trackWarnings++ < defData->settings->TrackWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The DO number %g in TRACK is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-4].dval));
                defData->defError(6525, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if ((yyvsp[-2].dval) < 0) {
            if (defData->callbacks->TrackCbk)
              if (defData->trackWarnings++ < defData->settings->TrackWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The STEP number %g in TRACK is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-2].dval));
                defData->defError(6526, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if (defData->callbacks->TrackCbk) {
            defData->Track.setDo(ROUND((yyvsp[-7].dval)), ROUND((yyvsp[-4].dval)), (yyvsp[-2].dval));
            CALLBACK(defData->callbacks->TrackCbk, defrTrackCbkType, &defData->Track);
          }
        }
#line 4972 "def.tab.c"
    break;

  case 231:
#line 1509 "def.y"
        {
          (yyval.string) = (yyvsp[0].string);
        }
#line 4980 "def.tab.c"
    break;

  case 232:
#line 1514 "def.y"
            { (yyval.string) = (char*)"X";}
#line 4986 "def.tab.c"
    break;

  case 233:
#line 1516 "def.y"
            { (yyval.string) = (char*)"Y";}
#line 4992 "def.tab.c"
    break;

  case 236:
#line 1522 "def.y"
           { 
              if (defData->validateMaskInput((int)(yyvsp[-1].dval), defData->trackWarnings, defData->settings->TrackWarnings)) {
                  if (defData->callbacks->TrackCbk) {
                    defData->Track.addMask((yyvsp[-1].dval), (yyvsp[0].integer));
                  }
               }
            }
#line 5004 "def.tab.c"
    break;

  case 237:
#line 1532 "def.y"
        { (yyval.integer) = 0; }
#line 5010 "def.tab.c"
    break;

  case 238:
#line 1534 "def.y"
        { (yyval.integer) = 1; }
#line 5016 "def.tab.c"
    break;

  case 240:
#line 1537 "def.y"
                  { defData->dumb_mode = 1000; }
#line 5022 "def.tab.c"
    break;

  case 241:
#line 1538 "def.y"
            { defData->dumb_mode = 0; }
#line 5028 "def.tab.c"
    break;

  case 244:
#line 1545 "def.y"
        {
          if (defData->callbacks->TrackCbk)
            defData->Track.addLayer((yyvsp[0].string));
        }
#line 5037 "def.tab.c"
    break;

  case 245:
#line 1552 "def.y"
        {
          if ((yyvsp[-3].dval) <= 0) {
            if (defData->callbacks->GcellGridCbk)
              if (defData->gcellGridWarnings++ < defData->settings->GcellGridWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The DO number %g in GCELLGRID is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-3].dval));
                defData->defError(6527, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if ((yyvsp[-1].dval) < 0) {
            if (defData->callbacks->GcellGridCbk)
              if (defData->gcellGridWarnings++ < defData->settings->GcellGridWarnings) {
                defData->defMsg = (char*)malloc(1000);
                sprintf (defData->defMsg,
                   "The STEP number %g in GCELLGRID is invalid.\nThe number value has to be greater than 0. Specify the valid syntax and try again.", (yyvsp[-1].dval));
                defData->defError(6528, defData->defMsg);
                free(defData->defMsg);
              }
          }
          if (defData->callbacks->GcellGridCbk) {
            defData->GcellGrid.setup((yyvsp[-6].string), ROUND((yyvsp[-5].dval)), ROUND((yyvsp[-3].dval)), (yyvsp[-1].dval));
            CALLBACK(defData->callbacks->GcellGridCbk, defrGcellGridCbkType, &defData->GcellGrid);
          }
        }
#line 5068 "def.tab.c"
    break;

  case 246:
#line 1580 "def.y"
        {
          if (defData->callbacks->ExtensionCbk)
             CALLBACK(defData->callbacks->ExtensionCbk, defrExtensionCbkType, &defData->History_text[0]);
        }
#line 5077 "def.tab.c"
    break;

  case 247:
#line 1586 "def.y"
        { }
#line 5083 "def.tab.c"
    break;

  case 249:
#line 1592 "def.y"
        {
          if (defData->callbacks->ViaStartCbk)
            CALLBACK(defData->callbacks->ViaStartCbk, defrViaStartCbkType, ROUND((yyvsp[-1].dval)));
        }
#line 5092 "def.tab.c"
    break;

  case 252:
#line 1601 "def.y"
                     {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5098 "def.tab.c"
    break;

  case 253:
#line 1602 "def.y"
            {
              if (defData->callbacks->ViaCbk) defData->Via.setup((yyvsp[0].string));
              defData->viaRule = 0;
            }
#line 5107 "def.tab.c"
    break;

  case 254:
#line 1607 "def.y"
            {
              if (defData->callbacks->ViaCbk)
                CALLBACK(defData->callbacks->ViaCbk, defrViaCbkType, &defData->Via);
              defData->Via.clear();
            }
#line 5117 "def.tab.c"
    break;

  case 257:
#line 1617 "def.y"
                       {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5123 "def.tab.c"
    break;

  case 258:
#line 1618 "def.y"
            { 
              if (defData->callbacks->ViaCbk)
                if (defData->validateMaskInput((yyvsp[-2].integer), defData->viaWarnings, defData->settings->ViaWarnings)) {
                    defData->Via.addLayer((yyvsp[-3].string), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y, (yyvsp[-2].integer));
                }
            }
#line 5134 "def.tab.c"
    break;

  case 259:
#line 1624 "def.y"
                        { defData->dumb_mode = 1; }
#line 5140 "def.tab.c"
    break;

  case 260:
#line 1625 "def.y"
            {
              if (defData->VersionNum < 5.6) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defMsg = (char*)malloc(1000);
                    sprintf (defData->defMsg,
                       "The POLYGON statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                    defData->defError(6509, defData->defMsg);
                    free(defData->defMsg);
                    CHKERR();
                  }
                }
              }
              
              defData->Geometries.Reset();
              
            }
#line 5162 "def.tab.c"
    break;

  case 261:
#line 1643 "def.y"
            {
              if (defData->VersionNum >= 5.6) {  // only add if 5.6 or beyond
                if (defData->callbacks->ViaCbk)
                  if (defData->validateMaskInput((yyvsp[-5].integer), defData->viaWarnings, defData->settings->ViaWarnings)) {
                    defData->Via.addPolygon((yyvsp[-6].string), &defData->Geometries, (yyvsp[-5].integer));
                  }
              }
            }
#line 5175 "def.tab.c"
    break;

  case 262:
#line 1651 "def.y"
                            {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5181 "def.tab.c"
    break;

  case 263:
#line 1652 "def.y"
            {
              if (defData->VersionNum < 5.6) {
                if (defData->callbacks->ViaCbk)
                  defData->Via.addPattern((yyvsp[0].string));
              } else
                if (defData->callbacks->ViaCbk)
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings)
                    defData->defWarning(7019, "The PATTERNNAME statement is obsolete in version 5.6 and later.\nThe DEF parser will ignore this statement."); 
            }
#line 5195 "def.tab.c"
    break;

  case 264:
#line 1661 "def.y"
                        {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5201 "def.tab.c"
    break;

  case 265:
#line 1663 "def.y"
                       {defData->dumb_mode = 3;defData->no_num = 1; }
#line 5207 "def.tab.c"
    break;

  case 266:
#line 1666 "def.y"
            {
               defData->viaRule = 1;
               if (defData->VersionNum < 5.6) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defMsg = (char*)malloc(1000);
                    sprintf (defData->defMsg,
                       "The VIARULE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                    defData->defError(6557, defData->defMsg);
                    free(defData->defMsg);
                    CHKERR();
                  }
                }
              } else {
                if (defData->callbacks->ViaCbk)
                   defData->Via.addViaRule((yyvsp[-20].string), (int)(yyvsp[-17].dval), (int)(yyvsp[-16].dval), (yyvsp[-12].string), (yyvsp[-11].string),
                                             (yyvsp[-10].string), (int)(yyvsp[-7].dval), (int)(yyvsp[-6].dval), (int)(yyvsp[-3].dval),
                                             (int)(yyvsp[-2].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval)); 
              }
            }
#line 5232 "def.tab.c"
    break;

  case 268:
#line 1688 "def.y"
          { 
            if (defData->callbacks->ViaExtCbk)
              CALLBACK(defData->callbacks->ViaExtCbk, defrViaExtCbkType, &defData->History_text[0]);
          }
#line 5241 "def.tab.c"
    break;

  case 269:
#line 1694 "def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6559, "The ROWCOL statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addRowCol((int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }
#line 5257 "def.tab.c"
    break;

  case 270:
#line 1706 "def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6560, "The ORIGIN statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addOrigin((int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }
#line 5273 "def.tab.c"
    break;

  case 271:
#line 1718 "def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6561, "The OFFSET statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addOffset((int)(yyvsp[-3].dval), (int)(yyvsp[-2].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }
#line 5289 "def.tab.c"
    break;

  case 272:
#line 1729 "def.y"
                        {defData->dumb_mode = 1;defData->no_num = 1; }
#line 5295 "def.tab.c"
    break;

  case 273:
#line 1730 "def.y"
            {
              if (!defData->viaRule) {
                if (defData->callbacks->ViaCbk) {
                  if (defData->viaWarnings++ < defData->settings->ViaWarnings) {
                    defData->defError(6562, "The PATTERN statement is missing from the VIARULE statement. Ensure that it exists in the VIARULE statement.");
                    CHKERR();
                  }
                }
              } else if (defData->callbacks->ViaCbk)
                 defData->Via.addCutPattern((yyvsp[0].string));
            }
#line 5311 "def.tab.c"
    break;

  case 274:
#line 1743 "def.y"
          { defData->Geometries.startList((yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5317 "def.tab.c"
    break;

  case 275:
#line 1746 "def.y"
          { defData->Geometries.addToList((yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5323 "def.tab.c"
    break;

  case 278:
#line 1753 "def.y"
          {
            defData->save_x = (yyvsp[-2].dval);
            defData->save_y = (yyvsp[-1].dval);
            (yyval.pt).x = ROUND((yyvsp[-2].dval));
            (yyval.pt).y = ROUND((yyvsp[-1].dval));
          }
#line 5334 "def.tab.c"
    break;

  case 279:
#line 1760 "def.y"
          {
            defData->save_y = (yyvsp[-1].dval);
            (yyval.pt).x = ROUND(defData->save_x);
            (yyval.pt).y = ROUND((yyvsp[-1].dval));
          }
#line 5344 "def.tab.c"
    break;

  case 280:
#line 1766 "def.y"
          {
            defData->save_x = (yyvsp[-2].dval);
            (yyval.pt).x = ROUND((yyvsp[-2].dval));
            (yyval.pt).y = ROUND(defData->save_y);
          }
#line 5354 "def.tab.c"
    break;

  case 281:
#line 1772 "def.y"
          {
            (yyval.pt).x = ROUND(defData->save_x);
            (yyval.pt).y = ROUND(defData->save_y);
          }
#line 5363 "def.tab.c"
    break;

  case 282:
#line 1778 "def.y"
      { (yyval.integer) = 0; }
#line 5369 "def.tab.c"
    break;

  case 283:
#line 1780 "def.y"
      { (yyval.integer) = (yyvsp[0].dval); }
#line 5375 "def.tab.c"
    break;

  case 284:
#line 1783 "def.y"
        { 
          if (defData->callbacks->ViaEndCbk)
            CALLBACK(defData->callbacks->ViaEndCbk, defrViaEndCbkType, 0);
        }
#line 5384 "def.tab.c"
    break;

  case 285:
#line 1789 "def.y"
        {
          if (defData->callbacks->RegionEndCbk)
            CALLBACK(defData->callbacks->RegionEndCbk, defrRegionEndCbkType, 0);
        }
#line 5393 "def.tab.c"
    break;

  case 286:
#line 1795 "def.y"
        {
          if (defData->callbacks->RegionStartCbk)
            CALLBACK(defData->callbacks->RegionStartCbk, defrRegionStartCbkType, ROUND((yyvsp[-1].dval)));
        }
#line 5402 "def.tab.c"
    break;

  case 288:
#line 1802 "def.y"
            {}
#line 5408 "def.tab.c"
    break;

  case 289:
#line 1804 "def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5414 "def.tab.c"
    break;

  case 290:
#line 1805 "def.y"
        {
          if (defData->callbacks->RegionCbk)
             defData->Region.setup((yyvsp[0].string));
          defData->regTypeDef = 0;
        }
#line 5424 "def.tab.c"
    break;

  case 291:
#line 1811 "def.y"
        { CALLBACK(defData->callbacks->RegionCbk, defrRegionCbkType, &defData->Region); }
#line 5430 "def.tab.c"
    break;

  case 292:
#line 1815 "def.y"
        { if (defData->callbacks->RegionCbk)
          defData->Region.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5437 "def.tab.c"
    break;

  case 293:
#line 1818 "def.y"
        { if (defData->callbacks->RegionCbk)
          defData->Region.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 5444 "def.tab.c"
    break;

  case 296:
#line 1826 "def.y"
                               {defData->dumb_mode = DEF_MAX_INT; }
#line 5450 "def.tab.c"
    break;

  case 297:
#line 1828 "def.y"
         { defData->dumb_mode = 0; }
#line 5456 "def.tab.c"
    break;

  case 298:
#line 1830 "def.y"
         {
           if (defData->regTypeDef) {
              if (defData->callbacks->RegionCbk) {
                if (defData->regionWarnings++ < defData->settings->RegionWarnings) {
                  defData->defError(6563, "The TYPE statement already exists. It has been defined in the REGION statement.");
                  CHKERR();
                }
              }
           }
           if (defData->callbacks->RegionCbk) defData->Region.setType((yyvsp[0].string));
           defData->regTypeDef = 1;
         }
#line 5473 "def.tab.c"
    break;

  case 301:
#line 1849 "def.y"
        {
          if (defData->callbacks->RegionCbk) {
             char propTp;
             char* str = defData->ringCopy("                       ");
             propTp = defData->session->RegionProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "REGION");
             // For backword compatibility, also set the string value 
             // We will use a temporary string to store the number.
             // The string space is borrowed from the ring buffer
             // in the lexer.
             sprintf(str, "%g", (yyvsp[0].dval));
             defData->Region.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 5492 "def.tab.c"
    break;

  case 302:
#line 1864 "def.y"
        {
          if (defData->callbacks->RegionCbk) {
             char propTp;
             propTp = defData->session->RegionProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "REGION");
             defData->Region.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5505 "def.tab.c"
    break;

  case 303:
#line 1873 "def.y"
        {
          if (defData->callbacks->RegionCbk) {
             char propTp;
             propTp = defData->session->RegionProp.propType((yyvsp[-1].string));
             CHKPROPTYPE(propTp, (yyvsp[-1].string), "REGION");
             defData->Region.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5518 "def.tab.c"
    break;

  case 304:
#line 1883 "def.y"
            { (yyval.string) = (char*)"FENCE"; }
#line 5524 "def.tab.c"
    break;

  case 305:
#line 1885 "def.y"
            { (yyval.string) = (char*)"GUIDE"; }
#line 5530 "def.tab.c"
    break;

  case 306:
#line 1888 "def.y"
         {
           if (defData->VersionNum < 5.8) {
                if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                   defData->defMsg = (char*)malloc(10000);
                   sprintf (defData->defMsg,
                     "The MASKSHIFT statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                   defData->defError(7415, defData->defMsg);
                   free(defData->defMsg);
                   CHKERR();
                }
            }
            if (defData->callbacks->ComponentMaskShiftLayerCbk) {
                CALLBACK(defData->callbacks->ComponentMaskShiftLayerCbk, defrComponentMaskShiftLayerCbkType, &defData->ComponentMaskShiftLayer);
            }
         }
#line 5550 "def.tab.c"
    break;

  case 308:
#line 1908 "def.y"
         { 
            if (defData->callbacks->ComponentStartCbk)
              CALLBACK(defData->callbacks->ComponentStartCbk, defrComponentStartCbkType,
                       ROUND((yyvsp[-1].dval)));
         }
#line 5560 "def.tab.c"
    break;

  case 311:
#line 1919 "def.y"
        {
            if (defData->callbacks->ComponentMaskShiftLayerCbk) {
              defData->ComponentMaskShiftLayer.addMaskShiftLayer((yyvsp[0].string));
            }
        }
#line 5570 "def.tab.c"
    break;

  case 314:
#line 1930 "def.y"
         {
            if (defData->callbacks->ComponentCbk)
              CALLBACK(defData->callbacks->ComponentCbk, defrComponentCbkType, &defData->Component);
         }
#line 5579 "def.tab.c"
    break;

  case 315:
#line 1936 "def.y"
         {
            defData->dumb_mode = 0;
            defData->no_num = 0;
         }
#line 5588 "def.tab.c"
    break;

  case 316:
#line 1941 "def.y"
                      {defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT; }
#line 5594 "def.tab.c"
    break;

  case 317:
#line 1943 "def.y"
         {
            if (defData->callbacks->ComponentCbk)
              defData->Component.IdAndName((yyvsp[-1].string), (yyvsp[0].string));
         }
#line 5603 "def.tab.c"
    break;

  case 318:
#line 1949 "def.y"
        { }
#line 5609 "def.tab.c"
    break;

  case 319:
#line 1951 "def.y"
            {
              if (defData->callbacks->ComponentCbk)
                defData->Component.addNet("*");
            }
#line 5618 "def.tab.c"
    break;

  case 320:
#line 1956 "def.y"
            {
              if (defData->callbacks->ComponentCbk)
                defData->Component.addNet((yyvsp[0].string));
            }
#line 5627 "def.tab.c"
    break;

  case 335:
#line 1971 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            CALLBACK(defData->callbacks->ComponentExtCbk, defrComponentExtCbkType,
                     &defData->History_text[0]);
        }
#line 5637 "def.tab.c"
    break;

  case 336:
#line 1977 "def.y"
                          {defData->dumb_mode=1; defData->no_num = 1; }
#line 5643 "def.tab.c"
    break;

  case 337:
#line 1978 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setEEQ((yyvsp[0].string));
        }
#line 5652 "def.tab.c"
    break;

  case 338:
#line 1983 "def.y"
                              { defData->dumb_mode = 2;  defData->no_num = 2; }
#line 5658 "def.tab.c"
    break;

  case 339:
#line 1985 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
             defData->Component.setGenerate((yyvsp[-1].string), (yyvsp[0].string));
        }
#line 5667 "def.tab.c"
    break;

  case 340:
#line 1991 "def.y"
      { (yyval.string) = (char*)""; }
#line 5673 "def.tab.c"
    break;

  case 341:
#line 1993 "def.y"
      { (yyval.string) = (yyvsp[0].string); }
#line 5679 "def.tab.c"
    break;

  case 342:
#line 1996 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setSource((yyvsp[0].string));
        }
#line 5688 "def.tab.c"
    break;

  case 343:
#line 2002 "def.y"
            { (yyval.string) = (char*)"NETLIST"; }
#line 5694 "def.tab.c"
    break;

  case 344:
#line 2004 "def.y"
            { (yyval.string) = (char*)"DIST"; }
#line 5700 "def.tab.c"
    break;

  case 345:
#line 2006 "def.y"
            { (yyval.string) = (char*)"USER"; }
#line 5706 "def.tab.c"
    break;

  case 346:
#line 2008 "def.y"
            { (yyval.string) = (char*)"TIMING"; }
#line 5712 "def.tab.c"
    break;

  case 347:
#line 2013 "def.y"
        { }
#line 5718 "def.tab.c"
    break;

  case 348:
#line 2015 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setRegionName((yyvsp[0].string));
        }
#line 5727 "def.tab.c"
    break;

  case 349:
#line 2021 "def.y"
        { 
          // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->ComponentCbk)
               defData->Component.setRegionBounds((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, 
                                                            (yyvsp[0].pt).x, (yyvsp[0].pt).y);
          }
          else
            defData->defWarning(7020, "The REGION pt pt statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
        }
#line 5742 "def.tab.c"
    break;

  case 350:
#line 2032 "def.y"
        { 
          // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->ComponentCbk)
               defData->Component.setRegionBounds((yyvsp[-1].pt).x, (yyvsp[-1].pt).y,
                                                            (yyvsp[0].pt).x, (yyvsp[0].pt).y);
          }
          else
            defData->defWarning(7020, "The REGION pt pt statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
        }
#line 5757 "def.tab.c"
    break;

  case 351:
#line 2044 "def.y"
        {
          if (defData->VersionNum < 5.6) {
             if (defData->callbacks->ComponentCbk) {
               if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                 defData->defMsg = (char*)malloc(1000);
                 sprintf (defData->defMsg,
                    "The HALO statement is a version 5.6 and later syntax.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                 defData->defError(6529, defData->defMsg);
                 free(defData->defMsg);
                 CHKERR();
               }
             }
          }
        }
#line 5776 "def.tab.c"
    break;

  case 352:
#line 2059 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setHalo((int)(yyvsp[-3].dval), (int)(yyvsp[-2].dval),
                                                 (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
        }
#line 5786 "def.tab.c"
    break;

  case 354:
#line 2067 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->ComponentCbk) {
             if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                defData->defMsg = (char*)malloc(10000);
                sprintf (defData->defMsg,
                  "The HALO SOFT is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                defData->defError(6550, defData->defMsg);
                free(defData->defMsg);
                CHKERR();
             }
           }
        } else {
           if (defData->callbacks->ComponentCbk)
             defData->Component.setHaloSoft();
        }
      }
#line 5808 "def.tab.c"
    break;

  case 355:
#line 2086 "def.y"
                                       { defData->dumb_mode = 2; defData->no_num = 2; }
#line 5814 "def.tab.c"
    break;

  case 356:
#line 2087 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->ComponentCbk) {
             if (defData->componentWarnings++ < defData->settings->ComponentWarnings) {
                defData->defMsg = (char*)malloc(10000);
                sprintf (defData->defMsg,
                  "The ROUTEHALO is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                defData->defError(6551, defData->defMsg);
                free(defData->defMsg);
                CHKERR();
             }
           }
        } else {
           if (defData->callbacks->ComponentCbk)
             defData->Component.setRouteHalo(
                            (int)(yyvsp[-3].dval), (yyvsp[-1].string), (yyvsp[0].string));
        }
      }
#line 5837 "def.tab.c"
    break;

  case 357:
#line 2106 "def.y"
                              { defData->dumb_mode = DEF_MAX_INT; }
#line 5843 "def.tab.c"
    break;

  case 358:
#line 2108 "def.y"
      { defData->dumb_mode = 0; }
#line 5849 "def.tab.c"
    break;

  case 361:
#line 2115 "def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            char propTp;
            char* str = defData->ringCopy("                       ");
            propTp = defData->session->CompProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "COMPONENT");
            sprintf(str, "%g", (yyvsp[0].dval));
            defData->Component.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 5864 "def.tab.c"
    break;

  case 362:
#line 2126 "def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            char propTp;
            propTp = defData->session->CompProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "COMPONENT");
            defData->Component.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5877 "def.tab.c"
    break;

  case 363:
#line 2135 "def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            char propTp;
            propTp = defData->session->CompProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "COMPONENT");
            defData->Component.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 5890 "def.tab.c"
    break;

  case 364:
#line 2145 "def.y"
        { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5896 "def.tab.c"
    break;

  case 365:
#line 2147 "def.y"
                            { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5902 "def.tab.c"
    break;

  case 366:
#line 2149 "def.y"
        { 
          if (defData->VersionNum < 5.6) {
            if (defData->callbacks->ComponentCbk) {
              defData->Component.setForeignName((yyvsp[-2].string));
              defData->Component.setForeignLocation((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
            }
         } else
            if (defData->callbacks->ComponentCbk)
              if (defData->componentWarnings++ < defData->settings->ComponentWarnings)
                defData->defWarning(7021, "The FOREIGN statement is obsolete in version 5.6 and later.\nThe DEF parser will ignore this statement.");
         }
#line 5918 "def.tab.c"
    break;

  case 367:
#line 2163 "def.y"
         { (yyval.pt) = (yyvsp[0].pt); }
#line 5924 "def.tab.c"
    break;

  case 368:
#line 2165 "def.y"
         { (yyval.pt).x = ROUND((yyvsp[-1].dval)); (yyval.pt).y = ROUND((yyvsp[0].dval)); }
#line 5930 "def.tab.c"
    break;

  case 369:
#line 2168 "def.y"
        {
          if (defData->callbacks->ComponentCbk) {
            defData->Component.setPlacementStatus((yyvsp[-2].integer));
            defData->Component.setPlacementLocation((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
          }
        }
#line 5941 "def.tab.c"
    break;

  case 370:
#line 2175 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setPlacementStatus(
                                         DEFI_COMPONENT_UNPLACED);
            defData->Component.setPlacementLocation(-1, -1, -1);
        }
#line 5952 "def.tab.c"
    break;

  case 371:
#line 2182 "def.y"
        {
          if (defData->VersionNum < 5.4) {   // PCR 495463 
            if (defData->callbacks->ComponentCbk) {
              defData->Component.setPlacementStatus(
                                          DEFI_COMPONENT_UNPLACED);
              defData->Component.setPlacementLocation((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer));
            }
          } else {
            if (defData->componentWarnings++ < defData->settings->ComponentWarnings)
               defData->defWarning(7022, "In the COMPONENT UNPLACED statement, point and orient are invalid in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
#line 5969 "def.tab.c"
    break;

  case 372:
#line 2196 "def.y"
                           { defData->dumb_mode = 1; defData->no_num = 1; }
#line 5975 "def.tab.c"
    break;

  case 373:
#line 2197 "def.y"
        {  
          if (defData->callbacks->ComponentCbk) {
            if (defData->validateMaskShiftInput((yyvsp[0].string), defData->componentWarnings, defData->settings->ComponentWarnings)) {
                defData->Component.setMaskShift((yyvsp[0].string));
            }
          }
        }
#line 5987 "def.tab.c"
    break;

  case 374:
#line 2206 "def.y"
        { (yyval.integer) = DEFI_COMPONENT_FIXED; }
#line 5993 "def.tab.c"
    break;

  case 375:
#line 2208 "def.y"
        { (yyval.integer) = DEFI_COMPONENT_COVER; }
#line 5999 "def.tab.c"
    break;

  case 376:
#line 2210 "def.y"
        { (yyval.integer) = DEFI_COMPONENT_PLACED; }
#line 6005 "def.tab.c"
    break;

  case 377:
#line 2213 "def.y"
        {
          if (defData->callbacks->ComponentCbk)
            defData->Component.setWeight(ROUND((yyvsp[0].dval)));
        }
#line 6014 "def.tab.c"
    break;

  case 378:
#line 2219 "def.y"
        { 
          if (defData->callbacks->ComponentCbk)
            CALLBACK(defData->callbacks->ComponentEndCbk, defrComponentEndCbkType, 0);
        }
#line 6023 "def.tab.c"
    break;

  case 380:
#line 2228 "def.y"
        { 
          if (defData->callbacks->NetStartCbk)
            CALLBACK(defData->callbacks->NetStartCbk, defrNetStartCbkType, ROUND((yyvsp[-1].dval)));
          defData->netOsnet = 1;
        }
#line 6033 "def.tab.c"
    break;

  case 383:
#line 2239 "def.y"
        { 
          if (defData->callbacks->NetCbk)
            CALLBACK(defData->callbacks->NetCbk, defrNetCbkType, &defData->Net);
        }
#line 6042 "def.tab.c"
    break;

  case 384:
#line 2250 "def.y"
        {defData->dumb_mode = 0; defData->no_num = 0; }
#line 6048 "def.tab.c"
    break;

  case 385:
#line 2253 "def.y"
               {defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT; defData->nondef_is_keyword = TRUE; defData->mustjoin_is_keyword = TRUE;}
#line 6054 "def.tab.c"
    break;

  case 387:
#line 2256 "def.y"
        {
          // 9/22/1999 
          // this is shared by both net and special net 
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.setName((yyvsp[0].string));
          if (defData->callbacks->NetNameCbk)
            CALLBACK(defData->callbacks->NetNameCbk, defrNetNameCbkType, (yyvsp[0].string));
        }
#line 6067 "def.tab.c"
    break;

  case 389:
#line 2264 "def.y"
                                  {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6073 "def.tab.c"
    break;

  case 390:
#line 2265 "def.y"
        {
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addMustPin((yyvsp[-3].string), (yyvsp[-1].string), 0);
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6084 "def.tab.c"
    break;

  case 393:
#line 2276 "def.y"
                             {defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT;}
#line 6090 "def.tab.c"
    break;

  case 394:
#line 2278 "def.y"
        {
          // 9/22/1999 
          // since the code is shared by both net & special net, 
          // need to check on both flags 
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addPin((yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[-1].integer));
          // 1/14/2000 - pcr 289156 
          // reset defData->dumb_mode & defData->no_num to 3 , just in case 
          // the next statement is another net_connection 
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6107 "def.tab.c"
    break;

  case 395:
#line 2290 "def.y"
                  {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6113 "def.tab.c"
    break;

  case 396:
#line 2291 "def.y"
        {
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addPin("*", (yyvsp[-2].string), (yyvsp[-1].integer));
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6124 "def.tab.c"
    break;

  case 397:
#line 2297 "def.y"
                    {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6130 "def.tab.c"
    break;

  case 398:
#line 2298 "def.y"
        {
          if ((defData->callbacks->NetCbk && (defData->netOsnet==1)) || (defData->callbacks->SNetCbk && (defData->netOsnet==2)))
            defData->Net.addPin("PIN", (yyvsp[-2].string), (yyvsp[-1].integer));
          defData->dumb_mode = 3;
          defData->no_num = 3;
        }
#line 6141 "def.tab.c"
    break;

  case 399:
#line 2306 "def.y"
          { (yyval.integer) = 0; }
#line 6147 "def.tab.c"
    break;

  case 400:
#line 2308 "def.y"
        {
          if (defData->callbacks->NetConnectionExtCbk)
            CALLBACK(defData->callbacks->NetConnectionExtCbk, defrNetConnectionExtCbkType,
              &defData->History_text[0]);
          (yyval.integer) = 0;
        }
#line 6158 "def.tab.c"
    break;

  case 401:
#line 2315 "def.y"
        { (yyval.integer) = 1; }
#line 6164 "def.tab.c"
    break;

  case 404:
#line 2324 "def.y"
        {  
          if (defData->callbacks->NetCbk) defData->Net.addWire((yyvsp[0].string), NULL);
        }
#line 6172 "def.tab.c"
    break;

  case 405:
#line 2328 "def.y"
        {
          defData->by_is_keyword = FALSE;
          defData->do_is_keyword = FALSE;
          defData->new_is_keyword = FALSE;
          defData->nondef_is_keyword = FALSE;
          defData->mustjoin_is_keyword = FALSE;
          defData->step_is_keyword = FALSE;
          defData->orient_is_keyword = FALSE;
          defData->virtual_is_keyword = FALSE;
          defData->rect_is_keyword = FALSE;
          defData->mask_is_keyword = FALSE;
          defData->needNPCbk = 0;
        }
#line 6190 "def.tab.c"
    break;

  case 406:
#line 2343 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setSource((yyvsp[0].string)); }
#line 6196 "def.tab.c"
    break;

  case 407:
#line 2346 "def.y"
        {
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->NetCbk) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                 defData->defMsg = (char*)malloc(1000);
                 sprintf (defData->defMsg,
                    "The FIXEDBUMP statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                 defData->defError(6530, defData->defMsg);
                 free(defData->defMsg);
                 CHKERR();
              }
            }
          }
          if (defData->callbacks->NetCbk) defData->Net.setFixedbump();
        }
#line 6216 "def.tab.c"
    break;

  case 408:
#line 2362 "def.y"
                          { defData->real_num = 1; }
#line 6222 "def.tab.c"
    break;

  case 409:
#line 2363 "def.y"
        {
          if (defData->VersionNum < 5.5) {
            if (defData->callbacks->NetCbk) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                 defData->defMsg = (char*)malloc(1000);
                 sprintf (defData->defMsg,
                    "The FREQUENCY statement is a version 5.5 and later syntax.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                 defData->defError(6558, defData->defMsg);
                 free(defData->defMsg);
                 CHKERR();
              }
            }
          }
          if (defData->callbacks->NetCbk) defData->Net.setFrequency((yyvsp[0].dval));
          defData->real_num = 0;
        }
#line 6243 "def.tab.c"
    break;

  case 410:
#line 2380 "def.y"
                         {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6249 "def.tab.c"
    break;

  case 411:
#line 2381 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setOriginal((yyvsp[0].string)); }
#line 6255 "def.tab.c"
    break;

  case 412:
#line 2384 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setPattern((yyvsp[0].string)); }
#line 6261 "def.tab.c"
    break;

  case 413:
#line 2387 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setWeight(ROUND((yyvsp[0].dval))); }
#line 6267 "def.tab.c"
    break;

  case 414:
#line 2390 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setXTalk(ROUND((yyvsp[0].dval))); }
#line 6273 "def.tab.c"
    break;

  case 415:
#line 2393 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setCap((yyvsp[0].dval)); }
#line 6279 "def.tab.c"
    break;

  case 416:
#line 2396 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setUse((yyvsp[0].string)); }
#line 6285 "def.tab.c"
    break;

  case 417:
#line 2399 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.setStyle((int)(yyvsp[0].dval)); }
#line 6291 "def.tab.c"
    break;

  case 418:
#line 2401 "def.y"
                               { defData->dumb_mode = 1; defData->no_num = 1; }
#line 6297 "def.tab.c"
    break;

  case 419:
#line 2402 "def.y"
        { 
          if (defData->callbacks->NetCbk && defData->callbacks->NetNonDefaultRuleCbk) {
             // User wants a callback on nondefaultrule 
             CALLBACK(defData->callbacks->NetNonDefaultRuleCbk,
                      defrNetNonDefaultRuleCbkType, (yyvsp[0].string));
          }
          // Still save data in the class 
          if (defData->callbacks->NetCbk) defData->Net.setNonDefaultRule((yyvsp[0].string));
        }
#line 6311 "def.tab.c"
    break;

  case 421:
#line 2414 "def.y"
                          { defData->dumb_mode = 1; defData->no_num = 1; }
#line 6317 "def.tab.c"
    break;

  case 422:
#line 2415 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addShieldNet((yyvsp[0].string)); }
#line 6323 "def.tab.c"
    break;

  case 423:
#line 2417 "def.y"
                         { defData->dumb_mode = 1; defData->no_num = 1; }
#line 6329 "def.tab.c"
    break;

  case 424:
#line 2418 "def.y"
        { // since the parser still support 5.3 and earlier, can't 
          // move NOSHIELD in net_type 
          if (defData->VersionNum < 5.4) {   // PCR 445209 
            if (defData->callbacks->NetCbk) defData->Net.addNoShield("");
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->shield = TRUE;    // save the path info in the defData->shield paths 
          } else
            if (defData->callbacks->NetCbk) defData->Net.addWire("NOSHIELD", NULL);
        }
#line 6350 "def.tab.c"
    break;

  case 425:
#line 2435 "def.y"
        {
          if (defData->VersionNum < 5.4) {   // PCR 445209 
            defData->shield = FALSE;
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->nondef_is_keyword = FALSE;
            defData->mustjoin_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
          } else {
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->nondef_is_keyword = FALSE;
            defData->mustjoin_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
          }
          defData->needNPCbk = 0;
        }
#line 6382 "def.tab.c"
    break;

  case 426:
#line 2464 "def.y"
        { defData->dumb_mode = 1; defData->no_num = 1;
          if (defData->callbacks->NetCbk) {
            defData->Subnet = new defiSubnet(defData);
          }
        }
#line 6392 "def.tab.c"
    break;

  case 427:
#line 2469 "def.y"
                 {
          if (defData->callbacks->NetCbk && defData->callbacks->NetSubnetNameCbk) {
            // User wants a callback on Net subnetName 
            CALLBACK(defData->callbacks->NetSubnetNameCbk, defrNetSubnetNameCbkType, (yyvsp[0].string));
          }
          // Still save the subnet name in the class 
          if (defData->callbacks->NetCbk) {
            defData->Subnet->setName((yyvsp[0].string));
          }
        }
#line 6407 "def.tab.c"
    break;

  case 428:
#line 2479 "def.y"
                   {
          defData->routed_is_keyword = TRUE;
          defData->fixed_is_keyword = TRUE;
          defData->cover_is_keyword = TRUE;
        }
#line 6417 "def.tab.c"
    break;

  case 429:
#line 2483 "def.y"
                         {
          if (defData->callbacks->NetCbk) {
            defData->Net.addSubnet(defData->Subnet);
            defData->Subnet = NULL;
            defData->routed_is_keyword = FALSE;
            defData->fixed_is_keyword = FALSE;
            defData->cover_is_keyword = FALSE;
          }
        }
#line 6431 "def.tab.c"
    break;

  case 430:
#line 2493 "def.y"
                         {defData->dumb_mode = DEF_MAX_INT; }
#line 6437 "def.tab.c"
    break;

  case 431:
#line 2495 "def.y"
        { defData->dumb_mode = 0; }
#line 6443 "def.tab.c"
    break;

  case 432:
#line 2498 "def.y"
        { 
          if (defData->callbacks->NetExtCbk)
            CALLBACK(defData->callbacks->NetExtCbk, defrNetExtCbkType, &defData->History_text[0]);
        }
#line 6452 "def.tab.c"
    break;

  case 435:
#line 2508 "def.y"
        {
          if (defData->callbacks->NetCbk) {
            char propTp;
            char* str = defData->ringCopy("                       ");
            propTp = defData->session->NetProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "NET");
            sprintf(str, "%g", (yyvsp[0].dval));
            defData->Net.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
          }
        }
#line 6467 "def.tab.c"
    break;

  case 436:
#line 2519 "def.y"
        {
          if (defData->callbacks->NetCbk) {
            char propTp;
            propTp = defData->session->NetProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "NET");
            defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 6480 "def.tab.c"
    break;

  case 437:
#line 2528 "def.y"
        {
          if (defData->callbacks->NetCbk) {
            char propTp;
            propTp = defData->session->NetProp.propType((yyvsp[-1].string));
            CHKPROPTYPE(propTp, (yyvsp[-1].string), "NET");
            defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
          }
        }
#line 6493 "def.tab.c"
    break;

  case 438:
#line 2538 "def.y"
        { (yyval.string) = (char*)"NETLIST"; }
#line 6499 "def.tab.c"
    break;

  case 439:
#line 2540 "def.y"
        { (yyval.string) = (char*)"DIST"; }
#line 6505 "def.tab.c"
    break;

  case 440:
#line 2542 "def.y"
        { (yyval.string) = (char*)"USER"; }
#line 6511 "def.tab.c"
    break;

  case 441:
#line 2544 "def.y"
        { (yyval.string) = (char*)"TIMING"; }
#line 6517 "def.tab.c"
    break;

  case 442:
#line 2546 "def.y"
        { (yyval.string) = (char*)"TEST"; }
#line 6523 "def.tab.c"
    break;

  case 443:
#line 2549 "def.y"
        {
          // vpin_options may have to deal with orient 
          defData->orient_is_keyword = TRUE;
        }
#line 6532 "def.tab.c"
    break;

  case 444:
#line 2554 "def.y"
        { if (defData->callbacks->NetCbk)
            defData->Net.addVpinBounds((yyvsp[-3].pt).x, (yyvsp[-3].pt).y, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y);
          defData->orient_is_keyword = FALSE;
        }
#line 6541 "def.tab.c"
    break;

  case 445:
#line 2559 "def.y"
                       {defData->dumb_mode = 1; defData->no_num = 1;}
#line 6547 "def.tab.c"
    break;

  case 446:
#line 2560 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addVpin((yyvsp[0].string)); }
#line 6553 "def.tab.c"
    break;

  case 448:
#line 2563 "def.y"
                  {defData->dumb_mode=1;}
#line 6559 "def.tab.c"
    break;

  case 449:
#line 2564 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addVpinLayer((yyvsp[0].string)); }
#line 6565 "def.tab.c"
    break;

  case 451:
#line 2568 "def.y"
        { if (defData->callbacks->NetCbk) defData->Net.addVpinLoc((yyvsp[-2].string), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].integer)); }
#line 6571 "def.tab.c"
    break;

  case 452:
#line 2571 "def.y"
        { (yyval.string) = (char*)"PLACED"; }
#line 6577 "def.tab.c"
    break;

  case 453:
#line 2573 "def.y"
        { (yyval.string) = (char*)"FIXED"; }
#line 6583 "def.tab.c"
    break;

  case 454:
#line 2575 "def.y"
        { (yyval.string) = (char*)"COVER"; }
#line 6589 "def.tab.c"
    break;

  case 455:
#line 2578 "def.y"
        { (yyval.string) = (char*)"FIXED"; defData->dumb_mode = 1; }
#line 6595 "def.tab.c"
    break;

  case 456:
#line 2580 "def.y"
        { (yyval.string) = (char*)"COVER"; defData->dumb_mode = 1; }
#line 6601 "def.tab.c"
    break;

  case 457:
#line 2582 "def.y"
        { (yyval.string) = (char*)"ROUTED"; defData->dumb_mode = 1; }
#line 6607 "def.tab.c"
    break;

  case 458:
#line 2586 "def.y"
      { if (defData->NeedPathData && defData->callbacks->NetCbk)
          defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needNPCbk);
      }
#line 6615 "def.tab.c"
    break;

  case 459:
#line 2590 "def.y"
      { }
#line 6621 "def.tab.c"
    break;

  case 460:
#line 2592 "def.y"
                { defData->dumb_mode = 1; }
#line 6627 "def.tab.c"
    break;

  case 461:
#line 2593 "def.y"
      { if (defData->NeedPathData && defData->callbacks->NetCbk)
          defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needNPCbk);
      }
#line 6635 "def.tab.c"
    break;

  case 462:
#line 2598 "def.y"
      {
        if ((strcmp((yyvsp[0].string), "TAPER") == 0) || (strcmp((yyvsp[0].string), "TAPERRULE") == 0)) {
          if (defData->NeedPathData && defData->callbacks->NetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defError(6531, "The layerName which is required in path is missing. Include the layerName in the path and then try again.");
              CHKERR();
            }
          }
          // Since there is already error, the next token is insignificant 
          defData->dumb_mode = 1; defData->no_num = 1;
        } else {
          // CCR 766289 - Do not accummulate the layer information if there 
          // is not a callback set 
          if (defData->NeedPathData && defData->callbacks->NetCbk)
              defData->PathObj.addLayer((yyvsp[0].string));
          defData->dumb_mode = 0; defData->no_num = 0;
        }
      }
#line 6658 "def.tab.c"
    break;

  case 463:
#line 2617 "def.y"
      { defData->dumb_mode = DEF_MAX_INT; defData->by_is_keyword = TRUE; defData->do_is_keyword = TRUE;
/*
       dumb_mode = 1; by_is_keyword = TRUE; do_is_keyword = TRUE;
*/
        defData->new_is_keyword = TRUE; defData->step_is_keyword = TRUE; 
        defData->orient_is_keyword = TRUE; defData->virtual_is_keyword = TRUE;
        defData->mask_is_keyword = TRUE, defData->rect_is_keyword = TRUE;  }
#line 6670 "def.tab.c"
    break;

  case 464:
#line 2627 "def.y"
      { defData->dumb_mode = 0;   defData->virtual_is_keyword = FALSE; defData->mask_is_keyword = FALSE,
       defData->rect_is_keyword = FALSE; }
#line 6677 "def.tab.c"
    break;

  case 465:
#line 2632 "def.y"
    {
      if (defData->VersionNum < 5.8) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The VIRTUAL statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
          }
    }
#line 6696 "def.tab.c"
    break;

  case 466:
#line 2649 "def.y"
    {
      if (defData->VersionNum < 5.8) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The RECT statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
      }
    }
#line 6715 "def.tab.c"
    break;

  case 469:
#line 2672 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          if (strcmp((yyvsp[0].string), "TAPER") == 0)
            defData->PathObj.setTaper();
          else {
            defData->PathObj.addVia((yyvsp[0].string));
            }
        }
      }
#line 6730 "def.tab.c"
    break;

  case 470:
#line 2683 "def.y"
      {
        if (defData->validateMaskInput((int)(yyvsp[-1].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
            if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
                (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
              if (strcmp((yyvsp[0].string), "TAPER") == 0)
                defData->PathObj.setTaper();
              else {
                defData->PathObj.addViaMask((yyvsp[-1].dval));
                defData->PathObj.addVia((yyvsp[0].string));
                }
            }
        }
      }
#line 6748 "def.tab.c"
    break;

  case 471:
#line 2697 "def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
            defData->PathObj.addVia((yyvsp[-1].string));
            defData->PathObj.addViaRotation((yyvsp[0].integer));
        }
      }
#line 6759 "def.tab.c"
    break;

  case 472:
#line 2704 "def.y"
      { 
        if (defData->validateMaskInput((int)(yyvsp[-2].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
            if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
                (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
                defData->PathObj.addViaMask((yyvsp[-2].dval));
                defData->PathObj.addVia((yyvsp[-1].string));
                defData->PathObj.addViaRotation((yyvsp[0].integer));
            }
        }
      }
#line 6774 "def.tab.c"
    break;

  case 473:
#line 2715 "def.y"
      {
        if (defData->validateMaskInput((int)(yyvsp[-8].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {      
            if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
              if (defData->NeedPathData &&
                  defData->callbacks->SNetCbk) {
                if (defData->netWarnings++ < defData->settings->NetWarnings) {
                  defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
                  CHKERR();
                }
              }
            }
            if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
                defData->PathObj.addViaMask((yyvsp[-8].dval));
                defData->PathObj.addVia((yyvsp[-7].string));
                defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            }  else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
                CHKERR();
              }
            }
        }
      }
#line 6802 "def.tab.c"
    break;

  case 474:
#line 2739 "def.y"
      {
        if (defData->VersionNum < 5.5) {
          if (defData->NeedPathData && 
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The VIA DO statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6532, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        }
        if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
          if (defData->NeedPathData &&
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
              CHKERR();
            }
          }
        }
        if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
            defData->PathObj.addVia((yyvsp[-7].string));
            defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
        }  else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
          if (defData->netWarnings++ < defData->settings->NetWarnings) {
            defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
            CHKERR();
          }
        }
      }
#line 6840 "def.tab.c"
    break;

  case 475:
#line 2773 "def.y"
      {
        if (defData->VersionNum < 5.5) {
          if (defData->NeedPathData &&
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The VIA DO statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6532, defData->defMsg);
              CHKERR();
            }
          }
        }
        if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
          if (defData->NeedPathData &&
              defData->callbacks->SNetCbk) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
              CHKERR();
            }
          }
        }
        if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
            defData->PathObj.addVia((yyvsp[-8].string));
            defData->PathObj.addViaRotation((yyvsp[-7].integer));
            defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
        } else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
          if (defData->netWarnings++ < defData->settings->NetWarnings) {
            defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
            CHKERR();
          }
        }
      }
#line 6878 "def.tab.c"
    break;

  case 476:
#line 2807 "def.y"
      {
        if (defData->validateMaskInput((int)(yyvsp[-9].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
            if (((yyvsp[-5].dval) == 0) || ((yyvsp[-3].dval) == 0)) {
              if (defData->NeedPathData &&
                  defData->callbacks->SNetCbk) {
                if (defData->netWarnings++ < defData->settings->NetWarnings) {
                  defData->defError(6533, "Either the numX or numY in the VIA DO statement has the value. The value specified is 0.\nUpdate your DEF file with the correct value and then try again.\n");
                  CHKERR();
                }
              }
            }
            if (defData->NeedPathData && (defData->callbacks->SNetCbk && (defData->netOsnet==2))) {
                defData->PathObj.addViaMask((yyvsp[-9].dval)); 
                defData->PathObj.addVia((yyvsp[-8].string));
                defData->PathObj.addViaRotation((yyvsp[-7].integer));;
                defData->PathObj.addViaData((int)(yyvsp[-5].dval), (int)(yyvsp[-3].dval), (int)(yyvsp[-1].dval), (int)(yyvsp[0].dval));
            } else if (defData->NeedPathData && (defData->callbacks->NetCbk && (defData->netOsnet==1))) {
              if (defData->netWarnings++ < defData->settings->NetWarnings) {
                defData->defError(6567, "The VIA DO statement is defined in the NET statement and is invalid.\nRemove this statement from your DEF file and try again.");
                CHKERR();
              }
            }
        }
      }
#line 6907 "def.tab.c"
    break;

  case 479:
#line 2833 "def.y"
                          { defData->dumb_mode = 6; }
#line 6913 "def.tab.c"
    break;

  case 480:
#line 2834 "def.y"
    {
      if (defData->validateMaskInput((int)(yyvsp[-8].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          defData->PathObj.addMask((yyvsp[-8].dval));
          defData->PathObj.addViaRect((yyvsp[-4].dval), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval));
        }
      }
    }
#line 6927 "def.tab.c"
    break;

  case 481:
#line 2844 "def.y"
    {
       if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          defData->PathObj.addMask((yyvsp[0].dval)); 
        }
       }  
    }
#line 6940 "def.tab.c"
    break;

  case 483:
#line 2854 "def.y"
    {
       // reset defData->dumb_mode to 1 just incase the next token is a via of the path
        // 2/5/2004 - pcr 686781
        defData->dumb_mode = DEF_MAX_INT; defData->by_is_keyword = TRUE; defData->do_is_keyword = TRUE;
        defData->new_is_keyword = TRUE; defData->step_is_keyword = TRUE;
        defData->orient_is_keyword = TRUE;
    }
#line 6952 "def.tab.c"
    break;

  case 484:
#line 2865 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND((yyvsp[-2].dval)), ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-2].dval);
        defData->save_y = (yyvsp[-1].dval); 
      }
#line 6964 "def.tab.c"
    break;

  case 485:
#line 2873 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND(defData->save_x), ROUND((yyvsp[-1].dval))); 
        defData->save_y = (yyvsp[-1].dval);
      }
#line 6975 "def.tab.c"
    break;

  case 486:
#line 2880 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND((yyvsp[-2].dval)), ROUND(defData->save_y)); 
        defData->save_x = (yyvsp[-2].dval);
      }
#line 6986 "def.tab.c"
    break;

  case 487:
#line 2887 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addPoint(ROUND(defData->save_x), ROUND(defData->save_y)); 
      }
#line 6996 "def.tab.c"
    break;

  case 488:
#line 2893 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND((yyvsp[-3].dval)), ROUND((yyvsp[-2].dval)), ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-3].dval);
        defData->save_y = (yyvsp[-2].dval);
      }
#line 7008 "def.tab.c"
    break;

  case 489:
#line 2901 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND(defData->save_x), ROUND((yyvsp[-2].dval)),
          ROUND((yyvsp[-1].dval))); 
        defData->save_y = (yyvsp[-2].dval);
      }
#line 7020 "def.tab.c"
    break;

  case 490:
#line 2909 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND((yyvsp[-3].dval)), ROUND(defData->save_y),
          ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-3].dval);
      }
#line 7032 "def.tab.c"
    break;

  case 491:
#line 2917 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addFlushPoint(ROUND(defData->save_x), ROUND(defData->save_y),
          ROUND((yyvsp[-1].dval))); 
      }
#line 7043 "def.tab.c"
    break;

  case 492:
#line 2926 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND((yyvsp[-2].dval)), ROUND((yyvsp[-1].dval))); 
        defData->save_x = (yyvsp[-2].dval);
        defData->save_y = (yyvsp[-1].dval);
      }
#line 7055 "def.tab.c"
    break;

  case 493:
#line 2934 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND(defData->save_x), ROUND((yyvsp[-1].dval))); 
        defData->save_y = (yyvsp[-1].dval);
      }
#line 7066 "def.tab.c"
    break;

  case 494:
#line 2941 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND((yyvsp[-2].dval)), ROUND(defData->save_y)); 
        defData->save_x = (yyvsp[-2].dval);
      }
#line 7077 "def.tab.c"
    break;

  case 495:
#line 2948 "def.y"
      {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addVirtualPoint(ROUND(defData->save_x), ROUND(defData->save_y));
      }
#line 7087 "def.tab.c"
    break;

  case 496:
#line 2956 "def.y"
    {
        if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
          defData->PathObj.addViaRect((yyvsp[-4].dval), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval)); 
        }    
    }
#line 7098 "def.tab.c"
    break;

  case 501:
#line 2972 "def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.setTaper(); }
#line 7106 "def.tab.c"
    break;

  case 502:
#line 2975 "def.y"
                  { defData->dumb_mode = 1; }
#line 7112 "def.tab.c"
    break;

  case 503:
#line 2976 "def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addTaperRule((yyvsp[0].string)); }
#line 7120 "def.tab.c"
    break;

  case 504:
#line 2981 "def.y"
      { 
        if (defData->VersionNum < 5.6) {
           if (defData->NeedPathData && (defData->callbacks->NetCbk ||
               defData->callbacks->SNetCbk)) {
             if (defData->netWarnings++ < defData->settings->NetWarnings) {
               defData->defMsg = (char*)malloc(1000);
               sprintf (defData->defMsg,
                  "The STYLE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
               defData->defError(6534, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else
           if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
             (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
             defData->PathObj.addStyle((int)(yyvsp[0].dval));
      }
#line 7143 "def.tab.c"
    break;

  case 507:
#line 3006 "def.y"
      { if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
          (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
          defData->PathObj.addShape((yyvsp[0].string)); }
#line 7151 "def.tab.c"
    break;

  case 508:
#line 3010 "def.y"
      { if (defData->VersionNum < 5.6) {
          if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2)))) {
            if (defData->netWarnings++ < defData->settings->NetWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The STYLE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6534, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else {
          if (defData->NeedPathData && ((defData->callbacks->NetCbk && (defData->netOsnet==1)) ||
            (defData->callbacks->SNetCbk && (defData->netOsnet==2))))
            defData->PathObj.addStyle((int)(yyvsp[0].dval));
        }
      }
#line 7174 "def.tab.c"
    break;

  case 509:
#line 3030 "def.y"
          { 
            CALLBACK(defData->callbacks->NetEndCbk, defrNetEndCbkType, 0);
            defData->netOsnet = 0;
          }
#line 7183 "def.tab.c"
    break;

  case 510:
#line 3036 "def.y"
            { (yyval.string) = (char*)"RING"; }
#line 7189 "def.tab.c"
    break;

  case 511:
#line 3038 "def.y"
            { (yyval.string) = (char*)"STRIPE"; }
#line 7195 "def.tab.c"
    break;

  case 512:
#line 3040 "def.y"
            { (yyval.string) = (char*)"FOLLOWPIN"; }
#line 7201 "def.tab.c"
    break;

  case 513:
#line 3042 "def.y"
            { (yyval.string) = (char*)"IOWIRE"; }
#line 7207 "def.tab.c"
    break;

  case 514:
#line 3044 "def.y"
            { (yyval.string) = (char*)"COREWIRE"; }
#line 7213 "def.tab.c"
    break;

  case 515:
#line 3046 "def.y"
            { (yyval.string) = (char*)"BLOCKWIRE"; }
#line 7219 "def.tab.c"
    break;

  case 516:
#line 3048 "def.y"
            { (yyval.string) = (char*)"FILLWIRE"; }
#line 7225 "def.tab.c"
    break;

  case 517:
#line 3050 "def.y"
            {
              if (defData->VersionNum < 5.7) {
                 if (defData->NeedPathData) {
                   if (defData->fillWarnings++ < defData->settings->FillWarnings) {
                     defData->defMsg = (char*)malloc(10000);
                     sprintf (defData->defMsg,
                       "The FILLWIREOPC is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                     defData->defError(6552, defData->defMsg);
                     free(defData->defMsg);
                     CHKERR();
                  }
                }
              }
              (yyval.string) = (char*)"FILLWIREOPC";
            }
#line 7245 "def.tab.c"
    break;

  case 518:
#line 3066 "def.y"
            { (yyval.string) = (char*)"DRCFILL"; }
#line 7251 "def.tab.c"
    break;

  case 519:
#line 3068 "def.y"
            { (yyval.string) = (char*)"BLOCKAGEWIRE"; }
#line 7257 "def.tab.c"
    break;

  case 520:
#line 3070 "def.y"
            { (yyval.string) = (char*)"PADRING"; }
#line 7263 "def.tab.c"
    break;

  case 521:
#line 3072 "def.y"
            { (yyval.string) = (char*)"BLOCKRING"; }
#line 7269 "def.tab.c"
    break;

  case 525:
#line 3082 "def.y"
        { CALLBACK(defData->callbacks->SNetCbk, defrSNetCbkType, &defData->Net); }
#line 7275 "def.tab.c"
    break;

  case 532:
#line 3093 "def.y"
            {
             if (defData->VersionNum >= 5.8) {
                defData->specialWire_routeStatus = (yyvsp[0].string);
             } else {
                 if (defData->callbacks->SNetCbk) {   // PCR 902306 
                   defData->defMsg = (char*)malloc(1024);
                   sprintf(defData->defMsg, "The SPECIAL NET statement, with type %s, does not have any net statement defined.\nThe DEF parser will ignore this statemnet.", (yyvsp[0].string));
                   defData->defWarning(7023, defData->defMsg);
                   free(defData->defMsg);
                 }
             }
            }
#line 7292 "def.tab.c"
    break;

  case 533:
#line 3106 "def.y"
            {
            if (defData->callbacks->SNetCbk) defData->Net.addWire((yyvsp[0].string), NULL);
            }
#line 7300 "def.tab.c"
    break;

  case 534:
#line 3110 "def.y"
            {
            // 7/17/2003 - Fix for pcr 604848, add a callback for each wire
            if (defData->callbacks->SNetWireCbk) {
               CALLBACK(defData->callbacks->SNetWireCbk, defrSNetWireCbkType, &defData->Net);
               defData->Net.freeWire();
            }
            defData->by_is_keyword = FALSE;
            defData->do_is_keyword = FALSE;
            defData->new_is_keyword = FALSE;
            defData->step_is_keyword = FALSE;
            defData->orient_is_keyword = FALSE;
            defData->virtual_is_keyword = FALSE;
            defData->mask_is_keyword = FALSE;
            defData->rect_is_keyword = FALSE;
            defData->needSNPCbk = 0;
            }
#line 7321 "def.tab.c"
    break;

  case 535:
#line 3127 "def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 7327 "def.tab.c"
    break;

  case 536:
#line 3128 "def.y"
            { defData->shieldName = (yyvsp[0].string); 
              defData->specialWire_routeStatus = (char*)"SHIELD";
              defData->specialWire_routeStatusName = (yyvsp[0].string); 
            }
#line 7336 "def.tab.c"
    break;

  case 538:
#line 3135 "def.y"
          {  
            defData->specialWire_shapeType = (yyvsp[0].string);
          }
#line 7344 "def.tab.c"
    break;

  case 539:
#line 3139 "def.y"
          {
            if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->sNetWarnings, defData->settings->SNetWarnings)) {
                defData->specialWire_mask = (yyvsp[0].dval);
            }     
          }
#line 7354 "def.tab.c"
    break;

  case 540:
#line 3144 "def.y"
                        { defData->dumb_mode = 1; }
#line 7360 "def.tab.c"
    break;

  case 541:
#line 3145 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The POLYGON statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6535, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            
            defData->Geometries.Reset();
          }
#line 7381 "def.tab.c"
    break;

  case 542:
#line 3162 "def.y"
          {
            if (defData->VersionNum >= 5.6) {  // only add if 5.6 or beyond
              if (defData->callbacks->SNetCbk) {
                // defData->needSNPCbk will indicate that it has reach the max
                // memory and if user has set partialPathCBk, def parser
                // will make the callback.
                // This will improve performance
                // This construct is only in specialnet
                defData->Net.addPolygon((yyvsp[-5].string), &defData->Geometries, &defData->needSNPCbk, defData->specialWire_mask, defData->specialWire_routeStatus, defData->specialWire_shapeType,
                                                                defData->specialWire_routeStatusName);
                defData->specialWire_mask = 0;
                defData->specialWire_routeStatus = (char*)"ROUTED";
                defData->specialWire_shapeType = (char*)"";
                if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
                   CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                            &defData->Net);
                   defData->Net.clearRectPolyNPath();
                   defData->Net.clearVia();
                }
              }
            }
          }
#line 7408 "def.tab.c"
    break;

  case 543:
#line 3185 "def.y"
                     { defData->dumb_mode = 1; }
#line 7414 "def.tab.c"
    break;

  case 544:
#line 3186 "def.y"
          {
            if (defData->VersionNum < 5.6) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The RECT statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
            }
            if (defData->callbacks->SNetCbk) {
              // defData->needSNPCbk will indicate that it has reach the max
              // memory and if user has set partialPathCBk, def parser
              // will make the callback.
              // This will improve performance
              // This construct is only in specialnet
              defData->Net.addRect((yyvsp[-2].string), (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y, &defData->needSNPCbk, defData->specialWire_mask, defData->specialWire_routeStatus, defData->specialWire_shapeType, defData->specialWire_routeStatusName);
              defData->specialWire_mask = 0;
              defData->specialWire_routeStatus = (char*)"ROUTED";
              defData->specialWire_shapeType = (char*)"";
              defData->specialWire_routeStatusName = (char*)"";
              if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
                 CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                          &defData->Net);
                 defData->Net.clearRectPolyNPath();
                 defData->Net.clearVia();
              }
            }
          }
#line 7451 "def.tab.c"
    break;

  case 545:
#line 3218 "def.y"
                    { defData->dumb_mode = 1; }
#line 7457 "def.tab.c"
    break;

  case 546:
#line 3219 "def.y"
        {
          if (defData->VersionNum < 5.8) {
              if (defData->callbacks->SNetCbk) {
                if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                  defData->defMsg = (char*)malloc(1000);
                  sprintf (defData->defMsg,
                     "The VIA statement is available in version 5.8 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
                  defData->defError(6536, defData->defMsg);
                  free(defData->defMsg);
                  CHKERR();
                }
              }
          }
        }
#line 7476 "def.tab.c"
    break;

  case 547:
#line 3234 "def.y"
        {
          if (defData->VersionNum >= 5.8 && defData->callbacks->SNetCbk) {
              defData->Net.addPts((yyvsp[-4].string), (yyvsp[-3].integer), &defData->Geometries, &defData->needSNPCbk, defData->specialWire_mask, defData->specialWire_routeStatus, defData->specialWire_shapeType,
                                                          defData->specialWire_routeStatusName);
              defData->specialWire_mask = 0;
              defData->specialWire_routeStatus = (char*)"ROUTED";
              defData->specialWire_shapeType = (char*)"";
              defData->specialWire_routeStatusName = (char*)"";
              if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
                 CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                          &defData->Net);
                 defData->Net.clearRectPolyNPath();
                 defData->Net.clearVia();
              }
            }
        }
#line 7497 "def.tab.c"
    break;

  case 548:
#line 3252 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setSource((yyvsp[0].string)); }
#line 7503 "def.tab.c"
    break;

  case 549:
#line 3255 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setFixedbump(); }
#line 7509 "def.tab.c"
    break;

  case 550:
#line 3258 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setFrequency((yyvsp[0].dval)); }
#line 7515 "def.tab.c"
    break;

  case 551:
#line 3260 "def.y"
                         {defData->dumb_mode = 1; defData->no_num = 1;}
#line 7521 "def.tab.c"
    break;

  case 552:
#line 3261 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setOriginal((yyvsp[0].string)); }
#line 7527 "def.tab.c"
    break;

  case 553:
#line 3264 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setPattern((yyvsp[0].string)); }
#line 7533 "def.tab.c"
    break;

  case 554:
#line 3267 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setWeight(ROUND((yyvsp[0].dval))); }
#line 7539 "def.tab.c"
    break;

  case 555:
#line 3270 "def.y"
            { 
              // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
              if (defData->VersionNum < 5.5)
                 if (defData->callbacks->SNetCbk) defData->Net.setCap((yyvsp[0].dval));
              else
                 defData->defWarning(7024, "The ESTCAP statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
            }
#line 7551 "def.tab.c"
    break;

  case 556:
#line 3279 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setUse((yyvsp[0].string)); }
#line 7557 "def.tab.c"
    break;

  case 557:
#line 3282 "def.y"
            { if (defData->callbacks->SNetCbk) defData->Net.setStyle((int)(yyvsp[0].dval)); }
#line 7563 "def.tab.c"
    break;

  case 558:
#line 3284 "def.y"
                         {defData->dumb_mode = DEF_MAX_INT; }
#line 7569 "def.tab.c"
    break;

  case 559:
#line 3286 "def.y"
            { defData->dumb_mode = 0; }
#line 7575 "def.tab.c"
    break;

  case 560:
#line 3289 "def.y"
          { CALLBACK(defData->callbacks->NetExtCbk, defrNetExtCbkType, &defData->History_text[0]); }
#line 7581 "def.tab.c"
    break;

  case 561:
#line 3292 "def.y"
        { (yyval.integer) = 0; }
#line 7587 "def.tab.c"
    break;

  case 562:
#line 3293 "def.y"
               {(yyval.integer) = 0;}
#line 7593 "def.tab.c"
    break;

  case 563:
#line 3294 "def.y"
               {(yyval.integer) = 1;}
#line 7599 "def.tab.c"
    break;

  case 564:
#line 3295 "def.y"
               {(yyval.integer) = 2;}
#line 7605 "def.tab.c"
    break;

  case 565:
#line 3296 "def.y"
               {(yyval.integer) = 3;}
#line 7611 "def.tab.c"
    break;

  case 566:
#line 3297 "def.y"
               {(yyval.integer) = 4;}
#line 7617 "def.tab.c"
    break;

  case 567:
#line 3298 "def.y"
               {(yyval.integer) = 5;}
#line 7623 "def.tab.c"
    break;

  case 568:
#line 3299 "def.y"
               {(yyval.integer) = 6;}
#line 7629 "def.tab.c"
    break;

  case 569:
#line 3300 "def.y"
               {(yyval.integer) = 7;}
#line 7635 "def.tab.c"
    break;

  case 570:
#line 3303 "def.y"
            {
                if (defData->callbacks->SNetCbk) {
                    if (defData->VersionNum < 5.8) { 
                        defData->defMsg = (char*)malloc(1024);
                        sprintf(defData->defMsg, "The SPECIAL NET SHIELD statement doesn't have routing points definition.\nWill be ignored.");
                        defData->defWarning(7025, defData->defMsg);
                        free(defData->defMsg);
                    } else {  // CCR 1244433
                      defData->specialWire_routeStatus = (char*)"SHIELD";
                      defData->specialWire_routeStatusName = defData->shieldName;
                    }
                }
            }
#line 7653 "def.tab.c"
    break;

  case 571:
#line 3317 "def.y"
            { // since the parser still supports 5.3 and earlier, 
              // can't just move SHIELD in net_type 
              if (defData->VersionNum < 5.4) { // PCR 445209 
                if (defData->callbacks->SNetCbk) defData->Net.addShield(defData->shieldName);
                defData->by_is_keyword = FALSE;
                defData->do_is_keyword = FALSE;
                defData->new_is_keyword = FALSE;
                defData->step_is_keyword = FALSE;
                defData->orient_is_keyword = FALSE;
                defData->virtual_is_keyword = FALSE;
                defData->mask_is_keyword = FALSE;
                defData->rect_is_keyword = FALSE;
                defData->specialWire_routeStatus = (char*)"ROUTED";
                defData->specialWire_routeStatusName = (char*)"";
                defData->shield = TRUE;   // save the path info in the defData->shield paths 
              } else
                if (defData->callbacks->SNetCbk) defData->Net.addWire("SHIELD", defData->shieldName);
                defData->specialWire_routeStatus = (char*)"ROUTED";
                defData->specialWire_routeStatusName = (char*)"";
            }
#line 7678 "def.tab.c"
    break;

  case 572:
#line 3338 "def.y"
            {
              // 7/17/2003 - Fix for pcr 604848, add a callback for each wire
              if (defData->callbacks->SNetWireCbk) {
                 CALLBACK(defData->callbacks->SNetWireCbk, defrSNetWireCbkType, &defData->Net);
                 if (defData->VersionNum < 5.4)
                   defData->Net.freeShield();
                 else
                   defData->Net.freeWire();
              }
              if (defData->VersionNum < 5.4) {  // PCR 445209 
                defData->shield = FALSE;
                defData->by_is_keyword = FALSE;
                defData->do_is_keyword = FALSE;
                defData->new_is_keyword = FALSE;
                defData->step_is_keyword = FALSE;
                defData->nondef_is_keyword = FALSE;
                defData->mustjoin_is_keyword = FALSE;
                defData->orient_is_keyword = FALSE;
                defData->virtual_is_keyword = FALSE;
                defData->mask_is_keyword = FALSE;
                defData->rect_is_keyword = FALSE;
              } else {
                defData->by_is_keyword = FALSE;
                defData->do_is_keyword = FALSE;
                defData->new_is_keyword = FALSE;
                defData->step_is_keyword = FALSE;
                defData->orient_is_keyword = FALSE;
                defData->virtual_is_keyword = FALSE;
                defData->mask_is_keyword = FALSE;
                defData->rect_is_keyword = FALSE;
              }
              defData->needSNPCbk = 0;
            }
#line 7716 "def.tab.c"
    break;

  case 573:
#line 3372 "def.y"
                        { defData->dumb_mode = 1; }
#line 7722 "def.tab.c"
    break;

  case 574:
#line 3373 "def.y"
            {
              // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
              if (defData->VersionNum < 5.5)
                 if (defData->callbacks->SNetCbk) defData->Net.setWidth((yyvsp[-1].string), (yyvsp[0].dval));
              else
                 defData->defWarning(7026, "The WIDTH statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
            }
#line 7734 "def.tab.c"
    break;

  case 575:
#line 3381 "def.y"
                             { defData->dumb_mode = 1; defData->no_num = 1; }
#line 7740 "def.tab.c"
    break;

  case 576:
#line 3382 "def.y"
            {
              if (defrData::numIsInt((yyvsp[0].string))) {
                 if (defData->callbacks->SNetCbk) defData->Net.setVoltage(atoi((yyvsp[0].string)));
              } else {
                 if (defData->callbacks->SNetCbk) {
                   if (defData->sNetWarnings++ < defData->settings->SNetWarnings) {
                     defData->defMsg = (char*)malloc(1000);
                     sprintf (defData->defMsg,
                        "The value %s for statement VOLTAGE is invalid. The value can only be integer.\nSpecify a valid value in units of millivolts", (yyvsp[0].string));
                     defData->defError(6537, defData->defMsg);
                     free(defData->defMsg);
                     CHKERR();
                   }
                 }
              }
            }
#line 7761 "def.tab.c"
    break;

  case 577:
#line 3399 "def.y"
                            { defData->dumb_mode = 1; }
#line 7767 "def.tab.c"
    break;

  case 578:
#line 3400 "def.y"
            {
              if (defData->callbacks->SNetCbk) defData->Net.setSpacing((yyvsp[-1].string),(yyvsp[0].dval));
            }
#line 7775 "def.tab.c"
    break;

  case 579:
#line 3404 "def.y"
            {
            }
#line 7782 "def.tab.c"
    break;

  case 582:
#line 3412 "def.y"
            {
              if (defData->callbacks->SNetCbk) {
                char propTp;
                char* str = defData->ringCopy("                       ");
                propTp = defData->session->SNetProp.propType((yyvsp[-1].string));
                CHKPROPTYPE(propTp, (yyvsp[-1].string), "SPECIAL NET");
                // For backword compatibility, also set the string value 
                sprintf(str, "%g", (yyvsp[0].dval));
                defData->Net.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
              }
            }
#line 7798 "def.tab.c"
    break;

  case 583:
#line 3424 "def.y"
            {
              if (defData->callbacks->SNetCbk) {
                char propTp;
                propTp = defData->session->SNetProp.propType((yyvsp[-1].string));
                CHKPROPTYPE(propTp, (yyvsp[-1].string), "SPECIAL NET");
                defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
              }
            }
#line 7811 "def.tab.c"
    break;

  case 584:
#line 3433 "def.y"
            {
              if (defData->callbacks->SNetCbk) {
                char propTp;
                propTp = defData->session->SNetProp.propType((yyvsp[-1].string));
                CHKPROPTYPE(propTp, (yyvsp[-1].string), "SPECIAL NET");
                defData->Net.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
              }
            }
#line 7824 "def.tab.c"
    break;

  case 586:
#line 3444 "def.y"
            {
              if (defData->callbacks->SNetCbk) defData->Net.setRange((yyvsp[-1].dval),(yyvsp[0].dval));
            }
#line 7832 "def.tab.c"
    break;

  case 588:
#line 3450 "def.y"
            { defData->Prop.setRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 7838 "def.tab.c"
    break;

  case 589:
#line 3453 "def.y"
            { (yyval.string) = (char*)"BALANCED"; }
#line 7844 "def.tab.c"
    break;

  case 590:
#line 3455 "def.y"
            { (yyval.string) = (char*)"STEINER"; }
#line 7850 "def.tab.c"
    break;

  case 591:
#line 3457 "def.y"
            { (yyval.string) = (char*)"TRUNK"; }
#line 7856 "def.tab.c"
    break;

  case 592:
#line 3459 "def.y"
            { (yyval.string) = (char*)"WIREDLOGIC"; }
#line 7862 "def.tab.c"
    break;

  case 593:
#line 3463 "def.y"
      { 
        if (defData->NeedPathData && defData->callbacks->SNetCbk) {
           if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) { 
              // require a callback before proceed because defData->needSNPCbk must be
              // set to 1 from the previous pathIsDone and user has registered
              // a callback routine.
              CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                       &defData->Net);
              defData->needSNPCbk = 0;   // reset the flag
              defData->pathIsDone(defData->shield, 1, defData->netOsnet, &defData->needSNPCbk);
              defData->Net.clearRectPolyNPath();
              defData->Net.clearVia();
           } else
              defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needSNPCbk);
        }
      }
#line 7883 "def.tab.c"
    break;

  case 594:
#line 3480 "def.y"
      { }
#line 7889 "def.tab.c"
    break;

  case 595:
#line 3482 "def.y"
                 { defData->dumb_mode = 1; }
#line 7895 "def.tab.c"
    break;

  case 596:
#line 3483 "def.y"
      { if (defData->NeedPathData && defData->callbacks->SNetCbk) {
           if (defData->needSNPCbk && defData->callbacks->SNetPartialPathCbk) {
              // require a callback before proceed because defData->needSNPCbk must be
              // set to 1 from the previous pathIsDone and user has registered
              // a callback routine.
              CALLBACK(defData->callbacks->SNetPartialPathCbk, defrSNetPartialPathCbkType,
                       &defData->Net);
              defData->needSNPCbk = 0;   // reset the flag
              defData->pathIsDone(defData->shield, 1, defData->netOsnet, &defData->needSNPCbk);
              // reset any poly or rect in special wiring statement
              defData->Net.clearRectPolyNPath();
              defData->Net.clearVia();
           } else
              defData->pathIsDone(defData->shield, 0, defData->netOsnet, &defData->needSNPCbk);
        }
      }
#line 7916 "def.tab.c"
    break;

  case 597:
#line 3501 "def.y"
      { if (defData->NeedPathData && defData->callbacks->SNetCbk)
           defData->PathObj.addLayer((yyvsp[0].string));
        defData->dumb_mode = 0; defData->no_num = 0;
      }
#line 7925 "def.tab.c"
    break;

  case 598:
#line 3509 "def.y"
      { defData->dumb_mode = DEF_MAX_INT; defData->by_is_keyword = TRUE; defData->do_is_keyword = TRUE;
        defData->new_is_keyword = TRUE; defData->step_is_keyword = TRUE;
         defData->orient_is_keyword = TRUE; defData->rect_is_keyword = TRUE, defData->mask_is_keyword = TRUE; 
         defData->virtual_is_keyword = TRUE;  }
#line 7934 "def.tab.c"
    break;

  case 599:
#line 3515 "def.y"
      { defData->dumb_mode = 0; defData->rect_is_keyword = FALSE, defData->mask_is_keyword = FALSE, defData->virtual_is_keyword = FALSE; }
#line 7940 "def.tab.c"
    break;

  case 600:
#line 3518 "def.y"
      { if (defData->NeedPathData && defData->callbacks->SNetCbk)
          defData->PathObj.addWidth(ROUND((yyvsp[0].dval)));
      }
#line 7948 "def.tab.c"
    break;

  case 601:
#line 3523 "def.y"
      { 
        if (defData->callbacks->SNetStartCbk)
          CALLBACK(defData->callbacks->SNetStartCbk, defrSNetStartCbkType, ROUND((yyvsp[-1].dval)));
        defData->netOsnet = 2;
      }
#line 7958 "def.tab.c"
    break;

  case 602:
#line 3530 "def.y"
      { 
        if (defData->callbacks->SNetEndCbk)
          CALLBACK(defData->callbacks->SNetEndCbk, defrSNetEndCbkType, 0);
        defData->netOsnet = 0;
      }
#line 7968 "def.tab.c"
    break;

  case 604:
#line 3540 "def.y"
      {
        if (defData->callbacks->GroupsStartCbk)
           CALLBACK(defData->callbacks->GroupsStartCbk, defrGroupsStartCbkType, ROUND((yyvsp[-1].dval)));
      }
#line 7977 "def.tab.c"
    break;

  case 607:
#line 3550 "def.y"
      {
        if (defData->callbacks->GroupCbk)
           CALLBACK(defData->callbacks->GroupCbk, defrGroupCbkType, &defData->Group);
      }
#line 7986 "def.tab.c"
    break;

  case 608:
#line 3555 "def.y"
                 { defData->dumb_mode = 1; defData->no_num = 1; }
#line 7992 "def.tab.c"
    break;

  case 609:
#line 3556 "def.y"
      {
        defData->dumb_mode = DEF_MAX_INT;
        defData->no_num = DEF_MAX_INT;
        /* dumb_mode is automatically turned off at the first
         * + in the options or at the ; at the end of the group */
        if (defData->callbacks->GroupCbk) defData->Group.setup((yyvsp[0].string));
        if (defData->callbacks->GroupNameCbk)
           CALLBACK(defData->callbacks->GroupNameCbk, defrGroupNameCbkType, (yyvsp[0].string));
      }
#line 8006 "def.tab.c"
    break;

  case 611:
#line 3568 "def.y"
      {  }
#line 8012 "def.tab.c"
    break;

  case 612:
#line 3571 "def.y"
      {
        // if (defData->callbacks->GroupCbk) defData->Group.addMember($1); 
        if (defData->callbacks->GroupMemberCbk)
          CALLBACK(defData->callbacks->GroupMemberCbk, defrGroupMemberCbkType, (yyvsp[0].string));
      }
#line 8022 "def.tab.c"
    break;

  case 615:
#line 3582 "def.y"
      { }
#line 8028 "def.tab.c"
    break;

  case 616:
#line 3583 "def.y"
                           { defData->dumb_mode = DEF_MAX_INT; }
#line 8034 "def.tab.c"
    break;

  case 617:
#line 3585 "def.y"
      { defData->dumb_mode = 0; }
#line 8040 "def.tab.c"
    break;

  case 618:
#line 3586 "def.y"
                         { defData->dumb_mode = 1;  defData->no_num = 1; }
#line 8046 "def.tab.c"
    break;

  case 619:
#line 3587 "def.y"
      { }
#line 8052 "def.tab.c"
    break;

  case 620:
#line 3589 "def.y"
      { 
        if (defData->callbacks->GroupMemberCbk)
          CALLBACK(defData->callbacks->GroupExtCbk, defrGroupExtCbkType, &defData->History_text[0]);
      }
#line 8061 "def.tab.c"
    break;

  case 621:
#line 3595 "def.y"
      {
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5) {
          if (defData->callbacks->GroupCbk)
            defData->Group.addRegionRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
        }
        else
          defData->defWarning(7027, "The GROUP REGION pt pt statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8075 "def.tab.c"
    break;

  case 622:
#line 3605 "def.y"
      { if (defData->callbacks->GroupCbk)
          defData->Group.setRegionName((yyvsp[0].string));
      }
#line 8083 "def.tab.c"
    break;

  case 625:
#line 3614 "def.y"
      {
        if (defData->callbacks->GroupCbk) {
          char propTp;
          char* str = defData->ringCopy("                       ");
          propTp = defData->session->GroupProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "GROUP");
          sprintf(str, "%g", (yyvsp[0].dval));
          defData->Group.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
        }
      }
#line 8098 "def.tab.c"
    break;

  case 626:
#line 3625 "def.y"
      {
        if (defData->callbacks->GroupCbk) {
          char propTp;
          propTp = defData->session->GroupProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "GROUP");
          defData->Group.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 8111 "def.tab.c"
    break;

  case 627:
#line 3634 "def.y"
      {
        if (defData->callbacks->GroupCbk) {
          char propTp;
          propTp = defData->session->GroupProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "GROUP");
          defData->Group.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 8124 "def.tab.c"
    break;

  case 629:
#line 3645 "def.y"
      { }
#line 8130 "def.tab.c"
    break;

  case 630:
#line 3648 "def.y"
      {
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5)
          if (defData->callbacks->GroupCbk) defData->Group.setMaxX(ROUND((yyvsp[0].dval)));
        else
          defData->defWarning(7028, "The GROUP SOFT MAXX statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8142 "def.tab.c"
    break;

  case 631:
#line 3656 "def.y"
      { 
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5)
          if (defData->callbacks->GroupCbk) defData->Group.setMaxY(ROUND((yyvsp[0].dval)));
        else
          defData->defWarning(7029, "The GROUP SOFT MAXY statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8154 "def.tab.c"
    break;

  case 632:
#line 3664 "def.y"
      { 
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        if (defData->VersionNum < 5.5)
          if (defData->callbacks->GroupCbk) defData->Group.setPerim(ROUND((yyvsp[0].dval)));
        else
          defData->defWarning(7030, "The GROUP SOFT MAXHALFPERIMETER statement is obsolete in version 5.5 and later.\nThe DEF parser will ignore this statement.");
      }
#line 8166 "def.tab.c"
    break;

  case 633:
#line 3673 "def.y"
      { 
        if (defData->callbacks->GroupsEndCbk)
          CALLBACK(defData->callbacks->GroupsEndCbk, defrGroupsEndCbkType, 0);
      }
#line 8175 "def.tab.c"
    break;

  case 636:
#line 3687 "def.y"
      {
        if ((defData->VersionNum < 5.4) && (defData->callbacks->AssertionsStartCbk)) {
          CALLBACK(defData->callbacks->AssertionsStartCbk, defrAssertionsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
        } else {
          if (defData->callbacks->AssertionCbk)
            if (defData->assertionWarnings++ < defData->settings->AssertionWarnings)
              defData->defWarning(7031, "The ASSERTIONS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
        }
        if (defData->callbacks->AssertionCbk)
          defData->Assertion.setAssertionMode();
      }
#line 8192 "def.tab.c"
    break;

  case 637:
#line 3701 "def.y"
      {
        if ((defData->VersionNum < 5.4) && (defData->callbacks->ConstraintsStartCbk)) {
          CALLBACK(defData->callbacks->ConstraintsStartCbk, defrConstraintsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
        } else {
          if (defData->callbacks->ConstraintCbk)
            if (defData->constraintWarnings++ < defData->settings->ConstraintWarnings)
              defData->defWarning(7032, "The CONSTRAINTS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
        }
        if (defData->callbacks->ConstraintCbk)
          defData->Assertion.setConstraintMode();
      }
#line 8209 "def.tab.c"
    break;

  case 641:
#line 3720 "def.y"
      {
        if ((defData->VersionNum < 5.4) && (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)) {
          if (defData->Assertion.isConstraint()) 
            CALLBACK(defData->callbacks->ConstraintCbk, defrConstraintCbkType, &defData->Assertion);
          if (defData->Assertion.isAssertion()) 
            CALLBACK(defData->callbacks->AssertionCbk, defrAssertionCbkType, &defData->Assertion);
        }
      }
#line 8222 "def.tab.c"
    break;

  case 642:
#line 3730 "def.y"
      { 
        if ((defData->VersionNum < 5.4) && (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)) {
          if (defData->Assertion.isConstraint()) 
            CALLBACK(defData->callbacks->ConstraintCbk, defrConstraintCbkType, &defData->Assertion);
          if (defData->Assertion.isAssertion()) 
            CALLBACK(defData->callbacks->AssertionCbk, defrAssertionCbkType, &defData->Assertion);
        }
   
        // reset all the flags and everything
        defData->Assertion.clear();
      }
#line 8238 "def.tab.c"
    break;

  case 643:
#line 3742 "def.y"
               { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8244 "def.tab.c"
    break;

  case 644:
#line 3743 "def.y"
      {
         if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.addNet((yyvsp[0].string));
      }
#line 8253 "def.tab.c"
    break;

  case 645:
#line 3747 "def.y"
               {defData->dumb_mode = 4; defData->no_num = 4;}
#line 8259 "def.tab.c"
    break;

  case 646:
#line 3748 "def.y"
      {
         if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.addPath((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].string));
      }
#line 8268 "def.tab.c"
    break;

  case 647:
#line 3753 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.setSum();
      }
#line 8277 "def.tab.c"
    break;

  case 648:
#line 3758 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
           defData->Assertion.setDiff();
      }
#line 8286 "def.tab.c"
    break;

  case 650:
#line 3765 "def.y"
      { }
#line 8292 "def.tab.c"
    break;

  case 652:
#line 3768 "def.y"
                                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8298 "def.tab.c"
    break;

  case 653:
#line 3770 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setWiredlogic((yyvsp[-4].string), (yyvsp[-1].dval));
      }
#line 8307 "def.tab.c"
    break;

  case 654:
#line 3777 "def.y"
      { (yyval.string) = (char*)""; }
#line 8313 "def.tab.c"
    break;

  case 655:
#line 3779 "def.y"
      { (yyval.string) = (char*)"+"; }
#line 8319 "def.tab.c"
    break;

  case 658:
#line 3786 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setRiseMin((yyvsp[0].dval));
      }
#line 8328 "def.tab.c"
    break;

  case 659:
#line 3791 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setRiseMax((yyvsp[0].dval));
      }
#line 8337 "def.tab.c"
    break;

  case 660:
#line 3796 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setFallMin((yyvsp[0].dval));
      }
#line 8346 "def.tab.c"
    break;

  case 661:
#line 3801 "def.y"
      {
        if (defData->callbacks->ConstraintCbk || defData->callbacks->AssertionCbk)
          defData->Assertion.setFallMax((yyvsp[0].dval));
      }
#line 8355 "def.tab.c"
    break;

  case 662:
#line 3807 "def.y"
      { if ((defData->VersionNum < 5.4) && defData->callbacks->ConstraintsEndCbk) {
          CALLBACK(defData->callbacks->ConstraintsEndCbk, defrConstraintsEndCbkType, 0);
        } else {
          if (defData->callbacks->ConstraintsEndCbk) {
            if (defData->constraintWarnings++ < defData->settings->ConstraintWarnings)
              defData->defWarning(7032, "The CONSTRAINTS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
      }
#line 8369 "def.tab.c"
    break;

  case 663:
#line 3818 "def.y"
      { if ((defData->VersionNum < 5.4) && defData->callbacks->AssertionsEndCbk) {
          CALLBACK(defData->callbacks->AssertionsEndCbk, defrAssertionsEndCbkType, 0);
        } else {
          if (defData->callbacks->AssertionsEndCbk) {
            if (defData->assertionWarnings++ < defData->settings->AssertionWarnings)
              defData->defWarning(7031, "The ASSERTIONS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
          }
        }
      }
#line 8383 "def.tab.c"
    break;

  case 665:
#line 3832 "def.y"
      { if (defData->callbacks->ScanchainsStartCbk)
          CALLBACK(defData->callbacks->ScanchainsStartCbk, defrScanchainsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 8392 "def.tab.c"
    break;

  case 667:
#line 3839 "def.y"
      {}
#line 8398 "def.tab.c"
    break;

  case 668:
#line 3842 "def.y"
      { 
        if (defData->callbacks->ScanchainCbk)
          CALLBACK(defData->callbacks->ScanchainCbk, defrScanchainCbkType, &defData->Scanchain);
      }
#line 8407 "def.tab.c"
    break;

  case 669:
#line 3847 "def.y"
                {defData->dumb_mode = 1; defData->no_num = 1;}
#line 8413 "def.tab.c"
    break;

  case 670:
#line 3848 "def.y"
      {
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setName((yyvsp[0].string));
        defData->bit_is_keyword = TRUE;
      }
#line 8423 "def.tab.c"
    break;

  case 673:
#line 3860 "def.y"
      { (yyval.string) = (char*)""; }
#line 8429 "def.tab.c"
    break;

  case 674:
#line 3862 "def.y"
      { (yyval.string) = (yyvsp[0].string); }
#line 8435 "def.tab.c"
    break;

  case 675:
#line 3864 "def.y"
                         {defData->dumb_mode = 2; defData->no_num = 2;}
#line 8441 "def.tab.c"
    break;

  case 676:
#line 3865 "def.y"
      { if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setStart((yyvsp[-1].string), (yyvsp[0].string));
      }
#line 8449 "def.tab.c"
    break;

  case 677:
#line 3868 "def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8455 "def.tab.c"
    break;

  case 678:
#line 3869 "def.y"
      { defData->dumb_mode = 0; defData->no_num = 0; }
#line 8461 "def.tab.c"
    break;

  case 679:
#line 3871 "def.y"
      {
         defData->dumb_mode = 1;
         defData->no_num = 1;
         if (defData->callbacks->ScanchainCbk)
           defData->Scanchain.addOrderedList();
      }
#line 8472 "def.tab.c"
    break;

  case 680:
#line 3878 "def.y"
      { defData->dumb_mode = 0; defData->no_num = 0; }
#line 8478 "def.tab.c"
    break;

  case 681:
#line 3879 "def.y"
                   {defData->dumb_mode = 2; defData->no_num = 2; }
#line 8484 "def.tab.c"
    break;

  case 682:
#line 3880 "def.y"
      { if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setStop((yyvsp[-1].string), (yyvsp[0].string));
      }
#line 8492 "def.tab.c"
    break;

  case 683:
#line 3883 "def.y"
                             { defData->dumb_mode = 10; defData->no_num = 10; }
#line 8498 "def.tab.c"
    break;

  case 684:
#line 3884 "def.y"
      { defData->dumb_mode = 0;  defData->no_num = 0; }
#line 8504 "def.tab.c"
    break;

  case 685:
#line 3885 "def.y"
                        { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8510 "def.tab.c"
    break;

  case 686:
#line 3887 "def.y"
      {
        if (defData->VersionNum < 5.5) {
          if (defData->callbacks->ScanchainCbk) {
            if (defData->scanchainWarnings++ < defData->settings->ScanchainWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The PARTITION statement is available in version 5.5 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6538, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        }
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.setPartition((yyvsp[-1].string), (yyvsp[0].integer));
      }
#line 8531 "def.tab.c"
    break;

  case 687:
#line 3904 "def.y"
      {
        if (defData->callbacks->ScanChainExtCbk)
          CALLBACK(defData->callbacks->ScanChainExtCbk, defrScanChainExtCbkType, &defData->History_text[0]);
      }
#line 8540 "def.tab.c"
    break;

  case 688:
#line 3910 "def.y"
      { }
#line 8546 "def.tab.c"
    break;

  case 689:
#line 3912 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.setCommonIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.setCommonOut((yyvsp[-1].string));
        }
      }
#line 8559 "def.tab.c"
    break;

  case 690:
#line 3921 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.setCommonIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.setCommonOut((yyvsp[-5].string));
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.setCommonIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.setCommonOut((yyvsp[-1].string));
        }
      }
#line 8576 "def.tab.c"
    break;

  case 693:
#line 3939 "def.y"
      {
        defData->dumb_mode = 1000;
        defData->no_num = 1000;
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.addFloatingInst((yyvsp[0].string));
      }
#line 8587 "def.tab.c"
    break;

  case 694:
#line 3946 "def.y"
      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8593 "def.tab.c"
    break;

  case 695:
#line 3949 "def.y"
      { }
#line 8599 "def.tab.c"
    break;

  case 696:
#line 3951 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
        }
      }
#line 8616 "def.tab.c"
    break;

  case 697:
#line 3964 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
        }
      }
#line 8641 "def.tab.c"
    break;

  case 698:
#line 3986 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-10].string), "IN") == 0 || strcmp((yyvsp[-10].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "OUT") == 0 || strcmp((yyvsp[-10].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "BITS") == 0 || strcmp((yyvsp[-10].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-9].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addFloatingIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addFloatingOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setFloatingBits(defData->bitsNum);
          }
        }
      }
#line 8674 "def.tab.c"
    break;

  case 701:
#line 4020 "def.y"
      { defData->dumb_mode = 1000; defData->no_num = 1000; 
        if (defData->callbacks->ScanchainCbk)
          defData->Scanchain.addOrderedInst((yyvsp[0].string));
      }
#line 8683 "def.tab.c"
    break;

  case 702:
#line 4025 "def.y"
      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 8689 "def.tab.c"
    break;

  case 703:
#line 4028 "def.y"
      { }
#line 8695 "def.tab.c"
    break;

  case 704:
#line 4030 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
         }
        }
      }
#line 8712 "def.tab.c"
    break;

  case 705:
#line 4043 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
        }
      }
#line 8737 "def.tab.c"
    break;

  case 706:
#line 4065 "def.y"
      {
        if (defData->callbacks->ScanchainCbk) {
          if (strcmp((yyvsp[-10].string), "IN") == 0 || strcmp((yyvsp[-10].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "OUT") == 0 || strcmp((yyvsp[-10].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-9].string));
          else if (strcmp((yyvsp[-10].string), "BITS") == 0 || strcmp((yyvsp[-10].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-9].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-6].string), "IN") == 0 || strcmp((yyvsp[-6].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "OUT") == 0 || strcmp((yyvsp[-6].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-5].string));
          else if (strcmp((yyvsp[-6].string), "BITS") == 0 || strcmp((yyvsp[-6].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-5].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
          if (strcmp((yyvsp[-2].string), "IN") == 0 || strcmp((yyvsp[-2].string), "in") == 0)
            defData->Scanchain.addOrderedIn((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "OUT") == 0 || strcmp((yyvsp[-2].string), "out") == 0)
            defData->Scanchain.addOrderedOut((yyvsp[-1].string));
          else if (strcmp((yyvsp[-2].string), "BITS") == 0 || strcmp((yyvsp[-2].string), "bits") == 0) {
            defData->bitsNum = atoi((yyvsp[-1].string));
            defData->Scanchain.setOrderedBits(defData->bitsNum);
          }
        }
      }
#line 8770 "def.tab.c"
    break;

  case 707:
#line 4095 "def.y"
      { (yyval.integer) = -1; }
#line 8776 "def.tab.c"
    break;

  case 708:
#line 4097 "def.y"
      { (yyval.integer) = ROUND((yyvsp[0].dval)); }
#line 8782 "def.tab.c"
    break;

  case 709:
#line 4100 "def.y"
      { 
        if (defData->callbacks->ScanchainsEndCbk)
          CALLBACK(defData->callbacks->ScanchainsEndCbk, defrScanchainsEndCbkType, 0);
        defData->bit_is_keyword = FALSE;
        defData->dumb_mode = 0; defData->no_num = 0;
      }
#line 8793 "def.tab.c"
    break;

  case 711:
#line 4112 "def.y"
      {
        if (defData->VersionNum < 5.4 && defData->callbacks->IOTimingsStartCbk) {
          CALLBACK(defData->callbacks->IOTimingsStartCbk, defrIOTimingsStartCbkType, ROUND((yyvsp[-1].dval)));
        } else {
          if (defData->callbacks->IOTimingsStartCbk)
            if (defData->iOTimingWarnings++ < defData->settings->IOTimingWarnings)
              defData->defWarning(7035, "The IOTIMINGS statement is obsolete in version 5.4 and later.\nThe DEF parser will ignore this statement.");
        }
      }
#line 8807 "def.tab.c"
    break;

  case 713:
#line 4124 "def.y"
      { }
#line 8813 "def.tab.c"
    break;

  case 714:
#line 4127 "def.y"
      { 
        if (defData->VersionNum < 5.4 && defData->callbacks->IOTimingCbk)
          CALLBACK(defData->callbacks->IOTimingCbk, defrIOTimingCbkType, &defData->IOTiming);
      }
#line 8822 "def.tab.c"
    break;

  case 715:
#line 4132 "def.y"
                        {defData->dumb_mode = 2; defData->no_num = 2; }
#line 8828 "def.tab.c"
    break;

  case 716:
#line 4133 "def.y"
      {
        if (defData->callbacks->IOTimingCbk)
          defData->IOTiming.setName((yyvsp[-2].string), (yyvsp[-1].string));
      }
#line 8837 "def.tab.c"
    break;

  case 719:
#line 4144 "def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setVariable((yyvsp[-3].string), (yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 8846 "def.tab.c"
    break;

  case 720:
#line 4149 "def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setSlewRate((yyvsp[-3].string), (yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 8855 "def.tab.c"
    break;

  case 721:
#line 4154 "def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setCapacitance((yyvsp[0].dval));
      }
#line 8864 "def.tab.c"
    break;

  case 722:
#line 4158 "def.y"
                        {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8870 "def.tab.c"
    break;

  case 723:
#line 4159 "def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setDriveCell((yyvsp[0].string));
      }
#line 8879 "def.tab.c"
    break;

  case 725:
#line 4168 "def.y"
      {
        if (defData->VersionNum < 5.4 && defData->callbacks->IoTimingsExtCbk)
          CALLBACK(defData->callbacks->IoTimingsExtCbk, defrIoTimingsExtCbkType, &defData->History_text[0]);
      }
#line 8888 "def.tab.c"
    break;

  case 726:
#line 4174 "def.y"
              {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8894 "def.tab.c"
    break;

  case 727:
#line 4175 "def.y"
      {
        if (defData->callbacks->IOTimingCbk) 
          defData->IOTiming.setTo((yyvsp[0].string));
      }
#line 8903 "def.tab.c"
    break;

  case 730:
#line 4182 "def.y"
                  {defData->dumb_mode = 1; defData->no_num = 1; }
#line 8909 "def.tab.c"
    break;

  case 731:
#line 4183 "def.y"
      {
        if (defData->callbacks->IOTimingCbk)
          defData->IOTiming.setFrom((yyvsp[0].string));
      }
#line 8918 "def.tab.c"
    break;

  case 733:
#line 4190 "def.y"
      {
        if (defData->callbacks->IOTimingCbk)
          defData->IOTiming.setParallel((yyvsp[0].dval));
      }
#line 8927 "def.tab.c"
    break;

  case 734:
#line 4195 "def.y"
                 { (yyval.string) = (char*)"RISE"; }
#line 8933 "def.tab.c"
    break;

  case 735:
#line 4195 "def.y"
                                                  { (yyval.string) = (char*)"FALL"; }
#line 8939 "def.tab.c"
    break;

  case 736:
#line 4198 "def.y"
      {
        if (defData->VersionNum < 5.4 && defData->callbacks->IOTimingsEndCbk)
          CALLBACK(defData->callbacks->IOTimingsEndCbk, defrIOTimingsEndCbkType, 0);
      }
#line 8948 "def.tab.c"
    break;

  case 737:
#line 4204 "def.y"
      { 
        if (defData->callbacks->FPCEndCbk)
          CALLBACK(defData->callbacks->FPCEndCbk, defrFPCEndCbkType, 0);
      }
#line 8957 "def.tab.c"
    break;

  case 738:
#line 4210 "def.y"
      {
        if (defData->callbacks->FPCStartCbk)
          CALLBACK(defData->callbacks->FPCStartCbk, defrFPCStartCbkType, ROUND((yyvsp[-1].dval)));
      }
#line 8966 "def.tab.c"
    break;

  case 740:
#line 4217 "def.y"
      {}
#line 8972 "def.tab.c"
    break;

  case 741:
#line 4219 "def.y"
             { defData->dumb_mode = 1; defData->no_num = 1;  }
#line 8978 "def.tab.c"
    break;

  case 742:
#line 4220 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setName((yyvsp[-1].string), (yyvsp[0].string)); }
#line 8984 "def.tab.c"
    break;

  case 743:
#line 4222 "def.y"
      { if (defData->callbacks->FPCCbk) CALLBACK(defData->callbacks->FPCCbk, defrFPCCbkType, &defData->FPC); }
#line 8990 "def.tab.c"
    break;

  case 744:
#line 4225 "def.y"
      { (yyval.string) = (char*)"HORIZONTAL"; }
#line 8996 "def.tab.c"
    break;

  case 745:
#line 4227 "def.y"
      { (yyval.string) = (char*)"VERTICAL"; }
#line 9002 "def.tab.c"
    break;

  case 746:
#line 4230 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setAlign(); }
#line 9008 "def.tab.c"
    break;

  case 747:
#line 4232 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setMax((yyvsp[0].dval)); }
#line 9014 "def.tab.c"
    break;

  case 748:
#line 4234 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setMin((yyvsp[0].dval)); }
#line 9020 "def.tab.c"
    break;

  case 749:
#line 4236 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setEqual((yyvsp[0].dval)); }
#line 9026 "def.tab.c"
    break;

  case 752:
#line 4243 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setDoingBottomLeft(); }
#line 9032 "def.tab.c"
    break;

  case 754:
#line 4246 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.setDoingTopRight(); }
#line 9038 "def.tab.c"
    break;

  case 758:
#line 4253 "def.y"
                         {defData->dumb_mode = 1; defData->no_num = 1; }
#line 9044 "def.tab.c"
    break;

  case 759:
#line 4254 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.addRow((yyvsp[-1].string)); }
#line 9050 "def.tab.c"
    break;

  case 760:
#line 4255 "def.y"
                       {defData->dumb_mode = 1; defData->no_num = 1; }
#line 9056 "def.tab.c"
    break;

  case 761:
#line 4256 "def.y"
      { if (defData->callbacks->FPCCbk) defData->FPC.addComps((yyvsp[-1].string)); }
#line 9062 "def.tab.c"
    break;

  case 763:
#line 4263 "def.y"
      { 
        if (defData->callbacks->TimingDisablesStartCbk)
          CALLBACK(defData->callbacks->TimingDisablesStartCbk, defrTimingDisablesStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 9072 "def.tab.c"
    break;

  case 765:
#line 4271 "def.y"
      {}
#line 9078 "def.tab.c"
    break;

  case 766:
#line 4273 "def.y"
                                   { defData->dumb_mode = 2; defData->no_num = 2;  }
#line 9084 "def.tab.c"
    break;

  case 767:
#line 4274 "def.y"
                       { defData->dumb_mode = 2; defData->no_num = 2;  }
#line 9090 "def.tab.c"
    break;

  case 768:
#line 4275 "def.y"
      {
        if (defData->callbacks->TimingDisableCbk) {
          defData->TimingDisable.setFromTo((yyvsp[-6].string), (yyvsp[-5].string), (yyvsp[-2].string), (yyvsp[-1].string));
          CALLBACK(defData->callbacks->TimingDisableCbk, defrTimingDisableCbkType,
                &defData->TimingDisable);
        }
      }
#line 9102 "def.tab.c"
    break;

  case 769:
#line 4282 "def.y"
                      {defData->dumb_mode = 2; defData->no_num = 2; }
#line 9108 "def.tab.c"
    break;

  case 770:
#line 4283 "def.y"
      {
        if (defData->callbacks->TimingDisableCbk) {
          defData->TimingDisable.setThru((yyvsp[-2].string), (yyvsp[-1].string));
          CALLBACK(defData->callbacks->TimingDisableCbk, defrTimingDisableCbkType,
                   &defData->TimingDisable);
        }
      }
#line 9120 "def.tab.c"
    break;

  case 771:
#line 4290 "def.y"
                    {defData->dumb_mode = 1; defData->no_num = 1;}
#line 9126 "def.tab.c"
    break;

  case 772:
#line 4291 "def.y"
      {
        if (defData->callbacks->TimingDisableCbk) {
          defData->TimingDisable.setMacro((yyvsp[-2].string));
          CALLBACK(defData->callbacks->TimingDisableCbk, defrTimingDisableCbkType,
                &defData->TimingDisable);
        }
      }
#line 9138 "def.tab.c"
    break;

  case 773:
#line 4299 "def.y"
      { if (defData->callbacks->TimingDisableCbk)
          defData->TimingDisable.setReentrantPathsFlag();
      }
#line 9146 "def.tab.c"
    break;

  case 774:
#line 4304 "def.y"
                           {defData->dumb_mode = 1; defData->no_num = 1;}
#line 9152 "def.tab.c"
    break;

  case 775:
#line 4305 "def.y"
      {defData->dumb_mode=1; defData->no_num = 1;}
#line 9158 "def.tab.c"
    break;

  case 776:
#line 4306 "def.y"
      {
        if (defData->callbacks->TimingDisableCbk)
          defData->TimingDisable.setMacroFromTo((yyvsp[-3].string),(yyvsp[0].string));
      }
#line 9167 "def.tab.c"
    break;

  case 777:
#line 4310 "def.y"
                         {defData->dumb_mode=1; defData->no_num = 1;}
#line 9173 "def.tab.c"
    break;

  case 778:
#line 4311 "def.y"
      {
        if (defData->callbacks->TimingDisableCbk)
          defData->TimingDisable.setMacroThru((yyvsp[0].string));
      }
#line 9182 "def.tab.c"
    break;

  case 779:
#line 4317 "def.y"
      { 
        if (defData->callbacks->TimingDisablesEndCbk)
          CALLBACK(defData->callbacks->TimingDisablesEndCbk, defrTimingDisablesEndCbkType, 0);
      }
#line 9191 "def.tab.c"
    break;

  case 781:
#line 4327 "def.y"
      {
        if (defData->callbacks->PartitionsStartCbk)
          CALLBACK(defData->callbacks->PartitionsStartCbk, defrPartitionsStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 9201 "def.tab.c"
    break;

  case 783:
#line 4335 "def.y"
      { }
#line 9207 "def.tab.c"
    break;

  case 784:
#line 4338 "def.y"
      { 
        if (defData->callbacks->PartitionCbk)
          CALLBACK(defData->callbacks->PartitionCbk, defrPartitionCbkType, &defData->Partition);
      }
#line 9216 "def.tab.c"
    break;

  case 785:
#line 4343 "def.y"
                     { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9222 "def.tab.c"
    break;

  case 786:
#line 4344 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setName((yyvsp[-1].string));
      }
#line 9231 "def.tab.c"
    break;

  case 788:
#line 4351 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.addTurnOff((yyvsp[-1].string), (yyvsp[0].string));
      }
#line 9240 "def.tab.c"
    break;

  case 789:
#line 4357 "def.y"
      { (yyval.string) = (char*)" "; }
#line 9246 "def.tab.c"
    break;

  case 790:
#line 4359 "def.y"
      { (yyval.string) = (char*)"R"; }
#line 9252 "def.tab.c"
    break;

  case 791:
#line 4361 "def.y"
      { (yyval.string) = (char*)"F"; }
#line 9258 "def.tab.c"
    break;

  case 792:
#line 4364 "def.y"
      { (yyval.string) = (char*)" "; }
#line 9264 "def.tab.c"
    break;

  case 793:
#line 4366 "def.y"
      { (yyval.string) = (char*)"R"; }
#line 9270 "def.tab.c"
    break;

  case 794:
#line 4368 "def.y"
      { (yyval.string) = (char*)"F"; }
#line 9276 "def.tab.c"
    break;

  case 797:
#line 4374 "def.y"
                                     {defData->dumb_mode=2; defData->no_num = 2;}
#line 9282 "def.tab.c"
    break;

  case 798:
#line 4376 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setFromClockPin((yyvsp[-3].string), (yyvsp[-2].string));
      }
#line 9291 "def.tab.c"
    break;

  case 799:
#line 4380 "def.y"
                          {defData->dumb_mode=2; defData->no_num = 2; }
#line 9297 "def.tab.c"
    break;

  case 800:
#line 4382 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setFromCompPin((yyvsp[-2].string), (yyvsp[-1].string));
      }
#line 9306 "def.tab.c"
    break;

  case 801:
#line 4386 "def.y"
                        {defData->dumb_mode=1; defData->no_num = 1; }
#line 9312 "def.tab.c"
    break;

  case 802:
#line 4388 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setFromIOPin((yyvsp[-1].string));
      }
#line 9321 "def.tab.c"
    break;

  case 803:
#line 4392 "def.y"
                         {defData->dumb_mode=2; defData->no_num = 2; }
#line 9327 "def.tab.c"
    break;

  case 804:
#line 4394 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setToClockPin((yyvsp[-3].string), (yyvsp[-2].string));
      }
#line 9336 "def.tab.c"
    break;

  case 805:
#line 4398 "def.y"
                        {defData->dumb_mode=2; defData->no_num = 2; }
#line 9342 "def.tab.c"
    break;

  case 806:
#line 4400 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setToCompPin((yyvsp[-2].string), (yyvsp[-1].string));
      }
#line 9351 "def.tab.c"
    break;

  case 807:
#line 4404 "def.y"
                      {defData->dumb_mode=1; defData->no_num = 2; }
#line 9357 "def.tab.c"
    break;

  case 808:
#line 4405 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setToIOPin((yyvsp[-1].string));
      }
#line 9366 "def.tab.c"
    break;

  case 809:
#line 4410 "def.y"
      { 
        if (defData->callbacks->PartitionsExtCbk)
          CALLBACK(defData->callbacks->PartitionsExtCbk, defrPartitionsExtCbkType,
                   &defData->History_text[0]);
      }
#line 9376 "def.tab.c"
    break;

  case 810:
#line 4417 "def.y"
      { defData->dumb_mode = DEF_MAX_INT; defData->no_num = DEF_MAX_INT; }
#line 9382 "def.tab.c"
    break;

  case 811:
#line 4418 "def.y"
      { defData->dumb_mode = 0; defData->no_num = 0; }
#line 9388 "def.tab.c"
    break;

  case 813:
#line 4422 "def.y"
      { }
#line 9394 "def.tab.c"
    break;

  case 814:
#line 4425 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setMin((yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 9403 "def.tab.c"
    break;

  case 815:
#line 4430 "def.y"
      {
        if (defData->callbacks->PartitionCbk)
          defData->Partition.setMax((yyvsp[-1].dval), (yyvsp[0].dval));
      }
#line 9412 "def.tab.c"
    break;

  case 817:
#line 4437 "def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addPin((yyvsp[0].string)); }
#line 9418 "def.tab.c"
    break;

  case 820:
#line 4443 "def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addRiseMin((yyvsp[0].dval)); }
#line 9424 "def.tab.c"
    break;

  case 821:
#line 4445 "def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addFallMin((yyvsp[0].dval)); }
#line 9430 "def.tab.c"
    break;

  case 822:
#line 4447 "def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addRiseMax((yyvsp[0].dval)); }
#line 9436 "def.tab.c"
    break;

  case 823:
#line 4449 "def.y"
      { if (defData->callbacks->PartitionCbk) defData->Partition.addFallMax((yyvsp[0].dval)); }
#line 9442 "def.tab.c"
    break;

  case 826:
#line 4457 "def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addRiseMinRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9449 "def.tab.c"
    break;

  case 827:
#line 4460 "def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addFallMinRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9456 "def.tab.c"
    break;

  case 828:
#line 4463 "def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addRiseMaxRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9463 "def.tab.c"
    break;

  case 829:
#line 4466 "def.y"
      { if (defData->callbacks->PartitionCbk)
          defData->Partition.addFallMaxRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 9470 "def.tab.c"
    break;

  case 830:
#line 4470 "def.y"
      { if (defData->callbacks->PartitionsEndCbk)
          CALLBACK(defData->callbacks->PartitionsEndCbk, defrPartitionsEndCbkType, 0); }
#line 9477 "def.tab.c"
    break;

  case 832:
#line 4475 "def.y"
      { }
#line 9483 "def.tab.c"
    break;

  case 833:
#line 4477 "def.y"
               {defData->dumb_mode=2; defData->no_num = 2; }
#line 9489 "def.tab.c"
    break;

  case 834:
#line 4479 "def.y"
      {
        // note that the defData->first T_STRING could be the keyword VPIN 
        if (defData->callbacks->NetCbk)
          defData->Subnet->addPin((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].integer));
      }
#line 9499 "def.tab.c"
    break;

  case 835:
#line 4486 "def.y"
      { (yyval.integer) = 0; }
#line 9505 "def.tab.c"
    break;

  case 836:
#line 4488 "def.y"
      { (yyval.integer) = 1; }
#line 9511 "def.tab.c"
    break;

  case 839:
#line 4494 "def.y"
      {  
        if (defData->callbacks->NetCbk) defData->Subnet->addWire((yyvsp[0].string));
      }
#line 9519 "def.tab.c"
    break;

  case 840:
#line 4498 "def.y"
      {  
        defData->by_is_keyword = FALSE;
        defData->do_is_keyword = FALSE;
        defData->new_is_keyword = FALSE;
        defData->step_is_keyword = FALSE;
        defData->orient_is_keyword = FALSE;
        defData->needNPCbk = 0;
      }
#line 9532 "def.tab.c"
    break;

  case 841:
#line 4506 "def.y"
                         { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9538 "def.tab.c"
    break;

  case 842:
#line 4507 "def.y"
      { if (defData->callbacks->NetCbk) defData->Subnet->setNonDefault((yyvsp[0].string)); }
#line 9544 "def.tab.c"
    break;

  case 843:
#line 4510 "def.y"
      { (yyval.string) = (char*)"FIXED"; defData->dumb_mode = 1; }
#line 9550 "def.tab.c"
    break;

  case 844:
#line 4512 "def.y"
      { (yyval.string) = (char*)"COVER"; defData->dumb_mode = 1; }
#line 9556 "def.tab.c"
    break;

  case 845:
#line 4514 "def.y"
      { (yyval.string) = (char*)"ROUTED"; defData->dumb_mode = 1; }
#line 9562 "def.tab.c"
    break;

  case 846:
#line 4516 "def.y"
      { (yyval.string) = (char*)"NOSHIELD"; defData->dumb_mode = 1; }
#line 9568 "def.tab.c"
    break;

  case 848:
#line 4521 "def.y"
      { if (defData->callbacks->PinPropStartCbk)
          CALLBACK(defData->callbacks->PinPropStartCbk, defrPinPropStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 9575 "def.tab.c"
    break;

  case 849:
#line 4526 "def.y"
      { }
#line 9581 "def.tab.c"
    break;

  case 850:
#line 4528 "def.y"
      { }
#line 9587 "def.tab.c"
    break;

  case 851:
#line 4531 "def.y"
      { if (defData->callbacks->PinPropEndCbk)
          CALLBACK(defData->callbacks->PinPropEndCbk, defrPinPropEndCbkType, 0); }
#line 9594 "def.tab.c"
    break;

  case 854:
#line 4538 "def.y"
                       { defData->dumb_mode = 2; defData->no_num = 2; }
#line 9600 "def.tab.c"
    break;

  case 855:
#line 4539 "def.y"
      { if (defData->callbacks->PinPropCbk) defData->PinProp.setName((yyvsp[-1].string), (yyvsp[0].string)); }
#line 9606 "def.tab.c"
    break;

  case 856:
#line 4541 "def.y"
      { if (defData->callbacks->PinPropCbk) {
          CALLBACK(defData->callbacks->PinPropCbk, defrPinPropCbkType, &defData->PinProp);
         // reset the property number
         defData->PinProp.clear();
        }
      }
#line 9617 "def.tab.c"
    break;

  case 859:
#line 4551 "def.y"
                         { defData->dumb_mode = DEF_MAX_INT; }
#line 9623 "def.tab.c"
    break;

  case 860:
#line 4553 "def.y"
      { defData->dumb_mode = 0; }
#line 9629 "def.tab.c"
    break;

  case 863:
#line 4560 "def.y"
      {
        if (defData->callbacks->PinPropCbk) {
          char propTp;
          char* str = defData->ringCopy("                       ");
          propTp = defData->session->CompPinProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "PINPROPERTIES");
          sprintf(str, "%g", (yyvsp[0].dval));
          defData->PinProp.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
        }
      }
#line 9644 "def.tab.c"
    break;

  case 864:
#line 4571 "def.y"
      {
        if (defData->callbacks->PinPropCbk) {
          char propTp;
          propTp = defData->session->CompPinProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "PINPROPERTIES");
          defData->PinProp.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 9657 "def.tab.c"
    break;

  case 865:
#line 4580 "def.y"
      {
        if (defData->callbacks->PinPropCbk) {
          char propTp;
          propTp = defData->session->CompPinProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "PINPROPERTIES");
          defData->PinProp.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 9670 "def.tab.c"
    break;

  case 867:
#line 4592 "def.y"
      { if (defData->callbacks->BlockageStartCbk)
          CALLBACK(defData->callbacks->BlockageStartCbk, defrBlockageStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 9677 "def.tab.c"
    break;

  case 868:
#line 4596 "def.y"
      { if (defData->callbacks->BlockageEndCbk)
          CALLBACK(defData->callbacks->BlockageEndCbk, defrBlockageEndCbkType, 0); }
#line 9684 "def.tab.c"
    break;

  case 871:
#line 4605 "def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          CALLBACK(defData->callbacks->BlockageCbk, defrBlockageCbkType, &defData->Blockage);
          defData->Blockage.clear();
        }
      }
#line 9695 "def.tab.c"
    break;

  case 872:
#line 4612 "def.y"
                           { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9701 "def.tab.c"
    break;

  case 873:
#line 4613 "def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          if (defData->Blockage.hasPlacement() != 0) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6539, "Invalid BLOCKAGE statement defined in the DEF file. The BLOCKAGE statment has both the LAYER and the PLACEMENT statements defined.\nUpdate your DEF file to have either BLOCKAGE or PLACEMENT statement only.");
              CHKERR();
            }
          }
          defData->Blockage.setLayer((yyvsp[0].string));
          defData->Blockage.clearPoly(); // free poly, if any
        }
        defData->hasBlkLayerComp = 0;
        defData->hasBlkLayerSpac = 0;
        defData->hasBlkLayerTypeComp = 0;
      }
#line 9721 "def.tab.c"
    break;

  case 875:
#line 4632 "def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          if (defData->Blockage.hasLayer() != 0) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6539, "Invalid BLOCKAGE statement defined in the DEF file. The BLOCKAGE statment has both the LAYER and the PLACEMENT statements defined.\nUpdate your DEF file to have either BLOCKAGE or PLACEMENT statement only.");
              CHKERR();
            }
          }
          defData->Blockage.setPlacement();
          defData->Blockage.clearPoly(); // free poly, if any
        }
        defData->hasBlkPlaceComp = 0;
        defData->hasBlkPlaceTypeComp = 0;
      }
#line 9740 "def.tab.c"
    break;

  case 879:
#line 4653 "def.y"
      {
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The SPACING statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6540, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else if (defData->hasBlkLayerSpac) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6541, "The SPACING statement is defined in the LAYER statement,\nbut there is already either a SPACING statement or DESIGNRULEWIDTH  statement has defined in the LAYER statement.\nUpdate your DEF file to have either SPACING statement or a DESIGNRULEWIDTH statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk)
            defData->Blockage.setSpacing((int)(yyvsp[0].dval));
          defData->hasBlkLayerSpac = 1;
        }
      }
#line 9770 "def.tab.c"
    break;

  case 880:
#line 4679 "def.y"
      {
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6541, "The SPACING statement is defined in the LAYER statement,\nbut there is already either a SPACING statement or DESIGNRULEWIDTH  statement has defined in the LAYER statement.\nUpdate your DEF file to have either SPACING statement or a DESIGNRULEWIDTH statement.");
              CHKERR();
            }
          }
        } else if (defData->hasBlkLayerSpac) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6541, "The SPACING statement is defined in the LAYER statement,\nbut there is already either a SPACING statement or DESIGNRULEWIDTH  statement has defined in the LAYER statement.\nUpdate your DEF file to have either SPACING statement or a DESIGNRULEWIDTH statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk)
            defData->Blockage.setDesignRuleWidth((int)(yyvsp[0].dval));
          defData->hasBlkLayerSpac = 1;
        }
      }
#line 9796 "def.tab.c"
    break;

  case 883:
#line 4705 "def.y"
      {      
        if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->blockageWarnings, defData->settings->BlockageWarnings)) {
          defData->Blockage.setMask((int)(yyvsp[0].dval));
        }
      }
#line 9806 "def.tab.c"
    break;

  case 884:
#line 4713 "def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9812 "def.tab.c"
    break;

  case 885:
#line 4714 "def.y"
      {
        if (defData->hasBlkLayerComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk) {
            defData->Blockage.setComponent((yyvsp[0].string));
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
        }
      }
#line 9834 "def.tab.c"
    break;

  case 886:
#line 4733 "def.y"
      {
        if (defData->hasBlkLayerComp || defData->hasBlkLayerTypeComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk) {
            defData->Blockage.setSlots();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
          if (defData->VersionNum == 5.8) {
            defData->hasBlkLayerTypeComp = 1;
          }
        }
      }
#line 9859 "def.tab.c"
    break;

  case 887:
#line 4754 "def.y"
      {
        if (defData->hasBlkLayerComp || defData->hasBlkLayerTypeComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setFills();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
          if (defData->VersionNum == 5.8) {
            defData->hasBlkLayerTypeComp = 1;
          }
        }
      }
#line 9884 "def.tab.c"
    break;

  case 888:
#line 4775 "def.y"
      {
        if (defData->hasBlkLayerComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setPushdown();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkLayerComp = 1;
          }
        }
      }
#line 9906 "def.tab.c"
    break;

  case 889:
#line 4793 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->BlockageCbk) {
             if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The EXCEPTPGNET is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6549, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
              }
           }
        } else {
           if (defData->hasBlkLayerComp) {
             if (defData->callbacks->BlockageCbk) {
               if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                 defData->defError(6542, "The defined BLOCKAGES COMPONENT statement has either COMPONENT, SLOTS, FILLS, PUSHDOWN or EXCEPTPGNET defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES COMPONENT statement per layer.");
                 CHKERR();
               }
             }
           } else {
             if (defData->callbacks->BlockageCbk){
               defData->Blockage.setExceptpgnet();
             }
             if (defData->VersionNum < 5.8){
               defData->hasBlkLayerComp = 1;
             }
           }
        }
      }
#line 9941 "def.tab.c"
    break;

  case 892:
#line 4830 "def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 9947 "def.tab.c"
    break;

  case 893:
#line 4831 "def.y"
      {
        if (defData->hasBlkPlaceComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setComponent((yyvsp[0].string));
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkPlaceComp = 1;
          }
        }
      }
#line 9969 "def.tab.c"
    break;

  case 894:
#line 4849 "def.y"
      {
        if (defData->hasBlkPlaceComp) {
          if (defData->callbacks->BlockageCbk) {
            if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
              defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
              CHKERR();
            }
          }
        } else {
          if (defData->callbacks->BlockageCbk){
            defData->Blockage.setPushdown();
          }
          if (defData->VersionNum < 5.8) {
            defData->hasBlkPlaceComp = 1;
          }
        }
      }
#line 9991 "def.tab.c"
    break;

  case 895:
#line 4867 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->BlockageCbk) {
             if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The PLACEMENT SOFT is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6547, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else {
           if (defData->hasBlkPlaceComp || defData->hasBlkPlaceTypeComp) {
             if (defData->callbacks->BlockageCbk) {
               if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                 defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
                 CHKERR();
               }
             }
           } else {
             if (defData->callbacks->BlockageCbk){
               defData->Blockage.setSoft();
             }
             if (defData->VersionNum < 5.8) {
               defData->hasBlkPlaceComp = 1;
             }
             if (defData->VersionNum == 5.8) {
               defData->hasBlkPlaceTypeComp = 1;
             }
           }
        }
      }
#line 10029 "def.tab.c"
    break;

  case 896:
#line 4901 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->BlockageCbk) {
             if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                defData->defMsg = (char*)malloc(10000);
                sprintf (defData->defMsg,
                  "The PARTIAL is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
                defData->defError(6548, defData->defMsg);
                free(defData->defMsg);
                CHKERR();
             }
           }
        } else {
           if (defData->hasBlkPlaceComp || defData->hasBlkPlaceTypeComp) {
             if (defData->callbacks->BlockageCbk) {
               if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                 defData->defError(6543, "The defined BLOCKAGES PLACEMENT statement has either COMPONENT, PUSHDOWN, SOFT or PARTIAL defined.\nOnly one of these statements is allowed per LAYER. Updated the DEF file to define a valid BLOCKAGES PLACEMENT statement.");
                 CHKERR();
               }
             }
           } else {
             if (defData->callbacks->BlockageCbk){
               defData->Blockage.setPartial((yyvsp[0].dval));
             } 
             if (defData->VersionNum < 5.8) {
               defData->hasBlkPlaceComp = 1;
             }
             if (defData->VersionNum == 5.8) {
               defData->hasBlkPlaceTypeComp = 1;
             }
           }
         }
      }
#line 10067 "def.tab.c"
    break;

  case 899:
#line 4941 "def.y"
      {
        if (defData->callbacks->BlockageCbk)
          defData->Blockage.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
#line 10076 "def.tab.c"
    break;

  case 900:
#line 4946 "def.y"
      {
        if (defData->callbacks->BlockageCbk) {
            defData->Geometries.Reset();
        }
      }
#line 10086 "def.tab.c"
    break;

  case 901:
#line 4952 "def.y"
      {
        if (defData->callbacks->BlockageCbk) {
          if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond
            if (defData->Blockage.hasLayer()) {  // only in layer
              if (defData->callbacks->BlockageCbk)
                defData->Blockage.addPolygon(&defData->Geometries);
            } else {
              if (defData->callbacks->BlockageCbk) {
                if (defData->blockageWarnings++ < defData->settings->BlockageWarnings) {
                  defData->defError(6544, "A POLYGON statement is defined in the BLOCKAGE statement,\nbut it is not defined in the BLOCKAGE LAYER statement.\nUpdate your DEF file to either remove the POLYGON statement from the BLOCKAGE statement or\ndefine the POLYGON statement in a BLOCKAGE LAYER statement.");
                  CHKERR();
                }
              }
            }
          }
        }
      }
#line 10108 "def.tab.c"
    break;

  case 903:
#line 4974 "def.y"
      { if (defData->callbacks->SlotStartCbk)
          CALLBACK(defData->callbacks->SlotStartCbk, defrSlotStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 10115 "def.tab.c"
    break;

  case 904:
#line 4978 "def.y"
      { if (defData->callbacks->SlotEndCbk)
          CALLBACK(defData->callbacks->SlotEndCbk, defrSlotEndCbkType, 0); }
#line 10122 "def.tab.c"
    break;

  case 907:
#line 4986 "def.y"
      {
        if (defData->callbacks->SlotCbk) {
          CALLBACK(defData->callbacks->SlotCbk, defrSlotCbkType, &defData->Slot);
          defData->Slot.clear();
        }
      }
#line 10133 "def.tab.c"
    break;

  case 908:
#line 4993 "def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10139 "def.tab.c"
    break;

  case 909:
#line 4994 "def.y"
      {
        if (defData->callbacks->SlotCbk) {
          defData->Slot.setLayer((yyvsp[0].string));
          defData->Slot.clearPoly();     // free poly, if any
        }
      }
#line 10150 "def.tab.c"
    break;

  case 913:
#line 5006 "def.y"
      {
        if (defData->callbacks->SlotCbk)
          defData->Slot.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
#line 10159 "def.tab.c"
    break;

  case 914:
#line 5011 "def.y"
      {
          defData->Geometries.Reset();
      }
#line 10167 "def.tab.c"
    break;

  case 915:
#line 5015 "def.y"
      {
        if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond
          if (defData->callbacks->SlotCbk)
            defData->Slot.addPolygon(&defData->Geometries);
        }
      }
#line 10178 "def.tab.c"
    break;

  case 917:
#line 5026 "def.y"
      { if (defData->callbacks->FillStartCbk)
          CALLBACK(defData->callbacks->FillStartCbk, defrFillStartCbkType, ROUND((yyvsp[-1].dval))); }
#line 10185 "def.tab.c"
    break;

  case 918:
#line 5030 "def.y"
      { if (defData->callbacks->FillEndCbk)
          CALLBACK(defData->callbacks->FillEndCbk, defrFillEndCbkType, 0); }
#line 10192 "def.tab.c"
    break;

  case 921:
#line 5038 "def.y"
      {
        if (defData->callbacks->FillCbk) {
          CALLBACK(defData->callbacks->FillCbk, defrFillCbkType, &defData->Fill);
          defData->Fill.clear();
        }
      }
#line 10203 "def.tab.c"
    break;

  case 922:
#line 5044 "def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10209 "def.tab.c"
    break;

  case 923:
#line 5045 "def.y"
      {
        if (defData->callbacks->FillCbk) {
          defData->Fill.setVia((yyvsp[0].string));
          defData->Fill.clearPts();
          defData->Geometries.Reset();
        }
      }
#line 10221 "def.tab.c"
    break;

  case 925:
#line 5054 "def.y"
                       { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10227 "def.tab.c"
    break;

  case 926:
#line 5055 "def.y"
      {
        if (defData->callbacks->FillCbk) {
          defData->Fill.setLayer((yyvsp[0].string));
          defData->Fill.clearPoly();    // free poly, if any
        }
      }
#line 10238 "def.tab.c"
    break;

  case 930:
#line 5068 "def.y"
      {
        if (defData->callbacks->FillCbk)
          defData->Fill.addRect((yyvsp[-1].pt).x, (yyvsp[-1].pt).y, (yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
#line 10247 "def.tab.c"
    break;

  case 931:
#line 5073 "def.y"
      {
        defData->Geometries.Reset();
      }
#line 10255 "def.tab.c"
    break;

  case 932:
#line 5077 "def.y"
      {
        if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond
          if (defData->callbacks->FillCbk)
            defData->Fill.addPolygon(&defData->Geometries);
        } else {
            defData->defMsg = (char*)malloc(10000);
            sprintf (defData->defMsg,
              "POLYGON statement in FILLS LAYER is a version 5.6 and later syntax.\nYour def file is defined with version %g.", defData->VersionNum);
            defData->defError(6564, defData->defMsg);
            free(defData->defMsg);
            CHKERR();
        }
      }
#line 10273 "def.tab.c"
    break;

  case 937:
#line 5101 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->FillCbk) {
             if (defData->fillWarnings++ < defData->settings->FillWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The LAYER OPC is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6553, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else {
           if (defData->callbacks->FillCbk)
             defData->Fill.setLayerOpc();
        }
      }
#line 10295 "def.tab.c"
    break;

  case 938:
#line 5120 "def.y"
    {
        if (defData->callbacks->FillCbk) {
          defData->Fill.addPts(&defData->Geometries);
          CALLBACK(defData->callbacks->FillCbk, defrFillCbkType, &defData->Fill);
          defData->Fill.clear();
        }
    }
#line 10307 "def.tab.c"
    break;

  case 943:
#line 5139 "def.y"
      {
        if (defData->VersionNum < 5.7) {
           if (defData->callbacks->FillCbk) {
             if (defData->fillWarnings++ < defData->settings->FillWarnings) {
               defData->defMsg = (char*)malloc(10000);
               sprintf (defData->defMsg,
                 "The VIA OPC is available in version 5.7 or later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
               defData->defError(6554, defData->defMsg);
               free(defData->defMsg);
               CHKERR();
             }
           }
        } else {
           if (defData->callbacks->FillCbk)
             defData->Fill.setViaOpc();
        }
      }
#line 10329 "def.tab.c"
    break;

  case 944:
#line 5159 "def.y"
      { 
        if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->fillWarnings, defData->settings->FillWarnings)) {
             if (defData->callbacks->FillCbk) {
                defData->Fill.setMask((int)(yyvsp[0].dval));
             }
        }
      }
#line 10341 "def.tab.c"
    break;

  case 945:
#line 5169 "def.y"
      { 
        if (defData->validateMaskInput((int)(yyvsp[0].dval), defData->fillWarnings, defData->settings->FillWarnings)) {
             if (defData->callbacks->FillCbk) {
                defData->Fill.setMask((int)(yyvsp[0].dval));
             }
        }
      }
#line 10353 "def.tab.c"
    break;

  case 947:
#line 5182 "def.y"
      { 
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->NonDefaultStartCbk) {
            if (defData->nonDefaultWarnings++ < defData->settings->NonDefaultWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The NONDEFAULTRULE statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g.", defData->VersionNum);
              defData->defError(6545, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else if (defData->callbacks->NonDefaultStartCbk)
          CALLBACK(defData->callbacks->NonDefaultStartCbk, defrNonDefaultStartCbkType,
                   ROUND((yyvsp[-1].dval)));
      }
#line 10374 "def.tab.c"
    break;

  case 948:
#line 5200 "def.y"
      { if (defData->callbacks->NonDefaultEndCbk)
          CALLBACK(defData->callbacks->NonDefaultEndCbk, defrNonDefaultEndCbkType, 0); }
#line 10381 "def.tab.c"
    break;

  case 951:
#line 5207 "def.y"
                    { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10387 "def.tab.c"
    break;

  case 952:
#line 5208 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.clear(); 
          defData->NonDefault.setName((yyvsp[0].string));
        }
      }
#line 10398 "def.tab.c"
    break;

  case 953:
#line 5215 "def.y"
      { if (defData->callbacks->NonDefaultCbk)
          CALLBACK(defData->callbacks->NonDefaultCbk, defrNonDefaultCbkType, &defData->NonDefault); }
#line 10405 "def.tab.c"
    break;

  case 956:
#line 5223 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk)
          defData->NonDefault.setHardspacing();
      }
#line 10414 "def.tab.c"
    break;

  case 957:
#line 5227 "def.y"
                    { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10420 "def.tab.c"
    break;

  case 958:
#line 5229 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addLayer((yyvsp[-2].string));
          defData->NonDefault.addWidth((yyvsp[0].dval));
        }
      }
#line 10431 "def.tab.c"
    break;

  case 960:
#line 5236 "def.y"
                  { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10437 "def.tab.c"
    break;

  case 961:
#line 5237 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addVia((yyvsp[0].string));
        }
      }
#line 10447 "def.tab.c"
    break;

  case 962:
#line 5242 "def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10453 "def.tab.c"
    break;

  case 963:
#line 5243 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addViaRule((yyvsp[0].string));
        }
      }
#line 10463 "def.tab.c"
    break;

  case 964:
#line 5248 "def.y"
                      { defData->dumb_mode = 1; defData->no_num = 1; }
#line 10469 "def.tab.c"
    break;

  case 965:
#line 5249 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addMinCuts((yyvsp[-1].string), (int)(yyvsp[0].dval));
        }
      }
#line 10479 "def.tab.c"
    break;

  case 969:
#line 5262 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addDiagWidth((yyvsp[0].dval));
        }
      }
#line 10489 "def.tab.c"
    break;

  case 970:
#line 5268 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addSpacing((yyvsp[0].dval));
        }
      }
#line 10499 "def.tab.c"
    break;

  case 971:
#line 5274 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          defData->NonDefault.addWireExt((yyvsp[0].dval));
        }
      }
#line 10509 "def.tab.c"
    break;

  case 972:
#line 5281 "def.y"
                                    { defData->dumb_mode = DEF_MAX_INT;  }
#line 10515 "def.tab.c"
    break;

  case 973:
#line 5283 "def.y"
      { defData->dumb_mode = 0; }
#line 10521 "def.tab.c"
    break;

  case 976:
#line 5290 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          char propTp;
          char* str = defData->ringCopy("                       ");
          propTp = defData->session->NDefProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "NONDEFAULTRULE");
          sprintf(str, "%g", (yyvsp[0].dval));
          defData->NonDefault.addNumProperty((yyvsp[-1].string), (yyvsp[0].dval), str, propTp);
        }
      }
#line 10536 "def.tab.c"
    break;

  case 977:
#line 5301 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          char propTp;
          propTp = defData->session->NDefProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "NONDEFAULTRULE");
          defData->NonDefault.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 10549 "def.tab.c"
    break;

  case 978:
#line 5310 "def.y"
      {
        if (defData->callbacks->NonDefaultCbk) {
          char propTp;
          propTp = defData->session->NDefProp.propType((yyvsp[-1].string));
          CHKPROPTYPE(propTp, (yyvsp[-1].string), "NONDEFAULTRULE");
          defData->NonDefault.addProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
        }
      }
#line 10562 "def.tab.c"
    break;

  case 980:
#line 5323 "def.y"
      {
        if (defData->VersionNum < 5.6) {
          if (defData->callbacks->StylesStartCbk) {
            if (defData->stylesWarnings++ < defData->settings->StylesWarnings) {
              defData->defMsg = (char*)malloc(1000);
              sprintf (defData->defMsg,
                 "The STYLES statement is available in version 5.6 and later.\nHowever, your DEF file is defined with version %g", defData->VersionNum);
              defData->defError(6546, defData->defMsg);
              free(defData->defMsg);
              CHKERR();
            }
          }
        } else if (defData->callbacks->StylesStartCbk)
          CALLBACK(defData->callbacks->StylesStartCbk, defrStylesStartCbkType, ROUND((yyvsp[-1].dval)));
      }
#line 10582 "def.tab.c"
    break;

  case 981:
#line 5340 "def.y"
      { if (defData->callbacks->StylesEndCbk)
          CALLBACK(defData->callbacks->StylesEndCbk, defrStylesEndCbkType, 0); }
#line 10589 "def.tab.c"
    break;

  case 984:
#line 5348 "def.y"
      {
        if (defData->callbacks->StylesCbk) defData->Styles.setStyle((int)(yyvsp[0].dval));
        defData->Geometries.Reset();
      }
#line 10598 "def.tab.c"
    break;

  case 985:
#line 5353 "def.y"
      {
        if (defData->VersionNum >= 5.6) {  // only 5.6 and beyond will call the callback
          if (defData->callbacks->StylesCbk) {
            defData->Styles.setPolygon(&defData->Geometries);
            CALLBACK(defData->callbacks->StylesCbk, defrStylesCbkType, &defData->Styles);
          }
        }
      }
#line 10611 "def.tab.c"
    break;


#line 10615 "def.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (defData, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (defData, yymsgp);
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
                      yytoken, &yylval, defData);
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
                  yystos[yystate], yyvsp, defData);
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
  yyerror (defData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, defData);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, defData);
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
#line 5363 "def.y"


END_LEFDEF_PARSER_NAMESPACE
