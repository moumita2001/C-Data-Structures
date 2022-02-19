# include<stdio.h>
# include<conio.h>
# include<process.h>
struct Node
{
    int data;
    struct Node *next;
}*head;
struct Node *tail=NULL;
int main()
{
    int ch;
    while(1)
    {
        printf("\n\n........MAIN MENU........\n");
        printf("\n1.Create a circular linked list");
        printf("\n2.Insertion at the end of circular linked list");
        printf("\n3.Insertion at the beginning of circular Linked List ");
        printf("\n4.Insertion after a given node");
        printf("\n5.Insertion before a given node");
        printf("\n6.Deletion at the end of circular linked list");
        printf("\n7.Deletion at the beginning of circular Linked List ");
        printf("\n8.Deletion after a given node");
        printf("\n9.Deletion of a node");
        printf("\n10.Delete the whole list");
        printf("\n11.sort the list");
        printf("\n12.Display Circular Linked List");
        printf("\n13.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create_cll();
            printf("\nCircular linked list created..");
            break;
            case 2:ins_end();
            printf("\nInserted at the end of circular linked list");
            break;
            case 3:ins_beg();
            printf("\nInserted at the beginning of circular linked list");
            break;
            case 4:ins_aft();
            printf("\nInserted after the given node of circular linked list");
            break;
            case 5:ins_bef();
            printf("\nInserted after the given node of circular linked list");
            break;
            case 6:del_end();
            printf("\nDeleted at the end of circular linked list");
            break;
            case 7:del_beg();
            printf("\nDeleted at the beginning of circular linked list");
            break;
            case 8:del_aft();
            printf("\nDeleted after the given node of circular linked list");
            break;
            case 9:del_node();
            printf("\n Deleted/;");
            break;
            case 10:del_list();
            printf("\nThe list is deleted:");
            break;
            case 11:sort_list();
            break;
            case 12:display();
            break;
            case 13:exit(0);
            break;
            default:printf("\nWrong choice");
        }
    }
}
void create_cll()
{
    struct Node *ptr,*temp;
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
    if(tail==NULL)
    {
       temp=tail=ptr;
       ptr->next=tail;
    }else{
        head=tail->next;
        tail->next=ptr;
        ptr->next=head;
        tail=ptr;
    }
    printf("\nWant to enter more(1 or 0)");
    scanf("%d",&ch);
}while(ch!=0);
}
void display()
{
    struct Node *ptr;
    if(tail==NULL)
    {
        printf("\nCircular Linked List is empty");
        return;
    }
    head=tail->next;
    ptr=head;
    do
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);

}
void ins_end()
{
    struct Node *ptr,*temp;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("\nMemory allocation unsuccessfully");
        return;
    }
    printf("\nEnter data:  ");
    scanf("%d",&ptr->data);
    if(tail==NULL)
    {
        tail=ptr;
        ptr->next=tail;

    }else{
    head=tail->next;
    ptr->next=tail->next;
    tail->next=ptr;
    tail=ptr;
    }

}
void ins_beg()
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
    if(tail==NULL)
    {
        tail=ptr;
        ptr->next=tail;
    }
    else
    {
        head=tail->next;
        ptr->next=tail->next;
        tail->next=ptr;
    }
}
void ins_aft()
{
   struct Node *temp,*ptr;
    int n;
    printf("\nEnter data to be inserted after: ");
    scanf("%d",&n);
    if(tail==NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
    head=tail->next;
    temp=head;
    while(temp->data!=n)
    {
        temp=temp->next;
    }
    if(temp==head&&temp->data!=n)
    {
        printf("Element not found");
        return;
    }
   else if(temp==tail&&temp->data==n){
         ptr=(struct Node *)malloc(sizeof(struct Node));
        if(ptr==NULL)
        {
            printf("\nMemory allocation unsuccessfully");
            return;
        }
        printf("\nEnter data to be inserted: ");
        scanf("%d",&ptr->data);
        ptr->next=tail->next;
        tail->next=ptr;
        tail=ptr;
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
     ptr->next=temp->next;
     temp->next=ptr;
    }
}
void ins_bef()
{
    struct Node *temp,*ptr,*prev;
    int n;
    printf("\nEnter data to be inserted before: ");
    scanf("%d",&n);
    if(tail==NULL)
    {
        printf("\nCircular Linked List is Empty");
        return;
    }
    head=tail->next;
    if(head->data==n)
    {
         ptr=(struct Node *)malloc(sizeof(struct Node));
        if(ptr==NULL)
        {
            printf("\nMemory allocation unsuccessfully");
            return;
        }
        printf("\nEnter data to be inserted: ");
        scanf("%d",&ptr->data);
        ptr->next=tail->next;
        tail->next=ptr;
        return;
    }
    temp=head->next;
    prev=tail->next;
    while(temp->data!=n&&temp!=NULL)
    {
        prev=prev->next;
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
        ptr->next=prev->next;
        prev->next=ptr;
    }
}
void del_end()
{
    struct Node *temp,*prev;
    if(tail==NULL)
    {
        printf("\nCircular Linked List is empty");
        return;
    }
    head=tail->next;
    prev=head;
    if(prev->next==head)
    {
        tail=NULL;
        free(head);
        return;
    }
    while(prev->next!=tail)
    {
        prev=prev->next;
    }
    temp=prev->next;
    prev->next=tail->next;
    tail=prev;
    free(temp);
}
void del_beg()
{
    struct Node *temp;
    if(tail==NULL)
    {
        printf("\nCircular Linked List is empty");
        return;
    }
    head=tail->next;
    if(head->next==head)
    {
        tail=NULL;
        free(head);
        return;
    }
    temp=head;
    head=head->next;
    tail->next=head;
    free(temp);
}
void del_aft()
{
    struct Node *temp,*prev;
    int n;
    if(tail==NULL)
    {
        printf("\nCircular Linked List is empty");
        return;
    }
    printf("Enter a node to be deleted : ");
    scanf("%d",&n);
    head=tail->next;
    temp=head->next;
    prev=head;
    if(head->data==n)
    {
        if(head->next==head)
        {
            printf("\nNo node after given node");
            return;
        }
        head->next=temp->next;
        free(temp);
    }
    else
    {
        while(temp!=head)
        {
            if (temp->data==n)
            {
                prev->next=temp->next;
                if(temp==tail)
                    tail=prev;
                free(temp);
                break;
            }
            temp=temp->next;
            prev=prev->next;
        }
        if(temp==head)
            printf("\nElement not found");
    }
}
void del_node()
{
    struct Node *temp,*prev;
    int n;
    if(tail==NULL)
    {
        printf("\nCircular Linked List is empty");
        return;
    }
    printf("Enter a node to be deleted : ");
    scanf("%d",&n);
    head=tail->next;
    if(head->data==n)
    {
        temp=head;
        if(temp->next==head)
        {
        tail=NULL;
        free(head);
        return;
        }
        tail->next=head->next;
        free(temp);
    }
    else
    {
        prev=head;
        temp=head->next;
        while(temp!=head)
        {
           if(temp->data==n)
           {
               prev->next=temp->next;
               if(temp==tail)
                tail=prev;
               free(temp);
                return;
           }
           temp=temp->next;
           prev=prev->next;

        }
    }
}
void del_list()
{
    struct Node *temp,*ptr;
    head=tail->next;
    temp=head->next;
    while(temp->next!=head)
    {
        ptr=temp;
        temp=temp->next;
        free(ptr);
    }
    if(temp->next==head)
    {
        free(head);
        free(temp);
        tail=NULL;
    }
}
void sort_list()
{
    struct Node *last,*temp;
    int n=1,i,j,k;
    head=tail->next;
    for(temp=head->next;temp!=head;temp=temp->next)
        n++;
    for(i=0;i<n-1;i++)
    {
    temp=head;
    for(j=0;j<n-i-1;j++)
    {
        if(temp->data>(temp->next)->data)
        {
            k=temp->data;
            temp->data=(temp->next)->data;
            (temp->next)->data=k;
        }
        temp=temp->next;
    }
}

}

