#include<stdio.h>
#define size 100
int s[size],top=-1;

void push(char val){
    s[++top]=val;
}

char pop(){
    return (s[top--]);
}

char peek(){
    return (s[top]);
}

int inprio(char token){
    switch(token){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 6;
    }
}

int stackprio(char token){
    switch(token){
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '^':return 5;
        case '(':return 0;
    }
}

void main(){
    char expe[10],ch,post[10],token;
    int j=0;
    printf("Enter the expression :");
    scanf("%[^\n]",expe);
    printf("\nInfix : %s\n",expe);
    for(int i=0;expe[i]!='\0';i++){
        token=expe[i];
        switch(token){
            case '(':   push(token);
                        break;
            case ')':   while((ch=pop())!='(')
                            post[j++]=ch;
                        break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':   while(top!=-1 && inprio(token)<stackprio(peek())){
                            ch=pop();
                            post[j++]=ch;
                        }
                        push(token);
                        break;
            default :   post[j++]=token;
                
        }
    }
    while(top!=-1){
        post[j++]=pop();
    }
    post[j]='\0';
    printf("Postfix : %s",post);
}