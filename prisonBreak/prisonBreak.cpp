/*
 * =====================================================================================
 *
 *       Filename:  prisonBreak.cpp
 *
 *    Description:  Break the prison with minimum number of opening door
 *
 *        Version:  1.0
 *        Created:  02/04/19 17:12:39
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

char prison[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int test = 0; test < T; test++) {
        int height, width;
        cin >> height >> width;

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                cin >> prison[i][j];
            }
        }
    }

    return 0;
}
