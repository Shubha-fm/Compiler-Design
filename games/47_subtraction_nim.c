/* One heap: remove 1, 2 or 3 stones; computer uses optimal modulo-4 play. */
#include <stdio.h>
#include <string.h>
int main(void){int stones=17;char cmd[32];puts("Subtraction Nim: 17 stones. Remove 1-3; last stone wins. q quits.");
while(stones>0){printf("Stones=%d. Take: ",stones);fflush(stdout);
if(scanf("%31s",cmd)!=1||!strcmp(cmd,"q")){puts("Game ended.");return 0;}
if(strlen(cmd)!=1||cmd[0]<'1'||cmd[0]>'3'){puts("Choose 1, 2 or 3.");continue;}
int take=cmd[0]-'0';if(take>stones){puts("Not enough stones.");continue;}stones-=take;
if(!stones){puts("You win!");return 0;}
int bot=stones%4;if(bot==0)bot=1;if(bot>stones)bot=stones;stones-=bot;
printf("Computer takes %d.\n",bot);if(!stones){puts("Computer wins!");return 0;}}
return 0;}