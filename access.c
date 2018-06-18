#include "access.h"

int Access(void) {
    int totalScore;
    int scoreOfAI = SituationEvaluate(chessKind);
    int scoreOfOpponent = SituationEvaluate(3-chessKind);

    totalScore = scoreOfAI - scoreOfOpponent;

    if (chessKind == 1) {
        return totalScore;
    } else if (chessKind == 2) {
        return -totalScore;
    }

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

    int score1 = RowAndLineAccess(chess1, chess2);
    int score2 = DiagonalAccess(chess1, chess2);
    int score = score1 + score2;

    return score;
}

int RowAndLineAccess(int chess1, int chess2) {
    int i, j, n;
    int lineScore = 0;
    int rowScore = 0;
    int total1 = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == chess1) {
                int num = 1, cnt = 0;
                if (j - 1 < 0 || board[i][j - 1] == chess2) {
                    cnt = 1;
                }
                for (n = 1; n < 5; n++) {
                    if (board[i][j + n] == chess1) {
                        num++;
                    }
                    if (board[i][j + n] == 0) {
                        j += n;
                        break;
                    }
                    if (board[i][j + n] == chess2 || j + n >= BOARD_SIZE) {
                        if (cnt == 1) cnt = -1;
                        if (cnt == 0) cnt = 1;
                        j += n;
                        break;
                    }
                }
                switch (cnt) {
                    case -1:
                        rowScore += 0;
                        break;
                    case 0 :
                        rowScore += pow(10, num);
                        break;
                    case 1 :
                        rowScore += pow(10, num - 1);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    for (j = 0; j < BOARD_SIZE; j++) {
        for (i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == chess1) {
                int num = 1, cnt = 0;
                if (i - 1 < 0 || board[i - 1][j] == chess2) {
                    cnt = 1;
                }
                for (n = 1; n < 5; n++) {
                    if (board[i + n][j] == chess1) {
                        num++;
                    }
                    if (board[i + n][j] == 0) {
                        i += n;
                        break;
                    }
                    if (board[i + n][j] == chess2 || i + n >= BOARD_SIZE) {
                        if (cnt == 1) cnt = -1;
                        if (cnt == 0) cnt = 1;
                        i += n;
                        break;
                    }
                }
                switch (cnt) {
                    case -1:
                        lineScore += 0;
                        break;
                    case 0 :
                        lineScore += pow(10, num);
                        break;
                    case 1 :
                        lineScore += pow(10, num - 1);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    total1 = lineScore + rowScore;
    return total1;
}

int DiagonalAccess(int chess1, int chess2) {
    int i, j, k = 0;
    int x = 21;          //2*15-1-8(前后各四层不可能成五，不进行考虑)=21
    int n = 0;
    int total2 = 0;
    int leadingDiaScore = 0;
    int oppositeDiaScore = 0;

    int len[21] = {0,};
    for (i = 0; i < 11; i++) {
        len[i] = i + 5;
    }
    for (i = 0; i < 10; i++) {
        len[i + 11] = 14 - i;
    }                     //列出对角线方向上每层一维数组的长度。
//反对角线的评测，分为两块。
    for (i = 4; i < 15; i++) {
        for (j = 0; j < len[k]; j++) {
            if (board[j][i - j] == chess1) {
                int num = 1, cnt = 0;
                if (j - 1 < 0 || board[j - 1][i - j + 1] == chess2) {
                    cnt = 1;
                }
                for (n = 1; n < 5; n++) {
                    if (board[j + n][i - j - n] == chess1) {
                        num++;
                    }
                    if (board[j + n][i - j - n] == 0) {
                        j += n;
                        break;
                    }
                    if (board[j + n][i - j - n] == chess2 || j + n >= len[k]) {
                        if (cnt == 1) cnt = -1;
                        if (cnt == 0) cnt = 1;
                        j += n;
                        break;
                    }
                }
                switch (cnt) {
                    case -1:
                        oppositeDiaScore += 0;
                        break;
                    case 0 :
                        oppositeDiaScore += pow(10, num);
                        break;
                    case 1 :
                        oppositeDiaScore += pow(10, num - 1);
                        break;
                    default:
                        break;
                }
            }
        }
        k++;
    }

    for (i = 15; i < x + 4; i++) {
        for (j = i - 14; j < len[k]; j++) {
            if (board[j][i - j] == chess1) {
                int num = 1, cnt = 0;
                if (j - 1 < i - 14 || board[j - 1][i - j + 1] == chess2) {
                    cnt = 1;
                }
                for (n = 1; n < 5; n++) {
                    if (board[j + n][i - j - n] == chess1) {
                        num++;
                    }
                    if (board[j + n][i - j - n] == 0) {
                        j += n;
                        break;
                    }
                    if (board[j + n][i - j - n] == chess2 || j + n >= len[k]) {
                        if (cnt == 1) cnt = -1;
                        if (cnt == 0) cnt = 1;
                        j += n;
                        break;
                    }
                }
                switch (cnt) {
                    case -1:
                        oppositeDiaScore += 0;
                        break;
                    case 0 :
                        oppositeDiaScore += pow(10, num);
                        break;
                    case 1 :
                        oppositeDiaScore += pow(10, num - 1);
                        break;
                    default:
                        break;
                }
            }
        }
        k++;
    }
//主对角线计算同理
    int k1=10;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < len[k1]; j++) {
            if (board[j][i + j] == chess1) {
                int num = 1, cnt = 0;
                if (j - 1 < 0 || board[j - 1][i + j - 1] == chess2) {
                    cnt = 1;
                }
                for (n = 1; n < 5; n++) {
                    if (board[j + n][i + j + n] == chess1) {
                        num++;
                    }
                    if (board[j + n][i + j + n] == 0) {
                        j += n;
                        break;
                    }
                    if (board[j + n][i + j + n] == chess2 || j + n >= len[k]) {
                        if (cnt == 1)cnt = -1;
                        if (cnt == 0)cnt = 1;
                        j += n;
                        break;
                    }
                }
                switch (cnt) {
                    case -1:
                        leadingDiaScore += 0;
                        break;
                    case 0 :
                        leadingDiaScore += pow(10, num);
                        break;
                    case 1 :
                        leadingDiaScore += pow(10, num - 1);
                        break;
                    default:
                        break;
                }
            }
        }
        k1--;
    }

    int k2=9;
    for (i = 1; i < 11; i++) {
        for (j = i; j < len[k2]; j++) {
            if (board[j][j - i] == chess1) {
                int num = 1, cnt = 0;
                if (j - 1 < i || board[j - 1][j - 1 - i] == chess2) {
                    cnt = 1;
                }
                for (n = 1; n < 5; n++) {
                    if (board[j + n][j + n - i] == chess1) {
                        num++;
                    }
                    if (board[j + n][j + n - i] == 0) {
                        j += n;
                        break;
                    }
                    if (board[j + n][j + n - i] == chess2 || j + n >= len[k]) {
                        if (cnt == 1)cnt = -1;
                        if (cnt == 0)cnt = 1;
                        j += n;
                        break;
                    }
                }
                switch (cnt) {
                    case -1:
                        leadingDiaScore += 0;
                        break;
                    case 0 :
                        leadingDiaScore += pow(10, num);
                        break;
                    case 1 :
                        leadingDiaScore += pow(10, num - 1);
                        break;
                    default:
                        break;
                }
            }
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

