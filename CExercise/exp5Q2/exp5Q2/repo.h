//
// Created by astzls213 on 2019-09-19.
//

#ifndef GRAPH_MYSTD_H
#define GRAPH_MYSTD_H

#endif //GRAPH_MYSTD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#define Non_Vertex -1
#define MAXWORD 101

typedef int vertex;
typedef double Weight;


typedef struct spot{
	char name[MAXWORD];
	char *brief[MAXWORD];
}*Spot;

typedef struct MatrixGraph{
	int numberVertex;
	int numbersEdge;
	Weight **matrix;
	Spot *Vertices_Info;
}*MGraph;


char *input(char word[], int length, FILE *src);

void mGraphInsertEdge(MGraph graph, FILE *src, int mode);

MGraph createMGraph(int scale, FILE *src);

void AllPairs(MGraph g, Weight **D, vertex **Path);
Weight **createDistance(int scale);
vertex **createPath(int scale);
void printPath(vertex **Path, MGraph g);

int settings(void);
void menu(vertex **Path, Weight **Dist, MGraph g, void(*func)(vertex **Path, Weight **Dist, MGraph g));