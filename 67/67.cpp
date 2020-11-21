#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n = 100, a[100][100], dp[100][100];

int main (){

  ifstream fin ("triangle.txt");

  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= i; j++){
      fin >> a[i][j];
    }    
  }

  for (int i = n; i >= 0; i--){
    for (int j = 0; j <= i; j++){
      dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    }
  }

  cout << dp[0][0];
  
  return 0;
  
}
