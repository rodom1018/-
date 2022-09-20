#include <string>
#include <vector>
#include <iostream>

using namespace std;

int best_score = 0;
vector<int> best_arrow = { 0,0,0,0,0,0,0,0,0,0,0 };
vector<int> score_board = {10,9,8,7,6,5,4,3,2,1,0};
void dfs(int now, int remain_arrow , vector<int> now_arrow,int score, vector<int> info){
    //cout << now << "/ " << remain_arrow << "/" << score << endl;
    if(remain_arrow<=0 || now>11) return;

    dfs(now+1 , remain_arrow, now_arrow, score, info);

    int use_arrow = remain_arrow - (info[now] + 1);
    if(use_arrow < 0 ) return;
    int use_score = score_board[now] + score;
    now_arrow[now] = (info[now] + 1);

    if(use_score > best_score){
        best_score = use_score;

        for(int i=0 ; i<best_arrow.size(); i++){
            best_arrow[i] = now_arrow[i];
        }
    }

    if(use_score == best_score){
        for(int i=10 ; i>=0; i--){
            if(now_arrow[i] == best_arrow[i]) continue;
            if(now_arrow[i] > best_arrow[i]){
                for(int i=0 ; i<best_arrow.size(); i++){
                    best_arrow[i] = now_arrow[i];
                }
                break;
            }

            break;
        }
    }
    /*
    for(int i=0 ; i<11; i++) printf("%d // " ,now_arrow[i]);
    printf("%d  %d !!", use_score, best_score);
    printf("\n");
    */
    dfs(now+1 , use_arrow, now_arrow, use_score, info);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    for(int i=0 ; i<11 ; i++){
        if(info[i] >0) score_board[i] = score_board[i] * 2;
    }

    dfs(0, n, best_arrow,0, info);

    int real_score = 0;
    for(int i=0 ; i<11 ;i++){
        if(best_arrow[i] == 0 && info[i] == 0 ) continue;
        if(best_arrow[i] > info[i]) real_score += (10-i);
        else real_score -= (10-i);
    }

    int arrows =0;
    if(real_score >0 ){
        for(int i=0 ; i<11; i++){
            answer.push_back(best_arrow[i]);
            arrows+=best_arrow[i];
        }

        answer[10] = n-arrows;
    }else{
        answer.push_back(-1);
    }

    return answer;
}


int main() {

    int n = 10;
    vector<int> info = {0,0,0,0,0,0,0,0,3,4,3};

    vector<int>  ans = solution(n, info);
    for(int j=0; j<11 ;j++){
        cout << ans[j] << "/";
    }
    return 0;
}

