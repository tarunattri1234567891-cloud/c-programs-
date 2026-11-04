#include<stdio.h>
int main(){
    int a=0,b=1,c,n;
    printf("enter number of terms :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d " ,b);
        c=a+b;
        a=b;
        b=c;
    }
}