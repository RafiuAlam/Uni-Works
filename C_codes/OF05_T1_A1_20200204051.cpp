#include<bits/stdc++.h>
using namespace std;

char stk[30];
int top = -1;

void push(char x)
{
    stk[++top]= x;
}
char pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return stk[top--];
    }
}
int priority(char x)
{
    if( x== '(')
        return 0;
    if( x=='+' || x == '-')
        return 1;
    if( x=='*' || x == '/')
        return 2;
}
int main()
{
    char exp[30];
    char *e ,x;
    cout << "Enter the expression: " ;
    cin>> exp  ;
    e= exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            cout<<*e;
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while((x = pop()) != '(')
               {
                   cout<<x;
               }
        }
        else{
            while(priority(stk[top]) >= priority(*e))
            {
                cout<< pop();
            }
            push(*e);
        }
    }
    while(top !=-1)
    {
        cout<<pop();
    }

}
