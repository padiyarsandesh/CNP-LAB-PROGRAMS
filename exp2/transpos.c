#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char *remove_white_spaces(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
          str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}
int main()
{
    /*ENCRYPTION*/
    char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char msg[100];
    char keyword[50];
    
    printf("Enter the Keyword: ");
    gets(keyword);
    int keylen=strlen(keyword);
    int *keyIdx=(int*)malloc((keylen+1)*sizeof(int));
    printf("\nEnter the message: ");
    scanf("%[^\n]%*c", msg);
    remove_white_spaces(msg);
    int msglen=strlen(msg);
    int dummy=keylen-(msglen%keylen);
    int rows=(dummy==keylen)?(msglen/keylen):(msglen/keylen +1);
    int it=0;
    for(int i=0;i<strlen(alpha);i++)
    {
        for(int j=0;j<strlen(keyword);j++)
        {
            if(alpha[i]==keyword[j])
            {
                keyIdx[j]=it++;
            }
        }
    }
    keyIdx[keylen]='\0';
    char **arr = (char **)malloc(rows * sizeof(char *));
    for (int i=0; i<rows; i++)
         arr[i] = (char *)malloc(keylen * sizeof(char));
    /*Printing the keyword Indexes */
    printf("\n");
    for(int i=0;i<keylen;i++)
    {
        printf("%d ",keyIdx[i]);
    }
    /* Adding dummy characters */
    for(int i=0;i<dummy;i++)
    {
        msg[i+msglen]='.';
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<keylen;j++)
        {
            arr[i][j]=msg[i*keylen+j];
        }
    }
    printf("\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<keylen;j++)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }

    msg[msglen+dummy]='\0';
    printf("The now of rows are %d and string after removing spaces is %s",rows,msg);
     char **encrypted = (char **)malloc(keylen * sizeof(char *));
    for (int i=0; i<keylen; i++)
         encrypted[i] = (char *)malloc((rows+1) * sizeof(char));
    for(int i=0;i<keylen;i++)    
    {
        for(int j=0;j<rows;j++)
        {
            encrypted[keyIdx[i]][j]=arr[j][i];
        }
        encrypted[keyIdx[i]][rows]='\0';
    } 
    printf("\nThe Encrypted Code is : ");
    for(int i=0;i<keylen;i++)
    printf("%s",encrypted[i]);
    free(keyIdx);
    free(arr);
    free(encrypted);
    
    /*DECRYPTION*/
    char data[100];
    char dec_key[50];
    printf("\nEnter the data to be decrypted: ");
    scanf("%[^\n]%*c", data);
    printf("Enter the key: ");
    scanf("%[^\n]%*c", dec_key);
    int len=strlen(data);
    int l=strlen(dec_key);
    if(len%l!=0)
    {
        printf("Invalid Key! ");
        return 0;
    }

    int *deckeyIdx=(int*)malloc((l+1)*sizeof(int));
    it=0;
    for(int i=0;i<strlen(alpha);i++)
    {
        for(int j=0;j<strlen(dec_key);j++)
        {
            if(alpha[i]==dec_key[j])
            {
                deckeyIdx[j]=it++;
            }
        }
    }
    deckeyIdx[l]='\0';
    printf("");
    for(int i=0;i<keylen;i++)
    {
        printf("%d ",deckeyIdx[i]);
    }
    rows=len/l;
    char **decrypted = (char **)malloc((rows) * sizeof(char *));
    for (int i=0; i<keylen; i++)
         decrypted[i] = (char *)malloc((l+1) * sizeof(char));
    int k=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<rows;j++)
        {
            decrypted[j][i]=data[k];
            k++;
        }
    }
    

    char output[100];
    k=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(decrypted[i][deckeyIdx[j]]!='.')
            output[k++]=decrypted[i][deckeyIdx[j]];
        }
    }
    output[k]='\0';
    printf("\nThe decrypted message is : %s",output);
    


free(deckeyIdx);
free(decrypted);


    



















    
    



}