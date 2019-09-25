//
// Created by astzls on 2019-09-20.
//

#ifndef STUDENTCLASSARRANGEMENTSYSTEM_MYSTD_H
#define STUDENTCLASSARRANGEMENTSYSTEM_MYSTD_H

#endif //STUDENTCLASSARRANGEMENTSYSTEM_MYSTD_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME 50
#define idLENGTH 11

typedef struct student{
    char name[NAME];
    char ID[idLENGTH];
    struct class *nextClass;
    struct student *nextStu;
}*Student;
typedef struct class{
    char name[NAME];
    unsigned short point;
    struct class *nextClass;
}*Class;

char *input(char *word, int len);
Student addStudents(int scale);
int addScore(Student students);
int changeScore(Student students);
int deleteScore(Student students);
void printScoreList(Student students);
Student deleteAStudent(Student students);