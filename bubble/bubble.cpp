#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    priority_queue<int, vector<int>, greater<int> > queue;

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        queue.push(temp);
        if(i+1 > K) {
            cout << queue.top() << " ";
            queue.pop();
        }
    }

    while(!queue.empty()) {
        cout << queue.top() << " ";
        queue.pop();
    }

    cout << '\n';

	return 0;
}
