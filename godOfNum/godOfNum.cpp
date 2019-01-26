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
    string origin;
    int numSize;

    bool operator<(const struct numInfo& rhs) const{
        return (origin + rhs.origin) > (rhs.origin + origin);
    }
};

int main() {
    int K, N;
    cin >> K >> N;

    vector<struct numInfo> nums;
    int  maxNum = 0;
    for(int i = 0; i < K; i++) {
        int input;
        cin >> input;

        struct numInfo _info;
        _info.origin = to_string(input);
        _info.numSize = _info.origin.length();
        nums.push_back(_info);
        
        if(maxNum < input) maxNum = input;
    }

    for(int i = 0; i < N-K; i++) {
        struct numInfo _info;
        _info.origin = to_string(maxNum);
        _info.numSize = _info.origin.length();
        nums.push_back(_info);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i].origin;
    }
    cout << endl;

    return 0;
}
