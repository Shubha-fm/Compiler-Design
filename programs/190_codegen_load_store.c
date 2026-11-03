/* Generate pseudo assembly from a simple constant assignment: name integer. */
#include <stdio.h>
#include <ctype.h>
int main(void){char name[32];long value;if(scanf("%31s %ld",name,&value)!=2)return 1;if(!isalpha((unsigned char)name[0])&&name[0]!='_')return 1;for(int i=1;name[i];i++)if(!isalnum((unsigned char)name[i])&&name[i]!='_')return 1;printf("LOADI R0, %ld\nSTORE %s, R0\n",value,name);return 0;}