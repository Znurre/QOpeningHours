/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_HOME_ZNURRE_PROGRAM_DEVELOP_C_QOPENINGHOURS_BUILD_SRC_LIB_OPENINGHOURSPARSER_P_H_INCLUDED
# define YY_YY_HOME_ZNURRE_PROGRAM_DEVELOP_C_QOPENINGHOURS_BUILD_SRC_LIB_OPENINGHOURSPARSER_P_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 64 "openinghoursparser.y"


#include "openinghours_p.h"
#include "interval.h"

using namespace QOpeningHours;

struct StringRef {
    const char *str;
    int len;
};

struct Selectors {
    Timespan *timeSelector;
    WeekdayRange *weekdaySelector;
    Week *weekSelector;
    MonthdayRange *monthdaySelector;
    YearRange *yearSelector;
    StringRef wideRangeSelectorComment;
    bool seen_24_7;
    bool colonAfterWideRangeSelector;
};

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif


#line 74 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser_p.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_NORMAL_RULE_SEPARATOR = 258, /* T_NORMAL_RULE_SEPARATOR  */
    T_ADDITIONAL_RULE_SEPARATOR = 259, /* T_ADDITIONAL_RULE_SEPARATOR  */
    T_FALLBACK_SEPARATOR = 260,    /* T_FALLBACK_SEPARATOR  */
    T_STATE = 261,                 /* T_STATE  */
    T_24_7 = 262,                  /* T_24_7  */
    T_YEAR = 263,                  /* T_YEAR  */
    T_PLUS = 264,                  /* T_PLUS  */
    T_MINUS = 265,                 /* T_MINUS  */
    T_SLASH = 266,                 /* T_SLASH  */
    T_COLON = 267,                 /* T_COLON  */
    T_COMMA = 268,                 /* T_COMMA  */
    T_ALT_TIME_SEP = 269,          /* T_ALT_TIME_SEP  */
    T_ALT_TIME_SEP_OR_SUFFIX = 270, /* T_ALT_TIME_SEP_OR_SUFFIX  */
    T_ALT_TIME_AM = 271,           /* T_ALT_TIME_AM  */
    T_ALT_TIME_PM = 272,           /* T_ALT_TIME_PM  */
    T_4DIGIT_TIME = 273,           /* T_4DIGIT_TIME  */
    T_ALT_RANGE_SEP = 274,         /* T_ALT_RANGE_SEP  */
    T_EVENT = 275,                 /* T_EVENT  */
    T_LBRACKET = 276,              /* T_LBRACKET  */
    T_RBRACKET = 277,              /* T_RBRACKET  */
    T_LPAREN = 278,                /* T_LPAREN  */
    T_RPAREN = 279,                /* T_RPAREN  */
    T_PH = 280,                    /* T_PH  */
    T_SH = 281,                    /* T_SH  */
    T_KEYWORD_DAY = 282,           /* T_KEYWORD_DAY  */
    T_KEYWORD_WEEK = 283,          /* T_KEYWORD_WEEK  */
    T_EASTER = 284,                /* T_EASTER  */
    T_WHITSUN = 285,               /* T_WHITSUN  */
    T_WEEKDAY = 286,               /* T_WEEKDAY  */
    T_MONTH = 287,                 /* T_MONTH  */
    T_INTEGER = 288,               /* T_INTEGER  */
    T_COMMENT = 289,               /* T_COMMENT  */
    T_INVALID = 290                /* T_INVALID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 108 "openinghoursparser.y"

    int num;
    StringRef strRef;
    State state;
    Rule *rule;
    Time time;
    Selectors selectors;
    Timespan *timespan;
    NthEntry nthEntry;
    NthSequence *nthSequence;
    WeekdayRange *weekdayRange;
    Week *week;
    Date date;
    MonthdayRange *monthdayRange;
    DateOffset dateOffset;
    YearRange *yearRange;

#line 144 "/home/znurre/Program/Develop/C++/Qopeninghours/build/src/lib/openinghoursparser_p.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (QOpeningHours::OpeningHoursPrivate *parser, yyscan_t scanner);

#endif /* !YY_YY_HOME_ZNURRE_PROGRAM_DEVELOP_C_QOPENINGHOURS_BUILD_SRC_LIB_OPENINGHOURSPARSER_P_H_INCLUDED  */
