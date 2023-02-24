#include<stdio.h>

void heapify(int a[],int n,int i)
{
    int lar=i,l=2*i,r=(2*i)+1;
    while(l<=n && a[l]>a[lar])
        lar=l;
    while(r<=n && a[r]>a[lar])
        lar=r;
    if(lar!=i){
        int temp=a[i];
        a[i]=a[lar];
        a[lar]=temp;
        heapify(a,n,lar);
    }
}

void heapSort(int a[],int n)
{
    for(int i=n/2;i>=1;i--){
        heapify(a,n,i);
    }
    for(int i=n;i>=1;i--){
        int temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        n--;
        heapify(a,n,1);
    }
}


void main(){
    int a[10],n;
    printf("Enter the size :");
    scanf("%d",&n);
    printf("Enter the elements :");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heapSort(a,n);
    printf("Sorted array is : ");
    for(int i=1;i<=n;i++)
        printf("%d\t",a[i]);

}