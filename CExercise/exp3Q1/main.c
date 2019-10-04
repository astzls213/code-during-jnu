#include "header.h"
int main() {
    puts("Welcome astzls's experiment 3 and Question 1!");
    puts("Stack test:");
    puts("***********************************");
    puts("How many data do you want to enter?");
    puts("***********************************");
    int n, count;
    scanf("%d",&n);
    int del[n];
    Stack stack=createStack(n);
    // pop specified number in stack. like (9,5)
    puts("*********************************");
    puts("How many data do you want to pop?");
    puts("*********************************");
    scanf("%d",&count);
    puts("Data:");
    for(int i=0;i<count&&i<n;i++)
        scanf("%d",del+i);
    for(int k=0;k<count&&k<n;k++) {
        Stack tmp = (Stack) malloc(sizeof(struct node));
        tmp->next = NULL;
        while (stack->next->data != del[k]) {
            push(tmp, stack->next->data);
            pop(stack);
            if(stackEmpty(stack))
                break;
        }
        if(!stackEmpty(stack))
            pop(stack);
        while (!stackEmpty(tmp)) {
            push(stack, tmp->next->data);
            pop(tmp);
        }
    }
    puts("Now print stack:");
    while(!stackEmpty(stack))
        printf("%d\t",pop(stack));
    putchar('\n');

    puts("Queue test:");
    puts("***********************************");
    puts("How many data do you want to enter?");
    puts("***********************************");
    scanf("%d",&n);
    Queue queue=createQueue(n);

    puts("*************************************");
    puts("How many data do you want to dequeue?");
    puts("*************************************");
    scanf("%d",&count);
    puts("Data:");
    for(int i=0;i<count&&i<n;i++)
        scanf("%d",del+i);
    for(int k=0;k<count;k++) {
        int scale = queue->size;
        for (int i = 0; i != scale; i++) {
            if (queue->front->data != del[k]) {
                enQueue(queue, queue->front->data);
                deQueue(queue);
            }
            else
                deQueue(queue);
        }
    }
    puts("Now print queue:");
    while(!queueEmpty(queue))
        printf("%d\t",deQueue(queue));
    return 0;
}