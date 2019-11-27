#include "mystd.h"

int main() {
    int ar[1000];
    srand(time(0));
    for(int i=0;i<1000;i++)
        ar[i]=(int)random();
    QuickSort(ar,1000);
    printf("%d\t",ar[0]);
    for(int i=1;i<1000;i++)
    {
        printf("%d\t",ar[i]);
        if(i%10==9)
            putchar('\n');
    }
    puts("\n\n");
    int target=Find_Min_Kth(ar,1000,2);
    printf("%d",target);
    return 0;
}