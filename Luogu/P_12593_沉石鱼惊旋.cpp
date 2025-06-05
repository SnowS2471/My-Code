#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
struct yyy{
    int v,w;
};
vector<yyy> g[10];
vector<int> d(10);
int ans=1e18;
bool vis[10];
int n,m;
void dfs(int u,int res){
    if(u>n) {
        ans=min(ans,res);
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            vis[i]=1;
            int al=0;
            for(auto [v,w]:g[i]) {
                if(!vis[v]) {
                    d[v]--;
                    al+=w;
                }
            }
            dfs(u+1,res+al*d[i]);
            vis[i]=0;
            for(auto [v,w]:g[i]) {
                if(!vis[v]) {
                    d[v]++;
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i=1,u,v,w;i<=m;i++) {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        d[u]++,d[v]++;
    }
    dfs(1,0);
    cout << ans << endl;
}
signed main() {
    cios
    init();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}