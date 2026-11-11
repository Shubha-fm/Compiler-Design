/* Two-pass label assembler for tokens: LABEL name, NOP, JMP name, HALT, END.
   First pass assigns instruction addresses; second resolves JMP targets. */
#include <stdio.h>
#include <string.h>
int main(void){
  char cmd[16],arg[32],labels[100][32],ops[100][8],args[100][32];
  int addresses[100],nl=0,ni=0;
  while(scanf("%15s",cmd)==1&&!(!strcmp(cmd,"END"))){
    if(!strcmp(cmd,"LABEL")){
      if(nl==100||scanf("%31s",arg)!=1)return 1;
      for(int j=0;j<nl;j++)if(!strcmp(labels[j],arg)){puts("DUPLICATE LABEL");return 0;}
      strcpy(labels[nl],arg);addresses[nl++]=ni;
    }else if(!strcmp(cmd,"JMP")){
      if(ni==100||scanf("%31s",arg)!=1)return 1;
      strcpy(ops[ni],"JMP");strcpy(args[ni++],arg);
    }else if(!strcmp(cmd,"NOP")||!strcmp(cmd,"HALT")){
      if(ni==100)return 1;strcpy(ops[ni++],cmd);
    }else return 1;
  }
  for(int i=0;i<ni;i++){
    if(strcmp(ops[i],"JMP"))printf("%d %s\n",i,ops[i]);
    else{int target=-1;for(int j=0;j<nl;j++)if(!strcmp(labels[j],args[i]))target=addresses[j];
      if(target<0){printf("UNRESOLVED %s\n",args[i]);return 0;}
      printf("%d JMP %d\n",i,target);
    }
  }
  return 0;
}