#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;

    cin >> N >> M;
    vector<long long> dp(N+1,1e15);
    vector<vector<long long>> cost(N+1,vector<long long>(M+1,1e15));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < min(M+1,N-i+1); j++){
            long long tmp;
            cin >> tmp;
            cost[i][j] = tmp;
        }
    }
    cost[N][0] = 0;
    
    dp[0] = cost[0][0];
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < min(i+1,M+1); j++){
            dp[i] = min(dp[i],dp[i-j]-cost[i-j][j]+cost[i][0]);
        }
    }
    
    cout << dp[N];
    return 0;
}   