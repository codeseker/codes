class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};
        int minTime = 0;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int row = front.first.first;
            int col = front.first.second;

            grid[row][col] = 2;

            int time = front.second;
            minTime = time;
            for (int i = 0; i < 4; i++)
            {
                int x = row + r[i];
                int y = col + c[i];

                if ((x >= 0 && x < n) && (y >= 0 && y < m) && vis[x][y] == 0 && grid[x][y] == 1)
                {
                    q.push({{x, y}, time + 1});
                    vis[x][y] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return minTime;
    }
};