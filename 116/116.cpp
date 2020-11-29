#include <bits/stdc++.h>
#define int long long

using namespace std;

int N = 50;
const int M = 50 + 10;
int red[M][M];
int green[M][M];
int blue[M][M];

int32_t main() {

  int ways = 0;
  
  for (int j = 0; j <= N; j++){
    red[0][j] = 1;
    green[0][j] = 1;
    blue[0][j] = 1;
  }
  
  for (int i = 1; i <= N; i++){
    for (int j = 2; j <= N; j++){
      red[i][j] = red[i][j-1] + red[i-1][j-2];
    }
    ways += red[i][N];
  }
  
  for (int i = 1; i <= N; i++){
    for (int j = 3; j <= N; j++){
      green[i][j] = green[i][j-1] + green[i-1][j-3];
    }
    ways += green[i][N];
  }

  for (int i = 1; i <= N; i++){
    for (int j = 4; j <= N; j++){
      blue[i][j] = blue[i][j-1] + blue[i-1][j-4];
    }
    ways += blue[i][N];
  }

  cout << ways;
  
  return 0;
  
}
