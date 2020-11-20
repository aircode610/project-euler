#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>

using namespace std;

void bigSum(vector<int> nums[], int arrLength){
  
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
  
  for (int i = 0; i< 11; i++){
    cout << sumNums.back();
    sumNums.pop_back();
  }
  
}

int main() {

  ifstream fin("nums.txt");
  string line;

  vector<int> allNums[100];
  int index = 0;
  
  while (getline(fin, line)){
    vector<int> num;

    for (int i = 50; i >= 0; i--){
      num.push_back(line[i] - '0');
    }

    allNums[index++] = num;
    
  }
  
  bigSum(allNums, *(&allNums + 1) - allNums);
  
  return 0;
  
}
