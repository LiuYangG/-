#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 20;
int n;
int ans[N];
bool st[N];
void dfs(int p, int u,int sta)
{
    if (p == u)
    {
        for (int i = 0; i < p; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = sta; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            ans[u] = i;
            dfs(p, u + 1,i+1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    cout<<endl;
    for(int i=1;i<=n;i++){
        dfs(i,0,1);
    }
    return 0;
}