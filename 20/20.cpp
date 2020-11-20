#include<iostream>
#include<vector>

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

vector<int> bigMult(vector<int> fNum, int sNum){

  vector<int> mult;
  int count = 0;

  while (sNum != 0){

    vector<int> tempMult;
    tempMult.resize(count++);
    int rem = 0;
    int num = sNum % 10;

    for (int i = fNum.size() - 1; i >= 0; i--){

      int multTwo = fNum[i] * num + rem;
      tempMult.push_back(multTwo % 10);
      rem = multTwo / 10;
      
    }

    if (rem != 0){
      tempMult.push_back(rem);
    }
    
    vector<int> arr[2] = {mult, tempMult};
    mult = bigSum(arr, 2);
    
    sNum /= 10;

  }

  return mult;
      
}

int main() {

  vector<int> fact{1};
  
  for (int i = 2; i <= 100; i++){
    fact = bigMult(fact, i);
  }

  int sum = 0;
  
  for (int i = 0; i < fact.size(); i++){
    sum += fact[i];
  }

  cout << sum;
  
  return 0;

}
