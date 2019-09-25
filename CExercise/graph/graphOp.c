#include "mystd.h"

//
// Created by astzls on 2019-09-23.
//
MUGraph createMUGraph(int scale){
    MUGraph graph=(MUGraph)malloc(sizeof(struct MatrixUndirectedGraph));
    graph->numberVertex=scale;
    graph->numbersEdge=0;
    // Create a adjoining matrix.
    graph->matrix=(int **)malloc(scale*sizeof(int *));
    for(int i=0;i<scale;i++)
        (graph->matrix)[i]=(int *)malloc(scale*sizeof(int));
    // assign every vertex to independent.
    for(int i=0;i<scale;i++)
        for(int j=0;j<scale;j++)
            (graph->matrix)[i][j]=Independent;
    return graph;
}
LGraph createLGraph(int scale){
    LGraph graph=(LGraph)malloc(sizeof(struct ListGraph));
    graph->numbersVertex=scale;
    graph->numbersEdge=0;
    for(int i=0;i<scale;i++)
    {
        (graph->adjList)[i].flag=false;
        (graph->adjList)[i].firstAdjNode=NULL;
    }
    return graph;
}
void mUGraphInsertEdge(MUGraph graph){
    vertex V,W;
    Weight weight;
    puts("( V, W, weight):");
    scanf("%d %d %d",&V,&W,&weight);

    if((graph->matrix)[V][W]!=Independent)
    {
        puts("Error: This edge has existed!");
        return;
    }
    graph->numbersEdge++;
    (graph->matrix)[V][W]=weight;
    (graph->matrix)[W][V]=weight;
    puts("Insert succeed^ ^");
}
void lGraphInsertEdge(LGraph graph){
    vertex V,W;
    Weight weight;
    puts("<V,W> && weight:");
    scanf("%d %d %d",&V,&W,&weight);

    AdjNode find=graph->adjList[V-1].firstAdjNode;
    while(find!=NULL&&find->v!=W)
        find=find->adjVertex;
    if(find)
    {
        printf("Error: %d -> %d existed.\n",V,W);
    }
    else
    {
        graph->numbersEdge++;
        AdjNode newNode=(AdjNode)malloc(sizeof(struct adjNode));
        newNode->v=W;
        newNode->weight=weight;
        newNode->adjVertex=graph->adjList[V-1].firstAdjNode;
        graph->adjList[V-1].firstAdjNode=newNode;
        newNode=NULL; //prevent using that to change node info.
        puts("Insert succeed^ ^");
    }
}

void bfsLG(LGraph graph, vertex V){
    Queue tmpQueue=(Queue)malloc(sizeof(struct searchQueue));
    tmpQueue->front=tmpQueue->rear=0;
    graph->adjList[V-1].flag=true;
    //start: doing you want to do when travel the graph.
    printf("%d -> ",V);
    //end
    enSearchQueue(V,tmpQueue);
    while(tmpQueue->rear!=tmpQueue->front){
        V=deSearchQueue(tmpQueue);
        AdjNode tmpNode=graph->adjList[V-1].firstAdjNode;
        while(tmpNode!=NULL){
            if(!(graph->adjList[(tmpNode->v)-1].flag)) {
                graph->adjList[(tmpNode->v)-1].flag = true;
                //start: doing you want to do when travel the graph.
                printf("%d -> ",tmpNode->v);
                //end
                enSearchQueue(tmpNode->v, tmpQueue);
            }
            // let tmpNode be the next adjoin vertex.
            tmpNode=tmpNode->adjVertex;
        }
    }
    //Unnecessary for bfs, it just a extend feature.
    puts("END");
}
void enSearchQueue(vertex V, Queue Q){
    if(((Q->front+1)%MAX_NODE_LIST_GRAPH)==Q->rear)
        puts("Error: Queue filled. Please extend the queue size!");
    else
    {
        Q->front=(Q->front+1)%MAX_NODE_LIST_GRAPH;
        Q->queue[Q->front]=V;
    }
}
vertex deSearchQueue(Queue Q){
    if(Q->rear==Q->front)
    {
        puts("Error: Queue empty.");
        return -1;
    }
    else
    {
        Q->rear=(Q->rear+1)%MAX_NODE_LIST_GRAPH;
        return Q->queue[Q->rear];
    }
}

