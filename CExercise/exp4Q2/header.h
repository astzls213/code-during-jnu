#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN 0
#define ROW 100
#define COL 100
struct node;
typedef struct node *Node;
struct node{
    char c;
    double weight;
    Node left;
    Node right;
};

typedef struct{
    int capacity;
    int size;
    Node *element;
}heap;
typedef heap *MinHeap;

typedef struct stack{
    int capacity;
    int top;
    Node *data;
}*Stack;

MinHeap initialMinHeap(int cap);
Node delMin(MinHeap h);
Node huffmanStatus(MinHeap h);
void MinHeapStatus(MinHeap h);
void insert(Node i,MinHeap h);
void loadData(MinHeap h);

void printHuffmanTree(Node huff);
int TreeHeight(Node huff);
int maxInt(int i,int j);

Stack createStack(int cap);
void push(Stack,Node data);
Node pop(Stack s);
int isEmpty(Stack s);
int isFull(Stack s);
