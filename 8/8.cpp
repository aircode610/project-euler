#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main() {

  ifstream fin;
  fin.open("number.txt", ios::in);
  //ifstream fin("number.txt");
  //ofstream fout("out.txt");
  //fout<<max;

  int number[1000];

  char curr;
  int count = 0;
  
  while (!fin.eof() ) {//while(fin>>curr)

    fin.get(curr);//
    
    if (curr == '\n'){
      continue;
    }
    else{
      number[count] = (int)curr - 48;//curr-'0'
      count += 1;
    }
    
  }
 
  long int max = 0;
  
  for (int i = 0; i < 1000 - 12; i++){
   
    long int mult = 1;

    for (int j = i; j < i + 13; j++){
      mult *= number[j];
      cout << number[j];
    }

    cout << " " << mult  << endl;
    if (mult > max){
      max = mult;
    }
  }

  cout << max;
  
  return 0;

}
