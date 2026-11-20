/* Collect a key, unlock the door and reach the treasure. WASD movement. */
#include <stdio.h>
static const char *world[]={"##########","#S   #   #","# ## # #T#","# K  D   #","##########"};
static int row=1,col=1,has_key=0;
static void show(void){printf("\nKey: %s\n",has_key?"yes":"no");for(int r=0;r<5;r++){for(int c=0;c<10;c++){char ch=world[r][c];if(ch=='K'&&has_key)ch=' ';if(r==row&&c==col)ch='@';putchar(ch);}putchar('\n');}}
int main(void){puts("Dungeon Quest: collect K, open D, reach T. WASD moves, q quits.");char cmd[32];
while(1){show();printf("Move: ");fflush(stdout);if(scanf("%31s",cmd)!=1||cmd[0]=='q'){puts("Game ended.");return 0;}
int dr=0,dc=0;if(cmd[1]){puts("One direction only.");continue;}
if(cmd[0]=='w')dr=-1;else if(cmd[0]=='s')dr=1;else if(cmd[0]=='a')dc=-1;else if(cmd[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}
int nr=row+dr,nc=col+dc;if(nr<0||nr>=5||nc<0||nc>=10||world[nr][nc]=='#'){puts("Wall.");continue;}
char tile=world[nr][nc];if(tile=='D'&&!has_key){puts("The door is locked. Find the key.");continue;}
row=nr;col=nc;if(tile=='K'&&!has_key){has_key=1;puts("You found the key!");}
if(tile=='T'){if(has_key)puts("You found the treasure! You win!");else puts("Treasure is locked!");return 0;}}}