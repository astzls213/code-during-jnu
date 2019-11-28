//
// Created by astzls on 2019-11-27.
//

#ifndef EXP7Q1_MYSTD_H
#define EXP7Q1_MYSTD_H

#endif //EXP7Q1_MYSTD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 10000
#define MAX_name 20
#define MAX_marks 4
#define RADIX 10

typedef struct student{
    char name[MAX_name];
    char marks[MAX_marks];
    int rank;
    int next;
}*Student;
typedef struct marks{
    struct student array[MAX];
    int keyNum;
    int size;
}*Marks;
typedef int KeyArray[RADIX];

char *input(char *word,int length);
Marks initMarks(int n);
//RadixSort
void Distributed(Student stu,int i,int *f,int *e);
void Collect(Student stu, int *f, int *e);
void RadixSort(Marks list);
void GiveRank(Marks list);
void print_Rank_K(Marks list,int k);
void printScore(Marks list);
//RadixSort

//QuickSort
#define ElementType Stu
typedef struct stu{
   char name[MAX_name];
   int score;
   int rank;
}*Stu;
ElementType *initClass(int n);
void swap(ElementType *num1,ElementType *num2);
ElementType medium(ElementType ar[],int low,int high);
int partition(ElementType ar[],int low,int high);
void Qsort(ElementType ar[],int low, int high);
void QuickSort(ElementType ar[],int length);
void rank(ElementType ar[],int length);
void Print_rank_k(ElementType list[],int length,int k);
void PrintScore(ElementType list[],int length);
//QuickSort