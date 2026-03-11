#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, L;
    cin >> N >> L;

    int Max = 0;
    int Max_cnt = 0;
    

    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;

        int cur = 0;
        bool is_counting = false;
        for(int j = 0; j < L; j++){
            if (!is_counting && tmp[j] == '1')
                cur++;
            
            if(tmp[j] == '0')
                is_counting = false;
            else
                is_counting = true;
        }

        if (Max < cur){
            Max = cur;
            Max_cnt = 1;
        }
        else if(Max == cur)
            Max_cnt++;
    }

    cout << Max << " " << Max_cnt;

    return 0;
}