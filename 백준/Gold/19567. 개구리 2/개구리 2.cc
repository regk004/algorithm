#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    int N;
    cin >> N;
    int parity = -1;
    // u = x+y, v = x-y
    long long min_u = -1e9*4;
    long long max_u = 1e9*4;
    long long min_v = -1e9*4;
    long long max_v = 1e9*4; 
    
    for(int i = 0; i < N; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        if(parity == -1) parity = abs((a+b+c) % 2);
        else if((a+b+c) % 2 != parity){
                cout << "NO";
                return 0;
            }
        min_u = max(min_u,a+b-c);
        max_u = min(max_u,a+b+c);
        min_v = max(min_v,a-b-c);
        max_v = min(max_v,a-b+c);

        if (min_u > max_u || min_v > max_v) {
            cout << "NO";
            return 0;
        }
    }

    long long x = (min_u+min_v)/2;
    cout << x << " " << min_u-x;
    
    return 0;
}