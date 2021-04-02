#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N = 15;
int n;
int ans[N];
bool col[N], ug[N + N], uug[N + N];
int cnt;
void dfs(int u)
{
    if (u == n)
    {
        cnt++;
        if (cnt <= 3)
        {
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }

        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !ug[u + i] && !uug[n - u + i])
        {
            col[i] = ug[u + i] = uug[n - u + i] = true;
            ans[u] = i + 1;
            dfs(u + 1);
            col[i] = ug[u + i] = uug[n - u + i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    cout << cnt << endl;
    return 0;
}