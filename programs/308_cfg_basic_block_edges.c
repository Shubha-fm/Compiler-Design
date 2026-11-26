/* Build basic blocks from a toy instruction stream.
   Each line is: NORMAL, BR target, JMP target, or HALT.
   Branch has fallthrough. Outputs leaders and CFG edges. */
#include <stdio.h>
#include <string.h>
static char op[100][8];static int target[100],leader[100],block[100];
int main(void){int n;if(scanf("%d",&n)!=1||n<1||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%7s",op[i])!=1)return 1;if(!strcmp(op[i],"BR")||!strcmp(op[i],"JMP")){if(scanf("%d",&target[i])!=1||target[i]<0||target[i]>=n)return 1;}
else if(strcmp(op[i],"NORMAL")&&strcmp(op[i],"HALT"))return 1;}
leader[0]=1;for(int i=0;i<n;i++){if(!strcmp(op[i],"BR")||!strcmp(op[i],"JMP"))leader[target[i]]=1;
if(i+1<n&&strcmp(op[i],"NORMAL"))leader[i+1]=1;}
int blocks=0;for(int i=0;i<n;i++){if(leader[i])blocks++;block[i]=blocks-1;}
printf("blocks=%d\n",blocks);
for(int i=0;i<n;i++)if(leader[i])printf("leader=%d block=%d\n",i,block[i]);
for(int i=0;i<n;i++)if(i==n-1||block[i]!=block[i+1]){if(!strcmp(op[i],"JMP")||!strcmp(op[i],"BR"))printf("edge %d->%d\n",block[i],block[target[i]]);
if(strcmp(op[i],"JMP")&&strcmp(op[i],"HALT")&&i+1<n)printf("edge %d->%d\n",block[i],block[i+1]);}
return 0;}
