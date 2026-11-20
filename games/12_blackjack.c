/* Simplified blackjack with seeded draws. No gambling or betting. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
static uint32_t rng=1357911u;
static uint32_t rand32(void){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;}
static int draw(void){return 1+(int)(rand32()%13u);}
static int score(const int *cards,int n){int total=0,aces=0;for(int i=0;i<n;i++){int c=cards[i];if(c==1){aces++;total++;}else total+=c>10?10:c;}while(aces--&&total+10<=21)total+=10;return total;}
int main(int argc,char **argv){int player[32],dealer[32],np=2,nd=2;char cmd[16];
if(argc>2)return 1;
if(argc==2){char *end;unsigned long s=strtoul(argv[1],&end,10);if(end==argv[1]||*end)return 1;rng=(uint32_t)s;if(!rng)rng=1;}
player[0]=draw();dealer[0]=draw();player[1]=draw();dealer[1]=draw();
printf("Blackjack: hit (h), stand (s), or quit (q). Dealer shows %d.\n",dealer[0]);
while(score(player,np)<21){printf("Your total: %d. Action: ",score(player,np));fflush(stdout);
if(scanf("%15s",cmd)!=1||!strcmp(cmd,"q")){puts("Game ended.");return 0;}
if(!strcmp(cmd,"s")||!strcmp(cmd,"stand"))break;
if(strcmp(cmd,"h")&&strcmp(cmd,"hit")){puts("Enter h, s, or q.");continue;}
if(np>=32)return 1;
player[np++]=draw();}
int ps=score(player,np);if(ps>21){printf("Bust! Your total: %d. Dealer wins.\n",ps);return 0;}
while(score(dealer,nd)<17){if(nd>=32)return 1;dealer[nd++]=draw();}
int ds=score(dealer,nd);printf("Your total: %d | Dealer total: %d\n",ps,ds);
if(ds>21||ps>ds)puts("You win!");else if(ps==ds)puts("Push (tie).");else puts("Dealer wins.");return 0;}