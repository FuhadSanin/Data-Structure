#include <stdio.h>

void read(int a[],int n)
{
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void print(int a[],int n)
{
    printf("Sorted array : ");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void sort(int a[],int n) 
{
    for(int i=0;i<n-1;i++){
        int small=i;
        for(int j=i+1;j<n;j++){
            if(a[small] > a[j]){
                small = j;
            }
        }
        int temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }
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