/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user prologue.  */
#line 1 "openinghoursparser.y"

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openinghours_p.h"
#include "openinghoursparser_p.h" // generated
#include "openinghoursscanner_p.h" // generated
#include "logging.h"

using namespace QOpeningHours;

void yyerror(YYLTYPE *loc, OpeningHoursPrivate *parser, yyscan_t scanner, char const* msg)
{
    Q_UNUSED(scanner);
    qCDebug(Log) << "PARSER ERROR:" << msg << "at position" << loc->first_column;
    parser->m_error = OpeningHours::SyntaxError;
}

static void initSelectors(Selectors &sels)
{
    sels.timeSelector = nullptr;
    sels.weekdaySelector = nullptr;
    sels.weekSelector = nullptr;
    sels.monthdaySelector = nullptr;
    sels.yearSelector = nullptr;
    sels.wideRangeSelectorComment.str = nullptr;
    sels.wideRangeSelectorComment.len = 0;
    sels.seen_24_7 = false;
    sels.colonAfterWideRangeSelector = false;
}

static void applySelectors(const Selectors &sels, Rule *rule)
{
    rule->m_timeSelector.reset(sels.timeSelector);
    rule->m_weekdaySelector.reset(sels.weekdaySelector);
    rule->m_weekSelector.reset(sels.weekSelector);
    rule->m_monthdaySelector.reset(sels.monthdaySelector);
    rule->m_yearSelector.reset(sels.yearSelector);
    rule->m_seen_24_7 = sels.seen_24_7;
    rule->m_colonAfterWideRangeSelector = sels.colonAfterWideRangeSelector;
    rule->m_wideRangeSelectorComment = QString::fromUtf8(sels.wideRangeSelectorComment.str, sels.wideRangeSelectorComment.len);
}

static bool extendMonthdaySelector(MonthdayRange *monthdaySelector, int beginDay, int endDay)
{
    const auto prevSelector = lastSelector(monthdaySelector);
    if (prevSelector->begin.year == prevSelector->end.year
     && prevSelector->begin.month == prevSelector->end.month)
    {
        auto sel = new MonthdayRange;
        sel->begin = sel->end = prevSelector->end;
        sel->begin.day = beginDay;
        sel->end.day = endDay;
        appendSelector(prevSelector, sel);
        return true;
    }
    return false;
}


#line 121 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"

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

#include "openinghoursparser_p.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_NORMAL_RULE_SEPARATOR = 3,    /* T_NORMAL_RULE_SEPARATOR  */
  YYSYMBOL_T_ADDITIONAL_RULE_SEPARATOR = 4, /* T_ADDITIONAL_RULE_SEPARATOR  */
  YYSYMBOL_T_FALLBACK_SEPARATOR = 5,       /* T_FALLBACK_SEPARATOR  */
  YYSYMBOL_T_STATE = 6,                    /* T_STATE  */
  YYSYMBOL_T_24_7 = 7,                     /* T_24_7  */
  YYSYMBOL_T_YEAR = 8,                     /* T_YEAR  */
  YYSYMBOL_T_PLUS = 9,                     /* T_PLUS  */
  YYSYMBOL_T_MINUS = 10,                   /* T_MINUS  */
  YYSYMBOL_T_SLASH = 11,                   /* T_SLASH  */
  YYSYMBOL_T_COLON = 12,                   /* T_COLON  */
  YYSYMBOL_T_COMMA = 13,                   /* T_COMMA  */
  YYSYMBOL_T_ALT_TIME_SEP = 14,            /* T_ALT_TIME_SEP  */
  YYSYMBOL_T_ALT_TIME_SEP_OR_SUFFIX = 15,  /* T_ALT_TIME_SEP_OR_SUFFIX  */
  YYSYMBOL_T_ALT_TIME_AM = 16,             /* T_ALT_TIME_AM  */
  YYSYMBOL_T_ALT_TIME_PM = 17,             /* T_ALT_TIME_PM  */
  YYSYMBOL_T_4DIGIT_TIME = 18,             /* T_4DIGIT_TIME  */
  YYSYMBOL_T_ALT_RANGE_SEP = 19,           /* T_ALT_RANGE_SEP  */
  YYSYMBOL_T_EVENT = 20,                   /* T_EVENT  */
  YYSYMBOL_T_LBRACKET = 21,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 22,                /* T_RBRACKET  */
  YYSYMBOL_T_LPAREN = 23,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 24,                  /* T_RPAREN  */
  YYSYMBOL_T_PH = 25,                      /* T_PH  */
  YYSYMBOL_T_SH = 26,                      /* T_SH  */
  YYSYMBOL_T_KEYWORD_DAY = 27,             /* T_KEYWORD_DAY  */
  YYSYMBOL_T_KEYWORD_WEEK = 28,            /* T_KEYWORD_WEEK  */
  YYSYMBOL_T_EASTER = 29,                  /* T_EASTER  */
  YYSYMBOL_T_WHITSUN = 30,                 /* T_WHITSUN  */
  YYSYMBOL_T_WEEKDAY = 31,                 /* T_WEEKDAY  */
  YYSYMBOL_T_MONTH = 32,                   /* T_MONTH  */
  YYSYMBOL_T_INTEGER = 33,                 /* T_INTEGER  */
  YYSYMBOL_T_COMMENT = 34,                 /* T_COMMENT  */
  YYSYMBOL_T_INVALID = 35,                 /* T_INVALID  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_Ruleset = 37,                   /* Ruleset  */
  YYSYMBOL_Rule = 38,                      /* Rule  */
  YYSYMBOL_SelectorSequence = 39,          /* SelectorSequence  */
  YYSYMBOL_WideRangeSelector = 40,         /* WideRangeSelector  */
  YYSYMBOL_SmallRangeSelector = 41,        /* SmallRangeSelector  */
  YYSYMBOL_TimeSelector = 42,              /* TimeSelector  */
  YYSYMBOL_Timespan = 43,                  /* Timespan  */
  YYSYMBOL_Time = 44,                      /* Time  */
  YYSYMBOL_VariableTime = 45,              /* VariableTime  */
  YYSYMBOL_WeekdaySelector = 46,           /* WeekdaySelector  */
  YYSYMBOL_HolidayAndWeekdaySequence = 47, /* HolidayAndWeekdaySequence  */
  YYSYMBOL_HolidayAndWeekday = 48,         /* HolidayAndWeekday  */
  YYSYMBOL_HolidayOrWeekdaySequence = 49,  /* HolidayOrWeekdaySequence  */
  YYSYMBOL_WeekdaySequence = 50,           /* WeekdaySequence  */
  YYSYMBOL_WeekdayRange = 51,              /* WeekdayRange  */
  YYSYMBOL_HolidaySequence = 52,           /* HolidaySequence  */
  YYSYMBOL_Holiday = 53,                   /* Holiday  */
  YYSYMBOL_NthSequence = 54,               /* NthSequence  */
  YYSYMBOL_NthEntry = 55,                  /* NthEntry  */
  YYSYMBOL_DayOffset = 56,                 /* DayOffset  */
  YYSYMBOL_WeekSelector = 57,              /* WeekSelector  */
  YYSYMBOL_Week = 58,                      /* Week  */
  YYSYMBOL_MonthdaySelector = 59,          /* MonthdaySelector  */
  YYSYMBOL_MonthdayRange = 60,             /* MonthdayRange  */
  YYSYMBOL_MonthdayRangeAdditional = 61,   /* MonthdayRangeAdditional  */
  YYSYMBOL_DateOffset = 62,                /* DateOffset  */
  YYSYMBOL_DateFrom = 63,                  /* DateFrom  */
  YYSYMBOL_DateTo = 64,                    /* DateTo  */
  YYSYMBOL_VariableDate = 65,              /* VariableDate  */
  YYSYMBOL_AltMonthdayOffset = 66,         /* AltMonthdayOffset  */
  YYSYMBOL_YearSelector = 67,              /* YearSelector  */
  YYSYMBOL_YearSelectorCombined = 68,      /* YearSelectorCombined  */
  YYSYMBOL_YearRange = 69,                 /* YearRange  */
  YYSYMBOL_YearRangeStandalone = 70,       /* YearRangeStandalone  */
  YYSYMBOL_ExtendedHourMinute = 71,        /* ExtendedHourMinute  */
  YYSYMBOL_RangeSeparator = 72             /* RangeSeparator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   317

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 6
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   233,   233,   234,   235,   239,   243,   252,   264,   268,
     273,   278,   284,   288,   292,   300,   301,   302,   303,   307,
     312,   321,   322,   323,   324,   328,   332,   336,   341,   349,
     350,   351,   352,   356,   364,   368,   372,   377,   385,   390,
     396,   401,   407,   413,   422,   423,   427,   428,   433,   442,
     446,   453,   454,   461,   466,   474,   475,   476,   480,   487,
     488,   495,   500,   505,   510,   519,   520,   524,   528,   533,
     540,   544,   550,   554,   558,   565,   566,   571,   575,   582,
     586,   591,   603,   607,   611,   620,   628,   636,   647,   651,
     654,   658,   662,   667,   672,   677,   682,   686,   692,   699,
     707,   715,   720,   725,   737,   738,   739,   743,   744,   745,
     746,   753,   754,   758,   759,   763,   764,   765,   766,   772,
     776,   782,   786,   793,   797,   801,   810,   815,   825,   832,
     836,   840,   844,   848,   852,   857,   862,   867,   872,   877,
     882,   888,   889
};
#endif

#define YYPACT_NINF (-143)
#define YYTABLE_NINF (-125)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -11,  -143,   110,  -143,  -143,  -143,  -143,    20,   238,
    -143,    28,  -143,  -143,   202,   115,   167,    65,   205,  -143,
       9,   139,  -143,   111,  -143,   215,  -143,   151,    71,  -143,
     128,    60,   177,     7,    41,   145,    40,  -143,  -143,   219,
    -143,   103,   148,  -143,   194,  -143,  -143,  -143,  -143,    83,
    -143,   117,  -143,   122,   240,   180,   193,  -143,   222,  -143,
       8,   191,   239,  -143,    77,   227,    62,   121,   228,  -143,
    -143,  -143,    74,    74,    74,   261,   231,  -143,   160,  -143,
     178,    13,  -143,   178,   178,   162,   189,   189,   232,   251,
    -143,   226,   253,  -143,    28,   234,    18,   145,    95,   166,
    -143,    77,    26,    -8,   145,    70,   260,  -143,  -143,    17,
     258,   127,   127,   243,   245,   241,   242,   263,     6,  -143,
    -143,    27,    80,  -143,  -143,  -143,   256,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,   275,  -143,  -143,
     230,   229,  -143,  -143,  -143,  -143,  -143,  -143,   267,    -8,
     268,  -143,  -143,  -143,    85,   201,   212,  -143,  -143,   244,
     145,   208,   266,  -143,   249,  -143,   247,   259,   262,  -143,
    -143,   271,  -143,   252,     8,   238,   254,   269,   212,  -143,
    -143,  -143,  -143,   171,   255,   257,   264,   244,   265,  -143,
     213,  -143,  -143,  -143,  -143,  -143,   270,  -143,  -143,  -143,
     272,   246,  -143,   167,  -143,  -143,  -143,  -143,  -143,   248,
    -143,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    15,    88,   138,   139,   140,    46,     0,    67,
      69,     0,   113,   114,    61,    90,     0,    12,     0,     2,
       8,    17,    16,    29,    34,    38,    45,    30,    50,    51,
      49,     0,    55,     0,    56,    23,    22,    82,    89,    96,
     109,    21,     0,   121,   119,    44,    14,   128,   141,     0,
     142,    91,   110,     0,     0,     0,     0,    68,    79,    77,
       0,     0,     0,   107,     0,     0,     0,     0,   133,    28,
       1,     7,     0,     0,     0,     0,    10,     9,    18,    19,
       0,     0,    39,     0,    31,    32,     0,     0,     0,    54,
      65,     0,    53,    59,     0,     0,     0,    26,     0,   141,
     106,    97,     0,    88,    25,    24,     0,   126,   108,     0,
     125,     0,     0,     0,     0,     0,     0,    72,     0,    70,
      62,     0,     0,    92,   134,   136,   129,   135,   137,   130,
     132,     3,     4,     5,     6,    11,    20,     0,    36,    35,
      40,    33,    52,    57,    58,    60,    66,    78,    85,     0,
      84,    83,   104,   105,     0,     0,     0,   112,   111,    98,
      27,   123,   120,   124,     0,    93,     0,     0,     0,    75,
      76,    80,    74,     0,     0,    63,     0,     0,     0,   102,
     131,    37,    41,     0,     0,     0,     0,    99,     0,   101,
       0,   100,    94,   127,    47,    48,     0,    73,    71,    64,
       0,   115,    95,    42,    43,    87,    86,   103,    81,   116,
     117,   118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   163,  -143,  -143,   -13,   -18,   203,    69,  -143,
    -143,  -143,   206,  -143,   273,   -17,   274,   -24,  -143,   119,
      -9,   -30,   195,   276,  -143,   199,  -142,   -90,  -112,    -2,
    -121,  -143,  -143,   190,   196,  -107,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   118,   119,
     100,    35,    59,    36,    37,    38,   101,    39,   159,    40,
      64,    41,    42,    43,    44,    45,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    52,    61,    65,   167,   168,    97,    90,    79,    85,
     179,   104,   158,    83,   138,    76,    93,   191,   116,   174,
      91,    12,    13,    46,    51,   164,   149,   102,   175,     4,
       5,     6,   158,     7,   155,   189,     8,   176,    14,   109,
      54,   117,   187,    77,    95,   207,    16,    12,    13,   165,
      15,   150,   122,    96,   -56,    12,    13,   202,   156,   157,
     177,    58,    90,   144,   158,   136,   141,   146,    11,    93,
     143,   145,   -65,    88,    95,   160,   204,    69,   124,   125,
       1,     2,     3,    96,    86,     9,    10,    48,   155,   154,
       4,     5,     6,   155,     7,   126,    50,     8,    11,     9,
      10,    52,    11,    12,    13,    14,    15,    16,    17,    12,
      13,   103,   178,   157,    12,    13,   107,   186,   157,    47,
      48,    49,    80,   -88,    81,    48,   152,    48,   113,    50,
     110,    11,    12,    13,    50,    15,    50,   127,   128,    12,
      13,    87,    51,     4,     5,     6,    62,    52,    63,   137,
     108,    78,   140,    52,   129,     4,     5,     6,    94,     7,
      16,   106,     8,    84,     9,    10,   199,     4,     5,     6,
      14,     7,    16,    80,     8,    81,     4,     5,     6,    66,
       7,    67,    68,     8,    16,     9,    10,     4,     5,     6,
     -55,    14,   210,    16,     4,     5,     6,   153,     7,   114,
     211,     8,   -59,   -59,   203,    70,    71,  -124,    72,    73,
      74,    16,    48,   113,     9,    10,    75,    47,    48,    49,
      14,    50,   120,    60,    82,    48,   114,    50,    98,    99,
      12,    13,   115,   188,    50,   131,   132,   133,    50,   182,
      80,   183,    81,    62,   153,    63,   114,    55,    56,   111,
     112,     9,    10,    98,   190,    55,    56,    55,    56,   123,
     121,   130,   134,    14,    91,   135,    88,   148,   161,   166,
     169,   180,   170,   173,   171,   172,   181,   184,   185,  -122,
     193,   192,   196,   194,   139,   197,   195,   200,   205,   147,
     206,   201,   142,   198,   209,   151,   162,    63,   108,     0,
       0,     0,   163,   208,     0,    89,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105
};

static const yytype_int16 yycheck[] =
{
       9,     3,    14,    15,   111,   112,    36,    31,    21,    27,
     122,    41,   102,    25,     1,     6,    33,   159,    10,    13,
      13,    29,    30,    34,    32,     8,     8,    39,    22,    16,
      17,    18,   122,    20,     8,   156,    23,    10,    31,    51,
      20,    33,   154,    34,     4,   187,    33,    29,    30,    32,
      32,    33,    64,    13,    13,    29,    30,   178,    32,    33,
      33,    33,    86,    87,   154,    78,    84,    91,    28,    86,
      87,    88,    31,    13,     4,   105,   183,    12,    16,    17,
       6,     7,     8,    13,    13,    25,    26,    10,     8,   101,
      16,    17,    18,     8,    20,    33,    19,    23,    28,    25,
      26,   103,    28,    29,    30,    31,    32,    33,    34,    29,
      30,     8,    32,    33,    29,    30,    33,    32,    33,     9,
      10,    11,    11,    13,    13,    10,    31,    10,    33,    19,
       8,    28,    29,    30,    19,    32,    19,    16,    17,    29,
      30,    13,    32,    16,    17,    18,    31,   149,    33,    80,
      33,    12,    83,   155,    33,    16,    17,    18,    13,    20,
      33,    13,    23,    12,    25,    26,   175,    16,    17,    18,
      31,    20,    33,    11,    23,    13,    16,    17,    18,    12,
      20,    14,    15,    23,    33,    25,    26,    16,    17,    18,
      13,    31,   201,    33,    16,    17,    18,    31,    20,    33,
     209,    23,    25,    26,    33,     0,     1,    13,     3,     4,
       5,    33,    10,    33,    25,    26,    11,     9,    10,    11,
      31,    19,    31,    21,     9,    10,    33,    19,     9,    10,
      29,    30,    10,    32,    19,    72,    73,    74,    19,     9,
      11,    11,    13,    31,    31,    33,    33,     9,    10,     9,
      10,    25,    26,     9,    10,     9,    10,     9,    10,    32,
      21,    33,     1,    31,    13,    34,    13,    33,     8,    11,
      27,    15,    27,    10,    33,    33,     1,    10,    10,    13,
      33,    32,    11,    24,    81,    33,    24,    33,    33,    94,
      33,    22,    86,   174,    22,    96,   106,    33,    33,    -1,
      -1,    -1,   106,    33,    -1,    31,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    16,    17,    18,    20,    23,    25,
      26,    28,    29,    30,    31,    32,    33,    34,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    57,    59,    60,    61,    63,
      65,    67,    68,    69,    70,    71,    34,     9,    10,    11,
      19,    32,    65,    72,    20,     9,    10,    56,    33,    58,
      21,    72,    31,    33,    66,    72,    12,    14,    15,    12,
       0,     1,     3,     4,     5,    11,     6,    34,    12,    41,
      11,    13,     9,    72,    12,    42,    13,    13,    13,    52,
      53,    13,    50,    51,    13,     4,    13,    57,     9,    10,
      56,    62,    72,     8,    57,    59,    13,    33,    33,    72,
       8,     9,    10,    33,    33,    10,    10,    33,    54,    55,
      31,    21,    72,    32,    16,    17,    33,    16,    17,    33,
      33,    38,    38,    38,     1,    34,    41,    44,     1,    43,
      44,    42,    48,    51,    53,    51,    53,    58,    33,     8,
      33,    61,    31,    31,    72,     8,    32,    33,    63,    64,
      57,     8,    69,    70,     8,    32,    11,    71,    71,    27,
      27,    33,    33,    10,    13,    22,    10,    33,    32,    64,
      15,     1,     9,    11,    10,    10,    32,    64,    32,    66,
      10,    62,    32,    33,    24,    24,    11,    33,    55,    56,
      33,    22,    66,    33,    71,    33,    33,    62,    33,    22,
      56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    38,    38,
      38,    38,    38,    38,    38,    39,    39,    39,    39,    39,
      39,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      41,    41,    41,    41,    42,    42,    42,    42,    43,    43,
      43,    43,    43,    43,    44,    44,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     2,     1,     2,
       2,     3,     1,     1,     2,     1,     1,     1,     2,     2,
       3,     1,     1,     1,     2,     2,     2,     3,     2,     1,
       1,     2,     2,     3,     1,     3,     3,     4,     1,     2,
       3,     4,     5,     5,     1,     1,     1,     5,     5,     1,
       1,     1,     3,     2,     2,     1,     1,     3,     3,     1,
       3,     1,     3,     4,     5,     1,     3,     1,     2,     1,
       1,     3,     1,     3,     2,     3,     3,     2,     3,     1,
       3,     5,     1,     3,     3,     3,     5,     5,     1,     1,
       1,     2,     3,     4,     5,     5,     1,     2,     3,     4,
       4,     4,     4,     5,     2,     2,     1,     2,     3,     1,
       2,     1,     1,     1,     1,     4,     5,     5,     6,     1,
       3,     1,     3,     1,     1,     3,     3,     5,     2,     3,
       3,     4,     3,     2,     3,     3,     3,     3,     1,     1,
       1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     9,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     7,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,    41,     0,
       0,     0,     0,     0,    21,     0,    23,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    88,     0,   123,     0,    90,     0,    90,     0,    29,
       0,    59,     0,    65,     0,    22,     0,    91,     0,    32,
       0,    54,     0,    53,     0,   141,     0,    24,     0,   125,
       0,    40,     0,    33,     0,   123,     0,    80,     0,   115,
       0,   116,     0
};


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, parser, scanner, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"",
  "T_NORMAL_RULE_SEPARATOR", "T_ADDITIONAL_RULE_SEPARATOR",
  "T_FALLBACK_SEPARATOR", "T_STATE", "T_24_7", "T_YEAR", "T_PLUS",
  "T_MINUS", "T_SLASH", "T_COLON", "T_COMMA", "T_ALT_TIME_SEP",
  "T_ALT_TIME_SEP_OR_SUFFIX", "T_ALT_TIME_AM", "T_ALT_TIME_PM",
  "T_4DIGIT_TIME", "T_ALT_RANGE_SEP", "T_EVENT", "T_LBRACKET",
  "T_RBRACKET", "T_LPAREN", "T_RPAREN", "T_PH", "T_SH", "T_KEYWORD_DAY",
  "T_KEYWORD_WEEK", "T_EASTER", "T_WHITSUN", "T_WEEKDAY", "T_MONTH",
  "T_INTEGER", "T_COMMENT", "T_INVALID", "$accept", "Ruleset", "Rule",
  "SelectorSequence", "WideRangeSelector", "SmallRangeSelector",
  "TimeSelector", "Timespan", "Time", "VariableTime", "WeekdaySelector",
  "HolidayAndWeekdaySequence", "HolidayAndWeekday",
  "HolidayOrWeekdaySequence", "WeekdaySequence", "WeekdayRange",
  "HolidaySequence", "Holiday", "NthSequence", "NthEntry", "DayOffset",
  "WeekSelector", "Week", "MonthdaySelector", "MonthdayRange",
  "MonthdayRangeAdditional", "DateOffset", "DateFrom", "DateTo",
  "VariableDate", "AltMonthdayOffset", "YearSelector",
  "YearSelectorCombined", "YearRange", "YearRangeStandalone",
  "ExtendedHourMinute", "RangeSeparator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (parser);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, parser, scanner);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, Location, parser, scanner);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
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


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  yysymbol_kind_t yytoken;
  YY_USE (parser);
  YY_USE (scanner);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex (&yylval, &yylloc, scanner);
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (parser);
  YY_USE (scanner);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, parser, scanner, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule, parser, scanner));
  switch (yyrule)
    {
  case 2: /* Ruleset: Rule  */
#line 233 "openinghoursparser.y"
          { parser->addRule((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.rule)); }
#line 1524 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 3: /* Ruleset: Ruleset T_NORMAL_RULE_SEPARATOR Rule  */
#line 234 "openinghoursparser.y"
                                          { parser->addRule((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.rule)); }
#line 1530 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 4: /* Ruleset: Ruleset T_ADDITIONAL_RULE_SEPARATOR Rule  */
#line 235 "openinghoursparser.y"
                                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.rule)->m_ruleType = Rule::AdditionalRule;
    parser->addRule((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.rule));
  }
#line 1539 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 5: /* Ruleset: Ruleset T_FALLBACK_SEPARATOR Rule  */
#line 239 "openinghoursparser.y"
                                       {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.rule)->m_ruleType = Rule::FallbackRule;
    parser->addRule((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.rule));
  }
#line 1548 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 6: /* Ruleset: Ruleset T_SLASH error  */
#line 243 "openinghoursparser.y"
                        {
    if (!parser->isRecovering()) {
        parser->restartFrom((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc).first_column, Rule::NormalRule);
        parser->m_ruleSeparatorRecovery = true;
        yyerrok;
    } else {
        YYERROR;
    }
  }
#line 1562 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 7: /* Ruleset: Ruleset error  */
#line 252 "openinghoursparser.y"
                {
    if (!parser->isRecovering()) {
        parser->restartFrom((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc).first_column, Rule::GuessRuleType);
        parser->m_ruleSeparatorRecovery = true;
        yyerrok;
    } else {
        YYERROR;
    }
  }
#line 1576 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 8: /* Rule: SelectorSequence  */
#line 264 "openinghoursparser.y"
                      {
    ((*yyvalp).rule) = new Rule;
    applySelectors((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors), ((*yyvalp).rule));
  }
#line 1585 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 9: /* Rule: SelectorSequence T_COMMENT  */
#line 268 "openinghoursparser.y"
                                   {
    ((*yyvalp).rule) = new Rule;
    ((*yyvalp).rule)->setComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).str, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).len);
    applySelectors((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors), ((*yyvalp).rule));
  }
#line 1595 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 10: /* Rule: SelectorSequence T_STATE  */
#line 273 "openinghoursparser.y"
                                 {
    ((*yyvalp).rule) = new Rule;
    ((*yyvalp).rule)->setState((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.state));
    applySelectors((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors), ((*yyvalp).rule));
  }
#line 1605 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 11: /* Rule: SelectorSequence T_STATE T_COMMENT  */
#line 278 "openinghoursparser.y"
                                              {
    ((*yyvalp).rule) = new Rule;
    ((*yyvalp).rule)->setComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).str, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).len);
    ((*yyvalp).rule)->setState((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.state));
    applySelectors((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors), ((*yyvalp).rule));
  }
#line 1616 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 12: /* Rule: T_COMMENT  */
#line 284 "openinghoursparser.y"
               {
    ((*yyvalp).rule) = new Rule;
    ((*yyvalp).rule)->setComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).str, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).len);
  }
#line 1625 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 13: /* Rule: T_STATE  */
#line 288 "openinghoursparser.y"
             {
    ((*yyvalp).rule) = new Rule;
    ((*yyvalp).rule)->setState((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.state));
  }
#line 1634 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 14: /* Rule: T_STATE T_COMMENT  */
#line 292 "openinghoursparser.y"
                          {
    ((*yyvalp).rule) = new Rule;
    ((*yyvalp).rule)->setComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).str, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.strRef).len);
    ((*yyvalp).rule)->setState((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.state));
  }
#line 1644 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 15: /* SelectorSequence: T_24_7  */
#line 300 "openinghoursparser.y"
         { initSelectors(((*yyvalp).selectors)); ((*yyvalp).selectors).seen_24_7 = true; }
#line 1650 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 16: /* SelectorSequence: SmallRangeSelector  */
#line 301 "openinghoursparser.y"
                        { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1656 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 17: /* SelectorSequence: WideRangeSelector  */
#line 302 "openinghoursparser.y"
                       { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1662 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 18: /* SelectorSequence: WideRangeSelector T_COLON  */
#line 303 "openinghoursparser.y"
                               {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors);
    ((*yyvalp).selectors).colonAfterWideRangeSelector = true;
  }
#line 1671 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 19: /* SelectorSequence: WideRangeSelector SmallRangeSelector  */
#line 307 "openinghoursparser.y"
                                             {
    ((*yyvalp).selectors).timeSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).timeSelector;
    ((*yyvalp).selectors).weekdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).weekdaySelector;
    ((*yyvalp).selectors).weekSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors).weekSelector;
  }
#line 1681 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 20: /* SelectorSequence: WideRangeSelector T_COLON SmallRangeSelector  */
#line 312 "openinghoursparser.y"
                                                     {
    ((*yyvalp).selectors).timeSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).timeSelector;
    ((*yyvalp).selectors).weekdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).weekdaySelector;
    ((*yyvalp).selectors).weekSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors).weekSelector;
    ((*yyvalp).selectors).colonAfterWideRangeSelector = true;
  }
#line 1692 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 21: /* WideRangeSelector: YearSelector  */
#line 321 "openinghoursparser.y"
                  { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1698 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 22: /* WideRangeSelector: MonthdaySelector  */
#line 322 "openinghoursparser.y"
                      { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1704 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 23: /* WideRangeSelector: WeekSelector  */
#line 323 "openinghoursparser.y"
                  { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1710 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 24: /* WideRangeSelector: YearSelector MonthdaySelector  */
#line 324 "openinghoursparser.y"
                                      {
    ((*yyvalp).selectors).yearSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors).yearSelector;
    ((*yyvalp).selectors).monthdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).monthdaySelector;
}
#line 1719 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 25: /* WideRangeSelector: YearSelector WeekSelector  */
#line 328 "openinghoursparser.y"
                                  {
    ((*yyvalp).selectors).yearSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors).yearSelector;
    ((*yyvalp).selectors).weekSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).weekSelector;
  }
#line 1728 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 26: /* WideRangeSelector: MonthdaySelector WeekSelector  */
#line 332 "openinghoursparser.y"
                                      {
    ((*yyvalp).selectors).monthdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors).monthdaySelector;
    ((*yyvalp).selectors).weekSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).weekSelector;
  }
#line 1737 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 27: /* WideRangeSelector: YearSelector MonthdaySelector WeekSelector  */
#line 336 "openinghoursparser.y"
                                                      {
    ((*yyvalp).selectors).yearSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors).yearSelector;
    ((*yyvalp).selectors).monthdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors).monthdaySelector;
    ((*yyvalp).selectors).weekSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).weekSelector;
  }
#line 1747 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 28: /* WideRangeSelector: T_COMMENT T_COLON  */
#line 341 "openinghoursparser.y"
                       {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).wideRangeSelectorComment = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.strRef);
    ((*yyvalp).selectors).colonAfterWideRangeSelector = true;
  }
#line 1757 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 29: /* SmallRangeSelector: TimeSelector  */
#line 349 "openinghoursparser.y"
                  { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1763 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 30: /* SmallRangeSelector: WeekdaySelector  */
#line 350 "openinghoursparser.y"
                     { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors); }
#line 1769 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 31: /* SmallRangeSelector: WeekdaySelector T_COLON  */
#line 351 "openinghoursparser.y"
                             { ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors); }
#line 1775 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 32: /* SmallRangeSelector: WeekdaySelector TimeSelector  */
#line 352 "openinghoursparser.y"
                                     {
    ((*yyvalp).selectors).timeSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).timeSelector;
    ((*yyvalp).selectors).weekdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.selectors).weekdaySelector;
  }
#line 1784 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 33: /* SmallRangeSelector: WeekdaySelector T_COLON TimeSelector  */
#line 356 "openinghoursparser.y"
                                             {
    ((*yyvalp).selectors).timeSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.selectors).timeSelector;
    ((*yyvalp).selectors).weekdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors).weekdaySelector;
  }
#line 1793 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 34: /* TimeSelector: Timespan  */
#line 364 "openinghoursparser.y"
              {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).timeSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.timespan);
  }
#line 1802 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 35: /* TimeSelector: TimeSelector T_COMMA Timespan  */
#line 368 "openinghoursparser.y"
                                        {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    appendSelector(((*yyvalp).selectors).timeSelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.timespan));
  }
#line 1811 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 36: /* TimeSelector: TimeSelector T_COMMA error  */
#line 372 "openinghoursparser.y"
                                {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    parser->restartFrom((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc).first_column, Rule::AdditionalRule);
    yyerrok;
  }
#line 1821 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 37: /* TimeSelector: TimeSelector T_SLASH Time error  */
#line 377 "openinghoursparser.y"
                                        { /* wrong use of slash as a timespan separator */
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.selectors);
    parser->restartFrom((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc).first_column, Rule::AdditionalRule);
    yyerrok;
  }
#line 1831 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 38: /* Timespan: Time  */
#line 385 "openinghoursparser.y"
          {
    ((*yyvalp).timespan) = new Timespan;
    ((*yyvalp).timespan)->begin = ((*yyvalp).timespan)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->pointInTime = true;
  }
#line 1841 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 39: /* Timespan: Time T_PLUS  */
#line 390 "openinghoursparser.y"
                 {
    ((*yyvalp).timespan) = new Timespan;
    ((*yyvalp).timespan)->begin = ((*yyvalp).timespan)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->pointInTime = true;
    ((*yyvalp).timespan)->openEnd = true;
  }
#line 1852 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 40: /* Timespan: Time RangeSeparator Time  */
#line 396 "openinghoursparser.y"
                                   {
    ((*yyvalp).timespan) = new Timespan;
    ((*yyvalp).timespan)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time);
  }
#line 1862 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 41: /* Timespan: Time RangeSeparator Time T_PLUS  */
#line 401 "openinghoursparser.y"
                                          {
    ((*yyvalp).timespan) = new Timespan;
    ((*yyvalp).timespan)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->openEnd = true;
  }
#line 1873 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 42: /* Timespan: Time RangeSeparator Time T_SLASH T_INTEGER  */
#line 407 "openinghoursparser.y"
                                                        {
    ((*yyvalp).timespan) = new Timespan;
    ((*yyvalp).timespan)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->interval = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 1884 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 43: /* Timespan: Time RangeSeparator Time T_SLASH ExtendedHourMinute  */
#line 413 "openinghoursparser.y"
                                                                 {
    ((*yyvalp).timespan) = new Timespan;
    ((*yyvalp).timespan)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.time);
    ((*yyvalp).timespan)->interval = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time).hour * 60 + (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time).minute;
  }
#line 1895 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 44: /* Time: ExtendedHourMinute  */
#line 422 "openinghoursparser.y"
                        { ((*yyvalp).time) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time); }
#line 1901 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 45: /* Time: VariableTime  */
#line 423 "openinghoursparser.y"
                  { ((*yyvalp).time) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time); }
#line 1907 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 46: /* VariableTime: T_EVENT  */
#line 427 "openinghoursparser.y"
             { ((*yyvalp).time) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.time); }
#line 1913 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 47: /* VariableTime: T_LPAREN T_EVENT T_PLUS ExtendedHourMinute T_RPAREN  */
#line 428 "openinghoursparser.y"
                                                            {
    ((*yyvalp).time) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.time);
    ((*yyvalp).time).hour = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.time).hour;
    ((*yyvalp).time).minute = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.time).minute;
  }
#line 1923 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 48: /* VariableTime: T_LPAREN T_EVENT T_MINUS ExtendedHourMinute T_RPAREN  */
#line 433 "openinghoursparser.y"
                                                             {
    ((*yyvalp).time) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.time);
    ((*yyvalp).time).hour = -(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.time).hour;
    ((*yyvalp).time).minute = -(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.time).minute;
  }
#line 1933 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 49: /* WeekdaySelector: HolidayOrWeekdaySequence  */
#line 442 "openinghoursparser.y"
                              {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).weekdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange);
  }
#line 1942 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 50: /* WeekdaySelector: HolidayAndWeekdaySequence  */
#line 446 "openinghoursparser.y"
                               {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).weekdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange);
  }
#line 1951 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 51: /* HolidayAndWeekdaySequence: HolidayAndWeekday  */
#line 453 "openinghoursparser.y"
                        { ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange); }
#line 1957 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 52: /* HolidayAndWeekdaySequence: HolidayAndWeekdaySequence T_COMMA HolidayAndWeekday  */
#line 454 "openinghoursparser.y"
                                                                {
    ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.weekdayRange);
    appendSelector(((*yyvalp).weekdayRange), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange));
  }
#line 1966 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 53: /* HolidayAndWeekday: HolidaySequence WeekdaySequence  */
#line 461 "openinghoursparser.y"
                                        {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->lhsAndSelector.reset((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.weekdayRange));
    ((*yyvalp).weekdayRange)->rhsAndSelector.reset((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange));
  }
#line 1976 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 54: /* HolidayAndWeekday: WeekdaySequence HolidaySequence  */
#line 466 "openinghoursparser.y"
                                        { // wrong order according to the specification
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->lhsAndSelector.reset((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange));
    ((*yyvalp).weekdayRange)->rhsAndSelector.reset((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.weekdayRange));
  }
#line 1986 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 55: /* HolidayOrWeekdaySequence: WeekdayRange  */
#line 474 "openinghoursparser.y"
                  { ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange); }
#line 1992 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 56: /* HolidayOrWeekdaySequence: Holiday  */
#line 475 "openinghoursparser.y"
             { ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange); }
#line 1998 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 57: /* HolidayOrWeekdaySequence: HolidayOrWeekdaySequence T_COMMA WeekdayRange  */
#line 476 "openinghoursparser.y"
                                                      {
    ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.weekdayRange);
    appendSelector(((*yyvalp).weekdayRange), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange));
  }
#line 2007 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 58: /* HolidayOrWeekdaySequence: HolidayOrWeekdaySequence T_COMMA Holiday  */
#line 480 "openinghoursparser.y"
                                                 {
    ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.weekdayRange);
    appendSelector(((*yyvalp).weekdayRange), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange));
  }
#line 2016 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 59: /* WeekdaySequence: WeekdayRange  */
#line 487 "openinghoursparser.y"
                  { ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange); }
#line 2022 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 60: /* WeekdaySequence: WeekdaySequence T_COMMA WeekdayRange  */
#line 488 "openinghoursparser.y"
                                             {
    ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.weekdayRange);
    appendSelector(((*yyvalp).weekdayRange), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange));
  }
#line 2031 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 61: /* WeekdayRange: T_WEEKDAY  */
#line 495 "openinghoursparser.y"
               {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->beginDay = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
    ((*yyvalp).weekdayRange)->endDay = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2041 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 62: /* WeekdayRange: T_WEEKDAY RangeSeparator T_WEEKDAY  */
#line 500 "openinghoursparser.y"
                                             {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->beginDay = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num);
    ((*yyvalp).weekdayRange)->endDay = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2051 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 63: /* WeekdayRange: T_WEEKDAY T_LBRACKET NthSequence T_RBRACKET  */
#line 505 "openinghoursparser.y"
                                                    {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->beginDay = ((*yyvalp).weekdayRange)->endDay = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num);
    ((*yyvalp).weekdayRange)->nthSequence.reset((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.nthSequence));
  }
#line 2061 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 64: /* WeekdayRange: T_WEEKDAY T_LBRACKET NthSequence T_RBRACKET DayOffset  */
#line 510 "openinghoursparser.y"
                                                                 {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->beginDay = ((*yyvalp).weekdayRange)->endDay = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num);
    ((*yyvalp).weekdayRange)->nthSequence.reset((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.nthSequence));
    ((*yyvalp).weekdayRange)->offset = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2072 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 65: /* HolidaySequence: Holiday  */
#line 519 "openinghoursparser.y"
             { ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange); }
#line 2078 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 66: /* HolidaySequence: HolidaySequence T_COMMA Holiday  */
#line 520 "openinghoursparser.y"
                                        { ((*yyvalp).weekdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.weekdayRange); appendSelector(((*yyvalp).weekdayRange), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.weekdayRange)); }
#line 2084 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 67: /* Holiday: T_PH  */
#line 524 "openinghoursparser.y"
       {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->holiday = WeekdayRange::PublicHoliday;
  }
#line 2093 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 68: /* Holiday: T_PH DayOffset  */
#line 528 "openinghoursparser.y"
                    {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->holiday = WeekdayRange::PublicHoliday;
    ((*yyvalp).weekdayRange)->offset = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2103 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 69: /* Holiday: T_SH  */
#line 533 "openinghoursparser.y"
       {
    ((*yyvalp).weekdayRange) = new WeekdayRange;
    ((*yyvalp).weekdayRange)->holiday = WeekdayRange::SchoolHoliday;
  }
#line 2112 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 70: /* NthSequence: NthEntry  */
#line 540 "openinghoursparser.y"
              {
      ((*yyvalp).nthSequence) = new NthSequence;
      ((*yyvalp).nthSequence)->add((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nthEntry));
  }
#line 2121 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 71: /* NthSequence: NthSequence T_COMMA NthEntry  */
#line 544 "openinghoursparser.y"
                                       {
      (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.nthSequence)->add((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.nthEntry));
      ((*yyvalp).nthSequence) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.nthSequence);
  }
#line 2130 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 72: /* NthEntry: T_INTEGER  */
#line 550 "openinghoursparser.y"
               {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) < 1 || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) > 5) { YYABORT; }
    ((*yyvalp).nthEntry) = {(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num)};
  }
#line 2139 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 73: /* NthEntry: T_INTEGER T_MINUS T_INTEGER  */
#line 554 "openinghoursparser.y"
                                      {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num) < 1 || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num) > 5 || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) < 1 || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) > 5 || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) <= (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num)) { YYABORT; }
    ((*yyvalp).nthEntry) = {(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num)};
  }
#line 2148 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 74: /* NthEntry: T_MINUS T_INTEGER  */
#line 558 "openinghoursparser.y"
                       {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) < 1 || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) > 5) { YYABORT; }
    ((*yyvalp).nthEntry) = {-(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num),-(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num)};
  }
#line 2157 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 75: /* DayOffset: T_PLUS T_INTEGER T_KEYWORD_DAY  */
#line 565 "openinghoursparser.y"
                                    { ((*yyvalp).num) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num); }
#line 2163 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 76: /* DayOffset: T_MINUS T_INTEGER T_KEYWORD_DAY  */
#line 566 "openinghoursparser.y"
                                     { ((*yyvalp).num) = -(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num); }
#line 2169 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 77: /* WeekSelector: T_KEYWORD_WEEK Week  */
#line 571 "openinghoursparser.y"
                         {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).weekSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.week);
  }
#line 2178 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 78: /* WeekSelector: WeekSelector T_COMMA Week  */
#line 575 "openinghoursparser.y"
                                    {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    appendSelector(((*yyvalp).selectors).weekSelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.week));
  }
#line 2187 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 79: /* Week: T_INTEGER  */
#line 582 "openinghoursparser.y"
               {
    ((*yyvalp).week) = new Week;
    ((*yyvalp).week)->beginWeek = ((*yyvalp).week)->endWeek = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2196 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 80: /* Week: T_INTEGER T_MINUS T_INTEGER  */
#line 586 "openinghoursparser.y"
                                      {
    ((*yyvalp).week) = new Week;
    ((*yyvalp).week)->beginWeek = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num);
    ((*yyvalp).week)->endWeek = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2206 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 81: /* Week: T_INTEGER T_MINUS T_INTEGER T_SLASH T_INTEGER  */
#line 591 "openinghoursparser.y"
                                                           {
    ((*yyvalp).week) = new Week;
    ((*yyvalp).week)->beginWeek = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num);
    ((*yyvalp).week)->endWeek = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num);
    ((*yyvalp).week)->interval = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2217 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 82: /* MonthdaySelector: MonthdayRange  */
#line 603 "openinghoursparser.y"
                   {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).monthdaySelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.monthdayRange);
  }
#line 2226 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 83: /* MonthdaySelector: MonthdaySelector T_COMMA MonthdayRangeAdditional  */
#line 607 "openinghoursparser.y"
                                                         {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    appendSelector(((*yyvalp).selectors).monthdaySelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.monthdayRange));
  }
#line 2235 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 84: /* MonthdaySelector: MonthdaySelector T_COMMA T_INTEGER  */
#line 611 "openinghoursparser.y"
                                           {
    // month day sets, not covered the official grammar but in the
    // description in https://wiki.openstreetmap.org/wiki/Key:opening_hours#Summary_syntax
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    if (!extendMonthdaySelector(((*yyvalp).selectors).monthdaySelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num))) {
        delete ((*yyvalp).selectors).monthdaySelector;
        YYABORT;
    }
  }
#line 2249 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 85: /* MonthdaySelector: MonthdaySelector T_ADDITIONAL_RULE_SEPARATOR T_INTEGER  */
#line 620 "openinghoursparser.y"
                                                               {
    // same as the above, just with the wrong ", " separator
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    if (!extendMonthdaySelector(((*yyvalp).selectors).monthdaySelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num))) {
        delete ((*yyvalp).selectors).monthdaySelector;
        YYABORT;
    }
  }
#line 2262 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 86: /* MonthdaySelector: MonthdaySelector T_COMMA T_INTEGER T_MINUS T_INTEGER  */
#line 628 "openinghoursparser.y"
                                                                  {
    // same with a range of days
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.selectors);
    if (!extendMonthdaySelector(((*yyvalp).selectors).monthdaySelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num))) {
        delete ((*yyvalp).selectors).monthdaySelector;
        YYABORT;
    }
  }
#line 2275 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 87: /* MonthdaySelector: MonthdaySelector T_ADDITIONAL_RULE_SEPARATOR T_INTEGER T_MINUS T_INTEGER  */
#line 636 "openinghoursparser.y"
                                                                                      {
    // same as the above, just with the wrong ", " separator
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.selectors);
    if (!extendMonthdaySelector(((*yyvalp).selectors).monthdaySelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num))) {
        delete ((*yyvalp).selectors).monthdaySelector;
        YYABORT;
    }
  }
#line 2288 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 88: /* MonthdayRange: T_YEAR  */
#line 647 "openinghoursparser.y"
            {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = ((*yyvalp).monthdayRange)->end = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, 0, Date::FixedDate, { 0, 0, 0 } };
  }
#line 2297 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 89: /* MonthdayRange: MonthdayRangeAdditional  */
#line 651 "openinghoursparser.y"
                             { ((*yyvalp).monthdayRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.monthdayRange); }
#line 2303 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 90: /* MonthdayRangeAdditional: T_MONTH  */
#line 654 "openinghoursparser.y"
             {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = ((*yyvalp).monthdayRange)->end = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
  }
#line 2312 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 91: /* MonthdayRangeAdditional: T_YEAR T_MONTH  */
#line 658 "openinghoursparser.y"
                       {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = ((*yyvalp).monthdayRange)->end = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
  }
#line 2321 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 92: /* MonthdayRangeAdditional: T_MONTH RangeSeparator T_MONTH  */
#line 662 "openinghoursparser.y"
                                         {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
    ((*yyvalp).monthdayRange)->end = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
  }
#line 2331 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 93: /* MonthdayRangeAdditional: T_YEAR T_MONTH RangeSeparator T_MONTH  */
#line 667 "openinghoursparser.y"
                                                   {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
    ((*yyvalp).monthdayRange)->end = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
  }
#line 2341 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 94: /* MonthdayRangeAdditional: T_YEAR T_MONTH RangeSeparator T_YEAR T_MONTH  */
#line 672 "openinghoursparser.y"
                                                               {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
    ((*yyvalp).monthdayRange)->end = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, { 0, 0, 0 } };
  }
#line 2351 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 95: /* MonthdayRangeAdditional: T_MONTH AltMonthdayOffset RangeSeparator T_MONTH AltMonthdayOffset  */
#line 677 "openinghoursparser.y"
                                                                                     {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dateOffset) };
    ((*yyvalp).monthdayRange)->end = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dateOffset) };
  }
#line 2361 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 96: /* MonthdayRangeAdditional: DateFrom  */
#line 682 "openinghoursparser.y"
              {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = ((*yyvalp).monthdayRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date);
  }
#line 2370 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 97: /* MonthdayRangeAdditional: DateFrom DateOffset  */
#line 686 "openinghoursparser.y"
                            {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.date);
    ((*yyvalp).monthdayRange)->begin.offset += (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dateOffset);
    ((*yyvalp).monthdayRange)->end = ((*yyvalp).monthdayRange)->begin;
  }
#line 2381 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 98: /* MonthdayRangeAdditional: DateFrom RangeSeparator DateTo  */
#line 692 "openinghoursparser.y"
                                       {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.date);
    ((*yyvalp).monthdayRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date);
    if (((*yyvalp).monthdayRange)->end.year == 0) { ((*yyvalp).monthdayRange)->end.year = ((*yyvalp).monthdayRange)->begin.year; }
    if (((*yyvalp).monthdayRange)->end.month == 0) { ((*yyvalp).monthdayRange)->end.month = ((*yyvalp).monthdayRange)->begin.month; }
  }
#line 2393 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 99: /* MonthdayRangeAdditional: DateFrom DateOffset RangeSeparator DateTo  */
#line 699 "openinghoursparser.y"
                                                      {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.date);
    ((*yyvalp).monthdayRange)->begin.offset += (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dateOffset);
    ((*yyvalp).monthdayRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date);
    if (((*yyvalp).monthdayRange)->end.year == 0) { ((*yyvalp).monthdayRange)->end.year = ((*yyvalp).monthdayRange)->begin.year; }
    if (((*yyvalp).monthdayRange)->end.month == 0) { ((*yyvalp).monthdayRange)->end.month = ((*yyvalp).monthdayRange)->begin.month; }
  }
#line 2406 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 100: /* MonthdayRangeAdditional: DateFrom RangeSeparator DateTo DateOffset  */
#line 707 "openinghoursparser.y"
                                                      {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.date);
    ((*yyvalp).monthdayRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.date);
    if (((*yyvalp).monthdayRange)->end.year == 0) { ((*yyvalp).monthdayRange)->end.year = ((*yyvalp).monthdayRange)->begin.year; }
    if (((*yyvalp).monthdayRange)->end.month == 0) { ((*yyvalp).monthdayRange)->end.month = ((*yyvalp).monthdayRange)->begin.month; }
    ((*yyvalp).monthdayRange)->end.offset += (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dateOffset);
  }
#line 2419 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 101: /* MonthdayRangeAdditional: DateFrom RangeSeparator T_MONTH AltMonthdayOffset  */
#line 715 "openinghoursparser.y"
                                                             {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.date);
    ((*yyvalp).monthdayRange)->end = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.date).year, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dateOffset) };
  }
#line 2429 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 102: /* MonthdayRangeAdditional: T_MONTH AltMonthdayOffset RangeSeparator DateTo  */
#line 720 "openinghoursparser.y"
                                                           {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num), 0, Date::FixedDate, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dateOffset) };
    ((*yyvalp).monthdayRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date);
  }
#line 2439 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 103: /* MonthdayRangeAdditional: DateFrom DateOffset RangeSeparator DateTo DateOffset  */
#line 725 "openinghoursparser.y"
                                                                     {
    ((*yyvalp).monthdayRange) = new MonthdayRange;
    ((*yyvalp).monthdayRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.date);
    ((*yyvalp).monthdayRange)->begin.offset += (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dateOffset);
    ((*yyvalp).monthdayRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.date);
    if (((*yyvalp).monthdayRange)->end.year == 0) { ((*yyvalp).monthdayRange)->end.year = ((*yyvalp).monthdayRange)->begin.year; }
    if (((*yyvalp).monthdayRange)->end.month == 0) { ((*yyvalp).monthdayRange)->end.month = ((*yyvalp).monthdayRange)->begin.month; }
    ((*yyvalp).monthdayRange)->end.offset += (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dateOffset);
  }
#line 2453 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 104: /* DateOffset: T_PLUS T_WEEKDAY  */
#line 737 "openinghoursparser.y"
                      { ((*yyvalp).dateOffset) = { 0, (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 1 }; }
#line 2459 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 105: /* DateOffset: T_MINUS T_WEEKDAY  */
#line 738 "openinghoursparser.y"
                       { ((*yyvalp).dateOffset) = { 0, (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), -1 }; }
#line 2465 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 106: /* DateOffset: DayOffset  */
#line 739 "openinghoursparser.y"
               { ((*yyvalp).dateOffset) = { (int16_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0, 0 }; }
#line 2471 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 107: /* DateFrom: T_MONTH T_INTEGER  */
#line 743 "openinghoursparser.y"
                          { ((*yyvalp).date) = { 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), Date::FixedDate, { 0, 0, 0 } }; }
#line 2477 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 108: /* DateFrom: T_YEAR T_MONTH T_INTEGER  */
#line 744 "openinghoursparser.y"
                                    { ((*yyvalp).date) = { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), Date::FixedDate, { 0, 0, 0 } }; }
#line 2483 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 109: /* DateFrom: VariableDate  */
#line 745 "openinghoursparser.y"
                  { ((*yyvalp).date) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date); }
#line 2489 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 110: /* DateFrom: T_YEAR VariableDate  */
#line 746 "openinghoursparser.y"
                            {
    ((*yyvalp).date) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date);
    ((*yyvalp).date).year = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num);
  }
#line 2498 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 111: /* DateTo: DateFrom  */
#line 753 "openinghoursparser.y"
              { ((*yyvalp).date) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.date); }
#line 2504 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 112: /* DateTo: T_INTEGER  */
#line 754 "openinghoursparser.y"
               { ((*yyvalp).date) = { 0, 0, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), Date::FixedDate, { 0, 0, 0 } }; }
#line 2510 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 113: /* VariableDate: T_EASTER  */
#line 758 "openinghoursparser.y"
           { ((*yyvalp).date) = { 0, 0, 0, Date::Easter, { 0, 0, 0 } }; }
#line 2516 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 114: /* VariableDate: T_WHITSUN  */
#line 759 "openinghoursparser.y"
            { ((*yyvalp).date) = { 0, 0, 0, Date::Easter, { 49, 0, 0 } }; }
#line 2522 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 115: /* AltMonthdayOffset: T_WEEKDAY T_LBRACKET T_INTEGER T_RBRACKET  */
#line 763 "openinghoursparser.y"
                                                  { ((*yyvalp).dateOffset) = { 0, (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num), (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num) }; }
#line 2528 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 116: /* AltMonthdayOffset: T_WEEKDAY T_LBRACKET T_MINUS T_INTEGER T_RBRACKET  */
#line 764 "openinghoursparser.y"
                                                          { ((*yyvalp).dateOffset) = { 0, (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num), (int8_t)-(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num) }; }
#line 2534 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 117: /* AltMonthdayOffset: T_WEEKDAY T_LBRACKET T_INTEGER T_RBRACKET DayOffset  */
#line 765 "openinghoursparser.y"
                                                               { ((*yyvalp).dateOffset) = { (int16_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num), (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num) }; }
#line 2540 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 118: /* AltMonthdayOffset: T_WEEKDAY T_LBRACKET T_MINUS T_INTEGER T_RBRACKET DayOffset  */
#line 766 "openinghoursparser.y"
                                                                       { ((*yyvalp).dateOffset) = { (int16_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), (int8_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.num), (int8_t)-(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num) }; }
#line 2546 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 119: /* YearSelector: YearRangeStandalone  */
#line 772 "openinghoursparser.y"
                         {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).yearSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.yearRange);
  }
#line 2555 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 120: /* YearSelector: YearSelectorCombined T_COMMA YearRange  */
#line 776 "openinghoursparser.y"
                                               {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    appendSelector(((*yyvalp).selectors).yearSelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.yearRange));
  }
#line 2564 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 121: /* YearSelectorCombined: YearRange  */
#line 782 "openinghoursparser.y"
               {
    initSelectors(((*yyvalp).selectors));
    ((*yyvalp).selectors).yearSelector = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.yearRange);
  }
#line 2573 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 122: /* YearSelectorCombined: YearSelectorCombined T_COMMA YearRange  */
#line 786 "openinghoursparser.y"
                                               {
    ((*yyvalp).selectors) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.selectors);
    appendSelector(((*yyvalp).selectors).yearSelector, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.yearRange));
  }
#line 2582 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 123: /* YearRange: T_YEAR  */
#line 793 "openinghoursparser.y"
            {
    ((*yyvalp).yearRange) = new YearRange;
    ((*yyvalp).yearRange)->begin = ((*yyvalp).yearRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2591 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 124: /* YearRange: YearRangeStandalone  */
#line 797 "openinghoursparser.y"
                         { ((*yyvalp).yearRange) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.yearRange); }
#line 2597 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 125: /* YearRangeStandalone: T_YEAR RangeSeparator T_YEAR  */
#line 801 "openinghoursparser.y"
                                       {
    ((*yyvalp).yearRange) = new YearRange;
    ((*yyvalp).yearRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num);
    ((*yyvalp).yearRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
    if (((*yyvalp).yearRange)->end < ((*yyvalp).yearRange)->begin) {
        delete ((*yyvalp).yearRange);
        YYABORT;
    }
  }
#line 2611 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 126: /* YearRangeStandalone: T_YEAR T_SLASH T_INTEGER  */
#line 810 "openinghoursparser.y"
                                 {
    ((*yyvalp).yearRange) = new YearRange;
    ((*yyvalp).yearRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num);
    ((*yyvalp).yearRange)->interval = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2621 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 127: /* YearRangeStandalone: T_YEAR RangeSeparator T_YEAR T_SLASH T_INTEGER  */
#line 815 "openinghoursparser.y"
                                                            {
    ((*yyvalp).yearRange) = new YearRange;
    ((*yyvalp).yearRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.num);
    ((*yyvalp).yearRange)->end = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num);
    if (((*yyvalp).yearRange)->end < ((*yyvalp).yearRange)->begin) {
        delete ((*yyvalp).yearRange);
        YYABORT;
    }
    ((*yyvalp).yearRange)->interval = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num);
  }
#line 2636 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 128: /* YearRangeStandalone: T_YEAR T_PLUS  */
#line 825 "openinghoursparser.y"
                   {
    ((*yyvalp).yearRange) = new YearRange;
    ((*yyvalp).yearRange)->begin = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num);
  }
#line 2645 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 129: /* ExtendedHourMinute: T_INTEGER T_COLON T_INTEGER  */
#line 832 "openinghoursparser.y"
                                    {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2654 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 130: /* ExtendedHourMinute: T_INTEGER T_ALT_TIME_SEP T_INTEGER  */
#line 836 "openinghoursparser.y"
                                           {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2663 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 131: /* ExtendedHourMinute: T_INTEGER T_COLON T_INTEGER T_ALT_TIME_SEP_OR_SUFFIX  */
#line 840 "openinghoursparser.y"
                                                             {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num) };
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2672 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 132: /* ExtendedHourMinute: T_INTEGER T_ALT_TIME_SEP_OR_SUFFIX T_INTEGER  */
#line 844 "openinghoursparser.y"
                                                     {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2681 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 133: /* ExtendedHourMinute: T_INTEGER T_ALT_TIME_SEP_OR_SUFFIX  */
#line 848 "openinghoursparser.y"
                                        {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.num), 0 };
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2690 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 134: /* ExtendedHourMinute: T_INTEGER T_COLON T_ALT_TIME_AM  */
#line 852 "openinghoursparser.y"
                                        {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    Time::convertFromAm(((*yyvalp).time));
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2700 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 135: /* ExtendedHourMinute: T_INTEGER T_ALT_TIME_SEP T_ALT_TIME_AM  */
#line 857 "openinghoursparser.y"
                                               {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    Time::convertFromAm(((*yyvalp).time));
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2710 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 136: /* ExtendedHourMinute: T_INTEGER T_COLON T_ALT_TIME_PM  */
#line 862 "openinghoursparser.y"
                                        {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    Time::convertFromPm(((*yyvalp).time));
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2720 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 137: /* ExtendedHourMinute: T_INTEGER T_ALT_TIME_SEP T_ALT_TIME_PM  */
#line 867 "openinghoursparser.y"
                                               {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.num), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) };
    Time::convertFromPm(((*yyvalp).time));
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2730 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 138: /* ExtendedHourMinute: T_ALT_TIME_AM  */
#line 872 "openinghoursparser.y"
                   {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0 };
    Time::convertFromAm(((*yyvalp).time));
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2740 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 139: /* ExtendedHourMinute: T_ALT_TIME_PM  */
#line 877 "openinghoursparser.y"
                   {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num), 0 };
    Time::convertFromPm(((*yyvalp).time));
    if (!Time::isValid(((*yyvalp).time))) { YYABORT; }
  }
#line 2750 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;

  case 140: /* ExtendedHourMinute: T_4DIGIT_TIME  */
#line 882 "openinghoursparser.y"
                   {
    ((*yyvalp).time) = { Time::NoEvent, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) / 100, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.num) % 100 }; // lexer ensures this is always a valid time
}
#line 2758 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
    break;


#line 2762 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (parser);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_Rule: /* Rule  */
#line 208 "openinghoursparser.y"
            { delete ((*yyvaluep).rule); }
#line 2817 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_SelectorSequence: /* SelectorSequence  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2829 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_WideRangeSelector: /* WideRangeSelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2841 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_SmallRangeSelector: /* SmallRangeSelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2853 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_TimeSelector: /* TimeSelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2865 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_Timespan: /* Timespan  */
#line 216 "openinghoursparser.y"
            { delete ((*yyvaluep).timespan); }
#line 2871 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_WeekdaySelector: /* WeekdaySelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2883 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_HolidayAndWeekdaySequence: /* HolidayAndWeekdaySequence  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2889 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_HolidayAndWeekday: /* HolidayAndWeekday  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2895 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_HolidayOrWeekdaySequence: /* HolidayOrWeekdaySequence  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2901 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_WeekdaySequence: /* WeekdaySequence  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2907 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_WeekdayRange: /* WeekdayRange  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2913 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_HolidaySequence: /* HolidaySequence  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2919 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_Holiday: /* Holiday  */
#line 218 "openinghoursparser.y"
            { delete ((*yyvaluep).weekdayRange); }
#line 2925 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_NthSequence: /* NthSequence  */
#line 217 "openinghoursparser.y"
            { delete ((*yyvaluep).nthSequence); }
#line 2931 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_WeekSelector: /* WeekSelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2943 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_Week: /* Week  */
#line 219 "openinghoursparser.y"
            { delete ((*yyvaluep).week); }
#line 2949 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_MonthdaySelector: /* MonthdaySelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2961 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_MonthdayRange: /* MonthdayRange  */
#line 220 "openinghoursparser.y"
            { delete ((*yyvaluep).monthdayRange); }
#line 2967 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_MonthdayRangeAdditional: /* MonthdayRangeAdditional  */
#line 220 "openinghoursparser.y"
            { delete ((*yyvaluep).monthdayRange); }
#line 2973 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_YearSelector: /* YearSelector  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2985 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_YearSelectorCombined: /* YearSelectorCombined  */
#line 209 "openinghoursparser.y"
            {
    delete ((*yyvaluep).selectors).timeSelector;
    delete ((*yyvaluep).selectors).weekdaySelector;
    delete ((*yyvaluep).selectors).weekSelector;
    delete ((*yyvaluep).selectors).monthdaySelector;
    delete ((*yyvaluep).selectors).yearSelector;
}
#line 2997 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_YearRange: /* YearRange  */
#line 221 "openinghoursparser.y"
            { delete ((*yyvaluep).yearRange); }
#line 3003 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

    case YYSYMBOL_YearRangeStandalone: /* YearRangeStandalone  */
#line 221 "openinghoursparser.y"
            { delete ((*yyvaluep).yearRange); }
#line 3009 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, &yys->yyloc, parser, scanner);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, parser, scanner);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , parser, scanner);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, yylocp, parser, scanner);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, yylocp, parser, scanner);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, &yyloc, parser, scanner);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval, &yyloc);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, parser, scanner));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, parser, scanner));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, parser, scanner);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, parser, scanner);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, yylocp, parser, scanner);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, parser, scanner, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, parser, scanner);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, parser, scanner);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, parser, scanner);
              return yyreportAmbiguity (yybest, yyp, yylocp, parser, scanner);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, parser, scanner);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, &yydummy, parser, scanner);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, yylocp, parser, scanner);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, parser, scanner);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , parser, scanner));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn, YYLTYPE *yylocp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], parser, scanner);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, parser, scanner);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], parser, scanner);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, parser, scanner));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], parser, scanner);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
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

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
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
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
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
      yyerror (&yylloc, parser, scanner, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, parser, scanner, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, parser, scanner, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, parser, scanner);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, parser, scanner);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, parser, scanner, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, parser, scanner);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, parser, scanner, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, parser, scanner);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, parser, scanner));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, parser, scanner);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack, parser, scanner);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, parser, scanner));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, parser, scanner));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, parser, scanner, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, parser, scanner));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, parser, scanner);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, parser, scanner));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, parser, scanner);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (&yylloc, parser, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, parser, scanner);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, parser, scanner);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc




#line 890 "openinghoursparser.y"

