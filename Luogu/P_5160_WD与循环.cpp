#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 20000005, M = 100005;
const int mod = /* 1e9 + 7 */ 19491001;
int fac[N],infac[N];

int qpow(int a,int b) {
    int res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0]=1;
    for(int i=1;i<mod;i++) {
        fac[i]=fac[i-1]*i%mod;
    }
    infac[mod-1] = qpow(fac[mod-1],mod-2);
    for(int i=mod-2;i>=0;i--) {
        infac[i] = infac[i+1]*(i+1)%mod;
    } 
}

int C(int n,int m) {
    if(n<m) return 0;
    return fac[n]*infac[m]%mod*infac[n-m]%mod;
}

int lucas(int n,int m) {
    if(n==0 && m==0) return 1;
    return C(n%mod,m%mod)*lucas(n/mod,m/mod)%mod;
}

void solve() {
    int n,m;
    cin >> n >> m;
    cout << lucas(n+m,m) << endl;
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