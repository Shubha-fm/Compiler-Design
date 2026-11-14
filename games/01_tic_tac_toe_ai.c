/* Tic-tac-toe against an optimal minimax computer. You are X, computer O.
   Build: gcc -std=c11 -Wall -Wextra -pedantic games/01_tic_tac_toe_ai.c -o tic */
#include <stdio.h>
static char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
static const int lines[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
static char winner(void){for(int i=0;i<8;i++){int a=lines[i][0],b=lines[i][1],c=lines[i][2];if(board[a]!=' '&&board[a]==board[b]&&board[b]==board[c])return board[a];}return ' ';}
static int full(void){for(int i=0;i<9;i++)if(board[i]==' ')return 0;return 1;}
static int solve(int depth,int turn){char w=winner();if(w=='O')return 10-depth;if(w=='X')return depth-10;if(full())return 0;int best=turn? -100:100;
for(int i=0;i<9;i++)if(board[i]==' '){board[i]=turn?'O':'X';int s=solve(depth+1,!turn);board[i]=' ';if(turn){if(s>best)best=s;}else if(s<best)best=s;}return best;}
static void display(void){puts("");for(int r=0;r<3;r++){printf(" %c | %c | %c\n",board[r*3],board[r*3+1],board[r*3+2]);if(r<2)puts("---+---+---");}}
int main(void){puts("Tic-Tac-Toe: You are X. Choose positions 1-9; q quits.");while(1){display();if(winner()!=' '||full())break;char token[32];printf("Your move: ");fflush(stdout);if(scanf("%31s",token)!=1||token[0]=='q')break;int move=0;if(token[0]>='1'&&token[0]<='9'&&token[1]==0)move=token[0]-'0';if(move<1||move>9||board[move-1]!=' '){puts("Invalid move.");continue;}board[move-1]='X';if(winner()!=' '||full())break;int best=-100,choice=-1;for(int i=0;i<9;i++)if(board[i]==' '){board[i]='O';int s=solve(0,0);board[i]=' ';if(s>best){best=s;choice=i;}}if(choice>=0){board[choice]='O';printf("Computer chooses %d\n",choice+1);}}
display();char w=winner();if(w=='X')puts("You win!");else if(w=='O')puts("Computer wins!");else if(full())puts("Draw!");else puts("Game ended.");return 0;}