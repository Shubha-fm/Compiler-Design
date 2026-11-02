/* Validate parser ACTION table entries from state, terminal, action lines.
   Detect conflicting actions for same cell. */
#include <stdio.h>
#include <string.h>
int main(void){int n,s;char symbol,action[16],table[32][128][16]={{{0}}};if(scanf("%d",&n)!=1||n<0||n>200)return 1;for(int i=0;i<n;i++){if(scanf("%d %c %15s",&s,&symbol,action)!=3||s<0||s>=32||(unsigned char)symbol>=128)return 1;char *cell=table[s][(unsigned char)symbol];if(*cell&&strcmp(cell,action)){printf("CONFLICT state=%d terminal=%c\n",s,symbol);return 0;}strcpy(cell,action);}puts("NO CONFLICT");return 0;}