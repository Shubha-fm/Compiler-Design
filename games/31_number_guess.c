/* Guess a reproducible secret from 1..100; q quits. */
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){int secret=57,attempts=0;char s[32];
if(argc>2)return 1;
if(argc==2){char *end;long v=strtol(argv[1],&end,10);if(end==argv[1]||*end||v<1||v>100)return 1;secret=(int)v;}
puts("Number Guess: find a number from 1 to 100. Enter q to quit.");
while(1){printf("Guess: ");fflush(stdout);if(scanf("%31s",s)!=1||(s[0]=='q'&&s[1]==0)){puts("Game ended.");return 0;}
char *end;long v=strtol(s,&end,10);if(end==s||*end||v<1||v>100){puts("Enter an integer 1..100.");continue;}
attempts++;if(v==secret){printf("Correct in %d guesses!\n",attempts);return 0;}
puts(v<secret?"Too low.":"Too high.");}}
