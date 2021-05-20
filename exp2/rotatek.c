#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

/*Encryption*/
int main()
{
    char key[]="abcdefghijklmnopqrstuvwxyz";
    char input[50];
    char encrypted[50];
    char decrypted[50];
    int k;
    int l=strlen(key);
    printf("Enter the input data: ");
     scanf ("%[^\n]%*c", input);
    printf("\nEnter the key value: ");
    scanf("%d",&k);
    int len=strlen(input);
    int i;
    for(i=0;i<len;i++)
    {
        char ch=input[i];
        ch=tolower(ch);
        if(ch==' ')
        encrypted[i]=' ';
        else
        {
            encrypted[i]=key[(ch-'a'+k)%l];
        }
    }
    encrypted[i]='\0';
    printf("The encrypted code is: %s",encrypted);

    /*Decryption*/
    len=strlen(encrypted);
    for(i=0;i<len;i++)
    {
        if(encrypted[i]==' ')
        decrypted[i]=' ';
        else
        {
            int b=(encrypted[i]-'a'-k)%l;
            if(b>=0)
            decrypted[i]=key[b];
            else
            {
                decrypted[i]=key[b+l];
            }

        }
    }
    decrypted[i]='\0';
    printf("\nThe decrypted code is: %s \n",decrypted);
}