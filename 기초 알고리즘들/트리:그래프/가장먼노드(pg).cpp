#include <string>
#include <vector>
#include <queue>

using namespace std;

int my_map[20002][20002];
int visited[20002];
int my_distance[20002];
void init(vector<vector<int>> edge){
    for(int i=0 ; i<edge.size(); i++){
        vector<int> temp = edge[i];
        my_map[temp[0]][temp[1]] = 1;
        my_map[temp[1]][temp[0]] = 1;
    }

    for(int i=0; i< 20002; i++) my_distance[i] = 20005;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    init(edge);
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));

    int max_distance = 0;
    while(q.size() !=0){
        int now = q.front().first;
        int now_distance =q.front().second;
        //printf("%d -  %d\n", now,now_distance);
        if(my_distance[now] > now_distance) my_distance[now] = now_distance;
        if(max_distance < now_distance) max_distance = now_distance ;
        visited[now] = 1;
        q.pop();

        for(int i=1 ; i<=20000;i++){
            if(my_map[now][i] == 1 && visited[i] == 0){
                q.push(make_pair(i, now_distance+1));
                visited[i] = 1;
            }
        }
    }

    for(int i=1; i<=20000; i++){
        if(my_distance[i] == max_distance) answer++;
    }
    //printf("%d ?", max_distance);
    return answer;
}

int main(void){
    int n = 6;
    vector<vector<int>> edge = {{3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2}};
    int ans = solution(n, edge);
    printf("%d", ans);
}