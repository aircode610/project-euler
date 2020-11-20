#include <iostream>
#include<string> 
using namespace std;

bool isPal(int num){

  string numStr = to_string(num);
  int len = numStr.length();
  /*int a[10],x=len,n=0;
  while(x>0)
    {
      n++;
      a[n]=x%10;
      x/=10;
    }*/
  for (int i = 0; i < len; i++){

    if (numStr[i] != numStr[len - i - 1]){
      return false;
    }
    
  }
  
  return true;

}

int main() {

  int max = 0;//max-> max_
  
  for (int i = 100; i <= 999; i++){
				   
    for (int j = 100; j <= 999; j++){

      if (isPal(i * j) == true && i * j > max){
        max = i * j;
      }
      
    }

  }

  cout << max;
  
  return 0;

}
