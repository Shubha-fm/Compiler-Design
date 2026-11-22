/* Two-player mini checkers on a 6x6 board, men only.
   Forced captures are not implemented; capturing is optional. */
#include <stdio.h>
static char b[6][6];
static void show(void){puts("   1 2 3 4 5 6");for(int r=0;r<6;r++){printf("%d  ",r+1);for(int c=0;c<6;c++)printf("%c ",b[r][c]);putchar('\n');}}
static int inside(int r,int c){return r>=0&&r<6&&c>=0&&c<6;}
int main(void){for(int r=0;r<6;r++)for(int c=0;c<6;c++)b[r][c]=((r+c)&1)?(r<2?'x':r>3?'o':'.'):' ';
char side='x',input[32];int turns=0;puts("Mini Checkers: x goes down, o goes up. Enter from-row from-col to-row to-col, or q.");
while(turns<100){show();int leftx=0,lefto=0;for(int r=0;r<6;r++)for(int c=0;c<6;c++){leftx+=b[r][c]=='x';lefto+=b[r][c]=='o';}
if(!leftx||!lefto){printf("%c wins!\n",leftx?'x':'o');return 0;}
printf("%c move: ",side);fflush(stdout);
if(scanf("%31s",input)!=1||input[0]=='q'){puts("Game ended.");return 0;}
if(input[1]||input[0]<'1'||input[0]>'6'){puts("Invalid source row.");continue;}
int sr=input[0]-'1',sc,tr,tc;if(scanf("%d%d%d",&sc,&tr,&tc)!=3){puts("Invalid move format.");return 0;}sc--;tr--;tc--;
if(!inside(sr,sc)||!inside(tr,tc)||b[sr][sc]!=side||b[tr][tc]!='.'){puts("Illegal move.");continue;}
int dr=tr-sr,dc=tc-sc,dir=side=='x'?1:-1;
if(dr==dir&&(dc==1||dc==-1)){}else if(dr==2*dir&&(dc==2||dc==-2)&&b[sr+dir][sc+dc/2]==(side=='x'?'o':'x')){b[sr+dir][sc+dc/2]='.';}else{puts("Illegal move.");continue;}
b[tr][tc]=side;b[sr][sc]='.';turns++;side=side=='x'?'o':'x';}
show();puts("Turn limit reached: draw.");return 0;}
