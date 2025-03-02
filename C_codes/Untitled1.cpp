#include<stdio.h>

int stringLength(char *ptr){

  int len=0;
  while(*ptr != '\0')
    {

    *ptr++;
    if(*ptr != ' ')
      {
    len++;
      }
    }

  return len;
}

int main(){

    char str[]="cse ekta bal";

    int length= stringLength(str);
    printf("length of the string =%d", length);
}

