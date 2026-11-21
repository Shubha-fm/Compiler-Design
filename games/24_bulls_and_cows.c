/* Bulls and Cows with a fixed four-digit secret (distinct digits).
   Bulls match position; cows match digit in the wrong position. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){const char *secret="4271";char guess[32];puts("Bulls and Cows: guess a four-digit code with distinct digits in 10 attempts. q quits.");
for(int turn=1;turn<=10;){printf("Guess %d/10: ",turn);fflush(stdout);
if(scanf("%31s",guess)!=1||!strcmp(guess,"q")){puts("Game ended.");return 0;}
if(strlen(guess)!=4){puts("Enter four digits.");continue;}
int unique=1;for(int i=0;i<4;i++){if(!isdigit((unsigned char)guess[i]))unique=0;for(int j=0;j<i;j++)if(guess[i]==guess[j])unique=0;}
if(!unique){puts("Digits must be distinct.");continue;}
int bulls=0,cows=0;for(int i=0;i<4;i++){if(guess[i]==secret[i])bulls++;else for(int j=0;j<4;j++)if(i!=j&&guess[i]==secret[j]){cows++;break;}}
printf("Bulls=%d Cows=%d\n",bulls,cows);if(bulls==4){printf("Code cracked in %d guesses!\n",turn);return 0;}turn++;}
printf("Out of guesses. Secret: %s\n",secret);return 0;}
