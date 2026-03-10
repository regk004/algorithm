#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int M,t,N;
    cin >> M >> t >> N;

    queue<pair<int,int>> left;
    queue<pair<int,int>> right;

    vector<int> res(N,0);

    for(int i = 0; i < N; i++){
        int time;
        string tp;
        cin >> time >> tp;
        if (tp == "left") left.push({time,i});
        else right.push({time,i});
    }


    bool is_left = true;
    int cur_time = 0;

    while(!left.empty() || !right.empty()){
        int cap = M;
        if(is_left){
            while(!left.empty() && cur_time >= left.front().first && cap > 0){
                res[left.front().second] = cur_time+t;
                left.pop();
                cap--;
            }
        }
        else{
            while(!right.empty() && cur_time >= right.front().first && cap > 0){
                res[right.front().second] = cur_time+t;
                right.pop();
                cap--;
            }
        }

        if(cap != M){
            cur_time += t;
            is_left = !is_left;
        }
        else{
            if((right.empty() && !left.empty()) || (!right.empty() && !left.empty() && right.front().first > left.front().first)){
                if(is_left)
                    cur_time = max(cur_time,left.front().first);
                else{
                    cur_time = max(cur_time,left.front().first)+t;
                    is_left = !is_left;
                }
            }
            else{
                if(!is_left)
                    cur_time = max(cur_time,right.front().first);
                else{
                    cur_time = max(cur_time,right.front().first)+t;
                    is_left = !is_left;
                }
            }
        }
    }

    for(int v: res)
        cout << v << endl;


    return 0;
}