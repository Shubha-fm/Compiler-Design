/* Simulate an NFA with epsilon transitions (-), alphabet {a,b}.
   Input: n m start, final-count final-states, m edges: from label to, word.
   Use 'eps' as the input word to test the empty string. */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
static uint32_t closure(uint32_t s,const uint32_t ep[32],int n){
  uint32_t old;
  do{old=s;for(int i=0;i<n;i++)if(s&(UINT32_C(1)<<i))s|=ep[i];}while(s!=old);
  return s;
}
int main(void){
  int n,m,start,k;uint32_t ep[32]={0},edges[32][2]={{0}},final=0,s;char c,w[256];
  if(scanf("%d%d%d%d",&n,&m,&start,&k)!=4||n<1||n>32||m<0||m>2048||start<0||start>=n||k<0||k>n)return 1;
  for(int i=0;i<k;i++){int v;if(scanf("%d",&v)!=1||v<0||v>=n)return 1;final|=UINT32_C(1)<<v;}
  for(int i=0;i<m;i++){int a,b;if(scanf("%d %c %d",&a,&c,&b)!=3||a<0||a>=n||b<0||b>=n)return 1;
    if(c=='-')ep[a]|=UINT32_C(1)<<b;
    else if(c=='a'||c=='b')edges[a][c-'a']|=UINT32_C(1)<<b;
    else return 1;
  }
  if(scanf("%255s",w)!=1)return 1;s=closure(UINT32_C(1)<<start,ep,n);
  if(strcmp(w,"eps"))for(int j=0;w[j];j++){if(w[j]!='a'&&w[j]!='b')return 1;
    uint32_t next=0;for(int i=0;i<n;i++)if(s&(UINT32_C(1)<<i))next|=edges[i][w[j]-'a'];
    s=closure(next,ep,n);
  }
  puts(s&final?"ACCEPT":"REJECT");return 0;
}