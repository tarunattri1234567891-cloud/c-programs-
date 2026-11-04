#include<stdio.h>
int main(){
    int a,r,sum=0,term,n,i;
    printf("enter your first term :");
    scanf("%d",&a);
    printf("enter common ratio:");
    scanf("%d",&r);
    printf("enter no of terms :");
    scanf("%d",&n);
    term=a;
    for (i=1;i<=n;i++){
        sum=sum+term;
        term=term*r;

    }   
    printf("sum of geometric series : %d",sum);
    return 0;                                                                                                                              
}