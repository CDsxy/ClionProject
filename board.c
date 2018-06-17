#include "board.h"

void Initboard(void){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            board[i][j]=0;

        }
    }
}

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

void RecordChess(int x,int y){
    if(chessKind == 1) board[x][y]=1;
    if(chessKind == 2) board[x][y]=2;
}

void RecordOppentChess(int x,int y){
    if(chessKind == 1) board[x][y]=2;
    if(chessKind == 2) board[x][y]=1;
}

void RemoveChess(int x,int y){
    board[x][y]=0;
}

void Putboard(void){
    int i,j;
    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}//
// Created by 17738 on 2018/6/17.
//

