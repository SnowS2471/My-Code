#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 1000005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
struct yyy{
    int v,w;
};
vector<yyy> g[N];
int sz[N];
int ans;
int n;
void dfs(int u, int fa) {
    if(g[u].size() == 1) {
        sz[u]=1;
        return;
    }
    for(auto x: g[u]) {
        if(x.v == fa) continue;
        dfs(x.v, u);
        ans += x.w * abs(sz[x.v] - (n - sz[x.v]));
        sz[u] += sz[x.v]; 
    }
    sz[u] ++;
}
void solve() {
    cin >> n;
    for(int i=1;i<n;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
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