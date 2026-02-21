#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M,Q;
    cin >> N >> M >> Q;
    unordered_map<long long,int> edge;

    while(M--){
        long long a,b;
        int c;
        long long key;
        cin >> a >> b >> c;

        if (a > b) swap(a,b);
        
        key = a << 32LL | b;
        auto it = edge.find(key);
        if(it != edge.end()) it->second = min(it->second,c);
        else edge[key] = c;
        
    }

    while(Q--){
        long long s,e;
        long long key;
        cin >> s >> e;
        if (s > e) swap(s,e);

        key = s << 32LL | e;
        auto it = edge.find(key);
        if(it == edge.end()) cout << -1 << "\n";
        else cout << it->second << "\n";
    }

    return 0;
}