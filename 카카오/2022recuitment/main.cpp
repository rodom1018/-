// 1번
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string convert(long n, long k){
    string temp_result = "";
    while(n>k){
        temp_result = to_string(n%k) + temp_result ;
        n /= k;
        // cout<<temp_result << "// " << n << endl;
    }
    temp_result = to_string(n) + temp_result;
    //cout << temp_result;
    return temp_result;
}

bool isPrime(long n) {
    if (n < 2) return false;
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(long n, long k){
    string con_string = convert(n, k );
    //cout<<con_string << endl; 잘되는거확인.
    long answer = 0;
    long start = 0;
    long len = 0;
    string cmp = "0";
    while(start < con_string.length()){
        while(con_string.substr(start+len , 1).compare(cmp) != 0){
            len += 1;
            if(start+len >= con_string.length()) break;
        }

        if(len == 0 ){
            start += 1;
            if(start >= con_string.length()) break;
            continue;
        }
        long now_num = stol(con_string.substr(start, len));
        //cout<< start << "//" << len << "//" << now_num << endl;
        if(isPrime(now_num)) answer ++ ;

        start += len;

        len = 0 ;

    }
    return answer;

}
int main() {
    long n, k;
    scanf("%ld %ld", &n, &k);
    long ans = solution(n, k);
    printf("%ld", ans);
    return 0;
}
