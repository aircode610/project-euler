#include<sys/resource.h>
#include <iostream>

using namespace std;

int chain(long long start, int count) {
  if (start == 1){
    return count + 1;
  }
  if (start % 2 == 0){
    return chain(start / 2, ++count);
  }else {
    return chain(3 * start + 1, ++count);
  }
}

int main() {

  const rlim_t rlm=1024*1024*1024;
  struct rlimit rl;
  getrlimit(RLIMIT_STACK,&rl);
  rl.rlim_cur=rlm;
  setrlimit(RLIMIT_STACK, &rl);
  
  int maxChain = 0;
  int maxStart = 0;
  
  for (long long i = 1; i < 1000000; i++){
    int chainCount = chain(i, 0);
    if (maxChain < chainCount){
      maxChain = chainCount;
      maxStart = i;
    }
  }

  cout << maxStart;
  
  return 0;
  
}
