#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> meet;


    while(N--){
        int s,e;
        cin >> s >> e;
        meet.push_back({s,1});
        meet.push_back({e,-1});
    }

    sort(meet.begin(),meet.end());


    int res = 0;
    int cur = 0;
    for(auto &t: meet){
        cur += t.second;
        if (t.second > 0) res = max(res,cur);
    }

    cout << res;

    return 0;
}