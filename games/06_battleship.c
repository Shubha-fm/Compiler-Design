/* Single-player 5x5 Battleship. Find all four cells of a hidden ship. */
#include <stdio.h>
static const int ship[5][5]={{0,0,0,0,0},{0,1,1,1,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0}};
static char hits[5][5]={{0}};
int main(void){int remaining=4,turns=0;char word[32];
puts("Mini Battleship: guess ROW COL (1..5); q to quit. Four ship cells.");
while(remaining){printf("\n    1 2 3 4 5\n");for(int r=0;r<5;r++){printf("%d | ",r+1);for(int c=0;c<5;c++)printf("%c ",hits[r][c]?hits[r][c]:'.');putchar('\n');}
printf("Row (or q): ");fflush(stdout);if(scanf("%31s",word)!=1||word[0]=='q'){puts("Game ended.");return 0;}
if(word[1]||word[0]<'1'||word[0]>'5'){puts("Invalid row.");continue;}int r=word[0]-'1',c;
if(scanf("%d",&c)!=1||c<1||c>5){puts("Invalid column.");return 0;}c--;
if(hits[r][c]){puts("Already guessed.");continue;}
turns++;hits[r][c]=ship[r][c]?'X':'o';
if(ship[r][c]){remaining--;puts("Hit!");}else puts("Miss.");}
printf("You sank all ships in %d turns!\n",turns);return 0;}