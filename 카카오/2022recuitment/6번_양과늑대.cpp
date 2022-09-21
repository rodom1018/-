#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> tree;
int my_max = -1 ;

void dfs(int now, vector<int> can_go , int now_sheep, int now_wolf, vector<int> info){

    if(info[now] == 0){
        //양일때
        now_sheep += 1;
        if(my_max < now_sheep) my_max = now_sheep;
    }else{
        //늑대
        now_wolf+=1;
        if(now_sheep <= now_wolf) return;
    }

    for (int i = 0; i < tree[now].size(); i++){
        can_go.push_back(tree[now][i]);
    }

    for(int i = 0 ; i<can_go.size(); i++){
        int going_to = can_go[i];
        vector<int> temp_go = can_go;
        temp_go.erase(temp_go.begin()+i);
        dfs(going_to , temp_go, now_sheep, now_wolf, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;

    for(int i=0 ;i<20; i++){
        vector<int> temp;
        tree.push_back(temp);
    }

    for(int i=0; i<edges.size(); i++){
        int temp_start = edges[i][0];
        int temp_end = edges[i][1];

        tree[temp_start].push_back(temp_end);
    }

    vector<int> can_go;

    dfs(0, can_go, 0, 0, info);
    answer = my_max;
    return answer;
}