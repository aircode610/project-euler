#include <iostream>
#include <vector>

using namespace std;

vector<int> abundants;

bool isAbun(int num){

  int sum = 0;

  for (int i = 1; i < num; i++){
    if (num % i == 0){
      sum += i;
    }
  }

  if (sum > num){
    return true;
  }

  return false;
  
}

bool isSum(int num){
  for (int i = 0; i < abundants.size(); i++){
    if (abundants[i] > num){
      return false;
    }
    
    for (int j = i; j < abundants.size(); j++){
      if (abundants[i] + abundants[j] == num){
	return true;
      }
      else if (abundants[i] + abundants[j] > num){
	break;
      }
    }
    
  }
  
  return false;
}

int main() {
  
  for (int i = 1; i <= 28123; i++){
    if (isAbun(i)){
      abundants.push_back(i);
    }
  }
  
  int sum = 0;
  
  for (int i = 1; i <= 28123; i++){
    if (isSum(i) == false){
      sum += i;
    }
  }

  cout << sum;
  
  return 0;
  
}
