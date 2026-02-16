#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int T,N;
    cin >> T;
    for (int i = 0; i < T; i++){
        int j = 0;
        vector<int> res;
        cin >> N;
        while (pow(2,j) <= N) j++;
        j--;
        while (j > -1){
            if (pow(2,j) <= N){
                N -= pow(2,j);
                res.push_back(j);
            }
            j--;
        }
        reverse(res.begin(),res.end());
        for(int idx : res){
            cout << idx << " ";
        }
        cout << endl;
    }
    
    return 0;
}