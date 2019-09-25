//
// Created by astzls on 2019-09-02.
//
#include <stdio.h>
#include "mystd.h"
void masterHint() { // guest numbers game.
    int n;
    while(scanf("%d",&n)!=1||n<=0)
        continue;
    int ans[n],tmp[n];
    int num = 1, A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ans[i]);//get answer
    }
    while (1) {
        A=0;B=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp[i]);//get input and compare
            if(tmp[i]==ans[i])
                A++;
        }
        if(tmp[0]==0)
            break;
        for(int nat=1;nat<=9;nat++)
        {
            int freqa=0,freqt=0;
            for(int j=0;j<n;j++)
            {
                if(ans[j]==nat)
                    freqa++;
                if(tmp[j]==nat)
                    freqt++;
            }
            if(freqa<freqt)
                B=B+freqa;
            else
                B=B+freqt;
        }
        printf("(%d,%d)\n",A,B-A);
    }
}
