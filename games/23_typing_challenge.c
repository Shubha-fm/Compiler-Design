/* Five fixed typing prompts; score exact line matches, including spaces.
   A short correctness challenge, not a timed words-per-minute benchmark. */
#include <stdio.h>
#include <string.h>
static const char *sentences[]={"hello compiler","lexical analysis","finite automata","syntax tree","code generation"};
int main(void){char line[256];int score=0;puts("Typing Challenge: type each sentence exactly. q quits.");
for(int i=0;i<5;i++){printf("Prompt %d/5: %s\n> ",i+1,sentences[i]);fflush(stdout);
if(!fgets(line,sizeof line,stdin)){puts("Game ended.");return 0;}
size_t n=strcspn(line,"\r\n");line[n]=0;if(!strcmp(line,"q")){puts("Game ended.");return 0;}
if(!strcmp(line,sentences[i])){puts("Correct!");score++;}else puts("Mismatch.");}
printf("Typing score: %d/5\n",score);return 0;}
