
#include <stdio.h>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct cmp1{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;
    }
};

struct sample{
    int x;
    int y;
    int z;
};
bool cmp(const struct sample& s1, const struct sample & s2 ){
    return s1.z < s2.z;
}
int main(void){

    ///////////////////////////////////////////////////////////////////////////
    /////////////////////stack ///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    stack<int> my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    cout << my_stack.top() << endl;
    my_stack.pop();
    cout << my_stack.top() << endl;
    my_stack.pop();

    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);
    cout << my_queue.front() << endl;
    cout << my_queue.back() << endl;


    ///////////////////////////////////////////////////////////////////////////
    //////////////////////string - 문자열 //////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    string s1 = "donghyeon";
    string s2 = "donghyeon";
    if(s1 == s2) cout << "true !! "<< endl;

    //string 에는 split 같은 아주 좋은 함수가 없다
    //그러니까 문자열은 앵간하면 파이썬 을 써야한다 ...

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////해시(map)////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    map<string,int> m;
    m.insert({"cam",3000});
    m.insert({"donghyeon", -1});

    cout << m["cam"] << endl;
    cout << m["donghyeon"] << endl;
    //m의 시작부분에서 1만큼 이동한 위치에 있는 특정 데이터를 삭제
    m.erase(m.begin()+1); 
    //key값으로 데이터 삭제
    m.erase("han");
    //map의 모든 데이터를 삭제
    m.erase(m.begin(), m.end()); 또는 m.clear();
    
    ///////////////////////////////////////////////////////////////////////////
    //////////////////////////////memset////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////    
    #include <string.h> // string.h 파일이 필요합니다.
    #include <stdio.h>

    int main (){

        char a[20];

        // 1바이트마다 모두 65로 초기화
        // 배열을 채울 때는 sizeof()함수를 사용하면 됩니다.
        // sizeof 함수 - 배열의 전체 바이트 크기를 반환합니다.
        memset(a, 65, sizeof(a));

        // 출력을 통해 확인
        for(int i = 0; i < (sizeof(a)/sizeof(char)); i++){
            printf("%c\n", a[i]);
        }

    }
    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////vector + 구조체 정렬 ///////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    vector<struct sample> v_c;
    v_c.push_back({1,2,3});
    v_c.push_back({2,2,2});
    v_c.push_back({3,2,1});

    sort(v_c.begin(), v_c.end(), cmp);

    cout<<"v_c"<<endl;
    for(int i=0; i<v_c.size(); i++){
        cout << v_c[i].z << endl;
    }

    ///////////////////////////////////////////////////////////////////////////
    /////////////////////////////////우선순위 큐(힙큐) //////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    //우선순위 큐 ( 최대 힙 )
    priority_queue<int> pq;
    pq.push(2);
    pq.push(4);
    pq.push(8);
    pq.push(16);
    cout << pq.top()<<endl;
    pq.pop();
    cout << pq.top()<<endl;
    pq.pop();

    //우선순위 큐 ( 최소 힙)
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(16);
    pq2.push(8);
    pq2.push(4);
    pq2.push(2);
    cout<< pq2.top() << endl;
    pq2.pop();
    cout << pq2.top() << endl;
    pq2.pop();

    //pair<int, int> 정렬.  (최대 힙)
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq3;
    pq3.push(make_pair(1,2));
    pq3.push(make_pair(3,4));
    pq3.push(make_pair(5,6));

    cout << pq3.top().first << "//" << pq3.top().second << endl;

    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////////////deque / //////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    #include <deque>

    using namespace std;

    int main(void){
        deque<int> dq;
        dq.push_front(1);
        dq.push_back(2);
        dq.push_back(3);
        dq.pop_back();
        dq.pop_front();
        dq.size();
}

}
