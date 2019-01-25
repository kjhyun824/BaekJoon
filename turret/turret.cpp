/*
 * =====================================================================================
 *
 *       Filename:  turret.cpp
 *
 *    Description:  Find location of person with information from turrets
 *
 *        Version:  1.0
 *        Created:  01/25/19 15:48:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0 ; i < T; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if(x1 == x2 && y1 == y2 && r1 == r2) {
            cout << -1 << endl;
            continue;
        }

        float dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

        if(dist > (r1+r2) || dist < abs(r1-r2)) {
            cout << 0 << endl;
        } else if(dist == float((r1+r2)) || dist == float(abs(r1-r2))) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
