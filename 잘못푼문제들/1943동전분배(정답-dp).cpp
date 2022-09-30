#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int dp[110][50010];
int main(void){
    for(int tc = 0; tc < 3 ; tc++){

        memset(dp , 0 ,sizeof(dp));

        int n;
        scanf("%d", &n);
        vector<pair<int,int>> money;
        int total_money = 0 ;
        for(int i=0; i<n ; i++){
            int cost, num;
            scanf("%d %d", &cost, &num);
            money.push_back(make_pair(cost, num));
            total_money += cost * num;
        }

        if(total_money % 2 != 0 ){
            printf("0\n");
            continue;
        }

        int half_money = total_money / 2;
        for(int i=0; i<money.size(); i++){
            for(int j=1; j<=half_money; j++) {

                if (j % money[i].first == 0 && j <= money[i].first * money[i].second) dp[i + 1][j] = 1;
                else dp[i + 1][j] = max(dp[i][j], dp[i+1][j]);

                if(dp[i][j] == 1){
                    for(int k=1 ; k <= money[i].second; k++){
                        dp[i+1][j+money[i].first*k] = 1;
                    }
                }
            }
        }
        //printf("%d // %d // ", hwa, hee);
        if(dp[money.size()][half_money] == 1) printf("1\n");
        else printf("0\n");
    }
}
