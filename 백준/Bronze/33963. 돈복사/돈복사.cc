#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    cin >> inp;

    while (inp.size() < 3) inp += "0";
    int ref_val = stoi(inp.substr(0,3));

    if (ref_val >= 500) cout << 0;
    else if(ref_val >= 250) cout << 1;
    else if(ref_val >= 125) cout << 2;
    else cout << 3;

    return 0;
}
