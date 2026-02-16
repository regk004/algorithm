#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    double cur_S;
    double time = 0.0;

    cin >> N >> cur_S >> K;
    
    int start_bar = 1;
    while(K--){
        int nxt_bar;
        double nxt_S;
        cin >> nxt_bar >> nxt_S;
        
        time += 60*(nxt_bar-start_bar)*4/cur_S;
        cur_S = nxt_S;
        start_bar = nxt_bar;
    }

    time += 60*(N-start_bar+1)*4/cur_S;

    cout << fixed << setprecision(12) << time << endl;
    return 0;
}