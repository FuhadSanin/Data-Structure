#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}node;
node *head=NULL,*p,*curr,*prev;

node *newnode(int val){
    p=(node *)malloc(sizeof(node));
    p->data=val;
    p->link=NULL;
}

void insert_front(int val){
    p=newnode(val);
    if(head==NULL){
        head=p;
    }else{
        p->link=head;
        head=p;
    }
}
void insert_last(int val){
    p=newnode(val);
    if(head==NULL){
        head=p;
    }else{
        curr=head;
        while(curr->link!=NULL){
            curr=curr->link;
        }
        curr->link=p;
    }
}

int delete_front(){
    curr=head;
    int val=curr->data;
    head=curr->link;
    free(curr);
    return val;
    
}
int delete_last(){
    curr=head;
    while(curr->link!=NULL){
        prev=curr;
        curr=curr->link;
    }
    int val=curr->data;
    prev->link=NULL;
    free(curr);
    return val;
}

void insert_any(int val,int pos){
    p=newnode(val);
    if(head==NULL){
        head=p;
    }else{
        curr=head;
        int i=1;
        while(i<pos){
            prev=curr;
            curr=curr->link;
            i++;
        }
        p->link=prev->link;
        curr=p;
    }
}

int delete_any(int pos){
    curr=head;
    int i=1;
    while(i<pos){
        prev=curr;
        curr=curr->link;
        i++;
    }
    int val=curr->data;
    prev->link=curr->link;
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
            curr=curr->link;
        }
    }
}
int main(){
    int choice,ele,pos;
    do
    {
        printf("\n\n1.insert_front\n2.insert_last\n3.insert_after\n4.delete_front\n5.delete_last\n6.delete_any\n7.display\n\nEnter the choice :");
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
                    printf("Enter the pos :");
                    scanf("%d",&pos);
                    insert_any(ele,pos);
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
                        printf("Enter the pos :");
                        scanf("%d",&pos);
                        ele=delete_any(pos);
                        printf("Deleted element is :%d",ele);
                    }
                    break;
            case 7: display();
                    break;
        }
    }while(choice!=8);
    return 0;
}