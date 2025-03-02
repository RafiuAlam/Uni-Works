#include<stdio.h>
void main(void)
{
    int a;
    int result[95];
    result[0]=55;
    for(a=2;a<=10;a++){
        result[a-1]=(a*3)+2;
    }
    for(a=0;a<8;a++)
        printf("%d \t",result[a]);

    printf("\n\n");

    for(a=1;a<8;a++)
    {
        result[a]=result[a+1];
        if(a==2){
            result[a]=98;
            }
    }
    for(a=0;a<8;a++)
        printf("%d \n",result[a]);
}
