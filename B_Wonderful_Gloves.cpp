#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
struct yyy{ 
    int x,tp;
    bool operator<(const yyy &o) const{return x<o.x;}
}a[N<<1];
void solve() {
    int n,k,sum=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i].x,a[i].tp=i,sum+=a[i].x;
    for(int i=n+1;i<=n<<1;i++) cin >> a[i].x,a[i].tp=i-n,sum+=a[i].x;
    sort(a+1,a+(n<<1)+1);
    vector<int> f(n+1);
    int cnt=n-k+1;
    for(int i=1;i<=n<<1;i++) {
        if(!f[a[i].tp]) {
            f[a[i].tp]=1;
            sum-=a[i].x;
            if(--cnt==0) {
                cout << sum+1 << endl;
            }
        }
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