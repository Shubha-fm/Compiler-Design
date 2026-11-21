/* Memory-match pairs on a fixed 2x4 board.
   Enter two positions (1..8) each turn; repeat until four pairs matched. */
#include <stdio.h>
static const char cards[8]={'A','C','B','D','C','A','D','B'};
static int found[8]={0};
static void show(void){for(int i=0;i<8;i++){printf("%c%s",found[i]?cards[i]:(char)('1'+i),i==3?"\n":i==7?"\n":" ");}}
int main(void){int pairs=0,turns=0;char token[32];puts("Memory Match: reveal two positions 1..8; q quits.");
while(pairs<4){show();printf("First position: ");fflush(stdout);
if(scanf("%31s",token)!=1||token[0]=='q'){puts("Game ended.");return 0;}
if(token[1]||token[0]<'1'||token[0]>'8'){puts("Invalid first choice.");continue;}
int a=token[0]-'1',b;if(scanf("%d",&b)!=1){puts("Invalid second choice.");return 0;}b--;
if(b<0||b>=8||a==b||found[a]||found[b]){puts("Choose two distinct hidden cards.");continue;}
turns++;printf("Cards: %c %c\n",cards[a],cards[b]);
if(cards[a]==cards[b]){found[a]=found[b]=1;pairs++;puts("Match!");}else puts("No match.");}
show();printf("All pairs matched in %d turns!\n",turns);return 0;}
