//
// Created by astzls on 2019-09-14.
//
#include<stdio.h>
void PBD() // Hduoj 1703
{
    int num[10000],i,input[10000];
    num[0]=0;
    num[1]=1;
    num[2]=3;
    num[3]=4;
    for(i=4;i<10000;i++){
        num[i]=num[i-1]+2;
    }
    for(i=0;i<10000;i++){
        scanf("%d",input+i);
        if(input[i]==0)
            break;
    }
    for(i=0;input[i]!=0;i++){
        printf("%d\n",num[input[i]-1]*5);
    }
}
