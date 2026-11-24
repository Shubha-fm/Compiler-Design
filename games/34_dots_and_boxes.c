/* Two-player Dots and Boxes on a 2x2 square board.
   Horizontal edges H row col: row=1..3, col=1..2.
   Vertical edges V row col: row=1..2, col=1..3. q quits. */
#include <stdio.h>
static int h[3][2]={{0}},v[2][3]={{0}},owner[2][2]={{0}};
static void show(void){for(int r=0;r<3;r++){for(int c=0;c<2;c++)printf("+%s",h[r][c]?"---":"   ");puts("+");
if(r<2){for(int c=0;c<2;c++)printf("%c %c ",v[r][c]?'|':' ',owner[r][c]?(char)('0'+owner[r][c]):' ');printf("%c\n",v[r][2]?'|':' ');}}}
static int closed(int r,int c){return h[r][c]&&h[r+1][c]&&v[r][c]&&v[r][c+1];}
int main(void){int player=1,score[3]={0},edges=0;char token[32];
puts("Dots and Boxes: select H/V ROW COL. Completing a box earns a point and extra turn; q quits.");
while(edges<12){show();printf("Player %d move: ",player);fflush(stdout);
if(scanf("%31s",token)!=1||(token[0]=='q'&&token[1]==0)){puts("Game ended.");return 0;}
char orientation=token[0];if(token[1]||!(orientation=='H'||orientation=='V')){puts("Use H or V.");continue;}
int r,c;if(scanf("%d%d",&r,&c)!=2){puts("Invalid coordinates.");return 0;}r--;c--;
int *edge=NULL;if(orientation=='H'&&r>=0&&r<3&&c>=0&&c<2)edge=&h[r][c];
if(orientation=='V'&&r>=0&&r<2&&c>=0&&c<3)edge=&v[r][c];
if(!edge||*edge){puts("Invalid or selected edge.");continue;}
*edge=1;edges++;int gained=0;
for(int i=0;i<2;i++)for(int j=0;j<2;j++)if(!owner[i][j]&&closed(i,j)){owner[i][j]=player;gained++;score[player]++;}
if(gained)printf("Player %d completes %d box(es)!\n",player,gained);else player=3-player;}
show();printf("Score P1=%d P2=%d. ",score[1],score[2]);
puts(score[1]==score[2]?"Draw!":score[1]>score[2]?"Player 1 wins!":"Player 2 wins!");return 0;}
