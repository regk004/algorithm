#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N;
    vector<int> seq(N);
    set<int> num_lst;
    for(int i = 0; i < N; i++){
        cin  >> seq[i];
        num_lst.insert(seq[i]);
    }

    int dif_cnt = num_lst.size();
    int res;
    cin >> M;

    if (M <= N) cout << seq[M-1];
    else{
        res = dif_cnt + M-N-1;
        if (dif_cnt <= *num_lst.rbegin()){
            res = min(res,*num_lst.lower_bound(dif_cnt));
        }
        cout << res;
        
    }
    return 0;
}