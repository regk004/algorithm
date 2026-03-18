#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int total = 180*(N-1);
    while(N--){
        int tmp;
        cin >> tmp;
        total -= tmp*2;
    }

    cout << total;
    return 0;
}