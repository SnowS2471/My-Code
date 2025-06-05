#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 100005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    for(int i=1,x;i<=n;i++) {
        cin >> x;
        while(a[x]) {
            ans++;
            int p=a[x];
            a[x]=0;
            x=p;
        }
        cout << ans << " \n"[i==n];
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