#include <stdio.h>
int main() {
    puts("Enter two numerator and two denominator: (n1 d1 n2 d2)");
    puts("denominator can't be 0! if it's 0,it will request you to enter again!");
    int n1,n2,d1,d2;
    do
    {
        puts("Enter:");
        scanf("%d %d %d %d",&n1,&d1,&n2,&d2);
    }while(!n1||!n2);
    float num1,num2;
    num1=(float) n1/d1;
    num2=(float) n2/d2;
    printf("num1+num2 = %f\nnum1-num2 = %f\nnum1*num2 = %f\nnum1/num2 = %f\n",
            num1+num2,num1-num2,num1*num2,num1/num2);
    return 0;
}