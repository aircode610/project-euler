#include <bits/stdc++.h>
#define int long long

using namespace std;

int n = 21;
const int M = 23;
int dp[M][M];

int32_t main() {
  
  dp[n - 1][n] = 1;
  dp[n][n - 1] = 1;
  int i = n - 1;
  int j = n;
  
  while (i >= 1 && j >= 1){
    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    if (dp[i][j] == 0){
      dp[i][j] = 1;
    }
    if (i == 1){
      i = n;
      j--;
    }
    else {
      i--;
    }
  }
  
  cout << dp[1][1];
  
  return 0;
  
}
