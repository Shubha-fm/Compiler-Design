/* Thompson construction for postfix regex with a-z literals,
   # epsilon, . concatenation, | alternation, * closure.
   Prints number of NFA states and edges. Educational bounded builder. */
#include <stdio.h>
#include <string.h>
typedef struct{int start,end;} Fragment;
typedef struct{int a,b;char symbol;} Edge;
static Edge edges[4096];static int nodes=0,count=0;
static int state(void){return nodes<1024?nodes++:-1;}
static int edge(int a,int b,char c){if(a<0||b<0||count>=4096)return 0;edges[count++]=(Edge){a,b,c};return 1;}
int main(void){char expr[128];Fragment st[128];int top=0,valid=1;
if(scanf("%127s",expr)!=1)return 1;
for(int i=0;expr[i]&&valid;i++){char c=expr[i];Fragment a,b,f;
if((c>='a'&&c<='z')||c=='#'){f=(Fragment){state(),state()};valid=edge(f.start,f.end,c=='#'?'-':c);st[top++]=f;}
else if(c=='.'){if(top<2){valid=0;break;}b=st[--top];a=st[--top];valid=edge(a.end,b.start,'-');st[top++]=(Fragment){a.start,b.end};}
else if(c=='|'){if(top<2){valid=0;break;}b=st[--top];a=st[--top];f=(Fragment){state(),state()};
valid=edge(f.start,a.start,'-')&&edge(f.start,b.start,'-')&&edge(a.end,f.end,'-')&&edge(b.end,f.end,'-');st[top++]=f;}
else if(c=='*'){if(top<1){valid=0;break;}a=st[--top];f=(Fragment){state(),state()};
valid=edge(f.start,f.end,'-')&&edge(f.start,a.start,'-')&&edge(a.end,a.start,'-')&&edge(a.end,f.end,'-');st[top++]=f;}
else valid=0;}
if(!valid||top!=1){puts("INVALID");return 0;}
printf("states=%d transitions=%d start=%d accept=%d\n",nodes,count,st[0].start,st[0].end);
for(int i=0;i<count;i++)printf("%d -%c-> %d\n",edges[i].a,edges[i].symbol,edges[i].b);
return 0;}
