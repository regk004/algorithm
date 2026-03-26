#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    cin >> word;
    for(int i = 1; i < word.length(); i++){
        if(word[i-1] == word[i]) cout << word[i];
    }

    return 0;
}