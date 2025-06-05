#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int cnt = 0;
int p[N];
int find(int x){
    cnt++;
    return (p[x]==x?x:find(p[x]));
}
void solve() {
    int n;
    cin >> n;
    int ans=mod;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1,x;i<=n;i++) {
        cnt=0;
        cin >> x;
        (find(x)==i?ans=min(ans,cnt):p[i]=x);
    }
    cout << ans << endl;
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