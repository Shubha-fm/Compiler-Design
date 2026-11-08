/* BFS shortest binary input word reaching target state from initial state. */
#include <stdio.h>
int main(void){int n,start,target,next[32][2],seen[32]={0},q[32],parent[32],letter[32],h=0,t=0;
if(scanf("%d%d%d",&n,&start,&target)!=3||n<1||n>32||start<0||start>=n||target<0||target>=n)return 1;
for(int i=0;i<n;i++)for(int c=0;c<2;c++)if(scanf("%d",&next[i][c])!=1||next[i][c]<0||next[i][c]>=n)return 1;
q[t++]=start;seen[start]=1;parent[start]=-1;while(h<t){int x=q[h++];if(x==target){char word[33];int k=0;while(parent[x]>=0){word[k++]=(char)('0'+letter[x]);x=parent[x];}printf("word:");if(!k)printf(" epsilon");while(k)putchar(word[--k]);putchar('\n');return 0;}for(int c=0;c<2;c++){int y=next[x][c];if(!seen[y]){seen[y]=1;parent[y]=x;letter[y]=c;q[t++]=y;}}}puts("UNREACHABLE");return 0;}