#include "mystd.h"

int main() {
    LGraph listGraph=createLGraph(8);
    Distance_Vertex list[listGraph->numbersVertex+1];

    for(int i=0;i<13;i++)
        lGraphInsertEdge(listGraph);
    //TopPath(1,listGraph);
    MinPath(1,listGraph,list);
    printPath(8,list);
    return 0;
}
