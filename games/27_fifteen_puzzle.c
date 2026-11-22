/* 4x4 15-puzzle, a solvable starting board one move from completion.
   WASD moves the empty square. */
#include <stdio.h>
#include <string.h>
static int a[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15};
static void show(void){puts("+----+----+----+----+");for(int r=0;r<4;r++){for(int c=0;c<4;c++){int v=a[4*r+c];if(v)printf("|%3d ",v);else printf("|    ");}puts("|");puts("+----+----+----+");}}
static int solved(void){for(int i=0;i<15;i++)if(a[i]!=i+1)return 0;return a[15]==0;}
int main(void){char s[32];int moves=0;puts("15-Puzzle: move blank using w/a/s/d; q quits.");
while(1){show();if(solved()){printf("Solved in %d moves!\n",moves);return 0;}
printf("Move: ");fflush(stdout);if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
int dr=0,dc=0;if(s[1]){puts("One direction at a time.");continue;}
if(s[0]=='w')dr=-1;else if(s[0]=='s')dr=1;else if(s[0]=='a')dc=-1;else if(s[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}
int i=0;while(i<16&&a[i])i++;int r=i/4+dr,c=i%4+dc;if(r<0||r>=4||c<0||c>=4){puts("Invalid move.");continue;}
int j=4*r+c;a[i]=a[j];a[j]=0;moves++;}}
