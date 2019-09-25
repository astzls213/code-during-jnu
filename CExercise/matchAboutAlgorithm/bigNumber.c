//
// Created by astzls on 2019-09-14.
//48
#include "mystd.h"
void bigNum(void){//simple add operation. But numbers is very very big. It really big!
    int round;
    scanf("%d",&round);
    getchar();
    Expr express=(Expr)malloc(round*sizeof(expr));
    for(int i=0;i<round;i++)
    {
        int count;
        (express+i)->num1=(Stack)malloc(sizeof(stack));
        (express+i)->num2=(Stack)malloc(sizeof(stack));

        (express+i)->num1->TopOfStack=EMPTY;
        (express+i)->num1->element=(int*)malloc(STACK*sizeof(int));

        (express+i)->num2->TopOfStack=EMPTY;
        (express+i)->num2->element=(int*)malloc(STACK*sizeof(int));

        while(1)
        {
            count=getchar();
            if(count==32)
                break;
            else
            {
                (express+i)->num1->element[++((express+i)->num1->TopOfStack)]=count-48;
                continue;
            }
        }
        while(1)
        {
            count=getchar();
            if(count==32||count==10)
                break;
            else
            {
                (express+i)->num2->element[++((express+i)->num2->TopOfStack)]=count-48;
                continue;
            }
        }
    }
    for(int i=0;i<round;i++){
        bool flag=false;
        Stack answer=(Stack)malloc(sizeof(stack));
        answer->TopOfStack=EMPTY;
        answer->element=(int *)malloc(sizeof(int)*STACK);
        printf("Case %d:\n",i+1);
        for(int c=0;c<=(express+i)->num1->TopOfStack;c++){
            printf("%d",(express+i)->num1->element[c]);
        }
        printf(" + ");
        for(int c=0;c<=(express+i)->num2->TopOfStack;c++){
            printf("%d",(express+i)->num2->element[c]);
        }
        printf(" = ");
        for(;(express+i)->num1->TopOfStack>-1&&(express+i)->num2->TopOfStack>-1;
             ((express+i)->num1->TopOfStack)--,((express+i)->num2->TopOfStack)--){
            int tmpAns=(express+i)->num1->element[((express+i)->num1->TopOfStack)]+
                    (express+i)->num2->element[((express+i)->num2->TopOfStack)];
            if(flag)
            {
                tmpAns+=1;
            }
            if(tmpAns>9)
            {
                answer->element[++(answer->TopOfStack)]=tmpAns-10;
                flag=true;
                continue;
            }
            else
            {
                answer->element[++(answer->TopOfStack)]=tmpAns;
                flag=false;
                continue;
            }
        }

        for(;(express+i)->num1->TopOfStack>-1;)
        {
            if(flag)
            {
                answer->element[++(answer->TopOfStack)]=(express+i)->num1->element[
                        ((express+i)->num1->TopOfStack)--]+1;
                flag=false;
            }
            else
                answer->element[++(answer->TopOfStack)]=(express+i)->num1->element[
                    ((express+i)->num1->TopOfStack)--];
        }
        for(;(express+i)->num2->TopOfStack>-1;)
        {
            if(flag)
            {
                answer->element[++(answer->TopOfStack)]=(express+i)->num2->element[
                        ((express+i)->num2->TopOfStack)--]+1;
                flag=false;
            }
            else
                answer->element[++(answer->TopOfStack)]=(express+i)->num2->element[
                    ((express+i)->num2->TopOfStack)--];
        }
        if(flag)
            answer->element[++(answer->TopOfStack)]=1;
        while(answer->TopOfStack>-1&&answer->element[(answer->TopOfStack)]==0)
            (answer->TopOfStack)--;
        if(answer->TopOfStack==-1)
        {
            printf("0");
            if(i==round-1)
                printf("\n");
            else
                printf("\n\n");
            free(answer->element);
            free(answer);
            continue;
        }
        while(answer->TopOfStack>-1){
            printf("%d",answer->element[(answer->TopOfStack)--]);
        }

        if(i==round-1)
            printf("\n");
        else
            printf("\n\n");
        free(answer->element);
        free(answer);
    }
    for(int n=0;n<round;n++)
    {
        free((express+n)->num1);
        free((express+n)->num2);
    }
    free(express);
}

