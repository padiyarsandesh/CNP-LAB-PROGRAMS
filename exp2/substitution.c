#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

/*Encryption*/
int main()
{
    char key[]="qwertyuiopasdfghjklzxcvbnm1234567890";
    char input[50];
    char encrypted[50];
    char decrypted[50];
    printf("Enter the input data: \n");
    scanf ("%[^\n]%*c", input);
    int len=strlen(input);
    int i;
    for( i=0;i<len;i++)
    {
        char c=input[i];
        if(c==' ')
        encrypted[i]=' ';
        else if(isalpha(c))
        {
        c=tolower(c);
        encrypted[i]=key[c-'a'];
        }
        else
        {
            encrypted[i]=key[c-'0'+26];
        }
        
    }
    encrypted[i]='\0';
    printf("\nThe encrypted data is : %s \n ",encrypted);
    

    /*decryption*/
    i=0;
    len=strlen(encrypted);
    for(i=0;i<len;i++)
    {
        
       char ch=encrypted[i];
        if(ch==' ')
        {
            decrypted[i]=' ';
        }
        else
        {
            int j=0;
            for(j=0;j<36;j++)
            {
                if(key[j]==ch)
                break;
            }
            if(j!=36)
            {
                if(!isdigit(ch))
                {
                    decrypted[i]=j+'a';
                }
                else
                {
                    
                    decrypted[i]=j-26+'0';
                }
            }
           
        }

    }
    printf("\nThe decrypted code is : %s \n",decrypted);


}