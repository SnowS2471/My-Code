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
    int n,k;
    cin >> n >> k;
    if(n==1) {
        if(k==2) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    if(k!=1) {
        cout << "NO\n";
        return;
    }
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i==0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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