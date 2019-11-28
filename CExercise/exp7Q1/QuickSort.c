//
// Created by astzls on 2019-11-28.
//
#include "mystd.h"
ElementType *initClass(int n){
    ElementType *rtv=(ElementType *)calloc(n,sizeof(ElementType));
    if(rtv) {
        for (int i = 0; i != n; i++) {
            rtv[i] = (ElementType) malloc(sizeof(struct stu));
            if(!rtv[i]){
                puts("FatalError: Out of memory!");
                break;
            }
            rtv[i]->rank = 0;
            puts("Student's Name:");
            input(rtv[i]->name, MAX_name);
            puts("Marks:");
            while (scanf("%d", &rtv[i]->score) != 1)
                puts("Invalid input, again.");
            getchar();
        }
    }
    return rtv;
}
void swap(ElementType *num1,ElementType *num2){
    ElementType tmp=*num1;
    *num1=*num2;
    *num2=tmp;
}
ElementType medium(ElementType ar[],int low,int high){
    int mid=(low+high)/2;
    if(ar[low]->score < ar[mid]->score)
        swap(ar+low,ar+mid);
    if(ar[mid]->score < ar[high]->score)
        swap(ar+mid,ar+high);
    if(ar[low]->score < ar[mid]->score)
        swap(ar+low,ar+mid);
    swap(ar+mid,ar+high-1);
    return ar[high-1];
}
int partition(ElementType ar[],int low,int high){
    ElementType pivot=medium(ar,low,high);
    int i=low,j=high-1;
    while(i<j){
        while(ar[++i]->score > pivot->score){}
        while(ar[--j]->score < pivot->score){}
        if(i<j)
            swap(ar+i,ar+j);
        else
            break;
    }
    swap(ar+i,ar+high-1);
    return i;
}
void Qsort(ElementType ar[],int low, int high){
    if(low<0||high<0)
        return;
    int p=partition(ar,low,high);
    if(low<high) {
        Qsort(ar, low, p - 1);
        Qsort(ar, p + 1, high);
    }
}
void QuickSort(ElementType ar[],int length){
    Qsort(ar,0,length-1);
}
void rank(ElementType list[],int length){
    int prev=0;
    int rank=0;
    for(int i=0;i!=length;i++){
        if(prev!=list[i]->score)
            list[i]->rank=++rank;
        else
            list[i]->rank=rank;
        prev=list[i]->score;
    }
}
void Print_rank_k(ElementType list[],int length,int k){
    int i;
    for(i=0;i!=length&&list[i]->rank!=k;i++){
    }
    if(i==length)
    {
        puts("Not found!");
        return;
    }
    puts("Rank\t\t\t\tName\tScore");
    for(;list[i]->rank==k;i++){
        printf("%4d%20s\t%5d\n",list[i]->rank,list[i]->name,list[i]->score);
    }
}
void PrintScore(ElementType list[],int length){
    puts("Rank\t\t\t\tName\tScore");
    for(int i=0;i!=length;i++){
        printf("%4d%20s\t%5d\n",list[i]->rank,list[i]->name,list[i]->score);
    }
}
