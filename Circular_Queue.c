#include<stdio.h>
#include<process.h>
int rear=-1,front=-1;
int main()
{
    int ch,cqueue[50],size;
     printf("\nEnter the size of Circular Queue ");
    scanf("%d",&size);
   while(1)
    {

        printf("\n\n1.To enqueue: ");
        printf("\n2.To dequeue: ");
        printf("\n3.Display queue: ");
        printf("\n4.Exit: ");
        printf("\nEnter Your Option: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Insert_cqueue(cqueue,size);
                   break;
            case 2:Delete_cqueue(cqueue,size);
                   break;
            case 3:display(cqueue,size);
                    break;
            case 4:printf("\n.....Exit.....");
                    exit(0);
            default: printf("\n!!!!!Wrong choice!!!!!!!");
        }
    }

    return 0;
}
void Insert_cqueue(int cqueue[],int size)
{
    int ele;
    if((front==0&&rear==size-1)||front==rear+1)
    {
        printf("\n.......OVERFLOW......");
    }
    else
    {
        if(rear==-1)
        {
           front=0;
           rear=0;
        }
        else if(rear==size-1)
            rear=0;
        else
            rear++;
        printf("\nEnter element to insert: ");
        scanf("%d",&ele);
       cqueue[rear]=ele;
    }
}
void Delete_cqueue(int cqueue[],int size)
{
    int item;
    if(front==-1)
        printf("\n......UNDERFLOW........");
    else
    {
        item=cqueue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        printf("\nItem deleted: %d",item);
    }


}
void display(int cqueue[],int size)
{
    int i;
    if (front==-1)
        return;
    else if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("\n%d",cqueue[i]);
    }
    else
    {
        for(i=front;i<size;i++)
            printf("\n%d",cqueue[i]);
        for(i=0;i<=rear;i++)
            printf("\n%d",cqueue[i]);
    }
}
