/* Validate a simple TAC assignment with identifiers and a binary operator.
Input five whitespace-separated tokens: dst = lhs op rhs. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
static int id(const char *s){if(!isalpha((unsigned char)*s)&&*s!='_')return 0;
for(int i=1;s[i];i++)if(!isalnum((unsigned char)s[i])&&s[i]!='_')return 0;return 1;}
int main(void){char d[64],eq[8],a[64],op[8],b[64],extra[8];
int n=scanf("%63s%7s%63s%7s%63s%7s",d,eq,a,op,b,extra);
puts(n==5&&id(d)&&id(a)&&id(b)&&!strcmp(eq,"=")&&strlen(op)==1&&strchr("+-*/",op[0])?"VALID TAC":"INVALID TAC");return 0;}