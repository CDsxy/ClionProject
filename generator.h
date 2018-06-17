//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_GENERATOR_H
#define CLIONPROJECT_GENERATOR_H



#include "board.h"
#include "access.h"
#define NEIBOR_NUM 80

Point VaildPoint[NEIBOR_NUM];

int LegalMoves(Point *point);
int NeighborJudge(int m,int n);
void Order(int num,Point *point);
Point Finding(int target);

#endif //CLIONPROJECT_GENERATOR_H
