/* Backward dead-store elimination for single-letter variable assignments.
   Inputs: n then 'SET x', 'USE x' or 'PRINT x' instruction pairs.
   Assumes SET has no observable side effects. */
#include <stdio.h>
#include <string.h>
static char op[100][8],var[100];static int keep[100],live[26];
int main(void){int n;if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%7s %c",op[i],&var[i])!=2||var[i]<'a'||var[i]>'z')return 1;
if(strcmp(op[i],"SET")&&strcmp(op[i],"USE")&&strcmp(op[i],"PRINT"))return 1;}
for(int i=n-1;i>=0;i--){int v=var[i]-'a';if(!strcmp(op[i],"SET")){if(live[v]){keep[i]=1;live[v]=0;}}
else{keep[i]=1;live[v]=1;}}
int removed=0;for(int i=0;i<n;i++)if(keep[i])printf("%s %c\n",op[i],var[i]);else removed++;
printf("removed=%d\n",removed);return 0;}
