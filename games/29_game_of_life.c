/* Conway's Game of Life on a fixed 8x8 board.
   Enter number of generations (0..20), or q to quit. */
#include <stdio.h>
#include <string.h>
static int board[8][8]={{0}};
static void show(void){for(int r=0;r<8;r++){for(int c=0;c<8;c++)putchar(board[r][c]?'#':'.');putchar('\n');}}
static void step(void){int next[8][8]={{0}};
for(int r=0;r<8;r++)for(int c=0;c<8;c++){int neighbors=0;for(int dr=-1;dr<=1;dr++)for(int dc=-1;dc<=1;dc++){int x=r+dr,y=c+dc;if((dr||dc)&&x>=0&&x<8&&y>=0&&y<8)neighbors+=board[x][y];}
next[r][c]=neighbors==3||(board[r][c]&&neighbors==2);}
for(int r=0;r<8;r++)for(int c=0;c<8;c++)board[r][c]=next[r][c];}
int main(void){board[3][2]=board[3][3]=board[3][4]=1;char token[32];puts("Game of Life: gliderless blinker example. Generations 0..20 or q.");
printf("Generations: ");fflush(stdout);if(scanf("%31s",token)!=1||!strcmp(token,"q")){puts("Game ended.");return 0;}
int n=-1;char tail;if(sscanf(token,"%d%c",&n,&tail)!=1||n<0||n>20){puts("Invalid generation count.");return 0;}
puts("Generation 0:");show();for(int i=1;i<=n;i++){step();printf("Generation %d:\n",i);show();}return 0;}
