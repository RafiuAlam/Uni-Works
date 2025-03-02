#include<stdio.h>
void sum(int x, int y)
{
    int add=x+y;
    printf("%d",add);
}
void sum(int x, int y, int z)
{
    int add=x+y+z;
    printf("%d",add);
    }

int main()
{
    sum(4,6);
    sum(5,7,2);

    return 0;
}
