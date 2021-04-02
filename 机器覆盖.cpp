#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
int n, m, k;
bool g[N][N], st[N];
int match[N];
bool find(int x)
{
    for (int i = 1; i < m; i++)
    {
        if (!st[i] && g[x][i])
        {
            st[i] = true;
            int t = match[i];
            if (t == 0 || find(t))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while (cin >> n && n)
    {
        cin >> m >> k;
        memset(g, 0, sizeof g);
        memset(match, 0, sizeof match);

        while (k--)
        {
            int i, a, b;
            cin >> i >> a >> b;
            if (!a || !b)
                continue;
            g[a][b] = true;
        }
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            memset(st, 0, sizeof st);
            if (find(i))
                res++;
        }
        cout << res << endl;
    }
    return 0;
}