#include<iostream>
using namespace std;
const int N = 15;
int count = 1;
int col[N],ug[N+N],uug[N+N];
int Map[N][N];
void dfs(int u){
    if(u==8){
        //找满了8行
        cout<<"No. "<<count++<<endl;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<Map[i][j]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    for(int i=0;i<8;i++){
        if(!col[i]&&!ug[u+i]&&!uug[8-u+i]){
            Map[u][i] = 1;
            col[i] = ug[u+i] = uug[8-u+i] = 1;
            dfs(u+1);
            Map[u][i] = 0;
            col[i] = ug[u+i] = uug[8-u+i] = 0;
        }
    }
}
int main()
{
    dfs(0);
    return 0;
}