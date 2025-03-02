#include <stdio.h>
int main()
{
    char string[100];
    char *p;
    int i, vowC=0,consC=0;

    printf("Enter any word: ");
    fgets(string, 100, stdin);

    p=string;
    for(i=string[0];*p!='\0' ;p++)
    {
        if(*p=='A' ||*p=='E' ||*p=='I' ||*p=='O' ||*p=='U'
        		||*p=='a' ||*p=='e' ||*p=='i' ||*p=='o' ||*p=='u' )
            vowC++;
        else if(*p==' ' || *p=='2' || *p=='3'|| *p=='4'|| *p=='5'|| *p=='6'|| *p=='7'|| *p=='8'|| *p=='9'|| *p=='1'|| *p=='0')
            consC=consC;
        else
            consC++;
    }

    printf("Number of Vowels in String: %d\n",vowC);
    printf("Number of Consonants in String: %d",consC-1);
    return 0;
}
