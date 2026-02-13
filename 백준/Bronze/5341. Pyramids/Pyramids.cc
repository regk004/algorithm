#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N ){
        if (N == 0) break;
        cout << int(N*(N+1)/2) << endl;
    }
    return 0;
}   