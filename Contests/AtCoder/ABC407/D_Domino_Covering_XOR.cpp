#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > a(n,vector<int>(m)),g(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    int ans=0;
    function<void(int)> dfs = [&](int id) {
        // cout << id << endl;
        int x = id/m, y = id%m;
        if(id==n*m) {
            int res = 0;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(!g[i][j]) res^=a[i][j];
                }
            }
            ans=max(ans,res);
            return;
        }
        dfs(id+1);
        if(x<n-1 && !g[x][y]) {
            g[x][y] = g[x+1][y] = 1;
            dfs(id+1);
            g[x][y] = g[x+1][y] = 0;
        }
        if(y<m-1 && !g[x][y] && !g[x][y+1]) {
            g[x][y] = g[x][y+1] = 1;
            dfs(id+1);
            g[x][y] = g[x][y+1] = 0;
        }
    };
    dfs(0);
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