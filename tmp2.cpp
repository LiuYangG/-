#include <iostream>
#include <cstring>
using namespace std;
const int N = 205;
int n, m, t, x, y;
bool g[N][N], st[N];
int match[N];
bool find(int x)
{
    for (int y = 1; y <= m; y++)
    {
        if (g[x][y] || st[y])
            continue;
        st[y] = true;
        if (!match[y] || find(match[y]))
        {
            match[y] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m >> t;
    while (t--)
    {
        cin >> x >> y;
        g[x][y] = true;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(st, 0, sizeof st);
        if (find(i))
            res++;
    }
    cout << res << endl;
    return 0;
}