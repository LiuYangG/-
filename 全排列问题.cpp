#include<iostream>
using namespace std;
int n;
int p[10];
bool st[10];
void dfs(int u){
    if(u == n){
        for(int i=0;i<n;i++){
            printf("%5d",p[i]);
        }
        puts("");
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i] = true;
            p[u] = i;
            dfs(u+1);
            st[i] = false;
        }
    }
}
int main(){
    cin>>n;
    dfs(0);
    return 0;
}
