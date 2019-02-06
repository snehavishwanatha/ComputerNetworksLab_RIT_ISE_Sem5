#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main()
{
int outputrate,drop=0,bsize,x,count=0,
input[10]={0},i=0,n,ch;
printf(" \n enter bucket size : ");
scanf("%d",&bsize);
printf("\n enter output rate :");
scanf("%d",&outputrate);
do{
printf("\n enter number of packets coming at second %d : ",i+1);
scanf("%d",&input[i]);
i++;
printf("\n enter 1 to continue or 0 to quit..........");
scanf("%d",&ch);
}while(ch);
n=i;
printf("\n second \t recieved \t sent \t dropped \t remained \n");
for(i=0;count || i<n;i++)
{
printf("%d",i+1);
printf(" \t %d\t ",input[i]);
printf(" \t %d\t ",MIN((input[i]+count),outputrate));
if((x=input[i]+count-outputrate)>0)
{
if(x>bsize)
{
count=bsize;
drop=x-bsize;
}
else
{
count=x;
drop=0;
}
}
else
{
drop=0;
count=0;
}
printf(" \t %d \t %d \n",drop,count);
}
return 0;
}

