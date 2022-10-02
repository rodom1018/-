#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

char my_map[110][110];
int visited[110][110] = {0};

int n;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void dfs_R(int x, int y){
    if(my_map[x][y] != 'R') return;
    if(x<=0 || y<=0 || x>n || y>n) return;
    if(visited[x][y] == 1) return;

    visited[x][y] = 1;

    for(int i=0; i<=3; i++){
        int now_x = x + dx[i];
        int now_y = y+ dy[i];
        dfs_R(now_x, now_y);
    }
}

void dfs_G(int x, int y){
    if(my_map[x][y] != 'G') return;
    if(x<=0 || y<=0 || x>n || y>n) return;
    if(visited[x][y] == 1) return;

    visited[x][y] = 1;

    for(int i=0; i<=3; i++){
        int now_x = x + dx[i];
        int now_y = y+ dy[i];
        dfs_G(now_x, now_y);
    }
}

void dfs_B(int x, int y){
    if(my_map[x][y] != 'B') return;
    if(x<=0 || y<=0 || x>n || y>n) return;
    if(visited[x][y] == 1) return;

    visited[x][y] = 1;

    for(int i=0; i<=3; i++){
        int now_x = x + dx[i];
        int now_y = y+ dy[i];
        dfs_B(now_x, now_y);
    }
}

void dfs_RG(int x, int y){
    if(my_map[x][y] == 'B') return;
    if(x<=0 || y<=0 || x>n || y>n) return;
    if(visited[x][y] == 1) return;

    visited[x][y] = 1;

    for(int i=0; i<=3; i++){
        int now_x = x + dx[i];
        int now_y = y+ dy[i];
        dfs_RG(now_x, now_y);
    }
}

void print_map(){
    for(int i=1; i<=5; i++){
        printf("\n");
        for(int j=1; j<=5 ; j++){
            printf("%d ", visited[i][j]);
        }
    }
    printf("\n");
}

int main(void){

    scanf("%d", &n);

    for(int i=1 ; i<=n ; i++){
        string temp;
        cin >> temp;
        for(int j=1; j<=n ; j++){
            my_map[i][j] = temp[j-1];
        }
    }
    int usual = 0;
    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            if(visited[i][j] == 1) continue;
            usual++;
            if(my_map[i][j] == 'R') dfs_R(i,j);
            else if(my_map[i][j] == 'G') dfs_G(i,j);
            else if(my_map[i][j] == 'B') dfs_B(i,j);
            //print_map();
        }
    }

    memset(visited, 0, sizeof(visited));

    int not_usual = 0;

    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            if(visited[i][j] == 1) continue;
            not_usual++;
            if(my_map[i][j] == 'R' || my_map[i][j] == 'G') dfs_RG(i,j);
            else if(my_map[i][j] == 'B') dfs_B(i,j);
        }
    }


    printf("%d %d", usual, not_usual);

    return 0 ;
}
