#include <iostream>

using namespace std;

int main(){

    int res_val = -1;
    int res_r,res_c;

    for(int r = 1; r <= 9; r++){
        for(int c = 1; c <= 9; c++){
            int tmp;
            cin >> tmp;
            if (res_val < tmp){
                res_val = tmp;
                res_r = r;
                res_c = c;
            }
        }
    }
    cout << res_val << endl;
    cout << res_r << " " << res_c;


    return 0;
}