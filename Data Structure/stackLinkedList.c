#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}node;

node *p,*top=NULL,*curr;

node *newnode(int val){
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->link=NULL;
}

void push(int val){
    p=newnode(val);
    if(top==NULL){
        top=p;
    }else{
        p->link=top;
        top=p;
    }
}

int pop(){
    curr=top;
    int val=top->data;
    top=curr->link;
    free(curr);
    return val;
}
int peek(){
    return top->data;
}
void display(){
    curr=top;
    while(curr!=NULL){
        printf("%d\t",curr->data);
        curr=curr->link;
    }
}

int main(){
    int choice,val;
    do{
        printf("\n\n1.push\n2.pop\n3.peek\n4.display\n5.exit\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value : ");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: if(top==NULL){
                        printf("Stack is empty");
                    }else{
                        val=pop();
                        printf("Deleted : %d",val);
                    }
                    break;
            case 3: if(top==NULL){
                        printf("Stack is empty");
                    }else{
                        val=peek();
                        printf("Peel : %d",val);
                    }
                    break;
            case 4: display();
                    break;
        }
    }while(choice!=5);
    return 0;
}