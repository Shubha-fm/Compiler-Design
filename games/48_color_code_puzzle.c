/* Crack the sequence RGBY in at most six tries.
   Output exact positions and colors elsewhere, counting duplicates correctly. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){const char secret[]="RGBY";char guess[32];puts("Color Code: guess 4 letters R,G,B,Y in six tries. q quits.");
for(int turn=1;turn<=6;){printf("Attempt %d: ",turn);fflush(stdout);
if(scanf("%31s",guess)!=1||!strcmp(guess,"q")){puts("Game ended.");return 0;}
if(strlen(guess)!=4){puts("Four colors required.");continue;}
int valid=1,used[4]={0},exact=0,near=0;
for(int i=0;i<4;i++){guess[i]=(char)toupper((unsigned char)guess[i]);
if(!strchr("RGBY",guess[i]))valid=0;}
if(!valid){puts("Only R,G,B,Y allowed.");continue;}
for(int i=0;i<4;i++)if(guess[i]==secret[i]){exact++;used[i]=1;}
for(int i=0;i<4;i++)if(guess[i]!=secret[i])for(int j=0;j<4;j++)
if(!used[j]&&guess[i]==secret[j]){near++;used[j]=1;break;}
printf("Exact=%d Misplaced=%d\n",exact,near);
if(exact==4){puts("Code cracked!");return 0;}turn++;}
puts("Out of tries. Code: RGBY");return 0;}