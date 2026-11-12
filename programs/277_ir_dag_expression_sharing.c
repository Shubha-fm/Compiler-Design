/* Count unique pure binary expressions (order independent for + and *).
No operand reassignment is modeled; only expression signatures are compared. */
#include <stdio.h>
#include <string.h>
int main(void){int n,unique=0;char op[100][4],a[100][32],b[100][32];
if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%3s%31s%31s",op[i],a[i],b[i])!=3||strlen(op[i])!=1||!strchr("+-*/",op[i][0]))return 1;
int duplicate=0;for(int j=0;j<i;j++)if(!strcmp(op[i],op[j])){
int same=!strcmp(a[i],a[j])&&!strcmp(b[i],b[j]);
if(op[i][0]=='+'||op[i][0]=='*')same|=!strcmp(a[i],b[j])&&!strcmp(b[i],a[j]);
if(same)duplicate=1;}
if(!duplicate)unique++;}
printf("unique_expressions=%d\n",unique);return 0;}