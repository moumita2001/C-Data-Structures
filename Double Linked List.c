#include<stdio.h>
#include<process.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next,*prev;
};
struct Node *head=NULL;
int main()
{
    int ch;
    while(1){
        printf("\n......MAIN MENU.....\n");
        printf("\n1.Create List");
        printf("\n2.Insertion at beginning");
        printf("\n3.Insertion at the end");
        printf("\n4.Deletion at beginning");
        printf("\n5.Deletion at the end");
        printf("\n6.Display Linked List");
        printf("\n7.EXIT");
        printf("\n\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                printf("\n\nLinked List created");
            break;
            case 2:insbeg();
             printf("\n\nInserted at the beginning");
            break;
            case 3:insend();
             printf("\n\nInserted at the end");
            break;
            case 4:delbeg();
            printf("\n\nDeleted at the beginning");
            break;
            case 5:delend();
            printf("\n\nDeleted at the end");
            break;
            case 6:display();
            break;
            case 7:exit(0);
            default: printf("\nWrong choice");
        }
    }
}
void create()
{
    struct Node *temp,*ptr;
    int ch;
    do{
        ptr=(struct Node *)malloc(sizeof(struct Node));
        if(ptr==NULL)
        {
            printf("\nMemory allocation unsuccessfully");
            return;
        }
        printf("\nEnter data:  ");
        scanf("%d",&ptr->data);
        ptr->next=NULL;
        if(head==NULL)
        {
            ptr->prev=NULL;
           temp=head=ptr;
        }
        else
        {
            temp->next=ptr;
            ptr->prev=temp;
            temp=temp->next;
        }
    printf("\nWant to enter more(1 or 0)");
    scanf("%d",&ch);
    }while(ch!=0);
}
void display()
{
    struct Node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("\nLinked List is empty");

    }
    while(temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}
void delbeg()
{
    struct Node *ptr;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    else
    {
        head=head->next;
        head->prev=NULL;
    }
}
void delend()
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        (temp->prev)->next=NULL;
        free(temp);
    }
}
void insend()
{
    struct Node *ptr,*temp;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("\nMemory allocation unsuccessfully");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(head==NULL)
    {
        ptr->prev=NULL;
        head=ptr;
    }
    else{
            temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
        ptr->prev=temp;
    }
}
void insbeg()
{
    struct Node *ptr,*temp;
    temp=head;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("\nMemory allocation unsuccessfully");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(head==NULL)
    {
        ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
}
