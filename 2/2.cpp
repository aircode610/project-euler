#include <iostream>
using namespace std;

int main() {

  int last = 0;
  int cur = 1;
  int sum = 0;

  int exceed = 4000000;

  while (cur <= exceed) {

    int temp = cur;
    cur += last;
    last = temp;

    if (cur % 2 == 0){
      sum += cur;
    }
    
  }

  cout << sum;
  
  return 0;
    
}
