#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

set<int> answers;

void perms(int arr[9]){
  for (int i = 0; i < 9; i++){
    for (int j = i + 1; j < 9; j++){
      
      int first = 0;
      for(int a = 0; a <= i; a++){
	first += arr[a] * pow(10, i - a);
      }
      int second = 0;
      for(int a = i + 1; a <= j; a++){
	second += arr[a] * pow(10, j - a);
      }
      int third = 0;
      for(int a = j + 1; a <= 8; a++){
	third += arr[a] * pow(10, 8 - a);
      }

      if (first * second == third){
	answers.insert(third);
      }
      
    }
  }
}

int main() {

  int digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  do {
    perms(digits);
  } while (next_permutation(digits,digits+9));

  int sumAll = 0;

  for (auto num : answers){
    sumAll += num;
  }

  cout << sumAll << endl;

  return 0;
  
}
