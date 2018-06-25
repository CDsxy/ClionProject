#include "assess.h"

int Assess(void) {
    int totalScore;
    int scoreOfAI = SituationEvaluate(chessKind);
    int scoreOfOpponent = SituationEvaluate(3-chessKind);

    totalScore = scoreOfAI - scoreOfOpponent;

    return totalScore;

}

int SituationEvaluate(int player) {
    char chess1, chess2;

    if (player == 1) {
        chess1 = 1;
        chess2 = 2;
    } else {
        chess1 = 2;
        chess2 = 1;
    }

    int score1 = RowAndLineCalculate(chess1, chess2);
    int score2 = DiagonalCalculate(chess1, chess2);
    int score = score1 + score2;

    return score;
}

int LineAssess(int a,int b,int chess1,int chess2,int length,int aMIn){
    int score=0;
    if(board[a][b] == chess1){
        int num=1,cnt=0,a0=a;
        a--;
        if(a<aMIn || board[a][b] == chess2){
            cnt=1;
        }
        for(int n=1;n<5;n++){
            a=a0+n;
            if (board[a][b] == chess1) {
                num++;
            }
            if (board[a][b] == 0) {
                break;
            }
            if (board[a][b] == chess2 || a >= length) {
                if (cnt == 1) cnt = -1;
                if (cnt == 0) cnt = 1;
                break;
            }
        }
        switch (cnt) {
            case -1:score += 0;break;
            case 0 :score += pow(10, num);break;
            case 1 :score += pow(10, num - 1);break;
        }
    }
    return score;
}

int RowAndLineCalculate(int chess1, int chess2) {
    int i, j = 0;
    int lineScore = 0;
    int rowScore = 0;
    int total1 = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            rowScore+=LineAssess(i,j,chess1,chess2,BOARD_SIZE,0);
        }
    }

    for (i = 0; j < BOARD_SIZE; j++) {
        for (j = 0; i < BOARD_SIZE; i++) {
            lineScore+=LineAssess(j,i,chess1,chess2,BOARD_SIZE,0);
        }
    }

    total1 = lineScore + rowScore;
    return total1;
}

int DiagonalCalculate(int chess1, int chess2) {
    int i, j, k = 0;
    int x = 21;          //2*15-1-8(前后各四层不可能成五，不进行考虑)=21
    int total2 = 0;
    int leadingDiaScore = 0;
    int oppositeDiaScore = 0;

    //列出对角线方向上每层一维数组的长度。
    int len[21] = {0,};
    for (i = 0; i < 11; i++) {
        len[i] = i + 5;
    }
    for (i = 0; i < 10; i++) {
        len[i + 11] = 14 - i;
    }

    //反对角线的评测，分为两块。
    //反对角线的上半部分
    for (i = 4; i < 15; i++) {
        for (j = 0; j < len[k]; j++) {
            oppositeDiaScore+=LineAssess(j,i-j,chess1,chess2,len[k],0);
        }
        k++;
    }

    //反对角线的下半部分
    for (i = 15; i < x + 4; i++) {
        for (j = i - 14; j < len[k]; j++) {
           oppositeDiaScore+=LineAssess(j,i-j,chess1,chess2,len[k],i-14);
        }
        k++;
    }
//主对角线计算同理
    //主对角线的上半部分
    int k1=10;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < len[k1]; j++) {
            leadingDiaScore+=LineAssess(j,i+j,chess1,chess2,len[k1],0);
        }
        k1--;
    }

    //主对角线的下半部分
    int k2=9;
    for (i = 1; i < 11; i++) {
        for (j = i; j < len[k2]; j++) {
           oppositeDiaScore+=LineAssess(j,i-j,chess1,chess2,len[k2],i);
        }
        k2--;
    }

    total2 = leadingDiaScore + oppositeDiaScore;
    return total2;
}

int EmptyPointEvaluate(Point location) {
    int totalDistance = 0;
    int x, y, i, j ;
    int diff_x=0,diff_y=0;

    x = location.x;
    y = location.y;

    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if(board[i][j] != 0){
                diff_x+=abs(i-x);
                diff_y+=abs(j-y);
            }
        }
    }

    totalDistance=diff_x+diff_y;
    return -totalDistance;
}
//
// Created by 17738 on 2018/6/17.
//

