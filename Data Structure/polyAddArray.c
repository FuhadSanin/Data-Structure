#include<stdio.h>
int poly3[20][2];

int read(int poly[20][2]){
    int n;
    printf("\nEnter the no. of non-zero terms :");
    scanf("%d",&n);
    printf("\nEnter the elements :");
    for(int i=0;i<n;i++){
        printf("\nCoefficient : ");
        scanf("%d",&poly[i][0]);
        printf("Exponential : ");
        scanf("%d",&poly[i][1]);
    }
    return n;

}

int  add(int poly1[20][2],int poly2[20][2],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(poly1[i][1]==poly2[j][1]){
            poly3[k][0]=poly1[i][0]+poly2[i][0];
            poly3[k][1]=poly1[i][1];
            i++;j++;k++;
        }else if(poly1[i][1]>poly2[j][1]){
            poly3[k][0]=poly1[i][0];
            poly3[k][1]=poly1[i][1];
            i++;k++;
        }else{
            poly3[k][0]=poly2[i][0];
            poly3[k][1]=poly2[i][1];
            j++;k++;
        }
    }
    while(i<n1){
            poly3[k][0]=poly1[i][0];
            poly3[k][1]=poly1[i][1];
            i++;k++;
    }
    while(j<n2){
            poly3[k][0]=poly2[i][0];
            poly3[k][1]=poly2[i][1];
            j++;k++;
    }
    return k;
}

void display(int poly[20][2],int n)
{
    for(int i=0;i<n;i++)
    {
        if(poly[i][1]==0)
            printf("%d",poly[i][0]);
        else if(poly[i][1]==1)
            printf("%dx",poly[i][0]);
        else
            printf("%dx^%d",poly[i][0],poly[i][1]);
        if(i<n-1)
            printf(" + ");
    }
}



void main(){
    int poly1[20][2],poly2[20][2];
    printf("Enter Polynomial 1 :");
    int n1=read(poly1);
    printf("\nEnter Polynomial 1 :");
    int n2=read(poly2);
    printf("Poly 1 : ");
    display(poly1,n1);
    printf("\nPoly 2 : ");
    display(poly2,n2);
    int n3=add(poly1,poly2,n1,n2);
    printf("\nSum is :");
    display(poly3,n3);
}