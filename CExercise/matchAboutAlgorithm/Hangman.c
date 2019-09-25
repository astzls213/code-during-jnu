//
// Created by astzls on 2019-09-03.
//
#include <stdio.h>
#include "mystd.h"
void Hangman(void){// guest word game
    int num,wrong=0,correct=0,kind=0,kase=0;
    int character[26];
    for(int i=0;i<26;i++)
        character[i]=0;
    char ans[MAX],player[MAX];
    while (scanf("%d",&num)){
        if(num==-1)
            break;
        kase++;
        while (getchar()!='\n')
            continue;
        impget(ans,MAX+1);

        for(int j=97;j<=122;j++){
            for(int i=0;ans[i]!='\0'&&i<MAX;i++){
                if((int)ans[i]==j)
                    character[j-97]=character[j-97]+1;
            }
        }
        //count kinds of character in ans.
        for(int i=0;i<26;i++){
            if(character[i])
                kind++;
        }
        impget(player,MAX+1);
        for(int i=0;player[i]!='\0';i++){
            if(strchr(ans,player[i])){
                if(!spechr(player,player[i],i))
                    correct++;
                else
                    wrong++;
            }
            else
                wrong++;
            if(correct==kind)
            {
                printf("Round %d\nYou win.\n",kase);
                continue;
            }
            if(wrong==WRONG){
                printf("Round %d\nYou lose.\n",kase);
                continue;
            }
        }
        printf("Round %d\nYou chickened out.\n",kase);
        getchar();//test
    }
}
char* impget(char *word,int n){
    char * retVal,* tmp;
    retVal=fgets(word,n,stdin);
    if(retVal){
        tmp=strchr(word,'\n');
        if(tmp){
            *tmp='\0';
        }
        else{
            while(getchar()!='\n')
                continue;
        }
    }
    return retVal;
}
char* spechr(char* word,char find,int n){
    for(int i=0;word[i]!='\0'&&i<n;i++){
        if(word[i]==find)
            return &word[i];
    }
    return NULL;
}
