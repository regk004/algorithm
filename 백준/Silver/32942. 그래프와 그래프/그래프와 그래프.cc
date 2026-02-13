#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int A,B,C;
    cin >> A >> B >> C;
    vector<vector<int>> graph(11); 

    for(int x = 1; x < 11; x++){
        for (int y = 1; y < 11; y++){
            if (A*x + B*y == C) {
                graph[x].push_back(y);
            }
        }
    }

    for(int x = 1; x < 11; x++){
        if (graph[x].empty()) cout << 0 << endl;
        else{
            for(int nxt : graph[x]){
            cout << nxt << " ";
            }
            cout << endl;
        }
        
    }

    return 0;
}