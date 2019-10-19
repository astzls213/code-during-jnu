#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MIN 0
#define MAX_NAME_LENGTH 101
#define CHAR 95
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

void menu();

MinHeap initialMinHeap(int cap);
Node delMin(MinHeap h);
Node huffmanStatus(MinHeap h);
void MinHeapStatus(MinHeap h);
void insert(Node i,MinHeap h);
void loadData(MinHeap h);

void printHuffmanTree(Node huff,FILE *file);
void printBigTree(Node huff,FILE *file);
int TreeHeight(Node huff);
int maxInt(int i,int j);

Stack createStack(int cap);
void push(Stack,Node data);
Node pop(Stack s);
int isEmpty(Stack s);
int isFull(Stack s);

char *inputStream(char *string,int size,FILE *);

void getCode(Node huff,FILE *file,int path[]);

void encoding(FILE *dest,FILE *text,char *code[]);
void decoding(FILE *dest,FILE *text,char *code[],int treeHeight);

int *analyseFrequency();
