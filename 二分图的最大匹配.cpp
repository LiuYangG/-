#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, M = 100010;
//虽然是无向图，但是只会从左半边找到右半边，所以没必要存储无向图
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N]; //存储女孩配对的对象  
bool st[N];   //临时预定数组，st[j]=a表示一轮模拟匹配中，女孩j被男孩a预定了。
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x)//x能不能有配对的对象
{
    for (int i = h[x]; i != -1; i = ne[i])//遍历有好感的女生，
    {
        int j = e[i];
        if (!st[j])//在当前这一轮中，女孩还没有被预定，那就预定这个女孩
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))//同时判断这个女孩是否有对象，有对象的话，他对象能不能换个人谈恋爱
            {
                match[j] = x;//如果可以，就选定这个女孩。
                return true;//此时，匹配数增加1
            }
        }
    }
    return false;//找不到对象
}
int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, 0, sizeof(st));
        if (find(i))
        {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}