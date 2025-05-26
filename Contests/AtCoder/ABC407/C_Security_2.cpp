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
    string s;
    cin >> s;
    int ans=0;
    ans+=s.size();
    ans+=s[0]-'0';
    for(int i = 1;i <s.size();i++) {
        if(s[i]>s[i-1]) ans+=10;
    }
    cout << ans << endl;
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