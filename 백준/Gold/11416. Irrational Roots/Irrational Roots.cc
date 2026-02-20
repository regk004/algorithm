#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



bool test(int root,vector<int> &cf){
    int cur = 0;
    for(int i = 0; i < cf.size(); i++){ 
        cur += int(pow(root,cf.size()-i-1))*cf[i];
    }

    if (cur == 0) return true;
    else return false;
}

void div(int root, vector<int> &cf){
    vector<int> nxt;
    for(int i = 0; i < cf.size()-1; i++){
        nxt.push_back(cf[i]);
        cf[i+1] += cf[i]*root;
    }

    cf = nxt;
}

int main(){
    int N;
    cin >> N;
    vector<int> coef;
    vector<int> factor;
    coef.push_back(1);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        coef.push_back(a);
    }

    int C0 = coef[N];
    for (int i = 1; i <= 10; i++){
        if (C0 % i == 0) factor.push_back(i),factor.push_back(-i);
    }

    int cnt = 0;
    for (int i = 0; i < factor.size(); i++){
        while(test(factor[i],coef)){
            cnt += 1;
            div(factor[i],coef);
        }

    }

    cout << N-cnt;

    return 0;
}
