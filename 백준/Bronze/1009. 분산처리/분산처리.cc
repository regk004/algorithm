#include <iostream>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T,a,b;
    cin >> T;
    for(int i = 0; i < T; i++){
        int res = 1;
        cin >> a >> b;
        for(int j = 0; j < b; j++){
            res *= a;
            res %= 10;
        }
        
        if (res == 0) cout << 10 << endl;
        else cout << res << endl;
    }
    return 0;
}