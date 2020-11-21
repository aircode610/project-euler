#include <iostream>

using namespace std;

int currency[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int money = 200;
int count = 0;

void calculate(int n, int sum){

  if (n == 7){
    if (sum == money){
      count++;
    }
    return;
  }
  
  for (int i = 0; i <= money / currency[n]; i++){
    
    int temp = sum + i * currency[n];
    if (temp > 200){
      return;
    }
    
    calculate(n + 1, temp);
  }
  
}

int main() {

  calculate(0, 0);
  cout << count + 1;
  
  return 0;
  
}
