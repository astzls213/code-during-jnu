//
// Created by astzls on 2019-08-28.
//
#include "mystd.h"
#include <stdio.h>
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
Position newnode(int value)
{
    Tree bt=(Tree)malloc(sizeof(struct tree));
    if(!bt)
        puts("Memory is full now!");
    bt->element=value;
    bt->left=bt->right=NULL;
    bt->flag=0;
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
void pretravel(Tree bt)
{
    if(bt) {
        printf("%d\t", bt->element);
        pretravel(bt->left);
        pretravel(bt->right);
    }
}
Position find(Tree bt,int value){
    Tree temp=bt;
    while(temp!=NULL){
        if(temp->element>value)
            temp=temp->left;
        else if(temp->element<value)
            temp=temp->right;
        else
            return temp;
    }
    return NULL;
}
Position findmin(Tree bt){
    Tree tmp=bt;
    if(tmp)
    {
        while(tmp->left)
            tmp=tmp->left;
    }
    return tmp;
}
Tree delete(Tree bt,int value){
    Tree tmp=NULL;
    if(bt==NULL)
        puts("Element not found");
    else if(value<bt->element)
        bt->left=delete(bt->left,value);
    else if(value>bt->element)
        bt->right=delete(bt->right,value);
    else if(bt->left&&bt->right)
    {
        tmp=findmin(bt->right);
        bt->element=tmp->element;
        bt->right=delete(bt->right,bt->element);
    }
    else
    {
        tmp=bt;
        if(bt->left==NULL)
            bt=bt->right;
        else if(bt->right==NULL)
            bt=bt->left;
        free(tmp);
    }
    return bt;
}
Position my_delete(int value,Tree t){

}
Position delfind(Tree t,int value){
    /*Tree temp=t;
    while(temp!=NULL){
        if(temp->element>value)
            temp=temp->left;
        else if(temp->element<value)
            temp=temp->right;
        else
            return temp;
    }
    return NULL;*/
}