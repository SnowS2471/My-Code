#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
string a[N],b[N];
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> ex(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    for(int i=1;i<=m;i++) {
        int res=0;
        string s;
        for(int j=1;j<=n;j++) {
            cin >> s;
            if(a[j] == s){
                res++;
                ex[j]=1;
            }
        }
        ans=max(ans,res);
    }
    for(int i=1;i<=n;i++) {
        if(!ex[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << n+(n-ans)*2 << endl; 
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