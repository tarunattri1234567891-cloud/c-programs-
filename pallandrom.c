#include<stdio.h>
int main(){
    int a ;
    printf("enter three digit no :");
    scanf("%d",&a);
    if(a%10==a/100){
        printf("yes it is a pallandrom");

    
    }
    else{
        printf("it is not pallandrom");
    }
    
}