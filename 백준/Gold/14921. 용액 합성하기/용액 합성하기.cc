#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<int> fluid;
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        fluid.push_back(tmp);
    }

    int L = 0;
    int R = N-1;
    int res = 1e9;

    while(L < R){
        int val = fluid[R]+fluid[L];
        if (val == 0){
            cout << 0; return 0;
        }
        else if (val > 0){
            if (abs(res) > abs(val))
                res = val;
            R -= 1;
        }
        else{
            if (abs(res) > abs(val))
                res = val;
            L += 1;
        }   
    }

    cout << res;
    return 0;
}