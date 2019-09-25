//
// Created by astzls on 2019-09-19.
//

#ifndef GRAPH_MYSTD_H
#define GRAPH_MYSTD_H

#endif //GRAPH_MYSTD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Independent -1
#define MAX_NODE_LIST_GRAPH 100
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
    AdjNode firstAdjNode;
}VNode;

typedef struct ListGraph{
    int numbersVertex;
    int numbersEdge;
    VNode adjList[MAX_NODE_LIST_GRAPH];
}*PtrToLGraph;
//end
typedef PtrToMUGraph MUGraph;
typedef PtrToLGraph LGraph;

typedef struct searchQueue{
    int front,rear;
    vertex queue[MAX_NODE_LIST_GRAPH];
}*Queue;

void enSearchQueue(vertex V, Queue Q);
vertex deSearchQueue(Queue Q);

void bfsLG(LGraph graph, vertex V);
void lGraphInsertEdge(LGraph graph);
void mUGraphInsertEdge(MUGraph graph);
MUGraph createMUGraph(int scale);
LGraph createLGraph(int scale);