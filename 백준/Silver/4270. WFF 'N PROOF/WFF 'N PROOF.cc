#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    while(true){
        vector<char> variable;
        vector<char> two_op;
        vector<char> not_op;
        string inp;
        cin >> inp;

        if(inp == "0") break;

        for(auto c : inp){
            if (c == 'N') not_op.push_back('N');
            else if (c == 'K' || c == 'A' || c == 'C' || c == 'E') two_op.push_back(c);
            else variable.push_back(c);
        }

        if(variable.empty()) cout << "no WFF possible" << endl;
        else{
            string res = "";
            for(auto c : not_op){
                res += c;
            }

            int N = min(variable.size(),two_op.size()+1);

            for(int i = 0; i < N-1; i++){
                res += two_op[i];
            }

            for(int i = 0; i < N; i++){
                res += variable[i];
            }
            
            cout << res << endl;
        }       
    }


    return 0;
}