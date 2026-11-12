/* Apply GEN/KILL transfer to a bitmask: OUT = GEN union (IN minus KILL). */
#include <stdio.h>
#include <stdint.h>
int main(void){uint32_t in,gen,kill;if(scanf("%u%u%u",&in,&gen,&kill)!=3)return 1;printf("OUT=%u\n",gen|(in&~kill));return 0;}