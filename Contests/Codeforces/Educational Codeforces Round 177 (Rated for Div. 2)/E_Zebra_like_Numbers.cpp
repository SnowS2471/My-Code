#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;
const int inf = 1000000000000000000;
int l,r,k;
int a[32];
map< pair<int,int>, int > dp;
void init() {
    for(int i=1;i<=30;i++) {
        a[i]=a[i-1]*4+1;
        dp[{a[i],1}]=i;
    }
}
int dfs(int x,int y) {
    // cout << x << ' ' << y << endl;
    if(x==0 || x<y) return 0;
    if(dp.count({x,y})) return dp[{x,y}];
    int p=30;
    for(int i=30;i>=1;i--) {
        if(a[i]<=x) {
            p=i;
            break;
        }    
    }
    // if(!p&&y==1) return 30;
    if(y==1) return dp[{x,y}]=p;
    return dp[{x,y}] = dfs(x-a[p],y-1) + dfs(a[p]-1,y);
}
void solve() {
    cin >> l >> r >> k;
    cout << dfs(r,k) - dfs(l-1,k) << endl;
}
signed main() {
    cios
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}