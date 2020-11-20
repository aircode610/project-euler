#include <iostream>

using namespace std;

const int n = 20;

int main() {
  
  int grid[20][20];
  for (int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> grid[i][j];
    }
  }

  int maxProduct = 0;
  
  // ver and hor
  for (int i = 0; i <= n- 4; i++){
    for (int j = 0; j <= n- 4; j++){
      int product = 1;
      
      for (int k = i; k < i + 4; k++){
	product *= grid[k][j];
      }
      if (product > maxProduct){
	maxProduct = product;
      }

      product = 1;
      
      for (int k = j; k < j + 4; k++){
	product *= grid[i][k];
      }
      if (product > maxProduct){
	maxProduct = product;
      }
      
    }  
  }

  // diag
  for (int i = 3; i < n - 3; i++){
    for (int j = 3; j < n - 3; j++){
      int product = 1;
      for (int k = 0; k < 4; k++){
	product *= grid[i + k][j + k];
      }
      if (product > maxProduct){
	maxProduct = product;
      }

      product = 1;
      for (int k = 0; k < 4; k++){
	product *= grid[i + k][j - k];
      }
      if (product > maxProduct){
	maxProduct = product;
      }

      product = 1;
      for (int k = 0; k < 4; k++){
	product *= grid[i - k][j + k];
      }
      if (product > maxProduct){
	maxProduct = product;
      }

      product = 1;
      for (int k = 0; k < 4; k++){
	product *= grid[i - k][j - k];
      }
      if (product > maxProduct){
	maxProduct = product;
      }
    }
  }

  cout << maxProduct;
  
  return 0;
  
}
