#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long facto(long long n){
    if (n <= 1) return 1;
    else return n*facto(n-1);
}


int main(){
    int N;
    cin >> N;

    int query_type;
    cin >> query_type;

    vector<int> Nums;
    for(int i = 1; i <= N; i++) Nums.push_back(i);


    if (query_type == 1){
        long long k;
        cin >> k;

        while(!Nums.empty()){
            long long i = 0;
            while ((i+1)*facto(Nums.size()-1) < k) i++;
            k -= (i)*facto(Nums.size()-1);
            cout << Nums[i] << " ";
            Nums.erase(Nums.begin()+i);
        }
    }
    else{
        long long res = 1;
        while(!Nums.empty()){
            int n;
            cin >> n;
            long long idx = find(Nums.begin(),Nums.end(),n)-Nums.begin();
            res += (idx)*facto(Nums.size()-1);
            Nums.erase(Nums.begin()+idx);
        }

        cout << res;
    }

    return 0;
}