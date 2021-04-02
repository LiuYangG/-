#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20010, M = 200010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int col[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs(int u, int c, int mid)
{
    col[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (w[i] <= mid)
            continue;
        int j = e[i];
        if (col[j])
        {
            if (col[j] == c)
                return false;
        }
        else if (!dfs(j, 3 - c, mid))
            return false;
    }
    return true;
}
bool check(int mid)
{
    memset(col, 0, sizeof col);
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            if (!dfs(i, 1, mid))
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int l = 0, r = 1e9;
    while (l < r)
    {
        
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout<<r<<endl;
    return 0;
}