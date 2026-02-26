#include <iostream>

using namespace std;

int main(){
    int w,h,a_x,a_y,b_x,b_y;
    cin >> w >> h >> a_x >> a_y >> b_x >> b_y;

    if (a_x == b_x) cout << 0 << " " << a_y << " " << w << " " << b_y;
    else cout << a_x << " " << 0 << " " << b_x << " " << h;

    return 0;
}