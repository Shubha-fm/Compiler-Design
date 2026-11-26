/* Traverse a four-step binary decision tree to find treasure.
   Each choice 0 or 1 appends one bit. The winning path is 1011. */
#include <stdio.h>
#include <string.h>
int main(void){char path[5]={0},cmd[16];puts("Binary Path Puzzle: choose 0/1 four times. q quits.");
for(int i=0;i<4;){printf("Level %d, path=%s. Branch: ",i+1,path);fflush(stdout);
if(scanf("%15s",cmd)!=1||!strcmp(cmd,"q")){puts("Game ended.");return 0;}
if(strlen(cmd)!=1||(cmd[0]!='0'&&cmd[0]!='1')){puts("Choose 0 or 1.");continue;}
path[i]=cmd[0];path[++i]=0;}
printf("Path: %s\n",path);puts(!strcmp(path,"1011")?"Treasure discovered!":"Empty chamber. Try again.");return 0;}
