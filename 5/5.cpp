#include <iostream>
using namespace std;

bool isDivisible(int num){

  for (int i = 1; i <= 20; i++){

    if (num % i != 0){
      return false;
    }

  }

  return true;

}

int main() {

  int num = 1;
  
  while (isDivisible(num) == false){
    num++;
  }

  cout << num;
  
  return 0;
  
}
