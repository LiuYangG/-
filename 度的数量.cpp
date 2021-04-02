#include<bits/stdc++.h>
using namespace std;
const int N = 35;
int f[N][N]; // f[i][j] 表示枚举到第i位,枚举了j个1的方案
int k, B;
int a[N]; //取出数字的各位数
int dp(int i, int j, int limit){// 表示枚举到第i位,枚举了j个1的方案，limit表示是否是上限
    if(i == 0) return j == 0;// 对应 f[0][0] = 1;
    if(!limit && f[i][j] != -1) return f[i][j];
    int up = limit? a[i] : B-1;
    int ans = 0;
    for(int k = 0; k <= min(up,1); k++){ // 第i位只能取0或者1;
        ans  += dp(i-1,j - (k==1),limit && k == up );// 状态转移 , f[i][j] = f[i-1][j - (k==1)]
    }
    if(!limit) f[i][j] = ans;// 记忆化
    return ans;
}
int solve(int x){
    int n = 0;
    while(x){
        a[++n] = x%B;
        x /= B;
    }
    return dp(n,k,1);
}
int main(){
    int x , y;
    cin >> x >> y;
    cin >> k >> B;
    memset(f, -1, sizeof f);
    cout << solve(y) - solve(x-1);
    return 0;
}