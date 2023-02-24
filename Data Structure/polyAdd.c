#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coef;
    int expo;
    struct Node *link;
}node;
node *p,*poly1, *poly2, *poly3,*curr,*head=NULL,*tail=NULL,*p1,*p2,*p3;

node* newnode(){
    p=(node *)malloc(sizeof(node));
    p->link=NULL;
    return p;
}

void display(node *head){
    curr=head;
    while(curr!=NULL){
        if(curr->expo==0){
            printf("%d",curr->coef);
        }else if(curr->expo==1){
            printf("%dx",curr->coef);
        }else{
            printf("%dx^%d",curr->coef,curr->expo);
        }
        if(curr->link!=NULL){
            printf(" + ");
        }
        curr=curr->link;
    }
}

node* read(){
    int terms;
    head=NULL,tail=NULL;
    printf("\nEnter the no. non-zero terms :");
    scanf("%d",&terms);
    printf("Enter the numbers :");
    for(int i=0;i<terms;i++){
        node *p=newnode();
        printf("\nCoefficient : ");
        scanf("%d",&p->coef);
        printf("Exponential : ");
        scanf("%d",&p->expo);
        if(head==NULL){
            head=p;
            tail=p;
        }else{
            tail->link=p;
            tail=p;
        }
    }
    return head;
}

node* add(node *poly1,node *poly2){
    p1=poly1;
    p2=poly2;
    poly3=newnode();
    p3=poly3;
    
    while(p1!=NULL && p2!=NULL){
        if(p1->expo==p2->expo){
            p3->coef=p1->coef+p2->coef;
            p3->expo=p1->expo;
            p1=p1->link;
            p2=p2->link;
        }else if(p1->expo>p2->expo){
            p3->coef=p1->coef;
            p3->expo=p1->expo;
            p1=p1->link;
        }else{
            p3->coef=p2->coef;
            p3->expo=p2->expo;
            p2=p2->link;
        }
        if(p1!=NULL && p2!=NULL){
            p3->link=newnode();
            p3=p3->link;
        }
    }
    while(p1!=NULL){
            p3->link=newnode();
            p3=p3->link;
            p3->coef=p1->coef;
            p3->expo=p1->expo;
            p1=p1->link;
        
    }
    while(p2!=NULL){
            p3->link=newnode();
            p3=p3->link;
            p3->coef=p2->coef;
            p3->expo=p2->expo;
            p2=p2->link;
    }
    return poly3;
}

int main(){

    printf("Enter the polynomial 1 :");
    poly1=read();
    printf("Enter the polynomial 2 :");
    poly2=read();
    poly3=add(poly1,poly2);
    printf("\npolynomial 1:\t");
    display(poly1);
    printf("\npolynomial 2:\t");
    display(poly2);
    printf("\n\nSum is :\t");
    display(poly3);
    return 0;
}