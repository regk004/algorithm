#include <iostream>

using namespace std;

int main(){
    int N,K,Max,Min,cnt = 0,tmp;
    cin >> N >> K;
    
    cin >> tmp;
    Max = tmp;
    Min = tmp;
    for(int i = 1; i < N; i++){
        cin >> tmp;
        Max = max(Max,tmp);
        Min = min(Min,tmp);

        if (Max-Min+1 > K){
            Max = tmp;
            Min = tmp;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}