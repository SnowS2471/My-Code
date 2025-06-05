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
    map<char,int> mp;
    for(auto c: s) {
        mp[c]++;
    }
    int oc=0;
    for(auto [c,cnt]:mp) {
        if(cnt&1) oc++;
    }
    if(oc<=1) cout << "Yes" << endl;
    else cout << "No" << endl;
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