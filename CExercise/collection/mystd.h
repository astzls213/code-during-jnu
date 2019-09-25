//
// Created by astzls on 2019-09-19.
//

#ifndef COLLECTION_MYSTD_H
#define COLLECTION_MYSTD_H

#endif //COLLECTION_MYSTD_H

#include <stdio.h>
#define NumSets 10
#define INIT -1
typedef int Disjoint[NumSets+1];
typedef int ElementType;
typedef int SetType;
//collection Function
void initialDisjointSet(Disjoint S);
void UnionByHeight(Disjoint S, SetType Root1, SetType Root2);
void UnionBySize(Disjoint S, SetType Root1, SetType Root2);
SetType findRoot(Disjoint S, ElementType X);
void checkConnect(Disjoint S, ElementType object1, ElementType onject2);
SetType findCompress(Disjoint S, ElementType X);