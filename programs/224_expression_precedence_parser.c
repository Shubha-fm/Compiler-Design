/* Recursive-descent evaluator for nonnegative numbers, +, *, parentheses.
Whitespaces allowed; rejects syntax errors and trailing tokens. */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
static char source[1024],*p;static int good=1;
static void skip(void){while(isspace((unsigned char)*p))p++;}
static long expr(void);
static long factor(void){skip();if(*p=='('){p++;long v=expr();skip();if(*p!=')')good=0;else p++;return v;}if(!isdigit((unsigned char)*p)){good=0;return 0;}char *end;long v=strtol(p,&end,10);p=end;return v;}
static long term(void){long v=factor();skip();while(good&&*p=='*'){p++;long b=factor();v*=b;skip();}return v;}
static long expr(void){long v=term();skip();while(good&&*p=='+'){p++;long b=term();v+=b;skip();}return v;}
int main(void){if(!fgets(source,sizeof source,stdin))return 1;p=source;long v=expr();skip();if(!good||*p){puts("SYNTAX ERROR");return 0;}printf("value=%ld\n",v);return 0;}