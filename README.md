! 코테 알고리즘 마지막 점검용 !

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

==================================================

[ 구현 ]

[ 그리디 ]

[ dp ]

<< 그리디와 dp를 구분하는 마음가짐 >>
