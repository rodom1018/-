#include <iostream>
#include <algorithm>
#include <string.h>

int n;
int my_array[2020];
long long ans = 0;

using namespace std;

int main(void){

    scanf("%d", &n);

    for(int i=0 ; i<n ; i++){
        scanf("%d", &my_array[i]);
    }

    sort(my_array , my_array +n);

    for(int i=0 ; i<n ; i++){

        int left = 0;
        int right = n-1;
        int target = i;
        int now_num = my_array[target];

        while(left < right){
            //cout << my_array[left] << " / " << my_array[right] << " / " << my_array[target] << endl;

            if(my_array[left] + my_array[right] == now_num){
                if(left == target){
                    left ++;
                    continue;
                }

                if(right == target){
                    right --;
                    continue;
                }

                ans++;
                break;

            }else if(my_array[left] + my_array[right] < now_num){
                left ++ ;
            }else{
                right -- ;
            }
        }
    }

    printf("%lld", ans);

}