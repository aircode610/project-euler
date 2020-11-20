#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>

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

int main() {

  vector<int> last{1};
  vector<int> curr{1};

  int count = 2;

  while (curr.size() < 1000){

    vector<int> twoNums[2] = {last, curr};

    curr = bigSum(twoNums, 2);
    last = twoNums[1];

    count++;
  }

  cout << count;
  
  return 0;
  
}
