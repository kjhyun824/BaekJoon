/*
 * =====================================================================================
 *
 *       Filename:  godOfNum.cpp
 *
 *    Description:  Make the largest number from K numbers by picking N numbers ( K <= N )
 *
 *        Version:  1.0
 *        Created:  01/26/19 17:56:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct numInfo{
    long long num;
    long long origin;
    int numSize;

    bool operator<(const struct numInfo& rhs) const{
        return (num > rhs.num) || (num == rhs.num && numSize < rhs.numSize);
    }
};

int getNumSize(long long num) {
    return to_string(num).length();
}

int main() {
    int K, N;
    cin >> K >> N;

    vector<struct numInfo> nums;
    long long maxNum = 0;
    int maxSize = -1;
    for(int i = 0; i < K; i++) {
        long long input;
        cin >> input;

        int numSize = getNumSize(input);
        struct numInfo _info;
        _info.origin = input;
        _info.numSize = numSize;
        nums.push_back(_info);
        
        if(maxNum < input) maxNum = input;
        if(maxSize < numSize) maxSize = numSize;
    }

    for(int i = 0; i < N-K; i++) {
        struct numInfo _info;
        _info.origin = maxNum;
        _info.numSize = maxSize;
        nums.push_back(_info);
    }

    for(int i = 0; i < nums.size(); i++) {
        nums[i].num = nums[i].origin * pow(10, maxSize - nums[i].numSize);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        cout << to_string(nums[i].origin);
    }
    cout << endl;

    return 0;
}
