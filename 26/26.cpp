#include <iostream>
#include <vector>

using namespace std;

int isIn(vector<int> v, int val){

  for (int i = 0; i < v.size(); i++){
    if (v[i] == val){
      return i;
    }
  }

  return -1;
    
}

int recurDigit(int num){

  int rem = 1;
  int div = 1;
  vector<int> divs;
  vector<int> allDivs;
  
  while (true){

    while (rem < num){
      rem *= 10;
    }
    
    div = rem / num;
    
    if (isIn(allDivs, rem) == -1){
      allDivs.push_back(rem);
      rem = rem - (div * num);
    }
    else {
      break;
    }
    
    if (rem == 0){
      return 0;
    }
  }

  int count = 0;
  for (int i = isIn(allDivs, rem); i < allDivs.size(); i++){
    count++;
  } 

  return count;
  
}

int main(){

  int maxDig = 0;
  int maxNum = 0;
  
  for (int i = 2; i < 1000; i++){
    if (recurDigit(i) > maxDig){
      maxDig = recurDigit(i);
      maxNum = i;
    }    
  }

  cout << maxNum;
  
  return 0;
  
}
