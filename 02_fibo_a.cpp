//
// Created by nngocquang on 11/23/2024.
//

#include <iostream>
using namespace std;

long fibo_iteration(int n) {
    if (n <= 1) return n;
    long f0 = 0, f1 = 1;

    for(int i = 2; i <= n; i++) {
        long sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }

    return f1;
}

long fibo(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    cout << "Nhap n:";
    cin >> n;
    cout << "So fibo thu " << n << " khong su dung de quy: " << fibo_iteration(n) << endl;
    cout << "So fibo thu " << n << " su dung de quy: " <<  fibo(n) << endl;
}