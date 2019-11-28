#include "mystd.h"

int main() {
    /*QuickSort
    int n;
    puts("Numbers of students:");
    while (scanf("%d",&n)!=1)
        puts("Invalid input, plz try again.");
    getchar();
    ElementType *list=initClass(n);
    clock_t start=clock();
    QuickSort(list,n);
    clock_t end=clock();
    printf("Sorting time: %lfms\n",(double)(end-start)/1000);
    rank(list,n);
    PrintScore(list,n);
    int flag=1;
    while(1){
        if(flag==1)
            puts("Want to check the Kth rank in class? (0 to terminated / positive to check now");
        else
            puts("Check again? (same format)");
        while (scanf("%d",&flag)!=1&&flag<0)
            puts("Unknown error, again.");
        if(flag==0)
            break;
        else{
            Print_rank_k(list,n,flag);
        }
    }*/


    int n;// numbers of students.
    puts("Numbers of students:");
    while (scanf("%d",&n)!=1)
        puts("Invalid input, plz try again.");
    getchar();
    Marks list=initMarks(n);
    clock_t start,end;
    if(list)
    {
        start=clock();
        RadixSort(list);
        end=clock();
        printf("Sorting time: %lfms\n",(double)(end-start)/1000);
        GiveRank(list);
        printScore(list);
    }
    int flag=1;
    while(1){
        if(flag==1)
            puts("Want to check the Kth rank in class? (0 to terminated / positive to check now");
        else
            puts("Check again? (same format)");
        while (scanf("%d",&flag)!=1&&flag<0)
            puts("Unknown error, again.");
        if(flag==0)
            break;
        else{
            print_Rank_K(list,flag);
        }
    }
    puts("^ ^Bye!~");
    return 0;
}