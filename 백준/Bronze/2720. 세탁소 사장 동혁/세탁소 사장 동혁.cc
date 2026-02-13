#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T,C_100;
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> C_100;
        cout << C_100 / 25 << " "; C_100 %= 25;
        cout << C_100 / 10 << " "; C_100 %= 10;
        cout << C_100 / 5 << " "; C_100 %= 5;
        cout << C_100 << endl;
    }

    return 0;
}