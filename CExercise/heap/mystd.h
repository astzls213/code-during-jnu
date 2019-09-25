//
// Created by astzls on 2019-08-29.
//

#ifndef HEAP_MYSTD_H
#define HEAP_MYSTD_H

#endif //HEAP_MYSTD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 1000
//define heap
struct heap{
    int* element;
    int size;
    int capacity;
};
typedef struct heap* maxheap;
//base Operation
maxheap createHeap(int cap);
int isFull(maxheap heap);
void insert_MAX(int value,maxheap heap);
maxheap deleteHeapMax(maxheap heap);
int isEmpty(maxheap heap);
maxheap constructMaxHeap(maxheap maxHeap,int array[],int lenArray);