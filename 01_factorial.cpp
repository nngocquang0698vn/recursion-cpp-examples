//
// Created by nngocquang on 11/23/2024.
//

#include <iostream>
using namespace std;

long factorial_iteration(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++) result = result * i;
    return result;
}

long factorial(int n) {
    if (n == 0)
        return 1L;
    else
        return factorial(n - 1) * n;
}

int main() {
    int n;
    cout << "Nhap n:";
    cin >> n;
    cout << n << "! khong su dung de quy: " << factorial_iteration(n) << endl;
    cout << n << "! su dung de quy: " << factorial(n) << endl;
}