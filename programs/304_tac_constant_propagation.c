/* Linear TAC constant propagation for one-letter variables a-z.
   Statements: CONST variable integer, COPY dst src, ADD dst src src,
   PRINT variable. Unknown values are printed as '?'. No branching. */
#include <stdio.h>
#include <string.h>
static int value[26],known[26];
static int var(char c){return c>='a'&&c<='z';}
int main(void){int n;if(scanf("%d",&n)!=1||n<0||n>200)return 1;
for(int i=0;i<n;i++){char op[16],a,b,c;if(scanf("%15s",op)!=1)return 1;
if(!strcmp(op,"CONST")){int x;if(scanf(" %c%d",&a,&x)!=2||!var(a))return 1;known[a-'a']=1;value[a-'a']=x;}
else if(!strcmp(op,"COPY")){if(scanf(" %c %c",&a,&b)!=2||!var(a)||!var(b))return 1;known[a-'a']=known[b-'a'];if(known[a-'a'])value[a-'a']=value[b-'a'];}
else if(!strcmp(op,"ADD")){if(scanf(" %c %c %c",&a,&b,&c)!=3||!var(a)||!var(b)||!var(c))return 1;
int ok=known[b-'a']&&known[c-'a'],sum=value[b-'a']+value[c-'a'];known[a-'a']=ok;if(ok)value[a-'a']=sum;}
else if(!strcmp(op,"PRINT")){if(scanf(" %c",&a)!=1||!var(a))return 1;
if(known[a-'a'])printf("%c=%d\n",a,value[a-'a']);else printf("%c=?\n",a);}
else return 1;}return 0;}
