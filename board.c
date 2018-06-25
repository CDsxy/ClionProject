#include "board.h"

int JudgeChessKind(void){
    int i,j,num=0;
    int chessman=1;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if(board[i][j] != 0){
                num++;
            }
        }
    }

    if(num%2 == 1){
        chessman=2;
    }

    return chessman;
}

void Scanf(void){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0; BOARD_SIZE > j; j++){
            scanf("%d",&board[i][j]);
        }
    }
}

void FirstStep(void){
    int cnt=0;
    Point firstStep=(Point){7,7};
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j] != 0){
                firstStep=(Point){i,j+1};
                cnt++;
            }
        }
    }
    if(cnt == 0){
        printf("%d %d",firstStep.x,firstStep.y);
        exit(0);
    }
    if(cnt == 1){
        printf("%d %d",firstStep.x,firstStep.y);
        exit(0);
    }
    if(cnt > 1){
        return ;
    }
}

void RecordChess(int x,int y){
    if(chessKind == 1) board[x][y]=1;
    if(chessKind == 2) board[x][y]=2;
}

void RecordOppentChess(int x,int y){
    if(chessKind == 1) board[x][y]=2;
    if(chessKind == 2) board[x][y]=1;
}

//
// Created by 17738 on 2018/6/17.
//

