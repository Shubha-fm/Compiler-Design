/* Mini 4x4 Sudoku: enter row, column, value (1..4), or q. */
#include <stdio.h>
static int board[4][4]={{1,0,0,4},{0,4,1,0},{0,1,4,0},{4,0,0,1}};
static const int fixed[4][4]={{1,0,0,1},{0,1,1,0},{0,1,1,0},{1,0,0,1}};
static void show(void){puts("  1 2 3 4");for(int r=0;r<4;r++){printf("%d ",r+1);for(int c=0;c<4;c++)printf("%c%c",board[r][c]?'0'+board[r][c]:'.',c==1?'|':' ');putchar('\n');if(r==1)puts("  -----");}}
static int valid(int r,int c,int val){
for(int k=0;k<4;k++)if((k!=c&&board[r][k]==val)||(k!=r&&board[k][c]==val))return 0;
for(int a=(r/2)*2;a<(r/2)*2+2;a++)for(int b=(c/2)*2;b<(c/2)*2+2;b++)if((a!=r||b!=c)&&board[a][b]==val)return 0;
return 1;}
static int complete(void){for(int r=0;r<4;r++)for(int c=0;c<4;c++)if(!board[r][c])return 0;return 1;}
int main(void){char line[64];puts("Mini Sudoku 4x4: enter row col value (1..4), or q to quit.");
while(1){show();if(complete()){puts("Puzzle solved!");return 0;}printf("Move: ");fflush(stdout);
if(!fgets(line,sizeof line,stdin)){puts("Game ended.");return 0;}if(line[0]=='q'){puts("Game ended.");return 0;}
int r,c,v;char extra;if(sscanf(line,"%d %d %d %c",&r,&c,&v,&extra)!=3||r<1||r>4||c<1||c>4||v<1||v>4){puts("Enter row col value from 1 to 4.");continue;}
r--;c--;if(fixed[r][c]){puts("This cell is fixed.");continue;}
if(!valid(r,c,v)){puts("Conflicts with row, column, or 2x2 box.");continue;}
board[r][c]=v;puts("Placed.");}}