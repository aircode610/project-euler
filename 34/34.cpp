#include <iostream>
#include <map>

using namespace std;

map<int, int> facts;

bool isCur(long long num){
  long long tempNum = num;
  long long sumDig = 0;

  while (tempNum != 0){
    int dig = tempNum % 10;
    sumDig += facts[dig];
    tempNum /= 10;
  }

  if (sumDig == num){
    return true;
  }
  
  return false;
}

int fact(int num){
  
  if (num == 1){
    return 1;
  }

  return num * fact(num - 1);
  
}

int main() {

  long long sum = 0;
  
  for (int i = 0; i < 10; i++){
    if (i == 0){
      facts[i] = 1;
      continue;
    }
    facts[i] = fact(i);
  }

  for (int i = 3; i <= 999999; i++){
    if (isCur(i)){
      sum += i;
    }
  }

  cout << sum;
  
  return 0;
  
}
