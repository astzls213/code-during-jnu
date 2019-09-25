#include "mystd.h"

int main() {
    Disjoint set;
    initialDisjointSet(set);
    UnionBySize(set,5,6);
    UnionBySize(set, 3, 4);
    UnionBySize(set,3,5);
    UnionBySize(set,1,2);
    UnionBySize(set,2,5);
    for(int i=1;i<=NumSets;i++)
        printf("%d:%d\n",i,set[i]);
    checkConnect(set, 2, 3);
    findCompress(set,6);
    for(int i=1;i<=NumSets;i++)
        printf("%d:%d\n",i,set[i]);
    return 0;
}