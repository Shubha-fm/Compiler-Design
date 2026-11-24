/* Count identifiers, integers, operators and other symbols on stdin.
   Illustrative ASCII lexer; does not skip comments or quoted strings. */
#include <stdio.h>
#include <ctype.h>
int main(void){int c,ids=0,integers=0,operators=0,other=0;
while((c=getchar())!=EOF){if(isspace((unsigned char)c))continue;
if(isalpha((unsigned char)c)||c=='_'){ids++;while((c=getchar())!=EOF&&(isalnum((unsigned char)c)||c=='_')){}if(c!=EOF)ungetc(c,stdin);}
else if(isdigit((unsigned char)c)){integers++;while((c=getchar())!=EOF&&isdigit((unsigned char)c)){}if(c!=EOF)ungetc(c,stdin);}
else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='='||c=='<')operators++;else other++;}
printf("identifiers=%d integers=%d operators=%d other=%d\n",ids,integers,operators,other);return 0;}
