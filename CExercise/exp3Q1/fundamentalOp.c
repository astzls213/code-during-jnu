//
// Created by astzls on 2019-10-04.
//
#include "header.h"
Node newNode(int data){
    Node n=(Node)malloc(sizeof(struct node));
    if(!n)
    {
        puts("Memory fulled!");
        return NULL;
    }
    n->data=data;
    n->next=NULL;
    return n;
}
Stack createStack(int n){
    //head node
    Stack s=(Stack)malloc(sizeof(struct node));
    s->next=NULL;

    puts("Data:");
    int data;
    scanf("%d",&data);
    s->next=newNode(data);
    for(int count=1;count!=n;count++){
        scanf("%d",&data);
        push(s,data);
    }
    return s;
}
void push(Stack s,int data){
    Node tmp=newNode(data);
    tmp->next=s->next;
    s->next=tmp;
    tmp=NULL;
}
int pop(Stack s){
    if(!stackEmpty(s)) {
        Node tmp = s->next;
        s->next = tmp->next;
        tmp->next = NULL;
        int tmpData = tmp->data;
        free(tmp);
        return tmpData;
    }
    else{
        puts("Stack already empty!");
        return -1;
    }
}
int stackEmpty(Stack s){
    if(s->next==NULL)
        return 1;
    else
        return 0;
}

Queue createQueue(int n){
    Queue q=(Queue)malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
    puts("Data:");
    int data;
    scanf("%d",&data);
    Node node=newNode(data);
    if(!node){
        puts("Failed to create a queue.");
        return NULL;
    }
    q->front=node;
    q->size++;
    for(int i=1;i!=n;i++){
        scanf("%d",&data);
        node->next=newNode(data);
        if(!node->next){
            puts("Failed to create a queue.");
            return NULL;
        }
        node=node->next;
        q->size++;
    }
    q->rear=node;
    return q;
}
void enQueue(Queue q,int data){
    q->rear->next=newNode(data);
    q->rear=q->rear->next;
    q->size++;
}
int deQueue(Queue q){
    if(!queueEmpty(q)) {
        Node tmp = q->front;
        q->front = tmp->next;
        if(!q->front)// when queue is empty.
            q->rear=NULL;
        tmp->next = NULL;
        int tmpData = tmp->data;
        q->size--;
        free(tmp);
        return tmpData;
    }
    else{
        puts("Queue is empty!");
        return -1;
    }
}
int queueEmpty(Queue q){
    if(q->front==NULL)
        return 1;
    else
        return 0;
}
