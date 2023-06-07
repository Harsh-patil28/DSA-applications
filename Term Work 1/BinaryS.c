#include<stdio.h>
#define MAX 1000
void read(int array[],int n)
{
    printf("enter the array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
}
int binary_search(int array[],int n,int key)
{
    int flag=0;
    int start=0,end=n-1,mid=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(array[mid]==key)
        {
            flag=1;
            break;
        }
        else if(array[mid]<key)
            start=mid+1;
        else
            end=mid-1;
    }
    if(flag==1)
        return mid;
    else
        return -1;
}
void main()
{
    int array[MAX];
    int n,key,flag;
    printf("enter the size:");
    scanf("%d",&n);
    read(array,n);
    printf("enter the key to be found:");
    scanf("%d",&key);
    int found_index=binary_search(array,n,key);
    if(found_index!=-1)
        printf("element found at index %d\n",found_index);
    else
        printf("element not found!");
}
