#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int nxt, cost, color;
};

struct Node{
    int id;
    long long cost;
    int k1_cnt,k2_cnt;

    bool operator>(const Node &other) const{
        return cost > other.cost;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M,k1,k2;
    cin >> N >> M >> k1 >> k2;
    vector<vector<vector<long long>>> dist(N+1,vector<vector<long long>> (k1+1,vector<long long> (k2+1,1e13)));
    vector<vector<Edge>> adj(N+1);
    while(M--){
        int u,v,x,c;
        cin >> u >> v >> x >> c;
        adj[u].push_back({v,x,c});
        adj[v].push_back({u,x,c});
    }

    int S,T;
    cin >> S >> T;

    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push({S,0,0,0});
    dist[S][0][0] = 0;

    while (!pq.empty()){
        Node cur = pq.top();
        pq.pop();


        if (dist[cur.id][cur.k1_cnt][cur.k2_cnt] < cur.cost) continue;

        for(auto &edge : adj[cur.id]){
            int nxt_node = edge.nxt;
            long long nxt_cost = cur.cost + edge.cost;
            int nxt_k1 = cur.k1_cnt;
            int nxt_k2 = cur.k2_cnt;
            if (edge.color == 1) nxt_k1 += 1;
            else if (edge.color == 2) nxt_k2 += 1;

            if (nxt_k1 <= k1 && nxt_k2 <= k2 && dist[nxt_node][nxt_k1][nxt_k2] > nxt_cost){
                pq.push({nxt_node,nxt_cost,nxt_k1,nxt_k2});
                dist[nxt_node][nxt_k1][nxt_k2] = nxt_cost;
            }
        }
    }


    if (dist[T][k1][k2] == 1e13) cout << -1;
    else cout << dist[T][k1][k2];

    return 0;
}