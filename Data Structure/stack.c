#include <stdio.h>
#define size 10
int s[size],top=-1,ele;

 int is_full()
 {
     if(top==size)
        return 1;
    else
        return 0;
 }
 
 int is_empty()
 {
    if(top==-1)
        return 1;
    else
        return 0;
 }

void push(ele)
{
    if(is_full()){
        printf("Stack overflow");
    }else{
        top=top+1;
        s[top]=ele;
    }
}

int pop()
{
    if(is_empty()){
        printf("Stack underflow");
    }else{
        ele=s[top];
        top=top-1;
        return ele;
    }
}

int peek()
{
    if(is_empty()){
        printf("Stack underflow");
    }else{
        return(s[top]);
    }
}

void display()
{
    if(is_empty()){
        printf("Stack underflow");
    }else{
        for(int i=0;i<=top;i++){
            printf("%d\t",s[i]);
        }
    }
}

int main()
{
    int choice,ele;
    do
    {
        printf("\n\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n\nEnter the choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(!is_full()){
                        printf("Enter the number to be inserted :");
                        scanf("%d",&ele);
                        push(ele);
                    }else{
                        printf("Stack overflow");
                    }
                    break;
            case 2: if(!is_empty()){
                        ele=pop();
                        printf("Deleted element is : %d",ele);
                    }else{
                        printf("Stack underflow");
                    }
                    break;
            case 3: if(!is_empty()){
                        ele=peek();
                        printf("Peek element : %d",ele);
                    }else{
                        printf("Stack underflow");
                    }
                    break;
            case 4: display();
                    break;
        }
    }while(choice!=5);
    return 0;
}