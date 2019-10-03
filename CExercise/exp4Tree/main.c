#include "mystd.h"

int main(void){
    int num=7;
    Tree tree=maketree(num);
    //before reversing children.
    printf("PreOrder traverse: ");
    traverse(tree);
    printf("\nReversing now.\n");
    //start
    printf("PreOrder traverse: ");
    childReverse(tree);
    traverse(tree);
    printf("\n");
    return 0;
}