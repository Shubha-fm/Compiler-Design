/* Binary codebreaker. Secret is 10110.
   Enter a 5-bit guess; Hamming-distance hints indicate differing bits. */
#include <stdio.h>
#include <string.h>
int main(void){const char *secret="10110";char s[32];int tries=0;
puts("Binary Codebreaker: guess a hidden five-bit code in six tries. q quits.");
while(tries<6){printf("Guess %d/6: ",tries+1);fflush(stdout);
if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
if(strlen(s)!=5){puts("Exactly five bits required.");continue;}
int valid=1,difference=0;for(int i=0;i<5;i++){if(s[i]!='0'&&s[i]!='1')valid=0;difference+=s[i]!=secret[i];}
if(!valid){puts("Only zeros and ones.");continue;}tries++;
if(!difference){printf("Code cracked in %d guesses!\n",tries);return 0;}
printf("Different bits: %d\n",difference);}
printf("Out of guesses. Code: %s\n",secret);return 0;}
