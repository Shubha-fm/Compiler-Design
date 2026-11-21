/* Sliding 8-puzzle with numbered tiles; move blank using WASD.
   Start from a solvable board two moves from the goal. */
#include <stdio.h>
#include <string.h>
static int tiles[9]={1,2,3,4,0,5,7,8,6};
static int won(void){for(int i=0;i<8;i++)if(tiles[i]!=i+1)return 0;return tiles[8]==0;}
static void show(void){puts("+---+---+---+");for(int r=0;r<3;r++){for(int c=0;c<3;c++){int n=tiles[r*3+c];if(n)printf("| %d ",n);else printf("|   ");}puts("|");puts("+---+---+---+");}}
int main(void){char input[32];int moves=0;puts("8-Puzzle: move blank using w/a/s/d; q to quit.");
while(1){show();if(won()){printf("Solved in %d moves!\n",moves);return 0;}printf("Move: ");fflush(stdout);
if(scanf("%31s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
if(input[1]){puts("Enter one direction.");continue;}
int dr=0,dc=0;if(input[0]=='w')dr=-1;else if(input[0]=='s')dr=1;else if(input[0]=='a')dc=-1;else if(input[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}
int blank=0;while(tiles[blank])blank++;int row=blank/3+dr,col=blank%3+dc;
if(row<0||row>2||col<0||col>2){puts("Invalid move.");continue;}
int target=row*3+col;tiles[blank]=tiles[target];tiles[target]=0;moves++;}}
