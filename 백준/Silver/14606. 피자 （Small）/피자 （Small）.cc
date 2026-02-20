#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> dp(2,0);
    dp.push_back(1);
    for(int i= 3; i < N+1; i++){
        int Max_benefit = 0;
        for(int j = 1; j < i; j++){
            Max_benefit = max(Max_benefit,(i-j)*j+dp[j]+dp[i-j]);
        }
        dp.push_back(Max_benefit);
    }

    cout << dp[N];
    return 0;
}