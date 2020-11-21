#include <iostream>

#define int long long

using namespace std;

const int n = 2000000;
int nums[n];

int gharbal(){

  nums[0] = nums[1] = 0;
  int sum = 0;
  for (int i = 2; i < n; i ++){
    if (nums[i] != 0){
      sum += nums[i];
      for (int j = nums[i] * nums[i]; j < n; j++){
	if (nums[j] % nums[i] == 0){
	  nums[j] = 0;
	}
      }
    }
  }

  return sum;
  
}

__int32_t main() {
  
  for (int i = 0; i < n - 1; i++){
    nums[i] = i;
  }

  cout << gharbal();
  
  return 0;
  
}
