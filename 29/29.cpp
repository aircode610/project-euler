#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> bigSum(vector<int> nums[], int arrLength){
  
  vector<int> sumNums = nums[0];

  for (int i = 1; i < arrLength; i++){
    int maxSize = max(nums[i].size(), sumNums.size());
    
    sumNums.resize(maxSize);
    nums[i].resize(maxSize);

    vector<int> tempSum;
    int rem = 0;
      
    for (int j = 0; j < maxSize; j++){
      int sumTwo = nums[i][j] + sumNums[j] + rem;
      tempSum.push_back(sumTwo % 10);
      rem = sumTwo / 10;
    }

    if (rem != 0){
      tempSum.push_back(rem);
    }
    sumNums = tempSum;
  }
  
  return sumNums;
  
}

vector<int> bigPower(int base, int exponent){

  vector<int> multAll{1};

  for (int i = 0; i < exponent; i++){

    vector<int> sum;
    int count = 0;
    int tempBase = base;
      
    while (tempBase != 0){

      vector<int> tempMult;    
      tempMult.resize(count++);
      int rem = 0;
      int num = tempBase % 10;
      
      for (int j = 0; j < multAll.size(); j++){
	int mult = num * multAll[j] + rem;
	tempMult.push_back(mult % 10);
	rem = mult / 10;
      }

      if (rem != 0){
	tempMult.push_back(rem);
      }  

      vector<int> arr[2] = {sum, tempMult};
      sum = bigSum(arr, 2);
      
      tempBase /= 10;
      
    }

    multAll = sum;
    
  }

  return multAll;
  
}

int main() {

  set<vector<int>> terms;
  
  for (int a = 2; a <= 100; a++){

    for (int b = 2; b <= 100; b++){

      terms.insert(bigPower(a, b));
      
    }

  }

  cout << terms.size();
  
  return 0;
  
}
