#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

struct my_struct{
    int r; // 행
    int c; // 열
    int s; // 속력
    int d; // 이동 방향
    int z; // 크기 .
};

vector<my_struct> sharks;
vector<int> dead;
int r,c,m;

int temp_r;
int temp_c;
int temp_direct;
void shark_move(int current_r, int current_c, int speed, int direct){
    if(direct == 1 || direct ==2){
        //위
        temp_r = current_r;
        temp_c = current_c;
        temp_direct =direct;

        speed = speed % (2*(r-1));

        while(speed>0){
            if(temp_direct == 2){
                speed -= (r-temp_r);
                temp_r =r;
                if(speed <0) temp_r += speed;
                else temp_direct = 1;
            }else{
                speed -= (temp_r -1);
                temp_r = 1;
                if(speed <0) temp_r -= speed;
                else temp_direct = 2;
            }
        }
    }else if(direct == 3 || direct == 4){
        //아래
        temp_r = current_r;
        temp_c = current_c;
        temp_direct = direct;

        speed = speed % (2*(c-1));

        while(speed>0){
            if(temp_direct == 3){
                speed -= (c-temp_c);
                temp_c =c;
                if(speed <0) temp_c += speed;
                else temp_direct = 4;
            }else{
                speed -= (temp_c -1);
                temp_c = 1;
                if(speed <0) temp_c -= speed;
                else temp_direct = 3;
            }
        }
    }
}

void where_shark(){
    printf("-----------------------------\n");
    for(int i=0; i<sharks.size(); i++){
        printf(" %d %d : %d %d %d \n", sharks[i].r, sharks[i].c, sharks[i].s,  sharks[i].z, sharks[i].d);
    }
    printf("-----------------------------\n");
}
int main(void){
    int result = 0;
    scanf("%d %d %d", &r, &c, &m);

    for(int i=1; i<=m ; i++){
        int temp_r, temp_c, temp_s, temp_d, temp_z;
        scanf("%d %d %d %d %d", &temp_r, &temp_c, &temp_s, &temp_d, &temp_z);
        struct my_struct temp;
        temp.r = temp_r;
        temp.c = temp_c;
        temp.d = temp_d;
        temp.s = temp_s;
        temp.z = temp_z;
        sharks.push_back(temp);
        dead.push_back(0);
    }

    for(int turn=1; turn<=c; turn++){
        //where_shark();
        //printf("%d\n", result);
        //n번째 턴에
        //1. 낚시왕이 오른쪽으로 한 칸 이동한다.
        //2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.
        //상어를 잡으면 격자판에서 잡은 상어가 사라진다.
        int capture_index = -1;
        int min_r = 1000;
        for(int i=0 ; i<sharks.size(); i++){
            if(dead[i]==1) continue;
            if(sharks[i].c ==turn){
                if(sharks[i].r < min_r){
                    min_r = sharks[i].r;
                    capture_index = i;
                }
            }
        }

        if(capture_index != -1){
            result += sharks[capture_index].z;
            dead[capture_index] = 1;
        }

        //3. 상어가 이동한다. (같은 칸이 되면 큰 상어만 남게되고 ... )
        for(int i=0; i<sharks.size(); i++){
            if(dead[i] == 1) continue;
            shark_move(sharks[i].r,sharks[i].c,sharks[i].s, sharks[i].d);

            sharks[i].d = temp_direct;
            sharks[i].r = temp_r;
            sharks[i].c = temp_c;
        }

        //(같은 칸이 되면 큰 상어만 남게되고 ... )
        for(int a=0 ; a<sharks.size(); a++){
            if(dead[a] == 1) continue;
            for(int b=a+1; b<sharks.size(); b++){
                if(dead[b] == 1) continue;

                if((sharks[a].r == sharks[b].r )&& (sharks[a].c == sharks[b].c)){
                    if(sharks[a].z > sharks[b].z) dead[b] = 1;
                    else dead[a] = 1;
                }
            }
        }

    }
    printf("%d", result);
}