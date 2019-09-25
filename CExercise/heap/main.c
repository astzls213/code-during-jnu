#include <stdio.h>
#include "mystd.h"
int main() {
    puts("now create a maxheap, how much capacity do you need?");
    int cap, value;;
    srand((unsigned)time(0));
    while(scanf("%d",&cap)==0)
        printf("You should enter a valid value, enter it again.");
    maxheap maxHeap=createHeap(cap);
    /*puts("now insert some value, enter your numbers of value.");
    int num=0;
    while(scanf("%d",&num)==0)
        printf("You should enter a valid value, enter it again.");
    puts("Enter value: ");
    for(int i=0;i<num;i++)
    {
        while(scanf("%d",&value)==0)
            printf("You should enter a valid value, enter it again.");

        insert_MAX(value,maxHeap);
    }
    puts("now heap: ");
    for(int i=1;i<=maxHeap->size;i++)
        printf("%d\t",maxHeap->element[i]);

    puts("now delete maximum in your heap.");
    deleteHeapMax(maxHeap);*/
    int array[10];
    for(int i=0;i<10;i++){
        array[i]=(i+1)*10;
    }
    maxHeap=constructMaxHeap(maxHeap,array,10);
    puts("now heap: ");
    for(int i=1;i<=maxHeap->size;i++)
        printf("%d\t",maxHeap->element[i]);
    return 0;
}