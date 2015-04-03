#include<stdio.h>
#include<string.h>

void push(char);
void pop();

char stack[400];
int top=0;

int main()
{
    int len, test_case,index=0,j=0;
    char expr[400];

    scanf("%d\n",&test_case);

    for(;j<test_case;j++)
    {
        scanf("%s\n",expr);
        len=strlen(expr);

        for(;index<len;index++)
        {
            if(expr[index]=='+'||expr[index]=='-'||expr[index]=='*'||expr[index]=='/'||expr[index]=='^')
                push(expr[index]);

            else if(expr[index]==')')
            {
                pop();
            }

            else if(expr[index]=='(')
                continue;

            else
                printf("%c",expr[index]);
        }
    }

    return 0;
}

void pop()
{
    if(top ==-1)
        return;
    else
    {
        printf("%c",stack[top]);
        top = top - 1; 
    }
}

void push(char x)
{
    if(top == 400)
        return;
    else
    {
        stack[++top]=x;
    }
}
