#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    int cnt = 0;
    cin >> N >> M;
    vector<int> wait_lst;
    unordered_set<int> frd_lst;
    while(N--) {
        int num;
        cin >> num;
        wait_lst.push_back(num);
    }

    for(int i = 0; i < M; i++){
        int frd;
        cin >> frd;
        frd_lst.insert(frd);
    }

    for(int i = 0; i < M; i++){
        if (frd_lst.find(wait_lst[i]) == frd_lst.end()) cnt += 1;
    }

    cout << cnt << endl;
    return 0;
}