#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


int get_sum(int s,int e,vector<int> &Sum, vector<int> &arr){
    return Sum[s] - Sum[e] + arr[e];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> seq;
    vector<int> suf_sum;
    vector<vector<int>> total_dp(M+1,vector<int>(N,1e9));
    vector<vector<int>> clean_dp(M+1,vector<int>(N,1e9));
    map<pair<int,int>,set<int>> clean_lst; 
    map<pair<int,int>,set<int>> total_lst; 


    int Sum = 0;
    for(int i = 0; i < N; i ++){
        int n;
        cin >> n;
        Sum += n;
        seq.push_back(n);
    }

    for(int i = 0; i < N; i++){
        suf_sum.push_back(Sum);
        Sum -= seq[i];
    }
    
    for(int m = 0; m < M+1; m++){
        clean_dp[m][N-1] = 0;
        total_dp[m][N-1] = 0;

        if (m != 0){
        clean_lst[{m,N-1}].insert(N-1);
        total_lst[{m,N-1}].insert(N-1);
        }
        for(int s = N-2; s > -1; s--){
    
            if (m == 0) {
                total_dp[0][s] = total_dp[0][s+1]+seq[s]*suf_sum[s+1];
                clean_dp[0][s] = clean_dp[0][s+1]+seq[s]*suf_sum[s+1];   
            }
            else {
                clean_lst[{m,s}] = total_lst[{m-1,s+1}];
                clean_lst[{m,s}].insert(s);
                clean_dp[m][s] = total_dp[m-1][s+1];
                
                total_lst[{m,s}] = total_lst[{m-1,s+1}];
                total_lst[{m,s}].insert(s);
                total_dp[m][s] = total_dp[m-1][s+1];
                
                for(int d = s+1; d < N; d++){
                    int cur = clean_dp[m][d];
                    for(int n = s; n < d; n++){
                        cur += seq[n]*get_sum(n+1,d,suf_sum,seq);
                    }

                    if(cur < total_dp[m][s]){
                        total_dp[m][s] = cur;
                        total_lst[{m,s}] = clean_lst[{m,d}];
                    }
                }
            }
        }
    }

    cout << total_dp[M][0] << "\n";
    for(int n : total_lst[{M,0}]) cout << n+1 << " ";
    
    return 0;
}
