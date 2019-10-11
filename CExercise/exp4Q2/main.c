#include "header.h"
int main() {
    int cap;
    scanf("%d",&cap);
    while(getchar()!='\n')
        continue;
    MinHeap h=initialMinHeap(cap);
    loadData(h);
    MinHeapStatus(h);
    Node myHuff=huffmanStatus(h);
    printHuffmanTree(myHuff);

    return 0;
}
