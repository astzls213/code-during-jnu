//
// Created by astzls on 2019-08-29.
//
#include "mystd.h"
maxheap createHeap(int cap){
    maxheap heap=(maxheap)malloc(sizeof(struct heap));
    heap->element=(int *)malloc(sizeof(int)*(cap+1));
    heap->element[0]=MAX;
    heap->size=0;
    heap->capacity=cap;
    return heap;
}
int isFull(maxheap heap){
    if(heap->size==heap->capacity)
        return 1;
    else
        return 0;
}
void insert(int value,maxheap heap){
    if(isFull(heap))
    {
        puts("maxheap is already full!!");
        return;
    }

    int k=++heap->size;
    for(;heap->element[k/2]<value;k/=2)
        heap->element[k]=heap->element[k/2];
    heap->element[k]=value;
}
maxheap deleteHeapMax(maxheap heap){
    if(isEmpty(heap))
    {
        puts("it's a empty heap! Delete failed!");
        return NULL;
    }

    heap->element[1]=heap->element[heap->size--];
    int tmp=heap->element[1];
    int parent,child;
    for(parent=1;parent<=heap->size;)
    {
        child=parent*2;
        if(child<=heap->size)
        {
            if (heap->element[child] > heap->element[child + 1]) {
                heap->element[parent] = heap->element[child];
                parent = child;
                continue;
            } else {
                heap->element[parent] = heap->element[child + 1];
                parent = child + 1;
                continue;
            }
        }
        else
        {
            heap->element[parent]=tmp;
            return heap;
        }
    }
    return heap;
}
int isEmpty(maxheap heap){
    if(heap->size==0)
        return 1;
    else
        return 0;
}


