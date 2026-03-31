#include <iostream>

using namespace std;

int main(){
    int S,F;
    cin >> S;
    cin >> F;

    if(F<S) cout << "flight";
    else cout << "high speed rail";

    return 0;
}