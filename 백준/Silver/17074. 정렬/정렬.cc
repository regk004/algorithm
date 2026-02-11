#include <iostream>
#include <vector>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    int cnt = 0;
    cin >> N;

    vector <int> seq(N);
    vector <bool> left_sorted(N,false);
    vector <bool> right_sorted(N,false);
    
    left_sorted[0] = true;
    right_sorted[N-1] = true;
    
    for(int i = 0; i< N; i++){
        cin >> seq[i];
    }

    for(int i = 1; i < N; i++){
        if (seq[i] >= seq[i-1] && left_sorted[i-1]) {
            left_sorted[i] = true;
        }
    }

    for(int i = N-2; i > -1; i--){
        if (seq[i+1] >= seq[i] && right_sorted[i+1]) {
            right_sorted[i] = true;
        }
    }
    
    if (left_sorted[N-2]) cnt += 1;
    if (right_sorted[1]) cnt += 1;

    for(int i = 1; i < N-1; i++){
        if (left_sorted[i-1] && right_sorted[i+1] && seq[i-1] <= seq[i+1]) cnt += 1;
    }


    cout << cnt;

    return 0;
}