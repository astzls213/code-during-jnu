//
// Created by astzls on 2019-11-27.
//
#include "mystd.h"
void swap(int *num1,int *num2){
    int tmp=*num1;
    *num1=*num2;
    *num2=tmp;
}
int medium(int ar[],int low,int high){
    int mid=(low+high)/2;
    if(ar[low]>ar[mid])
        swap(ar+low,ar+mid);
    if(ar[mid]>ar[high])
        swap(ar+mid,ar+high);
    if(ar[low]>ar[mid])
        swap(ar+low,ar+mid);
    swap(ar+mid,ar+high-1);
    return ar[high-1];
}
int partition(int ar[],int low,int high){
    int pivot=medium(ar,low,high);
    int i=low,j=high-1;
    while(i<j){
        while(ar[++i]<pivot){}
        while(ar[--j]>pivot){}
        if(i<j)
            swap(ar+i,ar+j);
        else
            break;
    }
    swap(ar+i,ar+high-1);
    return i;
}
void Qsort(int ar[],int low, int high){
    int p=partition(ar,low,high);
    if(low<high) {
        if (high - low > CutOff) {
            Qsort(ar, low, p - 1);
            Qsort(ar, p + 1, high);
        } else {
            insertionSort(ar, low, high);
        }
    }
}
void QuickSort(int ar[],int length){
    Qsort(ar,0,length-1);
}
int find_min_kth(int ar[],int low,int high,int k){
    if(k<1)
    {
        puts("Undefined Error!");
        return -1;
    }
    int tmp=partition(ar,low,high);
    int target=0;
    if(tmp+1>k){
        target=find_min_kth(ar,low,tmp-1,k);
    }
    else if(tmp+1<k)
    {
        target=find_min_kth(ar,tmp+1,high,k);
    }
    else
        target=ar[tmp];
    return target;
}
int Find_Min_Kth(int ar[],int length,int k){
    return find_min_kth(ar,0,length-1,k);
}