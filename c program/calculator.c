# include<stdio.h>
int main(){
    // int p,t,r;
    // float b;
    //  p= 100;
    //  t=2;
    //  r=10;
    // b=32+a*1.8;
    // b=8;
    // printf("enter your numbers ");
    // scanf("%d,%d",&a,&b);
    // printf("area will be %d ",a*b);
    // printf("volume of cylinder is %f",3.14*a*a*b);
    // printf("temp is %f ",b);
    // printf("simple interest is %d",p*t*r/100);



    int a,b,c,d,e,f,g;
    printf("enter first no: ");
    scanf("%d",&a);
    printf("enter second no: ");
    scanf("%d",&b);
    printf("press 1 for add\n 2 for subt\n 3 for mult\n 4 for div\n");
    d=a+b;
    e=a-b;
    f=a*b;
    g=a/b;
    printf("press: ");
    scanf("%d",&c);
    switch(c){
        case 1:
        printf("sum is : %d",d);
        break;
        case 2:
        printf("diff is : %d",e);
        break;
        case 3:
        printf("mult is : %d",f);
        break;
        case 4:
        printf("div is : %d",g);
        break;
        default:
        printf("error");
    }
    return 0;
}