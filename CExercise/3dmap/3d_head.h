//
// Created by astzls on 2019-08-29.
//

#ifndef INC_3DMAP_3D_HEAD_H
#define INC_3DMAP_3D_HEAD_H

#endif //INC_3DMAP_3D_HEAD_H
#define MAX 100
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct point{
    int r,c;//store position in the map
    int value;
};
typedef  struct point node;
typedef node* Node;
struct map{
    int row,column;//numbers of rows and columns
    int nonezero;//numbers of none-zero
    node array[MAX];//you know
};
typedef struct map* MAP;
