#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int vertex;
typedef int Weight;


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

typedef PtrToLGraph LGraph;

#define Non_Vertex -1
typedef struct{
    bool known;
    int distance;
    vertex pre;
}Distance_Vertex;

void lGraphInsertEdge(LGraph graph);


LGraph createLGraph(int scale);

void MinPath(vertex start,LGraph g,Distance_Vertex list[]);

void printPath(vertex start, Distance_Vertex list[]);


LGraph createLGraph(int scale){
    LGraph graph=(LGraph)malloc(sizeof(struct ListGraph));
    graph->numbersVertex=scale;
    graph->adjList=(VNode*)malloc(sizeof(VNode)*scale);
    graph->numbersEdge=0;
    for(int i=0;i<scale;i++)
    {
        (graph->adjList)[i].flag=false;
        (graph->adjList)[i].firstAdjNode=NULL;
        (graph->adjList)[i].InDegree=0;
        (graph->adjList)[i].OutDegree=0;
    }
    return graph;
}
void lGraphInsertEdge(LGraph graph){
    vertex V,W;
    Weight weight;
    puts("<V,W> && weight:");
    scanf("%d %d %d",&V,&W,&weight);

    AdjNode find=graph->adjList[V].firstAdjNode;
    while(find!=NULL&&find->v!=W)
        find=find->adjVertex;
    if(find)
    {
        find->weight=weight;
        puts("Insert succeed^ ^");
    }
    else
    {
        graph->numbersEdge++;
        AdjNode newNode=(AdjNode)malloc(sizeof(struct adjNode));
        newNode->v=W;
        newNode->weight=weight;
        newNode->adjVertex=graph->adjList[V].firstAdjNode;
        graph->adjList[V].firstAdjNode=newNode;
        graph->adjList[W].InDegree++;
        newNode=NULL; //prevent using that to change node info.
        puts("Insert succeed^ ^");
    }
}
void MinPath(vertex start, LGraph g, Distance_Vertex list[])
{

    for(int i=0;i<g->numbersVertex;i++){
        list[i].known=false;
        list[i].distance=INT32_MAX;
        list[i].pre=Non_Vertex;
    }
    list[start].distance=0;
    vertex min=start;
    int minDv;
    while(1){
        minDv=INT32_MAX;
        bool flag=true;
        for(int i=0;i<g->numbersVertex;i++){
            flag=true;
            if(list[i].known==true)
                continue;
            else{
                if(list[i].distance<minDv)
                {
                    min=i;
                    minDv=list[i].distance;
                }
                flag=false;
            }
        }
        if(flag==true)
            break;
        list[min].known=true;
        AdjNode tmpNode=g->adjList[min].firstAdjNode;
        while(tmpNode){
            if(list[tmpNode->v].distance>list[min].distance+tmpNode->weight) {
                list[tmpNode->v].distance = list[min].distance+tmpNode->weight;
                list[tmpNode->v].pre = min;
            }
            tmpNode=tmpNode->adjVertex;
        }
    }
}
void printPath(vertex start, Distance_Vertex list[]){
    if(list[start].pre!=Non_Vertex)
    {
        printPath(list[start].pre,list);
        printf(" to ");
    }
    printf("V%d",start);
}

int main() {
    LGraph listGraph=createLGraph(3);
    Distance_Vertex list[listGraph->numbersVertex];

    for(int i=0;i<3;i++)
        lGraphInsertEdge(listGraph);

    MinPath(0,listGraph,list);
    puts("Minimal Path for each vertex from V0:");
    for(int i=1;i<3;i++)
    {
        printPath(i,list);
        putchar('\n');
    }
    return 0;
}