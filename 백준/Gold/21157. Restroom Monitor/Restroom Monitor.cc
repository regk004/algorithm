#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S,N;
    cin >> S >> N;

    vector<pair<int,int>> toilet;
    int s;
    char n;
    for(int i = 0; i < N; i++){
        cin >> s >> n;
        if (n == 'y')
            toilet.push_back({s,1});
        else 
            toilet.push_back({s,0});
    }

    sort(toilet.begin(),toilet.end());

    long long need = 0;
    long long not_need = 0;
    long long max_full = 0;

    for( auto [t,tp] : toilet){
        if(tp == 1) need++;
        else not_need++;

        long long cur_full = not_need - (long long) (S-1)*t;

        if (cur_full > max_full) max_full = cur_full;

        if(need+max_full > t  || need+not_need > (long long)t*S){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}