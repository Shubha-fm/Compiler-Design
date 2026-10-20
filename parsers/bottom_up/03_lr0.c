/* LR(0) shift/reduce table for augmented grammar S'->S, S->aS|b.
States: 0: a->2 b->3 goto S=1; 2: a->2 b->3 goto S=4; 3 reduce S->b; 4 reduce S->aS; 1 accept. */
#include <stdio.h>
int main(void){char in[256];if(scanf("%255s",in)!=1)return 1;int st[512],top=0,i=0;st[0]=0;
for(int steps=0;steps<1000;steps++){int s=st[top],x=in[i]?in[i]:'$';if(s==0||s==2){if(x=='a'){st[++top]=2;i++;}else if(x=='b'){st[++top]=3;i++;}else break;}
else if(s==3||s==4){int pop=s==3?1:2;top-=pop;if(top<0)break;int base=st[top];int go=base==0?1:base==2?4:-1;if(go<0)break;st[++top]=go;}
else if(s==1&&x=='$'){puts("ACCEPT");return 0;}else break;}
puts("REJECT");return 0;}
