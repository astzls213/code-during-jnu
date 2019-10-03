//
// Created by astzls on 2019-09-26.
//
#include "mystd.h"

void childReverse(Tree tree){
    if(tree!=NULL)
    {
        Tree tmp=tree->left;
        tree->left=tree->right;
        tree->right=tmp;
        childReverse(tree->left);
        childReverse(tree->right);
    }
}
Tree maketree(int num)
{
    Tree bt;
    int value;
    printf("Enter your value: ");
    scanf("%d",&value);
    bt=newnode(value);
    for(int i=1;i<num;i++)
    {
        scanf("%d",&value);
        insert(bt,value);
    }
    while(getchar()!='\n')
        continue;
    return bt;
}
Position newnode(int value) {
    Tree bt = (Tree) malloc(sizeof(struct tree));
    if (!bt)
        puts("Memory is full now!");
    else {
    bt->element = value;
    bt->left = bt->right = NULL;
    }
    return bt;
}
Position insert(Tree bt,int value)
{
    if(!bt)
    {
        bt=newnode(value);
    }
    else {
        if (value > bt->element)
            bt->right = insert(bt->right, value);
        else if(value < bt->element)
            bt->left = insert(bt->left, value);
    }
    return bt;
}
void traverse(Tree tree){
    if(tree){
        printf("%d ",tree->element);
        traverse(tree->left);
        traverse(tree->right);
    }
}
