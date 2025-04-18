#ifndef _yy_defines_h_
#define _yy_defines_h_

#define MAIN 257
#define INT 258
#define ASSIGN 259
#define PRINT 260
#define NUMBER 261
#define ID 262
#define PLUS 263
#define MINUS 264
#define TIMES 265
#define SEMI 266
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int iValue;
    char sIndex;
    nodeType *nPtr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
