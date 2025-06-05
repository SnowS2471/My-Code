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
    int n;
    cin >> n;
    if(n==1) {
        cout << 1 << endl << 1 << endl;
        return;
    }
    cout << n/2 << endl;
    for(int i=1;i<=n/2;i++) {
        cout << i*2 << ' ';
    }
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