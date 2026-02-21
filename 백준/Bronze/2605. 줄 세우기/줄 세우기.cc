#include <iostream>
#include <vector>


using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> line;
    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        line.insert(line.end()-num,i);
    }  

    for(int n: line){
        cout << n << " ";
    }

    return 0;
}