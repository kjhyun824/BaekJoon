/*
 * =====================================================================================
 *
 *       Filename:  seqChange.cpp
 *
 *    Description:  Given N size array to compressed after K iteration
 *
 *        Version:  1.0
 *        Created:  2019년 02월 22일 21시 26분 33초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int* arr = new int[N];
    string input, delim = ",";
    cin >> input;

    size_t pos = 0;
    int idx = 0;
    string token;
    while((pos = input.find(delim)) != std::string::npos) {
        token = input.substr(0,pos);
        arr[idx++] = stoi(token);
        input.erase(0, pos + delim.length());
    }
    arr[idx] = stoi(input);

    for(int i = 0; i < K; i++) {
        int* temp = new int[N-i-1];
        for(int j = 0; j < N-i-1; j++) {
            temp[j] = arr[j+1] - arr[j];
        }
        delete [] arr;
        arr = temp;
    }

    for(int i = 0; i < N-K-1; i++) {
        cout << arr[i] << ",";
    }
    cout << arr[N-K-1] << endl;

    delete [] arr;
    return 0;
}
