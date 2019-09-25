//
// Created by astzls on 2019-09-02.
//

#ifndef MATCHABOUTALGORITHM_MYSTD_H
#define MATCHABOUTALGORITHM_MYSTD_H

#endif //MATCHABOUTALGORITHM_MYSTD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 26
#define WRONG 7

#define STRIMAXHEAP 10001.0

#define STACK 1600
#define EMPTY -1
void Flooded(int n,int m);
typedef struct{
    double high;
    double V;//V of water
}grid;


void masterHint();
void Hangman(void);
char* impget(char *word,int n);
char* spechr(char* word,char find,int n);

typedef struct{
    int capacity;
    int size;
    double* element;
}stripiesMaxHeap;
typedef stripiesMaxHeap* stripie;

stripie initialStripie(int capacity);
void Stripies(void);
void loadWeight(stripie s);
void maxHeapStatus(stripie s);
double getMaxWeight(stripie s);
void insertWeight(double i,stripie s);
double minimalWeight(stripie s);

void PBD();

typedef struct{
    int TopOfStack;
    int *element;
}stack;
typedef stack* Stack;
typedef struct{
    Stack num1;
    Stack num2;
}expr;
typedef expr* Expr;

void bigNum();

void hanoi(int num , char A, char B, char C);
