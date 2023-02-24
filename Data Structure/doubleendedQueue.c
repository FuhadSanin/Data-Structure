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
        if(r==0){
            f=-1;
            r=-1;
        }else
            f=(f+1)%size;
        return ele;
    }
}

void insert_front(int ele){
    if(is_full()){
        printf("Queue is full");
    }
    if(f==-1){
        f=0;
    }else{
        if(f==0)
            f=size-1;
        else
            f=f-1;
    }
    q[f]=ele;
}

int delete_rear(){
    int ele;
    if(is_empty()){
        printf("Queue is empty");
    }else{
        ele=q[r];
        if(f==r){
            f=-1;
            r=-1;
        }else{
            if(r==0)
                r=size-1;
            else
                r=r-1;
        }
        return ele;
    }
    
}

void display(){
    if(is_empty()){
        printf("Queue is empty");
    }else{
        for(int i=f;i!=r;i=(i+1)%size)
            printf("%d\t",q[i]);
        printf("%d",q[r]);
    }
}

int main(){
    int choice,ele;
    do
    {
        printf("\n\n1.insert_rear\n2.delete_front\n3.insert_front\n4.delte_rear\n5.display\n6.exit\n\nEnter the choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(!is_full()){
                        printf("Enter the number to be inserted :");
                        scanf("%d",&ele);
                        insert_rear(ele);
                    }else{
                        printf("Queue overflow");
                    }
                    break;
            case 2: if(!is_empty()){
                        ele=delete_front();
                        printf("Deleted element is : %d",ele);
                    }else{
                        printf("Queue underflow");
                    }
                    break;
            case 3: if(!is_full()){
                        printf("Enter the number to be inserted :");
                        scanf("%d",&ele);
                        insert_front(ele);
                    }else{
                        printf("Queue overflow");
                    }
                    break;
            case 4: if(!is_empty()){
                        ele=delete_rear();
                        printf("Deleted element is : %d",ele);
                    }else{
                        printf("Queue underflow");
                    }
                    break;
            case 5: display();
                    break;
        }
    }while(choice!=6);
    return 0;
}