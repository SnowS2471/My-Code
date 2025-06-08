#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 805, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int g[N][N];
void solve() {
    int n;
    cin >> n;
    vector<int> f(n*2+1,0);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> g[i][j];
            f[g[i][j]]=1;
        }
    }
    for(int i=1;i<=n<<1;i++) if(!f[i]) cout << i << ' ';
    for(int i=1;i<n;i++) cout << g[1][i] << ' ';
    for(int i=1;i<=n;i++) cout << g[i][n] << " \n"[i==n];
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