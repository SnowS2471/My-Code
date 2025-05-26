#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 505, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}

struct yyy{
    int v,l,c;
};
vector<yyy> g[N];

void solve() {
    int n,m,x;
    cin >> n >> m >> x;
    set<int> st;
    for(int i=1;i<=m;i++) {
        int u,v,l,c;
        cin >> u >> v >> l >> c;
        g[u].push_back({v,l,c});
        g[v].push_back({u,l,c});
        st.insert(c);
    }
    int ans = 1e9;
    for(int mx : st) {
        vector<int> disl(n+1,1e9),mc(n+1,1e9);
        vector<int> vis(n+1,0);
        disl[1] = 0;
    
        for(int i=1;i<n;i++) {
            int y = 0;
            for(int j=1;j<=n;j++) {
                if(!vis[j] && (y == 0 || disl[j] + x / mc[j] < disl[y] + x / mc[y])) {
                    y = j;
                }
            }
            if(y==0) break;
            vis[y] = 1;
            for(auto [a,b,c]:g[y]) {
                if(!vis[a] && c >= mx && disl[y] + b + x / mx < disl[a] + x / mx){
                    disl[a] = disl[y] + b;
                }
            }
        }
        ans = min(ans,disl[n] + x / mx);
    }

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