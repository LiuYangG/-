#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 25;
int Case = 1;
int n;
int ans[N];
int cnt = 1;
bool st[N];
bool isP(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int step)
{
    if (step == n + 1)
    {
        if (ans[1] == 1)
        {
            if (isP(ans[1] + ans[n]) == true)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << ans[i] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i] && isP(i + ans[step - 1]) == true)
        {
            ans[step] = i;
            st[i] = true;
            dfs(step + 1);
            st[i] = false;
        }
    }
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    while (scanf("%d", &n) != EOF)
    {
        cout << "Case " << Case++ << ":" << endl;
        memset(ans, 0, sizeof(ans));
        if (n != 1)
        {
            dfs(1);
            cout<<endl;
        }else{
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}