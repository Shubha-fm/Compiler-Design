/* Nim: human removes 1-3 stones, computer uses modulo-four strategy. */
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){int stones=21;if(argc>2)return 1;
if(argc==2){char *end;long n=strtol(argv[1],&end,10);if(end==argv[1]||*end||n<1||n>100)return 1;stones=(int)n;}
puts("Nim: remove 1, 2, or 3 stones. Player who takes last stone wins. q quits.");
while(stones>0){char input[32];printf("Stones: %d. Take (1-3): ",stones);fflush(stdout);
if(scanf("%31s",input)!=1||input[0]=='q'){puts("Game ended.");return 0;}
if(input[1]||input[0]<'1'||input[0]>'3'||input[0]-'0'>stones){puts("Invalid number of stones.");continue;}
int mine=input[0]-'0';stones-=mine;if(!stones){puts("You win!");return 0;}
int take=stones%4;if(take==0)take=1;if(take>stones)take=stones;
printf("Computer takes %d.\n",take);stones-=take;
if(!stones){puts("Computer wins!");return 0;}}
return 0;}