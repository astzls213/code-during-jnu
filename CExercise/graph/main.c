#include "mystd.h"

int main() {
    LGraph listGraph=createLGraph(4);
    for(int i=0;i<5;i++)
        lGraphInsertEdge(listGraph);
    bfsLG(listGraph,1);
    return 0;
}