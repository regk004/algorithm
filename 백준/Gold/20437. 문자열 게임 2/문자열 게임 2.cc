#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int K;
        string S;
        cin.ignore();
        getline(cin,S);
        cin >> K;
        vector<queue<int>> char_queue(26);

        int Max = 0;
        int Min = 1e9;
        int s,e;
        for(int i = 0; i < S.size(); i++){
            int c_idx = int(S[i]-97);
            char_queue[c_idx].push(i);
            if (char_queue[c_idx].size() == K){
                int length = i-char_queue[c_idx].front()+1;
                Max = max(Max,length);
                Min = min(Min,length);
                char_queue[c_idx].pop();
            }
        }
        if(Max == 0) cout << -1 << "\n";    
        else cout << Min << " " << Max << "\n";
    }

    return 0;
}