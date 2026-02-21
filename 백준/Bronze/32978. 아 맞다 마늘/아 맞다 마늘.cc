#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    int N;
    cin >> N;
    unordered_set<string> ingrd;
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        ingrd.insert(s);
    }

    for(int i = 0; i < N-1; i++){
        string s;
        cin >> s;
        ingrd.erase(s);
    }

    for(string element: ingrd) cout << element;

    return 0;
}