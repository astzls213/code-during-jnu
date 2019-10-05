#include "header.h"
int main() {
    unsigned n;// capacity of park.
    puts("What size do you park?");
    scanf("%u",&n);
    getchar();// clean \n in buffer.
    Queue shortCut=createQueue();
    Park park=createPark(n);
    carBehaviourStream(park,shortCut);
    return 0;
}