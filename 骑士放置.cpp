#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
struct node
{
    int x, y;
};
int n, m, t;
bool g[N][N], st[N][N];
node match[N][N];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool find(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m)
            continue;
        if (g[nx][ny] || st[nx][ny])
            continue;
        st[nx][ny] = true;
        node tmp = match[nx][ny];
        if (tmp.x == 0 || find(tmp.x, tmp.y))
        {
            match[nx][ny].x = x;
            match[nx][ny].y = y;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] || (i + j) % 2)
                continue;
            memset(st, 0, sizeof st);
            if (find(i, j))
                res++;
        }
    }
    cout << n * m - t - res << endl;
    return 0;
}