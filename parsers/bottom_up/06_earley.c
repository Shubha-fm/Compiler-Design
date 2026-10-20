/* Earley-style chart recognizer for S->aS|b. Chart holds dotted rules,
   with prediction, scanning, completion. Simple educational implementation. */
#include <stdio.h>
#include <string.h>
typedef struct{int rule,dot,origin;} Item;
typedef struct{Item item[1024];int n;} Chart;
static const char *rhs[]={"S","aS","b"};static const char lhs[]={'Z','S','S'};
static Chart chart[257];
static int add(int col,int rule,int dot,int origin){Chart *c=&chart[col];for(int i=0;i<c->n;i++){Item x=c->item[i];if(x.rule==rule&&x.dot==dot&&x.origin==origin)return 0;}if(c->n>=1024)return 0;c->item[c->n++]=(Item){rule,dot,origin};return 1;}
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int n=(int)strlen(s);add(0,0,0,0);
for(int k=0;k<=n;k++)for(int i=0;i<chart[k].n;i++){Item x=chart[k].item[i];int len=(int)strlen(rhs[x.rule]);if(x.dot<len){char next=rhs[x.rule][x.dot];if(next=='S'){add(k,1,0,k);add(k,2,0,k);}else if(k<n&&s[k]==next)add(k+1,x.rule,x.dot+1,x.origin);}else{for(int j=0;j<chart[x.origin].n;j++){Item y=chart[x.origin].item[j];if(rhs[y.rule][y.dot]==lhs[x.rule])add(k,y.rule,y.dot+1,y.origin);}}}
for(int i=0;i<chart[n].n;i++){Item x=chart[n].item[i];if(x.rule==0&&x.dot==1&&x.origin==0){puts("ACCEPT");return 0;}}puts("REJECT");return 0;}
