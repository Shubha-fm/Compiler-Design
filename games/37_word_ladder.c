/* Word ladder using an explicitly bounded dictionary of 3-letter words.
   Start CAT, goal DOG. A move must change exactly one character. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
static const char *dict[]={"CAT","COT","COG","DOG","DOT","DAT","BAT","BOT","BOG","BAG"};
static int allowed(const char *s){for(int i=0;i<10;i++)if(!strcmp(s,dict[i]))return 1;return 0;}
int main(void){char current[4]="CAT",s[32];int steps=0;
puts("Word Ladder: change CAT to DOG, one letter per step. q quits.");
while(strcmp(current,"DOG")){printf("Current: %s | Next word: ",current);fflush(stdout);
if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
for(int i=0;s[i];i++)s[i]=(char)toupper((unsigned char)s[i]);
if(strlen(s)!=3||!allowed(s)){puts("Not in the small dictionary.");continue;}
int differences=0;for(int i=0;i<3;i++)differences+=s[i]!=current[i];
if(differences!=1){puts("Change exactly one letter.");continue;}
strcpy(current,s);steps++;}printf("Ladder solved in %d steps!\n",steps);return 0;}
