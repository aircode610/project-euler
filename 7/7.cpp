#include <iostream>
using namespace std;

bool isPrime(int num){

  for (int i = 2; i < num; i++){

    if (num %i == 0){
      return false;
    }
    
  }

  return true;
  
}

int main() {

  int count = 0;
  int num = 2;

  while (count < 10001){
    
    if (isPrime(num) == true){
      count++;
    }

    num++;
  }

  cout << num - 1;
  
  return 0;
  
}
