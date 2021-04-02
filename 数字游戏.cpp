#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20;
int a, b;
int num[N];
int f[N][2][N];
int dfs(int loc, bool limit, int pre)
{
    if (loc == 0)
        return 1;
    if (f[loc][limit][pre] != -1)
        return f[loc][limit][pre];
    int ans = 0;
    int temp = limit ? num[loc] : 9;
    for (int i = 0; i <= temp; i++)
    {
        if (pre <= i)
        {
            ans += dfs(loc - 1, limit && (i == num[loc]), i);
        }
    }
    f[loc][limit][pre] = ans;
    return ans;
}
int sol(int x)
{
    memset(f,-1,sizeof(f));
    int loc = 0;
    while (x)
    {
        num[++loc] = x % 10;
        x /= 10;
    }
    return dfs(loc, 1, 0);
}
int main()
{
    while (cin >> a >> b)
    {
        cout << sol(b) - sol(a - 1) << endl;
    }
    return 0;
}