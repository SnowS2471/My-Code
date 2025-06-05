#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 1000005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n==1) {
        cout << 0 << endl;
        return;
    }
    int s=0,t=0;
    for(int i=1;i<=n;i++) {
        s+=a[i]*(n-i+1);
        t+=a[i]*i;
    }
    int d=abs(s-t);
    if(d&1) cout << -1 << endl;
    else cout << (d/2+n-2)/(n-1) << endl;
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