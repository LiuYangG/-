#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

struct node{
    int l;
    int r;
    int length;
    ll sum;
    ll add;
}tree[N * 4];
int a[N];
void build(int root, int l, int r){
    tree[root].l = l;
    tree[root].r = r;
    tree[root].length = (r-l+1);
    if(l == r){
        tree[root].sum = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
    tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}

void pushdown(int root){
    if(tree[root].add){
        tree[root*2].add+=tree[root].add;
		tree[root*2+1].add+=tree[root].add;
		tree[root].sum+=(tree[root].r-tree[root].l+1)*tree[root].add;
		tree[root].add=0;
    }
}

ll query(int root, int l, int r){
    if(l <= tree[root].l && tree[root].r <= r){
        return tree[root].sum+tree[root].add*(r-l+1);
    }
    pushdown(root);
    int mid = (tree[root].l + tree[root].r) / 2;
    ll sum = 0;
    if(tree[root].mid>=r) return query(root*2,l,r);
	else if(tree[root].mid<l) return query(root*2+1,l,r);
	else return query(root*2,l,tree[root].mid)+query(root*2+1,tree[root].mid+1,r);

}

void update(int root, int l, int r, ll x){
    if(l <= tree[root].l && tree[root].r <= r){
        tree[root].add += x;    
        return ;
    }
    tree[root].sum += x * (r-l+1);
    if(tree[root].mid>=r) update(2*root,l,r,x);
	else if(tree[root].mid<l) update(root*2+1,l,r,x);
	else{
		update(root*2,l,tree[root].mid,x);
		update(root*2+1,tree[root].mid+1,r,x);
	}
}
int n, m;
int main(){
    char s[5];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    build(1,1,n);
    for(int i = 1;i <= m;i ++){
        int l,r;
        ll d;
        scanf("%s%d%d",s, &l, &r);
        if(s[0] == 'Q'){
            printf("%lld\n",query(1,l,r));
        }
        else{
            scanf("%lld",&d);
            update(1, l, r, d);
        }
    }
    return 0;
}