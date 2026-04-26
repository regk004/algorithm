#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


bool bfs(unordered_map<string, vector<string>> &graph, string &p, string &target){
    queue<string> q;
    unordered_set<string> visited;
    visited.insert({p});
    q.push(p);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        for(auto &nxt : graph[cur]){
            if(visited.find(nxt) == visited.end()){
                if(nxt == target) return true;
                q.push(nxt);
                visited.insert(nxt);
            } 
        }
    }
    return false;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_map<string, vector<string>> graph;

    for(int i = 0; i < M; i++){
        string a, b;
        cin >> a >> b;
        auto it = graph.find(a);
        if(it != graph.end()) it->second.push_back(b);
        else graph.insert({a,{b}});
    }

    int Q;
    cin >> Q;


    vector<string> res;
    for(int i = 0; i < Q; i++){
        string a,b;
        cin >> a >> b;
        if(bfs(graph,a,b)) res.push_back(a);
        else if(bfs(graph,b,a)) res.push_back(b);
        else res.push_back("gg");
    }

    for(auto &s : res){
        cout << s << " ";
    }

    return 0;
}