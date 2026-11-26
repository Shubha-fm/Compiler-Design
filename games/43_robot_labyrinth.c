/* Robot navigation with a shortest-path hint using BFS.
   S=start, G=goal, #=wall; WASD to move, h for hint. */
#include <stdio.h>
#include <string.h>
static const char *grid[]={"########","#S    ##","### #  #","#   ## #","# #    #","#    #G#","########"};
static int row=1,col=1;
static int open(int r,int c){return r>=0&&r<7&&c>=0&&c<8&&grid[r][c]!='#';}
static char hint(void){int dist[7][8]={ {0} },qr[56],qc[56],head=0,tail=0;const int dr[]={-1,1,0,0},dc[]={0,0,-1,1};const char dir[]="wsad";qr[tail]=5;qc[tail++]=6;dist[5][6]=1;
while(head<tail){int r=qr[head],c=qc[head++];for(int k=0;k<4;k++){int nr=r+dr[k],nc=c+dc[k];if(open(nr,nc)&&!dist[nr][nc]){dist[nr][nc]=dist[r][c]+1;qr[tail]=nr;qc[tail++]=nc;}}}
int best=1000;char result='?';for(int k=0;k<4;k++){int nr=row+dr[k],nc=col+dc[k];if(open(nr,nc)&&dist[nr][nc]&&dist[nr][nc]<best){best=dist[nr][nc];result=dir[k];}}return result;}
int main(void){char input[16];puts("Robot Labyrinth: WASD moves, h shortest-route hint, q quit.");
while(1){for(int r=0;r<7;r++){for(int c=0;c<8;c++)putchar(row==r&&col==c?'@':grid[r][c]);putchar('\n');}
if(row==5&&col==6){puts("Robot reached the goal!");return 0;}
printf("Command: ");fflush(stdout);if(scanf("%15s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
if(!strcmp(input,"h")){printf("Hint: %c\n",hint());continue;}
if(strlen(input)!=1){puts("One command at a time.");continue;}
int dr=0,dc=0;if(input[0]=='w')dr=-1;else if(input[0]=='s')dr=1;else if(input[0]=='a')dc=-1;else if(input[0]=='d')dc=1;else{puts("Use w/a/s/d/h.");continue;}
if(!open(row+dr,col+dc)){puts("Blocked.");continue;}row+=dr;col+=dc;}}
