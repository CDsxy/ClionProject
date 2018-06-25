#include "generator.h"

int LegalMoves(Point * point){
    int num=0;
    for(int k=0;k<NEIBOR_NUM;k++){
        point[k]=(Point){0,0};
    }

    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j] == 0){
                if(NeighborJudge(i,j) == 1){
                    point[num]=(Point){i,j};
                    num++;
                }
            }
        }
    }

    int cnt=0;
    for(int i=0;i<NEIBOR_NUM;i++){
        if(point[i].x !=0||point[i].y !=0){
            cnt++;
        }
    }

	Order(point);

    return cnt;
}

int NeighborJudge(int i,int j){
    int sta=0;
    int m,n;
    for(m=i-2;m<i+3;m++){
        if(m < 0){
            m=0;
        }
        if(m >= BOARD_SIZE){
            m=BOARD_SIZE-1;
            break;
        }
        for(n=j-2;n<j+3;n++){
            if(n < 0){
                n=0;
            }
            if (n >= BOARD_SIZE) {
                n = BOARD_SIZE - 1;
                break;
            } else if (board[m][n] != 0) {
                    sta = 1;
                    break;
            }
        }
    }
    return sta;
}

void Order(Point *point1){
    int scoreTemp;
    Point temp;
    int scoreOfPoint[NEIBOR_NUM]={0,};
    for(int i=0;i<NEIBOR_NUM;i++){
        scoreOfPoint[i]=EmptyPointEvaluate(point1[i]);
        for(int j=0;j<i;j++){
            if(scoreOfPoint[i]>scoreOfPoint[j]){
                scoreTemp=scoreOfPoint[i];
                scoreOfPoint[i]=scoreOfPoint[j];
                scoreOfPoint[j]=scoreTemp;
                temp=point1[i];
                point1[i]=point1[j];
                point1[j]=temp;
            }
        }
    }

}

int Best(int *grades){
    int best,i;
    for(i=0;i<NEIBOR_NUM;i++){
        if(grades[i]>grades[i+1]){
            best=i;
        }
    }
    return best;
}

Point Finding(int target,const int *scorelist,const Point *point){
   int store[NEIBOR_NUM]={0};
   int j=0;


   for(int i=0;i<NEIBOR_NUM;i++){
       if(scorelist[i] == target){
           store[j]=i;
           j++;
       }
   }

   srand((unsigned)time(0));
   int a=rand()%j;
   return point[ store[a] ];

}



//
// Created by 17738 on 2018/6/17.
//

