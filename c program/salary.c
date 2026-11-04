#include<stdio.h>

int main(){
    float a,hra,da;
    printf("your basic salary :");
    scanf("%f",&a);
    if(a<=10000){
        hra=(1.0/5)*a;
        da=(4.0/5)*a;
        printf("total salary is %f",a+hra+da);
    }
    else if (a<=20000)
    {
        hra=(1.0/4)*a;
        da=(9.0/10)*a;
        printf("total salary is %f",a+hra+da);
    }
    else if (a>20000)
    {
        hra=(3.0/10)*a;
        da=(19.0/20)*a;
        printf("total salary is %f",a+hra+da);
    
    }
    return 0;
}