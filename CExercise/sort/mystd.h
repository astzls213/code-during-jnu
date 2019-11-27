//
// Created by astzls on 2019-11-27.
//

#ifndef SORT_MYSTD_H
#define SORT_MYSTD_H

#endif //SORT_MYSTD_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CutOff 100

void swap(int *num1,int *num2);
int medium(int ar[],int low,int high);
int partition(int ar[],int low,int high);
void Qsort(int ar[],int low,int high);
void QuickSort(int ar[],int length);

void insertionSort(int ar[],int low,int high);
void InsertionSort(int ar[],int length);

int find_min_kth(int ar[],int low,int high,int k);
int Find_Min_Kth(int ar[],int length,int k);
