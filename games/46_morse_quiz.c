/* Morse decoding quiz with five fixed letters. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){const char *codes[]={".-","-...","-.-.","-..","."};const char answers[]="ABCDE";char input[32];int score=0;
puts("Morse Quiz: identify A-E for each pattern. q quits.");
for(int i=0;i<5;i++){printf("Pattern %d: %s -> ",i+1,codes[i]);fflush(stdout);
if(scanf("%31s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
if(strlen(input)==1&&toupper((unsigned char)input[0])==answers[i]){score++;puts("Correct!");}
else printf("Answer: %c\n",answers[i]);}
printf("Score: %d/5\n",score);return 0;}