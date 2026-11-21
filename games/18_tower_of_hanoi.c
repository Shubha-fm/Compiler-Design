/* Interactive Tower of Hanoi with 3 disks and 3 pegs.
   Enter FROM TO, e.g. 1 3; q quits. */
#include <stdio.h>
static int peg[3][3]={{3,2,1},{0},{0}},height[3]={3,0,0};
static void show(void){for(int p=0;p<3;p++){printf("Peg %d:",p+1);for(int j=0;j<height[p];j++)printf(" %d",peg[p][j]);putchar('\n');}}
int main(void){char token[32];int moves=0;puts("Tower of Hanoi: move 3 disks from peg 1 to peg 3. q quits.");
while(1){show();if(height[2]==3){printf("Solved in %d moves!\n",moves);return 0;}
printf("Move FROM TO: ");fflush(stdout);
if(scanf("%31s",token)!=1||token[0]=='q'){puts("Game ended.");return 0;}
if(token[1]||token[0]<'1'||token[0]>'3'){puts("Use pegs 1, 2, 3.");continue;}
int from=token[0]-'1',to;if(scanf("%d",&to)!=1){puts("Invalid destination.");return 0;}to--;
if(to<0||to>2||from==to||!height[from]||(height[to]&&peg[to][height[to]-1]<peg[from][height[from]-1])){puts("Illegal move.");continue;}
int disk=peg[from][--height[from]];peg[to][height[to]++]=disk;moves++;}}
