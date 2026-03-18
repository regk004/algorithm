#include <iostream>
#include <string>

using namespace std;

int main(){
    string query = "";
    while(true){
        cin >> query;
        if (query == "end") break;

        if (query == "animal") cout << "Panthera tigris" << endl;
        else if (query == "tree") cout << "Pinus densiflora" << endl;
        else cout << "Forsythia koreana" << endl;
    }
    return 0;
}