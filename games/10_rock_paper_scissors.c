/* Best-of-five rounds of rock-paper-scissors vs a seeded computer.
   Each non-tie round counts; ties do not use up a round. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
static uint32_t rng=12345u;static uint32_t random32(void){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;}
static int pick(const char *s){if(!strcmp(s,"rock")||!strcmp(s,"r"))return 0;if(!strcmp(s,"paper")||!strcmp(s,"p"))return 1;if(!strcmp(s,"scissors")||!strcmp(s,"s"))return 2;return -1;}
int main(int argc,char **argv){if(argc>2)return 1;if(argc==2){char *end;unsigned long v=strtoul(argv[1],&end,10);if(end==argv[1]||*end)return 1;rng=(uint32_t)v;if(!rng)rng=1;}
const char *names[]={"rock","paper","scissors"};int wins=0,losses=0,rounds=0;char input[32];
puts("Rock Paper Scissors: first to 3 wins. r/p/s or full words; q quits.");
while(wins<3&&losses<3){printf("Score %d-%d. Your move: ",wins,losses);fflush(stdout);
if(scanf("%31s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
int you=pick(input);if(you<0){puts("Invalid move.");continue;}
int bot=(int)(random32()%3u);printf("Computer played %s.\n",names[bot]);
if(you==bot)puts("Tie.");else if((you-bot+3)%3==1){wins++;puts("You win this round!");}else{losses++;puts("Computer wins this round.");}rounds++;}
printf("%s Final: %d-%d after %d rounds.\n",wins==3?"You win!":"Computer wins!",wins,losses,rounds);return 0;}