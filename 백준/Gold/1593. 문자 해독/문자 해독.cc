#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int g, s;
    string W,S; 
    vector<int> target(int('z')-int('A')+1,0);
    vector<int> cur(int('z')-int('A')+1,0);
    cin >> g >> s;

    int total_dif = 0, cnt = 0;
    cin >> W;
    cin >> S;

    if(g <= s){
        for(int i = 0; i < g; i++){
            target[int(W[i])-65] += 1;
            cur[int(S[i])-65] += 1;
        }

        for(int i = 0; i < target.size(); i++){
            total_dif += abs(target[i]-cur[i]);
        }

        if(total_dif == 0) cnt += 1;



        for(int i = 0; i+g < s; i++){
            int old_dif,new_dif;

            old_dif = abs(target[int(S[i])-65]-cur[int(S[i])-65]);
            cur[int(S[i]-65)] -= 1;
            new_dif = abs(target[int(S[i])-65]-cur[int(S[i])-65]);
            total_dif += (new_dif-old_dif);

            old_dif = abs(target[int(S[i+g])-65]-cur[int(S[i+g])-65]);
            cur[int(S[i+g]-65)] += 1;
            new_dif = abs(target[int(S[i+g])-65]-cur[int(S[i+g])-65]);
            total_dif += (new_dif-old_dif);

            if(total_dif == 0) cnt += 1;
        }
    }
    
    cout << cnt;
}