/* Reach the exit of a fixed 5x5 map in at most 8 legal moves. */
#include <stdio.h>
#include <string.h>
static const char *wall[]={".....",".###.",".....",".###.","....."};
int main(void){int r=0,c=0,moves=0;char cmd[32];puts("Grid Escape: reach (5,5) in 8 moves. WASD; q quits.");
while(1){printf("Position=(%d,%d), moves=%d/8\n",r+1,c+1,moves);
if(r==4&&c==4){puts("Escaped in time!");return 0;}if(moves==8){puts("Time expired!");return 0;}
printf("Direction: ");fflush(stdout);if(scanf("%31s",cmd)!=1||!strcmp(cmd,"q")){puts("Game ended.");return 0;}
if(strlen(cmd)!=1){puts("One direction.");continue;}
int dr=0,dc=0;if(cmd[0]=='w')dr=-1;else if(cmd[0]=='s')dr=1;
else if(cmd[0]=='a')dc=-1;else if(cmd[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}
int nr=r+dr,nc=c+dc;if(nr<0||nr>=5||nc<0||nc>=5||wall[nr][nc]=='#'){puts("Blocked.");continue;}
r=nr;c=nc;moves++;}}
