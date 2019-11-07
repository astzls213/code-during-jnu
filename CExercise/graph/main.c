#include "mystd.h"

int main() {
    MUGraph g=createMUGraph(7);
    for(int i=0;i<9;i++)
        mUGraphInsertEdge(g);
    FindArt(0,g);

    return 0;
}
