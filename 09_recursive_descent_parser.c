#include <stdio.h>
#include <ctype.h>
const char *p;
int expr(void);
int factor(void){while(*p==' ')p++;if(*p=='('){p++;if(!expr()||*p++!=')')return 0;return 1;}if(isalpha((unsigned char)*p)||isdigit((unsigned char)*p)){p++;return 1;}return 0;}
int term(void){if(!factor())return 0;while(*p=='*'||*p=='/'){p++;if(!factor())return 0;}return 1;}
int expr(void){if(!term())return 0;while(*p=='+'||*p=='-'){p++;if(!term())return 0;}return 1;}
int main(void){char s[256];puts("Expression (single-letter identifiers or digits):");if(!fgets(s,sizeof s,stdin))return 1;p=s;int ok=expr();while(*p==' '||*p=='\n')p++;puts(ok&&!*p?"Accepted":"Rejected");return 0;}
