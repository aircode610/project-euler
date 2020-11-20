#include <iostream>
using namespace std;

int main() {

  int sum = 0;
  int sumSquares = 0;

  for (int i = 1; i <= 100; i++){
    sum += i;
    sumSquares += i * i;
  }

  int diff = sum * sum - sumSquares;
  cout << diff;
  
  return 0;

}
