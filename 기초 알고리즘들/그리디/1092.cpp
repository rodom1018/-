#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

vector<int> crain;
vector<int> box;

int main(void){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        crain.push_back(temp);
    }

    int m;
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        int temp;
        scanf("%d", &temp);
        box.push_back(temp);
    }

    sort(box.begin(), box.end(),greater<>());
    sort(crain.begin(), crain.end(), greater<>());
    int cannot= 1;
    int ans = 0;

    while(box.size() > 0 ){
        cannot = 1;
        int used = 0;
        for(int i=0; i<box.size(); i++) {

            if(used >= crain.size()) break;

            if (crain[used] >= box[i]) {
                box.erase(box.begin()+i);
                i--;
                used++;
                cannot = 0;
            }
        }

        if (cannot == 1) {
            printf("-1");
            break;
        }
        ans++;
    }

    if(cannot == 0 ) printf("%d", ans);
}
