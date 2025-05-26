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
    int x,y;
    cin >> x >> y;
    int cnt = 0;
    for(int i=1;i<=6;i++) {
        for(int j=1;j<=6;j++) {
            if(i+j>=x || abs(i-j)>=y) cnt++;
        }
    }
    cout << fixed << setprecision(10) << 1.0*cnt/36 << endl;
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