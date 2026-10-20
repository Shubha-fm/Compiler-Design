/* SLR(1) table for grammar S -> C C; C -> c C | d.
Input c*d c*d, e.g. cdd, ccdcdd.
State transition/reduce table generated from LR(0) items and FOLLOW sets. */
#include <stdio.h>
#include <string.h>
enum {ERR=0,SHIFT=1,REDUCE=2,ACCEPT=3};
typedef struct {int kind,arg;} Action;
static const Action action[7][3]={
 {{SHIFT,3},{SHIFT,4},{ERR,0}}, /* 0 */
 {{ERR,0},{ERR,0},{ACCEPT,0}}, /* 1 */
 {{SHIFT,3},{SHIFT,4},{ERR,0}}, /* 2 */
 {{SHIFT,3},{SHIFT,4},{ERR,0}}, /* 3 */
 {{REDUCE,3},{REDUCE,3},{REDUCE,3}}, /* 4: C->d */
 {{ERR,0},{ERR,0},{REDUCE,1}}, /* 5: S->CC */
 {{REDUCE,2},{REDUCE,2},{REDUCE,2}}  /* 6: C->cC */
};
static int go(int st,char nt){if(st==0)return nt=='S'?1:nt=='C'?2:-1;if(st==2&&nt=='C')return 5;if(st==3&&nt=='C')return 6;return -1;}
int main(void){char in[256];if(scanf("%255s",in)!=1)return 1;int stack[512]={0},top=0,i=0;for(int steps=0;steps<1000;steps++){char c=in[i]?in[i]:'$';int col=c=='c'?0:c=='d'?1:c=='$'?2:-1;if(col<0||top>500)break;Action a=action[stack[top]][col];if(a.kind==SHIFT){stack[++top]=a.arg;i++;}else if(a.kind==REDUCE){int len=a.arg==1?2:a.arg==2?2:1;char nt=a.arg==1?'S':'C';if(top<len)break;top-=len;int state=go(stack[top],nt);if(state<0)break;stack[++top]=state;}else if(a.kind==ACCEPT){puts("ACCEPT");return 0;}else break;}puts("REJECT");return 0;}
