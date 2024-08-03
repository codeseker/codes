bool bfs(int src, vector<int> adj[], int vis[])
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                q.push({neighbour, node});
                vis[neighbour] = 1;
            }
            else if (parent != neighbour)
            {
                return true;
            }
        }
    }

    return false;
}

//  Using DFS
bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;

    for (auto adjacent : adj[node])
    {
        if (!vis[adjacent])
        {
            if (dfs(adjacent, node, vis, adj))
                return true;
        }
        else if (parent != adjacent)
            return true;
    }

    return false;
}