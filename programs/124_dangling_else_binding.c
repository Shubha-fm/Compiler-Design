/* Illustrate nearest-if binding in nested IF IF ELSE token sequence. */
#include <stdio.h>
#include <string.h>
int main(void){char s[32];int pending[32],n=0,ifs=0,elses=0;while(scanf("%31s",s)==1){if(!strcmp(s,"if")){if(n==32)return 1;pending[n++]=++ifs;}else if(!strcmp(s,"else")){if(!n){puts("UNMATCHED ELSE");return 0;}printf("else binds if%d\n",pending[--n]);elses++;}else return 1;}printf("unmatched_if=%d\n",ifs-elses);return 0;}