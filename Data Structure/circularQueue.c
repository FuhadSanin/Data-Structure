#include<stdio.h>
#define size 10
int q[size],f=-1,r=-1;

int is_full(){
    if(f==(r+1)%size)
        return 1;
    else
        return 0;
}
int is_empty(){
    if(f==-1)
        return 1;
    else
        return 0;
}

void insert_rear(int ele){
    if(is_full()){
        printf("Queue is full");
    }else{
        r=(r+1)%size;
        if(f==-1)
            f=0;
        q[r]=ele;
    }
}

int delete_front(){
    int ele;
    if(is_empty()){
        printf("Queue is empty");
    }else{
        ele=q[f];
        if(f==r){
            f=-1;
            r=-1;
        }else{
            f=(f+1)%size;
        }
        return ele;
    }
}

void display(){
    if(is_empty()){
        printf("Queue is empty");
    }else{
        for(int i=f;i<=r;i++){
            printf("%d\t",q[i]);
        }
    }
}
