//
// Created by 17738 on 2018/6/17.
//

#include "alphabeta.h"

int AlphaBeta(int depth, int alpha, int beta) {
    int val=0;
    Point legalPoint[NEIBOR_NUM];
    if (depth == 0) {
        return Access();
    }
    int num=LegalMoves(legalPoint);
    int cnt=0;
    while (cnt<num) {
        MakeNextMove(depth,cnt,legalPoint);
//        PutBoard();
        val = -AlphaBeta(depth-1, -beta, -alpha);
        UnmakeMove(cnt,legalPoint);
        cnt++;
        if (val >= beta) {
            return beta;
        }
        if (val > alpha) {
            alpha = val;
        }
    }

    return alpha;
}

void MakeNextMove(int depth,int i,Point *point){
    if( (depth+DEPTH)%2 == 0 ){
        RecordChess(point[i].x,point[i].y);
    }
    if( (depth+DEPTH)%2 == 1 ){
        RecordOppentChess(point[i].x,point[i].y);
    }
}

void UnmakeMove(int i,Point *point){
    board[point[i].x][point[i].y]=0;
}