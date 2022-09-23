#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dp[51][51];
int height[51];

int main(void){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n ; i++){
        int temp;
        scanf("%d", &temp);
        height[i] = temp;
    }

    int my_max = 0;

    for(int i=0; i<n; i ++){
        //i번째 건물 에서는 몇개가 보일까요 ?
        int now = 0;
        for(int j=0; j<n; j++){
            //i번째 건물에서, J번째 건물이 보일까요

            if(i==j) continue;

            //1번째에서 3번째 일 때 이미 세서
            //3번째에서 1번째가 보이는지 ? 는 dp로 해결합니다.
            if(i>j){
                if(dp[i][j] == 1) now+=1;
                continue;
            }

            int width = j - i;
            double step = (double) (height[j] - height[i]) / (double)width ;

            //무조건 낮은 번호 건물-> 높은 건물 서치하니까 상관없을거같고
            //i에서 j가 보이는지 ? 판별하는 for문
            int no_see= 0;
            for(int k=i+1 ; k<j; k++){
                /*
                if(i==4 && j== 11){
                    cout<<"why?" << endl;
                    cout << step << endl;
                    cout << double(height[i]) + double(step * (k-i)) << endl;
                    cout << double(height[k]) << endl;
                    cout<<"why?" << endl;
                }
                 */
                if(height[i] + step * (k-i) <= height[k]  ){
                    no_see = 1;
                    break;
                }
            }

            if(no_see ==0){
                dp[i][j] = 1;
                dp[j][i] = 1;
                now += 1;
            }
        }
        //cout << i <<" // " << now << endl;
        if(now > my_max) my_max = now;
    }

    printf("%d", my_max);

}