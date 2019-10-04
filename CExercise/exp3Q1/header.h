//
// Created by astzls on 2019-10-04.
//

#ifndef EXP3Q1_HEADER_H
#define EXP3Q1_HEADER_H

#endif //EXP3Q1_HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*Node;
Node newNode(int data);
// stack def
typedef Node Stack;
Stack createStack(int n);
void push(Stack s,int data);
int pop(Stack s);
int stackEmpty(Stack s);
//end

// queue def
typedef struct queue{
    Node front;
    Node rear;
    int size;
}*Queue;
Queue createQueue(int n);
void enQueue(Queue q,int data);
int deQueue(Queue q);
int queueEmpty(Queue q);
//end


