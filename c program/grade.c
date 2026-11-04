#include<stdio.h>
int main(){
    int g ;
    printf("enter grade :");
    scanf("%d",&g);
    if(g>=80&& g<100) printf("gradeA");
    else if(g>=60&& g<80) printf("gradeB");
    else if(g>=40&& g<60) printf("gradeC");
    else printf("fail..");
    return 0;


}