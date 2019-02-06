#include<stdio.h>
#include<stdlib.h>
#define xor(i,j)((i!=j)?'1':'0')
char divisor[18]={'\0'};

void crc(char a[60]){
  int i=0,j;
  while(a[i+16]!='\0'){
    if(a[i]!='0')
      for(j=0;j<=16;j++){
        a[i+j]=xor(a[i+j],divisor[j]);
        printf("%c",a[i+j]);
        if(j==16) printf("\n");
      }
    i++;
  }
}

void main(){
  char sent[60]={'\0'},receive[60]={'\0'},cc[17]={'\0'};
  int rl,sl,i=0,j=0;
  printf("Enter the 17 bit divisor\n");
  gets(divisor);
  divisor[18]='\0';
  puts(divisor);
  printf("Enter the sent data\n");
  gets(sent);
  while(sent[i]!='\0') i++;
  sl=i;
  while(j!=16) sent[i+(j++)]='0';
  printf("i %d and %d\n",i,j);
  sent[i+j]='\0';
  crc(sent);
  for(i=sl,j=0;i<sl+16;i++,j++)cc[j]=sent[i];
  cc[j]='\0';
  puts(cc);
  printf("Enter the received data\n");
  gets(receive);
  i=0;j=0;
  while(receive[i]!='\0') i++;
  rl=i;
  while(j!=16) receive[i+j]=cc[(j++)];
  receive[i+j]='\0';
  crc(receive);
  for(i=sl,j=0;i<sl+16;i++,j++)cc[j]=receive[i];
  cc[j]='\0';
  puts(cc);
  for(i=0;cc[i]!='\0';i++)
    if(cc[i]=='1'){
      printf("The data is corrupt\n");
      j=999;
      break;
    }
  if(j!=999)printf("Data transaction successful\n");
}
