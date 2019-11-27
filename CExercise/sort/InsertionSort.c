//
// Created by astzls on 2019-11-27.
//
#include "mystd.h"
void insertionSort(int ar[],int low,int high){
    int tmp,j;
    for(int i=low+1;i<=high;i++){
        tmp=ar[i];
        for(j=i-1;j>=low;){
            if(ar[j]>tmp)
                ar[j+1]=ar[j];
            else
                break;
            j--;
        }
        ar[j+1]=tmp;
    }
}
void InsertionSort(int ar[],int length){
    insertionSort(ar,0,length-1);
}
