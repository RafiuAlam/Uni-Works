#include<stdio.h>
#include<string.h>

int main(){

  FILE *file;
  int num,phone;
  char name[30];
  file=fopen("test.txt","a");

  char ch[50];
  if(file==NULL)
    printf("file doesn't exist");
  else
   {

    printf("file has been opened \n");

    printf("Enter the number of contract infos: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("Enter Name: ");
        scanf("%s",&name);
        printf("Enter Contract Number: ");
        scanf("%d",&phone);
        fprintf(file,"%s \t \t %d \n",name,phone);
    }
    printf("file is written successfully\n\n\n");
    fclose(file);

    printf("All contracts are shown bellow: \n");
    file=fopen("test.txt","r");

    while(!feof(file))
    {
    fgets(ch,50,file);
    printf("%s \n",ch);
    }
    fclose(file);
   }

    file=fopen("test.txt","r");
    char searchName[30];
    printf("Enter name to search: ");
    scanf("%s",&searchName);

    int res = strcmp(searchName,file);

    if (res==0)
        fprintf(file,"%s \t \t %d \n",name,phone);


    fclose(file);
   }

}
