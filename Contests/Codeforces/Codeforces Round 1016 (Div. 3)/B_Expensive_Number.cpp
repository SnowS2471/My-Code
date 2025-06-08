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
    for(int i=s.size()-1,f=0;i>=0;i--) {
        if(s[i]=='0'&&!f) {
            ans++;
            continue;
        }
        if(s[i]!='0' && !f){
            f=1;
            continue;
        }
        if(s[i]!='0') ans++;
    }
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