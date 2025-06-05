#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 100005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N],suf[N];
void solve() {
    int n,k,x;
    cin >> n >> k >> x;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    suf[n+1]=0;
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]+a[i];
    }  
    int res=x/suf[1];
    x-=res*suf[1];
    int ans;
    if(x==0) ans=(k-res)*n+1; 
    int p=0;
    for(int i=n;i>=1&&x!=0;i--) {
        if(suf[i]>=x) {
            p=i;
            ans=(k-res-1)*n+p;
            break;
        }
    }
    cout << (ans<0?0:ans) << endl;
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