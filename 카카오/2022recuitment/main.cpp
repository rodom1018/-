// 1번
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// cout << records[i].substr(0,5); 05:34
// cout << records[i].substr(5,5); 5961
// cout << records[i].substr(10,4) << endl; OUT

int calculate(string in_car, string out_car, vector<int> fees){
    string in_time = in_car.substr(0,5);
    string out_time = out_car.substr(0,5);

    int in_hour = stoi(in_time.substr(0,3));
    int in_min = stoi(in_time.substr(3,3));
    //cout<<in_hour << "// " <<in_min << endl;
    int out_hour = stoi(out_time.substr(0,3));
    int out_min = stoi(out_time.substr(3,3));
    //cout<<out_hour << "//" << out_min << endl;

    int diff_time = (out_hour - in_hour) * 60 + (out_min - in_min);
    // cout << diff_time << endl; 정상작동 !
    return diff_time;
}

int calculate_cost(int diff_time,vector<int> fees){

    int cost =fees[1] ;
    //cout << cost << endl;
    if(diff_time > fees[0]) {
        diff_time -= fees[0];

        int cost_hour = diff_time / fees[2];
        if(diff_time % fees[2] != 0 ) cost_hour +=1;

        cost += cost_hour * fees[3];
        //cout << cost << endl;
    }

    return cost;
}
vector<int> solution(vector<int> fees, vector<string> records) {

    vector<pair<int,int>> my_fees;

    vector<string> inside;

    for(int i=0; i<records.size(); i++){
        int flag = 0;
        int now_car = stoi(records[i].substr(5,5));

        for(int j=0; j<inside.size(); j++){
            int inside_car = stoi(inside[j].substr(5,5));

            if(now_car == inside_car){
                //입차한 차가 출차하는 경우.
                int diff_time = calculate(inside[j], records[i], fees);

                int fee_flag = 0;
                for(int k = 0; k<my_fees.size(); k++){
                    if(my_fees[k].first == now_car){
                        my_fees[k].second += diff_time;
                        fee_flag = 1;
                        break;
                    }
                }
                if(fee_flag == 0) my_fees.push_back(make_pair(now_car, diff_time));

                inside.erase(inside.begin() + j);
                flag = 1;

                break;
            }
        }

        if(flag == 0) inside.push_back(records[i]);
    }

    for(int j=0 ; j < inside.size(); j++){
        int now_car = stoi(inside[j].substr(5,5));
        int now_time = calculate(inside[j], "23:59 0000 OUT", fees);
        int fee_flag = 0;

        for(int k = 0; k<my_fees.size(); k++){
            if(my_fees[k].first == now_car){
                my_fees[k].second += now_time;
                fee_flag = 1;
                break;
            }
        }
        if(fee_flag == 0) my_fees.push_back(make_pair(now_car, now_time));
    }

    sort(my_fees.begin(), my_fees.end());
    /*
    for(int j=0; j< my_fees.size(); j++){
        cout << my_fees[j].first << " // " << my_fees[j].second << endl;
    }*/
    vector<int> answer;

    for(int i=0; i<my_fees.size(); i++){
        answer.push_back(calculate_cost(my_fees[i].second, fees));
    }

    return answer;
}


int main() {
    vector<int> fees = {180, 5000, 10, 600} ;
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> answer = solution(fees, records);

    for(int i=0 ; i<answer.size(); i++){
        cout<< answer[i] << endl;
    }

    return 0;
}
