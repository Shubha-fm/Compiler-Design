/* Hexapawn on a 3x3 board: two human players.
   White W moves toward row 1, black B toward row 3.
   Enter from-row from-col to-row to-col. */
#include <stdio.h>
#include <string.h>
static char b[3][3]={{'B','B','B'},{'.','.','.'},{'W','W','W'}};
static int moves(char p){int d=p=='W'?-1:1;for(int r=0;r<3;r++)for(int c=0;c<3;c++)if(b[r][c]==p){int nr=r+d;if(nr<0||nr>=3)continue;if(b[nr][c]=='.')return 1;for(int dc=-1;dc<=1;dc+=2){int nc=c+dc;if(nc>=0&&nc<3&&b[nr][nc]!='.'&&b[nr][nc]!=p)return 1;}}return 0;}
static void show(void){puts("  1 2 3");for(int r=0;r<3;r++)printf("%d %c %c %c\n",r+1,b[r][0],b[r][1],b[r][2]);}
int main(void){char p='W',s[32];puts("Hexapawn: W moves up; B moves down. q quits.");
while(1){show();int pieces=0;for(int r=0;r<3;r++)for(int c=0;c<3;c++)pieces+=b[r][c]==p;
if(!pieces||!moves(p)){printf("%c wins!\n",p=='W'?'B':'W');return 0;}
printf("%c move FROM_ROW FROM_COL TO_ROW TO_COL: ",p);fflush(stdout);
if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
if(strlen(s)!=1||s[0]<'1'||s[0]>'3'){puts("Invalid row.");continue;}
int r=s[0]-'1',c,nr,nc;if(scanf("%d%d%d",&c,&nr,&nc)!=3)return 1;c--;nr--;nc--;
if(c<0||c>=3||nr<0||nr>=3||nc<0||nc>=3||b[r][c]!=p){puts("Invalid source or destination.");continue;}
int d=p=='W'?-1:1;if(nr!=r+d){puts("Illegal move.");continue;}
if(c==nc){if(b[nr][nc]!='.'){puts("Blocked.");continue;}}
else if((c-nc==1||nc-c==1)&&b[nr][nc]!='.'&&b[nr][nc]!=p){}
else{puts("Illegal capture.");continue;}
b[nr][nc]=p;b[r][c]='.';if(nr==(p=='W'?0:2)){show();printf("%c reaches the far side and wins!\n",p);return 0;}
p=p=='W'?'B':'W';}}
