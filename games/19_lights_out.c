/* Lights Out on a 3x3 grid. Pressing a cell toggles it and neighbors.
   Starting board is the result of pressing center once from all-off. */
#include <stdio.h>
static int light[3][3]={{0,1,0},{1,1,1},{0,1,0}};
static void toggle(int r,int c){static const int dr[]={0,-1,1,0,0},dc[]={0,0,0,-1,1};for(int k=0;k<5;k++){int x=r+dr[k],y=c+dc[k];if(x>=0&&x<3&&y>=0&&y<3)light[x][y]^=1;}}
static int complete(void){for(int r=0;r<3;r++)for(int c=0;c<3;c++)if(light[r][c])return 0;return 1;}
int main(void){char token[32];int moves=0;puts("Lights Out: turn off all lights. Enter ROW COL (1..3); q quits.");
while(1){for(int r=0;r<3;r++){for(int c=0;c<3;c++)printf("%c%c",light[r][c]?'#':'.',c==2?'\n':' ');}
if(complete()){printf("All lights out in %d moves!\n",moves);return 0;}
printf("Row (or q): ");fflush(stdout);
if(scanf("%31s",token)!=1||token[0]=='q'){puts("Game ended.");return 0;}
if(token[1]||token[0]<'1'||token[0]>'3'){puts("Invalid row.");continue;}
int r=token[0]-'1',c;if(scanf("%d",&c)!=1){puts("Invalid column.");return 0;}c--;
if(c<0||c>=3){puts("Column must be 1..3.");continue;}
toggle(r,c);moves++;}}
