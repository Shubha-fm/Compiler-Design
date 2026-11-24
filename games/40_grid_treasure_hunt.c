/* Treasure hunt on 5x5 grid: avoid fixed traps while finding treasure.
   Player moves one cell using WASD. */
#include <stdio.h>
#include <string.h>
static const char *map[]={".....",".#...",".#.#.","...#.","....."};
int main(void){int r=0,c=0,moves=0;char s[32];
puts("Treasure Hunt: go from (1,1) to (5,5); # traps. WASD to move, q quits.");
while(1){for(int i=0;i<5;i++){for(int j=0;j<5;j++)putchar(i==r&&j==c?'@':i==4&&j==4?'T':map[i][j]);putchar('\n');}
if(r==4&&c==4){printf("Treasure found in %d moves!\n",moves);return 0;}
printf("Move: ");fflush(stdout);if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
if(strlen(s)!=1){puts("One direction only.");continue;}int dr=0,dc=0;
if(s[0]=='w')dr=-1;else if(s[0]=='s')dr=1;else if(s[0]=='a')dc=-1;else if(s[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}
int nr=r+dr,nc=c+dc;if(nr<0||nr>=5||nc<0||nc>=5){puts("Outside the map.");continue;}
if(map[nr][nc]=='#'){puts("Trap encountered! Game over.");return 0;}r=nr;c=nc;moves++;}
}
