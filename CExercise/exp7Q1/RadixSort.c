//
// Created by astzls on 2019-11-28.
//
#include "mystd.h"
char * input(char *word,int length){
    char *find;
    char *rtv_val;
    rtv_val=fgets(word,length,stdin);
    if(rtv_val){
        find=strchr(word,'\n');
        if(find){
            *find='\0';
        }
        else{
            while(getchar()!='\n')
                continue;
        }
    }
    return rtv_val;
}
Marks initMarks(int n){
    Marks tmp=(Marks)malloc(sizeof(struct marks));
    tmp->size=n;
    tmp->keyNum=MAX_marks;
    tmp->array[0].next=1;
    int i,length;
    for (i=1;i<=n;i++){
        tmp->array[i].next=i+1;
        tmp->array[i].rank=0;
        puts("Student's Name:");
        input(tmp->array[i].name,MAX_name);
        puts("Marks:");
        input(tmp->array[i].marks,MAX_marks);
        length=strlen(tmp->array[i].marks);
        //compensated 0  补0
        if(length==1)
        {
            tmp->array[i].marks[2]=tmp->array[i].marks[0];
            tmp->array[i].marks[0]=tmp->array[i].marks[1]='0';
        }
        else if(length==2){
            tmp->array[i].marks[2]=tmp->array[i].marks[1];
            tmp->array[i].marks[1]=tmp->array[i].marks[0];
            tmp->array[i].marks[0]='0';
        }
        for(int j=0;j<MAX_marks-1;j++){
            if(tmp->array[i].marks[j]<48||tmp->array[i].marks[j]>57){
                puts("Fatal Error: Incorrect format.");
                return NULL;
            }
        }
    }
    tmp->array[i-1].next=0;
    return tmp;
}
void Distributed(Student stu,int i,int *f,int *e){
    for (int j=0;j<RADIX;j++)
        f[j]=0;//Reset -> 0, cause f can be reused. And it means f[i] may be not 0.
    for(int p=stu[0].next;p;p=stu[p].next){
        int j=RADIX-stu[p].marks[3-i]+47; //47 means that -1+48 48:'0' 1:index
        if(!f[j]){
            f[j]=p;//f is used to store first node.
        }
        else{
            stu[e[j]].next=p; //let ending node point to current node.
        }
        e[j]=p;//mark down current ending node.
    }
}//Distributed.
void Collect(Student stu,int *f, int *e){
    int i;// index of f and e, i->[0~RADIX-1].
    for(i=0;!f[i];i++)
        continue;
    stu[0].next=f[i];
    int end=e[i];
    while(i<RADIX){
        for(i++;i<RADIX&&!f[i];i++)// ended at the last one in f,e.
            continue;
        if(i==RADIX)
            break;
        if(f[i]){
            stu[end].next=f[i]; //let 上一个节点指向现在的节点
            end=e[i]; //mark down now end-node.
        }
    }
    stu[end].next=0;//let it point to header-node.
}
void RadixSort(Marks list){
    KeyArray f={0},e={0};
    for(int i=1;i<list->keyNum;i++){
        Distributed(list->array,i,f,e);
        Collect(list->array,f,e);
    }
}
void GiveRank(Marks list){
    int prev=0;
    int rank=0;
    for(int i=list->array[0].next;i!=0;i=list->array[i].next){
        if(prev!=atoi(list->array[i].marks))
            list->array[i].rank=++rank;
        else
            list->array[i].rank=rank;
        prev=atoi(list->array[i].marks);
    }
}
void printScore(Marks list){
    puts("Rank\t\t\t\tName\tScore");
    for(int i=list->array[0].next;
            i!=0;i=list->array[i].next){
        printf("%4d%20s\t%5d\n",list->array[i].rank,list->array[i].name,atoi(list->array[i].marks));
    }
}
void print_Rank_K(Marks list,int k){
    int i;
    for(i=list->array[0].next;i!=0&&
        list->array[i].rank!=k;i=list->array[i].next){
    }
    if(i==0)
    {
        puts("Not found!");
        return;
    }
    for(;list->array[i].rank==k;i=list->array[i].next){
        printf("Rank %d: %s\t%d\n",list->array[i].rank,list->array[i].name,atoi(list->array[i].marks));
    }
}