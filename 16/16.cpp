#include<iostream>
#include<vector>

using namespace std;

void bigPower(int base, int exponent){

  vector<int> multAll{1};

  for (int i = 0; i < exponent; i++){

    int multLen = multAll.size();
    int rem = 0;
    
    vector<int> tempMult;

    for (int j = 0; j < multLen; j++){
      int mult = base * multAll[j] + rem;
      tempMult.push_back(mult % 10);
      rem = mult / 10;
    }
    
    if (rem != 0){
      tempMult.push_back(rem);
    }

    multAll = tempMult;
    
  }

  int sumAll = 0;
  
  for (int i = 0; i < multAll.size(); i++){
    sumAll += multAll[i];
  }

  cout << sumAll;
  
}

int main() {

  bigPower(2, 1000);
  
  return 0;
  
}
