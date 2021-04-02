#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20;
int a, b;
int num[N];
int f[N][2][2];
int dfs(int loc, bool limit, bool preis6)
{
    if (loc == 0)
        return 1;
    if(f[loc][limit][preis6]!=-1)return f[loc][limit][preis6];
    int ans = 0;
    int temp = limit ? num[loc] : 9;
    for (int i = 0; i <= temp; i++)
    {
        if (i == 2 && preis6)
            continue;
        if (i != 4)
        {
            ans += dfs(loc - 1, limit && (i == num[loc]), i == 6);
        }
    }
    f[loc][limit][preis6] = ans;
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
    while (cin >> a >> b && a && b)
    {
        cout << sol(b) - sol(a - 1) << endl;
    }
    return 0;
}