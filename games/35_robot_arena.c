/* Five-round tactical robot arena. Opponent alternates attack / charge.
   Your commands: attack, guard, repair, q. */
#include <stdio.h>
#include <string.h>
int main(void){int hp=20,enemy=18,repairs=2,round=0;char action[32];
puts("Robot Arena: five rounds. attack=6 damage, guard=reduce hits, repair=+5 health. q quits.");
while(round<5&&hp>0&&enemy>0){printf("Round %d Hero=%d Robot=%d Repairs=%d\n",round+1,hp,enemy,repairs);
printf("Action: ");fflush(stdout);if(scanf("%31s",action)!=1||!strcmp(action,"q")){puts("Game ended.");return 0;}
int guard=0;if(!strcmp(action,"attack"))enemy-=6;
else if(!strcmp(action,"guard"))guard=1;
else if(!strcmp(action,"repair")){if(!repairs){puts("No repairs left.");continue;}repairs--;hp+=5;if(hp>20)hp=20;}
else{puts("Use attack/guard/repair.");continue;}
if(enemy<=0)break;int damage=round%2?3:5;if(guard)damage=1;hp-=damage;round++;}
printf("Final Hero=%d Robot=%d. ",hp,enemy);
puts(enemy<=0?"You win!":hp<=0?"Robot wins!":"Arena completed.");return 0;}
