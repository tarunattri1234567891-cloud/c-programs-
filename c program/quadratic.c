#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c ;
    float d;
    printf("quadratic is in form ax^2+bx+c ");
    printf("enter the values of a,b,c \n");
    scanf("%d %d %d",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if(d>0){
        printf("first root is %.2f \n" ,((-b)+sqrt(d))/2*a);
        printf("second root is %.2f",((-b)-sqrt(d))/2*a);
        
    }
    else if (d==0)
    {
        printf("equal roots are %.2f",(float)((-b)/2*a));
    
    }
    else if (d<0)
    {
        printf("no real roots ...");
    }
    
    


    return 0;
}