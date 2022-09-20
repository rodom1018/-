#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int my_board[1001][1001] = {0,};

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    //
    for(int i=0 ; i<skill.size(); i++){
        int type = skill[i][0];
        int start_row = skill[i][1];
        int start_col = skill[i][2];
        int end_row = skill[i][3];
        int end_col = skill[i][4];
        int score = skill[i][5];

        if(type == 1) {
            my_board[start_row][start_col] -= score;
            my_board[end_row+1][end_col+1] -= score;
            my_board[end_row+1][start_col] += score;
            my_board[start_row][end_col+1] += score;
        }else{
            my_board[start_row][start_col] += score;
            my_board[end_row+1][end_col+1] += score;
            my_board[end_row+1][start_col] -= score;
            my_board[start_row][end_col+1] -= score;
        }

        /*
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                cout<< my_board[r][c] << " ";
            }
            cout<<endl;
        }
         */
    }
    for(int r=0; r<board.size(); r++){
        for(int c=0; c<board[0].size(); c++){
            if(c!=0) my_board[r][c] = my_board[r][c-1] + my_board[r][c];
        }
    }

    for(int c=0 ; c<board[0].size(); c++){
        for(int r=0; r<board.size(); r++){
            if(r!=0) my_board[r][c] = my_board[r-1][c] + my_board[r][c];
        }
    }

    for(int r=0; r<board.size(); r++){
        for(int c=0; c<board[0].size(); c++){
            if(my_board[r][c] + board[r][c] > 0 ) answer ++ ;
        }
    }

    //


    return answer;
}


int main() {

    vector<vector<int>> board = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
    vector<vector<int>> skill = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};

    cout << solution(board, skill);

    return 0;
}

