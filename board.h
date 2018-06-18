//
// Created by 17738 on 2018/6/17.
//

#ifndef CLIONPROJECT_BOARD_H
#define CLIONPROJECT_BOARD_H

#include <stdio.h>
#define BOARD_SIZE 15
#define INFINITE 2147483647
#define DEPTH 4

typedef struct point{
    int x;
    int y;
} Point;


int board[BOARD_SIZE][BOARD_SIZE];
int chessKind;


int main(int argc, char *argv[]);
void InitBoard(void);
int JudgeChessKind(void);
void Scanf(void);
void RecordChess(int x,int y);
void RecordOppentChess(int x,int y);
void RemoveChess(int x,int y);
void PutBoard(void);

#endif //CLIONPROJECT_BOARD_H
