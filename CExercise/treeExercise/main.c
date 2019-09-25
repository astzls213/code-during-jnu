#include <stdio.h>
#include "mystd.h"
int main() {
    Tree BT;
    int num,value;
    printf("Now making a binary tree, how many values do you want to enter?\n");
    scanf("%d",&num);
    BT=maketree(num);
    /*puts("do you want to insert a value? 1 for yes; 0 for no.");
    int judge;
    scanf("%d",&judge);
    if(judge)
    {
        int value;
        printf("value: ");
        scanf("%d",&value);
        insert(BT,value);
    }*/
    pretravel(BT);
    /*puts("do you want to delete a value? answer like above.");
    printf("value: ");
    scanf("%d",&value);
    delete(BT,value);
    pretravel(BT);*/
    rightLeftRotation(BT);
    pretravel(BT);
    puts("Bye!~");
    getchar();
    return 0;
}