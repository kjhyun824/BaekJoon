/*
 * =====================================================================================
 *
 *       Filename:  CD.cpp
 *
 *    Description:  Find the number of overlapping CD
 *
 *        Version:  1.0
 *        Created:  01/23/19 12:40:40
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

int arr1[1000000], arr2[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1) {
        int N, M;
        cin >> N >> M;

        if(N == 0 && M == 0) break;

        for(int i = 0; i < N; i++) {
            cin >> arr1[i];
        }

        for(int i = 0; i < M; i++) {
            cin >> arr2[i];
        }

        int pos1 = 0, pos2 = 0;
        int answer = 0;
        while(pos1 < N && pos2 < M) {
            if(arr1[pos1] == arr2[pos2]) {
                answer++;
                pos1++;
                pos2++;
            } else {
                if(arr1[pos1] < arr2[pos2]) {
                    pos1++;
                } else {
                    pos2++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}
