#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin >> N >> K;

    vector<int> cost;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        cost.push_back(tmp);
    }

    sort(cost.begin(),cost.end());

    for(int i = 0; i < N-2; i++){
        int s = i+1, e = N-1;
        int cur_cost = K-cost[i];
        while(s < e){
            if(cost[s]+cost[e] > cur_cost) e--;
            else if(cost[s]+cost[e] < cur_cost) s++;
            else{
                cout << "JAH";
                return 0;
            }
        }
    }
    cout << "EI";
    return 0;
}