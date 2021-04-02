#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 30;
int n, m;
int a[N];
bool st[N];
void dfs(int u,int sta)
{
    if (u == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = sta; i <= n; i++)
    {
        if (!st[i])
        {
            a[u] = i;
            st[i] = true;
            dfs(u+1,i+1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(0,1);
    return 0;
}