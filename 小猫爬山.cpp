#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20;
int n, w;
int q[N], cnt[N];
int ans = N;
bool cmp(int a, int b)
{
    return a > b;
}
void dfs(int u, int k) //u表示枚举到了第几个，k表示雇佣了多少车子
{
    if (k >= ans)
        return;
    if (u > n)
    {
        ans = k;
        return;
    }
    for (int i = 0; i < k; i++)
    {
        if (q[u] + cnt[i] <= w)
        {
            cnt[i] += q[u];
            dfs(u+1,k);
            cnt[i] -= q[u];
        }
    }
    //放不下了
    cnt[k] = q[u];
    dfs(u+1,k+1);
    cnt[k] = 0;
}
int main()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    sort(q, q + n, cmp);
    dfs(0, 0);
    cout<<ans<<endl;
    return 0;
}
