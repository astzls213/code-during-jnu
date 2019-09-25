//
// Created by astzls on 2019-09-20.
//
#include "mystd.h"

char *input(char *word, int len){
    char *find,*retVal;
    retVal=fgets(word,len,stdin);
    if(retVal){
        find=strchr(word,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return retVal;
}
Student addStudents(int scale){
    puts("Now adding all students's info in your class.");
    Student head=(Student)malloc(sizeof(struct student));
    Student tmpHead=head;
    puts("No.1");
    puts("Name:");
    input(head->name,NAME);
    puts("ID:");
    input(head->ID,idLENGTH);
    head->nextClass=NULL;
    head->nextStu=NULL;
    for(int count=1;count<scale;count++){
        tmpHead->nextStu=(Student)malloc(sizeof(struct student));
        printf("No.%d\n",count+1);
        puts("Name:");
        input(tmpHead->nextStu->name,NAME);
        puts("ID:");
        input(tmpHead->nextStu->ID,idLENGTH);
        tmpHead->nextStu->nextClass=NULL;
        tmpHead->nextStu->nextStu=NULL;
        tmpHead=tmpHead->nextStu;
    }
    tmpHead=NULL;
    return head;
}
int addScore(Student students){
    Student goalStudent;
    Class tmpClass;
    puts("Which student? give id:");
    char tmpId[idLENGTH];
    input(tmpId,idLENGTH);
    for(goalStudent=students;goalStudent&&
        strcmp(goalStudent->ID,tmpId)!=0;goalStudent=goalStudent->nextStu){
    }

    if(goalStudent)
        tmpClass=goalStudent->nextClass;
    else{
        puts("Not found that guy!");
        return 0;
    }

    puts("How many classes do you want to add?");
    int num;
    while(scanf("%d",&num)!=1||num<1)
        puts("Invalid input.Again!");
    while (getchar()!='\n') //clean \n
        continue;
    for(int i=0;i<num;)
    {
        char tmpName[NAME];
        puts("Class name:");
        input(tmpName, NAME);
        while (tmpClass && strcmp(tmpClass->name, tmpName) != 0) {
            tmpClass = tmpClass->nextClass;
        }
        if (tmpClass) {
            printf("%s already picked!\n", tmpName);
            continue;
        }
        else {
            tmpClass = goalStudent->nextClass;
            while (tmpClass && tmpClass->nextClass != NULL)
                tmpClass = tmpClass->nextClass;
            if (tmpClass) {
                tmpClass->nextClass = (Class) malloc(sizeof(struct class));
                tmpClass->nextClass->nextClass = NULL;
                strcpy(tmpClass->nextClass->name, tmpName);
                puts("Point:");
                while (scanf("%hu", &tmpClass->nextClass->point) != 1)
                    puts("Invalid input!Must range 0~100!again");
                while (getchar()!='\n') //clean \n
                    continue;
                i++;
                continue;
            } else {
                goalStudent->nextClass = (Class) malloc(sizeof(struct class));
                goalStudent->nextClass->nextClass = NULL;
                strcpy(goalStudent->nextClass->name, tmpName);
                puts("Point:");
                while (scanf("%hu", &goalStudent->nextClass->point) != 1)
                    puts("Invalid input!Must range 0~100!again");
                while (getchar()!='\n') //clean \n
                    continue;
                i++;
                continue;
            }
        }
    }
    puts("Operation succeed!");
    return 1;
}
int changeScore(Student students){
    Student goalStudent;
    Class tmpClass;
    puts("Which student? give id:");
    char tmpId[idLENGTH];
    input(tmpId,idLENGTH);
    for(goalStudent=students;goalStudent&&
        strcmp(goalStudent->ID,tmpId)!=0;goalStudent=goalStudent->nextStu){
    }

    if(goalStudent)
        tmpClass=goalStudent->nextClass;
    else{
        puts("Not found that guy!");
        return 0;
    }

    puts("Which class? give name:");
    char tmpName[NAME];
    input(tmpName,NAME);
    while (tmpClass&&strcmp(tmpClass->name,tmpName)!=0)
    {
        tmpClass=tmpClass->nextClass;
    }
    if(tmpClass){
        puts("What points do you want to change?");
        while (scanf("%hu",&tmpClass->point)!=1)
            puts("Invalid input!again!");
        puts("Operation succeed!");
        return 1;
    }
    else
    {
        puts("Not that class!");
        return 0;
    }
}
int deleteScore(Student students){
    Student goalStudent;
    Class tmpClass;
    puts("Which student? give id:");
    char tmpId[idLENGTH];
    input(tmpId,idLENGTH);
    for(goalStudent=students;goalStudent&&
                             strcmp(goalStudent->ID,tmpId)!=0;goalStudent=goalStudent->nextStu){
    }

    if(goalStudent)
        tmpClass=goalStudent->nextClass;
    else{
        puts("Not found that guy!");
        return 0;
    }
    char tmpName[NAME];
    puts("Which class? give name:");
    input(tmpName,NAME);
    if(strcmp(goalStudent->nextClass->name,tmpName)==0){
        Class tmp=goalStudent->nextClass;
        goalStudent->nextClass=goalStudent->nextClass->nextClass;
        tmp->nextClass=NULL;
        free(tmp);
        puts("Operation succeed!");
        return 1;
    }
    else{
        while (tmpClass->nextClass&&strcmp(tmpClass->nextClass->name,tmpName)!=0){
            tmpClass=tmpClass->nextClass;
        }
        if(tmpClass->nextClass){
            Class tmp=tmpClass->nextClass;
            tmpClass->nextClass=tmpClass->nextClass->nextClass;
            tmp->nextClass=NULL;
            free(tmp);
            puts("Operation succeed!");
            return 1;
        } else{
            puts("Not found this class for that guy.");
            return 0;
        }
    }
}
void printScoreList(Student students){
    Student goalStudent;
    puts("Which student? give id:");
    char tmpId[idLENGTH];
    input(tmpId,idLENGTH);
    for(goalStudent=students;goalStudent&&
                             strcmp(goalStudent->ID,tmpId)!=0;goalStudent=goalStudent->nextStu){
    }

    if(goalStudent)
    {
        printf("%15s\t",goalStudent->ID);
        Class eachClass=goalStudent->nextClass;
        while (eachClass!=NULL){
            printf("%15s\t",eachClass->name);
            eachClass=eachClass->nextClass;
        }
        printf("\n");
        printf("%15s\t",goalStudent->name);
        eachClass=goalStudent->nextClass;
        while (eachClass!=NULL){
            printf("%15hu\t",eachClass->point);
            eachClass=eachClass->nextClass;
        }
        printf("\n");
    }
    else
        puts("Not found that guy!");
}
Student deleteAStudent(Student students){
    Student head=students;
    Student goalStudentPrev;
    puts("Which student? give id:");
    char tmpId[idLENGTH];
    input(tmpId,idLENGTH);

    if(strcmp(head->ID,tmpId)==0)// Judge the request is head student?
    {
        Student tmp=head;
        head=tmp->nextStu;
        tmp->nextStu=NULL;
        free(tmp);
        puts("Operation succeed!");
        return head;
    }

    // The deleting student isn't head.
    for(goalStudentPrev=students;goalStudentPrev->nextStu&&
                             strcmp(goalStudentPrev->nextStu->ID,tmpId)!=0;
                                goalStudentPrev=goalStudentPrev->nextStu){
    }

    if(goalStudentPrev->nextStu)
    {
        Student tmp=goalStudentPrev->nextStu;
        goalStudentPrev->nextStu=tmp->nextStu;
        tmp->nextStu=NULL;
        if(tmp->nextClass){
            Class tmpC=tmp->nextClass;
            tmp->nextClass=NULL;
            free(tmp);
            while(tmpC!=NULL){
                Class tmpC1=tmpC;
                tmpC=tmpC1->nextClass;
                tmpC1->nextClass=NULL;
                free(tmpC1);
            }
            puts("Operation succeed!");
            return head;
        }
        else{
            free(tmp);
            puts("Operation succeed!");
            return head;
        }
    }
    else{
        puts("Not found that guy!");
        return head;
    }
}