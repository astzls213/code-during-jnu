//
// Created by astzls on 2019-10-05.
//

#ifndef EXP3Q2_HEADER_H
#define EXP3Q2_HEADER_H

#endif //EXP3Q2_HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY -1
#define PARK_PER_HOUR 10

typedef struct car{
   unsigned ID;
   unsigned tick;
}*Car;

typedef struct node{
    Car data;
    struct node *next;
}*Node;

typedef struct park{
    unsigned capacity;
    int topPark;
    Car *parking;
}*Park;

typedef struct queue{
    Node front;
    Node rear;
    int size;
}*Queue;

typedef struct info{
    int delta;
    unsigned money;
}*Info;

Node newNode(unsigned id);

Park createPark(unsigned n);
int arrival(Park p,Car data,Queue q);
Car departure(Park p);
bool parkIsEmpty(Park p);
bool parkIsFull(Park p);

Queue createQueue();
void enQueue(Queue q,Car data);
unsigned deQueue(Queue q);
bool queueEmpty(Queue q);

void carBehaviourStream(Park p,Queue q);
