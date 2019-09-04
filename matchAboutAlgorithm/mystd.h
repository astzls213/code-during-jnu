//
// Created by astzls on 2019-09-02.
//

#ifndef MATCHABOUTALGORITHM_MYSTD_H
#define MATCHABOUTALGORITHM_MYSTD_H

#endif //MATCHABOUTALGORITHM_MYSTD_H

#include <string.h>
#define MAX 26
#define WRONG 7
void Flooded(int n,int m);
typedef struct{
    double high;
    double V;//V of water
}grid;
void masterHint();
void Hangman(void);
char* impget(char *word,int n);
char* spechr(char* word,char find,int n);
