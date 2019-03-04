/*
 * =====================================================================================
 *
 *       Filename:  Z.cpp
 *
 *    Description:  Find the order of visit using Z-direction search
 *
 *        Version:  1.0
 *        Created:  03/04/2019 10:10:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

int findLoc(int i, int r, int c) {
    int threshold = pow(2,i);
    if(r < threshold && c < threshold) { return 0; }
    else if(r < threshold && c >= threshold) { return 1; }
    else if(r >= threshold && c < threshold) { return 2; }
    else { return 3; }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    int order = 0;

    for(int i = N-1; i >= 0; i--) {
        int loc = findLoc(i, r, c);
        order += loc * pow(2, 2*i);

        switch(loc) {
            case 0:
                break;
            case 1:
                c -= pow(2, i);
                break;
            case 2:
                r -= pow(2, i);
                break;
            case 3:
                c -= pow(2, i);
                r -= pow(2, i);
                break;
        }
    }

    cout << order << endl;

    return 0;
}
