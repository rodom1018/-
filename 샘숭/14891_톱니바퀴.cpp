#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int my_top[5][20];
int store_top[5][20];


void print_top(){
    for(int i=1; i<=4; i++){
        printf("\n");
        for(int j=1; j<=10; j++){
            printf("%d ", my_top[i][j]);
        }
    }
    printf("\n");
}
void rotate(int num , int ticks){

    for(int i=9; i<=8+ticks; i++){
        my_top[num][i] = my_top[num][i-ticks];
    }
    for(int i=8 ; i>ticks ; i--){
        my_top[num][i] = my_top[num][i-ticks];
    }

    for(int i=1 ; i<=ticks ; i++){
        my_top[num][i] = my_top[num][i+8];
    }
}

void rotate_inverse(int num, int ticks){
    for(int i=1 ; i<=ticks; i++){
        my_top[num][i+8] = my_top[num][i];
    }

    for(int i=1 ; i<=8-ticks ; i++){
        my_top[num][i] = my_top[num][i+ticks];
    }

    for(int i=9; i<=8+ticks ; i++){
        my_top[num][i-ticks] = my_top[num][i];
    }
}

void dfs(int now, int going, int banghang){
    if((now ==1 && going == -1) || (now==4 && going ==1) ) return;

    if(going == 1){
        if(store_top[now][3] != store_top[now+1][7]){
            if(banghang == 1){
                rotate_inverse(now+1 , 1);
                dfs(now+1, 1, -1);
            }
            else{
                rotate(now+1, 1);
                dfs(now+1, 1, 1);
            }
        }
        else return;

    }else{
        //if(now==4 && going ==-1) printf("들어오죠");
        if(store_top[now][7] != store_top[now-1][3]){
            if(banghang == 1){
                rotate_inverse(now-1 , 1);
                dfs(now-1, -1 , -1);
            }
            else{
                rotate(now-1, 1);
                dfs(now-1, -1 , 1);
            }
        }
        else return;
    }
}
int main(void){
    for(int i=1 ; i <=4 ; i++){
        string temp;
        cin >> temp;
        for(int j=1 ; j<=8; j++){
            if(temp[j-1] == '1') my_top[i][j] = 1;
            else my_top[i][j] = 0;
        }
    }

    int n;
    scanf("%d", &n);

    for(int tc=0 ; tc<n ; tc++){
        int top_num, banghang;
        scanf("%d %d", &top_num, &banghang);

        for(int a=1; a<=4; a++){
            for(int b=1; b<=8;b++){
                store_top[a][b] = my_top[a][b];
            }
        }

        if(banghang == 1) rotate(top_num, 1);
        else rotate_inverse(top_num , 1);
        dfs(top_num, 1, banghang);
        dfs(top_num , -1, banghang);
        //print_top();
    }

    int score = 0;

    if(my_top[1][1] == 1) score+=1;
    if(my_top[2][1] == 1) score+=2;
    if(my_top[3][1] == 1) score+=4;
    if(my_top[4][1] == 1) score+=8;
    //print_top();
    printf("%d", score);

}

/*
my_top[1][1] = 1;
my_top[1][2] = 0;
my_top[1][3] = 1;
my_top[1][4] = 0;
my_top[1][5] = 1;
my_top[1][6] = 1;
my_top[1][7] = 1;
my_top[1][8] = 1;

rotate(1, 3);

for(int i=1; i<=8; i++) printf("%d", my_top[1][i]);
printf("\n");

my_top[1][1] = 1;
my_top[1][2] = 0;
my_top[1][3] = 1;
my_top[1][4] = 0;
my_top[1][5] = 1;
my_top[1][6] = 1;
my_top[1][7] = 1;
my_top[1][8] = 1;

rotate_inverse(1, 3);

for(int i=1; i<=8; i++) printf("%d", my_top[1][i]);
printf("\n");
 */