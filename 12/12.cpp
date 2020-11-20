#include <iostream>

using namespace std;

bool isPrime(int num){
  for (int i = 2; i < num; i++){
    if (num % i ==  0){
      return false;
    }
  }
  return true;
}

int isDiv(long long num){

  int div = 2;
  int count = 1;
  int divCount = 1; 
  
  while (num != 1){
    if (isPrime(div) && num % div == 0){
      num /= div;
      count++;
    }else {
      divCount *= count;
      count = 1;
      div++;
    }
  }
  
  divCount *= count;
  
  if (divCount >= 500){
    return true;
  }
  
  return false;
  
}

int main() {
  
  long long num = 2;
  long long tri = 1;

  while (isDiv(tri) == false){
    tri = num * (num + 1) / 2;
    num++;
   }

  
  cout << tri;
  
  return 0;
  
}
