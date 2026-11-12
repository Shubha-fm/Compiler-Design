/* Assign addresses to labels for NOP (1 byte), JMP (2 bytes), HALT (1 byte).
Only label addresses are produced; no object-code emission. */
#include <stdio.h>
#include <string.h>
int main(void){char op[16],name[32],names[100][32];int address[100],count=0,pc=0;
while(scanf("%15s",op)==1){if(!strcmp(op,"END"))break;
if(!strcmp(op,"LABEL")){if(scanf("%31s",name)!=1||count==100)return 1;
for(int i=0;i<count;i++)if(!strcmp(name,names[i])){puts("DUPLICATE");return 0;}
strcpy(names[count],name);address[count++]=pc;}
else if(!strcmp(op,"NOP")||!strcmp(op,"HALT"))pc++;
else if(!strcmp(op,"JMP")){if(scanf("%31s",name)!=1)return 1;pc+=2;}
else return 1;}
for(int i=0;i<count;i++)printf("%s=%d\n",names[i],address[i]);return 0;}