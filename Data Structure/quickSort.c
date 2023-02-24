#include <stdio.h>

void read(int a[],int n)
{
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

int partition(int a[],int l,int r)
{
    int key=l,i=l+1,j=r;
    do{
        while(a[key]>a[i] && i<r)
            i++;
        while(a[key]<a[j] && j>l)
            j--;
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i<j);
    int temp = a[key];
    a[key] = a[j];
    a[j] = temp;
    
    return j;
}

void Qsort(int a[],int l,int r)
{
    if(l<r)
    {
        int pos = partition(a,l,r);
        Qsort(a,l,pos-1);
        Qsort(a,pos+1,r);
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
    Qsort(a,0,n-1);
    print(a,n);
}