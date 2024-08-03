#include <bits/stdc++.h>
using namespace std;

int main()
{

    queue<int> q;

    q.push(10);
    q.push(12);
    q.push(20);
    q.push(89);

    cout << "size of queue is: " << q.size() << endl;

    cout << "front element is: " << q.front() << endl;
    cout << "back element is: " << q.back() << endl;

    q.pop();

    cout << "front element is: " << q.front() << endl;
    cout << "back element is: " << q.back() << endl;

    cout << q.empty() << endl;

    deque<int> dq;

    dq.push_back(10);
    dq.push_back(40);
    dq.push_front(30);
    dq.push_front(80);

    // [ [80, 30, 10, 100]]

    // 10 40   (eye)
    cout << dq.front() << endl; // 80
    dq.pop_front();
    cout << dq.front() << endl; // 30

    dq.pop_back();
    cout << dq.back() << endl;
    dq.push_back(100);
    cout << dq.back() << endl;
    return 0;
}