#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> W;
    cin >> N;
    for(int i =0; i < N; i++){
        int A, B, X;
        cin >> A >> B >> X;
        W.push_back(A*(X-1)+B);
    }
    
    for(auto w: W){
        cout << w << endl;
    }

    return 0;
}
