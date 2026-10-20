#include <stdio.h>
#include <string.h>
/* Shift/reduce recognizer for a+b-like strings via E->E+E | i.
   Illustrative, not a general LR parser. */
int main(void){
 char in[128],stack[128]="";int top=0;
 puts("Input using i and + (e.g. i+i+i):");if(scanf("%127s",in)!=1)return 1;
 for(int j=0;in[j];j++){
  if(top>=124){puts("Too long");return 1;}
  stack[top++]=in[j];stack[top]=0;
  if(stack[top-1]=='i'){stack[top-1]='E';}
  while(top>=3&&stack[top-3]=='E'&&stack[top-2]=='+'&&stack[top-1]=='E'){top-=2;stack[top-1]='E';stack[top]=0;}
  printf("Stack: %s\n",stack);
 }
 puts(top==1&&stack[0]=='E'?"Accepted":"Rejected");return 0;
}