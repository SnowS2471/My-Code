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
    string p,s;
    cin >> p >> s;
    int n=p.size(),m=s.size();
    vector<int> a,b;
    int pre=0;
    for(int i=1;i<n;i++) {
        if(p[i]!=p[i-1]) {
            a.push_back(i-pre);
            pre=i;
        }
    }
    a.push_back(n-pre);
    pre=0;
    for(int i=1;i<m;i++) {
        if(s[i]!=s[i-1]) {
            b.push_back(i-pre);
            pre=i;
        }
    }
    b.push_back(m-pre);
    if(a.size()!=b.size() || p[0]!=s[0]) {
        cout << "NO\n";
    }else {
        for(int i=0;i<a.size();i++) {
            if(a[i]>b[i] || a[i]*2<b[i]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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