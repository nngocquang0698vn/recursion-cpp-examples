/*

The Collatz Conjecture, also known as the "3n + 1" sequence, proposes that
starting with any positive number and applying two rules
(if even, divide by two; if odd, triple it and add one)
will always eventually lead to the number one.

*/

#include <iostream>
using namespace std;

void solve_with_direct_recursion(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n % 2 == 0) {
        solve_with_direct_recursion(n/2);
        cout << " * 2" << endl;
    } else {
        solve_with_direct_recursion(n * 3 + 1);
        cout << " minus 1 and then div 3" << endl;
    }
}

void solve_odd(int n);
void solve_even(int n);

void solve_with_mutual_recursion(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n % 2 == 0)
        solve_even(n);
    else
        solve_odd(n);
}

void solve_even(int n) {
    solve_with_mutual_recursion(n/2);
    cout << " * 2" << endl;
}

void solve_odd(int n) {
    solve_with_mutual_recursion(n * 3 + 1);
    cout << " minus 1 and then div 3" << endl;
}


int main() {
    int n;
    cin >> n;
    cout << "De quy truc tiep: " << endl;
    cout << n << " = ";
    solve_with_direct_recursion(n);

    cout << "De quy tuong ho: " << endl;
    cout << n << " = ";
    solve_with_mutual_recursion(n);
}