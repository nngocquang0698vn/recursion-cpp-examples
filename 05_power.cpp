//
// Created by nngocquang on 11/23/2024.
//

#include <iostream>
using namespace std;

long power_iteration(int x, int exp) {
    long result = 1;
    for (int i = 1; i <= exp; i++) result = result * x;
    return result;
}

long power(int x, int exp) {
    if (exp == 0)
        return 1L;
    else
        return power(x, exp-1) * x;
}

int main() {
    int x, exp;
    cout << "Nhap x va exp:";
    cin >> x >> exp;
    cout << power_iteration(x, exp) << endl;
    cout << power(x, exp) << endl;
}