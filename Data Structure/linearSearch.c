#include<stdio.h>
int pos;
void read(int a[],int n){
    printf("Enter the elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

int search(int a[],int n,int val){
    for(int i=0;i<n;i++){
        if(val==a[i]){
            pos=i+1;
            return 1;
        }
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
    printf("Enter the value to be search :");
    scanf("%d",&val);
    int f=search(a,n,val);
    print(f,val);
    return 0;
}

