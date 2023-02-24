#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}node;

node *p,*f=NULL,*r=NULL,*curr;

node *newnode(int val){
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->link=NULL;
}

void insert(int val){
    p=newnode(val);
    if(f==NULL){
        f=r=p;
    }else{
        r->link=p;
        r=p;
    }
}

int delete(){
    curr=f;
    int val=f->data;
    f=curr->link;
    free(curr);
    return val;
}

void display(){
    if(f==NULL){
        printf("Queue is empty");
    }else{
        curr=f;
        while(curr!=NULL){
            printf("%d\t",curr->data);
            curr=curr->link;
        }
    }
}


int main(){
    int choice,val;
    do{
        printf("\n\n1.insert\n2.delete\n3.display\n4.exit\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value : ");
                    scanf("%d",&val);
                    insert(val);
                    break;
            case 2: if(f==NULL){
                        printf("Queue is empty");
                    }else{
                        val=delete();
                        printf("Deleted : %d",val);
                    }
                    break;
            case 3: display();
                    break;
        }
    }while(choice!=4);
    return 0;
}