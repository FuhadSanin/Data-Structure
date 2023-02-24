
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
    
}node;
node *head=NULL,*tail=NULL,*p,*curr;

node *newnode(int val){
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->next=NULL;
}

void insert_front(int val){
    p=newnode(val);
    if(head==NULL){
        head=tail=p;
    }else{
        p->next=head;
        head->prev=p;
        head=p;
    }
}

void insert_last(int val){
    p=newnode(val);
    if(head==NULL){
        head=tail=p;
    }else{
        p->prev=tail;
        tail->next=p;
        tail=p;
    }
}

void insert_any(int val){
    int pos;
    p=newnode(val);
    curr=head;
    printf("Enter the position :");
    scanf("%d",&pos);
    int i=1;
    while(i<pos-1){
        curr=curr->next;
        i++;
    }
    p->prev=curr;
    p->next=curr->next;
    curr->next->prev=p;
    curr->next=p;
    
}

int delete_front(){
    curr=head;
    int val=curr->data;
    head=curr->next;
    free(curr);
    return val;
    
}

int delete_last(){
    curr=tail;
    int val=curr->data;
    tail=curr->prev;
    tail->next=NULL;
    free(curr);
    return val;
}

int delete_any()
{
    int pos;
    curr=head;
    printf("Enter the position :");
    scanf("%d",&pos);
    int i=1;
    while(i<pos){
        curr=curr->next;
        i++;
    }
    int val=curr->data;
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    free(curr);
    return val;
}

void display(){
    if(head==NULL){
        printf("Linked list empty");
    }else{
        curr=head;
        while(curr!=NULL){
            printf("%d\t",curr->data);
            curr=curr->next;
        }
    }
}


int main(){
    int choice,ele,pos;
    do
    {
        printf("\n\n1.insert_front\n2.insert_rear\n3.insert_after\n4.delete_frontn\n5.delete_last\n6.delete_any\n7.display\n\nEnter the choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number to be inserted :");
                    scanf("%d",&ele);
                    insert_front(ele);
                    break;
            case 2: printf("Enter the number to be inserted :");
                    scanf("%d",&ele);
                    insert_last(ele);
                    break;
            case 3: printf("Enter the number to be inserted :");
                    scanf("%d",&ele);
                    insert_any(ele);
                    break;
            case 4: if(head==NULL){
                        printf("Linked list empty");
                    }else{
                        ele=delete_front();
                        printf("Deleted element is :%d",ele);
                    }
                    break;
            case 5: if(head==NULL){
                        printf("Linked list empty");
                    }else{
                        ele=delete_last();
                        printf("Deleted element is :%d",ele);
                    }
                    break;
            case 6: if(head==NULL){
                        printf("Linked list empty");
                    }else{
                        ele=delete_any();
                        printf("Deleted element is :%d",ele);
                    }
                    break;
            case 7: display();
                    break;
        }
    }while(choice!=8);
    return 0;
}