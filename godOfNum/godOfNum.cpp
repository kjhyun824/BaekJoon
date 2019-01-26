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
    int origin;

    bool operator<(const struct numInfo& rhs) const{
        string a = to_string(origin), b = to_string(rhs.origin);
        return (a+b) > (b+a);
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
        _info.origin = input;
        nums.push_back(_info);
        
        if(maxNum < input) maxNum = input;
    }

    for(int i = 0; i < N-K; i++) {
        struct numInfo _info;
        _info.origin = maxNum;
        nums.push_back(_info);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        cout << to_string(nums[i].origin);
    }
    cout << endl;

    return 0;
}
