#include <string>
#include <vector>
#include <iostream>
using namespace std;

int board[11][11];

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> fail_ans = {-1};
    int my_max = 0;
    for(int j=0 ; j<11 ; j++) answer.push_back(0);
    int score=0;

    for(int i=0;i<11; i++){

        int apeach = info[i];

        for(int j=0 ;j<=n; j++){
            if(j> apeach) {
                /*
                if(i ==1 && j ==4){
                    cout << board[0][0] << " / " << board[0][1] << " / " << board[0][2]
                         << " / " << board[0][3] << " / " << board[0][4] << "/ " << board[0][5] << endl;

                    cout << board[i-1][j-apeach-1] << " !!!" << endl;
                }
                */
                if (i != 0) board[i][j] = max(board[i - 1][j - apeach-1] + (1 << (9 - i)), board[i - 1][j]);
                else board[i][j] += (1 << 9);
            }else{
                if( i != 0) board[i][j] = board[i-1][j];
            }
            if(board[i][j] > my_max) my_max = board[i][j];
        }
    }
    for(int j=9; j>=n; j--){
        if(((my_max>>j) & 1 ) == 1){
            score += (j + 1) ;
            answer[9-j] = info[9-j] + 1 ;
        }
    }

    int win =0 ;
    for(int j=0; j<n ; j++){
        if(answer[j] == 0 && info[j] == 0 ) continue;
        if(answer[j] > info[j]) win += (10-j);
        else win -= (10-j);
    }

    for(int i=0; i<11 ;i++){
        for(int j=0; j<n ; j++){
            cout<< board[i][j] << " / ";
        }
        cout<<endl;
    }
    if(win<0) return fail_ans;
    else return answer;
}


int main() {

    int n = 9;
    vector<int> info = {0,0,1,2,0,1,1,1,1,1,1};

    vector<int>  ans = solution(n, info);
    for(int j=0; j<n ;j++){
        cout << ans[j] << "/";
    }
    return 0;
}

