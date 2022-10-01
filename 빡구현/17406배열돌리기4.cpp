#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int my_r[10];
int my_c[10];
int my_far[10];
int n, m, rules;
int my_min = 98765432;

void my_print(int r, int c, int temp_array[55][55]){
    printf("\n\n");
    for(int i=1 ; i<=r ; i++){
        for(int j=1; j<=c; j++){
            printf("%d ", temp_array[i][j]);
        }
        printf("\n");
    }
}

void calculate(int n , int m ,int now_array[55][55]){
    int temp_sum = 0;
    for(int i=1; i<=n ; i++){
        temp_sum =0;

        for(int j=1 ; j<=m; j++){
            temp_sum += now_array[i][j];
        }

        if(temp_sum < my_min) my_min = temp_sum ;

    }
}
void dfs(int count, vector<int> visited, int now_array[55][55]){
    if(count == rules){
        calculate(n,m,now_array);
        return;
    }

    for(int i=1; i<=rules; i++){
        if(visited[i] == 1) continue;

        vector<int> temp = visited;
        temp[i] = 1;

        int temp_array[55][55];
        for(int a=1; a<=54; a++){
            for(int b=1; b<=54; b++){
                temp_array[a][b] = now_array[a][b];
            }
        }

        int far = my_far[i];
        int r = my_r[i];
        int c = my_c[i];

        for(int d=far; d>0; d--){
            int now_r= r-d;
            int now_c;
            int prev = 0;
            int next = 0;

            for(now_c = c-d ; now_c<=c+d ; now_c++){
                next = temp_array[now_r][now_c];
                temp_array[now_r][now_c] = prev;
                prev = next;
            }

            now_c = c+d;
            for(now_r = r-d+1 ; now_r <= r+d ; now_r ++){
                next = temp_array[now_r][now_c];
                temp_array[now_r][now_c] = prev;
                prev = next;
            }
            //my_print(5,6);
            now_r = r+d;
            for(now_c = c+d-1 ; now_c >= c-d; now_c--){
                next = temp_array[now_r][now_c];
                temp_array[now_r][now_c] = prev;
                prev = next;
            }

            now_c =c-d;
            for(now_r = r+d-1 ; now_r >= r-d; now_r--){
                next = temp_array[now_r][now_c];
                temp_array[now_r][now_c] = prev;
                prev = next;
            }
        }
        dfs(count+1, temp , temp_array);
    }
}
int main(void){
    int my_array[55][55];

    scanf("%d %d %d", &n, &m , &rules);

    for(int i=1; i<=n ;i++){
        for(int j=1; j<=m ; j++){
            int temp;
            scanf("%d", &temp);
            my_array[i][j] = temp;
        }
    }

    for(int i=1; i<=rules; i++){
        int r, c, far;
        scanf("%d %d %d", &r, &c, &far);
        my_r[i] = r;
        my_c[i] = c;
        my_far[i] = far;
    }

    vector<int> visited = {0,0,0,0,0,0,0};
    dfs(0, visited, my_array);

    printf("%d", my_min);

}
