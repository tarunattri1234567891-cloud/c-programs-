#include<stdio.h>

int main(){
    int a;
    printf("enter year: ");
    scanf("%d",&a);

    if((a%4==0 && a%100!=0) || a%400==0){
        printf("yeah it is a leap year...");
    }
    else {
    printf("no it is not leap year ..");
    }
    return 0;
}