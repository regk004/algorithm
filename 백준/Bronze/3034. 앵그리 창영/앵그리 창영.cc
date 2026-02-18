#include <iostream>

using namespace std;

int main(){
    int N,W,H;
    cin >> N >> W >> H;
    int Max_length_pow = W*W+H*H;

    while(N--){
        int match;
        cin >> match;
        if (match*match <= Max_length_pow) cout <<"DA" << endl;
        else cout << "NE" << endl;
    }

    return 0;
}