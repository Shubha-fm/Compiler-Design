/* Open-addressing hash table supporting insert/find of unique identifiers.
Commands: ADD name, FIND name, END. At most 100 items. */
#include <stdio.h>
#include <string.h>
static char table[211][40];static unsigned hash(const char *s){unsigned h=2166136261u;for(;*s;s++)h=(h^(unsigned char)*s)*16777619u;return h%211u;}
static int slot(const char *s){unsigned x=hash(s);for(int i=0;i<211;i++){int k=(x+i)%211;if(!table[k][0]||!strcmp(table[k],s))return k;}return -1;}
int main(void){char cmd[8],s[40];while(scanf("%7s",cmd)==1){if(!strcmp(cmd,"END"))break;if(scanf("%39s",s)!=1)return 1;int k=slot(s);if(k<0)return 1;if(!strcmp(cmd,"ADD")){if(table[k][0])puts("EXISTS");else{strcpy(table[k],s);puts("ADDED");}}else if(!strcmp(cmd,"FIND"))puts(table[k][0]?"FOUND":"MISSING");else return 1;}return 0;}