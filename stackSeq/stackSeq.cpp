/*
 * =====================================================================================
 *
 *       Filename:  stackSeq.cpp
 *
 *    Description:  Stack Sequence that makes reasonable output
 *
 *        Version:  1.0
 *        Created:  01/23/19 02:49:02
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
#include <string>
using namespace std;

int main() {
    int num, pos = 0;
    cin >> num;
    vector<int> seqStack;
    string output = "";

    int currInput;
    for(int i = 0; i < num; i++) {
        cin >> currInput;
        if(pos < currInput) {
            while(pos != currInput) {
                seqStack.push_back(++pos);
                output += "+\n";
            }
            seqStack.pop_back();
            output += "-\n";
        } else {
            if(seqStack.back() != currInput) {
                cout << "NO" << endl;
                return 0;
            }

            seqStack.pop_back();
            output += "-\n";
        }
    }

    cout << output.substr(0, output.size()-1) << endl;

    return 0;
}
