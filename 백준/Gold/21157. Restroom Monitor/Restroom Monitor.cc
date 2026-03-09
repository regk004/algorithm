#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S,N;
    cin >> S >> N;

    priority_queue<pair<int,int>> pq;

    int s;
    char n;
    for(int i = 0; i < N; i++){
        cin >> s >> n;
        if (n == 'y')
            pq.push({s,1});
        else 
            pq.push({s,0});
    }


    int cur_t = pq.top().first;
    int need= 0;
    int not_need = 0;
    int need_only = 0;
    int total = 0;
    while(!pq.empty()){

        if (pq.top().first != cur_t){
            need_only += cur_t-pq.top().first;
            total += (cur_t-pq.top().first)*S;
            need_only = min(0,need_only-need);
            total = min(need_only,total-need-not_need);
            need = 0;
            not_need = 0;
            cur_t = pq.top().first;
        }

        if(pq.top().second == 1)
            need++;
        else 
            not_need++;
        pq.pop();
    }

    need_only += cur_t;
    total += cur_t*S;
    need_only = min(0,need_only-need);
    total = min(need_only,total-need-not_need);
    

    if(need_only < 0 || total < 0) 
        cout << "No";
    else
        cout << "Yes";

    return 0;
}