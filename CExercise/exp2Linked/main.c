#include "linkedHead.h"
int main() {
    printf("Now I help you create a linked-list, "
           "how many elements do you want to add?\n");
    int num;
    while (scanf("%d",&num)!=1&&num<1)
        printf("Invalid input.Again!");
    List myList=NewList(num);
    bool flag=true;
    while(flag){
        puts("*******************************************************************************");
        puts("1.delete value at a specific location.    2.insert value at a specific location");
        puts("3.delete entire list.                     4.print list");
        puts("5.exit");
        puts("*******************************************************************************");
        int judge;
        while (scanf("%d",&judge)!=1&&(judge>3||judge<1))
            printf("Invalid input.Again!");
        switch(judge){
            case 1:
                puts("which position do you want to delete?");
                int del;
                scanf("%d",&del);
                printf("%d has been deleted!\n",delete(del,myList));
                break;
            case 2:
                puts("which position do you want to add?");
                int ins,val;
                scanf("%d",&ins);
                puts("what about your value?");
                scanf("%d",&val);
                insert(val,ins,myList);
                printf("%d has been inserted!\n",val);
                break;
            case 3:
                freeList(myList);
                puts("Bye!~");
                return 0;
            case 4:
                printList(myList);
                break;
            case 5:
                flag=false;
                break;
        }
        if(!flag)
            break;
    }
    return 0;
}