#include "generator.h"

int LegalMoves(Point * point){
    int i,j,k;
    int num=0;

    for(k=0;k<NEIBOR_NUM;k++){
        point[k]=(Point){0,0};
    }

    for(i=0;i<BOARD_SIZE;i++){
        for(j=0;j<BOARD_SIZE;j++){
            if(board[i][j] == 0){
                if(NeighborJudge(i,j) == 1){
                    point[num]=(Point){i,j};
                    num++;
                }
            }
        }
    }

    int a=0;
    for(i=0;i<NEIBOR_NUM;i++){
        if(point[i].x !=0||point[i].y !=0){
            a++;
        }
    }

//	Order(num);

    return a;
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
            if(n >= BOARD_SIZE){
                n=BOARD_SIZE-1;
                break;
            }
            if(board[m][n] != 0){
                sta=1;
                break;
            }
        }
    }
    return sta;
}

void Order(int num,Point *point){
    int i,j;
    Point temp;
    int scoreofPoint[NEIBOR_NUM]={0,};
    for(i=0;i<num;i++){
        scoreofPoint[i]=EmptyPointEvaluate(point[i]);
        for(j=0;j<i;j++){
            if(scoreofPoint[i]>scoreofPoint[j]){
                temp=point[i];
                point[i]=point[j];
                point[j]=temp;
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

Point Finding(int target){
    int i;
    int grades[NEIBOR_NUM]={0,};

    for(i=0;i<NEIBOR_NUM;i++){
        if(VaildPoint[i].x!=0  || VaildPoint[i].y!= 0 ){
            RecordChess(VaildPoint[i].x,VaildPoint[i].y);
            grades[i]=Access();
            if(grades[i] == target){
                return VaildPoint[i];
            }
            RemoveChess(VaildPoint[i].x,VaildPoint[i].y);
        }
    }
    //best=Best(grades);

//	return VaildPoint[best];
}



//
// Created by 17738 on 2018/6/17.
//

