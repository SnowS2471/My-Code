#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void solve() {
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=1,x;i<=n;i++) cin >> x,mp[x]=i;
    int g=0;
    for(int i=1,x;i<=n;i++) {
        cin >> x;
        g=gcd(g,abs(i-mp[x]));
    }
    for(int i=1;i<=g;i++) {
        if(g%i==0) cout << i << endl;
    }
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