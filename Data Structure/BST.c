#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *l,*r;
}node;

node *root=NULL,*curr=NULL,*par,*p;

node *newnode(int val){
    p=(node*)malloc(sizeof(node));
    p->data=val;
    p->l=NULL;
    p->r=NULL;
    return p;
}

void insert(int val){
    p=newnode(val);
    curr=root;
    par=NULL;
    while(curr!=NULL){
        par=curr;
        if(val<curr->data)
            curr=curr->l;
        else
            curr=curr->r;
    }
    if(par==NULL){
        root=p;
    }else{
        if(val<par->data)
            par->l=p;
        else
            par->r=p;
    }
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->l);
        printf("%d\t",root->data);
        inorder(root->r);
    }
}
void preorder(node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->l);
        preorder(root->r);
    }
}
void postorder(node *root){
    if(root!=NULL){
        postorder(root->l);
        postorder(root->r);
        printf("%d\t",root->data);
    }
}

void search(int val){
    curr=root;
    while(curr!=NULL &&  curr->data!=val){
        if(val<curr->data)
            curr=curr->l;
        else
            curr=curr->r;
    }
    if(curr==NULL)
        printf("Element not found");
    else
        printf("Elemennt found");
}

void main()
{
    int val,ele,item;
    char ch;
    do{
    printf("\n\n1.INSERT\n2.INORDER Display\n3.PREORDER Display\n4.POSTORDER Display\n5.SEARCH FOR ELEMENT\n6.DELETE\n7.EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
        printf("Enter the element to be inserted : ");
        scanf("%d",&val);
        insert(val);
        break;
     case 2:
        printf("Inorder traversal is:\n");
        inorder(root); 
        break;
     case 3:
        printf("\nPreorder traversal is:\n");
        preorder(root); 
        break; 
     case 4:
        printf("\nPostorder traversal is:\n");
        postorder(root); 
        break;
    case 5: printf("Enter the val to be search :");
            scanf("%d",&val);
            search(val);
            break;
     default: printf("INVALID INPUT!!!!");
    }
  }while(ch!=7);
}