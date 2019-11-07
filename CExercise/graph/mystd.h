//
// Created by astzls on 2019-09-19.
//

#ifndef GRAPH_MYSTD_H
#define GRAPH_MYSTD_H

#endif //GRAPH_MYSTD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX 100
#define LengthQueue 100
typedef int vertex;
typedef int Weight;

typedef struct{ // for matrix undirected Graph. start
    vertex V,W;
    Weight weight;
}*Edge;
typedef struct MatrixUndirectedGraph{
    int numberVertex;
    int numbersEdge;
    int **matrix;
}*PtrToMUGraph;
//end

typedef struct adjNode *AdjNode; // for adjoint-list directed graph. start
struct adjNode{
    vertex v;
    Weight weight;
    AdjNode adjVertex;
};
typedef struct{
    bool flag; //used on bfs & dfs.
    int InDegree;
    int OutDegree;
    AdjNode firstAdjNode;
}VNode;

typedef struct ListGraph{
    int numbersVertex;
    int numbersEdge;
    VNode *adjList;
}*PtrToLGraph;
//end
typedef PtrToMUGraph MUGraph;
typedef PtrToLGraph LGraph;

typedef struct searchQueue{
    int front,rear;
    vertex queue[LengthQueue];
}*Queue;

#define Non_Vertex 0
typedef struct{
    bool known;
    int distance;
    vertex pre;
}Distance_Vertex;

void enSearchQueue(vertex V, Queue Q);
vertex deSearchQueue(Queue Q);

void bfsLG(LGraph graph, vertex V);
void lGraphInsertEdge(LGraph graph);
void mUGraphInsertEdge(MUGraph graph);
MUGraph createMUGraph(int scale);
LGraph createLGraph(int scale);

void MinPath(vertex start,LGraph g,Distance_Vertex list[]);
void TopPath(vertex start,LGraph g);
void printPath(vertex start, Distance_Vertex list[]);

bool IsFull(Queue);
bool IsEmpty(Queue);
Queue createQueue();
/*Tarjan algorithm which is used to find articulations in a graph.
  But it ignores judging the root.*/
void FindArt(vertex root,MUGraph graph);
static bool visited[MAX_VERTEX];
static vertex parent[MAX_VERTEX];
static int num[MAX_VERTEX];
static int low[MAX_VERTEX];
static int count=1;
//ended definitions.


