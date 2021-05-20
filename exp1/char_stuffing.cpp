#include <stdio.h>
#include <string.h>
#define DLE 16
#define STX 2
#define ETX 3
int main() {
    char a[50]={DLE,STX};
    char b[50]={DLE,STX};
    char ch;
    int i=2;
    int counter=0;
    printf("ENTER DATA TO TRANSMIT:");   //ctrl+B is stx, ctrl+c is etx ctrl+p is dle
    do {
        scanf("%c",&ch);
        if(ch=='\n')
            break;
        counter++;
        a[i++]=ch;
        if(ch==DLE)
            a[i++]=DLE;
        if(counter==4)
        break;

    } while(ch!='\n');
    int j=2;
    do {
        scanf("%c",&ch);
        if(ch=='\n')
            break;
        
        b[j++]=ch;
        if(ch==DLE)
            b[j++]=DLE;
        

    } while(ch!='\n');
    a[i++]=DLE;
    a[i++]=ETX;
    b[j++]=DLE;
    b[j++]=STX;
    printf("AFTER BYTE STUFFING= ");
    for(int j=0;j<i;j++) {
        if(a[j]==DLE)
            printf("DLE");
        else if(a[j]==STX)
            printf("STX");
        else if(a[j]==ETX)
            printf("ETX");
        else
            printf("%c",a[j]);
    }
    printf(" ");
    for(int k=0;k<j;k++) {
        if(b[k]==DLE)
            printf("DLE");
        else if(b[k]==STX)
            printf("STX");
        else if(b[k]==ETX)
            printf("ETX");
        else
            printf("%c",b[k]);
    }
    printf("\n");
    printf("OUTPUT AT RECEIVER AFTER DESTUFFING= ");
    for(int j=2;j<i-2;j++) {
        if(a[j]==DLE) {
            j++;
            printf("DLE");
        }
        else if(a[j]==STX)
            printf("STX");
        else if(a[j]==ETX)
            printf("ETX");
        else
            printf("%c",a[j]);
    }
    for(int k=2;k<j-2;k++) {
        if(b[k]==DLE) {
            k++;
            printf("DLE");
        }
        else if(b[k]==STX)
            printf("STX");
        else if(b[k]==ETX)
            printf("ETX");
        else
            printf("%c",b[k]);
    }
    return 0;
}