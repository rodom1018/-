#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};
int main(void){

    priority_queue<int, vector<int>, greater<int>> pq; // 그냥 넣으면 최대힙 . greater 넣으면 최소힙.
    vector<pair<int, int>> class_list;
    int ans = 0;
    int n;
    scanf("%d", &n);

    for(int i=0 ; i<n ; i++){
        int start, end ;
        scanf("%d %d", &start, &end);

        class_list.push_back(make_pair(start, end));
    }

    sort(class_list.begin() , class_list.end());

    for(int i=0; i<n; i++){
        int begin = class_list[i].first;
        int end = class_list[i].second-1;

        while(pq.size() !=0 && pq.top() < begin) pq.pop();

        pq.push(end);

        if(pq.size() > ans) ans = pq.size();
    }

    printf("%d", ans);

}