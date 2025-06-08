#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 6000005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N];
int tr[N][2],mx[N],cnt;
void solve() {
    int n,k;
    cin >> n >> k;
    int ans=N;
    for(int i=1,x;i<=n;i++) {
        cin >> x;
        int mxp=0;
        int p=0,tp=0;
        for(int j=30;j>=0;j--) {
            int t=x>>j&1;
            if(!tr[p][t]) tr[p][t]=++cnt;
            p=tr[p][t];
            mx[p]=max(mx[p],i);
            if(tp!=-1) {
                if(k>>j&1) {
                    if(!tr[tp][!t]) tp=-1;
                    else tp=tr[tp][!t];
                } else {
                    if(tr[tp][!t]) mxp=max(mxp,mx[tr[tp][!t]]);
                    if(tr[tp][t]) tp=tr[tp][t];
                    else tp=-1;
                }
            }
        }
        if(tp!=-1) mxp=max(mxp,mx[tp]);
        if(mxp) ans=min(ans,i-mxp+1);
    }
    if(ans==N) cout << -1 << endl;
    else cout << ans << endl;
    for(int i=0;i<=cnt;i++) {
        tr[i][0]=tr[i][1]=mx[i]=0;
    }
    cnt=0;
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