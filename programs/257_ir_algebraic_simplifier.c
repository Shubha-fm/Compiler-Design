/* Algebraic rewrite for a pure integer three-address operation.
   Supported identities: +0, -0, *1, *0; overflow/traps not modelled. */
#include <stdio.h>
#include <string.h>
int main(void){
  char d[32],eq[4],a[32],op[4],b[32];const char *result=NULL;
  if(scanf("%31s %3s %31s %3s %31s",d,eq,a,op,b)!=5||strcmp(eq,"="))return 1;
  if(!strcmp(op,"+")){if(!strcmp(a,"0"))result=b;else if(!strcmp(b,"0"))result=a;}
  else if(!strcmp(op,"-")){if(!strcmp(b,"0"))result=a;}
  else if(!strcmp(op,"*")){if(!strcmp(a,"0")||!strcmp(b,"0"))result="0";
    else if(!strcmp(a,"1"))result=b;else if(!strcmp(b,"1"))result=a;}
  if(result)printf("%s = %s\n",d,result);
  else printf("%s = %s %s %s\n",d,a,op,b);
  return 0;
}