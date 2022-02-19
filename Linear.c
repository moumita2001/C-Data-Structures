 #include<stdio.h>
int main()
{
int a[20],n,temp=0,x,i;
printf("enter the size of the array has to <= 20: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("enter at a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	printf("\nenter the element to be searched: ");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			temp=i;
			break;
		}
	}
	if(temp>=0)
		printf("The elements is present in index %d",temp);
	else
		printf("The element is not present in the array");
	return 0;
}

