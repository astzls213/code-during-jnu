//
// Created by astzls on 2019-09-26.
//

#ifndef EXP4TREE_MYSTD_H
#define EXP4TREE_MYSTD_H

#endif //EXP4TREE_MYSTD_H

#include<stdio.h>
#include<stdlib.h>

typedef struct tree *Position;
typedef struct tree *Tree;
struct tree{
    int element;
    Position left;
    Position right;
};

void childReverse(Tree tree);
Position newnode(int value);
Position insert(Tree bt,int value);
Tree maketree(int num);
void traverse(Tree tree);