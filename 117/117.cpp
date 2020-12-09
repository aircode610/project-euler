#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 50 + 10;
int dp[M];

int32_t main() {

  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= 50; i++){
    if (i >= 4)
      dp[i] += dp[i-4];
    if (i >= 3)
      dp[i] += dp[i-3];
    dp[i] += dp[i-2] + dp[i-1];
  }

  cout << dp[50];
  
  return 0;
  
}
