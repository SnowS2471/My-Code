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
    string s;
    cin >> n >> s;
    vector<int> ans(n+1);
    int cnt=0;
    for(int i=n-2;i>=0;i--) {
        if(s[i]=='<') ans[i+2]=++cnt;
    }
    ans[1]=++cnt;
    for(int i=0;i<n-1;i++) {
        if(s[i]=='>') ans[i+2]=++cnt;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i==n];
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