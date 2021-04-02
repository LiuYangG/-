#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 20;
int a, b;
int num[N];
int f[N][N][2][2];
int dfs(int loc, int pre, bool limit, bool lead)
{
    if (loc == 0)
        return 1;
    if (f[loc][pre][limit][lead] != -1)
        return f[loc][pre][limit][lead];
    int ans = 0;
    int temp = limit ? num[loc] : 9;
    for (int i = 0; i <= temp; i++)
    {
        if (lead || abs(i - pre) >= 2)
        {
            ans += dfs(loc - 1, i, limit && (i == num[loc]), lead && (i == 0));
        }
    }
    f[loc][pre][limit][lead] = ans;
    return ans;
}
int sol(int x)
{
    memset(f, -1, sizeof(f));
    int loc = 0;
    while (x)
    {
        num[++loc] = x % 10;
        x /= 10;
    }
    return dfs(loc, 0, 1, 1);
}
int main()
{
    while (cin >> a >> b && a && b)
    {
        cout << sol(b) - sol(a - 1) << endl;
    }
    return 0;
}