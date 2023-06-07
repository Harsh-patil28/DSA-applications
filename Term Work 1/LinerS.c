//Linear search
#include<stdio.h>
void read(int array[],int n)
{ printf("enter the array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
}
void linear_search(int array[],int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(array[i]==key)
        {
            printf("%d found at index %d\n",key,i);
            count++;
        }
    }
    if(count==0)
	    printf("%d is not present in the array\n",key);
    else
	    printf("%d is present %d times in the array",key,count);
}
void main()
{
    int n,key;
    printf("enter the size:");
    scanf("%d",&n);
    int array[n];
    read(array,n);
    printf("enter the key:");
    scanf("%d",&key);
    linear_search(array,n,key);
}
