#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
// 2 5 1 3 10
vector<int> g[N];
int w[N],dw[N];
int mxa=0,sum=0;
void dfs(int u, int fa) {
    priority_queue<int> q;
    for(auto x : g[u]) {
        if(x == fa) continue;
        dfs(x, u);
        q.push(w[x]);
    }
    int res=0;
    for(auto x : g[u]) {
        if(x == fa) continue;
        res += w[x] * (dw[u] - w[x]);
    }
    sum += res; 
    sum += w[fa] * dw[u] * 2;
    sum %= 10007;
    if(q.size()) mxa = max(mxa, w[fa] * q.top());
    if(q.size() > 1) {
        int top1 = q.top(); q.pop();
        int top2 = q.top();
        mxa = max(mxa, top1 * top2);
    }
    dw[fa] += w[u];
}
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin >> w[i];
    dfs(1,0);
    cout << mxa << ' ' << sum << endl;

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