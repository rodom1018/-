#include <iostream>
#include <algorithm>
#include <string.h>

int n;
long long my_array[2020];
long long sum_list[4004004];
long long pointer = 0;
long long ans = 0;

using namespace std;

int main(void){

    scanf("%d", &n);

    for(int i=0 ; i<n ; i++){
        scanf("%d", &my_array[i]);
    }

    for(int now = 0; now< n ; now++){

        memset(sum_list, 0, sizeof(sum_list));
        pointer= 0 ;
        for(int i=0; i<n ; i++){
            if(i == now) continue;

            for(int j=i+1; j<n; j++){
                if(j == now) continue;
                sum_list[pointer++] = my_array[i] + my_array[j];
            }
        }

        sort(sum_list , sum_list+pointer);
        /*
        if(now == 9){
            printf("\n!!");
            for(int i=0; i<pointer ; i++){
                printf("%d / ", sum_list[i]);
            }

        }
         */
        int now_num = my_array[now];

        int left = 0;
        int right = pointer;

        while(left <= right){
            int mid =  (left+right) / 2;

            if(now_num == sum_list[mid]){
                //정답!!
                //cout << now_num << "// " ;
                ans++;
                break;
            }else if(now_num < sum_list[mid]){
                right = mid- 1;
            }else{
                left = mid+ 1;
            }

        }
    }

    printf("%lld", ans);

}