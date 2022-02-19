# include<stdio.h>
# define MAX 50
int main()
{
    int a[MAX],size,i;
    printf("\nEnter the Size of Array: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("\nEnter the Value at A[%d]: ",i);
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,size-1);
    printf("\nThe Sorted Array is:-");
    for(i=0;i<size;i++)
    {
        printf("\nA[%d]: %d\n",i,a[i]);
    }
    return 0;

}
void mergeSort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void merge(int a[],int p,int q,int r)
{
    int n1,n2,L[MAX],R[MAX],j,i,k=0;
    n1=q-p+1;//4-0+1=5
    n2=r-q;//9-4=5
    L[n1];
    R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[q+1+j];
    }
    k=0;
    j=0;
    L[n1]=9999;
    R[n2]=9999;
    for(i=p;i<=r;i++)
    {
        if(L[k]<=R[j])
        {
            a[i]=L[k];
            k++;
        }
        else
        {
            a[i]=R[j];
            j++;
        }
    }
}
