//
// Created by astzls on 2019-09-19.
//
#include"mystd.h"
void initialDisjointSet(Disjoint S){
    for(int i=1;i<=NumSets;i++){
        S[i]=INIT;
    }
}
void UnionByHeight(Disjoint S, SetType R1, SetType R2){
    //保证root1和root2是根.
    SetType Root1=findRoot(S,R1);
    SetType Root2=findRoot(S,R2);

    if(S[Root2]<S[Root1])// Root2 deeper than Root1.
        S[Root1]=Root2;
    else{
        if(S[Root1]==S[Root2])
            Root1--;
        S[Root2]=Root1;
    }
}
void UnionBySize(Disjoint S, SetType R1, SetType R2){
    //保证root1和root2是根.
    SetType Root1=findRoot(S,R1);
    SetType Root2=findRoot(S,R2);

    if(S[Root1]>S[Root2]){ // Root2 size more than Root1.
        S[Root2]+=S[Root1];
        S[Root1]=Root2;
    }
    else
    {
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
}
SetType findRoot(Disjoint S, ElementType X){
    for(;S[X]>0;X=S[X]){

    }
    return X;
}
SetType findCompress(Disjoint S, ElementType X){
    if(S[X]<0)
        return X;
    else
        return S[X]=findCompress(S,S[X]);
}
void checkConnect(Disjoint S, ElementType object1, ElementType object2){
    if(findRoot(S, object1)==findRoot(S,object2))
        printf("%d <-> %d CONNECTED!\n", object1, object2);
    else
        printf("%d can't not connect with %d.\n", object1, object2);
}