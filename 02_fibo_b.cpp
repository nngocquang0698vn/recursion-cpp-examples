//
// Created by nngocquang on 11/23/2024.
//

#include <iostream>
#include <chrono>

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

long fibo_improved(int i, int n, long f0, long f1) {
    if (n <= 1) return n;
    if (i == n) return f1;
    return fibo_improved(i + 1, n, f1, f0 + f1);
}

void fibo_khu_de_quy(int n) {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "So fibo thu " << n << " khong su dung de quy: " << fibo_iteration(n) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time elapsed: " << elapsed.count() << " ms" << std::endl;
}

void fibo_de_quy(int n) {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "So fibo thu " << n << " su dung de quy: " <<  fibo(n) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time elapsed: " << elapsed.count() << " ms" << std::endl;
}

void fibo_de_quy_cai_tien(int n) {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "So fibo thu " << n << " su dung de quy toi uu: " <<  fibo_improved(2, n, 1, 1) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time elapsed: " << elapsed.count() << " ms" << std::endl;
}


int main() {
    int n;
    cout << "Nhap n:";
    cin >> n;
    fibo_khu_de_quy(n);
    fibo_de_quy(n);
    fibo_de_quy_cai_tien(n);
}