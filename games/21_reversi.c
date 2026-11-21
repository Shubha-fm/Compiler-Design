/* Two-player Reversi on a 4x4 board. Enter row column 1..4, or q.
   Legal moves must bracket an opponent disk and flip it. */
#include <stdio.h>
static char b[4][4]={{'.','.','.','.'},{'.','O','X','.'},{'.','X','O','.'},{'.','.','.','.'}};
static int inside(int r,int c){return r>=0&&r<4&&c>=0&&c<4;}
static int capture(int r,int c,char p,int apply){if(!inside(r,c)||b[r][c]!='.')return 0;char other=p=='X'?'O':'X';int total=0;
for(int dr=-1;dr<=1;dr++)for(int dc=-1;dc<=1;dc++){if(!dr&&!dc)continue;int rr=r+dr,cc=c+dc,n=0;
while(inside(rr,cc)&&b[rr][cc]==other){n++;rr+=dr;cc+=dc;}
if(n&&inside(rr,cc)&&b[rr][cc]==p){total+=n;if(apply)for(int k=1;k<=n;k++)b[r+dr*k][c+dc*k]=p;}}
if(total&&apply)b[r][c]=p;return total;}
static int possible(char p){for(int r=0;r<4;r++)for(int c=0;c<4;c++)if(capture(r,c,p,0))return 1;return 0;}
static void show(void){puts("  1 2 3 4");for(int r=0;r<4;r++){printf("%d ",r+1);for(int c=0;c<4;c++)printf("%c ",b[r][c]);putchar('\n');}}
int main(void){char p='X',token[32];int passes=0;puts("Mini Reversi: X versus O, row column 1..4; q quits.");
while(passes<2){show();if(!possible(p)){printf("%c passes.\n",p);passes++;p=p=='X'?'O':'X';continue;}passes=0;
printf("%c move (row column): ",p);fflush(stdout);
if(scanf("%31s",token)!=1||token[0]=='q'){puts("Game ended.");return 0;}
if(token[1]||token[0]<'1'||token[0]>'4'){puts("Invalid row.");continue;}int r=token[0]-'1',c;
if(scanf("%d",&c)!=1){puts("Invalid column.");return 0;}c--;
if(!inside(r,c)||!capture(r,c,p,0)){puts("Illegal move.");continue;}capture(r,c,p,1);p=p=='X'?'O':'X';}
show();int x=0,o=0;for(int r=0;r<4;r++)for(int c=0;c<4;c++){x+=b[r][c]=='X';o+=b[r][c]=='O';}
printf("Final X=%d O=%d. %s\n",x,o,x==o?"Draw!":x>o?"X wins!":"O wins!");return 0;}
