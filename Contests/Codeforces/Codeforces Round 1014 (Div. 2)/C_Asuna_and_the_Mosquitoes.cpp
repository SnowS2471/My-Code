#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N];
void solve() {
    int n;
    cin >> n;
    int ec=0,oc=0,sum=0,mx=0;
    for(int i=1,x;i<=n;i++) {
        cin >> x;
        mx=max(mx,x);
        sum+=x;
        if(x&1) oc++;
        else ec++;
    }
    if(!oc || !ec) cout << mx << endl;
    else cout << sum-oc+1 << endl;

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