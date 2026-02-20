#include <iostream>


using namespace std;

int fib(int n, int &c) {
    if (n == 1 || n == 2) return 1, c += 1; 
    else return (fib(n - 1, c) + fib(n - 2, c));
}

int fibonacci(int n, int &c) {
    int f[n];
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i < n+1; i ++){
        f[i] = f[i-1] + f[i-2];
        c += 1;
    }
    return f[n];
}

int main(){
    int N;
    int cnt_1 = 0;
    int cnt_2 = 0;
    cin >> N;
    fib(N,cnt_1);
    fibonacci(N,cnt_2);
    cout << cnt_1 << " " << cnt_2;

    return 0;
}