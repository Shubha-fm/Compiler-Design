/* Find three hidden words in a fixed 6x6 word search.
   Enter a word as a guess; q quits. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
static const char *grid[]={"PARSER","OTOKAN","CMODEL","PTRACE","ILOGIC","LEXERS"};
static const char *words[]={"PARSER","MODEL","LOGIC"};
int main(void){int found[3]={0},count=0;char guess[64];
puts("Word Search: find 3 words (horizontal, vertical, or diagonal). q quits.");
for(int i=0;i<6;i++)printf("%s\n",grid[i]);
while(count<3){printf("Word: ");fflush(stdout);if(scanf("%63s",guess)!=1||!strcmp(guess,"q")){puts("Game ended.");return 0;}
for(int i=0;guess[i];i++)guess[i]=(char)toupper((unsigned char)guess[i]);
int match=-1;for(int i=0;i<3;i++)if(!strcmp(guess,words[i]))match=i;
if(match<0){puts("Not a target word.");continue;}if(found[match]){puts("Already found.");continue;}
found[match]=1;count++;printf("Found %s (%d/3)\n",words[match],count);}
puts("All words found!");return 0;}
