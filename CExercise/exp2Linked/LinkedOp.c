//
// Created by astzls on 2019-09-15.
//
#include "linkedHead.h"
List NewNode(int value){
    List node=(List)malloc(sizeof(struct linked));
    node->value=value;
    node->next=NULL;
    return node;
}
void insert(int value,int position,List l){
    for(int i=1;i<position;i++)
        l=l->next;
    List node=NewNode(value);
    List tmp=l->next;
    l->next=node;
    node->next=tmp;
}
int delete(int position,List l){
    for(int i=2;i<position;i++)
        l=l->next;
    int tmpV=l->next->value;
    List tmp=l->next;
    l->next=l->next->next;
    tmp->next=NULL;
    free(tmp);
    return tmpV;
}
List NewList(int numbers){
    printf("Now enter your %d value:\n",numbers);
    int value;
    scanf("%d",&value);
    List head=NewNode(value);
    List tmp=head;
    for(int i=1;i<numbers;i++){
        scanf("%d",&value);
        tmp->next=NewNode(value);
        tmp=tmp->next;
    }
    tmp=NULL;
    return head;
}
void freeList(List l){
    if(l->next==NULL)
        free(l);
    else
        freeList(l->next);
}
void printList(List l){
    int i;
    for (i=1;l->next!=NULL;i++)
    {
        printf("Pos %d: %d\n",i,l->value);
        l=l->next;
    }
    printf("Pos %d: %d\n",i,l->value);
}
