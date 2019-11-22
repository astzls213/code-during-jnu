//
// Created by astzls on 2019-11-21.
//
#include "header.h"
int menu(void){
    int rtv;
    puts("*********************");
    puts(" 1.  Search  contact");
    puts(" 2.  Add     contact");
    puts(" 3.  Edit    contact");
    puts(" 4.  Delete  contact");
    puts(" 5.  Exit           ");
    puts("*********************");
    while(scanf("%d",&rtv)!=1||rtv>5||rtv<1)
        puts("Invalid input, again!");
    getchar();
    return rtv;
}
char *inStream(char *word,int length){
    char *rtv_val;
    char *find;
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
char *fileStream(char *word,int length,FILE *file) {
    char *rtv_val;
    char *find;
    rtv_val=fgets(word,length,file);
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
void phoneStream(short *front,int *rear){
    puts("Phone number:");
    while (scanf("%3hd%8d",front,rear)!=2){
        puts("Oops!Throw A Number Exception! Input It Again!");
    }
    getchar();//kill '\n'.
}
int binarySearch(int number,const int *array){
    int low=1;
    int high=array[0];
    int mid=(low+high)/2;
    while(low<high){
        if(number<array[mid])
        {
            high=mid-1;
            mid=(low+high)/2;
        }
        else{
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return low;
}
int hashCode(const char *name,HashTable table){
    int rtv=0;
    for(int i=0;*(name+i)!='\0';i++)
        rtv+=*(name+i);
    return rtv%table->TableSize;
}
int hashCode_Phone(int random,HashTable table){
    return random%table->TableSize;
}
void insert_Phone(const char *name,short front,int rear,HashTable table){
    int iter=hashCode_Phone(rear,table);
    Phone tmp;
    for(int i=0;i<table->TableSize &&
                table->Table[iter]!=NULL &&
                (table->Table[iter]->NetWorkRecognition!=front ||
                 table->Table[iter]->random!=rear);i++){
        iter=(iter+1)%table->TableSize;
    }
    if(table->Table[iter]==NULL){//when occupied a new place, factor should be added.
        table->Table[iter]=(Phone)malloc(sizeof(struct phone));
        table->Table[iter]->NetWorkRecognition=front;
        table->Table[iter]->random=rear;
        table->Table[iter]->name=(char *)malloc(sizeof(char)*(strlen(name)+1));
        strcpy(table->Table[iter]->name,name);
        table->Table[iter]->next=NULL;
        table->loads++;
        table->lambda=(double)table->loads/table->TableSize;
    }
    else{
        puts("Unchecked Exception: maybe already has the same phone or out of capacity.");
    }
}
Phone find(const char *find,HashTable table){
    int iter=hashCode(find,table);
    Phone tmp;
    while(table->Table[iter]!=NULL&&
            strcmp(table->Table[iter]->name,find)!=0){
        iter++;
    }
    if(table->Table[iter]==NULL){
        puts("Not found!");
        return NULL;
    }
    else{
        tmp=table->Table[iter];
        while(tmp!=NULL){
            printf("%s phone's numbers:\n",find);
            printf("%hd%d\n\n",tmp->NetWorkRecognition,tmp->random);
            tmp=tmp->next;
        }
    }
    return table->Table[iter];
}
Phone findByPhone(short front,int rear,HashTable table){
    int iter=hashCode_Phone(rear,table);
    while(table->Table[iter]!=NULL&&
            (front!=table->Table[iter]->NetWorkRecognition||  //judging phone numbers
            rear!=table->Table[iter]->random))
    {
        iter++;
    }
    if(table->Table[iter]==NULL){
        puts("Not found!");
        return NULL;
    }
    else{
        printf("%s phone's numbers:\n",table->Table[iter]->name);
        printf("%hd%d\n\n",table->Table[iter]->NetWorkRecognition,table->Table[iter]->random);
    }
    return table->Table[iter];
}
HashTable initialize(int size){
    int iter=binarySearch(size,primes);
    if(iter>primes[0])
    {
        puts("Checked Exception: Primes pool not enough to fix current size.");
        puts("Please call author to fix that issue.");
        puts("Author Email: astzls213@163.com");
        return NULL;
    }
    HashTable rtv=(HashTable)calloc(1,sizeof(struct hashTable));
    rtv->TableSize=primes[iter+1];//more size, less factor.
    rtv->Table=(Phone *)calloc(rtv->TableSize,sizeof(Phone));
    rtv->lambda=0;
    rtv->loads=0;
    return rtv;
}
void insert(const char *name,short front,int rear,HashTable table){
    int iter=hashCode(name,table);
    Phone tmp;
    for(int i=0;i<table->TableSize &&
                table->Table[iter]!=NULL &&
                strcmp(table->Table[iter]->name,name)!=0;i++){
        iter=(iter+1)%table->TableSize;//linear search.
    }
    if(table->Table[iter]==NULL){//when occupied a new place, factor should be added.
        table->Table[iter]=(Phone)malloc(sizeof(struct phone));
        table->Table[iter]->NetWorkRecognition=front;
        table->Table[iter]->random=rear;
        table->Table[iter]->name=(char *)malloc(sizeof(char)*(strlen(name)+1));
        strcpy(table->Table[iter]->name,name);
        table->Table[iter]->next=NULL;
        table->loads++;
        table->lambda=(double)table->loads/table->TableSize;
    }
    else if(strcmp(table->Table[iter]->name,name)==0){//same name
        tmp=table->Table[iter];
        while(tmp->next!=NULL)
            tmp=tmp->next;
        tmp->next=(Phone)malloc(sizeof(struct phone));
        tmp->next->NetWorkRecognition=front;
        tmp->next->random=rear;
        tmp->next->name=(char *)malloc(sizeof(char)*(strlen(name)+1));
        strcpy(tmp->next->name,name);
        tmp->next->next=NULL;
    }
    else{
        puts("Error: Out of capacity.");
    }
}
int search(const char *find,HashTable table){
    int iter=hashCode(find,table);
    while(table->Table[iter]!=NULL&&
          strcmp(table->Table[iter]->name,find)!=0){
        iter++;
    }
    if(table->Table[iter]==NULL)
        return 0;
    return iter;
}
void delete(const char *name,HashTable table,HashTable phone){
    int i=search(name,table);
    if(i==0){
        puts("Not found!");
        return;
    }
    Phone target=table->Table[i];
    while(target!=NULL){
        Phone tmp=target->next;
        deleteByPhone(target->NetWorkRecognition,target->random,phone);
        free(target);
        target=tmp;
    }
    table->Table[i]=NULL;
}
void deleteByPhone(short front,int rear,HashTable phone){
    int iter;
    iter=hashCode_Phone(rear,phone);
    while(phone->Table[iter]!=NULL&&
          (phone->Table[iter]->NetWorkRecognition!=front||  //judging phone numbers
          phone->Table[iter]->random!=rear)
            ){
        iter++;
    }
    free(phone->Table[iter]);
    phone->Table[iter]=NULL;
}
void modify(const char *name,HashTable table,HashTable phone){
    int i=search(name,table);
    if(i==0){
        puts("Not found!");
        return;
    }
    short f;
    int r;
    Phone target=table->Table[i];
    int iter;

    if(target->next==NULL){
        iter=hashCode_Phone(target->random,table);
        while(table->Table[iter]!=NULL&&
              (target->NetWorkRecognition!=table->Table[iter]->NetWorkRecognition||  //judging phone numbers
               target->random!=table->Table[iter]->random)
                ){
            iter++;
        }
        Phone target_phone=phone->Table[iter];

        //modify dir by hash name.
        printf("New ");
        phoneStream(&target->NetWorkRecognition,&target->random);
        //modify dir by hash phone.
        free(phone->Table[iter]);//Now phone changing, must rehash it.
        phone->Table[iter]=NULL;
        insert_Phone(name,target->NetWorkRecognition,target->random,phone);//Insert again.
    }
    else{
        printf("Old ");
        phoneStream(&f,&r);
        while(target!=NULL&&(target->NetWorkRecognition!=f||target->random!=r))
            target=target->next;
        if (target==NULL){
            puts("Not found!");
            return;
        }
        else{
            iter=hashCode_Phone(target->random,table);
            while(table->Table[iter]!=NULL&&
                  (target->NetWorkRecognition!=table->Table[iter]->NetWorkRecognition||  //judging phone numbers
                   target->random!=table->Table[iter]->random)
                    ){
                iter++;
            }
            Phone target_phone=phone->Table[iter];
            printf("New ");
            phoneStream(&target->NetWorkRecognition,&target->random);
            //modify dir by hash phone.
            free(phone->Table[iter]);//Now phone changing, must rehash it.
            phone->Table[iter]=NULL;
            insert_Phone(name,target->NetWorkRecognition,target->random,phone);//Insert again.
        }
    }
    puts("Clicking: Modify succeed! ^ ^");
}
void freeTable(HashTable table){
    for(int i=0;i<table->TableSize;i++){
        Phone target;
        if(table->Table[i]!=NULL){
            target=table->Table[i];
            while(target!=NULL){
                Phone tmp=target->next;
                free(target);
                target=tmp;
            }
        }
    }
    free(table->Table);
    free(table);
}
HashTable ReHash(HashTable old){
    HashTable new=initialize(old->TableSize*2);
    for(int i=0;i<old->TableSize;i++){
        Phone tmp=old->Table[i];
        if(tmp!=NULL){
            insert(tmp->name,tmp->NetWorkRecognition,tmp->random,new);
            tmp=tmp->next;
        }
    }
    return new;
}
HashTable ReHash_Phone(HashTable old){
    HashTable new=initialize(old->TableSize*2);
    for(int i=0;i<old->TableSize;i++) {
        Phone tmp = old->Table[i];
        if (tmp != NULL) {
            insert_Phone(tmp->name, tmp->NetWorkRecognition, tmp->random, new);
        }
    }
    return new;
}