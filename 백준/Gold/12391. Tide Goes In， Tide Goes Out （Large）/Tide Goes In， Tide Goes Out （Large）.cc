#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct node{
    int y,x;
    double t;

    bool operator<(const node& other) const{
        return t > other.t;
    }
};



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    vector<vector<int>> dydx = {{-1,0},{1,0},{0,-1},{0,1}};
    for(int t = 1; t <= T; t++){
        int N,M,H;
        cin >> H >> N >> M;
        vector<vector<int>> fl (N);
        vector<vector<int>> ci (N);

        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                int v;
                cin >> v;
                ci[y].push_back(v);
            }
        }

        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                int v;
                cin >> v;
                fl[y].push_back(v);
            }
        }

        vector<vector<bool>> visited(N,vector<bool> (M,false));
        vector<vector<double>> dist(N,vector<double>(M,1e9));

        queue<pair<int,int>> q;
        priority_queue<node> pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty()){ 
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int ny = cur_y + dydx[i][0];
                int nx = cur_x + dydx[i][1];

                if (ny >= 0 && ny < N && nx >= 0 &&  nx < M && !visited[ny][nx] &&
                    H <= ci[ny][nx] - 50 && fl[cur_y][cur_x] <= ci[ny][nx] - 50 && fl[ny][nx] <= ci[ny][nx] - 50 &&
                    fl[ny][nx] <= ci[cur_y][cur_x] - 50){
                    q.push({ny,nx});
                    pq.push({ny,nx,0});
                    visited[ny][nx] = true;
                    dist[ny][nx] = 0;
                  }
            }
        }

        while (!pq.empty()){
            int cur_y = pq.top().y;
            int cur_x = pq.top().x;
            double cur_t = pq.top().t;
            pq.pop();

            
            if (abs(cur_t-dist[cur_y][cur_x]) <= 1e-6){

            for(int i = 0; i < 4; i++){
                int ny = cur_y + dydx[i][0];
                int nx = cur_x + dydx[i][1];
                double cur_h = H-cur_t*10.0;

                if (ny >= 0 && ny < N && nx >= 0 &&  nx < M && 
                    fl[cur_y][cur_x] <= ci[ny][nx] - 50 && fl[ny][nx] <= ci[ny][nx] - 50 &&
                    fl[ny][nx] <= ci[cur_y][cur_x] - 50
                    ){

                    double cost_t = 0;

                    if(cur_h > ci[ny][nx] - 50) cost_t += (cur_h-(ci[ny][nx] - 50))/10;

                    if(cur_h - cost_t*10 - fl[cur_y][cur_x] >= 20) cost_t += 1.0;
                    else cost_t += 10.0;

                    if(dist[ny][nx] > cur_t + cost_t){
                        dist[ny][nx] = cur_t + cost_t;
                        pq.push({ny,nx,dist[ny][nx]});
                        }
                      }
                }

            }
        }
        cout << "Case #" << t << ": ";
        cout << fixed << setprecision(1);
        cout << dist[N-1][M-1] << "\n";
    }

    return 0;
}