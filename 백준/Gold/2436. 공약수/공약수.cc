#include <iostream>
#include <cmath>

using namespace std;


int gcd(int a, int b){
    if(a<b) swap(a,b);

    while(b!=0){
        int n = a%b;
        a = b;
        b = n;
    }

    return a;
}

int main(){
    int GCD, LCM;
    cin >> GCD >> LCM;


    if((LCM % GCD) != 0) return 0;

    int a_b = LCM/GCD;
    int A = 1e9;
    int B = 1e9;

    for(int i = 1; i <= sqrt(a_b)+1; i++){
        if (a_b % i == 0 && gcd(i,a_b/i) == 1 && A+B > i + a_b/i){
            A = i;
            B = a_b/i;
        }
    }

    if(A != 1e9) cout << A*GCD << " " << B*GCD;

    return 0;
}