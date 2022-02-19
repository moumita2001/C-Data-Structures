#include<stdio.h>
int main()
{
int a[20],n,i,key,index=0,mid,f,l;
printf("enter the size of the array: ");
scanf("%d",&n);
printf("Enter in sorted order");
for(i=0;i<n;i++)
{
printf("\nenter at a[%d]: ",i);
scanf("%d",&a[i]);
}
printf("\nenter the element to be search: ");
scanf("%d",&key);
f=0;
l=n-1;
while(f<=l)
{
mid=(f+l)/2;
if(key==a[mid])
{
    index=mid;
    break;
}
else if(key<a[mid])
{
l=mid-1;
}
else
{
f=mid+1;
}
}
if(index!=0)
{
    printf("The element is present in %d",index);
}
else
{
    printf("The element is not  present in the array");
}
return 0;
}
