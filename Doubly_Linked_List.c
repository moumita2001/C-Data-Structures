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
        printf("\n4.Insertion after a node");
        printf("\n5.Insertion before a node");
        printf("\n6.Deletion at beginning");
        printf("\n7.Deletion at the end");
        printf("\n8.Deletion of a node");
        printf("\n9.Deletion of node after a given node");
        printf("\n10.Deletion of node before a given node");
        printf("\n11.Sort a list");
        printf("\n12.Display Linked List");
        printf("\n13.Delete the entire list");
        printf("\n14.Print the list in reversed order");
        printf("\n15.EXIT");
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
            case 4:insaft();
            printf("\n\nInserted after the Node");
            break;
            case 5:insbef();
            printf("\n\nInserted before the node");
            break;
            case 6:delbeg();
            printf("\n\nDeleted at the beginning");
            break;
            case 7:delend();
            printf("\n\nDeleted at the end");
            break;
            case 8:del_node();
            printf("\n\nDeleted the given node");
            break;
            case 9:delaft();
            printf("\n\nDeleted the node after the given node");
            break;
            case 10:delbef();
            printf("\n\nDeleted the node before the given node");
            break;
            case 11:sort();
            printf("\n\nLinked List Sorted");
            break;
            case 12:display();
            printf("\n\nThe Linked List is ");
            break;
            case 13:delete_list();
            printf("\n\nLinked List deleted ");
            break;
            case 14:displayrev();
            printf("\n\nReverse Linked List is ");
            break;
            case 15:exit(0);
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
void displayrev()
{
    struct Node *tail;
    tail=head;
    if(head==NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
    while(tail->next!=NULL)
        tail=tail->next;
    while(tail!=NULL)
    {
        printf("\n%d",tail->data);
        tail=tail->prev;
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
void insaft()
{
     struct Node *temp,*ptr;
    int n;
    printf("\nEnter data to be inserted after: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
    temp=head;
    while(temp->data!=n&&temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nElement not found");
    }
    else{
         ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("\nMemory allocation unsuccessfully");
        return;
    }
    printf("\nEnter data to be inserted: ");
    scanf("%d",&ptr->data);
    if(temp->next!=NULL)
        (temp->next)->prev=ptr;
     ptr->next=temp->next;
     ptr->prev=temp;
    temp->next=ptr;

    }
}
void insbef()
{
    struct Node *ptr,*temp;
    int n;
    printf("\nEnter data to be inserted after: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
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
            if(temp->prev!=NULL){
            (temp->prev)->next=ptr;
            }
            else
            head=ptr;
            ptr->next=temp;
            ptr->prev=temp->prev;
            temp->prev=ptr;
            return;
        }
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
         if(head->next==NULL)
                {
                    free(head);
                    head=NULL;
                    return;
                }
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
         if(head->next==NULL)
                {
                    free(head);
                    head=NULL;
                    return;
                }
        while(temp->next!=NULL)
            temp=temp->next;
        (temp->prev)->next=NULL;
        free(temp);
    }
}
void del_node()
{
    struct Node *temp;
    int n;
      temp=head;
    printf("Enter a node to be deleted: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }

    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            if(temp==head)
            {
                if(head->next==NULL)
                {
                    free(head);
                    head=NULL;
                    return;
                }
                head=head->next;
                head->prev=NULL;
            }
            }
            else if(temp->next==NULL)
            {
                (temp->prev)->next=NULL;
            }
            else{
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
            }
            free(temp);
            return;
        }
        temp=temp->next;
    }
void delaft()
{
    struct Node *temp,*ptr;

    int n;
    temp=head;
    printf("Enter a node to be deleted after: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            if(temp->next==NULL)
            {
                printf("\nDeletion not possible");
                return;
            }
            ptr=temp->next;
            temp->next=(temp->next)->next;
             (temp->next)->prev=temp;
           free(ptr);
        }
        temp=temp->next;
        return;
    }
}
void delbef()
{
    struct Node *temp,*ptr;
     int n;
    temp=head;
    printf("Enter a node to be deleted before: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            if(temp==head)
            {
                printf("\nDeletion not possible");
                return;
            }
            else if(temp==head->next)
            {
                ptr=temp->prev;
                head=head->next;
                head->prev=NULL;
            }

           else{
                 ptr=temp->prev;
            temp->prev=(temp->prev)->prev;
            (temp->prev)->next=temp;}
            free(ptr);
            return;
        }
        temp=temp->next;
    }
}
void sort()
{
    struct Node *ptr,*ptr1;
    int temp;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr1=ptr->next;
        while(ptr1!=NULL)
        {
            if(ptr->data>ptr1->data)
            {
                temp=ptr->data;
                ptr->data=ptr1->data;
                ptr1->data=temp;

            }
            ptr1=ptr1->next;
        }
        ptr=ptr->next;
    }

}
void delete_list()
{
     struct Node *ptr;
    if (head==NULL)
    {
        printf("\nList is Empty");
        return;
    }
    while(head!=NULL)
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }

}

