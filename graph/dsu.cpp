#include <bits/stdc++.h>
using namespace std;

class Dsu
{

    vector<int> rank, parent, size;

public:
    Dsu(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main()
{
    Dsu ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Are is same component" << endl;
    }
    else
    {
        cout << "Are not same component" << endl;
    }

    ds.unionBySize(3, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Are is same component" << endl;
    }
    else
    {
        cout << "Are not same component" << endl;
    }
    return 0;
}