#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 20;
ll num[N];
int nu;
ll a, b;
ll f[N][N][2][2];
ll dfs(int loc, int cnt, bool limit, bool lead) //loc:当前位，cnt:当前数字的个数,limit：最高位限制,lead 前导0
{
    if (loc == 0)
        return cnt;
    if (f[loc][cnt][limit][lead] != -1)
        return f[loc][cnt][limit][lead];
    ll ans = 0;
    ll temp = limit ? num[loc] : 9;
    for (ll i = 0; i <= temp; i++)
    {
        if (lead && i == 0)
        {
            ans += dfs(loc - 1, 0, 0, 1);
        }
        else
            ans += dfs(loc - 1, cnt + (i == nu), limit && (i == num[loc]), 0);
    }
    f[loc][cnt][limit][lead] = ans;
    return ans;
}
ll sol(ll x)
{
    memset(f,-1,sizeof(f));
    ll loc = 0;
    while (x)
    {
        num[++loc] = x % 10;
        x /= 10;
    }
    return dfs(loc, 0, 1, 1);
}
int main()
{
    cin >> a >> b;
    for (nu = 0; nu <= 9; nu++)
        cout << sol(b) - 0ll - sol(a - 1) << " ";
    return 0;
}