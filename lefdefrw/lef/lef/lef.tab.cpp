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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         lefyyparse
#define yylex           lefyylex
#define yyerror         lefyyerror
#define yydebug         lefyydebug
#define yynerrs         lefyynerrs
#define yylval          lefyylval
#define yychar          lefyychar

/* First part of user prologue.  */
#line 52 "lef.y"

#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "lex.h"
#include "lefiDefs.hpp"
#include "lefiUser.hpp"
#include "lefiUtil.hpp"

#include "lefrData.hpp"
#include "lefrCallBacks.hpp"
#include "lefrSettings.hpp"

BEGIN_LEFDEF_PARSER_NAMESPACE

#define LYPROP_ECAP "EDGE_CAPACITANCE"

#define YYINITDEPTH 10000  // pcr 640902 - initialize the yystacksize to 300 
                           // this may need to increase in a design gets 
                           // larger and a polygon has around 300 sizes 
                           // 11/21/2003 - incrreased to 500, design from 
                           // Artisan is greater than 300, need to find a 
                           // way to dynamically increase the size 
                           // 2/10/2004 - increased to 1000 for pcr 686073 
                           // 3/22/2004 - increased to 2000 for pcr 695879 
                           // 9/29/2004 - double the size for pcr 746865 
                           // tried to overwrite the yyoverflow definition 
                           // it is impossible due to the union structure 
                           // 10/03/2006 - increased to 10000 for pcr 913695 

#define YYMAXDEPTH 300000  // 1/24/2008 - increased from 150000 
                           // This value has to be greater than YYINITDEPTH 


// Macro to describe how we handle a callback.
// If the function was set then call it.
// If the function returns non zero then there was an error
// so call the error routine and exit.
#define CALLBACK(func, typ, data) \
    if (!lefData->lef_errors) { \
      if (func) { \
        if ((lefData->lefRetVal = (*func)(typ, data, lefSettings->UserData)) == 0) { \
        } else { \
          return lefData->lefRetVal; \
        } \
      } \
    }

#define CHKERR() \
    if (lefData->lef_errors > 20) { \
      lefError(1020, "Too many syntax errors."); \
      lefData->lef_errors = 0; \
      return 1; \
    }

// **********************************************************************
// **********************************************************************

#define C_EQ 0
#define C_NE 1
#define C_LT 2
#define C_LE 3
#define C_GT 4
#define C_GE 5


int comp_str(char *s1, int op, char *s2)
{
    int k = strcmp(s1, s2);
    switch (op) {
        case C_EQ: return k == 0;
        case C_NE: return k != 0;
        case C_GT: return k >  0;
        case C_GE: return k >= 0;
        case C_LT: return k <  0;
        case C_LE: return k <= 0;
        }
    return 0;
}
int comp_num(double s1, int op, double s2)
{
    double k = s1 - s2;
    switch (op) {
        case C_EQ: return k == 0;
        case C_NE: return k != 0;
        case C_GT: return k >  0;
        case C_GE: return k >= 0;
        case C_LT: return k <  0;
        case C_LE: return k <= 0;
        }
    return 0;
}

int validNum(int values) {
    switch (values) {
        case 100:
        case 200:
        case 1000:
        case 2000:
             return 1;
        case 400:
        case 800:
        case 4000:
        case 8000:
        case 10000:
        case 20000:
             if (lefData->versionNum < 5.6) {
                if (lefCallbacks->UnitsCbk) {
                  if (lefData->unitsWarnings++ < lefSettings->UnitsWarnings) {
                    lefData->outMsg = (char*)lefMalloc(10000);
                    sprintf (lefData->outMsg,
                       "Error found when processing LEF file '%s'\nUnit %d is a version 5.6 or later syntax\nYour lef file is defined with version %g.",
                    lefData->lefrFileName, values, lefData->versionNum);
                    lefError(1501, lefData->outMsg);
                    lefFree(lefData->outMsg);
                  }
                }
                return 0;
             } else {
                return 1;
             }        
    }
    if (lefData->unitsWarnings++ < lefSettings->UnitsWarnings) {
       lefData->outMsg = (char*)lefMalloc(10000);
       sprintf (lefData->outMsg,
          "The value %d defined for LEF UNITS DATABASE MICRONS is invalid\n. Correct value is 100, 200, 400, 800, 1000, 2000, 4000, 8000, 10000, or 20000", values);
       lefError(1502, lefData->outMsg);
       lefFree(lefData->outMsg);
    }
    CHKERR();
    return 0;
}

int zeroOrGt(double values) {
    if (values < 0)
      return 0;
    return 1;
}


#line 219 "lef.tab.c"

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
#ifndef YY_LEFYY_LEF_TAB_H_INCLUDED
# define YY_LEFYY_LEF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int lefyydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    K_HISTORY = 258,
    K_ABUT = 259,
    K_ABUTMENT = 260,
    K_ACTIVE = 261,
    K_ANALOG = 262,
    K_ARRAY = 263,
    K_AREA = 264,
    K_BLOCK = 265,
    K_BOTTOMLEFT = 266,
    K_BOTTOMRIGHT = 267,
    K_BY = 268,
    K_CAPACITANCE = 269,
    K_CAPMULTIPLIER = 270,
    K_CLASS = 271,
    K_CLOCK = 272,
    K_CLOCKTYPE = 273,
    K_COLUMNMAJOR = 274,
    K_DESIGNRULEWIDTH = 275,
    K_INFLUENCE = 276,
    K_CORE = 277,
    K_CORNER = 278,
    K_COVER = 279,
    K_CPERSQDIST = 280,
    K_CURRENT = 281,
    K_CURRENTSOURCE = 282,
    K_CUT = 283,
    K_DEFAULT = 284,
    K_DATABASE = 285,
    K_DATA = 286,
    K_DIELECTRIC = 287,
    K_DIRECTION = 288,
    K_DO = 289,
    K_EDGECAPACITANCE = 290,
    K_EEQ = 291,
    K_END = 292,
    K_ENDCAP = 293,
    K_FALL = 294,
    K_FALLCS = 295,
    K_FALLT0 = 296,
    K_FALLSATT1 = 297,
    K_FALLRS = 298,
    K_FALLSATCUR = 299,
    K_FALLTHRESH = 300,
    K_FEEDTHRU = 301,
    K_FIXED = 302,
    K_FOREIGN = 303,
    K_FROMPIN = 304,
    K_GENERATE = 305,
    K_GENERATOR = 306,
    K_GROUND = 307,
    K_HEIGHT = 308,
    K_HORIZONTAL = 309,
    K_INOUT = 310,
    K_INPUT = 311,
    K_INPUTNOISEMARGIN = 312,
    K_COMPONENTPIN = 313,
    K_INTRINSIC = 314,
    K_INVERT = 315,
    K_IRDROP = 316,
    K_ITERATE = 317,
    K_IV_TABLES = 318,
    K_LAYER = 319,
    K_LEAKAGE = 320,
    K_LEQ = 321,
    K_LIBRARY = 322,
    K_MACRO = 323,
    K_MATCH = 324,
    K_MAXDELAY = 325,
    K_MAXLOAD = 326,
    K_METALOVERHANG = 327,
    K_MILLIAMPS = 328,
    K_MILLIWATTS = 329,
    K_MINFEATURE = 330,
    K_MUSTJOIN = 331,
    K_NAMESCASESENSITIVE = 332,
    K_NANOSECONDS = 333,
    K_NETS = 334,
    K_NEW = 335,
    K_NONDEFAULTRULE = 336,
    K_NONINVERT = 337,
    K_NONUNATE = 338,
    K_OBS = 339,
    K_OHMS = 340,
    K_OFFSET = 341,
    K_ORIENTATION = 342,
    K_ORIGIN = 343,
    K_OUTPUT = 344,
    K_OUTPUTNOISEMARGIN = 345,
    K_OVERHANG = 346,
    K_OVERLAP = 347,
    K_OFF = 348,
    K_ON = 349,
    K_OVERLAPS = 350,
    K_PAD = 351,
    K_PATH = 352,
    K_PATTERN = 353,
    K_PICOFARADS = 354,
    K_PIN = 355,
    K_PITCH = 356,
    K_PLACED = 357,
    K_POLYGON = 358,
    K_PORT = 359,
    K_POST = 360,
    K_POWER = 361,
    K_PRE = 362,
    K_PULLDOWNRES = 363,
    K_RECT = 364,
    K_RESISTANCE = 365,
    K_RESISTIVE = 366,
    K_RING = 367,
    K_RISE = 368,
    K_RISECS = 369,
    K_RISERS = 370,
    K_RISESATCUR = 371,
    K_RISETHRESH = 372,
    K_RISESATT1 = 373,
    K_RISET0 = 374,
    K_RISEVOLTAGETHRESHOLD = 375,
    K_FALLVOLTAGETHRESHOLD = 376,
    K_ROUTING = 377,
    K_ROWMAJOR = 378,
    K_RPERSQ = 379,
    K_SAMENET = 380,
    K_SCANUSE = 381,
    K_SHAPE = 382,
    K_SHRINKAGE = 383,
    K_SIGNAL = 384,
    K_SITE = 385,
    K_SIZE = 386,
    K_SOURCE = 387,
    K_SPACER = 388,
    K_SPACING = 389,
    K_SPECIALNETS = 390,
    K_STACK = 391,
    K_START = 392,
    K_STEP = 393,
    K_STOP = 394,
    K_STRUCTURE = 395,
    K_SYMMETRY = 396,
    K_TABLE = 397,
    K_THICKNESS = 398,
    K_TIEHIGH = 399,
    K_TIELOW = 400,
    K_TIEOFFR = 401,
    K_TIME = 402,
    K_TIMING = 403,
    K_TO = 404,
    K_TOPIN = 405,
    K_TOPLEFT = 406,
    K_TOPRIGHT = 407,
    K_TOPOFSTACKONLY = 408,
    K_TRISTATE = 409,
    K_TYPE = 410,
    K_UNATENESS = 411,
    K_UNITS = 412,
    K_USE = 413,
    K_VARIABLE = 414,
    K_VERTICAL = 415,
    K_VHI = 416,
    K_VIA = 417,
    K_VIARULE = 418,
    K_VLO = 419,
    K_VOLTAGE = 420,
    K_VOLTS = 421,
    K_WIDTH = 422,
    K_X = 423,
    K_Y = 424,
    T_STRING = 425,
    QSTRING = 426,
    NUMBER = 427,
    K_N = 428,
    K_S = 429,
    K_E = 430,
    K_W = 431,
    K_FN = 432,
    K_FS = 433,
    K_FE = 434,
    K_FW = 435,
    K_R0 = 436,
    K_R90 = 437,
    K_R180 = 438,
    K_R270 = 439,
    K_MX = 440,
    K_MY = 441,
    K_MXR90 = 442,
    K_MYR90 = 443,
    K_USER = 444,
    K_MASTERSLICE = 445,
    K_ENDMACRO = 446,
    K_ENDMACROPIN = 447,
    K_ENDVIARULE = 448,
    K_ENDVIA = 449,
    K_ENDLAYER = 450,
    K_ENDSITE = 451,
    K_CANPLACE = 452,
    K_CANNOTOCCUPY = 453,
    K_TRACKS = 454,
    K_FLOORPLAN = 455,
    K_GCELLGRID = 456,
    K_DEFAULTCAP = 457,
    K_MINPINS = 458,
    K_WIRECAP = 459,
    K_STABLE = 460,
    K_SETUP = 461,
    K_HOLD = 462,
    K_DEFINE = 463,
    K_DEFINES = 464,
    K_DEFINEB = 465,
    K_IF = 466,
    K_THEN = 467,
    K_ELSE = 468,
    K_FALSE = 469,
    K_TRUE = 470,
    K_EQ = 471,
    K_NE = 472,
    K_LE = 473,
    K_LT = 474,
    K_GE = 475,
    K_GT = 476,
    K_OR = 477,
    K_AND = 478,
    K_NOT = 479,
    K_DELAY = 480,
    K_TABLEDIMENSION = 481,
    K_TABLEAXIS = 482,
    K_TABLEENTRIES = 483,
    K_TRANSITIONTIME = 484,
    K_EXTENSION = 485,
    K_PROPDEF = 486,
    K_STRING = 487,
    K_INTEGER = 488,
    K_REAL = 489,
    K_RANGE = 490,
    K_PROPERTY = 491,
    K_VIRTUAL = 492,
    K_BUSBITCHARS = 493,
    K_VERSION = 494,
    K_BEGINEXT = 495,
    K_ENDEXT = 496,
    K_UNIVERSALNOISEMARGIN = 497,
    K_EDGERATETHRESHOLD1 = 498,
    K_CORRECTIONTABLE = 499,
    K_EDGERATESCALEFACTOR = 500,
    K_EDGERATETHRESHOLD2 = 501,
    K_VICTIMNOISE = 502,
    K_NOISETABLE = 503,
    K_EDGERATE = 504,
    K_OUTPUTRESISTANCE = 505,
    K_VICTIMLENGTH = 506,
    K_CORRECTIONFACTOR = 507,
    K_OUTPUTPINANTENNASIZE = 508,
    K_INPUTPINANTENNASIZE = 509,
    K_INOUTPINANTENNASIZE = 510,
    K_CURRENTDEN = 511,
    K_PWL = 512,
    K_ANTENNALENGTHFACTOR = 513,
    K_TAPERRULE = 514,
    K_DIVIDERCHAR = 515,
    K_ANTENNASIZE = 516,
    K_ANTENNAMETALLENGTH = 517,
    K_ANTENNAMETALAREA = 518,
    K_RISESLEWLIMIT = 519,
    K_FALLSLEWLIMIT = 520,
    K_FUNCTION = 521,
    K_BUFFER = 522,
    K_INVERTER = 523,
    K_NAMEMAPSTRING = 524,
    K_NOWIREEXTENSIONATPIN = 525,
    K_WIREEXTENSION = 526,
    K_MESSAGE = 527,
    K_CREATEFILE = 528,
    K_OPENFILE = 529,
    K_CLOSEFILE = 530,
    K_WARNING = 531,
    K_ERROR = 532,
    K_FATALERROR = 533,
    K_RECOVERY = 534,
    K_SKEW = 535,
    K_ANYEDGE = 536,
    K_POSEDGE = 537,
    K_NEGEDGE = 538,
    K_SDFCONDSTART = 539,
    K_SDFCONDEND = 540,
    K_SDFCOND = 541,
    K_MPWH = 542,
    K_MPWL = 543,
    K_PERIOD = 544,
    K_ACCURRENTDENSITY = 545,
    K_DCCURRENTDENSITY = 546,
    K_AVERAGE = 547,
    K_PEAK = 548,
    K_RMS = 549,
    K_FREQUENCY = 550,
    K_CUTAREA = 551,
    K_MEGAHERTZ = 552,
    K_USELENGTHTHRESHOLD = 553,
    K_LENGTHTHRESHOLD = 554,
    K_ANTENNAINPUTGATEAREA = 555,
    K_ANTENNAINOUTDIFFAREA = 556,
    K_ANTENNAOUTPUTDIFFAREA = 557,
    K_ANTENNAAREARATIO = 558,
    K_ANTENNADIFFAREARATIO = 559,
    K_ANTENNACUMAREARATIO = 560,
    K_ANTENNACUMDIFFAREARATIO = 561,
    K_ANTENNAAREAFACTOR = 562,
    K_ANTENNASIDEAREARATIO = 563,
    K_ANTENNADIFFSIDEAREARATIO = 564,
    K_ANTENNACUMSIDEAREARATIO = 565,
    K_ANTENNACUMDIFFSIDEAREARATIO = 566,
    K_ANTENNASIDEAREAFACTOR = 567,
    K_DIFFUSEONLY = 568,
    K_MANUFACTURINGGRID = 569,
    K_FIXEDMASK = 570,
    K_ANTENNACELL = 571,
    K_CLEARANCEMEASURE = 572,
    K_EUCLIDEAN = 573,
    K_MAXXY = 574,
    K_USEMINSPACING = 575,
    K_ROWMINSPACING = 576,
    K_ROWABUTSPACING = 577,
    K_FLIP = 578,
    K_NONE = 579,
    K_ANTENNAPARTIALMETALAREA = 580,
    K_ANTENNAPARTIALMETALSIDEAREA = 581,
    K_ANTENNAGATEAREA = 582,
    K_ANTENNADIFFAREA = 583,
    K_ANTENNAMAXAREACAR = 584,
    K_ANTENNAMAXSIDEAREACAR = 585,
    K_ANTENNAPARTIALCUTAREA = 586,
    K_ANTENNAMAXCUTCAR = 587,
    K_SLOTWIREWIDTH = 588,
    K_SLOTWIRELENGTH = 589,
    K_SLOTWIDTH = 590,
    K_SLOTLENGTH = 591,
    K_MAXADJACENTSLOTSPACING = 592,
    K_MAXCOAXIALSLOTSPACING = 593,
    K_MAXEDGESLOTSPACING = 594,
    K_SPLITWIREWIDTH = 595,
    K_MINIMUMDENSITY = 596,
    K_MAXIMUMDENSITY = 597,
    K_DENSITYCHECKWINDOW = 598,
    K_DENSITYCHECKSTEP = 599,
    K_FILLACTIVESPACING = 600,
    K_MINIMUMCUT = 601,
    K_ADJACENTCUTS = 602,
    K_ANTENNAMODEL = 603,
    K_BUMP = 604,
    K_ENCLOSURE = 605,
    K_FROMABOVE = 606,
    K_FROMBELOW = 607,
    K_IMPLANT = 608,
    K_LENGTH = 609,
    K_MAXVIASTACK = 610,
    K_AREAIO = 611,
    K_BLACKBOX = 612,
    K_MAXWIDTH = 613,
    K_MINENCLOSEDAREA = 614,
    K_MINSTEP = 615,
    K_ORIENT = 616,
    K_OXIDE1 = 617,
    K_OXIDE2 = 618,
    K_OXIDE3 = 619,
    K_OXIDE4 = 620,
    K_OXIDE5 = 621,
    K_OXIDE6 = 622,
    K_OXIDE7 = 623,
    K_OXIDE8 = 624,
    K_OXIDE9 = 625,
    K_OXIDE10 = 626,
    K_OXIDE11 = 627,
    K_OXIDE12 = 628,
    K_OXIDE13 = 629,
    K_OXIDE14 = 630,
    K_OXIDE15 = 631,
    K_OXIDE16 = 632,
    K_OXIDE17 = 633,
    K_OXIDE18 = 634,
    K_OXIDE19 = 635,
    K_OXIDE20 = 636,
    K_OXIDE21 = 637,
    K_OXIDE22 = 638,
    K_OXIDE23 = 639,
    K_OXIDE24 = 640,
    K_OXIDE25 = 641,
    K_OXIDE26 = 642,
    K_OXIDE27 = 643,
    K_OXIDE28 = 644,
    K_OXIDE29 = 645,
    K_OXIDE30 = 646,
    K_OXIDE31 = 647,
    K_OXIDE32 = 648,
    K_PARALLELRUNLENGTH = 649,
    K_MINWIDTH = 650,
    K_PROTRUSIONWIDTH = 651,
    K_SPACINGTABLE = 652,
    K_WITHIN = 653,
    K_ABOVE = 654,
    K_BELOW = 655,
    K_CENTERTOCENTER = 656,
    K_CUTSIZE = 657,
    K_CUTSPACING = 658,
    K_DENSITY = 659,
    K_DIAG45 = 660,
    K_DIAG135 = 661,
    K_MASK = 662,
    K_DIAGMINEDGELENGTH = 663,
    K_DIAGSPACING = 664,
    K_DIAGPITCH = 665,
    K_DIAGWIDTH = 666,
    K_GENERATED = 667,
    K_GROUNDSENSITIVITY = 668,
    K_HARDSPACING = 669,
    K_INSIDECORNER = 670,
    K_LAYERS = 671,
    K_LENGTHSUM = 672,
    K_MICRONS = 673,
    K_MINCUTS = 674,
    K_MINSIZE = 675,
    K_NETEXPR = 676,
    K_OUTSIDECORNER = 677,
    K_PREFERENCLOSURE = 678,
    K_ROWCOL = 679,
    K_ROWPATTERN = 680,
    K_SOFT = 681,
    K_SUPPLYSENSITIVITY = 682,
    K_USEVIA = 683,
    K_USEVIARULE = 684,
    K_WELLTAP = 685,
    K_ARRAYCUTS = 686,
    K_ARRAYSPACING = 687,
    K_ANTENNAAREADIFFREDUCEPWL = 688,
    K_ANTENNAAREAMINUSDIFF = 689,
    K_ANTENNACUMROUTINGPLUSCUT = 690,
    K_ANTENNAGATEPLUSDIFF = 691,
    K_ENDOFLINE = 692,
    K_ENDOFNOTCHWIDTH = 693,
    K_EXCEPTEXTRACUT = 694,
    K_EXCEPTSAMEPGNET = 695,
    K_EXCEPTPGNET = 696,
    K_LONGARRAY = 697,
    K_MAXEDGES = 698,
    K_NOTCHLENGTH = 699,
    K_NOTCHSPACING = 700,
    K_ORTHOGONAL = 701,
    K_PARALLELEDGE = 702,
    K_PARALLELOVERLAP = 703,
    K_PGONLY = 704,
    K_PRL = 705,
    K_TWOEDGES = 706,
    K_TWOWIDTHS = 707,
    IF = 708,
    LNOT = 709,
    UMINUS = 710
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 194 "lef.y"

        double    dval ;
        int       integer ;
        char *    string ;
        LefDefParser::lefPOINT  pt;

#line 734 "lef.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE lefyylval;

int lefyyparse (void);

#endif /* !YY_LEFYY_LEF_TAB_H_INCLUDED  */



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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2723

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  467
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  449
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1076
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2100

#define YYUNDEFTOK  2
#define YYMAXUTOK   710


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     464,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     461,   462,   457,   456,     2,   455,     2,   458,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   460,
     465,   463,   466,     2,     2,     2,     2,     2,     2,     2,
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
     459
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   342,   342,   363,   363,   402,   419,   432,   445,   446,
     447,   451,   457,   467,   467,   467,   467,   468,   468,   468,
     468,   468,   469,   469,   470,   470,   470,   470,   470,   470,
     470,   471,   471,   471,   472,   472,   473,   473,   474,   474,
     474,   475,   475,   476,   476,   476,   476,   476,   477,   477,
     477,   478,   481,   495,   513,   523,   534,   547,   554,   569,
     573,   574,   577,   578,   581,   582,   584,   590,   613,   614,
     617,   619,   621,   623,   625,   627,   629,   636,   639,   646,
     646,   678,   678,   736,   737,   742,   748,   741,   765,   771,
     786,   791,   796,   800,   804,   808,   812,   816,   820,   825,
     842,   841,   878,   877,   895,   909,   921,   932,   944,   955,
     967,   979,   991,  1003,  1015,  1028,  1055,  1074,  1092,  1111,
    1111,  1116,  1115,  1130,  1145,  1161,  1184,  1160,  1187,  1210,
    1186,  1214,  1253,  1252,  1291,  1330,  1329,  1369,  1368,  1383,
    1422,  1421,  1460,  1499,  1498,  1538,  1537,  1578,  1577,  1616,
    1637,  1658,  1680,  1701,  1679,  1717,  1741,  1765,  1789,  1813,
    1837,  1861,  1885,  1908,  1926,  1944,  1962,  1980,  1998,  2023,
    2049,  2048,  2066,  2065,  2081,  2080,  2087,  2104,  2103,  2130,
    2129,  2149,  2148,  2166,  2184,  2210,  2209,  2227,  2229,  2235,
    2237,  2243,  2245,  2248,  2265,  2286,  2291,  2297,  2264,  2311,
    2315,  2310,  2339,  2338,  2363,  2365,  2368,  2375,  2376,  2377,
    2379,  2381,  2380,  2387,  2403,  2404,  2420,  2421,  2428,  2429,
    2445,  2446,  2465,  2484,  2485,  2503,  2504,  2507,  2511,  2515,
    2529,  2530,  2531,  2534,  2538,  2537,  2557,  2558,  2562,  2567,
    2568,  2602,  2603,  2604,  2608,  2610,  2613,  2607,  2617,  2619,
    2618,  2633,  2632,  2649,  2648,  2653,  2654,  2657,  2658,  2662,
    2663,  2667,  2675,  2683,  2695,  2697,  2700,  2704,  2705,  2708,
    2712,  2713,  2716,  2720,  2721,  2722,  2723,  2724,  2725,  2728,
    2729,  2730,  2731,  2733,  2734,  2741,  2746,  2751,  2756,  2761,
    2766,  2771,  2776,  2781,  2786,  2791,  2796,  2801,  2806,  2811,
    2816,  2821,  2826,  2831,  2836,  2841,  2846,  2851,  2856,  2861,
    2866,  2871,  2876,  2881,  2886,  2891,  2896,  2903,  2904,  2908,
    2907,  2917,  2918,  2922,  2921,  2932,  2936,  2943,  2944,  2947,
    2950,  2986,  2986,  3013,  3013,  3023,  3026,  3035,  3043,  3052,
    3054,  3057,  3052,  3078,  3079,  3082,  3086,  3090,  3094,  3094,
    3100,  3101,  3103,  3106,  3107,  3111,  3113,  3115,  3117,  3117,
    3120,  3131,  3132,  3136,  3146,  3154,  3164,  3173,  3182,  3191,
    3201,  3201,  3205,  3206,  3207,  3208,  3209,  3210,  3211,  3212,
    3213,  3214,  3215,  3216,  3217,  3218,  3219,  3220,  3222,  3225,
    3225,  3232,  3234,  3238,  3252,  3251,  3275,  3275,  3309,  3309,
    3319,  3338,  3337,  3365,  3366,  3384,  3385,  3388,  3390,  3394,
    3395,  3398,  3398,  3403,  3404,  3408,  3416,  3424,  3435,  3466,
    3468,  3471,  3474,  3474,  3480,  3482,  3486,  3505,  3524,  3560,
    3562,  3565,  3567,  3569,  3599,  3627,  3627,  3661,  3664,  3686,
    3699,  3701,  3704,  3718,  3733,  3739,  3740,  3743,  3746,  3757,
    3766,  3768,  3771,  3779,  3781,  3784,  3787,  3790,  3804,  3815,
    3816,  3826,  3815,  3856,  3861,  3882,  3884,  3903,  3904,  3908,
    3909,  3910,  3911,  3912,  3913,  3914,  3917,  3934,  3953,  3972,
    3972,  3977,  3978,  3982,  3990,  3998,  4009,  4010,  4019,  4023,
    4009,  4065,  4067,  4071,  4076,  4079,  4103,  4126,  4149,  4168,
    4174,  4174,  4184,  4184,  4215,  4217,  4221,  4227,  4229,  4234,
    4238,  4239,  4240,  4242,  4245,  4247,  4251,  4253,  4255,  4258,
    4258,  4262,  4264,  4267,  4267,  4271,  4273,  4277,  4276,  4284,
    4284,  4302,  4302,  4324,  4326,  4330,  4331,  4332,  4333,  4334,
    4335,  4337,  4339,  4341,  4343,  4344,  4345,  4347,  4349,  4351,
    4353,  4355,  4357,  4359,  4361,  4363,  4363,  4368,  4369,  4372,
    4383,  4385,  4389,  4391,  4393,  4397,  4407,  4415,  4424,  4432,
    4433,  4452,  4453,  4454,  4473,  4492,  4493,  4506,  4507,  4508,
    4531,  4532,  4538,  4541,  4546,  4547,  4548,  4549,  4550,  4551,
    4554,  4555,  4556,  4557,  4574,  4591,  4610,  4611,  4612,  4613,
    4614,  4615,  4617,  4620,  4624,  4633,  4642,  4652,  4662,  4702,
    4713,  4724,  4735,  4748,  4758,  4758,  4761,  4761,  4772,  4783,
    4799,  4803,  4806,  4822,  4829,  4829,  4835,  4835,  4857,  4858,
    4862,  4871,  4880,  4889,  4898,  4907,  4916,  4916,  4925,  4934,
    4936,  4938,  4940,  4949,  4958,  4967,  4976,  4985,  4994,  5003,
    5012,  5014,  5014,  5016,  5016,  5025,  5025,  5034,  5034,  5043,
    5052,  5054,  5056,  5065,  5074,  5083,  5092,  5101,  5110,  5119,
    5121,  5121,  5124,  5138,  5150,  5171,  5192,  5213,  5215,  5217,
    5247,  5277,  5307,  5337,  5367,  5397,  5427,  5458,  5457,  5487,
    5487,  5503,  5503,  5519,  5519,  5537,  5542,  5547,  5552,  5557,
    5562,  5567,  5572,  5577,  5582,  5587,  5592,  5597,  5602,  5607,
    5612,  5617,  5622,  5627,  5632,  5637,  5642,  5647,  5652,  5657,
    5662,  5667,  5672,  5677,  5682,  5687,  5692,  5699,  5700,  5704,
    5714,  5722,  5732,  5733,  5734,  5735,  5736,  5738,  5750,  5751,
    5756,  5757,  5758,  5759,  5760,  5761,  5764,  5765,  5766,  5767,
    5770,  5771,  5772,  5773,  5775,  5778,  5779,  5778,  5795,  5807,
    5828,  5849,  5869,  5889,  5911,  5932,  5935,  5936,  5938,  5939,
    5954,  5955,  5969,  5984,  5988,  5992,  5994,  5998,  5998,  6011,
    6011,  6026,  6030,  6041,  6054,  6062,  6053,  6065,  6073,  6064,
    6075,  6084,  6094,  6096,  6099,  6102,  6111,  6121,  6132,  6144,
    6156,  6177,  6178,  6181,  6182,  6181,  6188,  6189,  6192,  6198,
    6198,  6201,  6204,  6207,  6221,  6223,  6228,  6227,  6238,  6238,
    6241,  6240,  6244,  6253,  6255,  6257,  6259,  6261,  6263,  6265,
    6267,  6269,  6271,  6273,  6275,  6277,  6279,  6281,  6283,  6285,
    6287,  6291,  6293,  6295,  6299,  6301,  6303,  6305,  6309,  6311,
    6313,  6317,  6319,  6321,  6325,  6327,  6331,  6333,  6336,  6340,
    6342,  6347,  6348,  6350,  6355,  6357,  6361,  6363,  6365,  6369,
    6371,  6375,  6377,  6381,  6380,  6390,  6390,  6400,  6400,  6424,
    6425,  6429,  6429,  6436,  6436,  6443,  6443,  6450,  6450,  6456,
    6459,  6459,  6465,  6471,  6474,  6479,  6480,  6484,  6484,  6491,
    6491,  6501,  6502,  6505,  6509,  6509,  6513,  6513,  6517,  6517,
    6526,  6526,  6535,  6535,  6546,  6547,  6548,  6551,  6552,  6556,
    6557,  6561,  6562,  6563,  6564,  6565,  6566,  6567,  6569,  6572,
    6573,  6574,  6575,  6576,  6577,  6578,  6579,  6580,  6581,  6582,
    6583,  6584,  6586,  6587,  6590,  6596,  6598,  6607,  6611,  6612,
    6613,  6614,  6615,  6616,  6617,  6618,  6619,  6623,  6622,  6635,
    6636,  6640,  6640,  6649,  6649,  6658,  6658,  6668,  6668,  6677,
    6677,  6686,  6686,  6695,  6695,  6704,  6704,  6715,  6720,  6725,
    6730,  6735,  6743,  6744,  6749,  6756,  6763,  6771,  6773,  6772,
    6781,  6782,  6790,  6791,  6799,  6800,  6805,  6806,  6811,  6812,
    6815,  6817,  6819,  6844,  6843,  6868,  6892,  6894,  6895,  6894,
    6911,  6910,  6935,  6959,  6958,  6964,  6970,  6978,  6977,  6993,
    7007,  7024,  7025,  7033,  7034,  7051,  7052,  7052,  7057,  7057,
    7061,  7075,  7088,  7101,  7115,  7114,  7120,  7133,  7134,  7138,
    7145,  7149,  7148,  7154,  7157,  7162,  7163,  7167,  7166,  7173,
    7176,  7181,  7180,  7187,  7200,  7201,  7205,  7212,  7216,  7215,
    7222,  7225,  7230,  7231,  7236,  7235,  7242,  7245,  7251,  7275,
    7299,  7323,  7357,  7391,  7425,  7426,  7428
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_HISTORY", "K_ABUT", "K_ABUTMENT",
  "K_ACTIVE", "K_ANALOG", "K_ARRAY", "K_AREA", "K_BLOCK", "K_BOTTOMLEFT",
  "K_BOTTOMRIGHT", "K_BY", "K_CAPACITANCE", "K_CAPMULTIPLIER", "K_CLASS",
  "K_CLOCK", "K_CLOCKTYPE", "K_COLUMNMAJOR", "K_DESIGNRULEWIDTH",
  "K_INFLUENCE", "K_CORE", "K_CORNER", "K_COVER", "K_CPERSQDIST",
  "K_CURRENT", "K_CURRENTSOURCE", "K_CUT", "K_DEFAULT", "K_DATABASE",
  "K_DATA", "K_DIELECTRIC", "K_DIRECTION", "K_DO", "K_EDGECAPACITANCE",
  "K_EEQ", "K_END", "K_ENDCAP", "K_FALL", "K_FALLCS", "K_FALLT0",
  "K_FALLSATT1", "K_FALLRS", "K_FALLSATCUR", "K_FALLTHRESH", "K_FEEDTHRU",
  "K_FIXED", "K_FOREIGN", "K_FROMPIN", "K_GENERATE", "K_GENERATOR",
  "K_GROUND", "K_HEIGHT", "K_HORIZONTAL", "K_INOUT", "K_INPUT",
  "K_INPUTNOISEMARGIN", "K_COMPONENTPIN", "K_INTRINSIC", "K_INVERT",
  "K_IRDROP", "K_ITERATE", "K_IV_TABLES", "K_LAYER", "K_LEAKAGE", "K_LEQ",
  "K_LIBRARY", "K_MACRO", "K_MATCH", "K_MAXDELAY", "K_MAXLOAD",
  "K_METALOVERHANG", "K_MILLIAMPS", "K_MILLIWATTS", "K_MINFEATURE",
  "K_MUSTJOIN", "K_NAMESCASESENSITIVE", "K_NANOSECONDS", "K_NETS", "K_NEW",
  "K_NONDEFAULTRULE", "K_NONINVERT", "K_NONUNATE", "K_OBS", "K_OHMS",
  "K_OFFSET", "K_ORIENTATION", "K_ORIGIN", "K_OUTPUT",
  "K_OUTPUTNOISEMARGIN", "K_OVERHANG", "K_OVERLAP", "K_OFF", "K_ON",
  "K_OVERLAPS", "K_PAD", "K_PATH", "K_PATTERN", "K_PICOFARADS", "K_PIN",
  "K_PITCH", "K_PLACED", "K_POLYGON", "K_PORT", "K_POST", "K_POWER",
  "K_PRE", "K_PULLDOWNRES", "K_RECT", "K_RESISTANCE", "K_RESISTIVE",
  "K_RING", "K_RISE", "K_RISECS", "K_RISERS", "K_RISESATCUR",
  "K_RISETHRESH", "K_RISESATT1", "K_RISET0", "K_RISEVOLTAGETHRESHOLD",
  "K_FALLVOLTAGETHRESHOLD", "K_ROUTING", "K_ROWMAJOR", "K_RPERSQ",
  "K_SAMENET", "K_SCANUSE", "K_SHAPE", "K_SHRINKAGE", "K_SIGNAL", "K_SITE",
  "K_SIZE", "K_SOURCE", "K_SPACER", "K_SPACING", "K_SPECIALNETS",
  "K_STACK", "K_START", "K_STEP", "K_STOP", "K_STRUCTURE", "K_SYMMETRY",
  "K_TABLE", "K_THICKNESS", "K_TIEHIGH", "K_TIELOW", "K_TIEOFFR", "K_TIME",
  "K_TIMING", "K_TO", "K_TOPIN", "K_TOPLEFT", "K_TOPRIGHT",
  "K_TOPOFSTACKONLY", "K_TRISTATE", "K_TYPE", "K_UNATENESS", "K_UNITS",
  "K_USE", "K_VARIABLE", "K_VERTICAL", "K_VHI", "K_VIA", "K_VIARULE",
  "K_VLO", "K_VOLTAGE", "K_VOLTS", "K_WIDTH", "K_X", "K_Y", "T_STRING",
  "QSTRING", "NUMBER", "K_N", "K_S", "K_E", "K_W", "K_FN", "K_FS", "K_FE",
  "K_FW", "K_R0", "K_R90", "K_R180", "K_R270", "K_MX", "K_MY", "K_MXR90",
  "K_MYR90", "K_USER", "K_MASTERSLICE", "K_ENDMACRO", "K_ENDMACROPIN",
  "K_ENDVIARULE", "K_ENDVIA", "K_ENDLAYER", "K_ENDSITE", "K_CANPLACE",
  "K_CANNOTOCCUPY", "K_TRACKS", "K_FLOORPLAN", "K_GCELLGRID",
  "K_DEFAULTCAP", "K_MINPINS", "K_WIRECAP", "K_STABLE", "K_SETUP",
  "K_HOLD", "K_DEFINE", "K_DEFINES", "K_DEFINEB", "K_IF", "K_THEN",
  "K_ELSE", "K_FALSE", "K_TRUE", "K_EQ", "K_NE", "K_LE", "K_LT", "K_GE",
  "K_GT", "K_OR", "K_AND", "K_NOT", "K_DELAY", "K_TABLEDIMENSION",
  "K_TABLEAXIS", "K_TABLEENTRIES", "K_TRANSITIONTIME", "K_EXTENSION",
  "K_PROPDEF", "K_STRING", "K_INTEGER", "K_REAL", "K_RANGE", "K_PROPERTY",
  "K_VIRTUAL", "K_BUSBITCHARS", "K_VERSION", "K_BEGINEXT", "K_ENDEXT",
  "K_UNIVERSALNOISEMARGIN", "K_EDGERATETHRESHOLD1", "K_CORRECTIONTABLE",
  "K_EDGERATESCALEFACTOR", "K_EDGERATETHRESHOLD2", "K_VICTIMNOISE",
  "K_NOISETABLE", "K_EDGERATE", "K_OUTPUTRESISTANCE", "K_VICTIMLENGTH",
  "K_CORRECTIONFACTOR", "K_OUTPUTPINANTENNASIZE", "K_INPUTPINANTENNASIZE",
  "K_INOUTPINANTENNASIZE", "K_CURRENTDEN", "K_PWL",
  "K_ANTENNALENGTHFACTOR", "K_TAPERRULE", "K_DIVIDERCHAR", "K_ANTENNASIZE",
  "K_ANTENNAMETALLENGTH", "K_ANTENNAMETALAREA", "K_RISESLEWLIMIT",
  "K_FALLSLEWLIMIT", "K_FUNCTION", "K_BUFFER", "K_INVERTER",
  "K_NAMEMAPSTRING", "K_NOWIREEXTENSIONATPIN", "K_WIREEXTENSION",
  "K_MESSAGE", "K_CREATEFILE", "K_OPENFILE", "K_CLOSEFILE", "K_WARNING",
  "K_ERROR", "K_FATALERROR", "K_RECOVERY", "K_SKEW", "K_ANYEDGE",
  "K_POSEDGE", "K_NEGEDGE", "K_SDFCONDSTART", "K_SDFCONDEND", "K_SDFCOND",
  "K_MPWH", "K_MPWL", "K_PERIOD", "K_ACCURRENTDENSITY",
  "K_DCCURRENTDENSITY", "K_AVERAGE", "K_PEAK", "K_RMS", "K_FREQUENCY",
  "K_CUTAREA", "K_MEGAHERTZ", "K_USELENGTHTHRESHOLD", "K_LENGTHTHRESHOLD",
  "K_ANTENNAINPUTGATEAREA", "K_ANTENNAINOUTDIFFAREA",
  "K_ANTENNAOUTPUTDIFFAREA", "K_ANTENNAAREARATIO",
  "K_ANTENNADIFFAREARATIO", "K_ANTENNACUMAREARATIO",
  "K_ANTENNACUMDIFFAREARATIO", "K_ANTENNAAREAFACTOR",
  "K_ANTENNASIDEAREARATIO", "K_ANTENNADIFFSIDEAREARATIO",
  "K_ANTENNACUMSIDEAREARATIO", "K_ANTENNACUMDIFFSIDEAREARATIO",
  "K_ANTENNASIDEAREAFACTOR", "K_DIFFUSEONLY", "K_MANUFACTURINGGRID",
  "K_FIXEDMASK", "K_ANTENNACELL", "K_CLEARANCEMEASURE", "K_EUCLIDEAN",
  "K_MAXXY", "K_USEMINSPACING", "K_ROWMINSPACING", "K_ROWABUTSPACING",
  "K_FLIP", "K_NONE", "K_ANTENNAPARTIALMETALAREA",
  "K_ANTENNAPARTIALMETALSIDEAREA", "K_ANTENNAGATEAREA",
  "K_ANTENNADIFFAREA", "K_ANTENNAMAXAREACAR", "K_ANTENNAMAXSIDEAREACAR",
  "K_ANTENNAPARTIALCUTAREA", "K_ANTENNAMAXCUTCAR", "K_SLOTWIREWIDTH",
  "K_SLOTWIRELENGTH", "K_SLOTWIDTH", "K_SLOTLENGTH",
  "K_MAXADJACENTSLOTSPACING", "K_MAXCOAXIALSLOTSPACING",
  "K_MAXEDGESLOTSPACING", "K_SPLITWIREWIDTH", "K_MINIMUMDENSITY",
  "K_MAXIMUMDENSITY", "K_DENSITYCHECKWINDOW", "K_DENSITYCHECKSTEP",
  "K_FILLACTIVESPACING", "K_MINIMUMCUT", "K_ADJACENTCUTS",
  "K_ANTENNAMODEL", "K_BUMP", "K_ENCLOSURE", "K_FROMABOVE", "K_FROMBELOW",
  "K_IMPLANT", "K_LENGTH", "K_MAXVIASTACK", "K_AREAIO", "K_BLACKBOX",
  "K_MAXWIDTH", "K_MINENCLOSEDAREA", "K_MINSTEP", "K_ORIENT", "K_OXIDE1",
  "K_OXIDE2", "K_OXIDE3", "K_OXIDE4", "K_OXIDE5", "K_OXIDE6", "K_OXIDE7",
  "K_OXIDE8", "K_OXIDE9", "K_OXIDE10", "K_OXIDE11", "K_OXIDE12",
  "K_OXIDE13", "K_OXIDE14", "K_OXIDE15", "K_OXIDE16", "K_OXIDE17",
  "K_OXIDE18", "K_OXIDE19", "K_OXIDE20", "K_OXIDE21", "K_OXIDE22",
  "K_OXIDE23", "K_OXIDE24", "K_OXIDE25", "K_OXIDE26", "K_OXIDE27",
  "K_OXIDE28", "K_OXIDE29", "K_OXIDE30", "K_OXIDE31", "K_OXIDE32",
  "K_PARALLELRUNLENGTH", "K_MINWIDTH", "K_PROTRUSIONWIDTH",
  "K_SPACINGTABLE", "K_WITHIN", "K_ABOVE", "K_BELOW", "K_CENTERTOCENTER",
  "K_CUTSIZE", "K_CUTSPACING", "K_DENSITY", "K_DIAG45", "K_DIAG135",
  "K_MASK", "K_DIAGMINEDGELENGTH", "K_DIAGSPACING", "K_DIAGPITCH",
  "K_DIAGWIDTH", "K_GENERATED", "K_GROUNDSENSITIVITY", "K_HARDSPACING",
  "K_INSIDECORNER", "K_LAYERS", "K_LENGTHSUM", "K_MICRONS", "K_MINCUTS",
  "K_MINSIZE", "K_NETEXPR", "K_OUTSIDECORNER", "K_PREFERENCLOSURE",
  "K_ROWCOL", "K_ROWPATTERN", "K_SOFT", "K_SUPPLYSENSITIVITY", "K_USEVIA",
  "K_USEVIARULE", "K_WELLTAP", "K_ARRAYCUTS", "K_ARRAYSPACING",
  "K_ANTENNAAREADIFFREDUCEPWL", "K_ANTENNAAREAMINUSDIFF",
  "K_ANTENNACUMROUTINGPLUSCUT", "K_ANTENNAGATEPLUSDIFF", "K_ENDOFLINE",
  "K_ENDOFNOTCHWIDTH", "K_EXCEPTEXTRACUT", "K_EXCEPTSAMEPGNET",
  "K_EXCEPTPGNET", "K_LONGARRAY", "K_MAXEDGES", "K_NOTCHLENGTH",
  "K_NOTCHSPACING", "K_ORTHOGONAL", "K_PARALLELEDGE", "K_PARALLELOVERLAP",
  "K_PGONLY", "K_PRL", "K_TWOEDGES", "K_TWOWIDTHS", "IF", "LNOT", "'-'",
  "'+'", "'*'", "'/'", "UMINUS", "';'", "'('", "')'", "'='", "'\\n'",
  "'<'", "'>'", "$accept", "lef_file", "version", "$@1", "int_number",
  "dividerchar", "busbitchars", "rules", "end_library", "rule",
  "case_sensitivity", "wireextension", "fixedmask", "manufacturing",
  "useminspacing", "clearancemeasure", "clearance_type", "spacing_type",
  "spacing_value", "units_section", "start_units", "units_rules",
  "units_rule", "layer_rule", "start_layer", "$@2", "end_layer", "$@3",
  "layer_options", "layer_option", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "layer_arraySpacing_long",
  "layer_arraySpacing_width", "layer_arraySpacing_arraycuts",
  "layer_arraySpacing_arraycut", "sp_options", "$@30", "$@31", "$@32",
  "$@33", "$@34", "$@35", "$@36", "layer_spacingtable_opts",
  "layer_spacingtable_opt", "layer_enclosure_type_opt",
  "layer_enclosure_width_opt", "$@37", "layer_enclosure_width_except_opt",
  "layer_preferenclosure_width_opt", "layer_minimumcut_within",
  "layer_minimumcut_from", "layer_minimumcut_length",
  "layer_minstep_options", "layer_minstep_option", "layer_minstep_type",
  "layer_antenna_pwl", "$@38", "layer_diffusion_ratios",
  "layer_diffusion_ratio", "layer_antenna_duo", "layer_table_type",
  "layer_frequency", "$@39", "$@40", "$@41", "ac_layer_table_opt", "$@42",
  "$@43", "dc_layer_table", "$@44", "int_number_list", "number_list",
  "layer_prop_list", "layer_prop", "current_density_pwl_list",
  "current_density_pwl", "cap_points", "cap_point", "res_points",
  "res_point", "layer_type", "layer_direction", "layer_minen_width",
  "layer_oxide", "layer_sp_parallel_widths", "layer_sp_parallel_width",
  "$@45", "layer_sp_TwoWidths", "layer_sp_TwoWidth", "$@46",
  "layer_sp_TwoWidthsPRL", "layer_sp_influence_widths",
  "layer_sp_influence_width", "maxstack_via", "$@47", "via", "$@48",
  "via_keyword", "start_via", "via_viarule", "$@49", "$@50", "$@51",
  "via_viarule_options", "via_viarule_option", "$@52", "via_option",
  "via_other_options", "via_more_options", "via_other_option", "$@53",
  "via_prop_list", "via_name_value_pair", "via_foreign", "start_foreign",
  "$@54", "orientation", "via_layer_rule", "via_layer", "$@55",
  "via_geometries", "via_geometry", "$@56", "end_via", "$@57",
  "viarule_keyword", "$@58", "viarule", "viarule_generate", "$@59",
  "viarule_generate_default", "viarule_layer_list", "opt_viarule_props",
  "viarule_props", "viarule_prop", "$@60", "viarule_prop_list",
  "viarule_layer", "via_names", "via_name", "viarule_layer_name", "$@61",
  "viarule_layer_options", "viarule_layer_option", "end_viarule", "$@62",
  "spacing_rule", "start_spacing", "end_spacing", "spacings", "spacing",
  "samenet_keyword", "maskColor", "irdrop", "start_irdrop", "end_irdrop",
  "ir_tables", "ir_table", "ir_table_values", "ir_table_value",
  "ir_tablename", "minfeature", "dielectric", "nondefault_rule", "$@63",
  "$@64", "$@65", "end_nd_rule", "nd_hardspacing", "nd_rules", "nd_rule",
  "usevia", "useviarule", "mincuts", "nd_prop", "$@66", "nd_prop_list",
  "nd_layer", "$@67", "$@68", "$@69", "$@70", "nd_layer_stmts",
  "nd_layer_stmt", "site", "start_site", "$@71", "end_site", "$@72",
  "site_options", "site_option", "site_class", "site_symmetry_statement",
  "site_symmetries", "site_symmetry", "site_rowpattern_statement", "$@73",
  "site_rowpatterns", "site_rowpattern", "$@74", "pt", "macro", "$@75",
  "start_macro", "$@76", "end_macro", "$@77", "macro_options",
  "macro_option", "$@78", "macro_prop_list", "macro_symmetry_statement",
  "macro_symmetries", "macro_symmetry", "macro_name_value_pair",
  "macro_class", "class_type", "pad_type", "core_type", "endcap_type",
  "macro_generator", "macro_generate", "macro_source", "macro_power",
  "macro_origin", "macro_foreign", "macro_fixedMask", "macro_eeq", "$@79",
  "macro_leq", "$@80", "macro_site", "macro_site_word", "site_word",
  "macro_size", "macro_pin", "start_macro_pin", "$@81", "end_macro_pin",
  "$@82", "macro_pin_options", "macro_pin_option", "$@83", "$@84", "$@85",
  "$@86", "$@87", "$@88", "$@89", "$@90", "$@91", "$@92",
  "pin_layer_oxide", "pin_prop_list", "pin_name_value_pair",
  "electrical_direction", "start_macro_port", "macro_port_class_option",
  "macro_pin_use", "macro_scan_use", "pin_shape", "geometries", "geometry",
  "$@93", "$@94", "geometry_options", "layer_exceptpgnet", "layer_spacing",
  "firstPt", "nextPt", "otherPts", "via_placement", "$@95", "$@96",
  "stepPattern", "sitePattern", "trackPattern", "$@97", "$@98", "$@99",
  "$@100", "trackLayers", "layer_name", "gcellPattern", "macro_obs",
  "start_macro_obs", "macro_density", "density_layers", "density_layer",
  "$@101", "$@102", "density_layer_rects", "density_layer_rect",
  "macro_clocktype", "$@103", "timing", "start_timing", "end_timing",
  "timing_options", "timing_option", "$@104", "$@105", "$@106",
  "one_pin_trigger", "two_pin_trigger", "from_pin_trigger",
  "to_pin_trigger", "delay_or_transition", "list_of_table_entries",
  "table_entry", "list_of_table_axis_dnumbers", "slew_spec", "risefall",
  "unateness", "list_of_from_strings", "list_of_to_strings", "array",
  "$@107", "start_array", "$@108", "end_array", "$@109", "array_rules",
  "array_rule", "$@110", "$@111", "$@112", "$@113", "$@114",
  "floorplan_start", "floorplan_list", "floorplan_element", "$@115",
  "$@116", "cap_list", "one_cap", "msg_statement", "$@117",
  "create_file_statement", "$@118", "def_statement", "$@119", "$@120",
  "$@121", "dtrm", "then", "else", "expression", "b_expr", "s_expr",
  "relop", "prop_def_section", "$@122", "prop_stmts", "prop_stmt", "$@123",
  "$@124", "$@125", "$@126", "$@127", "$@128", "$@129", "$@130",
  "prop_define", "opt_range_second", "opt_endofline", "$@131",
  "opt_endofline_twoedges", "opt_samenetPGonly", "opt_def_range",
  "opt_def_value", "opt_def_dvalue", "layer_spacing_opts",
  "layer_spacing_opt", "$@132", "layer_spacing_cut_routing", "$@133",
  "$@134", "$@135", "$@136", "$@137", "spacing_cut_layer_opt",
  "opt_adjacentcuts_exceptsame", "opt_layer_name", "$@138",
  "req_layer_name", "$@139", "universalnoisemargin", "edgeratethreshold1",
  "edgeratethreshold2", "edgeratescalefactor", "noisetable", "$@140",
  "end_noisetable", "noise_table_list", "noise_table_entry",
  "output_resistance_entry", "$@141", "num_list", "victim_list", "victim",
  "$@142", "vnoiselist", "correctiontable", "$@143", "end_correctiontable",
  "correction_table_list", "correction_table_item", "output_list", "$@144",
  "numo_list", "corr_victim_list", "corr_victim", "$@145", "corr_list",
  "input_antenna", "output_antenna", "inout_antenna", "antenna_input",
  "antenna_inout", "antenna_output", "extension_opt", "extension", YY_NULLPTR
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
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,    45,    43,    42,    47,   710,
      59,    40,    41,    61,    10,    60,    62
};
# endif

#define YYPACT_NINF (-1586)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-792)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2165, -1586,   141,  2368, -1586, -1586,    -4, -1586, -1586, -1586,
      -4,   515, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,   -18, -1586,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    30,   530, -1586, -1586,     9,   134,   193,
      -4,  -127,   335,   224,    -4, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586,   205, -1586,   110, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586,    26,   217, -1586,    39,   313,
     345,    -4,    45,    59,   352,   355,   362,   374,   378,   381,
   -1586,   108,   407,    -4,   125,   128,   130,   132, -1586,   137,
     152,   166,   169,   202,   204,   500,   504,   216,   220,   226,
     228, -1586, -1586, -1586,   250, -1586, -1586,   566,  -132,   577,
    1178,     4,   436,   447, -1586,   664, -1586, -1586,   165,   122,
      23,   470,   555,   677, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586,   290, -1586, -1586, -1586, -1586, -1586,   298,   342,   367,
    1060, -1586,   391,   424, -1586, -1586, -1586, -1586,   437, -1586,
   -1586, -1586, -1586, -1586, -1586,   442,   445, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586,   440, -1586, -1586,   816,   844,   505,
     765,   852,   842,   850,   764,   634, -1586,   772,   920,    -4,
      16,    -4, -1586,    -4,    -4,    -4,   365,    -4,    -4,    -4,
      40,    -4, -1586,   -58,    -4,    -4,    91,   658,    -4, -1586,
      -4, -1586,    -4,    -4, -1586,    -4, -1586,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4, -1586,   308,    -4,   779,    -4,    -4,    -4,   506,
      -4,    -4,    -4,    -4,    -4, -1586,   308, -1586,   492,    -4,
     494,    -4, -1586, -1586, -1586, -1586, -1586, -1586,    -4, -1586,
   -1586, -1586, -1586,   919, -1586, -1586, -1586,   464, -1586, -1586,
   -1586, -1586,   787, -1586,   -47,    29,   825, -1586, -1586, -1586,
     790,   900,   792, -1586, -1586, -1586,    70, -1586,    -4, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586,    75, -1586, -1586,   793,
     794, -1586, -1586,   -88, -1586,    -4, -1586,    -4,   263, -1586,
   -1586, -1586,   467,   507,   901,   614,   929, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
     798, -1586, -1586, -1586, -1586,   522, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586,   799, -1586,    -4, -1586,   935, -1586,
   -1586, -1586, -1586, -1586,   559,     5,  -117,   -89,   745, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
     519,   525,  -117,  -117, -1586,   810,    -4,    -4,    -4, -1586,
      -4,    -4,    -4,    -4,   809,   524,   -63,   527, -1586, -1586,
   -1586, -1586,   528,   529,   812,   531,   -82,   -45,   171,   536,
     553, -1586,   556, -1586, -1586, -1586, -1586, -1586, -1586,   558,
     564,   815,   565,    -4,   568,   572,   573, -1586, -1586, -1586,
      -4,   -36,   574,   230,   575,   230, -1586,   576,   230,   579,
     230, -1586,   580,   581,   583,   584,   585,   586,   589,   598,
     599,   600,    -4,   601,   602,   823,  1301, -1586, -1586,    -4,
     603, -1586, -1586,   612,   684,   650,     7,   616,   617,   626,
     -35,   627,   -88,    -4,   646,   -88,   629, -1586,   630,   921,
     922,   633,   924,   926, -1586, -1586,   443, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586,    -4,    -4,   638,   641,    83,   664,
     639,   533, -1586,   933,  1067,   -41, -1586, -1586,   119,    -4,
      -4,   -88,    -4,    -4,    -4,    -4, -1586, -1586,   947, -1586,
   -1586,   -30,   645,   660,   662,   953,  1112,  -118, -1586,  -179,
       1, -1586,   777,   560,    11, -1586, -1586, -1586, -1586,   669,
     961,   962,   965,   676,   967,   678,   969,   682,  1130,   685,
     686,   687,   -80,   974,   688,   689, -1586, -1586, -1586, -1586,
     690,   659, -1586, -1586,   -22,   692,  2029, -1586, -1586,   746,
     746,   746,   -19,    -4,  1117, -1586, -1586,  1613,   985,   985,
     578, -1586,   642, -1586,   985, -1586, -1586,   161,   696, -1586,
     -89,     5,     5, -1586,   259, -1586,   -89,  -117,  -281,   -89,
   -1586, -1586,   -89,   -89,   862,   281,   892, -1586,   987,   988,
     989,   991,   992,   993,   994,   995,    -4, -1586,    73, -1586,
   -1586,    -4, -1586,   293, -1586, -1586,  -281,  -281,   996,   707,
     709,   720,   723,   725,   726,   728,   729, -1586,   715,   730,
   -1586, -1586, -1586, -1586, -1586, -1586,   731, -1586,   734,   735,
     737, -1586, -1586,   -72, -1586, -1586, -1586,   550,   -83, -1586,
     740,    -4, -1586, -1586, -1586,   738,   882,    -4,  1023,   742,
   -1586,   743, -1586,   747, -1586,   748,   893, -1586,   749, -1586,
     750,   893, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,   752, -1586, -1586,    -4, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,   754,    -4,
   -1586,  1049, -1586, -1586,    -4,    -4,  1050,    -4,  1051,   759,
   -1586, -1586, -1586, -1586,   760, -1586, -1586, -1586,    -4, -1586,
    1054,   -88, -1586, -1586, -1586,   766, -1586,   767,   588,   -74,
   -1586,  1055, -1586,    -4, -1586, -1586, -1586,   769,   746,   746,
   -1586,   239, -1586, -1586, -1586, -1586,   -41,   770, -1586, -1586,
   -1586,   773,   774,   775,   776,   -88,   778,  1211,  1083,    -4,
      -4, -1586,    -4, -1586, -1586, -1586, -1586, -1586,    -4, -1586,
   -1586, -1586, -1586, -1586,   -62, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
     780,   785,   791, -1586,   796, -1586, -1586, -1586,    -4, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586,   637,   -54, -1586,
   -1586, -1586,  1069,    93, -1586, -1586,   800,  1080, -1586,    -4,
   -1586,    -4,   184,   644, -1586,    -4,    -4, -1586,  1082,    -4,
   -1586,    -4,    -4, -1586, -1586, -1586,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,   456,   509,    -4,  1099,    -4,    -4, -1586,
   -1586,  1084,    -4,    -4,  1065,    -4,    -4,  1081,  1087,  1089,
    1090,  1091,  1094,  1095,  1096, -1586, -1586, -1586, -1586,   -79,
   -1586, -1586, -1586,   112,  1101,    -4,   -21,   -20,   -16,   746,
     -88,   813, -1586,   453,  1121, -1586,    -4,    -4,    -4,    -4,
   -1586, -1586,    -4,    -4,    -4,    -4, -1586,   497,  1066, -1586,
   -1586,    -4,   814,   817, -1586, -1586,  1103,  1105,  1107, -1586,
   -1586, -1586, -1586, -1586,  1056,   449,   225,    -4,   820,   821,
      -4,    -4,   826,    -4,    -4,   827,    67,   833,  1115,  1124,
   -1586, -1586, -1586, -1586,   -15,    66, -1586,   236,     5,     5,
       5,     5, -1586, -1586, -1586,    66,  -110,  -117, -1586,    66,
   -1586,   716,    69,   848, -1586, -1586, -1586, -1586, -1586, -1586,
       5,     5, -1586, -1586, -1586,     5,   -89,   -89,   -89,   -89,
   -1586,  -117,  -117,  -117,   306,   306,   306,   306,   306,   306,
     306,   306,   835,    -4,  1052,  -299, -1586,   841,    -4,  1057,
    -299, -1586, -1586, -1586,   843, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586,   847, -1586, -1586, -1586,   861, -1586, -1586,
   -1586, -1586,    27,   -72, -1586, -1586, -1586, -1586, -1586,    -4,
     415, -1586,   840, -1586,  1137, -1586, -1586, -1586, -1586,   -88,
   -1586, -1586, -1586,   863, -1586, -1586,   864, -1586, -1586, -1586,
   -1586,    -4,   866,   -90,  1162,  1196,    -4, -1586,    -4, -1586,
   -1586,     8, -1586,    -4,   928, -1586, -1586,   930, -1586, -1586,
   -1586, -1586, -1586, -1586,   872, -1586, -1586,   -88,  1067, -1586,
    -115, -1586,  1165, -1586, -1586, -1586, -1586,   876, -1586,    -4,
      -4,   877,   -92, -1586,   878,  1318, -1586, -1586, -1586, -1586,
   -1586, -1586,   879, -1586, -1586, -1586, -1586, -1586,   880, -1586,
   -1586, -1586, -1586,  1318,   881,   883,   884,   886,   889,   890,
    -109,  1182,   896,   899,    -4,  1183,   906,  1197,   909,   910,
    1201,    -4,   912,   913,   914,   915,   916,   917,   918, -1586,
   -1586, -1586, -1586,   923, -1586, -1586, -1586,   927,   932, -1586,
   -1586, -1586, -1586, -1586, -1586,   934,   936,   937,  1209,    -4,
     938,  1316,  1316,  1316,   939,   941,  1316,  1316,  1316,  1316,
    1317,  1317,  1316,  1317,  2170,  1212,  1217,  1219,    12, -1586,
     680,    75, -1586,   453, -1586, -1586,   -88, -1586,   -88,   -88,
     -88,   -88,   -88, -1586, -1586, -1586, -1586,    -4,    -4,    -4,
      -4,  1225,    -4,    -4,    -4,    -4,  1233, -1586, -1586, -1586,
     944,    -4, -1586,   -14,    -4,   421, -1586, -1586,   945,   946,
     948,    -4, -1586, -1586, -1586,   567,    -4, -1586, -1586,  1251,
   -1586, -1586,  1375,  1376, -1586,  1377,  1378, -1586,  1213,    -4,
   -1586, -1586, -1586, -1586,   985,   985, -1586,   699, -1586,  1243,
    1246,  1247, -1586, -1586,  1381, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,  1207,     5, -1586,   446,   446, -1586, -1586,  -117,
   -1586, -1586,   -89, -1586,   282,   282,   282, -1586, -1586,   695,
     279,   964,   964,   964,  1250,  1187,  1187,  1253,   966,   968,
     970,   971,   973,   975,   977,   978, -1586, -1586,    -5, -1586,
   -1586, -1586, -1586,    10, -1586, -1586, -1586,    -4,   452, -1586,
      -4,   457, -1586,   976,  1252, -1586,    -4,    -4,    -4,    -4,
      -4,    -4,   980, -1586,    -4,   981, -1586,   982, -1586, -1586,
   -1586,   -88, -1586, -1586,  1029,   -87, -1586, -1586, -1586, -1586,
      -4, -1586,    -4, -1586, -1586, -1586,    -4,    -4,  1045, -1586,
     997, -1586, -1586, -1586,  1277, -1586,    -4, -1586,    -4, -1586,
     -88,   -88, -1586, -1586, -1586, -1586, -1586,   986,   990, -1586,
     998, -1586, -1586, -1586, -1586, -1586,  1411, -1586, -1586, -1586,
   -1586, -1586, -1586,   999, -1586, -1586, -1586, -1586,    -4,  1000,
   -1586,  1001, -1586, -1586,  1002,    -4, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,   717,
     -52, -1586,    -4, -1586, -1586,  1003,  1004,  1005, -1586, -1586,
    1006,  1007,  1010,  1011, -1586,  1012,  1013,  1014,  1015, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586,  1016,  1017,  1018,  1019, -1586,   824, -1586,  1020,  1047,
    1414,  1068, -1586,    19,   -88,   -88,   -88,  1048, -1586,  1278,
    1070,  1071,  1072,  1073, -1586,   -37,  1074,  1075,  1079,  1085,
   -1586,   -27, -1586,  1245, -1586, -1586,    -4, -1586, -1586, -1586,
   -1586, -1586,    -4, -1586, -1586, -1586,  1227,    -4,   497,    -4,
      -4,    -4,    -4, -1586,  1306,  1088,  1092,  1284, -1586, -1586,
   -1586,   297,    -4,  1097,  1098,  1285, -1586, -1586,  -108,   -13,
     834,    88,   118, -1586,    -4,    -4,  1353, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586,  1206, -1586,  1276, -1586,
      -4,  1100, -1586,    -4,  1102, -1586, -1586, -1586, -1586,  1359,
      -4,  1307,  1143,  1145,  1104, -1586, -1586,  1106, -1586, -1586,
   -1586,    25,    34, -1586,    -4,   569,    -4,    -4,  1109, -1586,
   -1586,  1111, -1586,    -4,    -4,    -4,    -4,    -4,  1116, -1586,
    -107,    -4,   -88,  1120, -1586, -1586, -1586, -1586,  1435,    -4,
   -1586,  1122, -1586, -1586, -1586,  1123, -1586, -1586, -1586, -1586,
   -1586,  1131,  1380, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
    1389, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
    1132, -1586, -1586, -1586, -1586,    86,    -3, -1586,   -88, -1586,
    1513, -1586,  1391,  1133, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586,    -4,    -4,    -4,    -4,
   -1586,  1337,  1426,  1427,  1429,  1434,    -4, -1586, -1586, -1586,
   -1586,   -96,  1135, -1586, -1586, -1586, -1586,  1364,     5,  -117,
     -89,    -4, -1586, -1586, -1586, -1586,    -4,  1206, -1586,    -4,
    1276, -1586,  1119, -1586,  1128, -1586, -1586, -1586,    -4,    -4,
      -4,    -4, -1586,    42, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586,  1230, -1586, -1586, -1586, -1586,  1198,  1465,  1433,
   -1586, -1586, -1586, -1586,  1171,  1146, -1586, -1586,  1147,   -88,
   -1586,   -88, -1586,  1590, -1586, -1586, -1586, -1586, -1586, -1586,
      -4,    -4,  1148,    -4,  1149, -1586,    21,  1156,  1513, -1586,
     397,  1155,  1159,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
    1163,  1438, -1586, -1586, -1586, -1586,   282,   964,   411, -1586,
    1166, -1586,  1172, -1586, -1586, -1586,  1486,    65,    -4, -1586,
   -1586,  1181, -1586,  1405,  1405,  -100,    -4,  1174,  1199,    -4,
    1176,  1198,    -4,    -4, -1586,    -4,  1177,  1171, -1586,  1223,
   -1586,   -88,  1435,    -4, -1586, -1586, -1586,  1628, -1586,    -3,
   -1586, -1586,  1184,  1185, -1586, -1586,    -4,    -4,  1483,    -4,
    1186,  1188, -1586, -1586, -1586,    -4, -1586, -1586, -1586, -1586,
      -4,    -4, -1586, -1586, -1586,  1218,  1200,    -4,     3,    -4,
   -1586, -1586, -1586,  1259, -1586,    -4, -1586,  1515, -1586, -1586,
   -1586, -1586,    -4,  1517, -1586, -1586, -1586, -1586,    32,    -4,
   -1586,  1521,    -4,  1235, -1586, -1586,  1236,    -4,    -4,    -4,
    1596,  1597,  1237,  1446,  1452,  1469,    -4, -1586, -1586,    -4,
   -1586, -1586,    -4,  1533,  1478, -1586,    -4, -1586,    -4, -1586,
   -1586,  1540,    -4,  1538, -1586,  1249,    -4,  1573, -1586, -1586,
      -4,    -4,  1254, -1586, -1586, -1586,    -4,    -4,    -4, -1586,
    1314, -1586, -1586,  1541, -1586, -1586, -1586,  1548,    -4,    -4,
   -1586,  1540, -1586,  1546, -1586,    -4,    -4,    -4,  1257, -1586,
   -1586, -1586, -1586, -1586,    51, -1586,    53,    -4,    -4, -1586,
   -1586, -1586,    56,    -4, -1586, -1586,   997, -1586,  1549, -1586,
      -4,    -4, -1586,  1550,  1550,    38, -1586, -1586, -1586, -1586,
   -1586, -1586,    74,    81, -1586, -1586,  1320,  1554,    -4,  1263,
   -1586,    -4, -1586, -1586,  1704,    -4, -1586,  1610,    -4,    -4,
      -4, -1586,  1286, -1586, -1586,    87,    -4,    -4, -1586, -1586,
    1332, -1586,    -4,  1279,  1566,    -4,  1280,  1281,  1287, -1586,
   -1586, -1586,  1604, -1586, -1586,    -4,  1288, -1586, -1586,  1289,
   -1586, -1586, -1586,    -4, -1586,    -4,    -4, -1586, -1586, -1586,
      -4,  1290,  1396,    -4,    -4,    -4,    -4,  1291, -1586, -1586,
     -17,    -4,    -4, -1586,    -4, -1586,    -4,    -4,  1582,    -4,
      -4,  1293,  1294,  1295,    -4, -1586, -1586, -1586,  1296, -1586
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    10,     0,  1074,     1,   875,     0,   448,    79,   529,
       0,     0,   459,   500,   438,    67,   335,   398,   908,   910,
     912,   957,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   904,   906,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    21,    14,     9,    15,
      22,    47,    46,    48,    49,    16,    68,    17,    83,    50,
      18,     0,   333,     0,    19,    20,    24,   440,    27,   450,
      26,    25,    32,    28,   504,    29,   533,    30,   879,    23,
      51,    31,    33,    34,    35,    37,    36,    38,    39,    40,
      41,    42,    43,    44,    45,    11,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     959,     0,     0,     0,     0,     0,     0,     0,  1034,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    61,    60,     0,    62,    63,     0,     0,     0,
       0,   336,     0,   403,   422,   419,   405,   424,     0,     0,
       0,   527,   873,     0,  1076,     2,  1075,   876,   458,    80,
     530,     0,    53,    52,   460,   501,   399,     0,     0,     0,
       0,     7,     0,     0,  1031,  1051,  1033,  1032,     0,  1069,
    1068,  1070,     6,    55,    54,     0,     0,  1071,  1072,  1073,
      57,    59,    65,    64,     0,   331,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,   132,
       0,   135,     0,     0,   140,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   207,     0,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,   185,   207,    85,     0,     0,
       0,     0,    78,    84,   337,   338,   370,   389,     0,   360,
     339,   358,   350,     0,   351,   353,   355,     0,   356,   391,
     404,   401,     0,   406,   407,   418,     0,   444,   437,   441,
       0,     0,     0,   447,   451,   453,     0,   502,     0,   514,
     519,   499,   505,   508,   507,   509,     0,   809,   614,     0,
       0,   616,   799,     0,   624,     0,   620,     0,     0,   560,
     812,   555,     0,     0,     0,     0,     0,   534,   539,   535,
     536,   537,   538,   542,   541,   543,   540,   544,   545,   547,
       0,   546,   548,   628,   551,     0,   552,   553,   554,   814,
     621,   883,   885,   887,     0,   890,     0,   881,     0,   880,
     895,   893,    12,   457,   465,     0,     0,     0,     0,   963,
     973,   961,   967,   975,   965,   969,   971,   960,     4,  1030,
       0,     0,     0,     0,    58,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   280,
     281,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,   274,   275,   273,   276,   277,   278,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   241,   243,
     121,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,   209,     0,
       0,   170,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,   149,     0,     0,
       0,     0,     0,     0,   396,   334,   352,   372,   374,   375,
     373,   376,   378,   379,   377,   380,   381,   382,   383,   386,
     384,   387,   385,   366,     0,     0,     0,     0,   388,     0,
       0,     0,   411,     0,     0,   408,   409,   420,     0,     0,
       0,     0,     0,     0,     0,     0,   425,   439,     0,   449,
     456,     0,     0,     0,     0,     0,     0,     0,   521,   572,
     580,   581,   569,     0,   577,   571,   578,   575,   576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   803,   801,   609,
       0,     0,   531,   528,     0,     0,     0,   798,   755,   445,
     445,   445,   445,     0,     0,   766,   765,     0,     0,     0,
       0,   894,     0,   901,     0,   877,   874,     0,     0,   467,
       0,     0,     0,   928,   914,   947,     0,     0,   914,     0,
     943,   942,     0,     0,     0,   914,     0,   958,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1058,     0,  1054,
    1057,     0,  1041,     0,  1037,  1040,   914,   914,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
     113,   104,   114,    82,   109,    94,     0,    90,     0,     0,
       0,   183,   112,  1000,   111,    88,    98,     0,     0,   259,
       0,     0,   116,   115,   110,     0,     0,     0,     0,     0,
     131,     0,   233,     0,   134,     0,   239,   139,     0,   142,
       0,   239,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,   166,   167,     0,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
     168,   283,   225,   169,     0,     0,     0,     0,     0,     0,
      89,   184,    97,    92,     0,    96,   773,   775,     0,   188,
     189,     0,   151,   150,   371,     0,   357,     0,     0,     0,
     361,     0,   354,     0,   525,   369,   367,     0,   445,   445,
     392,   407,   423,   415,   416,   417,     0,     0,   435,   400,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,   454,   511,   510,   512,   503,     0,   516,
     517,   518,   513,   515,     0,   573,   574,   590,   593,   591,
     592,   594,   595,   582,   570,   600,   601,   597,   596,   598,
     599,   583,   586,   584,   585,   587,   588,   589,   579,   568,
       0,     0,     0,   602,     0,   608,   625,   607,     0,   606,
     605,   604,   562,   563,   564,   559,   561,     0,     0,   557,
     549,   550,     0,     0,   612,   610,     0,     0,   618,     0,
     619,     0,     0,     0,   626,     0,     0,   657,     0,     0,
     636,     0,     0,   651,   653,   737,     0,     0,     0,     0,
       0,     0,     0,     0,   750,     0,     0,     0,     0,   670,
     655,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   687,   693,   689,   691,     0,
     623,   629,   639,   738,     0,     0,     0,     0,     0,   445,
       0,     0,   797,   754,     0,   865,     0,     0,     0,     0,
     816,   864,     0,     0,     0,     0,   818,     0,     0,   844,
     845,     0,     0,     0,   846,   847,     0,     0,     0,   841,
     842,   843,   811,   815,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     897,   899,   896,   466,   461,     0,   925,     0,     0,     0,
       0,     0,   915,   916,   909,     0,     0,     0,   911,     0,
     939,     0,     0,     0,   952,   953,   948,   949,   950,   951,
       0,     0,   954,   955,   956,     0,     0,     0,     0,     0,
     913,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   914,  1055,     0,     0,     0,
     914,  1038,   905,   907,     0,    71,    74,    76,    73,    72,
      70,    75,    77,     0,   107,    95,    91,     0,   105,  1003,
    1002,  1005,  1006,  1000,   261,   262,   263,   120,   260,     0,
       0,   264,     0,   123,     0,   122,   128,   125,   124,     0,
     133,   136,   240,     0,   141,   144,     0,   165,   172,   148,
     179,     0,     0,     0,     0,     0,     0,   194,     0,   178,
      93,     0,   181,     0,     0,   152,   390,     0,   365,   364,
     363,   359,   362,   397,     0,   368,   394,     0,     0,   413,
       0,   421,     0,   426,   427,   434,   433,     0,   432,     0,
       0,     0,     0,   455,     0,     0,   520,   522,   810,   615,
     603,   617,     0,   567,   566,   565,   556,   558,     0,   800,
     802,   611,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   746,
     747,   748,   749,     0,   751,   753,   752,     0,     0,   741,
     744,   745,   743,   742,   740,     0,     0,     0,     0,     0,
       0,  1025,  1025,  1025,     0,     0,  1025,  1025,  1025,  1025,
       0,     0,  1025,     0,     0,     0,     0,     0,     0,   630,
       0,     0,   673,     0,   756,   446,     0,   775,     0,     0,
       0,     0,     0,   777,   758,   767,   813,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   866,   867,   868,
       0,     0,   859,     0,     0,     0,   856,   840,     0,     0,
       0,     0,   848,   849,   850,     0,     0,   854,   855,     0,
     884,   886,     0,     0,   888,     0,     0,   891,     0,     0,
     902,   882,   878,   889,     0,     0,   486,     0,   479,     0,
       0,     0,   470,   471,     0,   468,   473,   474,   475,   472,
     469,   917,     0,     0,   926,   922,   921,   923,   924,     0,
     945,   944,     0,   940,   931,   930,   929,   935,   936,   938,
     937,   934,   933,   932,   979,   994,   994,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1056,  1060,     0,  1053,
    1052,  1039,  1043,     0,  1036,  1035,   332,     0,     0,   267,
       0,     0,   270,   992,     0,  1007,     0,     0,     0,     0,
       0,     0,     0,  1001,     0,     0,   265,     0,   244,   255,
     257,     0,   138,   146,   218,   210,   284,   171,   232,   230,
       0,   231,     0,   175,   226,   227,     0,     0,     0,   255,
     325,   186,   774,   776,   216,   190,     0,   236,     0,   526,
       0,     0,   402,   412,   414,   436,   430,     0,     0,   428,
       0,   442,   506,   523,   622,   804,   783,   659,   664,   665,
     736,   735,   732,     0,   733,   627,   646,   644,     0,     0,
     642,     0,   660,   661,     0,     0,   638,   663,   662,   645,
     643,   666,   667,   641,   650,   649,   640,   648,   647,     0,
       0,   727,     0,   669,  1026,     0,     0,     0,   677,   678,
       0,     0,     0,     0,  1028,     0,     0,     0,     0,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,     0,     0,     0,     0,   633,     0,   631,     0,     0,
       0,   768,   775,     0,     0,     0,     0,     0,   779,     0,
       0,     0,     0,     0,   869,     0,     0,     0,     0,     0,
     871,     0,   833,     0,   823,   860,     0,   824,   857,   837,
     838,   839,     0,   851,   852,   853,     0,     0,     0,     0,
       0,     0,     0,   892,     0,     0,     0,     0,   483,   484,
     485,     0,     0,     0,     0,   463,   462,   918,     0,     0,
       0,     0,     0,   980,     0,   998,   996,   981,   964,   974,
     962,   968,   976,   966,   970,   972,     0,  1061,     0,  1044,
       0,     0,   268,     0,     0,   271,   993,  1004,  1012,     0,
       0,  1015,     0,     0,     0,  1019,   101,     0,   117,   118,
     257,     0,     0,   234,     0,   220,     0,     0,     0,   228,
     229,     0,   102,     0,   195,     0,     0,     0,     0,    86,
       0,     0,     0,     0,   431,   429,   443,   524,     0,     0,
     734,     0,   668,   637,   652,     0,   731,   730,   729,   671,
     728,     0,     0,   674,   676,   675,   679,   680,   683,   682,
       0,   684,   685,   681,   686,   688,   694,   690,   692,   634,
       0,   632,   739,   672,   769,   770,     0,   759,     0,   775,
       0,   761,     0,     0,   828,   832,   830,   826,   870,   817,
     827,   825,   829,   831,   872,   819,     0,     0,     0,     0,
     820,     0,     0,     0,     0,     0,     0,   898,   900,   487,
     481,     0,     0,   476,   477,   464,   919,     0,     0,     0,
       0,     0,   999,   977,   997,   978,     0,  1059,  1062,     0,
    1042,  1045,     0,   108,     0,   106,  1008,  1013,     0,     0,
       0,     0,   266,     0,   129,   256,   258,   126,   236,   219,
     221,   222,   223,   211,   213,   180,   176,   204,     0,     0,
     326,   199,   217,   182,   191,     0,   237,   238,     0,     0,
     393,     0,   806,     0,   658,   654,   656,  1027,  1029,   635,
       0,     0,     0,     0,     0,   775,     0,     0,     0,   778,
       0,     0,     0,     0,   861,     0,     0,     0,     0,     0,
       0,     0,   480,   482,   478,   920,   927,   946,   941,   995,
       0,  1063,     0,  1046,   269,   272,  1021,   982,     0,  1010,
    1017,     0,   245,     0,     0,     0,     0,     0,   214,     0,
       0,   204,     0,     0,   255,     0,     0,   191,   153,     0,
     775,     0,   805,     0,   772,   771,   757,     0,   760,     0,
     763,   762,     0,     0,   858,   836,     0,     0,     0,     0,
     784,   787,   795,   796,   903,     0,  1064,  1047,  1022,  1009,
       0,     0,   983,  1014,  1016,  1023,   987,     0,   248,     0,
     130,   127,   235,     0,   173,     0,   212,     0,   103,   205,
     202,   196,   200,     0,    87,   192,   154,   340,     0,     0,
     807,     0,     0,     0,   780,   834,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   984,     0,  1024,  1011,     0,
    1018,  1020,     0,     0,     0,   253,     0,   215,     0,   327,
     255,   321,     0,     0,   395,     0,     0,     0,   764,   835,
       0,     0,     0,   785,   788,   488,     0,     0,     0,   986,
       0,   251,   249,     0,   255,   224,   206,   203,   197,     0,
     201,   321,   193,     0,   808,     0,     0,   862,     0,   822,
     792,   792,   491,  1066,     0,  1049,     0,     0,     0,   255,
     257,   246,     0,     0,   328,   317,   325,   322,     0,   782,
       0,     0,   821,   786,   789,     0,  1065,  1067,  1048,  1050,
     985,   988,     0,     0,   257,   254,     0,   198,     0,     0,
     781,     0,   794,   793,     0,     0,   489,     0,     0,     0,
       0,   492,   990,   252,   250,     0,     0,     0,   318,   323,
       0,   863,     0,     0,     0,     0,     0,     0,     0,   991,
     989,   247,     0,   319,   255,     0,     0,   497,   490,     0,
     493,   494,   498,     0,   255,   324,     0,   496,   495,   329,
     320,     0,     0,     0,     0,     0,     0,     0,   341,   343,
     342,     0,     0,   348,     0,   344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   346,   349,   345,     0,   347
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1586, -1586, -1586, -1586,    -6, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,   -86, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,   -84, -1586,
    1492, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586,   116, -1586,     2, -1586,  1058, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586,   -70, -1586, -1391, -1585, -1586,  1093,
   -1586,   693, -1586,   404, -1586,   405, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586,  -206, -1586, -1586,  -229, -1586, -1586, -1586,
   -1586,   781, -1586,  1474, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586,  1274, -1586, -1586,  1009, -1586,
    -139, -1586,  -332, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586,  1255,  1021, -1586,
    -498, -1586, -1586,  -130, -1586, -1586, -1586, -1586, -1586, -1586,
     648, -1586,   783, -1586, -1586, -1586, -1586, -1586,  -513, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1460, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586,  -211, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
     904, -1586,   547, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
     319, -1586, -1586, -1586, -1586, -1586, -1586,   548,   837, -1586,
   -1586, -1586, -1586, -1586,  -920, -1210, -1228, -1586, -1586, -1586,
   -1502,  -593, -1586, -1586, -1586, -1586, -1586,  -199, -1586, -1586,
   -1586, -1586, -1586, -1586,   931, -1586, -1586, -1586,   -69, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586,   521, -1586, -1586,   -11,   232,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586,  1639, -1586, -1586, -1586,
    -588,  -712,  -913,  -343,  -609,  -336,  -624, -1586, -1586, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,  -257,
   -1586, -1586, -1586, -1586, -1586,   458, -1586, -1586,   719, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,  -446,
   -1586,  -658, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586,
   -1586,  1150, -1586, -1586, -1586, -1586,    55, -1586, -1586, -1586,
   -1586, -1586, -1586,  1158, -1586, -1586, -1586, -1586,    68, -1586,
   -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586, -1586
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    45,   112,   515,    46,    47,     3,   155,    48,
      49,    50,    51,    52,    53,    54,   134,   137,   194,    55,
      56,   139,   206,    57,    58,    99,   272,   414,   140,   273,
     484,  1774,   673,  1767,   431,   686,  1380,  1834,  1379,  1833,
     443,   445,   696,   448,   450,   701,   466,  1407,  1906,   751,
    1384,   752,   476,  1385,  1404,   482,   770,  1114,  1846,  1847,
     759,  1399,  1769,  1940,  1995,  1844,  1941,  1939,  1840,  1841,
     469,  1628,  1838,  1896,  1638,  1625,  1762,  1837,  1103,  1394,
    1395,   693,  1758,  1640,  1776,  1093,   440,  1085,  1620,  1888,
    2014,  1934,  1990,  1989,  1890,  1964,  1621,  1622,   678,   679,
    1080,  1081,  1358,  1359,  1361,  1362,   429,   412,  1102,   748,
    2017,  2038,  2064,  1970,  1971,  2054,  1636,  1967,  1994,    59,
     395,    60,   142,    61,    62,   282,   492,  1943,  2079,  2080,
    2085,  2088,   283,   284,   496,   285,   493,   779,   780,   286,
     287,   489,   516,   288,   289,   490,   518,   790,  1410,   495,
     781,    63,   106,    64,    65,   519,   291,   145,   524,   525,
     526,   796,  1130,   146,   294,   527,   147,   292,   295,   536,
     799,  1132,    66,    67,   298,   148,   299,   300,   936,    68,
      69,   303,   149,   304,   541,   813,   305,    70,    71,    72,
     104,   374,  1304,  1576,   609,   994,  1305,  1306,  1307,  1308,
    1309,  1571,  1721,  1310,  1567,  1811,  1982,  2044,  2005,  2031,
      73,    74,   105,   311,   545,   150,   312,   313,   314,   547,
     823,   315,   548,   824,  1147,  1647,  1402,    75,   336,    76,
     100,   583,   877,   151,   337,   573,   868,   338,   572,   866,
     869,   339,   559,   848,   833,   841,   340,   341,   342,   343,
     344,   345,   346,   347,   561,   348,   564,   349,   350,   367,
     351,   352,   353,   566,   930,  1171,   586,   931,  1177,  1180,
    1181,  1209,  1174,  1208,  1224,  1226,  1227,  1225,  1511,  1460,
    1461,   932,   933,  1233,  1205,  1193,  1197,   594,   595,   934,
    1521,   943,  1685,  1792,   767,  1403,  1111,   596,  1529,  1692,
    1794,   585,   982,  1920,  1980,  1921,  1981,  2003,  2023,   985,
     354,   355,   356,   873,   578,   872,  1648,  1852,  1782,   357,
     560,   358,   359,   972,   597,   973,  1251,  1256,  1804,   974,
     975,  1275,  1556,  1279,  1265,  1266,  1263,  1868,   976,  1260,
    1535,  1541,    77,   368,    78,    96,   606,   988,   152,   369,
     604,   598,   599,   600,   602,   370,   607,   992,  1294,  1295,
     986,  1290,    79,   125,    80,   126,    81,   107,   108,   109,
    1004,  1313,  1728,   624,   625,   626,  1025,    82,   110,   170,
     387,   630,   628,   633,   631,   634,   635,   629,   632,  1338,
    1883,  1930,  2032,  2050,  1607,  1585,  1735,  1733,  1072,  1073,
    1363,  1372,  1609,  1826,  1885,  1827,  1886,  1879,  1928,  1465,
    1662,  1475,  1670,    83,    84,    85,    86,    87,   178,  1050,
     643,   644,   645,  1048,  1353,  1740,  1741,  1924,  1986,    88,
     390,  1045,   638,   639,   640,  1043,  1348,  1737,  1738,  1923,
    1984,    89,    90,    91,    92,    93,    94,    95,   156
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   995,  1033,   580,   101,   978,   979,  1005,  1634,  1523,
    1009,   987,   335,  1010,  1012,   293,  1237,  1239,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   800,   756,  1525,
    1008,  1793,   614,   274,   130,  1753,  1364,  1030,   138,   306,
     618,  1236,  1238,   939,  1420,  1433,  1240,   827,  1388,  1296,
     819,   820,  2024,  1069,   615,   521,   646,   647,  1052,  1053,
     307,  1228,   528,   153,   821,    97,   842,   843,   423,  2081,
     408,  2082,    97,  2025,  1297,  2026,   517,   937,   938,   940,
    1626,  2083,   615,    97,    97,   549,  1880,   677,   862,   863,
      97,  1365,   542,    97,   616,   161,   778,   550,   551,   552,
     844,   529,   864,   195,  1288,  1726,  1790,   173,  1145,    97,
    1044,  1720,   565,   553,    97,    16,   867,   845,  1459,    14,
     530,   522,   619,   521,   581,   620,   621,    97,  1231,   521,
    1159,   687,   424,  1698,   828,   622,    97,    97,   531,   532,
    1298,     4,    97,  1704,   846,   829,   830,    16,  2027,  1232,
      97,    97,    97,   111,   308,  1297,    97,   577,    97,   301,
     143,  1002,   425,   533,   309,  1003,   543,    97,    97,    97,
    1932,   554,  2028,   801,   144,  1007,   409,    97,   825,  1002,
      97,   127,    97,  1003,    97,   787,   788,   555,  1797,   522,
    1165,    97,   789,    97,   658,   522,   534,    97,   989,   432,
    1726,   122,   296,   407,    97,   413,  1756,   415,   416,   417,
     419,   420,   421,   422,  1756,   430,   610,   434,   435,   436,
    1791,  1298,   442,    97,   444,    97,   446,   447,    97,   449,
     426,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,    97,   826,   470,   876,
     472,   473,   474,  1756,   477,   478,   479,   480,   481,  1756,
     688,  1813,  1366,   486,   302,   488,   154,  1627,   996,   997,
    1289,   766,   491,   569,   771,  1126,  1127,   427,  1311,   802,
    1011,  1006,  1026,  1027,  1276,  1026,  1027,  1013,  1028,  1029,
     297,  1028,  1029,  1319,  1686,  1166,  1862,  1322,  1129,  1933,
    1881,  1726,   546,   144,  1026,  1027,   128,   544,   135,  2029,
    1028,  1029,   556,   570,  1688,  1689,  1522,   831,  1524,   567,
     805,   568,   636,   637,   136,  1389,  1367,  1390,   196,  1070,
    1049,  1726,  1391,   131,  1014,  1015,  1016,  1017,  1018,  1019,
    1031,  1032,   822,    97,   617,  1413,  1007,   998,   999,  1000,
    1001,  1434,  1320,  1392,   514,  1775,  1727,  1913,   990,   991,
     603,   514,  1892,  1882,  1812,   129,   611,   847,  1421,   613,
    1393,   613,   623,   514,  1368,   141,  1071,  1077,   665,   535,
     865,  1229,   514,   437,   438,   439,  1121,   157,   935,  1033,
     649,   650,   651,   428,   652,   653,   654,   655,  1146,   557,
     659,   757,    97,   433,  1299,  2013,  1156,  2084,  1659,   521,
     666,   668,   670,  1300,  1301,   667,   275,  1327,  1328,  1329,
    1330,   410,   411,  1699,   558,   763,  1242,   681,   669,  2035,
     811,   832,  1779,  1705,   685,   689,   945,   692,   878,   692,
     514,   514,   692,  1007,   692,   514,  1544,   929,   310,  2030,
    1277,  1727,   571,  1902,  1278,  1596,   712,  1350,   514,   758,
     611,  1796,  1355,   749,  1369,  1370,   612,  1297,  1401,   514,
    1598,  1371,  1515,   514,   764,   522,   290,   768,  1795,  1687,
     514,  1860,   514,   159,   276,  1754,   316,   691,   317,   418,
    1642,   276,  1944,   514,  1757,  1026,  1027,  1026,  1027,   158,
     277,  1028,  1832,  1028,  1029,   162,   318,   277,   783,   784,
     951,  2006,  1189,  2008,  1194,   160,  2015,   588,   276,   163,
     319,   320,   164,   803,   804,   165,   806,   807,   808,   809,
    1312,  1323,   166,  1298,  2033,   812,   321,    97,  1334,  1335,
    1336,  2034,   641,   642,   167,  1190,   278,  2051,   168,  1968,
     589,   169,  1727,   278,   322,  1195,   590,  1257,   323,   587,
    1115,   695,   591,  1476,   698,  1478,   700,  1859,   171,  1850,
     324,   835,   836,  1992,  1007,  1337,   325,   172,   879,  1258,
    1259,  1022,  1727,  1023,  1024,   174,   588,   941,   175,   279,
     176,   197,   177,  1191,  1137,  1192,   279,   179,  2012,   280,
     326,   327,   328,   198,   613,   613,   613,   199,   102,   103,
     613,   329,   180,   613,   200,   592,   613,   613,   330,   589,
     593,  1196,  1908,   123,   124,   590,   181,  1026,  1027,   182,
    1042,   591,  1414,  1028,  1029,  1047,    97,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   132,   133,  1315,  1316,  1317,  1318,   192,
     193,   293,   183,  2065,   184,   837,  1729,   838,  1730,  1729,
     185,  1321,   281,  2070,   186,  1082,   187,  1324,  1325,   281,
     188,  1086,  1326,   201,   592,   360,   189,   202,   190,   593,
    1167,   998,   999,  1000,  1001,  1331,  1332,  1333,  1314,  1168,
    1169,  1565,  1566,   793,   794,   795,   331,   467,   468,  1098,
     191,   839,   840,  1581,   998,   999,  1000,  1001,  1230,  1002,
    1074,  1075,  1076,  1003,   203,   766,   766,  1241,   144,  1243,
    1272,  1273,  1274,  1170,   574,   575,   332,   998,   999,  1000,
    1001,  1002,   204,  1100,   372,  1003,   980,   981,  1104,  1105,
     373,  1107,   361,   362,   363,   364,   365,   366,  1118,  1119,
    1120,   375,  1112,    18,    19,    20,  1466,  1467,   636,   637,
    1470,  1471,  1472,  1473,   641,   642,  1477,  1124,  1339,  1340,
    1341,  1342,  1343,  1344,  1345,   333,    97,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,  1141,  1142,   376,  1143,  1153,  1154,  1155,
     983,   984,  1144,  1423,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     377,  1426,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,  1553,  1554,
    1555,   388,  1152,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,  1568,
    1569,  1570,   205,  1163,   334,  1164,  1079,  1375,  1381,  1172,
    1173,  1547,  1264,  1176,   389,  1178,  1179,  1656,  1657,  1658,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,   391,  1518,  1198,
     394,  1206,  1207,  1000,  1001,   392,  1211,  1212,   393,  1214,
    1215,  1026,  1027,  1357,  1601,   396,  1411,   397,  1360,  1604,
    1760,  1761,   399,   398,   513,   514,   400,   401,   402,  1235,
     403,   404,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1247,  1248,  1249,  1250,   405,   406,  1252,  1253,  1254,  1255,
     441,   471,   475,   485,   487,  1262,   494,   520,  1033,   537,
     538,   539,   540,   562,   563,   577,   582,   576,   584,   601,
    1578,   879,   605,   608,  1282,  1283,   627,  1285,  1286,  1580,
     648,   656,   663,  1579,   657,   677,  1582,   660,   661,   662,
     715,   664,   613,   613,   613,   613,   671,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   672,   613,   613,   674,  1516,   675,   613,
     613,   613,   613,   613,   676,   766,   680,   766,   682,  1526,
    1527,  1528,   683,   684,   690,   694,   697,  1347,   754,   699,
     702,   703,  1352,   704,   705,   706,   707,  1726,   755,   708,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,   709,   710,
     711,   713,   714,   750,  1014,  1015,  1016,  1017,  1018,  1019,
    1031,  1032,   753,  1374,   579,   514,   760,   761,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,   762,   765,   769,   772,
     773,   774,   775,   776,   777,  1386,   778,   378,   785,   792,
    1398,   786,  1400,   797,   798,   814,  1199,  1405,  1014,  1015,
    1016,  1017,  1018,  1019,  1031,  1032,  1200,   810,   379,   875,
     815,  1818,   816,   817,   380,   818,   834,   381,   382,   849,
    1201,   850,   851,  1417,  1418,   852,   853,   854,   855,   856,
    1517,   383,   857,   858,   867,   859,   860,   861,   870,   871,
     874,  1202,   880,   935,   942,   977,   993,  1034,  1035,  1036,
     384,  1037,  1038,  1039,  1040,  1041,  1054,  1055,  1438,  1056,
    1623,   998,   999,  1000,  1001,  1445,  1063,  1084,  1314,  1022,
    1057,  1023,  1024,  1058,  1680,  1059,  1060,   207,  1061,  1062,
    1064,  1065,   208,   209,  1066,  1087,  1067,  1068,  1083,   766,
    1643,  1079,  1088,  1462,  1089,  1203,  1092,  1090,  1091,  1094,
    1095,   210,  1097,   211,  1099,   212,  1101,  1106,  1108,  1109,
    1110,  1113,   385,   386,  1139,  1123,  1116,  1117,  1204,  1125,
    1131,   213,  1140,  1133,  1134,  1135,  1136,  1213,  1138,  1158,
    1148,  1530,  1531,  1532,  1533,  1149,  1536,  1537,  1538,  1539,
    1162,  1150,  1175,  1216,  1210,  1543,  1151,  1545,  1546,  1217,
    1161,  1218,  1219,  1220,   214,  1552,  1221,  1222,  1223,  1246,
    1557,  1234,  1261,  1244,  1268,  1264,  1269,  1267,  1270,   215,
    1280,  1281,  1271,  1564,  1679,  1292,  1284,  1287,   216,   998,
     999,  1000,  1001,  1291,  1293,  1346,  1349,  1022,  1727,  1023,
    1024,  1351,  1377,  1356,  1007,  1354,   217,   613,  1357,  1378,
    1320,  1022,   218,  1023,  1024,  1690,   613,   998,   999,  1000,
    1001,   219,  1360,  1382,  1383,  1022,  1387,  1023,  1024,  1396,
    1397,  1406,  1408,   220,  1409,  1415,  1416,  1419,  1422,  1424,
    1425,  1427,  1597,  1428,  1429,   221,  1430,  1599,  1007,  1431,
    1432,  1600,  1435,  1439,  1603,  1022,  1436,  1023,  1024,  1437,
    1610,  1611,  1612,  1613,  1614,  1615,  1440,  1441,  1617,  1442,
    1443,  1444,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1459,
    1464,  1474,  1512,  1453,  1629,  1816,  1630,  1454,  1513,  1514,
    1631,  1632,  1455,  1817,  1456,  1534,  1457,  1458,  1463,  1468,
    1639,  1469,  1641,  1540,  1542,  1549,  1550,  1558,  1551,  1559,
    1560,  1561,  1562,  1572,   222,  1563,  1573,  1574,  1575,  1577,
    1007,  1583,  1584,  1587,  1608,  1606,  1588,  1624,  1589,  1777,
    1590,  1591,  1651,  1592,   223,  1593,   224,  1594,  1595,  1655,
    1616,  1618,  1619,  1633,  1637,  1649,  1644,  1635,  1693,   225,
    1645,  1683,  1706,  1709,  1719,  1725,  1661,  1736,  1646,  1650,
    1652,  1653,  1654,  1663,  1664,  1665,  1666,  1667,   226,   227,
    1668,  1669,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1681,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,  1682,  1691,  1684,
    1716,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,  1734,   252,  1739,   253,  1746,
    1694,  1695,  1696,  1697,  1700,  1701,   254,   255,   256,  1702,
    1707,  1749,  1748,  1750,  1781,  1703,  1708,  1793,  1717,  1751,
    1787,  1710,  1718,  1712,  1713,  1714,  1715,  1723,  1724,  1788,
    1743,  1798,  1745,  1805,  1806,  1807,  1722,  1808,  1752,  1765,
    1851,  1766,  1809,   257,   258,   259,  1773,  1815,  1731,  1732,
    1780,  1824,  1784,  1785,  1836,   260,   261,   262,   263,   264,
    1825,  1786,  1789,  1799,  1742,  1814,  1839,  1744,   265,  1842,
    1843,   266,  1845,  1853,  1747,  1875,  1848,  1849,  1856,  1858,
     267,   268,   269,   270,   271,  1755,  1861,  1864,  1759,  1865,
    1763,  1764,  1878,  1874,  1777,  1887,  1876,  1768,  1755,  1770,
    1771,  1772,  1877,  1889,  1894,  1778,  1898,  1904,  1895,  1907,
    1909,  1912,  1918,  1783,  1914,  1915,  -790,  1929,  -791,  1938,
     944,  1942,   945,   946,   947,   948,   949,  1936,  1927,  1946,
    1953,  1954,   950,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,  1948,  1949,  1955,  1956,  1957,
    1800,  1801,  1802,  1803,  1958,  1962,  1963,  1969,  1973,  1974,
    1810,  1976,  1988,  1991,  1979,  1993,  1998,  2002,  2036,  2019,
    2022,  2037,   613,  2040,   613,  1819,   951,   952,   953,  2042,
    1820,   954,   955,  1822,  2045,  2055,  2058,  2049,  2063,  2057,
    2060,  2061,  1828,  1829,  1830,  1831,  2073,  2062,  2067,  2068,
    2072,  2078,  2092,  2095,  2096,  2097,  2099,  1899,   483,  1096,
    1835,  1905,  1602,   956,  1891,  1997,  1605,  2018,   523,   957,
     782,  1078,  1157,  1376,   791,  1302,  1412,  1303,  1519,  1660,
    1245,  1520,  2004,  1910,  1854,  1855,  1548,  1857,  1122,  1863,
    1711,   371,  1373,  1051,  1586,  1823,  1046,  1866,  1867,  1869,
    1870,  1871,  1872,  1873,  1160,  1821,     0,     0,     0,     0,
       0,     0,  1128,     0,     0,     0,     0,     0,   958,   959,
     960,     0,  1884,     0,     0,     0,     0,     0,     0,     0,
    1893,     0,     0,  1897,     0,     0,  1900,  1901,     0,  1903,
     961,   962,     0,   963,     0,     0,     0,  1911,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1916,  1917,     0,  1919,     0,     0,     0,     0,     0,  1922,
       0,     0,     0,     0,  1925,  1926,     0,     0,     0,     0,
       0,  1931,     0,  1935,     0,     0,     0,     0,     0,  1937,
       0,     0,   964,   965,     0,     0,  1755,   966,   967,   968,
     969,   970,   971,  1945,     0,     0,  1947,     0,     0,     0,
       0,  1950,  1951,  1952,     0,     0,     0,     0,     0,     0,
    1959,     0,     0,  1960,     0,     0,  1961,     0,     0,     0,
    1965,     0,  1966,     0,     0,     0,  1972,     0,     0,     0,
    1975,     0,     0,     0,  1977,  1978,     0,     0,     0,     0,
    1983,  1985,  1987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1755,  1996,     0,     0,     0,     0,     0,  1999,
    2000,  2001,     0,     0,     0,     0,     0,     0,  2007,     0,
    2009,  2010,  2011,     0,     0,     0,  1755,  2016,     0,     0,
       0,     0,     0,     0,  2020,  2021,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1755,     0,     0,     0,
       0,     0,  2039,     0,     0,  2041,     0,     0,     0,  2043,
       0,     0,  2046,  2047,  2048,     0,     0,     0,     0,     0,
    2052,  2053,     0,     0,     0,     0,  2056,     0,     0,  2059,
       0,     0,     0,   881,     0,     0,     0,     0,     0,  2066,
       0,     0,     0,     0,     0,     0,   882,  2069,     0,  1755,
    2071,     0,   883,     0,  1755,     0,   884,  2074,  2075,  2076,
    2077,     0,     0,   885,   886,  2086,  2087,   276,  2089,     0,
    2090,  2091,     0,  2093,  2094,     0,   887,     0,  2098,     0,
       0,     0,   888,     0,   889,   890,     0,     0,     0,   891,
     892,     0,     0,     0,     0,   893,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   894,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   895,     0,   896,     0,   897,     0,   898,
       0,     0,     0,     0,     0,   899,   900,     0,     0,   901,
     902,     0,     0,     0,     0,   903,   904,     0,     0,     0,
       0,     0,     0,     0,     0,    -8,     1,     0,     0,     0,
       0,     0,     0,    -8,     0,   905,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,     0,     0,
     907,     0,     0,   908,     0,     0,     0,    -8,     0,     0,
       0,     0,    -8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -8,     0,     0,    -8,
       0,     0,     0,    -8,     0,     0,     0,     0,     0,     0,
      -8,     0,    -8,     0,     0,     0,    -8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   909,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   910,
       0,     0,     0,     0,     0,     0,     0,     0,   911,     0,
     912,   913,   914,   915,   916,    -8,     0,     0,     0,    -8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -8,     0,     0,     0,     0,    -8,    -8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   917,   918,   919,   920,   921,   922,
     923,   924,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -8,    -8,    -8,     5,   925,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -8,     0,     0,     0,
       6,     0,     0,    -8,    -8,    -8,     0,    -8,    -8,    -8,
      -8,    -8,     0,    -8,     0,     0,     0,     0,    -8,    -8,
      -8,     0,     0,     0,     0,    -8,     0,     0,     0,     7,
       0,     0,     8,     0,     0,    -8,     9,    -8,    -8,     0,
       0,     0,   926,    10,     0,    11,     0,     0,     0,    12,
     927,     0,     0,     0,     0,     0,   928,     0,     0,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -8,
      -8,     0,    -8,     0,     0,    -8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -8,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,  1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,
    1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,
    1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,
    1507,  1508,  1509,  1510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
      24,    25,    26,    27,    28,     0,    29,     0,     0,     0,
       0,    30,    31,    32,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,    42,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44
};

static const yytype_int16 yycheck[] =
{
       6,   610,   626,   335,    10,   598,   599,   616,  1399,  1237,
     619,   604,   151,   622,   623,   145,   936,   937,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   525,    21,  1239,
     618,    34,   375,    29,    40,  1620,     9,   625,    44,    16,
     376,    62,    62,    62,   136,   154,    62,    46,   138,    64,
     168,   169,    14,   125,   171,   170,   392,   393,   646,   647,
      37,   140,    33,    37,   182,   172,    55,    56,    28,    86,
      54,    88,   172,    35,   170,    37,   287,   590,   591,   592,
     167,    98,   171,   172,   172,    10,    21,   170,   168,   169,
     172,    64,    22,   172,   211,   101,   170,    22,    23,    24,
      89,    72,   182,   235,    37,   213,    20,   113,   170,   172,
      37,  1571,   323,    38,   172,   162,   170,   106,   170,   134,
      91,   236,   211,   170,   335,   214,   215,   172,    16,   170,
      37,   167,    92,   170,   133,   224,   172,   172,   109,   110,
     236,     0,   172,   170,   133,   144,   145,   162,   110,    37,
     172,   172,   172,   171,   131,   170,   172,    64,   172,    37,
      50,   460,   122,   134,   141,   464,    96,   172,   172,   172,
     167,    96,   134,    54,    64,   456,   160,   172,   357,   460,
     172,   172,   172,   464,   172,   517,   103,   112,  1690,   236,
       6,   172,   109,   172,   257,   236,   167,   172,    37,   257,
     213,   171,    37,   209,   172,   211,   172,   213,   214,   215,
     216,   217,   218,   219,   172,   221,   211,   223,   224,   225,
     134,   236,   228,   172,   230,   172,   232,   233,   172,   235,
     190,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   172,   426,   254,   581,
     256,   257,   258,   172,   260,   261,   262,   263,   264,   172,
     296,  1721,   235,   269,   142,   271,   240,   354,   611,   612,
     203,   482,   278,    10,   485,   788,   789,   237,   212,   160,
     623,   617,   216,   217,    59,   216,   217,   623,   222,   223,
     125,   222,   223,  1005,  1522,   111,  1798,  1009,   796,   296,
     235,   213,   308,    64,   216,   217,   172,   237,    84,   271,
     222,   223,   237,    50,  1524,  1525,  1236,   316,  1238,   325,
     531,   327,   249,   250,   100,   415,   299,   417,   460,   401,
      37,   213,   422,   460,   216,   217,   218,   219,   220,   221,
     222,   223,   460,   172,   461,   460,   456,   455,   456,   457,
     458,   460,   462,   443,   461,   462,   464,  1859,   197,   198,
     366,   461,   462,   298,   460,   172,   455,   356,   460,   375,
     460,   377,   461,   461,   347,   170,   448,   460,   460,   350,
     460,   460,   461,   292,   293,   294,   460,   170,   407,  1013,
     396,   397,   398,   353,   400,   401,   402,   403,   460,   324,
     406,   394,   172,   461,   419,  1990,   460,   424,   460,   170,
     416,   417,   418,   428,   429,   460,   412,  1026,  1027,  1028,
    1029,   405,   406,   460,   349,   460,   939,   433,   257,  2014,
     460,   430,  1642,   460,   440,   441,    39,   443,   460,   445,
     461,   461,   448,   456,   450,   461,   460,   586,   425,   411,
     225,   464,   189,  1844,   229,   460,   462,  1045,   461,   452,
     455,  1689,  1050,   469,   437,   438,   461,   170,   460,   461,
     460,   444,   460,   461,   480,   236,    29,   483,  1688,   460,
     461,   460,   461,   170,    48,   460,    16,   257,    18,   124,
    1410,    48,   460,   461,   460,   216,   217,   216,   217,   460,
      64,   222,   460,   222,   223,   460,    36,    64,   514,   515,
     113,   460,    56,   460,     5,   170,   460,    64,    48,   460,
      50,    51,   170,   529,   530,   170,   532,   533,   534,   535,
     464,   462,   170,   236,   460,   541,    66,   172,   232,   233,
     234,   460,   249,   250,   170,    89,   110,   460,   170,  1940,
      97,   170,   464,   110,    84,    46,   103,    60,    88,    37,
     771,   445,   109,  1221,   448,  1223,   450,  1795,   460,  1779,
     100,    11,    12,  1964,   456,   269,   106,   170,   584,    82,
      83,   463,   464,   465,   466,   460,    64,   593,   460,   153,
     460,    14,   460,   137,   805,   139,   153,   460,  1989,   163,
     130,   131,   132,    26,   610,   611,   612,    30,    93,    94,
     616,   141,   460,   619,    37,   162,   622,   623,   148,    97,
     167,   112,  1850,    93,    94,   103,   460,   216,   217,   460,
     636,   109,  1130,   222,   223,   641,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   318,   319,   998,   999,  1000,  1001,    93,
      94,   791,   460,  2054,   460,   105,  1579,   107,  1581,  1582,
     170,  1007,   236,  2064,   170,   681,   460,  1020,  1021,   236,
     460,   687,  1025,   106,   162,   130,   460,   110,   460,   167,
      46,   455,   456,   457,   458,  1031,  1032,  1033,   462,    55,
      56,  1294,  1295,   170,   171,   172,   236,   399,   400,   715,
     460,   151,   152,  1322,   455,   456,   457,   458,   929,   460,
     170,   171,   172,   464,   147,   936,   937,   938,    64,   940,
     281,   282,   283,    89,   267,   268,   266,   455,   456,   457,
     458,   460,   165,   749,    67,   464,   168,   169,   754,   755,
     460,   757,   197,   198,   199,   200,   201,   202,   170,   171,
     172,   463,   768,   208,   209,   210,  1212,  1213,   249,   250,
    1216,  1217,  1218,  1219,   249,   250,  1222,   783,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,   315,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   809,   810,   463,   812,   170,   171,   172,
     168,   169,   818,  1145,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     463,  1163,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   281,   282,
     283,   460,   858,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   170,
     171,   172,   295,   879,   404,   881,   461,   462,  1089,   885,
     886,   460,   461,   889,   460,   891,   892,   170,   171,   172,
     896,   897,   898,   899,   900,   901,   902,   460,  1230,   905,
     460,   907,   908,   457,   458,   463,   912,   913,   463,   915,
     916,   216,   217,   461,   462,    99,  1127,    73,   461,   462,
     351,   352,   157,   418,   460,   461,    74,    85,    78,   935,
     166,   297,   216,   217,   218,   219,   220,   221,   222,   223,
     946,   947,   948,   949,   172,    25,   952,   953,   954,   955,
     292,   172,   446,   461,   460,   961,    37,   170,  1582,   134,
     170,    61,   170,   170,   170,    64,    37,   460,   170,   170,
    1313,   977,    37,   414,   980,   981,   231,   983,   984,  1322,
     170,   172,   170,  1319,   460,   170,  1322,   460,   460,   460,
     167,   460,   998,   999,  1000,  1001,   460,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   460,  1020,  1021,   460,  1228,   460,  1025,
    1026,  1027,  1028,  1029,   460,  1236,   461,  1238,   460,  1240,
    1241,  1242,   460,   460,   460,   460,   460,  1043,   354,   460,
     460,   460,  1048,   460,   460,   460,   460,   213,   398,   460,
     216,   217,   218,   219,   220,   221,   222,   223,   460,   460,
     460,   460,   460,   460,   216,   217,   218,   219,   220,   221,
     222,   223,   460,  1079,   460,   461,   460,   460,   216,   217,
     218,   219,   220,   221,   222,   223,   460,   460,   442,   460,
     460,   170,   170,   460,   170,  1101,   170,    37,   460,   460,
    1106,   460,  1108,   170,    37,   460,     7,  1113,   216,   217,
     218,   219,   220,   221,   222,   223,    17,   170,    58,   460,
     460,  1730,   460,   170,    64,    13,   349,    67,    68,   460,
      31,   170,   170,  1139,  1140,   170,   460,   170,   460,   170,
     460,    81,   460,    13,   170,   460,   460,   460,   460,   460,
     460,    52,   460,   407,    37,   170,   460,   170,   170,   170,
     100,   170,   170,   170,   170,   170,   170,   460,  1174,   460,
    1381,   455,   456,   457,   458,  1181,   461,   295,   462,   463,
     460,   465,   466,   460,  1516,   460,   460,     9,   460,   460,
     460,   460,    14,    15,   460,   172,   461,   460,   460,  1410,
    1411,   461,   460,  1209,   461,   106,   313,   460,   460,   460,
     460,    33,   460,    35,   460,    37,   167,   167,   167,   460,
     460,   167,   162,   163,    13,   170,   460,   460,   129,   460,
     460,    53,   149,   460,   460,   460,   460,   172,   460,   170,
     460,  1247,  1248,  1249,  1250,   460,  1252,  1253,  1254,  1255,
     170,   460,   170,   172,   170,  1261,   460,  1263,  1264,   172,
     460,   172,   172,   172,    86,  1271,   172,   172,   172,   148,
    1276,   170,   206,   460,   171,   461,   171,   460,   171,   101,
     460,   460,   226,  1289,   460,   170,   460,   460,   110,   455,
     456,   457,   458,   460,   170,   460,   244,   463,   464,   465,
     466,   460,   462,   460,   456,   248,   128,  1313,   461,   172,
     462,   463,   134,   465,   466,  1526,  1322,   455,   456,   457,
     458,   143,   461,   460,   460,   463,   460,   465,   466,   167,
     134,   403,   402,   155,   462,   170,   460,   460,   460,   460,
     460,   460,  1348,   460,   460,   167,   460,  1353,   456,   460,
     460,  1357,   170,   170,  1360,   463,   460,   465,   466,   460,
    1366,  1367,  1368,  1369,  1370,  1371,   460,   170,  1374,   460,
     460,   170,   460,   460,   460,   460,   460,   460,   460,   170,
      64,    64,   170,   460,  1390,  1728,  1392,   460,   171,   170,
    1396,  1397,   460,  1729,   460,   170,   460,   460,   460,   460,
    1406,   460,  1408,   170,   460,   460,   460,   156,   460,    34,
      34,    34,    34,   170,   236,   202,   170,   170,    37,   212,
     456,   171,   235,   170,   172,   449,   460,   398,   460,  1640,
     460,   460,  1438,   460,   256,   460,   258,   460,   460,  1445,
     460,   460,   460,   398,   167,    34,   460,   450,   170,   271,
     460,    37,   207,   226,   170,   170,  1462,   251,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   290,   291,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   460,   460,   441,
     204,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   172,   348,   251,   350,   170,
     460,   460,   460,   460,   460,   460,   358,   359,   360,   460,
    1546,   398,   235,   398,   109,   460,  1552,    34,   460,   445,
     170,  1557,   460,  1559,  1560,  1561,  1562,   460,   460,   170,
     460,   170,   460,   226,   138,   138,  1572,   138,   462,   460,
    1781,   460,   138,   395,   396,   397,   460,   213,  1584,  1585,
     460,   462,   460,   460,   354,   407,   408,   409,   410,   411,
     462,   460,   460,   460,  1600,   460,   398,  1603,   420,   134,
     167,   423,   431,    13,  1610,   167,   460,   460,   460,   460,
     432,   433,   434,   435,   436,  1621,   460,   462,  1624,   460,
    1626,  1627,   136,   460,  1835,   444,   460,  1633,  1634,  1635,
    1636,  1637,   460,   228,   460,  1641,   460,   460,   439,   416,
    1851,    13,   159,  1649,   460,   460,   460,   447,   460,   134,
      37,   134,    39,    40,    41,    42,    43,   398,   440,   138,
      64,    64,    49,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   460,   460,   460,   252,   247,
    1706,  1707,  1708,  1709,   235,   172,   228,   167,   170,   460,
    1716,   138,   398,   172,   460,   167,   170,   460,   398,   170,
     170,   167,  1728,   460,  1730,  1731,   113,   114,   115,    25,
    1736,   118,   119,  1739,   124,   403,   170,   451,   134,   460,
     460,   460,  1748,  1749,  1750,  1751,   350,   460,   460,   460,
     460,   460,   170,   460,   460,   460,   460,  1841,   266,   701,
    1758,  1847,  1358,   150,  1834,  1971,  1361,  1996,   294,   156,
     496,   678,   868,  1080,   519,   994,  1128,   994,  1231,  1460,
     943,  1233,  1981,  1852,  1790,  1791,  1265,  1793,   779,  1800,
    1558,   152,  1073,   643,  1336,  1740,   638,  1803,  1804,  1805,
    1806,  1807,  1808,  1809,   873,  1737,    -1,    -1,    -1,    -1,
      -1,    -1,   791,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,    -1,  1828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1836,    -1,    -1,  1839,    -1,    -1,  1842,  1843,    -1,  1845,
     227,   228,    -1,   230,    -1,    -1,    -1,  1853,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1866,  1867,    -1,  1869,    -1,    -1,    -1,    -1,    -1,  1875,
      -1,    -1,    -1,    -1,  1880,  1881,    -1,    -1,    -1,    -1,
      -1,  1887,    -1,  1889,    -1,    -1,    -1,    -1,    -1,  1895,
      -1,    -1,   279,   280,    -1,    -1,  1902,   284,   285,   286,
     287,   288,   289,  1909,    -1,    -1,  1912,    -1,    -1,    -1,
      -1,  1917,  1918,  1919,    -1,    -1,    -1,    -1,    -1,    -1,
    1926,    -1,    -1,  1929,    -1,    -1,  1932,    -1,    -1,    -1,
    1936,    -1,  1938,    -1,    -1,    -1,  1942,    -1,    -1,    -1,
    1946,    -1,    -1,    -1,  1950,  1951,    -1,    -1,    -1,    -1,
    1956,  1957,  1958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1968,  1969,    -1,    -1,    -1,    -1,    -1,  1975,
    1976,  1977,    -1,    -1,    -1,    -1,    -1,    -1,  1984,    -1,
    1986,  1987,  1988,    -1,    -1,    -1,  1992,  1993,    -1,    -1,
      -1,    -1,    -1,    -1,  2000,  2001,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2012,    -1,    -1,    -1,
      -1,    -1,  2018,    -1,    -1,  2021,    -1,    -1,    -1,  2025,
      -1,    -1,  2028,  2029,  2030,    -1,    -1,    -1,    -1,    -1,
    2036,  2037,    -1,    -1,    -1,    -1,  2042,    -1,    -1,  2045,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,  2055,
      -1,    -1,    -1,    -1,    -1,    -1,    27,  2063,    -1,  2065,
    2066,    -1,    33,    -1,  2070,    -1,    37,  2073,  2074,  2075,
    2076,    -1,    -1,    44,    45,  2081,  2082,    48,  2084,    -1,
    2086,  2087,    -1,  2089,  2090,    -1,    57,    -1,  2094,    -1,
      -1,    -1,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,   106,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,
     161,    -1,    -1,   164,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
     261,   262,   263,   264,   265,   130,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   325,   326,   327,   328,   329,   330,
     331,   332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,     8,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      32,    -1,    -1,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,    -1,   248,    -1,    -1,    -1,    -1,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    61,
      -1,    -1,    64,    -1,    -1,   270,    68,   272,   273,    -1,
      -1,    -1,   413,    75,    -1,    77,    -1,    -1,    -1,    81,
     421,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,   301,   302,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
     315,    -1,   317,    -1,    -1,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     355,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,   163,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
     242,   243,   244,   245,   246,    -1,   248,    -1,    -1,    -1,
      -1,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
     272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   314,   315,    -1,   317,    -1,    -1,   320,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   355
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,   468,   474,     0,     8,    32,    61,    64,    68,
      75,    77,    81,   130,   134,   157,   162,   163,   208,   209,
     210,   231,   238,   239,   242,   243,   244,   245,   246,   248,
     253,   254,   255,   260,   270,   272,   273,   300,   301,   302,
     314,   315,   317,   320,   355,   469,   472,   473,   476,   477,
     478,   479,   480,   481,   482,   486,   487,   490,   491,   586,
     588,   590,   591,   618,   620,   621,   639,   640,   646,   647,
     654,   655,   656,   677,   678,   694,   696,   809,   811,   829,
     831,   833,   844,   880,   881,   882,   883,   884,   896,   908,
     909,   910,   911,   912,   913,   914,   812,   172,   471,   492,
     697,   471,    93,    94,   657,   679,   619,   834,   835,   836,
     845,   171,   470,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   171,    93,    94,   830,   832,   172,   172,   172,
     471,   460,   318,   319,   483,    84,   100,   484,   471,   488,
     495,   170,   589,    50,    64,   624,   630,   633,   642,   649,
     682,   700,   815,    37,   240,   475,   915,   170,   460,   170,
     170,   471,   460,   460,   170,   170,   170,   170,   170,   170,
     846,   460,   170,   471,   460,   460,   460,   460,   885,   460,
     460,   460,   460,   460,   460,   170,   170,   460,   460,   460,
     460,   460,    93,    94,   485,   235,   460,    14,    26,    30,
      37,   106,   110,   147,   165,   295,   489,     9,    14,    15,
      33,    35,    37,    53,    86,   101,   110,   128,   134,   143,
     155,   167,   236,   256,   258,   271,   290,   291,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   348,   350,   358,   359,   360,   395,   396,   397,
     407,   408,   409,   410,   411,   420,   423,   432,   433,   434,
     435,   436,   493,   496,    29,   412,    48,    64,   110,   153,
     163,   236,   592,   599,   600,   602,   606,   607,   610,   611,
      29,   623,   634,   630,   631,   635,    37,   125,   641,   643,
     644,    37,   142,   648,   650,   653,    16,    37,   131,   141,
     425,   680,   683,   684,   685,   688,    16,    18,    36,    50,
      51,    66,    84,    88,   100,   106,   130,   131,   132,   141,
     148,   236,   266,   315,   404,   607,   695,   701,   704,   708,
     713,   714,   715,   716,   717,   718,   719,   720,   722,   724,
     725,   727,   728,   729,   777,   778,   779,   786,   788,   789,
     130,   197,   198,   199,   200,   201,   202,   726,   810,   816,
     822,   833,    67,   460,   658,   463,   463,   463,    37,    58,
      64,    67,    68,    81,   100,   162,   163,   847,   460,   460,
     897,   460,   463,   463,   460,   587,    99,    73,   418,   157,
      74,    85,    78,   166,   297,   172,    25,   471,    54,   160,
     405,   406,   574,   471,   494,   471,   471,   471,   124,   471,
     471,   471,   471,    28,    92,   122,   190,   237,   353,   573,
     471,   501,   257,   461,   471,   471,   471,   292,   293,   294,
     553,   292,   471,   507,   471,   508,   471,   471,   510,   471,
     511,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   513,   399,   400,   537,
     471,   172,   471,   471,   471,   446,   519,   471,   471,   471,
     471,   471,   522,   537,   497,   461,   471,   460,   471,   608,
     612,   471,   593,   603,    37,   616,   601,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   460,   461,   471,   609,   693,   613,   622,
     170,   170,   236,   590,   625,   626,   627,   632,    33,    72,
      91,   109,   110,   134,   167,   350,   636,   134,   170,    61,
     170,   651,    22,    96,   237,   681,   471,   686,   689,    10,
      22,    23,    24,    38,    96,   112,   237,   324,   349,   709,
     787,   721,   170,   170,   723,   693,   730,   471,   471,    10,
      50,   189,   705,   702,   267,   268,   460,    64,   781,   460,
     609,   693,    37,   698,   170,   768,   733,    37,    64,    97,
     103,   109,   162,   167,   754,   755,   764,   791,   818,   819,
     820,   170,   821,   471,   817,    37,   813,   823,   414,   661,
     211,   455,   461,   471,   840,   171,   211,   461,   842,   211,
     214,   215,   224,   461,   840,   841,   842,   231,   849,   854,
     848,   851,   855,   850,   852,   853,   249,   250,   899,   900,
     901,   249,   250,   887,   888,   889,   842,   842,   170,   471,
     471,   471,   471,   471,   471,   471,   172,   460,   257,   471,
     460,   460,   460,   170,   460,   460,   471,   460,   471,   257,
     471,   460,   460,   499,   460,   460,   460,   170,   565,   566,
     461,   471,   460,   460,   460,   471,   502,   167,   296,   471,
     460,   257,   471,   548,   460,   548,   509,   460,   548,   460,
     548,   512,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   471,   460,   460,   167,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   576,   471,
     460,   516,   518,   460,   354,   398,    21,   394,   452,   527,
     460,   460,   460,   460,   471,   460,   693,   761,   471,   442,
     523,   693,   460,   460,   170,   170,   460,   170,   170,   604,
     605,   617,   602,   471,   471,   460,   460,   609,   103,   109,
     614,   624,   460,   170,   171,   172,   628,   170,    37,   637,
     627,    54,   160,   471,   471,   693,   471,   471,   471,   471,
     170,   460,   471,   652,   460,   460,   460,   170,    13,   168,
     169,   182,   460,   687,   690,   357,   426,    46,   133,   144,
     145,   316,   430,   711,   349,    11,    12,   105,   107,   151,
     152,   712,    55,    56,    89,   106,   133,   356,   710,   460,
     170,   170,   170,   460,   170,   460,   170,   460,    13,   460,
     460,   460,   168,   169,   182,   460,   706,   170,   703,   707,
     460,   460,   782,   780,   460,   460,   609,   699,   460,   471,
     460,    14,    27,    33,    37,    44,    45,    57,    63,    65,
      66,    70,    71,    76,    90,   104,   106,   108,   110,   116,
     117,   120,   121,   126,   127,   146,   158,   161,   164,   236,
     250,   259,   261,   262,   263,   264,   265,   325,   326,   327,
     328,   329,   330,   331,   332,   348,   413,   421,   427,   607,
     731,   734,   748,   749,   756,   407,   645,   645,   645,    62,
     645,   471,    37,   758,    37,    39,    40,    41,    42,    43,
      49,   113,   114,   115,   118,   119,   150,   156,   205,   206,
     207,   227,   228,   230,   279,   280,   284,   285,   286,   287,
     288,   289,   790,   792,   796,   797,   805,   170,   768,   768,
     168,   169,   769,   168,   169,   776,   827,   768,   814,    37,
     197,   198,   824,   460,   662,   841,   840,   840,   455,   456,
     457,   458,   460,   464,   837,   841,   842,   456,   837,   841,
     841,   840,   841,   842,   216,   217,   218,   219,   220,   221,
     222,   223,   463,   465,   466,   843,   216,   217,   222,   223,
     837,   222,   223,   843,   170,   170,   170,   170,   170,   170,
     170,   170,   471,   902,    37,   898,   900,   471,   890,    37,
     886,   888,   837,   837,   170,   460,   460,   460,   460,   460,
     460,   460,   460,   461,   460,   460,   460,   461,   460,   125,
     401,   448,   865,   866,   170,   171,   172,   460,   566,   461,
     567,   568,   471,   460,   295,   554,   471,   172,   460,   461,
     460,   460,   313,   552,   460,   460,   552,   460,   471,   460,
     471,   167,   575,   545,   471,   471,   167,   471,   167,   460,
     460,   763,   471,   167,   524,   693,   460,   460,   170,   171,
     172,   460,   605,   170,   471,   460,   645,   645,   625,   627,
     629,   460,   638,   460,   460,   460,   460,   693,   460,    13,
     149,   471,   471,   471,   471,   170,   460,   691,   460,   460,
     460,   460,   471,   170,   171,   172,   460,   707,   170,    37,
     781,   460,   170,   471,   471,     6,   111,    46,    55,    56,
      89,   732,   471,   471,   739,   170,   471,   735,   471,   471,
     736,   737,   471,   471,   471,   471,   471,   471,   471,    56,
      89,   137,   139,   752,     5,    46,   112,   753,   471,     7,
      17,    31,    52,   106,   129,   751,   471,   471,   740,   738,
     170,   471,   471,   172,   471,   471,   172,   172,   172,   172,
     172,   172,   172,   172,   741,   744,   742,   743,   140,   460,
     693,    16,    37,   750,   170,   471,    62,   761,    62,   761,
      62,   693,   645,   693,   460,   755,   148,   471,   471,   471,
     471,   793,   471,   471,   471,   471,   794,    60,    82,    83,
     806,   206,   471,   803,   461,   801,   802,   460,   171,   171,
     171,   226,   281,   282,   283,   798,    59,   225,   229,   800,
     460,   460,   471,   471,   460,   471,   471,   460,    37,   203,
     828,   460,   170,   170,   825,   826,    64,   170,   236,   419,
     428,   429,   588,   639,   659,   663,   664,   665,   666,   667,
     670,   212,   464,   838,   462,   840,   840,   840,   840,   838,
     462,   842,   838,   462,   840,   840,   840,   841,   841,   841,
     841,   842,   842,   842,   232,   233,   234,   269,   856,   856,
     856,   856,   856,   856,   856,   856,   460,   471,   903,   244,
     837,   460,   471,   891,   248,   837,   460,   461,   569,   570,
     461,   571,   572,   867,     9,    64,   235,   299,   347,   437,
     438,   444,   868,   865,   471,   462,   568,   462,   172,   505,
     503,   693,   460,   460,   517,   520,   471,   460,   138,   415,
     417,   422,   443,   460,   546,   547,   167,   134,   471,   528,
     471,   460,   693,   762,   521,   471,   403,   514,   402,   462,
     615,   693,   637,   460,   627,   170,   460,   471,   471,   460,
     136,   460,   460,   609,   460,   460,   609,   460,   460,   460,
     460,   460,   460,   154,   460,   170,   460,   460,   471,   170,
     460,   170,   460,   460,   170,   471,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   170,
     746,   747,   471,   460,    64,   876,   876,   876,   460,   460,
     876,   876,   876,   876,    64,   878,   878,   876,   878,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   745,   170,   171,   170,   460,   693,   460,   609,   709,
     754,   757,   761,   763,   761,   762,   693,   693,   693,   765,
     471,   471,   471,   471,   170,   807,   471,   471,   471,   471,
     170,   808,   460,   471,   460,   471,   471,   460,   802,   460,
     460,   460,   471,   281,   282,   283,   799,   471,   156,    34,
      34,    34,    34,   202,   471,   768,   768,   671,   170,   171,
     172,   668,   170,   170,   170,    37,   660,   212,   840,   842,
     840,   841,   842,   171,   235,   862,   862,   170,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   471,   460,   471,
     471,   462,   570,   471,   462,   572,   449,   861,   172,   869,
     471,   471,   471,   471,   471,   471,   460,   471,   460,   460,
     555,   563,   564,   693,   398,   542,   167,   354,   538,   471,
     471,   471,   471,   398,   563,   450,   583,   167,   541,   471,
     550,   471,   761,   693,   460,   460,   460,   692,   783,    34,
     460,   471,   460,   460,   460,   471,   170,   171,   172,   460,
     747,   471,   877,   460,   460,   460,   460,   460,   460,   460,
     879,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     609,   460,   460,    37,   441,   759,   763,   460,   762,   762,
     693,   460,   766,   170,   460,   460,   460,   460,   170,   460,
     460,   460,   460,   460,   170,   460,   207,   471,   471,   226,
     471,   806,   471,   471,   471,   471,   204,   460,   460,   170,
     667,   669,   471,   460,   460,   170,   213,   464,   839,   839,
     839,   471,   471,   864,   172,   863,   251,   904,   905,   251,
     892,   893,   471,   460,   471,   460,   170,   471,   235,   398,
     398,   445,   462,   564,   460,   471,   172,   460,   549,   471,
     351,   352,   543,   471,   471,   460,   460,   500,   471,   529,
     471,   471,   471,   460,   498,   462,   551,   693,   471,   762,
     460,   109,   785,   471,   460,   460,   460,   170,   170,   460,
      20,   134,   760,    34,   767,   762,   763,   767,   170,   460,
     471,   471,   471,   471,   795,   226,   138,   138,   138,   138,
     471,   672,   460,   667,   460,   213,   840,   842,   841,   471,
     471,   905,   471,   893,   462,   462,   870,   872,   471,   471,
     471,   471,   460,   506,   504,   550,   354,   544,   539,   398,
     535,   536,   134,   167,   532,   431,   525,   526,   460,   460,
     762,   693,   784,    13,   471,   471,   460,   471,   460,   763,
     460,   460,   767,   805,   462,   460,   471,   471,   804,   471,
     471,   471,   471,   471,   460,   167,   460,   460,   136,   874,
      21,   235,   298,   857,   471,   871,   873,   444,   556,   228,
     561,   561,   462,   471,   460,   439,   540,   471,   460,   535,
     471,   471,   563,   471,   460,   525,   515,   416,   763,   693,
     785,   471,    13,   767,   460,   460,   471,   471,   159,   471,
     770,   772,   471,   906,   894,   471,   471,   440,   875,   447,
     858,   471,   167,   296,   558,   471,   398,   471,   134,   534,
     530,   533,   134,   594,   460,   471,   138,   471,   460,   460,
     471,   471,   471,    64,    64,   460,   252,   247,   235,   471,
     471,   471,   172,   228,   562,   471,   471,   584,   563,   167,
     580,   581,   471,   170,   460,   471,   138,   471,   471,   460,
     771,   773,   673,   471,   907,   471,   895,   471,   398,   560,
     559,   172,   563,   167,   585,   531,   471,   580,   170,   471,
     471,   471,   460,   774,   774,   675,   460,   471,   460,   471,
     471,   471,   563,   564,   557,   460,   471,   577,   583,   170,
     471,   471,   170,   775,    14,    35,    37,   110,   134,   271,
     411,   676,   859,   460,   460,   564,   398,   167,   578,   471,
     460,   471,    25,   471,   674,   124,   471,   471,   471,   451,
     860,   460,   471,   471,   582,   403,   471,   460,   170,   471,
     460,   460,   460,   134,   579,   563,   471,   460,   460,   471,
     563,   471,   460,   350,   471,   471,   471,   471,   460,   595,
     596,    86,    88,    98,   424,   597,   471,   471,   598,   471,
     471,   471,   170,   471,   471,   460,   460,   460,   471,   460
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   467,   468,   470,   469,   471,   472,   473,   474,   474,
     474,   475,   475,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   477,   477,   478,   478,   479,   480,   481,   482,
     483,   483,   484,   484,   485,   485,   486,   487,   488,   488,
     489,   489,   489,   489,   489,   489,   489,   489,   490,   492,
     491,   494,   493,   495,   495,   497,   498,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     499,   496,   500,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   501,
     496,   502,   496,   496,   496,   503,   504,   496,   505,   506,
     496,   496,   507,   496,   496,   508,   496,   509,   496,   496,
     510,   496,   496,   511,   496,   512,   496,   513,   496,   496,
     496,   496,   514,   515,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     516,   496,   517,   496,   518,   496,   496,   519,   496,   520,
     496,   521,   496,   496,   496,   522,   496,   523,   523,   524,
     524,   525,   525,   526,   528,   529,   530,   531,   527,   532,
     533,   527,   534,   527,   535,   535,   536,   537,   537,   537,
     538,   539,   538,   538,   540,   540,   541,   541,   542,   542,
     543,   543,   543,   544,   544,   545,   545,   546,   546,   546,
     547,   547,   547,   548,   549,   548,   550,   550,   551,   552,
     552,   553,   553,   553,   555,   556,   557,   554,   558,   559,
     558,   560,   558,   562,   561,   563,   563,   564,   564,   565,
     565,   566,   566,   566,   567,   567,   568,   569,   569,   570,
     571,   571,   572,   573,   573,   573,   573,   573,   573,   574,
     574,   574,   574,   575,   575,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   577,   577,   579,
     578,   580,   580,   582,   581,   583,   583,   584,   584,   585,
     586,   587,   586,   589,   588,   590,   591,   591,   591,   593,
     594,   595,   592,   596,   596,   597,   597,   597,   598,   597,
     599,   599,   600,   601,   601,   602,   602,   602,   603,   602,
     602,   604,   604,   605,   605,   605,   606,   606,   606,   606,
     608,   607,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   610,   612,
     611,   613,   613,   614,   615,   614,   617,   616,   619,   618,
     620,   622,   621,   623,   623,   624,   624,   625,   625,   626,
     626,   628,   627,   629,   629,   627,   627,   627,   630,   631,
     631,   632,   634,   633,   635,   635,   636,   636,   636,   636,
     636,   636,   636,   636,   636,   638,   637,   639,   640,   641,
     642,   642,   643,   643,   644,   645,   645,   646,   647,   648,
     649,   649,   650,   651,   651,   652,   653,   654,   655,   657,
     658,   659,   656,   660,   660,   661,   661,   662,   662,   663,
     663,   663,   663,   663,   663,   663,   664,   665,   666,   668,
     667,   669,   669,   667,   667,   667,   671,   672,   673,   674,
     670,   675,   675,   676,   676,   676,   676,   676,   676,   677,
     679,   678,   681,   680,   682,   682,   683,   683,   683,   683,
     684,   684,   684,   685,   686,   686,   687,   687,   687,   689,
     688,   690,   690,   692,   691,   693,   693,   695,   694,   697,
     696,   699,   698,   700,   700,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   702,   701,   703,   703,   704,
     705,   705,   706,   706,   706,   707,   707,   707,   708,   709,
     709,   709,   709,   709,   709,   709,   709,   709,   709,   709,
     709,   709,   709,   709,   710,   710,   710,   710,   710,   710,
     711,   711,   711,   711,   711,   711,   712,   712,   712,   712,
     712,   712,   713,   714,   715,   715,   715,   716,   717,   718,
     718,   718,   718,   719,   721,   720,   723,   722,   724,   724,
     725,   726,   727,   728,   730,   729,   732,   731,   733,   733,
     734,   734,   734,   734,   734,   734,   735,   734,   734,   734,
     734,   734,   734,   734,   734,   734,   734,   734,   734,   734,
     734,   736,   734,   737,   734,   738,   734,   739,   734,   734,
     734,   734,   734,   734,   734,   734,   734,   734,   734,   734,
     740,   734,   734,   734,   734,   734,   734,   734,   734,   734,
     734,   734,   734,   734,   734,   734,   734,   741,   734,   742,
     734,   743,   734,   744,   734,   745,   745,   745,   745,   745,
     745,   745,   745,   745,   745,   745,   745,   745,   745,   745,
     745,   745,   745,   745,   745,   745,   745,   745,   745,   745,
     745,   745,   745,   745,   745,   745,   745,   746,   746,   747,
     747,   747,   748,   748,   748,   748,   748,   749,   750,   750,
     751,   751,   751,   751,   751,   751,   752,   752,   752,   752,
     753,   753,   753,   753,   754,   756,   757,   755,   755,   755,
     755,   755,   755,   755,   755,   755,   758,   758,   759,   759,
     760,   760,   760,   761,   762,   763,   763,   765,   764,   766,
     764,   767,   768,   768,   770,   771,   769,   772,   773,   769,
     769,   769,   774,   774,   775,   776,   776,   777,   777,   778,
     779,   780,   780,   782,   783,   781,   784,   784,   785,   787,
     786,   788,   789,   790,   791,   791,   793,   792,   794,   792,
     795,   792,   792,   792,   792,   792,   792,   792,   792,   792,
     792,   792,   792,   792,   792,   792,   792,   792,   792,   792,
     792,   796,   796,   796,   797,   797,   797,   797,   798,   798,
     798,   799,   799,   799,   800,   800,   801,   801,   802,   803,
     803,   804,   804,   804,   805,   805,   806,   806,   806,   807,
     807,   808,   808,   810,   809,   812,   811,   814,   813,   815,
     815,   817,   816,   818,   816,   819,   816,   820,   816,   816,
     821,   816,   816,   816,   822,   823,   823,   825,   824,   826,
     824,   827,   827,   828,   830,   829,   832,   831,   834,   833,
     835,   833,   836,   833,   837,   837,   837,   838,   838,   839,
     839,   840,   840,   840,   840,   840,   840,   840,   840,   841,
     841,   841,   841,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   842,   842,   842,   842,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   845,   844,   846,
     846,   848,   847,   849,   847,   850,   847,   851,   847,   852,
     847,   853,   847,   854,   847,   855,   847,   856,   856,   856,
     856,   856,   857,   857,   857,   857,   857,   858,   859,   858,
     860,   860,   861,   861,   862,   862,   863,   863,   864,   864,
     865,   865,   866,   867,   866,   866,   868,   869,   870,   868,
     871,   868,   868,   872,   868,   868,   868,   873,   868,   868,
     868,   874,   874,   875,   875,   876,   877,   876,   879,   878,
     880,   881,   882,   883,   885,   884,   886,   887,   887,   888,
     888,   890,   889,   891,   891,   892,   892,   894,   893,   895,
     895,   897,   896,   898,   899,   899,   900,   900,   902,   901,
     903,   903,   904,   904,   906,   905,   907,   907,   908,   909,
     910,   911,   912,   913,   914,   914,   915
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     4,     1,     3,     3,     0,     2,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     4,     1,     0,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     0,
       3,     0,     3,     0,     2,     0,     0,     9,     3,     3,
       3,     4,     3,     4,     3,     4,     3,     3,     3,     3,
       0,     6,     0,     9,     3,     4,     7,     4,     7,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     6,     0,
       4,     0,     4,     4,     4,     0,     0,     9,     0,     0,
       9,     3,     0,     4,     3,     0,     4,     0,     5,     3,
       0,     4,     3,     0,     4,     0,     5,     0,     4,     2,
       3,     3,     0,     0,     9,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       0,     5,     0,     9,     0,     5,     7,     0,     4,     0,
       7,     0,     7,     3,     3,     0,     5,     0,     1,     0,
       2,     0,     2,     4,     0,     0,     0,     0,    11,     0,
       0,     9,     0,     9,     0,     2,     4,     0,     1,     1,
       0,     0,     4,     2,     0,     2,     0,     2,     0,     2,
       0,     1,     1,     0,     4,     0,     2,     1,     2,     2,
       1,     1,     1,     1,     0,     7,     0,     2,     1,     0,
       1,     1,     1,     1,     0,     0,     0,    12,     0,     0,
       5,     0,     5,     0,     5,     0,     2,     0,     2,     1,
       2,     2,     2,     2,     1,     2,     4,     1,     2,     4,
       1,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       4,     0,     2,     0,     6,     0,     2,     0,     2,     6,
       3,     0,     7,     0,     4,     1,     2,     3,     3,     0,
       0,     0,    26,     0,     2,     4,     4,     6,     0,     4,
       1,     1,     2,     0,     2,     1,     1,     3,     0,     4,
       1,     1,     2,     2,     2,     2,     2,     3,     4,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       4,     0,     2,     5,     0,     8,     0,     3,     0,     3,
       5,     0,     7,     0,     1,     1,     2,     0,     1,     1,
       2,     0,     4,     1,     2,     2,     2,     2,     2,     0,
       2,     3,     0,     4,     0,     2,     3,     3,     4,     5,
       4,     5,     3,     3,     3,     0,     3,     3,     1,     2,
       0,     2,     5,     6,     1,     0,     2,     3,     1,     2,
       0,     2,     3,     0,     2,     2,     2,     4,     3,     0,
       0,     0,     8,     1,     2,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     0,
       4,     1,     2,     2,     2,     2,     0,     0,     0,     0,
      12,     0,     2,     3,     3,     4,     4,     3,     3,     3,
       0,     3,     0,     3,     0,     2,     5,     1,     1,     1,
       3,     3,     3,     3,     0,     2,     1,     1,     1,     0,
       4,     0,     2,     0,     3,     2,     4,     0,     4,     0,
       3,     0,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     0,     4,     1,     2,     3,
       0,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     3,     3,     3,     3,     2,
       3,     4,     3,     2,     0,     4,     0,     4,     3,     3,
       1,     1,     5,     3,     0,     3,     0,     3,     0,     2,
       2,     3,     4,     3,     4,     5,     0,     4,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     0,     4,     0,     5,     0,     5,     0,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       0,     4,     4,     2,     4,     4,     4,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     3,     3,     4,     3,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     2,     0,     0,     7,     3,     5,
       7,     5,     7,     7,     9,     1,     0,     2,     0,     1,
       0,     2,     2,     1,     1,     0,     2,     0,     6,     0,
       8,     7,    11,     4,     0,     0,    10,     0,     0,    10,
       6,     6,     0,     2,     1,     6,     6,     3,     2,     1,
       4,     0,     2,     0,     0,     7,     0,     2,     5,     0,
       4,     3,     1,     2,     0,     2,     0,     4,     0,     4,
       0,    10,     9,     3,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     7,     8,     6,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     1,
       2,     0,     4,     7,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     0,     4,     0,     3,     0,     3,     0,
       2,     0,     4,     0,     4,     0,     4,     0,     4,     4,
       0,     4,     5,     1,     2,     0,     2,     0,     4,     0,
       4,     0,     2,     5,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     1,     1,     1,     2,     1,
       2,     3,     3,     3,     3,     2,     3,     6,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     6,     1,     1,     3,     3,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     0,
       2,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     5,     3,     3,     1,
       2,     2,     0,     1,     2,     5,     3,     0,     0,     6,
       0,     1,     0,     1,     0,     3,     0,     1,     0,     1,
       0,     2,     1,     0,     3,     1,     0,     0,     0,     5,
       0,     6,     2,     0,     5,     2,     5,     0,     6,     2,
       6,     0,     1,     0,     1,     0,     0,     3,     0,     3,
       4,     3,     3,     3,     0,     7,     2,     1,     2,     3,
       1,     0,     5,     1,     2,     1,     2,     0,     7,     1,
       2,     0,     7,     2,     1,     2,     3,     1,     0,     5,
       1,     2,     1,     2,     0,     7,     1,     2,     3,     3,
       3,     3,     3,     3,     0,     2,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
  case 2:
#line 343 "lef.y"
      {
        // 11/16/2001 - Wanda da Rosa - pcr 408334
        // Return 1 if there are errors
        if (lefData->lef_errors)
           return 1;
        if (!lefData->hasVer) {
              char temp[300];
              sprintf(temp, "No VERSION statement found, using the default value %2g.", lefData->versionNum);
              lefWarning(2001, temp);            
        }        
        //only pre 5.6, 5.6 it is obsolete
        if (!lefData->hasNameCase && lefData->versionNum < 5.6)
           lefWarning(2002, "NAMESCASESENSITIVE is a required statement on LEF file with version 5.5 and earlier.\nWithout NAMESCASESENSITIVE defined, the LEF file is technically incorrect.\nRefer the LEF/DEF 5.5 or earlier Language Referece manual on how to define this statement.");
        if (!lefData->hasBusBit && lefData->versionNum < 5.6)
           lefWarning(2003, "BUSBITCHARS is a required statement on LEF file with version 5.5 and earlier.\nWithout BUSBITCHARS defined, the LEF file is technically incorrect.\nRefer the LEF/DEF 5.5 or earlier Language Referece manual on how to define this statement.");
        if (!lefData->hasDivChar && lefData->versionNum < 5.6)
           lefWarning(2004, "DIVIDERCHAR is a required statementon LEF file with version 5.5 and earlier.\nWithout DIVIDECHAR defined, the LEF file is technically incorrect.\nRefer the LEF/DEF 5.5 or earlier Language Referece manual on how to define this statement.");

      }
#line 3786 "lef.tab.c"
    break;

  case 3:
#line 363 "lef.y"
                   { lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 3792 "lef.tab.c"
    break;

  case 4:
#line 364 "lef.y"
      { 
		 // More than 1 VERSION in lef file within the open file - It's wrong syntax, 
		 // but copy old behavior - initialize lef reading.
         if (lefData->hasVer)     
         {
			lefData->initRead();
		 }

         lefData->versionNum = convert_name2num((yyvsp[-1].string));
         if (lefData->versionNum > CURRENT_VERSION) {
            char temp[120];
            sprintf(temp,
               "Lef parser %.1f does not support lef file with version %s. Parser will stop processing.", CURRENT_VERSION, (yyvsp[-1].string));
            lefError(1503, temp);
            return 1;
         }

         if (lefCallbacks->VersionStrCbk) {
            CALLBACK(lefCallbacks->VersionStrCbk, lefrVersionStrCbkType, (yyvsp[-1].string));
         } else {
            if (lefCallbacks->VersionCbk)
               CALLBACK(lefCallbacks->VersionCbk, lefrVersionCbkType, lefData->versionNum);
         }
         if (lefData->versionNum > 5.3 && lefData->versionNum < 5.4) {
            lefData->ignoreVersion = 1;
         }
         lefData->use5_3 = lefData->use5_4 = 0;
         lefData->lef_errors = 0;
         lefData->hasVer = 1;
         if (lefData->versionNum < 5.6) {
            lefData->doneLib = 0;
            lefData->namesCaseSensitive = lefSettings->CaseSensitive;
         } else {
            lefData->doneLib = 1;
            lefData->namesCaseSensitive = 1;
         }
      }
#line 3834 "lef.tab.c"
    break;

  case 5:
#line 403 "lef.y"
      {
         // int_number represent 'integer-like' type. It can have fraction and exponent part 
         // but the value shouldn't exceed the 64-bit integer limit. 
         if (!(( yylval.dval >= lefData->leflVal) && ( yylval.dval <= lefData->lefrVal))) { // YES, it isn't really a number 
            char *str = (char*) lefMalloc(strlen(lefData->current_token) + strlen(lefData->lefrFileName) + 350);
            sprintf(str, "ERROR (LEFPARS-203) Number has exceeded the limit for an integer. See file %s at line %d.\n",
                    lefData->lefrFileName, lefData->lef_nlines);
            fflush(stdout);
            lefiError(0, 203, str);
            free(str);
            lefData->lef_errors++;
        }

        (yyval.dval) = yylval.dval ;
      }
#line 3854 "lef.tab.c"
    break;

  case 6:
#line 420 "lef.y"
      {
        if (lefCallbacks->DividerCharCbk) {
          if (strcmp((yyvsp[-1].string), "") != 0) {
             CALLBACK(lefCallbacks->DividerCharCbk, lefrDividerCharCbkType, (yyvsp[-1].string));
          } else {
             CALLBACK(lefCallbacks->DividerCharCbk, lefrDividerCharCbkType, "/");
             lefWarning(2005, "DIVIDERCHAR has an invalid null value. Value is set to default /");
          }
        }
        lefData->hasDivChar = 1;
      }
#line 3870 "lef.tab.c"
    break;

  case 7:
#line 433 "lef.y"
      {
        if (lefCallbacks->BusBitCharsCbk) {
          if (strcmp((yyvsp[-1].string), "") != 0) {
             CALLBACK(lefCallbacks->BusBitCharsCbk, lefrBusBitCharsCbkType, (yyvsp[-1].string)); 
          } else {
             CALLBACK(lefCallbacks->BusBitCharsCbk, lefrBusBitCharsCbkType, "[]"); 
             lefWarning(2006, "BUSBITCHAR has an invalid null value. Value is set to default []");
          }
        }
        lefData->hasBusBit = 1;
      }
#line 3886 "lef.tab.c"
    break;

  case 10:
#line 448 "lef.y"
            { }
#line 3892 "lef.tab.c"
    break;

  case 11:
#line 451 "lef.y"
      {
        if (lefData->versionNum >= 5.6) {
           lefData->doneLib = 1;
           lefData->ge56done = 1;
        }
      }
#line 3903 "lef.tab.c"
    break;

  case 12:
#line 458 "lef.y"
      {
        lefData->doneLib = 1;
        lefData->ge56done = 1;
        if (lefCallbacks->LibraryEndCbk)
          CALLBACK(lefCallbacks->LibraryEndCbk, lefrLibraryEndCbkType, 0);
        // 11/16/2001 - Wanda da Rosa - pcr 408334
        // Return 1 if there are errors
      }
#line 3916 "lef.tab.c"
    break;

  case 52:
#line 482 "lef.y"
          {
            if (lefData->versionNum < 5.6) {
              lefData->namesCaseSensitive = TRUE;
              if (lefCallbacks->CaseSensitiveCbk)
                CALLBACK(lefCallbacks->CaseSensitiveCbk, 
                         lefrCaseSensitiveCbkType,
                         lefData->namesCaseSensitive);
              lefData->hasNameCase = 1;
            } else
              if (lefCallbacks->CaseSensitiveCbk) // write warning only if cbk is set 
                 if (lefData->caseSensitiveWarnings++ < lefSettings->CaseSensitiveWarnings)
                   lefWarning(2007, "NAMESCASESENSITIVE statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
          }
#line 3934 "lef.tab.c"
    break;

  case 53:
#line 496 "lef.y"
          {
            if (lefData->versionNum < 5.6) {
              lefData->namesCaseSensitive = FALSE;
              if (lefCallbacks->CaseSensitiveCbk)
                CALLBACK(lefCallbacks->CaseSensitiveCbk, lefrCaseSensitiveCbkType,
                               lefData->namesCaseSensitive);
              lefData->hasNameCase = 1;
            } else {
              if (lefCallbacks->CaseSensitiveCbk) { // write error only if cbk is set 
                if (lefData->caseSensitiveWarnings++ < lefSettings->CaseSensitiveWarnings) {
                  lefError(1504, "NAMESCASESENSITIVE statement is set with OFF.\nStarting version 5.6, NAMESCASENSITIVE is obsolete,\nif it is defined, it has to have the ON value.\nParser will stop processing.");
                  CHKERR();
                }
              }
            }
          }
#line 3955 "lef.tab.c"
    break;

  case 54:
#line 514 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->NoWireExtensionCbk)
          CALLBACK(lefCallbacks->NoWireExtensionCbk, lefrNoWireExtensionCbkType, "ON");
      } else
        if (lefCallbacks->NoWireExtensionCbk) // write warning only if cbk is set 
           if (lefData->noWireExtensionWarnings++ < lefSettings->NoWireExtensionWarnings)
             lefWarning(2008, "NOWIREEXTENSIONATPIN statement is obsolete in version 5.6 or later.\nThe NOWIREEXTENSIONATPIN statement will be ignored.");
    }
#line 3969 "lef.tab.c"
    break;

  case 55:
#line 524 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->NoWireExtensionCbk)
          CALLBACK(lefCallbacks->NoWireExtensionCbk, lefrNoWireExtensionCbkType, "OFF");
      } else
        if (lefCallbacks->NoWireExtensionCbk) // write warning only if cbk is set 
           if (lefData->noWireExtensionWarnings++ < lefSettings->NoWireExtensionWarnings)
             lefWarning(2008, "NOWIREEXTENSIONATPIN statement is obsolete in version 5.6 or later.\nThe NOWIREEXTENSIONATPIN statement will be ignored.");
    }
#line 3983 "lef.tab.c"
    break;

  case 56:
#line 535 "lef.y"
    { 
       if (lefData->versionNum >= 5.8) {
       
          if (lefCallbacks->FixedMaskCbk) {
            lefData->lefFixedMask = 1;
            CALLBACK(lefCallbacks->FixedMaskCbk, lefrFixedMaskCbkType, lefData->lefFixedMask);
          }
          
          lefData->hasFixedMask = 1;
       }
    }
#line 3999 "lef.tab.c"
    break;

  case 57:
#line 548 "lef.y"
    {
      if (lefCallbacks->ManufacturingCbk)
        CALLBACK(lefCallbacks->ManufacturingCbk, lefrManufacturingCbkType, (yyvsp[-1].dval));
      lefData->hasManufactur = 1;
    }
#line 4009 "lef.tab.c"
    break;

  case 58:
#line 555 "lef.y"
  {
    if ((strcmp((yyvsp[-2].string), "PIN") == 0) && (lefData->versionNum >= 5.6)) {
      if (lefCallbacks->UseMinSpacingCbk) // write warning only if cbk is set 
         if (lefData->useMinSpacingWarnings++ < lefSettings->UseMinSpacingWarnings)
            lefWarning(2009, "USEMINSPACING PIN statement is obsolete in version 5.6 or later.\n The USEMINSPACING PIN statement will be ignored.");
    } else {
        if (lefCallbacks->UseMinSpacingCbk) {
          lefData->lefrUseMinSpacing.set((yyvsp[-2].string), (yyvsp[-1].integer));
          CALLBACK(lefCallbacks->UseMinSpacingCbk, lefrUseMinSpacingCbkType,
                   &lefData->lefrUseMinSpacing);
      }
    }
  }
#line 4027 "lef.tab.c"
    break;

  case 59:
#line 570 "lef.y"
    { CALLBACK(lefCallbacks->ClearanceMeasureCbk, lefrClearanceMeasureCbkType, (yyvsp[-1].string)); }
#line 4033 "lef.tab.c"
    break;

  case 60:
#line 573 "lef.y"
            {(yyval.string) = (char*)"MAXXY";}
#line 4039 "lef.tab.c"
    break;

  case 61:
#line 574 "lef.y"
                  {(yyval.string) = (char*)"EUCLIDEAN";}
#line 4045 "lef.tab.c"
    break;

  case 62:
#line 577 "lef.y"
            {(yyval.string) = (char*)"OBS";}
#line 4051 "lef.tab.c"
    break;

  case 63:
#line 578 "lef.y"
            {(yyval.string) = (char*)"PIN";}
#line 4057 "lef.tab.c"
    break;

  case 64:
#line 581 "lef.y"
            {(yyval.integer) = 1;}
#line 4063 "lef.tab.c"
    break;

  case 65:
#line 582 "lef.y"
            {(yyval.integer) = 0;}
#line 4069 "lef.tab.c"
    break;

  case 66:
#line 585 "lef.y"
    { 
      if (lefCallbacks->UnitsCbk)
        CALLBACK(lefCallbacks->UnitsCbk, lefrUnitsCbkType, &lefData->lefrUnits);
    }
#line 4078 "lef.tab.c"
    break;

  case 67:
#line 591 "lef.y"
    {
      lefData->lefrUnits.clear();
      if (lefData->hasManufactur) {
        if (lefData->unitsWarnings++ < lefSettings->UnitsWarnings) {
          lefError(1505, "MANUFACTURINGGRID statement was defined before UNITS.\nRefer the LEF Language Reference manual for the order of LEF statements.");
          CHKERR();
        }
      }
      if (lefData->hasMinfeature) {
        if (lefData->unitsWarnings++ < lefSettings->UnitsWarnings) {
          lefError(1712, "MINFEATURE statement was defined before UNITS.\nRefer the LEF Language Reference manual for the order of LEF statements.");
          CHKERR();
        }
      }
      if (lefData->versionNum < 5.6) {
        if (lefData->hasSite) {//SITE is defined before UNIT and is illegal in pre 5.6
          lefError(1713, "SITE statement was defined before UNITS.\nRefer the LEF Language Reference manual for the order of LEF statements.");
          CHKERR();
        }
      }
    }
#line 4104 "lef.tab.c"
    break;

  case 70:
#line 618 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setTime((yyvsp[-1].dval)); }
#line 4110 "lef.tab.c"
    break;

  case 71:
#line 620 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setCapacitance((yyvsp[-1].dval)); }
#line 4116 "lef.tab.c"
    break;

  case 72:
#line 622 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setResistance((yyvsp[-1].dval)); }
#line 4122 "lef.tab.c"
    break;

  case 73:
#line 624 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setPower((yyvsp[-1].dval)); }
#line 4128 "lef.tab.c"
    break;

  case 74:
#line 626 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setCurrent((yyvsp[-1].dval)); }
#line 4134 "lef.tab.c"
    break;

  case 75:
#line 628 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setVoltage((yyvsp[-1].dval)); }
#line 4140 "lef.tab.c"
    break;

  case 76:
#line 630 "lef.y"
    { 
      if(validNum((int)(yyvsp[-1].dval))) {
         if (lefCallbacks->UnitsCbk)
            lefData->lefrUnits.setDatabase("MICRONS", (yyvsp[-1].dval));
      }
    }
#line 4151 "lef.tab.c"
    break;

  case 77:
#line 637 "lef.y"
    { if (lefCallbacks->UnitsCbk) lefData->lefrUnits.setFrequency((yyvsp[-1].dval)); }
#line 4157 "lef.tab.c"
    break;

  case 78:
#line 641 "lef.y"
    { 
      if (lefCallbacks->LayerCbk)
        CALLBACK(lefCallbacks->LayerCbk, lefrLayerCbkType, &lefData->lefrLayer);
    }
#line 4166 "lef.tab.c"
    break;

  case 79:
#line 646 "lef.y"
                     {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 4172 "lef.tab.c"
    break;

  case 80:
#line 647 "lef.y"
    { 
      if (lefData->lefrHasMaxVS) {   // 5.5 
        if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
          if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
            lefError(1506, "A MAXVIASTACK statement is defined before the LAYER statement.\nRefer to the LEF Language Reference manual for the order of LEF statements.");
            CHKERR();
          }
        }
      }
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setName((yyvsp[0].string));
      lefData->useLenThr = 0;
      lefData->layerCut = 0;
      lefData->layerMastOver = 0;
      lefData->layerRout = 0;
      lefData->layerDir = 0;
      lefData->lefrHasLayer = 1;
      //strcpy(lefData->layerName, $3);
      lefData->layerName = strdup((yyvsp[0].string));
      lefData->hasType = 0;
      lefData->hasMask = 0;
      lefData->hasPitch = 0;
      lefData->hasWidth = 0;
      lefData->hasDirection = 0;
      lefData->hasParallel = 0;
      lefData->hasInfluence = 0;
      lefData->hasTwoWidths = 0;
      lefData->lefrHasSpacingTbl = 0;
      lefData->lefrHasSpacing = 0;
    }
#line 4207 "lef.tab.c"
    break;

  case 81:
#line 678 "lef.y"
                 {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 4213 "lef.tab.c"
    break;

  case 82:
#line 679 "lef.y"
    { 
      if (strcmp(lefData->layerName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
          if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
             lefData->outMsg = (char*)lefMalloc(10000);
             sprintf (lefData->outMsg,
                "END LAYER name %s is different from the LAYER name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->layerName);
             lefError(1507, lefData->outMsg);
             lefFree(lefData->outMsg);
             lefFree(lefData->layerName);
             CHKERR(); 
          } else
             lefFree(lefData->layerName);
        } else
          lefFree(lefData->layerName);
      } else
        lefFree(lefData->layerName);
      if (!lefSettings->RelaxMode) {
        if (lefData->hasType == 0) {
          if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1508, "TYPE statement is a required statement in a LAYER and it is not defined.");
               CHKERR(); 
            }
          }
        }
        if ((lefData->layerRout == 1) && (lefData->hasPitch == 0)) {
          if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1509, "PITCH statement is a required statement in a LAYER with type ROUTING and it is not defined.");
              CHKERR(); 
            }
          }
        }
        if ((lefData->layerRout == 1) && (lefData->hasWidth == 0)) {
          if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1510, "WIDTH statement is a required statement in a LAYER with type ROUTING and it is not defined.");
              CHKERR(); 
            }
          }
        }
        if ((lefData->layerRout == 1) && (lefData->hasDirection == 0)) {
          if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg, "The DIRECTION statement which is required in a LAYER with TYPE ROUTING is not defined in LAYER %s.\nUpdate your lef file and add the DIRECTION statement for layer %s.", (yyvsp[0].string), (yyvsp[0].string));
              lefError(1511, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR(); 
            }
          }
        }
      }
    }
#line 4273 "lef.tab.c"
    break;

  case 83:
#line 736 "lef.y"
    { }
#line 4279 "lef.tab.c"
    break;

  case 84:
#line 738 "lef.y"
    { }
#line 4285 "lef.tab.c"
    break;

  case 85:
#line 742 "lef.y"
    {
       // let setArraySpacingCutSpacing to set the data 
    }
#line 4293 "lef.tab.c"
    break;

  case 86:
#line 748 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.setArraySpacingCut((yyvsp[0].dval));
         lefData->arrayCutsVal = 0;
      }
    }
#line 4304 "lef.tab.c"
    break;

  case 87:
#line 755 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "ARRAYSPACING is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1685, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      }
    }
#line 4319 "lef.tab.c"
    break;

  case 88:
#line 766 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.setType((yyvsp[-1].string));
      lefData->hasType = 1;
    }
#line 4329 "lef.tab.c"
    break;

  case 89:
#line 772 "lef.y"
    {
      if (lefData->versionNum < 5.8) {
          if (lefData->layerWarnings++ < lefSettings->ViaWarnings) {
              lefError(2081, "MASK information can only be defined with version 5.8");
              CHKERR(); 
          }           
      } else {
          if (lefCallbacks->LayerCbk) {
            lefData->lefrLayer.setMask((int)(yyvsp[-1].dval));
          }
          
          lefData->hasMask = 1;
      }
    }
#line 4348 "lef.tab.c"
    break;

  case 90:
#line 787 "lef.y"
    { 
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setPitch((yyvsp[-1].dval));
      lefData->hasPitch = 1;  
    }
#line 4357 "lef.tab.c"
    break;

  case 91:
#line 792 "lef.y"
    { 
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setPitchXY((yyvsp[-2].dval), (yyvsp[-1].dval));
      lefData->hasPitch = 1;  
    }
#line 4366 "lef.tab.c"
    break;

  case 92:
#line 797 "lef.y"
    { 
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDiagPitch((yyvsp[-1].dval));
    }
#line 4374 "lef.tab.c"
    break;

  case 93:
#line 801 "lef.y"
    { 
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDiagPitchXY((yyvsp[-2].dval), (yyvsp[-1].dval));
    }
#line 4382 "lef.tab.c"
    break;

  case 94:
#line 805 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setOffset((yyvsp[-1].dval));
    }
#line 4390 "lef.tab.c"
    break;

  case 95:
#line 809 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setOffsetXY((yyvsp[-2].dval), (yyvsp[-1].dval));
    }
#line 4398 "lef.tab.c"
    break;

  case 96:
#line 813 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDiagWidth((yyvsp[-1].dval));
    }
#line 4406 "lef.tab.c"
    break;

  case 97:
#line 817 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDiagSpacing((yyvsp[-1].dval));
    }
#line 4414 "lef.tab.c"
    break;

  case 98:
#line 821 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setWidth((yyvsp[-1].dval));
      lefData->hasWidth = 1;  
    }
#line 4423 "lef.tab.c"
    break;

  case 99:
#line 826 "lef.y"
    {
      // Issue an error is this is defined in masterslice
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1715, "It is incorrect to define an AREA statement in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
               CHKERR();
            }
         }
      }

      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.setArea((yyvsp[-1].dval));
      }
    }
#line 4443 "lef.tab.c"
    break;

  case 100:
#line 842 "lef.y"
    {
      lefData->hasSpCenter = 0;       // reset to 0, only once per spacing is allowed 
      lefData->hasSpSamenet = 0;
      lefData->hasSpParallel = 0;
      lefData->hasSpLayer = 0;
      lefData->layerCutSpacing = (yyvsp[0].dval);  // for error message purpose
      // 11/22/99 - Wanda da Rosa, PCR 283762
      //            Issue an error is this is defined in masterslice
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1512, "It is incorrect to define a SPACING statement in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      // 5.5 either SPACING or SPACINGTABLE, not both for routing layer only
      if (lefData->layerRout) {
        if (lefData->lefrHasSpacingTbl && lefData->versionNum < 5.7) {
           if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
              if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                lefWarning(2010, "It is incorrect to have both SPACING rules & SPACINGTABLE rules within a ROUTING layer");
              }
           }
        }
        if (lefCallbacks->LayerCbk)
           lefData->lefrLayer.setSpacingMin((yyvsp[0].dval));
        lefData->lefrHasSpacing = 1;
      } else { 
        if (lefCallbacks->LayerCbk)
           lefData->lefrLayer.setSpacingMin((yyvsp[0].dval));
      }
    }
#line 4481 "lef.tab.c"
    break;

  case 101:
#line 876 "lef.y"
                                  {}
#line 4487 "lef.tab.c"
    break;

  case 102:
#line 878 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.setSpacingTableOrtho();
      if (lefCallbacks->LayerCbk) // due to converting to C, else, convertor produce 
         lefData->lefrLayer.addSpacingTableOrthoWithin((yyvsp[-2].dval), (yyvsp[0].dval));//bad code
    }
#line 4498 "lef.tab.c"
    break;

  case 103:
#line 885 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "SPACINGTABLE ORTHOGONAL is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1694, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      }
    }
#line 4513 "lef.tab.c"
    break;

  case 104:
#line 896 "lef.y"
    {
      lefData->layerDir = 1;
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1513, "DIRECTION statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDirection((yyvsp[-1].string));
      lefData->hasDirection = 1;  
    }
#line 4531 "lef.tab.c"
    break;

  case 105:
#line 910 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1514, "RESISTANCE statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setResistance((yyvsp[-1].dval));
    }
#line 4547 "lef.tab.c"
    break;

  case 106:
#line 922 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1515, "RESISTANCE statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
    }
#line 4562 "lef.tab.c"
    break;

  case 107:
#line 933 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1516, "CAPACITANCE statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setCapacitance((yyvsp[-1].dval));
    }
#line 4578 "lef.tab.c"
    break;

  case 108:
#line 945 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1517, "CAPACITANCE statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
    }
#line 4593 "lef.tab.c"
    break;

  case 109:
#line 956 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1518, "HEIGHT statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setHeight((yyvsp[-1].dval));
    }
#line 4609 "lef.tab.c"
    break;

  case 110:
#line 968 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1519, "WIREEXTENSION statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setWireExtension((yyvsp[-1].dval));
    }
#line 4625 "lef.tab.c"
    break;

  case 111:
#line 980 "lef.y"
    {
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1520, "THICKNESS statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setThickness((yyvsp[-1].dval));
    }
#line 4641 "lef.tab.c"
    break;

  case 112:
#line 992 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1521, "SHRINKAGE statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setShrinkage((yyvsp[-1].dval));
    }
#line 4657 "lef.tab.c"
    break;

  case 113:
#line 1004 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1522, "CAPMULTIPLIER statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setCapMultiplier((yyvsp[-1].dval));
    }
#line 4673 "lef.tab.c"
    break;

  case 114:
#line 1016 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1523, "EDGECAPACITANCE statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setEdgeCap((yyvsp[-1].dval));
    }
#line 4689 "lef.tab.c"
    break;

  case 115:
#line 1029 "lef.y"
    { // 5.3 syntax 
      lefData->use5_3 = 1;
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1525, "ANTENNALENGTHFACTOR statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      } else if (lefData->versionNum >= 5.4) {
         if (lefData->use5_4) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                  lefData->outMsg = (char*)lefMalloc(10000);
                  sprintf (lefData->outMsg,
                    "ANTENNALENGTHFACTOR statement is a version 5.3 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNALENGTHFACTOR syntax, which is incorrect.", lefData->versionNum);
                  lefError(1526, lefData->outMsg);
                  lefFree(lefData->outMsg);
                  CHKERR();
               }
            }
         }
      }

      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaLength((yyvsp[-1].dval));
    }
#line 4720 "lef.tab.c"
    break;

  case 116:
#line 1056 "lef.y"
    {
      if (lefData->versionNum < 5.2) {
         if (!lefData->layerRout) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefError(1702, "CURRENTDEN statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
                 CHKERR();
               }
            }
         }
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setCurrentDensity((yyvsp[-1].dval));
      } else {
         if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
            lefWarning(2079, "CURRENTDEN statement is obsolete in version 5.2 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.2 or later.");
            CHKERR();
         }
      }
    }
#line 4743 "lef.tab.c"
    break;

  case 117:
#line 1075 "lef.y"
    { 
      if (lefData->versionNum < 5.2) {
         if (!lefData->layerRout) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefError(1702, "CURRENTDEN statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
                 CHKERR();
               }
            }
         }
      } else {
         if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
            lefWarning(2079, "CURRENTDEN statement is obsolete in version 5.2 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.2 or later.");
            CHKERR();
         }
      }
    }
#line 4765 "lef.tab.c"
    break;

  case 118:
#line 1093 "lef.y"
    {
      if (lefData->versionNum < 5.2) {
         if (!lefData->layerRout) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefError(1702, "CURRENTDEN statement can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
                 CHKERR();
               }
            }
         }
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setCurrentPoint((yyvsp[-3].dval), (yyvsp[-2].dval));
      } else {
         if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
            lefWarning(2079, "CURRENTDEN statement is obsolete in version 5.2 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.2 or later.");
            CHKERR();
         }
      }
    }
#line 4788 "lef.tab.c"
    break;

  case 119:
#line 1111 "lef.y"
               { lefData->lefDumbMode = 10000000;}
#line 4794 "lef.tab.c"
    break;

  case 120:
#line 1112 "lef.y"
    {
      lefData->lefDumbMode = 0;
    }
#line 4802 "lef.tab.c"
    break;

  case 121:
#line 1116 "lef.y"
    {
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1527, "ACCURRENTDENSITY statement can't be defined in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addAccurrentDensity((yyvsp[0].string));      
    }
#line 4818 "lef.tab.c"
    break;

  case 122:
#line 1127 "lef.y"
                    {

    }
#line 4826 "lef.tab.c"
    break;

  case 123:
#line 1131 "lef.y"
    {
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1527, "ACCURRENTDENSITY statement can't be defined in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) {
           lefData->lefrLayer.addAccurrentDensity((yyvsp[-2].string));
           lefData->lefrLayer.setAcOneEntry((yyvsp[-1].dval));
      }
    }
#line 4845 "lef.tab.c"
    break;

  case 124:
#line 1146 "lef.y"
    {
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1528, "DCCURRENTDENSITY statement can't be defined in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addDccurrentDensity("AVERAGE");
         lefData->lefrLayer.setDcOneEntry((yyvsp[-1].dval));
      }
    }
#line 4864 "lef.tab.c"
    break;

  case 125:
#line 1161 "lef.y"
    {
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1528, "DCCURRENTDENSITY statement can't be defined in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (!lefData->layerCut) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1529, "CUTAREA statement can only be defined in LAYER with type CUT. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addDccurrentDensity("AVERAGE");
         lefData->lefrLayer.addNumber((yyvsp[0].dval));
      }
    }
#line 4891 "lef.tab.c"
    break;

  case 126:
#line 1184 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addDcCutarea(); }
#line 4897 "lef.tab.c"
    break;

  case 127:
#line 1185 "lef.y"
                   {}
#line 4903 "lef.tab.c"
    break;

  case 128:
#line 1187 "lef.y"
    {
      if (lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1528, "DCCURRENTDENSITY can't be defined in LAYER with TYPE MASTERSLICE or OVERLAP. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1530, "WIDTH statement can only be defined in LAYER with type ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addDccurrentDensity("AVERAGE");
         lefData->lefrLayer.addNumber((yyvsp[0].dval));
      }
    }
#line 4930 "lef.tab.c"
    break;

  case 129:
#line 1210 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addDcWidth(); }
#line 4936 "lef.tab.c"
    break;

  case 130:
#line 1211 "lef.y"
                   {}
#line 4942 "lef.tab.c"
    break;

  case 131:
#line 1215 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNAAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1531, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNADIFFAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNAAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1704, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (!lefData->layerRout && !lefData->layerCut && lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1533, "ANTENNAAREARATIO statement can only be defined in LAYER with TYPE ROUTING or CUT. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaAreaRatio((yyvsp[-1].dval));
    }
#line 4984 "lef.tab.c"
    break;

  case 132:
#line 1253 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNADIFFAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1532, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNADIFFAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNADIFFAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1704, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (!lefData->layerRout && !lefData->layerCut && lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1534, "ANTENNADIFFAREARATIO statement can only be defined in LAYER with TYPE ROUTING or CUT. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      lefData->antennaType = lefiAntennaDAR; 
    }
#line 5026 "lef.tab.c"
    break;

  case 133:
#line 1290 "lef.y"
                          {}
#line 5032 "lef.tab.c"
    break;

  case 134:
#line 1292 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNACUMAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1535, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNACUMAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNACUMAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1536, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (!lefData->layerRout && !lefData->layerCut && lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1537, "ANTENNACUMAREARATIO statement can only be defined in LAYER with TYPE ROUTING or CUT. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaCumAreaRatio((yyvsp[-1].dval));
    }
#line 5074 "lef.tab.c"
    break;

  case 135:
#line 1330 "lef.y"
    {  // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNACUMDIFFAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1538, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNACUMDIFFAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNACUMDIFFAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1539, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (!lefData->layerRout && !lefData->layerCut && lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1540, "ANTENNACUMDIFFAREARATIO statement can only be defined in LAYER with TYPE ROUTING or CUT. Parser will stop processing.");
              CHKERR();
            }
         }
      }
      lefData->antennaType = lefiAntennaCDAR;
    }
#line 5116 "lef.tab.c"
    break;

  case 136:
#line 1367 "lef.y"
                          {}
#line 5122 "lef.tab.c"
    break;

  case 137:
#line 1369 "lef.y"
    { // both 5.3  & 5.4 syntax 
      if (!lefData->layerRout && !lefData->layerCut && lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1541, "ANTENNAAREAFACTOR can only be defined in LAYER with TYPE ROUTING or CUT. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      // this does not need to check, since syntax is in both 5.3 & 5.4 
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaAreaFactor((yyvsp[0].dval));
      lefData->antennaType = lefiAntennaAF;
    }
#line 5140 "lef.tab.c"
    break;

  case 138:
#line 1382 "lef.y"
                          {}
#line 5146 "lef.tab.c"
    break;

  case 139:
#line 1384 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1542, "ANTENNASIDEAREARATIO can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNASIDEAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1543, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNASIDEAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNASIDEAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1544, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaSideAreaRatio((yyvsp[-1].dval));
    }
#line 5188 "lef.tab.c"
    break;

  case 140:
#line 1422 "lef.y"
    {  // 5.4 syntax 
      lefData->use5_4 = 1;
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1545, "ANTENNADIFFSIDEAREARATIO can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNADIFFSIDEAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1546, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNADIFFSIDEAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNADIFFSIDEAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1547, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      lefData->antennaType = lefiAntennaDSAR;
    }
#line 5230 "lef.tab.c"
    break;

  case 141:
#line 1459 "lef.y"
                          {}
#line 5236 "lef.tab.c"
    break;

  case 142:
#line 1461 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1548, "ANTENNACUMSIDEAREARATIO can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNACUMSIDEAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1549, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNACUMSIDEAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNACUMSIDEAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1550, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaCumSideAreaRatio((yyvsp[-1].dval));
    }
#line 5278 "lef.tab.c"
    break;

  case 143:
#line 1499 "lef.y"
    {  // 5.4 syntax 
      lefData->use5_4 = 1;
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1551, "ANTENNACUMDIFFSIDEAREARATIO can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNACUMDIFFSIDEAREARATIO statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1552, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNACUMDIFFSIDEAREARATIO statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNACUMDIFFSIDEAREARATIO syntax, which is incorrect.", lefData->versionNum);
               lefError(1553, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      lefData->antennaType = lefiAntennaCDSAR;
    }
#line 5320 "lef.tab.c"
    break;

  case 144:
#line 1536 "lef.y"
                          {}
#line 5326 "lef.tab.c"
    break;

  case 145:
#line 1538 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (!lefData->layerRout && (lefData->layerCut || lefData->layerMastOver)) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1554, "ANTENNASIDEAREAFACTOR can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNASIDEAREAFACTOR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1555, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNASIDEAREAFACTOR statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNASIDEAREAFACTOR syntax, which is incorrect.", lefData->versionNum);
               lefError(1556, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaSideAreaFactor((yyvsp[0].dval));
      lefData->antennaType = lefiAntennaSAF;
    }
#line 5369 "lef.tab.c"
    break;

  case 146:
#line 1576 "lef.y"
                          {}
#line 5375 "lef.tab.c"
    break;

  case 147:
#line 1578 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (!lefData->layerRout && !lefData->layerCut && lefData->layerMastOver) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1557, "ANTENNAMODEL can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNAMODEL statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1558, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->use5_3) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "ANTENNAMODEL statement is a version 5.4 or earlier syntax.\nYour lef file with version %g, has both old and new ANTENNAMODEL syntax, which is incorrect.", lefData->versionNum);
               lefError(1559, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      lefData->antennaType = lefiAntennaO;
    }
#line 5417 "lef.tab.c"
    break;

  case 148:
#line 1615 "lef.y"
                    {}
#line 5423 "lef.tab.c"
    break;

  case 149:
#line 1617 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "ANTENNACUMROUTINGPLUSCUT is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1686, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      } else {
         if (!lefData->layerRout && !lefData->layerCut) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                  lefError(1560, "ANTENNACUMROUTINGPLUSCUT can only be defined in LAYER with type ROUTING or CUT. Parser will stop processing.");
                  CHKERR();
               }
            }
         }
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaCumRoutingPlusCut();
      }
    }
#line 5448 "lef.tab.c"
    break;

  case 150:
#line 1638 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "ANTENNAGATEPLUSDIFF is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1687, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      } else {
         if (!lefData->layerRout && !lefData->layerCut) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                  lefError(1561, "ANTENNAGATEPLUSDIFF can only be defined in LAYER with type ROUTING or CUT. Parser will stop processing.");
                  CHKERR();
               }
            }
         }
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaGatePlusDiff((yyvsp[-1].dval));
      }
    }
#line 5473 "lef.tab.c"
    break;

  case 151:
#line 1659 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "ANTENNAAREAMINUSDIFF is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1688, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      } else {
         if (!lefData->layerRout && !lefData->layerCut) {
            if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                  lefError(1562, "ANTENNAAREAMINUSDIFF can only be defined in LAYER with type ROUTING or CUT. Parser will stop processing.");
                  CHKERR();
               }
            }
         }
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setAntennaAreaMinusDiff((yyvsp[-1].dval));
      }
    }
#line 5498 "lef.tab.c"
    break;

  case 152:
#line 1680 "lef.y"
    {
      if (!lefData->layerRout && !lefData->layerCut) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1563, "ANTENNAAREADIFFREDUCEPWL can only be defined in LAYER with type ROUTING or CUT. Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) { // require min 2 points, set the 1st 2 
         if (lefData->lefrAntennaPWLPtr) {
            lefData->lefrAntennaPWLPtr->Destroy();
            lefFree(lefData->lefrAntennaPWLPtr);
         }

         lefData->lefrAntennaPWLPtr = lefiAntennaPWL::create();
         lefData->lefrAntennaPWLPtr->addAntennaPWL((yyvsp[-1].pt).x, (yyvsp[-1].pt).y);
         lefData->lefrAntennaPWLPtr->addAntennaPWL((yyvsp[0].pt).x, (yyvsp[0].pt).y);
      }
    }
#line 5523 "lef.tab.c"
    break;

  case 153:
#line 1701 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        lefData->lefrLayer.setAntennaPWL(lefiAntennaADR, lefData->lefrAntennaPWLPtr);
        lefData->lefrAntennaPWLPtr = NULL;
      }
    }
#line 5534 "lef.tab.c"
    break;

  case 154:
#line 1707 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "ANTENNAAREADIFFREDUCEPWL is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1689, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      }
    }
#line 5549 "lef.tab.c"
    break;

  case 155:
#line 1718 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotWireWidth((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2011, "SLOTWIREWIDTH statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "SLOTWIREWIDTH statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1564, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotWireWidth((yyvsp[-1].dval));
    }
#line 5577 "lef.tab.c"
    break;

  case 156:
#line 1742 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotWireLength((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2012, "SLOTWIRELENGTH statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "SLOTWIRELENGTH statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1565, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotWireLength((yyvsp[-1].dval));
    }
#line 5605 "lef.tab.c"
    break;

  case 157:
#line 1766 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotWidth((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2013, "SLOTWIDTH statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "SLOTWIDTH statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1566, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotWidth((yyvsp[-1].dval));
    }
#line 5633 "lef.tab.c"
    break;

  case 158:
#line 1790 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotLength((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2014, "SLOTLENGTH statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "SLOTLENGTH statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1567, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSlotLength((yyvsp[-1].dval));
    }
#line 5661 "lef.tab.c"
    break;

  case 159:
#line 1814 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxAdjacentSlotSpacing((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2015, "MAXADJACENTSLOTSPACING statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MAXADJACENTSLOTSPACING statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1568, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxAdjacentSlotSpacing((yyvsp[-1].dval));
    }
#line 5689 "lef.tab.c"
    break;

  case 160:
#line 1838 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxCoaxialSlotSpacing((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
                lefWarning(2016, "MAXCOAXIALSLOTSPACING statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MAXCOAXIALSLOTSPACING statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1569, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxCoaxialSlotSpacing((yyvsp[-1].dval));
    }
#line 5717 "lef.tab.c"
    break;

  case 161:
#line 1862 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxEdgeSlotSpacing((yyvsp[-1].dval));
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2017, "MAXEDGESLOTSPACING statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MAXEDGESLOTSPACING statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1570, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else
         if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxEdgeSlotSpacing((yyvsp[-1].dval));
    }
#line 5745 "lef.tab.c"
    break;

  case 162:
#line 1886 "lef.y"
    { // 5.4 syntax 
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum >= 5.7) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
               lefWarning(2018, "SPLITWIREWIDTH statement is obsolete in version 5.7 or later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.7 or later.");
         }
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "SPLITWIREWIDTH statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1571, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setSplitWireWidth((yyvsp[-1].dval));
    }
#line 5772 "lef.tab.c"
    break;

  case 163:
#line 1909 "lef.y"
    { // 5.4 syntax, pcr 394389 
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MINIMUMDENSITY statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1572, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMinimumDensity((yyvsp[-1].dval));
    }
#line 5794 "lef.tab.c"
    break;

  case 164:
#line 1927 "lef.y"
    { // 5.4 syntax, pcr 394389 
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MAXIMUMDENSITY statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1573, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaximumDensity((yyvsp[-1].dval));
    }
#line 5816 "lef.tab.c"
    break;

  case 165:
#line 1945 "lef.y"
    { // 5.4 syntax, pcr 394389 
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "DENSITYCHECKWINDOW statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1574, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDensityCheckWindow((yyvsp[-2].dval), (yyvsp[-1].dval));
    }
#line 5838 "lef.tab.c"
    break;

  case 166:
#line 1963 "lef.y"
    { // 5.4 syntax, pcr 394389 
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "DENSITYCHECKSTEP statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1575, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setDensityCheckStep((yyvsp[-1].dval));
    }
#line 5860 "lef.tab.c"
    break;

  case 167:
#line 1981 "lef.y"
    { // 5.4 syntax, pcr 394389 
      if (lefData->ignoreVersion) {
         // do nothing 
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "FILLACTIVESPACING statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1576, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setFillActiveSpacing((yyvsp[-1].dval));
    }
#line 5882 "lef.tab.c"
    break;

  case 168:
#line 1999 "lef.y"
    {
      // 5.5 MAXWIDTH, is for routing layer only
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefError(1577, "MAXWIDTH statement can only be defined in LAYER with TYPE ROUTING.  Parser will stop processing.");
               CHKERR();
            }
         }
      }
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MAXWIDTH statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1578, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMaxwidth((yyvsp[-1].dval));
    }
#line 5911 "lef.tab.c"
    break;

  case 169:
#line 2024 "lef.y"
    {
      // 5.5 MINWIDTH, is for routing layer only
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1579, "MINWIDTH statement can only be defined in LAYER with TYPE ROUTING.  Parser will stop processing.");
              CHKERR();
            }
         }
      }
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MINWIDTH statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1580, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setMinwidth((yyvsp[-1].dval));
    }
#line 5940 "lef.tab.c"
    break;

  case 170:
#line 2049 "lef.y"
    {
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "MINENCLOSEDAREA statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1581, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addMinenclosedarea((yyvsp[0].dval));
    }
#line 5960 "lef.tab.c"
    break;

  case 171:
#line 2064 "lef.y"
                          {}
#line 5966 "lef.tab.c"
    break;

  case 172:
#line 2066 "lef.y"
    { // pcr 409334 
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addMinimumcut((int)(yyvsp[-2].dval), (yyvsp[0].dval)); 
      lefData->hasLayerMincut = 0;
    }
#line 5976 "lef.tab.c"
    break;

  case 173:
#line 2074 "lef.y"
    {
      if (!lefData->hasLayerMincut) {   // FROMABOVE nor FROMBELOW is set 
         if (lefCallbacks->LayerCbk)
             lefData->lefrLayer.addMinimumcutConnect((char*)"");
      }
    }
#line 5987 "lef.tab.c"
    break;

  case 174:
#line 2081 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addMinstep((yyvsp[0].dval));
    }
#line 5995 "lef.tab.c"
    break;

  case 175:
#line 2085 "lef.y"
    {
    }
#line 6002 "lef.tab.c"
    break;

  case 176:
#line 2088 "lef.y"
    {
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "PROTRUSION RULE statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1582, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.setProtrusion((yyvsp[-5].dval), (yyvsp[-3].dval), (yyvsp[-1].dval));
    }
#line 6022 "lef.tab.c"
    break;

  case 177:
#line 2104 "lef.y"
    {
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "SPACINGTABLE statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1583, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      // 5.5 either SPACING or SPACINGTABLE in a layer, not both
      if (lefData->lefrHasSpacing && lefData->layerRout && lefData->versionNum < 5.7) {
         if (lefCallbacks->LayerCbk)  // write warning only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefWarning(2010, "It is incorrect to have both SPACING rules & SPACINGTABLE rules within a ROUTING layer");
            }
      } 
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addSpacingTable();
      lefData->lefrHasSpacingTbl = 1;
    }
#line 6050 "lef.tab.c"
    break;

  case 178:
#line 2127 "lef.y"
                   {}
#line 6056 "lef.tab.c"
    break;

  case 179:
#line 2130 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ENCLOSURE statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1584, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addEnclosure((yyvsp[-2].string), (yyvsp[-1].dval), (yyvsp[0].dval));
    }
#line 6077 "lef.tab.c"
    break;

  case 180:
#line 2146 "lef.y"
                                  {}
#line 6083 "lef.tab.c"
    break;

  case 181:
#line 2149 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "PREFERENCLOSURE statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1585, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addPreferEnclosure((yyvsp[-2].string), (yyvsp[-1].dval), (yyvsp[0].dval));
    }
#line 6104 "lef.tab.c"
    break;

  case 182:
#line 2165 "lef.y"
                                        {}
#line 6110 "lef.tab.c"
    break;

  case 183:
#line 2167 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "RESISTANCE statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1586, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else {
         if (lefCallbacks->LayerCbk)
            lefData->lefrLayer.setResPerCut((yyvsp[-1].dval));
      }
    }
#line 6132 "lef.tab.c"
    break;

  case 184:
#line 2185 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1587, "DIAGMINEDGELENGTH can only be defined in LAYER with TYPE ROUTING. Parser will stop processing.");
              CHKERR();
            }
         }
      } else if (lefData->versionNum < 5.6) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "DIAGMINEDGELENGTH statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1588, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else {
         if (lefCallbacks->LayerCbk)
            lefData->lefrLayer.setDiagMinEdgeLength((yyvsp[-1].dval));
      }
    }
#line 6161 "lef.tab.c"
    break;

  case 185:
#line 2210 "lef.y"
    {
      // Use the polygon code to retrieve the points for MINSIZE
      lefData->lefrGeometriesPtr = (lefiGeometries*)lefMalloc(sizeof(lefiGeometries));
      lefData->lefrGeometriesPtr->Init();
      lefData->lefrDoGeometries = 1;
    }
#line 6172 "lef.tab.c"
    break;

  case 186:
#line 2217 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
         lefData->lefrGeometriesPtr->addPolygon();
         lefData->lefrLayer.setMinSize(lefData->lefrGeometriesPtr);
      }
     lefData->lefrDoGeometries = 0;
      lefData->lefrGeometriesPtr->Destroy();
      lefFree(lefData->lefrGeometriesPtr);
    }
#line 6186 "lef.tab.c"
    break;

  case 188:
#line 2230 "lef.y"
    {
        if (lefCallbacks->LayerCbk)
           lefData->lefrLayer.setArraySpacingLongArray();
    }
#line 6195 "lef.tab.c"
    break;

  case 190:
#line 2238 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.setArraySpacingWidth((yyvsp[0].dval));
    }
#line 6204 "lef.tab.c"
    break;

  case 193:
#line 2249 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addArraySpacingArray((int)(yyvsp[-2].dval), (yyvsp[0].dval));
         if (lefData->arrayCutsVal > (int)(yyvsp[-2].dval)) {
            // Mulitiple ARRAYCUTS value needs to me in ascending order 
            if (!lefData->arrayCutsWar) {
               if (lefData->layerWarnings++ < lefSettings->LayerWarnings)
                  lefWarning(2080, "The number of cut values in multiple ARRAYSPACING ARRAYCUTS are not in increasing order.\nTo be consistent with the documentation, update the cut values to increasing order.");
               lefData->arrayCutsWar = 1;
            }
         }
         lefData->arrayCutsVal = (int)(yyvsp[-2].dval);
    }
#line 6222 "lef.tab.c"
    break;

  case 194:
#line 2265 "lef.y"
    { 
      if (lefData->hasInfluence) {  // 5.5 - INFLUENCE table must follow a PARALLEL
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1589, "An INFLUENCE table statement was defined before the PARALLELRUNLENGTH table statement.\nINFLUENCE table statement should be defined following the PARALLELRUNLENGTH.\nChange the LEF file and rerun the parser.");
              CHKERR();
            }
         }
      }
      if (lefData->hasParallel) { // 5.5 - Only one PARALLEL table is allowed per layer
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1590, "There is multiple PARALLELRUNLENGTH table statements are defined within a layer.\nAccording to the LEF Reference Manual, only one PARALLELRUNLENGTH table statement is allowed per layer.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval));
      lefData->hasParallel = 1;
    }
#line 6247 "lef.tab.c"
    break;

  case 195:
#line 2286 "lef.y"
    {
      lefData->spParallelLength = lefData->lefrLayer.getNumber();
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addSpParallelLength();
    }
#line 6256 "lef.tab.c"
    break;

  case 196:
#line 2291 "lef.y"
    { 
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addSpParallelWidth((yyvsp[0].dval));
      }
    }
#line 6266 "lef.tab.c"
    break;

  case 197:
#line 2297 "lef.y"
    { 
      if (lefData->lefrLayer.getNumber() != lefData->spParallelLength) {
         if (lefCallbacks->LayerCbk) {
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1591, "The number of length in the PARALLELRUNLENGTH statement is not equal to\nthe total number of spacings defined in the WIDTH statement in the SPACINGTABLE.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addSpParallelWidthSpacing();
    }
#line 6282 "lef.tab.c"
    break;

  case 199:
#line 2311 "lef.y"
    {
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval));
    }
#line 6290 "lef.tab.c"
    break;

  case 200:
#line 2315 "lef.y"
    {
      if (lefData->hasParallel) { // 5.7 - Either PARALLEL OR TWOWIDTHS per layer
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1592, "A PARALLELRUNLENGTH statement was already defined in the layer.\nIt is PARALLELRUNLENGTH or TWOWIDTHS is allowed per layer.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addSpTwoWidths((yyvsp[-4].dval), (yyvsp[-3].dval));
      lefData->hasTwoWidths = 1;
    }
#line 6307 "lef.tab.c"
    break;

  case 201:
#line 2328 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "TWOWIDTHS is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1697, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } 
    }
#line 6322 "lef.tab.c"
    break;

  case 202:
#line 2339 "lef.y"
    {
      if (lefData->hasInfluence) {  // 5.5 - INFLUENCE table must follow a PARALLEL
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1594, "A INFLUENCE table statement was already defined in the layer.\nOnly one INFLUENCE statement is allowed per layer.");
              CHKERR();
            }
         }
      }
      if (!lefData->hasParallel) {  // 5.5 - INFLUENCE must follow a PARALLEL
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1595, "An INFLUENCE table statement was already defined before the layer.\nINFLUENCE statement has to be defined after the PARALLELRUNLENGTH table statement in the layer.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.setInfluence();
         lefData->lefrLayer.addSpInfluence((yyvsp[-4].dval), (yyvsp[-2].dval), (yyvsp[0].dval));
      }
    }
#line 6349 "lef.tab.c"
    break;

  case 206:
#line 2369 "lef.y"
  {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addSpacingTableOrthoWithin((yyvsp[-2].dval), (yyvsp[0].dval));
  }
#line 6358 "lef.tab.c"
    break;

  case 207:
#line 2375 "lef.y"
    {(yyval.string) = (char*)"NULL";}
#line 6364 "lef.tab.c"
    break;

  case 208:
#line 2376 "lef.y"
             {(yyval.string) = (char*)"ABOVE";}
#line 6370 "lef.tab.c"
    break;

  case 209:
#line 2377 "lef.y"
             {(yyval.string) = (char*)"BELOW";}
#line 6376 "lef.tab.c"
    break;

  case 211:
#line 2381 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addEnclosureWidth((yyvsp[0].dval));
      }
    }
#line 6386 "lef.tab.c"
    break;

  case 213:
#line 2388 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "LENGTH is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1691, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      } else {
         if (lefCallbacks->LayerCbk) {
            lefData->lefrLayer.addEnclosureLength((yyvsp[0].dval));
         }
      }
    }
#line 6405 "lef.tab.c"
    break;

  case 215:
#line 2405 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
         lefData->outMsg = (char*)lefMalloc(10000);
         sprintf(lefData->outMsg,
           "EXCEPTEXTRACUT is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
         lefError(1690, lefData->outMsg);
         lefFree(lefData->outMsg);
         CHKERR();
      } else {
         if (lefCallbacks->LayerCbk) {
            lefData->lefrLayer.addEnclosureExceptEC((yyvsp[0].dval));
         }
      }
    }
#line 6424 "lef.tab.c"
    break;

  case 217:
#line 2422 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addPreferEnclosureWidth((yyvsp[0].dval));
      }
    }
#line 6434 "lef.tab.c"
    break;

  case 219:
#line 2430 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "MINIMUMCUT WITHIN is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1700, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } else {
         if (lefCallbacks->LayerCbk) {
            lefData->lefrLayer.addMinimumcutWithin((yyvsp[0].dval));
         }
      }
    }
#line 6453 "lef.tab.c"
    break;

  case 221:
#line 2447 "lef.y"
    {
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "FROMABOVE statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1596, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      lefData->hasLayerMincut = 1;
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addMinimumcutConnect((char*)"FROMABOVE");

    }
#line 6476 "lef.tab.c"
    break;

  case 222:
#line 2466 "lef.y"
    {
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "FROMBELOW statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1597, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      }
      lefData->hasLayerMincut = 1;
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addMinimumcutConnect((char*)"FROMBELOW");
    }
#line 6498 "lef.tab.c"
    break;

  case 224:
#line 2486 "lef.y"
    {   
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "LENGTH WITHIN statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1598, lefData->outMsg);
               lefFree(lefData->outMsg);
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addMinimumcutLengDis((yyvsp[-2].dval), (yyvsp[0].dval));
    }
#line 6519 "lef.tab.c"
    break;

  case 227:
#line 2508 "lef.y"
  {
    if (lefCallbacks->LayerCbk) lefData->lefrLayer.addMinstepType((yyvsp[0].string));
  }
#line 6527 "lef.tab.c"
    break;

  case 228:
#line 2512 "lef.y"
  {
    if (lefCallbacks->LayerCbk) lefData->lefrLayer.addMinstepLengthsum((yyvsp[0].dval));
  }
#line 6535 "lef.tab.c"
    break;

  case 229:
#line 2516 "lef.y"
  {
    if (lefData->versionNum < 5.7) {
      lefData->outMsg = (char*)lefMalloc(10000);
      sprintf(lefData->outMsg,
        "MAXEDGES is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
      lefError(1710, lefData->outMsg);
      lefFree(lefData->outMsg);
      CHKERR();
    } else
       if (lefCallbacks->LayerCbk) lefData->lefrLayer.addMinstepMaxedges((int)(yyvsp[0].dval));
  }
#line 6551 "lef.tab.c"
    break;

  case 230:
#line 2529 "lef.y"
                 {(yyval.string) = (char*)"INSIDECORNER";}
#line 6557 "lef.tab.c"
    break;

  case 231:
#line 2530 "lef.y"
                    {(yyval.string) = (char*)"OUTSIDECORNER";}
#line 6563 "lef.tab.c"
    break;

  case 232:
#line 2531 "lef.y"
           {(yyval.string) = (char*)"STEP";}
#line 6569 "lef.tab.c"
    break;

  case 233:
#line 2535 "lef.y"
      { if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setAntennaValue(lefData->antennaType, (yyvsp[0].dval)); }
#line 6576 "lef.tab.c"
    break;

  case 234:
#line 2538 "lef.y"
      { if (lefCallbacks->LayerCbk) { // require min 2 points, set the 1st 2 
          if (lefData->lefrAntennaPWLPtr) {
            lefData->lefrAntennaPWLPtr->Destroy();
            lefFree(lefData->lefrAntennaPWLPtr);
          }

          lefData->lefrAntennaPWLPtr = lefiAntennaPWL::create();
          lefData->lefrAntennaPWLPtr->addAntennaPWL((yyvsp[-1].pt).x, (yyvsp[-1].pt).y);
          lefData->lefrAntennaPWLPtr->addAntennaPWL((yyvsp[0].pt).x, (yyvsp[0].pt).y);
        }
      }
#line 6592 "lef.tab.c"
    break;

  case 235:
#line 2550 "lef.y"
      { 
        if (lefCallbacks->LayerCbk) {
          lefData->lefrLayer.setAntennaPWL(lefData->antennaType, lefData->lefrAntennaPWLPtr);
          lefData->lefrAntennaPWLPtr = NULL;
        }
      }
#line 6603 "lef.tab.c"
    break;

  case 238:
#line 2563 "lef.y"
  { if (lefCallbacks->LayerCbk)
      lefData->lefrAntennaPWLPtr->addAntennaPWL((yyvsp[0].pt).x, (yyvsp[0].pt).y);
  }
#line 6611 "lef.tab.c"
    break;

  case 240:
#line 2569 "lef.y"
      { 
        lefData->use5_4 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        }
        else if ((lefData->antennaType == lefiAntennaAF) && (lefData->versionNum <= 5.3)) {
           if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
              if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                   "ANTENNAAREAFACTOR with DIFFUSEONLY statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                 lefError(1599, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        } else if (lefData->use5_3) {
           if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
              if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                   "ANTENNAAREAFACTOR with DIFFUSEONLY statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                 lefError(1599, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
        if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setAntennaDUO(lefData->antennaType);
      }
#line 6647 "lef.tab.c"
    break;

  case 241:
#line 2602 "lef.y"
               {(yyval.string) = (char*)"PEAK";}
#line 6653 "lef.tab.c"
    break;

  case 242:
#line 2603 "lef.y"
               {(yyval.string) = (char*)"AVERAGE";}
#line 6659 "lef.tab.c"
    break;

  case 243:
#line 2604 "lef.y"
               {(yyval.string) = (char*)"RMS";}
#line 6665 "lef.tab.c"
    break;

  case 244:
#line 2608 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval)); }
#line 6671 "lef.tab.c"
    break;

  case 245:
#line 2610 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addAcFrequency(); }
#line 6677 "lef.tab.c"
    break;

  case 246:
#line 2613 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval)); }
#line 6683 "lef.tab.c"
    break;

  case 247:
#line 2615 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addAcTableEntry(); }
#line 6689 "lef.tab.c"
    break;

  case 249:
#line 2619 "lef.y"
    {
      if (!lefData->layerCut) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1600, "CUTAREA statement can only be defined in LAYER with TYPE CUT.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval));
    }
#line 6705 "lef.tab.c"
    break;

  case 250:
#line 2631 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addAcCutarea(); }
#line 6711 "lef.tab.c"
    break;

  case 251:
#line 2633 "lef.y"
    {
      if (!lefData->layerRout) {
         if (lefCallbacks->LayerCbk) { // write error only if cbk is set 
            if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1601, "WIDTH can only be defined in LAYER with TYPE ROUTING.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval));
    }
#line 6727 "lef.tab.c"
    break;

  case 252:
#line 2645 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addAcWidth(); }
#line 6733 "lef.tab.c"
    break;

  case 253:
#line 2649 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval)); }
#line 6739 "lef.tab.c"
    break;

  case 254:
#line 2651 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addDcTableEntry(); }
#line 6745 "lef.tab.c"
    break;

  case 256:
#line 2655 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval)); }
#line 6751 "lef.tab.c"
    break;

  case 258:
#line 2659 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval)); }
#line 6757 "lef.tab.c"
    break;

  case 261:
#line 2668 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        char propTp;
        propTp = lefSettings->lefProps.lefrLayerProp.propType((yyvsp[-1].string));
        lefData->lefrLayer.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 6769 "lef.tab.c"
    break;

  case 262:
#line 2676 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        char propTp;
        propTp = lefSettings->lefProps.lefrLayerProp.propType((yyvsp[-1].string));
        lefData->lefrLayer.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 6781 "lef.tab.c"
    break;

  case 263:
#line 2684 "lef.y"
    {
      char temp[32];
      sprintf(temp, "%.11g", (yyvsp[0].dval));
      if (lefCallbacks->LayerCbk) {
        char propTp;
        propTp = lefSettings->lefProps.lefrLayerProp.propType((yyvsp[-1].string));
        lefData->lefrLayer.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), temp, propTp);
      }
    }
#line 6795 "lef.tab.c"
    break;

  case 264:
#line 2696 "lef.y"
    { }
#line 6801 "lef.tab.c"
    break;

  case 265:
#line 2698 "lef.y"
    { }
#line 6807 "lef.tab.c"
    break;

  case 266:
#line 2701 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.setCurrentPoint((yyvsp[-2].dval), (yyvsp[-1].dval)); }
#line 6813 "lef.tab.c"
    break;

  case 269:
#line 2709 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.setCapacitancePoint((yyvsp[-2].dval), (yyvsp[-1].dval)); }
#line 6819 "lef.tab.c"
    break;

  case 271:
#line 2714 "lef.y"
    { }
#line 6825 "lef.tab.c"
    break;

  case 272:
#line 2717 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.setResistancePoint((yyvsp[-2].dval), (yyvsp[-1].dval)); }
#line 6831 "lef.tab.c"
    break;

  case 273:
#line 2720 "lef.y"
                  {(yyval.string) = (char*)"ROUTING"; lefData->layerRout = 1;}
#line 6837 "lef.tab.c"
    break;

  case 274:
#line 2721 "lef.y"
                  {(yyval.string) = (char*)"CUT"; lefData->layerCut = 1;}
#line 6843 "lef.tab.c"
    break;

  case 275:
#line 2722 "lef.y"
                  {(yyval.string) = (char*)"OVERLAP"; lefData->layerMastOver = 1;}
#line 6849 "lef.tab.c"
    break;

  case 276:
#line 2723 "lef.y"
                  {(yyval.string) = (char*)"MASTERSLICE"; lefData->layerMastOver = 1;}
#line 6855 "lef.tab.c"
    break;

  case 277:
#line 2724 "lef.y"
                  {(yyval.string) = (char*)"VIRTUAL";}
#line 6861 "lef.tab.c"
    break;

  case 278:
#line 2725 "lef.y"
                  {(yyval.string) = (char*)"IMPLANT";}
#line 6867 "lef.tab.c"
    break;

  case 279:
#line 2728 "lef.y"
                    {(yyval.string) = (char*)"HORIZONTAL";}
#line 6873 "lef.tab.c"
    break;

  case 280:
#line 2729 "lef.y"
                    {(yyval.string) = (char*)"VERTICAL";}
#line 6879 "lef.tab.c"
    break;

  case 281:
#line 2730 "lef.y"
                    {(yyval.string) = (char*)"DIAG45";}
#line 6885 "lef.tab.c"
    break;

  case 282:
#line 2731 "lef.y"
                    {(yyval.string) = (char*)"DIAG135";}
#line 6891 "lef.tab.c"
    break;

  case 284:
#line 2735 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addMinenclosedareaWidth((yyvsp[0].dval));
    }
#line 6900 "lef.tab.c"
    break;

  case 285:
#line 2742 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(1);
    }
#line 6909 "lef.tab.c"
    break;

  case 286:
#line 2747 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(2);
    }
#line 6918 "lef.tab.c"
    break;

  case 287:
#line 2752 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(3);
    }
#line 6927 "lef.tab.c"
    break;

  case 288:
#line 2757 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(4);
    }
#line 6936 "lef.tab.c"
    break;

  case 289:
#line 2762 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(5);
    }
#line 6945 "lef.tab.c"
    break;

  case 290:
#line 2767 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(6);
    }
#line 6954 "lef.tab.c"
    break;

  case 291:
#line 2772 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(7);
    }
#line 6963 "lef.tab.c"
    break;

  case 292:
#line 2777 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(8);
    }
#line 6972 "lef.tab.c"
    break;

  case 293:
#line 2782 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(9);
    }
#line 6981 "lef.tab.c"
    break;

  case 294:
#line 2787 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(10);
    }
#line 6990 "lef.tab.c"
    break;

  case 295:
#line 2792 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(11);
    }
#line 6999 "lef.tab.c"
    break;

  case 296:
#line 2797 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(12);
    }
#line 7008 "lef.tab.c"
    break;

  case 297:
#line 2802 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(13);
    }
#line 7017 "lef.tab.c"
    break;

  case 298:
#line 2807 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(14);
    }
#line 7026 "lef.tab.c"
    break;

  case 299:
#line 2812 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(15);
    }
#line 7035 "lef.tab.c"
    break;

  case 300:
#line 2817 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(16);
    }
#line 7044 "lef.tab.c"
    break;

  case 301:
#line 2822 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(17);
    }
#line 7053 "lef.tab.c"
    break;

  case 302:
#line 2827 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(18);
    }
#line 7062 "lef.tab.c"
    break;

  case 303:
#line 2832 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(19);
    }
#line 7071 "lef.tab.c"
    break;

  case 304:
#line 2837 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(20);
    }
#line 7080 "lef.tab.c"
    break;

  case 305:
#line 2842 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(21);
    }
#line 7089 "lef.tab.c"
    break;

  case 306:
#line 2847 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(22);
    }
#line 7098 "lef.tab.c"
    break;

  case 307:
#line 2852 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(23);
    }
#line 7107 "lef.tab.c"
    break;

  case 308:
#line 2857 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(24);
    }
#line 7116 "lef.tab.c"
    break;

  case 309:
#line 2862 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(25);
    }
#line 7125 "lef.tab.c"
    break;

  case 310:
#line 2867 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(26);
    }
#line 7134 "lef.tab.c"
    break;

  case 311:
#line 2872 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(27);
    }
#line 7143 "lef.tab.c"
    break;

  case 312:
#line 2877 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(28);
    }
#line 7152 "lef.tab.c"
    break;

  case 313:
#line 2882 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(29);
    }
#line 7161 "lef.tab.c"
    break;

  case 314:
#line 2887 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(30);
    }
#line 7170 "lef.tab.c"
    break;

  case 315:
#line 2892 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(31);
    }
#line 7179 "lef.tab.c"
    break;

  case 316:
#line 2897 "lef.y"
    {
    if (lefCallbacks->LayerCbk)
       lefData->lefrLayer.addAntennaModel(32);
    }
#line 7188 "lef.tab.c"
    break;

  case 317:
#line 2903 "lef.y"
    { }
#line 7194 "lef.tab.c"
    break;

  case 318:
#line 2905 "lef.y"
    { }
#line 7200 "lef.tab.c"
    break;

  case 319:
#line 2908 "lef.y"
    { 
      if (lefCallbacks->LayerCbk) {
         lefData->lefrLayer.addSpParallelWidth((yyvsp[0].dval));
      }
    }
#line 7210 "lef.tab.c"
    break;

  case 320:
#line 2914 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addSpParallelWidthSpacing(); }
#line 7216 "lef.tab.c"
    break;

  case 321:
#line 2917 "lef.y"
    { }
#line 7222 "lef.tab.c"
    break;

  case 322:
#line 2919 "lef.y"
    { }
#line 7228 "lef.tab.c"
    break;

  case 323:
#line 2922 "lef.y"
    {
       if (lefCallbacks->LayerCbk) lefData->lefrLayer.addNumber((yyvsp[0].dval));
    }
#line 7236 "lef.tab.c"
    break;

  case 324:
#line 2926 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
         lefData->lefrLayer.addSpTwoWidths((yyvsp[-4].dval), (yyvsp[-3].dval));
    }
#line 7245 "lef.tab.c"
    break;

  case 325:
#line 2932 "lef.y"
    { 
        (yyval.dval) = -1; // cannot use 0, since PRL number can be 0 
        lefData->lefrLayer.setSpTwoWidthsHasPRL(0);
    }
#line 7254 "lef.tab.c"
    break;

  case 326:
#line 2937 "lef.y"
    { 
        (yyval.dval) = (yyvsp[0].dval); 
        lefData->lefrLayer.setSpTwoWidthsHasPRL(1);
    }
#line 7263 "lef.tab.c"
    break;

  case 327:
#line 2943 "lef.y"
    { }
#line 7269 "lef.tab.c"
    break;

  case 328:
#line 2945 "lef.y"
    { }
#line 7275 "lef.tab.c"
    break;

  case 329:
#line 2948 "lef.y"
    { if (lefCallbacks->LayerCbk) lefData->lefrLayer.addSpInfluence((yyvsp[-4].dval), (yyvsp[-2].dval), (yyvsp[0].dval)); }
#line 7281 "lef.tab.c"
    break;

  case 330:
#line 2951 "lef.y"
    {
      if (!lefData->lefrHasLayer) {  // 5.5 
        if (lefCallbacks->MaxStackViaCbk) { // write error only if cbk is set 
           if (lefData->maxStackViaWarnings++ < lefSettings->MaxStackViaWarnings) {
             lefError(1602, "MAXVIASTACK statement has to be defined after the LAYER statement.");
             CHKERR();
           }
        }
      } else if (lefData->lefrHasMaxVS) {
        if (lefCallbacks->MaxStackViaCbk) { // write error only if cbk is set 
           if (lefData->maxStackViaWarnings++ < lefSettings->MaxStackViaWarnings) {
             lefError(1603, "A MAXVIASTACK was already defined.\nOnly one MAXVIASTACK is allowed per lef file.");
             CHKERR();
           }
        }
      } else {
        if (lefCallbacks->MaxStackViaCbk) {
           lefData->lefrMaxStackVia.setMaxStackVia((int)(yyvsp[-1].dval));
           CALLBACK(lefCallbacks->MaxStackViaCbk, lefrMaxStackViaCbkType, &lefData->lefrMaxStackVia);
        }
      }
      if (lefData->versionNum < 5.5) {
        if (lefCallbacks->MaxStackViaCbk) { // write error only if cbk is set 
           if (lefData->maxStackViaWarnings++ < lefSettings->MaxStackViaWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                "MAXVIASTACK statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1604, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      lefData->lefrHasMaxVS = 1;
    }
#line 7321 "lef.tab.c"
    break;

  case 331:
#line 2986 "lef.y"
                                     {lefData->lefDumbMode = 2; lefData->lefNoNum= 2;}
#line 7327 "lef.tab.c"
    break;

  case 332:
#line 2988 "lef.y"
    {
      if (!lefData->lefrHasLayer) {  // 5.5 
        if (lefCallbacks->MaxStackViaCbk) { // write error only if cbk is set 
           if (lefData->maxStackViaWarnings++ < lefSettings->MaxStackViaWarnings) {
              lefError(1602, "MAXVIASTACK statement has to be defined after the LAYER statement.");
              CHKERR();
           }
        }
      } else if (lefData->lefrHasMaxVS) {
        if (lefCallbacks->MaxStackViaCbk) { // write error only if cbk is set 
           if (lefData->maxStackViaWarnings++ < lefSettings->MaxStackViaWarnings) {
             lefError(1603, "A MAXVIASTACK was already defined.\nOnly one MAXVIASTACK is allowed per lef file.");
             CHKERR();
           }
        }
      } else {
        if (lefCallbacks->MaxStackViaCbk) {
           lefData->lefrMaxStackVia.setMaxStackVia((int)(yyvsp[-5].dval));
           lefData->lefrMaxStackVia.setMaxStackViaRange((yyvsp[-2].string), (yyvsp[-1].string));
           CALLBACK(lefCallbacks->MaxStackViaCbk, lefrMaxStackViaCbkType, &lefData->lefrMaxStackVia);
        }
      }
      lefData->lefrHasMaxVS = 1;
    }
#line 7356 "lef.tab.c"
    break;

  case 333:
#line 3013 "lef.y"
                { lefData->hasViaRule_layer = 0; }
#line 7362 "lef.tab.c"
    break;

  case 334:
#line 3014 "lef.y"
    { 
      if (lefCallbacks->ViaCbk) {
        if (lefData->ndRule) 
            lefData->nd->addViaRule(&lefData->lefrVia);
         else 
            CALLBACK(lefCallbacks->ViaCbk, lefrViaCbkType, &lefData->lefrVia);
       }
    }
#line 7375 "lef.tab.c"
    break;

  case 335:
#line 3024 "lef.y"
     { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 7381 "lef.tab.c"
    break;

  case 336:
#line 3027 "lef.y"
    {
      // 0 is nodefault 
      if (lefCallbacks->ViaCbk) lefData->lefrVia.setName((yyvsp[0].string), 0);
      lefData->viaLayer = 0;
      lefData->numVia++;
      //strcpy(lefData->viaName, $2);
      lefData->viaName = strdup((yyvsp[0].string));
    }
#line 7394 "lef.tab.c"
    break;

  case 337:
#line 3036 "lef.y"
    {
      // 1 is default 
      if (lefCallbacks->ViaCbk) lefData->lefrVia.setName((yyvsp[-1].string), 1);
      lefData->viaLayer = 0;
      //strcpy(lefData->viaName, $2);
      lefData->viaName = strdup((yyvsp[-1].string));
    }
#line 7406 "lef.tab.c"
    break;

  case 338:
#line 3044 "lef.y"
    {
      // 2 is generated 
      if (lefCallbacks->ViaCbk) lefData->lefrVia.setName((yyvsp[-1].string), 2);
      lefData->viaLayer = 0;
      //strcpy(lefData->viaName, $2);
      lefData->viaName = strdup((yyvsp[-1].string));
    }
#line 7418 "lef.tab.c"
    break;

  case 339:
#line 3052 "lef.y"
                       {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 7424 "lef.tab.c"
    break;

  case 340:
#line 3054 "lef.y"
           {lefData->lefDumbMode = 3; lefData->lefNoNum = 1; }
#line 7430 "lef.tab.c"
    break;

  case 341:
#line 3057 "lef.y"
    {
       if (lefData->versionNum < 5.6) {
         if (lefCallbacks->ViaCbk) { // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                "VIARULE statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1709, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
            }
         }
       }  else
          if (lefCallbacks->ViaCbk) lefData->lefrVia.setViaRule((yyvsp[-21].string), (yyvsp[-18].dval), (yyvsp[-17].dval), (yyvsp[-13].string), (yyvsp[-12].string), (yyvsp[-11].string),
                          (yyvsp[-8].dval), (yyvsp[-7].dval), (yyvsp[-4].dval), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval));
       lefData->viaLayer++;
       lefData->hasViaRule_layer = 1;
    }
#line 7453 "lef.tab.c"
    break;

  case 345:
#line 3083 "lef.y"
    {
       if (lefCallbacks->ViaCbk) lefData->lefrVia.setRowCol((int)(yyvsp[-2].dval), (int)(yyvsp[-1].dval));
    }
#line 7461 "lef.tab.c"
    break;

  case 346:
#line 3087 "lef.y"
    {
       if (lefCallbacks->ViaCbk) lefData->lefrVia.setOrigin((yyvsp[-2].dval), (yyvsp[-1].dval));
    }
#line 7469 "lef.tab.c"
    break;

  case 347:
#line 3091 "lef.y"
    {
       if (lefCallbacks->ViaCbk) lefData->lefrVia.setOffset((yyvsp[-4].dval), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval));
    }
#line 7477 "lef.tab.c"
    break;

  case 348:
#line 3094 "lef.y"
              {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 7483 "lef.tab.c"
    break;

  case 349:
#line 3095 "lef.y"
    {
       if (lefCallbacks->ViaCbk) lefData->lefrVia.setPattern((yyvsp[-1].string));
    }
#line 7491 "lef.tab.c"
    break;

  case 355:
#line 3112 "lef.y"
    { }
#line 7497 "lef.tab.c"
    break;

  case 356:
#line 3114 "lef.y"
    { }
#line 7503 "lef.tab.c"
    break;

  case 357:
#line 3116 "lef.y"
    { if (lefCallbacks->ViaCbk) lefData->lefrVia.setResistance((yyvsp[-1].dval)); }
#line 7509 "lef.tab.c"
    break;

  case 358:
#line 3117 "lef.y"
               { lefData->lefDumbMode = 1000000; }
#line 7515 "lef.tab.c"
    break;

  case 359:
#line 3118 "lef.y"
    { lefData->lefDumbMode = 0;
    }
#line 7522 "lef.tab.c"
    break;

  case 360:
#line 3121 "lef.y"
    { 
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->ViaCbk) lefData->lefrVia.setTopOfStack();
      } else
        if (lefCallbacks->ViaCbk)  // write warning only if cbk is set 
           if (lefData->viaWarnings++ < lefSettings->ViaWarnings)
              lefWarning(2019, "TOPOFSTACKONLY statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later");
    }
#line 7535 "lef.tab.c"
    break;

  case 363:
#line 3137 "lef.y"
    { 
      char temp[32];
      sprintf(temp, "%.11g", (yyvsp[0].dval));
      if (lefCallbacks->ViaCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrViaProp.propType((yyvsp[-1].string));
         lefData->lefrVia.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), temp, propTp);
      }
    }
#line 7549 "lef.tab.c"
    break;

  case 364:
#line 3147 "lef.y"
    {
      if (lefCallbacks->ViaCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrViaProp.propType((yyvsp[-1].string));
         lefData->lefrVia.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 7561 "lef.tab.c"
    break;

  case 365:
#line 3155 "lef.y"
    {
      if (lefCallbacks->ViaCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrViaProp.propType((yyvsp[-1].string));
         lefData->lefrVia.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 7573 "lef.tab.c"
    break;

  case 366:
#line 3165 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->ViaCbk) lefData->lefrVia.setForeign((yyvsp[-1].string), 0, 0.0, 0.0, -1);
      } else
        if (lefCallbacks->ViaCbk)  // write warning only if cbk is set 
           if (lefData->viaWarnings++ < lefSettings->ViaWarnings)
             lefWarning(2020, "FOREIGN statement in VIA is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 7586 "lef.tab.c"
    break;

  case 367:
#line 3174 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->ViaCbk) lefData->lefrVia.setForeign((yyvsp[-2].string), 1, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, -1);
      } else
        if (lefCallbacks->ViaCbk)  // write warning only if cbk is set 
           if (lefData->viaWarnings++ < lefSettings->ViaWarnings)
             lefWarning(2020, "FOREIGN statement in VIA is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 7599 "lef.tab.c"
    break;

  case 368:
#line 3183 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->ViaCbk) lefData->lefrVia.setForeign((yyvsp[-3].string), 1, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].integer));
      } else
        if (lefCallbacks->ViaCbk)  // write warning only if cbk is set 
           if (lefData->viaWarnings++ < lefSettings->ViaWarnings)
             lefWarning(2020, "FOREIGN statement in VIA is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 7612 "lef.tab.c"
    break;

  case 369:
#line 3192 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->ViaCbk) lefData->lefrVia.setForeign((yyvsp[-2].string), 0, 0.0, 0.0, (yyvsp[-1].integer));
      } else
        if (lefCallbacks->ViaCbk)  // write warning only if cbk is set 
           if (lefData->viaWarnings++ < lefSettings->ViaWarnings)
             lefWarning(2020, "FOREIGN statement in VIA is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 7625 "lef.tab.c"
    break;

  case 370:
#line 3201 "lef.y"
                                {lefData->lefDumbMode = 1; lefData->lefNoNum= 1;}
#line 7631 "lef.tab.c"
    break;

  case 371:
#line 3202 "lef.y"
    { (yyval.string) = (yyvsp[0].string); }
#line 7637 "lef.tab.c"
    break;

  case 372:
#line 3205 "lef.y"
              {(yyval.integer) = 0;}
#line 7643 "lef.tab.c"
    break;

  case 373:
#line 3206 "lef.y"
              {(yyval.integer) = 1;}
#line 7649 "lef.tab.c"
    break;

  case 374:
#line 3207 "lef.y"
              {(yyval.integer) = 2;}
#line 7655 "lef.tab.c"
    break;

  case 375:
#line 3208 "lef.y"
              {(yyval.integer) = 3;}
#line 7661 "lef.tab.c"
    break;

  case 376:
#line 3209 "lef.y"
              {(yyval.integer) = 4;}
#line 7667 "lef.tab.c"
    break;

  case 377:
#line 3210 "lef.y"
              {(yyval.integer) = 5;}
#line 7673 "lef.tab.c"
    break;

  case 378:
#line 3211 "lef.y"
              {(yyval.integer) = 6;}
#line 7679 "lef.tab.c"
    break;

  case 379:
#line 3212 "lef.y"
              {(yyval.integer) = 7;}
#line 7685 "lef.tab.c"
    break;

  case 380:
#line 3213 "lef.y"
              {(yyval.integer) = 0;}
#line 7691 "lef.tab.c"
    break;

  case 381:
#line 3214 "lef.y"
              {(yyval.integer) = 1;}
#line 7697 "lef.tab.c"
    break;

  case 382:
#line 3215 "lef.y"
              {(yyval.integer) = 2;}
#line 7703 "lef.tab.c"
    break;

  case 383:
#line 3216 "lef.y"
              {(yyval.integer) = 3;}
#line 7709 "lef.tab.c"
    break;

  case 384:
#line 3217 "lef.y"
              {(yyval.integer) = 4;}
#line 7715 "lef.tab.c"
    break;

  case 385:
#line 3218 "lef.y"
              {(yyval.integer) = 5;}
#line 7721 "lef.tab.c"
    break;

  case 386:
#line 3219 "lef.y"
              {(yyval.integer) = 6;}
#line 7727 "lef.tab.c"
    break;

  case 387:
#line 3220 "lef.y"
              {(yyval.integer) = 7;}
#line 7733 "lef.tab.c"
    break;

  case 388:
#line 3223 "lef.y"
    { }
#line 7739 "lef.tab.c"
    break;

  case 389:
#line 3225 "lef.y"
                   {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 7745 "lef.tab.c"
    break;

  case 390:
#line 3226 "lef.y"
    {
      if (lefCallbacks->ViaCbk) lefData->lefrVia.addLayer((yyvsp[-1].string));
      lefData->viaLayer++;
      lefData->hasViaRule_layer = 1;
    }
#line 7755 "lef.tab.c"
    break;

  case 393:
#line 3239 "lef.y"
    { 
      if (lefCallbacks->ViaCbk) {
        if (lefData->versionNum < 5.8 && (int)(yyvsp[-3].integer) > 0) {
          if (lefData->viaWarnings++ < lefSettings->ViaWarnings) {
              lefError(2081, "MASK information can only be defined with version 5.8");
              CHKERR(); 
            }           
        } else {
          lefData->lefrVia.addRectToLayer((int)(yyvsp[-3].integer), (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y);
        }
      }
    }
#line 7772 "lef.tab.c"
    break;

  case 394:
#line 3252 "lef.y"
    {
      lefData->lefrGeometriesPtr = (lefiGeometries*)lefMalloc(sizeof(lefiGeometries));
      lefData->lefrGeometriesPtr->Init();
      lefData->lefrDoGeometries = 1;
    }
#line 7782 "lef.tab.c"
    break;

  case 395:
#line 3258 "lef.y"
    { 
      if (lefCallbacks->ViaCbk) {
        if (lefData->versionNum < 5.8 && (yyvsp[-6].integer) > 0) {
          if (lefData->viaWarnings++ < lefSettings->ViaWarnings) {
              lefError(2083, "Color mask information can only be defined with version 5.8.");
              CHKERR(); 
            }           
        } else {
            lefData->lefrGeometriesPtr->addPolygon((int)(yyvsp[-6].integer));
            lefData->lefrVia.addPolyToLayer((int)(yyvsp[-6].integer), lefData->lefrGeometriesPtr);   // 5.6
        }
      }
      lefData->lefrGeometriesPtr->clearPolyItems(); // free items fields
      lefFree((char*)(lefData->lefrGeometriesPtr)); // Don't need anymore, poly data has
      lefData->lefrDoGeometries = 0;                // copied
    }
#line 7803 "lef.tab.c"
    break;

  case 396:
#line 3275 "lef.y"
               {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 7809 "lef.tab.c"
    break;

  case 397:
#line 3276 "lef.y"
    { 
      // 10/17/2001 - Wanda da Rosa, PCR 404149
      //              Error if no layer in via
      if (!lefData->viaLayer) {
         if (lefCallbacks->ViaCbk) {  // write error only if cbk is set 
            if (lefData->viaWarnings++ < lefSettings->ViaWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                "A LAYER statement is missing in the VIA %s.\nAt least one LAYERis required per VIA statement.", (yyvsp[0].string));
              lefError(1606, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
            }
         }
      }
      if (strcmp(lefData->viaName, (yyvsp[0].string)) != 0) {
         if (lefCallbacks->ViaCbk) { // write error only if cbk is set 
            if (lefData->viaWarnings++ < lefSettings->ViaWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                "END VIA name %s is different from the VIA name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->viaName);
              lefError(1607, lefData->outMsg);
              lefFree(lefData->outMsg);
              lefFree(lefData->viaName);
              CHKERR();
            } else
              lefFree(lefData->viaName);
         } else
            lefFree(lefData->viaName);
      } else
         lefFree(lefData->viaName);
    }
#line 7846 "lef.tab.c"
    break;

  case 398:
#line 3309 "lef.y"
                            { lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 7852 "lef.tab.c"
    break;

  case 399:
#line 3310 "lef.y"
    { 
      if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setName((yyvsp[0].string));
      lefData->viaRuleLayer = 0;
      //strcpy(lefData->viaRuleName, $3);
      lefData->viaRuleName = strdup((yyvsp[0].string));
      lefData->isGenerate = 0;
    }
#line 7864 "lef.tab.c"
    break;

  case 400:
#line 3320 "lef.y"
    {
      if (lefData->viaRuleLayer == 0 || lefData->viaRuleLayer > 2) {
         if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefError(1608, "A VIARULE statement requires two layers.");
              CHKERR();
            }
         }
      }
      if (lefCallbacks->ViaRuleCbk)
        CALLBACK(lefCallbacks->ViaRuleCbk, lefrViaRuleCbkType, &lefData->lefrViaRule);
      // 2/19/2004 - reset the ENCLOSURE overhang values which may be
      // set by the old syntax OVERHANG -- Not necessary, but just incase
      if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.clearLayerOverhang();
    }
#line 7884 "lef.tab.c"
    break;

  case 401:
#line 3338 "lef.y"
    {
      lefData->isGenerate = 1;
    }
#line 7892 "lef.tab.c"
    break;

  case 402:
#line 3342 "lef.y"
    {
      if (lefData->viaRuleLayer == 0) {
         if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefError(1708, "A VIARULE GENERATE requires three layers.");
              CHKERR();
            }
         }
      } else if ((lefData->viaRuleLayer < 3) && (lefData->versionNum >= 5.6)) {
         if (lefCallbacks->ViaRuleCbk)  // write warning only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings)
              lefWarning(2021, "turn-via is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
      } else {
         if (lefCallbacks->ViaRuleCbk) {
            lefData->lefrViaRule.setGenerate();
            CALLBACK(lefCallbacks->ViaRuleCbk, lefrViaRuleCbkType, &lefData->lefrViaRule);
         }
      }
      // 2/19/2004 - reset the ENCLOSURE overhang values which may be
      // set by the old syntax OVERHANG
      if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.clearLayerOverhang();
    }
#line 7919 "lef.tab.c"
    break;

  case 404:
#line 3367 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
         if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                "DEFAULT statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1605, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
            }
         }
      } else
        if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setDefault();
    }
#line 7939 "lef.tab.c"
    break;

  case 411:
#line 3398 "lef.y"
                         { lefData->lefDumbMode = 10000000;}
#line 7945 "lef.tab.c"
    break;

  case 412:
#line 3399 "lef.y"
    { lefData->lefDumbMode = 0;
    }
#line 7952 "lef.tab.c"
    break;

  case 415:
#line 3409 "lef.y"
    {
      if (lefCallbacks->ViaRuleCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrViaRuleProp.propType((yyvsp[-1].string));
         lefData->lefrViaRule.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 7964 "lef.tab.c"
    break;

  case 416:
#line 3417 "lef.y"
    {
      if (lefCallbacks->ViaRuleCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrViaRuleProp.propType((yyvsp[-1].string));
         lefData->lefrViaRule.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 7976 "lef.tab.c"
    break;

  case 417:
#line 3425 "lef.y"
    {
      char temp[32];
      sprintf(temp, "%.11g", (yyvsp[0].dval));
      if (lefCallbacks->ViaRuleCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrViaRuleProp.propType((yyvsp[-1].string));
         lefData->lefrViaRule.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), temp, propTp);
      }
    }
#line 7990 "lef.tab.c"
    break;

  case 418:
#line 3436 "lef.y"
    {
      // 10/18/2001 - Wanda da Rosa PCR 404181
      //              Make sure the 1st 2 layers in viarule has direction
      // 04/28/2004 - PCR 704072 - DIRECTION in viarule generate is
      //              obsolete in 5.6
      if (lefData->versionNum >= 5.6) {
         if (lefData->viaRuleLayer < 2 && !lefData->viaRuleHasDir && !lefData->viaRuleHasEnc &&
             !lefData->isGenerate) {
            if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
               if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
                  lefError(1705, "VIARULE statement in a layer, requires a DIRECTION construct statement.");
                  CHKERR(); 
               }
            }
         }
      } else {
         if (lefData->viaRuleLayer < 2 && !lefData->viaRuleHasDir && !lefData->viaRuleHasEnc &&
             lefData->isGenerate) {
            if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
               if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
                  lefError(1705, "VIARULE statement in a layer, requires a DIRECTION construct statement.");
                  CHKERR(); 
               }
            }
         }
      }
      lefData->viaRuleLayer++;
    }
#line 8023 "lef.tab.c"
    break;

  case 421:
#line 3472 "lef.y"
    { if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.addViaName((yyvsp[-1].string)); }
#line 8029 "lef.tab.c"
    break;

  case 422:
#line 3474 "lef.y"
                            {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 8035 "lef.tab.c"
    break;

  case 423:
#line 3475 "lef.y"
    { if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setLayer((yyvsp[-1].string));
      lefData->viaRuleHasDir = 0;
      lefData->viaRuleHasEnc = 0;
    }
#line 8044 "lef.tab.c"
    break;

  case 426:
#line 3487 "lef.y"
    {
      if (lefData->viaRuleHasEnc) {
        if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefError(1706, "An ENCLOSRE statement was already defined in the layer.\nIt is DIRECTION or ENCLOSURE can be specified in a layer.");
              CHKERR();
           }
        }
      } else {
        if ((lefData->versionNum < 5.6) || (!lefData->isGenerate)) {
          if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setHorizontal();
        } else
          if (lefCallbacks->ViaRuleCbk)  // write warning only if cbk is set 
             if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings)
               lefWarning(2022, "DIRECTION statement in VIARULE is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
      }
      lefData->viaRuleHasDir = 1;
    }
#line 8067 "lef.tab.c"
    break;

  case 427:
#line 3506 "lef.y"
    { 
      if (lefData->viaRuleHasEnc) {
        if (lefCallbacks->ViaRuleCbk) { // write error only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefError(1706, "An ENCLOSRE statement was already defined in the layer.\nIt is DIRECTION or ENCLOSURE can be specified in a layer.");
              CHKERR();
           }
        }
      } else {
        if ((lefData->versionNum < 5.6) || (!lefData->isGenerate)) {
          if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setVertical();
        } else
          if (lefCallbacks->ViaRuleCbk) // write warning only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings)
              lefWarning(2022, "DIRECTION statement in VIARULE is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
      }
      lefData->viaRuleHasDir = 1;
    }
#line 8090 "lef.tab.c"
    break;

  case 428:
#line 3525 "lef.y"
    {
      if (lefData->versionNum < 5.5) {
         if (lefCallbacks->ViaRuleCbk) { // write error only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                "ENCLOSURE statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1707, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
         }
      }
      // 2/19/2004 - Enforced the rule that ENCLOSURE can only be defined
      // in VIARULE GENERATE
      if (!lefData->isGenerate) {
         if (lefCallbacks->ViaRuleCbk) { // write error only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefError(1614, "An ENCLOSURE statement is defined in a VIARULE statement only.\nOVERHANG statement can only be defined in VIARULE GENERATE.");
              CHKERR();
           }
         }
      }
      if (lefData->viaRuleHasDir) {
         if (lefCallbacks->ViaRuleCbk) { // write error only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefError(1609, "A DIRECTION statement was already defined in the layer.\nIt is DIRECTION or ENCLOSURE can be specified in a layer.");
              CHKERR();
           }
         }
      } else {
         if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setEnclosure((yyvsp[-2].dval), (yyvsp[-1].dval));
      }
      lefData->viaRuleHasEnc = 1;
    }
#line 8130 "lef.tab.c"
    break;

  case 429:
#line 3561 "lef.y"
    { if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setWidth((yyvsp[-3].dval),(yyvsp[-1].dval)); }
#line 8136 "lef.tab.c"
    break;

  case 430:
#line 3563 "lef.y"
    { if (lefCallbacks->ViaRuleCbk)
        lefData->lefrViaRule.setRect((yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y); }
#line 8143 "lef.tab.c"
    break;

  case 431:
#line 3566 "lef.y"
    { if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setSpacing((yyvsp[-3].dval),(yyvsp[-1].dval)); }
#line 8149 "lef.tab.c"
    break;

  case 432:
#line 3568 "lef.y"
    { if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setResistance((yyvsp[-1].dval)); }
#line 8155 "lef.tab.c"
    break;

  case 433:
#line 3570 "lef.y"
    {
      if (!lefData->viaRuleHasDir) {
         if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
               lefError(1610, "An OVERHANG statement is defined, but the required DIRECTION statement is not yet defined.\nUpdate the LEF file to define the DIRECTION statement before the OVERHANG.");
               CHKERR();
            }
         }
      }
      // 2/19/2004 - Enforced the rule that OVERHANG can only be defined
      // in VIARULE GENERATE after 5.3
      if ((lefData->versionNum > 5.3) && (!lefData->isGenerate)) {
         if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
               lefError(1611, "An OVERHANG statement is defined in a VIARULE statement only.\nOVERHANG statement can only be defined in VIARULE GENERATE.");
               CHKERR();
            }
         }
      }
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setOverhang((yyvsp[-1].dval));
      } else {
        if (lefCallbacks->ViaRuleCbk)  // write warning only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings)
              lefWarning(2023, "OVERHANG statement will be translated into similar ENCLOSURE rule");
        // In 5.6 & later, set it to either ENCLOSURE overhang1 or overhang2
        if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setOverhangToEnclosure((yyvsp[-1].dval));
      }
    }
#line 8189 "lef.tab.c"
    break;

  case 434:
#line 3600 "lef.y"
    {
      // 2/19/2004 - Enforced the rule that METALOVERHANG can only be defined
      // in VIARULE GENERATE
      if ((lefData->versionNum > 5.3) && (!lefData->isGenerate)) {
         if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
            if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
               lefError(1612, "An METALOVERHANG statement is defined in a VIARULE statement only.\nOVERHANG statement can only be defined in VIARULE GENERATE.");
               CHKERR();
            }
         }
      }
      if (lefData->versionNum < 5.6) {
        if (!lefData->viaRuleHasDir) {
           if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
             if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
                lefError(1613, "An METALOVERHANG statement is defined, but the required DIRECTION statement is not yet defined.\nUpdate the LEF file to define the DIRECTION statement before the OVERHANG.");
                CHKERR();
             } 
           }
        }
        if (lefCallbacks->ViaRuleCbk) lefData->lefrViaRule.setMetalOverhang((yyvsp[-1].dval));
      } else
        if (lefCallbacks->ViaRuleCbk)  // write warning only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings)
             lefWarning(2024, "METALOVERHANG statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 8220 "lef.tab.c"
    break;

  case 435:
#line 3627 "lef.y"
                   {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 8226 "lef.tab.c"
    break;

  case 436:
#line 3628 "lef.y"
    {
      if ((lefData->isGenerate) && (lefCallbacks->ViaRuleCbk) && lefData->lefrViaRule.numLayers() >= 3) {         
        if (!lefData->lefrViaRule.layer(0)->hasRect() &&
            !lefData->lefrViaRule.layer(1)->hasRect() &&
            !lefData->lefrViaRule.layer(2)->hasRect()) {
            lefData->outMsg = (char*)lefMalloc(10000);
            sprintf (lefData->outMsg, 
                     "VIARULE GENERATE '%s' cut layer definition should have RECT statement.\nCorrect the LEF file before rerunning it through the LEF parser.", 
                      lefData->viaRuleName);
            lefWarning(1714, lefData->outMsg); 
            lefFree(lefData->outMsg);            
            CHKERR();                
        }
      }

      if (strcmp(lefData->viaRuleName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->ViaRuleCbk) {  // write error only if cbk is set 
           if (lefData->viaRuleWarnings++ < lefSettings->ViaRuleWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "END VIARULE name %s is different from the VIARULE name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->viaRuleName);
              lefError(1615, lefData->outMsg);
              lefFree(lefData->outMsg);
              lefFree(lefData->viaRuleName);
              CHKERR();
           } else
              lefFree(lefData->viaRuleName);
        } else
           lefFree(lefData->viaRuleName);
      } else
        lefFree(lefData->viaRuleName);
    }
#line 8263 "lef.tab.c"
    break;

  case 437:
#line 3662 "lef.y"
    { }
#line 8269 "lef.tab.c"
    break;

  case 438:
#line 3665 "lef.y"
    {
      lefData->hasSamenet = 0;
      if ((lefData->versionNum < 5.6) || (!lefData->ndRule)) {
        // if 5.6 and in nondefaultrule, it should not get in here, 
        // it should go to the else statement to write out a warning 
        // if 5.6, not in nondefaultrule, it will get in here 
        // if 5.5 and earlier in nondefaultrule is ok to get in here 
        if (lefData->versionNum >= 5.7) { // will get to this if statement if  
                           // lefData->versionNum is 5.6 and higher but lefData->ndRule = 0 
           if (lefData->spacingWarnings == 0) {  // only print once 
              lefWarning(2077, "A SPACING SAMENET section is defined but it is not legal in a LEF 5.7 version file.\nIt will be ignored which will probably cause real DRC violations to be ignored, and may\ncause false DRC violations to occur.\n\nTo avoid this warning, and correctly handle these DRC rules, you should modify your\nLEF to use the appropriate SAMENET keywords as described in the LEF/DEF 5.7\nmanual under the SPACING statements in the LAYER (Routing) and LAYER (Cut)\nsections listed in the LEF Table of Contents.");
              lefData->spacingWarnings++;
           }
        } else if (lefCallbacks->SpacingBeginCbk && !lefData->ndRule)
          CALLBACK(lefCallbacks->SpacingBeginCbk, lefrSpacingBeginCbkType, 0);
      } else
        if (lefCallbacks->SpacingBeginCbk && !lefData->ndRule)  // write warning only if cbk is set 
           if (lefData->spacingWarnings++ < lefSettings->SpacingWarnings)
             lefWarning(2025, "SAMENET statement in NONDEFAULTRULE is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 8294 "lef.tab.c"
    break;

  case 439:
#line 3687 "lef.y"
    {
      if ((lefData->versionNum < 5.6) || (!lefData->ndRule)) {
        if ((lefData->versionNum <= 5.4) && (!lefData->hasSamenet)) {
           lefError(1616, "SAMENET statement is required inside SPACING for any lef file with version 5.4 and earlier, but is not defined in the parsed lef file.");
           CHKERR();
        } else if (lefData->versionNum < 5.7) { // obsolete in 5.7 and later 
           if (lefCallbacks->SpacingEndCbk && !lefData->ndRule)
             CALLBACK(lefCallbacks->SpacingEndCbk, lefrSpacingEndCbkType, 0);
        }
      }
    }
#line 8310 "lef.tab.c"
    break;

  case 442:
#line 3705 "lef.y"
    {
      if ((lefData->versionNum < 5.6) || (!lefData->ndRule)) {
        if (lefData->versionNum < 5.7) {
          if (lefCallbacks->SpacingCbk) {
            lefData->lefrSpacing.set((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].dval), 0);
            if (lefData->ndRule)
                lefData->nd->addSpacingRule(&lefData->lefrSpacing);
            else 
                CALLBACK(lefCallbacks->SpacingCbk, lefrSpacingCbkType, &lefData->lefrSpacing);            
          }
        }
      }
    }
#line 8328 "lef.tab.c"
    break;

  case 443:
#line 3719 "lef.y"
    {
      if ((lefData->versionNum < 5.6) || (!lefData->ndRule)) {
        if (lefData->versionNum < 5.7) {
          if (lefCallbacks->SpacingCbk) {
            lefData->lefrSpacing.set((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-2].dval), 1);
            if (lefData->ndRule)
                lefData->nd->addSpacingRule(&lefData->lefrSpacing);
            else 
                CALLBACK(lefCallbacks->SpacingCbk, lefrSpacingCbkType, &lefData->lefrSpacing);    
          }
        }
      }
    }
#line 8346 "lef.tab.c"
    break;

  case 444:
#line 3735 "lef.y"
    { lefData->lefDumbMode = 2; lefData->lefNoNum = 2; lefData->hasSamenet = 1; }
#line 8352 "lef.tab.c"
    break;

  case 445:
#line 3739 "lef.y"
    { (yyval.integer) = 0; }
#line 8358 "lef.tab.c"
    break;

  case 446:
#line 3741 "lef.y"
    { (yyval.integer) = (int)(yyvsp[0].dval); }
#line 8364 "lef.tab.c"
    break;

  case 447:
#line 3744 "lef.y"
    { }
#line 8370 "lef.tab.c"
    break;

  case 448:
#line 3747 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->IRDropBeginCbk) 
          CALLBACK(lefCallbacks->IRDropBeginCbk, lefrIRDropBeginCbkType, 0);
      } else
        if (lefCallbacks->IRDropBeginCbk) // write warning only if cbk is set 
          if (lefData->iRDropWarnings++ < lefSettings->IRDropWarnings)
            lefWarning(2026, "IRDROP statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 8384 "lef.tab.c"
    break;

  case 449:
#line 3758 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->IRDropEndCbk)
          CALLBACK(lefCallbacks->IRDropEndCbk, lefrIRDropEndCbkType, 0);
      }
    }
#line 8395 "lef.tab.c"
    break;

  case 452:
#line 3772 "lef.y"
    { 
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->IRDropCbk)
          CALLBACK(lefCallbacks->IRDropCbk, lefrIRDropCbkType, &lefData->lefrIRDrop);
      }
    }
#line 8406 "lef.tab.c"
    break;

  case 455:
#line 3785 "lef.y"
  { if (lefCallbacks->IRDropCbk) lefData->lefrIRDrop.setValues((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 8412 "lef.tab.c"
    break;

  case 456:
#line 3788 "lef.y"
  { if (lefCallbacks->IRDropCbk) lefData->lefrIRDrop.setTableName((yyvsp[0].string)); }
#line 8418 "lef.tab.c"
    break;

  case 457:
#line 3791 "lef.y"
  {
    lefData->hasMinfeature = 1;
    if (lefData->versionNum < 5.4) {
       if (lefCallbacks->MinFeatureCbk) {
         lefData->lefrMinFeature.set((yyvsp[-2].dval), (yyvsp[-1].dval));
         CALLBACK(lefCallbacks->MinFeatureCbk, lefrMinFeatureCbkType, &lefData->lefrMinFeature);
       }
    } else
       if (lefCallbacks->MinFeatureCbk) // write warning only if cbk is set 
          if (lefData->minFeatureWarnings++ < lefSettings->MinFeatureWarnings)
            lefWarning(2027, "MINFEATURE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
  }
#line 8435 "lef.tab.c"
    break;

  case 458:
#line 3805 "lef.y"
  {
    if (lefData->versionNum < 5.4) {
       if (lefCallbacks->DielectricCbk)
         CALLBACK(lefCallbacks->DielectricCbk, lefrDielectricCbkType, (yyvsp[-1].dval));
    } else
       if (lefCallbacks->DielectricCbk) // write warning only if cbk is set 
         if (lefData->dielectricWarnings++ < lefSettings->DielectricWarnings)
           lefWarning(2028, "DIELECTRIC statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
  }
#line 8449 "lef.tab.c"
    break;

  case 459:
#line 3815 "lef.y"
                                  {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 8455 "lef.tab.c"
    break;

  case 460:
#line 3816 "lef.y"
  {
    (void)lefSetNonDefault((yyvsp[0].string));
    if (lefCallbacks->NonDefaultCbk) lefData->lefrNonDefault.setName((yyvsp[0].string));
    lefData->ndLayer = 0;
    lefData->ndRule = 1;
    lefData->numVia = 0;
    //strcpy(lefData->nonDefaultRuleName, $3);
    lefData->nonDefaultRuleName = strdup((yyvsp[0].string));
  }
#line 8469 "lef.tab.c"
    break;

  case 461:
#line 3826 "lef.y"
           {lefData->lefNdRule = 1;}
#line 8475 "lef.tab.c"
    break;

  case 462:
#line 3827 "lef.y"
  {
    // 10/18/2001 - Wanda da Rosa, PCR 404189
    //              At least 1 layer is required
    if ((!lefData->ndLayer) && (!lefSettings->RelaxMode)) {
       if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
         if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
            lefError(1617, "NONDEFAULTRULE statement requires at least one LAYER statement.");
            CHKERR();
         }
       }
    }
    if ((!lefData->numVia) && (!lefSettings->RelaxMode) && (lefData->versionNum < 5.6)) {
       // VIA is no longer a required statement in 5.6
       if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
         if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
            lefError(1618, "NONDEFAULTRULE statement requires at least one VIA statement.");
            CHKERR();
         }
       }
    }
    if (lefCallbacks->NonDefaultCbk) {
      lefData->lefrNonDefault.end();
      CALLBACK(lefCallbacks->NonDefaultCbk, lefrNonDefaultCbkType, &lefData->lefrNonDefault);
    }
    lefData->ndRule = 0;
    lefData->lefDumbMode = 0;
    (void)lefUnsetNonDefault();
  }
#line 8508 "lef.tab.c"
    break;

  case 463:
#line 3857 "lef.y"
    {
      if ((lefData->nonDefaultRuleName) && (*lefData->nonDefaultRuleName != '\0'))
        lefFree(lefData->nonDefaultRuleName);
    }
#line 8517 "lef.tab.c"
    break;

  case 464:
#line 3862 "lef.y"
    {
      if (strcmp(lefData->nonDefaultRuleName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
          if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
             lefData->outMsg = (char*)lefMalloc(10000);
             sprintf (lefData->outMsg,
                "END NONDEFAULTRULE name %s is different from the NONDEFAULTRULE name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->nonDefaultRuleName);
             lefError(1619, lefData->outMsg);
             lefFree(lefData->nonDefaultRuleName);
             lefFree(lefData->outMsg);
             CHKERR();
          } else
             lefFree(lefData->nonDefaultRuleName);
        } else
           lefFree(lefData->nonDefaultRuleName);
      } else
        lefFree(lefData->nonDefaultRuleName);
    }
#line 8540 "lef.tab.c"
    break;

  case 466:
#line 3885 "lef.y"
    {
       if (lefData->versionNum < 5.6) {
          if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "HARDSPACING statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1620, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
          }
       } else 
          if (lefCallbacks->NonDefaultCbk)
             lefData->lefrNonDefault.setHardspacing();
    }
#line 8561 "lef.tab.c"
    break;

  case 476:
#line 3918 "lef.y"
    {
       if (lefData->versionNum < 5.6) {
          if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
             lefData->outMsg = (char*)lefMalloc(10000);
             sprintf (lefData->outMsg,
               "USEVIA statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
             lefError(1621, lefData->outMsg);
             lefFree(lefData->outMsg);
             CHKERR();
          }
       } else {
          if (lefCallbacks->NonDefaultCbk)
             lefData->lefrNonDefault.addUseVia((yyvsp[-1].string));
       }
    }
#line 8581 "lef.tab.c"
    break;

  case 477:
#line 3935 "lef.y"
    {
       if (lefData->versionNum < 5.6) {
          if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
             if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
                lefData->outMsg = (char*)lefMalloc(10000);
                sprintf (lefData->outMsg,
                  "USEVIARULE statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                lefError(1622, lefData->outMsg);
                lefFree(lefData->outMsg);
                CHKERR();
             }
          }
       } else {
          if (lefCallbacks->NonDefaultCbk)
             lefData->lefrNonDefault.addUseViaRule((yyvsp[-1].string));
       }
    }
#line 8603 "lef.tab.c"
    break;

  case 478:
#line 3954 "lef.y"
    {
       if (lefData->versionNum < 5.6) {
          if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
             if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
                lefData->outMsg = (char*)lefMalloc(10000);
                sprintf (lefData->outMsg,
                  "MINCUTS statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                lefError(1623, lefData->outMsg);
                lefFree(lefData->outMsg);
                CHKERR();
             }
          }
       } else {
          if (lefCallbacks->NonDefaultCbk)
             lefData->lefrNonDefault.addMinCuts((yyvsp[-2].string), (int)(yyvsp[-1].dval));
       }
    }
#line 8625 "lef.tab.c"
    break;

  case 479:
#line 3972 "lef.y"
                    { lefData->lefDumbMode = 10000000;}
#line 8631 "lef.tab.c"
    break;

  case 480:
#line 3973 "lef.y"
    { lefData->lefDumbMode = 0;
    }
#line 8638 "lef.tab.c"
    break;

  case 483:
#line 3983 "lef.y"
    {
      if (lefCallbacks->NonDefaultCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrNondefProp.propType((yyvsp[-1].string));
         lefData->lefrNonDefault.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 8650 "lef.tab.c"
    break;

  case 484:
#line 3991 "lef.y"
    {
      if (lefCallbacks->NonDefaultCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrNondefProp.propType((yyvsp[-1].string));
         lefData->lefrNonDefault.addProp((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 8662 "lef.tab.c"
    break;

  case 485:
#line 3999 "lef.y"
    {
      if (lefCallbacks->NonDefaultCbk) {
         char temp[32];
         char propTp;
         sprintf(temp, "%.11g", (yyvsp[0].dval));
         propTp = lefSettings->lefProps.lefrNondefProp.propType((yyvsp[-1].string));
         lefData->lefrNonDefault.addNumProp((yyvsp[-1].string), (yyvsp[0].dval), temp, propTp);
      }
    }
#line 8676 "lef.tab.c"
    break;

  case 486:
#line 4009 "lef.y"
                  {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 8682 "lef.tab.c"
    break;

  case 487:
#line 4010 "lef.y"
  {
    if (lefCallbacks->NonDefaultCbk) lefData->lefrNonDefault.addLayer((yyvsp[0].string));
    lefData->ndLayer++;
    //strcpy(lefData->layerName, $3);
    lefData->layerName = strdup((yyvsp[0].string));
    lefData->ndLayerWidth = 0;
    lefData->ndLayerSpace = 0;
  }
#line 8695 "lef.tab.c"
    break;

  case 488:
#line 4019 "lef.y"
  { 
    lefData->ndLayerWidth = 1;
    if (lefCallbacks->NonDefaultCbk) lefData->lefrNonDefault.addWidth((yyvsp[-1].dval));
  }
#line 8704 "lef.tab.c"
    break;

  case 489:
#line 4023 "lef.y"
                       {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 8710 "lef.tab.c"
    break;

  case 490:
#line 4024 "lef.y"
  {
    if (strcmp(lefData->layerName, (yyvsp[0].string)) != 0) {
      if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
         if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
            lefData->outMsg = (char*)lefMalloc(10000);
            sprintf (lefData->outMsg,
               "END LAYER name %s is different from the LAYER name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[-9].string), lefData->layerName);
            lefError(1624, lefData->outMsg);
            lefFree(lefData->outMsg);
            lefFree(lefData->layerName);
            CHKERR();
         } else
            lefFree(lefData->layerName);
      } else
         lefFree(lefData->layerName);
    } else
      lefFree(lefData->layerName);
    if (!lefData->ndLayerWidth) {
      if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
         if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
            lefError(1625, "A WIDTH statement is required in the LAYER statement in NONDEFULTRULE.");
            CHKERR();
         }
      }
    }
    if (!lefData->ndLayerSpace && lefData->versionNum < 5.6) {   // 5.6, SPACING is optional
      if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
         if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
            lefData->outMsg = (char*)lefMalloc(10000);
            sprintf (lefData->outMsg,
               "A SPACING statement is required in the LAYER statement in NONDEFAULTRULE for lef file with version 5.5 and earlier.\nYour lef file is defined with version %g. Update your lef to add a LAYER statement and try again.",
                lefData->versionNum);
            lefError(1626, lefData->outMsg);
            lefFree(lefData->outMsg);
            CHKERR();
         }
      }
    }
  }
#line 8754 "lef.tab.c"
    break;

  case 493:
#line 4072 "lef.y"
    {
      lefData->ndLayerSpace = 1;
      if (lefCallbacks->NonDefaultCbk) lefData->lefrNonDefault.addSpacing((yyvsp[-1].dval));
    }
#line 8763 "lef.tab.c"
    break;

  case 494:
#line 4077 "lef.y"
    { if (lefCallbacks->NonDefaultCbk)
         lefData->lefrNonDefault.addWireExtension((yyvsp[-1].dval)); }
#line 8770 "lef.tab.c"
    break;

  case 495:
#line 4080 "lef.y"
    {
      if (lefData->ignoreVersion) {
         if (lefCallbacks->NonDefaultCbk)
            lefData->lefrNonDefault.addResistance((yyvsp[-1].dval));
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "RESISTANCE RPERSQ statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1627, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->versionNum > 5.5) {  // obsolete in 5.6
         if (lefCallbacks->NonDefaultCbk) // write warning only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings)
              lefWarning(2029, "RESISTANCE RPERSQ statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
      } else if (lefCallbacks->NonDefaultCbk)
         lefData->lefrNonDefault.addResistance((yyvsp[-1].dval));
    }
#line 8797 "lef.tab.c"
    break;

  case 496:
#line 4104 "lef.y"
    {
      if (lefData->ignoreVersion) {
         if (lefCallbacks->NonDefaultCbk)
            lefData->lefrNonDefault.addCapacitance((yyvsp[-1].dval));
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "CAPACITANCE CPERSQDIST statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1628, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
            }
         }
      } else if (lefData->versionNum > 5.5) { // obsolete in 5.6
         if (lefCallbacks->NonDefaultCbk) // write warning only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings)
              lefWarning(2030, "CAPACITANCE CPERSQDIST statement is obsolete in version 5.6. and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
      } else if (lefCallbacks->NonDefaultCbk)
         lefData->lefrNonDefault.addCapacitance((yyvsp[-1].dval));
    }
#line 8824 "lef.tab.c"
    break;

  case 497:
#line 4127 "lef.y"
    {
      if (lefData->ignoreVersion) {
         if (lefCallbacks->NonDefaultCbk)
            lefData->lefrNonDefault.addEdgeCap((yyvsp[-1].dval));
      } else if (lefData->versionNum < 5.4) {
         if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "EDGECAPACITANCE statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1629, lefData->outMsg);
               lefFree(lefData->outMsg);
              CHKERR();
            }
         }
      } else if (lefData->versionNum > 5.5) {  // obsolete in 5.6
         if (lefCallbacks->NonDefaultCbk) // write warning only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings)
              lefWarning(2031, "EDGECAPACITANCE statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
      } else if (lefCallbacks->NonDefaultCbk)
         lefData->lefrNonDefault.addEdgeCap((yyvsp[-1].dval));
    }
#line 8851 "lef.tab.c"
    break;

  case 498:
#line 4150 "lef.y"
    {
      if (lefData->versionNum < 5.6) {  // 5.6 syntax
         if (lefCallbacks->NonDefaultCbk) { // write error only if cbk is set 
            if (lefData->nonDefaultWarnings++ < lefSettings->NonDefaultWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                 "DIAGWIDTH statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
               lefError(1630, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR(); 
            }
         }
      } else {
         if (lefCallbacks->NonDefaultCbk)
            lefData->lefrNonDefault.addDiagWidth((yyvsp[-1].dval));
      }
    }
#line 8873 "lef.tab.c"
    break;

  case 499:
#line 4169 "lef.y"
    { 
      if (lefCallbacks->SiteCbk)
        CALLBACK(lefCallbacks->SiteCbk, lefrSiteCbkType, &lefData->lefrSite);
    }
#line 8882 "lef.tab.c"
    break;

  case 500:
#line 4174 "lef.y"
                   {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 8888 "lef.tab.c"
    break;

  case 501:
#line 4175 "lef.y"
    { 
      if (lefCallbacks->SiteCbk) lefData->lefrSite.setName((yyvsp[0].string));
      //strcpy(lefData->siteName, $3);
      lefData->siteName = strdup((yyvsp[0].string));
      lefData->hasSiteClass = 0;
      lefData->hasSiteSize = 0;
      lefData->hasSite = 1;
    }
#line 8901 "lef.tab.c"
    break;

  case 502:
#line 4184 "lef.y"
                {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 8907 "lef.tab.c"
    break;

  case 503:
#line 4185 "lef.y"
    {
      if (strcmp(lefData->siteName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->SiteCbk) { // write error only if cbk is set 
           if (lefData->siteWarnings++ < lefSettings->SiteWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "END SITE name %s is different from the SITE name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->siteName);
              lefError(1631, lefData->outMsg);
              lefFree(lefData->outMsg);
              lefFree(lefData->siteName);
              CHKERR();
           } else
              lefFree(lefData->siteName);
        } else
           lefFree(lefData->siteName);
      } else {
        lefFree(lefData->siteName);
        if (lefCallbacks->SiteCbk) { // write error only if cbk is set 
          if (lefData->hasSiteClass == 0) {
             lefError(1632, "A CLASS statement is required in the SITE statement.");
             CHKERR();
          }
          if (lefData->hasSiteSize == 0) {
             lefError(1633, "A SIZE  statement is required in the SITE statement.");
             CHKERR();
          }
        }
      }
    }
#line 8941 "lef.tab.c"
    break;

  case 506:
#line 4222 "lef.y"
    {

      if (lefCallbacks->SiteCbk) lefData->lefrSite.setSize((yyvsp[-3].dval),(yyvsp[-1].dval));
      lefData->hasSiteSize = 1;
    }
#line 8951 "lef.tab.c"
    break;

  case 507:
#line 4228 "lef.y"
    { }
#line 8957 "lef.tab.c"
    break;

  case 508:
#line 4230 "lef.y"
    { 
      if (lefCallbacks->SiteCbk) lefData->lefrSite.setClass((yyvsp[0].string));
      lefData->hasSiteClass = 1;
    }
#line 8966 "lef.tab.c"
    break;

  case 509:
#line 4235 "lef.y"
    { }
#line 8972 "lef.tab.c"
    break;

  case 510:
#line 4238 "lef.y"
                    {(yyval.string) = (char*)"PAD"; }
#line 8978 "lef.tab.c"
    break;

  case 511:
#line 4239 "lef.y"
                        {(yyval.string) = (char*)"CORE"; }
#line 8984 "lef.tab.c"
    break;

  case 512:
#line 4240 "lef.y"
                           {(yyval.string) = (char*)"VIRTUAL"; }
#line 8990 "lef.tab.c"
    break;

  case 513:
#line 4243 "lef.y"
    { }
#line 8996 "lef.tab.c"
    break;

  case 516:
#line 4252 "lef.y"
    { if (lefCallbacks->SiteCbk) lefData->lefrSite.setXSymmetry(); }
#line 9002 "lef.tab.c"
    break;

  case 517:
#line 4254 "lef.y"
    { if (lefCallbacks->SiteCbk) lefData->lefrSite.setYSymmetry(); }
#line 9008 "lef.tab.c"
    break;

  case 518:
#line 4256 "lef.y"
    { if (lefCallbacks->SiteCbk) lefData->lefrSite.set90Symmetry(); }
#line 9014 "lef.tab.c"
    break;

  case 519:
#line 4258 "lef.y"
                                        {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 9020 "lef.tab.c"
    break;

  case 520:
#line 4260 "lef.y"
    { }
#line 9026 "lef.tab.c"
    break;

  case 523:
#line 4267 "lef.y"
                                      {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 9032 "lef.tab.c"
    break;

  case 524:
#line 4268 "lef.y"
    { if (lefCallbacks->SiteCbk) lefData->lefrSite.addRowPattern((yyvsp[-2].string), (yyvsp[-1].integer)); }
#line 9038 "lef.tab.c"
    break;

  case 525:
#line 4272 "lef.y"
    { (yyval.pt).x = (yyvsp[-1].dval); (yyval.pt).y = (yyvsp[0].dval); }
#line 9044 "lef.tab.c"
    break;

  case 526:
#line 4274 "lef.y"
    { (yyval.pt).x = (yyvsp[-2].dval); (yyval.pt).y = (yyvsp[-1].dval); }
#line 9050 "lef.tab.c"
    break;

  case 527:
#line 4277 "lef.y"
    { 
      if (lefCallbacks->MacroCbk)
        CALLBACK(lefCallbacks->MacroCbk, lefrMacroCbkType, &lefData->lefrMacro);
      lefData->lefrDoSite = 0;
    }
#line 9060 "lef.tab.c"
    break;

  case 529:
#line 4284 "lef.y"
                     {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 9066 "lef.tab.c"
    break;

  case 530:
#line 4285 "lef.y"
    {
      lefData->siteDef = 0;
      lefData->symDef = 0;
      lefData->sizeDef = 0; 
      lefData->pinDef = 0; 
      lefData->obsDef = 0; 
      lefData->origDef = 0;
      lefData->lefrMacro.clear();      
      if (lefCallbacks->MacroBeginCbk || lefCallbacks->MacroCbk) {
        // some reader may not have MacroBeginCB, but has MacroCB set
        lefData->lefrMacro.setName((yyvsp[0].string));
        CALLBACK(lefCallbacks->MacroBeginCbk, lefrMacroBeginCbkType, (yyvsp[0].string));
      }
      //strcpy(lefData->macroName, $3);
      lefData->macroName = strdup((yyvsp[0].string));
    }
#line 9087 "lef.tab.c"
    break;

  case 531:
#line 4302 "lef.y"
                 {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 9093 "lef.tab.c"
    break;

  case 532:
#line 4303 "lef.y"
    {
      if (strcmp(lefData->macroName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->MacroEndCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "END MACRO name %s is different from the MACRO name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->macroName);
              lefError(1634, lefData->outMsg);
              lefFree(lefData->outMsg);
              lefFree(lefData->macroName);
              CHKERR();
           } else
              lefFree(lefData->macroName);
        } else
           lefFree(lefData->macroName);
      } else
        lefFree(lefData->macroName);
      if (lefCallbacks->MacroEndCbk)
        CALLBACK(lefCallbacks->MacroEndCbk, lefrMacroEndCbkType, (yyvsp[0].string));
    }
#line 9118 "lef.tab.c"
    break;

  case 540:
#line 4336 "lef.y"
      { }
#line 9124 "lef.tab.c"
    break;

  case 541:
#line 4338 "lef.y"
      { }
#line 9130 "lef.tab.c"
    break;

  case 542:
#line 4340 "lef.y"
      { }
#line 9136 "lef.tab.c"
    break;

  case 543:
#line 4342 "lef.y"
      { }
#line 9142 "lef.tab.c"
    break;

  case 546:
#line 4346 "lef.y"
      { }
#line 9148 "lef.tab.c"
    break;

  case 547:
#line 4348 "lef.y"
      { }
#line 9154 "lef.tab.c"
    break;

  case 548:
#line 4350 "lef.y"
      { }
#line 9160 "lef.tab.c"
    break;

  case 549:
#line 4352 "lef.y"
      { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setBuffer(); }
#line 9166 "lef.tab.c"
    break;

  case 550:
#line 4354 "lef.y"
      { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setInverter(); }
#line 9172 "lef.tab.c"
    break;

  case 551:
#line 4356 "lef.y"
      { }
#line 9178 "lef.tab.c"
    break;

  case 552:
#line 4358 "lef.y"
      { }
#line 9184 "lef.tab.c"
    break;

  case 553:
#line 4360 "lef.y"
      { }
#line 9190 "lef.tab.c"
    break;

  case 554:
#line 4362 "lef.y"
      { }
#line 9196 "lef.tab.c"
    break;

  case 555:
#line 4363 "lef.y"
               {lefData->lefDumbMode = 1000000; }
#line 9202 "lef.tab.c"
    break;

  case 556:
#line 4364 "lef.y"
      { lefData->lefDumbMode = 0;
      }
#line 9209 "lef.tab.c"
    break;

  case 559:
#line 4373 "lef.y"
    {
      if (lefData->siteDef) { // SITE is defined before SYMMETRY 
          // pcr 283846 suppress warning 
          if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
             if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
               lefWarning(2032, "A SITE statement is defined before SYMMETRY statement.\nTo avoid this warning in the future, define SITE after SYMMETRY");
      }
      lefData->symDef = 1;
    }
#line 9223 "lef.tab.c"
    break;

  case 562:
#line 4390 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setXSymmetry(); }
#line 9229 "lef.tab.c"
    break;

  case 563:
#line 4392 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setYSymmetry(); }
#line 9235 "lef.tab.c"
    break;

  case 564:
#line 4394 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.set90Symmetry(); }
#line 9241 "lef.tab.c"
    break;

  case 565:
#line 4398 "lef.y"
    {
      char temp[32];
      sprintf(temp, "%.11g", (yyvsp[0].dval));
      if (lefCallbacks->MacroCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrMacroProp.propType((yyvsp[-1].string));
         lefData->lefrMacro.setNumProperty((yyvsp[-1].string), (yyvsp[0].dval), temp,  propTp);
      }
    }
#line 9255 "lef.tab.c"
    break;

  case 566:
#line 4408 "lef.y"
    {
      if (lefCallbacks->MacroCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrMacroProp.propType((yyvsp[-1].string));
         lefData->lefrMacro.setProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 9267 "lef.tab.c"
    break;

  case 567:
#line 4416 "lef.y"
    {
      if (lefCallbacks->MacroCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrMacroProp.propType((yyvsp[-1].string));
         lefData->lefrMacro.setProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 9279 "lef.tab.c"
    break;

  case 568:
#line 4425 "lef.y"
    {
       if (lefCallbacks->MacroCbk) lefData->lefrMacro.setClass((yyvsp[-1].string));
       if (lefCallbacks->MacroClassTypeCbk)
          CALLBACK(lefCallbacks->MacroClassTypeCbk, lefrMacroClassTypeCbkType, (yyvsp[-1].string));
    }
#line 9289 "lef.tab.c"
    break;

  case 569:
#line 4432 "lef.y"
          {(yyval.string) = (char*)"COVER"; }
#line 9295 "lef.tab.c"
    break;

  case 570:
#line 4434 "lef.y"
    { (yyval.string) = (char*)"COVER BUMP";
      if (lefData->versionNum < 5.5) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              if (lefSettings->RelaxMode)
                 lefWarning(2033, "The statement COVER BUMP is a LEF verion 5.5 syntax.\nYour LEF file is version 5.4 or earlier which is incorrect but will be allowed\nbecause this application does not enforce strict version checking.\nOther tools that enforce strict checking will have a syntax error when reading this file.\nYou can change the VERSION statement in this LEF file to 5.5 or higher to stop this warning.");
              else {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "COVER BUMP statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                 lefError(1635, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
      }
    }
#line 9318 "lef.tab.c"
    break;

  case 571:
#line 4452 "lef.y"
              {(yyval.string) = (char*)"RING"; }
#line 9324 "lef.tab.c"
    break;

  case 572:
#line 4453 "lef.y"
              {(yyval.string) = (char*)"BLOCK"; }
#line 9330 "lef.tab.c"
    break;

  case 573:
#line 4455 "lef.y"
    { (yyval.string) = (char*)"BLOCK BLACKBOX";
      if (lefData->versionNum < 5.5) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
             if (lefSettings->RelaxMode)
                lefWarning(2034, "The statement BLOCK BLACKBOX is a LEF verion 5.5 syntax.\nYour LEF file is version 5.4 or earlier which is incorrect but will be allowed\nbecause this application does not enforce strict version checking.\nOther tools that enforce strict checking will have a syntax error when reading this file.\nYou can change the VERSION statement in this LEF file to 5.5 or higher to stop this warning.");
              else {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "BLOCK BLACKBOX statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                 lefError(1636, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
      }
    }
#line 9353 "lef.tab.c"
    break;

  case 574:
#line 4474 "lef.y"
    {
      if (lefData->ignoreVersion) {
        (yyval.string) = (char*)"BLOCK SOFT";
      } else if (lefData->versionNum < 5.6) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "BLOCK SOFT statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1637, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      else
        (yyval.string) = (char*)"BLOCK SOFT";
    }
#line 9376 "lef.tab.c"
    break;

  case 575:
#line 4492 "lef.y"
              {(yyval.string) = (char*)"NONE"; }
#line 9382 "lef.tab.c"
    break;

  case 576:
#line 4494 "lef.y"
      {
        if (lefData->versionNum < 5.7) {
          lefData->outMsg = (char*)lefMalloc(10000);
          sprintf(lefData->outMsg,
            "BUMP is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
          lefError(1698, lefData->outMsg);
          lefFree(lefData->outMsg);
          CHKERR();
        }
       
        (yyval.string) = (char*)"BUMP";
     }
#line 9399 "lef.tab.c"
    break;

  case 577:
#line 4506 "lef.y"
              {(yyval.string) = (char*)"PAD"; }
#line 9405 "lef.tab.c"
    break;

  case 578:
#line 4507 "lef.y"
              {(yyval.string) = (char*)"VIRTUAL"; }
#line 9411 "lef.tab.c"
    break;

  case 579:
#line 4509 "lef.y"
      {  sprintf(lefData->temp_name, "PAD %s", (yyvsp[0].string));
        (yyval.string) = lefData->temp_name; 
        if (lefData->versionNum < 5.5) {
           if (strcmp("AREAIO", (yyvsp[0].string)) != 0) {
             sprintf(lefData->temp_name, "PAD %s", (yyvsp[0].string));
             (yyval.string) = lefData->temp_name; 
           } else if (lefCallbacks->MacroCbk) { 
             if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
               if (lefSettings->RelaxMode)
                  lefWarning(2035, "The statement PAD AREAIO is a LEF verion 5.5 syntax.\nYour LEF file is version 5.4 or earlier which is incorrect but will be allowed\nbecause this application does not enforce strict version checking.\nOther tools that enforce strict checking will have a syntax error when reading this file.\nYou can change the VERSION statement in this LEF file to 5.5 or higher to stop this warning.");
               else {
                  lefData->outMsg = (char*)lefMalloc(10000);
                  sprintf (lefData->outMsg,
                     "PAD AREAIO statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                  lefError(1638, lefData->outMsg);
                  lefFree(lefData->outMsg);
                  CHKERR();
               }
            }
          }
        }
      }
#line 9438 "lef.tab.c"
    break;

  case 580:
#line 4531 "lef.y"
              {(yyval.string) = (char*)"CORE"; }
#line 9444 "lef.tab.c"
    break;

  case 581:
#line 4533 "lef.y"
      {(yyval.string) = (char*)"CORNER";
      // This token is NOT in the spec but has shown up in 
      // some lef files.  This exception came from LEFOUT
      // in 'frameworks'
      }
#line 9454 "lef.tab.c"
    break;

  case 582:
#line 4539 "lef.y"
      {sprintf(lefData->temp_name, "CORE %s", (yyvsp[0].string));
      (yyval.string) = lefData->temp_name;}
#line 9461 "lef.tab.c"
    break;

  case 583:
#line 4542 "lef.y"
      {sprintf(lefData->temp_name, "ENDCAP %s", (yyvsp[0].string));
      (yyval.string) = lefData->temp_name;}
#line 9468 "lef.tab.c"
    break;

  case 584:
#line 4546 "lef.y"
                  {(yyval.string) = (char*)"INPUT";}
#line 9474 "lef.tab.c"
    break;

  case 585:
#line 4547 "lef.y"
                    {(yyval.string) = (char*)"OUTPUT";}
#line 9480 "lef.tab.c"
    break;

  case 586:
#line 4548 "lef.y"
                    {(yyval.string) = (char*)"INOUT";}
#line 9486 "lef.tab.c"
    break;

  case 587:
#line 4549 "lef.y"
                    {(yyval.string) = (char*)"POWER";}
#line 9492 "lef.tab.c"
    break;

  case 588:
#line 4550 "lef.y"
                    {(yyval.string) = (char*)"SPACER";}
#line 9498 "lef.tab.c"
    break;

  case 589:
#line 4551 "lef.y"
                {(yyval.string) = (char*)"AREAIO";}
#line 9504 "lef.tab.c"
    break;

  case 590:
#line 4554 "lef.y"
                    {(yyval.string) = (char*)"FEEDTHRU";}
#line 9510 "lef.tab.c"
    break;

  case 591:
#line 4555 "lef.y"
                    {(yyval.string) = (char*)"TIEHIGH";}
#line 9516 "lef.tab.c"
    break;

  case 592:
#line 4556 "lef.y"
                    {(yyval.string) = (char*)"TIELOW";}
#line 9522 "lef.tab.c"
    break;

  case 593:
#line 4558 "lef.y"
    { 
      (yyval.string) = (char*)"SPACER";

      if (!lefData->ignoreVersion && lefData->versionNum < 5.4) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "SPACER statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1639, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
    }
#line 9543 "lef.tab.c"
    break;

  case 594:
#line 4575 "lef.y"
    { 
      (yyval.string) = (char*)"ANTENNACELL";

      if (!lefData->ignoreVersion && lefData->versionNum < 5.4) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNACELL statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1640, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
    }
#line 9564 "lef.tab.c"
    break;

  case 595:
#line 4592 "lef.y"
    { 
      (yyval.string) = (char*)"WELLTAP";

      if (!lefData->ignoreVersion && lefData->versionNum < 5.6) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "WELLTAP statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1641, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
    }
#line 9585 "lef.tab.c"
    break;

  case 596:
#line 4610 "lef.y"
                {(yyval.string) = (char*)"PRE";}
#line 9591 "lef.tab.c"
    break;

  case 597:
#line 4611 "lef.y"
                   {(yyval.string) = (char*)"POST";}
#line 9597 "lef.tab.c"
    break;

  case 598:
#line 4612 "lef.y"
                      {(yyval.string) = (char*)"TOPLEFT";}
#line 9603 "lef.tab.c"
    break;

  case 599:
#line 4613 "lef.y"
                       {(yyval.string) = (char*)"TOPRIGHT";}
#line 9609 "lef.tab.c"
    break;

  case 600:
#line 4614 "lef.y"
                         {(yyval.string) = (char*)"BOTTOMLEFT";}
#line 9615 "lef.tab.c"
    break;

  case 601:
#line 4615 "lef.y"
                         {(yyval.string) = (char*)"BOTTOMRIGHT";}
#line 9621 "lef.tab.c"
    break;

  case 602:
#line 4618 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setGenerator((yyvsp[-1].string)); }
#line 9627 "lef.tab.c"
    break;

  case 603:
#line 4621 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setGenerate((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 9633 "lef.tab.c"
    break;

  case 604:
#line 4625 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->MacroCbk) lefData->lefrMacro.setSource("USER");
      } else
        if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
             lefWarning(2036, "SOURCE statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9646 "lef.tab.c"
    break;

  case 605:
#line 4634 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->MacroCbk) lefData->lefrMacro.setSource("GENERATE");
      } else
        if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
             lefWarning(2037, "SOURCE statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9659 "lef.tab.c"
    break;

  case 606:
#line 4643 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->MacroCbk) lefData->lefrMacro.setSource("BLOCK");
      } else
        if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
             lefWarning(2037, "SOURCE statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9672 "lef.tab.c"
    break;

  case 607:
#line 4653 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->MacroCbk) lefData->lefrMacro.setPower((yyvsp[-1].dval));
      } else
        if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
             lefWarning(2038, "MACRO POWER statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 9685 "lef.tab.c"
    break;

  case 608:
#line 4663 "lef.y"
    { 
       if (lefData->origDef) { // Has multiple ORIGIN defined in a macro, stop parsing
          if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
             if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                lefError(1642, "ORIGIN statement has defined more than once in a MACRO statement.\nOnly one ORIGIN statement can be defined in a Macro.\nParser will stop processing.");
               CHKERR();
             }
          }
       }
       lefData->origDef = 1;
       if (lefData->siteDef) { // SITE is defined before ORIGIN 
          // pcr 283846 suppress warning 
          if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
             if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
               lefWarning(2039, "A SITE statement is defined before ORIGIN statement.\nTo avoid this warning in the future, define SITE after ORIGIN");
       }
       if (lefData->pinDef) { // PIN is defined before ORIGIN 
          // pcr 283846 suppress warning 
          if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
             if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
               lefWarning(2040, "A PIN statement is defined before ORIGIN statement.\nTo avoid this warning in the future, define PIN after ORIGIN");
       }
       if (lefData->obsDef) { // OBS is defined before ORIGIN 
          // pcr 283846 suppress warning 
          if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
             if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
               lefWarning(2041, "A OBS statement is defined before ORIGIN statement.\nTo avoid this warning in the future, define OBS after ORIGIN");
       }
      
       // Workaround for pcr 640902 
       if (lefCallbacks->MacroCbk) lefData->lefrMacro.setOrigin((yyvsp[-1].pt).x, (yyvsp[-1].pt).y);
       if (lefCallbacks->MacroOriginCbk) {
          lefData->macroNum.x = (yyvsp[-1].pt).x; 
          lefData->macroNum.y = (yyvsp[-1].pt).y; 
          CALLBACK(lefCallbacks->MacroOriginCbk, lefrMacroOriginCbkType, lefData->macroNum);
       }
    }
#line 9727 "lef.tab.c"
    break;

  case 609:
#line 4703 "lef.y"
    { 
      if (lefCallbacks->MacroCbk) {
        lefData->lefrMacro.addForeign((yyvsp[-1].string), 0, 0.0, 0.0, -1);
      }
      
      if (lefCallbacks->MacroForeignCbk) {
        lefiMacroForeign foreign((yyvsp[-1].string), 0, 0.0, 0.0, 0, 0);
        CALLBACK(lefCallbacks->MacroForeignCbk, lefrMacroForeignCbkType, &foreign);
      }  
    }
#line 9742 "lef.tab.c"
    break;

  case 610:
#line 4714 "lef.y"
    { 
      if (lefCallbacks->MacroCbk) {
        lefData->lefrMacro.addForeign((yyvsp[-2].string), 1, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, -1);
      }
      
      if (lefCallbacks->MacroForeignCbk) {
        lefiMacroForeign foreign((yyvsp[-2].string), 1, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, 0, 0);
        CALLBACK(lefCallbacks->MacroForeignCbk, lefrMacroForeignCbkType, &foreign);
      }  
    }
#line 9757 "lef.tab.c"
    break;

  case 611:
#line 4725 "lef.y"
    { 
      if (lefCallbacks->MacroCbk) {
        lefData->lefrMacro.addForeign((yyvsp[-3].string), 1, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].integer));
      }
      
      if (lefCallbacks->MacroForeignCbk) {
        lefiMacroForeign foreign((yyvsp[-3].string), 1, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, 1, (yyvsp[-1].integer));
        CALLBACK(lefCallbacks->MacroForeignCbk, lefrMacroForeignCbkType, &foreign);
      } 
    }
#line 9772 "lef.tab.c"
    break;

  case 612:
#line 4736 "lef.y"
    { 
      if (lefCallbacks->MacroCbk) {
        lefData->lefrMacro.addForeign((yyvsp[-2].string), 0, 0.0, 0.0, (yyvsp[-1].integer));
      }

      if (lefCallbacks->MacroForeignCbk) {
        lefiMacroForeign foreign((yyvsp[-2].string), 0, 0.0, 0.0, 1, (yyvsp[-1].integer));
        CALLBACK(lefCallbacks->MacroForeignCbk, lefrMacroForeignCbkType, &foreign);
      } 
    }
#line 9787 "lef.tab.c"
    break;

  case 613:
#line 4749 "lef.y"
   {   
       if (lefCallbacks->MacroCbk && lefData->versionNum >= 5.8) {
          lefData->lefrMacro.setFixedMask(1);
       }
       if (lefCallbacks->MacroFixedMaskCbk) {
          CALLBACK(lefCallbacks->MacroFixedMaskCbk, lefrMacroFixedMaskCbkType, 1);
       }        
    }
#line 9800 "lef.tab.c"
    break;

  case 614:
#line 4758 "lef.y"
                 { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 9806 "lef.tab.c"
    break;

  case 615:
#line 4759 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setEEQ((yyvsp[-1].string)); }
#line 9812 "lef.tab.c"
    break;

  case 616:
#line 4761 "lef.y"
                 { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 9818 "lef.tab.c"
    break;

  case 617:
#line 4762 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->MacroCbk) lefData->lefrMacro.setLEQ((yyvsp[-1].string));
      } else
        if (lefCallbacks->MacroCbk) // write warning only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings)
             lefWarning(2042, "LEQ statement in MACRO is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9831 "lef.tab.c"
    break;

  case 618:
#line 4773 "lef.y"
    {
      if (lefCallbacks->MacroCbk) {
        lefData->lefrMacro.setSiteName((yyvsp[-1].string));
      }

      if (lefCallbacks->MacroSiteCbk) {
        lefiMacroSite site((yyvsp[-1].string), 0);
        CALLBACK(lefCallbacks->MacroSiteCbk, lefrMacroSiteCbkType, &site);
      }
    }
#line 9846 "lef.tab.c"
    break;

  case 619:
#line 4784 "lef.y"
    {
      if (lefCallbacks->MacroCbk) {
        // also set site name in the variable siteName_ in lefiMacro 
        // this, if user wants to use method lefData->siteName will get the name also 
        lefData->lefrMacro.setSitePattern(lefData->lefrSitePatternPtr);
      }

      if (lefCallbacks->MacroSiteCbk) {
        lefiMacroSite site(0, lefData->lefrSitePatternPtr);
        CALLBACK(lefCallbacks->MacroSiteCbk, lefrMacroSiteCbkType, &site);
      }
        
      lefData->lefrSitePatternPtr = 0;
    }
#line 9865 "lef.tab.c"
    break;

  case 620:
#line 4800 "lef.y"
    { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; lefData->siteDef = 1;
        if (lefCallbacks->MacroCbk) lefData->lefrDoSite = 1; }
#line 9872 "lef.tab.c"
    break;

  case 621:
#line 4804 "lef.y"
    { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 9878 "lef.tab.c"
    break;

  case 622:
#line 4807 "lef.y"
    { 
      if (lefData->siteDef) { // SITE is defined before SIZE 
      }
      lefData->sizeDef = 1;
      if (lefCallbacks->MacroCbk) lefData->lefrMacro.setSize((yyvsp[-3].dval), (yyvsp[-1].dval));
      if (lefCallbacks->MacroSizeCbk) {
         lefData->macroNum.x = (yyvsp[-3].dval); 
         lefData->macroNum.y = (yyvsp[-1].dval); 
         CALLBACK(lefCallbacks->MacroSizeCbk, lefrMacroSizeCbkType, lefData->macroNum);
      }
    }
#line 9894 "lef.tab.c"
    break;

  case 623:
#line 4823 "lef.y"
    { 
      if (lefCallbacks->PinCbk)
        CALLBACK(lefCallbacks->PinCbk, lefrPinCbkType, &lefData->lefrPin);
      lefData->lefrPin.clear();
    }
#line 9904 "lef.tab.c"
    break;

  case 624:
#line 4829 "lef.y"
                       {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; lefData->pinDef = 1;}
#line 9910 "lef.tab.c"
    break;

  case 625:
#line 4830 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setName((yyvsp[0].string));
      //strcpy(lefData->pinName, $3);
      lefData->pinName = strdup((yyvsp[0].string));
    }
#line 9919 "lef.tab.c"
    break;

  case 626:
#line 4835 "lef.y"
                     {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 9925 "lef.tab.c"
    break;

  case 627:
#line 4836 "lef.y"
    {
      if (strcmp(lefData->pinName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->MacroCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "END PIN name %s is different from the PIN name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->pinName);
              lefError(1643, lefData->outMsg);
              lefFree(lefData->outMsg);
              lefFree(lefData->pinName);
              CHKERR();
           } else
              lefFree(lefData->pinName);
        } else
           lefFree(lefData->pinName);
      } else
        lefFree(lefData->pinName);
    }
#line 9948 "lef.tab.c"
    break;

  case 628:
#line 4857 "lef.y"
    { }
#line 9954 "lef.tab.c"
    break;

  case 629:
#line 4859 "lef.y"
    { }
#line 9960 "lef.tab.c"
    break;

  case 630:
#line 4863 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.addForeign((yyvsp[-1].string), 0, 0.0, 0.0, -1);
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2043, "FOREIGN statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9973 "lef.tab.c"
    break;

  case 631:
#line 4872 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.addForeign((yyvsp[-2].string), 1, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, -1);
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2043, "FOREIGN statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9986 "lef.tab.c"
    break;

  case 632:
#line 4881 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.addForeign((yyvsp[-3].string), 1, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].integer));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2043, "FOREIGN statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 9999 "lef.tab.c"
    break;

  case 633:
#line 4890 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.addForeign((yyvsp[-2].string), 0, 0.0, 0.0, -1);
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2043, "FOREIGN statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 10012 "lef.tab.c"
    break;

  case 634:
#line 4899 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.addForeign((yyvsp[-3].string), 1, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y, -1);
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2043, "FOREIGN statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 10025 "lef.tab.c"
    break;

  case 635:
#line 4908 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.addForeign((yyvsp[-4].string), 1, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].integer));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2043, "FOREIGN statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 10038 "lef.tab.c"
    break;

  case 636:
#line 4916 "lef.y"
          { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 10044 "lef.tab.c"
    break;

  case 637:
#line 4917 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setLEQ((yyvsp[-1].string));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2044, "LEQ statement in MACRO PIN is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
   }
#line 10057 "lef.tab.c"
    break;

  case 638:
#line 4926 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setPower((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2045, "MACRO POWER statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10070 "lef.tab.c"
    break;

  case 639:
#line 4935 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setDirection((yyvsp[0].string)); }
#line 10076 "lef.tab.c"
    break;

  case 640:
#line 4937 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setUse((yyvsp[-1].string)); }
#line 10082 "lef.tab.c"
    break;

  case 641:
#line 4939 "lef.y"
    { }
#line 10088 "lef.tab.c"
    break;

  case 642:
#line 4941 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setLeakage((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2046, "MACRO LEAKAGE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, r emove this statement from the LEF file with version 5.4 or later.");
    }
#line 10101 "lef.tab.c"
    break;

  case 643:
#line 4950 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setRiseThresh((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2047, "MACRO RISETHRESH statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10114 "lef.tab.c"
    break;

  case 644:
#line 4959 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setFallThresh((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2048, "MACRO FALLTHRESH statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10127 "lef.tab.c"
    break;

  case 645:
#line 4968 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setRiseSatcur((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2049, "MACRO RISESATCUR statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10140 "lef.tab.c"
    break;

  case 646:
#line 4977 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setFallSatcur((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2050, "MACRO FALLSATCUR statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10153 "lef.tab.c"
    break;

  case 647:
#line 4986 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setVLO((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2051, "MACRO VLO statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10166 "lef.tab.c"
    break;

  case 648:
#line 4995 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setVHI((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2052, "MACRO VHI statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10179 "lef.tab.c"
    break;

  case 649:
#line 5004 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setTieoffr((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2053, "MACRO TIEOFFR statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10192 "lef.tab.c"
    break;

  case 650:
#line 5013 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setShape((yyvsp[-1].string)); }
#line 10198 "lef.tab.c"
    break;

  case 651:
#line 5014 "lef.y"
               {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 10204 "lef.tab.c"
    break;

  case 652:
#line 5015 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setMustjoin((yyvsp[-1].string)); }
#line 10210 "lef.tab.c"
    break;

  case 653:
#line 5016 "lef.y"
                        {lefData->lefDumbMode = 1;}
#line 10216 "lef.tab.c"
    break;

  case 654:
#line 5017 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setOutMargin((yyvsp[-2].dval), (yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2054, "MACRO OUTPUTNOISEMARGIN statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10229 "lef.tab.c"
    break;

  case 655:
#line 5025 "lef.y"
                       {lefData->lefDumbMode = 1;}
#line 10235 "lef.tab.c"
    break;

  case 656:
#line 5026 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setOutResistance((yyvsp[-2].dval), (yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2055, "MACRO OUTPUTRESISTANCE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10248 "lef.tab.c"
    break;

  case 657:
#line 5034 "lef.y"
                       {lefData->lefDumbMode = 1;}
#line 10254 "lef.tab.c"
    break;

  case 658:
#line 5035 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setInMargin((yyvsp[-2].dval), (yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2056, "MACRO INPUTNOISEMARGIN statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10267 "lef.tab.c"
    break;

  case 659:
#line 5044 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setCapacitance((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2057, "MACRO CAPACITANCE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10280 "lef.tab.c"
    break;

  case 660:
#line 5053 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setMaxdelay((yyvsp[-1].dval)); }
#line 10286 "lef.tab.c"
    break;

  case 661:
#line 5055 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setMaxload((yyvsp[-1].dval)); }
#line 10292 "lef.tab.c"
    break;

  case 662:
#line 5057 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setResistance((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2058, "MACRO RESISTANCE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10305 "lef.tab.c"
    break;

  case 663:
#line 5066 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setPulldownres((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2059, "MACRO PULLDOWNRES statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10318 "lef.tab.c"
    break;

  case 664:
#line 5075 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setCurrentSource("ACTIVE");
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2060, "MACRO CURRENTSOURCE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10331 "lef.tab.c"
    break;

  case 665:
#line 5084 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setCurrentSource("RESISTIVE");
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2061, "MACRO CURRENTSOURCE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10344 "lef.tab.c"
    break;

  case 666:
#line 5093 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setRiseVoltage((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2062, "MACRO RISEVOLTAGETHRESHOLD statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10357 "lef.tab.c"
    break;

  case 667:
#line 5102 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setFallVoltage((yyvsp[-1].dval));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2063, "MACRO FALLVOLTAGETHRESHOLD statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10370 "lef.tab.c"
    break;

  case 668:
#line 5111 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) lefData->lefrPin.setTables((yyvsp[-2].string), (yyvsp[-1].string));
      } else
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2064, "MACRO IV_TABLES statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 10383 "lef.tab.c"
    break;

  case 669:
#line 5120 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setTaperRule((yyvsp[-1].string)); }
#line 10389 "lef.tab.c"
    break;

  case 670:
#line 5121 "lef.y"
               {lefData->lefDumbMode = 1000000; }
#line 10395 "lef.tab.c"
    break;

  case 671:
#line 5122 "lef.y"
    { lefData->lefDumbMode = 0;
    }
#line 10402 "lef.tab.c"
    break;

  case 672:
#line 5125 "lef.y"
    {
      lefData->lefDumbMode = 0;
      lefData->hasGeoLayer = 0;
      if (lefCallbacks->PinCbk) {
        lefData->lefrPin.addPort(lefData->lefrGeometriesPtr);
        lefData->lefrGeometriesPtr = 0;
        lefData->lefrDoGeometries = 0;
      }
      if ((lefData->needGeometry) && (lefData->needGeometry != 2))  // if the lefData->last LAYER in PORT
        if (lefCallbacks->PinCbk) // write warning only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings)
             lefWarning(2065, "Either PATH, RECT or POLYGON statement is a required in MACRO/PIN/PORT.");
    }
#line 10420 "lef.tab.c"
    break;

  case 673:
#line 5139 "lef.y"
    {
      // Since in start_macro_port it has call the Init method, here
      // we need to call the Destroy method.
      // Still add a null pointer to set the number of port
      if (lefCallbacks->PinCbk) {
        lefData->lefrPin.addPort(lefData->lefrGeometriesPtr);
        lefData->lefrGeometriesPtr = 0;
        lefData->lefrDoGeometries = 0;
      }
      lefData->hasGeoLayer = 0;
    }
#line 10436 "lef.tab.c"
    break;

  case 674:
#line 5151 "lef.y"
    {  // a pre 5.4 syntax 
      lefData->use5_3 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum >= 5.4) {
        if (lefData->use5_4) {
           if (lefCallbacks->PinCbk) { // write error only if cbk is set 
             if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
                lefData->outMsg = (char*)lefMalloc(10000);
                sprintf (lefData->outMsg,
                   "ANTENNASIZE statement is a version 5.3 and earlier syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                lefError(1644, lefData->outMsg);
                lefFree(lefData->outMsg);
                CHKERR();
             }
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaSize((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10461 "lef.tab.c"
    break;

  case 675:
#line 5172 "lef.y"
    {  // a pre 5.4 syntax 
      lefData->use5_3 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum >= 5.4) {
        if (lefData->use5_4) {
           if (lefCallbacks->PinCbk) { // write error only if cbk is set 
              if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "ANTENNAMETALAREA statement is a version 5.3 and earlier syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                 lefError(1645, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaMetalArea((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10486 "lef.tab.c"
    break;

  case 676:
#line 5193 "lef.y"
    { // a pre 5.4 syntax  
      lefData->use5_3 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum >= 5.4) {
        if (lefData->use5_4) {
           if (lefCallbacks->PinCbk) { // write error only if cbk is set 
              if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "ANTENNAMETALLENGTH statement is a version 5.3 and earlier syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
                 lefError(1646, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaMetalLength((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10511 "lef.tab.c"
    break;

  case 677:
#line 5214 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setRiseSlewLimit((yyvsp[-1].dval)); }
#line 10517 "lef.tab.c"
    break;

  case 678:
#line 5216 "lef.y"
    { if (lefCallbacks->PinCbk) lefData->lefrPin.setFallSlewLimit((yyvsp[-1].dval)); }
#line 10523 "lef.tab.c"
    break;

  case 679:
#line 5218 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAPARTIALMETALAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1647, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAPARTIALMETALAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1647, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaPartialMetalArea((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10557 "lef.tab.c"
    break;

  case 680:
#line 5248 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAPARTIALMETALSIDEAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1648, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAPARTIALMETALSIDEAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1648, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaPartialMetalSideArea((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10591 "lef.tab.c"
    break;

  case 681:
#line 5278 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAPARTIALCUTAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1649, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAPARTIALCUTAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1649, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaPartialCutArea((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10625 "lef.tab.c"
    break;

  case 682:
#line 5308 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNADIFFAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1650, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNADIFFAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1650, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaDiffArea((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10659 "lef.tab.c"
    break;

  case 683:
#line 5338 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAGATEAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1651, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAGATEAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1651, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaGateArea((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10693 "lef.tab.c"
    break;

  case 684:
#line 5368 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMAXAREACAR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1652, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMAXAREACAR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1652, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaMaxAreaCar((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10727 "lef.tab.c"
    break;

  case 685:
#line 5398 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMAXSIDEAREACAR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1653, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMAXSIDEAREACAR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1653, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaMaxSideAreaCar((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10761 "lef.tab.c"
    break;

  case 686:
#line 5428 "lef.y"
    { // 5.4 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.4) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMAXCUTCAR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1654, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMAXCUTCAR statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1654, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
      if (lefCallbacks->PinCbk) lefData->lefrPin.addAntennaMaxCutCar((yyvsp[-2].dval), (yyvsp[-1].string));
    }
#line 10795 "lef.tab.c"
    break;

  case 687:
#line 5458 "lef.y"
    { // 5.5 syntax 
      lefData->use5_4 = 1;
      if (lefData->ignoreVersion) {
        // do nothing 
      } else if (lefData->versionNum < 5.5) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMODEL statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1655, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else if (lefData->use5_3) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ANTENNAMODEL statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1655, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      }
    }
#line 10828 "lef.tab.c"
    break;

  case 689:
#line 5487 "lef.y"
              {lefData->lefDumbMode = 2; lefData->lefNoNum = 2; }
#line 10834 "lef.tab.c"
    break;

  case 690:
#line 5488 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "NETEXPR statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1656, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else
        if (lefCallbacks->PinCbk) lefData->lefrPin.setNetExpr((yyvsp[-1].string));
    }
#line 10854 "lef.tab.c"
    break;

  case 691:
#line 5503 "lef.y"
                        {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 10860 "lef.tab.c"
    break;

  case 692:
#line 5504 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "SUPPLYSENSITIVITY statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1657, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else
        if (lefCallbacks->PinCbk) lefData->lefrPin.setSupplySensitivity((yyvsp[-1].string));
    }
#line 10880 "lef.tab.c"
    break;

  case 693:
#line 5519 "lef.y"
                        {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 10886 "lef.tab.c"
    break;

  case 694:
#line 5520 "lef.y"
    {
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->PinCbk) { // write error only if cbk is set 
           if (lefData->pinWarnings++ < lefSettings->PinWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "GROUNDSENSITIVITY statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1658, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } else
        if (lefCallbacks->PinCbk) lefData->lefrPin.setGroundSensitivity((yyvsp[-1].string));
    }
#line 10906 "lef.tab.c"
    break;

  case 695:
#line 5538 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(1);
    }
#line 10915 "lef.tab.c"
    break;

  case 696:
#line 5543 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(2);
    }
#line 10924 "lef.tab.c"
    break;

  case 697:
#line 5548 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(3);
    }
#line 10933 "lef.tab.c"
    break;

  case 698:
#line 5553 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(4);
    }
#line 10942 "lef.tab.c"
    break;

  case 699:
#line 5558 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(5);
    }
#line 10951 "lef.tab.c"
    break;

  case 700:
#line 5563 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(6);
    }
#line 10960 "lef.tab.c"
    break;

  case 701:
#line 5568 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(7);
    }
#line 10969 "lef.tab.c"
    break;

  case 702:
#line 5573 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(8);
    }
#line 10978 "lef.tab.c"
    break;

  case 703:
#line 5578 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(9);
    }
#line 10987 "lef.tab.c"
    break;

  case 704:
#line 5583 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(10);
    }
#line 10996 "lef.tab.c"
    break;

  case 705:
#line 5588 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(11);
    }
#line 11005 "lef.tab.c"
    break;

  case 706:
#line 5593 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(12);
    }
#line 11014 "lef.tab.c"
    break;

  case 707:
#line 5598 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(13);
    }
#line 11023 "lef.tab.c"
    break;

  case 708:
#line 5603 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(14);
    }
#line 11032 "lef.tab.c"
    break;

  case 709:
#line 5608 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(15);
    }
#line 11041 "lef.tab.c"
    break;

  case 710:
#line 5613 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(16);
    }
#line 11050 "lef.tab.c"
    break;

  case 711:
#line 5618 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(17);
    }
#line 11059 "lef.tab.c"
    break;

  case 712:
#line 5623 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(18);
    }
#line 11068 "lef.tab.c"
    break;

  case 713:
#line 5628 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(19);
    }
#line 11077 "lef.tab.c"
    break;

  case 714:
#line 5633 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(20);
    }
#line 11086 "lef.tab.c"
    break;

  case 715:
#line 5638 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(21);
    }
#line 11095 "lef.tab.c"
    break;

  case 716:
#line 5643 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(22);
    }
#line 11104 "lef.tab.c"
    break;

  case 717:
#line 5648 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(23);
    }
#line 11113 "lef.tab.c"
    break;

  case 718:
#line 5653 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(24);
    }
#line 11122 "lef.tab.c"
    break;

  case 719:
#line 5658 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(25);
    }
#line 11131 "lef.tab.c"
    break;

  case 720:
#line 5663 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(26);
    }
#line 11140 "lef.tab.c"
    break;

  case 721:
#line 5668 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(27);
    }
#line 11149 "lef.tab.c"
    break;

  case 722:
#line 5673 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(28);
    }
#line 11158 "lef.tab.c"
    break;

  case 723:
#line 5678 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(29);
    }
#line 11167 "lef.tab.c"
    break;

  case 724:
#line 5683 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(30);
    }
#line 11176 "lef.tab.c"
    break;

  case 725:
#line 5688 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(31);
    }
#line 11185 "lef.tab.c"
    break;

  case 726:
#line 5693 "lef.y"
    {
    if (lefCallbacks->PinCbk)
       lefData->lefrPin.addAntennaModel(32);
    }
#line 11194 "lef.tab.c"
    break;

  case 729:
#line 5705 "lef.y"
    { 
      char temp[32];
      sprintf(temp, "%.11g", (yyvsp[0].dval));
      if (lefCallbacks->PinCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrPinProp.propType((yyvsp[-1].string));
         lefData->lefrPin.setNumProperty((yyvsp[-1].string), (yyvsp[0].dval), temp, propTp);
      }
    }
#line 11208 "lef.tab.c"
    break;

  case 730:
#line 5715 "lef.y"
    {
      if (lefCallbacks->PinCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrPinProp.propType((yyvsp[-1].string));
         lefData->lefrPin.setProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 11220 "lef.tab.c"
    break;

  case 731:
#line 5723 "lef.y"
    {
      if (lefCallbacks->PinCbk) {
         char propTp;
         propTp = lefSettings->lefProps.lefrPinProp.propType((yyvsp[-1].string));
         lefData->lefrPin.setProperty((yyvsp[-1].string), (yyvsp[0].string), propTp);
      }
    }
#line 11232 "lef.tab.c"
    break;

  case 732:
#line 5732 "lef.y"
                                       {(yyval.string) = (char*)"INPUT";}
#line 11238 "lef.tab.c"
    break;

  case 733:
#line 5733 "lef.y"
                                        {(yyval.string) = (char*)"OUTPUT";}
#line 11244 "lef.tab.c"
    break;

  case 734:
#line 5734 "lef.y"
                                        {(yyval.string) = (char*)"OUTPUT TRISTATE";}
#line 11250 "lef.tab.c"
    break;

  case 735:
#line 5735 "lef.y"
                                        {(yyval.string) = (char*)"INOUT";}
#line 11256 "lef.tab.c"
    break;

  case 736:
#line 5736 "lef.y"
                                        {(yyval.string) = (char*)"FEEDTHRU";}
#line 11262 "lef.tab.c"
    break;

  case 737:
#line 5739 "lef.y"
    {
      if (lefCallbacks->PinCbk) {
        lefData->lefrDoGeometries = 1;
        lefData->hasPRP = 0;
        lefData->lefrGeometriesPtr = (lefiGeometries*)lefMalloc( sizeof(lefiGeometries));
        lefData->lefrGeometriesPtr->Init();
      }
      lefData->needGeometry = 0;  // don't need rect/path/poly define yet
      lefData->hasGeoLayer = 0;   // make sure LAYER is set before geometry
    }
#line 11277 "lef.tab.c"
    break;

  case 739:
#line 5752 "lef.y"
    { if (lefData->lefrDoGeometries)
        lefData->lefrGeometriesPtr->addClass((yyvsp[-1].string)); }
#line 11284 "lef.tab.c"
    break;

  case 740:
#line 5756 "lef.y"
                {(yyval.string) = (char*)"SIGNAL";}
#line 11290 "lef.tab.c"
    break;

  case 741:
#line 5757 "lef.y"
                {(yyval.string) = (char*)"ANALOG";}
#line 11296 "lef.tab.c"
    break;

  case 742:
#line 5758 "lef.y"
                {(yyval.string) = (char*)"POWER";}
#line 11302 "lef.tab.c"
    break;

  case 743:
#line 5759 "lef.y"
                {(yyval.string) = (char*)"GROUND";}
#line 11308 "lef.tab.c"
    break;

  case 744:
#line 5760 "lef.y"
                {(yyval.string) = (char*)"CLOCK";}
#line 11314 "lef.tab.c"
    break;

  case 745:
#line 5761 "lef.y"
                {(yyval.string) = (char*)"DATA";}
#line 11320 "lef.tab.c"
    break;

  case 746:
#line 5764 "lef.y"
          {(yyval.string) = (char*)"INPUT";}
#line 11326 "lef.tab.c"
    break;

  case 747:
#line 5765 "lef.y"
                {(yyval.string) = (char*)"OUTPUT";}
#line 11332 "lef.tab.c"
    break;

  case 748:
#line 5766 "lef.y"
                {(yyval.string) = (char*)"START";}
#line 11338 "lef.tab.c"
    break;

  case 749:
#line 5767 "lef.y"
                {(yyval.string) = (char*)"STOP";}
#line 11344 "lef.tab.c"
    break;

  case 750:
#line 5770 "lef.y"
  {(yyval.string) = (char*)""; }
#line 11350 "lef.tab.c"
    break;

  case 751:
#line 5771 "lef.y"
                {(yyval.string) = (char*)"ABUTMENT";}
#line 11356 "lef.tab.c"
    break;

  case 752:
#line 5772 "lef.y"
                {(yyval.string) = (char*)"RING";}
#line 11362 "lef.tab.c"
    break;

  case 753:
#line 5773 "lef.y"
                {(yyval.string) = (char*)"FEEDTHRU";}
#line 11368 "lef.tab.c"
    break;

  case 755:
#line 5778 "lef.y"
          {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 11374 "lef.tab.c"
    break;

  case 756:
#line 5779 "lef.y"
    {
      if ((lefData->needGeometry) && (lefData->needGeometry != 2)) // 1 LAYER follow after another
        if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
          // geometries is called by MACRO/OBS & MACRO/PIN/PORT 
          if (lefData->obsDef)
             lefWarning(2076, "Either PATH, RECT or POLYGON statement is a required in MACRO/OBS.");
          else
             lefWarning(2065, "Either PATH, RECT or POLYGON statement is a required in MACRO/PIN/PORT.");
        }
      if (lefData->lefrDoGeometries)
        lefData->lefrGeometriesPtr->addLayer((yyvsp[0].string));
      lefData->needGeometry = 1;    // within LAYER it requires either path, rect, poly
      lefData->hasGeoLayer = 1;
    }
#line 11393 "lef.tab.c"
    break;

  case 758:
#line 5796 "lef.y"
    { 
      if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else
           lefData->lefrGeometriesPtr->addWidth((yyvsp[-1].dval)); 
      } 
    }
#line 11409 "lef.tab.c"
    break;

  case 759:
#line 5808 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else {
           if (lefData->versionNum < 5.8 && (int)(yyvsp[-3].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
           } else {
                lefData->lefrGeometriesPtr->addPath((int)(yyvsp[-3].integer));
           }
        }
      }
      lefData->hasPRP = 1;
      lefData->needGeometry = 2;
    }
#line 11434 "lef.tab.c"
    break;

  case 760:
#line 5829 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else {
           if (lefData->versionNum < 5.8 && (int)(yyvsp[-5].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
           } else {
              lefData->lefrGeometriesPtr->addPathIter((int)(yyvsp[-5].integer));
            }
         }
      } 
      lefData->hasPRP = 1;
      lefData->needGeometry = 2;
    }
#line 11459 "lef.tab.c"
    break;

  case 761:
#line 5850 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else {
           if (lefData->versionNum < 5.8 && (int)(yyvsp[-3].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
           } else {
              lefData->lefrGeometriesPtr->addRect((int)(yyvsp[-3].integer), (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].pt).x, (yyvsp[-1].pt).y);
           }
        }
      }
      lefData->needGeometry = 2;
    }
#line 11483 "lef.tab.c"
    break;

  case 762:
#line 5870 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else {
           if (lefData->versionNum < 5.8 && (int)(yyvsp[-5].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
           } else {
              lefData->lefrGeometriesPtr->addRectIter((int)(yyvsp[-5].integer), (yyvsp[-3].pt).x, (yyvsp[-3].pt).y, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y);
           }
        }
      }
      lefData->needGeometry = 2;
    }
#line 11507 "lef.tab.c"
    break;

  case 763:
#line 5890 "lef.y"
    {
      if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else {
           if (lefData->versionNum < 5.8 && (int)(yyvsp[-5].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
           } else {
              lefData->lefrGeometriesPtr->addPolygon((int)(yyvsp[-5].integer));
            }
           }
      }
      lefData->hasPRP = 1;
      lefData->needGeometry = 2;
    }
#line 11533 "lef.tab.c"
    break;

  case 764:
#line 5912 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (lefData->hasGeoLayer == 0) {   // LAYER statement is missing 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefError(1701, "A LAYER statement is missing in Geometry.\nLAYER is a required statement before any geometry can be defined.");
              CHKERR();
           }
        } else {
           if (lefData->versionNum < 5.8 && (int)(yyvsp[-7].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
           } else {
              lefData->lefrGeometriesPtr->addPolygonIter((int)(yyvsp[-7].integer));
           }
         }
      }
      lefData->hasPRP = 1;
      lefData->needGeometry = 2;
    }
#line 11558 "lef.tab.c"
    break;

  case 765:
#line 5933 "lef.y"
    { }
#line 11564 "lef.tab.c"
    break;

  case 769:
#line 5940 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "EXCEPTPGNET is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1699, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } else {
       if (lefData->lefrDoGeometries)
        lefData->lefrGeometriesPtr->addLayerExceptPgNet();
      }
    }
#line 11582 "lef.tab.c"
    break;

  case 771:
#line 5956 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (zeroOrGt((yyvsp[0].dval)))
           lefData->lefrGeometriesPtr->addLayerMinSpacing((yyvsp[0].dval));
        else {
           lefData->outMsg = (char*)lefMalloc(10000);
           sprintf (lefData->outMsg,
              "THE SPACING statement has the value %g in MACRO OBS.\nValue has to be 0 or greater.", (yyvsp[0].dval));
           lefError(1659, lefData->outMsg);
           lefFree(lefData->outMsg);
           CHKERR();
        }
      }
    }
#line 11600 "lef.tab.c"
    break;

  case 772:
#line 5970 "lef.y"
    { if (lefData->lefrDoGeometries) {
        if (zeroOrGt((yyvsp[0].dval)))
           lefData->lefrGeometriesPtr->addLayerRuleWidth((yyvsp[0].dval));
        else {
           lefData->outMsg = (char*)lefMalloc(10000);
           sprintf (lefData->outMsg,
              "THE DESIGNRULEWIDTH statement has the value %g in MACRO OBS.\nValue has to be 0 or greater.", (yyvsp[0].dval));
           lefError(1660, lefData->outMsg);
           lefFree(lefData->outMsg);
           CHKERR();
        }
      }
    }
#line 11618 "lef.tab.c"
    break;

  case 773:
#line 5985 "lef.y"
    { if (lefData->lefrDoGeometries)
        lefData->lefrGeometriesPtr->startList((yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 11625 "lef.tab.c"
    break;

  case 774:
#line 5989 "lef.y"
    { if (lefData->lefrDoGeometries)
        lefData->lefrGeometriesPtr->addToList((yyvsp[0].pt).x, (yyvsp[0].pt).y); }
#line 11632 "lef.tab.c"
    break;

  case 777:
#line 5998 "lef.y"
                     {lefData->lefDumbMode = 1;}
#line 11638 "lef.tab.c"
    break;

  case 778:
#line 5999 "lef.y"
    { 
        if (lefData->lefrDoGeometries){
            if (lefData->versionNum < 5.8 && (int)(yyvsp[-4].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
            } else {
                lefData->lefrGeometriesPtr->addVia((int)(yyvsp[-4].integer), (yyvsp[-3].pt).x, (yyvsp[-3].pt).y, (yyvsp[-1].string));
            }
        }
    }
#line 11655 "lef.tab.c"
    break;

  case 779:
#line 6011 "lef.y"
                                 {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 11661 "lef.tab.c"
    break;

  case 780:
#line 6013 "lef.y"
    { 
        if (lefData->lefrDoGeometries) {
            if (lefData->versionNum < 5.8 && (int)(yyvsp[-5].integer) > 0) {
              if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
                 lefError(2083, "Color mask information can only be defined with version 5.8.");
                 CHKERR(); 
              }           
            } else {
              lefData->lefrGeometriesPtr->addViaIter((int)(yyvsp[-5].integer), (yyvsp[-4].pt).x, (yyvsp[-4].pt).y, (yyvsp[-2].string)); 
            }
        }
    }
#line 11678 "lef.tab.c"
    break;

  case 781:
#line 6027 "lef.y"
     { if (lefData->lefrDoGeometries)
         lefData->lefrGeometriesPtr->addStepPattern((yyvsp[-5].dval), (yyvsp[-3].dval), (yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 11685 "lef.tab.c"
    break;

  case 782:
#line 6032 "lef.y"
    {
      if (lefData->lefrDoSite) {
        lefData->lefrSitePatternPtr = (lefiSitePattern*)lefMalloc(
                                   sizeof(lefiSitePattern));
        lefData->lefrSitePatternPtr->Init();
        lefData->lefrSitePatternPtr->set((yyvsp[-10].string), (yyvsp[-9].dval), (yyvsp[-8].dval), (yyvsp[-7].integer), (yyvsp[-5].dval), (yyvsp[-3].dval),
          (yyvsp[-1].dval), (yyvsp[0].dval));
        }
    }
#line 11699 "lef.tab.c"
    break;

  case 783:
#line 6042 "lef.y"
    {
      if (lefData->lefrDoSite) {
        lefData->lefrSitePatternPtr = (lefiSitePattern*)lefMalloc(
                                   sizeof(lefiSitePattern));
        lefData->lefrSitePatternPtr->Init();
        lefData->lefrSitePatternPtr->set((yyvsp[-3].string), (yyvsp[-2].dval), (yyvsp[-1].dval), (yyvsp[0].integer), -1, -1,
          -1, -1);
        }
    }
#line 11713 "lef.tab.c"
    break;

  case 784:
#line 6054 "lef.y"
    { 
      if (lefData->lefrDoTrack) {
        lefData->lefrTrackPatternPtr = (lefiTrackPattern*)lefMalloc(
                                sizeof(lefiTrackPattern));
        lefData->lefrTrackPatternPtr->Init();
        lefData->lefrTrackPatternPtr->set("X", (yyvsp[-4].dval), (int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }    
    }
#line 11726 "lef.tab.c"
    break;

  case 785:
#line 6062 "lef.y"
            {lefData->lefDumbMode = 1000000000;}
#line 11732 "lef.tab.c"
    break;

  case 786:
#line 6063 "lef.y"
    { lefData->lefDumbMode = 0;}
#line 11738 "lef.tab.c"
    break;

  case 787:
#line 6065 "lef.y"
    { 
      if (lefData->lefrDoTrack) {
        lefData->lefrTrackPatternPtr = (lefiTrackPattern*)lefMalloc(
                                    sizeof(lefiTrackPattern));
        lefData->lefrTrackPatternPtr->Init();
        lefData->lefrTrackPatternPtr->set("Y", (yyvsp[-4].dval), (int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }    
    }
#line 11751 "lef.tab.c"
    break;

  case 788:
#line 6073 "lef.y"
            {lefData->lefDumbMode = 1000000000;}
#line 11757 "lef.tab.c"
    break;

  case 789:
#line 6074 "lef.y"
    { lefData->lefDumbMode = 0;}
#line 11763 "lef.tab.c"
    break;

  case 790:
#line 6076 "lef.y"
    { 
      if (lefData->lefrDoTrack) {
        lefData->lefrTrackPatternPtr = (lefiTrackPattern*)lefMalloc(
                                    sizeof(lefiTrackPattern));
        lefData->lefrTrackPatternPtr->Init();
        lefData->lefrTrackPatternPtr->set("X", (yyvsp[-4].dval), (int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }    
    }
#line 11776 "lef.tab.c"
    break;

  case 791:
#line 6085 "lef.y"
    { 
      if (lefData->lefrDoTrack) {
        lefData->lefrTrackPatternPtr = (lefiTrackPattern*)lefMalloc(
                                    sizeof(lefiTrackPattern));
        lefData->lefrTrackPatternPtr->Init();
        lefData->lefrTrackPatternPtr->set("Y", (yyvsp[-4].dval), (int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }    
    }
#line 11789 "lef.tab.c"
    break;

  case 794:
#line 6100 "lef.y"
    { if (lefData->lefrDoTrack) lefData->lefrTrackPatternPtr->addLayer((yyvsp[0].string)); }
#line 11795 "lef.tab.c"
    break;

  case 795:
#line 6103 "lef.y"
    {
      if (lefData->lefrDoGcell) {
        lefData->lefrGcellPatternPtr = (lefiGcellPattern*)lefMalloc(
                                    sizeof(lefiGcellPattern));
        lefData->lefrGcellPatternPtr->Init();
        lefData->lefrGcellPatternPtr->set("X", (yyvsp[-4].dval), (int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }    
    }
#line 11808 "lef.tab.c"
    break;

  case 796:
#line 6112 "lef.y"
    {
      if (lefData->lefrDoGcell) {
        lefData->lefrGcellPatternPtr = (lefiGcellPattern*)lefMalloc(
                                    sizeof(lefiGcellPattern));
        lefData->lefrGcellPatternPtr->Init();
        lefData->lefrGcellPatternPtr->set("Y", (yyvsp[-4].dval), (int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }    
    }
#line 11821 "lef.tab.c"
    break;

  case 797:
#line 6122 "lef.y"
    { 
      if (lefCallbacks->ObstructionCbk) {
        lefData->lefrObstruction.setGeometries(lefData->lefrGeometriesPtr);
        lefData->lefrGeometriesPtr = 0;
        lefData->lefrDoGeometries = 0;
        CALLBACK(lefCallbacks->ObstructionCbk, lefrObstructionCbkType, &lefData->lefrObstruction);
      }
      lefData->lefDumbMode = 0;
      lefData->hasGeoLayer = 0;       // reset 
    }
#line 11836 "lef.tab.c"
    break;

  case 798:
#line 6133 "lef.y"
    {
       // The pointer has malloced in start, need to free manually 
       if (lefData->lefrGeometriesPtr) {
          lefData->lefrGeometriesPtr->Destroy();
          lefFree(lefData->lefrGeometriesPtr);
          lefData->lefrGeometriesPtr = 0;
          lefData->lefrDoGeometries = 0;
       }
       lefData->hasGeoLayer = 0;
    }
#line 11851 "lef.tab.c"
    break;

  case 799:
#line 6145 "lef.y"
    {
      lefData->obsDef = 1;
      if (lefCallbacks->ObstructionCbk) {
        lefData->lefrDoGeometries = 1;
        lefData->lefrGeometriesPtr = (lefiGeometries*)lefMalloc(
            sizeof(lefiGeometries));
        lefData->lefrGeometriesPtr->Init();
        }
      lefData->hasGeoLayer = 0;
    }
#line 11866 "lef.tab.c"
    break;

  case 800:
#line 6157 "lef.y"
    { 
      if (lefData->versionNum < 5.6) {
        if (lefCallbacks->DensityCbk) { // write error only if cbk is set 
           if (lefData->macroWarnings++ < lefSettings->MacroWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "DENSITY statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1661, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
      } 
      if (lefCallbacks->DensityCbk) {
        CALLBACK(lefCallbacks->DensityCbk, lefrDensityCbkType, &lefData->lefrDensity);
        lefData->lefrDensity.clear();
      }
      lefData->lefDumbMode = 0;
    }
#line 11890 "lef.tab.c"
    break;

  case 803:
#line 6181 "lef.y"
                       { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 11896 "lef.tab.c"
    break;

  case 804:
#line 6182 "lef.y"
    {
      if (lefCallbacks->DensityCbk)
        lefData->lefrDensity.addLayer((yyvsp[-1].string));
    }
#line 11905 "lef.tab.c"
    break;

  case 808:
#line 6193 "lef.y"
    {
      if (lefCallbacks->DensityCbk)
        lefData->lefrDensity.addRect((yyvsp[-3].pt).x, (yyvsp[-3].pt).y, (yyvsp[-2].pt).x, (yyvsp[-2].pt).y, (yyvsp[-1].dval)); 
    }
#line 11914 "lef.tab.c"
    break;

  case 809:
#line 6198 "lef.y"
                             { lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 11920 "lef.tab.c"
    break;

  case 810:
#line 6199 "lef.y"
    { if (lefCallbacks->MacroCbk) lefData->lefrMacro.setClockType((yyvsp[-1].string)); }
#line 11926 "lef.tab.c"
    break;

  case 811:
#line 6202 "lef.y"
    { }
#line 11932 "lef.tab.c"
    break;

  case 812:
#line 6205 "lef.y"
    { }
#line 11938 "lef.tab.c"
    break;

  case 813:
#line 6208 "lef.y"
  {
    if (lefData->versionNum < 5.4) {
      if (lefCallbacks->TimingCbk && lefData->lefrTiming.hasData())
        CALLBACK(lefCallbacks->TimingCbk, lefrTimingCbkType, &lefData->lefrTiming);
      lefData->lefrTiming.clear();
    } else {
      if (lefCallbacks->TimingCbk) // write warning only if cbk is set 
        if (lefData->timingWarnings++ < lefSettings->TimingWarnings)
          lefWarning(2066, "MACRO TIMING statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
      lefData->lefrTiming.clear();
    }
  }
#line 11955 "lef.tab.c"
    break;

  case 816:
#line 6228 "lef.y"
    {
    if (lefData->versionNum < 5.4) {
      if (lefCallbacks->TimingCbk && lefData->lefrTiming.hasData())
        CALLBACK(lefCallbacks->TimingCbk, lefrTimingCbkType, &lefData->lefrTiming);
    }
    lefData->lefDumbMode = 1000000000;
    lefData->lefrTiming.clear();
    }
#line 11968 "lef.tab.c"
    break;

  case 817:
#line 6237 "lef.y"
    { lefData->lefDumbMode = 0;}
#line 11974 "lef.tab.c"
    break;

  case 818:
#line 6238 "lef.y"
            {lefData->lefDumbMode = 1000000000;}
#line 11980 "lef.tab.c"
    break;

  case 819:
#line 6239 "lef.y"
    { lefData->lefDumbMode = 0;}
#line 11986 "lef.tab.c"
    break;

  case 820:
#line 6241 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addRiseFall((yyvsp[-3].string),(yyvsp[-1].dval),(yyvsp[0].dval)); }
#line 11992 "lef.tab.c"
    break;

  case 821:
#line 6243 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addRiseFallVariable((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 11998 "lef.tab.c"
    break;

  case 822:
#line 6246 "lef.y"
    { if (lefCallbacks->TimingCbk) {
        if ((yyvsp[-7].string)[0] == 'D' || (yyvsp[-7].string)[0] == 'd') // delay 
          lefData->lefrTiming.addDelay((yyvsp[-8].string), (yyvsp[-5].string), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval));
        else
          lefData->lefrTiming.addTransition((yyvsp[-8].string), (yyvsp[-5].string), (yyvsp[-3].dval), (yyvsp[-2].dval), (yyvsp[-1].dval));
      }
    }
#line 12010 "lef.tab.c"
    break;

  case 823:
#line 6254 "lef.y"
    { }
#line 12016 "lef.tab.c"
    break;

  case 824:
#line 6256 "lef.y"
    { }
#line 12022 "lef.tab.c"
    break;

  case 825:
#line 6258 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setRiseRS((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12028 "lef.tab.c"
    break;

  case 826:
#line 6260 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setFallRS((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12034 "lef.tab.c"
    break;

  case 827:
#line 6262 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setRiseCS((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12040 "lef.tab.c"
    break;

  case 828:
#line 6264 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setFallCS((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12046 "lef.tab.c"
    break;

  case 829:
#line 6266 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setRiseAtt1((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12052 "lef.tab.c"
    break;

  case 830:
#line 6268 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setFallAtt1((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12058 "lef.tab.c"
    break;

  case 831:
#line 6270 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setRiseTo((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12064 "lef.tab.c"
    break;

  case 832:
#line 6272 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setFallTo((yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12070 "lef.tab.c"
    break;

  case 833:
#line 6274 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addUnateness((yyvsp[-1].string)); }
#line 12076 "lef.tab.c"
    break;

  case 834:
#line 6276 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setStable((yyvsp[-4].dval),(yyvsp[-2].dval),(yyvsp[-1].string)); }
#line 12082 "lef.tab.c"
    break;

  case 835:
#line 6278 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addSDF2Pins((yyvsp[-7].string),(yyvsp[-6].string),(yyvsp[-5].string),(yyvsp[-3].dval),(yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12088 "lef.tab.c"
    break;

  case 836:
#line 6280 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addSDF1Pin((yyvsp[-5].string),(yyvsp[-3].dval),(yyvsp[-2].dval),(yyvsp[-2].dval)); }
#line 12094 "lef.tab.c"
    break;

  case 837:
#line 6282 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setSDFcondStart((yyvsp[-1].string)); }
#line 12100 "lef.tab.c"
    break;

  case 838:
#line 6284 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setSDFcondEnd((yyvsp[-1].string)); }
#line 12106 "lef.tab.c"
    break;

  case 839:
#line 6286 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.setSDFcond((yyvsp[-1].string)); }
#line 12112 "lef.tab.c"
    break;

  case 840:
#line 6288 "lef.y"
    { }
#line 12118 "lef.tab.c"
    break;

  case 841:
#line 6292 "lef.y"
    { (yyval.string) = (char*)"MPWH";}
#line 12124 "lef.tab.c"
    break;

  case 842:
#line 6294 "lef.y"
    { (yyval.string) = (char*)"MPWL";}
#line 12130 "lef.tab.c"
    break;

  case 843:
#line 6296 "lef.y"
    { (yyval.string) = (char*)"PERIOD";}
#line 12136 "lef.tab.c"
    break;

  case 844:
#line 6300 "lef.y"
    { (yyval.string) = (char*)"SETUP";}
#line 12142 "lef.tab.c"
    break;

  case 845:
#line 6302 "lef.y"
    { (yyval.string) = (char*)"HOLD";}
#line 12148 "lef.tab.c"
    break;

  case 846:
#line 6304 "lef.y"
    { (yyval.string) = (char*)"RECOVERY";}
#line 12154 "lef.tab.c"
    break;

  case 847:
#line 6306 "lef.y"
    { (yyval.string) = (char*)"SKEW";}
#line 12160 "lef.tab.c"
    break;

  case 848:
#line 6310 "lef.y"
    { (yyval.string) = (char*)"ANYEDGE";}
#line 12166 "lef.tab.c"
    break;

  case 849:
#line 6312 "lef.y"
    { (yyval.string) = (char*)"POSEDGE";}
#line 12172 "lef.tab.c"
    break;

  case 850:
#line 6314 "lef.y"
    { (yyval.string) = (char*)"NEGEDGE";}
#line 12178 "lef.tab.c"
    break;

  case 851:
#line 6318 "lef.y"
    { (yyval.string) = (char*)"ANYEDGE";}
#line 12184 "lef.tab.c"
    break;

  case 852:
#line 6320 "lef.y"
    { (yyval.string) = (char*)"POSEDGE";}
#line 12190 "lef.tab.c"
    break;

  case 853:
#line 6322 "lef.y"
    { (yyval.string) = (char*)"NEGEDGE";}
#line 12196 "lef.tab.c"
    break;

  case 854:
#line 6326 "lef.y"
    { (yyval.string) = (char*)"DELAY"; }
#line 12202 "lef.tab.c"
    break;

  case 855:
#line 6328 "lef.y"
    { (yyval.string) = (char*)"TRANSITION"; }
#line 12208 "lef.tab.c"
    break;

  case 856:
#line 6332 "lef.y"
    { }
#line 12214 "lef.tab.c"
    break;

  case 857:
#line 6334 "lef.y"
    { }
#line 12220 "lef.tab.c"
    break;

  case 858:
#line 6337 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addTableEntry((yyvsp[-3].dval),(yyvsp[-2].dval),(yyvsp[-1].dval)); }
#line 12226 "lef.tab.c"
    break;

  case 859:
#line 6341 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addTableAxisNumber((yyvsp[0].dval)); }
#line 12232 "lef.tab.c"
    break;

  case 860:
#line 6343 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addTableAxisNumber((yyvsp[0].dval)); }
#line 12238 "lef.tab.c"
    break;

  case 861:
#line 6347 "lef.y"
    { }
#line 12244 "lef.tab.c"
    break;

  case 862:
#line 6349 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addRiseFallSlew((yyvsp[-3].dval),(yyvsp[-2].dval),(yyvsp[-1].dval),(yyvsp[0].dval)); }
#line 12250 "lef.tab.c"
    break;

  case 863:
#line 6351 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addRiseFallSlew((yyvsp[-6].dval),(yyvsp[-5].dval),(yyvsp[-4].dval),(yyvsp[-3].dval));
      if (lefCallbacks->TimingCbk) lefData->lefrTiming.addRiseFallSlew2((yyvsp[-2].dval),(yyvsp[-1].dval),(yyvsp[0].dval)); }
#line 12257 "lef.tab.c"
    break;

  case 864:
#line 6356 "lef.y"
    { (yyval.string) = (char*)"RISE"; }
#line 12263 "lef.tab.c"
    break;

  case 865:
#line 6358 "lef.y"
    { (yyval.string) = (char*)"FALL"; }
#line 12269 "lef.tab.c"
    break;

  case 866:
#line 6362 "lef.y"
    { (yyval.string) = (char*)"INVERT"; }
#line 12275 "lef.tab.c"
    break;

  case 867:
#line 6364 "lef.y"
    { (yyval.string) = (char*)"NONINVERT"; }
#line 12281 "lef.tab.c"
    break;

  case 868:
#line 6366 "lef.y"
    { (yyval.string) = (char*)"NONUNATE"; }
#line 12287 "lef.tab.c"
    break;

  case 869:
#line 6370 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addFromPin((yyvsp[0].string)); }
#line 12293 "lef.tab.c"
    break;

  case 870:
#line 6372 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addFromPin((yyvsp[0].string)); }
#line 12299 "lef.tab.c"
    break;

  case 871:
#line 6376 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addToPin((yyvsp[0].string)); }
#line 12305 "lef.tab.c"
    break;

  case 872:
#line 6378 "lef.y"
    { if (lefCallbacks->TimingCbk) lefData->lefrTiming.addToPin((yyvsp[0].string)); }
#line 12311 "lef.tab.c"
    break;

  case 873:
#line 6381 "lef.y"
    {
      if (lefCallbacks->ArrayCbk)
        CALLBACK(lefCallbacks->ArrayCbk, lefrArrayCbkType, &lefData->lefrArray);
      lefData->lefrArray.clear();
      lefData->lefrSitePatternPtr = 0;
      lefData->lefrDoSite = 0;
   }
#line 12323 "lef.tab.c"
    break;

  case 875:
#line 6390 "lef.y"
                     {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 12329 "lef.tab.c"
    break;

  case 876:
#line 6391 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.setName((yyvsp[0].string));
        CALLBACK(lefCallbacks->ArrayBeginCbk, lefrArrayBeginCbkType, (yyvsp[0].string));
      }
      //strcpy(lefData->arrayName, $3);
      lefData->arrayName = strdup((yyvsp[0].string));
    }
#line 12342 "lef.tab.c"
    break;

  case 877:
#line 6400 "lef.y"
                 {lefData->lefDumbMode = 1; lefData->lefNoNum = 1;}
#line 12348 "lef.tab.c"
    break;

  case 878:
#line 6401 "lef.y"
    {
      if (lefCallbacks->ArrayCbk && lefCallbacks->ArrayEndCbk)
        CALLBACK(lefCallbacks->ArrayEndCbk, lefrArrayEndCbkType, (yyvsp[0].string));
      if (strcmp(lefData->arrayName, (yyvsp[0].string)) != 0) {
        if (lefCallbacks->ArrayCbk) { // write error only if cbk is set 
           if (lefData->arrayWarnings++ < lefSettings->ArrayWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "END ARRAY name %s is different from the ARRAY name %s.\nCorrect the LEF file before rerunning it through the LEF parser.", (yyvsp[0].string), lefData->arrayName);
              lefError(1662, lefData->outMsg);
              lefFree(lefData->outMsg);
              lefFree(lefData->arrayName);
              CHKERR();
           } else
              lefFree(lefData->arrayName);
        } else
           lefFree(lefData->arrayName);
      } else
        lefFree(lefData->arrayName);
    }
#line 12373 "lef.tab.c"
    break;

  case 879:
#line 6424 "lef.y"
    { }
#line 12379 "lef.tab.c"
    break;

  case 880:
#line 6426 "lef.y"
    { }
#line 12385 "lef.tab.c"
    break;

  case 881:
#line 6429 "lef.y"
            { if (lefCallbacks->ArrayCbk) lefData->lefrDoSite = 1; lefData->lefDumbMode = 1; }
#line 12391 "lef.tab.c"
    break;

  case 882:
#line 6431 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.addSitePattern(lefData->lefrSitePatternPtr);
      }
    }
#line 12401 "lef.tab.c"
    break;

  case 883:
#line 6436 "lef.y"
               {lefData->lefDumbMode = 1; if (lefCallbacks->ArrayCbk) lefData->lefrDoSite = 1; }
#line 12407 "lef.tab.c"
    break;

  case 884:
#line 6438 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.addCanPlace(lefData->lefrSitePatternPtr);
      }
    }
#line 12417 "lef.tab.c"
    break;

  case 885:
#line 6443 "lef.y"
                   {lefData->lefDumbMode = 1; if (lefCallbacks->ArrayCbk) lefData->lefrDoSite = 1; }
#line 12423 "lef.tab.c"
    break;

  case 886:
#line 6445 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.addCannotOccupy(lefData->lefrSitePatternPtr);
      }
    }
#line 12433 "lef.tab.c"
    break;

  case 887:
#line 6450 "lef.y"
             { if (lefCallbacks->ArrayCbk) lefData->lefrDoTrack = 1; }
#line 12439 "lef.tab.c"
    break;

  case 888:
#line 6451 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.addTrack(lefData->lefrTrackPatternPtr);
      }
    }
#line 12449 "lef.tab.c"
    break;

  case 889:
#line 6457 "lef.y"
    {
    }
#line 12456 "lef.tab.c"
    break;

  case 890:
#line 6459 "lef.y"
                { if (lefCallbacks->ArrayCbk) lefData->lefrDoGcell = 1; }
#line 12462 "lef.tab.c"
    break;

  case 891:
#line 6460 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.addGcell(lefData->lefrGcellPatternPtr);
      }
    }
#line 12472 "lef.tab.c"
    break;

  case 892:
#line 6466 "lef.y"
    {
      if (lefCallbacks->ArrayCbk) {
        lefData->lefrArray.setTableSize((int)(yyvsp[-3].dval));
      }
    }
#line 12482 "lef.tab.c"
    break;

  case 893:
#line 6472 "lef.y"
    { }
#line 12488 "lef.tab.c"
    break;

  case 894:
#line 6475 "lef.y"
    { if (lefCallbacks->ArrayCbk) lefData->lefrArray.addFloorPlan((yyvsp[0].string)); }
#line 12494 "lef.tab.c"
    break;

  case 895:
#line 6479 "lef.y"
    { }
#line 12500 "lef.tab.c"
    break;

  case 896:
#line 6481 "lef.y"
    { }
#line 12506 "lef.tab.c"
    break;

  case 897:
#line 6484 "lef.y"
             { lefData->lefDumbMode = 1; if (lefCallbacks->ArrayCbk) lefData->lefrDoSite = 1; }
#line 12512 "lef.tab.c"
    break;

  case 898:
#line 6486 "lef.y"
    {
      if (lefCallbacks->ArrayCbk)
        lefData->lefrArray.addSiteToFloorPlan("CANPLACE",
        lefData->lefrSitePatternPtr);
    }
#line 12522 "lef.tab.c"
    break;

  case 899:
#line 6491 "lef.y"
                   { if (lefCallbacks->ArrayCbk) lefData->lefrDoSite = 1; lefData->lefDumbMode = 1; }
#line 12528 "lef.tab.c"
    break;

  case 900:
#line 6493 "lef.y"
    {
      if (lefCallbacks->ArrayCbk)
        lefData->lefrArray.addSiteToFloorPlan("CANNOTOCCUPY",
        lefData->lefrSitePatternPtr);
     }
#line 12538 "lef.tab.c"
    break;

  case 901:
#line 6501 "lef.y"
    { }
#line 12544 "lef.tab.c"
    break;

  case 902:
#line 6503 "lef.y"
    { }
#line 12550 "lef.tab.c"
    break;

  case 903:
#line 6506 "lef.y"
    { if (lefCallbacks->ArrayCbk) lefData->lefrArray.addDefaultCap((int)(yyvsp[-3].dval), (yyvsp[-1].dval)); }
#line 12556 "lef.tab.c"
    break;

  case 904:
#line 6509 "lef.y"
            {lefData->lefDumbMode=1;lefData->lefNlToken=TRUE;}
#line 12562 "lef.tab.c"
    break;

  case 905:
#line 6510 "lef.y"
    {  }
#line 12568 "lef.tab.c"
    break;

  case 906:
#line 6513 "lef.y"
               {lefData->lefDumbMode=1;lefData->lefNlToken=TRUE;}
#line 12574 "lef.tab.c"
    break;

  case 907:
#line 6514 "lef.y"
    { }
#line 12580 "lef.tab.c"
    break;

  case 908:
#line 6517 "lef.y"
           {lefData->lefDumbMode=1;lefData->lefNlToken=TRUE;}
#line 12586 "lef.tab.c"
    break;

  case 909:
#line 6518 "lef.y"
    {
      if (lefData->versionNum < 5.6)
        lefAddNumDefine((yyvsp[-3].string), (yyvsp[-1].dval));
      else
        if (lefCallbacks->ArrayCbk) // write warning only if cbk is set 
           if (lefData->arrayWarnings++ < lefSettings->ArrayWarnings)
             lefWarning(2067, "DEFINE statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 12599 "lef.tab.c"
    break;

  case 910:
#line 6526 "lef.y"
               {lefData->lefDumbMode=1;lefData->lefNlToken=TRUE;}
#line 12605 "lef.tab.c"
    break;

  case 911:
#line 6527 "lef.y"
    {
      if (lefData->versionNum < 5.6)
        lefAddStringDefine((yyvsp[-3].string), (yyvsp[-1].string));
      else
        if (lefCallbacks->ArrayCbk) // write warning only if cbk is set 
           if (lefData->arrayWarnings++ < lefSettings->ArrayWarnings)
             lefWarning(2068, "DEFINES statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 12618 "lef.tab.c"
    break;

  case 912:
#line 6535 "lef.y"
               {lefData->lefDumbMode=1;lefData->lefNlToken=TRUE;}
#line 12624 "lef.tab.c"
    break;

  case 913:
#line 6536 "lef.y"
    {
      if (lefData->versionNum < 5.6)
        lefAddBooleanDefine((yyvsp[-3].string), (yyvsp[-1].integer));
      else
        if (lefCallbacks->ArrayCbk) // write warning only if cbk is set 
           if (lefData->arrayWarnings++ < lefSettings->ArrayWarnings)
             lefWarning(2069, "DEFINEB statement is obsolete in version 5.6 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.6 or later.");
    }
#line 12637 "lef.tab.c"
    break;

  case 915:
#line 6547 "lef.y"
         {lefData->lefNlToken = FALSE;}
#line 12643 "lef.tab.c"
    break;

  case 916:
#line 6548 "lef.y"
                 {lefData->lefNlToken = FALSE;}
#line 12649 "lef.tab.c"
    break;

  case 921:
#line 6561 "lef.y"
                                {(yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); }
#line 12655 "lef.tab.c"
    break;

  case 922:
#line 6562 "lef.y"
                                {(yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); }
#line 12661 "lef.tab.c"
    break;

  case 923:
#line 6563 "lef.y"
                                {(yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); }
#line 12667 "lef.tab.c"
    break;

  case 924:
#line 6564 "lef.y"
                                {(yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval); }
#line 12673 "lef.tab.c"
    break;

  case 925:
#line 6565 "lef.y"
                                {(yyval.dval) = -(yyvsp[0].dval);}
#line 12679 "lef.tab.c"
    break;

  case 926:
#line 6566 "lef.y"
                                {(yyval.dval) = (yyvsp[-1].dval);}
#line 12685 "lef.tab.c"
    break;

  case 927:
#line 6568 "lef.y"
                {(yyval.dval) = ((yyvsp[-4].integer) != 0) ? (yyvsp[-2].dval) : (yyvsp[0].dval);}
#line 12691 "lef.tab.c"
    break;

  case 928:
#line 6569 "lef.y"
                                     {(yyval.dval) = (yyvsp[0].dval);}
#line 12697 "lef.tab.c"
    break;

  case 929:
#line 6572 "lef.y"
                              {(yyval.integer) = comp_num((yyvsp[-2].dval),(yyvsp[-1].integer),(yyvsp[0].dval));}
#line 12703 "lef.tab.c"
    break;

  case 930:
#line 6573 "lef.y"
                                {(yyval.integer) = (yyvsp[-2].dval) != 0 && (yyvsp[0].dval) != 0;}
#line 12709 "lef.tab.c"
    break;

  case 931:
#line 6574 "lef.y"
                                {(yyval.integer) = (yyvsp[-2].dval) != 0 || (yyvsp[0].dval) != 0;}
#line 12715 "lef.tab.c"
    break;

  case 932:
#line 6575 "lef.y"
                              {(yyval.integer) = comp_str((yyvsp[-2].string),(yyvsp[-1].integer),(yyvsp[0].string));}
#line 12721 "lef.tab.c"
    break;

  case 933:
#line 6576 "lef.y"
                              {(yyval.integer) = (yyvsp[-2].string)[0] != 0 && (yyvsp[0].string)[0] != 0;}
#line 12727 "lef.tab.c"
    break;

  case 934:
#line 6577 "lef.y"
                              {(yyval.integer) = (yyvsp[-2].string)[0] != 0 || (yyvsp[0].string)[0] != 0;}
#line 12733 "lef.tab.c"
    break;

  case 935:
#line 6578 "lef.y"
                              {(yyval.integer) = (yyvsp[-2].integer) == (yyvsp[0].integer);}
#line 12739 "lef.tab.c"
    break;

  case 936:
#line 6579 "lef.y"
                              {(yyval.integer) = (yyvsp[-2].integer) != (yyvsp[0].integer);}
#line 12745 "lef.tab.c"
    break;

  case 937:
#line 6580 "lef.y"
                              {(yyval.integer) = (yyvsp[-2].integer) && (yyvsp[0].integer);}
#line 12751 "lef.tab.c"
    break;

  case 938:
#line 6581 "lef.y"
                              {(yyval.integer) = (yyvsp[-2].integer) || (yyvsp[0].integer);}
#line 12757 "lef.tab.c"
    break;

  case 939:
#line 6582 "lef.y"
                                               {(yyval.integer) = !(yyval.integer);}
#line 12763 "lef.tab.c"
    break;

  case 940:
#line 6583 "lef.y"
                              {(yyval.integer) = (yyvsp[-1].integer);}
#line 12769 "lef.tab.c"
    break;

  case 941:
#line 6585 "lef.y"
        {(yyval.integer) = ((yyvsp[-4].integer) != 0) ? (yyvsp[-2].integer) : (yyvsp[0].integer);}
#line 12775 "lef.tab.c"
    break;

  case 942:
#line 6586 "lef.y"
                              {(yyval.integer) = 1;}
#line 12781 "lef.tab.c"
    break;

  case 943:
#line 6587 "lef.y"
                              {(yyval.integer) = 0;}
#line 12787 "lef.tab.c"
    break;

  case 944:
#line 6591 "lef.y"
    {
      (yyval.string) = (char*)lefMalloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcat((yyval.string),(yyvsp[0].string));
    }
#line 12797 "lef.tab.c"
    break;

  case 945:
#line 6597 "lef.y"
    { (yyval.string) = (yyvsp[-1].string); }
#line 12803 "lef.tab.c"
    break;

  case 946:
#line 6599 "lef.y"
    {
      lefData->lefDefIf = TRUE;
      if ((yyvsp[-4].integer) != 0) {
        (yyval.string) = (yyvsp[-2].string);        
      } else {
        (yyval.string) = (yyvsp[0].string);
      }
    }
#line 12816 "lef.tab.c"
    break;

  case 947:
#line 6608 "lef.y"
    { (yyval.string) = (yyvsp[0].string); }
#line 12822 "lef.tab.c"
    break;

  case 948:
#line 6611 "lef.y"
       {(yyval.integer) = C_LE;}
#line 12828 "lef.tab.c"
    break;

  case 949:
#line 6612 "lef.y"
         {(yyval.integer) = C_LT;}
#line 12834 "lef.tab.c"
    break;

  case 950:
#line 6613 "lef.y"
         {(yyval.integer) = C_GE;}
#line 12840 "lef.tab.c"
    break;

  case 951:
#line 6614 "lef.y"
         {(yyval.integer) = C_GT;}
#line 12846 "lef.tab.c"
    break;

  case 952:
#line 6615 "lef.y"
         {(yyval.integer) = C_EQ;}
#line 12852 "lef.tab.c"
    break;

  case 953:
#line 6616 "lef.y"
         {(yyval.integer) = C_NE;}
#line 12858 "lef.tab.c"
    break;

  case 954:
#line 6617 "lef.y"
         {(yyval.integer) = C_EQ;}
#line 12864 "lef.tab.c"
    break;

  case 955:
#line 6618 "lef.y"
         {(yyval.integer) = C_LT;}
#line 12870 "lef.tab.c"
    break;

  case 956:
#line 6619 "lef.y"
         {(yyval.integer) = C_GT;}
#line 12876 "lef.tab.c"
    break;

  case 957:
#line 6623 "lef.y"
    { 
      if (lefCallbacks->PropBeginCbk)
        CALLBACK(lefCallbacks->PropBeginCbk, lefrPropBeginCbkType, 0);
    }
#line 12885 "lef.tab.c"
    break;

  case 958:
#line 6628 "lef.y"
    { 
      if (lefCallbacks->PropEndCbk)
        CALLBACK(lefCallbacks->PropEndCbk, lefrPropEndCbkType, 0);
    }
#line 12894 "lef.tab.c"
    break;

  case 959:
#line 6635 "lef.y"
    { }
#line 12900 "lef.tab.c"
    break;

  case 960:
#line 6637 "lef.y"
    { }
#line 12906 "lef.tab.c"
    break;

  case 961:
#line 6640 "lef.y"
            {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 12912 "lef.tab.c"
    break;

  case 962:
#line 6642 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("library", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrLibProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 12924 "lef.tab.c"
    break;

  case 963:
#line 6649 "lef.y"
                   {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 12930 "lef.tab.c"
    break;

  case 964:
#line 6651 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("componentpin", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrCompProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 12942 "lef.tab.c"
    break;

  case 965:
#line 6658 "lef.y"
          {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 12948 "lef.tab.c"
    break;

  case 966:
#line 6660 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("pin", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrPinProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
      
    }
#line 12961 "lef.tab.c"
    break;

  case 967:
#line 6668 "lef.y"
            {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 12967 "lef.tab.c"
    break;

  case 968:
#line 6670 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("macro", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrMacroProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 12979 "lef.tab.c"
    break;

  case 969:
#line 6677 "lef.y"
          {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 12985 "lef.tab.c"
    break;

  case 970:
#line 6679 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("via", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrViaProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 12997 "lef.tab.c"
    break;

  case 971:
#line 6686 "lef.y"
              {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 13003 "lef.tab.c"
    break;

  case 972:
#line 6688 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("viarule", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrViaRuleProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 13015 "lef.tab.c"
    break;

  case 973:
#line 6695 "lef.y"
            {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 13021 "lef.tab.c"
    break;

  case 974:
#line 6697 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("layer", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrLayerProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 13033 "lef.tab.c"
    break;

  case 975:
#line 6704 "lef.y"
                     {lefData->lefDumbMode = 1; lefData->lefrProp.clear(); }
#line 13039 "lef.tab.c"
    break;

  case 976:
#line 6706 "lef.y"
    { 
      if (lefCallbacks->PropCbk) {
        lefData->lefrProp.setPropType("nondefaultrule", (yyvsp[-2].string));
        CALLBACK(lefCallbacks->PropCbk, lefrPropCbkType, &lefData->lefrProp);
      }
      lefSettings->lefProps.lefrNondefProp.setPropType((yyvsp[-2].string), lefData->lefPropDefType);
    }
#line 13051 "lef.tab.c"
    break;

  case 977:
#line 6716 "lef.y"
    { 
      if (lefCallbacks->PropCbk) lefData->lefrProp.setPropInteger();
      lefData->lefPropDefType = 'I';
    }
#line 13060 "lef.tab.c"
    break;

  case 978:
#line 6721 "lef.y"
    { 
      if (lefCallbacks->PropCbk) lefData->lefrProp.setPropReal();
      lefData->lefPropDefType = 'R';
    }
#line 13069 "lef.tab.c"
    break;

  case 979:
#line 6726 "lef.y"
    {
      if (lefCallbacks->PropCbk) lefData->lefrProp.setPropString();
      lefData->lefPropDefType = 'S';
    }
#line 13078 "lef.tab.c"
    break;

  case 980:
#line 6731 "lef.y"
    {
      if (lefCallbacks->PropCbk) lefData->lefrProp.setPropQString((yyvsp[0].string));
      lefData->lefPropDefType = 'Q';
    }
#line 13087 "lef.tab.c"
    break;

  case 981:
#line 6736 "lef.y"
    {
      if (lefCallbacks->PropCbk) lefData->lefrProp.setPropNameMapString((yyvsp[0].string));
      lefData->lefPropDefType = 'S';
    }
#line 13096 "lef.tab.c"
    break;

  case 982:
#line 6743 "lef.y"
    { }
#line 13102 "lef.tab.c"
    break;

  case 983:
#line 6745 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingRangeUseLength();
    }
#line 13111 "lef.tab.c"
    break;

  case 984:
#line 6750 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        lefData->lefrLayer.setSpacingRangeInfluence((yyvsp[0].dval));
        lefData->lefrLayer.setSpacingRangeInfluenceRange(-1, -1);
      }
    }
#line 13122 "lef.tab.c"
    break;

  case 985:
#line 6757 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        lefData->lefrLayer.setSpacingRangeInfluence((yyvsp[-3].dval));
        lefData->lefrLayer.setSpacingRangeInfluenceRange((yyvsp[-1].dval), (yyvsp[0].dval));
      }
    }
#line 13133 "lef.tab.c"
    break;

  case 986:
#line 6764 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingRangeRange((yyvsp[-1].dval), (yyvsp[0].dval));
    }
#line 13142 "lef.tab.c"
    break;

  case 987:
#line 6771 "lef.y"
    { }
#line 13148 "lef.tab.c"
    break;

  case 988:
#line 6773 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingParSW((yyvsp[-2].dval), (yyvsp[0].dval));
    }
#line 13157 "lef.tab.c"
    break;

  case 990:
#line 6781 "lef.y"
    { }
#line 13163 "lef.tab.c"
    break;

  case 991:
#line 6783 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingParTwoEdges();
    }
#line 13172 "lef.tab.c"
    break;

  case 992:
#line 6790 "lef.y"
    { }
#line 13178 "lef.tab.c"
    break;

  case 993:
#line 6792 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingSamenetPGonly();
    }
#line 13187 "lef.tab.c"
    break;

  case 994:
#line 6799 "lef.y"
    { }
#line 13193 "lef.tab.c"
    break;

  case 995:
#line 6801 "lef.y"
    {  if (lefCallbacks->PropCbk) lefData->lefrProp.setRange((yyvsp[-1].dval), (yyvsp[0].dval)); }
#line 13199 "lef.tab.c"
    break;

  case 996:
#line 6805 "lef.y"
    { }
#line 13205 "lef.tab.c"
    break;

  case 997:
#line 6807 "lef.y"
    { if (lefCallbacks->PropCbk) lefData->lefrProp.setNumber((yyvsp[0].dval)); }
#line 13211 "lef.tab.c"
    break;

  case 998:
#line 6811 "lef.y"
    { }
#line 13217 "lef.tab.c"
    break;

  case 999:
#line 6813 "lef.y"
    { if (lefCallbacks->PropCbk) lefData->lefrProp.setNumber((yyvsp[0].dval)); }
#line 13223 "lef.tab.c"
    break;

  case 1002:
#line 6820 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
         if (lefData->hasSpCenter) {
           if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1663, "A CENTERTOCENTER statement was already defined in SPACING\nCENTERTOCENTER can only be defined once per LAYER CUT SPACING.");
              CHKERR();
           }
        }
        lefData->hasSpCenter = 1;
        if (lefData->versionNum < 5.6) {
           if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "CENTERTOCENTER statement is a version 5.6 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1664, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
        if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setSpacingCenterToCenter();
      }
    }
#line 13251 "lef.tab.c"
    break;

  case 1003:
#line 6844 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        if (lefData->hasSpSamenet) {
           if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefError(1665, "A SAMENET statement was already defined in SPACING\nSAMENET can only be defined once per LAYER CUT SPACING.");
              CHKERR();
           }
        }
        lefData->hasSpSamenet = 1;
        if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setSpacingSamenet();
       }
    }
#line 13269 "lef.tab.c"
    break;

  case 1004:
#line 6858 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "SAMENET is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1684, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      }
    }
#line 13284 "lef.tab.c"
    break;

  case 1005:
#line 6869 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "PARALLELOVERLAP is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1680, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR(); 
      } else {
        if (lefCallbacks->LayerCbk) {
          if (lefData->hasSpParallel) {
             if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                lefError(1666, "A PARALLELOVERLAP statement was already defined in SPACING\nPARALLELOVERLAP can only be defined once per LAYER CUT SPACING.");
                CHKERR();
             }
          }
          lefData->hasSpParallel = 1;
          if (lefCallbacks->LayerCbk)
            lefData->lefrLayer.setSpacingParallelOverlap();
        }
      }
    }
#line 13311 "lef.tab.c"
    break;

  case 1007:
#line 6894 "lef.y"
            {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 13317 "lef.tab.c"
    break;

  case 1008:
#line 6895 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
{
        if (lefData->versionNum < 5.7) {
           if (lefData->hasSpSamenet) {    // 5.6 and earlier does not allow 
              if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefError(1667, "A SAMENET statement was already defined in SPACING\nEither SAMENET or LAYER can be defined, but not both.");
                 CHKERR();
              }
           }
        }
        lefData->lefrLayer.setSpacingName((yyvsp[0].string));
      }
    }
#line 13336 "lef.tab.c"
    break;

  case 1010:
#line 6911 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        if (lefData->versionNum < 5.5) {
           if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
              lefData->outMsg = (char*)lefMalloc(10000);
              sprintf (lefData->outMsg,
                 "ADJACENTCUTS statement is a version 5.5 and later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
              lefError(1668, lefData->outMsg);
              lefFree(lefData->outMsg);
              CHKERR();
           }
        }
        if (lefData->versionNum < 5.7) {
           if (lefData->hasSpSamenet) {    // 5.6 and earlier does not allow 
              if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                 lefError(1669, "A SAMENET statement was already defined in SPACING\nEither SAMENET or ADJACENTCUTS can be defined, but not both.");
                 CHKERR();
              }
           }
        }
        lefData->lefrLayer.setSpacingAdjacent((int)(yyvsp[-2].dval), (yyvsp[0].dval));
      }
    }
#line 13364 "lef.tab.c"
    break;

  case 1012:
#line 6936 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "AREA is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1693, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } else {
        if (lefCallbacks->LayerCbk) {
          if (lefData->versionNum < 5.7) {
             if (lefData->hasSpSamenet) {    // 5.6 and earlier does not allow 
                if (lefData->layerWarnings++ < lefSettings->LayerWarnings) {
                   lefError(1670, "A SAMENET statement was already defined in SPACING\nEither SAMENET or AREA can be defined, but not both.");
                   CHKERR();
                }
             }
          }
          lefData->lefrLayer.setSpacingArea((yyvsp[0].dval));
        }
      }
    }
#line 13391 "lef.tab.c"
    break;

  case 1013:
#line 6959 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingRange((yyvsp[-1].dval), (yyvsp[0].dval));
    }
#line 13400 "lef.tab.c"
    break;

  case 1015:
#line 6965 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        lefData->lefrLayer.setSpacingLength((yyvsp[0].dval));
      }
    }
#line 13410 "lef.tab.c"
    break;

  case 1016:
#line 6971 "lef.y"
    {
      if (lefCallbacks->LayerCbk) {
        lefData->lefrLayer.setSpacingLength((yyvsp[-3].dval));
        lefData->lefrLayer.setSpacingLengthRange((yyvsp[-1].dval), (yyvsp[0].dval));
      }
    }
#line 13421 "lef.tab.c"
    break;

  case 1017:
#line 6978 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingEol((yyvsp[-2].dval), (yyvsp[0].dval));
    }
#line 13430 "lef.tab.c"
    break;

  case 1018:
#line 6983 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "ENDOFLINE is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1681, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      }
    }
#line 13445 "lef.tab.c"
    break;

  case 1019:
#line 6994 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "NOTCHLENGTH is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1682, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } else {
        if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setSpacingNotchLength((yyvsp[0].dval));
      }
    }
#line 13463 "lef.tab.c"
    break;

  case 1020:
#line 7008 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "ENDOFNOTCHWIDTH is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1696, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } else {
        if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setSpacingEndOfNotchWidth((yyvsp[-4].dval), (yyvsp[-2].dval), (yyvsp[0].dval));
      }
    }
#line 13481 "lef.tab.c"
    break;

  case 1021:
#line 7024 "lef.y"
    {}
#line 13487 "lef.tab.c"
    break;

  case 1022:
#line 7026 "lef.y"
    {
      if (lefCallbacks->LayerCbk)
        lefData->lefrLayer.setSpacingLayerStack();
    }
#line 13496 "lef.tab.c"
    break;

  case 1023:
#line 7033 "lef.y"
    {}
#line 13502 "lef.tab.c"
    break;

  case 1024:
#line 7035 "lef.y"
    {
      if (lefData->versionNum < 5.7) {
        lefData->outMsg = (char*)lefMalloc(10000);
        sprintf(lefData->outMsg,
          "EXCEPTSAMEPGNET is a version 5.7 or later syntax.\nYour lef file is defined with version %g.", lefData->versionNum);
        lefError(1683, lefData->outMsg);
        lefFree(lefData->outMsg);
        CHKERR();
      } else {
        if (lefCallbacks->LayerCbk)
          lefData->lefrLayer.setSpacingAdjacentExcept();
      }
    }
#line 13520 "lef.tab.c"
    break;

  case 1025:
#line 7051 "lef.y"
    { (yyval.string) = 0; }
#line 13526 "lef.tab.c"
    break;

  case 1026:
#line 7052 "lef.y"
            {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 13532 "lef.tab.c"
    break;

  case 1027:
#line 7053 "lef.y"
    { (yyval.string) = (yyvsp[0].string); }
#line 13538 "lef.tab.c"
    break;

  case 1028:
#line 7057 "lef.y"
           {lefData->lefDumbMode = 1; lefData->lefNoNum = 1; }
#line 13544 "lef.tab.c"
    break;

  case 1029:
#line 7058 "lef.y"
    { (yyval.string) = (yyvsp[0].string); }
#line 13550 "lef.tab.c"
    break;

  case 1030:
#line 7062 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->NoiseMarginCbk) {
          lefData->lefrNoiseMargin.low = (yyvsp[-2].dval);
          lefData->lefrNoiseMargin.high = (yyvsp[-1].dval);
          CALLBACK(lefCallbacks->NoiseMarginCbk, lefrNoiseMarginCbkType, &lefData->lefrNoiseMargin);
        }
      } else
        if (lefCallbacks->NoiseMarginCbk) // write warning only if cbk is set 
          if (lefData->noiseMarginWarnings++ < lefSettings->NoiseMarginWarnings)
            lefWarning(2070, "UNIVERSALNOISEMARGIN statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 13567 "lef.tab.c"
    break;

  case 1031:
#line 7076 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->EdgeRateThreshold1Cbk) {
          CALLBACK(lefCallbacks->EdgeRateThreshold1Cbk,
          lefrEdgeRateThreshold1CbkType, (yyvsp[-1].dval));
        }
      } else
        if (lefCallbacks->EdgeRateThreshold1Cbk) // write warning only if cbk is set 
          if (lefData->edgeRateThreshold1Warnings++ < lefSettings->EdgeRateThreshold1Warnings)
            lefWarning(2071, "EDGERATETHRESHOLD1 statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 13583 "lef.tab.c"
    break;

  case 1032:
#line 7089 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->EdgeRateThreshold2Cbk) {
          CALLBACK(lefCallbacks->EdgeRateThreshold2Cbk,
          lefrEdgeRateThreshold2CbkType, (yyvsp[-1].dval));
        }
      } else
        if (lefCallbacks->EdgeRateThreshold2Cbk) // write warning only if cbk is set 
          if (lefData->edgeRateThreshold2Warnings++ < lefSettings->EdgeRateThreshold2Warnings)
            lefWarning(2072, "EDGERATETHRESHOLD2 statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 13599 "lef.tab.c"
    break;

  case 1033:
#line 7102 "lef.y"
    {
      if (lefData->versionNum < 5.4) {
        if (lefCallbacks->EdgeRateScaleFactorCbk) {
          CALLBACK(lefCallbacks->EdgeRateScaleFactorCbk,
          lefrEdgeRateScaleFactorCbkType, (yyvsp[-1].dval));
        }
      } else
        if (lefCallbacks->EdgeRateScaleFactorCbk) // write warning only if cbk is set 
          if (lefData->edgeRateScaleFactorWarnings++ < lefSettings->EdgeRateScaleFactorWarnings)
            lefWarning(2073, "EDGERATESCALEFACTOR statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
    }
#line 13615 "lef.tab.c"
    break;

  case 1034:
#line 7115 "lef.y"
    { if (lefCallbacks->NoiseTableCbk) lefData->lefrNoiseTable.setup((int)(yyvsp[0].dval)); }
#line 13621 "lef.tab.c"
    break;

  case 1035:
#line 7117 "lef.y"
    { }
#line 13627 "lef.tab.c"
    break;

  case 1036:
#line 7121 "lef.y"
  {
    if (lefData->versionNum < 5.4) {
      if (lefCallbacks->NoiseTableCbk)
        CALLBACK(lefCallbacks->NoiseTableCbk, lefrNoiseTableCbkType, &lefData->lefrNoiseTable);
    } else
      if (lefCallbacks->NoiseTableCbk) // write warning only if cbk is set 
        if (lefData->noiseTableWarnings++ < lefSettings->NoiseTableWarnings)
          lefWarning(2074, "NOISETABLE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
  }
#line 13641 "lef.tab.c"
    break;

  case 1039:
#line 7139 "lef.y"
    { if (lefCallbacks->NoiseTableCbk)
         {
            lefData->lefrNoiseTable.newEdge();
            lefData->lefrNoiseTable.addEdge((yyvsp[-1].dval));
         }
    }
#line 13652 "lef.tab.c"
    break;

  case 1040:
#line 7146 "lef.y"
    { }
#line 13658 "lef.tab.c"
    break;

  case 1041:
#line 7149 "lef.y"
    { if (lefCallbacks->NoiseTableCbk) lefData->lefrNoiseTable.addResistance(); }
#line 13664 "lef.tab.c"
    break;

  case 1043:
#line 7155 "lef.y"
    { if (lefCallbacks->NoiseTableCbk)
    lefData->lefrNoiseTable.addResistanceNumber((yyvsp[0].dval)); }
#line 13671 "lef.tab.c"
    break;

  case 1044:
#line 7158 "lef.y"
    { if (lefCallbacks->NoiseTableCbk)
    lefData->lefrNoiseTable.addResistanceNumber((yyvsp[0].dval)); }
#line 13678 "lef.tab.c"
    break;

  case 1047:
#line 7167 "lef.y"
        { if (lefCallbacks->NoiseTableCbk)
        lefData->lefrNoiseTable.addVictimLength((yyvsp[-1].dval)); }
#line 13685 "lef.tab.c"
    break;

  case 1048:
#line 7170 "lef.y"
        { }
#line 13691 "lef.tab.c"
    break;

  case 1049:
#line 7174 "lef.y"
    { if (lefCallbacks->NoiseTableCbk)
    lefData->lefrNoiseTable.addVictimNoise((yyvsp[0].dval)); }
#line 13698 "lef.tab.c"
    break;

  case 1050:
#line 7177 "lef.y"
    { if (lefCallbacks->NoiseTableCbk)
    lefData->lefrNoiseTable.addVictimNoise((yyvsp[0].dval)); }
#line 13705 "lef.tab.c"
    break;

  case 1051:
#line 7181 "lef.y"
    { if (lefCallbacks->CorrectionTableCbk)
    lefData->lefrCorrectionTable.setup((int)(yyvsp[-1].dval)); }
#line 13712 "lef.tab.c"
    break;

  case 1052:
#line 7184 "lef.y"
    { }
#line 13718 "lef.tab.c"
    break;

  case 1053:
#line 7188 "lef.y"
  {
    if (lefData->versionNum < 5.4) {
      if (lefCallbacks->CorrectionTableCbk)
        CALLBACK(lefCallbacks->CorrectionTableCbk, lefrCorrectionTableCbkType,
               &lefData->lefrCorrectionTable);
    } else
      if (lefCallbacks->CorrectionTableCbk) // write warning only if cbk is set 
        if (lefData->correctionTableWarnings++ < lefSettings->CorrectionTableWarnings)
          lefWarning(2075, "CORRECTIONTABLE statement is obsolete in version 5.4 and later.\nThe LEF parser will ignore this statement.\nTo avoid this warning in the future, remove this statement from the LEF file with version 5.4 or later.");
  }
#line 13733 "lef.tab.c"
    break;

  case 1056:
#line 7206 "lef.y"
    { if (lefCallbacks->CorrectionTableCbk)
         {
            lefData->lefrCorrectionTable.newEdge();
            lefData->lefrCorrectionTable.addEdge((yyvsp[-1].dval));
         }
    }
#line 13744 "lef.tab.c"
    break;

  case 1057:
#line 7213 "lef.y"
    { }
#line 13750 "lef.tab.c"
    break;

  case 1058:
#line 7216 "lef.y"
  { if (lefCallbacks->CorrectionTableCbk)
  lefData->lefrCorrectionTable.addResistance(); }
#line 13757 "lef.tab.c"
    break;

  case 1059:
#line 7219 "lef.y"
  { }
#line 13763 "lef.tab.c"
    break;

  case 1060:
#line 7223 "lef.y"
    { if (lefCallbacks->CorrectionTableCbk)
    lefData->lefrCorrectionTable.addResistanceNumber((yyvsp[0].dval)); }
#line 13770 "lef.tab.c"
    break;

  case 1061:
#line 7226 "lef.y"
    { if (lefCallbacks->CorrectionTableCbk)
    lefData->lefrCorrectionTable.addResistanceNumber((yyvsp[0].dval)); }
#line 13777 "lef.tab.c"
    break;

  case 1064:
#line 7236 "lef.y"
     { if (lefCallbacks->CorrectionTableCbk)
     lefData->lefrCorrectionTable.addVictimLength((yyvsp[-1].dval)); }
#line 13784 "lef.tab.c"
    break;

  case 1065:
#line 7239 "lef.y"
     { }
#line 13790 "lef.tab.c"
    break;

  case 1066:
#line 7243 "lef.y"
    { if (lefCallbacks->CorrectionTableCbk)
        lefData->lefrCorrectionTable.addVictimCorrection((yyvsp[0].dval)); }
#line 13797 "lef.tab.c"
    break;

  case 1067:
#line 7246 "lef.y"
    { if (lefCallbacks->CorrectionTableCbk)
        lefData->lefrCorrectionTable.addVictimCorrection((yyvsp[0].dval)); }
#line 13804 "lef.tab.c"
    break;

  case 1068:
#line 7252 "lef.y"
    { // 5.3 syntax 
        lefData->use5_3 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        } else if (lefData->versionNum > 5.3) {
           // A 5.3 syntax in 5.4 
           if (lefData->use5_4) {
              if (lefCallbacks->InputAntennaCbk) { // write warning only if cbk is set 
                if (lefData->inputAntennaWarnings++ < lefSettings->InputAntennaWarnings) {
                   lefData->outMsg = (char*)lefMalloc(10000);
                   sprintf (lefData->outMsg,
                      "INPUTPINANTENNASIZE statement is a version 5.3 or earlier syntax.\nYour lef file with version %g, has both old and new INPUTPINANTENNASIZE syntax, which is incorrect.", lefData->versionNum);
                   lefError(1671, lefData->outMsg);
                   lefFree(lefData->outMsg);
                   CHKERR();
                }
              }
           }
        }
        if (lefCallbacks->InputAntennaCbk)
          CALLBACK(lefCallbacks->InputAntennaCbk, lefrInputAntennaCbkType, (yyvsp[-1].dval));
    }
#line 13831 "lef.tab.c"
    break;

  case 1069:
#line 7276 "lef.y"
    { // 5.3 syntax 
        lefData->use5_3 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        } else if (lefData->versionNum > 5.3) {
           // A 5.3 syntax in 5.4 
           if (lefData->use5_4) {
              if (lefCallbacks->OutputAntennaCbk) { // write warning only if cbk is set 
                if (lefData->outputAntennaWarnings++ < lefSettings->OutputAntennaWarnings) {
                   lefData->outMsg = (char*)lefMalloc(10000);
                   sprintf (lefData->outMsg,
                      "OUTPUTPINANTENNASIZE statement is a version 5.3 or earlier syntax.\nYour lef file with version %g, has both old and new OUTPUTPINANTENNASIZE syntax, which is incorrect.", lefData->versionNum);
                   lefError(1672, lefData->outMsg);
                   lefFree(lefData->outMsg);
                   CHKERR();
                }
              }
           }
        }
        if (lefCallbacks->OutputAntennaCbk)
          CALLBACK(lefCallbacks->OutputAntennaCbk, lefrOutputAntennaCbkType, (yyvsp[-1].dval));
    }
#line 13858 "lef.tab.c"
    break;

  case 1070:
#line 7300 "lef.y"
    { // 5.3 syntax 
        lefData->use5_3 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        } else if (lefData->versionNum > 5.3) {
           // A 5.3 syntax in 5.4 
           if (lefData->use5_4) {
              if (lefCallbacks->InoutAntennaCbk) { // write warning only if cbk is set 
                if (lefData->inoutAntennaWarnings++ < lefSettings->InoutAntennaWarnings) {
                   lefData->outMsg = (char*)lefMalloc(10000);
                   sprintf (lefData->outMsg,
                      "INOUTPINANTENNASIZE statement is a version 5.3 or earlier syntax.\nYour lef file with version %g, has both old and new INOUTPINANTENNASIZE syntax, which is incorrect.", lefData->versionNum);
                   lefError(1673, lefData->outMsg);
                   lefFree(lefData->outMsg);
                   CHKERR();
                }
              }
           }
        }
        if (lefCallbacks->InoutAntennaCbk)
          CALLBACK(lefCallbacks->InoutAntennaCbk, lefrInoutAntennaCbkType, (yyvsp[-1].dval));
    }
#line 13885 "lef.tab.c"
    break;

  case 1071:
#line 7324 "lef.y"
    { // 5.4 syntax 
        // 11/12/2002 - this is obsolete in 5.5, suppose should be ingored 
        // 12/16/2002 - talked to Dave Noice, leave them in here for debugging
        lefData->use5_4 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        } else if (lefData->versionNum < 5.4) {
           if (lefCallbacks->AntennaInputCbk) { // write warning only if cbk is set 
             if (lefData->antennaInputWarnings++ < lefSettings->AntennaInputWarnings) {
               lefData->outMsg = (char*)lefMalloc(10000);
               sprintf (lefData->outMsg,
                  "ANTENNAINPUTGATEAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.\nEither update your VERSION number or use the 5.3 syntax.", lefData->versionNum);
               lefError(1674, lefData->outMsg);
               lefFree(lefData->outMsg);
               CHKERR();
             }
           }
        } else if (lefData->use5_3) {
           if (lefCallbacks->AntennaInputCbk) { // write warning only if cbk is set 
             if (lefData->antennaInputWarnings++ < lefSettings->AntennaInputWarnings) {
                lefData->outMsg = (char*)lefMalloc(10000);
                sprintf (lefData->outMsg,
                   "ANTENNAINPUTGATEAREA statement is a version 5.4 or later syntax.\nYour lef file with version %g, has both old and new ANTENNAINPUTGATEAREA syntax, which is incorrect.", lefData->versionNum);
                lefError(1675, lefData->outMsg);
                lefFree(lefData->outMsg);
               CHKERR();
             }
           }
        }
        if (lefCallbacks->AntennaInputCbk)
          CALLBACK(lefCallbacks->AntennaInputCbk, lefrAntennaInputCbkType, (yyvsp[-1].dval));
    }
#line 13922 "lef.tab.c"
    break;

  case 1072:
#line 7358 "lef.y"
    { // 5.4 syntax 
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        // 12/16/2002 - talked to Dave Noice, leave them in here for debugging
        lefData->use5_4 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        } else if (lefData->versionNum < 5.4) {
           if (lefCallbacks->AntennaInoutCbk) { // write warning only if cbk is set 
              if (lefData->antennaInoutWarnings++ < lefSettings->AntennaInoutWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "ANTENNAINOUTDIFFAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.\nEither update your VERSION number or use the 5.3 syntax.", lefData->versionNum);
                 lefError(1676, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        } else if (lefData->use5_3) {
           if (lefCallbacks->AntennaInoutCbk) { // write warning only if cbk is set 
              if (lefData->antennaInoutWarnings++ < lefSettings->AntennaInoutWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "ANTENNAINOUTDIFFAREA statement is a version 5.4 or later syntax.\nYour lef file with version %g, has both old and new ANTENNAINOUTDIFFAREA syntax, which is incorrect.", lefData->versionNum);
                 lefError(1677, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
        if (lefCallbacks->AntennaInoutCbk)
          CALLBACK(lefCallbacks->AntennaInoutCbk, lefrAntennaInoutCbkType, (yyvsp[-1].dval));
    }
#line 13959 "lef.tab.c"
    break;

  case 1073:
#line 7392 "lef.y"
    { // 5.4 syntax 
        // 11/12/2002 - this is obsolete in 5.5, & will be ignored 
        // 12/16/2002 - talked to Dave Noice, leave them in here for debugging
        lefData->use5_4 = 1;
        if (lefData->ignoreVersion) {
           // do nothing 
        } else if (lefData->versionNum < 5.4) {
           if (lefCallbacks->AntennaOutputCbk) { // write warning only if cbk is set 
              if (lefData->antennaOutputWarnings++ < lefSettings->AntennaOutputWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "ANTENNAOUTPUTDIFFAREA statement is a version 5.4 and later syntax.\nYour lef file is defined with version %g.\nEither update your VERSION number or use the 5.3 syntax.", lefData->versionNum);
                 lefError(1678, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        } else if (lefData->use5_3) {
           if (lefCallbacks->AntennaOutputCbk) { // write warning only if cbk is set 
              if (lefData->antennaOutputWarnings++ < lefSettings->AntennaOutputWarnings) {
                 lefData->outMsg = (char*)lefMalloc(10000);
                 sprintf (lefData->outMsg,
                    "ANTENNAOUTPUTDIFFAREA statement is a version 5.4 or later syntax.\nYour lef file with version %g, has both old and new ANTENNAOUTPUTDIFFAREA syntax, which is incorrect.", lefData->versionNum);
                 lefError(1679, lefData->outMsg);
                 lefFree(lefData->outMsg);
                 CHKERR();
              }
           }
        }
        if (lefCallbacks->AntennaOutputCbk)
          CALLBACK(lefCallbacks->AntennaOutputCbk, lefrAntennaOutputCbkType, (yyvsp[-1].dval));
    }
#line 13996 "lef.tab.c"
    break;

  case 1076:
#line 7429 "lef.y"
    { 
        if (lefCallbacks->ExtensionCbk)
          CALLBACK(lefCallbacks->ExtensionCbk, lefrExtensionCbkType, &lefData->Hist_text[0]);
        if (lefData->versionNum >= 5.6)
           lefData->ge56almostDone = 1;
    }
#line 14007 "lef.tab.c"
    break;


#line 14011 "lef.tab.c"

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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 7436 "lef.y"


END_LEFDEF_PARSER_NAMESPACE
