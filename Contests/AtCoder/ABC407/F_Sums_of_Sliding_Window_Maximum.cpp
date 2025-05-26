#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N];
int l[N],r[N];
int c[N];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    stack<int> ls,rs;
    for(int i=1;i<=n;i++) {
        while(!ls.empty() && a[ls.top()]<a[i]) ls.pop();
        if(ls.empty()) l[i]=1;
        else l[i]=ls.top()+1;
        ls.push(i);
    }
    for(int i=n;i>=1;i--) {
        while(!rs.empty() && a[rs.top()]<=a[i]) rs.pop();
        if(rs.empty()) r[i]=n;
        else r[i]=rs.top()-1;
        rs.push(i);
    }
    for(int i=1;i<=n;i++) {
        int x = min(i-l[i]+1,r[i]-i+1);
        int len = r[i]-l[i]+1;
        c[1] += a[i];
        c[x+1] -= a[i];
        c[len-x+2] -= a[i];
        c[len+2] += a[i];
    }
    for(int i=1;i<=n;i++) c[i] += c[i-1];
    for(int i=1;i<=n;i++) c[i] += c[i-1];
    for(int i=1;i<=n;i++) cout << c[i] << endl;




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