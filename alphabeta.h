//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_ALPHABETA_H
#define CLIONPROJECT_ALPHABETA_H

#include "access.h"
#include "generator.h"


int AlphaBeta(int depth, int alpha, int beta);
void MakeNextMove(int depth ,int i,Point *point);
void UnmakeMove(int i,Point* point);


#endif //CLIONPROJECT_ALPHABETA_H
