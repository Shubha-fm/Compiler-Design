/* LL(1) recursive descent for E -> T {(+|-) T}; T -> F {(*|/) F}; F -> id | (E). */
#include <stdio.h>
#include <ctype.h>
static const char *p;
static void ws(void){while(isspace((unsigned char)*p))p++;}
static int expr(void);
static int factor(void){ws();if(*p=='('){p++;if(!expr())return 0;ws();if(*p++!=')')return 0;return 1;}if(isalpha((unsigned char)*p)){do{p++;}while(isalnum((unsigned char)*p)||*p=='_');return 1;}return 0;}
static int term(void){if(!factor())return 0;for(;;){ws();if(*p!='*'&&*p!='/')break;p++;if(!factor())return 0;}return 1;}
static int expr(void){if(!term())return 0;for(;;){ws();if(*p!='+'&&*p!='-')break;p++;if(!term())return 0;}return 1;}
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;p=s;int ok=expr();ws();puts(ok&&!*p?"ACCEPT":"REJECT");return 0;}
