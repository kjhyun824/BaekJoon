/*
 * =====================================================================================
 *
 *       Filename:  bracket2.cpp
 *
 *    Description:  Bracket 2
 *
 *        Version:  1.0
 *        Created:  01/21/19 15:29:16
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
#include <vector>
#include <bitset>
#include <cmath>
#include <climits>
using namespace std;

vector<int> numbers;
vector<char> operators;

/* Calculate for a combination
 * Step 1. Find brackets using bit operation
 * Step 2. Calculate bracket operations
 * Step 3. Calculate multiplications
 * Step 4. Calculate rest operators
 */

int eval(int num1, int num2, char oper) {
    switch(oper) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:
            exit(-1);
    }
}

bool isAvailable(string binary) {
    return (binary.find("11") == std::string::npos);
}

int calculate(int combination, const int numOper) {
    int calcVal;

    string binary = bitset<16>(combination).to_string().substr(16 - numOper);

    if(!isAvailable(binary)) {
        return INT_MIN;
    }

    vector<int> tempNum;
    vector<char> tempOper;
    tempNum.push_back(numbers[0]);

    for(int i = 0; i < numOper; i++) {
        if( binary[i] == '0') {
            tempNum.push_back(numbers[i+1]);
            tempOper.push_back(operators[i]);
        } else {
            int value = eval(tempNum.back(), numbers[i+1], operators[i]);
            tempNum.pop_back();
            tempNum.push_back(value);
        }
    }

    vector<int> tempNum2;
    vector<char> tempOper2;
    tempNum2.push_back(tempNum[0]);

    for(int i = 0; i < tempOper.size(); i++) {
        if( tempOper[i] != '*') {
            tempNum2.push_back(tempNum[i+1]);
            tempOper2.push_back(tempOper[i]);
        } else {
            int value = tempNum2.back() * tempNum[i+1];
            tempNum2.pop_back();
            tempNum2.push_back(value);
        }
    }

    calcVal = tempNum2[0];

    for(int i = 0; i < tempOper2.size(); i++) {
        calcVal = eval(calcVal, tempNum2[i+1], tempOper2[i]);
    }

    return calcVal;
}

int main() {
    int len;
    string input;
    cin >> len >> input;

    for(int i = 0; i < len; i++) {
        if(i % 2 == 0) {
            numbers.push_back(input[i] - '0');
        } else {
            operators.push_back(input[i]);
        }
    }

    int numOper = operators.size();
    int answer = INT_MIN, combination = 0;
    int bound = pow(2, operators.size());

    while(combination < bound){
        int result = calculate(combination, numOper);

        if(result > answer) {
            answer = result;
        }

        combination++;
    }

    cout << answer << endl;

    return 0;
}
