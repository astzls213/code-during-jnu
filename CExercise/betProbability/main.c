#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCOPE 49
#define ODDS 40
int main() {
    int numbers[SCOPE];
    for(int i=0;i<SCOPE;i++){
        numbers[i]=i+1;
    }
    srand(time(NULL));
    while(1){
        int flag=0;
        int count=0;
        int suc=0;
        int n;
        int money;
        int total=0, bonus=0;
        puts("n, money:");
        scanf("%d %d",&n,&money);
        while(count<1000) {
            int guess[n];
            int goal=rand()%SCOPE+1;
            for (int i = 0; i < n; i++)
                guess[i] = rand() % SCOPE + 1;
            for (int i = 0; i < n; i++) {
                if (goal == guess[i]) {
                    suc++;
                    bonus+=(money*ODDS);
                    break;
                }
            }
            count++;
            total+=(n*money);
        }
        printf("P: %.2f%%\nEX: %d\n",suc/10.0, bonus-total);
        puts("continue?");
        scanf("%d",&flag);
        if(flag==0)
            break;
    }
    return 0;
}