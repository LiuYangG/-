#include <iostream>
#include <cstring>
using namespace std;
const int N = 20;
int num[N];
int n;
int f[N][2][10];
int dfs(int loc, bool limit, int sum)
{
    if (loc == 0)
        return sum;
    if (f[loc][limit][sum] != -1)
        return f[loc][limit][sum];
    int res = 0;
    int temp = limit ? num[loc] : 9;
    for (int i = 0; i <= temp; i++)
    {
        res += dfs(loc - 1, limit && (i == num[loc]), sum + (i == 1));
    }
    f[loc][limit][sum] = res;
    return res;
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
    return dfs(loc, 1, 0);
}
int main()
{
    cin >> n;
    cout << sol(n) << endl;
    return 0;
}