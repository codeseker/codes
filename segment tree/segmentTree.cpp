#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> seg;
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int index, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int index, int low, int high, int l, int r)
    {

        // no overlap [low, high] [l, r] || [l, r] [low, high]
        if (high < l || r < low)
        {
            return INT_MAX;
        }

        // complete overlap [l, low high, r]
        if (low >= l && high <= r)
            return seg[index];

        int mid = low + (high - low) / 2;
        int op1 = query(2 * index + 1, low, mid, l, r);
        int op2 = query(2 * index + 2, mid + 1, high, l, r);
        return min(op1, op2);
    }

    void update(int index, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[index] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid)
        {
            update(2 * index + 1, low, mid, i, val);
        }
        else
        {
            update(2 * index + 2, mid + 1, high, i, val);
        }
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

void solve()
{
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    SegmentTree sg1(n);
    sg1.build(0, 0, n - 1, arr1);

    int n2;
    cin >> n2;
    int arr2[n2];

    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    SegmentTree sg2(n2);
    sg2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            int val1 = sg1.query(0, 0, n - 1, l1, r1);
            int val2 = sg2.query(0, 0, n2 - 1, l2, r2);
            cout << min(val1, val2) << endl;
        }
        else
        {
            int arrNo, i, val;
            cin >> arrNo >> i >> val;

            if (arrNo == 1)
            {
                sg1.update(0, 0, n - 1, i, val);
                arr1[i] = val;
            }
            else
            {
                sg2.update(0, 0, n2 - 1, i, val);
                arr2[i] = val;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}