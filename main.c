#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "access.h"
#include "generator.h"
#include "alphabeta.h"

int main(int argc, char **argv) {
    Initboard();
    board[7][7]=1;
    board[6][7]=2;
    int target;
    chessKind=JudgeChessKind();
    Point nextStep;
    target=AlphaBeta(DEPTH,-INFINITE,INFINITE);
    LegalMoves(VaildPoint);
//  nextStep=Finding(target);
    printf("%d\n",target);
/*  RecordChess(nextStep.x,nextStep.y);
    printf("%d %d\n",nextStep.x,nextStep.y);
*/
    Putboard();
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
