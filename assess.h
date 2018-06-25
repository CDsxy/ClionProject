//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_ACCESS_H
#define CLIONPROJECT_ACCESS_H

#include "board.h"
#include <math.h>
#include <stdlib.h>

int Assess(void);
int SituationEvaluate(int player);
int RowAndLineCalculate(int chess1, int chess2);
int DiagonalCalculate(int chess1, int chess2);
int LineAssess(int a,int b,int chess1,int chess2,int length,int aMIn);
int EmptyPointEvaluate(Point location);

#endif //CLIONPROJECT_ACCESS_H
