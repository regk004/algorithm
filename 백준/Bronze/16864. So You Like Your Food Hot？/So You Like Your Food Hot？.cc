#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double total,pita,pizza;
    int total_cent,pita_cent,pizza_cent;

    cin >> total >> pita >> pizza;
    total_cent = round(total*100);
    pita_cent = round(pita*100);
    pizza_cent = round(pizza*100);

    int pt_cnt = 0;
    bool flag = false;
    while(pita_cent*pt_cnt <= total_cent){
        int pz_cnt;
        if ((total_cent-pita_cent*pt_cnt) % pizza_cent == 0){
            pz_cnt = (total_cent-pita_cent*pt_cnt)/pizza_cent;
            cout << pt_cnt << " " << pz_cnt << "\n";
            flag = true;
        }
        pt_cnt += 1;
    }

    if(!flag) cout << "none";
    return 0;
}