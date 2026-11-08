/* Scoped declarations: ENTER, DECL name, FIND name, EXIT, END.
Each scope holds up to 50 identifiers; at most 16 nested scopes. */
#include <stdio.h>
#include <string.h>
int main(void){char names[16][50][32],cmd[16],word[32];int count[16]={0},depth=0;
while(scanf("%15s",cmd)==1){if(!strcmp(cmd,"END"))break;
if(!strcmp(cmd,"ENTER")){if(depth==15)return 1;depth++;count[depth]=0;}
else if(!strcmp(cmd,"EXIT")){if(!depth){puts("INVALID EXIT");return 0;}depth--;}
else if(!strcmp(cmd,"DECL")){if(scanf("%31s",word)!=1)return 1;int found=0;for(int j=0;j<count[depth];j++)if(!strcmp(names[depth][j],word))found=1;if(found)puts("DUPLICATE");else{if(count[depth]==50)return 1;strcpy(names[depth][count[depth]++],word);puts("DECLARED");}}
else if(!strcmp(cmd,"FIND")){if(scanf("%31s",word)!=1)return 1;int found=-1;for(int i=depth;i>=0&&found<0;i--)for(int j=0;j<count[i];j++)if(!strcmp(names[i][j],word)){found=i;break;}if(found<0)puts("MISSING");else printf("scope=%d\n",found);}else return 1;}return 0;}