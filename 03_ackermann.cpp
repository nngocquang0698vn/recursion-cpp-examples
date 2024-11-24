#include <iostream>
#include <chrono>

using namespace std;

long ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return ackermann(m - 1, n);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    int m, n;
    cin >> m >> n;
    auto start = std::chrono::high_resolution_clock::now();
    cout << ackermann(m, n) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time elapsed: " << elapsed.count() << " ms" << std::endl;
}