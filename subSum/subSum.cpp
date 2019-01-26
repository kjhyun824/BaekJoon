/*
 * =====================================================================================
 *
 *       Filename:  subSum.cpp
 *
 *    Description:  Find minimum length of subset that exceeds sum
 *
 *        Version:  1.0
 *        Created:  01/26/19 20:25:55
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

unsigned long long nums[100000];
int main() {
    int numInput, target;
    cin >> numInput >> target;

    bool onePossible = false;
    unsigned long long allSum = 0;
    for(int i = 0; i < numInput; i++) {
        cin >> nums[i];
        allSum += nums[i];
        if(nums[i] > target) {
            onePossible = true;
        }
    }

    if(allSum < target) {
        cout << 0 << endl;
        return 0;
    }

    if(onePossible) {
        cout << 1 << endl;
        return 0;
    }

    int head = 0, tail = 1;
    int currSum = nums[0] + nums[1]; 
    int minLength = numInput;

    while(true) {
        if(currSum < target) {
            tail++;
            currSum += nums[tail];
        } else {
            if(tail - head + 1 < minLength) {
                minLength = tail - head + 1;
            }

            currSum -= nums[head];
            head++;
        }

        if(tail >= numInput) break;
    }

    cout << minLength << endl;

    return 0;
}
