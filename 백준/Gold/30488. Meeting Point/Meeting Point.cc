#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M,P,G;
    cin >> N >> M;
    cin >> P >> G;

    vector<long long> dist(N+1,1e15);
    vector<vector<pair<long long,int>>> ori_graph(N+1);
    

    for(int i = 0; i < M; i++){
        int u,v,d;
        cin >> u >> v >> d;
        ori_graph[u].push_back({d,v});
        ori_graph[v].push_back({d,u});
    }

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    pq.push({0,P});
    dist[P] = 0;

    while(!pq.empty()){
        long long cur_d = pq.top().first;
        int cur_p = pq.top().second;
        pq.pop();

        if (dist[cur_p] != cur_d) continue;

        for(int i = 0; i < ori_graph[cur_p].size(); i++){
            long long nxt_d = ori_graph[cur_p][i].first;
            int nxt_p = ori_graph[cur_p][i].second;

            if (dist[nxt_p] > dist[cur_p] + nxt_d){
                dist[nxt_p] = dist[cur_p] + nxt_d;
                pq.push({dist[nxt_p],nxt_p});
            }
        }
    }


    vector<vector<int>> dag(N+1);
    vector<int> indegree(N+1,0);

    for(int u = 1; u <= N; u++){
        for(pair<long long,int> edge : ori_graph[u]){
            int v = edge.second;

            if (dist[v] == dist[u]+edge.first){
                dag[u].push_back(v);
                indegree[v] += 1;
            }
       }
    }


    queue<int> q;
    q.push(G);
    vector<bool> is_visited_G(N+1,false);
    is_visited_G[G] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt : dag[cur]){

            indegree[nxt] -= 1;
            if (indegree[nxt] == 0){
                q.push(nxt);
                is_visited_G[nxt] = true;
            }
        }
    }


    bool flag = false;
    for(int x = 1; x <= N; x++){
        //cout << dist[x] << is_visited_G[x] << " ";
        if(dist[x] == dist[G]*2 && is_visited_G[x]){
            cout << x << " ";
            flag = true;
        }
    }

    if (!flag) cout << "*";


    return 0;
}