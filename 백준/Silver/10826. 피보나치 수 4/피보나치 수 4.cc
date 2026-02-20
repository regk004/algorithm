#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

int main(){
    int N;
    vector<vector<int>> dp;
    cin >> N;
    dp.push_back({0});
    dp.push_back({1});

    for(int i = 2;  i < 10001; i++){
        vector a = dp[i-1];
        vector b = dp[i-2];
        vector<int> nxt;
        int tmp = 0;
        for(int j = 0; j < max(a.size(),b.size()); j++){
            int cur = 0;
            if (j < a.size()) cur += a[j];
            if (j < b.size()) cur += b[j];
            cur += tmp;
            tmp = 0;

            if (cur >= 10) cur %= 10, tmp += 1;
            nxt.push_back(cur);
        }
        if (tmp) nxt.push_back(tmp);
        dp.push_back(nxt);
    }

    for(int i = dp[N].size()-1; i > -1; i--){
        cout << dp[N][i];
    }

    return 0;
}