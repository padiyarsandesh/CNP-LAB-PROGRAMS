#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char arr[50]="01111110",input[50],output[50];
printf("Enter the bitstream: \n");
scanf("%s",&input);
int i=0;
int j=8;
int count=0;
while(input[i]!='\0')
{
    if(input[i]=='1')
    count++;
    else 
    count=0;
    arr[j++]=input[i];
    if(count==5)
    {
        arr[j++]='0';
    }
    
    i++;

}
arr[j]='\0';
strcat(arr,"011111110");
printf("The bit stuffed output is %s \n",arr);


/* Defstuffing */
int n=strlen(arr);
count=0;
j=0;
for(int i=8;i<n-9;i++)
{
if(arr[i]=='1')
count++;
else 
count=0;
output[j++]=arr[i];
if(count==5)
{
   i++;
    count=0;
   

}
}
output[j]='\0';
printf("The destuffed output is %s \n",output);
return 0;

}

