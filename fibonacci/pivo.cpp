#include <iostream>
using namespace std;

bool* flag;
int pivo(int n) {
    int returnVal;
    if ( n < 2 )  {
        returnVal = n;
    }
    else {
        returnVal = pivo(n-1) + pivo(n-2);
    }

    if( n != 0 && flag[n-1] ) {
        cout << returnVal << endl;
        flag[n-1] = false;
    }

    return returnVal;
}

int main() {
    int numPivo;

    cin >> numPivo;
    flag = new bool[numPivo];

    for(int i = 0; i < numPivo; i++) {
        flag[i] = true;
    }

    pivo(numPivo);

    return 0;
}
