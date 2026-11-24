/* One-dimensional peg solitaire on seven slots.
   Initial board ooo.ooo; jump adjacent peg into an empty cell, removing jumped peg.
   Enter FROM TO as 1-based positions; q quits. */
#include <stdio.h>
static char board[8]="ooo.ooo";
static void display(void){printf("Slots: 1 2 3 4 5 6 7\nBoard: %c %c %c %c %c %c %c\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6]);}
int main(void){int pegs=6;char token[32];puts("Line Peg Solitaire: jump a peg over a peg into an empty slot. q quits.");
while(1){display();if(pegs==1){puts("You win with one peg!");return 0;}
int moves=0;for(int i=0;i<7;i++)if(board[i]=='o')for(int d=-2;d<=2;d+=4){int j=i+d,mid=i+d/2;if(j>=0&&j<7&&board[j]=='.'&&board[mid]=='o')moves++;}
if(!moves){printf("No moves. %d pegs remain.\n",pegs);return 0;}
printf("From (or q): ");fflush(stdout);if(scanf("%31s",token)!=1||!strcmp(token,"q")){puts("Game ended.");return 0;}
if(token[1]||token[0]<'1'||token[0]>'7'){puts("Invalid source.");continue;}
int from=token[0]-'1',to;if(scanf("%d",&to)!=1){puts("Invalid destination.");return 0;}to--;
if(to<0||to>=7||(to-from!=2&&to-from!=-2)||board[from]!='o'||board[(from+to)/2]!='o'||board[to]!='.'){puts("Illegal jump.");continue;}
board[to]='o';board[from]=board[(from+to)/2]='.';pegs--;}}
