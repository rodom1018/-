#include <iostream>
#include <algorithm>
#include <vector>

/*
그리디로 풀었으나 , 실패함 . 
[반례]
5
3 1
4 1
5 1
6 1
8 1
*/

using namespace std;
int main(void){
    for(int tc = 0; tc < 3 ; tc++){
        int n;
        cin >> n;
        vector<pair<int,int>> money;

        for(int i=0; i<n ; i++){
            int cost, num;
            cin >> cost >> num ;
            money.push_back(make_pair(cost,num));
        }

        sort(money.begin(), money.end(), greater<>());

        int hwa = 0;
        int hee = 0;
        for(int i=0; i<money.size(); i++){
            int now_cost, now_num;
            now_cost = money[i].first;
            now_num = money[i].second;
            //printf("%d ~ %d ~ ", now_cost, now_num);

            for(int j=0; j<now_num ; j++){
                if(hwa >= hee ) hee += now_cost;
                else hwa += now_cost;
            }
        }
        //printf("%d // %d // ", hwa, hee);
        if(hwa == hee) cout<<"1"<<endl;
        else cout<<"0" << endl;
    }
}
