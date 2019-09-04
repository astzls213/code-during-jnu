#include <stdio.h>
#include "3d_head.h"
int main(void) {
    int rows,cols;
    int i=0;
    int judge=1;
    MAP map=(MAP)calloc(1,sizeof(struct map));

    puts("What size do your 2d map? Please enter rows and columns in order.");
    scanf("%d %d",&rows,&cols);
    map->row=rows;map->column=cols;
    while(judge) {
        printf("how much numbers do you want to insert? (value can't be zero)\n");
        int num;
        scanf("%d", &num);
        map->nonezero = num;
        num=i+num;//constantly add

        for (; i < num; i++) {
            printf("array column value in this order enter:\n");
            scanf("%d %d %d", &(map->array[i].r), &(map->array[i].c), &(map->array[i].value));
        }
        puts("do you want to continue adding? 1 to yes, 0 to no.");
        scanf("%d",&judge);
    }
    puts("well, do you want to find maximum in your map? answer like above.");
    scanf("%d",&judge);
    int tmp=0;
    if(judge){
        for(int k=0;k<i;k++)
        {
            if(map->array[k].value>tmp)
                tmp=map->array[k].value;
        }
    }
    printf("%d is maximum in your map.",tmp);

    puts("Bye!~");

    return 0;
}
