//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_ACCESS_H
#define CLIONPROJECT_ACCESS_H

#include "board.h"
#include <math.h>

int Access(void);
int SituationEvaluate(int player);
int RowAndLineAccess(int chess1,int chess2);
int DiagonalAccess(int chess1,int chess2);
int EmptyPointEvaluate(Point location);

#endif //CLIONPROJECT_ACCESS_H
