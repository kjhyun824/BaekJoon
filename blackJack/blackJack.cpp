/*
 * =====================================================================================
 *
 *       Filename:  blackJack.cpp
 *
 *    Description:  Black Jack with N cards and Not exceed M
 *
 *        Version:  1.0
 *        Created:  01/23/19 02:30:30
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

int main() {
    int N, M;
    cin >> N >> M;

    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int maxi = -1;
    for(int i = 0; i < N-2; i++) {
        for(int j = i+1; j < N-1; j++) {
            for(int k = j+1; k < N; k++) {
                int currSum = arr[i] + arr[j] + arr[k];
                if(currSum <= M && currSum > maxi) {
                    maxi = currSum;
                }
            }
        }
    }

    cout << maxi << endl;

    return 0;
}
