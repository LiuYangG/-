#include <iostream>
using namespace std;
int n, k;
int ans;
void dfs(int u, int l, int sum)
{
    if (u == k)
    {
        if (sum == n)
        {
            ans++;
        }
        return;
    }
    for (int i = l; i <= n - sum; i++)
    {
        dfs(u+1,i,sum+i);
    }
}
int main()
{
    cin >> n >> k;
    dfs(0, 1, 0);
    cout<<ans<<endl;
    return 0;
}