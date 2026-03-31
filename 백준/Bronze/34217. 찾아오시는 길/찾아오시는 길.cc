#include <iostream>

using namespace std;

int main(){
    int A,B,C,D;
    cin >> A >> B;
    cin >> C >> D;
    if(A+C < B+D) cout << "Hanyang Univ.";
    else if(A+C > B+D) cout << "Yongdap";
    else cout << "Either";

    return 0;
}