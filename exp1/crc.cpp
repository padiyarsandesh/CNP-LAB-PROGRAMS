#include<string.h>
#include<conio.h>
#include<stdio.h>
#define N strlen(g)

char t[128],cs[128];
char g[]="10001000000100001";
int a,e,c;
void fxor();
void crc();
int main()
{
	printf("\n Enter data polynomial: ");
	scanf("%s",t);
	printf("\n Generating polynomial is : %s",g);
	a=strlen(t);
	for(e=a;e<a+N-1;e++)
	t[e]='0';
	printf("\n Modified after appending N-1 zeros is : %s",t);
	crc();
	for(e=a;e<a+N-1;e++)
	t[e]=cs[e-a];
	printf(" \nThe crc to append is : %s",cs);
	printf("\n The final codeword is :%s ",t);
	printf("\n Test Error detection 0(yes) 1(no) ? :");
	scanf("%d",&e);
	if(e==0)
	{
		printf("Enter the position where error is to be inserted: ");
		scanf("%d",&e);
		t[e]=(t[e]=='0')?'1':'0';
		printf("Errorneous data : %s \n",t);
	}
	crc();
	printf("The calculated cheksum is %s \n",cs);
	for(e=0;(e<N-1) && (cs[e]!='1');e++);
	if(e<N-1)
	printf("Error detected.");
	else printf("No error detected");
	return 0;
}

void fxor()
{
	for(c=1;c<N;c++)
	cs[c]=((cs[c]==g[c]))?'0':'1';
}
void crc()
{
	for(e=0;e<N;e++)
	cs[e]=t[e];
	do{
		if(cs[0]=='1')
		fxor();
		for(c=0;c<N-1;c++)
		cs[c]=cs[c+1];
		cs[c]=t[e++];
	}while(e<=a+N-1);
}
