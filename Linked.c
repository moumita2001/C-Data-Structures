#include<stdio.h>
#include<process.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
int main()
{
    int ch;
    printf("\nCreate a linked list: ");
    create();
    while(1){
        printf("\n......MAIN MENU.....\n");
        printf("\n1.Insertion at beginning");
        printf("\n2.Insertion at the end");
        printf("\n3.Insertion after a given node");
        printf("\n4.Deletion at beginning");
        printf("\n5.Deletion at the end");
        printf("\n6.Deletion after a given node");
        printf("\n7.Display");
        printf("\n8.Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insbeg();
                    break;
            case 2:insend();
                    break;
            case 3:insaft();
                    break;
            case 4:delbeg();
                    break;
            case 5:delend();
                    break;
            case 6:delaft();
                    break;
            case 7:display();
                    break;
            case 8:exit(0);
            default:printf("\n\nWrong choice");
        }
    }
}
void create()
{
    struct Node *ptr,*temp;
    int ch;
    do
    {
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
            head=ptr;
            temp=head;
        }
        else
        {
            temp->next=ptr;
            temp=ptr;
        }
        printf("\n\nWant to enter more(press 1 or press 0): ");
        scanf("%d",&ch);
    }while(ch!=0);
    printf("\n\nLinked List created.");;
}
void insbeg()
{
    struct Node *ptr;
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
        head=ptr;
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
    printf("\n Inserted at the beginning. \n");
}
void insend()
{
    struct Node *ptr,*temp;
    temp=head;
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
        head=ptr;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
    }
    printf("\n Inserted at the end. \n");
}
void insaft()
{
    struct Node *temp,*ptr;
    int n,found=0;
    if(head==NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
    printf("\nEnter data to be inserted after: ");
    scanf("%d",&n);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            ptr=(struct Node *)malloc(sizeof(struct Node));
            if(ptr==NULL)
            {
                printf("\nMemory allocation unsuccessfully");
                return;
            }
            printf("\nEnter data to be inserted: ");
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            ptr->next=temp->next;
            temp->next=ptr;
            break;
        }
        temp=temp->next;
    }
    printf("\n Inserted after the given node. \n");

}
void delbeg()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    else
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
    printf("\n Deleted at the beginning. \n");
}
void delend()
{
    struct Node *ptr,*prev;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    else
    {
        prev=head;
        ptr=head;
        while(ptr->next!=NULL)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=NULL;
        free(ptr);
    }
    printf("\n Deleted at the end. \n");
}
void delaft()
{
    struct Node *ptr,*prev,*temp;
    int n;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    printf("Enter a node to be deleted after : ");
    scanf("%d",&n);
    temp=head->next;
    prev=head;
    while(temp!=NULL)
    {
        if(prev->data==n)
        {
        prev->next=temp->next;
        free(temp);
        break;
        }
        prev=prev->next;
        temp=temp->next;
    }
    printf("\n Deleted after the given node. \n");
}
void display()
{
    struct Node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    printf("\n\nThe list is: ");
    while(temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }

}
