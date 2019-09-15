//
// Created by astzls on 2019-09-14.
//
#include "mystd.h"
void Stripies(void){
    int n;
    scanf("%d",&n);
    stripie stripies=initialStripie(n);

    loadWeight(stripies);
    maxHeapStatus(stripies);
    printf("%.3f",minimalWeight(stripies));
}
stripie initialStripie(int capacity){
    stripie Stripie=(stripie)malloc(sizeof(stripiesMaxHeap));//free unavailable.
    if(!Stripie)
        printf("Out of memory.");
    else {
        Stripie->size = 0;
        Stripie->capacity = capacity;
        Stripie->element = (double *) malloc(sizeof(double) * capacity + 1);
        if(!Stripie->element)
            puts("Out of memory.");
        else
            Stripie->element[0] = STRIMAXHEAP;
    }
    return Stripie;
}
void loadWeight(stripie s){
    while(s->size<s->capacity)
        scanf("%lf",s->element+(++s->size));
}
void maxHeapStatus(stripie s){
    for(int parent=s->size/2;parent>0;parent--){
        int tmpP=parent;
        int tmpPE=s->element[parent];
        while(2*parent<=s->size){
            int child=2*parent;
            if(child+1>s->size)//only left child available.
            {
                if(tmpPE<s->element[child])
                {
                    s->element[parent]=s->element[child];
                    parent=child;
                }
                else
                    break;
            }
            else
            {
                if(s->element[child]<s->element[child+1])
                {
                    if(tmpPE<s->element[child+1])
                    {
                        s->element[parent]=s->element[child+1];
                        parent=child+1;
                    }
                    else
                        break;
                }
                else
                {
                    if(tmpPE<s->element[child])
                    {
                        s->element[parent]=s->element[child];
                        parent=child;
                    }
                    else
                        break;
                }
            }
        }
        s->element[parent]=tmpPE;
        parent=tmpP;
    }
}
double getMaxWeight(stripie s){
    double max=s->element[1];
    s->element[1]=s->element[s->size--];
    maxHeapStatus(s);
    return max;
}
void insertWeight(double i,stripie s){
    if(s->size+1>s->capacity)
        printf("Error! Heap is full now!");
    else
        s->element[++s->size]=i;
}
double minimalWeight(stripie s){
    int minimalW=0;
    double maxW1,maxW2,tmpW;
    while(1)
    {
        maxW1=getMaxWeight(s);
        maxW2=getMaxWeight(s);
        tmpW=2*sqrt(maxW1*maxW2);
        if(s->size==0)
            return tmpW;
        insertWeight(tmpW, s);
        maxHeapStatus(s);
    }
}