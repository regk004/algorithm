#include <iostream>

using namespace std;

int main(){
    int time = 300;
    for(int i = 0; i < 4; i++){
        int tmp;
        cin >> tmp;
        time += tmp;
    }
    
    if(time <= 1800) cout << "Yes";
    else cout << "No";

    return 0;
}