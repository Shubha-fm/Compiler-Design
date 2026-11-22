/* Terminal Simon memory challenge: repeat a growing sequence of digits 1..4.
   Uses a fixed reproducible pattern. Enter one entire sequence each round. */
#include <stdio.h>
#include <string.h>
static const char *pattern="1324132413";
int main(void){char guess[64];puts("Simon Says: memorize and repeat the digits. 10 rounds, q quits.");
for(int n=1;n<=10;n++){printf("Round %d: %.*s\n",n,n,pattern);printf("Repeat: ");fflush(stdout);
if(scanf("%63s",guess)!=1||!strcmp(guess,"q")){puts("Game ended.");return 0;}
if(strlen(guess)!=(size_t)n||strncmp(guess,pattern,(size_t)n)){printf("Wrong sequence at round %d. Game over.\n",n);return 0;}
puts("Correct!");}
puts("Perfect memory: all 10 rounds complete!");return 0;}
