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
            (graph->matrix)[i][j]=INT32_MAX;
    return graph;
}
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
void mUGraphInsertEdge(MUGraph graph){
    vertex V,W;
    Weight weight;
    puts("( V, W, weight):");
    scanf("%d %d %d",&V,&W,&weight);

    if((graph->matrix)[V][W]!=INT32_MAX)
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
    //All vertices are indexed starting at 1.


    vertex V,W;
    Weight weight;
    puts("<V,W> && weight:");
    scanf("%d %d %d",&V,&W,&weight);

    AdjNode find=graph->adjList[V-1].firstAdjNode;
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
        newNode->adjVertex=graph->adjList[V-1].firstAdjNode;
        graph->adjList[V-1].firstAdjNode=newNode;
        graph->adjList[W-1].InDegree++;
        newNode=NULL; //prevent using that to change node info.
        puts("Insert succeed^ ^");
    }
}

void bfsLG(LGraph graph, vertex V){
    Queue tmpQueue=createQueue();
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
bool IsFull(Queue Q){
    return ((Q->front+1)%LengthQueue)==Q->rear ? true:false;
}
bool IsEmpty(Queue Q){
    return Q->rear==Q->front ? true:false;
}
void enSearchQueue(vertex V, Queue Q){
    if(IsFull(Q))
        puts("Error: Queue filled. Please extend the queue size!");
    else
    {
        Q->front=(Q->front+1)%LengthQueue;
        Q->queue[Q->front]=V;
    }
}
vertex deSearchQueue(Queue Q){
    if(IsEmpty(Q))
    {
        puts("Error: Queue empty.");
        return -1;
    }
    else
    {
        Q->rear=(Q->rear+1)%LengthQueue;
        return Q->queue[Q->rear];
    }
}
Queue createQueue(){
    Queue rtv=(Queue)malloc(sizeof(struct searchQueue));
    rtv->front=0;
    rtv->rear=0;
    return rtv;
}
void MinPath(vertex start, LGraph g, Distance_Vertex list[])
{

    for(int i=0;i<=g->numbersVertex;i++){
        list[i].known=false;
        list[i].distance=INT32_MAX;
        list[i].pre=Non_Vertex;
    }
    list[start].distance=0;
    vertex min;
    while(1){
        min=0;
        bool flag=true;
        for(int i=1;i<=g->numbersVertex;i++){
            flag=true;
            if(list[i].known==true)
                continue;
            else{
                if(list[i].distance<list[min].distance)
                    min=i;
                flag=false;
            }
        }
        if(flag==true)
            break;
        list[min].known=true;
        AdjNode tmpNode=g->adjList[min-1].firstAdjNode;
        while(tmpNode){
            if(list[tmpNode->v].distance>list[min].distance+tmpNode->weight) {
                list[tmpNode->v].distance = tmpNode->weight+list[min].distance;
                list[tmpNode->v].pre = min;
            }
            tmpNode=tmpNode->adjVertex;
        }
    }

}
void TopPath(vertex start,LGraph g){
    puts("Top Sort:");
    Queue q=createQueue();
    if(g->adjList[start-1].InDegree==0)
        enSearchQueue(start,q);
    while (!IsEmpty(q)){
        vertex tmp=deSearchQueue(q);
        AdjNode tmpNode=g->adjList[tmp-1].firstAdjNode;
        printf("V%d ",tmp);
        while(tmpNode!=NULL){
            g->adjList[tmpNode->v-1].InDegree--;
            if(g->adjList[tmpNode->v-1].InDegree==0)
                enSearchQueue(tmpNode->v,q);
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
void FindArt(vertex root,MUGraph graph){
    vertex adj;
    visited[root]=true;
    low[root]=num[root]=count++;

    for(adj=0;adj<graph->numberVertex;adj++){
        if(graph->matrix[root][adj]==INT32_MAX)
            continue;
        else{
            if(!visited[adj]){
                parent[adj]=root;
                FindArt(adj,graph);
                if(num[root]!=1){//ignored starting point.
                    if(num[root]<=low[adj]){
                        printf("%d is a articulation!",root);
                    }
                }
                low[root]=low[adj]<low[root]?low[adj]:low[root];
            }
            else{
                if(parent[root]!=adj)//back edge.
                {
                    low[root]=num[adj] < low[root] ? num[adj] : low[root];
                }
            }
        }
    }
}
