/* Three anagrams of compiler terms; fixed for reproducible tests. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
static const char *scramble[]={"RESRAP","NEKOT","REXEL"};
static const char *answer[]={"PARSER","TOKEN","LEXER"};
int main(void){char input[64];int score=0;puts("Anagram Challenge: unscramble each compiler term. q quits.");
for(int i=0;i<3;i++){printf("Puzzle %d: %s | Answer: ",i+1,scramble[i]);fflush(stdout);
if(scanf("%63s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
for(int j=0;input[j];j++)input[j]=(char)toupper((unsigned char)input[j]);
if(!strcmp(input,answer[i])){puts("Correct!");score++;}else printf("Answer: %s\n",answer[i]);}
printf("Final score: %d/3\n",score);return 0;}
