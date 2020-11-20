#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d(int num){

  int sum = 0;

  for (int i = 1; i < num; i++){
    if (num % i == 0){
      sum += i;
    }
  }

  return sum;
  
}

int main() {

  vector<int> amicables;
  
  for (int i = 1; i < 10000; i++){
    int pd = d(i);
    int dpd = d(pd);
    
    if (dpd == i && (find(amicables.begin(), amicables.end(), dpd) == amicables.end()) && dpd != pd){
      amicables.push_back(pd);
      amicables.push_back(dpd);
    }
    
  }

  int sum = 0;

  for (int i = 0; i < amicables.size(); i++){
    cout << amicables[i] << endl;
    sum += amicables[i];
  }

  cout << sum;
  
  return 0;
  
}
