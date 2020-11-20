#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int num = 15;
vector<int> tri[15];
int maxAll = 0;

void maxSum(int sum, pair<int, int> pos){

  if (pos.first == num - 1){
    sum += tri[pos.first][pos.second];
    
    if (sum > maxAll){
      maxAll = sum;
    }
    
    return;
  }

  sum += tri[pos.first][pos.second];
  maxSum(sum, make_pair(pos.first + 1, pos.second));
  maxSum(sum, make_pair(pos.first + 1, pos.second + 1));
  
}

int main() {

  int count = 1;
  
  ifstream fin("tri.txt");
  string line;
  
  while (getline(fin, line)){

    istringstream iss(line);

    for (int i = 0; i < count; i++){
      int val;
      iss >> val;
      
      tri[count - 1].push_back(val);
    }

    count++;
    
  }

  maxSum(0, make_pair(0, 0));
  
  cout << maxAll;
 
  return 0;
  
}
