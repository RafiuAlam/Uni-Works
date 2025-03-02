
#include<stdio.h>

int main(){
int a[]={40,50,60,70,80,90};
int *p1=a;
int *p2=a+5;
printf("Number of elements between two pointers are: %d", (p2-p1));
return 0;

}
