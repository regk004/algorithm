#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M,T,P;
    cin >> N >> M >> T;

    vector<int> seq(N);
    vector<bitset<100001>> dp(N);
    for(int i = 0; i < N; i++){
        cin >> seq[i];
    }

    cin >> P;
    P -= 1;
    dp[P][seq[P]] = 1;

    for(int i = 1; i <= T; i++){
        if (P+i >= N) break;
        dp[P+i] = (dp[P+i-1] | dp[P+i-1] << seq[P+i]);
    }

    for(int i = 1; i <= T; i++){
        if (P-i < 0) break;
        for(int j = 0; min(i,j)*2+max(i,j) <= T; j++){
            if (P+j >= N) break;
            dp[P+j] = (dp[P+j] | dp[P+j] << seq[P-i]);
        }
    }


    for(int i = P; i < N; i++){
        if (dp[i][M]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}