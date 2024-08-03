vector<int> topoSort(int V, vector<int> adj[])
{
    int indeg[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto it : adj[node])
        {
            indeg[it]--;

            if (indeg[it] == 0)
                q.push(it);
        }
    }

    return ans;
}

// Using DFS
void dfs(int node, vector<int> adj[], stack<int> &st, int vis[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, st, vis);
        }
    }

    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    int vis[V] = {0};
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, st, vis);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}