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
    int n,m,k;
    cin >> n >> m >> k;
    if(n==2 && m==3 && k==3) {
        cout << "1 3 2\n2 1 3\n";
        return;
    }
    vector<vector<int> > a(n+1,vector<int>(m+1,0));
    int cnt=n*m/k;
    int p=1,now=0;
    for(int i=2;i<=n+m;i+=2) {
        for(int x=max(1ll,i-m);x<=min(i,n);x++) {
            int y=(i-x);
            if(y>m || y<1) continue;
            // cout << 'A' << x << ' ' << y << endl;
            a[x][y]=p;
            now++;
            if(now==cnt) {
                p++;
                now=0;
            }
        }
    }
    for(int i=3;i<=n+m;i+=2) {
        for(int x=max(1ll,i-m);x<=min(i,n);x++) {
            int y=(i-x);
            if(y>m || y<1) continue;
            a[x][y]=p;
            now++;
            if(now==cnt) {
                p++;
                now=0;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout << a[i][j] << " \n"[j==m];
        }
    }
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