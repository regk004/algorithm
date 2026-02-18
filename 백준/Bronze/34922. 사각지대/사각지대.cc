#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int w,h,r;
    cin >> w >> h;
    cin >> r;
    cout << double(w*h)-(r*r*acos(0.0)/2);
}