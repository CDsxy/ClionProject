//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_GENERATOR_H
#define CLIONPROJECT_GENERATOR_H

#include "board.h"
#include "assess.h"
#include <stdlib.h>
#include <time.h>

#define NEIBOR_NUM 80

int LegalMoves(Point *point);
int NeighborJudge(int m,int n);
void Order(Point *point1);
Point Finding(int target,const int * ,const Point *);

#endif //CLIONPROJECT_GENERATOR_H
