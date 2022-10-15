#include <iostream>

using namespace std;

int arr[5][5], tmp_arr[5][5];

void print_array(){
    for(int i=0; i<5 ; i++){
        printf("\n");
        for(int j=0; j<5 ; j++){
            printf("%d |", tmp_arr[i][j]);
        }

    }
}
int main(void){
    for(int i=0; i<5;i++){
        for(int j=0; j<5 ; j++){
            arr[i][j] = i*5 + j;
        }
    }

    //시계
    for(int i=0; i<5 ; i++){
        for(int j=0; j<5 ; j++) tmp_arr[j][5-1-i] = arr[i][j];
    }
    print_array();

    //반시계
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) tmp_arr[5-1-j][i] = arr[i][j];
    }
    print_array();


}