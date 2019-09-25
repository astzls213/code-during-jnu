//
// Created by astzls on 2019-08-28.
//

#ifndef UNTITLED1_MYSTD_H
#define UNTITLED1_MYSTD_H

#endif //UNTITLED1_MYSTD_H

#include <stdlib.h>
#include <string.h>

typedef struct tree* Position;
typedef struct tree* Tree;
struct tree{
    int element;
    Position left;
    Position right;
    int flag;
};
Position find(Tree bt,int value);
Position newnode(int value);
Position insert(Tree bt,int value);
Tree maketree(int num);
void pretravel(Tree bt);
Tree delete(Tree bt,int value);
Position my_delete(int value,Tree t);
Position delfind(Tree t,int value);

struct AvlNode;
typedef struct AvlNode* AvlTree;
struct AvlNode{
    int element;
    AvlTree left;
    AvlTree right;
    int highDiffer;
};
void leftRotation(AvlTree avlRoot);
int Height(AvlTree avl);
void rightLeftRotation(AvlTree avlRoot);


