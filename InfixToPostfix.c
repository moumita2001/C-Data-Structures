#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#define Max 50
int top=-1;
char stack[Max];
char pop();
int getpriority(char);
int main()
{
    char infix[Max],postfix[Max];
    printf("\nEnter Infix Expression");
    gets(infix);
    strcat(infix,")");
    infixtopostfix(infix,postfix);
    printf("\nPostfix Enpression: ");
    puts(postfix);
}
void infixtopostfix(char source[],char target[])
{
    int i=0,j=0,k;
    char temp;
    stack[++top]='(';
    puts(stack);
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while((stack[top]!='(')&&(top!=-1))
            {
                target[j]=pop();
                j++;
            }
            temp=pop();
            i++;
        }
         else if(isdigit(source[i]) || isalpha(source[i]))
      {
          target[j]=source[i];
          i++;
          j++;
        }
      else if(source[i]=='%'||source[i]=='/'||source[i]=='*'||source[i]=='+'||source[i]=='-')
      {
         while((stack[top]!='(')&&(top!=-1)&&(getpriority(source[i])<=getpriority(stack[top])))
         {
             target[j]=pop();
             j++;
         }
         push(source[i]);
         i++;
      }

    }
    while(stack[top]!='('&&top!=-1)
    {
        target[j]=pop();

        j++;
    }
    target[j]='\0';

}
void push(char val)
{

    if(top==Max-1)
    {
        printf("\n!!!!!!!Stack Overflow!!!!!!!!");
    }
    else
    {
        top++;
        stack[top]=val;
    }
}
char pop()
{
    char value;
    if(top==-1)
    {
        printf("\n!!!!!!Underflow!!!!!!!");

             }
    else
    {

        value=stack[top];
        top--;
    }
    return value;
}
int getpriority(char op)
{
    if(op=='/' || op == '*' || op=='%')
return 1;
else if(op=='+' || op=='–')
return 0;

}
