#include <stdio.h>
int main(){
    printf("hello welcome to c \n");
    int a,b,c,d,e;
    double g;
    printf(" enter your first number: ");
    scanf("%d",&a);
    printf("enter your second no: ");
    scanf("%d",&b);
    c=a+b;
    printf("sum is: %d",c );
    d=a*b;
    printf(" \n multiplication is :%d ",d);
    e=a-b;
    printf("\n diffrence is :%d",e);
    g=a/b;
    printf(" \n division is :%f",g);
    return 0;
}
