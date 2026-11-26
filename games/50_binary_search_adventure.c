/* Guess the hidden number using at most 7 questions. Hints encourage binary search. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){const int secret=73;int low=1,high=100;char s[32];puts("Binary Search Adventure: guess 1..100 in 7 attempts. q quits.");
for(int i=1;i<=7;){printf("Range [%d,%d], guess %d/7: ",low,high,i);fflush(stdout);
if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
char *end;long n=strtol(s,&end,10);if(end==s||*end||n<low||n>high){puts("Enter a number within the current range.");continue;}
if(n==secret){printf("Found the treasure in %d guesses!\n",i);return 0;}
if(n<secret){low=(int)n+1;puts("Go higher.");}else{high=(int)n-1;puts("Go lower.");}i++;}
puts("No attempts left. Treasure was at 73.");return 0;}