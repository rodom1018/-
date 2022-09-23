#include <iostream>

int my_array[100010];
int record[100010];
long long ans = 0;

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);

    for(int  i=1 ; i<=n ; i++) scanf("%d", &my_array[i]);

    int left_p = 1;
    int right_p = 1;

    while(right_p<=n){
        //cout << left_p <<"//" << right_p << endl;
        int now_left = my_array[left_p];
        int now_right = my_array[right_p];

        if(record[now_right] == 0){
            // 중복된 것이 없을 경우 .
            record[now_right] ++ ;
            ans += (right_p - left_p)+1 ;
            right_p += 1;
        }else{
            // 중복된 것이 있을 경우 .
            while(now_right != now_left){
                record[now_left] -- ;
                left_p+=1;
                now_left = my_array[left_p];
            }

            record[now_left]--;
            left_p+=1;
        }
    }

    printf("%lld", ans);

}