//
// Created by astzls on 2019-11-21.
//

#ifndef EXP6Q2_HEADER_H
#define EXP6Q2_HEADER_H

#endif //EXP6Q2_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 20
static int primes[]={9,53,97,157,211,263,317,503,1039,2011};//primes[0] means length of that array.
typedef struct phone{
    char *name;
    short NetWorkRecognition;
    int random;//after NetWork Recognition are the combination of region recognition and random numbers。
    struct phone *next;
}*Phone;
typedef struct hashTable{
    int TableSize;
    int loads;
    double lambda;//@param lambda is factor of the load data.
    Phone *Table;
}*HashTable;
int menu(void);
char *inStream(char *word,int length);
char *fileStream(char *word,int length,FILE *file);
void phoneStream(short *front,int *rear);
int binarySearch(int,const int *array);
int hashCode(const char *,HashTable table);
int hashCode_Phone(int,HashTable);
void insert_Phone(const char *name,short front,int rear,HashTable table);
Phone find(const char *,HashTable table);
Phone findByPhone(short front,int rear,HashTable table);
int search(const char *,HashTable table);//used by delete and modify.
HashTable initialize(int);
void insert(const char *,short front,int rear,HashTable table);
void delete(const char *,HashTable table,HashTable);
void deleteByPhone(short,int,HashTable);
void modify(const char *name,HashTable table,HashTable phone);
void freeTable(HashTable);
HashTable ReHash(HashTable);
HashTable ReHash_Phone(HashTable old);