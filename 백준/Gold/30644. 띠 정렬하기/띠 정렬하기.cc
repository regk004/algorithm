#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N;
    vector<pair<int,int>> seq;

    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        seq.push_back({tmp,i});
    }

    sort(seq.begin(),seq.end());

    int cnt = 0;
    for(int i = 1; i < N; i++){
        if (abs(seq[i-1].second -seq[i].second) > 1) cnt ++;    
    }

    cout << cnt;
    
    return 0;
}
