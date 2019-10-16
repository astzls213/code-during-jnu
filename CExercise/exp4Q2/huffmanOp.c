#include "header.h"

void menu(){
    puts("*******************************************************");
    puts("$  1. Analyse each character frequency in your text.  $");
    puts("$   2. Manually enter frequency for each character.   $");
    puts("*******************************************************");
}
MinHeap initialMinHeap(int cap){
    MinHeap rtv=(MinHeap)malloc(sizeof(heap));
    if(!rtv)
        printf("Out of memory.");
    else {
        rtv->size = 0;
        rtv->capacity = cap;
        rtv->element = (Node *) malloc(sizeof(Node) * cap + 1);
        if(!rtv->element)
            puts("Out of memory.");
        else {
            rtv->element[0] = (Node) malloc(sizeof(struct node));
            if(!rtv->element[0])
                puts("Out of memory.");
            else
            {
                rtv->element[0]->weight=MIN;
                rtv->element[0]->c=0;
                rtv->element[0]->left=NULL;
                rtv->element[0]->right=NULL;
            }
        }
    }
    return rtv;
}
void loadData(MinHeap h){
    puts("Format-> frequency char frequency char ...");
    while(h->size<h->capacity)
    {
        h->element[++h->size]=(Node)malloc(sizeof(struct node));
        if(!h->element[h->size])
            puts("Out of memory!");
        else{
            scanf("%lf %c",&h->element[h->size]->weight,&h->element[h->size]->c);
            h->element[h->size]->left=NULL;
            h->element[h->size]->right=NULL;
        }
    }
    getchar();
}
void MinHeapStatus(MinHeap h){
    for(int parent=h->size/2;parent>0;parent--){
        int tmpP=parent;
        Node tmpPE=h->element[parent];
        while(2*parent<=h->size){
            int child=2*parent;
            if(child+1 > h->size)//only left child available.
            {
                if(tmpPE->weight > h->element[child]->weight)
                {
                    h->element[parent]=h->element[child];
                    parent=child;
                }
                else
                    break;
            }
            else
            {
                if(h->element[child]->weight > h->element[child+1]->weight)
                {
                    if(tmpPE->weight > h->element[child+1]->weight)
                    {
                        h->element[parent]=h->element[child+1];
                        parent=child+1;
                    }
                    else
                        break;
                }
                else
                {
                    if(tmpPE->weight > h->element[child]->weight)
                    {
                        h->element[parent]=h->element[child];
                        parent=child;
                    }
                    else
                        break;
                }
            }
        }
        h->element[parent]=tmpPE;
        parent=tmpP;
    }
}
Node delMin(MinHeap h){
    Node min=h->element[1];
    h->element[1]=h->element[h->size--];
    MinHeapStatus(h);
    return min;
}
void insert(Node i,MinHeap h){
    if(h->size+1>h->capacity)
        printf("Error! Heap is full now!");
    else
    {
        h->element[++h->size]=i;
        MinHeapStatus(h);
    }
}
Node huffmanStatus(MinHeap h){
    while(1){
        Node tmp=(Node)malloc(sizeof(struct node));
        if(!tmp)
            puts("Out of memory!");
        else
        {
            tmp->left=delMin(h);
            tmp->right=delMin(h);
            tmp->weight=tmp->left->weight+tmp->right->weight;
            tmp->c='*';
        }
        insert(tmp,h);
        if(h->size==1)
            break;
    }
    return h->element[1];
}

int maxInt(int i, int j){
    if(i>j)
        return i;
    else
        return j;
}
int TreeHeight(Node huff){
    return huff == NULL ? -1 : 1+maxInt(TreeHeight(huff->left),TreeHeight(huff->right));
}
int countHuff(Node huff){
    int count=0;
    if(!huff)
        ;
    else{
        countHuff(huff->left);
        countHuff(huff->right);
        count++;
    }
    return count;
}

void printHuffmanTree(Node huff,FILE *file) {
    int N = TreeHeight(huff); //height of tree
    //Can use a queue instead of 2 stacks.
    Stack formal=createStack((int)pow(2,N));
    Stack reserves=createStack((int)pow(2,N));
    //empty node means NULL node.
    Node empty=malloc(sizeof(struct node));
    empty->c=' ';
    empty->left=NULL;
    empty->right=NULL;
    //calculate the huffman tree size.
    int row;
    if (N == 1)
        row = 3;
    else
        row = 3 * (int) pow(2, N - 1);

    int col = (3 * (int) pow(2, N)) - 1;

    char display[row][col];
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++)
            display[r][c] = ' ';
    }

    int r=0,c=col/2; // This is the coordinate of root.
    for(;r!=row;r++,c--){ // from the root print / towards lower left.
        display[r][c]='/';
    }
    //let it symmetry. From the button to top.
    r-=3; //after a loop above, (r,c) now overflow! So, we just let it turn to the first node in the last but one layer.
    c+=3;
    for(int i=1;i<=N;i++)
    {
        for(int sc=c-1;sc!=-1;sc--){
            for(int sr=r+1;sr!=row;sr++){
                int offset=c-sc;
                if(display[sr][sc]=='/')
                    display[sr][c+offset]='\\';
                else if(display[sr][sc]=='\\')
                    display[sr][c+offset]='/';
            }
        }
        r-=3*(int)pow(2,i-1); //This is a function that indicate the coordinate of the first node about the upper layer.
        c+=3*(int)pow(2,i-1);
    }

    int k=N; /*k is a counter. It can help we calculate the coordinate about the first node next layer.*/
    // reset (r,c) to the root.
    r=0;
    c=col/2;
    push(reserves,huff);// let the root get in!
    for(int i=0;i<N;i++){
        while(!isEmpty(reserves))
        {
            Node tmp=pop(reserves);
            push(formal,tmp);
        }

        int originC=c; //keep c! Cause c will be changed to the next node on the same layer.

        for(int j=1;j<=(int)pow(2,i);j++){ // it repeats 2^i times.
            int offset=3*(int)pow(2,N-i)-1;
            Node n=pop(formal);
            display[r][c]=n->c;

            if(n->c==' ')
            {
                int upper=3*(int)pow(2,k-1)-1;
                if(j%2==1)
                {
                    int upRow=r-1;
                    int upCol=c+1;
                    while(upRow>=r-upper){
                        display[upRow][upCol]=' ';
                        upRow--;
                        upCol++;
                    }
                }
                else{
                    int upRow=r-1;
                    int upCol=c-1;
                    while(upRow>=r-upper){
                        display[upRow][upCol]=' ';
                        upRow--;
                        upCol--;
                    }
                }
            }

            if(n->left)
                push(reserves,n->left);
            else
                push(reserves,empty);
            if(n->right)
                push(reserves,n->right);
            else
                push(reserves,empty);
            c+=offset+1;
        }

        c=originC;
        if(k>=2) {
            r += 3 * (int) pow(2, k - 2);
            c -= 3 * (int) pow(2, k - 2);
            k--;
        }
        else{
            r+=2;
            c-=2;
        }
    }
    // last line must be printed it separately.
    while(!isEmpty(reserves))
    {
        Node tmp=pop(reserves);
        push(formal,tmp);
    }
    for(int i=1;i<=(int)pow(2,N);i++){
        Node n=pop(formal);
        if(n->c==' '){
            display[r][c]=' ';
            if(i%2==1)
            {
                display[r-1][c+1]=' ';//delete / as it is a NULL node.
                c+=4;
            }
            else
            {
                display[r-1][c-1]=' ';//like above.
                c+=2;
            }
        }
        else{
            display[r][c]=n->c;
            if(i%2==1)
                c+=4;
            else
                c+=2;
        }
    }
    puts("*************************************************");
    puts("$   Do you want to visual huffman in console?   $");
    puts("$   1.Yes                                0.No   $");
    puts("*************************************************");
    int judge;
    while(scanf("%d",&judge)!=1||(judge>1||judge<0))
        puts("Invalid input. Again!");
    getchar();
    if(judge==1)
    {
        //print display.
        for (int q = 0; q < row; q++) {
            for (int t = 0; t < col; t++)
                printf("%c", display[q][t]);
            putchar('\n');
        }
    }

    for(int q=0;q<row;q++){
        for(int t=0;t<col;t++)
            fputc(display[q][t],file);
        fputc('\n',file);
    }
    //free malloc on this function.
    free(formal);
    free(reserves);
    free(empty);
}

Stack createStack(int cap){
    Stack rtv=(Stack)malloc(sizeof(struct stack));
    if(!rtv)
        puts("Out of memory!");
    else
    {
        rtv->top=-1;
        rtv->capacity=cap;
        rtv->data=(Node *)malloc(cap*sizeof(Node));
        if(!rtv->data)
        {
            puts("Out of memory!");
            free(rtv);
            rtv=NULL;
            return NULL;
        }
        else
            return rtv;
    }
    return NULL;
}
void push(Stack s,Node data){
    if(isFull(s)){
        puts("Stack overflow.");
    }
    else{
        s->data[++s->top]=data;
    }
}
Node pop(Stack s){
    if(isEmpty(s)){
        puts("Stack empty!");
        return NULL;
    }
    else{
        Node rtv=s->data[s->top--];
        return rtv;
    }
}
int isEmpty(Stack s){
    return (s->top==-1)?1:0;
}
int isFull(Stack s){
    return (s->top+1==s->capacity)?1:0;
}

char * inputStream(char *string,int size,FILE *stream){
    char *rtv;
    char *find;

    rtv=fgets(string,size,stream);
    if(!rtv)
        return NULL;
    else{
        find=strchr(string,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return rtv;
}

void getCode(Node huff,FILE *file,int path[]){
    static int i=0;
    if(huff->left->left!=NULL)
    {
        *(path+i++)=0;
        getCode(huff->left,file,path);
        i--;
    }
    else
    {
        //print in text.
        fputc(huff->left->c,file);
        for(int count=0;count<i;count++)
            fprintf(file,"%d",path[count]);
        fprintf(file,"0\n");

    }
    if(huff->right->right!=NULL)
    {
        *(path+i++)=1;
        getCode(huff->right,file,path);
        i--;
    }
    else
    {
        //print in text.
        fputc(huff->right->c,file);
        for(int count=0;count<i;count++)
            fprintf(file,"%d",path[count]);
        fprintf(file,"1\n");
    }
}

void encoding(FILE *dest,FILE *text,char *code[]){
    while(1){
        int tmp;
        tmp=getc(text);
        if(tmp==-1)
            break;
        if(code[tmp-32]!=NULL){
            fprintf(dest,"%s",code[tmp-32]);
        }
        else{
            printf("Appear an unknown character, terminate!");
            return ;
        }
    }
}
void decoding(FILE *dest,FILE *text,char **code,int treeHeight){
    char *find=NULL;
    char *tmp=(char *)malloc(sizeof(char)*(treeHeight+1));
    *tmp='\0';
    while(1){
        int i=getc(text);
        if(i==-1)
            break;
        find=strchr(tmp,'\0');
        *find=i;
        *(find+1)='\0';

        for(int count=0;count<CHAR;count++){
            if(code[count]==NULL)
                continue;
            else
            {
                if(strcmp(code[count],tmp)==0)
                {
                    fputc(count+32,dest);
                    *tmp='\0';
                    break;
                }
                else
                    continue;
            }
        }
    }
    free(tmp);
}