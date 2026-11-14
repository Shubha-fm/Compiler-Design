/* Hangman with fixed word options for reproducible games.
   Usage: ./hangman [0..5]; defaults to word 0. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char **argv){static const char *words[]={"compiler","automata","parser","syntax","register","language"};int idx=0;
if(argc>2){puts("Usage: hangman [0..5]");return 1;}
if(argc==2){char *end;long n=strtol(argv[1],&end,10);if(end==argv[1]||*end||n<0||n>5){puts("Choose a word index 0..5");return 1;}idx=(int)n;}
const char *word=words[idx];int guessed[26]={0},mistakes=0;
puts("Hangman: guess letters a-z (6 wrong guesses allowed). Type q to quit.");
while(mistakes<6){int missing=0;for(const char *p=word;*p;p++){if(guessed[*p-'a'])putchar(*p);else{putchar('_');missing++;}}printf(" | wrong=%d/6\n",mistakes);
if(!missing){puts("You win!");return 0;}
char token[32];printf("Guess: ");fflush(stdout);if(scanf("%31s",token)!=1||token[0]=='q'){puts("Game ended.");return 0;}
if(!isalpha((unsigned char)token[0])||token[1]){puts("Enter one letter.");continue;}char c=(char)tolower((unsigned char)token[0]);
if(c<'a'||c>'z'){puts("Enter a-z.");continue;}if(guessed[c-'a']){puts("Already guessed.");continue;}guessed[c-'a']=1;
if(!strchr(word,c)){mistakes++;puts("Incorrect.");}else puts("Correct.");}
printf("Game over. Word: %s\n",word);return 0;}