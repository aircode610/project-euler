#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int n = 1000000;
int allNums[n - 1];

void empty(int num, int index){
  for (int i = index; i < n - 1; i+=num){
    allNums[i] = 0;
  } 
}

int digits(int num){

  int count = 0;

  while (num != 0){
    num /= 10;
    count++;
  }

  return count;
  
}

int main() {

  vector<int> primes;
  
  for (int i = 2; i <= n; i++){
    allNums[i - 2] = i;
  }

  int i = 0;
  
  while (i < n - 1){
    int num = allNums[i];
    
    if (num == 0){
      i++;
      continue;
    }
    else{
      int index = num * num - 2;
      empty(num, i++);
      
      primes.push_back(num);
    }
    
  }

  int count = 0;
  set<int> circular;
  
  for (int i = 0; i < primes.size(); i++){
    
    bool con = true;
    
    int num = primes[i];  
    int dig = digits(num) - 1;
    
    for (int j = 1; j <= dig ; j++){
      int first = num / (int)pow(10, dig);
      int second = num % (int)pow(10, dig);
      num = second * 10 + first;

      if (find(primes.begin(), primes.end(), num)==primes.end()){
	con = false;
	break;
      }
    }

    if (con == true){
      circular.insert(primes[i]);
    }
    
  }
  
  cout << circular.size();
  
  return 0;
  
}
