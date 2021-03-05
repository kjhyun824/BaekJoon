/*
 * =====================================================================================
 *
 *       Filename:  fibo.cpp
 *
 *    Description:  Fibonacci 1,0 print num
 *
 *        Version:  1.0
 *        Created:  04/14/18 14:49:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int zeros[41];
int ones[41];

void fibo(int N) {
  if(zeros[N] != -1) return;

  if(N == 0) {
    zeros[N] = 1;
    ones[N] = 0;
  } 
  else if(N == 1) {
    zeros[N] = 0;
    zeros[N] = 1;
  }
  else {
    fibo(N-1);
    fibo(N-2);
    zeros[N] = zeros[N-1] + zeros[N-2];
    ones[N] = ones[N-1] + ones[N-2];
  }
}

int main() {
  int numTest;
  cin >> numTest;
  for(int i = 0; i < 41; i++) {
    zeros[i] = -1;
    ones[i] = -1;
  }
  
  for(int T = 0; T < numTest; T++) {
    int numFibo;
    cin >> numFibo;
    fibo(numFibo);
    cout << zeros[numFibo] << " " << ones[numFibo] << endl;
  }
}
