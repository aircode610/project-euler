#include <iostream>

using namespace std;

const int n = 1001;
int grid[n][n];

bool isFull(){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (grid[i][j] == 0){
	return false;
      }
    }
  }
  return true;
}

void makeGrid(){

  int i = 0;
  int j = n - 1;
  int num = n * n;
  
  while (isFull() == false){

    while ((i < n && i > -1) && (j < n && j > -1) && grid[i][j] == 0){
      grid[i][j] = num--;
      j--;
    }
    j++;
    i++;

    while ((i < n && i > -1) && (j < n && j > -1) && grid[i][j] == 0){
      grid[i][j] = num--;
      i++;
    }
    i--;
    j++;

    while ((i < n && i > -1) && (j < n && j > -1) && grid[i][j] == 0){
      grid[i][j] = num--;
      j++;
    }
    i--;
    j--;

    while ((i < n && i > -1) && (j < n && j > -1) && grid[i][j] == 0){
      grid[i][j] = num--;
      i--;
    }
    i++;
    j--;
  }
  
}

int diagnolSum(int grid[n][n]){

  int dsum = 0;
  
  int i = 0;
  int j = 0;

  while (i < n){
    dsum += grid[i++][j++];
  }

  i = n - 1;
  j = 0;

  while (j < n){
    dsum += grid[i--][j++];
  }

  return dsum;
  
}

int main() {

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      grid[i][j] = 0;
    }
  }
  
  makeGrid();
  
  cout << diagnolSum(grid) - 1 << endl;
  
  return 0;
  
}
