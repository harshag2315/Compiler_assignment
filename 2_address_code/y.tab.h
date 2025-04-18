#ifndef _yy_defines_h_
#define _yy_defines_h_

#define ID 257
#define MAIN 258
#define INT 259
#define PRINT 260
#define LPAREN 261
#define RPAREN 262
#define LBRACE 263
#define RBRACE 264
#define SEMI 265
#define PLUS 266
#define MINUS 267
#define MUL 268
#define ASSIGN 269
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char* str;
    int val;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
