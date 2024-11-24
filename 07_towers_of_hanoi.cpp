#include <iostream>
using namespace std;

void moveSingleDisk(char start, char finish) {
    cout << start << " -> " << finish << endl;
}

void findSolution(int n, char source, char target, char aux) {
    // All about that base
    if(n == 1) {
        moveSingleDisk(source, target);
        // Recursive case
    } else {
        findSolution(n - 1, source, aux, target);
        moveSingleDisk(source, target);
        findSolution(n - 1, aux, target, source);
    }
}

int main() {
    int n;
    cout << "nhap so luong dia:";
    cin >> n;
    findSolution(n, 'A', 'B', 'C');
}
