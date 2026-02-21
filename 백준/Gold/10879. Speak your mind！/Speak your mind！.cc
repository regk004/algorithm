#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define Max int(pow(2,16))+1

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dp(Max,1e9);
    dp[0] = 6;
    int cur = 1;
    for(int i = 1; i < 18; i++){
        dp[cur] = i;
        cur *= 2;
    }

    for(int i = 3; i < 50001; i++){
        int j = 1;
        while(j < i){
            dp[i] = min(dp[i],dp[j]+dp[i-j]+4);
            j *= 2;
        }
        dp[i] = min(dp[i],dp[j]+dp[j-i]+4);
    }

    int T,N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << dp[abs(N)] << endl;
    }

    return 0;
}