#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int backT(int depth,string &cur,string &cards, vector<bool> &v,vector<int> &res){

    if (depth == cards.size()) return 0;

    for(int i = 0; i < cards.size(); i++){
        if (!v[i]) {
            v[i] = true;
            cur += cards[i];
            res.push_back(stoi(cur));
            backT(depth+1,cur,cards,v,res);
            v[i] = false;
            cur.pop_back();
        } 
    }

    return 0;
}




int main(){

    int T;
    cin >> T;
    while(T--){
        int N;
        string bob_tmp;
        cin >> N;

        cin >> bob_tmp;
        int BoB = stoi(bob_tmp);
        reverse(bob_tmp.begin(),bob_tmp.end());
        BoB = min(BoB,stoi(bob_tmp));

        vector<int> Case;
        string Alice;
        string cur_str = "";
        vector<bool> visited (N,false);
        cin >> Alice;

        
        for (int i = 0; i < N; i++){
            visited[i] = true;
            cur_str += Alice[i];
            Case.push_back(stoi(cur_str));
            backT(1,cur_str,Alice,visited,Case);
            visited[i] = false;
            cur_str.pop_back();
        }

    sort(Case.begin(),Case.end());

    int idx = lower_bound(Case.begin(),Case.end(),BoB)-1 - Case.begin();
    cout << Case[idx] << endl;

    }

    return 0;
}
