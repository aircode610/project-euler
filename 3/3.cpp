#include <iostream>
using namespace std;

bool isPrime(long int num){//bool isPrime(long long num)

  for (int i = 2; i*i <= num; i++){//O(num) -> O(sqrt(num))
    //num/a=b => num=a*b 
    if (num % i == 0){
      return false;
    }
    
  }

  return true;

}

int main() {

  long int num = 600851475143;//long long num=600851475143LL;
  int div = 2;

  while (num > 1){

    if (num % div == 0 && isPrime(div)){
      num /= div;
    }
    else {
      div += 1;
    }
      
  }

  cout << div;

  return 0;

}
