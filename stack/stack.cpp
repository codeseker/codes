#include <bits/stdc++.h>

using namespace std;

int main()
{

    stack<int> st;
    st.push(20);
    st.push(10);
    st.push(30);
    st.push(40);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;

    cout << st.empty() << endl;

    return 0;
}