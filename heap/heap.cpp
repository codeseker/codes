#include <bits/stdc++.h>
using namespace std;

int main()
{

    // max heap
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(3);
    pq.push(4);
    pq.push(11);

    cout << pq.top() << endl;
    // pq.pop();
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    cout << pq.empty() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    // Min heap
    vector<int> arr;
    // sort(arr.begin(), arr.end()); -> ascen
    // sort(arr.begin(), arr.end(), greater<int>); -> desc

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // 10 ,20, 3, 4, 11
    pq.push(10);
    pq.push(20);
    pq.push(3);
    pq.push(4);
    pq.push(11);
    O(N)

    sorting->O(N) space used
            NLogN

                cout
        << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    O(n)
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
