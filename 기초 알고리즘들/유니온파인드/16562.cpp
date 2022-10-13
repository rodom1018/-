#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int need_money[10010];
int friend_root[10010];
int total_money = 0;
int find(int x){
    if(friend_root[x] != x){
        return find(friend_root[x]);
    }else{
        return friend_root[x];
    }
}

void combine(int temp_a , int temp_b){
    temp_a = find(temp_a);
    temp_b = find(temp_b);
    //printf("%d %d / %d %d\n", temp_a, temp_b , result_temp_a , result_temp_b);
    if(need_money[temp_a] <= need_money[temp_b]) {
        friend_root[temp_b] = temp_a;
    }else{
        friend_root[temp_a] = temp_b;
    }
}
void init(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1 ; i<=n; i++) friend_root[i] = i;

    for(int i=1; i<=n; i++){
        int temp;
        scanf("%d", &temp);

        need_money[i] = temp;
    }

    for(int i=0; i<m ; i++){
        int a, b ;
        scanf("%d %d", &a, &b);
        combine(a,b);
    }

    /*
    for(int i=1 ; i<=5 ; i++){
        printf("%d / ",friend_root[i]);
    }
     */
}
int main(void){
    init();
    int now =1;

    for(int i=1; i<=n; i++){
        if(friend_root[i] == i){
            total_money += need_money[i];
        }
    }

    if(k < total_money) printf("Oh no");
    else printf("%d", total_money);
}