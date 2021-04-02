#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 20;
int a, b, mod;
int num[N];
int f[N][110][2];
int dfs(int loc, int sum, bool limit)
{
    if (loc == 0)
    {
        if (sum % mod == 0)
            return 1;
        return 0;
    }
    if (f[loc][sum][limit] != -1)
        return f[loc][sum][limit];
    int ans = 0;
    int temp = limit ? num[loc] : 9;
    for (int i = 0; i <= temp; i++)
    {
        ans += dfs(loc - 1, sum + i, limit && (i == num[loc]));
    }
    f[loc][sum][limit] = ans;
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
    return dfs(loc, 0, 1);
}
int main()
{
    while (cin >> a >> b >> mod)
    {
        cout << sol(b) - sol(a - 1) << endl;
    }
    return 0;
}