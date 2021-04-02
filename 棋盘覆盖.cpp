#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 110;
int n, m;
bool g[N][N], st[N][N];
pii match[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool find(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && st[nx][ny] == false && g[nx][ny] == false)
        {
            st[nx][ny] = true;
            pii t = match[nx][ny];
            if (t.x == 0 || find(t.x, t.y))
            {
                match[nx][ny].x = x;
                match[nx][ny].y = y;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    //棋盘覆盖
    /*
        匹配：
        最多可以放置多少棋牌，可以理解为最多取多少条边
        棋牌不能重叠，可以理解为所有选择的边之间不能存在公共点（占用的格子也不能使用）
        二分图：
        在一个n*m的格子里，可以使用二染色的方式将图中所有的点进行染色。
    */
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = true; //不能放置点
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) % 2 == 1 && g[i][j] != true)
            {
                memset(st, 0, sizeof(st));
                if (find(i, j))
                    res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}