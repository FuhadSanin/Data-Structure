#include<stdio.h>
int pos;
void read(int a[],int n){
    printf("Enter the elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted array is :");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

int search(int a[],int n,int val){
    int top=0,bot=n-1;
    while(top<=bot){
        int mid=(top+bot)/2;
        if(a[mid]==val){
            pos=mid+1;
            return 1;
        }else if(val<a[mid])
            bot=mid-1;
        else
            top=mid+1;
    }
    return 0;
            
}

void print(int f,int val){
    if(f)
        printf("%d Found at pos : %d",val,pos);
    else
        printf("%d Not found",val);
}

int main(){
    int a[10],n,val;
    printf("Enter the size :");
    scanf("%d",&n);
    read(a,n);
    sort(a,n);
    printf("\nEnter the value to be search :");
    scanf("%d",&val);
    int f=search(a,n,val);
    print(f,val);
    return 0;
}

