/* Navigate a fixed maze with WASD. '#' walls, S start, E exit. */
#include <stdio.h>
static const char *maze[]={
"##########",
"#S  #    #",
"### # ## #",
"#   # #  #",
"# ### # ##",
"#     # E#",
"##########"
};static int row=1,col=1;
static void draw(void){puts("");for(int r=0;r<7;r++){for(int c=0;c<10;c++)putchar(r==row&&c==col?'@':maze[r][c]);putchar('\n');}}
int main(void){puts("Maze Escape: WASD to move; reach E. q quits.");while(1){draw();char cmd[32];printf("Move: ");fflush(stdout);
if(scanf("%31s",cmd)!=1||cmd[0]=='q'){puts("Game ended.");return 0;}
int dr=0,dc=0;if(cmd[1]==0){if(cmd[0]=='w')dr=-1;else if(cmd[0]=='s')dr=1;else if(cmd[0]=='a')dc=-1;else if(cmd[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}}else{puts("One move at a time.");continue;}
int nr=row+dr,nc=col+dc;if(nr<0||nr>=7||nc<0||nc>=10||maze[nr][nc]=='#'){puts("Wall!");continue;}
row=nr;col=nc;if(maze[row][col]=='E'){draw();puts("You escaped!");return 0;}}
}