#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 500005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;
int fac[N],infac[N];
int qpow(int a,int b) {
    int res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void init() {
    fac[0]=1;
    for(int i=1;i<N;i++) {
        fac[i]=fac[i-1]*i%mod;
    }
    infac[N-1]=qpow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) {
        infac[i]=infac[i+1]*(i+1)%mod;
    }
}

int C(int n,int m) {
    return fac[n] * infac[m] % mod *infac[n-m] %mod;
}
int a[27],dp[N],pre[27];
void solve() {
    int sum=0;
    for(int i=1;i<=26;i++) {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
        sum+=a[i];
    }
    int n = (sum+1)/2;
    dp[0]=1;
    for(int i=1;i<=26;i++) {
        if(a[i]==0) continue;
        for(int j=pre[i];j>=0;j--) {
            if(j>n || pre[i]-j>sum-n) continue;
            // 放偶数位
            dp[j]=dp[j]*C(sum-n-pre[i-1]+j,a[i]) % mod;
            // 放奇数位
            if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]]*C(n-j+a[i],a[i])) % mod;
        }
    }
    cout << dp[n] << endl;
    for(int i=0;i<=pre[26];i++) dp[i]=0;
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