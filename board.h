//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_BOARD_H
#define CLIONPROJECT_BOARD_H

#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 15
#define INFINITE 2147483647
#define DEPTH 2

typedef struct point{
    int x;
    int y;
} Point;

int board[BOARD_SIZE][BOARD_SIZE];
int chessKind;
Point nextStep;

int main(int argc, char *argv[]);
void FirstStep(void);
int JudgeChessKind(void);
void Scanf(void);
void RecordChess(int x,int y);
void RecordOppentChess(int x,int y);

#endif //CLIONPROJECT_BOARD_H
