#include "header.h"
int main(void){
    HashTable tel_Name=initialize(50);
    HashTable tel_Phone=initialize(50);
    char tmp[MAX];
    char f[4];
    char r[9];
    short front=0;
    int rear=0;
    FILE *tel;
    tel=fopen("teleDirectory.txt","r");
    if(tel==NULL)
        return 0;
    for(char loadName[MAX],loadPhone[MAX];!feof(tel) &&
                                        fileStream(loadName,MAX,tel)!=NULL&&
                                        fileStream(loadPhone,MAX,tel)!=NULL;)
    {
        strncpy(f,loadPhone,3);
        strncpy(r,loadPhone+3,8);
        short tmpF=(short)atoi(f);
        int tmpR=atoi(r);
        insert(loadName,tmpF,tmpR,tel_Name);
        insert_Phone(loadName,tmpF,tmpR,tel_Phone);
    }
    fclose(tel);
    while(1){
        int rtv=menu();
        if(rtv==5)
            break;
        //system("clear");
        if(rtv==1){
            puts("Enter Name or Phone:");
            inStream(tmp,MAX);
            if(isdigit(tmp[0])){//phone number
                strncpy(f,tmp,3);
                strncpy(r,tmp+3,8);
                front=(short)atoi(f);
                rear=atoi(r);
                findByPhone(front,rear,tel_Phone);
            }
            else{//name
                find(tmp,tel_Name);
            }
        }
        else if(rtv==2){
            puts("Enter contact's name:");
            inStream(tmp,MAX);
            phoneStream(&front,&rear);
            insert(tmp,front,rear,tel_Name);
            insert_Phone(tmp,front,rear,tel_Phone);
            if(tel_Name->lambda>0.5)
            {
                ReHash(tel_Name);
                ReHash_Phone(tel_Phone);
            }
        }
        else if(rtv==3){
            puts("Enter contact's name:");
            inStream(tmp,MAX);
            modify(tmp,tel_Name,tel_Phone);
        }
        else{
            puts("Enter contact's name:");
            inStream(tmp,MAX);
            delete(tmp,tel_Name,tel_Phone);
        }
    }
    freeTable(tel_Name);
    freeTable(tel_Phone);
    puts("Bye~ ^ ^");
    return 0;
}