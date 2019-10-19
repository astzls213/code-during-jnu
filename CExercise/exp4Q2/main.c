#include "header.h"
int main() {
    int *frequencyTable;
    int cap=0;

    FILE *huffVisual = fopen("huffmanTreeVisualization", "w+");
    MinHeap h;

    menu();
    int judge;
    while(scanf("%d",&judge)!=1||(judge>2||judge<1))
        puts("Invalid input, again!");
    getchar();
    if(judge==1){
        frequencyTable=analyseFrequency();

        for(int i=0;i!=CHAR;i++){
            if(frequencyTable[i]!=0)
                cap++;
        }

        h=initialMinHeap(cap);

        for(int i=0;i!=CHAR;i++){
            if(frequencyTable[i]!=0){
                h->element[++h->size]=(Node)malloc(sizeof(struct node));
                if(!h->element[h->size])
                    puts("Out of memory!");
                else{
                    h->element[h->size]->c=(char)(i+32);
                    h->element[h->size]->weight=(double)frequencyTable[i];
                    h->element[h->size]->left=NULL;
                    h->element[h->size]->right=NULL;
                }
            }
        }
    }
    else{
        puts("How many characters do you hold?");
        while (scanf("%d", &cap) != 1 || cap < 2)
            puts("At least 2! Again!");
        h = initialMinHeap(cap);
        loadData(h);
    }

    MinHeapStatus(h);
    Node myHuff = huffmanStatus(h);
    free(h);
    h=NULL;
    int N = TreeHeight(myHuff); //Tree height.
    if(N<5)
        printHuffmanTree(myHuff, huffVisual);
    else
        printBigTree(myHuff,huffVisual);
    fclose(huffVisual);
    huffVisual = NULL;

    //write code in Huffman text.
    FILE *huffCode = fopen("Huffman", "w");
    int *path=(int *)malloc(sizeof(int)*N);
    getCode(myHuff, huffCode, path);
    fclose(huffCode);
    free(path);
    path=NULL;
    //read code into memory.
    huffCode=fopen("Huffman","r");
    char *hashTable[CHAR]={NULL};

    while(1) {
        int tmp;
        int code;
        int i=0;
        tmp = getc(huffCode);
        if(tmp==-1)// when meet EOF, break;
            break;
        hashTable[tmp - 32] = (char *) malloc(sizeof(char) * (N + 1));
        while ((code=getc(huffCode))!='\n'){
            hashTable[tmp-32][i]=code;
            i++;
        }
        hashTable[tmp-32][i]='\0';
    }
    fclose(huffCode);
    huffCode=NULL;

    //encoding text.
    puts("What name do your text file going to encoding?");
    char name[MAX_NAME_LENGTH];
    inputStream(name,MAX_NAME_LENGTH,stdin);
    FILE *text=fopen(name,"r");
    if(!text){
        puts("Not found!");
        return 0;
    }
    FILE *CodeFile=fopen("CodeFile","w");
    encoding(CodeFile,text,hashTable);
    fclose(text);
    fclose(CodeFile);

    //decoding "CodeFile" By "Huffman"
    CodeFile=fopen("CodeFile","r");
    text=fopen("TextFile","w");
    decoding(text,CodeFile,hashTable,N);
    fclose(CodeFile);
    fclose(text);

    puts("Accomplished! Please go to: ./exp4Q2/cmake-build-debug , to check your file.");
    return 0;
}