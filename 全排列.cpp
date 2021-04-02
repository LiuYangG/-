#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string s;
int l;
char ans[30];
bool st[30];
void dfs(int u)
{
    if (u == l)
    {
        ans[u] = '\0';
        printf("%s\n", ans);
        return;
    }
    for (int i = 0; i < l; i++)
    {
        if (!st[i])
        {
            ans[u] = s[i];
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> s;
    l = s.length();
    dfs(0);
    return 0;
}