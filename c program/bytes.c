#include<stdio.h>

int main(){
    float a,b;
    printf("enter number in bytes :");
    scanf("%f",&a);
    b=a/1024;
    printf("%f kilobytes",b);
    
    return 0;
}