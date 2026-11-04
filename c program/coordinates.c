#include<stdio.h>

int main(){
    int a,b ;
    printf("enter coordinates :");
    scanf("%d,%d",&a,&b);
    if(a>0&&b>0){
        printf("lies in first quadrant ");
    }
    else if (a<0&&b>0)
    {
        printf("lies in second quadrant ");
    }
    else if (a<0&&b<0)
    {
        printf("lies in third quadrant");
    }
    else if (a>0&&b<0)
    {
        printf("lies in fourth quadrant ");
    }
    
    return 0;
}