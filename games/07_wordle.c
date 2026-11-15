/* Five-letter Wordle-style game with fixed secret 'logic'. Six attempts.
   Upper/lowercase guesses accepted; + exact, ? present elsewhere, - absent. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){const char *secret="logic";char guess[64];puts("Word Guess: find a five-letter secret in six tries. q quits.");
for(int turn=1;turn<=6;){printf("Guess %d/6: ",turn);fflush(stdout);
if(scanf("%63s",guess)!=1||!strcmp(guess,"q")){puts("Game ended.");return 0;}
if(strlen(guess)!=5){puts("Enter exactly five letters.");continue;}
int valid=1;for(int i=0;i<5;i++){if(!isalpha((unsigned char)guess[i]))valid=0;else guess[i]=(char)tolower((unsigned char)guess[i]);}
if(!valid){puts("Letters only.");continue;}
if(!strcmp(guess,secret)){puts("You win!");return 0;}
char marks[6]="-----";int used[5]={0};
for(int i=0;i<5;i++)if(guess[i]==secret[i]){marks[i]='+';used[i]=1;}
for(int i=0;i<5;i++)if(marks[i]!='+')for(int j=0;j<5;j++)if(!used[j]&&guess[i]==secret[j]){marks[i]='?';used[j]=1;break;}
printf("Clues: %s  (+ exact, ? elsewhere, - absent)\n",marks);turn++;}
printf("Out of tries. Word: %s\n",secret);return 0;}