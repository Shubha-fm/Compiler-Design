/* Precedence climbing expression parser: identifiers/numbers, +,-,*,/, parentheses. */
#include <stdio.h>
#include <ctype.h>
static const char *p;static void ws(void){while(isspace((unsigned char)*p))p++;}
static int parse(int min);
static int atom(void){ws();if(*p=='('){p++;if(!parse(1))return 0;ws();if(*p!=')')return 0;p++;return 1;}if(isalnum((unsigned char)*p)){while(isalnum((unsigned char)*p))p++;return 1;}return 0;}
static int prec(char c){return c=='+'||c=='-'?1:c=='*'||c=='/'?2:0;}
static int parse(int min){if(!atom())return 0;for(;;){ws();int pr=prec(*p);if(pr<min)break;p++;if(!parse(pr+1))return 0;}return 1;}
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;p=s;int ok=parse(1);ws();puts(ok&&!*p?"ACCEPT":"REJECT");return 0;}
