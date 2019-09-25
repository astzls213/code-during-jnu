//
// Created by astzls on 2019-09-18.
//
#include "mystd.h"
void hanoi(int num, char A, char B, char C){// classical hanoi problem.
    if(num==1)
        printf("%c --> %c\n",A,C);
    else{
        hanoi(num-1,A,C,B);
        printf("%c --> %c\n",A,C);
        hanoi(num-1,B,A,C);
    }
}
