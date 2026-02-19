#include <iostream>
#include <vector>
#define Max 1e15

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    vector<int> speed;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long v;
        cin >> v;
        speed.push_back(v);
    }

    long long res = speed[N-1];
    for(int i = N-2; i > -1; i--){
        long long cur = speed[i];
        long long e = Max/cur+1; long long s = 1;
        while (s < e){
            long long mid = (s+e)/2;
            if (cur*mid >= res) e = mid;
            else s = mid+1;
        }

        res = cur*s;
    }
    
    cout << res << endl;
    return 0;
}