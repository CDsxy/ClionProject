#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "access.h"
#include "generator.h"
#include "alphabeta.h"

int main(int argc, char **argv) {
    InitBoard();
    board[7][7]=1;
    board[6][7]=2;
    int target;
    chessKind=JudgeChessKind();
    Point nextStep;
    target=AlphaBeta(DEPTH,-INFINITE,INFINITE);
    LegalMoves(vaildPoint);
//  nextStep=Finding(target);
    printf("%d\n",target);
/*  RecordChess(nextStep.x,nextStep.y);
    printf("%d %d\n",nextStep.x,nextStep.y);
*/
    PutBoard();
//	printf("%d %d",nextstep.x,nextstep.y);
/*	while(1){
		Scanf();V
		LegalMoves();
		int target=AlphaBeta(4,-INFINITE,INFINITE);
		nextstep=Choosing(target);
		printf("%d %d",nextstep.x,nextstep.y);
	}
*/

    return 0;
}
