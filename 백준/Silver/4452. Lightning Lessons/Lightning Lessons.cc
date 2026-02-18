#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    while(N--){
        int M;
        cin >> M;
        deque<int> thunder;

        for(int i = 0; i < M; i++){
            int p;
            cin >> p;
            thunder.push_back(p);
        }

        int cycle = 0;
        bool flag = false;

        while(true){
            
            for(int i = 0; i < thunder.size(); i ++){
                if (thunder[i]) break;
                else if (i == thunder.size()-1) {
                    while(cycle--) cout << 'z';
                    cout << "ap!" << endl;
                    flag = true;
                }
            }

            if (!flag && thunder.size() == 1){
                if (thunder.front() > 0) cout << "*fizzle*" << endl;
                else cout << "*bunny*" << endl;
                flag = true;
            }

            if (flag) break;
            
            for(int i = thunder.size()-1; i > 0; i--){
                thunder[i] -= thunder[i-1];
            }
            thunder.pop_front();
            cycle ++;
        }
    }

    return 0;
}