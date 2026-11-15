/* Fixed 5x5 Minesweeper with four hidden mines. Enter row col (1..5).
   Reveal safe squares until 21 are open; q quits. No flag action. */
#include <stdio.h>
static const int mines[5][5]={{1,0,0,0,0},{0,0,0,1,0},{0,0,0,0,0},{0,1,0,0,0},{0,0,0,0,1}};
static int shown[5][5]={{0}};
static int nearby(int r,int c){int n=0;for(int a=r-1;a<=r+1;a++)for(int b=c-1;b<=c+1;b++)if(a>=0&&a<5&&b>=0&&b<5&&mines[a][b])n++;return n;}
static void display(void){puts("\n  1 2 3 4 5");for(int r=0;r<5;r++){printf("%d ",r+1);for(int c=0;c<5;c++)printf("%c ",shown[r][c]?(char)('0'+nearby(r,c)):'#');putchar('\n');}}
int main(void){char word[32];int safe=0;puts("Minesweeper: find 21 safe squares; q quits.");
while(safe<21){display();printf("Row (or q): ");fflush(stdout);if(scanf("%31s",word)!=1||word[0]=='q'){puts("Game ended.");return 0;}
if(word[1]||word[0]<'1'||word[0]>'5'){puts("Invalid row.");continue;}
int r=word[0]-'1',c;if(scanf("%d",&c)!=1||c<1||c>5){puts("Invalid column.");return 0;}c--;
if(shown[r][c]){puts("Already open.");continue;}if(mines[r][c]){printf("BOOM! Mine at %d,%d. Game over.\n",r+1,c+1);return 0;}
shown[r][c]=1;safe++;printf("Safe. Adjacent mines: %d\n",nearby(r,c));}
display();puts("You cleared the minefield!");return 0;}