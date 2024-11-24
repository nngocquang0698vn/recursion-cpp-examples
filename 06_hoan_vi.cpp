#include <iostream>
using namespace std;

void try_to_fill(int i, int n, int arr[], bool avail[]) {
  if (i == n+1) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return;
  }

  for(int j = 1; j <= n; j++)
    if (avail[j-1]) {
      avail[j-1] = false;
      arr[i-1] = j;
      try_to_fill(i+1, n, arr, avail);
      avail[j-1] = true;
    }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  bool avail[n];
  for(int i = 0; i < n; i++) avail[i] = true;
  try_to_fill(1, n, arr, avail);
}
