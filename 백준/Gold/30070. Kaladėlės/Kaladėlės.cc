#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    char block;
    bool flag = false;
    int size = int('Z')-int('A') + 1;
    vector <int> chr_cnt(size,0);
    vector <char> res;

    for(int i = 0; i < N; i++){
        cin >> block;
        chr_cnt[int(block) - int('A')] += 1;
    }

    int bef_chr = -1;
    for(int i = 0; i < N; i++){
        int Max = 0;
        int chr_tmp = -1;
        for(int j = 0; j < size; j++){
            if (j != bef_chr && Max < chr_cnt[j]){
                chr_tmp = j;
                Max = chr_cnt[j];
            }
        }
        if (Max == 0){
            flag = true; break;
        }
        bef_chr = chr_tmp;
        res.push_back(bef_chr);
        chr_cnt[bef_chr] -= 1;
    }


    if (flag) cout << "NE";
    else{
        for (int c : res){
            cout << char(c+'A') << " ";
        } 

    }
    return 0;
}