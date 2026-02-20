#include <iostream>

using namespace std;

int main(){
    char inp;
    cin >> inp;
    if(inp == 'M') cout << "MatKor";
    else if(inp == 'W') cout << "WiCys";
    else if(inp == 'C') cout << "CyKor";
    else if(inp == 'A') cout << "AlKor";
    else if(inp == '$') cout << "$clear";

    return 0;
}