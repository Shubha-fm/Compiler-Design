/* Four distinct digits 1..6. Ten turns; seed may be given on command line. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
static uint32_t rng=24681357u;
static uint32_t next_random(void){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;}
int main(int argc,char **argv){char secret[5],guess[32];int used[7]={0};
if(argc>2)return 1;
if(argc==2){char *end;unsigned long v=strtoul(argv[1],&end,10);if(end==argv[1]||*end)return 1;rng=(uint32_t)v;if(!rng)rng=1;}
for(int i=0;i<4;i++){int d;do{d=1+(int)(next_random()%6u);}while(used[d]);used[d]=1;secret[i]=(char)('0'+d);}secret[4]=0;
puts("Mastermind: guess four DIFFERENT digits from 1 to 6. You have 10 turns. q quits.");
for(int turn=1;turn<=10;){printf("Attempt %d/10: ",turn);fflush(stdout);
if(scanf("%31s",guess)!=1||!strcmp(guess,"q")){puts("Game ended.");return 0;}
if(strlen(guess)!=4){puts("Enter exactly four digits.");continue;}
int seen[7]={0},valid=1;for(int i=0;i<4;i++){int d=guess[i]-'0';if(d<1||d>6||seen[d])valid=0;else seen[d]=1;}
if(!valid){puts("Digits must be distinct and between 1 and 6.");continue;}
int exact=0,present=0;for(int i=0;i<4;i++){if(guess[i]==secret[i])exact++;else if(strchr(secret,guess[i]))present++;}
printf("Exact=%d Misplaced=%d\n",exact,present);
if(exact==4){puts("You cracked the code!");return 0;}turn++;}
printf("Out of guesses. Secret: %s\n",secret);return 0;}