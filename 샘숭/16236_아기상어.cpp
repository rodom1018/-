#include <string>
#include <vector>
#include <queue>
using namespace std;
int n;
int my_map[22][22];

int shark_r;
int shark_c;
int shark_l;
int answer = 0 ;

void init(){
    scanf("%d", &n);

    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            int temp;
            scanf("%d", &temp);
            my_map[a][b]=temp;

            if(temp == 9){
                shark_r = a;
                shark_c = b;
                shark_l = 2;
            }
        }
    }
}

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

struct queue_info{
    int r;
    int c;
    int depth;
};

queue_info bfs(int start_r , int start_c){

    deque<queue_info> q;
    vector<queue_info> now_fishes;

    q.push_back({start_r, start_c, 0});
    int visited[22][22] = {0,};

    int distance = 9999;
    int out_flag = 0;
    while(out_flag==0 && q.size() != 0){
        int current_r = q.front().r;
        int current_c = q.front().c;
        int current_d = q.front().depth;
        q.pop_front();
        if(visited[current_r][current_c] != 0) continue;
        //if(start_r == 4 && start_c == 1 ) printf("%d %d %d\n", current_r , current_c, current_d);
        visited[current_r][current_c] = 1;

        for(int i=0; i<4 ; i++){
            int temp_r = current_r + dx[i];
            int temp_c = current_c + dy[i];

            if(temp_r <=0 || temp_c <=0 || temp_r > n || temp_c > n) continue;

            if(shark_l >= my_map[temp_r][temp_c]){
                //갈 수 있는 길 !
                //printf("들어오시죠 ? %d %d %d\n", temp_r , temp_c , my_map[temp_r][temp_c]);
                if(my_map[temp_r][temp_c] != 0 && shark_l > my_map[temp_r][temp_c]){
                    //이미 1) 가까운 순에 어긴 생선이라 후보가 아님
                    if(now_fishes.size() != 0 && now_fishes[0].depth < current_d+1){
                        out_flag = 1;
                        break;
                    }

                    now_fishes.push_back({temp_r , temp_c, current_d+1});
                    distance = current_d + 1;
                }else{
                    q.push_back({temp_r, temp_c, current_d+1});
                }
            }
        }
    }

    int best_r = 2222;
    int best_c = 2222;
    for(int i=0; i<now_fishes.size(); i++){
        if(now_fishes[i].r < best_r){
            best_r = now_fishes[i].r;
            best_c = now_fishes[i].c;
        }else if(now_fishes[i].r == best_r && now_fishes[i].c < best_c){
            best_r = now_fishes[i].r;
            best_c = now_fishes[i].c;
        }
    }
    //printf("current_r ,current_c : %d %d // best_r, best_c: %d %d \n", start_r, start_c, best_r , best_c);
    shark_r = best_r;
    shark_c = best_c;
    if(now_fishes.size() != 0 ) answer += distance;
    struct queue_info result = {best_r , best_c, distance};
    return result;
}

void draw_map(){
    for(int i=1; i<=4 ; i++){
        for(int j=1; j<=4 ; j++){
            printf("%d / ", my_map[i][j]);
        }
        printf("\n");
    }
}
int main(void){
    init();
    int eating = 0;
    while(true){
        my_map[shark_r][shark_c]  = 0 ;
        struct queue_info temp_result = bfs(shark_r, shark_c);

        if(temp_result.r == 2222 && temp_result.c == 2222) break;
        shark_r = temp_result.r ;
        shark_c = temp_result.c ;
        my_map[shark_r][shark_c] = 9;
        eating++;

       // draw_map();
        if(eating >= shark_l){
            eating = 0;
            shark_l ++;
        }

        //printf("%d ..?", answer);
    }

    printf("%d\n", answer);

}