//
// Created by astzls on 2019-09-15.
//

#ifndef EXP2LINKED_LINKEDHEAD_H
#define EXP2LINKED_LINKEDHEAD_H

#endif //EXP2LINKED_LINKEDHEAD_H

#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>
struct linked{
    int value;
    struct linked* next;
};
typedef struct linked* List;
void insert(int value, int position, List l);
int delete(int position,List l);
List NewNode(int value);
List NewList(int numbers);
void freeList(List l);
void printList(List l);