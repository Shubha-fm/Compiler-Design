/* A small deterministic turn-based battle: attack, defend or heal.
   Monster responds to every valid player turn. */
#include <stdio.h>
#include <string.h>
int main(void){int hp=30,enemy=25,potions=2,shield=0,round=0;char cmd[32];
puts("Dungeon Battle: defeat the monster. Commands: attack, defend, heal, q.");
while(hp>0&&enemy>0){printf("Hero HP=%d Monster HP=%d Potions=%d\n",hp,enemy,potions);printf("Action: ");fflush(stdout);
if(scanf("%31s",cmd)!=1||!strcmp(cmd,"q")){puts("Game ended.");return 0;}
shield=0;if(!strcmp(cmd,"attack")){enemy-=8;puts("You hit for 8.");}
else if(!strcmp(cmd,"defend")){shield=1;puts("You brace for the next attack.");}
else if(!strcmp(cmd,"heal")){if(!potions){puts("No potions left.");continue;}potions--;hp+=10;if(hp>30)hp=30;puts("You recovered health.");}
else{puts("Use attack/defend/heal.");continue;}
if(enemy<=0)break;int damage=5+(round%3);if(shield)damage=damage/2;hp-=damage;printf("Monster hits for %d.\n",damage);round++;}
puts(enemy<=0?"You defeated the monster!":"The monster defeated you.");return 0;}
