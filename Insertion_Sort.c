# include<stdio.h>
# include<process.h>
# define MAX 50
void insertionSort(int[],int);
void main()
{
    int a[MAX],size,i;
    printf("\nEnter the Size of Array: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("\nEnter the Value at A[%d]: ",i);
        scanf("%d",&a[i]);
    }
    insertionSort(a,size);
    exit(0);
    return 0;

}
void insertionSort(int a[],int size)
{
    int i,temp,j;
    for(i=1;i<size;i++)
    {
        j=i-1;
        temp=a[i];
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;

    }

    printf("\nThe Sorted Array is:-");
    for(i=0;i<size;i++)
    {
        printf("\na[%d]: %d\n",i,a[i]);
    }
}
