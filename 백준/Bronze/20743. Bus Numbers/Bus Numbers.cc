#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> dp(400001,0);

    for(int i = 1; i < 1000; i++){
        for(int j = i; j < 1000; j++ ){
            int val = i*i*i+j*j*j;
            if(val > 400000) break;
            dp[val] += 1;
        }
    }

    int N;
    cin >> N;
    if (N < 1729) cout << "none";
    else{
        int e = N;
        while(e > 0 && dp[e] < 2) e--;
        cout << e;
    }
    

    return 0;
}