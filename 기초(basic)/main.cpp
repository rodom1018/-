#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
using namespace std;

int n, m ;
int A[100001];
int B[100001];

void my_input(){
    scanf("%d", &n);

    for(int i=1 ; i<=n; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for(int i=1 ; i<=m; i++){
        scanf("%d", &B[i]);
    }
}

int main() {
    my_input();
    sort(A+1 , A+n+1);

    for(int i=1 ; i<=m ; i++){
        int start = 1;
        int end = n;
        int flag = 0;
        while(start <= end){
            int mid = ( start+end ) / 2;

            if(B[i] < A[mid]){
                end = mid - 1;
            }else if (B[i] == A[mid]){
                printf("1\n");
                flag = 1;
                break;
            }else {
                start = mid + 1;
            }
        }

        if(flag == 0) printf("0\n");
    }

}
