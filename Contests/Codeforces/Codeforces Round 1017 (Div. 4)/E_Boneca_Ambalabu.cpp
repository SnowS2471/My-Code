#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int c[31],a[N];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        for(int j=0;j<30;j++) c[j]+=a[i]>>j&1;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        int res=0;
        for(int j=0;j<30;j++) {
            if(a[i]>>j&1) res+=(n-c[j])*(1<<j);
            else res+=c[j]*(1<<j);
        }
        ans=max(res,ans);
    }
    for(int i=0;i<30;i++) c[i]=0;
    cout << ans << endl;
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