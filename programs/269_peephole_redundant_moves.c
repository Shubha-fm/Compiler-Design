/* Remove MOV x x and consecutive duplicate MOV dst src.
Input n, followed by n MOV destination source instructions. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char prevd[32]="",prevs[32]="",d[32],s[32],op[8];if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%7s%31s%31s",op,d,s)!=3||strcmp(op,"MOV"))return 1;
if(!strcmp(d,s))continue;if(!strcmp(prevd,d)&&!strcmp(prevs,s))continue;
printf("MOV %s %s\n",d,s);strcpy(prevd,d);strcpy(prevs,s);}
return 0;}