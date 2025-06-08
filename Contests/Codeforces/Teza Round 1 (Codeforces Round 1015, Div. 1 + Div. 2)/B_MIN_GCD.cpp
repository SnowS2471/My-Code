#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 100005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int gcd(int a,int b) {
    return b?gcd(b,a%b):a;
}
int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    int p=a[1];
    int g=0;
    for(int i=2;i<=n;i++) {
        if(a[i]%p) continue;
        g=gcd(g,a[i]);
    }
    if(g==p) cout << "Yes\n";
    else cout << "No\n"; 
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