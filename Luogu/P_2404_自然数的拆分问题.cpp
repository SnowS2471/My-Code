#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int ans[10];
void dfs(int pre,int s,int cnt){
    if(s==0) {
        if(cnt==2) return;
        for(int i=1;i<cnt;i++) {
            cout << ans[i] << "+\n"[i==cnt-1];
        }
        return;
    }
    if(s<pre) return;
    for(int i=pre;i<=s;i++) {
        ans[cnt]=i;
        dfs(i,s-i,cnt+1);
    }
}
void solve() {
    int n;
    cin >> n;
    dfs(1,n,1);
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