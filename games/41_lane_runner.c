/* Turn-based three-lane runner. Avoid obstacles for six turns. */
#include <stdio.h>
#include <string.h>
static const int obstacle[6]={0,2,1,0,2,1};
int main(void){int lane=1;char cmd[16];puts("Lane Runner: a=left, d=right, s=stay, q=quit. Lanes 1-3.");
for(int turn=0;turn<6;){printf("Turn %d/6, lane=%d. Obstacle in lane %d. Move: ",turn+1,lane+1,obstacle[turn]+1);fflush(stdout);
if(scanf("%15s",cmd)!=1||!strcmp(cmd,"q")){puts("Game ended.");return 0;}
if(!strcmp(cmd,"a")){if(lane==0){puts("Edge of track.");continue;}lane--;}
else if(!strcmp(cmd,"d")){if(lane==2){puts("Edge of track.");continue;}lane++;}
else if(strcmp(cmd,"s")){puts("Use a/d/s.");continue;}
if(lane==obstacle[turn]){printf("Crash on turn %d!\n",turn+1);return 0;}turn++;}
puts("Finished the race!");return 0;}
