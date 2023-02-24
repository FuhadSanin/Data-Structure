#include <stdio.h>

void read(int a[],int n)
{
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}


void sort(int a[],int n) 
{
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(a[j] > key && j>=0){
            a[j+1] = a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

void print(int a[],int n)
{
    printf("Sorted array : ");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}


void main()
{
    int a[10],n;
    printf("Ente the array size :");
    scanf("%d",&n);
    read(a,n);
    sort(a,n);
    print(a,n);
}