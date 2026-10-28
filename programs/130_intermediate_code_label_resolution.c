/* Resolve labels in a small pseudo-IR instruction list.
   Each line is LABEL name or JMP name, END ends input. */
#include <stdio.h>
#include <string.h>
int main(void){char op[16],arg[32],names[64][32],refs[64][32];int pos[64],n=0,m=0,pc=0;while(scanf("%15s",op)==1){if(!strcmp(op,"END"))break;if(scanf("%31s",arg)!=1)return 1;if(!strcmp(op,"LABEL")){if(n==64)return 1;strcpy(names[n],arg);pos[n++]=pc;}else if(!strcmp(op,"JMP")){if(m==64)return 1;strcpy(refs[m++],arg);pc++;}else return 1;}for(int i=0;i<m;i++){int found=-1;for(int j=0;j<n;j++)if(!strcmp(refs[i],names[j]))found=pos[j];if(found<0)printf("UNRESOLVED %s\n",refs[i]);else printf("JMP %s -> %d\n",refs[i],found);}return 0;}