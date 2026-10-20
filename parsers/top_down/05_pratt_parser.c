/* Pratt/TDOP parser with prefix minus and infix +,-,*,/,^. ^ is right associative. */
#include <stdio.h>
#include <ctype.h>
static const char *p;static void ws(void){while(isspace((unsigned char)*p))p++;}
static int expression(int min);
static int nud(void){ws();if(*p=='-'){p++;return expression(30);}if(*p=='('){p++;if(!expression(0))return 0;ws();if(*p!=')')return 0;p++;return 1;}if(isalnum((unsigned char)*p)){while(isalnum((unsigned char)*p))p++;return 1;}return 0;}
static int lbp(char c){return c=='+'||c=='-'?10:c=='*'||c=='/'?20:c=='^'?40:-1;}
static int expression(int min){if(!nud())return 0;for(;;){ws();int bp=lbp(*p);if(bp<min)break;char op=*p++;if(!expression(bp+(op=='^'?0:1)))return 0;}return 1;}
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;p=s;int ok=expression(0);ws();puts(ok&&!*p?"ACCEPT":"REJECT");return 0;}
