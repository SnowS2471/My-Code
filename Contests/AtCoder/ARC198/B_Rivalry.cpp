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
    int x,y,z;
    cin >> x >> y >> z;
    int a = 0;
    if(x==0) {
        cout << "No" << endl;
        return;
    }
    if(y&1) {
        if(z==0) {
            cout << "No" << endl;
            return;
        }
        y--,z--;
        a++;
    }
    int t = min(y/2,z);
    a += t;
    y -= t*2;
    z -= t;
    if(y) a+=y/2;
    else if(z) a+=z;
    if(a<=x) cout << "Yes" << endl;
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
