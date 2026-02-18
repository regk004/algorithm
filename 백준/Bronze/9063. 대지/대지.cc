#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int Max_x = -10001, Min_x = 10001, Max_y = -10001,Min_y = 10001;
    cin >> N;
    while(N--){
        int x,y;
        cin >> x >> y;
        Max_x = max(Max_x,x);
        Max_y = max(Max_y,y);
        Min_x = min(Min_x,x);
        Min_y = min(Min_y,y);
    }
    cout << (Max_y-Min_y)*(Max_x-Min_x);
    return 0;
}