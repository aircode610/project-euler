#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

  string allNames;
  
  ifstream fin("names.txt");
  fin >> allNames;
  
  allNames.erase(remove(allNames.begin(), allNames.end(), '"'), allNames.end());
  allNames += ',';
  
  vector<string> names;
  string str = "";
  
  for (int i = 0; i < allNames.size(); i++){
    if (allNames[i] == ','){
      names.push_back(str);
      str = "";
    } else {
      str += allNames[i];
    }
    
  }

  sort(names.begin(), names.end());
  
  int sumScore = 0;
  
  for (int i = 0; i < names.size(); i++){
    
    int currScore = 0;
    for (int j = 0; j < names[i].size(); j++){

      currScore += (int)names[i][j] - 64;
      
    }

    sumScore += currScore * (i + 1);
    
  }

  cout << sumScore;
  
  return 0;
  
}
