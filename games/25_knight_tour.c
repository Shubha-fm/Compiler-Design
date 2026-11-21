/* Find a knight's tour on a 5x5 chessboard via backtracking.
   Enter start row and column 1..5 or q. Prints one complete tour. */
#include <stdio.h>
static int board[5][5],dr[8]={2,1,-1,-2,-2,-1,1,2},dc[8]={1,2,2,1,-1,-2,-2,-1};
static int search(int r,int c,int move){if(move==25)return 1;
for(int k=0;k<8;k++){int x=r+dr[k],y=c+dc[k];if(x>=0&&x<5&&y>=0&&y<5&&!board[x][y]){board[x][y]=move+1;if(search(x,y,move+1))return 1;board[x][y]=0;}}return 0;}
int main(void){char token[32];puts("Knight Tour: choose a starting square (row column 1..5), q quits.");
printf("Start row: ");fflush(stdout);
if(scanf("%31s",token)!=1||token[0]=='q'){puts("Game ended.");return 0;}
if(token[1]||token[0]<'1'||token[0]>'5'){puts("Invalid row.");return 0;}
int r=token[0]-'1',c;if(scanf("%d",&c)!=1||c<1||c>5){puts("Invalid column.");return 0;}c--;
board[r][c]=1;
if(!search(r,c,1)){puts("No tour found.");return 0;}
puts("Knight's tour (move numbers):");for(int i=0;i<5;i++){for(int j=0;j<5;j++)printf("%3d",board[i][j]);putchar('\n');}
puts("Tour complete!");return 0;}
