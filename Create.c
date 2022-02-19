#include<stdio.h>
#include<conio.h>
#include<process.h>
struct Node
{
    int data;
    struct Node *next;
}*head,*newnode,*temp,*ptr;
int main()
{
    int ch;
    while(1){
        printf("\n1.Create a list ");
        printf("\n2.Display ");
        printf("\n3.Exit ");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:create();
            break;
        case 2:display();
            break;
        case 3:exit(0);
        default: printf("\nWrong Choice");

        }
    }
}
void create()
{
    newnode=(struct Node *)malloc(sizeof(struct Node ));
    if(newnode==NULL)
    {
        printf("\nMemory allocation unsuccessfully");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
void display()
{
    ptr=head;
    while(ptr!=NULL){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
