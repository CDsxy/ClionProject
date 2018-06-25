#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "assess.h"
#include "generator.h"
#include "alphabeta.h"

int main(int argc, char **argv) {
    Scanf();
    FirstStep();
    chessKind=JudgeChessKind();
    AlphaBeta(DEPTH,-INFINITE,INFINITE);
    printf("%d %d",nextStep.x,nextStep.y);


    return 0;
}
