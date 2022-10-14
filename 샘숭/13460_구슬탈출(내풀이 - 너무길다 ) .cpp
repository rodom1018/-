#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int n, m ;

int blue_x;
int blue_y;
int red_x;
int red_y;
int o_x;
int o_y;

int temp_x;
int temp_y;

int going_up(int x, int y, char my_map[15][15]){
    temp_x = x;
    temp_y = y;
    while(true){
        temp_x = temp_x-1;

        if(temp_x == o_x && temp_y == o_y){
            temp_x = 0;
            temp_y = 0;
            return 1;
        }

        if(my_map[temp_x][temp_y] == '#' || my_map[temp_x][temp_y] == 'B' || my_map[temp_x][temp_y] == 'R'){
            temp_x = temp_x+1;
            //printf("going_up : %d %d\n", temp_x, temp_y);
            return 0;
        }
    }
}

int going_down(int x, int y, char my_map[15][15]){
    temp_x = x;
    temp_y = y;
    while(true){
        temp_x = temp_x + 1;

        if(temp_x == o_x && temp_y == o_y){
            temp_x = 0;
            temp_y = 0;
            return 1;
        }

        if(my_map[temp_x][temp_y] == '#' || my_map[temp_x][temp_y] == 'B' || my_map[temp_x][temp_y] == 'R'){
            temp_x = temp_x-1;
            return 0;
        }
    }
}

int going_right(int x, int y, char my_map[15][15]){
    temp_x = x;
    temp_y = y;
    while(true){
        temp_y = temp_y + 1;

        if(temp_x == o_x && temp_y == o_y){
            temp_x = 0;
            temp_y = 0;
            return 1;
        }

        if(my_map[temp_x][temp_y] == '#'|| my_map[temp_x][temp_y] == 'B' || my_map[temp_x][temp_y] == 'R'){
            temp_y = temp_y-1;
            return 0;
        }
    }
}

int going_left(int x, int y, char my_map[15][15]){
    temp_x = x;
    temp_y = y;
    while(true){
        temp_y = temp_y - 1;

        if(temp_x == o_x && temp_y == o_y){
            temp_x = 0;
            temp_y = 0;
            return 1;
        }

        if(my_map[temp_x][temp_y] == '#' || my_map[temp_x][temp_y] == 'B' || my_map[temp_x][temp_y] == 'R'){
            temp_y = temp_y+1;
            return 0;
        }
    }
}

int answer = 98765432;

void print_map(char my_map[15][15]){
    for(int a=1; a<=10; a++){
        for(int b=1; b<=10 ; b++){
            printf("%c  ", my_map[a][b]);
        }
        printf("\n");
    }
}

void dfs(int turn, int now_blue_x , int now_blue_y, int now_red_x , int now_red_y, char my_map[15][15]){
    //if(turn == 5) printf("%d  %d %d   %d  %d\n", now_blue_x, now_blue_y, now_red_x, now_red_y, answer);
    //if(turn == 5) print_map(my_map);
    if(turn >= 10) return;
    int blue_result;
    int red_result;

    int temp_blue_x;
    int temp_blue_y;
    int temp_red_x;
    int temp_red_y;

    // 1. 위로 가기
    if(now_blue_x < now_red_x){
        blue_result = going_up(now_blue_x, now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';

        red_result= going_up(now_red_x, now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';
    }else{
        red_result = going_up(now_red_x , now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';

        blue_result = going_up(now_blue_x , now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';
    }

    if(blue_result != 1) {
        if (now_blue_x != temp_blue_x || now_blue_y != temp_blue_y || now_red_x != temp_red_x ||now_red_y != temp_red_y) {
            if (red_result == 1) {
                if (answer > turn + 1) answer = turn + 1;
            } else {
                dfs(turn + 1, temp_blue_x, temp_blue_y, temp_red_x, temp_red_y, my_map);
            }
        }
    }

    int x_diff = abs(temp_blue_x - o_x) + abs(temp_blue_y - o_y);
    int y_diff = abs(temp_red_x - o_x) + abs(temp_red_y - o_y);
    int diff = x_diff - y_diff;

    if(blue_result == 1 && red_result == 1){
        if(diff != 0){
            if (answer > turn + 1) answer = turn + 1;
        }
    }
    my_map[now_red_x][now_red_y] = 'R';
    my_map[temp_red_x][temp_red_y] = '.';
    my_map[now_blue_x][now_blue_y] = 'B';
    my_map[temp_blue_x][temp_blue_y] = '.';
    my_map[o_x][o_y]= 'O';
    //2. 아래 가기
    if(now_blue_x > now_red_x){
        blue_result = going_down(now_blue_x, now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';

        red_result= going_down(now_red_x, now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';
    }else{
        red_result = going_down(now_red_x , now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';

        blue_result = going_down(now_blue_x , now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';
    }
    if(blue_result != 1) {
        if (now_blue_x != temp_blue_x || now_blue_y != temp_blue_y || now_red_x != temp_red_x ||now_red_y != temp_red_y) {
            if (red_result == 1) {
                if (answer > turn + 1) answer = turn + 1;
            } else {
                dfs(turn + 1, temp_blue_x, temp_blue_y, temp_red_x, temp_red_y, my_map);
            }
        }
    }

    x_diff = abs(temp_blue_x - o_x) + abs(temp_blue_y - o_y);
    y_diff = abs(temp_red_x - o_x) + abs(temp_red_y - o_y);
    diff = x_diff - y_diff;

    if(blue_result == 1 && red_result == 1){
        if(diff != 0){
            if (answer > turn + 1) answer = turn + 1;
        }
    }

    my_map[now_red_x][now_red_y] = 'R';
    my_map[temp_red_x][temp_red_y] = '.';
    my_map[now_blue_x][now_blue_y] = 'B';
    my_map[temp_blue_x][temp_blue_y] = '.';
    my_map[o_x][o_y]= 'O';

    //3. 우측 가기.
    if(now_blue_y > now_red_y){
        blue_result = going_right(now_blue_x, now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';

        red_result= going_right(now_red_x, now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';
    }else{
        red_result = going_right(now_red_x , now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';

        blue_result = going_right(now_blue_x , now_blue_y,my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';
    }

    if(blue_result != 1) {
        if (now_blue_x != temp_blue_x || now_blue_y != temp_blue_y || now_red_x != temp_red_x ||now_red_y != temp_red_y) {
            if (red_result == 1) {
                if (answer > turn + 1) answer = turn + 1;
            } else {
                dfs(turn + 1, temp_blue_x, temp_blue_y, temp_red_x, temp_red_y, my_map);
            }
        }
    }

    x_diff = abs(temp_blue_x - o_x) + abs(temp_blue_y - o_y);
    y_diff = abs(temp_red_x - o_x) + abs(temp_red_y - o_y);
    diff = x_diff - y_diff;

    if(blue_result == 1 && red_result == 1){
        if(diff != 0){
            if (answer > turn + 1) answer = turn + 1;
        }
    }

    my_map[now_red_x][now_red_y] = 'R';
    my_map[temp_red_x][temp_red_y] = '.';
    my_map[now_blue_x][now_blue_y] = 'B';
    my_map[temp_blue_x][temp_blue_y] = '.';
    my_map[o_x][o_y]= 'O';

    //4. 좌측 가기
    if(now_blue_y < now_red_y){
        blue_result = going_left(now_blue_x, now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';

        red_result= going_left(now_red_x, now_red_y, my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';
    }else{
        //printf("%d %d\n", now_red_x, now_red_y);
        red_result = going_left(now_red_x , now_red_y ,my_map);
        temp_red_x = temp_x;
        temp_red_y = temp_y;
        my_map[now_red_x][now_red_y] = '.';
        my_map[temp_red_x][temp_red_y] = 'R';

        blue_result = going_left(now_blue_x , now_blue_y, my_map);
        temp_blue_x = temp_x;
        temp_blue_y = temp_y;
        my_map[now_blue_x][now_blue_y] = '.';
        my_map[temp_blue_x][temp_blue_y] = 'B';
    }
    if(blue_result != 1) {
        if (now_blue_x != temp_blue_x || now_blue_y != temp_blue_y || now_red_x != temp_red_x ||now_red_y != temp_red_y) {
            if (red_result == 1) {
                if (answer > turn + 1) answer = turn + 1;
            } else {
                dfs(turn + 1, temp_blue_x, temp_blue_y, temp_red_x, temp_red_y, my_map);
            }
        }
    }
    x_diff = abs(temp_blue_x - o_x) + abs(temp_blue_y - o_y);
    y_diff = abs(temp_red_x - o_x) + abs(temp_red_y - o_y);
    diff = x_diff - y_diff;

    if(blue_result == 1 && red_result == 1){
        if(diff != 0){
            if (answer > turn + 1) answer = turn + 1;
        }
    }

    my_map[now_red_x][now_red_y] = 'R';
    my_map[temp_red_x][temp_red_y] = '.';
    my_map[now_blue_x][now_blue_y] = 'B';
    my_map[temp_blue_x][temp_blue_y] = '.';
    my_map[o_x][o_y]= 'O';
}
int main(void){
    char my_map[15][15];
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++){
        char temp[15] ;
        scanf("%s", temp);
        for(int j=1; j<=m ; j++){
            my_map[i][j] = temp[j-1];

            if(temp[j-1] == 'O'){
                o_x = i;
                o_y = j;
            }

            if(temp[j-1] == 'B'){
                blue_x = i;
                blue_y = j;
            }

            if(temp[j-1] == 'R'){
                red_x = i;
                red_y = j;
            }
        }
    }

    //print_map(my_map);
    dfs(0, blue_x , blue_y , red_x , red_y , my_map);
    if(answer != 98765432) printf("%d", answer);
    else printf("-1");
}