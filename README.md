! 코테 알고리즘 마지막 점검용 !

[python 문자열]
https://jimmy-ai.tistory.com/62

[ c++ 문법 ]
1. sort
(오름차순)
int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
sort(a, a+10);

(내림차순)
bool compare(int a, int b){
  return a > b ;
}
sort(a, a+10, compare);

(구조체를 정렬)

struct Point{
  int x;
  int y;
};

bool compare(const Point &p1, const Point &p2){
  if(p1.x < p2.x){
    return true;
  }else if(p1.x == p2.x){
    return p1.y < p2.y;
  }else{
    return false;
   }  
}

sort(a, a+10 , compare);


2. 스택
#include <iostream>
#include <stack>

using namespace std;

int main(){

	// 스택 생성
	stack<int> s;


	// push
	s.push(3);
	s.push(2);
	s.push(1);


	// top
	cout << "top element: " << s.top() << '\n';
	// pop
	s.pop(); // 1이 삭제
	s.pop(); // 2가 삭제


	// size
	cout << "stack size: " << s.size() << '\n';


	// empty
	cout << "Is it empty?: " << (s.empty() ? "Yes" : "No") << '\n';

	return 0;

}
  
  
3. 큐

#include <queue>

queue<int> q;

queue.push(element);
queue.pop();
queue.front();
queue.back();
queue.size();
queue.empty();

4. 우선순위 큐
#include <queue>
priority_queue<int> pq;
pq.push(5);
pq.push(1);
pq.push(7);

    struct cmp{
        bool operator()(int a, int b){
            return a>b;
        }
    }
    #include <queue>

    priority_queue<int> q1; // 루트가 최대인 우선순위 큐 선언
    priority_queue<int, vector<int>, greater<int>>; // 루트가 최소값인 우선순위 큐 선언
    priority_queue<int, vector<int>, cmp>;// 루트가 최소값인 우선순위 큐 선언
    
    
주의 ! 그냥 배열 정렬 compare때에 비해
1) struct 에 쌓여있고 , 
2) 거꾸로다 ! 아래와 같은 때라면 12345 같이 오름차이지만, 최대 숫자가 나오는 힙 ( 최대힙 ) 이다 . 
struct compare {
	bool operator()(const Struct& s1, const Struct& s2) {
		return s1.compare_value < s2.compare_value;
	}
};

priority_queue<Struct, vector<Struct>, compare> pq;

우선순위 큐에 pair가 들어가게 작성해야 할 경우가 있다면 다음과 같이 작성할 수 있습니다. T에 pair<int, int> 가 들어가는 것 뿐입니다.
아래와 같이 선언하면, pair에서 first 값을 기준으로 Max-Heap 동작을 합니다.
priority_queue<pair<int, int>> pq;

만약 pair<int, int> 형을 우선순위 큐에서 사용하고 싶은데, Min-Heap으로 동작하게 하려면 똑같은 방법으로 아래와 같이 작성합니다.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> pq;

==================================================


[ 구현 ]

[ 그리디 ]
그리디를 풀 때에는 이렇게 " 탐욕적으로 풀어도 될련지 ? " 를 꼭 생각해보자 . <- 그리디, dp 구분에 필요한 생각임. 

[ dp ]
	- 최적 부분 구조 ( optimal substructure) 
	- 중복되는 부분 문제 ( overlapping subproblem ) 일 경우 사용 
바텀업으로  푸는 걸 디폴트로 하자 ! 
