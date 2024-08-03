class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;

        vector<int> dist(V, INT_MAX);
        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            auto top = *(st.begin());
            st.erase(top);
            int node = top.second;
            int currentDistance = top.first;

            for (auto it : adj[node])
            {
                int v = it[0];
                int wt = it[1];

                if (currentDistance + wt < dist[v])
                {
                    if (dist[v] != INT_MAX)
                    {
                        st.erase({dist[v], v});
                    }

                    dist[v] = currentDistance + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
};