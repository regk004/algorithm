#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int P;
    cin >> P;
    while(P--){
        int cur_height, t;
        int cnt = 0;
        vector<int> line;
        cin >> t;
        for(int i = 0; i < 20; i++){
            cin >> cur_height;
            bool is_tallest = true;
            for(int j = 0; j < line.size(); j++){
                if(line[j] > cur_height) {
                    cnt += line.size()-j;
                    line.emplace(line.begin()+j,cur_height);
                    is_tallest = false;
                    break;
                }
            }

            if (is_tallest) line.push_back(cur_height);
        }
    cout << t << " " << cnt << endl;
    }
    return 0;
}