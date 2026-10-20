#include <stdio.h>
#include <string.h>
#define MAX 100
int main(void){
 char names[MAX][64],name[64];int n=0,choice,found;
 do{
  puts("1 Insert  2 Search  3 Display  0 Exit");if(scanf("%d",&choice)!=1)break;
  if(choice==1||choice==2){
   printf("Name: ");if(scanf("%63s",name)!=1)break;found=-1;
   for(int i=0;i<n;i++)if(!strcmp(names[i],name)){found=i;break;}
   if(choice==2)printf(found<0?"Not found\n":"Found at index %d\n",found);
   else if(found>=0)puts("Already exists");
   else if(n<MAX){strcpy(names[n++],name);puts("Inserted");}
   else puts("Table full");
  }else if(choice==3)for(int i=0;i<n;i++)printf("%d %s\n",i,names[i]);
 }while(choice!=0);return 0;
}