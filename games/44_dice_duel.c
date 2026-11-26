/* Dice duel: deterministic xorshift32 rolls; score first to 20.
   Roll to gain a die, hold to bank your turn total. Opponent banks fixed 1 die. */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
static uint32_t seed=2463534242u;
static int roll(void){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return (int)(seed%6u)+1;}
int main(void){int you=0,bot=0,turn=0;char input[16];puts("Dice Duel: r=roll, h=hold, q=quit. Rolling a 1 loses turn points.");
while(you<20&&bot<20){int subtotal=0;printf("Scores you=%d bot=%d\n",you,bot);
while(1){printf("Turn subtotal=%d, action: ",subtotal);fflush(stdout);
if(scanf("%15s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
if(!strcmp(input,"h")){you+=subtotal;break;}
if(strcmp(input,"r")){puts("Use r or h.");continue;}
int die=roll();printf("You rolled %d\n",die);
if(die==1){subtotal=0;puts("Bust!");break;}subtotal+=die;if(you+subtotal>=20){you+=subtotal;break;}}
if(you>=20)break;int die=roll();printf("Computer rolled %d\n",die);if(die!=1)bot+=die;turn++;if(turn>200){puts("Round limit reached.");return 0;}}
puts(you>=20?"You win!":"Computer wins!");return 0;}
