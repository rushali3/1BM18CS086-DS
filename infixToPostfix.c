#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<ctype.h>
#define SIZE 100
int top=-1;
char s[SIZE];

void push(char val)
{
    if(top==SIZE-1)
        printf("stack full");
    else{
        top=top+1;
        s[top]=val;
    }
}

char pop()
{
    char val=' ';
    if(top==-1)
        printf("stack empty");
    else{
        val=s[top];
        top=top-1;
    }
    return val;
}

int priority(char op)
{
    if(op=='%' || op=='/' || op=='*' )
        return 1;
    else
        return 0;
}

void infixToPostfix(char in[],char post[])
{
    int i=0,j=0;
    while(in[i]!='\0')
    {
        if(in[i]=='(')
        {
             push(in[i]);
             i++;
        }
        else if(in[i]==')')
        {
            while(top!=-1 && s[top]!='(')
            {
                post[j]=pop();
                j++;
            }
            pop();
            i++;
        }
        else if(isdigit(in[i]) || isalpha(in[i]))
        {
            post[j]=in[i];
            i++;
            j++;
        }
        else if(in[i]=='%' || in[i]=='/' || in[i]=='-' || in[i]=='*' || in[i]=='+' )
        {
            while(top!=-1 && s[top]!='(' && (priority(s[top])>=priority(in[i])))
            {
                post[j]=pop();
                j++;
            }
            push(in[i]);
            i++;
        }
        else
            printf("invalid expression\n");
    }
    while(top!=-1 && s[top]!='(')
    {
        post[j]=pop();
        j++;
    }
    post[j]='\0';
}

int main()
{
    char infix[100],postfix[100];
    printf("enter infix expression: ");
    scanf("%s",infix);
    strcpy(postfix,"");
    infixToPostfix(infix,postfix);
    printf("postfix: ");
    printf("%s",postfix);
    getch();
    return 0;
}
