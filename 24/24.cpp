#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int count = 1;

  while (count < 1000000 && next_permutation(arr, arr + 10)) {
    count++;
  }
  
  for (int i = 0; i < 10; i++){
    cout << arr[i];
  }

  return 0;
  
}
